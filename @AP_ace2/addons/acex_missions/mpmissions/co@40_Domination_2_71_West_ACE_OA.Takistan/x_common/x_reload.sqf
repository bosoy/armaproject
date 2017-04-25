// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_reload.sqf"
#include "x_setup.sqf"
private ["_trigger", "_object", "_magspercent", "_fuelavailable", "_type", "_curfuel", "_fuelcapacity", "_fuelreal", "_fuelneeded", "_result", "_magazines", "_maxavail", "_maxavailnr", "_idx", "_removed", "_removednr", "_diffn", "_diffnnr", "_ee", "_mname", "_mmax", "_count", "_zz", "_cfgturrets", "_turrets", "_reloadTurrets", "_path", "_i", "_turretIndex", "_thisTurret", "_fullmags", "_samsleft", "_maxsams"];

PARAMS_2(_trigger,_object);

if (typeName _object == "ARRAY") then {
	_obb = objNull;
	{
		if ((_x isKindOf "Helicopter" || _x isKindOf "LandVehicle" || _x isKindOf "Plane") && !(_x isKindOf "HeliH")) exitWith {
			_obb = _x;
		};
	} forEach _object;
	_object = _obb;
};

if (isNull _object) exitWith {};

if (_object isKindOf "ParachuteBase") exitWith {};

_lrl = GV(_object,GVAR(last_reload));
if (isNil "_lrl") then {_lrl = -1};
if (_lrl != -1 && (time - _lrl) < 60) exitWith {
	if (!isDedicated) then {
		[_object, format [(localize "STR_DOM_MISSIONSTRING_699"), round (60 - (time - _lrl))]] call FUNC(VehicleChat)
	};
};
_object setVariable [QGVAR(last_reload), time];

if (isNil {GVAR(reload_time_factor)}) then {GVAR(reload_time_factor) = 1};

_magspercent = GV(_trigger,GVAR(magspercent));
_fuelavailable = GV(_trigger,GVAR(fuelavailable));
if (isNil "_magspercent") then {
	_magspercent = 100;
	_fuelavailable = 5000;
	if (isServer) then {
		_trigger setVariable [QGVAR(magspercent), _magspercent, true];
		_trigger setVariable [QGVAR(fuelavailable), _fuelavailable, true];
	};
};

_type = typeof _object;

if (GVAR(reload_engineoff)) then {_object action ["engineOff", _object]};
if (!alive _object) exitWith {};

if (!isDedicated) then {
	[_object , format [(localize "STR_DOM_MISSIONSTRING_700"), round _fuelavailable, round _magspercent]] call FUNC(VehicleChat);
};

_curfuel = fuel _object;
_fuelcapacity = getNumber(configFile >> "CfgVehicles" >> _type >> "fuelCapacity");
_fuelreal = _curfuel * _fuelcapacity;
_fuelneeded = _fuelcapacity - _fuelreal;

_fuel_end = _curfuel;

if (_fuelavailable > 0) then {
	_result = _fuelavailable - _fuelneeded;
	if (_result < 0) then {
		_fuelavailable = 0;
		_fuelneeded = _fuelneeded + _result;
	} else {
		_fuelavailable = _result;
	};
	
	_fuel_end = (_fuel_end + ((1 / _fuelcapacity) * _fuelneeded)) min 1;
};

_object setFuel 0; // player can't start engine

_type_name = [_type,0] call FUNC(GetDisplayName);

if (!isDedicated) then {[_object,format [(localize "STR_DOM_MISSIONSTRING_701"), _type_name]] call FUNC(VehicleChat)};

_magazines = getArray(configFile >> "CfgVehicles" >> _type >> "magazines");

