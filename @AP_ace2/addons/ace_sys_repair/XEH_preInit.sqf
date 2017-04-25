// #define DEBUG_MODE_FULL
#include "script_component.hpp"

LOG(MSG_INIT);

PREP(action);
PREP(rearm);
PREP(reload);
PREP(repair);
PREP(refuel);
PREP(init);
PREP(setHit);

PREP(fill_turret_list);
PREP(fill_weapon_list);
PREP(add_magazine);
PREP(fill_compatible_magazines_list);
PREP(fill_current_magazines_list);
PREP(get_capacity);
PREP(get_current_magazines_turret);
FUNC(get_selected_data) = {
	private "_selection";
	PARAMS_1(_idc);
	_selection = (lbSelection GET_CTRL(_idc) select 0);
	if (isNil "_selection") then {_selection = 0};
	(GET_CTRL(_idc) lbData _selection)
};

FUNC(get_selected_turret) = {
	private ["_selection","_index_turret","_i"];
	_selection = (lbSelection GET_CTRL(66364) select 0);
	if (isNil "_selection") then {_selection = 0};
	_index_turret = [(GET_CTRL(66364) lbvalue _selection)];
	if (_index_turret select 0 <= -2) then {
		_i = _index_turret select 0;
		_index_turret = [round(-(_i+2)/10),(-(_i+2)+10*round((_i+2)/10))];
	};
	_index_turret
};
FUNC(get_selected_vehicle) = {
	private "_selection";
	_selection = (lbSelection GET_CTRL(66363) select 0);
	if (isNil "_selection") then {_selection = 0};
	((uiNamespace GetVariable QGVAR(vehlist)) select _selection)
};
FUNC(remove_magazine) = {
	private ["_veh","_magazine","_index_turret"];
	_veh = GET_SELECTED_VEHICLE;
	_magazine = GET_SELECTED_DATA(66369);
	_index_turret = GET_SELECTED_TURRET;
	if ((_veh isKindOf "Plane" || {_veh isKindOf "Helicopter"}) && {_index_turret select 0 < 1}) then {
		_veh removeMagazine _magazine;
	} else {
		_veh removeMagazineTurret [_magazine,_index_turret];
	};
	[] call FUNC(fill_current_magazines_list);
};

PREP(restore_loadout);
FUNC(ammo_info) = {
	private ["_ctrl","_index","_mag","_count","_displayName","_text"];
	disableSerialization;
	_ctrl = _this select 0 select 0;
	_index = _this select 0 select 1;
	_mag = _ctrl lbData _index;
	_count = getNumber(configFile >> "CfgMagazines">> _mag >> "count");
	_displayName = getText(configFile >> "CfgMagazines" >> _mag >> "displayName");
	_text = composeText [localize "STR_ACE_REP_DL_COUNT",str _count];
	GET_CTRL(66370) ctrlSetStructuredText _text;
};
FUNC(fill_transportMagazines) = {
	PARAMS_1(_veh);
	_indexWeapons = count (configFile >> "CfgVehicles" >> typeOf _veh >> "TransportWeapons");
	_indexMagazines = count (configFile >> "CfgVehicles" >> typeOf _veh >> "TransportMagazines"); 

	for "_j" from 0 to (_indexMagazines - 1) do {
		_item = getText (((configFile >> "CfgVehicles" >> typeOf _veh >> "TransportMagazines") select _j) >> "Magazine");
		_count = getNumber (((configFile >> "CfgVehicles" >> typeOf _veh >> "TransportMagazines") select _j) >> "count");
		[_veh, _item, _count] call ACE_fnc_removemagazinecargo;
		_veh addMagazineCargoGlobal [_item, _count];
	};
	for "_i" from 0 to (_indexWeapons - 1) do {
		_item = getText (((configFile >> "CfgVehicles" >> typeOf _veh >> "TransportWeapons") select _i) >> "Weapon");
		_count = getNumber (((configFile >> "CfgVehicles" >> typeOf _veh >> "TransportWeapons") select _i) >> "count");
		[_veh, _item, _count] call ACE_fnc_removeweaponcargo;
		_veh addWeaponCargoGlobal [_item, _count];
	};
};

FUNC(repair_tracks) = {
	private "_parts";
	PARAMS_1(_veh);
	if !(local _veh) exitWith {};
	_parts = [];
	switch (true) do {
		case (_veh isKindOf "Tank"): {
			_parts = ["ltrack","rtrack"];
		};
		case (_veh isKindOf "Wheeled_APC" || {_veh isKindOf "Car"}): {
			_parts = ["lfwheel","lf2wheel","lmwheel","lbwheel","rfwheel","rf2wheel","rmwheel","rbwheel"];
		};
		// TODO: Anything for other vehicle types?
	};
	{ [_veh, _x, 0] call FUNC(setHit) } forEach _parts;
	_veh setDamage 0;
};

