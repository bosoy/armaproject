/*
DRAW ROPES SCRIPT

© AUGUST 2009 - norrin
Based loosely on the OFPEC fast rope script

***********************************************************************************************************************************
draw_fastropes.sqf
*/

/* Heavily modified by rocko */

#include "script_component.hpp"

private ["_ropetypes", "_ropemodel", "_atpts", "_ap1", "_ap2", "_rope1", "_rope", "_c"];

PARAMS_1(_v);
DEFAULT_PARAM(1,_unit,player);

if ((_v getVariable "ACE_RopeInUse" == 1) || {(!isNull (_v getVariable "ACE_RopeController"))}) exitWith {};

_ropetypes = [_unit] call FUNC(hasropemag);

if (_ropetypes == "") exitWith {};

_ropemodel = getText(configFile >> "CfgMagazines" >> _ropetypes >> "ACE_FastRope_Model");
_unit removeMagazine _ropetypes;

_v setVariable ["ACE_RopeInUse", 1, true];
_v setVariable ["ACE_RopeController", _unit, true];
_v setVariable ["ACE_RopeAbort", false, true];

_crew_v = crew _v;

_atpts = _v getVariable ["ACE_RopeAttachment", getArray(configFile >> "CfgVehicles" >> typeOf _v >> "ACE_RopeAttachment")];
_attach_points = count _atpts;

_ap1 = _atpts select 0;
if (typeName (_ap1 select 0) == "STRING") then { _ap1 = _v selectionPosition (_ap1 select 0); };

if (_attach_points > 1) then {
	_ap2 = _atpts select 1;
	if (typeName (_ap2 select 0) == "STRING") then {_ap2 = _v selectionPosition (_ap2 select 0)};
};

_rope1 = objNull;
_rope = _ropemodel createVehicle [0,0,0];
if (_attach_points > 1) then {
	_rope1 = _ropemodel createVehicle [0,0,0];
};
sleep 1;

_v setVectorUp [0.001, 0.001, 1];
_rope attachto [_v, [-1, 2, -19]];
if (_attach_points > 1) then {
	_rope1 attachto [_v,[-1, -2, -19]];
};

detach _rope;
if (_attach_points > 1) then {
	detach _rope1;
};

_rope attachto [_v,_ap1, "ACE_Ropestart"];
if (_attach_points > 1) then {
	_rope1 attachTo [_v, _ap2, "ACE_Ropestart"];
};

[QGVAR(adda), _v] call CBA_fnc_globalEvent;

_c = 1;
{
	if (count(assignedVehicleRole _x) == 2) then {
		INC(_c);
	};
} forEach _crew_v;
_count_crew_v = (count _crew_v) - _c;

if (_attach_points > 1) then {
	_crew_count = 0;
	_even_crew = [];
	_odd_crew =[];
	{
		if ((_crew_count mod 2) == 0) then {
			INC(_crew_count);
			_even_crew set [count _even_crew,_x];
		} else {
			INC(_crew_count);
			_odd_crew set [count _odd_crew,_x];
		};
	} forEach _crew_v;
	{
		if (count(assignedVehicleRole _x) != 2 && {_x != driver _v}) then {
			[QGVAR(fr), [_x, 3, _rope]] call ACE_fnc_receiverOnlyEvent;
		};
	} forEach _even_crew;
	{
		if (count(assignedVehicleRole _x) != 2 && {_x != driver _v}) then {
			if (_attach_points > 1) then {
				[QGVAR(fr), [_x, 3, _rope1]] call ACE_fnc_receiverOnlyEvent;
			} else {
				[QGVAR(fr), [_x, 3, _rope]] call ACE_fnc_receiverOnlyEvent;
			};
		};
	} forEach _odd_crew;
} else {
	{
		if (count(assignedVehicleRole _x) != 2 && {_x != driver _v}) then {
			[QGVAR(fr), [_x, 3, _rope]] call ACE_fnc_receiverOnlyEvent;
		};
	} forEach _crew_v;
};

[QGVAR(rs), [_v, _rope, _rope1]] call ACE_fnc_clientToServerEvent;

[QGVAR(vsv), _v] call ACE_fnc_receiverOnlyEvent;
