//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;

PREP(checkMountCrewMG);
PREP(checkNearCrewMG);
PREP(checkPickupTripod);

PREP(drag);
PREP(load);
PREP(unload);
PREP(mount);
PREP(unmount);
PREP(unmount_parts);
PREP(rotate);
PREP(pitch);
PREP(getIn);
PREP(elevate);
PREP(swap_barrel);

GVAR(CSW_ACTIONS) = [ACE_CSW_ACTIONS];

[QGVAR(remadd), { PARAMS_3(_veh,_addMag,_va); _veh setVehicleAmmo 0; _veh addMagazine _addMag; _veh setVehicleAmmo _va }] call CBA_fnc_addEventHandler;
[QGVAR(sva), { PARAMS_2(_veh,_va); _veh setVehicleAmmo _va }] call CBA_fnc_addEventHandler;
[QGVAR(rem), { PARAMS_2(_veh,_mag); _veh removeMagazine _mag }] call CBA_fnc_addEventHandler;
[QGVAR(rem), { PARAMS_2(_veh,_mag); _veh removeMagazine _mag }] call CBA_fnc_addEventHandler;
[QGVAR(noam), { PARAMS_1(_veh); _veh setVehicleAmmo 0}] call CBA_fnc_addEventHandler;

[QGVAR(remMagTur), { PARAMS_3(_vehicle,_magazine,_tp); _vehicle removeMagazineTurret [_magazine, _tp] }] call CBA_fnc_addEventhandler;
[QGVAR(addMagTur), { PARAMS_4(_vehicle,_magazine,_tp,_amount); for "_i" from 1 to _amount do { _vehicle addMagazineTurret [_magazine, _tp] }; }] call CBA_fnc_addEventhandler;

FUNC(busy) = { _this getVariable [QGVAR(busy), false] };

FUNC(setbusy) = {
	PARAMS_2(_mg,_state);
	_mg setVariable [QGVAR(busy), _state, true];
};

#define CFG configFile >> "CfgMagazines" >> _magazine >> "ACE" >> "ACE_CREWSERVED" >> "ACE_magXchange"
FUNC(fired) = {
	if ((_this select 0) ammo (_this select 2) > 0) exitWith {};
	private ["_magazine"];
	_magazine = _this select 5;
	if !(isText(CFG)) exitWith {};

	_this spawn {
		PARAMS_7(_unit,_weapon,_muzzle,_mode,_ammo,_magazine,_projectile);
		_mag = getText(CFG);												// TODO: Alternative magazines found!
		TRACE_1("Magazine to reload",_mag);
		_reloadtime = getNumber(configFile >> "CfgVehicles" >> typeOf _unit >> "ACE" >> "ACE_CREWSERVED" >> "reloadtime");
		if (_mag in ((getMagazineCargo _unit) select 0)) then {
			TRACE_1("Changing magazine","");
			[(vehicle _unit),_mag,1] call ACE_fnc_removemagazinecargo;
			_tp = [(vehicle _unit), _weapon] call CBA_fnc_getFirer;
			_unit addMagazineTurret [_magazine, (_tp select 1)];
			sleep (_reloadtime + 2);	// TODO: If bug confirmed and ammotrucks do reload AI (patch?) then CSWDM reload needs to be aborted or quicker than engine does reloading
			reload _unit;
		} else {
			// Check if soldier unit has magazine in gear
			if (_mag in (magazines gunner _unit)) then {					// TODO: Alternative magazines found!
				TRACE_1("Changing magazine from gunner gear","");
				(gunner _unit) removeMagazine _mag;
				_tp = [(vehicle _unit), _weapon] call CBA_fnc_getFirer;
				_unit addMagazineTurret [_magazine, (_tp select 1)];
				sleep (_reloadtime + 2);
				reload _unit;
			} else {
				// Out of ammo?
				// Check if its being reloaded
				sleep (_reloadtime + 5); // BUG: Ammotrucks don't seem to reload AI guns?
				if ((typeOf vehicle _unit) isKindOf "StaticWeapon" && !(_unit ammo _muzzle > 0)) then {
					TRACE_1("Static weapon out of ammo - Exiting static weapon","");
					moveOut (gunner vehicle _unit);
				};
			};
		};
	};
};

FUNC(swapFireReload) = {
	private ["_current"];
	PARAMS_1(_unit);
	_current = _unit getVariable [QGVAR(fireReload), false];
	if (_current) then {
		hintSilent "Fire on Load: Disabled";
	} else {
		hintSilent "Fire on Load: Enabled";
	};
	_unit setVariable [QGVAR(fireReload), !_current,true];
};

