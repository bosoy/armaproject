_unit = _this select 0;

removeAllWeapons _unit;
removeBackpack _unit;

{_unit addMagazine "30Rnd_556x45_G36"} foreach [1,2,3,4,5,6];
_unit addWeapon "G36A_camo";

{_unit addMagazine "17Rnd_9x19_glock17"} foreach [1,2,3,4];
_unit addWeapon "glock17_EP1";

{_unit addMagazine "HandGrenade_West"} foreach [1,2];
{_unit addMagazine "SmokeShell"} foreach [1,2];

_unit addWeapon "Binocular_Vector";
_unit addMagazine "ACE_Battery_Rangefinder";
_unit addWeapon "NVGoggles";
_unit addWeapon "ACE_Earplugs";

{_unit addMagazine "ACE_Bandage"} foreach [1,2];

_unit selectWeapon (primaryWeapon _unit);

if (true) exitWith {};