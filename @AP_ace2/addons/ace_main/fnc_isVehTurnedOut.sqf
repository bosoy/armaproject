/* ----------------------------------------------------------------------------
Function: ACE_fnc_isVehTurnedOut

Description:
	Checks whether a vehicle has any crew turned out.
	Accepts vehicle or individual unit as parameter.
	By default, if crew (even exposed gunners) do not have the option to turn in, they are considered turned in.
	Use optional parameter _exposure to be treat only sealed or pressurized vehicles as capable of being turned in.

Parameters:
	_unit - Unit or Vehicle to check [Object]

Optional Parameters:
	_exposure - Set to true to consider unsealed vehicles and foot soldiers as turnedOut/exposed [Boolean]

Returns:
	"true" for turned out or "false" for not turned out [Boolean]

Examples:
	(begin example)
		if ( [player] call ACE_fnc_isVehTurnedOut ) then {
			player sideChat "My vehicle is turned out!";
		};
	(end)

Author:
	(c) tcp 2010
---------------------------------------------------------------------------- */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"
PARAMS_1(_unit);
DEFAULT_PARAM(1,_exposure,false);

private ["_exposure", "_unit", "_veh", "_crew", "_turnedout", "_handled", "_role", "_OutAction", "_InAction", "_trrAry", "_turCfg", "_mt", "_st", "_anim", "_count", "_out"];

_veh = vehicle _unit;
_crew = crew _veh;

_turnedout = false;
_handled = false;

//unit is on foot
if ((_crew select 0) == _veh) then {
	_handled = true;
	if (_exposure) then {
		_turnedout = true;
	};
};

if (_handled) exitWith {_turnedout};

if (_exposure) then {
	_handled = true;
	//plane - pressurized
	if !(_veh isKindOf "Plane") then {
		{
			if ((_x distance _veh) > 0) exitWith {_turnedout = true};
		} forEach _crew;
	};
};

if (_handled) exitWith {_turnedout};

#define __cfg (configFile >> "CfgVehicles" >> typeof _veh)
{
	_role = assignedVehicleRole _x;
	TRACE_1("Role",_role);
	switch (toLower (_role select 0)) do {
		case "driver": {
			_OutAction = getText(__cfg >> "driverAction");
			//_InAction	= getText(__cfg >> "driverInAction");
		};
		case "turret": {
			_trrAry = _role select 1;
			_turCfg = (__cfg >> "turrets");
			if (count _trrAry > 1) then {
				_mt = _trrAry select 0;
				_st = _trrAry select 1;
				_OutAction = getText( (((_turCfg select _mt) >> "turrets") select _st) >> "gunnerAction" );
				//_InAction	= getText( ((_turCfg select _mt) select _st) >> "gunnerInAction" );
			} else {
				_mt = _trrAry select 0;
				_OutAction = getText((_turCfg select _mt) >> "gunnerAction");
				//_InAction	= getText((_turCfg select _mt) >> "gunnerInAction");
			};
		};
		default {
			_OutAction = "";
			//_InAction = "";
		};
	};

	//has Out animation
	_anim = toArray (toLower _OutAction);
	_count = count _anim - 1;
	if (_count > 2) then {
		_out = toString ([_anim select (_count-2),_anim select (_count-1),_anim select _count]);
		if (_out == "out") then {
			if (_x distance _veh > 0) then {_turnedout = true};
		};
	};
	TRACE_2("out",_out,_OutAction);
	if (_turnedout) exitWith {};
} forEach _crew;


_turnedout;