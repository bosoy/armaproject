/* ace_sys_dogtag | (c) 2008 by rocko */

// _this by Xeno

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_1(_unit);

if !(alive _unit) exitWith { TRACE_1("Dead Unit",_unit) };
_unit setVariable [QGVAR(name), name _unit];

// To avoid the stupid "Warning  bla bla is dead function bla bla bla" error message