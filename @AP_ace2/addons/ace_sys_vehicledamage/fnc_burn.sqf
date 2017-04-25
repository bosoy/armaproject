//#define DEBUG_MODE_FULL
#include "script_component.hpp"
//Burning vehicles. By Maddmatt, for ArmA 2
//modified by q1184 for ACE2 vehicle dmg sys
//params: [unit,intensity,time,lifecheck,fade/grow,gain,veh type,time to last]

/*

unit: the name of the object that the fire will be attached to
intensity: the intensity of the fire. Recommended to use values between 0.7 and 10, higher values may be used if desired though.
time: the time that the fire started. use global variable "time". this is used to keep effects synced for JIP players
lifecheck: if this is true then the unit will only burn as long as it is alive. set to false to burn things like buildings and gamelogics
grow/fade: if true then the fire will die down over time, eventually dying out. set to false if you want it to keep burning. (affected by rain too).
		or grow with time, depending on gain parameter
gain: (scalar) if positive, fire gains strength over time, negative will die it down.
veh type (string): class of vehicle burning obj is attached to
time to last: time to last

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

*/

TRACE_1("Burn script starting","");

#define INT_DIV 70 // 30 // 300
private ["_al","_timeleft","_dead","_veh","_die","_v","_int","_t","_tdiff","_lifecheck","_fade","_gain","_fl","_sm","_li","_cl","_snd"];

PARAMS_8(_v,_int,_t,_lifecheck,_fade,_gain,_ammo,_die); //time for the fire to last
if (isNull _v) exitWith {};
if (typeName _ammo != "STRING") exitWith { ERROR("_ammo is not string!") };

_v setVariable ["ace_is_burning", true];

_tdiff = (time - _t) max 0;	//server might be too ahead on time
_veh = if (_v isKindOf "ACE_LogicDummy") then {
	nearestObject [_v, _ammo] //vehicle logic is attached to
} else {
	_v
};

_veh setVariable ["ace_is_burning", true];
_dead = false;

if (_fade) then {_int = (_int + (_tdiff*_gain/3)) max 0.06};
TRACE_1("Burn script: Intensity",_int);

