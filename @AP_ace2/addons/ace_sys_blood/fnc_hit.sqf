/*
	Hit EH shared between Hit and Killed
	TODO: Evaluate handsHit, canMove etc. Otherwise the Dammaged EH could be used for selections, instead.
	TODO: Evaluate Damaged EH:  [unit, selectionName, damage]
*/
#include "script_component.hpp"

private ["_damage", "_history", "_unitPos", "_causedByPos", "_bulletDir", "_c"];
PARAMS_2(_unit,_causedBy);
_damage = if (count _this > 2) then {if (typeName (_this select 2) == "SCALAR") then {(_this select 2) min 1} else {1}} else {1};
TRACE_1("",_damage);

// Get damaged info if there is any, and reset it
_history = _unit getVariable QGVAR(damage);
if (isNil "_history") then { _history = [] } else { _unit setVariable [QGVAR(damage), []] };
TRACE_1("",_history);

// Calculate bulletDirection
// TODO: Apply a bit randomminity to the direction?
_unitPos = getPosATL _unit;
_causedByPos = getPosATL _causedBy;

// _bulletDir = 0; // Direction the blood spurt must fly to (the bullet's direction) - Calculate from _unit and _causedBy?
// _bulletDir = getDir _causedBy
_bulletDir = ((_unitPos select 0) - (_causedByPos select 0)) atan2 ((_unitPos select 1) - (_causedByPos select 1));

// Do magic with damaged history
 _c = count _history;
if (_c > 0) then {
	_unitPos = _unit modelToWorld (_unit selectionPosition ((_history select (_c - 1)) select 0));
	TRACE_1("",((_history select (_c - 1)) select 0));
};

[QGVAR(spurt), [_unit, _bulletDir, _damage]] call CBA_fnc_globalEvent;
