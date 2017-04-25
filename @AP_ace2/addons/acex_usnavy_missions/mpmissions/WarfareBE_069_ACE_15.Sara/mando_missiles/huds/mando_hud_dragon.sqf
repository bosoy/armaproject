// Hud modes setup
   mando_hud_init_code = {[currentWeapon Vehicle player]execVm"mando_missiles\huds\custom\custom_hud_generic.sqf"};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   3,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   [""],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0,		// Aim circle diameter
   "Dragon (Manual)", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   3,		// Number of simultaneously detected HUD targets (max is 6)
   50, 		// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_num_modes = count mando_hud_modes; // Number of available modes

// Missile parameters setup
   mando_hud_misp = [];


   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10, 	// speedini 
   200, 	// speedmax 
   100,		// acceleration
   mando_missile_path+"special\do_nothing.sqf", 	// target (calculated by the firing action)
   0, 		// boomrange
   1500, 	// activerange
   2, 		// modeinit
   60, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   "",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   10, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0, 		// controltime
   false, 	// detectable 
   true, 	// debug
   "", 		// launchscript
   5, 		// hagility
   8, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   8, 		// scanarch 
   8,		// scanarcv
   0,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];