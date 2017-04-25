if (isDedicated) exitWith {};

#include "script_component.hpp"

private ["_sh","_i","_no","_int"];

PARAMS_1(_unit);

_sh = _this select 6; // Uses Extended_FiredBIS
_i = 1;
_no = 3 + random 2;
//Flash
while {_i < _no} do {
	drop [["\ca\Data\ParticleEffects\Universal\Universal",16,2,32],
		"", "Billboard", 1,(0.12 + 0.015*_i),
		[-0.5 + random 1, -0.5 + random 1, -0.5 + random 1],
		[-5 + random 10, (_i*30) -5 + random 10, -5 + random 10],
		0, 10, 7.9, 0.075,
		[5, _i*6],
		[[1, 1, 1, -2],[1, 1, 1, -2], [1, 1, 1, -1], [1, 1, 1, -0]],
		[3 + random 2], 1, 0, "", "", _sh];
	INC(_i);
};
//Smoke
_i = 1;
_no = 8 + random 4;
while {_i < _no} do {
	drop [["\ca\Data\ParticleEffects\Universal\Universal", 16, 7, 48],
		"", "Billboard", 1, 4+random 2,
		[-0.5 + random 1, -0.5 + random 1, -0.5 + random 1],
		[-1+random 2,(1.5+random 1.5)*_i,-1+random 2],
		1, 1, 0.80, 0.4,
		[2,(3+random 2)*_i],
		[[0.6,0.6,0.6,0],[0.7,0.7,0.7,0.8],[0.7,0.7,0.7,0.7],[0.8,0.8,0.8,0.35],[0.9,0.9,0.9,0.15], [1,1,1,0]],
		[2,0.7,0.5],0.1,0.1,"","",_sh];
	INC(_i);
};