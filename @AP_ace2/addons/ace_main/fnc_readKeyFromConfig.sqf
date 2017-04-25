/* ----------------------------------------------------------------------------
Function: CBA_fnc_readKeyFromConfig

Description:
	Reads key setting from config

Parameters:
	_component - Classname under "CfgSettings" >> "CBA" >> "events" [String].
	_action - Action classname [String].

Returns:

Examples:
	(begin example)
		_keyConfig = ["cba_sys_nvg", "nvgon"] call CBA_fnc_readKeyFromConfig;
	(end)

Author:
	Sickboy
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"
SCRIPT(readKeyFromConfig);

private ["_component", "_action", "_settings", "_conf", "_key"];
PARAMS_2(_component,_action);
_settings = [false, false, false];
_conf = configFile >> "CfgSettings" >> "CBA" >> "Events";
if (isNumber (_conf >> _component >> _action)) exitWith {
	TRACE_2("",_this,getNumber (_conf >> _component >> _action));
	[["CBA", "Events", _component, _action] call ACE_settings_fnc_getNumber, _settings];
};

if (isClass (_conf >> _component >> _action)) exitWith {
	_key = ["CBA", "Events", _component, _action, "key"] call ACE_settings_fnc_getNumber;
	{
		if ((["CBA", "Events", _component, _action, _x] call ACE_settings_fnc_getNumber) == 1) then {_settings set [_forEachIndex, true]};
	} forEach ["shift", "ctrl", "alt"];
	TRACE_3("",_this,_key,_settings);
	[_key, _settings];
};

[-1, _settings];
