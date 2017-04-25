//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090929
// Contact: http://creobellum.org
// Purpose: Custom load ammo in Zodiac
///////////////////////////////////////////////////////////////////
_crate = _this select 0;

clearMagazineCargo _crate;
clearWeaponCargo _crate;
/*
_crate addMagazineCargo ["30Rnd_556x45_Stanag", 20];
_crate addMagazineCargo ["200Rnd_556x45_M249", 3];
_crate addMagazineCargo ["100Rnd_762x51_M240", 3];
_crate addMagazineCargo ["HandGrenade_West", 5];

_crate addMagazineCargo ["1Rnd_HE_M203", 10];
*/
_crate addMagazineCargo ["30Rnd_556x45_G36", 20];
_crate addMagazineCargo ["100Rnd_556x45_BetaCMag", 6];
_crate addMagazineCargo ["HandGrenade_West", 10];

_crate addMagazineCargo ["SmokeShell", 5];
_crate addMagazineCargo ["SmokeShellRed", 2];
_crate addMagazineCargo ["SmokeShellGreen", 2];