//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;

GVAR(enabled) = ["ACE", "sys_grenadethrow2", "enabled"] call ace_settings_fnc_getNumber;
GVAR(enabled) = !isNil QGVAR(enabled) && {GVAR(enabled) == 1};
GVAR(enabled) = false; // temporarily disabling until a key MP bug is fixed. 


GVAR(holding) = false;
GVAR(throwing) = false;
GVAR(throwTime) = 0;
GVAR(throw) = false;
GVAR(cancel) = false;
GVAR(underHand) = false;

FUNC(handleKeyDown) = {
	TRACE_1("handleKeyDown",_this);
	if ((currentWeapon player) == "Throw" && {GVAR(enabled)}) then {
		// for whatever reason it won't use QUOTE(ADDON) here... 
		// Will work when moved to its own file, because right now ADDON gets assigned a value above. - Nou
		_underHandKey = ["ace_sys_grenadethrow2", "under_hand"] call CBA_fnc_readKeyFromConfig;
		TRACE_1("handleKeyDown",_underHandKey);
		if (_this select 1 == _underHandKey select 0) then {
			GVAR(underHand) = true;
		};
	};
};

FUNC(handleKeyUp) = {
	TRACE_1("handleKeyUp",_this);
	if (GVAR(enabled)) then {
		_underHandKey = ["ace_sys_grenadethrow2", "under_hand"] call CBA_fnc_readKeyFromConfig;
		TRACE_1("handleKeyDown",_underHandKey);
		if (_this select 1 == _underHandKey select 0) then {
			GVAR(underHand) = false;
		};
	};
};

FUNC(handleMouseUp) = {
	_button = _this select 1;
	if ((currentWeapon player) == "Throw" && {GVAR(enabled)}) then {
		if (_button == 0 && {GVAR(holding)}) then {
			GVAR(throw) = true;
		};
	};
};

FUNC(dir) = {
	_pos1 = ATLtoASL positionCameraToWorld [0,0,0];
	_pos2 = ATLtoASL positionCameraToWorld [0,0,1];
	_vec = [_pos1, _pos2] call BIS_fnc_vectorFromXtoY;
	_vec;
};

FUNC(holdFunc) = {
	_params = _this select 0;
	_grenade = _params select 0;
	_eyePos = ATLtoASL positionCameraToWorld [0,0,0];
	_eyePos set[2, (_eyePos select 2)-0.05];
	_eyeDir = [] call FUNC(dir);
	
	_holdPos = [
				(_eyePos select 0) + ((_eyeDir select 0)/2.5),
				(_eyePos select 1) + ((_eyeDir select 1)/2.5),
				(_eyePos select 2) + ((_eyeDir select 2)/2.5)
			];

	_grenade setPosASL _holdPos;
	_grenade setDir (getDir player)+180;
	_polar = _eyeDir call CBA_fnc_vect2Polar;
	_elev = _polar select 2;
	if (GVAR(underHand)) then {
		[_grenade, 0, 89.999] call BIS_fnc_setPitchBank;
	} else {
		[_grenade, 0, 45] call BIS_fnc_setPitchBank;
	};
	if (GVAR(cancel) || {(currentWeapon player) != "Throw"}) then {
		GVAR(holding) = false;
		GVAR(cancel) = false;
		deleteVehicle _grenade;
		[(_this select 1)] call cba_fnc_removePerFrameHandler;
	} else {
		if (GVAR(throw)) then {
			GVAR(throw) = false;
			GVAR(holding) = false;
			GVAR(cancel) = false;
			GVAR(throwing) = true;
			GVAR(throwTime) = diag_tickTime + 0.45;
			player playAction "GestureAdvance";
		} else {
			if (GVAR(throwing)) then {
				if (diag_tickTime >= GVAR(throwTime)) then {
					_grenade enableSimulation true;
					_wepDir = [] call FUNC(dir);//eyeDirection player;//player weaponDirection (currentWeapon player);
					_vel = 17;
					if(GVAR(underHand)) then {
						_vel = 8;
					};
					_gVel = 
							[
								(_wepDir select 0)*_vel,
								(_wepDir select 1)*_vel,
								(_wepDir select 2)*_vel
							];
					_pV = velocity player;
					_gVel = [
								(_gVel select 0)+(_pv select 0),
								(_gVel select 1)+(_pv select 1),
								(_gVel select 2)+(_pv select 2)
							];
					// [_grenade] call ace_sys_frag_fnc_addManualTrack;
					_geoObject = "ACE_Grenade_Geometry_Small" createVehicle [0,0,1000];
					_geoObject setPos (getPos _grenade);
					
					_grenade attachTo [_geoObject, [0,0,0]];
					
					_geoObject setPosASL _holdPos;
					if(GVAR(underHand)) then {
						[_geoObject, 0, 89.999] call BIS_fnc_setPitchBank;
					} else {
						[_geoObject, 0, 45] call BIS_fnc_setPitchBank;
					};
					
					_geoObject setDir (getDir player)+180;
					_geoObject setVelocity _gVel;
					_cmag = (currentMagazine player);
					_currentMuzzle = currentMuzzle player;
					_count = { _x == _cmag } count (magazines player);
					player removeMagazines _cmag;
					if (_count-1 > 0) then {
						for "_i" from 1 to _count-1 do {
							player addMagazine _cmag;
						};
					};
					player removeWeapon "Throw";
					player addWeapon "Throw";
					player selectWeapon _currentMuzzle;
					//[unit, weapon, muzzle, mode, ammo, magazine, projectile]
					_firedEH = [player, (currentWeapon player), _currentMuzzle, "", (typeOf _grenade), _cmag, _grenade];
					[-2, { _this call SLX_XEH_EH_Fired }, _firedEH] call CBA_fnc_globalExecute;
					[FUNC(wallCheck), 0, [_geoObject, _grenade, diag_tickTime + 0.25]] call cba_fnc_addPerFrameHandler;
					[(_this select 1)] call cba_fnc_removePerFrameHandler;
					GVAR(throwing) = false;							
				};
			};
		};
	};
};

