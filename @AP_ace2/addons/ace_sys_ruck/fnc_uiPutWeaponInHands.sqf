/* ace_sys_ruck (.pbo) (c) 2009 by tcp */
//#define DEBUG_MODE_FULL

#include "script_component.hpp"
#include "script_dialog_defines.hpp"

ace_weapononback_inprogress = true;

private ["_dispb", "_weapon_on_back", "_type", "_x", "_mag", "_magC", "_reselect", "_mz"];
PARAMS_2(_unit,_weapon);

_dispb = false;
_weapon = "";

_weapon_on_back = _unit getVariable ["ACE_weapononback",""];
if ( _weapon_on_back != "" && {isClass (configFile >> "cfgWeapons" >> _weapon_on_back)} ) then {
	_type = getNumber(configFile >> "CfgWeapons" >> _weapon_on_back >> "type");
	{
		if ( getNumber(configFile >> "CfgWeapons" >> _x >> "type") == _type ) exitwith {
			_weapon = _x;
			_mag = getArray(__CONF_WEAPONS >> _x >> "magazines");
			TRACE_1("mag",_mag);

			_magC = -1;
			if (count _mag > 0) then {
				_mag = _mag select 0;
				_magC = getNumber(__CONF_MAGAZINES >> _mag >> "count");
			};
			TRACE_1("magC",_magC);

			if ( _magC == 0 ) then {
				_dispb = true;
				_weapon = "";
			};
		};
	} foreach (weapons _unit);
	TRACE_2("Weapons",_dispb,_weapon);

	_reselect = ( currentWeapon _unit == _weapon );
	if ( _weapon != "" ) then {
		_unit removeWeapon _weapon;
	};

	_unit setvariable ["ACE_weapononback", _weapon, true];

	//if (_type == 1) then { };

	if (_dispb) then {ACE_WOB_DISPB = true;};

	_unit addWeapon _weapon_on_back;

    [QGVAR(changed), [-1,0,_weapon_on_back]] call CBA_fnc_localEvent;

	if ( _reselect ) then {
		_mz = ([_weapon_on_back] call CBA_fnc_determineMuzzles) select 0;
		_unit selectWeapon _mz;
	};
};

ace_weapononback_inprogress = false;
