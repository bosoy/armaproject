//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_rand", "_pos", "_vel", "_vDirUp", "_params"];

PARAMS_3(_object,_dummy,_grenadeType);

_rand = random 100;

if (_rand < 95) then {		// certain chance it will fail to detonate on impact
	TRACE_2("Detonate",_object,_dummy);
	_pos = getPosASL _dummy;
	_vel = velocity _dummy;
	_vDirUp = [vectorDir _dummy,vectorUp _dummy];
	deleteVehicle _dummy;
	_object setPosASL [(_pos select 0)+((_vel select 0)*.005),(_pos select 1)+((_vel select 1)*.005),(_pos select 2)+((_vel select 2)*.005)];
	_params = [_object, _vDirUp, _vel];
	// if !(isServer) then { PUSH(_params,true) };
	[QGVAR(dumm), _params] call CBA_fnc_globalEvent; // Grenade objects setPos are synced, but velocity+vdir aren't synced over the net...
} else {		// Dud. No detonation on impact
	TRACE_2("Dud",_object,_dummy);
	if (_grenadeType == "M203") then {	// Only delete for M433 that doesn't self-destruct. Need the grenade alive for VOG-25 self destruct
		deleteVehicle _object;
	};
};
