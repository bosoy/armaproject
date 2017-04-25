//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090929
// Contact: http://creobellum.org
// Purpose: Custom load ammo in truck
///////////////////////////////////////////////////////////////////
_crate = _this select 0;

clearMagazineCargo _crate;
clearWeaponCargo _crate;

_loadout = Param2;
if (isNil "_loadout") then {
	_loadout = defValueParam2;
};

switch (_loadout) do {
	case 1: {
		_crate addMagazineCargo ["30Rnd_556x45_StanagSD", 150];
		_crate addMagazineCargo ["15Rnd_9x19_M9SD", 100];
	};
	case 2: {
		_crate addMagazineCargo ["30Rnd_556x45_Stanag", 150];
		_crate addMagazineCargo ["ACE_33Rnd_9x19_G18", 50];
	};
	case 3: {
		_crate addMagazineCargo ["30Rnd_556x45_Stanag", 150];
		_crate addMagazineCargo ["ACE_33Rnd_9x19_G18", 50];
	};
};

_crate addWeaponCargo ["M136", 5];

_crate addMagazineCargo ["30Rnd_556x45_G36", 60];
_crate addWeaponCargo ["Javelin", 5];
_crate addMagazineCargo ["Stinger", 5];
_crate addMagazineCargo ["SMAW_HEAA", 15];
_crate addmagazinecargo ["ACE_SMAW_Spotting", 50];
_crate addMagazineCargo ["200Rnd_556x45_M249", 25];
_crate addMagazineCargo ["100Rnd_762x51_M240", 20];

_crate addMagazineCargo ["HandGrenade_West", 50];

_crate addMagazineCargo ["SmokeShell", 35];
_crate addMagazineCargo ["SmokeShellGreen", 5];
_crate addMagazineCargo ["1Rnd_HE_M203", 40];
_crate addMagazineCargo ["1Rnd_SmokeGreen_M203", 5];
_crate addMagazineCargo ["1Rnd_SmokeRed_M203", 5];

_crate addMagazineCargo ["PipeBomb", 10];
_crate addMagazineCargo ["Mine", 30];
_crate addMagazineCargo ["SmokeShellPurple", 5];
_crate addMagazineCargo ["SmokeShellYellow", 5];
_crate addMagazineCargo ["LaserBatteries", 5];
