#include "script_component.hpp"

private ["_exit_it", "_allowed", "_nearMedicFacility"];

_exit_it = false;
if (!isNil "ace_sys_wounds_medics_only") then {
	_nearMedicFacility = [player] call FUNC(nearMedicalFacility);

	if (!_nearMedicFacility && {!([player] call FUNC(isMedic))}) then {
		hintSilent (localize "STR_ACE_WOUNDS_NO_EPI");
		_exit_it = true;
	};
};
if (_exit_it) exitWith {};

_allowed = [player, player, EPI] call FUNC(takeItem);
if !(_allowed) exitWith {};

player setVariable ["ACE_PB_Result", 0];
_delay = if ([player] call FUNC(isMedic)) then { 12 } else { 15 };
[_delay,[localize "STR_ACE_UA_USEEPI"],true,true] spawn ace_progressbar;
playSound "ACE_Injector";
waitUntil { (player getVariable "ACE_PB_Result" != 0) };
if (player getVariable "ACE_PB_Result" == 1) then {
	[EPI,player] call FUNC(litter);
	player call FUNC(RemoveUncon);
};
