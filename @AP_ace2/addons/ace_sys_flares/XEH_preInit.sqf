/* ace_sys_flares (.pbo) | (c) 2009 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

["shotFlare", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;
["shotFlareCluster", COMPILE_FILE(fnc_fired_cluster)] call ACE_fnc_registerSimulation;

PREP(SlowDescent);
PREP(Cluster);

[QGVAR(fired), {_this execFSM "\x\ace\addons\sys_flares\fnc_rocko_flares.fsm"}] call CBA_fnc_addEventHandler;

ADDON = true;
