/* ace_sys_explosives (.pbo)| C4 | (c) 2008, 2009, 2010, 2011 by rocko */
#include "script_component.hpp"

private ["_A_ID","_mine"];
_ar = _this;
if (count _this > 2) then {
	_A_ID = _this select 2;
	_mine = _this select 3;
	player removeAction _A_ID;
} else {
	_mine = _this select 0; // Has no trigger!
};

if (isNull _mine) exitwith { false };

_position = position _mine;
_z = [_mine] call CBA_fnc_realHeight;
_position = [_position select 0,_position select 1, _z];
if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
"ACE_C4Explosion" createVehicle [_position select 0,_position select 1, _z + 0.2];

_breach = "ACE_BreachObject" createVehicle [_position select 0,_position select 1, _z + 0.2];
_breach spawn {
	sleep 2;
	deleteVehicle _this;
};
