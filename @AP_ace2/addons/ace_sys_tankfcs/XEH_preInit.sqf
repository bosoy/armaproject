#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(fired);
PREP(lase);
PREP(lasePFH);
PREP(lase_com);
PREP(lead);
PREP(findrange);
PREP(turrettracker);
PREP(startFCS);
PREP(startFCS_commander);
PREP(keypressed_lase);
PREP(keypressed_bsgt);
PREP(keypressed_dump);
PREP(rangedisplay);
PREP(startrangedisplay);
PREP(elev);
PREP(dumplead);
PREP(battlesight);
PREP(setsolution);
PREP(boreoffset);

FUNC(firedEH) = {
	if (getNumber(configfile>>'cfgVehicles'>>typeof (_this select 0)>>'ace_tankfcs_enabled')==1) then {
		if ((isplayer (gunner (_this select 0)) && {!(1 == getNumber(configfile>>'cfgVehicles'>>typeof (_this select 0)>>'ace_tankfcs_commanderisgunner'))}) || {(isplayer (commander (_this select 0)) && {1 == getNumber(configfile>>'cfgVehicles'>>typeof (_this select 0)>>'ace_tankfcs_commanderisgunner')})}) then {
		if !((_this select 4) isKindOf 'MissileBase') then {
		if !(isnil {(_this select 0) getvariable 'ace_tankfcs_fired'}) then { _this call ace_sys_tankfcs_fnc_fired }}}
	};
};

GVAR(presstime) = 0;

[QUOTE(ADDON), "Lase", { _this call FUNC(keyPressed_lase)}] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Battlesight", { _this call FUNC(keyPressed_bsgt)}] call CBA_fnc_addKeyHandlerFromConfig;
[QUOTE(ADDON), "Dump", { _this call FUNC(keyPressed_dump)}] call CBA_fnc_addKeyHandlerFromConfig;

ADDON = true;
