#include "script_component.hpp"

private ["_ammo", "_nextt", "_sidear", "_ar", "_ransound"];

PARAMS_4(_unit,_firer,_dist,_weapon);
_ammo = _this select 6;

if (_dist > 30) exitWith {};

if (_weapon == "Put" || {_ammo isKindOf "SmokeShell"}) exitWith {};
if (getNumber(configFile >> "CfgAmmo" >> _ammo >> "audibleFire") < 1 && {!(_ammo isKindOf "GrenadeCore")} && {!(_ammo isKindOf "Grenade")}) exitWith {};

if (!GVAR(talkforplayer) && {isPlayer _unit}) exitWith {};
if (side _unit == side _firer) exitWith {};

if (_unit call ace_sys_wounds_fnc_isUncon) exitWith {};

if ((random 100) > 60) exitWith {}; // do not allways play a sound. Sounds awfull if 20 arabs are calling out the same soundfile :(

_nextt = _unit getVariable [QGVAR(nextt), 0];

if (time < _nextt) exitWith {};

_sidear = _unit call FUNC(getfaction);

if (count _sidear > 0) then {
	_ar = _sidear select 4; // under fire
	if (count _ar > 0) then {
		if ((random 100) > 49) then { // randomized a little bit so not all units start to talk
			_ransound = _ar select (floor (random (count _ar)));
			if (getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "isWoman") != 1) then {	// no shemales please
				[_unit, _ransound] call CBA_fnc_globalSay3D;
			};
			_unit setVariable [QGVAR(nextt), time + 40 + random 20];
		};
	};
};
