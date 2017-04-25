/* ace_sys_combatdeaf | (c) 2008, 2009, 2010 by rommel and rocko */

#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

PREP(fired);
PREP(firedNear);
PREP(getIn);
PREP(getOut);
PREP(killed);
GVAR(blur) = ppEffectCreate ["dynamicBlur", -13505];

ADDON = true;
