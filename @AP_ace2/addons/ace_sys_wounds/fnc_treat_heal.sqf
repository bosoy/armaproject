#include "script_component.hpp"

// Heal treatment by Medics, possible at medical objects like Mash etc.
#define MEDKIT "ACE_Medkit"
#define TREAT_TIME 120

PARAMS_3(_unit,_healer,_damage);

_isTheP = player == _healer;
if !(alive _unit) exitWith {
	if (_isTheP) then { hintSilent (localize "STR_ACE_WOUNDS_HEISDEAD") };
};

_allowed = [_unit, _healer, MEDKIT] call FUNC(takeItem);

if !(_allowed) exitWith {
	if (_isTheP) then { hintSilent "No MedKit" };
};

if (_damage == 0) exitWith {
	if (_isTheP) then { hintSilent "He looks fine" };
};

if (_isTheP) then { hintSilent ("Treating: " + name _unit) };

_nearMedicFacility = [_unit] call FUNC(nearMedicalFacility);
_coef = if (_nearMedicFacility) then { 0.5 } else { 1 };
_leftdamagemodifier = [_unit] call FUNC(getBestNearestMedicalFacility);
_timeOut = (TREAT_TIME * _coef) * _damage;
_endTime = time + _timeOut;

// Play animation on the other unit
if (_unit != _healer) then { [QGVAR(surg), [_unit,_timeOut]] call ACE_fnc_receiverOnlyEvent };

_healer setVariable ["ace_w_healing", true];
_abort = false;

_healer setVariable ["ACE_PB_Result", 0];
[_timeOut,[localize "STR_ACE_UA_HEAL"],false,true,_healer,true] spawn ace_progressbar;
_healer playMove "AinvPknlMstpSlayWrflDnon_medic";

waitUntil { (_healer getVariable "ACE_PB_Result" != 0) };
if (_healer getVariable "ACE_PB_Result" == 1) then {
	_treated = if (_nearMedicFacility) then { localize "STR_ACE_WOUNDS_HEALED" } else { localize "STR_ACE_WOUNDS_PATCHED" };
	if (_isTheP) then { hintSilent (localize "STR_ACE_WOUNDS_SUCK" + " " + _treated) };
	[MEDKIT,_healer] call FUNC(litter);
	[QGVAR(heal), [_unit,_leftdamagemodifier]] call ACE_fnc_receiverOnlyEvent;
};
_healer setVariable ["ace_w_healing", false];
if (_unit != _healer) then { [QGVAR(surg_abort), _unit] call ACE_fnc_receiverOnlyEvent };
