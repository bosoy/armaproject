/* ace_sys_air_refuel | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

private "_tank";
PARAMS_1(_veh);
_tank = createVehicle ["ACE_Refueling_Tanks", [0,0,0], [], 0, "NONE"];
_tank attachTo [_veh,[0,1.5,-1.2],""];
_tank setDir 180;