FUNC(replaceTyre) = {
	PARAMS_3(_vehicle,_selection,_tyre);
	player setVariable ["ACE_PB_Result", 0];
	_time = if (_vehicle isKindOf "Wheeled_APC" && {_vehicle isKindOf "Car"}) then { 130 } else { 45 };
	[_time,[localize "STR_ACE_FIXTYRE"],false,true,player,true] spawn ace_progressbar;
	waitUntil { (player getVariable "ACE_PB_Result" != 0) };
	if (player getVariable "ACE_PB_Result" == 1) then {
		[QGVAR(replace_wheel), [_vehicle,_selection]] call CBA_fnc_globalEvent;
		deletevehicle _tyre; //delete the tyre
	};
	player setVariable ["ACE_PB_Result", 0];
};

// FUEL
// Fuel Can
// Transfer of Fuel, realFuelConsumption, carry jericans, cargo etc.
// TODO: Anything useful in fuelCargo etc?

#define MINIMUM_FUEL 0.1
#define TRANSFER_TIME 60

// Transfer fuel between two vehicles
FUNC(transferFuel) = {
	private ["_vehicleA", "_vehicleB", "_amount", "_fuelA", "_fuelB", "_typea", "_typeb", "_fuelCapacityA", "_fuelRealA", "_fuelToTransfer", "_fuelCapacityB", "_fuelRealB", "_fuelNeededB", "_exitFuel", "_iscan", "_amountB", "_transferTime"];
	PARAMS_2(_vehicleA,_vehicleB);
	DEFAULT_PARAM(2,_amount,0.1); // TODO: Support 'move all available fuel'?

	// _vehicleA = 
	
	_fuelA = fuel _vehicleA;
	_fuelB = fuel _vehicleB;

	// TODO: Locality/global events?

	_typea = typeOf _vehicleA;
	_typeb = typeOf _vehicleB;
	_fuelCapacityA = getNumber(configFile >> "CfgVehicles" >> _typea >> "fuelCapacity");
	_fuelRealA = _fuelA * _fuelCapacityA;
	_fuelToTransfer = _amount * _fuelCapacityA;

	_fuelCapacityB = getNumber(configFile >> "CfgVehicles" >> _typeb >> "fuelCapacity");
	_fuelRealB = _fuelB * _fuelCapacityB;
	_fuelNeededB = _fuelCapacityB - _fuelRealB;

	_exitFuel = false;
	_iscan = false;
	switch (true) do {
		case (_vehicleA isKindOf "ACE_JerryCan"): { // Filling fuel from can --> car
			if (_fuelA == 0) exitWith {
				hintSilent localize "STR_ACE_JERRYCAN_CAPACITY_EMPTY";
				_exitFuel = true;
			};
			_amountB = (_fuelCapacityA / _fuelCapacityB) * _fuelA;
			_fuelToTransfer = _fuelRealA;
			_amount = _fuelA;
			_iscan = true;
		};
		case (_vehicleB isKindOf "ACE_JerryCan"): {
			if (_fuelA == 0) exitWith {
				hintSilent localize "STR_ACE_JERRYCAN_CAPACITY_EMPTY";
				_exitFuel = true;
			};		
			_amountB = 1;
			_amount = (_fuelCapacityB / _fuelCapacityA) * (1 - _fuelB);
			_fuelToTransfer = (1 - _fuelB) * _fuelCapacityB;
			_iscan = true;
		};
		default {
			_amountB = (_fuelCapacityA / _fuelCapacityB) * _amount;
		};
	};

	if (_exitFuel) exitWith {};

	#define DSPN(typex) getText(configFile >> "CfgVehicles" >> typex >> "displayName")

	// Exit incase of too few fuel available
	if (!_iscan && {_fuelA < (_amount + MINIMUM_FUEL)}) exitWith {
		//hintSilent ("Not enough fuel available in " + DSPN(_typea) + "!");
	};

	// Exit incase of full already
	if (_fuelB >= 1) exitWith {
		hintSilent  (DSPN(_typeb) + " is already full!");
	};

	// Remove fuel from A - Removing this before the timer etc, so that the fuel can't be double tapped by another person at once
	[QGVAR(jfueladd), [_vehicleA, (_fuelA - _amount) max 0]] call ACE_fnc_receiverOnlyEvent;

	_transferTime = _amount * TRANSFER_TIME;
	hintSilent ("Working....Please wait! " + str(_transfer_time));
	sleep _transfer_time;

	// Add fuel to A
	[QGVAR(jfueladd), [_vehicleB, (_fuelB + _amountB) min 1]] call ACE_fnc_receiverOnlyEvent;

	hintSilent (str(round(_fuelToTransfer)) + " liter of fuel transferred from " + DSPN(_typea) + " to " + DSPN(_typeb) + "!");
};

