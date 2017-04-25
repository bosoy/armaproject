/* ace_sys_combatdeaf | (c) 2008, 2009, 2010 by rocko and rommel */

//#define DEBUG_MODE_FULL

#include "script_component.hpp"

#define __own_distance 2
#define __max_distance 5
#define __blur_delay 0.075

PARAMS_5(_hearer,_shooter,_distance,_weapon,_muzzle);

// leads to nil value for QGVAR(dv) and breaks the combatdeaf fsm
if (_weapon == "Throw") exitWith {};

// Minimise processing by doing the exit checks straight away
if (player != _hearer || {_distance > __max_distance}) exitWith { TRACE_1("Exit: Distance",""); };
if (_hearer call ACE_fnc_hasCrewProtection || {([_hearer] call ace_sys_goggles_fnc_earprotection)} || {(_hearer getVariable ["ACE_CrewProtection_combatdeaf",false])}) exitWith { TRACE_1("Earprotection",""); };

// There will be no deafening for the _shooter if caliber is < 7.62
// 7.62 and above will slowly increase the deafening, but needs a lot of rounds, maybe ~30 in quick succession
// Also determine by velocity speed of round, the higher the velocity the higher the igniting shit > louder

_magazine = (getArray(configFile >> "CfgWeapons" >> _weapon >> "magazines")) select 0;
_ammo = getText(configFile >> "CfgMagazines" >> _magazine >> "ammo");
_initSpeed = getNumber(configFile >> "CfgMagazines" >> _magazine >> "initSpeed"); //diag_log _initSpeed;
_caliber = getNumber(configFile >> "CfgAmmo" >> _ammo >> "caliber"); //diag_log _caliber;
//Exit here if caliber is < 0.83 || _initSpeed < 700
if (_caliber < 0.83 || {_initSpeed < 205}) exitWith { TRACE_1("Low shit",""); };

// Check to see if player is the shooter (all distance checks are done, so now we can modify it for the FX...)
if (_shooter == _hearer || {vehicle _shooter == vehicle _hearer}) then {_distance = __own_distance; TRACE_1("Shooter is hearer",""); };

#ifndef DEBUG_MODE_FULL
	// Complex formula, calculate deaf threshold
	_d = (_caliber/3) * (_initspeed/1000) * (0.9475/_distance);
#else
	//CALDIV = 3; ISPDDIV = 1000; DISTF = 0.9475;\\
	_d = (_caliber/CALDIV) * (_initspeed/ISPDDIV) * (DISTF/_distance);
#endif

// SYS_COMBAT DEAFNESS
player setvariable [QGVAR(dv),(player getvariable [QGVAR(dv),0]) + _d];

#ifdef DEBUG_MODE_FULL
	hint str(player getvariable QGVAR(dv));
#endif
	
// POST PROCESS EFFECTS
[_distance] spawn { // parameters distance
	//TRACE_1("Blurring...","");
	private ["_i", "_b", "_distance"];
	PARAMS_1(_distance);
	_i = __max_distance - _distance; // 5 - 2;
	_b = 0.5 / _distance; // As distance decreases, blur increases //
	GVAR(blur) ppEffectEnable true;
	GVAR(blur) ppEffectAdjust [(__max_distance / (7*_distance)) + _b];
	GVAR(blur) ppEffectCommit __blur_delay;
	sleep (__blur_delay * 2);
	while { _i > 0 } do {
		GVAR(blur) ppEffectAdjust [_i - _b];
		GVAR(blur) ppEffectCommit (__blur_delay / 2);
		_i = _i - 1;
		sleep (__blur_delay / 2.1);
	};
	GVAR(blur) ppEffectAdjust [0];
	GVAR(blur) ppEffectCommit __blur_delay;
	sleep __blur_delay;
	GVAR(blur) ppEffectEnable false;
};
