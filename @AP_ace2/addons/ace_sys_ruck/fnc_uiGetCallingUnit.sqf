//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

#define SPACE 32

private["_str","_word_count","_arrayName","_name","_unit","_arrayNum","_num","_units"];

_unit = player; //fallback

//Grab the text from the dialog
_str = ctrlText(_this displayCtrl UNIT_TITLE_IDC);


// Grab the name from the text
_word_count = 1;
_arrayName = [];
_arrayNum = [];
{
	if ( _word_count >= 4 ) then {
		PUSH(_arrayName,_x);
	} else {
		if ( _x == SPACE ) then {
			INC(_word_count);
		};
	};
	if (_word_count == 1) then {
		PUSH(_arrayNum,_x);
	};
} forEach toArray(_str);


// Find the unit with matching name in the commanded group
_name = toString(_arrayName);

_units = units player;
{
	if ((name _x) == _name && {_x != player}) exitWith { _unit = _x; };
} forEach _units; //only commanded group able to interact with gear dialog

if ((name player) == _name && {_unit != player}) then { //duplicate names
	//use unit number to identify
	_num = parseNumber(toString(_arrayNum)) - 1;
	_unit = _units select _num;
};

_unit
