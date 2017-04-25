//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: -eutf-Myke
// Vehicle driver caching and SL cache check added by Wolffy.au
//////////////////////////////////////////////////////////////////

if (!isServer) exitwith {};
waitUntil{cep_init_done};
private ["_cep_leader", "_cep_unitarray", "_cep_typearray", "_cep_cache_dist"];
_cep_leader = _this select 0;
_cep_cache_dist = _this select 1;
sleep 20;
_cep_leader = leader _cep_leader;
_cep_grp = group _cep_leader;

if (_cep_grp in cep_cached_grps) exitWith{};
cep_cached_grps = cep_cached_grps + [_cep_grp];

_cep_unitarray = units _cep_leader - [_cep_leader];
_cep_typearray = [];

while {true} do {

	//waituntil {sleep 5;((cep_playerside countside (position _cep_leader nearobjects ["AllVehicles", (_cep_cache_dist + 15)])) == 0)};
	if (((cep_playerside countside (position _cep_leader nearobjects ["AllVehicles", (_cep_cache_dist + 15)])) == 0)) then {
		//	hint "Out range";
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
	//			player sideChat format["%1,%2", _x, _cep_vehpos];
				doGetOut _x;
				waitUntil{unitReady _x};
				_cep_typearray = _cep_typearray + [[_cep_type, _cep_weap, _cep_mags, _cep_pos, _cep_veh, _cep_vehpos]];
				deletevehicle _x;
				_x = objNull;
			};
		} foreach _cep_unitarray;
	};

//	waituntil {sleep 1;((cep_playerside countside (position _cep_leader nearobjects ["AllVehicles", _cep_cache_dist])) != 0)};
	if (((cep_playerside countside (position _cep_leader nearobjects ["AllVehicles", _cep_cache_dist])) != 0)) then {
		//	hint "In range";
		{
			_cep_unit_init = _x select 0;
			_cep_unit_weap = _x select 1;
			_cep_unit_mags = _x select 2;
			_cep_unit_offset = _x select 3;
			_cep_unit_veh = _x select 4;
			_cep_unit_vehpos = _x select 5;
			_cep_unit_pos = _cep_leader modeltoworld _cep_unit_offset;
			_cep_myunit = _cep_unit_init createunit [_cep_unit_pos, group _cep_leader, "this addeventhandler [""killed"", {_this call cep_fBody_remover}]"];
			removeallweapons _cep_myunit;
			removeAllItems _cep_myunit;
			{
				_cep_myunit addmagazine _x;
			} foreach _cep_unit_mags;
			{
				_cep_myunit addweapon _x;
			} foreach _cep_unit_weap;
	//		player sideChat format["%1,%2", _cep_myunit, _cep_unit_vehpos];
			if (count _cep_unit_vehpos != 0) then {
				switch(_cep_unit_vehpos select 0) do {
					case "Driver": {
						_cep_myunit moveInDriver _cep_unit_veh;
					};
					case "Cargo": {
						_cep_myunit moveInCargo _cep_unit_veh;
					};
					case "Turret": {
						_tp = _cep_unit_vehpos select 1;
						_cep_myunit moveInTurret [_cep_unit_veh, _tp];
					};
				};
			};
		} foreach _cep_typearray;
		_cep_typearray = [];
	};
	sleep 2;
};
