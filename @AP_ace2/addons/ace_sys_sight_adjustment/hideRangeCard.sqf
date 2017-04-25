#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

private ["_c"];
for "_c" from 4000 to 4008 do {ctrlShow [_c,false]};

ctrlSetText [3147, localize "STR_ACE_SA_RANGETABLE"];
buttonSetAction [3147, "[] execVM ""\x\ace\addons\sys_sight_adjustment\ShowRangeCard.sqf"""];
