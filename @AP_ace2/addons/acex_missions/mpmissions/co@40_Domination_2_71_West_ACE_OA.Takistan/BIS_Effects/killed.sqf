/*
ACE sys_destruction killed EH by Maddmatt
*/
// #define __DEBUG__
#define THIS_FILE "killed.sqf"
#include "x_setup.sqf"

PARAMS_1(_veh);

#ifdef __DEBUG__
_fuel = fuel _veh;
__TRACE_2("","_veh","_fuel");
#endif

if (_veh iskindof "helicopter" || _veh iskindof "plane") exitWith {
	[QGVAR(AirD), _veh] call FUNC(NetCallEvent);
};
if (_veh iskindof "tank") exitWith {
	[_veh, (fuel _veh) * (2 + random 2)] call BIS_Effects_Secondaries;
};
if (_veh iskindof "car" || _veh iskindof "ship") exitWith {
	_int = (fuel _veh) * (2 + random 1);
	[_veh, _int] call BIS_Effects_Secondaries;

	//Possible initial explosion
	if ((random _int) > 2.2) then {
		"SmallSecondary" createvehicle (getpos _veh);
	};
};
