/* Call in dynamically the west special variables. */
Call Compile preprocessFile Format["Common\Config\Core_Units\%1\Units_Special_%2.sqf",WFBE_V_West_UnitsRootVersion,WFBE_V_West_Faction];

/* Call in dynamically the east special variables. */
Call Compile preprocessFile Format["Common\Config\Core_Units\%1\Units_Special_%2.sqf",WFBE_V_East_UnitsRootVersion,WFBE_V_East_Faction];

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Special: Initialization (West: %3 | East: %4) - [Done]",diag_frameno,diag_tickTime,WFBE_V_West_Faction,WFBE_V_East_Faction];