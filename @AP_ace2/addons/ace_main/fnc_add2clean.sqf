/* ----------------------------------------------------------------------------
Function: ACE_fnc_add2Clean

Description:
	Add an item to a timed cleanup list. Item is automatically removed after it's lifetime expires.

Parameters:
	_item - Item to be removed. [Object]
	_lifetime - Number of seconds for item to live ( Optional, default 1800 ) [Number]

Returns:
	nil

Example:
	(begin example)
		[_ShellCrater, 600] call ACE_fnc_add2Clean;
	(end)

Author:
	Xeno, (c) 2010
---------------------------------------------------------------------------- */
#include "script_component.hpp"

private ["_deltime"];

// default delete time 30 minutes if not specified
_deltime = if (count _this > 1) then {_this select 1} else {1800};

GVAR(clean_array) set [count GVAR(clean_array), [_this select 0, time + _deltime]];
