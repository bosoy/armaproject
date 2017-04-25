//#define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("",_this);

switch (_this select 1) do {
	case 0: {[_this select 0, _this select 2] call FUNC(RemoveBleed)};
	case 1: {(_this select 0) call FUNC(RemovePain)};
	case 2: {(_this select 0) call FUNC(RemoveUncon)};
	case 3: {(_this select 0) setVariable ["ace_w_revive",((_this select 0) getVariable "ace_w_revive") + __cardiactime1]};
	case -3: {
		(_this select 0) setVariable ["ace_w_revive",((_this select 0) getVariable "ace_w_revive") - __cardiactime1];
		(_this select 0) setVariable ["ace_w_bleed",((_this select 0) getVariable "ace_w_bleed") + 0.1];	
	};
	case 100: {(_this select 0) playActionNow "Die"};
	case 104: {unassignVehicle (_this select 0)};
	case 200: {
		if (local (_this select 0)) then {
			(_this select 0) setVariable ["ace_w_cat",false]; //TODO: Check if works in MP...
			(_this select 0) setVariable ["ace_w_cat_time",0];
			(_this select 0) setVariable ["ace_w_bleed_add",((_this select 0) getVariable "ace_w_cat_bleed_add_restore")];
		}
	};
};
