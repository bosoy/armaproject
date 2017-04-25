#include "script_component.hpp"

////////////////////////////////////////////////////////////
// ACE AH-1Z Gunner MFD & Targeting System Handler Thread //
// by Headspace                                           //
////////////////////////////////////////////////////////////
// Last updated: February 1, 2010 by zGuba

private ["_AH_MFD_HeadingText", "_AH_MFD_TimeText", "_AH_MFD_WeaponIndicator",
         "_AH_MFD_DesignatorStatus", "_AH_MFD_RangeText", "_AH_MFD_DesignatorCircle", "_AH_MFD_ATTKIndicator",
         "_desText", "_rangePadding", "_pulseOffset", "_pulseResults", "_vehicle", "_pollinterval_vehicle_check",
         "_pollinterval_gunner_position"];

PARAMS_2(_player,_vehicle);

// Initialize polling intervals
_pollinterval_vehicle_check = 5;
_pollinterval_gunner_position = 0.1;

if (player in [gunner _vehicle, driver _vehicle]) then {
	// If we get into a new little cobra, we need to reset our modes.
	if (_vehicle != (player getVariable "MY_LITTLE_COBRA")) then {
		_vehicle setVariable ["AH_MODES_INITIALIZED", nil];
	};

	if (isNil {_vehicle getVariable "AH_MODES_INITIALIZED"}) then {
		AH_DISPLAYING_OPTICS = nil;

		// Cobra variable initialization
		player setVariable ["MY_LITTLE_COBRA", _vehicle];
		_vehicle setVariable ["AH_DISTANCE_TO_TARGET", 250];  // In Meters

		AH_CURRENT_WEAPON = "ACE_DAGR_Launcher";
		_vehicle selectWeapon "ACE_DAGR_Launcher";

		_vehicle setVariable ["AH_MODES_INITIALIZED", true]; // Good to go.
	};

	// Perform Initial Load of UI elements
	if (isNil {_vehicle getVariable "AH_SYSTEMS_LOADED"}) then {
		// *** Set up MFD Controls ***
		// Initialize Display

		cutRsc ["AH1Z_MFD_Display", "plain"];	// Internal will care for itself.
	};
};
