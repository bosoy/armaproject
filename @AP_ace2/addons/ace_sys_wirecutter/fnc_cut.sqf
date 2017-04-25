// 2009 by Xeno

#include "script_component.hpp"

private ["_no", "_fence", "_str", "_pdir"];

_no = nearestObjects [player, [], 3];

_fence = objNull;
{
	_str = toUpper str(_x);
	if (_str call FUNC(fencestr)) exitWith {
		_fence = _x;
	};
} forEach _no;

if (isNull _fence) exitWith {
	(localize "STR_DN_ACE_NOFENCE") spawn ace_fnc_visual;
};

if (!alive _fence) exitWith {
	(localize "STR_DN_ACE_NOFENCE") spawn ace_fnc_visual;
};

_posfence = position _fence;
_posp = position player;
_pdir = (((_posfence select 0) - (_posp select 0)) atan2 ((_posfence select 1) - (_posp select 1))) % 360;
_pdir = _pdir - (direction player);

if (_pdir < 0) then {_pdir = _pdir + 360};
if (_pdir > 360) then {_pdir = _pdir - 360};

if (_pdir > 90 && {_pdir < 270}) exitWith {
	(localize "STR_DN_ACE_NOFENCE") spawn ace_fnc_visual;
};

player setVariable ["ACE_PB_Result", 0];
[12,[""],true,true] spawn ace_progressbar;
playSound "ace_wire_cut";
[_posfence] spawn {
	PARAMS_1(_posfence);
	waitUntil { (player getVariable "ACE_PB_Result" != 0) };
	if (player getVariable "ACE_PB_Result" == 1) then {
		[QGVAR(cut), _posfence] call CBA_fnc_globalEvent;
	};
};
