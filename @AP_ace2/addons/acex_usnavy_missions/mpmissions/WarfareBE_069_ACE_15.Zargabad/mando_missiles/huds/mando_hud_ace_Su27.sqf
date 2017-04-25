// Hud modes setup
   mando_hud_init_code = {[0.675,0.81,0.20,false]execVm"mando_missiles\huds\custom\custom_radar.sqf"};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   15,
   false,
   1,
   ["Air"],
   0.17,
   "Air - R73",
   0.02,
   6,
   1000,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   14,
   false,
   1,
   ["Air"],
   0.17,
   "Air - R73",
   0.02,
   6,
   1000,
   5000,
   3
   ]];

   // HUD for R73 ACE
   mando_hud_modes = mando_hud_modes + [[
   21,
   false,
   1,
   ["Air"],
   0.17,
   "Air - R73",
   0.02,
   6,
   1000,
   5000,
   3
   ]];

   // HUD for R27 ACE
   mando_hud_modes = mando_hud_modes + [[
   22,
   false,
   2,
   ["Air"],
   0.12,
   "Air - R27 (SARH)",
   0.02,
   4,
   1000,
   10000,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   16,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "Kh29 (TV)",
   0.015,
   3,
   500,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   17,
   false,
   0,
   ["LandVehicle"],
   0.1,
   "Kh29 (TV)",
   0.015,
   3,
   500,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   10,
   false,
   2,
   ["RADAR"],
   0.17,
   "Antiradar",
   0.02,
   2,
   800,
   3500,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   18,
   false,
   4,
   ["LOCATIONS"],
   0,
   "CCIP/Nav",
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
   "CCIP/Nav Nuclear",
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

   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_miss_params.sqf"));

   // Missile parameters for ACE_FAB500M62Launcher
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
   5,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   10,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   55,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"ACE_FAB500M62Launcher"]];

   mando_hud_modes = mando_hud_modes + [[
   (count mando_missileidxbase) - 1,
   false,
   4,
   ["LOCATIONS"],
   0.025,
   "CCIP/NAV KB500",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_num_modes = count mando_hud_modes;