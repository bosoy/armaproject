#include "script_component.hpp"

ADDON = false;

GVAR(dropPos) = [0,0,0];
GVAR(currentAmmoClass) = "Bo_Mk82";
GVAR(CCIP_RELEASE_COUNT) = 0;
GVAR(CCRP_LAST_RELEASECHECK) = 100000000;
GVAR(CCRP_LAST_LOFTRELEASECHECK) = 100000000;
GVAR(CCIP_TARGET_TYPE) = "pipper";
GVAR(currentMagazineClass) = "";

GVAR(CCIP_FLASH_TIME) = 0;
GVAR(CCIP_FLASH_COUNT) = 0;
GVAR(CONSENT_PIPPERPOS) = [0,0,0];
GVAR(CCIP_FLASHED) = false;
GVAR(CCIP_FLASH_MODE) = false;
GVAR(CCIP_FLASHING) = false;
GVAR(CCIP_RELEASE_RIPPLECOUNT) = 1;
GVAR(CCIP_RELEASE_RIPPLESPACING) = 100;
GVAR(CCIP_RELEASE_RIPPLEPAIRS) = false;
GVAR(CCIP_PREDICTEDRELEASE) = false;
GVAR(CCRP_CONSENTING) = false;
GVAR(ccip_plane) = nil;
GVAR(hudInitSized) = false;
GVAR(currentPlaneWeapons) = [];
GVAR(currentPlaneWeaponsIndex) = -1;
GVAR(CCIP_IMMEDIATE_RELEASE) = false;
GVAR(smoothCount) = 5;
GVAR(nextPipperPoint) = [0,0,0];

GVAR(hasKeyedUp) = true;

PREP(ccip);
PREP(drawDashedLine);
PREP(drawHud);
PREP(fired);
PREP(getImpactPos);
PREP(getIn);
PREP(hudOpen);
PREP(releaseBombs);
PREP(shackEm);
PREP(syncBomb);

FUNC(vectorAdd) = {
	_vec1 = _this select 0;
	_vec2 = _this select 1;
	
	_ret = [
			(_vec1 select 0)+(_vec2 select 0),
			(_vec1 select 1)+(_vec2 select 1),
			(_vec1 select 2)+(_vec2 select 2)
		];
			
	_ret
};

FUNC(unitVectorFast) = {
	private ["_mag","_ret"];


	_mag = _this call ACE_fnc_magnitude;
	
	_ret = [
			(_this select 0)/_mag,
			(_this select 1)/_mag,
			(_this select 2)/_mag
		];


	_ret
};

FUNC(triggerPressCheckDown) = {
	// player sideChat format["trigger: %1", _this];
	if((_this select 1) == 0) then {
		if((currentWeapon GVAR(ccip_plane)) == "ACE_CCRP_Launcher" && {GVAR(CCIP_IMMEDIATE_RELEASE)}) then {
			[] call FUNC(doBombRelease);
		} else {
			if((currentWeapon GVAR(ccip_plane)) == "ACE_CCRP_Launcher" && {!GVAR(CCRP_CONSENTING)}) then {
				GVAR(CCRP_LAST_RELEASECHECK) = 100000000;
				GVAR(CCRP_LAST_LOFTRELEASECHECK) = 100000000;
				GVAR(CCRP_CONSENTING) = true;
			};
		};
	};
};

FUNC(keyboard_pickleWeaponDown) = {
	if(isNil QGVAR(ccip_plane)) exitWith { false };
	if(GVAR(hasKeyedUp)) then {
		GVAR(hasKeyedUp) = false;
		if((currentWeapon GVAR(ccip_plane)) == "ACE_CCRP_Launcher" && {GVAR(CCIP_IMMEDIATE_RELEASE)}) then {
			[] call FUNC(doBombRelease);
		} else {
			if((currentWeapon GVAR(ccip_plane)) == "ACE_CCRP_Launcher" && {!GVAR(CCRP_CONSENTING)}) then {
				GVAR(CCRP_LAST_RELEASECHECK) = 100000000;
				GVAR(CCRP_LAST_LOFTRELEASECHECK) = 100000000;
				GVAR(CCRP_CONSENTING) = true;
			};
		};
	};
	true
};

FUNC(triggerPressCheckUp) = {
	if((_this select 1) == 0) then {
		if(GVAR(CCRP_CONSENTING)) then {
			GVAR(CCRP_CONSENTING) = false;
		};
	};
};

FUNC(keyboard_pickleWeaponUp) = {
	GVAR(hasKeyedUp) = true;
	if(isNil QGVAR(ccip_plane)) exitWith { false };
	if(GVAR(CCRP_CONSENTING)) then {
		GVAR(CCRP_CONSENTING) = false;
	};
	true
};

FUNC(doBombRelease) = {
	_velocityVec = velocity GVAR(ccip_plane);
	_Vx = _velocityVec select 0;
	_Vy = _velocityVec select 1;
	_Vz = _velocityVec select 2;
	_Vmag = sqrt (_Vx^2 + _Vy^2 + _Vz^2);
	GVAR(CCIP_RELEASE_COUNT) = GVAR(CCIP_RELEASE_RIPPLECOUNT);
	_rippleTiming = GVAR(CCIP_RELEASE_RIPPLESPACING)/_Vmag;
	_id = [FUNC(releaseBombs), _rippleTiming*(1/accTime)] call cba_fnc_addPerFramehandler;
};

