#include "script_component.hpp"

private ["_unit", "_caused", "_nextt", "_sidear", "_ar", "_ransound"];

PARAMS_2(_unit,_caused);

if (!GVAR(talkforplayer) && {isPlayer _unit}) exitWith {};

if (_unit call ace_sys_wounds_fnc_isUncon) exitWith {};
if (!alive _unit) exitWith {};

_nextt = _unit getVariable [QGVAR(nextt), 0];

if (time < _nextt) exitWith {};

_sidear = _unit call FUNC(getfaction);

if (count _sidear > 0) then {
	_ar = _sidear select 3; // wounded sounds
	if (count _ar > 0) then {
		_ransound = _ar select (floor (random (count _ar)));
		if (getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "isWoman") != 1) then {	// no shemales please
			[_unit, _ransound] call CBA_fnc_globalSay3D;
		};
		_unit setVariable [QGVAR(nextt), time + 30 + random 10];
	};
};