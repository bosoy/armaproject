/* ace_sys_fastroping | (c) 2009 by rocko */

#include "script_component.hpp"

private ["_dummy"];

PARAMS_1(_v);

if !([_v] call FUNC(canFastRope)) exitWith {};

_dummy = _v getVariable "ACE_RopeInUse";
if (isNil "_dummy") then {
	_v setVariable ["ACE_RopeInUse", 0, true];
};
_dummy = _v getVariable "ACE_RopeController";
if (isNil "_dummy") then {
	_v setVariable ["ACE_RopeController", objNull, true];
};
