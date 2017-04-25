// #define DEBUG_MODE_FULL
#include "script_component.hpp"

// Self action, in light blue and most negative value
#define ACE_TEXT_LIGHTBLUE(Text) ("<t color='#0303ff'>" + ##Text + "</t>")
#define __STOPBLEED ACE_TEXT_LIGHTBLUE(localize "STR_ACE_UA_STOPBLEED")
#define __USEMORPHI ACE_TEXT_LIGHTBLUE(localize "STR_ACE_UA_USEMORPHI")
#define __USEEPI ACE_TEXT_LIGHTBLUE(localize "STR_ACE_UA_USEEPI")

#define _state_blackingOut 801 // semi-lucid

private ["_exitloop","_pain_action","_epi_action","_epi_and_morph", "_unit"];
sleep 5;
if (isNil "ace_sys_wounds_enabled") exitWith {};

_nearMedicFacility = [player] call FUNC(nearMedicalFacility);
_epi_and_morph = if (!isNil "ace_sys_wounds_medics_only") then {
	([player] call FUNC(isMedic) || {_nearMedicFacility})
} else {
	true
};

while {true} do {
	_bandage_action = -9999;
	_pain_action = -9999;
	_epi_action = -9999;
	waitUntil {alive player};
	sleep 1;

	while {true} do {
		_unit = player;
		if (alive _unit && {!(_unit call FUNC(isUncon))}) then {
			// bandage
			if ((_unit getVariable "ace_w_bleed") > 0 && {_bandage_action == -9999}) then {
				if (BND in magazines _unit) then {
					_bandage_action = _unit addAction [__STOPBLEED, QPATHTO_F(self_bandage), BND,-1];
				};
			} else {
				if ((_unit getVariable "ace_w_bleed") == 0 && {_bandage_action != -9999}) then {
					_unit removeAction _bandage_action;
					_bandage_action = -9999;
				};
			};

			if (_epi_and_morph) then {
				// morphine
				if ((_unit getVariable "ace_w_pain") > 0 && {_pain_action == -9999}) then {
					if (MOR in magazines _unit) then {
						_pain_action = _unit addAction [__USEMORPHI, QPATHTO_F(self_morphine),"",-1];
					};
				} else {
					if ((_unit getVariable "ace_w_pain") == 0 && {_pain_action != -9999}) then {
						_unit removeAction _pain_action;
						_pain_action = -9999;
					};
				};

				// epi
				if ((_unit getVariable "ace_w_state") >= _state_blackingOut && {_epi_action == -9999}) then {
					if (EPI in magazines _unit) then {
						_epi_action = _unit addAction [__USEEPI, QPATHTO_F(self_epi),"",-1];
					};
				} else {
					if ((_unit getVariable "ace_w_state") < _state_blackingOut && {_epi_action != -9999}) then {
						_unit removeAction _epi_action;
						_epi_action = -9999;
					};
				};
			};
		};

		// remove all actions
		if (!alive _unit || {(_unit call FUNC(isUncon))}) exitWith {
			if (_bandage_action != -9999) then {
				_unit removeAction _bandage_action;
			};
			if (_epi_and_morph) then {
				if (_pain_action != -9999) then {
					_unit removeAction _pain_action;
				};
				if (_epi_action != -9999) then {
					_unit removeAction _epi_action;
				};
			};
		};
		sleep 0.5;
	};
};
