// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#define CFG configFile >> "CfgAmmo" >> _ammo

PARAMS_5(_unit,_bla,_bla,_bla,_ammo);

if (local _unit) then {
	_cfg = CFG >> "ACE_simulation";
	if (isText _cfg) then {
		_simulation = getText _cfg;
		{ TRACE_2("Local",_simulation,_x); _this call _x} forEach (ace_simulation getVariable _simulation );
	};
};

_cfg = CFG >> "ACE_simulation_global";
if (isText _cfg) then {
	_simulation = getText _cfg;
	{ TRACE_2("Global",_simulation,_x); _this call _x} forEach (ace_simulation_global getVariable _simulation );
};
