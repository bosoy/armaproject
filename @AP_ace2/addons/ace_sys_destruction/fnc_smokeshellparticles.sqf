#include "script_component.hpp"

if (isDedicated) exitWith {};

private ["_sh", "_col", "_c1", "_c2", "_c3", "_source", "_trails", "_wp", "_source2"];

PARAMS_2(_sh,_col);

_c1 = _col select 0;
_c2 = _col select 1;
_c3 = _col select 2;
sleep (1.5 + random 0.5);

_trails = "#particlesource" createVehicleLocal getpos _sh;
_trails setdropinterval 0.02;
_trails setparticleparams [["\ca\Data\ParticleEffects\Universal\Universal", 16, 0, 1],
	"", "Billboard", 0.1, 1, [0,0,0],
	[0, 0, 7], 0, 15, 7.9, 0.075, [0.4],
	[[1, 1, 1, 1]],
	[0], 1, 0, "\CA\Data\ParticleEffects\SCRIPTS\WPTrail.sqf", "", _sh];
_trails setParticleRandom [0.1, [0.25, 0.25, 0], [15, 15, 7], 0, 0.15, [0, 0, 0, 0], 0, 0];

_wp = "#particlesource" createVehicleLocal getpos _sh;
_wp setdropinterval 0.02;
_wp setparticleparams [["\Ca\Data\Cl_basic.p3d", 1, 0, 1],
	"", "Billboard", 1, 10, [0,0,0], [0, 0, 0],
	0, 10, 7.9, 0.075, [5, 10, 15,20],
	[[1, 1, 1, 1], [1, 1, 1, 0.5], [1, 1, 1, 0]],
	[0], 1, 0, "", "", _sh];

_wp setParticleRandom [4, [3, 3, 3], [0.1, 0.1, 0.1], 0, 0.25, [0, 0, 0, 0], 0, 0];

sleep 0.15;
deletevehicle _trails;deletevehicle _wp;

_source2 = "#particlesource" createVehicleLocal getpos _sh;
_source2 setParticleParams [["\Ca\Data\ParticleEffects\Universal\Universal", 16, 12, 8, 0], "", "Billboard", 1, 6, [0, 0, 0],
				[0, 0, 0.5], 0, 1.277, 1, 0.025, [0.5, 8, 12, 15], [[_c1, _c2, _c3, 1],[_c1, _c2, _c3, 1], [_c1, _c2, _c3, 1], [_c1, _c2, _c3, 0]],
				[0.2], 1, 0.04, "", "", _sh];
_source2 setParticleRandom [2, [0.3, 0.3, 0.3], [1.5, 1.5, 1], 0, 0.2, [0, 0, 0, 0.1], 0, 0, 360];
_source2 setDropInterval 0.1;

sleep (55 + random 3);
deletevehicle _source2;