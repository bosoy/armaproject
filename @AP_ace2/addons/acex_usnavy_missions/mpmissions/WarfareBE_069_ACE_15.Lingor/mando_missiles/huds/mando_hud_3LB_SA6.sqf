// Hud modes setup
   mando_hud_init_code = {};

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,
   false,
   2,
   ["Air"],
   0.17,
   "Air - SA6 SARH",
   0.015,
   3,
   100,
   6000,
   4
   ]];

   mando_hud_num_modes = count mando_hud_modes;


   mando_hud_misp = [];

   // Missile parameters for Stinger (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   10,
   600,
   200,
   objNull,
   5,
   6000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   15,
   false,
   1,
   0,
   0,
   false,
   false,
   "",
   35,
   35,
   1,
   true,
   60,
   65,
   1,
   mando_minchaffdist
   ]];