#include "script_component.hpp"

private ["_ar"];
_ar = [player] call CBA_help_fnc_describe;
copyToClipboard str(_ar);

_i = 0;
{
	_ar set [_i, [_x, "<br />"] call CBA_fnc_join];
	ADD(_i,1);
} forEach _ar;
hint parseText ([_ar, "<br /><br />"] call CBA_fnc_join);
