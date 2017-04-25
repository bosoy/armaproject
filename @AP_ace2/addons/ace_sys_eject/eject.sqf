// eject.sqf
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfgV (configFile >> "cfgVehicles" >> typeOf (_vehicle))
private ["_typeOfP", "_offdir", "_boost", "_engine", "_vectorDir", "_vectorUp", "_velocity", "_ivelocity", "_seat", "_upwvel", "_newvel", "_cycle", "_smoketrail", "_light", "_dir", "_sdir", "_offvel", "_vupx", "_vupz", "_vupy", "_seatpos", "_sepvel", "_parachute"];
/* This script is executed by the "Eject" addAction command. Parts of this script are adapted from mando_ejectunit.sqf v1.1 by Mandoble.*/

// Argument(s) passed from addAction command. 0 = the vehicle the event handler is assigned to. 2 = the action index id for this particular addAction command.
PARAMS_2(_vehicle,_ejector);

private ["_offdir"];

// Get ejection seat type
#define __typeOfES (getText (__cfgV >> "ace_ejection_seat"))

// Don't bother the engine with bollocks.
if (isNull _ejector) exitWith { TRACE_1("Null",_ejector); false };
if !(local _ejector) exitWith { TRACE_1("Remote",_ejector); false };
if !(_ejector isKindOf "CAManBase") exitWith { TRACE_1("Vehicle",_ejector); false };
// if !(_ejector in _vehicle) exitWith { TRACE_1("Outside",_ejector); false };	// Not the problem
if !(isNil {_ejector getVariable QGVAR(Eject_AI)}) exitWith { false };
_ejector setVariable [QGVAR(Eject_AI), true];

// Make other crew members run this script, if they haven't already
if (!isNull (driver _vehicle)) then {
	if (isNil {(driver _vehicle) getVariable QGVAR(Eject_AI)}) then {
		[QGVAR(sejt), [_vehicle, driver _vehicle]] call CBA_fnc_globalEvent;
	};
};
if (!isNull (gunner _vehicle)) then {
	if (isNil {(gunner _vehicle) getVariable QGVAR(Eject_AI)}) then {
		[QGVAR(sejt), [_vehicle, gunner _vehicle]] call CBA_fnc_globalEvent;
	};
};

// Set parachute type
_typeOfP = switch (side _ejector) do {
	case west: { "ParachuteWest" };
	case east: { "ParachuteEast" };
	case resistance: { "ParachuteG" };
	default { "ParachuteC" };
};

// offset L/R for front/back seat
#define __crew (configfile >> "CfgVehicles" >> typeOf _vehicle >> "ACE_SYS_EJECT_MULTICREW")
if (isNumber __crew) then {
	if (getNumber __crew == 1) then {
		if (_ejector == (driver _vehicle)) then {
			_offdir = -90;
		} else {
			_offdir = 90;
			sleep 0.4; // Gunner ejects after pilot
		};
	};
//	 else {
//		_offdir = 0;
//	};
} else {
	_offdir = 0;
};

// 0/0 issue, now uniform/constant
_boost = 50;

// Ka-50/52 rotor blades
if ((_vehicle isKindOf "Kamov_Base") && {!("500Rnd_TwinVickers" in magazines _vehicle)}) then {
	[QGVAR(jbld), _vehicle] call CBA_fnc_globalEvent;
	sleep 0.3;
};

// If the ejector is the player, do a few extra things

if (_ejector == player) then {
	ACE_EjectingBool = true;
	0 spawn {
		"colorCorrections" ppEffectEnable true;
		"colorCorrections" ppEffectAdjust [0.01, 0.25, 0.05, [0.0, 0.0, 0.0, 0.0], [1, 1, 1, 0.2],  [1, 1, 1, 1]];
		"colorCorrections" ppEffectCommit 0;

		"dynamicBlur" ppEffectEnable true;
		"dynamicBlur" ppEffectAdjust [10];
		"dynamicBlur" ppEffectCommit 0;
		sleep 4;
		"colorCorrections" ppEffectAdjust [1, 1, 0, [0,0,0,0], [0,0,0,1], [0,0,0,1]];
		"colorCorrections" ppEffectCommit 15;
		"dynamicBlur" ppEffectAdjust [0];
		"dynamicBlur" ppEffectCommit 10;
		sleep 15;
		"colorCorrections" ppEffectEnable false;
		"dynamicBlur" ppEffectEnable false;
		titleFadeOut 20;
	};
};


_vectorDir = vectorDir _vehicle;
_vectorUp = vectorUp _vehicle;
_velocity = velocity _vehicle;
_ivelocity = _velocity;
_seat = __typeOfES createVehicle [0,0,100 + random 400];
//_seat setPos (_vehicle modelToWorld [0,4,1]);
//_seat setVectorDirAndUp [_vectorDir, _vectorUp];
//_seat setVelocity _velocity;
_seat attachTo [_vehicle, [0,4,1]];
sleep 0.01;
waitUntil { (_seat distance _vehicle < 20) };
detach _seat;

