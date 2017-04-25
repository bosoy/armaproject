//fnc_trackFragRound.sqf
#include "script_component.hpp"

private ["_params", "_round", "_lastPos", "_lastVel", "_time"];
_params = _this select 0;
_round = _params select 0;
_lastPos = _params select 1;
_lastVel = _params select 2;
_time = _params select 4;

if (!alive _round) then {
	[_this select 1] call cba_fnc_removePerFrameHandler;
	if(_time != time && {_round in GVAR(trackedObjects)} && {!(_round in GVAR(blackList))}) then {
		GVAR(trackedObjects) = GVAR(trackedObjects) - [_round];
		[QGVAR(frag_eh), _params] call ACE_fnc_clientToServerEvent;
		GVAR(trackedObjects) = GVAR(trackedObjects) - [_round];
	};
} else {
	if(!(_round in GVAR(trackedObjects)) || {_round in GVAR(blackList)}) then {
		[_this select 1] call cba_fnc_removePerFrameHandler;
		if(_round in GVAR(blackList)) then {
			GVAR(blackList) = GVAR(blackList) - [_round];
		};
	};
	_params set[1, (getPosASL _round)];
	_params set[2, (velocity _round)];
};
