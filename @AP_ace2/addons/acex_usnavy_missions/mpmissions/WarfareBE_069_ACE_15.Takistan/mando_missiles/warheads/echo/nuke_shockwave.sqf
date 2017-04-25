#include "nuke.h"

private [
	"_pos",
	"_yield",
	"_shockwave_size",
	"_epicenter",
	"_ShockWave_PA",
	"_ShockWave",
	"_delay"
];

_pos = _this select 0;
_yield = _this select 1;

_shockwave_size = 475.6*_yield^(1/3);
_epicenter    = "logic" createVehicleLocal _pos;
_ShockWave    = "#particlesource" createVehicleLocal _pos;

// shock wave front

_ShockWave_PA =  [
	["\Ca\Data\ParticleEffects\Universal\Universal.p3d", 16, 7, 48],
	"",
	"Billboard",
	1,
	DUST_LIFETIME,
	[0, 0, 0],
	[0, 0, 0],
	0.0,
	DUST_DENSITY,
	1,
	DUST_FRICTION,
	[30.0, 60.0],
	[
		[1.0, 1.0, 1.0, 0.3],
		[1.0, 1.0, 1.0, 0.1],
		[1.0, 1.0, 1.0, 0.0]
	],
	[1.0, 0.5],
	0.1,
	1,
	"",
	"",
	_epicenter
];

_delay = _shockwave_size/SHOCK_SPEED;

sleep _delay;

_ShockWave setParticleCircle [
	_shockwave_size*0.1, 
	[_shockwave_size*0.1, _shockwave_size*0.1, 10]];

_ShockWave setParticleRandom [
	2.0,
	[20, 20, 10],
	[DUST_SPEED, DUST_SPEED, 0],
	0,
	0,
	[0, 0, 0, 0.1],
	0,
	0];

_ShockWave setParticleParams _ShockWave_PA;
_ShockWave setDropInterval 0.0002;

for "_i" from 0.2 to 1.0 step 0.1 do {
	_ShockWave setParticleCircle [
		_shockwave_size*_i, 
		[_shockwave_size*(1.1 - _i), _shockwave_size*(1.1 - _i), 10]];
	sleep 0.1;
};

_ShockWave setParticleCircle [
	_shockwave_size, 
	[_shockwave_size, _shockwave_size, 10]];

_ShockWave setDropInterval 0.001;

sleep 6.5;

_ShockWave_PA set [12, 
	[
		[0.80, 0.80, 0.80, 0.3],
		[1.0, 1.0, 1.0, 0.1],
		[1.0, 1.0, 1.0, 0.0]
	]];

_ShockWave setDropInterval 0.01;

for "_i" from 1.0 to 0.1 step -0.1 do {
	_ShockWave setParticleCircle [
		_shockwave_size*_i, 
		[_shockwave_size*_i, _shockwave_size*_i, 10]];

	sleep 0.1;
};

sleep 5;

deleteVehicle _ShockWave;
deleteVehicle _epicenter;
