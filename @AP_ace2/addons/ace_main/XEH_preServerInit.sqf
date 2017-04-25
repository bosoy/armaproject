#include "script_component.hpp"

LOG(MSG_INIT);

ADDON = false;

#include "ace_sys_ladebalken_pre.sqf"

GVAR(event_holderCTS) = "ACE_LogicDummy" createVehicleLocal [0, 0];

PREP(NetRunEventCTS);

QGVAR(ncts) addPublicVariableEventHandler {
	(_this select 1) call FUNC(NetRunEventCTS);
};

ADDON = true;
