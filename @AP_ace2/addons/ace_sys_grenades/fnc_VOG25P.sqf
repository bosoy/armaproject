//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_time","_velocity","_pos","_rand","_v"];

PARAMS_2(_object,_dummy);

_rand = random 100;

if (_rand < 95) then { // certain chance it will fail to detonate on impact
	_velocity = velocity _dummy;
	while { alive _dummy } do {
		//TRACE_1("AngleDiff",[velocity _dummy,_velocity] call ace_sys_missileguidance_fnc_mat_cos3Dvec);
		if( ([velocity _dummy,_velocity] call ace_sys_missileguidance_fnc_mat_cos3Dvec) < 0.8) exitwith {_v = velocity _dummy};
		_pos = getPosASL _dummy;
		_velocity = velocity _dummy;
		//drop ["\ca\data\koulesvetlo","","Billboard",100,120,getpos _dummy,[0,0,0],0,1.275,1,0,[1],[[1,0.1,0.1,0.9]],[0],0,0,"","",""];
		TRACE_2("Speed/Velocity VOG25P", _speed, _velocity);
		TRACE_1("COORD",_pos);
		sleep 0.01;
	};
	deletevehicle _object;
	_v = _v call ace_sys_missileguidance_fnc_mat_Normalize3D;
	//diag_log _v;
	if (_v select 2 <= -0.99) then {_v set [2,0],_v = _v call ace_sys_missileguidance_fnc_mat_Normalize3D};
	_object = "ACE_Grenade_40mm_SelfDestr" createVehicle [_pos select 0,_pos select 1,200];
	_object setPosASL _pos;
	_object setVelocity [25*(_v select 0),25*(_v select 1),25*(_v select 2)];
	deleteVehicle _dummy;
	//_time = time;
	//waituntil {
	//	TRACE_2("Time,height",time-_time,(getpos _object) select 2);
	//	drop ["\ca\data\koulesvetlo","","Billboard",100,120,getpos _object,[0,0,0],0,1.275,1,0,[1],[[0.1,1,0.1,0.9]],[0],0,0,"","",""];
	//	! (alive _object)
	//};

	// HOW TO DESTROY GRENADE MID AIR?
} else {
	TRACE_2("Dud",_object,_dummy);
};