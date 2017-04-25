_unit = _this select 0;

removeAllWeapons _unit;
removeBackpack _unit;

{_unit addMagazine "5Rnd_762x51_M24"} foreach [1,2,3,4,5,6,7,8,9,10,11,12];
_unit addWeapon "M24_des_EP1";

{_unit addMagazine "17Rnd_9x19_glock17"} foreach [1,2,3,4];
_unit addWeapon "glock17_EP1";

_unit addWeapon "NVGoggles";
_unit addWeapon "ACE_Earplugs";

{_unit addMagazine "ACE_Bandage"} foreach [1,2];

_unit selectWeapon (primaryWeapon _unit);

if (true) exitWith {};