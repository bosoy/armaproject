//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_emitters","_int","_looptime"];

PARAMS_1(_plane);
_plane setVariable [QGVAR(running), true, true];

#define __maxint 2
#define __boost 0.4
#define __maxspeed 1300

#define __cfg configFile >> "CfgVehicles" >> (typeOf _plane)

private["_ab_array","_ab_number"];
_ab_array = getArray(__cfg >> "ace_afterburner_engines");
_ab_number = count _ab_array;
TRACE_2("AB STUFF",_ab_array,_ab_number);
_int = 0;
_looptime = 0.1;

private ["_boost_a","_boost","_maxspeed_a","_maxspeed"];
_boost_a = getArray(__cfg >> "boost");
_maxspeed_a = getArray(__cfg >> "maxSpeed");

_boost = if (count _boost_a > 0) then {
	_boost_a select 0
} else {
	__boost
};

_maxspeed = if (count _maxspeed_a > 0) then {
	_maxspeed_a select 0
} else {
	__maxspeed
};

private ["_leftengine","_rightengine","_middleengine"];
switch (_ab_number) do {
	case 1: {
		_middleengine = "#particlesource" createVehicleLocal position _plane;
		_emitters = [_middleengine];
	};
	case 2: {
		_rightengine = "#particlesource" createVehicleLocal position _plane;
		_leftengine = "#particlesource" createVehicleLocal position _plane;
		_emitters = [_leftengine,_rightengine];
	};
};
TRACE_4("EMIT",_middleengine,_rightengine,_leftengine,_emitters);

{ _x setParticleRandom [0.05,[0.05,0.05,0.05],[0.05,0.05,0.05],0,0.8,[0.1,0.1,0.1,0],0,0] } foreach _emitters;
{ _x setDropInterval 0 } foreach _emitters;

while { alive _plane && {GVAR(afterburner)} } do {
	if (isengineon _plane && {driver _plane == player}) then {
		if (_int < __maxint) then { _int = _int + 0.1*(10*_looptime); };
		if (speed _plane < _maxspeed) then {
			_plane setVelocity [(velocity _plane select 0)+((vectordir _plane) select 0)*((_boost*_int/2)*(10*_looptime)),(velocity _plane select 1)+((vectordir _plane) select 1)*((_boost*_int/2)*(10*_looptime)),(velocity _plane select 2)+((vectordir _plane) select 2)*((_boost*_int/2)*(10*_looptime))];
		};
		if (fuel _plane > 0) then { _plane setFuel ((fuel _plane)-((1/1200)*(2.5*_looptime))); };
	} else {
		if (_int > 0) then { _int = _int - 0.2*(10*_looptime); };
	};
	for "_i" from 0 to (_ab_number - 1) do {
		_pos = (_ab_array select _i);
			// TESTING
			//#define __SETUP
			#ifdef __SETUP
				_pos = [0,-5,0];
			#endif
		TRACE_1("",_pos);
		(_emitters select _i) setParticleParams ["\Ca\data\cl_exp","","Billboard",1,0.07,_pos,[(velocity _plane select 0) - ((vectordir _plane) select 0)*30,(velocity _plane select 1) - ((vectordir _plane) select 1)*30,(velocity _plane select 2) - ((vectordir _plane) select 2)*30],1,1.2745,1,0,[0.6+(2*(speed _plane/_maxspeed)),0.5+(10*(speed _plane/_maxspeed))],[[0.040,0.100,0.900,0.1500*_int],[0.200,0.200,0.800,0.1000*_int],[0.500,0.200,0.000,0.0250*_int],[0.000,0.000,0.000,0.0000*_int]],[0],0,0,"","",_plane];
		//(_emitters select _i) setPos (getPos _plane);
		TRACE_1(EMIT SELECT I, (_emitters select _i));
	};

	if (_int > 0) then {
		{ _x setDropInterval 0.001 } foreach _emitters;
		_plane say "ace_fx_planeABurner";	// publish to clients ? loud enough ?
	} else {
		{ _x setDropInterval 0 } foreach _emitters;
	};
	_looptime = time;
	sleep 0.05;
	_looptime = time - _looptime;
};

{ _x setDropInterval 0 } foreach _emitters;

#define DELVEH(VAR1) if (!isNil 'VAR1' && {!isNull VAR1}) then { deleteVehicle VAR1 }
DELVEH(_leftengine);
DELVEH(_rightengine);
DELVEH(_middleengine);

_plane setVariable [QGVAR(running), false, true];

false