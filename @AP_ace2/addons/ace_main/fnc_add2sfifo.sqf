/* ----------------------------------------------------------------------------
Function: ACE_fnc_add2sfifo

Description:
	adds an object to the slowly running FIFO

Parameters:
	type (string), add whatever you want as type
	maxitems is only needed in the first call but can be changed during runtime, if not specified standard value 10 is taken

Returns:
	nil

Example:
	["type", object,  maxitems before delete] call ACE_fnc_add2fifo

Author:
	Xeno
---------------------------------------------------------------------------- */
#include "script_component.hpp"

private ["_index", "_objs", "_numobjs", "_i"];

_index = GVAR(sfifo_index) find (_this select 0);
if (_index != -1) then {
	_element = GVAR(sfifo_array) select _index;
	_objs = _element select 1;
	_objs set [count _objs, _this select 1];
	_element set [1, _objs];
	if (count _this > 2) then {
		_element set [0, _this select 2];
	};
	GVAR(sfifo_array) set [_index, _element];
} else {
	GVAR(sfifo_index) set [count GVAR(sfifo_index), _this select 0];
	GVAR(sfifo_array) set [count GVAR(sfifo_array), [if (count _this > 2) then {_this select 2} else {10}, [_this select 1]]];
};

/*
// CBA hash way. Would need changing FSM too :P
private ["_ar", "_objs", "_entry"];

_ar = [GVAR(sfifo), _this select 0] call CBA_fnc_hashGet;
if (count _ar > 0) then {
	_objs = _entries select 1;
	PUSH(_objs,_this select 1);
	if (count _this > 2) then {
		_ar set [0, _this select 2];
	};
} else {
	// Only required when the array is new, limitation due to array reference
	_entry = [if (count _this > 2) then {_this select 2} else {10}, [_this select 1]];
	[GVAR(sfifo), _this select 0, _entry] call CBA_fnc_hashSet;
};
*/
