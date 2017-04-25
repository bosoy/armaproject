// Hud modes setup   
   mando_hud_init_code = {
		[safeZoneX + safezoneW - 0.2, 0.80, 0.20, false] ExecVM "mando_missiles\huds\custom\custom_radar.sqf";
		[] ExecVM "mando_missiles\huds\custom\custom_hud_apache.sqf";
	};

   mando_hud_modes = [];

   mando_hud_modes = mando_hud_modes + [[
   0,
   false,
   1,
   ["Air"],
   0.17,
   "Air - AIM9X",
   0.015,
   4,
   200,
   2000,
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
   4,
   200,
   2000,
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
   4,
   200,
   2000,
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
   4,
   200,
   2000,
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
   4,
   200,
   2000,
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
   2,
   200,
   2000,
   4
   ]];


   mando_hud_modes = mando_hud_modes + [[
   13,
   false,
   5,
   ["LandVehicle"],
   0.17,
   "AGM-114K", 
   0.015,
   6,
   200,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   24,
   false,
   0,
   ["LandVehicle"],
   0.17,
   "AGM-114L", 
   0.015,
   6,
   200,
   3000,
   3
   ]];

   mando_hud_modes = mando_hud_modes + [[
   13,
   false,
   5,
   ["REMOTE"],
   0.17,
   "AGM-114K - Remote", 
   0.015,
   6,
   200,
   5000,
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