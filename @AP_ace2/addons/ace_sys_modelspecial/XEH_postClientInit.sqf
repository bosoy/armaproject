#include "script_component.hpp"

//run the mag/weapon change loop
[] spawn {
	private ["_lastMuzzle", "_lastWeap", "_lastCount", "_cfg", "_weapMags", "_unitMags", "_muzzles"];
	_lastWeap = secondaryWeapon player;
	_lastCount = count (magazines player);

	while { true } do {
		// must find a better check for this, sth like "onPickUpMagazine" and "onDropMagazine" :-)
		waitUntil {sleep 1; (count (magazines player) != _lastCount || {secondaryWeapon player != _lastWeap}) };
		if (count (magazines player) < _lastCount && {secondaryWeapon player == _lastWeap}) then {
			_lastCount = count (magazines player);	//don't trigger if the amount of mags decreased with the same weapon - means no mags were picked up.
		} else {
			waitUntil { sleep 1; _lastWeap = secondaryWeapon player; _lastWeap != "" };

			_lastCount = count (magazines player);

			_cfg = (configFile >> "CfgWeapons" >> _lastWeap);

			_lastMuzzle = _lastWeap;
			_weapMags = getArray (_cfg >> "magazines");
			_muzzles = getArray (_cfg >> "muzzles");

			if (count _muzzles > 1) then {
				if ("this" != (_muzzles select 0)) then {
					_lastMuzzle = _muzzles select 0;
					if (_lastMuzzle != "this") then { _cfg = (_cfg >> _lastMuzzle) };
					_weapMags = getArray (_cfg >> "magazines");
				};
			};

			_unitMags = magazines player;
			{
				[player,_lastWeap,_weapMags,_x] call FUNC(MagReplace);
			} forEach _unitMags;

			sleep 0.1;

			_lastCount = count (magazines player);
		};
	};
};