// We want to be able to exchange magazines from vehicles. Vehicle 2 Vehicle, Man 2 Vehicle and Vehicle 2 Man.
// We also want to be able to convert the magazines between different weapon types like vehicle M240 to man M240 etc.
// TODO: Locality
// TODO: Protection? First the action needs to take like 10 seconds, and only exzchange on completion,
// second; perhaps only possible when inside the tank, or friendly to tank

#define C_MAGAZINE configFile >> "CfgMagazines"
#define C_WEAPON configFile >> "CfgWeapons"

FUNC(partialMagazines) = {
	// [_unit, [["mag_a", "m240", "m240", [200,100,50]]]];
	PARAMS_2(_unit,_magazines);

	//Create a dummy
	_dummy = createAgent ["ACE_CivDummy", getPos _unit, [], 0, "FORM"]; // [10,10,0]
	waitUntil { alive _dummy };
	TRACE_1("Dummy",_dummy);

	_unit reveal _dummy;
	_dummy reveal _unit;

	{
		_x disableAI "TARGET";
		_x disableAI "AUTOTARGET";
		_x disableAI "MOVE";
		_x disableAI "ANIM";
	} foreach [_dummy];

	{
		_mag = _x select 0;
		_weap = _x select 1;
		_muzzle = _x select 2;
		removeAllWeapons _dummy;
		{
			_dummy removeWeapon _weap;
			_dummy addMagazine _mag;
			_dummy addWeapon _weap;
			_dummy selectWeapon _muzzle;
			waitUntil {_dummy ammo _muzzle > 0};
			_count = _dummy ammo _muzzle;
			_multiplier = _x / _count;
			TRACE_3("Dropping",_unit,_count,_multiplier);
			_dummy setVehicleAmmo _multiplier;
			if (_unit isKindOf "CAManBase") then {
				_unit action ["TAKEMAGAZINE", _dummy, _mag];
			} else {
				// Doesn't work well atm??
				// _dummy action ["DROPMAGAZINE", _unit, _mag];
				_dummy action ["DROPMAGAZINE", _dummy, _mag];
				//_unit action ["TAKEMAGAZINE", _dummy, _mag];
			};
			waituntil { count (magazines _dummy) == 0 };
			TRACE_1("Pass over",_dummy);
		} forEach (_x select 3);
	} forEach _magazines;
	_dummy setDamage 1;
	deleteVehicle _dummy;
};

// add dummyweapon to dummy
// take the magazine from unit, give to dummy
// do the ammocount
// return the magazine to unit
// return the ammoCount for the magazine
FUNC(countMagazine) = {
	// [_unit, _weapon, _muzzle, _magazine];
	PARAMS_4(_unit,_weapon,_muzzle,_magazine);

	// Workaround
	if (getNumber(C_MAGAZINE >> _magazine >> "count") == 1) exitWith {
		1
	};

	//Create a dummy
	_dummy = createAgent ["ACE_CivDummy", getPos _unit, [], 0, "FORM"]; // [10,10,0]
	waitUntil { alive _dummy };
	TRACE_1("Dummy",_dummy);

	removeAllWeapons _dummy;

	_unit reveal _dummy;
	_dummy reveal _unit;

	{
		_x disableAI "TARGET";
		_x disableAI "AUTOTARGET";
		_x disableAI "MOVE";
		_x disableAI "ANIM";
	} foreach [_dummy];

	// Take Mag
	//_dummy action ["TAKEMAGAZINE", _unit, _magazine];
	_unit action ["DROPMAGAZINE", _dummy, _magazine];
	TRACE_2("Taking",_magazine,_unit);
	waitUntil {count (magazines _dummy) > 0};
	_dummy removeWeapon _weapon;
	_dummy addWeapon _weapon;
	_dummy selectWeapon _muzzle;
	_ammoCount = _dummy ammo _muzzle;

	// Give mag back
	// TODO: Will this magazine be the new first magazine that we remove in MagazineToVehicle???
	// Or do we need some extra processing?
	_mc = count (magazines _unit);
	// _unit action ["TAKEMAGAZINE", _dummy, _magazine];
	_dummy action ["DROPMAGAZINE", _unit, _magazine];
	TRACE_2("Givingback",_magazine,_unit);
	waitUntil {_mc != (count magazines _unit)};
	if (_unit hasWeapon _weapon && !(_weapon in ["Throw", "Put"])) then {
		_unit removeWeapon _weapon;
		_unit addWeapon _weapon;
		_unit selectWeapon _muzzle;
	};
	TRACE_1("Pass over",_dummy);

	_dummy setDamage 1;
	deleteVehicle _dummy;

	// return data
	_ammoCount;
};

