// #define DEBUG_MODE_FULL
#define CFGA configFile >> "CfgAmmo" >> _ammo
#include "script_component.hpp"

// IM Event == Global, however fnc_i_m runs these events only where _whoFired == local
// sys_missileguidance types: "saclos", "shturm", "hellfire", "longbow"

private ["_distance", "_enabled", "_failure", "_count", "_laser", "_gunner"];
PARAMS_3(_unit,_ammo,_whoFired);

_enabled = _unit getVariable [QGVAR(shtora), true]; // Set the variable ?
if !(_enabled) exitWith {
	TRACE_1("Abort. Not enabled",_unit);
};

// Shtora Enabled/Disabled on this unit (Player/Action sensitive)?
if !(alive _unit) exitWith {
	TRACE_1("Abort. Unit not alive",_unit);
};

_gunner = gunner _unit;
if (isNull _gunner) exitWith {
	TRACE_1("Abort. No gunner",_unit);
};

_distance = _unit distance _whoFired;
if (_distance < 40) exitWith {
	TRACE_1("Abort. Too close!",_distance);
};

_busy = _unit getVariable [QGVAR(busy_stora), false];
if (_busy) exitWith { TRACE_1("Abort. Already busy",_unit) };
_unit setVariable [QGVAR(busy_shora), true];

_enabled = false; _failure = false; _laser = false;

// Laser
if (getNumber(CFGA >> QGVAR(laser)) == 1) then {
	// Longbow - NOPE. Check actually required ?
	if (getText(CFGA >> "ace_guidance_type") == "longbow") exitWith {
		TRACE_1("longbow",_laser);
	};
	_laser = true;
	_enabled = true;
	_failure = [_whoFired, _unit, objNull] call FUNC(shtora_targeted);
};

// Wire (Saclos)
// TODO: Need special logic for sys_missileguidance! As there's no incomingMissile event played.
if (getNumber(CFGA >> QGVAR(wire)) == 1) then {
	_enabled = true;
	TRACE_2("Wire",_enabled,_failure);
	// IR Jammers - Jam the Missile!
};

// IR (HeatSeek) - NOPE, ONLY ON ARENA
if (getNumber(CFGA >> QGVAR(ir)) == 1) then {
	// _enabled = true;
	TRACE_2("IR",_enabled,_failure);
	// IR Jammers - Jam the Missile!
};

// Radio - NOPE, ONLY ON ARENA
if (getNumber(CFGA >> QGVAR(radio)) == 1) then {
	// _enabled = true;
	TRACE_2("Radio",_enabled,_failure);
	// Radio Jammers - Jam the Missile!
};

if (_failure || {!_enabled}) exitWith {_unit setVariable [QGVAR(busy_shtora), false]}; // Too bad, you're probably gonna die! :D

// Detected, Jam Working..
if (count _this == 3) then {
	PUSH(_this,objNull);
};
PUSH(_this,_laser);

// Need to spawn, otherwise nearestObject null
_this spawn {
	private ["_failure", "_gunner"];
	PARAMS_5(_unit,_ammo,_whoFired,_missile,_laser);
	_failure = false;

	// Seems to happen to some hellfire modes, where incomingMissile EH fires late...
	// TODO: Maybe scan closest missile to tank, or use missile object directly from within sys missileguidance
	if (isNil "_missile") then { _missile = objNull };
	if (isNull _missile) then { _missile = nearestObject [_whoFired, _ammo] };
	if (isNull _missile) exitWith {
		ERROR("Can't find missile");
	};

	if (random 10 > 7) exitWith { _failure = true; TRACE_1("Failure chance",_failure); _unit setVariable [QGVAR(busy_shtora), false] }; // 20% Failure chance

	// TODO: Might wanna consider adding the course change, in sys_missileguidance instead.. (Or move the lasertarget (+override variable)? :D)
	// Expecting the missile to adjust path due to missileguidance loop :P
	_fBla = {
		// _missile setPos [0,0,9999];
		_climb = 60;
		if (alive _missile) then {
			_whoFired setVariable ["ACE_jammed", true];
			_pos = getPos _unit;
			_pos set [2, (_pos select 2) + 4];
			_missile setPos _pos;
			// TODO: Apply in loop
			_velocity = velocity _missile;
			_vectorUp = vectorUp _missile;
			_upwvel = [_vectorUp,_climb] call CBA_fnc_scaleVectTo;
			_newvel = [_velocity,_upwvel] call ACE_fnc_vectorAdd;
			_missile setVelocity _newVel;
			TRACE_5("",_vectorUp,_velocity,_upwvel,_newvel,_pos);
			// [_missile, _climb, 0] call BIS_fnc_setPitchBank;
		};
	};

	if (_laser) then {
		// TODO: Consider changing the laserTarget position instead?
		_laser2 = nearestObject [_unit, "LaserTarget"];
		TRACE_1("Laser",_laser2);
	};

	// Locallity isues? Where to setPos it ? - Actually no, because this is the firer's machine.
	_do = false; _done = false;
	waitUntil {
		// TODO: Make deflect sensitive to distance to missile, when turret direction is correct, incase close by, there's a chance Shtora will fail. Maybe apply dispersion
		if (_missile distance _unit < 25) then { if (!_do) then { if !([_unit, _missile] call FUNC(verifyWeaponDir)) then { _failure = true }; _do = true } };
		// TODO: Move away from tank, instead of disappear :)
		if (_do && {!_failure}) then { _done = true; call _fBla;  }; // TODO: Make sensitive for done?
		_done || {!(alive _missile)}
	};
	if (_laser) then {
		_gunner = gunner _unit;
		if !(isNull _gunner) then { _gunner doWatch objNull };
		_unit setVariable [QGVAR(busy_laser), false];
	};
	_whoFired setVariable ["ACE_jammed", false];
	TRACE_4("Exit",_missile,_do,_failure,_done);
	_unit setVariable [QGVAR(busy_shtora), false];
};
