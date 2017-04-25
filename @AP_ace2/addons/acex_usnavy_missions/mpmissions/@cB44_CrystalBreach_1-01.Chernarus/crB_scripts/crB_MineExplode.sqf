//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20091104
// Version: 20091104 - Initial release
// Version: 20091224
//     - Added multiple blast size options - Odin
//     - Changed only healthy or lightly injured units will trigger mines - Odin
// Contact: http://creobellum.org
// Purpose: Setup anti-personnel mine fields
// Usage: call{["rectangularMarker1","rectangularMarker2",etc] execVM "crb_scripts\crb_AntiPersonnelMines.sqf";};
///////////////////////////////////////////////////////////////////

// Choose Blast size by removing the // comments from the _shelltype line You want to use, and add the comment // to the previously used _shelltype line.
// Choose _shelltype that will spawn at each target ====>

_shelltype = "Grenade"; //SMALL
//_shelltype = "M_R73_AA"; // LARGE
//_shelltype = "R_Hydra_HE"; // LARGE
//_shelltype = "R_57mm_HE"; // LARGE
//_shelltype = "M_Sidewinder_AA"; //LARGE
//_shelltype = "Sh_105_HE"; //EXTRA-LARGE
//_shelltype = "R_S8T_AT"; // LARGE
//_shelltype = "M_AT5_AT"; //MEDIUM
//_shelltype = "M_Hellfire_AT"; //MEDIUM
//_shelltype = "M_Ch29_AT"; //SUPERSIZED
//_shelltype = "Bo_GBU12_LGB"; //SUPERSIZED

_thisList = _this select 0;
while {count _thisList > 0} do {
	{
		if (canStand _x) then {
			_shelltype createVehicle (position _x);
		};
	} forEach _thisList;
	sleep 2;
};