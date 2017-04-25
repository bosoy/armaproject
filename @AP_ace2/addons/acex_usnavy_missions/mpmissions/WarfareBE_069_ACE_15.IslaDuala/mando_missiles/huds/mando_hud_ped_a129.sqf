// Hud modes setup
   mando_hud_init_code = {[west, 1, 1.2, 1.0] ExecVM "mando_missiles\huds\custom\custom_hud_helmet.sqf"};

   mando_hud_modes = [];

   if (driver (vehicle player) == player) then
   {
      mando_hud_modes = mando_hud_modes + [[
      0,
      false,
      1,
      ["Air"],
      0.17,
      "Air - Stinger",
      0.015,
      2,
      200,
      1500,
      5
      ]];
   };

   mando_hud_modes = mando_hud_modes + [[
   1,
   false,
   2,
   ["LandVehicle"],
   0.17,
   "Hellfire", 
   0.015,
   6,
   200,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   2,
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

   mando_hud_misp = [];
   mando_missileidxbase = [];

   // Missile parameters for Stinger (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   5,
   500,
   200,
   objNull,
   10,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1l.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "",
   29,
   6,
   false,
   1,
   0,
   0.2,
   false,
   false,
   "",
   35,
   35,
   1,
   true,
   35,
   35,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"Stinger_Launcher4_ASZ"]]; 

   // Missile parameters for HellfireLauncher (mando_hud_missile = 1);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   10, 
   355,
   150,
   objNull,
   0,
   850,
   1,
   350,
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "mando_missile1",
   29,
   15,
   false,
   0.5,
   0,
   0.5,
   false,
   false,
   "",
   40,
   75,
   1,
   true,
   90,
   90,
   0,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"HellfireLauncher"]];

   // Missile parameters for TOW (mando_hud_missile = 2);
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"ASZ_TOWLauncher"]];


