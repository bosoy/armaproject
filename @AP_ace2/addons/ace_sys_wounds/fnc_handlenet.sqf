//#define DEBUG_MODE_FULL
#include "script_component.hpp"

TRACE_1("",_this);

switch (_this select 1) do {
	case 0: {if (local (_this select 0)) then {[_this select 0, _this select 2] call FUNC(RemoveBleed)}};
	case 1: {if (local (_this select 0)) then {(_this select 0) call FUNC(RemovePain)}};
	case 2: {if (local (_this select 0)) then {(_this select 0) call FUNC(RemoveUncon)}};
	case 3: {if (local (_this select 0)) then {(_this select 0) setVariable ["ace_w_revive",((_this select 0) getVariable "ace_w_revive") + __cardiactime1]}};
	case -3: {
		if (local (_this select 0)) then {
			(_this select 0) setVariable ["ace_w_revive",((_this select 0) getVariable "ace_w_revive") - __cardiactime1];
			(_this select 0) setVariable ["ace_w_bleed",((_this select 0) getVariable "ace_w_bleed") + 0.1]; 
		};
	};
	case 100: {if (local (_this select 0)) then {(_this select 0) playActionNow "Die"}};
	case 101: {(_this select 0) switchmove "AmovPpneMstpSnonWnonDnon_healed";if (local (_this select 0)) then {(_this select 0) playActionNow "Die"}};
	case 102: {(_this select 0) switchmove "AmovPpneMstpSnonWnonDnon_healed"};
	case 103: {(_this select 0) switchmove "";if (local (_this select 0)) then {(_this select 0) moveInCargo (_this select 2)}};
	case 104: {if (local (_this select 0)) then {unassignVehicle (_this select 0)}};
	case 105: {(_this select 0) switchmove ""};
	case 110: {if !(local (_this select 0)) then {(_this select 0) switchmove ""}};
	case 200: {if (local (_this select 0)) then {[_this select 0, _this select 2] call FUNC(RemoveCAT)}};
};
