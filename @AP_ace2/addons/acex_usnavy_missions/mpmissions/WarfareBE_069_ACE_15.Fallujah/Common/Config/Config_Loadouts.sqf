/*
	New loadout system. | Hybrid
	  Only one side gear is defined at a time. west don't know east and vice versa.
*/

/* Backpacks */

/* Binocular (Used for spotting) */
['WFBE_BINOCULARS',['Binocular','Binocular_Vector','Laserdesignator'],true] Call SetNamespace;

/* Set the loadout depending on it's type. */
[] Call Compile PreprocessFile Format["Common\Config\Core_Loadout\%1\Loadout_%2.sqf",WFBE_V_West_LoadoutRootVersion,WFBE_V_West_Loadout];
[] Call Compile PreprocessFile Format["Common\Config\Core_Loadout\%1\Loadout_%2.sqf",WFBE_V_East_LoadoutRootVersion,WFBE_V_East_Loadout];

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Loadouts: Initialization (West: %3 | East: %4) - [Done]",diag_frameno,diag_tickTime,WFBE_V_West_Loadout,WFBE_V_East_Loadout];