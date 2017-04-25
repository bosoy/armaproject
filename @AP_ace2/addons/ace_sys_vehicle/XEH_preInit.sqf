#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

PREP(hind_cargo);
PREP(hind_getinout);
PREP(bicycle);
PREP(tracer);
PREP(40mm_tracer);

PREP(findwmmclass);
PREP(gatling_spinup);
PREP(shadow_weapon);
PREP(tank_loader);

if (isNil QGVAR(limit_crew_weapons)) then { GVAR(limit_crew_weapons) = false };
if (isNil QGVAR(limit_crew_weapons_incl_ai)) then { GVAR(limit_crew_weapons_incl_ai) = false };
if (isNil QGVAR(limit_crew_weapons_ai_auto)) then { GVAR(limit_crew_weapons_ai_auto) = true };

FUNC(putWeaponInCargo) = {
	private ["_ar", "_nar"];
	PARAMS_3(_vehicle,_unit,_weapon);
	// TODO: Consider using the DROPWEAPON/PUTWEAPON actions instead? Any reason to?
	_unit removeWeapon _weapon;
	_vehicle addWeaponCargo [_weapon, 1];
	//_ar = _unit getVariable [QGVAR(weapon_cargo), []];
	//_nAr = [_vehicle, _weapon];
	//PUSH(_ar,_nAr); // always set, in case of default value.
};

// TODO: Proper AutoPilot / Trimming (fake) system 
// TODO: For now also Ka50 gets Hover to be useful with the FCS stuff
FUNC(vtol) = {
	private ["_VTOL","_VTOL_TRIM","_id0","_id1"];
	PARAMS_1(_vehicle);
	//_VTOL = getNumber(configFile >> "CfgVehicles" >> typeOf _vehicle >> "vtol") in [1,3];
	//_VTOL_TRIM = getNumber(configFile >> "CfgVehicles" >> typeOf _vehicle >> "vtol_trim") == 1; // TODO: better
	
	//if (true) then {
		_id0 = _vehicle addAction [localize "str_action_hover", QPATHTO_F(fnc_exec), ["vtol"], 6, false, false, "Autohover", "alive _target && {driver _target == player} && {isEngineOn _target} && {!(_target getVariable ['ace_sys_vehicle_vtolon',false])}"];
		_id1 = _vehicle addAction [localize "str_action_hover_cancel", QPATHTO_F(fnc_exec), ["vtol"], 6, false, false, "Autohover", "alive _target && {driver _target == player} && {(_target getVariable ['ace_sys_vehicle_vtolon',false])}"];
	//} else {
	//	if (_VTOL_TRIM) then {
	//		_id0 = _vehicle addAction [localize "str_action_hover", QPATHTO_F(fnc_exec), ["vtol"], 6, false, false, "Autohover", "alive _target && {driver _target == player} && {!(_target getVariable ['ace_sys_vehicle_vtolon',false])} && {speed _target > 1} && {speed _target < 35}"];
	//		_id1 = _vehicle addAction [localize "str_action_hover_cancel", QPATHTO_F(fnc_exec), ["vtol"], 6, false, false, "Autohover", "alive _target && {driver _target == player} && {(_target getVariable ['ace_sys_vehicle_vtolon',false])}"];
	//	};
	//};
};

FUNC(getOutCrew) = {
	PARAMS_3(_vehicle,_position,_unit);

	if !(GVAR(limit_crew_weapons)) exitWith {}; // System is disabled
	if !(GVAR(limit_crew_weapons_incl_ai)) exitWith {}; // System is disabled for AI
	if !(GVAR(limit_crew_weapons_ai_auto)) exitWith {}; // Optional

	if !(alive _vehicle) exitWith {};
	if !(alive _unit) exitWith {};
	if (isPlayer _unit) exitWith {}; // Only for AI

	// TODO: Check if the weapon is in the actual vehicle
	_this spawn {
		private ["_ar", "_wVehicle", "_weapon"];
		PARAMS_3(_vehicle,_position,_unit);
		sleep 5;
		if !(alive _vehicle) exitWith {};
		if !(alive _unit) exitWith {};
		if (isPlayer _unit) exitWith {}; // Only for AI

		// SecondaryWeapon
		_ar = _unit getVariable [QGVAR(weapon_cargo), []];
		if (count _ar > 0) then {
			_wVehicle = _ar select 0;
			if (_wVehicle != _vehicle) exitWith {};
			_weapon = _ar select 1;
			if (secondaryWeapon _unit == "") then {
				// _vehicle removeWeaponCargo [_weapon, 1];
				_unit addWeapon _weapon;
			};
			_unit setVariable [QGVAR(weapon_cargo), []];
		};

		// WeaponOnBack
		_ar = _unit getVariable [QGVAR(weapon_cargo_wob), []];
		if (count _ar > 0) then {
			_wVehicle = _ar select 0;
			if (_wVehicle != _vehicle) exitWith {};
			_weapon = _ar select 1;
			if (_unit getVariable ["ACE_weapononback",""] == "") then {
				// _vehicle removeWeaponsCargo [_weapon, 1];
				_unit getVariable ["ACE_weapononback",_weapon];
			};
			_unit setVariable [QGVAR(weapon_cargo_wob), []];
		};
	};
};

FUNC(getInCrew) = {
	private ["_done", "_secWep", "_wob"];
	PARAMS_3(_vehicle,_position,_unit);
	if !(GVAR(limit_crew_weapons)) exitWith {}; // System is disabled
	if !(local _unit) exitWith {};
	if (!GVAR(limit_crew_weapons_incl_ai) && {!isPlayer _unit}) exitWith {}; // By default, only for players.
	if !(_position in ["driver", "gunner", "commander"]) exitWith {}; // Returns "gunner" for Loaders and fronthull left/right gunners etc
	_done = false;

	// Seconadry Weapons - Launchers. Rucksacks excluded for now
	// TODO: check for the size of the weapon, perhaps allow LAW/RPG18 etc?
	_secWep = secondaryWeapon _unit;
	if (_secWep != "") then {
		if !([_secWep] call ace_sys_weapons_fnc_getType == 4094) then {
			[_vehicle, _unit, _secWep] call FUNC(putWeaponInCargo);
			_unit setVariable [QGVAR(weapon_cargo), [_vehicle, _secWep]];
			_done = true;
		};
	};

	// Weapon On Back (sys_ruck feature)
	_wob = _unit getVariable ["ACE_weapononback",""]; // TODO: Shouldn't there be a Ruck API for this?
	if (_wob != "") then {
		_vehicle addWeaponCargo [_wob, 1];
		_unit setVariable [QGVAR(weapon_cargo_wob), [_vehicle, _wob]];
		_unit setVariable ["ACE_weapononback",""];
		_done = true;
	};

	// TODO: Heavy Sniper Rifles ?
	// TODO: Heavy Machine Guns ?

	if (_done && {_unit == player}) then { hintSilent "Some weapons dropped in vehicle cargo" };
};

FUNC(gatling) = {
	PARAMS_3(_vehicle,_animation,_phase);
	if !(local _vehicle) exitWith {};
	_vehicle animate [_animation,(_vehicle animationPhase _animation) + _phase];
};

ADDON = true;
