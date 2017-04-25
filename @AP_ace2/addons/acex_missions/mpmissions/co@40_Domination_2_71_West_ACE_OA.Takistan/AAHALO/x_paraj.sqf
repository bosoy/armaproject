#define THIS_FILE "x_paraj.sqf"
#include "x_setup.sqf"
private ["_do_exit","_exitj","_realpos", "_jumpobj"];

PARAMS_1(_jumpobj);

if (player distance _jumpobj > 15) exitWith {
	(format [(localize "STR_DOM_MISSIONSTRING_63"), GVAR(name_pl)]) call FUNC(GlobalChat);
};

_exitj = false;
if (GVAR(with_ranked)) then {
	if (score player < (GVAR(ranked_a) select 4)) then {
		(format [(localize "STR_DOM_MISSIONSTRING_64"), score player,GVAR(ranked_a) select 4]) call FUNC(HQChat);
		_exitj = true;
	} else {
		[QGVAR(pas), [player, (GVAR(ranked_a) select 4) * -1]] call FUNC(NetCallEventCTS);
	};
};

if (_exitj) exitWith {};

_do_exit = false;
if (GVAR(HALOWaitTime) > 0) then {
#ifndef __TT__
	if (position player distance GVAR(FLAG_BASE) < 15) then {
#else
	if (position player distance GVAR(EFLAG_BASE) < 15 || position player distance GVAR(WFLAG_BASE) < 15) then {
#endif
		if (GVAR(next_jump_time) > time) then {
			_do_exit = true;
			(format [(localize "STR_DOM_MISSIONSTRING_65"), round ((GVAR(next_jump_time) - time)/60)]) call FUNC(HQChat);
		};
	};
};
if (_do_exit) exitWith {};

#ifdef __ACE__
if !(player hasWeapon "ACE_ParachutePack") exitWith {(localize "STR_DOM_MISSIONSTRING_66") call FUNC(HQChat)};
#endif
GVAR(global_jump_pos) = [];
createDialog "XD_ParajumpDialog";

waitUntil {!GVAR(parajump_dialog_open) || !alive player};
if (alive player) then {
	if (count GVAR(global_jump_pos) > 0) then {
		_realpos = [GVAR(global_jump_pos), 200] call FUNC(GetRanJumpPoint);
		[_realpos] execVM 'AAHALO\jump.sqf';
	};
} else {
	if (GVAR(parajump_dialog_open)) then {closeDialog 0};
};
sleep 0.512;
