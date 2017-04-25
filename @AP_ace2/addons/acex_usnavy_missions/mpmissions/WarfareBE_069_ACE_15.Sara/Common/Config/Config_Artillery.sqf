/* Call in dynamically the west artillery. */
Call Compile PreprocessFile Format["Common\Config\Core_Artillery\%1\Artillery_%2.sqf",WFBE_V_West_ArtilleryRootVersion,WFBE_V_West_ArtilleryFaction];

/* Call in dynamically the east artillery. */
Call Compile PreprocessFile Format["Common\Config\Core_Artillery\%1\Artillery_%2.sqf",WFBE_V_East_ArtilleryRootVersion,WFBE_V_East_ArtilleryFaction];

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Artillery: Initialization (West: %3 | East: %4) - [Done]",diag_frameno,diag_tickTime,WFBE_V_West_ArtilleryFaction,WFBE_V_East_ArtilleryFaction];