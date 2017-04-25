#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(keypressed);
PREP(afterburner);

[QUOTE(ADDON), "Afterburner", { [_this, "DOWN"] call FUNC(keypressed)}, "DOWN"] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Afterburner", { [_this, "UP"] call FUNC(keypressed)}, "UP"] call CBA_fnc_addKeyHandlerFromConfig;

FUNC(hasAfterburner) = {
	PARAMS_1(_unit);
	// setVariable should always override config property when set, so we don't use getVariable array.
	_afterBurner = _unit getVariable "ace_hasAfterburner";
	if (isNil "_afterBurner") then {
		_afterBurner = getNumber(configFile >> "CfgVehicles" >> typeOf (vehicle player) >> "ACE_hasAfterburner") == 1;
	};
	_afterBurner;
};

GVAR(afterburner) = false;

ADDON = true;
