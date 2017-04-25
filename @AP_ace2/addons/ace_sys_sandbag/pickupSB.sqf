/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"
//closeDialog 0;
_SB = _this;

_busy = player getVariable [QGVAR(busy), false];

if(!_busy) then {
	player setVariable [QGVAR(busy), true];
	deleteVehicle _SB;
	[player, "ACE_SandBag_Magazine"] call CBA_fnc_addMagazine;
	player setVariable [QGVAR(busy), false];
};

