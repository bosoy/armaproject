/* ace_sys_viewblock (.pbo) | (c) 2008, 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __wind (call FUNC(winddir))
#define __dir (__wind select 0)
#define __pos (if (!isNull _smokeShell) then {getPosATL _smokeshell} else {_this select 1})

if (!isServer) exitWith {};

private ["_count"];
PARAMS_4(_ty,_po,_smokeShell,_timeToLive);

if (isNil "_ty" || {isNil "_po"}) exitWith {};
if (typeName _ty != "STRING" || {typeName _po != typeName []}) exitWith {};

_ace_viewblock = (_this select 0) createVehicleLocal (_this select 1);

if (isNull _smokeShell) then {
	_ace_viewblock setPos __pos;
} else {
	_ace_viewblock setPosATL __pos;
};

_count = -5;
while { _count < _timeToLive } do {
	_count = _count+5;

	_ace_viewblock setDir __dir;
	sleep 5;
	TRACE_5("",__dir,_count,_timeToLive,__pos,isNull _ace_viewblock);
};
sleep 3;
deleteVehicle _ace_viewblock;
TRACE_1("Finished","");
