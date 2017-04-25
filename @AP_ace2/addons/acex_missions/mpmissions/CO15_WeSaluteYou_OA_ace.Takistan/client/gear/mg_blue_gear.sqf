_unit = _this select 0;

removeAllWeapons _unit;
removeBackpack _unit;

{_unit addMagazine "100Rnd_556x45_BetaCMag"} foreach [1,2,3,4,5,6];
_unit addWeapon "MG36_camo";

{_unit addMagazine "17Rnd_9x19_glock17"} foreach [1,2,3,4];
_unit addWeapon "glock17_EP1";

_unit addWeapon "NVGoggles";
_unit addWeapon "ACE_Earplugs";

{_unit addMagazine "ACE_Bandage"} foreach [1,2];

_unit selectWeapon (primaryWeapon _unit);

if (true) exitWith {};