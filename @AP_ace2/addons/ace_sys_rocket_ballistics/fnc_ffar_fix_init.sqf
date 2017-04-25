#include "script_component.hpp"

// BIS bug fixer
// Script by zGuba

private ["_vehicle","_logic","_lrocket","_rrocket"];

_vehicle = _this select 0;

_rrocket = getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "memoryPointRRocket");
_lrocket = getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "memoryPointLRocket");

// Cache selection position
if (isNil {_vehicle getVariable QGVAR(ffar_r)}) then {
	_vehicle setVariable [QGVAR(ffar_r), _vehicle selectionPosition _rrocket];
};
if (isNil {_vehicle getVariable QGVAR(ffar_l)}) then {
	_vehicle setVariable [QGVAR(ffar_l), _vehicle selectionPosition _lrocket];
};

if (((_vehicle getVariable QGVAR(ffar_r)) call ACE_fnc_magnitude) > 0) then {
	_logic = "Logic" createVehicleLocal [0,0,0];
	_logic attachTo [_vehicle, [0,0,0], _rrocket];
	_vehicle setVariable [QGVAR(ffar_r_logic),_logic];
	_logic setVariable [QGVAR(ffar_parent),_vehicle];
	GVAR(ffar_logic_array) set [count GVAR(ffar_logic_array),_logic];
};
if (((_vehicle getVariable QGVAR(ffar_l)) call ACE_fnc_magnitude) > 0) then {
	_logic = "Logic" createVehicleLocal [0,0,0];
	_logic attachTo [_vehicle, [0,0,0], _lrocket];
	_vehicle setVariable [QGVAR(ffar_l_logic),_logic];
	_logic setVariable [QGVAR(ffar_parent),_vehicle];
	GVAR(ffar_logic_array) set [count GVAR(ffar_logic_array),_logic];
};

// remove parentless logics.
{
	if (isNil {_x getVariable QGVAR(ffar_parent)}) then {
		deleteVehicle _x;
	};
} forEach GVAR(ffar_logic_array);

GVAR(ffar_logic_array) = GVAR(ffar_logic_array) - [objNull];
