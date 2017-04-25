// TODO: Merge this, or call this from statehandler, instead of it's own loop? Just skip whe time < waitTime?

#include "script_component.hpp"

private ["_requested", "_need", "_units", "_do", "_medics"];
PARAMS_1(_unit);
_requested = objNull;

sleep (5 + (random 10));
while {alive _unit && {_unit getVariable ["ace_w_state", 0] in [801, 802]} && {vehicle _unit == _unit} && {!([_unit] call FUNC(occupied))}} do {
	_need = false;
	_units = if (GVAR(auto_assist_any)) then {
		(position _unit) nearObjects ["CAManBase", 12];
	} else {
		units _unit;
	};

	// Sort medics higher up the chain.
	// TODO: Sort state > 0 units last?
	_medics = [];
	{ if ([_unit] call FUNC(isMedic)) then { PUSH(_medics,_x) } } forEach _units;
	_units = _units - _medics;
	_units = _medics + _units;
	{
		// TODO: Remote helping??
		if !(isPlayer _x) then {
			_do = if (GVAR(auto_assist_any)) then {
				(side (group _unit)) getFriend (side (group _x)) >= 0.6
			} else {
				_unit distance _x < 12
			};
			if (_do) then {
				if !(_x call FUNC(isUncon) || {!alive _x} || {vehicle _x != _x} || {([_x] call FUNC(occupied))}) then {
					if (_unit getVariable "ace_w_bleed" > 0.5) then {
						_need = LRGBND in (magazines _unit) || {LRGBND in (magazines _x)};
					} else {
						_need = BND in (magazines _unit) || {BND in (magazines _x)};
					};
					if (_need) exitWith { _requested = _x };

					if (_unit getVariable "ace_w_epi" > 0) then {
						_need = EPI in (magazines _unit) || {EPI in (magazines _x)};
					};
					if (_need) exitWith { _requested = _x };

					if (_unit getVariable "ace_w_pain" > 0) then {
						_need = MOR in (magazines _unit) || {MOR in (magazines _x)};
					};
					if (_need) exitWith { _requested = _x };
				};
			};
		};
		if !(isNull _requested) exitWith {};
	} forEach (_units - [_unit]);

	if !(isNull _requested) exitWith {};
	sleep (10 + (random 15));
};

if (alive _unit && {!isNull _requested}) then {
	TRACE_3("Requested to help",_unit,_requested,local _requested);
	if (local _requested) then {
		[QGVAR(help), [_unit, _requested]] call CBA_fnc_localEvent;
	} else {
		[QGVAR(help), [_unit, _requested]] call CBA_fnc_globalEvent;
		sleep 8;
	};
	//while {alive _unit && alive _requested}
};

sleep (5 + (random 10));
_unit setVariable ["ace_w_requested_help", false];
