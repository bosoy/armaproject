/* ace_sys_spacebar | (c) 2009 by rocko */
      /* aKA */
  /* R1oT M!X3R */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __LAYER 135999

#define __FSM [] execFSM "\x\ace\addons\sys_recognize\fsm_recognize.fsm"
#define __DISP ((uiNamespace getVariable "ACE_Recog_Overlay") displayCtrl -1)
LOG(MSG_INIT);

ADDON = false;

PREP(keypressed);
PREP(recognize_side);
PREP(recognize_type);
PREP(recognize_display);
PREP(recognize_name);
PREP(recognize_accuracy);

PREP(recognize_crew);

GVAR(presstime) = 0;
GVAR(shown) = false;
GVAR(spacebar) = false;

if (isNil QUOTE(ACE_NO_RECOGNIZE)) then { ACE_NO_RECOGNIZE = false; };

FUNC(change_recognize) = {
	private "_selidx";
	PARAMS_1(_selidx);
	if (GVAR(cur_recog_key) != _selidx) then {
		GVAR(cur_recog_key) = _selidx;
		if (GVAR(constant)) then {
			__LAYER cutRsc ["DEFAULT", "PLAIN"];
		};
		GVAR(constant) = false;
		if (GVAR(id_key_id) != -9999) then {
			[GVAR(cur_key_event), GVAR(id_key_id)] call CBA_fnc_removeDisplayHandler;
			GVAR(id_key_id) = -9999;
		};

		if (GVAR(plrespeh) != -9999) then {
			["CBA_playerSpawn", GVAR(plrespeh)] call CBA_fnc_removeEventHandler;
			GVAR(plrespeh) = -9999;
		};
		
		if (GVAR(pfhhandle) != -9999) then {
			[GVAR(pfhhandle)] call cba_fnc_removePerFrameHandler;
			GVAR(pfhhandle) = -9999;
		};

		GVAR(cur_key_event) = "";
		switch (_selidx) do {
			case 0: { GVAR(cur_key_event) = "KeyDown"; GVAR(spacebar) = true; };
			case 1: { GVAR(cur_key_event) = "MouseZChanged"; GVAR(spacebar) = false; };
			case 2: { GVAR(constant) = true; };
			default { GVAR(cur_key_event) = "MouseZChanged"; GVAR(spacebar) = false; };
		};
		if !(GVAR(constant)) then {
			GVAR(id_key_id) = [GVAR(cur_key_event), QUOTE(_handle = _this spawn FUNC(keypressed))] call CBA_fnc_addDisplayHandler;
		} else {
			[] call FUNC(initRecognizePFH);
			GVAR(plrespeh) = ["CBA_playerSpawn", {call FUNC(initRecognizePFH)}] call CBA_fnc_addEventHandler;
		};
	};
};

FUNC(rankString) = {
	_man = _this;
	_rankList = [
		localize "STR_SHORT_PRIVATE",
		localize "STR_SHORT_CORPORAL",
		localize "STR_SHORT_SERGEANT",
		localize "STR_SHORT_LIEUTENANT",
		localize "STR_SHORT_CAPTAIN",
		localize "STR_SHORT_MAJOR",
		localize "STR_SHORT_COLONEL"
	];
	
	if (_man isKindOf "Civilian") then {""} else {
		(_rankList select (rankId _man)) + " ";
	};
};
GVAR(pfhhandle) = -9999;
FUNC(initRecognizePFH) = {
	GVAR(old_player) = player;
	if (ACE_NO_RECOGNIZE) exitWith {
		if (ACE_NO_RECOGNIZE) then { diag_log "ACE_NO_RECOGNIZE"; };
	};
	__LAYER cutRsc ["ACE_Recog_Overlay","PLAIN",0];
	GVAR(pfhhandle) = [FUNC(recognizePFH), 0.67] call cba_fnc_addPerFramehandler;
};

FUNC(recognizePFH) = {
	private["_target","_viewdistance","_distance","_continue"];
	_target = cursorTarget;
	_viewDistance = ((viewDistance/(viewDistance / 1200)) * (1 - fog));
	_distance = player distance _target;
	
	_continue = switch (true) do {
		case (isNull _target): {false};
		case (_viewDistance < _distance): {false};
		case ace_sys_spectator_SPECTATINGON: {false};
		case ((_target isKindOf "Building") && !(_target isKindOf "Reammobox")): {false};
		case (!alive _target): {false};
		case (_target == player): {false};
		case ((_target call ace_sys_recognize_fnc_recognize_side) != "FRIENDLY"): {false};
		default {true};
	};
	if (_continue) then {
		private["_name", "_type"];
		_type = _target call ace_sys_recognize_fnc_recognize_type;
		_name = [_target,_type] call ace_sys_recognize_fnc_recognize_name;
		// Max recognise distance is 200m
		(_name + [_target, 30]) call ace_sys_recognize_fnc_recognize_display;
	} else {
		__DISP ctrlSetStructuredText (composeText [""]);
		if (!alive player || {player != GVAR(old_player)}) then {
			[_this select 1] call cba_fnc_removePerFrameHandler;
			GVAR(pfhhandle) = -9999;
			__LAYER cutRsc ["DEFAULT", "PLAIN"];
		};
	};
};

ADDON = true;
