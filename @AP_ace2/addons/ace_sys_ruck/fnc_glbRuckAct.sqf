//#define DEBUG_MODE_FULL
#include "script_component.hpp"

/* Global Ruck Add Action
	On manually dropped rucks (as ruck crates)
*/
private ["_magAry", "_wepAry", "_orgRuck"];
PARAMS_2(_crate,_orgRuck);

if (!isDedicated) then {
//add action
	_crate addAction [localize "STR_ACE_SYS_RUCK_TAKRUCK", QPATHTO_F(act_TakeRuck), _orgRuck, 4, true, true, "", "alive _target && {!(player call ace_sys_ruck_fnc_HasRuck)}"];
};