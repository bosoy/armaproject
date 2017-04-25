/* ace_sys_wounds(.pbo)  */
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

closeDialog 0;

private "_delay";
PARAMS_1(_receiver);

TRACE_1("CAT remove", _receiver);

if (!alive player) exitWith {};

player setVariable ["ace_w_busy",true];

// If prone and attempting to bandage other player
_delay = 20;
if (((player call CBA_fnc_getUnitAnim) select 0) != "prone") then {
	_delay = 10;
};

player setVariable ["ACE_PB_Result", 0];
[_delay,[localize "STR_ACE_UA_REMOVECAT"],false,true,player,true] spawn ace_progressbar;
waitUntil { (player getVariable "ACE_PB_Result" != 0) };
if (player getVariable "ACE_PB_Result" == 1) then {
	[_receiver,200] call FUNC(animator2);
	["ACE_Tourniquet",player] call FUNC(litter);
};
player setVariable ["ace_w_busy", false]; // always set busy state to false regardless of PB result

// TODO: Tourniquet litter

false
