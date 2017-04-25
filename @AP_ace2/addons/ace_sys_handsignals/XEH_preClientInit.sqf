//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define ACE_TEXT_RED(Text) ("<t size='1.2' font='Zeppelin32' color='#FF0000'>" + ##Text + "</t>")

LOG(MSG_INIT);

ADDON = false;

PREP(exec);

[QGVAR(1), { _this playaction "gestureFreeze" }] call CBA_fnc_addEventHandler;
[QGVAR(2), { _this playaction "GestureGo" }] call CBA_fnc_addEventHandler;
[QGVAR(3), { _this playaction "GestureCover" }] call CBA_fnc_addEventHandler;
[QGVAR(4), { _this playaction "GestureAttack" }] call CBA_fnc_addEventHandler;
[QGVAR(5), { _this playaction "GestureCeaseFire" }] call CBA_fnc_addEventHandler;
[QGVAR(6), { _this playaction "GestureFollow" }] call CBA_fnc_addEventHandler;
[QGVAR(7), { _this playaction "GestureUp" }] call CBA_fnc_addEventHandler;
[QGVAR(8), { _this playaction "GestureAdvance" }] call CBA_fnc_addEventHandler;
[QGVAR(9), { _this playaction "GesturePoint" }] call CBA_fnc_addEventHandler;

FUNC(numpad) = {
	PARAMS_1(_id);
	if ((["ACE", "sys_handsignals", "method"] call ace_settings_fnc_getNumber) != 2) exitWith { false };
	if (getNumber(configFile >> "CfgWeapons" >> (currentWeapon player) >> "type") == 4) exitWith { false };
	if (player != vehicle player) exitWith { false };
	[player,player,-1,[_id]] call FUNC(exec);
	true
};

FUNC(hs_add) = {
	PARAMS_1(_unit);
	GVAR(H_ID_AR) = [
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_FREEZE"), QUOTE(PATHTO(fnc_exec)), ["1"], 27309, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_GO"), QUOTE(PATHTO(fnc_exec)), ["2"], 27308, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_TAKECOVER"), QUOTE(PATHTO(fnc_exec)), ["3"], 27307, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_OPENFIRE"), QUOTE(PATHTO(fnc_exec)), ["4"], 27306, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_CEASEFIRE"), QUOTE(PATHTO(fnc_exec)), ["5"], 27305, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_FOLLOW"), QUOTE(PATHTO(fnc_exec)), ["6"], 27304, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_UP"), QUOTE(PATHTO(fnc_exec)), ["7"], 27303, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_ADVANCE"), QUOTE(PATHTO(fnc_exec)), ["8"], 27302, false, true, "", ""],
		_unit addAction [ACE_TEXT_RED(localize "STR_ACE_HANDSIGNAL_WATCH"), QUOTE(PATHTO(fnc_exec)), ["9"], 27301, false, true, "", ""]
	];
};

FUNC(hs_remove) = {
	PARAMS_1(_unit);
	{_unit removeAction _x} forEach GVAR(H_ID_AR);
	GVAR(H_ID_AR) = nil;
};

GVAR(dialog_open) = false;
GVAR(keyup_handler) = -9999;

GVAR(gesturesarray) = [
	[["MS;ME;","MS;MW;","ME;MS;"], {[QGVAR(1), player] call CBA_fnc_LocalEvent}],
	[["MW;", "TW;", "BW;"], {[QGVAR(2), player] call CBA_fnc_LocalEvent}],
	[["MS;"], {[QGVAR(3), player] call CBA_fnc_LocalEvent}],
	[["MN;"], {[QGVAR(4), player] call CBA_fnc_LocalEvent}],
	[["ME;"], {[QGVAR(5), player] call CBA_fnc_LocalEvent}],
	[["SE;"], {[QGVAR(6), player] call CBA_fnc_LocalEvent}],
	[["NE;"], {[QGVAR(7), player] call CBA_fnc_LocalEvent}],
	[["NW;"], {[QGVAR(8), player] call CBA_fnc_LocalEvent}],
	[["SW;"], {[QGVAR(9), player] call CBA_fnc_LocalEvent}]
	//[["LS;"], {call FUNC(TabShoulder)}]
];

FUNC(DirTo) = {
	private ["_ret"];
	PARAMS_2(_pos1,_pos2);
	_ret = ((_pos2 select 0) - (_pos1 select 0)) atan2 ((_pos2 select 1) - (_pos1 select 1));
	if (_ret < 0) then {_ret = _ret + 360};
	_ret
};

