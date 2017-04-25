#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(dummy);
PREP(M203);
PREP(VOG25);
PREP(VOG25P);
PREP(40mmG);
PREP(fired);

FUNC(dumm) = {
	PARAMS_3(_dummy,_vDirUp,_vel);
	// DEFAULT_PARAM(3,_net,false);
	if (isNull _dummy) exitWith { TRACE_1("Null Dummy") };
	 
	 // if (!_net || (_net && isServer)) then {};
	_dummy setVectorDirAndUp _vDirUp; // vectorDirAndUp is synced if done from non local machine, followed by a setPosASL
	_dummy setVelocity _vel; // velocity is not synced over the net
	// if (_net && isServer) then { _dummy setPosASL (getPosASL _dummy) }; // Sync in net
};

[QGVAR(dumm), {_this call FUNC(dumm)}] call CBA_fnc_addEventhandler;

ADDON = true;