FUNC(jerryCap) = {
	private ["_fuel", "_hint"];
	PARAMS_1(_jerry);
	_fuel = fuel _jerry;
	_hint = switch true do {
		case (_fuel < 0.25): { localize "STR_ACE_JERRYCAN_CAPACITY_EMPTY" };
		case (_fuel < 0.50): { localize "STR_ACE_JERRYCAN_CAPACITY_HALFFULL" };
		default { localize "STR_ACE_JERRYCAN_CAPACITY_FULL" };
	};
	hintSilent _hint;
};

// Real fuel consumption
//TODO: Could be done by config, but is permanently active (without resorting to mergeConfigFile etc) ?

#define FUEL_CONSUMPTION_PER_MINUTE 0.01
FUNC(realFuelConsumption) = {
	PARAMS_1(_unit);
	_consumption = FUEL_CONSUMPTION_PER_MINUTE / 60;
	// TODO: Convert to single script, with array of objects or so.
	while {true} do {
		_fuel = fuel _unit;
		_unit setFuel (_fuel - _consumption) max 0;
		sleep 1;
	};
};

// Transfer fuel between vehicle and jerrycan
FUNC(transferFuelFromJerrycan) = {
	PARAMS_2(_jerryCan,_vehicle);
	[_jerryCan, _vehicle] call FUNC(transferFuel);
};
// Transfer fuel between vehicle and jerrycan
FUNC(transferFuelToJerrycan) = {
	PARAMS_2(_vehicle,_jerryCan);
	[_vehicle, _jerryCan] call FUNC(transferFuel);
};

[QGVAR(rearm), { PARAMS_3(_veh,_remMags,_addMags); { _veh removeMagazine _x } forEach _remMags; { _veh addMagazine _x } forEach _addMags }] call CBA_fnc_addEventhandler;

[QGVAR(refuel), { PARAMS_2(_veh,_amount); _veh setFuel _amount }] call CBA_fnc_addEventhandler;
[QGVAR(repair_full), { _this call ace_sys_vehicledamage_fnc_fullrepair }] call CBA_fnc_addEventhandler;
[QGVAR(repair_part), { _this call ace_sys_vehicledamage_fnc_rep_tracks_n_wheels }] call CBA_fnc_addEventhandler;
[QGVAR(repair_tracks), { _this call FUNC(repair_tracks) }] call CBA_fnc_addEventhandler;
[QGVAR(sd), { PARAMS_2(_unit,_dam); if (local _unit) then { _unit setDamage _dam } }] call CBA_fnc_addEventhandler;
[QGVAR(replace_wheel), { (_this select 0) setHit [_this select 1,0] }] call CBA_fnc_addEventhandler;
if (isNil QGVAR(full)) then { GVAR(full) = false };


// Due to time probably desyncing from server, do the time math on each machine
// Do not send to JIP players - so there's a small hole - JIP players do not receive busy state on join
// Which seems to be a small price to pay for fixing 'disconnecting players during repair will block the vehicle forever from repair'..
[QGVAR(setBusyRep), { PARAMS_2(_unit,_addTime); _unit setVariable [QGVAR(repair_busy), true]; _unit setVariable [QGVAR(repair_busyState), time + _addTime] }] call CBA_fnc_addEventhandler;
[QGVAR(unsetBusyRep), { PARAMS_1(_unit); _unit setVariable [QGVAR(repair_busy), false]; _unit setVariable [QGVAR(repair_busyState), 0] }] call CBA_fnc_addEventhandler;

[QGVAR(setBusyRef), { PARAMS_2(_unit,_addTime); _unit setVariable [QGVAR(refuel_busy), true]; _unit setVariable [QGVAR(refuel_busyState), time + _addTime] }] call CBA_fnc_addEventhandler;
[QGVAR(unsetBusyRef), { PARAMS_1(_unit); _unit setVariable [QGVAR(refuel_busy), false]; _unit setVariable [QGVAR(refuel_busyState), 0] }] call CBA_fnc_addEventhandler;

[QGVAR(setBusyRea), { PARAMS_2(_unit,_addTime); _unit setVariable [QGVAR(rearm_busy), true]; _unit setVariable [QGVAR(rearm_busyState), time + _addTime] }] call CBA_fnc_addEventhandler;
[QGVAR(unsetBusyRea), { PARAMS_1(_unit); _unit setVariable [QGVAR(rearm_busy), false]; _unit setVariable [QGVAR(rearm_busyState), 0] }] call CBA_fnc_addEventhandler;

//TODO: Replace refuel event with this one ?
// setFuel does only work where the vehicle is local anyway!
[QGVAR(jfueladd), {(_this select 0) setFuel (_this select 1)}] call ACE_fnc_addReceiverOnlyEventhandler;