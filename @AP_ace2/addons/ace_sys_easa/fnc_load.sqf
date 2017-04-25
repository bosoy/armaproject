/* ACE2 Module: Exchangeable Armament System for Aircrafts (EASA) */
// (c) 2009 by rocko
//
// #define DEBUG_MODE_FULL
#include "script_component.hpp"

PARAMS_3(_veh,_loadorder,_type);

private["_side","_group","_dummy","_fuel", "_newPAL"];
if !(local _veh) then {
	TRACE_1("Vehicle is NOT local to server ... Attempting to make local","");
	_side = createCenter civilian;
	_group = createGroup _side;
	_dummy = _group createUnit["ACE_CivDummy", [10, 10, 0], [], 0, "FORM"];
	waitUntil { alive _dummy };
	_dummy disableAI "TARGET";
	_dummy disableAI "MOVE";
	_dummy disableAI "ANIM";
	sleep 0.5;
	_fuel = fuel _veh;
	_veh setFuel 0;
	_dummy moveInDriver _veh;
	sleep 0.5;
	_dummy action ["engineOff", _veh];
	_dummy setDamage 1;
	sleep 0.5;
	deleteVehicle _dummy;
	_veh setFuel _fuel;
};

sleep 1;

switch (toUpper _type) do {
	case "C": {	// Custom loadout
		[_veh] call FUNC(remove_loadout);
		sleep 1;
		{
			_veh addMagazine _x;
			if (_x != "FakeWeapon") then {
				sleep 1;
			};
		} foreach _loadorder;
		{
			_weapon = getText(configFile >> "CfgMagazines" >> _x >> "ACE_EASA_WEAPON");
			if (_weapon != "") then {
				if (!(_veh hasWeapon _weapon)) then { _veh addWeapon _weapon; };
			};
		} foreach _loadorder;
	};

	case "D": {	// Default loadout
		private["_weapons","_magazines"];
		if (isClass(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret")) then {
			_weapons = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret" >> "weapons"));
			_magazines = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "Turrets" >> "MainTurret" >> "magazines"));
		} else {
			_weapons = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "weapons"));
			_magazines = (getArray(configFile >> "CfgVehicles" >> (typeOf _veh) >> "magazines"));
		};
		{ _veh removeWeapon _x } foreach (weapons _veh);
		{ _veh removeMagazines _x } foreach (magazines _veh);
		sleep 2;
		{ _veh addMagazine _x } foreach _magazines;
		{ _veh addWeapon _x } foreach _weapons;
	};
};

//TODO: Check if aircraft has been moved while its loaded, abort the loading then
//TODO: OR lock it until reloaded


false
