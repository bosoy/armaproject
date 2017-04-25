// Hud modes setup
   mando_hud_init_code = {[west, 1, 1.2, 1.0] ExecVM "mando_missiles\huds\custom\custom_hud_helmet.sqf"};

   mando_hud_modes = [];

   mando_hud_modes = mando_hud_modes + [[
   -1,
   false,
   1,
   ["LandVehicle"],
   0,
   "",
   0.015,
   6,
   800,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   34,
   false,
   3,
   ["LandVehicle"],
   0.,
   "TOW",
   0.015,
   3,
   800,
   3000,	
   3
   ]];

   mando_hud_num_modes = count mando_hud_modes;

   call compile (preprocessFileLineNumbers (mando_missile_path+"huds\mando_hud_miss_params.sqf"));