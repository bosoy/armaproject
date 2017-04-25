#define THIS_FILE "x_update_target.sqf"
#include "x_setup.sqf"
private ["_target","_display","_textctrl","_text","_end_pos"];

PARAMS_1(_target);

disableSerialization;

_display = __uiGetVar(X_TELE_DIALOG);
_textctrl = _display displayCtrl 100110;

if (GVAR(x_loop_end)) exitWith {};

_text = "";
_text2 = "";
_end_pos = position player;
#ifndef __TT__
switch (_target) do {
	case 0: {
		switch (GVAR(tele_dialog)) do {
			case 0: {
				_text = (localize "STR_DOM_MISSIONSTRING_604");
				GVAR(beam_target) = 0;
				_end_pos = position GVAR(FLAG_BASE);
			};
			case 1: {
				_text = (localize "STR_DOM_MISSIONSTRING_605");
				GVAR(beam_target) = 1;
				_end_pos = position MRR1;
			};
			case 2: {
				_text = (localize "STR_DOM_MISSIONSTRING_606");
				GVAR(beam_target) = 0;
				_end_pos = position GVAR(FLAG_BASE);
			};
		};
	};
	case 1: {
		_text = switch (GVAR(tele_dialog)) do {
			case 0: {(localize "STR_DOM_MISSIONSTRING_607")};
			case 1: {(localize "STR_DOM_MISSIONSTRING_605")};
			case 2: {(localize "STR_DOM_MISSIONSTRING_605")};
		};
		GVAR(beam_target) = 1;
		_end_pos = position MRR1;
	};
	case 2: {
		_text = switch (GVAR(tele_dialog)) do {
			case 0: {(localize "STR_DOM_MISSIONSTRING_608")};
			case 1: {(localize "STR_DOM_MISSIONSTRING_609")};
			case 2: {(localize "STR_DOM_MISSIONSTRING_609")};
		};
		GVAR(beam_target) = 2;
		_end_pos = position MRR2;
	};
};
#endif
#ifdef __TT__
switch (_target) do {
	case 0: {
		switch (GVAR(tele_dialog)) do {
			case 0: {
				_text = (localize "STR_DOM_MISSIONSTRING_604");
				GVAR(beam_target) = 0;
				_end_pos = if (GVAR(player_side) == west) then {position GVAR(WFLAG_BASE)} else {position GVAR(EFLAG_BASE)};
			};
			case 1: {
				_text = (localize "STR_DOM_MISSIONSTRING_605");
				GVAR(beam_target) = 1;
				_end_pos = if (GVAR(player_side) == west) then {position MRR1} else {position MRRR1};
			};
			case 2: {
				_text = (localize "STR_DOM_MISSIONSTRING_606");
				GVAR(beam_target) = 0;
				_end_pos = if (GVAR(player_side) == west) then {position GVAR(WFLAG_BASE)} else {position GVAR(EFLAG_BASE)};
			};
		};
	};
	case 1: {
		_text = switch (GVAR(tele_dialog)) do {
			case 0: {(localize "STR_DOM_MISSIONSTRING_607")};
			case 1: {(localize "STR_DOM_MISSIONSTRING_605")};
			case 2: {(localize "STR_DOM_MISSIONSTRING_605")};
		};
		GVAR(beam_target) = 1;
		_end_pos = if (GVAR(player_side) == west) then {position MRR1} else {position MRRR1};
	};
	case 2: {
		_text = switch (GVAR(tele_dialog)) do {
			case 0: {(localize "STR_DOM_MISSIONSTRING_608")};
			case 1: {(localize "STR_DOM_MISSIONSTRING_609")};
			case 2: {(localize "STR_DOM_MISSIONSTRING_609")};
		};
		GVAR(beam_target) = 2;
		_end_pos = if (GVAR(player_side) == west) then {position MRR2} else {position MRRR2};
	};
};
#endif

_textctrl ctrlSetText _text;

_ctrlmap = _display displayCtrl 100104;
ctrlMapAnimClear _ctrlmap;

_start_pos = position player;
_ctrlmap ctrlmapanimadd [0.0, 1.00, _start_pos];
_ctrlmap ctrlmapanimadd [1.2, 1.00, _end_pos];
_ctrlmap ctrlmapanimadd [0.5, 0.30, _end_pos];
ctrlmapanimcommit _ctrlmap;