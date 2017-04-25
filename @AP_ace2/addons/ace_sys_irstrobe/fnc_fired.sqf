/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

if ((_this select 4) in ["ACE_VIP_IRStrobe", "IRStrobe"]) then {
	_this spawn FUNC(throw_IRStrobe);
};
