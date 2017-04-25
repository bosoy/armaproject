/* ace_sys_viewblock (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired); // Needed for vehicle smoke
PREP(fired_veh);
PREP(viewblock);
PREP(winddir);

["shotSmoke", FUNC(fired)] call ACE_fnc_registerSimulation;
["shotWP", FUNC(fired)] call ACE_fnc_registerSimulation;


[QGVAR(viewb), {_this spawn FUNC(viewblock)}] call ACE_fnc_addClientToServerEventhandler;

ADDON = true;
