#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(meter);

FUNC(meter_held) = {
	if (vehicle player == player) exitWith {false};
	if (vehicle player isKindOf "Air") exitWith {false};
	if (! isNil QGVAR(meter_inpro)) exitWith {true};
	private ["_held"];
	if (_this) then {
		if (isNil QGVAR(meter_held)) then {
			GVAR(meter_held) = time;
		};
		if (isNil QGVAR(meter_held_done)) then {
			_held = time - GVAR(meter_held);
			if (_held > 2) then {
				GVAR(meter_held_done) = true;
				["reset"] call FUNC(meter);
			};
		};
	} else {
		GVAR(meter_held) = nil;
		if (isNil QGVAR(meter_held_done)) then {
			["stop"] call FUNC(meter);
		};
		GVAR(meter_held_done) = nil;
	};
	true
};

GVAR(sh_done) = 0 spawn {};

[QUOTE(ADDON), "Odometer_Start", {["start"] call FUNC(meter)}, "keyup"] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "Odometer_Stop", {true call FUNC(meter_held)}] call CBA_fnc_addKeyHandlerFromConfig;

[QUOTE(ADDON), "Odometer_Stop", {false call FUNC(meter_held)}, "keyup"] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
