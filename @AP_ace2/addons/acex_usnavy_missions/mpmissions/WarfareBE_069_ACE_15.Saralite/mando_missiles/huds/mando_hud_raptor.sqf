// Hud modes setup
   mando_hud_init_code = {[] ExecVM "mando_missiles\huds\custom\custom_hud_trackbean.sqf"};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   true,	// Keep coords set in mando_assignvehicle_by_ ?
   0,          // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],        // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.1,	// Aim circle diameter
   "Track Bean",  // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   400, 	// Sensor width / 2 in meters
   1000,	// Sensor length / 2 in meters
   3            // Normal time to lock
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
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_num_modes = count mando_hud_modes; // Number of available modes


// Missile parameters setup
   mando_hud_misp = [];

   // Missile parameters for Maverick (mando_hud_missile = 1)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "baseball", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   600,	 	// speedmax 
   200,		// acceleration
   objNull, 	// target (calculated by the firing action)
   10, 		// boomrange
   1000, 	// activerange
   2, 		// modeinit
   0, 		// cruisealt
   mando_missile_path+"warheads\mando_trackbean.sqf", 	// boomscript
   mando_missile_path+"exhausts\mma_bgs_tractor.sqf",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   10,		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   0,		// delayinit 
   0.5, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   15, 		// hagility
   15, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   25, 		// scanarch 
   25,		// scanarcv
   1,		// Offset above target
   -1000	// Countermeasures extent
   ]];