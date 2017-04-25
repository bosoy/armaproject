// #define DEBUG_MODE_FULL
// Catastrophic destruction of T-72 MBTs
// By zGuba
// ToDo: config reader
#include "script_component.hpp"

private ["_tankFuel","_turretClass","_tankDir","_tankUp","_weapon","_turretDir","_turretUp","_dispersion","_speed","_speed0","_speed1","_speed2"];

PARAMS_1(_tank);
if !(local _tank) exitWith { TRACE_1("Not local",""); };
_tankFuel = fuel _tank;
if (_tankFuel == 0) exitWith { TRACE_1("No fuel",""); };
if (4 < random 5) exitWith {};	// Comment if sure

[QGVAR(hide_turret), [_tank,1,""]] call CBA_fnc_globalEvent;

// Hide otocVez and beyond
_tank animate ["turret_hide",1];

_turretClass = "ACE_T72WreckTurret";

// Perish crew
_tank call FUNC(killcrew);

// ToDo: fancy cookoff FX!

// Tank orientation
_tankDir = vectorDir _tank;
_tankUp = vectorUp _tank;

// Turret direction
_weapon = (weapons _tank) select 0;
_turretDir = _tank weaponDirection _weapon;
_turretDir = ((_turretDir select 0) atan2 (_turretDir select 1)) - (direction _tank);

_turret = _turretClass createVehicle [0,0,0];
sleep 0.1;

_turret attachTo [_tank,[0,0,1],"turretAttachPoint"];
_turret setDir _turretDir;
_turret setDamage 1;
waitUntil {(_turret distance _tank) < 10};
"ACE_HelicopterExploBig" createVehicle getPos _turret;
detach _turret;	// exactly that's what happens
_dispersion = random 360;
_speed = 9 + random 9;

_turretUp = vectorUp _turret;
_speed0 = _speed * (_turretUp select 0) + (3 * cos (_dispersion));
_speed1 = _speed * (_turretUp select 1) + (3 * sin (_dispersion));
_speed2 = _speed * (_turretUp select 2);

_turret setVelocity [_speed0, _speed1, _speed2];

// Stabilize turret
waitUntil {sleep 10; (velocity _turret call ACE_fnc_magnitude) < 1};
_turret setVelocity [0,0,0];
_turret setPosASL getPosASL _turret;

[_turret, 600] call ACE_fnc_add2fifo;