// [_vehicle, "M240_Veh", "1200Rnd_762x51_M240", player, [0]] call ace_sways_crewserved_fnc_exchangeMagazineFromVehicle;
FUNC(exchangeMagazineFromVehicle) = {
	PARAMS_5(_vehicle,_weapon,_magazine,_unit,_tp);
	_ammoCount = _vehicle ammo _weapon;

	// Sweet workaround for no ammoTurret command;
	// If player is inside the turret, we can check _unit ammo _weap!
	if (_ammoCount == 0 && {_unit in _vehicle}) then {
		_ammoCount = _unit ammo _weapon;
	};

	if (_ammoCount == 0) exitWith {
		TRACE_1("No Ammo",_weapon);
		false;
	};

	_curCount = getNumber(C_MAGAZINE >> _magazine >> "count");

	_replMag = getText(C_MAGAZINE >> _magazine >> "ACE" >> "ACE_CREWSERVED" >> "ACE_magXchange");
	if (_replMag == "this") then { _replMag = _magazine };
	_replCount = getNumber(C_MAGAZINE >> _replMag >> "count");
	TRACE_3("",_ammoCount,_replCount,_curCount);

	if (_ammoCount > _curCount) then {
		// Wrong magazine currently loaded // no currentMagazineTurret yet :/
		// TODO: Should we abort here?
		// So the user needs to load the magazine as current magazine of the vehicle, before being able to take it?
		TRACE_3("Current ammo count higher than mag cap!",_vehicle,_ammoCount,_curCount);
		_ammoCount = _curCount;
	};

	//if (_unit in (crew _vehicle)) then {
		if ((currentMagazine _vehicle) != _magazine) then { // need currentMagazineTurret?
			TRACE_3("Current magazine differs!",_vehicle,currentMagazine _vehicle,_magazine);
		};
	//};

	_holder = "WeaponHolder" createVehicle (getPos player);

	// get the needed dummy weapon+muzzle to count the magazine
	_cfg = C_MAGAZINE >> _replMag;
	_weap = if (isText(_cfg >> "ACE" >> "ACE_CREWSERVED" >> "ace_magXchange_wep")) then { getText(_cfg >> "ACE" >> "ACE_CREWSERVED" >> "ace_magXchange_wep") } else { "Put" }; // Dummy mags seem to be hooked to Put..
	_cfg = C_WEAPON >> _weap;
	_muzzle = _weap;
	if !(_replMag in getArray(_cfg >> "magazines")) then {
		_muzzles = getArray(_cfg >> "muzzles") - ["this"];
		{
			if (_replMag in (getArray(_cfg >> _x >> "magazines"))) exitWith {
				_muzzle = _x;
			};
		} forEach _muzzles;
	};

	TRACE_3("Removing magazine from vehicle", _vehicle, _magazine,_tp);
	if (local _vehicle) then {
		_vehicle removeMagazineTurret [_magazine, _tp];
	} else {
		[QGVAR(remMagTur), [_vehicle,_magazine,_tp]] call CBA_fnc_globalEvent;
	};

	if (_ammoCount >= _replCount) then {
		_amount = floor(_ammoCount / _replCount);

		// TODO: LeftOver - once we use a dummy unit!
		_leftOver = _ammoCount - (_amount * _replCount);
		if (_leftOver > 0) then {
			_modifier = (_leftOver / _replCount);
			TRACE_4("Adding leftOver",_unit,_replMag,_modifier,_leftOver);
			// Add leftOver
			[ _holder, [ [_replMag,_weap,_muzzle, [_leftOver]] ] ] call FUNC(partialMagazines);
		};

		// Add fullMags
		TRACE_3("Adding fullmags",_holder,_replMag,_amount);
		_str = if(_leftOver > 0) then { ", and 1 mag with %4 projectiles" } else { "" };
		hintSilent format[("Unloaded %1 of %2 magazines out of %3" + _str+" from %5"), _amount,getText(C_MAGAZINE >> _replMag >> "displayName"), getText(C_WEAPON >> _weapon >> "displayName"),_leftOver,getText([_vehicle,_tp] call CBA_fnc_getTurret >> "gunnerName")];
		_holder addMagazineCargoGlobal [_replMag, _amount];
		_success = true;
	} else {
		_modifier = (_ammoCount / _replCount);
		TRACE_3("Adding",_holder,_replMag,_modifier);
		hintSilent format["Unloaded 1 mag with %1 projectiles out of %2 from %3", _ammoCount,getText(C_WEAPON >> _weapon >> "displayName"), getText([_vehicle,_tp] call CBA_fnc_getTurret >> "gunnerName")];
		[ _holder, [ [_replMag,_weap,_muzzle, [_ammoCount]] ] ] call FUNC(partialMagazines);
		_success = true;
	};
	player reveal _holder;

	_success;
};

