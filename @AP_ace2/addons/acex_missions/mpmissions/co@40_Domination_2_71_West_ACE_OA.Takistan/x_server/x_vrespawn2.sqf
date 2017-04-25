// by Xeno
#define THIS_FILE "x_vrespawn2.sqf"
#include "x_setup.sqf"

#define __Trans(tkind) _trans = getNumber(configFile >> #CfgVehicles >> typeOf _vehicle >> #tkind)
private ["_vehicle", "_camotype", "_camo", "_i", "_disabled", "_trans", "_empty", "_outb", "_hasbox", "_fuelleft"];
if (!isServer) exitWith{};

_vec_array = [];
{
	_vehicle = _x select 0;
	_number_v = _x select 1;
	_vec_array set [count _vec_array, [_vehicle,_number_v,position _vehicle,direction _vehicle,typeOf _vehicle]];
	
	_vehicle setVariable [QGVAR(OUT_OF_SPACE), -1];
	_vehicle setVariable [QGVAR(vec), _number_v, true];
	_vehicle setAmmoCargo 0;
	_vehicle setVariable [QGVAR(vec_islocked), (_vehicle call d_fnc_isVecLocked)];
	_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(fuelCheck)}}];
	#ifdef __TT__
	if (_number_v < 100) then {
		_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(checkveckillwest)}}];
	} else {
		_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(checkveckilleast)}}];
	};
	#endif
	if (_number_v < 10 || (_number_v > 99 && _number_v < 110)) then {
		_vehicle addMPEventhandler ["MPKilled", {(_this select 0) call FUNC(MHQFunc)}];
	};
	
	#ifndef __CARRIER__
	if (GVAR(with_base_camonet) == 0) then {
		_camotype = switch (getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "side")) do {
			case 1: {
				switch (true) do {
					case (__OAVer): {"Land_CamoNetB_NATO_EP1"};
					case (__COVer): {"Land_CamoNetB_NATO"};
				}
			};
			case 0: {
				switch (true) do {
					case (__OAVer): {"Land_CamoNetB_EAST_EP1"};
					case (__COVer): {"Land_CamoNetB_EAST"};
				};
			};
		};
		_camo = createVehicle [_camotype, position _vehicle, [], 0, "NONE"];
		_camo setDir (direction _vehicle) + 180;
		_camo setPos position _vehicle;
		_vehicle setVariable [QGVAR(camonet), _camo];
	};
	#endif
} forEach _this;
_this = nil;

//sleep 65;
sleep 5;

