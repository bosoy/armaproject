/* ace_sys_interaction (.pbo) | (c) 2013 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("",_this);

private["_receiver"];
PARAMS_1(_receiver);

private["_action"];
_action = "gear";

GVAR(confirmed) = nil;

if (missionNamespace getVariable [QGVAR(inProgress), false]) exitWith {};
if (!alive _receiver) exitWith {};
GVAR(inProgress) = true;

private["_t","_endtime", "_w"];
_w = !(!isNil "ace_sys_wounds_enabled" && {_receiver call ace_sys_wounds_fnc_isUncon});
if (isPlayer _receiver && {_w}) then {
	TRACE_1("Requesting action from receiver","");
	[QGVAR(confirmation), [_receiver, player, -1, _action]] call ACE_fnc_receiverOnlyEvent;
	_endtime = time + 20;
} else {
	TRACE_1("Requesting action from receiver AI or uncon unit","");
	GVAR(confirmed) = true;
	if (isNil "ace_sys_wounds_enabled") then {
		if (side _receiver != playerSide || {!(_receiver in (units group player))}) then {GVAR(confirmed) = false};
	} else {
		if (_w) then {
			if (side _receiver != playerSide || {!(_receiver in (units group player))}) then {GVAR(confirmed) = false};
		};
	};
	_endtime = time + 9999999;
};
sleep 0.5;
waitUntil { !(isNil QGVAR(confirmed)) || {time > _endtime} };
sleep 0.5;

if (!isNil QGVAR(confirmed) && {GVAR(confirmed)}) then {
	player action ["Gear", _receiver];
};

GVAR(inProgress) = false;

false
