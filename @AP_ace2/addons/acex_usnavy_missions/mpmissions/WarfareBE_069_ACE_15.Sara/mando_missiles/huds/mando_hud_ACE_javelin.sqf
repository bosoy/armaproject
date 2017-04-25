// Hud modes setup
   mando_hud_init_code = {[]execVm"mando_missiles\huds\custom\custom_hud_javelin.sqf"};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LandVehicle"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.1,	// Aim circle diameter
   "Javelin TOP", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   50, 		// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LandVehicle"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.1,	// Aim circle diameter
   "Javelin DIR", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   50, 		// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   2,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["GROUND"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.1,	// Aim circle diameter
   "Javelin Ground", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   50, 		// Sensor width / 2 in meters
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
   5, 	// speedini 
   250, 	// speedmax 
   100,		// acceleration
   mando_missile_path+"special\do_nothing.sqf", 	// target (calculated by the firing action)
   0, 		// boomrange
   350, 	// activerange
   0, 		// modeinit
   130, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   "",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   8, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0, 		// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   75, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   180,		// scanarch 
   90,		// scanarcv
   0.5,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];
   mando_missileidxbase = mando_missileidxbase + [[-6,"ACE_Javelin_Direct"]]; 

   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   5, 	// speedini 
   250, 	// speedmax 
   100,		// acceleration
   mando_missile_path+"special\do_nothing.sqf", 	// target (calculated by the firing action)
   0, 		// boomrange
   400, 	// activerange
   1, 		// modeinit
   60, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   "",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   8, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0, 		// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   75, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   35, 		// scanarch 
   85,		// scanarcv
   0.5,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];
   mando_missileidxbase = mando_missileidxbase + [[-6,"ACE_Javelin_Direct"]];

   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   5, 	// speedini 
   250, 	// speedmax 
   100,		// acceleration
   mando_missile_path+"special\do_nothing.sqf", 	// target (calculated by the firing action)
   0, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   60, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   "",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   8, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0, 		// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   75, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   35, 		// scanarch 
   85,		// scanarcv
   0,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];
   mando_missileidxbase = mando_missileidxbase + [[-6,"ACE_Javelin_Direct"]];