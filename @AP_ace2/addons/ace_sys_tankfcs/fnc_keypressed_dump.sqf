#include "script_component.hpp"
private ["_veh","_h"];

_veh = vehicle player;
if (player == _veh) exitWith { false };
if (getNumber(configfile>>"cfgVehicles">>typeof _veh>>"ace_tankfcs_enabled") == 0) exitwith {false};
if (getNumber(configfile>>"cfgVehicles">>typeof _veh>>"ace_tankfcs_maxlead") == 0) exitwith {false};
_h = false;
switch (true) do {
	case (player == gunner _veh && {cameraView == "GUNNER"}): {
		if (! isNil {_veh getvariable "ace_tankfcs_init"}) then {
			if (GVAR(presstime) == time) exitWith {false};
			GVAR(presstime) = time;
			_veh spawn FUNC(dumplead);
			_h = true;
		};
	};
};
_h
