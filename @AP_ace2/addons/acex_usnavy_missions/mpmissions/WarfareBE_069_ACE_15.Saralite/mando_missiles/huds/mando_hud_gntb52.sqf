// Hud modes setup
   mando_hud_init_code = {[0.8,0.84,0.22,false]execVm"mando_missiles\huds\custom\custom_radar.sqf"};

   mando_hud_modes = [];

   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "AGM86 (Local)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   10000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   0,
   ["REMOTE"],
   0.18,
   "AGM86 (Remote)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   10000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   4,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual, 4 CCIP
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.025,	// Aim circle diameter
   "CCIP/NAV", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   4,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual, 4 CCIP
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.025,	// Aim circle diameter
   "CCIP/NAV B61", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];
 
   mando_hud_modes = mando_hud_modes + [[
   -1,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   4,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual, 4 CCIP
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.025,	// Aim circle diameter
   "NAV", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_num_modes = count mando_hud_modes; // Number of available modes

// Missile parameters setup
   mando_missileidxbase = [];
   mando_hud_misp = [];

   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
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
   60, 		// scanarch 
   65,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1, "GNTMK82Launcher"]];

   // Missile parameters for "ACE_B61BombLauncher" Nuke (mando_hud_missile = 1)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
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
   60, 		// scanarch 
   65,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ACE_B61BombLauncher"]];


   // Missile parameters for AGM86 Nuclear (mando_hud_missile = 2)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   247, 	// speedmax 
   80,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   2000, 	// activerange
   1, 		// modeinit
   600, 	// cruisealt
   mando_missile_path+"warheads\echo\w80.sqf", 	// boomscript
   "",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   120,		// endurance
   true,	// terrainavoidance
   2, 		// updatefreq
   4, 		// delayinit 
   3,	 	// controltime
   true, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   60, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   120, 	// scanarch 
   120,		// scanarcv
   0,		// Offset above target
   0	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"AGM86Launcher"]];

   vehicle player setVariable ["mando_flares_script", "mando_missiles\mando_chaffflaredraw_c130.sqf"];