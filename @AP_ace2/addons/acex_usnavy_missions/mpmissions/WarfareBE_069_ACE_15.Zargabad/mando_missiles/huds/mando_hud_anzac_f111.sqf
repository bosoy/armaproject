// Hud modes setup
   mando_hud_init_code = {[0.75,0.77,0.20,false]execVm"mando_missiles\huds\custom\custom_radar.sqf"};
   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9X",
   0.015,
   6,
   1000,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   3,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   6,
   1000,
   5000,
   3
   ]];

   // AIM 9 for SidewinderLaucher_AH1Z
   mando_hud_modes = mando_hud_modes + [[
   8,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   6,
   1000,
   5000,
   3
   ]];

   // AIM 9 for SidewinderLaucher_F35B
   mando_hud_modes = mando_hud_modes + [[
   11,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   6,
   1000,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   12,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   6,
   1000,
   5000,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   20,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   2,
   200,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   30,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   2,
   200,
   5000,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   1,
   false,
   0,
   ["Air"],
   0.19,
   "Air - AIM120",
   0.03,
   6,
   1000,
   10000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   2,
   ["Air"],
   0.14,
   "Air - AIM7 (SARH)",
   0.03,
   6,
   500,
   10000,
   4
   ]];

// Eble Sparrow
   mando_hud_modes = mando_hud_modes + [[
   26,
   false,
   2,
   ["Air"],
   0.14,
   "Air - AIM7 (SARH)",
   0.03,
   6,
   500,
   10000,
   4
   ]];

// Eble AIM54
   mando_hud_modes = mando_hud_modes + [[
   31,
   false,
   0,
   ["Air"],
   0.14,
   "Air - AIM54",
   0.03,
   6,
   1000,
   24000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   32,
   false,
   1,
   ["LandVehicle"],
   0.1,
   "AGM65",
   0.015,
   2,
   500,
   3000,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   32,
   false,
   1,
   ["GROUND"],
   0,
   "AGM65 (Ground)",
   0.015,
   2,
   500,
   3000,
   4
   ]];


   mando_hud_modes = mando_hud_modes + [[
   4,
   false,
   1,
   ["LandVehicle"],
   0.1,
   "AGM65",
   0.015,
   4,
   500,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   4,
   false,
   1,
   ["GROUND"],
   0.1,
   "AGM65 (Ground)",
   0.015,
   4,
   500,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   10,
   false,
   1,
   ["LandVehicle"],
   0.1,
   "AGM65",
   0.015,
   4,
   500,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   10,
   false,
   1,
   ["GROUND"],
   0.1,
   "AGM65 (Ground)",
   0.015,
   4,
   500,
   3000,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   6,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "AGM84 (Local)",
   0.015,
   3,
   500,
   10000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   6,
   false,
   0,
   ["REMOTE"],
   0.18,
   "AGM84 (Remote)",
   0.015,
   3,
   500,
   10000,
   3
   ]];

   // Mk82 for Mk82BombLauncher_6
   mando_hud_modes = mando_hud_modes + [[
   9,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   5,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV mk82",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   28,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV mk82",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   29,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV BLU-1",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   7,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV mk84",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   25,
   false,
   4,
   ["LOCATIONS"],
   0,
   "CCIP/Nav B61",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   33,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV GBU-12",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   -1,
   false,
   1,
   ["LOCATIONS"],
   0,
   "Navigation",
   0.015,
   6,
   800,
   3000,
   3
   ]];


// Missile parameters setup
   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_miss_params.sqf"));

   // Missile parameters for iron bombs
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   0,
   8000,
   2,
   100,
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "mando_missile1",
   29,
   30,
   false,
   2,
   1,
   0.5,
   false,
   false,
   "",
   45,
   45,
   1,
   true,
   75,
   75,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ADF_SKC_F111_MK82_launcher"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase)-1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV Mk82",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   // Missile parameters for ccip gub12 bombs
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   0,
   8000,
   2,
   100,
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "mando_missile1",
   29,
   30,
   false,
   2,
   1,
   0.5,
   false,
   false,
   "",
   45,
   45,
   1,
   true,
   75,
   75,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ADF_SKC_F111_GBU12_launcher"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase)-1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV GBU 12",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   // Missile parameters for ccip gub10 bombs
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   0,
   0,
   objNull,
   0,
   8000,
   2,
   100,
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "mando_missile1",
   29,
   30,
   false,
   2,
   1,
   0.5,
   false,
   false,
   "",
   45,
   45,
   1,
   true,
   75,
   75,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ADF_SKC_F111_GBU10_launcher"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase)-1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV GBU 10",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   mando_hud_num_modes = count mando_hud_modes; // Number of available modes// Hud modes setup