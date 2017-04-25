// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_unit,_wpn,_classes);
private ["_exit","_handlemags","_handlemagsGL","_mags_unit","_GLmags_unit","_GLmags","_wpnNew","_magGL","_ammoGL","_muzzleGL","_muzzles","_magm", "_mz","_ammo", "_cfg", "_muzzle", "_weapMags", "_dummy", "_i", "_s", "_mag", "_hint"];
//diag_log time;
//diag_log "start";

_cfg = (configFile >> "CfgWeapons" >> _wpn);
_wpnNew = if (_wpn == (_classes select 0)) then { _classes select 1 } else { _classes select 0 };
_hasmuzzleGL = (_wpn call FUNC(hasGL)) select 0;
_muzzleGL = (_wpn call FUNC(hasGL)) select 1;

if(GVAR(GLinprogress)) exitwith {};
GVAR(GLinprogress) = true;

_GLMags = if (_hasmuzzleGL) then { getArray(_cfg >> _muzzleGL >> "magazines") } else { [] };

_muzzle = _wpn;
_muzzles = getArray (_cfg >> "muzzles");
if ("this" != (_muzzles select 0)) then {
	_muzzle = _muzzles select 0;
	_cfg = _cfg >> _muzzle;
};
_weapMags = getArray (_cfg >> "magazines");

_hint = if (getNumber (_cfg >> "irdistance") > 0) then { "Flashlight" } else { "IR" };

//listing current ammo counts and magazines for rifle and GL muzzles
if (currentmuzzle _unit == _muzzle) then {
	_magm = currentmagazine _unit;
	_ammo = _unit ammo _muzzle;
	_unit selectweapon _muzzleGL;
	_magGL = currentmagazine _unit;
	_ammoGL = _unit ammo _muzzleGL;
	_unit selectweapon _muzzle;
	_mz = _muzzle;
} else {
	_unit selectweapon _muzzle;
	_magm = currentmagazine _unit;
	_ammo = _unit ammo _muzzle;
	_unit selectweapon _muzzleGL;
	_magGL = currentmagazine _unit;
	_ammoGL = _unit ammo _muzzleGL;
	_mz = _muzzleGL;
};

//lists of player's magazines for rifle and GL muzzles

_mags_unit = [];
_GLmags_unit = [];
{
	_mag = _x;
	if ({_x==_mag} count _weapMags > 0) then {_mags_unit set [count _mags_unit, _mag]};
	if ({_x==_mag} count _GLMags > 0) then {_GLmags_unit set [count _GLmags_unit, _mag]};
} foreach (magazines _unit);

_handlemags = (count _mags_unit != 0);
_handlemagsGL = (count _GLmags_unit != 0);

if (_handlemags) then {
	if (_magm == "" || {_magm == "<null>"} || {({_x==_magm} count _mags_unit == 0)}) then {_magm = _mags_unit select 0};
};
if (_handlemagsGL) then {
	if (_magGL == "" || {_magGL == "<null>"} || {({_x==_magGL} count _GLmags_unit == 0)}) then {_magGL = _GLmags_unit select 0};
};

// ====== Starting the transactions ====== //
_dummy = [];

if (_handlemags) then {
	for "_i" from 0 to ((count _mags_unit)-1) do {
		_dummy set[count _dummy, createAgent ["ACE_CivDummy", [10,10,0], [], 0, "FORM"]];
	};

	waitUntil { alive (_dummy select 0)};

	//diag_log time;
	//diag_log "Dummies Alive";
	{
		_x disableAI "TARGET";
		_x disableAI "AUTOTARGET";
		_x disableAI "MOVE";
		_x disableAI "ANIM";
		removeAllWeapons _x;
		removeAllItems _x;
		_unit reveal _x;
	} foreach _dummy;

	//diag_log time;
	//diag_log format ["Giving mags to dummies %1",_dummy];

	//giving rifle mags to dummies
	_i = 0;
	_s = {_x==_magm} count (magazines _unit);
	{
		if (_x == _magm) then {
			if (_s > 1 || {_ammo == 0}) then { //give all mags of this type but currently loaded
				//diag_log format ["Giving mag %1 to dummy %2",_x,_dummy select _i];
				_unit action ["DROPMAGAZINE", _dummy select _i, _x];
				INC(_i);
				DEC(_s);
			};
		} else {
			//diag_log format ["Giving mag %1 to dummy %2",_x,_dummy select _i];
			_unit action ["DROPMAGAZINE", _dummy select _i, _x];
			INC(_i);
		};
	} foreach _mags_unit;
};

if (_handlemagsGL) then {
	//removing GL mags
	{
		//diag_log format ["Removing GL mag %1",_x];
		_unit removemagazine _x;
	} foreach _GLmags_unit;
	_unit removemagazines _magGL;
	if (_ammoGL > 0) then {_unit addmagazine _magGL};
};

//diag_log time;
//diag_log format["ammo %1 ammoGL %2 curmag %3 curmagGL %4",_ammo,_ammoGL,_magm,_magGL];

if (_handlemags) then {
	if (_magm != "") then {
		waituntil {	// only one mag for this weapon should be left (currently loaded)
			_exit = true;
			{
				_mag = _x;
				if (_mag != _magm && {({_x==_mag} count _mags_unit) > 0}) then {
					_exit = false;
				};
			} foreach (magazines _unit);
			_exit && {({_x==_magm} count (magazines _unit) <= 1)}
		};
	};
	//diag_log format["Success1 mags plr %1",magazines player];

	// _s - dummy who got no mag before (as it was loaded, player refused to give it away
	{
		//diag_log format["%1 mags %2",_x, magazines _x];
		_s = if ( count (magazines _x) == 0) then { _x } else { _dummy select 0 };
	} foreach _dummy;

	if (_ammo == 0) then {
		if ({_x==_magm} count (magazines _unit) > 0) then {
			_unit action ["DROPMAGAZINE", _s, _magm];
			waituntil {
				(count (magazines _s) == 1)
			};
		};
	};
	//diag_log time;
	//diag_log format["Success2 mags plr %1",magazines player];
};

hintSilent _hint;
//need a sound, a gesture maybe too

//new weapon
_unit addWeapon _wpnNew;
_unit removeWeapon _wpn;
_unit selectweapon _mz;
_wasSafe = player getVariable [QGVAR(safety),[]];
_safe = if (count _wasSafe == 0) then { false } else { (_wasSafe select 1) };
if (_safe) then {
	player setVariable [QGVAR(safety),[(currentWeapon player),true]];
	if !(player hasweapon "ace_safe") then {player addweapon "ace_safe"};
	player selectweapon "ace_safe";
};

//returning GL mags
_s = 0;
{
	if (_x == _magGL && {_ammoGL > 0} && {_s == 0}) then {
		_s = 1;
	} else {
		player addmagazine _x;
		//diag_log format["adding GL mag %1 mags %2",_x, magazines player];
	};
} foreach _GLmags_unit;

if (_handlemags) then {
	//returning rifle mags
	{
		if ( count (magazines _x) > 0) then {
			_x action ["DROPMAGAZINE", _unit, (magazines _x) select 0];
			//diag_log format["%1 is returning mag, mags %2",_x, magazines _x];
		};
	} foreach _dummy;

	sleep 2;
	//diag_log time;
	//diag_log "dummies given the mags back";
	//diag_log "Deleting dummies";
	{
		deleteVehicle _x;
	} foreach _dummy;
};

GVAR(GLinprogress) = false;

//diag_log time;
//diag_log "Done";
