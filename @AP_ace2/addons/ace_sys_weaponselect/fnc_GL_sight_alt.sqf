// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_classes","_reload","_GLmags_unit","_GLmags","_wpnNew","_magGL","_ammoGL","_muzzleGL","_muzzles","_magm", "_mz","_ammo", "_pistol", "_max", "_unit", "_wpn", "_cfg", "_muzzle", "_weapMags", "_dummy", "_dummy2", "_curdummy", "_curmag", "_i", "_s", "_mag"];

_unit = player;
_wpn = primaryweapon player;
_cfg = (configFile >> "CfgWeapons" >> _wpn);
if !(isArray(_cfg>>"ace_gl_classes")) exitwith {};
_classes = getArray(_cfg>>"ace_gl_classes");

if ({_x==_wpn} count _classes != 1) exitwith {};
_wpnNew = if (_wpn == (_classes select 0)) then {_classes select 1} else {_classes select 0};

_muzzleGL = _wpn call FUNC(hasGL);
if !(_muzzleGL select 0) exitwith {};

if (GVAR(GLinprogress)) exitwith {};
GVAR(GLinprogress) = true;

_muzzleGL = _muzzleGL select 1;
_GLMags = getArray(_cfg >> _muzzleGL >> "magazines");

_muzzle = _wpn;
_muzzles = getArray (_cfg >> "muzzles");
if ("this" != (_muzzles select 0)) then
{
	_muzzle = _muzzles select 0;
	_cfg = (_cfg >> _muzzle);
};

_mz = currentmuzzle _unit;

if (_mz == _muzzle) then
{
	_magm = currentmagazine _unit;
	_unit selectweapon _muzzleGL;
	_magGL = currentmagazine _unit;
	_unit selectweapon _muzzle;
} else
{
	_magGL = currentmagazine _unit;
	_unit selectweapon _muzzle;
	_magm = currentmagazine _unit;
	_unit selectweapon _muzzleGL;
};

_ammoGL = _unit ammo _muzzleGL;
_ammo = _unit ammo _muzzle;

_reload = true;
if (isClass(configfile>>"cfgMagazines">>_magm)) then
{
	_max = getNumber(configfile>>"cfgMagazines">>_magm>>"count");
	//if (_ammo == _max && _ammoGL > 0) then {_reload = false};
	if (_ammo == _max) then {_reload = false};
};

_GLmags_unit = [];
{
	_mag = _x;
	if ({_x==_mag} count _GLMags > 0) then {_GLmags_unit set [count _GLmags_unit, _mag]};
} foreach (magazines _unit);


//removing GL mags
{
	_unit removemagazine _x;
} foreach _GLmags_unit;

_unit removemagazines _magGL;

if (_ammoGL > 0 && {_magGL != ""}) then {_unit addmagazine _magGL};


//if(_reload) then
//{
//	_unit playActionNow "ReloadMagazine";
	_unit playAction "gesturePoint";
	sleep 1;
//};

_unit addWeapon _wpnNew;
_unit removeWeapon _wpn;
_unit selectweapon _mz;

//returning GL mags
_s = 0;
{
	if (_x == _magGL && {_ammoGL > 0} && {_s == 0}) then
	{
		_s = 1;
	} else
	{
		_unit addmagazine _x;
	};
} foreach _GLmags_unit;

GVAR(GLinprogress) = false;
