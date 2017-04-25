/* ace_sys_explosives (.pbo)| IED | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

private ["_A_ID","_mine"];

if (count _this > 2) then {
	_A_ID = _this select 2;
	_mine = _this select 3;
	player removeAction _A_ID;
} else {
	_trigger = _this select 0;
	_mine = [_trigger] call FUNC(get_mine);
};

if ((_mine getVariable [QGVAR(jammed),false]) && {!(_mine call FUNC(has_trigger))}) exitWith {
	_mine spawn COMPILE_FILE2_SYS(PATH+"attach_clacker.sqf");
};
if (isNull _mine) exitwith { false };

"ACE_PipebombExplosion" createVehicle [(position _mine) select 0,(position _mine) select 1, 0.2 + ([_mine] call CBA_fnc_realHeight)];
[_mine] call FUNC(removeMine);
