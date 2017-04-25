Private ["_unit"];
_unit = _this select 0;

switch (typeOf _unit) do {
	case "HMMWV_Avenger": {
		_unit removeWeapon "SidewinderLaucher_AH1Z";
		_unit removeWeapon "StingerLaucher";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addMagazine "2Rnd_Sidewinder_AH1Z";
		_unit addWeapon "SidewinderLaucher_AH1Z";
	};
	case "AH1Z": {
		_unit removeMagazine "2Rnd_Sidewinder_AH1Z";
		_unit removeWeapon "SidewinderLaucher_AH1Z";
	};
	case "Ka52": {
		_unit removeWeapon "AT9Launcher";
		_unit removeWeapon "VikhrLauncher";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addweapon "AT9Launcher";
	};
	case "Ka52Black": {
		_unit removeWeapon "AT9Launcher";
		_unit removeWeapon "VikhrLauncher";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addMagazine "4Rnd_AT9_Mi24P";
		_unit addweapon "AT9Launcher";
	};	
};