#include "script_component.hpp"

// This script is spawned when an improper mag was detected in player's inventory. It processes all mags of given type at once.
// A dummy AI is created to check if there are partially used mags of this type. if yes, they are changed to partially used mags of the new type,
// while those full are simply converted into the proper ones and given back to player.
//
//
//waituntil { GVAR(Processing) == 0 };
[_this select 0,_this select 1,_this select 2,_this select 3] spawn {

	TRACE_1("Starting the script","");

	private ["_muzzle", "_ammo", "_magcheck", "_c", "_magtoremove", "_newmag", "_weapon", "_unit", "_dummy", "_i", "_max", "_magCountArray", "_action"];
	PARAMS_4(_magToRemove,_newMag,_weapon,_muzzle);
	_unit = player;

	if (vehicle player!= player) exitwith {
		while { ({ _x == _magtoremove } count (magazines player)) > 0 } do {
			_action = [player, _magtoremove] call CBA_fnc_removeMagazine;
			_action = [player, _newmag] call CBA_fnc_addMagazine;
		};
	};

	PUSH(GVAR(StartedMags),_magtoremove);

	//Create a dummy
	_dummy = createAgent ["ACE_CivDummy", [10,10,0], [], 0, "FORM"];
	waitUntil { alive _dummy };
	_unit reveal _dummy; // Handles delays in MP? reveal _dummy; // Handles delays in MP?

	TRACE_1("Dummy alive","");

	//safety script, delete dummy if it stays alive for some reason
	[_dummy] spawn {
		sleep 12;
		{
			if !(isNull _x) then { _x setdamage 1; deletevehicle _x; deletegroup (group _x); GVAR(Processing) = 0; GVAR(StartedMags) = [];GVAR(DoneMags) = [];/*[format["eliminating dummy %1",_x], "ace_sys_magazines"] call CBA_fnc_debug*/ };
		} foreach [(_this select 0)];
	};

	GVAR(Processing) = 1;	//announcing the mags are being processed so it doesn't trigger the check again
	{
		_x disableAI "TARGET";
		_x disableAI "AUTOTARGET";
		_x disableAI "MOVE";
		_x disableAI "ANIM";
	} foreach [_dummy];

	_magcheck = false;
	if (isClass (configFile >> "CfgWeapons" >> _weapon)) then { _magcheck = true };

	removeAllWeapons _dummy;

	if (_magcheck) then { _dummy addWeapon _weapon };

	#ifdef DEBUG_MODE_FULL
	hint format ["%1 amount = %2, Newmagtype = %3", _magtoremove,{ _x == _magtoremove }count magazines _unit, _newmag];
	_dbg = format ["processing mag %1 amount = %2, newmagtype = %3 muzzle %4", _magtoremove,{ _x == _magtoremove }count magazines _unit, _newmag,_muzzle];
	TRACE_1("",_dbg);
	#endif
	//Give magazines to the dummy until he finds a full one.
	_i = 0;
	_max = getNumber(configFile >> "CfgMagazines" >> _magtoremove >> "count");
	_magCountArray = [];	//array of amounts of ammo in each half-used magazine ie [3,16,28]
	if (_magcheck) then {
		for "_c" from 0 to ({ _x == _magtoremove }count (magazines _unit))-1 step 1 do {
			_unit action ["DROPMAGAZINE", _dummy, _magtoremove];
			waitUntil { ({ _x == _magtoremove }count magazines _dummy) > 0 };
			_dummy removeweapon _weapon;
			_dummy addweapon _weapon;
			_dummy selectweapon _muzzle;
			waituntil { (_dummy ammo _muzzle) > 0 };

			#ifdef DEBUG_MODE_FULL
			_dbg = format["got a mag, n = %1, ammo = %2 max = %3",{ _x == _magtoremove }count magazines _dummy,_dummy ammo _muzzle,_max];
			TRACE_1("",_dbg);
			#endif
			if ((_dummy ammo _muzzle) == _max) then {
				_action = [_dummy, _magtoremove] call CBA_fnc_removeMagazine;
				_action = [_unit, _newmag] call CBA_fnc_addMagazine;
			} else {
				TRACE_1("Not full magazine","");
				_ammo = _dummy ammo _muzzle;
				_action = [_dummy, _magtoremove] call CBA_fnc_removeMagazine;
				_action = [_dummy, _newmag] call CBA_fnc_addMagazine;
				_dummy setVehicleAmmo (_ammo/_max);
				TRACE_2("Giving new magazine back",(magazines _dummy),(_dummy ammo _weapon));
				//_dummy action ["DROPMAGAZINE", _unit, _newmag];
				_unit action ["TAKEMAGAZINE", _dummy, _newmag];
				TRACE_2("Given new magazine back",_dummy,(_dummy ammo _weapon));

			};
			waituntil { count (magazines _dummy) == 0 };
			TRACE_1("Pass over","");
		};
	};
	TRACE_1("1st loop over",(count (magazines _dummy)));

	_dummy setdamage 1;
	deleteVehicle _dummy;
	GVAR(Processing) = 0;
	PUSH(GVAR(DoneMags),_magtoremove);

	TRACE_2("Dummy destroyed",_magtoremove,GVAR(DoneMags));
};
