/* ace_sys_wounds(.pbo)  */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"
// _this (c) by Xeno

closeDialog 0;

private ["_receiver", "_delay"];
PARAMS_3(_receiver,_state,_bandage);

TRACE_1("Bandage", _receiver);

if (!alive player) exitWith {};

if (!alive _receiver) exitWith {
	hintSilent format [localize "STR_ACE_WOUNDS_XDEAD", name _receiver];
};

_ismed = [player] call FUNC(isMedic);

_allowed = true;
if (!_ismed) then {
	_allowed = [_receiver, player, _bandage] call FUNC(takeItem);
};

if !(_allowed) exitWith {}; // No item!
player setVariable ["ace_w_busy",true];

// If prone and attempting to bandage other player
_delay = 15;
if (((player call CBA_fnc_getUnitAnim) select 0) != "prone") then {
		player playMove "AinvPknlMstpSlayWrflDnon_medic";
		_delay = 6.5;
};

_text = localize "STR_ACE_UA_STOPBLEED";
if (_bandage == "ACE_Tourniquet") then {
	_text = localize "STR_ACE_UA_STOPBLEEDFUCKINGVERYLARGE";
};

[_delay,_receiver,_bandage,_text] spawn {
	PARAMS_4(_delay,_receiver,_bandage,_text);
	player setVariable ["ACE_PB_Result", 0];
	[_delay,[_text],false,true,player,true] spawn ace_progressbar;
	waitUntil { (player getVariable "ACE_PB_Result" != 0) };
	if (player getVariable "ACE_PB_Result" == 1) then {
		[_receiver,0,_bandage] call FUNC(animator2);
		[_bandage,player] call FUNC(litter);
	};
	player setVariable ["ace_w_busy", false]; // always set busy state to false regardless of PB result
};

false