// Hud modes setup
   mando_hud_init_code = {["F16"]execVm"mando_missiles\huds\custom\custom_hud_maptgt.sqf";};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   8,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual, 4 CCIP, 5 LOAL
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Air - AIM9", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   2,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   4            // Normal time to lock  
   ]];

   mando_hud_modes = mando_hud_modes + [[
   20,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   2,
   800,
   3000,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   10,
   false,
   1,
   ["LandVehicle"],
   0.1,
   "AGM65",
   0.015,
   2,
   500,
   3000,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   10,
   false,
   1,
   ["GROUND"],
   0,
   "AGM65 (Ground)",
   0.015,
   2,
   500,
   3000,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   42,
   false,
   0,
   ["GROUND"],
   0.1,
   "JDAM (Ground)",
   0.015,
   4,
   500,
   3000,
   3
   ]];
   
   
   mando_hud_modes = mando_hud_modes + [[
   5,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   9,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   -1,
   false,
   1,
   ["LOCATIONS"],
   0,
   "Navigation",
   0.015,
   6,
   800,
   3000,
   3 
   ]];

   
   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_miss_params.sqf"));


   // Missile parameters for Mk20_12Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"MK20_12Pod"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV Mk20",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   // Missile parameters for Mk20_6Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"MK20_6Pod"]];


   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV Mk20",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   // Missile parameters for Mk20_4Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"MK20_4Pod"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV Mk20",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   // Missile parameters for Mk20_2Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"MK20_2Pod"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV Mk20",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   // Missile parameters for CBU87_8Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"CBU87_8Pod"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV CBU87",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   // Missile parameters for CBU87_4Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"CBU87_4Pod"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV CBU87",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   // Missile parameters for CBU87_2Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"CBU87_2Pod"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV CBU87",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   // Missile parameters for CBU89_4Pod
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"CBU89_4Pod"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV CBU89",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   // Missile parameters for LGB BombLauncherA10
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"BombLauncherA10"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV LGB",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   // Missile parameters for ATOW BombLauncherA10
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ATOW_BombLauncherA10"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV LGB",
   0.015,
   6,
   800,
   3000,
   3
   ]];



   // Missile parameters for ACE CBU87
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ACE_CBU87_Bomblauncher"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV CBU87",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   // Missile parameters for ACE_Mk82BombLauncher
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ACE_Mk82BombLauncher"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV Mk82",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_num_modes = count mando_hud_modes;