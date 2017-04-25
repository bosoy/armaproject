_unit = _this select 0;

removeAllWeapons _unit;
removeBackpack _unit;

{_unit addMagazine "30Rnd_556x45_G36"} foreach [1,2,3,4,5,6];
_unit addWeapon "G36A_camo";

{_unit addMagazine "17Rnd_9x19_glock17"} foreach [1];
_unit addWeapon "glock17_EP1";

_unit addMagazine "SmokeShell";
_unit addMagazine "SmokeShell";

_unit addWeapon "NVGoggles";
_unit addWeapon "ACE_Earplugs";

_unit addMagazine "ACE_Bandage";
_unit addMagazine "ACE_Epinephrine";
_unit addMagazine "ACE_Morphine";

//Rucksack needed
_unit addWeapon "ACE_Rucksack_MOLLE_DMARPAT_Medic";
[_unit, "SmokeShell", 2] call ACE_fnc_PackMagazine;
[_unit, "ACE_Bandage", 10] call ACE_fnc_PackMagazine;
[_unit, "ACE_LargeBandage", 10] call ACE_fnc_PackMagazine;
[_unit, "ACE_Epinephrine", 10] call ACE_fnc_PackMagazine;
[_unit, "ACE_Morphine", 10] call ACE_fnc_PackMagazine;

_unit selectWeapon (primaryWeapon _unit);

if (true) exitWith {};