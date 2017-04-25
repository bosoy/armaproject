//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __blb ["NVGoggles"]
PARAMS_1(_unit);

private "_binocs";
_binocs = [];

{ // find binocs excluding items in black list
	if (getNumber (configFile >> "CfgWeapons" >> _x >> "type") == 4096) then {
		if !(_x in __blb) then {_binocs set [count _binocs, _x]};
	};
} forEach weapons _unit;
TRACE_1("",_binocs);
_binocs;