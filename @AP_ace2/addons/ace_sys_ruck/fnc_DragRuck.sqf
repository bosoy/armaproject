//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_ruck_crate", "_unitpos", "_unitdir"];
if (isNil "ace_sys_cargo_fnc_drag") exitWith {LOG("Drag function not present"); false};
if (player getVariable ["ace_sys_cargo_dragging", false]) exitWith {LOG("Already dragging"); true};

_ruck_crate = nearestObject [player, "ACE_Rucksack_crate"];

if (isNull _ruck_crate) then {
	(localize "STR_DN_ACE_RUCK_NOT_IN_RANGE") spawn ace_fnc_visual;
} else {
	if ((_ruck_crate distance player) > 10) then {
		(localize "STR_DN_ACE_RUCK_NOT_IN_RANGE") spawn ace_fnc_visual;
	} else {
		_unitpos = getPosASL player;
		_unitdir = getDir player;
		_unitpos = [(_unitpos select 0) + (sin _unitdir),(_unitpos select 1) + (cos _unitdir),_unitpos select 2];
		_ruck_crate setPosASL _unitpos;
		[_ruck_crate] spawn ace_sys_cargo_fnc_drag;
	};
};

true
