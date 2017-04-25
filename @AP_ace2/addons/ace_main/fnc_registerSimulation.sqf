/* ----------------------------------------------------------------------------
Function: ACE_fnc_registerSimulation

Description:
	Register simulationType for CAManBase

Parameters:
	- type
	- code
	- optional parameter; boolean; global or local event (true = global)

Returns:
		nil

Examples:
	(begin example)
		-
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */

#include "script_component.hpp"

PARAMS_2(_type,_code);
DEFAULT_PARAM(2,_global,false);

if (_global) then {
	_ar = ace_simulation_global getVariable _type;
	if (isNil "_ar") then { _ar = [] };
	PUSH(_ar,_code);
	ace_simulation_global setVariable [_type, _ar];
} else {
	_ar = ace_simulation getVariable _type;
	if (isNil "_ar") then { _ar = [] };
	PUSH(_ar,_code);
	ace_simulation setVariable [_type, _ar];
};
