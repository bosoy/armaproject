/* ace_sys_irstrobe (.pbo) | (c) 2008, 2009 by rocko */
#include "script_component.hpp"

_unit = _this;
if (_unit != player) exitWith { false };
GVAR(ison) = false;
GVAR(ison_throw) = false;
GVAR(nostrobeon) = true;
_unit setVariable [QGVAR(active_strobes), [], false];
if (_unit in GVAR(local_array)) then {
	[QGVAR(arrm), [_unit]] call CBA_fnc_globalEvent;
};
playSound "Counter";
