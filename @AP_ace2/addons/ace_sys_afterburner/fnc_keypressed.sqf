
#include "script_component.hpp"

TRACE_1("KEYPRESS DETECTED", _this);

if (player != driver (vehicle player)) exitWith { TRACE_1("NOT DRIVER","");false };

#define __hasAB
if !([vehicle player] call FUNC(hasAfterburner)) exitWith { TRACE_1("NO AB","");false };

private "_getVar";
_getVar = (vehicle player) getVariable QGVAR(running);

private "_case";
_case = _this select 1;

switch (toLower _case) do {
	case "down": {
		GVAR(afterburner) = true;
		if (isNil "_getVar") then { _getVar = false; };
		if !(_getVar) then { [vehicle player] spawn FUNC(afterburner); };	// Publish to clients ?
		TRACE_2("AB SCRIPT RUNNING",GVAR(afterburner),_getVar);
	};
	case "up": {
		GVAR(afterburner) = false;
		TRACE_1("",GVAR(afterburner));
	};
};

false