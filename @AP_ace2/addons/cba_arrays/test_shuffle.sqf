// ----------------------------------------------------------------------------

#include "script_component.hpp"

SCRIPT(test_shuffle);

// ----------------------------------------------------------------------------

private ["_expected", "_result", "_fn"];

_fn = "CBA_fnc_shuffle";
ASSERT_DEFINED(_fn,"");

LOG("Testing " + _fn);

_original = [1, 2, 3];
_result = [_original] call CBA_fnc_shuffle;
ASSERT_OP(count _result,==,count _original,_fn);

{
	ASSERT_OP(_x,in,_original,_fn);
} forEach _result;

// Test depecated version.
_original = [1, 2, 3];
_result = _original call CBA_fnc_shuffle;
ASSERT_OP(count _result,==,count _original,_fn);

{
	ASSERT_OP(_x,in,_original,_fn);
} forEach _result;

// Test depecated version.
_original = [];
_result = _original call CBA_fnc_shuffle;
ASSERT_OP(count _result,==,count _original,_fn);

nil;
