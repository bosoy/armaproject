/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
#include "script_component.hpp"

PARAMS_1(_veh);

if (({alive _x} count crew _veh) > 0) exitWith {
	format["Safety Violation. %1 has crew onboard",_veh] spawn ace_fnc_visual;
	closeDialog 0;
	false;
};
// Coming from dialog = local
_time = 90;
_string = format[localize "CONFIG_DEPOT.SQF5" +": " + "%1",(typeOf _veh)];
player setVariable ["ACE_PB_Result", 0];
[_time,[_string],false,false] spawn ace_progressbar;

if (isMultiPlayer) then {
	[QGVAR(load), [_veh,"","D"]] call CBA_fnc_globalEvent;
} else {
	[_veh,"","D"] spawn FUNC(load);
};
closeDialog 0;