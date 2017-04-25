/* ace_sys_spacebar | (c) 2009 by rocko */
      /* aKA */
  /* R1oT M!X3R */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __Scanning_Method (["ACE", "ACE_RECOGNITION","Scanning_Method"] call ace_settings_fnc_getNumber)
#define __Complex_Unit_Info (["ACE", "ACE_RECOGNITION","Complex_Unit_Info"] call ace_settings_fnc_getNumber)
#define __Player_Unit_Info (["ACE", "ACE_RECOGNITION","Player_Unit_Info"] call ace_settings_fnc_getNumber)
#define __FSM [] execFSM "\x\ace\addons\sys_recognize\fsm_recognize.fsm"

LOG(MSG_INIT);

ADDON = false;

//#define __constant_debug

[] spawn {
	private["_key","_keyevent"];
	waitUntil { sleep 1; !isNull (findDisplay 46) };
	_key = __Scanning_Method;
	
	GVAR(cur_recog_key) = _key;
	GVAR(id_key_id) = -9999;
	GVAR(plrespeh) = -9999;
#ifndef __constant_debug
	GVAR(constant) = false;

	_keyevent = "";
	switch (_key) do {
		case 0: { _keyevent = "KeyDown"; GVAR(spacebar) = true; };
		case 1: { _keyevent = "MouseZChanged"; GVAR(spacebar) = false; };
		case 2: { GVAR(constant) = true; };
		default { _keyevent = "MouseZChanged"; GVAR(spacebar) = false; };
	};
	GVAR(cur_key_event) = _keyevent;
	
	if !(GVAR(constant)) then {
		TRACE_2("MouseWheel for ACE_SYS_RECOGNIZE is", _key,GVAR(spacebar));
		GVAR(id_key_id) = [_keyEvent, QUOTE(_handle = _this spawn FUNC(keypressed))] call CBA_fnc_addDisplayHandler;
	} else {
		TRACE_2("Constant Recognize","");
		[] call FUNC(initRecognizePFH);
		GVAR(plrespeh) = ["CBA_playerSpawn", {call FUNC(initRecognizePFH)}] call CBA_fnc_addEventHandler;
	};
#else
	diag_log "Recognize Debug FSM";
	[] call FUNC(initRecognizePFH);
	GVAR(plrespeh) = ["CBA_playerSpawn", {call FUNC(initRecognizePFH)}] call CBA_fnc_addEventHandler;
#endif

	_cmp = __Complex_Unit_Info;
	_plr = __Player_Unit_Info;
	
	if (isNil QGVAR(info_override)) then {
		GVAR(info_complex) = switch (_cmp) do {
			case 0: { 0 };
			case 1: { 1 };
			default { 0 };
		};
		
		GVAR(info_players) = switch (_plr) do {
			case 0: { 0 };
			case 1: { 1 };
			default { 0 };
		};
	};
};

ADDON = true;
