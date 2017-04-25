/* ----------------------------------------------------------------------------
Function: ACE_fnc_startSpectator

Description:
	Start spectator script

Parameters:

Optional Parameters:
	_unit  [Object]
	_killer  [Object]
	_bla  [String]

Returns:
	Spectator scriptHandle

Examples:
	respawn = "seagull"
	In mission folder, create onPlayerRespawnAsSeagull.sqf
	inside it add:
	(begin example)
		_this spawn ace_fnc_startSpectator;
	(end)

	Wait for the moment you wish to run the spectator (e.g waituntil {!alive player};), then execute:
	(begin example)
		[] spawn ace_fnc_startSpectator;
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
#include "script_component.hpp"
private ["_ar"];
TRACE_1("",_this);
_ar = if (isNil "_this" || {typeName _this != "ARRAY"}) then { [] } else { _this };
if (count _ar == 0) then { _ar = [player, player, "null"] };

// Unit sides allowed to use Spectator - Default: All sides allowed.
// example: ace_sys_spectator_SidesApprovedForSpectator = [west];
if (isNil QGVAR(SidesApprovedForSpectator)) then {
	GVAR(SidesApprovedForSpectator) = [west, east, resistance, civilian];
} else {
	if (count GVAR(SidesApprovedForSpectator) == 0 || {count GVAR(SidesApprovedForSpectator) > 4}) then {
		GVAR(SidesApprovedForSpectator) = [west, east, resistance, civilian];
	};
};

if (isPlayer(_ar select 0)  && {playerSide in GVAR(SidesApprovedForSpectator)}) then {
	_ar spawn COMPILE_FILE(specta);
};
