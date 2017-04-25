// Hud modes setup
   mando_hud_init_code = {[currentWeapon Vehicle player]execVm"mando_missiles\huds\custom\custom_hud_generic.sqf"};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   3,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   [""],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.,	// Aim circle diameter
   "TOW (Manual)", // HUD Text
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   0,		// Number of simultaneously detected HUD targets (max is 6)
   10, 	// Sensor width / 2 in meters
   10,		// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_num_modes = count mando_hud_modes; // Number of available modes

// Missile parameters setup
   mando_hud_misp = [];

   // Missile parameters for Stinger (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "R_S8T_AT", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10, 		// speedini 
   278, 	// speedmax 
   80,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missileheadat2.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_towsmoke.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   6, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0.2, 	// controltime
   false, 	// detectable 
   true, 	// debug
   "", 		// launchscript
   8, 		// hagility
   8, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   15, 		// scanarch 
   15,		// scanarcv
   0,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];