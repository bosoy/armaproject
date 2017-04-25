#include "script_component.hpp"

private ["_lastAmmo", "_lastMuzzle", "_lastWeap", "_lastCount", "_cfg", "_weapMags", "_altMags", "_unitMags", "_processedMagTypes", "_muzzles"];
if (GVAR(Processing) == 0) then {
	
	TRACE_1("gear closed check started...","");
	_lastweap = primaryweapon player;
	if (_lastweap == "") exitwith {};
	_unitMags = magazines player;
	_lastCount = count _unitMags;
	_processedMagTypes = [];
	GVAR(DoneMags) = [];
	GVAR(StartedMags) = [];
	_cfg = (configFile >> "CfgWeapons" >> _lastWeap);
	_lastMuzzle = _lastWeap;
	_weapMags = getArray (_cfg >> "magazines");
	_muzzles = getArray (_cfg >> "muzzles");
	if ("this" != (_muzzles select 0)) then {
		_lastMuzzle = _muzzles select 0;
		_cfg = _cfg >> _lastMuzzle;
		_weapMags = getArray (_cfg >> "magazines");
	};
	TRACE_1("",_lastMuzzle);
	_lastAmmo = player ammo _lastMuzzle;
	{
		#include "Script_magReplace.hpp"
	} forEach _unitMags;
	sleep 0.1;
	waituntil { (count GVAR(DoneMags)) == (count GVAR(StartedMags)) };
	if (_lastAmmo > 0 && {player ammo _lastMuzzle == 0}  && {(primaryweapon player == _lastWeap)}) then {	//re-adding the weapon so the mag is already loaded.
		player removeWeapon _lastWeap;
		player addweapon _lastWeap;
		if (player == vehicle player) then {
			player selectweapon _lastMuzzle;
		};
	};
};