// Hud modes setup
   mando_hud_init_code = {[0.6,0.75,0.20,false]execVm"mando_missiles\huds\custom\custom_radar.sqf"};

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
   4
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
   4
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
   4
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
   4
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
   4
   ]];


   mando_hud_modes = mando_hud_modes + [[
   20,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9",
   0.015,
   6,
   1000,
   5000,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,
   false,
   0,
   ["Air"],
   0.19,
   "Air - AIM120",
   0.03,
   4,
   1000,
   8000,
   3
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
   2500,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   4,
   false,
   1,
   ["GROUND"],
   0,
   "AGM65 (Ground)",
   0.015,
   4,
   500,
   2500,
   4
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
   2500,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   10,
   false,
   1,
   ["GROUND"],
   0,
   "AGM65 (Ground)",
   0.015,
   4,
   500,
   2500,
   4
   ]];

   mando_hud_modes = mando_hud_modes + [[
   37,
   false,
   2,
   ["REMOTE"],
   0.17,	
   "LGB (REMOTE)",
   0.015,
   3,
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
   "CCIP/NAV",
   0.015,
   6,
   800,
   3000,
   3
   ]];


   mando_hud_modes = mando_hud_modes + [[
   9,
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

   mando_hud_num_modes = count mando_hud_modes; // Number of available modes

   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_miss_params.sqf"));