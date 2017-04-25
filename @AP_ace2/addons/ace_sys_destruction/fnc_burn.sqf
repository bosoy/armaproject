//Burning vehicles. By Maddmatt, for ArmA 2
//params: [unit,intensity,time,lifecheck,fade]

/*
How to use
[unit,intensity,time,lifecheck,fade] spawn BIS_Effects_Burn

unit: the name of the object that the fire will be attached to
intensity: the intensity of the fire. Recommended to use values between 0.7 and 10, higher values may be used if desired though.
time: the time that the fire started. use global variable "time". this is used to keep effects synced for JIP players
lifecheck: if this is true then the unit will only burn as ling as it is dead (!alive unit). set to false to burn things like buildings and gamelogics
fade: if true then the fire will die down over time, eventually dying out. set to false if you want it to keep burning. (affected by rain too).

If you want to kill a fire you can delete the object it is attached to.
hint: you can attach a gamelogic to a moving object via the attachto command, and then make the gamelogic burn.
that way you can kill the fire without deleting the object.

examples:
To make a gamelogic named mygamelogic burn forever with a big fire:
[mygamelogic,10,time,false,false] spawn BIS_Effects_Burn

same with medium sized fire:
[mygamelogic,5,time,false,false] spawn BIS_Effects_Burn

To make a gamelogic burn and have the fire fade over time:
[mygamelogic,10,time,false,true] spawn BIS_Effects_Burn

To make it smoke, with no visible flame you can use an intensity of 3 or lower:
[mygamelogic,3,time,false,false] spawn BIS_Effects_Burn

BIS_Effects_Burn=compile preprocessFile "\ca\Data\ParticleEffects\SCRIPTS\destruction\burn.sqf";
*/
private ["_v", "_int", "_t", "_tdiff", "_lifecheck", "_fade", "_snd", "_fl", "_sm", "_li", "_cl"];
#include "script_component.hpp"
#define INT_DIV 30 // 300 // 150
PARAMS_3(_v,_int,_t);
if (isNull _v) exitWith {TRACE_1("Null vehicle",_v)};
if (isNil "_int") exitWith {TRACE_1("Nil int",_int)};

_v setVariable ["ace_is_burning", true];

_tdiff = time - _t;
_lifecheck = if (count _this > 3) then {_this select 3} else {true}; //if true then script will only run while unit is 'dead'
_fade = if (count _this > 4) then {_this select 4} else {true}; //if true then fire will fade over time and according to rain, eventually dying out.
if (_fade) then {_int = _int - ((_tdiff * 0.02) / 3)};

if (!isDedicated) then {
	_fl = "#particlesource" createVehicleLocal getpos _v;
	_fl attachto [_v,[0,0,0],"destructionEffect2"];
	_fl setdropinterval 0.02;

	_sm = "#particlesource" createVehicleLocal getpos _v;
	_sm attachto [_v,[0,0,0],"destructionEffect1"];

	_li = "#lightpoint" createVehicleLocal getpos _v;
	_li setLightBrightness 0;
	_li setLightAmbient[0.8, 0.6, 0.2];
	_li setLightColor[1, 0.5, 0.4];
	_li lightAttachObject [_v, [0,0,0]];
};

if (isServer) then {
	_snd = createSoundSource ["Sound_Fire", getpos _v, [], 0];
	_snd attachto [_v,[0,0,0], "destructionEffect1"];
	// diag_log text format["sys_destruct: %1", [_v, _int]];
	[_v, _int] call FUNC(cookOff);
};