if (count _magazines > 0) then {
	_maxavail = [];
	_maxavailnr = [];
	{
		if !(_x in _maxavail) then {
			_maxavail set [count _maxavail, _x];
		};
		_idx = _maxavail find _x;
		if (count _maxavailnr == _idx) then {
			_maxavailnr set [_idx, 1];
		} else {
			_maxavailnr set [_idx, (_maxavailnr select _idx) + 1];
		};
	} forEach _magazines;
	
	_removed = [];
	_removednr = [];
	{
		_object removeMagazine _x;
		if !(_x in _removed) then {
			_removed set [count _removed, _x];
		};
		_idx = _removed find _x;
		if (count _removednr == _idx) then {
			_removednr set [_idx, 1];
		} else {
			_removednr set [_idx, (_removednr select _idx) + 1];
		};
	} forEach _magazines;
	
	_diffn = [];
	_diffnnr = [];
	for "_ee" from 0 to (count _maxavail - 1) do {
		_mname = _maxavail select _ee;
		_mmax = _maxavailnr select _ee;
		if !(_mname in _diffn) then {
			_diffn set [count _diffn, _mname];
			_idx = _removed find _mname;
			if (_idx != -1) then {
				_diffnnr set [count _diffnnr, _mmax - (_removednr select _idx)];
			} else {
				_diffnnr set [count _diffnnr, 0];
			};
		};
	};
	
	if (!alive _object) exitWith {};
	
	for "_ee" from 0 to (count _removed - 1) do {
		_mname = _removed select _ee;
		_count = _removednr select _ee;
		if (_count > 0) then {
			_mag_disp_name = [_mname,2] call FUNC(GetDisplayName);
			if (_mag_disp_name == "") then {_mag_disp_name = _mname};
			if (!isDedicated) then {[_object, format [(localize "STR_DOM_MISSIONSTRING_702"), _mag_disp_name]] call FUNC(VehicleChat)};
			for "_zz" from 1 to _count do {
				sleep GVAR(reload_time_factor);
				if (!alive _object) exitWith {};
				_object addMagazine _mname;
				_magspercent = (_magspercent - 1) max 0;
				if (_magspercent == 0) exitWith {
					if (!isDedicated) then {[_object, (localize "STR_DOM_MISSIONSTRING_703")] call FUNC(VehicleChat)};
				};
				sleep GVAR(reload_time_factor);
				if (!alive _object) exitWith {};
			};
		};
	};
	
	if (_magspercent == 0) exitWith {};		
	if (!alive _object) exitWith {};
	
	for "_ee" from 0 to (count _diffn - 1) do {
		_mname = _diffn select _ee;
		_count = _diffnnr select _ee;
		if (_count > 0) then {
			_mag_disp_name = [_mname,2] call FUNC(GetDisplayName);
			if (_mag_disp_name == "") then {_mag_disp_name = _mname};
			if (!isDedicated) then {[_object, format [(localize "STR_DOM_MISSIONSTRING_702"), _mag_disp_name]] call FUNC(VehicleChat)};
			for "_zz" from 1 to _count do {
				sleep GVAR(reload_time_factor);
				if (!alive _object) exitWith {};
				_object addMagazine _mname;
				_magspercent = (_magspercent - 1) max 0;
				if (_magspercent == 0) exitWith {
					if (!isDedicated) then {[_object, (localize "STR_DOM_MISSIONSTRING_703")] call FUNC(VehicleChat)};
				};
				sleep GVAR(reload_time_factor);
				if (!alive _object) exitWith {};
			};
		};
	};
	if (_magspercent == 0) exitWith {};	
};

_cfgturrets = configFile >> "CfgVehicles" >> _type >> "Turrets";
_turrets = [_cfgturrets] call FUNC(returnVehicleTurrets);

