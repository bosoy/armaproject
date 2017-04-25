/* ----------------------------------------------------------------------------
Function: ACE_fnc_inBuilding

Description:
	Function to check if a person or a position is inside a house.

Parameters:
	Unit or position. [Object/Position]
	Accuracy ( Optional, default 0.5 ) [Number]

Returns:
	true
	false

Example:
	(begin example)
		[player, 1] call ACE_fnc_inBuilding;
	(end)

Author:
	rocko, (c) 2010
---------------------------------------------------------------------------- */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
PARAMS_2(_p,_acc);
DEFAULT_PARAM(1,_acc,0.5);

private["_o", "_rel", "_bb", "_ret"];

#define __minx (((_bb select 0) select 0) - _acc)
#define __miny (((_bb select 0) select 1) - _acc)
#define __minz ((_bb select 0) select 2)
#define __maxx (((_bb select 1) select 0) - _acc)
#define __maxy (((_bb select 1) select 1) - _acc)
#define __maxz ((_bb select 1) select 2)
#define __relx (_rel select 0)
#define __rely (_rel select 1)
#define __relz (_rel select 2)

if (typeName _p == "ARRAY") then { _p = _p; _acc = 0; } else { _p = position _p; };
 
_o = _p nearestObject "House";
if (isNull _o) exitWith { false };
_rel = _o worldToModel _p;
_bb = boundingBox _o;

_ret = (__relx > __minx && {__relx < __maxx} && {__rely > __miny} && {__rely < __maxy} && {__relz > __minz} && {__relz < __maxz});
TRACE_4("",_o,_rel,_bb,_ret);
_ret