_range = if (_v isKindOf "Man" || {!(_v isKindOf "AllVehicles")}) then { 1.5 } else { 4 };
while {_int > 3 && {!alive _v} && {_lifecheck} && {(getpos _v select 2 > -2.5)} && {!isnull _v}} do {
	_pos = getPos _v;
	if (surfaceIsWater _pos && {(_pos select 2) < 0.5}) exitWith {
		// schtop burning in water!
	};

	if (!isDedicated) then {
		_fl setParticleParams
		[["\Ca\Data\ParticleEffects\Universal\Universal", 16, 10, 32],
		"", "Billboard", 1, 0.3*_int,
		"destructionEffect2",[0, 0, 0.17*_int],
		0, 10, 7.9, 1, [0.3*_int, 0.05*_int],
		[[1,1,1,-0], [1,1,1,-1], [1,1,1,-1], [1,1,1,-1], [1,1,1,-1], [1,1,1,0]],
		[0.5, 1], 1, 0, "", "", _v];
		_fl setParticleRandom [0.04*_int, [0.1*_int, 0.1*_int, 0.1*_int], [0.05*_int, 0.05*_int, 0.05*_int], 0, 0.06*_int, [0, 0, 0, 0], 0, 0];

		_cl = 0.8/_int;
		_sm setDropInterval (0.02*_int);
		_sm setParticleParams
		[["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48],
		"","Billboard",1, 3*_int,
		"destructionEffect1",[0, 0, 0.5*_int],
		0, 0.05, 0.04, 0.05, [0.5 + 0.5*_int, 3 + 3*_int],
		[[_cl, _cl, _cl, 0.2],[_cl, _cl, _cl, 1],[_cl, _cl, _cl, 1],
		[0.05+_cl, 0.05+_cl, 0.05+_cl, 0.9],[0.1+_cl, 0.1+_cl, 0.1+_cl, 0.6],[0.2+_cl, 0.2+_cl, 0.2+_cl, 0.3], [1,1,1, 0]],
		[0.8,0.3,0.25], 1, 0, "", "", _v];
		_sm setParticleRandom [0.7*_int, [1 - _int/10,1 - _int/10,1 - _int/10], [0.2*_int, 0.2*_int, 0.05*_int], 0, 0.3, [0.05, 0.05, 0.05, 0], 0, 0];

		_li setLightBrightness (_int / INT_DIV);
	};

	// TODO: Propagate to other objects/vehicles

	// Propagate to AI Soldiers
	[_v, _range] call ace_sys_destruction_fnc_propagateFire;

	if (_fade) then {_int = _int - 0.02 - rain/10;};

	sleep 3;
};

if (!isDedicated) then {
	deletevehicle _fl;
};

while {_int > 0.7 && {!(alive _v && {_lifecheck})} && {(getpos _v select 2 > -2.5)} && {!isnull _v}} do {
	_pos = getPos _v;
	if (surfaceIsWater _pos && {(_pos select 2) < 0.5}) exitWith {
		// schtop burning in water!
	};

	if (!isDedicated) then {
		_cl = 0.8/_int;
		_sm setDropInterval (0.01 + 0.02 * _int);
		_sm setParticleParams
		[["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48],
		"","Billboard",1, 3*_int,
		"destructionEffect1",[0, 0, 0.5*_int],
		0, 0.05, 0.04, 0.05, [0.5*_int, 3*_int],
		[[_cl, _cl, _cl, 0.2],[_cl, _cl, _cl, 1],[_cl, _cl, _cl, 1],
		[0.05+_cl, 0.05+_cl, 0.05+_cl, 0.9],[0.1+_cl, 0.1+_cl, 0.1+_cl, 0.6],[0.2+_cl, 0.2+_cl, 0.2+_cl, 0.3], [1,1,1, 0]],
		[0.8,0.3,0.25], 1, 0, "", "", _v];
		_sm setParticleRandom [0.7*_int, [1 - _int/10,1 - _int/10,1 - _int/10], [0.2*_int, 0.2*_int, 0.05*_int], 0, 0.3, [0.05, 0.05, 0.05, 0], 0, 0];

		_li setLightBrightness (_int / INT_DIV);
	};

	// TODO: Propagate to other objects/vehicles

	// Propagate to AI Soldiers
	[_v, _range] call ace_sys_destruction_fnc_propagateFire;

	if (_fade) then {_int = _int - 0.02 - rain/10};

	sleep 3;
};
_v setVariable ["ace_is_burning", false];
// player sideChat format["stop burn"];
if (!isDedicated) then {
	deletevehicle _sm;
	deletevehicle _li;
};
if (isServer) then {deletevehicle _snd};
