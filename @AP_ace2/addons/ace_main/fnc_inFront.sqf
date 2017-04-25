/* ----------------------------------------------------------------------------
Function: ACE_fnc_inFront

Description:
	Function to check if Object2 is in front of Object1

Parameters:
	Object1, Object2. [Object]
	Offset [Scalar]
	
Returns:
		bool

Examples:
	(begin example)
		[Car1,player] call ACE_fnc_inFront;
	(end)

Author:
	ACE Team
---------------------------------------------------------------------------- */
// fnc_inFront.sqf

#include "script_component.hpp"

PARAMS_3(_object1,_object2,_offset);

if (_object2 in _object1) exitWith {false};

// TODO: Check water
// TODO: Check air

_p1 = getPos _object1;
_p2 = getPos _object2;

_d = vectorDir _object1;

((_p1 select 0)*(_d select 0)+(_p1 select 1)*(_d select 1)+_offset < (_p2 select 0)*(_d select 0)+(_p2 select 1)*(_d select 1))