// Make ejector get out of the vehicle.
if (vehicle _ejector == _vehicle) then {
	_engine = isEngineOn _vehicle;
	moveOut _ejector;
	waitUntil {!(_ejector in _vehicle)};
	if (_engine && {(!isEngineOn _vehicle)}) then { _vehicle action ["EngineOn", _vehicle] };
};

_deleteMe = vehicle _ejector;
if (_deleteMe isKindOf "ParachuteBase") then {
	deleteVehicle _deleteMe;
};

// Fix for AI not beign moved into seats.
waitUntil {
	_ejector moveInDriver _seat;
	sleep 0.005;
	vehicle _ejector == _seat
};
_seat lock true;

_vectorUp = vectorUp _seat;
_upwvel = [_vectorUp,_boost] call CBA_fnc_scaleVectTo;
_newvel = [_velocity,_upwvel] call ACE_fnc_vectorAdd;

// Spawn booster rocket flame effect + sound on all machines:
[QGVAR(ejfl), _seat] call CBA_fnc_globalEvent;

// Rocket motor simulation
_dir = (((getDir _seat) + _offdir) mod 360);
_sdir = [_dir] call CBA_fnc_simplifyAngle;
_offvel = [5,_sdir,4] call CBA_fnc_polar2vect;
_newvel = [(velocity _seat),_offvel] call ACE_fnc_vectorAdd;
_t1 = time;
_offVelM = 0; // offset: for separating pilot/gunner
while {(time - _t1) < 0.25} do { // Gradually point seat more upright + apply thrust in upvector of seat
	_seat setVelocity _newvel;
	_vectorUp = vectorUp _seat;
	_vupx = (_vectorUp select 0) * 0.95;
	_vupz = (_vectorUp select 1) * 0.95;
	_vupy = (_vectorUp select 2) + ((1 - (_vectorUp select 2)) / 20);
	_seat setVectorUp [_vupx,_vupz,_vupy];
	if (_vupy < -0.1) then { _boost = 25 } else { _boost = 50 }; // don't apply as much thrust if inverted
	_upwvel = [[_vupx, _vupz, _vupy],_boost] call CBA_fnc_scaleVectTo;
	_offvel = [_offvelM, _sdir, 0] call CBA_fnc_polar2vect;
	_newvel = [_velocity,_upwvel] call ACE_fnc_vectorAdd;
	_newvel = [_newvel, _offvel] call ACE_fnc_vectorAdd;

	_t2 = time;
	sleep 0.01;
	_dT = time - _t2;
	_offVelM = _offVelM + _boost*_dT; // gradually increase the offset booster
};

//don't open parachute if over 600m - I think IRL it's more like 4000m, but this is better for gameplay... about 1.5mins of parachute hang-time
while { (getPos _seat select 2 > 600) } do {
	if (alive _seat) then {
		_vectorUp = vectorUp _seat;
		_vupx = (_vectorUp select 0) * 0.95;
		_vupz = (_vectorUp select 1) * 0.95;
		_vupy = (_vectorUp select 2) + ((1 - (_vectorUp select 2)) / 20);
		_seat setVectorUp [_vupx,_vupz,_vupy];
		sleep 0.025;
	};
};

if ((_seat isKindOf "ParachuteBase") && {(alive _ejector)} && {(alive _seat)}) then {
	_if_AI_acts_weird = "_ejector switchMove 'para_pilot'" // What was the purpose of nil?
} else {
	_parachute = _typeOfP createVehicle [0, 0, (100 + random 400)];
	_parachute setVelocity velocity vehicle _ejector;
	_parachute attachTo [_seat, [0,0,0]];

	sleep 1.25;
	detach _parachute;
	sleep 0.001;
	_seat attachTo [_parachute, [0,0,0]];
	_t1 = time;
	[_seat, _parachute] spawn {
		_seat = _this select 0;
		_parachute = _this select 1;
		waitUntil {((velocity _parachute) select 2) < 5};
		detach _seat;
	};

	while {((vehicle _ejector) != _ejector)} do {
		_seat lock false;
		moveOut _ejector;
		sleep 0.01;
	};
	_seat lock true;
	if (_ejector == player) then 
	{
		ACE_EjectingBool = false;
	};

	while {(TypeOf(vehicle _ejector)) != _typeOfP} do {
		_ejector moveInDriver _parachute;
		sleep 0.01;
	};

	if (_ejector == player) then { _ejector setVariable [QGVAR(ChuteOpen),1] };

	if ((isNull driver _vehicle) && {(isNull gunner _vehicle)}) then {
		[QGVAR(ooc), _vehicle] call CBA_fnc_globalEvent;
	};

	_ejector setVariable [QGVAR(Eject_AI), nil];

	[_seat, 20] call ACE_fnc_add2sfifo;
	// Spawn survival gear when ejecting over water
	[_ejector] spawn FUNC(water_survival);
};
TRACE_1("Exiting Script",_jumper);