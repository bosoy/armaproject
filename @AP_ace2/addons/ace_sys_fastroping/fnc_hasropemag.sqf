/* ace_sys_fastroping */

#include "script_component.hpp"

PARAMS_1(_unit);

private "_r";
_r = "";
{
	if (getText(configFile >> "CfgMagazines" >> _x >> "ACE_FastRope_Model") != "") exitWith {_r = _x};
} forEach magazines _unit;

// TODO: Enable once, sys_slingload is functional
// Dirty hack to prevent fastroping when the helicopter is already carrying a sling load

if ((vehicle _unit) getVariable ["isTransporting", false]) then {_r = ""};

_r
