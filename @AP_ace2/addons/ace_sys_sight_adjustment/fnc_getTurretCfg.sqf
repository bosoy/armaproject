// #define DEBUG_MODE_FULL
#include "script_component.hpp"
//returns config of given turret and its weapon
//if given turret is [0] it returns path to vehicle config (to simplify config job for 1-turret vehicles)
//true path to the turret is also returned as the third argument
private ["_ar","_adjustedpath","_vehcfg","_weap","_path","_weapons","_abort"];

PARAMS_2(_veh,_turret);
_sa = false;
_te = false;
_vehcfg = configfile >> "CfgVehicles" >> _veh;
_path = _vehcfg;
_ar = [];
{
	_path = _path >> "Turrets";
	_ar = [];
	for "_i" from 0 to (count _path - 1) do
	{
		if(isClass(_path select _i)) then {_ar set[count _ar,_path select _i]};
	};
	_path = _ar select _x;
//[format["ar %2 path %1",_path,_ar]] call cba_fnc_debug;
} foreach _turret;
_weapons = getArray (_path >> "weapons");
_weap = "";
{
	if (getNumber(configfile >> "cfgWeapons" >> _x >> "ace_sa_enabled") == 1) exitwith {_weap = _x; _sa = true};
} foreach _weapons;
{
	if (getNumber(configfile >> "cfgWeapons" >> _x >> "ace_sa_te_enabled") == 1) exitwith {_weap = _x; _te = true};
} foreach _weapons;

_adjustedpath = _path;
if (count _turret == 1 && {_turret select 0 == 0}) then {
	_adjustedpath = _vehcfg;
};
if (getNumber(_adjustedpath >> "ace_sa_enabled") == 0) then {_sa = false};
if (getNumber(_adjustedpath >> "ace_sa_te_enabled") == 0) then {_te = false};

TRACE_5("",_adjustedpath,_weap,_path,_sa,_te);
[_adjustedpath,_weap,_path,_sa,_te]