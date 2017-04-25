/* ace_sys_craters | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

#define __cfgW configFile >> "CfgWeapons" >> _weapon
#define __cfgA configFile >> "CfgAmmo" >> _ammo
#define __craterlist []
#define __krambambuli getText(__cfgA >> "CraterEffects")

private ["_ammo", "_crater"];
_ammo = _this select 4;
_crater = __krambambuli;
if !(_crater in __craterlist) exitWith { TRACE_1("No crater needed",""); };

_this spawn {
	private["_ammo", "_object", "_crater", "_pos", "_newpos", "_c"];
	_pos = [0, 0, 0];
	_range = 5;
	_model = "";
	_ammo = _this select 4;
	_object = _this select 6;

	_crater = __krambambuli;
	_model = "ACE_" + _crater;

	// Insisto id telum
	_pos = getPosATL _object;
	while { alive _object && {!isNull _object} } do {
		_pos = getPosATL _object;
		sleep .02;
	};
	// Telum infixium
	if ( isOnRoad _pos && {(_crater in ["HEShellCrater", "HERocketCrater"])} ) exitWith { TRACE_1("HE Shell on concrete",""); };

	// Verify if position is flat
	_newpos = _pos isFlatEmpty [5, 0, 0.5, 5, 0, false, _object];
	if (count _newpos == 0) exitWith { TRACE_1("No space for crater object",""); };
/*
	TRACE_1("Spawn crater","");
	_pos set [2, 0]; //detonatation is 1m above the ground, and we don't want floating craters ever anyway
	_c = _pos createVehiclelocal _model;
*/
	// New Cleaner
	switch (toUpper _crater) do {
		case "BOMBCRATER": { [_c, 30] call ACE_fnc_add2fifo; };
		case "HESHELLCRATER": { [_c, 600] call ACE_fnc_add2clean; };
		case "ARTYSHELLCRATER": { [_c, 600] call ACE_fnc_add2clean; };
		case "HEROCKETCRATER": { [_c, 600] call ACE_fnc_add2clean; };
		case "NUKECRATER": { [_c, 30] call ACE_fnc_add2fifo; };
	};
};
