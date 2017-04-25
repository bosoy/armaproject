/* ace_sys_wounds(.pbo) - fnc_selfCATremove.sqf | (c) 2012, 2013 by rocko */
#include "script_component.hpp"

player setVariable ["ACE_PB_Result", 0];

[6,[localize "STR_ACE_UA_REMOVECAT"],true,true] spawn ace_progressbar;

player playMove "AinvPknlMstpSlayWrflDnon_medic";

waitUntil { (player getVariable "ACE_PB_Result" != 0) };

if (player getVariable "ACE_PB_Result" == 1) then {
	player setVariable ["ace_w_cat",false];
	player setVariable ["ace_w_cat_time",0];
	player setVariable ["ace_w_bleed_add",(player getVariable "ace_w_cat_bleed_add_restore")];
	["ACE_Tourniquet",player] call FUNC(litter);
};

// TODO: Tourniquet litter
