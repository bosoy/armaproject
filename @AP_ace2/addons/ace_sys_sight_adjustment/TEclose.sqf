#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"
#define ACE_TEXT_SILVER(Text) ("<t color='#C0C0C0'>" + ##Text + "</t>")
(vehicle player) removeaction (_this select 2);
ace_te_enabled = false;
ACE_SYS_SA_SET_TEACTIVE(false);
hint "";
private ["_s","_veh"];
_veh = vehicle player;
_s = _veh addaction [ACE_TEXT_SILVER(localize "STR_ACE_SA_TandE"),"\x\ace\addons\sys_sight_adjustment\TE.sqf",[],0.1];

waituntil { sleep 1; ACE_SYS_SA_TEACTIVE || {(player != gunner _veh)} };
if (ACE_SYS_SA_TEACTIVE) exitwith {};
_veh removeaction _s;

