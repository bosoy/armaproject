/* ace_sys_wounds(.pbo) - fnc_stretcher_fix.sqf | (c) 2012, 2013 by rocko */

#include "script_component.hpp"

PARAMS_3(_stretcher,_pos,_unit);

if (_pos == "DRIVER") then {
	sleep 0.1;
	_unit action ["getout", _stretcher];
	sleep 0.05;
	_unit setPos (getpos _stretcher);
};
