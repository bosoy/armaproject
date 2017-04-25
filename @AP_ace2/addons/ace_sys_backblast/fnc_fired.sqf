/* ace_sys_backblast (.pbo) | (c) 2008, 2009, 2010 by rocko */

#include "script_component.hpp"

if (isText(configFile >> "CfgAmmo" >> (_this select 4) >> "ACE" >> "ACE_BACKBLAST" >> "type")) then {
	_this call FUNC(backblast);
};
