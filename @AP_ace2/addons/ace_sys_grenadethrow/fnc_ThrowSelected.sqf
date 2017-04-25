//#define DEBUG_MODE_FULL
#include "script_component.hpp"
if (GVAR(opt_enabled)==1) then
{
if (_this) then //first switch to throw
{
	GVAR(mode) = 0;
	GVAR(speed) = 1;
	player setvariable ["ace_sys_grenadethrow_cookie",objNull];
	//if (difficultyEnabled "weaponCursor") exitwith {};
	call FUNC(readsettings);
	if !(GVAR(grenadecursor)) then
	{
		GVAR(grenadecursor) = true;
		0 = [] spawn FUNC(cursor);
	};
	//call GVAR(mkey_add);
} else //cycle modes
{
	if !(GVAR(grenadecursor)) then
	{
		GVAR(mode) = 0;
		GVAR(speed) = 1;
		//player setvariable ["ace_sys_grenadethrow_cookie",objNull];
		GVAR(grenadecursor) = true;
		0 = [] spawn FUNC(cursor);
	};
	GVAR(mode) = if (GVAR(mode) == 3) then {0} else {GVAR(mode) + 1};
	TRACE_1("",GVAR(mode));
	GVAR(speed) call FUNC(indicator);
};
};

