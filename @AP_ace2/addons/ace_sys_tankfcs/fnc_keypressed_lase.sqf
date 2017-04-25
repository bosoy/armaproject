#include "script_component.hpp"
#define __comgun  (1 == getNumber(configfile>>"cfgVehicles">>typeof _veh>>"ace_tankfcs_commanderisgunner"))

private ["_veh","_h"];

_veh = vehicle player;
if (player == _veh) exitWith { false };
if (getNumber(configfile>>"cfgVehicles">>typeof _veh>>"ace_tankfcs_enabled") == 0) exitwith {false};
_h = false;
switch (true) do {
	case (((player == gunner _veh && {!__comgun}) || {(player == commander _veh && {__comgun})}) && {cameraView == "GUNNER"}): {
		if (GVAR(presstime) == time) exitWith {false};
		GVAR(presstime) = time;
		if (! isNil {_veh getvariable "ace_tankfcs_init"}) then {
			_veh call FUNC(lasePFH);
		} else {
			if (isNil {_veh getvariable "ace_tankfcs_down"}) then {
				_veh spawn FUNC(startFCS);
			};
		};
		_h = true;
	};
	case (player == commander _veh && {!__comgun} && {cameraView == "GUNNER"}): {
		if (GVAR(presstime) == time) exitWith {false};
		GVAR(presstime) = time;
		if (! isNil {_veh getvariable "ace_tankfcs_com_init"}) then {
			_veh spawn FUNC(lase_com);
		} else {
			if (isNil {_veh getvariable "ace_tankfcs_down"}) then {
				_veh spawn FUNC(startFCS_commander);
			};
		};
		_h = true;
	};
};
_h
