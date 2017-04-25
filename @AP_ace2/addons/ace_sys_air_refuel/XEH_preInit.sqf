/* ace_sys_air_refuel | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

LOG(MSG_INIT);

ADDON = false;

PREP(abort);

GVAR(abort) = false;
FUNC(hose_pulled) = {
	_this getVariable [QGVAR(hose_released), false]
};
FUNC(busy) = {
	_this getVariable [QGVAR(busy), false]
};

[QGVAR(fuel), { _this execFSM QPATHTO_C(fnc_fuel.fsm) }] call ACE_fnc_addReceiverOnlyEventhandler; // Remote refueling
[QGVAR(remove_fuel_cargo), { _this execFSM QPATHTO_C(fnc_remove_fuel_cargo.fsm) }] call ACE_fnc_addReceiverOnlyEventhandler; // Remote removing fuel cargo

ADDON = true;
