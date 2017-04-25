/* ace_sys_knicklicht (.pbo) | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

PARAMS_1(_unit);

_a0 = _unit getVariable "ace_attached_knicklicht_object"; if !(isNil "_a0") then { detach _a0; _a0 setPos (getPosATL _unit); }; // Falls to ground ?
_a1 = _unit getVariable "ace_used_knicklicht_object"; if !(isNil "_a1") then { detach _a1; _a1 setPos (getPosATL _unit); };
_a0 setVariable [QGVAR(locked), false, true];
_a1 setVariable [QGVAR(locked), false, true];

_unit setVariable ["ace_attached_knicklicht", false, false];
_unit setVariable ["ace_used_knicklicht", false, false];

_unit removeAction GVAR(remove_action);