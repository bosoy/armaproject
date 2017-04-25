//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfgW configFile >> "CfgWeapons" >> _wpn

TRACE_1("",_this);

private["_wpn","_type","_snd"];
if (count _this != 2) exitwith {false};

_vehicle = vehicle player;

if (_vehicle isKindOf "Air") exitWith { false };

// TODO: Check if current turret has no weapons, then exit

if (currentWeapon _vehicle == "") exitWith { false }; //Exit if player has no weapon, refs #24316 ?
// Exit if in Driver or Cargo seats
if (assignedVehicleRole player in ["Driver","Cargo"]) exitWith { false };

_type = _this select 1; // -1 Safety, 0 Main Weapons, 1 Launcher Weapons

// Current selected weapon of player
_wpn = currentWeapon _vehicle;

TRACE_2("",_type,_wpn);

switch (_type) do {
	case -1: { //safety
		TRACE_1("Switch to safety","");
		if (_wpn == "") exitwith {}; // If no weapon in hands no reason to switch to safe mode
		if (_wpn != "ace_safe") then {
			if !(_vehicle hasweapon "ace_safe") then {_vehicle addweapon "ace_safe"};
			_vehicle selectweapon "ace_safe";
		};
	};
	case 0: { //switch to main weapons : first weapon in weapons array that inherits from MGun, MgunCore or CannonCore
		private ["_kind","_first","_weapon","_weapons","_types","_weaponFound","_skip","_showToPlayer","_showModes","_modes","_mode","_show"];
		_weapons = _vehicle weaponsTurret ((assignedVehicleRole player) select 1); 
		_types = ["MGunCore","CannonCore"];
		_first = false;
		_weaponFound = currentWeapon (vehicle player);
		for "_i" from 0 to (count _weapons)-1 do {
			_weapon = _weapons select _i; //diag_log format ["Weapon %1",_weapon];
			_skip = false;
			_showToPlayer = getNumber(configFile >> "CfgWeapons" >> _weapon >> "showToPlayer") == 1; //diag_log format ["ShowToPlayer %1",_showToPlayer];
			_modes = getArray(configFile >> "CfgWeapons" >> _weapon >> "modes"); //diag_log format ["Modes %1",_modes];
			_showModes = 0;
			if (count _modes > 0) then {
				{
					_showModes = _showModes + getNumber(configFile >> "CfgWeapons" >> _weapon >> _x >> "showToPlayer");
				} foreach _modes;
			};
			//diag_log format ["ShowModes %1",_showModes];
			
			_skip = if (count _modes > 0) then { _showModes == 0 } else { false }; //diag_log format ["Skip from SHOWMODES %1",_skip];
			_skip = !_showToPlayer; //diag_log format ["Skip from SHOWTOPLAYER %1",_skip];
			
			
			//diag_log format ["Skip %1",_skip];
			
			if (!_skip) then {
				{
					//diag_log format ["Kind %1",_x];
					_first = [(configFile >> "CfgWeapons" >> _weapon), (configFile >> "CfgWeapons" >> _x)] call CBA_fnc_inheritsFrom; 
					if (_first && {currentWeapon _vehicle == _weapon}) then { _first = false };
					if (_first) exitWith {};
				} foreach _types;
			};
			if (_first) exitWith {_weaponFound = _weapon;};
		};
		if (_vehicle hasweapon "ace_safe") then { _vehicle removeweapon "ace_safe" };
		_vehicle selectweapon _weaponFound;
	};
	case 1: { // switch to launcher type weapon : First weapon in weapons array that inherits from MissileLauncher
		private ["_first","_weapon","_weapons","_types","_weaponFound","_skip","_showToPlayer","_showModes","_modes","_mode","_show"];
		_weapons = _vehicle weaponsTurret ((assignedVehicleRole player) select 1); 
		_types = ["MissileLauncher","RocketPods"];
		_first = false;
		_weaponFound = currentWeapon (vehicle player);
		for "_i" from 0 to (count _weapons)-1 do {
			_weapon = _weapons select _i; //diag_log format ["Weapon %1",_weapon];
			_skip = false;
			_showToPlayer = getNumber(configFile >> "CfgWeapons" >> _weapon >> "showToPlayer") == 1; //diag_log format ["ShowToPlayer %1",_showToPlayer];
			_modes = getArray(configFile >> "CfgWeapons" >> _weapon >> "modes"); //diag_log format ["Modes %1",_modes];
			_showModes = 0;
			if (count _modes > 0) then {
				{
					_showModes = _showModes + getNumber(configFile >> "CfgWeapons" >> _weapon >> _x >> "showToPlayer");
				} foreach _modes;
			};
			//diag_log format ["ShowModes %1",_showModes];
			
			_skip = if (count _modes > 0) then { _showModes == 0 } else { false }; //diag_log format ["Skip from SHOWMODES %1",_skip];
			_skip = !_showToPlayer; //diag_log format ["Skip from SHOWTOPLAYER %1",_skip];
			
			//diag_log format ["Skip %1",_skip];
			
			if (!_skip) then {
				{
					//diag_log format ["Kind %1",_x];
					_first = [(configFile >> "CfgWeapons" >> _weapon), (configFile >> "CfgWeapons" >> _x)] call CBA_fnc_inheritsFrom; 
					if (_first && {currentWeapon _vehicle == _weapon}) then { _first = false };
					if (_first) exitWith {};
				} foreach _types;
			};
			if (_first) exitWith {_weaponFound = _weapon;};
		};
		if (_vehicle hasweapon "ace_safe") then { _vehicle removeweapon "ace_safe" };
		_vehicle selectweapon _weaponFound;
	};
	//case 2: {};
	//default {};
};

true
