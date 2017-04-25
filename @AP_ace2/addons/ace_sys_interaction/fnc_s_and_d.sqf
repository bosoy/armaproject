/* ace_sys_interaction (.pbo) | (c) 2013 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"


// TODO: Make new ui similar to gear weapon list from gear menu, show hidden weapons (wob)

TRACE_1("",_this);

private["_receiver"];
PARAMS_1(_receiver);

private["_action"];
_action = "gear";

GVAR(confirmed) = nil;

if (GVAR(inProgress)) exitWith {};
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
	_endtime = time + 9999999;
};
sleep 0.5;
waitUntil { !(isNil QGVAR(confirmed)) || {time > _endtime} };
sleep 0.5;

if (!isNil QGVAR(confirmed) && {GVAR(confirmed)}) then {
	player action ["Gear", _receiver];
	_receiver setVariable [QGVAR(searched),true];
};

GVAR(inProgress) = false;

false
