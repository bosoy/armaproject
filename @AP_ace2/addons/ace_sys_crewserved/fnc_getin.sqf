#include "script_component.hpp"

private["_MG","_unit","_actor"];

if (count _this == 1) then {
	call (_this select 0);

	_MG = ACE_MG;
	ACE_MG = nil;
	_unit=player;
	_actor=player;
} else {
	_unit  = _this select 0;
	_actor = _this select 1;
	_MG	= nearestObject[_unit,'StaticWeapon'];
};
if (_actor != _unit) exitWith {};

if (isnil "_MG") exitWith {
	[localize "STR_ACE_CREW_ERR_NOWEP",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};
_busy = _MG getVariable [QGVAR(busy), false];
if (_busy) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

// Gunner already in?
_gunner = gunner _MG;
if (!isNull _gunner && {alive _gunner}) exitWith {
	[localize "STR_ACE_CREW_ERR_OCC",[1,0,0,1],true,0] spawn ace_fnc_visual;
	closeDialog 0;
};

closeDialog 0;

[_unit,_MG] spawn {
	if !(isNull gunner (_this select 1)) then {
		moveOut (gunner (_this select 1)); // not sure if needed
	};
	sleep 1;
	(_this select 0) action ["getInGunner", (_this select 1)];
};
