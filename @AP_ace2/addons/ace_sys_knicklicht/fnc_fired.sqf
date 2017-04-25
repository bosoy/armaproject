/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

if ((_this select 4) in ["ACE_Knicklicht_R", "ACE_Knicklicht_G", "ACE_Knicklicht_W", "ACE_Knicklicht_Y", "ACE_Knicklicht_B", "ACE_Knicklicht_IR"]) then {
	_this spawn FUNC(throw_Knicklicht);
};
