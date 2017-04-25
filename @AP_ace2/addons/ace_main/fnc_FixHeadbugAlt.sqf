/* ----------------------------------------------------------------------------
Function: ACE_fnc_fixHeadBugAlt

Description:
	Func

Parameters:
	-

Returns:
		nil

Examples:
	(begin example)
		-
	(end)

Author:
	(c) Rocko 2009
---------------------------------------------------------------------------- */
#include "script_component.hpp"
/* ACE_fFixHeadBugAlt.sqf | (c) 2009 by rocko */

#define __fix _logic = createVehicle ["ACE_LogicDummy", getPosATL _dragger, [], 0, "NONE"]; \
_logic moveInCargo (vehicle _dragger); \
_dragger action ["EJECT", vehicle _dragger]; \
_logic action ["EJECT", vehicle _dragger]; \
deleteVehicle _logic;

private["_count"];
PARAMS_1(_respawnDelayTime);
_respawn = _this select 1; // Eject dead on, BASE, INSTANT, GROUP, SIDE - Do NOT eject on, BIRD, NONE as it does not matter
_being_dragged = _this select 2;
_dragger = (driver (vehicle _being_dragged));

if !( (_respawn in ["BIRD", "NONE"]) || {(_respawn in [0, 1])} ) then {

	// Eject dragged player immediately when respawndelay is <= 5
	if (_respawnDelayTime <= 5) then { __fix; }
	else {
		// Eject player five seconds before respawn timer has counted to zero
		_count = 5;
		while {_count != _respawnDelayTime} do {
			INC(_count);
			sleep 1;
		};
		__fix;
	};
};
