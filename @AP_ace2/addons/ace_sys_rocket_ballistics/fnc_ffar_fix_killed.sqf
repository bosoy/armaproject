#include "script_component.hpp"

// BIS bug fixer
// Script by zGuba

private ["_vehicle"];

_vehicle = _this select 0;

// Cache selection position
if !(isNil {_vehicle getVariable QGVAR(ffar_r_logic)}) then {
	deleteVehicle (_vehicle getVariable QGVAR(ffar_r_logic));
};
if !(isNil {_vehicle getVariable QGVAR(ffar_l_logic)}) then {
	deleteVehicle (_vehicle getVariable QGVAR(ffar_l_logic));
};

// remove parentless logics.
{
	if (isNil {_x getVariable QGVAR(ffar_parent)}) then {
		deleteVehicle _x;
	};
} forEach GVAR(ffar_logic_array);

GVAR(ffar_logic_array) = GVAR(ffar_logic_array) - [objNull];
