// Hud modes setup
   mando_hud_init_code = {[west, 2, 1.4, 1.0, [1.0, 0.8, 0.2]] ExecVM "mando_missiles\huds\custom\custom_hud_helmet.sqf"};

   mando_hud_modes = [];

   mando_hud_modes = mando_hud_modes + [[
   1,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   2,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LandVehicle"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Spike-ER",  // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   4,		// Number of simultaneously detected HUD targets (max is 6)
   200, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   2,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["REMOTE"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Spike-ER - Remote",  // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   4,		// Number of simultaneously detected HUD targets (max is 6)
   200, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
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
   200,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
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
   0.2, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   55, 		// hagility
   55, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   60, 		// scanarch 
   65,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-6,"ffaa_Mistral_tig"]]; 

   // Missile parameters for Spike-ER (mando_hud_missile = 1);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10, 		// speedini 
   200, 	// speedmax 
   75,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   600, 	// activerange
   1, 		// modeinit
   350, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_towsmoke.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   40, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0.2, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   75, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90, 		// scanarch 
   90,		// scanarcv
   0.5,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-6,"ffaa_spike_tig"]]; 