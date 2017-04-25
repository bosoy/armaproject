#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

GVAR(Debug) = false;
GVAR(Processing) = 0;
GVAR(DoneMags) = [];
GVAR(StartedMags) = [];

PREP(refill);
PREP(unload);
PREP(invInit);
PREP(MagReplace);
PREP(magcheckAndReplace);
PREP(checkongearclosed);

call FUNC(invInit);

//run the mag/weapon change loop
[] spawn {
	private ["_lastAmmo", "_lastMuzzle", "_lastWeap", "_lastCount", "_cfg", "_weapMags", "_altMags", "_unitMags", "_processedMagTypes", "_muzzles"];
	_lastWeap = currentWeapon player;
	_lastCount = count (magazines player);
	while { true } do {
		// must find a better check for this, sth like "onPickUpMagazine" and "onDropMagazine" :-)
		waitUntil {count (magazines player) != _lastCount || {currentWeapon player != _lastWeap}};
		if (GVAR(Processing) == 0) then {
			if (count (magazines player) < _lastCount && {currentWeapon player == _lastWeap}) then {
				_lastCount = count (magazines player);	//don't trigger if the amount of mags decreased with the same weapon - means no mags were picked up.
				TRACE_1("Magazines decreased","");
			} else {
				TRACE_1("Check started","");
				waitUntil { _lastWeap = currentWeapon player; _lastWeap != "" };
				_unitMags = magazines player;
				_lastCount = count _unitMags;
				_processedMagTypes = [];
				GVAR(DoneMags) = [];
				GVAR(StartedMags) = [];
				_cfg = (configFile >> "CfgWeapons" >> _lastWeap);
				_lastMuzzle = _lastWeap;
				_weapMags = getArray (_cfg >> "magazines");
				_muzzles = getArray (_cfg >> "muzzles");
				//if (count _muzzles > 1) then {
					if ("this" != (_muzzles select 0)) then {
						_lastMuzzle = _muzzles select 0;
						_cfg = _cfg >> _lastMuzzle;
						_weapMags = getArray (_cfg >> "magazines");
					};
				//};
				TRACE_1("",_lastMuzzle);
				_lastAmmo = player ammo _lastMuzzle;
				//_altMags = getArray (_cfg >> "ACE_magazines_compat");
				{
					#include "Script_magReplace.hpp"
					//[player,_lastWeap,_weapMags,_altMags,_x] call FUNC(fMagReplace);
				} forEach _unitMags;
				sleep 0.1;
				waituntil { (count GVAR(DoneMags)) == (count GVAR(StartedMags)) };
				if (player ammo _lastMuzzle == 0  && {_lastAmmo > 0} && {(currentWeapon player == _lastWeap)}) then {	//re-adding the weapon so the mag is already loaded.
					player removeWeapon _lastWeap;
					player addweapon _lastWeap;
					if (player == vehicle player) then {
						player selectweapon _lastMuzzle;
					};
				};
				_lastCount = count (magazines player);
			};
			TRACE_1("Cycle complete - Waiting","");
		};
		//sleep 1;
	};
};

ADDON = true;
