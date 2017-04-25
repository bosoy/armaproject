#include "script_component.hpp"

#define __engines getNumber configFile >> "cfgVehicles" >> typeOf _unit >> "ace_engines"
#define __verticalClimbSpeed getNumber configFile >> "cfgVehicles" >> typeOf _unit >> "ace_verticalClimbSpeed"
#define __eArmor 25
#define __minHit 5
#define __gravity -9.8

while {true} do {
	_vehicles = vehicles;
	if !(local _x && {alive _x} && {(typeOf _x isKindOf "Helicopter")}) then {_vehicles = _vehicles - [_x]}} forEach _vehicles;
	_count = count _vehicles;
	{
		private ["_unit","_enginesOn","_engines","_engineStatus"];
		_unit = _x;
		_engineOn = isEngineOn _unit;
		_time = time;
		_timeprev = _unit getVariable [QGVAR(timePrev), _time];
		_timeDiff = _time - _timePrev;
		_unit setVariable [_timePrev,time];

		_velocity = velocity _unit;
		_velocityPrev = _unit getVariable [QGVAR(_velocityPrev), [0,0,0]];
		_velocityPrev set [2,(_velocityPrev select 2) - (_gravity min (((getPos _unit) select 2) min 30))*_time];	// ToDo: transitional lift
		_load = (_velocityPrev distance _velocity) / (_time * __verticalClimbSpeed);
	// Left engine data
		// Damage
		_D1 = _unit getVariable [QGVAR(D1), 0];
		// Temperature
		_T1 = _unit getVariable [QGVAR(T1), 0];
		// Power
		_P1 = 1 - _D1;
	// Right engine data
		// Damage
		_D2 = _unit getVariable [QGVAR(D2), 0];
		// Temperature
		_T2 = _unit getVariable [QGVAR(T2), 0];
		// Power
		_P2 = 1 - _D2;
	// Total power
		_power = _P1 + _P2;	// Up to 2
	// Load per engine
		// Left
		_L1 = _load * _P1/_power;
		// Right
		_L2 = _load * _P2/_power;
	// Can it withstand it?
		// Left
		_O1 = _L1/_P1;
		// Right
		_O2 = _L2/_P2;
	// Will it overheat?
		_T1 = _T1

		_unit setVariable [QGVAR(D1), _D1, true];
		_sleep = 10/sqrt(_count max 1);
	} forEach _vehicles;
	_sleep = 10/sqrt(_count max 1);
};
