#include "script_component.hpp"
private ["_veh","_h"];

_veh = vehicle player;
if (player == _veh) exitWith { false };
if (getNumber(configfile>>"cfgVehicles">>typeof _veh>>"ace_air_fcs_enabled") == 0) exitwith {false};
_h = false;
if (player == gunner _veh) then {
	if (GVAR(presstime) < time) then {
		GVAR(presstime) = time + 0.1;
		_veh call FUNC(findrangePFH);
	//	_h = true;
	};
//	if (currentWeapon _veh == "ACE_HellfireLauncher_Apache") then {
//		_h = false;
//	};
};
_h
