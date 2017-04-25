//fnc_ccip.sqf
#include "script_component.hpp"

if((currentWeapon GVAR(ccip_plane)) == "ACE_CCRP_Launcher") then {
	_proxy = getText(configFile >> "CfgAmmo" >> GVAR(currentAmmoClass) >> "ACE_ccip_proxy");
	if(_proxy != "") then {
		_pos = (getPosASL GVAR(ccip_plane));
		_vel = (velocity GVAR(ccip_plane));
		_airFriction = getNumber(configFile >> "CfgAmmo" >> _proxy >> "airFriction");
		GVAR(lastDropPos) = +GVAR(dropPos);
		GVAR(dropPos) = [_vel, _pos, _airFriction, [0,0,EJECTOR_SPEED]] call FUNC(getImpactPos);
		if(GVAR(CCRP_CONSENTING)) then {
			_polar = _vel call CBA_fnc_vect2polar;
			_newVelVec = [_polar select 0, _polar select 1, 40] call CBA_fnc_polar2vect;
			GVAR(CCIP_LOFT_POS) = [_newVelVec, _pos, _airFriction, [0,0,EJECTOR_SPEED]] call FUNC(getImpactPos);
			// GVAR(CCIP_LOFT_POS) set[2, 0];
		};
	} else {
		_gravity = getNumber(configFile >> "CfgAmmo" >> GVAR(currentAmmoClass) >> "ACE_CCIP_GRAVITY");
		if(_gravity != 0) then {
			_pos = (getPosASL GVAR(ccip_plane));
			_vel = (velocity GVAR(ccip_plane));
			_airFriction = getNumber(configFile >> "CfgAmmo" >> GVAR(currentAmmoClass) >> "ACE_CCIP_AIRFRIC");
			GVAR(lastDropPos) = +GVAR(dropPos);
			GVAR(dropPos) = [_vel, _pos, _airFriction, [0,0,0], _gravity] call FUNC(getImpactPos);
			if(GVAR(CCRP_CONSENTING)) then {
				_polar = _vel call CBA_fnc_vect2polar;
				_newVelVec = [_polar select 0, _polar select 1, 40] call CBA_fnc_polar2vect;
				GVAR(CCIP_LOFT_POS) = [_newVelVec, _pos, _airFriction, [0,0,0], _gravity] call FUNC(getImpactPos);
				// GVAR(CCIP_LOFT_POS) set[2, 0];
			};
		};
	};
};