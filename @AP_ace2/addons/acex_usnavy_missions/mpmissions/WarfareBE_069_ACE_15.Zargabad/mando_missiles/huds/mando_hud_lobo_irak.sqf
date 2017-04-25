// Hud modes setup
   mando_hud_init_code = {};

   mando_hud_modes = [];

   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Air - Aphid", // HUD Text
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   4,		// Number of simultaneously detected HUD targets (max is 6)
   200, 	// Sensor width / 2 in meters
   2000,	// Sensor length / 2 in meters
   4            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,
   false,
   1,
   ["Air"],
   0.17,
   "Air - R73",
   0.02,
   6,
   1000,
   5000,
   3
   ]];

   // HUD for R27
   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   2,
   ["Air"],
   0.12,
   "Air - R27 (SARH)",
   0.02,
   4,
   1000,
   10000,
   4
   ]];
   
   
   mando_hud_modes = mando_hud_modes + [[
   -1,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0,	// Aim circle diameter
   "Navigation", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
   4000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_num_modes = count mando_hud_modes; // Number of available modes

// Missile parameters setup
   mando_hud_misp = [];
   mando_missileidxbase = [];

   // Missile parameters for Mistral (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100, 	// speedini 
   600, 	// speedmax 
   150,		// acceleration
   objNull, 	// target (calculated by the firing action)
   10, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1l.sqf", 	// boomscript
   "",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   10, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0.1, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   35, 		// hagility
   35, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   35, 		// scanarch 
   35,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"lobo_Flog_AphidRail", "su17TMD_R602"]];
   
   // Missile parameters for R73 (mando_hud_missile = 1);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100, 	// speedini 
   600, 	// speedmax 
   200,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   10, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0.2, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   55, 		// hagility
   35, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   65, 		// scanarch 
   65,		// scanarcv
   0.5,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"R73Launcher"]];
   
   // Missile parameters for R27 ACE (mando_hud_missile = 2)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   100,
   700,
   150,
   objNull,
   0,
   10000,
   2,
   100,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "mando_missile1",
   29,
   25,
   false,
   2,
   0,
   1,
   false,
   false,
   "",
   35,
   35,
   1,
   false,
   25,
   25,
   1,
   mando_minchaffdist
   ]];
   
   mando_missileidxbase = mando_missileidxbase + [[-1,"Vit_R27_Launcher", "GLT_R27_Launcher"]];
