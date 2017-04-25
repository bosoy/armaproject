// by Xeno
#define THIS_FILE "x_fackilled.sqf"
#include "x_setup.sqf"
private ["_fac", "_index"];
if (!isServer) exitWith {};

PARAMS_2(_fac,_index);

deleteVehicle _fac;

switch (_index) do {
	case 0: {
		[QGVAR(jet_serviceH),true] call FUNC(NetSetJIP);
		[QGVAR(jet_sf)] call FUNC(NetCallEventToClients);
		GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"JetServiceDestroyed",true];
	};
	case 1: {
		[QGVAR(chopper_serviceH),true] call FUNC(NetSetJIP);
		[QGVAR(chop_sf)] call FUNC(NetCallEventToClients);
		GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"ChopperServiceDestroyed",true];
	};
	case 2: {
		[QGVAR(wreck_repairH),true] call FUNC(NetSetJIP);
		[QGVAR(wreck_rf)] call FUNC(NetCallEventToClients);
		GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"WreckServiceDestroyed",true];
	};
};