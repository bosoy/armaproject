#include "script_component.hpp"

// (c) 2012 by zGuba
// Spinning up gatling guns

PARAMS_4(_vehicle,_weapon,_muzzle,_mode);
/*
_gunnerInfo = [_vehicle, _weapon] call CBA_fnc_getFirer;
_gunner = _gunnerInfo select 0;
*/
//if !(local _gunner) exitWith {};

// Find firing mode/muzzle/weapon
_class = _this call FUNC(findwmmclass);

// Bullets
_spinUpCount = getNumber (_class >> "ace_spinup_count");
if (_spinUpCount <= 0) exitWith {};

// Maximum reload time reduction factor
_spinUpMax = getNumber (_class >> "ace_spinup_max");
if (_spinUpMax <= 1) exitWith {};

// Spin down time
_spinDownTime = getNumber (_class >> "ace_spindown_time");
if (_spinDownTime <= 0) exitWith {};

// Time factors
_currentTime = time;
_prevTime = _vehicle getVariable [QGVAR(spinup_time_)+_weapon,_currentTime];

// Previous factor
_prevFactor = _vehicle getVariable [QGVAR(spinup_factor_)+_weapon,1];

// Spindown factor
_spinDownFactor = (1 - (1 / _spinUpMax)) * (_currentTime - _prevTime) / _spinDownTime;

// Spinup factor
_spinUpFactor = (1 - (1 / _spinUpMax)) / _spinUpCount;

_newFactor = (1 min (_prevFactor + _spinDownFactor - _spinUpFactor)) max (1/_spinUpMax);

_vehicle setVariable [QGVAR(spinup_time_)+_weapon, _currentTime];
_vehicle setVariable [QGVAR(spinup_factor_)+_weapon, _newFactor];

_crew = crew _vehicle;
/* // todo: better
_crew = [driver _vehicle];
_turretPaths = [configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets"] call BIS_fnc_returnVehicleTurrets;
{
	_crew set [count _crew,_vehicle turretUnit [_x]];
} forEach _turretPaths;

_crew = _crew - [objNull];
*/

{if (local _x) then {_vehicle setWeaponReloadingTime [_x, _weapon, _newFactor]}} forEach _crew;
