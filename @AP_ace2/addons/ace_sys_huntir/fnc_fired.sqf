/* ace_sys_huntir | (c) 2008 rocko */

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_7(_unit,_weapon,_muzzle,_mode,_ammo,_magazine,_shot);
private["_dir","_pos","_dir_degree","_b","_a","_y","_x","_huntir"];

_dir = player weaponDirection _weapon;
_pos = getPos player;

_dir_degree = (_dir select 0) atan2 (_dir select 1);
_b = 500 /(tan ((asin(_dir select 2)) +10));
_a = _b * (sin _dir_degree);
_b = _a / (tan _dir_degree);
_x = (_pos select 0) + _a;
_y = (_pos select 1) + _b;

TRACE_5("",_dir_degree,_a,_b,_x,_y);

[_shot, _x, _y] execFSM QPATHTO_C(fired.fsm);

