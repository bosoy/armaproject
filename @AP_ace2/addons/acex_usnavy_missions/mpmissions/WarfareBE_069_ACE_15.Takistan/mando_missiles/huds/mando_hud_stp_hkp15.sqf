// Hud modes setup
   mando_hud_init_code = {};

   mando_hud_modes = [];

   mando_hud_modes = mando_hud_modes + [[
   0,
   false,
   3,
   ["LandVehicle"],
   0.,
   "RBS-55 TOW Man",
   0.015,
   3,
   800,
   3000,	
   3
   ]];


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

   mando_hud_num_modes = count mando_hud_modes;

// Missile parameters setup
   mando_hud_misp = [];
   mando_missileidxbase = [];

   // Missile parameters for TOW (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "R_S8T_AT",
   [0,0,0],
   0,
   0,
   10, 
   278,
   80,
   objNull,
   0,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missileheadat2.sqf",
   mando_missile_path+"exhausts\mando_towsmoke.sqf",
   "mando_missile1",
   29,
   6,
   false,
   1,
   0,
   0.2,
   false,
   true,
   "",
   7,
   7,
   1,
   false,
   20,
   20,
   0,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"sfp_rbs55_veh_launcher"]];
