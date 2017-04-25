// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private "_allowed";

PARAMS_4(_bla,_bla1,_bla1,_bandage);

_allowed = [player, player, _bandage] call FUNC(takeItem);
if !(_allowed) exitWith {};

player setVariable ["ace_w_busy",true];
player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 6.5; // TODO: Find out how long animation takes
[_bandage,player] call FUNC(litter);
[player, _bandage] call FUNC(RemoveBleed);
player setVariable ["ace_w_busy",false];
