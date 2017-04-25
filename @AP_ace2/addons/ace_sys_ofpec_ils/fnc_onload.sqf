#include "script_component.hpp"

with uiNameSpace do { OFPEC_AirPortSelector = _this select 0 };

["onLoad", _this] call FUNC(airportevents);