// #define DEBUG_MODE_FULL
#include "script_component.hpp"

#define STABILIZE_TIME 90

closeDialog 0;

PARAMS_2(_receiver,_state);

if (!alive player) exitWith {};
if (!alive _receiver) exitWith { hintSilent (localize "STR_ACE_WOUNDS_HEISDEAD") };

_coef = if ([player] call FUNC(isMedic)) then { 0.5} else { 1 };
_timeOut = (STABILIZE_TIME * _coef);
_endTime = time + _timeOut;

// Play animation on the other unit
if (player != _receiver) then { [QGVAR(stabilize), [_receiver,_timeOut]] call ACE_fnc_receiverOnlyEvent };

player setVariable ["ace_w_busy",true];
player setVariable ["ace_w_stabilizing", true];
_abort = false;

player setVariable ["ACE_PB_Result", 0];
[_timeOut,[format [localize "STR_ACE_UA_STABILIZE", name _receiver]],false,true,player,true] spawn ace_progressbar;
player playMove "AinvPknlMstpSlayWrflDnon_medic";

waitUntil { (player getVariable "ACE_PB_Result" != 0) };
if (player getVariable "ACE_PB_Result" == 1) then {
	// Stabilized msg
	if (local player) then {
		hintSilent (localize "STR_ACE_WOUNDS_SUCK" + " " + localize "STR_ACE_WOUNDS_STABILIZED");
	};
	[QGVAR(isStabilized), _receiver] call ACE_fnc_receiverOnlyEvent;
};
player setVariable ["ace_w_stabilizing", false];
player setVariable ["ace_w_busy",false];
if (_receiver != player) then { [QGVAR(stabilize_abort), _receiver] call ACE_fnc_receiverOnlyEvent };
