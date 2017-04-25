/* ace_sys_helidust | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

private ["_v", "_eo", "_planeorchopper", "_disableshred"];

TRACE_1("",_this);

#define __VTOL (getNumber(configFile >> "CfgVehicles" >> (typeOf _v) >> "vtol"))

PARAMS_2(_v,_eo);

if (_eo && {fuel _v == 0}) exitWith {};

if (_v isKindOf "ParachuteBase") exitWith { TRACE_1("exit. parachut",""); false };

if ((_v isKindOf "Plane") && {!(__VTOL in [1, 2, 3])}) exitWith {/*no vtol*/};

if (_eo) then {
	// 0 = chopper, 1 = plane
	_planeorchopper = if (_v isKindOf "Helicopter") then {0} else {1};

	[QGVAR(engineon), [_v, _planeorchopper]] call CBA_fnc_globalEvent;
	if (_planeorchopper == 0) then {
		_disableshred = _v getVariable QGVAR(disable_manshred);
		if (isNil "_disableshred") then {
			_disableshred = getNumber(configFile >> "CfgVehicles" >> typeOf _v >> QGVAR(disable_manshred));
		} else {
			_disableshred = 0;
		};
		if (_disableshred == 0) then {[_v] spawn FUNC(rocko_tailrotor)}
	};
} else {
	[QGVAR(engineoff), _v] call CBA_fnc_globalEvent;
};

false