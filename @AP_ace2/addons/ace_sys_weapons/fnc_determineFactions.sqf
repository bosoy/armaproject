#include "script_component.hpp"

PARAMS_1(_weap);
_factions = [];

_cfg = configFile >> "CfgWeapons" >> _weap >> QGVAR(side);
if (isArray _cfg) then { _factions = getArray _cfg };

_factions;
