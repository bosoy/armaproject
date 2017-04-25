/* ace_sys_muzzleblast | (c) 2008, 2009, 2010 by rocko */

// #define DEBUG_MODE_FULL
#include "script_component.hpp"

if (isText(configFile>> "CfgAmmo" >> _this select 4 >> "ACE_Muzzle_FX")) then {
	_simulation = getText(configFile >> "CfgAmmo" >> _this select 4 >> "ACE_Muzzle_FX");
	TRACE_1("",_simulation);
	_this call (call compile (_simulation));
};
