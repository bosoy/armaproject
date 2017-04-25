// randomize and set damage for individual soldiers

#include "script_component.hpp"

PARAMS_1(_unit);
private ["_d","_t","_u","_du"];

if (isNull _unit) exitwith {/*[format["Injuring %1: isnull",_unit]] call CBA_fnc_debug*/};
if (! alive _unit) exitwith {/*[format["Injuring %1: not alive",_unit]] call CBA_fnc_debug*/};
if (_unit == vehicle _unit) exitwith {};

if (local _unit) then {
	_du = damage _unit;
	_d = (_du +  random 1.8) max (_du + 0.1);
	if (_d < 0.95) then {
		_t = 10+random 300;
		_u = (_d >= 0.55);
		//[_unit, _d] call ace_sys_wounds_fnc_prdamcheck;
		if (_d > 0.55 && {!isplayer _unit}) then {_unit setskill 0.01; _d = 0.4}; //unc for AI not worky properly
		[_unit,_d,_u,_t] call ace_w_setunitdam;
		#ifdef DEBUG_MODE_FXONLY
		[format["%1 is injured, args [d,u,t] %2",_unit,[_d,_u,_t]]] call CBA_fnc_debug;
		#endif
	} else {
		//[_unit, 1] call ace_sys_wounds_fnc_prdamcheck;
		[_unit,1,false,1] call ace_w_setunitdam;
		#ifdef DEBUG_MODE_FXONLY
		[format["%1 is killed, dam %2",_unit,damage _unit]] call CBA_fnc_debug;
		#endif
	};
};
