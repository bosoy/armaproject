//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __wcfg configFile >> "CfgWeapons" >> _weapon
#define __vcfg configFile >> "CfgVehicles" >> typeof _unit
#define __acfg configFile >> "CfgAmmo" >> _ammo

if !(difficultyenabled "camerashake") exitwith { TRACE_1("Shake disabled",""); };

private ["_pwr","_c","_fov","_turret","_pos","_t","_abort"];
PARAMS_5(_unit,_weapon,_muzzle,_mode,_ammo);

if (getNumber(__vcfg>>"ace_camshake_enabled")== 0) exitwith { TRACE_1("Shake disabled",""); };

_pos = assignedvehiclerole player;
_turret = [];
_abort = false;
if (_pos select 0 == "Turret") then {
	_turret = _pos select 1;

	TRACE_2("",_turret,_pos); //[format["turret %1 pos %2",_turret,_pos]] call cba_fnc_debug;

	if (count _turret == 0) exitwith {_abort = true};
	if !(_weapon in (_unit weaponsturret _turret)) exitwith {_abort = true};

	_t = [_unit,_turret] call CBA_fnc_getTurret;
	_fov = 0.3333;
	if (isClass(_t>>"opticsin")) then {
		_t = _t>>"opticsIn";
		_fov = getNumber((_t select (count _t - 1))>>"minfov");
	} else {
		if (isClass(_t>>"viewoptics")) then {
			_fov = getNumber(_t>>"viewoptics">>"minfov");
		};
	};
	_c = if (_fov < 0.14) then {0.5} else {2};
	TRACE_2("",_fov,_c); //[format["fov %1 _c %2",_fov,_c]] call cba_fnc_debug;
} else {
	//if (_pos select 0 == "Driver") then {
		//if !(_weapon in (getArray(__vcfg>>"weapons"))) exitwith {_abort = true};
		_c = 1.75;
	//};
};
if (_abort) exitwith { TRACE_1("Shake abort",""); };

if (_ammo isKindOf "BulletBase") then {
	_m = getNumber (__acfg>>"ace_mass");
	_c = _c*(2.5 min _m/6);
};
_pwr = _c*getNumber(__acfg>>"ace_sys_camshake_coef");

TRACE_1("",_pwr);
if (_pwr < 0.001) exitwith {};
addcamshake [_pwr,0.1,20];
