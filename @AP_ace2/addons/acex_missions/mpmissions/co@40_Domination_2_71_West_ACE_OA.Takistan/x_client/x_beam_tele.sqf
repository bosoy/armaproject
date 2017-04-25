// by Xeno
#define THIS_FILE "x_beam_tele.sqf"
#include "x_setup.sqf"
#define __CTRL2(A) (_display displayCtrl A)
private ["_display", "_ctrl", "_typepos"];
if (!X_Client) exitWith {};

if (GVAR(beam_target) < 0) exitWith{};

if (GVAR(x_loop_end)) exitWith {};

GVAR(x_loop_end) = true;

if (vehicle player != player) then {unassignVehicle player};

disableSerialization;
_display = __uiGetVar(X_TELE_DIALOG);
__CTRL2(100102) ctrlEnable false;
__CTRL2(100107) ctrlEnable false;
__CTRL2(100108) ctrlEnable false;
__CTRL2(100109) ctrlEnable false;
__CTRL2(100112) ctrlShow true;

GVAR(last_telepoint) = GVAR(beam_target);
_global_pos = [];
_global_dir = 180;
_typepos = 0;
switch (GVAR(beam_target)) do {
	case 0: {
#ifndef __TT__
		_global_pos = markerPos "base_spawn_1"
#else
		_global_pos = if (GVAR(player_side) == west) then {markerPos "base_spawn_1"} else {markerPos "base_spawn_2"};
#endif
	};
	case 1: {
#ifndef __TT__
		_global_pos = MRR1 modelToWorld [0,-6,0];
		_global_pos set [2,0];
		_global_dir = direction MRR1;
#else
		_global_pos = if (GVAR(player_side) == west) then {MRR1 modelToWorld [0,-5,0]} else {MRRR1 modelToWorld [0,-5,0]};
		_global_dir = if (GVAR(player_side) == west) then {direction MRR1} else {direction MRRR1};
#endif
		_typepos = 1;
	};
	case 2: {
#ifndef __TT__
		_global_pos = MRR2 modelToWorld [0,-6,0];
		_global_pos set [2,0];
		_global_dir = direction MRR2;
#else
		_global_pos = if (GVAR(player_side) == west) then {MRR2 modelToWorld [0,-5,0]} else {MRRR2 modelToWorld [0,-5,0]};
		_global_dir = if (GVAR(player_side) == west) then {direction MRR2} else {direction MRRR2};
#endif
		_typepos = 1;
	};
};
GVAR(beam_target) = -1;
if (_typepos == 1) then {
	player setPosATL [_global_pos select 0, _global_pos select 1, 0];
	player setDir _global_dir;
} else {
#ifdef __CARRIER__
	player setPosASL [_global_pos select 0, _global_pos select 1, 15.9];
#else
	player setPos _global_pos;
#endif
	player setDir _global_dir;
};
0 spawn {
	private "_nobs";
	sleep 2;
	if (GVAR(teleport_dialog_open)) then {
		closeDialog 0;
	};

	titletext ["", "BLACK IN"];

	_nobs = switch (true) do {
		case (__OAVer): {nearestObjects [player, [GVAR(the_box),"M1133_MEV_EP1","BMP2_HQ_TK_EP1"], 30]};
		case (__COVer): {nearestObjects [player, [GVAR(the_box),"LAV25_HQ","BTR90_HQ"], 30]};
	};
	{player reveal _x} forEach _nobs;

	if (GVAR(with_ai)) then {if (alive player) then {[] execVM "x_client\x_moveai.sqf"}};
};