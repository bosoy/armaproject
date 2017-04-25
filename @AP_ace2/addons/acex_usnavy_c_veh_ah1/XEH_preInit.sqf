#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(cobra_getinout);

["ace_cobra_op", {if (local _this) then {_this animate ["PilotWindow",1]}}] call CBA_fnc_addEventhandler;
["ace_cobra_og", {if (local _this) then {_this animate ["GunnerWindow",1]}}] call CBA_fnc_addEventhandler;
["ace_cobra_cp", {if (local _this) then {_this animate ["PilotWindow",0]}}] call CBA_fnc_addEventhandler;
["ace_cobra_cg", {if (local _this) then {_this animate ["GunnerWindow",0]}}] call CBA_fnc_addEventhandler;

ADDON = true;
