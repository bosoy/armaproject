removeAllWeapons player;
removeBackPack player;

if (isNil "customMagazines") exitWith {};

{player addMagazine _x;} forEach customMagazines;
{player addWeapon _x;} forEach customWeapons;
player setVariable ["ACE_WeaponOnBack", customBack];
//{[player, _x select 0, _x select 1] call ACE_fnc_PackMagazine;} forEach backpackMags;
//{[player, _x select 0, _x select 1] call ACE_fnc_PackWeapon;} forEach backpackWeapons;

_primaryWeapon = primaryWeapon player;
player selectweapon _primaryWeapon;
// Fix for weapons with grenade launcher
_muzzles = getArray(configFile>>"cfgWeapons" >> _primaryWeapon >> "muzzles");
player selectWeapon (_muzzles select 0);