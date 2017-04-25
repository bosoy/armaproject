//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_vel","_flare","_t","_vx","_vy","_vz","_step","_z"];
_flare = _this select 6;
_step = 0.15;
waituntil {sleep 1; ((velocity _flare) select 2) < 0 || {!(alive _flare)}};
_t = time;
//horizontally aligned
_flare setvectorUp [0,0,1];

// Burst height ~ 180m - 190m for Star Cluster
// Burst height ~ 180m - 190m for Star Parachute
// If height is achieved when firing vertically up, all is fine
// Users shooting in 45 degrees, bad luck then

while {alive _flare} do {
	_vel = velocity _flare;
	_vx = _vel select 0;
	_vy = _vel select 1;
	_vz = _vel select 2;
	if (_vx < (wind select 0)/3.5) then {
		_vx = _vx + _step*(wind select 0)*0.3;
	};
	if (_vy < (wind select 1)/3.5) then {
		_vy = _vy + _step*(wind select 1)*0.3;	//dt*wind*coef
	};
	if (_vz < -2) then {
		_vz = -2;
	};
	_z = [_flare] call CBA_fnc_realHeight;
	if (_z <= 0.7) then {_step = 0.01};
	if (_z <= 0.15) exitwith { _flare enablesimulation false; _flare setvelocity [0,0,0]; };	//freezes the flare indefinitely
	_flare setvelocity [_vx,_vy,_vz];
	TRACE_3("Time - Vel - Height",time-_t,(velocity _flare) select 2,_z);
	sleep _step;
};

waituntil {sleep 2; !(alive _flare) || {(time - _t >= 41)}};
deletevehicle _flare;
