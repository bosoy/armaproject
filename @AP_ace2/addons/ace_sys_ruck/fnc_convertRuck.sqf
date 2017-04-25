//#define DEBUG_MODE_FULL
#include "script_component.hpp"
private ["_unit","_oapack","_oapacktype","_cfg","_acepacktype","_fnc_itemlist","_weapons","_mags","_havesec"];

if (count _this > 2) then {
	_unit = _this select 2; // getOut
} else {
	_unit = _this select 0; // init/respawn
};
TRACE_1("Ruck conversion begins",_unit);
if !(local _unit) exitWith {TRACE_1("EXIT: Remote unit",_unit)};
if (vehicle _unit != _unit) exitWith {TRACE_1("EXIT: Unit in vehicle",_unit)};

_oapack = unitBackpack _unit;
if (isNull _oapack) exitWith {TRACE_1("EXIT: Unit does not have OA ruck",_unit)};

_oapacktype = typeOf _oapack;
_cfg = (configFile >> "CfgVehicles" >> _oapacktype);
if !(isArray (_cfg >> "ACE" >> QUOTE(COMPONENT) >> "convert")) exitWith {TRACE_1("Exit: Bad or missing ruck conversion config",_oapacktype)};
_cfg = getArray (_cfg >> "ACE" >> QUOTE(COMPONENT) >> "convert");
if ({_x == _oapacktype} count _cfg != 1) exitWith {TRACE_1("Exit: Bad or missing ruck conversion config",_cfg)};
_acepacktype = if (_oapacktype == _cfg select 0) then {_cfg select 1} else {_cfg select 0};
if !(isClass (configFile >> "CfgWeapons" >> _acepacktype)) exitWith {TRACE_1("Exit: ACE ruck class not found",_acepacktype)};

_fnc_itemlist = {
	PARAMS_2(_types,_numbers);
	private ["_itemlist","_i","_j"];
	_itemlist = [];
	for "_i" from 0 to ((count _types) - 1) do {
		for "_j" from 1 to (_numbers select _i) do {
			_itemlist set [count _itemlist, _types select _i];
		};
	};
	TRACE_1("",_itemlist);
	_itemlist
};

_weapons = (getWeaponCargo _oapack) call _fnc_itemlist;
_mags = (getMagazineCargo _oapack) call _fnc_itemlist;
//check if unit already has a secondary weapon
_haveSec = (secondaryWeapon _unit) != "";
removeBackpack _unit;
_unit addWeapon _acepacktype;
{[_unit,_x] call ace_sys_ruck_fnc_AddWepToRuck} forEach _weapons;
{[_unit,_x] call ace_sys_ruck_fnc_AddMagToRuck} forEach _mags;
//put ACE pack on back
if (_havesec) then {[_unit, _acepacktype] call ACE_fnc_PutWeaponOnBack};
TRACE_1("Ruck conversion ends",_unit);
