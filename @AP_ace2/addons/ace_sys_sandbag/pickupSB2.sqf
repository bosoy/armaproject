/* ace_sys_sandbag (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"
//closeDialog 0;
_SB = _this;
_SB_get = 12;
_SB_special = "";

_busy = player getVariable [QGVAR(busy), false];

TRACE_4(_SB,_SB_get,_SB_special,_busy);

if(!_busy) then {
	private["_i"];
	player setVariable [QGVAR(busy), true];
	//_place1 = getPosATL _SB;
	//_place2 = [(_place1 select 0) + 1, (_place1 select 2) + 1, (_place1 select 2)];
	//_place3 = [(_place2 select 0) + 1, (_place2 select 2) + 1, (_place1 select 2)];
	deleteVehicle _SB;

	for "_i" from 0 to _SB_get - 1 do {
		// TODO: Stack them up 3 x 4

		_SB0 = "ACE_Sandbag_Build" createVehicle [(((getpos player) select 0) + (_i/10)), (((getpos player) select 1) + (_i/10))];
		_SB0 setPos [(((getpos player) select 0) + (_i/10)), (((getpos player) select 1) + (_i/10)),((getpos player) select 2)];
		sleep 0.15;
	};

	if (_SB_special == "P") then {
		"Paleta1" createVehicle (getpos player);
	};
	sleep 1;
	player setVariable [QGVAR(busy), false];
};