if (isServer) then {
	_snd = createSoundSource ["Sound_Fire", getpos _v, [], 0];
	_snd attachto [_v,[0,0,0]];
	//diag_log format["sys_vd: %1", [(typeOf _veh), _int]];
	[_veh, _int] call ace_sys_destruction_fnc_cookOff;
};
if (!isDedicated) then {
	_fl = "#particlesource" createVehicleLocal getpos _v;
	_fl attachto [_v,[0,0,0]];
	_fl setdropinterval 0.02;

	_sm = "#particlesource" createVehicleLocal getpos _v;
	_sm attachto [_v,[0,0,0]];

	_li = "#lightpoint" createVehicleLocal getpos _v;
	_li setLightBrightness 0; // brightness = "0.065 * fireIntensity + 0.065";
	_li setLightAmbient[0.05,0.05,0.05];
	_li setLightColor[8.543,4.124,2.269];
	_li lightAttachObject [_v, [0,0,0]];

	while {_int > 0.01 && {(alive _veh || {!_lifecheck})} && {getpos _v select 2 > -2.5} && {!isNull _v} && {!isNull _veh} && {time-_t < _die}} do {
		_posv = getPos _v;
		if (surfaceIsWater _posv && {(_posv select 2) < 0.5}) exitWith {
			// schtop burning in water!
		};
	
		_fl setParticleParams
		[["\Ca\Data\ParticleEffects\Universal\Universal", 16, 10, 32],
		"", "Billboard", 1, 0.3*_int,
		"destructionEffect2",[0, 0, 0.17*_int],
		0, 10, 7.9, 1, [0.3*_int, 0.05*_int],
		[[1,1,1,-0], [1,1,1,-1], [1,1,1,-1], [1,1,1,-1], [1,1,1,-1], [1,1,1,0]],
		[0.5, 1], 1, 0, "", "", _v];
		_fl setParticleRandom [0.04*_int, [0.1*_int, 0.1*_int, 0.1*_int], [0.05*_int, 0.05*_int, 0.05*_int], 0, 0.06*_int, [0, 0, 0, 0], 0, 0];

		_cl = (0.8/_int) min 0.1;
		_al = (_int/10) min 1;
		_sm setDropInterval (0.01 + 0.02*_int);
		_sm setParticleParams
		[["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48],
		"","Billboard",1, 3*_int,
		[0,0,0],[0, 0, 0.5*_int],
		0, 0.05, 0.04, 0.05, [0.1 + 0.5*_int, 0.5 + 3*_int],
		[[_cl, _cl, _cl, 0.2],[_cl, _cl, _cl, _al],[_cl, _cl, _cl, _al],
		[0.05+_cl, 0.05+_cl, 0.05+_cl, 0.9*_al],[0.1+_cl, 0.1+_cl, 0.1+_cl, 0.6*_al],[0.1+_cl, 0.1+_cl, 0.1+_cl, 0.3*_al], [0.1+_cl,0.1+_cl,0.1+_cl, 0]],
		[0.8,0.3,0.25], 1, 0, "", "", _v];
		_sm setParticleRandom [0.7*_int, [1 - _int/10,1 - _int/10,1 - _int/10], [0.2*_int, 0.2*_int, 0.05*_int], 0, 0.3, [0.05, 0.05, 0.05, 0], 0, 0];
		
		_li setLightBrightness (_int / INT_DIV);

		// TODO: Propagate to other objects/vehicles

		// Propagate to AI Soldiers
		[_veh] call ace_sys_destruction_fnc_propagateFire;

		if (_fade) then {_int = (_int + _gain - rain/50) min 7};

		sleep 3;
	};

	deletevehicle _fl;

	while {_int > 0.005 && {(alive _veh || {!_lifecheck})} && {getpos _v select 2 > -2.5} && {!isNull _v} && {!isNull _veh} && {time-_t < _die}} do {
		_posv = getPos _v;
		if (surfaceIsWater _posv && {(_posv select 2) < 0.5}) exitWith {
			// schtop burning in water!
		};
		
		_cl = 0.8/_int;
		_sm setDropInterval (0.01 + 0.02*_int);
		_sm setParticleParams
		[["\Ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48],
		"","Billboard",1, 3*_int,
		[0,0,0],[0, 0, 0.5*_int],
		0, 0.05, 0.04, 0.05, [0.5*_int, 3*_int],
		[[_cl, _cl, _cl, 0.2],[_cl, _cl, _cl, 1],[_cl, _cl, _cl, 1],
		[0.05+_cl, 0.05+_cl, 0.05+_cl, 0.9],[0.1+_cl, 0.1+_cl, 0.1+_cl, 0.6],[0.2+_cl, 0.2+_cl, 0.2+_cl, 0.3], [0.3+_cl,0.3+_cl,0.3+_cl, 0]],
		[0.8,0.3,0.25], 1, 0, "", "", _v];
		_sm setParticleRandom [0.7*_int, [1 - _int/10,1 - _int/10,1 - _int/10], [0.2*_int, 0.2*_int, 0.05*_int], 0, 0.3, [0.05, 0.05, 0.05, 0], 0, 0];
		
		_li setLightBrightness (_int / INT_DIV);

		// TODO: Propagate to other objects/vehicles

		// Propagate to AI Soldiers
		[_veh] call ace_sys_destruction_fnc_propagateFire;

		if (_fade) then {_int = (_int + _gain - rain/50) min 7};

		sleep 3;
	};

	deletevehicle _sm;
	deletevehicle _li;
} else {	//no shmoogidy on dedicated
	while {(alive _veh || {!_lifecheck}) && {getpos _veh select 2 > -2.5} && {!isNull _veh} && {!isNull _v} && {time-_t < _die}} do {
		// Propagate to AI Soldiers
		[_veh] call ace_sys_destruction_fnc_propagateFire;
		sleep 3;
	};
};
_v setVariable ["ace_is_burning", false];

if (isServer) then {deletevehicle _snd};
if (local _v) then {
	if (_v isKindOf "Logic") then {
		detach _v;
		deletevehicle _v;
	};
};

TRACE_1("Burn script end for",_veh);
