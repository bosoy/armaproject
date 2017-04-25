#include "\x\ace\addons\sys_explosives\script_component.hpp"

PARAMS_1(_mine);

call FUNC(anim);

_mine call FUNC(delete_trigger);

_mine setVariable [QGVAR(tw),false,true];
_mine setVariable [QGVAR(active),false,true];
[_mine,true] call FUNC(set_ready);