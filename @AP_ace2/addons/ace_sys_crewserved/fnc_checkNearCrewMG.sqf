#include "script_component.hpp"

PARAMS_3(_unit,_action,_radius);

_fCheckManipulate= {
	_ok = false;
	_MG = ((position _this) nearEntities ["StaticWeapon", _radius]) select 0;
	if !(isNull _MG) then {
		_ok = alive _MG && {(getText(configFile >> 'CfgVehicles' >> typeOf _MG >> 'ACE' >> 'ACE_CREWSERVED' >> 'tripod') != '')};
	};
	_r = _this getVariable ['ace_sys_crewserved_rotating', false];
	_ok && !_r
};

_fCheckLoadAmmo= {
	_ok = false;
	_r = false;
	_MG = ((position _this) nearEntities ["StaticWeapon", _radius]) select 0;
	if !(isNull _MG) then {
		_ok = alive _MG && {(getText(configFile >> 'CfgVehicles' >> typeOf _MG >> 'ACE' >> 'ACE_CREWSERVED' >> 'tripod') != '')};
	};
	if _ok then {
		_type = typeOf _MG;
		_dummyMags = getArray (configfile >> "CfgVehicles" >> _type >> "ACE" >> "ACE_CREWSERVED" >> "magazines");
		_fullMagRds = getNumber (configfile >> "CfgMagazines" >> _dummyMags select 0 >> "count");
		_wepType = (getArray (configfile >> "CfgVehicles" >> _type >> "Turrets" >> "MainTurret" >> "weapons")) select 0;
		_wepMagType = (getArray (configfile >> "CfgVehicles" >> _type >> "Turrets" >> "MainTurret" >> "magazines")) select 0;
		_totalAmmo = getNumber (configfile >> "CfgMagazines" >> _wepMagType >> "count");

		_curMag = -1;
		{
			if (_x in _dummyMags) exitWith {_curMag = _dummyMags find _x};
		} forEach magazines _unit;
		if (_curMag == -1 || {isNil "_curMag"}) exitWith {};
		if (_totalAmmo == _fullMagRds) then {
		_canAmmoLink = false;
	} else {
		_canAmmoLink = true;
	};
		if ((_MG ammo _wepType ) > 0 && {!_canAmmoLink}) exitWith {};
		if ((_MG ammo _wepType ) > _fullMagRds) exitWith {};
		if (gunner _MG == _this) exitWith {};
		_r = true;
	};
	_r
};

_fCheckUnloadAmmo= {
	_ok = false;
	_r = false;
	_MG = ((position _this) nearEntities ["StaticWeapon", _radius]) select 0;
	if !(isNull _MG) then {
		_ok = alive _MG && {(getText(configFile >> 'CfgVehicles' >> typeOf _MG >> 'ACE' >> 'ACE_CREWSERVED' >> 'tripod') != '')};
	};
	if _ok then {
		_type = typeOf _MG;
		_CSWMagType = (getArray (configfile >> "CfgVehicles" >> _type >> "ACE" >> "ACE_CREWSERVED" >> "magazines") select 0);
		_fullMagRds = getNumber (configfile >> "CfgMagazines" >> _CSWMagType >> "count");
		_wepType = (getArray (configfile >> "CfgVehicles" >> _type >> "Turrets" >> "MainTurret" >> "weapons")) select 0;
		_wepMagType = (getArray (configfile >> "CfgVehicles" >> _type >> "Turrets" >> "MainTurret" >> "magazines")) select 0;
		_totalAmmo = getNumber (configfile >> "CfgMagazines" >> _wepMagType >> "count");
		if (gunner _MG == _unit) exitWith {};
		if (_MG ammo _wepType < (_fullMagRds * .25)) exitWith {};
		_r = true;
	};
	_r
};

switch toLower(_action) do {
	case "rotate":  {_unit call _fCheckManipulate};
	case "unmount": {_unit call _fCheckManipulate};
	case "load":	{_unit call _fCheckLoadAmmo};
	case "unload":  {_unit call _fCheckUnloadAmmo};
	default {false};
};
