#include "script_component.hpp"

// BIS bug fixer
// Script by zGuba

private ["_vehicle", "_bullet", "_velocity"];

_vehicle = _this select 0;
_bullet = _this select 6; // uses BIS Fired EH

// Set up proper position
if (isNil {_vehicle getVariable QGVAR(ffar)}) then {
	_vehicle setVariable [QGVAR(ffar), 1];
	if !(isNil {_vehicle getVariable QGVAR(ffar_r_logic)}) then {
		_velocity = velocity _bullet;
		_bullet setPosASL getPosASL (_vehicle getVariable QGVAR(ffar_r_logic));
		_bullet setVelocity _velocity;
	};
} else {
	_vehicle setVariable [QGVAR(ffar), nil];
	if !(isNil {_vehicle getVariable QGVAR(ffar_l_logic)}) then {
		_velocity = velocity _bullet;
		_bullet setPosASL getPosASL (_vehicle getVariable QGVAR(ffar_l_logic));
		_bullet setVelocity _velocity;
	};
};

// remove parentless logics.
{
	if (isNil {_x getVariable QGVAR(ffar_parent)}) then {
		deleteVehicle _x;
	};
} forEach GVAR(ffar_logic_array);

GVAR(ffar_logic_array) = GVAR(ffar_logic_array) - [objNull];