// [player, "M240_scoped_ep1", "100Rnd_762x51_M240", _vehicle, [0], "M240_scoped_ep1"] call ace_sys_crewserved_fnc_exchangeMagazineToVehicle;
// TODO: Support multi-magazine conversion into a single (big) mag.
// TODO: Support left-overs but SVA cannot be used on these vehicles due to multi-turret/weapon/magazine
FUNC(exchangeMagazineToVehicle) = {
	PARAMS_6(_unit,_weapon,_magazine,_vehicle,_tp,_muzzle);

	_ammoCount = if (_unit hasWeapon _weapon && {(_unit ammo _muzzle) > 0}) then {
		_unit ammo _muzzle;
	} else {
		[_unit,_weapon,_muzzle,_magazine] call FUNC(countMagazine);
	};

	if (_ammoCount == 0) exitWith {
		TRACE_1("No Ammo",_weapon);
		false;
	};

	_replMag = getText(C_MAGAZINE >> _magazine >> "ACE" >> "ACE_CREWSERVED" >> "ACE_magXchange_veh");
	if (_replMag == "this") then { _replMag = _magazine };
	_replCount = getNumber(C_MAGAZINE >> _replMag >> "count");
	TRACE_2("",_ammoCount,_replCount);

	_success = false;
	if (_ammoCount >= _replCount) then {
		_amount = floor(_ammoCount / _replCount);
		/*
		// Cannot use SVA because of multimagazines, multiturrets, and no way found yet to transfer magazines like with man-dummies
		_leftOver = _ammoCount - (_amount * _replCount);
		if (_leftOver > 0) then {
			_modifier = (_leftOver / _replCount);
			TRACE_3("Adding leftOver",_vehicle,_replMag,_modifier);
			// Add leftOver
			_vehicle setVehicleAmmo _modifier;
		};
		*/

		// Add fullMags
		TRACE_4("Adding fullmags",_vehicle,_replMag,_tp,_amount);
		// TODO: Turret
		if (local _vehicle) then {
			for "_i" from 1 to _amount do { _vehicle addMagazineTurret [_replMag, _tp] };
		} else {
			[QGVAR(addMagTur), [_vehicle,_replMag,_tp,_amount]] call CBA_fnc_globalEvent;
		};
		//hintSilent format["Loaded %1 of %2 magazines into %3 of %4", _amount,getText(C_MAGAZINE >> _replMag >> "displayName"),getText(C_WEAPON >> _weapon >> "displayName"),getText([_vehicle,_tp] call CBA_fnc_getTurret >> "gunnerName")];
		hintSilent "Loaded";
		_success = true;
	} else {
		// TODO: Add smaller magazines
	};

	if (_success) then {
		TRACE_2("Removing magazine from unit", _unit, _magazine);
		_unit removeMagazine _magazine;
	} else {
		TRACE_1("Abort",_vehicle);
		hintSilent "Too few ammo left";
	};
	_success;
};

FUNC(isTripod) = {
	private "_cfg";
	PARAMS_1(_tripod);
	if (_tripod == "") exitWith { false };
	_cfg = (configFile >> "CfgWeapons" >> _tripod >> "ACE" >> "ACE_CREWSERVED");
	if !(isClass _cfg) exitWith { false };
	// _tripod >> 'ACE_isTripod'
	(getNumber(_cfg >> "isTripod") == 1);
};

// We want to be able to remove a weapon mounted on a vehicle and use it as CSW.
// Would require a tripod (perhaps to be included in the vehicle cargo, or manually put in by players), and models without the guns (swap model function etc)
// .....

FUNC(getPitch) = {
	PARAMS_1(_MG);
	private "_p";
	_p = _MG getVariable [QGVAR(pitch),0];
	TRACE_1("fnc_getPitch",_p);
	_p
};

FUNC(setPitch) = {
	PARAMS_2(_MG,_p);
	private ["_cp","_np","_d"];
	_cp = [_MG] call FUNC(getPitch);
	_np = if (typeName _p == "STRING") then { _cp } else { _cp + _p };
	_d = direction _MG;
	TRACE_3("fnc_setPitch",_cp,_np,_d);
	_MG setVectorUp [((sin _d)*(sin _np)),((cos _d)*(sin _np)),(cos _np)];
	_MG setVariable [QGVAR(pitch),_np,true];
};

FUNC(setPitch_stored) = {
	PARAMS_1(_MG);
	private "_p";
	_p = [_MG] call FUNC(getPitch);
	[_MG,"store"] call FUNC(setPitch);
};

ADDON = true;