FUNC(getWeaponMode) = {
	_currentWeapon = (currentWeapon GVAR(ccip_plane));
	_weaponType = getText(configFile >> "CfgWeapons" >> _currentWeapon >> "ACE_HUD_WeaponType");
	
	if(_weaponType == "bomb" || {_weaponType == "lgb"}) then {
		GVAR(currentCCRPWeaponType) = _weaponType;
		if(!("ACE_CCRP_Launcher" in (weapons GVAR(ccip_plane)))) then {
			GVAR(currentPlaneWeapons) = (weapons GVAR(ccip_plane));
			GVAR(currentPlaneWeaponsIndex) = GVAR(currentPlaneWeapons) find _currentWeapon;
			_curMagazine = currentMagazine GVAR(ccip_plane);
			GVAR(currentMagazineClass) = _curMagazine;
			GVAR(currentAmmoClass) = getText(configFile >> "CfgMagazines" >> _curMagazine >> "ammo");
			GVAR(ccip_plane) addWeapon "ACE_CCRP_Launcher";
			GVAR(ccip_plane) selectWeapon "ACE_CCRP_Launcher";
		};
	};
	if(_weaponType == "gun") then {
		_curMagazine = currentMagazine GVAR(ccip_plane);
		GVAR(currentMagazineClass) = _curMagazine;
		GVAR(currentAmmoClass) = getText(configFile >> "CfgMagazines" >> _curMagazine >> "ammo");
	};
	if(_weaponType == "" && {_currentWeapon != "ACE_CCRP_Launcher"}) then {
		GVAR(ccip_plane) removeWeapon "ACE_CCRP_Launcher";
	};
	if(_weaponType == "" && {_currentWeapon == "ACE_CCRP_Launcher"}) then {
		_weaponType = GVAR(currentCCRPWeaponType);
	};
	_weaponType
};

FUNC(checkChangeWeapon) = {
	_return = false;
	if((_this select 1) in (actionKeys "ToggleWeapons")) then {
		// player sideChat format["switching!"];
		_currentWeapon = (currentWeapon GVAR(ccip_plane));
		if(_currentWeapon == "ACE_CCRP_Launcher") then {
			_nextIndex = GVAR(currentPlaneWeaponsIndex) + 1;
			if(_nextIndex > ((count GVAR(currentPlaneWeapons))-1)) then {
				_nextIndex = 0;
			};
			GVAR(currentPlaneWeaponsIndex) = _nextIndex;
			_weaponName = GVAR(currentPlaneWeapons) select GVAR(currentPlaneWeaponsIndex);
			GVAR(ccip_plane) removeWeapon "ACE_CCRP_Launcher";
			GVAR(ccip_plane) selectWeapon _weaponName;
			// player sideChat format["_weaponName: %1", _weaponName];
			_return = true;
		};
		
	};
	_return
};

FUNC(cleanUp) = {
	GVAR(CCRP_CONSENTING) = false;
	GVAR(CCIP_FLASHED) = false;
	GVAR(CCRP_LAST_RELEASECHECK) = 100000000;
	GVAR(CCRP_LAST_LOFTRELEASECHECK) = 100000000;
	GVAR(CCIP_PREDICTEDRELEASE) = false;
};


FUNC(lineLineIntersect) = {
	_p1 = _this select 0;
	_p2 = _this select 1;
	_p3 = _this select 2;
	_p4 = _this select 3;
	
	_x1 = _p1 select 0;
	_x2 = _p2 select 0;
	_x3 = _p3 select 0;
	_x4 = _p4 select 0;
	
	_y1 = _p1 select 1;
	_y2 = _p2 select 1; 
	_y3 = _p3 select 1;
	_y4 = _p4 select 1;
	 
	_d = (_x1 - _x2) * (_y3 - _y4) - (_y1 - _y2) * (_x3 - _x4);
	
	// If d is zero, there is no intersection
	if (_d == 0) exitWith { nil };
	 
	// Get the x and y
	_pre = (_x1*_y2 - _y1*_x2);
	_post = (_x3*_y4 - _y3*_x4);
	_x = ( _pre * (_x3 - _x4) - (_x1 - _x2) * _post ) / _d;
	_y = ( _pre * (_y3 - _y4) - (_y1 - _y2) * _post ) / _d;
	 
	// Check if the x and y coordinates are within both lines
	if ( _x < (_x1 min _x2) || _x > (_x1 max _x2) ||
	_x < (_x3 min _x4) || _x > (_x3 max _x4) ) exitWith { nil };
	if ( _y < (_y1 min _y2) || _y > (_y1 max _y2) ||
	_y < (_y3 min _y4) || _y > (_y3 max _y4) ) exitWith { nil };
	 
	// Return the point of intersection
	_ret = [_x, _y];
	_ret

};

ADDON = true;
