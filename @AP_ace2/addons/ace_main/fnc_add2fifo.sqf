/* ----------------------------------------------------------------------------
Function: ACE_fnc_add2Fifo

Description:
	Add an item to a queue. Items in excess of the specified purge count will be deleted
	in First-in First-out ( FIFO ) order.

Parameters:
	_item - Item queued for removal. [Object]
	_max_count - Maximum number of instances of this item allowed to exist.

Returns:
	nil

Example:
	(begin example)
		[_BombCrater, 30] call ACE_fnc_add2Fifo;
	(end)

Author:
	Xeno, (c) 2010
---------------------------------------------------------------------------- */
#include "script_component.hpp"

// [object, maxitems before delete] call ace_sys_cleaner_fnc_add2fifo
// deletes first objects immediately if number of items > maxitems

private ["_objs", "_numobjs", "_i", "_ob", "_type"];

_type = typeOf (_this select 0);
_objs = GVAR(fifologic) getVariable _type;
if (!isNil "_objs") then {
	PUSH(_objs,_this select 0);
	_numobjs = count _objs;
	if (_numobjs >= (_this select 1)) then {
		for "_i" from 0 to (_numobjs - (_this select 1)) do {
			_ob = _objs select _i;
			if (!isNull _ob) then {
				deleteVehicle _ob;
			};
			_objs set [_i, objNull];
		};
		_objs = _objs - [objNull];
		GVAR(fifologic) setVariable [_type, if (count _objs > 0) then {_objs} else {nil}]; // have to use setVar here for _objs too as otherwise the array fills up with null objects
	};
} else {
	GVAR(fifologic) setVariable [_type, [_this select 0]];
};