FUNC(handleMouseDown) = {
	if (dialog) exitWith { };
	_button = _this select 1;
	if ((currentWeapon player) == "Throw" && {GVAR(enabled)} && {_button == 0} && {!GVAR(holding)} && {!GVAR(throwing)}) then {
		GVAR(holding) = true;
		GVAR(currentMagazine) = (currentMagazine player);
		_ammoType = getText(configFile >> "CfgMagazines" >> GVAR(currentMagazine) >> "ammo");
		_ammoObject = _ammoType createVehicle [0,0,10000];
		_ammoObject enableSimulation false;
		[FUNC(holdFunc), 0, [_ammoObject]] call cba_fnc_addPerFrameHandler;
	} else {
		if ((currentWeapon player) == "Throw" && {GVAR(enabled)} && {_button == 1} && {GVAR(holding)} && {!GVAR(throwing)}) then {
			GVAR(cancel) = true;
		};
	};
	true
};

FUNC(wallCheck) = {
	_params = _this select 0;
	_grenadeGeo = _params select 0;
	_grenade = _params select 1;
	_startTime = _params select 2;
	if(_startTime > diag_tickTime) exitWith { };
	if (alive _grenade) then {
		_pos = getPosASL _grenadeGeo;
		_velocity = velocity _grenadeGeo;
		_tdelta = (1/diag_fps);
		_offset = [
					(_velocity select 0)*_tdelta,
					(_velocity select 1)*_tdelta,
					(_velocity select 2)*_tdelta
				];
		_pos2 = [
					(_pos select 0)+(_offset select 0),
					(_pos select 1)+(_offset select 1),
					(_pos select 2)+(_offset select 2)
				];
		
		// player sideChat format["test"];
		// _test = lineIntersectsWith [_pos, _pos2, _grenade, _grenadeGeo];
		if(lineIntersects [_pos, _pos2, _grenade, _grenadeGeo]) then {
			_offset = [
				(_velocity select 0)*(_tdelta*-1),
				(_velocity select 1)*(_tdelta*-1),
				(_velocity select 2)*(_tdelta*-1)
			];
			_backPos = [
					(_pos select 0)+(_offset select 0),
					(_pos select 1)+(_offset select 1),
					(_pos select 2)+(_offset select 2)
				];
			_grenadeGeo setPosASL _backPos;
			_grenadeGeo setVelocity [0,0,0];
			// player sideChat format["intersect!"];
			[(_this select 1)] call cba_fnc_removePerFramehandler;
		};
		// drop ["\Ca\Data\Cl_basic","","Billboard",1,15,(getPos _grenade),[0,0,0],1,1.275,1.0,0.0,[0.5],[[1,0,0,1]],[0],0.0,2.0,"","",""];
		// drop ["\Ca\Data\Cl_basic","","Billboard",1,15,(getPos _grenadeGeo),[0,0,0],1,1.275,1.0,0.0,[0.5],[[0,1,0,1]],[0],0.0,2.0,"","",""];
		// _p1 = getPosASL _grenade;
		// _p2 = getPosASL _grenadeGeo;
		// _dif = [
				// (_p1 select 0)-(_p2 select 0),
				// (_p1 select 1)-(_p2 select 1),
				// (_p1 select 2)-(_p2 select 2)
			// ];
		// diag_log text format["d: %1", _dif];
	} else {
		deleteVehicle _grenadeGeo;
		// player sideChat format["END"];
		[_this select 1] call cba_fnc_removePerFramehandler;
	};
};

FUNC(monitorGrenadeWeapon) = {
	if ((currentWeapon player) == "Throw") then {
		player setWeaponReloadingTime [player, currentMuzzle player, 1];
	};
};

ADDON = true;