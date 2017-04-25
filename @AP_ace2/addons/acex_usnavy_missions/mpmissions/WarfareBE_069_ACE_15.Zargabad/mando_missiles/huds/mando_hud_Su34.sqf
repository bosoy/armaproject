// Hud modes setup
   mando_hud_init_code = {
	[0.675,0.81,0.20,false]execVm"mando_missiles\huds\custom\custom_radar.sqf";
	["F16"]execVm"mando_missiles\huds\custom\custom_hud_maptgt.sqf";
	};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   15,		// Missile to be used
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
   14,		// Missile to be used
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
   44,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   1,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Air - R3",  // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy for ECM targets
   3,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   40,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   0,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Air - R77",  // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   12000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   22,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   2,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["Air"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.12,	// Aim circle diameter
   "Air - R27 (SARH)",  // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy for ECM targets
   4,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   10000,	// Sensor length / 2 in meters
   4            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   16,
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
   17,
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
   39,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "Kh31",
   0.015,        // IR accuracy for headon shots or radar accuracy for ECM targets
   6,		// Number of simultaneously detected HUD targets (max is 6)
   1000, 	// Sensor width / 2 in meters
   8000,	// Sensor length / 2 in meters
   5            // Normal time to lock
   ]];

   mando_hud_modes = mando_hud_modes + [[
   10,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_
   2,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["RADAR"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0.17,	// Aim circle diameter
   "Antiradar",  // HUD Text
   0.02,        // IR accuracy for headon shots or radar accuracy for ECM targets
   2,		// Number of simultaneously detected HUD targets (max is 6)
   800, 	// Sensor width / 2 in meters
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
   42,
   false,
   0,
   ["GROUND"],
   0.1,
   "KAB500SE (Ground)",
   0.015,       // IR accuracy for headon shots or radar accuracy with ECM
   4,		// Number of simultaneously detected HUD targets (max is 6)
   500, 	// Sensor width / 2 in meters
   3000,	// Sensor length / 2 in meters
   3            // Normal time to lock
   ]];


   mando_hud_modes = mando_hud_modes + [[
   18,		// Missile to be used
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
   25,		// Missile to be used
   false,	// Keep coords set in mando_assignvehicle_by_ ?
   4,           // Guidance type 0 Radar, 1 IR, 2 SARH, 3 Manual
   ["LOCATIONS"],     // Type of targets ["Air"], [""LandVehicle"], ["RADAR"], ["REMOTE"] or ["GROUND"]
   0,	// Aim circle diameter
   "CCIP/Nav Nuclear", // HUD Text
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
   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_miss_params.sqf"));