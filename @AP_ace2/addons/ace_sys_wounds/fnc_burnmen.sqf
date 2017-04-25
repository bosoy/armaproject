// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_v", "_int", "_t", "_tdiff", "_fade", "_fl", "_li", "_snd", "_isBurning", "_sm"];

// _v = vehicle, _int = intensitiy (0.7-10), _t = time scripte started
PARAMS_4(_v,_int,_t,_fade);
if (isNull _v) exitWith {TRACE_1("Null vehicle",_v)};
if (isNil "_int") exitWith {TRACE_1("Nil int",_int)};
_v setVariable ["ace_is_burning", true]; // TODO: Check if already burning, abort?
_tdiff = time - _t;
if (_fade) then {_int = _int - ((_tdiff * 0.02) / 3)};

if (!isDedicated) then {
	_fl = "#particlesource" createVehicleLocal getpos _v;
	_fl attachto [_v,[0,0,2]]; // does it even recognize 2 ?
	_fl setdropinterval 0.03;
	
	_sm = "#particlesource" createVehicleLocal getpos _v;

	_li = "#lightpoint" createVehicleLocal getpos _v;
	_li setLightBrightness 0;
	_li setLightAmbient[0.8, 0.6, 0.2];
	_li setLightColor[1, 0.5, 0.4];
	_li lightAttachObject [_v, [0,0,0]];
};

if (isServer) then {
	_snd = createSoundSource ["Sound_Fire", getpos _v, [], 0];
	_snd attachto [_v,[0,0,0], "destructionEffect1"];
};

// http://community.bistudio.com/wiki/ParticleArray
while {_int > 3 && {(_v getVariable "ace_is_burning")} && {(getpos _v select 2 > -2.5)} && {!isnull _v}} do {
	#ifdef DEBUG_MODE_FULL
	TRACE_2("in particle loop",_int,_v);
	#endif

	_pos = getPos _v;
	if (surfaceIsWater _pos && {(_pos select 2) < 1}) exitWith {
		// schtop burning in water!
	};

	if (!isDedicated) then {
		_fl setParticleParams
		[["\Ca\Data\ParticleEffects\Universal\Universal", 16, 10, 32],"",
		"Billboard",
		1,
		0.7, //0.3*_int, // Lifetime
		"destructionEffect2",
		[0, 0, 1], //[0, 0, 0.17*_int], // Position
		0, 10, 7.9, 1,
		[0.3, 0.3],//[0.3*_int, 0.05*_int], // Scale ?
		[[1,1,1,-0], [1,1,1,-1], [1,1,1,-1], [1,1,1,-1], [1,1,1,-1], [1,1,1,0]],
		[0.5, 1],
		1,
		0,
		"",
		"",
		_v];
		_fl setParticleRandom
		[0.04*_int,
		//[0.1*_int, 0.1*_int, 0.1*_int],
		[0.05,0.05,2],
		[0.05*_int, 0.05*_int, 0.05*_int],
		0,
		0.06*_int,
		[0, 0, 0, 0], 0, 0];
		
		
		_sm setParticleCircle [0, [0, 0, 0]];
		_sm setParticleRandom [0, [0.25, 0.25, 0], [0.2, 0.2, 0], 0, 0.25, [0, 0, 0, 0.1], 0, 0];
		_sm setParticleParams [["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48], "", "Billboard", 1, 8, [0, 0, 1.1], [0, 0, 1], 0, 10, 7.9, 0.066, [1, 3, 6], [[0.5, 0.5, 0.5, 0.15], [0.75, 0.75, 0.75, 0.075], [1, 1, 1, 0]], [0.125], 1, 0, "", "", _v];
		_sm setDropInterval 0.15;

		_li setLightBrightness (_int/30);
	};

	// TODO: Propagate to other objects/vehicles

	// Propagate to AI Soldiers
	[_v, 1.5] call ace_sys_destruction_fnc_propagateFire;

	if (_fade) then {_int = _int - 0.03 - rain / 10};

	sleep 3;
};

if (!isNull _v) then {
	_v setVariable ["ace_is_burning", false];
};

if (!isDedicated) then {
	deletevehicle _fl;
	deletevehicle _li;
	deleteVehicle _sm;
};

if (isServer) then {deletevehicle _snd};
