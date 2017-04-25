//Burning vehicles. By Maddmatt, for ArmA 2
//params: [unit,intensity,time,lifecheck,fade]
#define THIS_FILE "burn.sqf"
#include "x_setup.sqf"

private ["_v", "_int", "_t", "_tdiff", "_lifecheck", "_fade", "_snd", "_fl", "_sm", "_li", "_cl"];

PARAMS_3(_v,_int,_t);
if (isNull _v || {isNil "_int"}) exitWith {};

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
	_ppp = position _v;
	if (count _ppp > 0) then {
		_snd = createSoundSource ["Sound_Fire", getpos _v, [], 0];
		_snd attachto [_v,[0,0,0], "destructionEffect1"];
	} else {
		_snd = objNull;
	};
};

_range = if (_v isKindOf "CAManBase" || !(_v isKindOf "AllVehicles")) then {15 } else {4};
while {_int > 3 && !(alive _v && _lifecheck) && (getpos _v select 2 > -2.5) && !isnull _v} do {
	_pos = getPos _v;
	if (surfaceIsWater _pos && (_pos select 2) < 0.5) exitWith {};

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

		_li setLightBrightness (_int/30);
	};
	if (_fade) then {_int = _int - 0.02 - rain/10;};
	sleep 3;
};

if (!isDedicated) then {
	deletevehicle _fl;
};

while {_int > 0.7 && !(alive _v && _lifecheck) && (getpos _v select 2 > -2.5) && !isnull _v} do {
	_pos = getPos _v;
	if (surfaceIsWater _pos && (_pos select 2) < 0.5) exitWith {};

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

		_li setLightBrightness (_int/30);
	};

	if (_fade) then {_int = _int - 0.02 - rain/10};

	sleep 3;
};

if (!isDedicated) then {
	deletevehicle _sm;
	deletevehicle _li;
};
if (isServer) then {if (!isNull _snd) then {deletevehicle _snd}};
