//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: -eutf-Myke
// Vehicle driver caching and SL cache check added by Wolffy.au
// Activation method inspired by RMM_Reducer
//////////////////////////////////////////////////////////////////

if (!isServer) exitwith {};
private ["_cep_leader", "_cep_grp", "_cep_unitarray", "_cep_typearray", "_cep_cache_dist"];
_cep_leader = _this select 0;
_cep_cache_dist = _this select 1;

_cep_leader = leader _cep_leader;
_cep_grp = group _cep_leader;

_cep_unitarray = units _cep_leader - [_cep_leader];
_cep_typearray = [];

fClosestUnit = {
	private["_units", "_unit", "_dist", "_udist"];
	_units = _this select 0;
	_unit = _this select 1;
	_dist = 10^5;

	{
		_udist = _x distance _unit;
		if (_udist < _dist) then {_dist = _udist;};
	} forEach _units;
	_dist;
};

waitUntil{typeName allUnits == "ARRAY"};
waitUntil{typeName playableUnits == "ARRAY"};

// player is not in playableUnits under Single Player mode
// This method ensures the player is always included
_playUnits = playableUnits + [player];

_exit = false;
while {!_exit} do {

	_disable = _cep_grp getVariable "crB_disableCache";
	_disable = if(isNil "_disable") then { false; } else {_disable;};

	_trigUnits = [];
	{
		if (side _x != civilian && side _cep_leader != civilian && side _x != side _cep_leader) then {
			_trigUnits = _trigUnits + [_x];
		};
	} forEach allUnits;
	_trigUnits = _trigUnits + _playUnits;

	sleep 3;
	if (!_disable && [_trigUnits, leader _cep_leader] call fClosestUnit > _cep_cache_dist + 15) then {
//hint "Out range";
		_cep_leader = leader _cep_grp;
		_cep_unitarray = (units _cep_leader) - [_cep_leader];
		{
			_cep_type = typeof _x;
			_cep_weap = weapons _x;
			_cep_mags = magazines _x;
			_cep_pos = _cep_leader worldtomodel position _x;
			_cep_veh = assignedVehicle _x;
			_cep_vehpos = assignedVehicleRole _x;
			if (!("Driver" in _cep_vehpos)) then {
//player sideChat format["%1,%2", _x, _cep_vehpos];
				unassignVehicle _x;
				doGetOut _x;
				waitUntil{unitReady _x};
//player sideChat format["%1", [_cep_type, _cep_weap, _cep_mags, _cep_pos, _cep_veh, _cep_vehpos]];
				_cep_typearray = _cep_typearray + [[_cep_type, _cep_weap, _cep_mags, _cep_pos, _cep_veh, _cep_vehpos]];
				deletevehicle _x;
				_x = objNull;
			};
		} foreach _cep_unitarray;
	};

	sleep 3;
//hint format["X: %1", [_trigUnits, leader _cep_leader] call fClosestUnit];
	if ((!_disable && ([_trigUnits, leader _cep_leader] call fClosestUnit < _cep_cache_dist)) || _disable) then {
//hint "In range";
		{
//player sideChat format["%1", _x];
			_cep_unit_init = _x select 0;
			_cep_unit_weap = _x select 1;
			_cep_unit_mags = _x select 2;
			_cep_unit_offset = _x select 3;
			_cep_unit_veh = _x select 4;
			_cep_unit_vehpos = _x select 5;
			_cep_unit_pos = _cep_leader modeltoworld _cep_unit_offset;
			_cep_myunit = (group _cep_leader) createUnit [_cep_unit_init, _cep_unit_pos, [], 0, "NONE"];
//player sideChat format["%1,%2", _cep_myunit, _cep_unit_vehpos];
/*
			removeallweapons _cep_myunit;
			removeAllItems _cep_myunit;
			{
				_cep_myunit addmagazine _x;
			} foreach _cep_unit_mags;
			{
				_cep_myunit addweapon _x;
			} foreach _cep_unit_weap;
*/
			if (count _cep_unit_vehpos != 0) then {
				switch(_cep_unit_vehpos select 0) do {
					case "Driver": {
						_cep_myunit moveInDriver _cep_unit_veh;
						_cep_myunit assignAsDriver _cep_unit_veh;
					};
					case "Cargo": {
						_cep_myunit moveInCargo _cep_unit_veh;
						_cep_myunit assignAsCargo _cep_unit_veh;
					};
					case "Turret": {
						_tp = _cep_unit_vehpos select 1;
						_cep_myunit moveInTurret [_cep_unit_veh, _tp];
						_cep_myunit assignAsGunner _cep_unit_veh;
					};
				};
			};
		} foreach _cep_typearray;
		_cep_typearray = [];
		if(_disable) then {
			cep_cached_grps = cep_cached_grps - [_cep_grp];
			_exit = true;
		};
	};
};

true;