FUNC(KeyFuncDown) = {
	// Numpad check
	if ((["ACE", "sys_handsignals", "method"] call ace_settings_fnc_getNumber) == 2) exitWith { false };
	// Actionmenu
	if ((["ACE", "sys_handsignals", "method"] call ace_settings_fnc_getNumber) == 1) then {
		if (getNumber(configFile >> "CfgWeapons" >> (currentWeapon player) >> "type") == 4) exitWith { false };
		if (player getVariable [QGVAR(hs),false]) exitWith { false };
		player setVariable [QGVAR(hs),true];
		player call FUNC(hs_add);
	} else { // Image
		if (GVAR(dialog_open)) exitWith {};
		GVAR(dialog_open) = true;
		createDialog "ACE_EmptyMouseGestureDialog";
		_ctrltext = if ((["ACE", "sys_handsignals", "background_enabled"] call ace_settings_fnc_getNumber) == 1) then {
			("x\ace\addons\sys_handsignals\data\" + localize "STR_ACE_HANDSIGNALS_PIC")
		} else {
			""
		};
		disableSerialization;
		((uiNamespace getVariable "ACE_EmptyMouseGestureDialog") displayCtrl 999) ctrlSetText _ctrltext;
		setMousePosition [0.5, 0.5];
		GVAR(mouse_down) = false;
		GVAR(gesturestring) = "";
		GVAR(keyup_handler) = (findDisplay 46) displayAddEventHandler ["keyup", "
			if (_this select 1 == (['CBA', 'events', 'ace_sys_handsignals', 'Mouse_Gesture', 'key'] call ace_settings_fnc_getNumber)) then {_this call ace_sys_handsignals_fnc_KeyUp};
			false
		"];
	};
};

FUNC(KeyUp) = {
	if (!GVAR(dialog_open)) exitWith {};
	GVAR(dialog_open) = false;
	if (dialog) then {closeDialog 0};
	GVAR(nexttime) = time + 0.3;
	if (GVAR(keyup_handler) != -9999) then {
		(findDisplay 46) displayRemoveEventHandler ["keyup", GVAR(keyup_handler)];
		GVAR(keyup_handler) = -9999;
	};
	if (!alive player) exitWith {};
	// gesturecheck
	if (GVAR(gesturestring) != "") then {
		{
			if (GVAR(gesturestring) in (_x select 0)) exitWith {
				call (_x select 1)
			};
		} forEach GVAR(gesturesarray)
	};
	false
};

FUNC(MouseButtonDownFunc) = {
	if (_this select 1 != 0) exitWith {};
	GVAR(mouse_down) = true;
	GVAR(old_mouse_pos) = [_this select 2, _this select 3];
	GVAR(prevgesture) = "";
	GVAR(olddir) = -9000;
};

FUNC(MouseMovingFunc) = {
	private ["_curmpos", "_xmp", "_ymp"];
	if (!GVAR(mouse_down)) exitWith {};
	_xmp = _this select 1;
	_ymp = _this select 2;
	_curmpos = [_xmp, _ymp];
	if (_curmpos distance GVAR(old_mouse_pos) >= 0.3) then {
		_dir = [GVAR(old_mouse_pos), _curmpos] call FUNC(DirTo);
		if (_dir >= (GVAR(olddir) + 22.5) || {_dir <= (GVAR(olddir) - 22.5)}) then {
			GVAR(olddir) = _dir;
			GVAR(old_mouse_pos) = _curmpos;
			// L = left
			// T = top
			// R = right
			// B = Bottom
			// M = Middle
			// examples:
			// TW;MS;  = T
			// MS; = Line from top middle screen to bottom middle screen
			_mpos = "";
			_gesture = switch (true) do {
				case (_dir < 22.5 || {_dir >= 337.5}): {
					_mpos =  switch (true) do {
						case (_xmp <= 0.25): {"L"};
						case (_xmp > 0.25 && {_xmp <= 0.75}): {"M"};
						default {"R"};
					};
					"S;"
				};
				case (_dir < 337.5 && {_dir >= 292.5}): { "SW;" };
				case (_dir < 292.5 && {_dir >= 247.5}): {
					_mpos =  switch (true) do {
						case (_ymp <= 0.25): {"T"};
						case (_ymp > 0.25 && {_ymp <= 0.75}): {"M"};
						default {"B"};
					};
					"W;"
				};
				case (_dir < 247.5 && {_dir >= 202.5}): { "NW;" };
				case (_dir < 202.5 && {_dir >= 157.5}): {
					_mpos =  switch (true) do {
						case (_xmp <= 0.25): {"L"};
						case (_xmp > 0.25 && {_xmp <= 0.75}): {"M"};
						default {"R"};
					};
					"N;"
				};
				case (_dir < 157.5 && {_dir >= 112.5}): { "NE;" };
				case (_dir < 112.5 && {_dir >= 67.5}): {
					_mpos =  switch (true) do {
						case (_ymp <= 0.25): { "T" };
						case (_ymp > 0.25 && {_ymp <= 0.75}): { "M" };
						default { "B" };
					};
					"E;"
				};
				case (_dir < 67.5 && {_dir >= 22.5}): { "SE;" };
				default { "U;" };
			};
			_gesture = _mpos + _gesture;
			if (GVAR(prevgesture) != _gesture) then {
				GVAR(prevgesture) = _gesture;
				GVAR(gesturestring) = GVAR(gesturestring) + _gesture;
			};
		};
	};
};

FUNC(RemoveActions) = {
	if (!isNil QGVAR(H_ID_AR)) then {
		player call FUNC(hs_remove);
	};
	player setVariable [QGVAR(hs),false];
};

FUNC(MouseButtonUpFunc) = {
	if (_this select 1 != 0) exitWith {};
	GVAR(mouse_down) = false;
};

GVAR(nexttime) = -1;

FUNC(onMouseGesturesKeyPressed) = {
	if (time >= GVAR(nexttime)) then {
		if (alive player && {vehicle player == player} && {!([player] call ace_sys_wounds_fnc_isUncon)}) then {
			_this call FUNC(KeyFuncDown)
		};
	};
	false
};

//GVAR(KP) = ["KeyDown", "diag_log [_this];player sideChat str(_this);if (_this select 1 == 29 && {(_this select 3)}) then {[0, _this] call ace_sys_handsignals_fnc_onMouseGesturesKeyPressed}"] call CBA_fnc_addDisplayHandler;

[QUOTE(ADDON), "Mouse_Gesture", { call FUNC(onMouseGesturesKeyPressed) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Mouse_Gesture", { call FUNC(RemoveActions); false }, "keyUp"] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "HS_STOP", { ["1"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_GO", { ["2"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_COVER", { ["3"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_ATTACK", { ["4"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_CEASEFIRE", { ["5"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_FOLLOW", { ["6"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_UP", { ["7"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_ADVANCE", { ["8"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "HS_POINT", { ["9"] call FUNC(numpad) }] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
