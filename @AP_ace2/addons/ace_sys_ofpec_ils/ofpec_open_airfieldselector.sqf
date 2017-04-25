#include "script_component.hpp"

GVAR(vehicle) = _this select 0;

if !(isengineOn GVAR(vehicle)) exitWith {};
GVAR(airportevents) = true;
_ok = createDialog "OFPEC_AirPortSelector";