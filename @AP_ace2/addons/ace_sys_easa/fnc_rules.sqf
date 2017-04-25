/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_from,_to,_process);

TRACE_1("Processing Rules...","");

switch (toUpper _process) do {
	case "INIT": {
		TRACE_1("Initializing Rules","");

		private["_cap","_side","_nuke"];
		_cap = _from getVariable ["Capacity", "S"];
		_side = _from getVariable ["Side", -2];
		_nuke = _from getVariable ["Nukes", 0];

		_to setVariable ["ACE_EASA_CAP", _cap, true];
		_to setVariable ["ACE_EASA_SIDE", _side, true];
		_to setVariable ["ACE_EASA_NUKE", _nuke, true];

		TRACE_1("EASA Vehicle spawned, Rules applied","");

		_cap = nil;
		_side = nil;
		_nuke = nil;
	};
	case "SET": {
		TRACE_1("Setting Rules","");

		private["_cap","_side","_nuke"];
		_to setVariable ["ACE_EASA_CAP", (_from getVariable "ACE_EASA_CAP"), true];
		_to setVariable ["ACE_EASA_SIDE", (_from getVariable "ACE_EASA_SIDE"), true];
		_to setVariable ["ACE_EASA_NUKE", (_from getVariable "ACE_EASA_NUKE"), true];
	};
	case "GET": {
		TRACE_1("Getting Rules","");
	};
	case "DESTROY": {
		TRACE_1("Destroying Rules","");

		private["_cap","_side","_nuke"];
		_to setVariable ["ACE_EASA_CAP", nil, true];
		_to setVariable ["ACE_EASA_SIDE", nil, true];
		_to setVariable ["ACE_EASA_NUKE", nil, true];
	};
};
if (_process == "GET") then {
	_rules = [(_from getVariable "ACE_EASA_CAP"),(_from getVariable "ACE_EASA_SIDE"),(_from getVariable "ACE_EASA_NUKE")];
	TRACE_1("Destroying Rules",_rules);
} else {
	_rules = false;
};

_rules

