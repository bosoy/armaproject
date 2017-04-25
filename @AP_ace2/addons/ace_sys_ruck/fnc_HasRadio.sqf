/*
Function: ACE_fnc_HasRadio

Description:
	Determine if a unit has a radio.

Parameters:
	_unit - Unit to check for a radio [Object]

Returns:
	"true" if has radio or "false" if not [Boolean]

Example:
	(begin example)
		_onTheAir = [BOB] call ACE_fnc_HasRadio;
	(end)

Author:
	tcp
*/


/* ace_sys_ruck (.pbo) (c) 2009,2010 by tcp */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

private ["_ruck","_confIsRadio","_hasRadio"];

_hasRadio = false;

if ( _unit call FUNC(HasRuck) ) then {
	_ruck = _unit call FUNC(FindRuck);
	_confIsRadio = configFile >> "CfgWeapons" >> _ruck >> "ACE_is_radio";

	if (getNumber(_confIsRadio) == 1) then {
		TRACE_1("Has a radio", _ruck);
		_hasRadio = true;
	} else {
		TRACE_1("Does not have a radio", _ruck);
	};
};

_hasRadio
