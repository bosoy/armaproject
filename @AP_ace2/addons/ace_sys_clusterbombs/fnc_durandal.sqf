/* ace_sys_clusterbombs (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_unit,_bomb);

sleep 5;

_vel = velocity _bomb;
_pos = getPos _bomb;
_dir = getDir _bomb;
_vdir = vectorDir _bomb;
TRACE_4("",_vel,_pos,_dir,_vdir);

// Pop Fx
[QGVAR(popfx), _bomb] call CBA_fnc_globalEvent;
// Create Durandal
deleteVehicle _bomb;
_durandal = "ACE_BLU107BPara" createvehicle [(_pos select 0) + random 30,(_pos select 1) + random 30,(_pos select 2)];
_durandal setpos [(_pos select 0) + random 30,(_pos select 1) + random 30,(_pos select 2)];

// Wait until Durandal is at 25m height
while { (((getPosATL _durandal) select 2) > 80) && {alive _durandal} } do {
	sleep 2;
	TRACE_1("Durandal flying",((getPosATL _durandal) select 2));
};
// Durandal #1 is in attack height
TRACE_1("Durandal reaches 25m",nil);

// Attack
// Get center position of Durandal
_pos_center_x = getPos _durandal;
_px = _pos_center_x select 0;
_py = _pos_center_x select 1;
_pz = _pos_center_x select 2;
if (_pz < 25) then { _pz = 25; };

//TODO: Shoot 10 degree into ground in flying direction
//_pos_hit = [_px, _py, 0];

// TODO: Calc new impact point

_p = "ACE_BLU108B_PROJO" createVehicle [_px, _py, _pz - 5];
_p setPos [_px, _py, _pz - 5];
_xoff = .1; //(getPos _targetToHit select 0) - _px;
_yoff = .1; //(getPos _targetToHit select 1) - _py;
_zoff = - _pz;
_mag = sqrt(_xoff*_xoff + _yoff*_yoff + _zoff*_zoff);
_dir = [_xoff/_mag, _yoff/_mag, _zoff/_mag];
_dx = _dir select 0;
_dy = _dir select 1;
_dz = _dir select 2;
_hmag = sqrt(_dx*_dx + _dy*_dy);
_zcomp = -_dz/_hmag;
_ux = _zcomp*_dx;
_uy = _zcomp*_dy;
_uz = _hmag;
_p setVectorDir _dir;
_p setVectorUp [_ux,_uy,_uz];
_p setVelocity [(_dir select 0) * 300, (_dir select 1) * 300, (_dir select 2) * 300];

deleteVehicle _durandal;

//TODO: runway crater stuff
_crater = "ACE_RunwayCrater";
// Projectile creation position = crater position
// Check if is road/runway
// If road/runway: _crater = _crater
// Else _crater = other"

_c = _crater createVehicle [_px,_py,0];


// TODO: Solution for crater removal: No, I want runway craters to be impairable, like in RL. No bullshit noob pussy solutions, please.
