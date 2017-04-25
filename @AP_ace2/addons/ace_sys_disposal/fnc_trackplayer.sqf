// Script by Inkompetent & zGuba A.D. 2009

#include "script_component.hpp"

#define __config configFile >> "CfgWeapons" >> _weapon

private ["_weapon", "_magazine"];

while {true} do {
	waitUntil {sleep 1; !isNull player};
	if (alive player) then 
	{
		_weapon = secondaryWeapon player;
		if (_weapon != "" && {getNumber (__config >> "ace_disposable") == 1}) then 
		{
			_magazines = getArray (__config >> "magazines");
			if ((getNumber (__config >> "ace_disposable_needpart") == 0) || {((getNumber (__config >> "ace_disposable_needpart") == 1) && {(getText (__config >> "ace_disposable_neededpart") in (weapons player))})}) then 
			{
				_magazine = _magazines select ((count _magazines) - 1);
				while {currentWeapon player == _weapon} do {
					if !(_magazine in (magazines player)) then 
					{
						if (animationState player == "ACE_launcherProne") then 
						{
							sleep 1;
							if (animationState player == "ACE_launcherProne" && {currentWeapon player == _weapon}) then 
							{
								{player removeMagazines _x} forEach _magazines;	// Ensure reload
								player removeWeapon _weapon;
								player addMagazine _magazine;
								
								player addWeapon _weapon;
								player selectWeapon _weapon;
							};
						} else {
							player addMagazine _magazine;
						};
					};
					sleep 0.2;
					// Javelin modes - unneeded
					_weapon = secondaryWeapon player;
					if (_weapon == "") exitWith {};
					_magazines = getArray (__config >> "magazines");
					if (count _magazines == 0) exitWith {};
					_magazine = _magazines select ((count _magazines) - 1);
					if (getNumber (__config >> "ace_disposable") == 0) then {_weapon = ""};
					// Disallow optics when undeployed!
					if (cameraOn == player && {cameraView == "GUNNER"} && {currentWeapon player == _weapon} && {player ammo _weapon == 0} && {getNumber (__config >> "ace_disposable_needpart") == 1}) then {
						player switchCamera "INTERNAL";
					};
				};
			} else {
				if (cameraOn == player && {cameraView == "GUNNER"} && {currentWeapon player == _weapon} && {getNumber (__config >> "ace_disposable_needpart") == 1}) then {
					player switchCamera "INTERNAL";
				};
			};
			{
				if (_x in (magazines player)) then {
					player removeMagazines _x;
				};
			} forEach _magazines;
		};
		{	// Remove unneeded "magazines"
			if (getNumber (configFile >> "CfgMagazines" >> _x >> "ace_disposable") == 1) then {
				player removeMagazines _x;
			};
		} forEach (magazines player);
	};
	sleep 1;
};
