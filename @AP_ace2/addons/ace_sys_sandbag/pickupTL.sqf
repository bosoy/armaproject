/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

_ladder = _this;
deleteVehicle _ladder;
[player, "ACE_TacticalLadder_Pack"] call CBA_fnc_addWeapon;
