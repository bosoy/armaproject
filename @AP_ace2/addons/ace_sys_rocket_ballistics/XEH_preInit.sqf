#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired_ffar);
PREP(fired_rpg);
PREP(dispersion);
PREP(apply_dispersion);
PREP(turnrocket);
PREP(tracer);
PREP(ffar_fix);	//fix FFARs shooting from missile racks. This one should be running BEFORE FX scripts, but currently they're loaded first.
PREP(ffar_fix_init);	// attach local gamelogics, clear redundant ones (when deleteVehicle was issued on helicopter)
PREP(ffar_fix_killed);	// clear local gamelogics
PREP(ffar_fix_ai);	// fix proximity fuses on AI FFARs

[QGVAR(disp), {_this call FUNC(apply_dispersion)}] call CBA_fnc_addEventHandler;

// CBA_GAUSS_INIT
// Translating GAUSS values
// TODO: Simply use the CBA arrays :)
ACE_WTAB = CBA_WTAB;
ACE_KTAB = CBA_KTAB;
ACE_YTAB = CBA_YTAB;
ACE_PARAM_R = CBA_PARAM_R;

GVAR(ffar_logic_array) = [];

ACE_Effects_Rocket = {
	if ((_this select 0) isKindOf "Helicopter") then {_this call FUNC(ffar_fix)};
	_this call BIS_Effects_Rocket;
};

ADDON = true;
