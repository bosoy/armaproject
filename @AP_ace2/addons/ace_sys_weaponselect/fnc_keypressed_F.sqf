//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfgW configFile >> "CfgWeapons" >> currentWeapon player

private["_cur","_wpn","_mz","_fm","_modes","_modes1","_muzzles","_muzzles1","_cfg","_handled","_c","_t","_snd","_binocs","_curBin","_binocnt"];

if (player == vehicle player) then { // Player
	_handled = true;

	if (GVAR(Fdown)) exitwith {true};
	GVAR(Fdown) = true;

	_wpn = currentWeapon player;
	_mz = currentMuzzle player;
	_fm = currentWeaponmode player;
	_cfg = configFile >> "CfgWeapons" >> _wpn;

	_binocs = [player] call FUNC(getBinoculars);
	_binocnt = count _binocs;
	_curBin = (_binocs find _wpn);

	switch (true) do {
		case (_mz == "ace_safe"): {};	//safety

		case (_curBin != -1 && {_binocnt > 1}): { //binocular types
			if (isNil QGVAR(lastw)) then {GVAR(lastw) = primaryWeapon player};
			player selectweapon GVAR(lastw);
			INC(_curBin); // get next or first
			if (_curBin > _binocnt - 1) then {_curBin = 0};
			(_binocs select _curBin) spawn {sleep 0.4; player selectweapon _this};
		};
		case !(_wpn == "Throw" || {_wpn == "Put"}): { //rifles, GLs, pistols, launchers
			_muzzles1 = getArray (_cfg >> "muzzles");
			_muzzles = [];
			{
				_c = if (_x == "this") then {_cfg} else {_cfg>>_x};
				if (getNumber(_c>>"showtoplayer")==1) then {_muzzles set [count _muzzles,_x]};
			} foreach _muzzles1;
			if (_mz in _muzzles)  then {
				_cfg = _cfg >> _mz;
			};
			//player sidechat format ["wpn: %1 mz %2 fm %3",_wpn,_mz,_fm];
			//player sidechat format ["mzls: %1 cfg %2",_muzzles,_cfg];
			_modes1 = getArray(_cfg>>"modes");
			_modes = [];
			_cur = "";
			//"this" fire mode ordeal
			{
				if (_x == "this") then {
					_c = _cfg;
					_cur = if !(_mz in _muzzles) then {_wpn} else {_mz}; //if muzzle =="this" then firemode name equals weapon name
				} else {
					_c = _cfg>>_x;
					_cur = _x;
				};
				if (getNumber(_c>>"showtoplayer")==1) then {
					_modes set [count _modes,_cur];
				};
			} foreach _modes1;
			//player sidechat format ["modes: %1",_modes];
			if (count _modes <= 1) exitwith {};
			if (_fm == (_modes select (count _modes -1))) then { //last mode, re-select cur weapon to go to first mode
				player selectweapon _mz;

			} else {	//allow to go to the next fire mode
				_handled = false;
			};
			if (count _modes > 1) then	{//switching sound
				_snd = format ["ace_switch_%1_%2", gettext(__cfgW>>"ace_firemode_sound"),round (1 + random 1)];
				_snd call GVAR(SwitchSound);
			};
		};
		default	{ //Throw and Put handling
			_muzzles = _wpn call FUNC(throwputmuzzles);
			if (count _muzzles <= 1) exitwith {};
			if (_mz == (_muzzles select (count _muzzles -1))) then { //last muzzle, re-select cur weapon to go to first muzzles
				player selectweapon (_muzzles select 0);

			} else {//allow to go to the next muzzle
				_handled = false;
			};
		};
	};
} else { // Vehicle
	if ((vehicle player) isKindOf "Air") exitWith { _handled = false };

	_handled = true;

	if (GVAR(Fdown)) exitwith {true};
	GVAR(Fdown) = true;
	
	// Check MODES of CURRENTWEAPON and if SHOW TO PLAYER == 1 SWITCH MODE
	_weapon = currentWeapon (vehicle player);
	_modes = getArray(configFile >> "CfgWeapons" >> _weapon >> "modes"); //diag_log format ["Modes %1",_modes];
	if (count _modes > 1) then {
		_showModes = 0;
		_currentMode = currentWeaponMode player;
		{
			_showModes = _showModes + getNumber(configFile >> "CfgWeapons" >> _weapon >> _x >> "showToPlayer");
		} foreach _modes;
		// Find position of currentMode in Array
		_position = (([_modes,_currentMode] call BIS_fnc_arrayFindDeep) select 0) + 1;
		if (_showModes > 0 && {_position < _showModes}) then { _handled = false } else { (vehicle player) selectWeapon _weapon; };		
	};
	
};
_handled