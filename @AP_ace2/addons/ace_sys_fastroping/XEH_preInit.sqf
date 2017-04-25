#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(init);
PREP(fastrope);
PREP(ropeserver);
PREP(premoveaction);
PREP(paddaction);
PREP(hasropemag);
PREP(deployFastropes);

GVAR(action_abort) = -999999;

GVAR(fr_state) = [objNull, -9999];

FUNC(canFastRope) = {
	PARAMS_1(_veh);
	_veh getVariable ["ACE_canFastrope", getNumber(configFile >> "CfgVehicles" >> typeOf _veh >> "ACE_canFastrope") == 1];
};

FUNC(SetVectorVec) = {
	private "_v";
	_v = _this;
	while {!(_v getVariable "ACE_RopeAbort") && {alive _v} && {canMove _v}} do {
		_v setVectorUp [0.001, 0.001, 1];
		sleep 0.01;
	};
};

[QGVAR(fr), {_this spawn FUNC(fastrope)}] call ACE_fnc_addReceiverOnlyEventhandler;
if (isServer) then {
	[QGVAR(rs), {_this spawn FUNC(ropeserver)}] call ACE_fnc_addClientToServerEventhandler;
};
[QGVAR(a1), {_this switchMove "MLB_Fast_Rope"}] call CBA_fnc_addEventHandler;
[QGVAR(a2), {_this switchMove "AcrgPknlMstpSnonWnonDnon_AmovPercMstpSrasWrflDnon_getOutHigh"}] call CBA_fnc_addEventHandler;
[QGVAR(sv), {_this setVelocity [0,0,-20]}] call ACE_fnc_addReceiverOnlyEventhandler;
if (!isDedicated) then {
	[QGVAR(wh), {player reveal _this}] call CBA_fnc_addEventHandler;
};

[QGVAR(vsv), {_this spawn FUNC(SetVectorVec)}] call ACE_fnc_addReceiverOnlyEventhandler;

ADDON = true;
