// Hud modes setup
   mando_hud_init_code = 
   {
      [0.67,0.89,0.20,false]execVm"mando_missiles\huds\custom\custom_radar.sqf";
      [west, 3, 1.33, 1.33, [0.25, 1.0, 0.75]] ExecVM "mando_missiles\huds\custom\custom_hud_helmet.sqf";
      ["F16"]execVm"mando_missiles\huds\custom\custom_hud_maptgt.sqf";
   };
   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		
   false,	
   1,           
   ["Air"],
   0.17,
   "Air - RB98",
   0.015,
   6,
   1000,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,
   false,
   0,
   ["Air"],
   0.19,
   "Air - RB100",
   0.03,
   6,
   1000,
   10000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   1,
   ["LandVehicle"],
   0.1,
   "AG - rb75",
   0.015,
   4,
   500,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   2,
   false,
   1,
   ["GROUND"],
   0.1,
   "AG - rb75 (Ground)",
   0.015,
   4,
   500,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   3,
   false,
   1,
   ["LandVehicle"],
   0.1,
   "AG - rbs15",
   0.015,
   4,
   1000,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   3,
   false,
   1,
   ["GROUND"],
   0.1,
   "AG - rbs15 (Ground)",
   0.015,
   4,
   500,
   10000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   4,
   false,
   0,
   ["GROUND"],
   0.1,
   "BK90 (Ground)",
   0.015,
   4,
   500,
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

   // Missile parameters for AIM9 (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   100,
   600,
   200,
   objNull,
   10,
   5000,
   2,
   500,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "mando_missile1",
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"sfp_rbs98_launcher"]]; 

   // Missile parameters for AIM120 (mando_hud_missile = 1)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   100,
   800,
   150,
   objNull,
   5,
   12000,
   1,
   100,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",
   "mando_missile1",
   29,
   25,
   false,
   2,
   0,
   0.5,
   false,
   false,
   "",
   55,
   55,
   1,
   true,
   75,
   75,
   1,
   mando_minchaffdist
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"sfp_rbs100_launcher"]];

   // Missile parameters for RB75 (mando_hud_missile = 2)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   5,
   278,
   120,
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
   45,
   75,
   0,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"sfp_rbs75_launcher"]];

   // Missile parameters for RBS15 (mando_hud_missile = 3)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   10,
   237,
   100,
   objNull,
   2,
   1000,
   0,
   100,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "mando_missile1",
   29,
   120,
   true,
   2,
   1,
   1,
   true,
   false,
   "",
   40,
   40,
   1,
   true,
   90,
   90,
   0,
   0
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"sfp_rbs15_launcher"]];

   // Missile parameters for BK90 Bombs (mando_hud_missile = 4);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   0,
   80,
   10,
   objNull,
   0,
   1000,
   1,
   100,
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf",
   "",
   "",
   29,
   60,
   false,
   1,
   1,
   0,
   true,
   false,
   "",
   15,
   15,
   1,
   false,
   180,
   180,
   0,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"sfp_bk90_launcher"]];