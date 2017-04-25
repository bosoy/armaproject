/* ----------------------------------------------------------------------------
Function: ACE_fnc_fixHeadBug

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
/* HEADBUG FIX by rocko*/

if (vehicle player != player) exitWith {};
titleCut ["", "PLAIN"];
_pos = getposATL player;
// create invisible headbug fix vehicle
_ACE_HeadbugFix = createVehicle ["ACE_Headbug_Fix", getposATL player, [], 0, "NONE"];
player moveinDriver _ACE_HeadbugFix;
sleep 1.0;
unassignVehicle player;
player action ["Eject", vehicle player];
sleep 1.0;
deleteVehicle _ACE_HeadbugFix;
player setposATL _pos;
titleText ["", "PLAIN"];