_reloadTurrets = {
	private ["_turrets", "_path", "_cfgturrets"];
	PARAMS_3(_turrets,_path,_cfgturrets);

	private "_i";
	_i = 0;
	while {_i < (count _turrets)} do {
		private ["_turretIndex", "_thisTurret"];
		_turretIndex = _turrets select _i;
		_thisTurret = _path + [_turretIndex];
		
		_cfgturrets = _cfgturrets select _turretIndex;
		_fullmags = getArray(_cfgturrets >> "magazines");
		
		_maxavail = [];
		_maxavailnr = [];
		{
			if !(_x in _maxavail) then {
				_maxavail set [count _maxavail, _x];
			};
			_idx = _maxavail find _x;
			if (count _maxavailnr == _idx) then {
				_maxavailnr set [_idx, 1];
			} else {
				_maxavailnr set [_idx, (_maxavailnr select _idx) + 1];
			};
		} forEach _fullmags;
		
		_magazines = _object magazinesTurret _thisTurret;
		if (!alive _object) exitWith {};
		_removed = [];
		_removednr = [];
		{
			_object removeMagazineTurret [_x, _thisTurret];
			if !(_x in _removed) then {
				_removed set [count _removed, _x];
			};
			_idx = _removed find _x;
			if (count _removednr == _idx) then {
				_removednr set [_idx, 1];
			} else {
				_removednr set [_idx, (_removednr select _idx) + 1];
			};
		} forEach _magazines;
		
		__TRACE_3("","_magazines","_removed","_removednr");

		_diffn = [];
		_diffnnr = [];
		for "_ee" from 0 to (count _maxavail - 1) do {
			_mname = _maxavail select _ee;
			_mmax = _maxavailnr select _ee;
			if !(_mname in _diffn) then {
				_diffn set [count _diffn, _mname];
				_idx = _removed find _mname;
				if (_idx != -1) then {
					_diffnnr set [count _diffnnr, _mmax - (_removednr select _idx)];
				} else {
					_diffnnr set [count _diffnnr, 0];
				};
			};
		};
		
		__TRACE_2("","_diffn","_diffnnr");

		if (!alive _object) exitWith {};

		for "_ee" from 0 to (count _removed - 1) do {
			_mname = _removed select _ee;
			_count = _removednr select _ee;
			if (_count > 0) then {
				_mag_disp_name = [_mname,2] call FUNC(GetDisplayName);
				if (_mag_disp_name == "") then {_mag_disp_name = _mname};
				if (!isDedicated) then {[_object, format [(localize "STR_DOM_MISSIONSTRING_702"), _mag_disp_name]] call FUNC(VehicleChat)};
				for "_zz" from 1 to _count do {
					sleep GVAR(reload_time_factor);
					if (!alive _object) exitWith {};
					_object addMagazineTurret [_mname, _thisTurret];
					_magspercent = (_magspercent - 1) max 0;
					if (!alive _object) exitWith {};
				};
			};
		};
		
		if (_magspercent == 0) exitWith {};		
		if (!alive _object) exitWith {};
		
		for "_ee" from 0 to (count _diffn - 1) do {
			_mname = _diffn select _ee;
			_count = _diffnnr select _ee;
			if (_count > 0) then {
				_mag_disp_name = [_mname,2] call FUNC(GetDisplayName);
				if (_mag_disp_name == "") then {_mag_disp_name = _mname};
				if (!isDedicated) then {[_object, format [(localize "STR_DOM_MISSIONSTRING_702"), _mag_disp_name]] call FUNC(VehicleChat)};
				for "_zz" from 1 to _count do {
					sleep GVAR(reload_time_factor);
					if (!alive _object) exitWith {};
					_object addMagazineTurret [_mname, _thisTurret];
					_magspercent = (_magspercent - 3) max 0;
					if (_magspercent == 0) exitWith {
						if (!isDedicated) then {[_object, (localize "STR_DOM_MISSIONSTRING_703")] call FUNC(VehicleChat)};
					};
					sleep GVAR(reload_time_factor);
					if (!alive _object) exitWith {};
				};
			};
			if (_magspercent == 0) exitWith {};
			if (!alive _object) exitWith {};
		};
		
		_cfgturrets = _cfgturrets select 0;
		[_turrets select (_i + 1), _thisTurret, _cfgturrets] call _reloadTurrets;
		_i = _i + 2;
		if (!alive _object) exitWith {};
	};
};

if (_magspercent != 0) then {
	if (count _turrets > 0) then {
		[_turrets, [], _cfgturrets] call _reloadTurrets;
	};
};

if (isServer) then {
	_trigger setVariable [QGVAR(magspercent), _magspercent, true];
};

if (!alive _object) exitWith {};

sleep GVAR(reload_time_factor);
if (!alive _object) exitWith {};
if (!isDedicated) then {[_object, (localize "STR_DOM_MISSIONSTRING_704")] call FUNC(VehicleChat)};
_object setDamage 0;
sleep GVAR(reload_time_factor);
if (!alive _object) exitWith {};
if (!isDedicated) then {[_object, (localize "STR_DOM_MISSIONSTRING_705")] call FUNC(VehicleChat)};
//while {fuel _object < _fuel_end} do {
	_object setFuel _fuel_end;
//	sleep 0.01;
	if (!alive _object) exitWith {};
//};
_trigger setVariable [QGVAR(fuelavailable), _fuelavailable, true];
if (!alive _object) exitWith {};
if (!isDedicated) then {[_object, format [(localize "STR_DOM_MISSIONSTRING_706"), _type_name]] call FUNC(VehicleChat)};

reload _object;

if (!isDedicated) then {
	[_object , format [(localize "STR_DOM_MISSIONSTRING_700"), round _fuelavailable, round _magspercent]] call FUNC(VehicleChat);
};