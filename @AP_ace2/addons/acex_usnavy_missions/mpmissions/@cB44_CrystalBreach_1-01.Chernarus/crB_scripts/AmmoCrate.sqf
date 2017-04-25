//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090619
// Contact: http://creobellum.org
// Purpose: Custom load ammo crate
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
_crate addWeaponCargo ["G36C", 1];
_crate addweaponcargo ["M16A2",1];
_crate addweaponcargo ["M16A4",1];
_crate addweaponcargo ["ACE_M16A4_Iron",1];

_crate addweaponcargo ["M4A1",1];
_crate addweaponcargo ["M4A1_Aim",1];

_crate addweaponcargo ["ACE_SOC_M4A1_Aim",1];
_crate addweaponcargo ["ACE_SOC_M4A1",1];
_crate addweaponcargo ["ACE_SOC_M4A1_Eotech",1];
_crate addweaponcargo ["ACE_SOC_M4A1_SHORTDOT",1];

_crate addweaponcargo ["ACE_M4A1_Eotech",1];

_crate addweaponcargo ["ACE_FAL_Para",1];
_crate addweaponcargo ["ACE_SA58",1];

_crate addMagazineCargo ["30Rnd_556x45_G36", 16];
_crate addmagazinecargo ["ACE_30Rnd_762x51_B_FAL", 16];
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
_crate addMagazineCargo ["SmokeShellPurple", 1];
_crate addMagazineCargo ["SmokeShellYellow", 1];
_crate addMagazineCargo ["LaserBatteries", 1];
