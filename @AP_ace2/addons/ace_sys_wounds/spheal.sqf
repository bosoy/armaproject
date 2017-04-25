#include "script_component.hpp"

private ["_bandage", "_isMedic"];

PARAMS_2(_unit,_caller);

if (!alive _unit) exitWith {};
if (!alive _caller) exitWith {};
_isMedic = [_caller] call FUNC(isMedic);
if (_isMedic) exitWith {};

_bandage = BND; // TODO: Shouldn't this support also large bandage etc?
if ((_unit getVariable "ace_w_bleed") > 0) then {
	if ([_unit, player, _bandage] call FUNC(takeItem)) then {
		_caller playMove "AinvPknlMstpSlayWrflDnon_medic";
		[_unit, _bandage] call FUNC(RemoveBleed);
	};
};
_nearMedicFacility = [_unit] call FUNC(nearMedicalFacility);
if (_nearMedicFacility || {isNil "ace_sys_wounds_medics_only"}) then {
	if ((_unit getVariable "ace_w_pain") > 0) then {
		if ([_unit, player, MOR] call FUNC(takeItem)) then {
			_unit call ace_sys_wounds_fnc_RemovePain;
		};
	};
	if ((_unit getVariable "ace_w_epi") != 0) then {
		if ([_unit, player, EPI] call FUNC(takeItem)) then {
			_unit call ace_sys_wounds_fnc_RemoveUncon;
		};
	};
};
