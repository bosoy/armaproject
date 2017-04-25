// [unit, mag class A, mag class B] call this_func to convert all A's to B's
// [unit, mag class A] call this_func to refill the mags of type A

#include "script_component.hpp"

private ["_readdwpn","_primw","_pst","_veh","_magclass0","_type","_capacity","_capacity0","_rnds","_rndsleft","_fullmags","_exit","_amt","_cfgM","_magclass","_muzzles","_magm", "_mz","_ammo", "_curloaded", "_unit", "_wpn","_wpn0", "_cfg", "_muzzle","_muzzle0", "_weapMags", "_dummy", "_curmag", "_s", "_mag","_looseC","_belt","_pckTime"];
_unit = _this select 0;
_magclass0 =  _this select 1; //initial mag class
if (count _this == 2) then {_magclass = _magclass0} else {_magclass =  _this select 2}; //class to convert to

//diag_log time;
// diag_log "start";
//diag_log format ["This %1 mags player %2",_this,magazines _unit];

if(GVAR(refillinprogress)) exitwith {};
GVAR(refillinprogress) = true;

_veh = vehicle _unit;
if (_unit != _veh && {(_unit == driver _veh || {_unit == gunner _veh} || {_unit == commander _veh})}) exitwith {GVAR(refillinprogress) = false};
if (_unit call ace_sys_wounds_fnc_isuncon) exitwith {GVAR(refillinprogress) = false};
_amt = {_x==_magclass0} count (magazines _unit);
if (_amt < 2) exitwith {GVAR(refillinprogress) = false};

_cfgM = (configFile >> "CfgMagazines" >> _magclass0);
_type = if (isNumber(_cfgM>>"type")) then {
	getNumber(_cfgM>>"type");
} else {
	call compile getText(_cfgM>>"type");
};

_looseC = [_cfgM>>QGVAR(loose_cartridges),"number", 0] call CBA_fnc_getConfigEntry;
_belt = [_cfgM>>QGVAR(belt),"number", 0] call CBA_fnc_getConfigEntry;

_capacity0 = getNumber (_cfgM>>"count");
_capacity = getNumber (configFile >> "CfgMagazines" >> _magclass >>"count");

_pckTime = 12*_amt*_capacity0/30; //12 secs per 30rnds mag
if (_looseC == 1) then {_pckTime = 0.1};
if (_belt == 1) then {_pckTime = 18*_amt}; //18 secs per box (linking)


if (_unit == _veh) then {
	[_pckTime,[localize "STR_DN_ACE_MAGAZINESREFILL_PB"],true,true] spawn ace_progressbar;
} else {
	[_pckTime,[localize "STR_DN_ACE_MAGAZINESREFILL_PB"],false,true] spawn ace_progressbar; //can repack in cargo of moving vehicle
};

sleep 1;
waitUntil {(_unit getVariable "ACE_PB_Result" != 0) || {(_unit call ace_sys_wounds_fnc_isuncon)} };
if ((_unit getVariable "ACE_PB_Result" != 1) || {(_unit call ace_sys_wounds_fnc_isuncon)}) exitwith {GVAR(refillinprogress) = false;135996 cutText["", "PLAIN"]};

//if (_capacity0 == 1) exitwith {};

_pst = [_unit] call ACE_fnc_getPistol;
_primw = primaryweapon _unit;
_readdwpn = "";
_wpn0 = if (_type == 16) then {_pst} else {_primw};
_cfg = configFile >> "CfgWeapons";
_mags = ["bla"];
if (_wpn0 != "") then {
	if (isClass (_cfg>>_wpn0)) then {
		_cfg = (configFile >> "CfgWeapons" >> _wpn0);
		_muzzle0 = _wpn0;
		_muzzles = getArray (_cfg >> "muzzles");
		if ("this" != (_muzzles select 0)) then {
			_muzzle0 = _muzzles select 0;
			_cfg = (_cfg >> _muzzle0);
		};
		_mags = getArray (_cfg >> "magazines");
	};
};

if (_wpn0 == _primw && {_pst != ""} && {_primw != ""}) then {_readdwpn = _pst};
if (_wpn0 == _pst && {_pst != ""} && {_primw != ""}) then {_readdwpn = _primw};

_wpn = _wpn0;
 //diag_log format ["wpn %1 mags %2 type %3",_wpn0,_mags,_type];

