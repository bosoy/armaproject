//#define DEBUG_MODE_FULL
#include "script_component.hpp"

private ["_w","_readdwpn","_primw","_pst","_veh","_cnt","_muzzles","_mz","_unit", "_wpn","_cfg","_muzzle","_weapMags", "_dummy","_cfgmz", "_cur","_mag"];
_unit = _this;
TRACE_1("",_unit);
//diag_log time;
//diag_log "start";
//diag_log format ["This %1 mags player %2",_this,magazines _unit];

if(GVAR(refillinprogress)) exitwith {};
GVAR(refillinprogress) = true;

//_veh = vehicle _unit;
//if (_unit != _veh && {(_unit == driver _veh || _unit == gunner _veh || _unit == commander _veh)}) exitwith {GVAR(refillinprogress) = false};

_pst = [_unit] call ACE_fnc_getPistol;
_primw = primaryweapon _unit;

_wpn = currentweapon _unit;
_mz = currentmuzzle _unit;
_mag = currentmagazine _unit;

TRACE_5("",_pst,_primw,_wpn,_mz,_mag);

if (_unit ammo _mz == 0) exitwith {GVAR(refillinprogress) = false};

_readdwpn = if (_wpn == _primw) then {_pst} else {_primw};
TRACE_1("",_readdwpn);

_weapmags = [];
if (isClass (configFile >> "CfgWeapons" >>_wpn)) then {
	_cfg = (configFile >> "CfgWeapons" >> _wpn);
	_muzzle = _wpn;
	_muzzles = getArray (_cfg >> "muzzles");
	TRACE_1("",_muzzles);
	{
		_cfgmz = if (_x != "this") then {_cfg >> _x} else {_cfg};
		_weapmags = _weapmags + getArray (_cfgmz >> "magazines");
	} foreach _muzzles;
};
TRACE_1("",_weapmags);

_m = [];

{
	_cur = _x;
	if ({_x == _cur} count _weapmags > 0) then {_m set [count _m, _cur]};

} foreach (magazines _unit);
TRACE_1("",_m);

if (count _m == 0) exitwith {GVAR(refillinprogress) = false};


// ====== Starting the transactions ====== //
// TODO: fnc_refill uses more than one dummy to transfer the magazines back to the unit while unload uses only one dummy. Change it so this one also uses more dummies ?
// action DROPMAGAZINE does not always work reliably, sometimes it does not drop a mag
// best would be if finally the fucking magazinesEX command would be available

_dummy = createAgent ["ACE_CivDummy", position _unit, [], 0, "FORM"];
TRACE_1("",_dummy);

waitUntil {alive _dummy};
{
	_x disableAI "TARGET";
	_x disableAI "AUTOTARGET";
	_x disableAI "MOVE";
	_x disableAI "ANIM";
	removeAllWeapons _x;
	removeAllItems _x;
	_unit reveal _x;
} foreach [_dummy];

if (_readdwpn != "") then {_unit removeweapon _readdwpn};

//diag_log "dropping weapon";
//_unit action ["DROPWEAPON", _dummy, _wpn];
_unit removeweapon _wpn;
{
	_unit action ["DROPMAGAZINE", _dummy, _x];
	TRACE_1("action dropmag 1",_forEachIndex);
} foreach _m;

waituntil {{_x==(_m select 0)} count (magazines _unit) == 0};
//diag_log "dropped weapon";
_unit addweapon _wpn;
_unit selectweapon _mz;
if (_readdwpn!="") then {_unit addweapon _readdwpn};
//_dummy removeweapon _wpn;
while {count (magazines _dummy)>0} do {
	_cnt = count (magazines _dummy);
	TRACE_5("",_cnt,_dummy,(magazines _dummy),(magazines _unit),(alive _dummy));
	_dummy action ["DROPMAGAZINE", _unit, (magazines _dummy) select 0];
	TRACE_2("",(magazines _dummy),(magazines _unit));
	//_unit action ["TAKEMAGAZINE", _dummy, (magazines _dummy) select 0];
	//diag_log format["%1 is returning mag, mags %2",_dummy, magazines _dummy];
	TRACE_1("waiting...",(alive _dummy));
	_endtime = time + 1;
	waituntil {count (magazines _dummy) < _cnt || {time >= _endtime}};
};

sleep 0.5;
//diag_log format["All done, plr mags %1 dummy mags %2",magazines _unit, magazines _dummy];
deleteVehicle _dummy;

GVAR(refillinprogress) = false;

//diag_log time;
//diag_log "Done";