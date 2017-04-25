//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_dialogClass", "_hasGuided"];

// disable for debug
if (vehicle player == player || {!(vehicle player isKindOf "Air")}) exitWith {};

GVAR(currentDialogClass) = getText (configFile >> "CfgVehicles" >> typeOf (vehicle Player) >> "ACE_mfdClass");

GVAR(currentDialogClass) = QGVAR(MFD_Dialog);

TRACE_1("", GVAR(currentDialogClass));

if (GVAR(currentDialogClass) != "") then {

	// TODO: disabled has_guided test to change for CBU. need to change this so all vehicles have a MFD, and just change
	// what is displayed
	// check to see if the vehicle carrys the appropriate munitions	
	//_hasGuided = [(typeOf (vehicle player))] call FUNC(hasLaserGuided);
	
	//if(_hasGuided) then {
		GVAR(currentDialog) = nil;
		DISPLAY_ID cutRsc [GVAR(currentDialogClass), "PLAIN", 1];

		// we are opening, assign our override hotkeys
		GVAR(KeyPressHandler) = (findDisplay 46) displayAddEventHandler ["KeyDown", "[_this] call ace_sys_mfd_fnc_onKeyPress;"];
	//};
};
