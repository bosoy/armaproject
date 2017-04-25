/* ace_sys_clusterbombs (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_5(_unit,_bomb,_ammo,_count,_time);

sleep 3;

_vel = velocity _bomb;
_pos = getPos _bomb;
_dir = getDir _bomb;
_vdir = vectorDir _bomb;
TRACE_4("",_vel,_pos,_dir,_vdir);

// Pop Fx
[QGVAR(popfx), _bomb] call CBA_fnc_globalEvent;

deleteVehicle _bomb;

// Spawn 4 bomb shell particles
// TODO: Try particleEffects
_s1 = "ACE_CBU87_Shell_1" createVehicle _pos;
_s2 = "ACE_CBU87_Shell_2" createVehicle _pos;
_s3 = "ACE_CBU87_Shell_1" createVehicle _pos;
//_s4 = "ACE_CBU87_Shell_2" createVehicle _pos;
// Spawn bomb core
_c = "ACE_CBU_87_Core" createVehicle _pos;

{ _x setPos _pos; _x setVectorDir _vdir; /*_x setVelocity _vel;*/ } foreach [_s1,_s2,_s3,_s4,_c];

sleep 1;

// Create bomblets
for "_i" from 0 to (_count - 1) do {
	_ex = if ((_i mod 2) == 0) then { (_ammo select 0) } else { (_ammo select 1) };
	_bomblet = _ex createvehicle _pos;
	_bomblet setvelocity [(_vel select 0)+random 20-random 20,(_vel select 1)+random 20-random 20,(_vel select 2)+random 20.0-random 20.0];
	sleep 0.01;
};

// Clean up
[QGVAR(trash), [_s1,_s2,_s3,_c]] call ACE_fnc_clientToServerEvent;
