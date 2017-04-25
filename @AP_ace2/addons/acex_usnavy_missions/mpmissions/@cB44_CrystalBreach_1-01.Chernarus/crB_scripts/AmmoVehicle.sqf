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

_loadout = Param2;
if (isNil "_loadout") then {
	_loadout = defValueParam2;
};

switch (_loadout) do {
	case 1: {
		_crate addMagazineCargo ["30Rnd_556x45_StanagSD", 24];
		_crate addMagazineCargo ["15Rnd_9x19_M9SD", 20];
	};
	case 2: {
		_crate addMagazineCargo ["30Rnd_556x45_Stanag", 24];
		_crate addMagazineCargo ["ACE_33Rnd_9x19_G18", 10];
	};
	case 3: {
		_crate addMagazineCargo ["30Rnd_556x45_Stanag", 24];
		_crate addMagazineCargo ["ACE_33Rnd_9x19_G18", 10];
	};
};

_crate addWeaponCargo ["M136", 1];
_crate addWeaponCargo ["Javelin", 1];
_crate addWeaponCargo ["Stinger", 1];

_crate addMagazineCargo ["30Rnd_556x45_G36", 16];
_crate addWeaponCargo ["ACE_Javelin_CLU", 1];
_crate addMagazineCargo ["Stinger", 1];
_crate addMagazineCargo ["SMAW_HEAA", 3];
_crate addmagazinecargo ["ACE_SMAW_Spotting", 10];
_crate addMagazineCargo ["200Rnd_556x45_M249", 5];
_crate addMagazineCargo ["100Rnd_762x51_M240", 4];

_crate addMagazineCargo ["HandGrenade_West", 10];

_crate addMagazineCargo ["SmokeShell", 7];
_crate addMagazineCargo ["SmokeShellGreen", 1];
_crate addMagazineCargo ["1Rnd_HE_M203", 8];
_crate addMagazineCargo ["1Rnd_SmokeGreen_M203", 1];
_crate addMagazineCargo ["1Rnd_SmokeRed_M203", 1];

_crate addMagazineCargo ["PipeBomb", 2];
_crate addMagazineCargo ["Mine", 6];
_crate addMagazineCargo ["SmokeShellPurple", 1];
_crate addMagazineCargo ["SmokeShellYellow", 1];
_crate addMagazineCargo ["LaserBatteries", 1];
