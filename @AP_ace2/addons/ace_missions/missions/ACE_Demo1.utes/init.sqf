#include "script_component.hpp"

ace_sys_wounds_enabled = true;
ace_sys_spectator_can_exit_spectator = true;

hint "Please find the ACE Diary menu in your Diary";
_actionIndex = [["Open Function Help", "\x\cba\addons\help\fnc_help.sqf"]] call CBA_fnc_addPlayerAction;
_actionIndex = [["Open Spectator", "\x\ace\addons\sys_spectator\fnc_startSpectator.sqf"]] call CBA_fnc_addPlayerAction;
_actionIndex = [["Switch debug", "action.sqf"]] call CBA_fnc_addPlayerAction;
_actionIndex = [["Describe Player", "actionDescribe.sqf"]] call CBA_fnc_addPlayerAction;
setViewDistance 5000;

FUNC(fired) = {
	PARAMS_7(_unit,_bla1,_bla2,_bla3,_ammo,_magazine,_obj);
	if !(isNil "ace_test_debug_disabled") exitWith {};
	if !((_ammo isKindOf "ShellBase") || (_ammo isKindOf "MissileBase")) exitWith {};
	if !(isNull _obj) then { [_obj] spawn ACE_fnc_track };
};

[] spawn {
	sleep 1;
	{ _x addEventHandler ["Fired", {_this call FUNC(fired)}] } forEach (vehicles + allUnits);
};

[] execVM "showclass.sqf";
