/* ace_sys_goggles (.pbo) | (c) 2009, 2010 by rocko */

#include "script_component.hpp"

PARAMS_1(_unit);

private["_old_identity"];
_old_identity = _unit getVariable QGVAR(identity);
if (isNil "_old_identity") exitWith { TRACE_1("No identity found",""); };

TRACE_1("Old ID",_old_identity);

_unit setVariable [QGVAR(identity),"ACE_Original_Identity",true];
_unit setVariable [QGVAR(earplugs), false, false];
_unit setVariable [QGVAR(protection), -1, false];

if (_old_identity != "ACE_Original_Identity") then { _unit addWeapon _old_identity; };

135214 cutRsc["Default","PLAIN"];

// Should resolve respawned units still having the action to "Remove goggles"
if (GVAR(mask_deh)) then {
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", ACE_GasmaskDisplayHandler_Weapon];
	(findDisplay 46) displayRemoveEventHandler ["MouseZChanged", ACE_GasmaskDisplayHandler_Mouse];
	GVAR(mask_deh) = false;
};
