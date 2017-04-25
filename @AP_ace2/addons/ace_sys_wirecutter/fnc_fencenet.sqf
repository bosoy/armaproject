// 2009 by Xeno

#include "script_component.hpp"

private ["_no","_fence"];

_no = nearestObjects [_this, [], 2];

_fence = objNull;
{
	_str = toUpper str(_x);
	if (_str call FUNC(fencestr)) exitWith {
		_fence = _x;
	};
} forEach _no;

if (isNull _fence) exitWith {};

_fence setDamage 1;
