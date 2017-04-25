/* ace_sys_explosives | SLAM mines | (c) 2008,2009 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

private ["_mine","_bool"];
_mine = _this;

GVAR(SLAM) = _mine;
_bool = createDialog "ACE_SLAM_MENU";
