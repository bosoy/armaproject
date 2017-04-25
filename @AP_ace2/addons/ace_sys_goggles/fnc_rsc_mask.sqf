/* ace_sys_goggles (.pbo) | (c) 2009, 2010 by rocko */

#include "script_component.hpp"

135214 cutRsc [_this,"PLAIN",0];

GVAR(mask_deh) = false;

// Gasmask workaround fix
sleep 1;
if (format["%1",(uiNamespace getVariable "ACE_Gasmask")] != "No Display") then {
	// displayAddEventhandler
	ACE_GasmaskDisplayHandler_Weapon = (findDisplay 46) displayAddEventhandler ["KeyDown", "["""",(_this select 1)] call ace_sys_goggles_overlay_change"];
	ACE_GasmaskDisplayHandler_Mouse = (findDisplay 46) displayAddEventhandler ["MouseZChanged", "["""",(actionKeys ""toggleWeapons"") select 0] call ace_sys_goggles_overlay_change"];
	GVAR(mask_deh) = true;
};
