// Hud modes setup
   mando_hud_init_code = 
   {
      [0.67,0.89,0.20,false]execVm"mando_missiles\huds\custom\custom_radar.sqf";
   };

   mando_hud_modes = [];
   mando_hud_modes = mando_hud_modes + [[
   0,		
   false,	
   1,           
   ["Air"],
   0.17,
   "Air - AA8 Aphid",
   0.015,
   6,
   1000,
   5000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   1,
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

   // Missile parameters for AA8 (mando_hud_missile = 0);
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
   5,
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
   60,
   65,
   1,
   mando_minchaffdist
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"PRACS_AA8_Launcher"]]; 
   
      // Missile parameters for AirBombLauncher (mando_hud_missile =1)
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"AirBombLauncher"]];
