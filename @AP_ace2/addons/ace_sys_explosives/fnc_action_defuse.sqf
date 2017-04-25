/* ace_sys_explosives (.pbo)| Disarming mines | (c) 2008, 2009, 2010, 2011 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_man", "_engineer", "_chance", "_fail", "_time", "_process", "_explosion_type", "_onDestroyScript", "_onDestroyPath", "_mine", "_path"];

PARAMS_1(_mine);

_engineer = (getNumber(configFile >> "CfgVehicles" >> typeOf player >> "canDeactivateMines") == 1 || getNumber(configFile >> "CfgVehicles" >> typeOf player >> "engineer") == 1);
_chance = ((1 - (damage _mine)) * 100)/2;
if (_engineer) then { _chance = _chance + 100; };

TRACE_2("",_engineer,_chance);

_fail = false;
if (_chance < 50) then {
	_fail = if ((random 100 < 50) && {(random 50 < 25)}) then { true } else { false };
	TRACE_1("",_fail);
};

// Progressbar
_time = if (damage _mine > 0.5) then { 20 } else { 10 };
player setVariable ["ACE_PB_Result", 0];
[_time,[localize "STR_HINT_ACE_SYS_EXPLOSIVES_DEFUSING"],true,true] spawn ace_progressbar;
waitUntil { (player getVariable "ACE_PB_Result" != 0) };
_process = (player getVariable "ACE_PB_Result" == 1); TRACE_1("",_process);
player setVariable ["ACE_PB_Result", 0];
if (!_process) exitWith { TRACE_1("Exiting",""); };

if (_fail) then {
	TRACE_1("FAIL","");
	_explosion_type = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(explosion_type));
	_onDestroyScript = "onDestroyed.sqf";
	_onDestroyPath = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(mine_type));
	if !(isNull _mine) then {
		_path = format ["x\ace\addons\sys_explosives\%1\%2",_onDestroyPath,_onDestroyScript];
		[_mine,_explosion_type] spawn COMPILE_FILE2_SYS(_path);
	};
} else {
	TRACE_1("SUCCESS","");
	[_mine] call FUNC(delete_trigger);
	// Disarm script
	_path = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "disarm");
	[_mine,false] spawn COMPILE_FILE2_SYS(_path);
};
