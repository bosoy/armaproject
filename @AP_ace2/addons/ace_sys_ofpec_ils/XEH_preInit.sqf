#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(onload);
PREP(airportevents);
PREP(ClosestTown);
PREP(init);
PREP(getin);
PREP(getout);
PREP(keypress);

GVAR(m_to_km) = { ((_this / 100) - (_this / 100)%1)/10 };

FUNC(ADDKEYPRESS) = { [QUOTE(ADDON), "ILS", { call FUNC(keypress)}, "keyup"] call CBA_fnc_addKeyHandlerFromConfig; };
FUNC(REMOVEKEYPRESS) = { ["ace_sys_ofpec_ils_ils", "keyup"] call CBA_fnc_removeKeyHandler; };

GVAR(airportevents) = false;

ADDON = true;
