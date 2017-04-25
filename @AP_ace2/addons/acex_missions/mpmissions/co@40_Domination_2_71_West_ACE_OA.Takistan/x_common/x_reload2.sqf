// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_reload2.sqf"
#include "x_setup.sqf"
private ["_config","_count","_i","_magazines","_object","_type","_type_name"];

PARAMS_1(_object);
__TRACE_1("","_object");
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

_type = typeof _object;
__TRACE_2("","_object","_type");

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

#ifndef __TOH__
if (GVAR(reload_engineoff)) then {_object action ["engineOff", _object]};
#else
if (_object isKindOf "Helicopter_Base_H") then {
	[1, _object] call BIS_fnc_enginesOff;
	waitUntil {!(isBatteryOnRTD _object)};
};
#endif
if (!alive _object) exitWith {};
_object setFuel 0;

_type_name = [_type,0] call FUNC(GetDisplayName);
if (_type_name == "") then {_type_name = _type};
if (!isDedicated) then {[_object,format [(localize "STR_DOM_MISSIONSTRING_701"), _type_name]] call FUNC(VehicleChat)};

#ifdef __DEBUG__
_magazinesxx = _object magazinesTurret [0];
__TRACE_1("","_magazinesxx");
#endif

_cfgturrets = configFile >> "CfgVehicles" >> _type >> "Turrets";

__TRACE_1("","_cfgturrets");

_fillTurrets = {
	if (count _this < 1) exitWith {[]};
	private ["_entry", "_path"];
	PARAMS_3(_entry,_path,_object);
	if (typeName _entry != typeName configFile) exitWith {[]};
	private ["_turrets", "_turretIndex","_thisTurret"];
	_turrets = [];
	_turretIndex = 0;
	for "_i" from 0 to (count _entry - 1) do {
		private "_subEntry";
		_subEntry = _entry select _i;
		__TRACE_1("","_subEntry");
		if (isClass _subEntry) then {
			private "_hasGunner";
			_hasGunner = [_subEntry, "hasGunner"] call FUNC(returnConfigEntry);
			__TRACE_1("","_hasGunner");
			if (!isNil "_hasGunner") then {
				if (_hasGunner == 1) then {
					_thisTurret = _path + [_turretIndex];
					__TRACE_2("","_object","_thisTurret");
					private "_fullmags";
					_fullmags = getArray (_subEntry >> "magazines");
					__TRACE_2("","_subEntry","_fullmags");
					private "_magazinesx";
					__TRACE_1("mags cur","_magazinesx");
					_magazinesx = _object magazinesTurret _thisTurret;
					__TRACE_2("","_thisTurret","_magazinesx");
					private "_removedX";
					_removedX = [];
					{
						if !(_x in _removedX) then {
							_object removeMagazinesTurret [_x, _thisTurret];
							_removedX set [count _removedX, _x];
						};
					} forEach _magazinesx;
					__TRACE_1("","_removedX");
					if (!alive _object) exitWith {[]};
					{
						private "_mag_disp_name";
						_mag_disp_name = [_x,2] call FUNC(GetDisplayName);
						if (_mag_disp_name == "") then {_mag_disp_name = _x};
						if (!isDedicated) then {[_object,format [(localize "STR_DOM_MISSIONSTRING_702"), _mag_disp_name]] call FUNC(VehicleChat)};
						sleep GVAR(reload_time_factor);
						if (!alive _object) exitWith {[]};
						__TRACE_1("","_x");
						_object addMagazineTurret [_x, _thisTurret];
						sleep GVAR(reload_time_factor);
						if (!alive _object) exitWith {[]};
					} forEach _fullmags;
					if (!alive _object) exitWith {[]};
					_turrets set [count _turrets, _turretIndex];
					if (isClass (_subEntry >> "Turrets")) then {
						_turrets set [count _turrets, [_subEntry >> "Turrets",_thisTurret, _object] call _fillTurrets];
					} else {
						_turrets set [count _turrets, []];
					};
					if (!alive _object) exitWith {[]};
				};
				if (!alive _object) exitWith {[]};
			};
			__INC(_turretIndex);
			if (!alive _object) exitWith {[]};
		};
		if (!alive _object) exitWith {[]};
	};
	__TRACE_1("_fillTurrets","_turrets");
	_turrets
};

if (count _cfgturrets > 0) then {
	[_cfgturrets,[], _object] call _fillTurrets;
};

if (!alive _object) exitWith {};

_magazines = getArray(configFile >> "CfgVehicles" >> _type >> "magazines");
__TRACE_1("","_magazines");

if (count _magazines > 0) then {
	_removed = [];
	{
		if !(_x in _removed) then {
			_object removeMagazines _x;
			_removed set [count _removed, _x];
			__TRACE_1("remMag","_x");
		};
	} forEach _magazines;
	__TRACE_1("","_removed");
	{
		if (!isDedicated) then {[_object, format [(localize "STR_DOM_MISSIONSTRING_702"), _x]] call FUNC(VehicleChat)};
		sleep GVAR(reload_time_factor);
		if (!alive _object) exitWith {};
		_object addMagazine _x;
		__TRACE_1("addMag","_x");
	} forEach _magazines;
};
_object setVehicleAmmo 1;

if (!alive _object) exitWith {};

sleep GVAR(reload_time_factor);
if (!alive _object) exitWith {};
if (!isDedicated) then {[_object, (localize "STR_DOM_MISSIONSTRING_704")] call FUNC(VehicleChat)};
_object setDamage 0;
#ifdef __TOH__
if (_object iskindof "Heli_Light01_Base_H" || _object iskindof "Heli_Medium01_Base_H" || _object iskindof "Heli_Heavy_Base_H") then {
	_hitp = _object call BIS_fnc_helicopterGetHitpoints;
	if (count _hitp > 0) then {
		{
			if ((_object getHitPointDamage _x) != 0) then {
				_object setHitPointDamage [_x, 0];
			};
		} forEach _hitp;
	};
};
#endif
sleep GVAR(reload_time_factor);
if (!alive _object) exitWith {};
if (!isDedicated) then {[_object, (localize "STR_DOM_MISSIONSTRING_705")] call FUNC(VehicleChat)};
while {fuel _object < 0.99} do {
	_object setFuel 1;
	sleep 0.01;
};
sleep GVAR(reload_time_factor);
if (!alive _object) exitWith {};
if (!isDedicated) then {[_object, format [(localize "STR_DOM_MISSIONSTRING_706"), _type_name]] call FUNC(VehicleChat)};

#ifdef __TOH__
if (_object isKindOf "Helicopter_Base_H") then {
	[1, _object] call BIS_fnc_enginesOn;
};
#endif

reload _object;