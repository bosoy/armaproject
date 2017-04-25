#include "Script_SightAdjustmentConfig.hpp"

private "_c";
for "_c" from 4000 to 4008 do {ctrlShow [_c,false]};

ctrlSetText [3147, "Range table"];
buttonSetAction [3147, "[] execVM ""\x\ACE\Addons\sys_sight_adjustment_rifle\s\ShowRangeCard.sqf"""];
