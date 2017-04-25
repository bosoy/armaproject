//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_i", "_space", "_maxCols", "_finalString", "_stringArray"];

PARAMS_2(_row,_string);
_stringArray = toArray _string;

_maxCols = [] call FUNC(getMaxCols);
_space = "";
for "_i" from 0 to (_maxCols - (count _stringArray)) - 1 do {
	_space = _space + " ";
};

_finalString = _space + _string;
TRACE_4("", _row, _space, _string, _finalString);

([_row, _finalString] call FUNC(setRowText))
