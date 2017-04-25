#include "script_component.hpp"

PARAMS_1(_cargo);

player playmove "AinvPknlMstpSlayWrflDnon_medic";
sleep 5;
player addMagazine "ACE_Rope_M5";
_cargo setVariable [QGVAR(hasSlingRope), false, true];

// Unlock
if (_cargo call CBA_fnc_locked) then {
	_lockedBefore = _cargo getVariable [QGVAR(locked), false];
	if !(_lockedBefore) then {
		[QGVAR(lock), [_cargo, false]] call CBA_fnc_globalEvent;
	};
};
