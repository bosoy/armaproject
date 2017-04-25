/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL

#include "script_component.hpp"

ace_weapononback_inprogress = true;

PARAMS_2(_unit,_weapon);

private ["_add","_weapon_on_back","_mz","_type","_dispb","_dweapon","_curWep"];

_curWep = currentWeapon _unit;
_add = true;
_dispb = false;
_dweapon = "";

_weapon_on_back = _unit getVariable ["ACE_weapononback",""];
//disposable launcher handling
_mag = getArray(__CONF_WEAPONS >> _weapon >> "magazines");
TRACE_1("mag",_mag);

_magC = -1;
if (count _mag > 0) then {
	_mag = _mag select 0;
	_magC = getNumber(__CONF_MAGAZINES >> _mag >> "count");
};
TRACE_1("magC",_magC);

if ( _magC == 0 ) then {
	_dispb = true;
} else {
	_unit removeWeapon _weapon;
	TRACE_1("Has",_unit hasWeapon _weapon);
};
TRACE_3("Disposable",_dispb,_weapon,_weapon_on_back);

if ( _weapon_on_back != "" && {isClass (__CONF_WEAPONS >> _weapon_on_back)} ) then {
	_type = getNumber(__CONF_WEAPONS >> _weapon_on_back >> "type");
	{
		if ( getNumber(__CONF_WEAPONS >> _x >> "type") == _type ) exitWith {
			_add = false;
			_dweapon = _x;
		};
	} foreach (weapons _unit);
	TRACE_3("Weapons",_add,_dweapon,weapons _unit);

	if (_dispb) then {
		_weapon = "";
		ACE_WOB_DISPB = true;
		_unit addWeapon _weapon_on_back;
	} else {
		if (! _add) then {
			if (_dweapon == _weapon_on_back) then {
				_unit action ["dropweapon", _unit, _dweapon];
				[_unit,_dweapon,_weapon_on_back] spawn {
					PARAMS_3(_unit,_dweapon,_weapon_on_back);
					waitUntil{sleep 0.3; !(_unit hasWeapon _dweapon)};
					_unit addWeapon _weapon_on_back;
				};
				TRACE_2("Dupe",_dweapon,_weapon_on_back);
			} else {
				_unit addWeapon _weapon_on_back;
				_unit action ["dropweapon", _unit, _weapon_on_back];
				TRACE_1("Not",_weapon_on_back);
			};
		} else {
			if (_type == 1) then { };
			_unit addWeapon _weapon_on_back;
		};
	};
};

_unit setvariable ["ACE_weapononback", _weapon, true];

[QGVAR(changed), [1,0,_weapon]] call CBA_fnc_localEvent;

if ( currentWeapon _unit != _curWep && {_unit hasWeapon _curWep} ) then {
	_mz = ([_curWep] call CBA_fnc_determineMuzzles) select 0;
	_unit selectWeapon _mz;
};

ace_weapononback_inprogress = false;
