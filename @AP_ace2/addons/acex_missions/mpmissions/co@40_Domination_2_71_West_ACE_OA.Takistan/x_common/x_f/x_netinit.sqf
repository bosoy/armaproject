//#define __DEBUG__
// by Xeno
#define THIS_FILE "x_netinit.sqf"
#include "x_setup.sqf"

GVAR(event_holder) = GVAR(HeliHEmpty) createVehicleLocal [0, 0, 0];
if (isServer) then {
	GVAR(event_holderCTS) = GVAR(HeliHEmpty) createVehicleLocal [0, 0, 0];
};
GVAR(event_holderSTO) = GVAR(HeliHEmpty) createVehicleLocal [0, 0, 0];
if (!isDedicated) then {
	GVAR(event_holderToClients) = GVAR(HeliHEmpty) createVehicleLocal [0, 0, 0];
};

// multiple events per type
FUNC(NetAddEvent) = {
	__TRACE_1("NetAddEvent","_this")
	private ["_a", "_ea"];
	_a = switch (_this select 0) do {
		case 0: {true}; // all
		case 1: {isServer}; // server only
		case 2: {X_Client}; // client only
		case 3: {isDedicated}; // dedicated only
		case 4: {!isServer}; // client only, 2
	};
	if (_a) then {
		_ea = GVAR(event_holder) getVariable (_this select 1);
		if (isNil "_ea") then {_ea = []};
		_ea set [count _ea, _this select 2];
		GVAR(event_holder) setVariable [_this select 1, _ea];
	};
};

if (isServer) then {
	FUNC(NetAddEventCTS) = {
		__TRACE_1("NetAddEventCTS","_this")
		private ["_ea"];
		_ea = GVAR(event_holderCTS) getVariable (_this select 0);
		if (isNil "_ea") then {_ea = []};
		_ea set [count _ea, _this select 1];
		GVAR(event_holderCTS) setVariable [_this select 0, _ea];
	};
};

FUNC(NetAddEventSTO) = {
	__TRACE_1("NetAddEventSTO","_this")
	private ["_ea"];
	_ea = GVAR(event_holderSTO) getVariable (_this select 0);
	if (isNil "_ea") then {_ea = []};
	_ea set [count _ea, _this select 1];
	GVAR(event_holderSTO) setVariable [_this select 0, _ea];
};

if (!isDedicated) then {
	FUNC(NetAddEventToClients) = {
		__TRACE_1("NetAddEventToClients","_this")
		private ["_ea"];
		_ea = GVAR(event_holderToClients) getVariable (_this select 0);
		if (isNil "_ea") then {_ea = []};
		_ea set [count _ea, _this select 1];
		GVAR(event_holderToClients) setVariable [_this select 0, _ea];
	};
};

FUNC(NetRemoveEvent) = {
	__TRACE_1("NetRemoveEvent","_this")
	if (!isNil {GVAR(event_holder) getVariable _this}) then {GVAR(event_holder) setVariable [_this, nil]};
};

FUNC(NetRemoveEventCTS) = {
	__TRACE_1("NetRemoveEventCTS","_this")
	if (!isNil {GVAR(event_holderCTS) getVariable _this}) then {GVAR(event_holderCTS) setVariable [_this, nil]};
};

FUNC(NetRemoveEventSTO) = {
	__TRACE_1("NetRemoveEventSTO","_this")
	if (!isNil {GVAR(event_holderSTO) getVariable _this}) then {GVAR(event_holderSTO) setVariable [_this, nil]};
};

FUNC(NetRemoveEventServToClients) = {
	__TRACE_1("NetRemoveEventServToClients","_this")
	if (!isNil {GVAR(event_holderToClients) getVariable _this}) then {GVAR(event_holderToClients) setVariable [_this, nil]};
};

FUNC(NetRunEvent) = {
	__TRACE_1("NetRunEvent","_this")
	private ["_ea", "_p", "_pa"];
	_ea = GVAR(event_holder) getVariable (_this select 0);
	if (!isNil "_ea") then {
		__TRACE_1("NetRunEvent found event","_ea")
		_pa = _this select 1;
		if (!isNil "_pa") then {
			{_pa call _x} forEach _ea;
		} else {
			{call _x} forEach _ea;
		};
	};
};

if (isServer) then {
	FUNC(NetRunEventCTS) = {
		__TRACE_1("NetRunEventCTS","_this")
		private ["_ea", "_p", "_pa"];
		_ea = GVAR(event_holderCTS) getVariable (_this select 0);
		if (!isNil "_ea") then {
			__TRACE_1("NetRunEventCTS found event","_ea")
			_pa = _this select 1;
			if (!isNil "_pa") then {
				{_pa call _x} forEach _ea;
			} else {
				{call _x} forEach _ea;
			};
		};
	};
};