while {true} do {
	sleep 8 + random 5;
	__MPCheck;
	{
		_vec_a = _x;
		_vehicle = _vec_a select 0;
		
		_disabled = false;
		if (damage _vehicle > 0.9) then {
			_disabled = true;
		} else {
			__Trans(transportAmmo);
			if (_trans > 0) then {
				_vehicle setAmmoCargo 1;
			};
			__Trans(transportRepair);
			if (_trans > 0) then {
				_vehicle setRepairCargo 1;
			};
			__Trans(transportFuel);
			if (_trans > 0) then {
				_vehicle setFuelCargo 1;
			};
		};
		
		_empty = _vehicle call FUNC(GetVehicleEmpty);
		
#ifdef __ACE__
		_aliveve = if (!isNil {_vehicle getVariable "ace_canmove"}) then {_vehicle call ace_v_alive} else {alive _vehicle};
#else
		_aliveve = alive _vehicle;
#endif

		if (_empty && !_disabled && _aliveve && (_vehicle call FUNC(OutOfBounds))) then {
			_outb = _vehicle getVariable QGVAR(OUT_OF_SPACE);
			if (_outb != -1) then {
				if (time > _outb) then {_disabled = true};
			} else {
				_vehicle setVariable [QGVAR(OUT_OF_SPACE), time + 600];
			};
		} else {
			_vehicle setVariable [QGVAR(OUT_OF_SPACE), -1];
		};
		
		sleep 0.01;

		if ((_disabled && _empty) || (_empty && !_aliveve)) then {
			_number_v = _vec_a select 1;
			_hasbox = GV(_vehicle,GVAR(ammobox));
			if (isNil "_hasbox") then {_hasbox = false};
			_fuelleft = GV(_vehicle,GVAR(fuel));
			if (isNil "_fuelleft") then {_fuelleft = 1};
			if (_hasbox) then {[QGVAR(num_ammo_boxes),__XJIPGetVar(GVAR(num_ammo_boxes)) - 1] call FUNC(NetSetJIP)};
			if (_number_v < 10 || (_number_v > 99 && _number_v < 110)) then {
				_dhqcamo = GV(_vehicle,GVAR(MHQ_Camo));
				if (isNil "_dhqcamo") then {_dhqcamo = objNull};
				if (!isNull _dhqcamo) then {deleteVehicle _dhqcamo};
			};
#ifndef __CARRIER__
			if (GVAR(with_base_camonet) == 0) then {
				_camo = GV(_vehicle,GVAR(camonet));
				if (isNil "_camo") then {_camo = objNull};
				if (!isNull _camo) then {deleteVehicle _camo;_camo = objNull} else {_camo = objNull};
			};
#endif
			_isitlocked = _vehicle getVariable QGVAR(vec_islocked);
			sleep 0.1;
			deletevehicle _vehicle;
			sleep 0.5;
			_vehicle = objNull;
			_vehicle = createVehicle [_vec_a select 4, _vec_a select 2, [], 0, "NONE"];
			_vehicle setdir (_vec_a select 3);
#ifndef __CARRIER__
			_vehicle setpos (_vec_a select 2);
#else
			if (_number_v > 9) then {
				_vehicle setPos (_vec_a select 3);
			} else {
				_vehicle setPosASL [(_vec_a select 2) select 0, (_vec_a select 2) select 1, 15.9];
			};
#endif
			_vehicle setFuel _fuelleft;
			
			_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(fuelCheck)}}];
			
			if (_number_v < 10 || (_number_v > 99 && _number_v < 110)) then {
				_vehicle addMPEventhandler ["MPKilled", {(_this select 0) call FUNC(MHQFunc)}];
			};
			_vec_a set [0, _vehicle];
			_vec_array set [_forEachIndex, _vec_a];
			_vehicle setVariable [QGVAR(OUT_OF_SPACE), -1];
			_vehicle setVariable [QGVAR(vec), _number_v, true];
			_vehicle setAmmoCargo 0;
			_vehicle setVariable [QGVAR(vec_islocked), _isitlocked];
			if (_isitlocked) then {_vehicle lock true};
			[QGVAR(n_v), _vehicle] call FUNC(NetCallEventToClients);
			
#ifdef __TT__
			if (_number_v < 100) then {
				_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(checkveckillwest)}}];
			} else {
				_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(checkveckilleast)}}];
			};
#endif
#ifndef __CARRIER__
			if (GVAR(with_base_camonet) == 0) then {
				if (isNull _camo) then {
					_camotype = switch (getNumber (configFile >> "CfgVehicles" >> typeOf _vehicle >> "side")) do {
						case 1: {
							switch (true) do {
								case (__OAVer): {"Land_CamoNetB_NATO_EP1"};
								case (__COVer): {"Land_CamoNetB_NATO"};
							}
						};
						case 0: {
							switch (true) do {
								case (__OAVer): {"Land_CamoNetB_EAST_EP1"};
								case (__COVer): {"Land_CamoNetB_EAST"};
							};
						};
					};
					_camo = createVehicle [_camotype, position _vehicle, [], 0, "NONE"];
					_camo setDir (direction _vehicle) + 180;
					_camo setPos position _vehicle;
					_vehicle setVariable [QGVAR(camonet), _camo];
				};
			};
#endif
		};
		sleep 8 + random 5;
	} forEach _vec_array;
};