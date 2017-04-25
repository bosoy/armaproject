/* ace_sys_explosives (.pbo)| Bury stuff | (c) 2011 by rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_2(_mine,_type);
_mine setVariable [QGVAR(burry),true,true];
if (isNil "_mine") exitWith { TRACE_1("Nil mine!"); false };
if (isNull _mine) exitwith { TRACE_1("Null mine!"); false };

_depth_max = (_mine selectionPosition "depth_max") select 2;
_depth_min = (_mine selectionPosition "depth") select 2;
_depth = _depth_max - _depth_min;
_increment = _depth/3;

_level = _mine getVariable [QGVAR(level),0];

if (_type < 0) then {
	_mine setVariable [QGVAR(level),(_level - 1),true];
} else {
	_mine setVariable [QGVAR(level),(_level + 1),true];
};

_pos = getPos _mine;
_pos set [2, ((_pos select 2) + (_increment * _type))];

player setVariable ["ACE_PB_Result", 0];
[4,[localize "STR_ACE_EXPL_SUBMERGEIED"],true,true] spawn ace_progressbar;
waitUntil { (player getVariable "ACE_PB_Result" != 0) };
if (player getVariable "ACE_PB_Result" == 1) then {
	_mine setPos _pos;
	_mine setVariable [QGVAR(burry),false,true];
};