FUNC(NetRunEventSTO) = {
	__TRACE_1("NetRunEventSTO","_this")
	private ["_ea", "_p", "_pa", "_obj", "_tt", "_islocal", "_isgrp"];
	_tt = _this select 1;
	_obj = if (typeName _tt == "ARRAY") then {_tt select 0} else {_tt};
	if (isNil "_obj" || {isNull _obj}) exitWith {};
	_islocal = if (typeName _obj != "GROUP") then {
		_isgrp = false;
		local _obj
	} else {
		_isgrp = true;
		local (leader _obj)
	};
	__TRACE_1("NetRunEventSTO","_islocal")
	if (_islocal) then {
		_ea = GVAR(event_holderSTO) getVariable (_this select 0);
		if (!isNil "_ea") then {
			__TRACE_1("NetRunEventSTO found event","_ea")
			_pa = _this select 1;
			if (!isNil "_pa") then {
				{_pa call _x} forEach _ea;
			} else {
				{call _x} forEach _ea;
			};
		};
	} else {
		__TRACE_1("NetRunEventSTO _obj not local","_obj")
		GVAR(nsto) = _this;
		if (isServer) then {
			_owner = if (!_isgrp) then {
				owner _obj
			} else {
				owner (leader _obj)
			};
			__TRACE_1("NetRunEventSTO owner _obj","_obj")
			_owner publicVariableClient QGVAR(nsto);
		} else { // not needed... redundant, who cares
			__TRACE_1("NetRunEventSTO not server send","_obj")
			publicVariableServer QGVAR(nsto);
		};
	};
};

if (!isDedicated) then {
	FUNC(NetRunEventToClients) = {
		__TRACE_1("NetRunEventToClients","_this")
		private ["_ea", "_p", "_pa"];
		_ea = GVAR(event_holderToClients) getVariable (_this select 0);
		if (!isNil "_ea") then {
			__TRACE_1("NetRunEventToClients found event","_ea")
			_pa = _this select 1;
			if (!isNil "_pa") then {
				{_pa call _x} forEach _ea;
			} else {
				{call _x} forEach _ea;
			};
		};
	};
};

// does send a normal publicVariable to all clients/server
// ["eventname", var or array with vars]
FUNC(NetCallEvent) = {
	__TRACE_1("NetCallEvent","_this")
	GVAR(negl) = _this; publicVariable QGVAR(negl);
	_this call FUNC(NetRunEvent);
};

// does not execute code on the client, Client To Server
// sends parameters only to the server
// ["eventname", var or array with vars]
FUNC(NetCallEventCTS) = {
	__TRACE_1("NetCallEventCTS","_this")
	if (isServer) then { // for hosted environment
		_this call FUNC(NetRunEventCTS);
	} else {
		GVAR(ncts) = _this;
		publicVariableServer QGVAR(ncts);
	};
};

// checks if object is local first otherwise tries to send to the owner client making use of publicVariableServer and publicVariableClient (on the server)
// ["eventname", [object, var or vararray]] call FUNC(NetCallEventSTO)
// ["eventname", object] call FUNC(NetCallEventSTO)
FUNC(NetCallEventSTO) = {
	__TRACE_1("NetCallEventSTO","_this")
	private ["_tt", "_obj", "_isLocal"];
	_tt = _this select 1;
	_obj = if (typeName _tt == "ARRAY") then {_tt select 0} else {_tt};
	if (isNil "_obj" || {isNull _obj}) exitWith {};
	_islocal = if (typeName _obj != "GROUP") then {
		local _obj
	} else {
		local (leader _obj)
	};
	__TRACE_1("NetCallEventSTO","_islocal")
	if (!_isLocal) then {
		GVAR(nsto) = _this;
		publicVariableServer QGVAR(nsto);
	} else {
		_this call FUNC(NetRunEventSTO);
	};
};

// does send a normal publicVariable to all clients from server
// ["eventname", var or array with vars]
// prevents that netrun is also running on the server
FUNC(NetCallEventToClients) = {
	__TRACE_1("NetCallEventToClients","_this")
	GVAR(nstc) = _this; publicVariable QGVAR(nstc);
	if (isServer && {!isDedicated}) then {
		_this call FUNC(NetRunEventToClients);
	};
};

XNetCallEvent = FUNC(NetCallEvent);

QGVAR(negl) addPublicVariableEventHandler {
	(_this select 1) call FUNC(NetRunEvent);
};

if (isServer) then {
	QGVAR(ncts) addPublicVariableEventHandler {
		(_this select 1) call FUNC(NetRunEventCTS);
	};
};

QGVAR(nsto) addPublicVariableEventHandler {
	(_this select 1) call FUNC(NetRunEventSTO);
};

if (!isDedicated) then {
	QGVAR(nstc) addPublicVariableEventHandler {
		(_this select 1) call FUNC(NetRunEventToClients);
	};
};

FUNC(NetSetJIP) = {
	__XJIPSetVar [_this select 0,_this select 1,true];
};

/////////////////////////////////////
// Local events

FUNC(LocalCallEvent) = {
	_this call FUNC(NetRunEvent);
};