if ({_x == _magclass} count _mags < 1) then { //plr doesnt have weapon that takes target mags, finding one in configs
	//_cfg = (configFile >> "CfgWeapons" >> _wpn);
	_cfg = configFile >> "CfgWeapons";
	_wpn = "";
	for "_i" from 0 to (count _cfg - 1) do {
		_cur = _cfg select _i;
		if (isClass (_cur)) then {
			_mags = getArray (_cur>>"magazines");
			if ({_x == _magclass} count _mags > 0) exitwith {_wpn = configname(_cur)};
		};
		if (_wpn != "") exitwith {};
	};
};

if !(isClass (configFile >> "CfgWeapons" >> _wpn)) exitwith {GVAR(refillinprogress) = false};

_cfg = (configFile >> "CfgWeapons" >> _wpn);
_muzzle = _wpn;
_muzzles = getArray (_cfg >> "muzzles");
if ("this" != (_muzzles select 0)) then {
	_muzzle = _muzzles select 0;
	_cfg = (_cfg >> _muzzle);
};
_mags = getArray (_cfg >> "magazines");
_magm = currentmagazine _unit;
_curloaded = (_magm == _magclass0);
_ammo = if (_curloaded) then {_unit ammo _muzzle0} else {0};

// ====== Starting the transactions ====== //

_dummy = [];

for "_i" from 0 to (_amt-1) do {
	_dummy set[count _dummy, createAgent ["ACE_CivDummy", [10,10,0], [], 0, "FORM"]];
};

waitUntil { alive (_dummy select 0)};

// diag_log time;
// diag_log "Dummies Alive";
{
	_x disableAI "TARGET";
	_x disableAI "AUTOTARGET";
	_x disableAI "MOVE";
	_x disableAI "ANIM";
	removeAllWeapons _x;
	removeAllItems _x;
	_unit reveal _x;
} foreach _dummy;

// diag_log time;
 //diag_log format ["Giving mags to dummies %1",_dummy];

if (_curloaded) then {_unit removeweapon _wpn0; if (_readdwpn!="") then {_unit removeweapon _readdwpn}};

//giving mags to dummies

for "_i" from 0 to (_amt-1) do {
	 //diag_log format ["Giving mag %1 to dummy %2",_magclass0,_dummy select _i];
	_unit action ["DROPMAGAZINE", _dummy select _i, _magclass0];
};

//if (_curloaded) then
//{
	waituntil {
		({_x==_magclass0} count (magazines _unit) == 0) 
	};
//};
// diag_log format["Success1 mags plr %1",magazines player];

// _s - dummy who got no mag before (as it was loaded, player refused to give it away
_s = objNull;
{
	// diag_log format["%1 mags %2",_x, magazines _x];
	if ( count (magazines _x) == 0) exitwith {_s = _x};
} foreach _dummy;


if !( isNull _s) then {
	if ({_x==_magclass0} count (magazines _unit) > 0) then {
		_unit action ["DROPMAGAZINE", _s, _magclass0];
		waituntil {count (magazines _s) == 1};
	};
};
if (_curloaded) then {_unit addweapon _wpn0;_unit selectweapon _muzzle0;if (_readdwpn!="") then {_unit addweapon _readdwpn}};
// diag_log time;
// diag_log format["Success2 mags plr %1 wpn %2 muz %3",magazines _unit,_wpn,_muzzle];

_rnds = 0;
{
	_x addweapon _wpn;
	_x selectweapon _muzzle;
	//sleep 0.1;
	_rnds = _rnds + (_x ammo _muzzle);
	//diag_log format["Dummy %1 mags %2 rnds %3",_x,magazines _x,_x ammo _muzzle];
} foreach _dummy;

_fullmags = floor (_rnds/_capacity);
_rndsleft = _rnds - _fullmags*_capacity;

//diag_log format["Total rnds %1 full mags %2 loose rnds %3",_rnds,_fullmags,_rndsleft];

if (_fullmags > 0) then {
	for "_i" from 1 to _fullmags do {
		_unit addmagazine _magclass;
	};
};
if (_rndsleft > 0) then {
	_s = _dummy select 0;
	{_s removemagazines _x} foreach (magazines _s);
	removeallweapons _s;
	_s addmagazine _magclass;
	_s setvehicleammo (_rndsleft/_capacity);
	_s action ["DROPMAGAZINE", _unit, (magazines _s) select 0];
	//diag_log format["%1 is returning mag, mags %2",_s, magazines _s];
	sleep 2;

//	diag_log time;
	//diag_log format["All done, plr mags %1 dummy mags %2",magazines _unit, magazines _s];
};
 //diag_log "Deleting dummies";

{
	deleteVehicle _x;
} foreach _dummy;

GVAR(refillinprogress) = false;

// diag_log time;
// diag_log "Done";