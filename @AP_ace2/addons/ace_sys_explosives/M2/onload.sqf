/* ace_sys_explosives | SLAM Arming | (c) 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

with uinamespace do { GVAR(SLAM_MENU) = _this select 0 };
GVAR(InitValue) = 0;

TRACE_1("onload",(GVAR(InitValue)));

[GVAR(slam),-1] execVM "\x\ace\addons\sys_explosives\M2\timer.sqf";
//[GVAR(slam),-1] spawn COMPILE_FILE2_SYS(PATH+"timer.sqf");
