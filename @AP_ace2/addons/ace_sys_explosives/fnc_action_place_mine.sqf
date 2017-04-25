/* ace_sys_explosives (.pbo)| Generic mine placement function | (c) 2008, 2009, 2010, 2011 by rocko */
#include "script_component.hpp"

_this call FUNC(removeMagazine);
call FUNC(anim);
_this call FUNC(createMine);
