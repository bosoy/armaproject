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
   500,
   2000,
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
   500,
   2000,
   3
   ]];

   // HUD for R73 ACE for Gunner
   mando_hud_modes = mando_hud_modes + [[
   21,
   false,
   1,
   ["Air"],
   0.17,
   "Air - R73",
   0.02,
   6,
   500,
   2000,
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

   mando_hud_num_modes = count mando_hud_modes;

   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_miss_params.sqf"));