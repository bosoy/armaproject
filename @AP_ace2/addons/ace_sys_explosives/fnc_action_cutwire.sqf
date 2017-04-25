/* ace_sys_explosives (.pbo)| Cutting tripwires | (c) 2008, 2009, 2010, 2011 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_stake = _this;
_mine = _stake getVariable "mine";
_trigger = [_mine] call FUNC(get_trigger);
[_mine] call FUNC(delete_trigger);
_stake setDamage 1;
[_stake, 600] call ACE_fnc_add2clean;
