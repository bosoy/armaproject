// Hud modes setup
   mando_hud_init_code = {};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   2,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LandVehicle"],     // Type of targets ["Air"], ["LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.2,		// Aim circle diameter
   "Arkan ATGM", // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy with ECM
   3,		// Number of simultaneously detected HUD targets (max is 6)
   100, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   2,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["REMOTE"],     // Type of targets ["Air"], ["LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.2,		// Aim circle diameter
   "Arkan ATGM (REMOTE)", // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy with ECM
   3,		// Number of simultaneously detected HUD targets (max is 6)
   100, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   2,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["GROUND"],     // Type of targets ["Air"], ["LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.2,		// Aim circle diameter
   "Arkan ATGM (GROUND)", // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy with ECM
   3,		// Number of simultaneously detected HUD targets (max is 6)
   100, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_num_modes = count mando_hud_modes; // Number of available modes

// Missile parameters setup
   mando_hud_misp = [];

   // Missile parameters for AIM9 (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   50, 	// speedini 
   280, 	// speedmax 
   120,		// acceleration
   mando_missile_path+"special\do_nothing.sqf", 	// target (calculated by the firing action)
   0, 		// boomrange
   3000, 	// activerange
   2, 		// modeinit
   100, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   "",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   6, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0, 		// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   35, 		// hagility
   45, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   25, 		// scanarch 
   25,		// scanarcv
   -.25,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];