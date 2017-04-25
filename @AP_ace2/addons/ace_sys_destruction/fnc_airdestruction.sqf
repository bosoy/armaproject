#include "script_component.hpp"

private ["_v", "_int", "_t", "_fl", "_sm", "_i", "_dr", "_tv", "_expl", "_pos", "_wave", "_splash", "_velz","_size","_s"];
PARAMS_1(_v);

// Reduce that annoying fire tail when an aircraft is hit (there should only be local flames DIRECTLY on the aircraft, not a 5km tail of fire)
#define __SIZEMOD (speed _v) //((velocity _v) select 2)

_int = (fuel _v) * (8 + random 2);

_size = sizeOf typeOf _v;
if (_size < 6) then {_int = 0};
_s = (sqrt(_size) / 4.5) min 1;	// Scale down for small vehicles
_t = time;

if (!isDedicated) then {
	_fl = "#particlesource" createVehicleLocal getpos _v;
	_fl attachto [_v,[0,0,0],"destructionEffect2"];
	_fl setParticleRandom [0.3*_s, [1*_s, 1*_s, 0], [0, 0, 0], 0, 0.3*_s, [0, 0, 0, 0], 0, 0];

	_fl setParticleParams [
		["\Ca\Data\ParticleEffects\Universal\Universal", 16, 10, 32], //sprite
		"", // obs
		"Billboard", //type
		1, // timer period
		0.5*_s, // lifetime
		"destructionEffect2", //pos 
		[0, 0, 0], //move velo
		0, //rot velo
		10, //weight
		7.9, //volume
		0.075, //rubbing
		[(4*_s)/(__SIZEMOD max 1),(7*_s)/(__SIZEMOD max 1),(9*_s)/(__SIZEMOD max 1),(10*_s)/(__SIZEMOD max 1)], //size
		[[1, 1, 1, -1], [1, 1, 1, -1],[1, 1, 1, -1*_s], [1, 1, 1, -0.5*_s], [1, 1, 1, -0]], //color
		[1,0.5], //animphase
		1, //random dir period
		0, //random dir inten
		"", //ontimer
		"", //b4 destroy
		_v // object
	];

	_fl setDropInterval _s;
	
	_sm = "#particlesource" createVehicleLocal getpos _v;
	_sm attachto [_v,[0,0,0],"destructionEffect1"];
	_sm setParticleRandom [2*_s, [2*_s, 2*_s, 0], [0, 0, 0], 0, 0.3*_s, [0, 0, 0, 0.1*_s], 0, 0];
	_sm setParticleParams [
		["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48],
		"",
		"Billboard",
		1,
		5*_s,
		"destructionEffect1",
		[0, 0, 5],
		0,
		10,
		7.9,
		0.075,
		[4*_s,8*_s,12*_s,14*_s],
		[[0.3, 0.3, 0.3, 1*_s], [0.45, 0.45, 0.45, 1*_s],[0.6, 0.6, 0.6, 0.6*_s], [0.7, 0.7, 0.7, 0.25*_s], [1, 1, 1, 0]], 
		[0.8,0.3,0.25],
		1,
		0,
		"",
		"",
		_v
	];
	_sm setDropInterval _s;
	_i = 0;
	_dr = 0.2*_s;
	_tv = 11*_s;
};

//Remove weapons/ammo to prevent explosion. Script will create its own explosions (doesnt work?)
removeallweapons _v;

// calculate real fuel amount, even bigger explosion for flying tanker?
if (local _v && {_int >= 1}) then {
	_pos = getPos _v;
	if (_size > 35) then {	// C-130
		_expl = "ACE_HelicopterExploBig" createvehicle _pos;
		_expl setPosASL getPosASL _v;
	} else {
		_expl = "ACE_HelicopterExploSmall" createvehicle _pos;
		_expl setPosASL getPosASL _v;
	};
};

while {_i < 1200 && {((velocity _v select 2) < -20 || {(getPos _v select 2) > 8})} && {!alive _v} && {!isNull _v} && {(getPos _v select 2) > 1}} do {
	if (!isDedicated) then {
		_tv = (velocity _v) distance [0,0,0];
		if (_tv > 2) then {_dr = 1/_tv} else {_dr = 1};
		_fl setDropInterval _dr*_s;
		_sm setDropInterval _dr*_s;
	};
	_i = _i + 1;
	sleep 0.2;
};

_pos = getpos _v;
deletevehicle _fl;
deletevehicle _sm;
if (surfaceiswater _pos && {(_pos select 2) < 9}) then {
	if (!isDedicated) then {
		_wave = "#particlesource" createVehicleLocal getpos _v;
		_wave attachto [_v,[0,0,0],"destructionEffect1"];
		_wave setParticleRandom [0.3*_s, [1*_s, 1*_s, 0], [0.5*_s, 0.5*_s, 0], 0, 0.3*_s, [0, 0, 0, 0], 0, 0];
		_wave setParticleParams [
			["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 13,0], 
			"", 
			"Billboard", 
			1, 
			1.6*_s, 
			"destructionEffect1",
			[0, 0, 0], 
			0, 
			10, 
			7.9, 
			0.075, 
			[3*_s,8*_s],
			[[0.7,0.8,1,0.6*_s],[0.85,0.9,1,0.0]],
			[1000],
			1, 
			0, 
			"", 
			"", 
			_v
		];
		_wave setparticlecircle [2*_s,[0,16*_s,0]];
		_wave setDropInterval 0.0015;

		_splash = "#particlesource" createVehicleLocal getpos _v;
		_splash attachto [_v,[0,0,0],"destructionEffect1"];
		_splash setParticleRandom [2*_s, [2*_s, 2*_s, 0], [2*_s, 2*_s, 7*_s], 0, 0.5*_s, [0, 0, 0, 0], 0, 0];
		_splash setParticleParams [
			["\Ca\Data\ParticleEffects\Universal\Universal", 16, 13, 6, 0], 
			"", 
			"Billboard", 
			1, 
			4*_s, 
			"destructionEffect1",
			[0, 0, 0], 
			0, 
			30, 
			7.9, 
			0.075, 
			[8*_s,15*_s],
			[[0.7,0.7,0.7,1*_s],[1,1,1,0]],
			[1000],
			1,
			0,
			"",
			"",
			_v
		];
		_splash setparticlecircle [2*_s,[0,3*_s,15*_s]];
		_splash setDropInterval 0.002;
	};

	sleep 0.2;
	if (!isDedicated) then {
		deletevehicle _wave;deletevehicle _splash;
	};
} else {
	if (local _v) then {
		_velz = velocity _v select 2;
		if (_velz > 1) then (_v setvelocity [velocity _v select 0,velocity _v select 1,0]);
		// Kaboom
		if (_size > 10 && {_int > 3}) then {
			_expl = "ACE_HelicopterExploBig" createvehicle [_pos select 0,_pos select 1,(_pos select 2) + 1];
			_expl setPos (_v modelToWorld (_v selectionposition "destructioneffect2"));
		} else {
		// Bang bang
			_expl = "ACE_HelicopterExploSmall" createvehicle [_pos select 0,_pos select 1,(_pos select 2) + 1];
			_expl setPos (_v modelToWorld (_v selectionposition "destructioneffect2"));
		};

		_i = 0;
		while {_i < _int min 5} do {
			_i = _i + 1;
			_expl = "ace_fuelexpsmall" createVehicle [-5*_s + (random 10*_s) + (_pos select 0), -5*_s + (random 10*_s) + (_pos select 1),-5*_s + (random 10*_s) + (_pos select 2)];
			sleep random 0.05;
		};

		sleep 0.05;
		[QGVAR(AirDestructionStage2), [_v,_int,_t,_s]] call CBA_fnc_globalEvent;
	};
};