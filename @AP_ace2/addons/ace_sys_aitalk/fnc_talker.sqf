#include "script_component.hpp"

private ["_allunits", "_unit", "_nextt", "_num", "_sidear", "_ar", "_ransound"];

if (isMultiplayer) then {
	waitUntil {time > 0};
	sleep 20;
};

while {true} do {
	_unit = allUnits select (floor random (count allUnits));
	_nextt = _unit getVariable [QGVAR(nextt), 0];
	_uncon = _unit call ace_sys_wounds_fnc_isUncon;
	while {!alive _unit || {(!GVAR(talkforplayer) && {isPlayer _unit})} || {time < _nextt} || {vehicle _unit != _unit} || {(_unit call ace_sys_wounds_fnc_isUncon)}} do {
		_unit = allUnits select (floor random (count allUnits));
		_nextt = _unit getVariable [QGVAR(nextt), 0];
		sleep 0.1;
	};
	_num = switch (behaviour _unit) do {
		case "CARELESS": {1};
		case "SAFE": {1};
		case "AWARE": {0};
		case "COMBAT": {2};
		case "STEALTH": {-1};
		default {-1};
	};
	if (_num >= 0) then {
		_sidear = _unit call FUNC(getfaction);
		if (count _sidear > 0) then {
			// check fleeing sounds, only available for US currently
			if (fleeing _unit) then {
				if (count (_sidear select 10) > 0) then {
					_num = 10;
				};
			};
			_ar = _sidear select _num;
			if (count _ar > 0) then {
				_ransound = _ar select (floor (random (count _ar)));
				// [[_unit], _ransound] call CBA_fnc_globalSay;
				if (getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "woman") != 1) then {	// no shemales please
					[_unit, _ransound, 50] call CBA_fnc_globalSay3D;
				};
				_unit setVariable [QGVAR(nextt), time + 40 + random 200];
			};
			sleep 10 + (random 10);
		} else {
			sleep 5 + (random 5);
		};
	} else {
		sleep 5 + (random 5);
	};
};
