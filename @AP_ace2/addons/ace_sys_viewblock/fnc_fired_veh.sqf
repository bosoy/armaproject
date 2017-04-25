/* ace_sys_viewblock (.pbo) | (c) 2008, 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_ammo","_smokeshell_array","_bullet"];

PARAMS_1(_unit);
_ammo = _this select 4;

// Catch smokeshells
_smokeshell_array = (position _unit) nearObjects ["SmokeShellVehicle",15];

{
	[_unit,"","","","SmokeShellVehicle","",_x] call FUNC(fired);
	//TRACE_1("Spawn","");
} foreach _smokeshell_array;
