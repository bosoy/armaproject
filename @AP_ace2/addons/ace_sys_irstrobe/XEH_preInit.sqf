/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009, 2010, 2011 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

GVAR(ison) = false;
GVAR(ison_throw) = false;
GVAR(nostrobeon) = true;
GVAR(local_array) = [];
GVAR(restart) = 0; // Legacy purposes

PREP(throw_IRStrobe);
PREP(array_add);
PREP(array_remove);
PREP(pickup);
PREP(turnonoff);

FUNC(startStrobe) = {
	PARAMS_1(_strobe);
	if (isNull _strobe) exitWith {};
	_strobe setVariable [QGVAR(fsm), [_strobe] execFSM "\x\ace\addons\sys_irstrobe\fnc_blink.fsm"];
	_strobe setVariable [QGVAR(isOn),true,true];
};

FUNC(startStrobeHuntIR) = {
	PARAMS_1(_strobe);
	if (isNull _strobe) exitWith {};
	_strobe setVariable [QGVAR(fsm2), [_strobe] execFSM "\x\ace\addons\sys_irstrobe\fnc_blinkhuntir.fsm"];
	_strobe setVariable [QGVAR(isOn),true,true];
};

FUNC(endStrobe) = {
	private ["_fsm"];
	PARAMS_1(_strobe);
	if (isNull _strobe) exitWith {};
	_fsm = _strobe getVariable QGVAR(fsm);
	if !(isNil "_fsm") then {
		_fsm setFSMVariable ["_exit", true]; // Termiantes the FSM gracefully - running end condition etc
	};
	_strobe setVariable [QGVAR(isOn),false,true];
};

FUNC(endStrobeHuntIR) = {
	private ["_fsm"];
	PARAMS_1(_strobe);
	if (isNull _strobe) exitWith {};
	_fsm = _strobe getVariable QGVAR(fsm2);
	if !(isNil "_fsm") then {
		_fsm setFSMVariable ["_exit", true]; // Termiantes the FSM gracefully - running end condition etc
	};
	_strobe setVariable [QGVAR(isOn),false,true];
};

// Register events
["shotIR", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;

[QGVAR(arrm), {_this call FUNC(array_remove)}] call CBA_fnc_addEventHandler;
[QGVAR(aradd), {_this call FUNC(array_add)}] call CBA_fnc_addEventHandler;

if !(isDedicated) then {
	// Nvg event
	["ace_nvg_off", { { [_x] call FUNC(endStrobe) } forEach GVAR(local_array) }] call CBA_fnc_addEventhandler;
	["ace_nvg_on", { { [_x] call FUNC(startStrobe) } forEach GVAR(local_array) }] call CBA_fnc_addEventhandler;

	// HuntIR event
	["ace_ir_off", { { [_x] call FUNC(endStrobeHuntIR) } forEach GVAR(local_array) }] call CBA_fnc_addEventhandler;
	["ace_ir_on", { { [_x] call FUNC(startStrobeHuntIR) } forEach GVAR(local_array) }] call CBA_fnc_addEventhandler;
};

ADDON = true;
