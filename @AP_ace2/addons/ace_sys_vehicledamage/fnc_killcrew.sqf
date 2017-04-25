//takes vehicle
//kills local and non-local occupants

#include "script_component.hpp"
PARAMS_1(_vehicle);
private ["_nonlocals"];
_nonlocals = [];
{
	if (isNull _x) exitwith {/*[format["Injuring %1: isnull",_x]] call CBA_fnc_debug*/};
	if (! alive _x) exitwith {/*[format["Injuring %1: not alive",_x]] call CBA_fnc_debug*/};

	if !(local _x) then {
		PUSH(_nonlocals,_x);
	} else {
		//[_x, 1] call ace_sys_wounds_fnc_prdamcheck;
		[_x,1,false,1] call ace_w_setunitdam;
		#ifdef DEBUG_MODE_FXONLY
		[format["%1 is killed as vehicle exploded",_x]] call CBA_fnc_debug;
		#endif
	};
} foreach (crew _vehicle);

//MP broadcast for non-local occupants

if (count _nonlocals > 0) then {
	[QGVAR(handle_killcrew), _nonlocals] call CBA_fnc_globalEvent;
};
