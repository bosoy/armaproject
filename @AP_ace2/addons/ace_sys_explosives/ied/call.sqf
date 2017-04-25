/* ace_sys_explosives | IED Phone | (c) 2012 by rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

private ["_mine","_bool"];
_mine = _this;

GVAR(IED) = _mine;
_bool = createDialog "ACE_CELLPHONE_MENU";
