// Hud modes setup
   mando_hud_init_code = {[0.77,0.91,0.25,false]execVm"mando_missiles\huds\custom\custom_radar.sqf"};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Air - R73",  // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Air - R73",  // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   6,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Air - R73",  // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   5,
   false,
   2,
   ["Air"],
   0.14,
   "Air - R27 (SARH)",
   0.03,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   10000,	// Sensor length / 2 in meters
   4            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "Kh29 (TV)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   3,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "Kh29 (TV)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   7,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "Kh-22",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   8000,	// Sensor length / 2 in meters
   4            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   7,
   false,
   0,
   ["REMOTE"],
   0.1,
   "Kh-22 (Remote)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   8000,	// Sensor length / 2 in meters
   4            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   8,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "Kh29 (TV)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   0,
   ["GROUND"],
   0,
   "Kh29 (TV-GRND)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   3,
   false,
   0,
   ["GROUND"],
   0,
   "Kh29 (TV-GRND)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   7,
   false,
   0,
   ["GROUND"],
   0,
   "Kh22 (GRND)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   2,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   8000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   8,
   false,
   0,
   ["GROUND"],
   0.1,
   "Kh29 (TV-GRND)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   19,
   false,
   0,
   ["RADAR"],
   0.1,
   "KH31P Anti-Radar",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   6000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


/* TV version here, not laser, so REMOTE mode not available
   mando_hud_modes = mando_hud_modes + [[
   1,
   false,
   0,
   ["REMOTE"],
   0.18,
   "Ch29 (Remote)",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   5000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];
*/

   mando_hud_modes = mando_hud_modes + [[
   4,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   4,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0,	// Aim circle diameter
   "CCIP/Nav", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   9,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   4,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0,	// Aim circle diameter
   "CCIP/Nav KB500", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   10,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   4,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0,	// Aim circle diameter
   "CCIP/Nav FB250", // HUD Text
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   6,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
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
   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_RKT_miss_params.sqf"));