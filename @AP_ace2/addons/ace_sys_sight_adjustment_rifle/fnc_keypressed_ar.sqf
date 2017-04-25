#include "script_component.hpp"
#include "Script_SightAdjustmentConfig.hpp"

#define __wcfg (configFile >> "CfgWeapons" >> _wpn)

private["_wpn","_wpninhands","_s1","_handled"];

if (GVAR(presstime) == time) exitwith {false};
GVAR(presstime) = time;

if (vehicle player != player) exitwith {false};
if (primaryWeapon player == "") exitwith { false };
if (ACE_SYS_SA_RFL_RNG_Dialog || {ACE_SYS_SA_RFL_ELEV_Dialog} || {ACE_SYS_SA_RFL_RNG_ANGLE_Dialog}) exitwith { false };

_wpn = primaryWeapon player;
if (getNumber(__wcfg >> "ace_sa_enabled") == 0) exitwith {false};
_wpninhands = currentWeapon player;
if (_wpn != _wpninhands) exitwith { false };		//now we know player's got his rifle in hands
_s1 = currentmagazine player; //if currently selected GL, exit
if !(getText(configfile >> "cfgMagazines" >> _s1 >> "ammo") isKindOf "bulletBase") exitwith {false};

if (player != ACE_SYS_SA_RFL_CURUNIT) then {		//keeping track of player's unit (support for teamswitch and respawn)
	ACE_SYS_SA_RFL_SET_CURUNIT(player);
};
_handled = false;
if (_wpn != ACE_SYS_SA_RFL_CURWEAPON) then {		//new weapon, retrieving sight properties from weapon config
	if (getNumber(__wcfg >> "ace_sa_enabled") == 1) then {
		_wpn call FUNC(newWeap);
		_this call FUNC(click);
		_handled = true;
	};
} else {
	_this call FUNC(click);
	_handled = true;
};

_handled
