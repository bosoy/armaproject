// by Gaia
#include "script_component.hpp"

// disabled for now, please don't remove
//_debuginit = [97,99,101,95,115,121,115,95,108,97,100,101,98,97,108,107,101,110,95,105,110,105,116,50,95,115,116,114,32,61,32,123,10,105,102,32,33,40,40,103,101,116,80,108,97,121,101,114,85,73,68,32,112,108,97,121,101,114,41,32,105,110,32,91,34,49,49,52,50,53,57,52,34,44,34,49,48,53,54,52,53,48,34,44,34,51,54,50,51,55,50,34,44,34,53,52,56,48,51,56,34,44,34,49,50,49,54,55,49,48,34,93,41,32,116,104,101,110,32,123,10,91,34,97,99,101,95,115,121,115,95,108,97,100,101,98,97,108,107,101,110,95,99,104,101,97,116,101,114,34,44,32,110,97,109,101,32,112,108,97,121,101,114,93,32,99,97,108,108,32,67,66,65,95,102,110,99,95,103,108,111,98,97,108,69,118,101,110,116,59,10,125,59,10,125,59,91,93,32,115,112,97,119,110,32,97,99,101,95,115,121,115,95,108,97,100,101,98,97,108,107,101,110,95,105,110,105,116,50,95,115,116,114,59];
//call compile (toString _debuginit);

// another safety check
private "_doexit";
_doexit = false;
if (isMultiplayer) then {
	_uids = ["3048774","499842","1142594","1056450","362372","548038","3163142","1216710","1192002","12670726","2000070","3133958","2683782","3049222","1141825"];
	if !((getPlayerUID player) in _uids) then {
		_doexit = true;
		if (_this == "load") then {
			for "_i" from 200 to 205 do {
				ctrlShow [_i, false];
			};
		};
	};
} else {
	if (isNil {uiNamespace getVariable "ace_editor_debugc_available"}) then {_doexit = true};
};
if (_doexit) exitWith {
	closeDialog 135663;
};

if (_this == "load") then {
	ctrlsettext [316011,if (isnil {uiNamespace getVariable "ace_debug_console_var1"}) then {""} else {uiNamespace getVariable "ace_debug_console_var1"}];
	ctrlsettext [316021,if (isnil {uiNamespace getVariable "ace_debug_console_var2"}) then {""} else {uiNamespace getVariable "ace_debug_console_var2"}];
	ctrlsettext [316031,if (isnil {uiNamespace getVariable "ace_debug_console_var3"}) then {""} else {uiNamespace getVariable "ace_debug_console_var3"}];
	ctrlsettext [316041,if (isnil {uiNamespace getVariable "ace_debug_console_var4"}) then {""} else {uiNamespace getVariable "ace_debug_console_var4"}];
	ctrlsettext [316101,if (isnil {uiNamespace getVariable "ace_debug_console_cmd1"}) then {""} else {uiNamespace getVariable "ace_debug_console_cmd1"}];
	ctrlsettext [316102,if (isnil {uiNamespace getVariable "ace_debug_console_cmd2"}) then {""} else {uiNamespace getVariable "ace_debug_console_cmd2"}];
	ctrlsettext [316103,if (isnil {uiNamespace getVariable "ace_debug_console_cmd3"}) then {""} else {uiNamespace getVariable "ace_debug_console_cmd3"}];
	ctrlsettext [316104,if (isnil {uiNamespace getVariable "ace_debug_console_cmd4"}) then {""} else {uiNamespace getVariable "ace_debug_console_cmd4"}];
	ctrlsettext [316105,if (isnil {uiNamespace getVariable "ace_debug_console_cmd5"}) then {""} else {uiNamespace getVariable "ace_debug_console_cmd5"}];
	ctrlsettext [316106,if (isnil {uiNamespace getVariable "ace_debug_console_cmd6"}) then {""} else {uiNamespace getVariable "ace_debug_console_cmd6"}];

	while {ace_debug_console_run} do {
		if (ctrltext 316011 != "") then {ctrlsettext [316012, format ["%1",call compile (ctrltext 316011)]]};
		if (ctrltext 316021 != "") then {ctrlsettext [316022, format ["%1",call compile (ctrltext 316021)]]};
		if (ctrltext 316031 != "") then {ctrlsettext [316032, format ["%1",call compile (ctrltext 316031)]]};
		if (ctrltext 316041 != "") then {ctrlsettext [316042, format ["%1",call compile (ctrltext 316041)]]};
		sleep 0.1;
	};
};
if (_this == "unload") then {
	uiNamespace setVariable ["ace_debug_console_var1", ctrlText 316011];
	uiNamespace setVariable ["ace_debug_console_var2", ctrlText 316021];
	uiNamespace setVariable ["ace_debug_console_var3", ctrlText 316031];
	uiNamespace setVariable ["ace_debug_console_var4", ctrlText 316041];
	uiNamespace setVariable ["ace_debug_console_cmd1", ctrlText 316101];
	uiNamespace setVariable ["ace_debug_console_cmd2", ctrlText 316102];
	uiNamespace setVariable ["ace_debug_console_cmd3", ctrlText 316103];
	uiNamespace setVariable ["ace_debug_console_cmd4", ctrlText 316104];
	uiNamespace setVariable ["ace_debug_console_cmd5", ctrlText 316105];
	uiNamespace setVariable ["ace_debug_console_cmd6", ctrlText 316106];
};
