/* ace_sys_wounds(.pbo) - fnc_cpr.sqf | (c) 2012, 2013 by rocko */
#include "script_component.hpp"

// _this (c) by rocko

closeDialog 0;

// TODO: Extend for more suitable environment, like combo: Epi + CPR - v01 (this) only extends PMR time + 90 (__cardiactime)

private ["_receiver", "_bleed", "_ace_w_cpr_attendant"];
PARAMS_2(_receiver,_bleed);

TRACE_1("CPR", _receiver);

if (!alive player) exitWith {};
if (!alive _receiver) exitWith {};

_ace_w_cpr_attendant = player getVariable ["ace_w_cpr_attendant", false];
if (_ace_w_cpr_attendant) exitWith {};
player setVariable ["ace_w_busy",true];
player setVariable ["ace_w_cpr_attendant", true];

player setVariable ["ACE_PB_Result", 0];
[19,[localize "STR_ACE_UA_CPR"],true,true] spawn ace_progressbar;

// Initial animation
player playActionNow "medicStart";
player switchAction "medicStart";

// TODO: Healer, Injured - Position ?

player playmove "AinvPknlMstpSnonWrflDr_medic0";
player setVariable [QGVAR(cancel_cpr), false];
GVAR(cancel_cpr_action) = player addAction [localize "STR_ACE_WOUNDS_CANCEL_CPR", QPATHTO_C(cancel_cpr.sqf), [], 0, false, true];

// Add first PMR time piece
if (_bleed == 0) then {
	[_receiver, 3] call FUNC(animator2);
} else {
	[_receiver, -3] call FUNC(animator2);
};
waitUntil { player getVariable "ACE_PB_Result" != 0 || {!(_receiver call FUNC(isUncon))} || {player getVariable QGVAR(cancel_cpr)} }; // Do wait 45 seconds OR until _receiver is no longer unconscious, no abort on death

// If continuing add second PMR time
if (player getVariable "ACE_PB_Result" == 1) then {
	if (_bleed == 0) then {
		[_receiver, 3] call FUNC(animator2);
	} else {
		[_receiver, -3] call FUNC(animator2);	
	};
};

player removeAction GVAR(cancel_cpr_action);
player switchAction "medicStart";
player playActionNow "medicStop";
player setVariable ["ace_w_cpr_attendant", false];
player setVariable ["ace_w_busy",false];

false
