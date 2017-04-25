#include "script_component.hpp"

private ["_unit", "_ammo", "_nextt", "_sidear", "_sel", "_ar", "_ransound"];
PARAMS_1(_unit);
_ammo = _this select 4;

if (!GVAR(talkforplayer) && {isPlayer _unit}) exitWith {};

// this shouldn't happen, but who knows
if (_unit call ace_sys_wounds_fnc_isUncon) exitWith {};

_nextt = _unit getVariable [QGVAR(nextt), 0];

if (time < _nextt) exitWith {};

_sidear = _unit call FUNC(getfaction);

if (count _sidear > 0) then {
	_sel = if (_ammo isKindOf "Grenade") then {7} else {8};
	_ar = _sidear select _sel;
	if (count _ar > 0) then {
		_ransound = _ar select (floor (random (count _ar)));
		if (getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "isWoman") != 1) then {	// no shemales please
			[_unit, _ransound] call CBA_fnc_globalSay3D;
		};
		_unit setVariable [QGVAR(nextt), time + 40 + random 20];
	};
};
