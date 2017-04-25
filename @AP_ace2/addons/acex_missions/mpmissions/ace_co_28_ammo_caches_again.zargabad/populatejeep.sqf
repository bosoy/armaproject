_unit = _this select 0;

clearWeaponCargo _unit;
clearMagazineCargo _unit;

_unit addMagazineCargo ["30Rnd_556x45_Stanag",20];
_unit addMagazineCargo ["HandGrenade_West",4];
_unit addMagazineCargo ["SmokeShell",4];
_unit addMagazineCargo ["SmokeShellGreen",1];
_unit addMagazineCargo ["SmokeShellRed",1];
_unit addMagazineCargo ["SmokeShellYellow",1];

_unit addMagazineCargo ["1Rnd_HE_M203", 6];
_unit addMagazineCargo ["FlareWhite_M203", 6];
_unit addMagazineCargo ["1Rnd_Smoke_M203", 3];
_unit addMagazineCargo ["1Rnd_SmokeRed_M203", 1];
_unit addMagazineCargo ["1Rnd_SmokeGreen_M203", 1];
_unit addMagazineCargo ["1Rnd_SmokeYellow_M203", 1];
_unit addMagazineCargo ["200Rnd_556x45_M249", 2];