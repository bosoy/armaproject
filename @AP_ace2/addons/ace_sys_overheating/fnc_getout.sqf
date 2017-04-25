/* ace_sys_overheating | Barrel Temperature for Static weapons | (c) 2011 rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_v);
private ["_t","_lst"];
_t = _v getVariable [QGVAR(temp),0];
_lst = _v getVariable [QGVAR(lastShotTime_static),time];
_v setVariable [QGVAR(temp),_t,true];
_v setVariable [QGVAR(lastShotTime_static),_lst,true];
