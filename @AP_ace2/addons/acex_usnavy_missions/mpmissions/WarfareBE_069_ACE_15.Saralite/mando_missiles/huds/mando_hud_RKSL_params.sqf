// Missile parameters setup
   mando_hud_misp = [];
   mando_missileidxbase = [];

   // Missile parameters for AIM132 (mando_hud_missile = 0);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100, 	// speedini 
   600, 	// speedmax 
   200,		// acceleration
   objNull, 	// target (calculated by the firing action)
   10, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   10, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0.2, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   55, 		// hagility
   35, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   60, 		// scanarch 
   65,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_AIM132Launcher"]]; 


   // Missile parameters for Meteor (mando_hud_missile = 1)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100,		// speedini 
   800, 	// speedmax 
   150,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   12000, 	// activerange
   1, 		// modeinit
   100, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   25, 		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   0, 		// delayinit 
   0.5, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   65, 		// hagility
   65, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   75, 		// scanarch 
   75,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_MeteorLauncher"]];

   // Missile parameters for AIM120 (mando_hud_missile = 2)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100,		// speedini 
   800, 	// speedmax 
   150,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   12000, 	// activerange
   1, 		// modeinit
   100, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   25, 		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   0, 		// delayinit 
   0.5, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   55, 		// hagility
   55, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   75, 		// scanarch 
   75,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_AIM120Launcher"]];


   // Missile parameters for BrimstoneLauncher (mando_hud_missile = 3);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10, 		// speedini 
   355, 	// speedmax 
   150,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   850, 	// activerange
   1, 		// modeinit
   350, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   15, 		// endurance
   false,	// terrainavoidance
   0.5, 	// updatefreq
   0, 		// delayinit 
   0.5, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   75, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90, 		// scanarch 
   90,		// scanarcv
   0,	// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_BrimstoneLauncher"]];


   // Missile parameters for LGB 500 Bombs (mando_hud_missile = 4);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10, 	        // speedini 
   200,		// speedmax 
   9.8,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   3500, 	// activerange
   2, 		// modeinit
   150, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",		// smokescript
   "", 		// soundrsc
   29, 		// sounddur 
   5, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   1, 		// delayinit 
   0,	 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   40, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   60, 		// scanarch 
   90,		// scanarcv
   0,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_Paveway4500Launcher","RKSL_Paveway500Launcher"]];


   // Missile parameters for RKSL_MaverickLauncher (mando_hud_missile = 5)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   5,		// speedini 
   278, 	// speedmax 
   120,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   8000, 	// activerange
   2, 		// modeinit
   100, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   15, 		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   1,		// delayinit 
   0.5, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   45, 		// hagility
   45, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   45, 		// scanarch 
   75,		// scanarcv
   0,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_MaverickLauncher"]];


   // Missile parameters for RKSL_1000GPLauncher (mando_hud_missile = 6)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0,		// speedini 
   0, 		// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   8000, 	// activerange
   2, 		// modeinit
   100, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1_nohe.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   30, 		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   1,		// delayinit 
   0.5, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   45, 		// hagility
   45, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   75, 		// scanarch 
   75,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_1000GPLauncher"]];


   // Missile parameters for IRIS-T (mando_hud_missile = 7);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100, 	// speedini 
   600, 	// speedmax 
   200,		// acceleration
   objNull, 	// target (calculated by the firing action)
   10, 		// boomrange
   6000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   15, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   0, 		// delayinit 
   0.2, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   65, 		// hagility
   65, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   80, 		// scanarch 
   80,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_iristLauncher"]];


   // Missile parameters for RKSL_agm119mk3 (mando_hud_missile = 8)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   237, 	// speedmax 
   100,		// acceleration
   objNull, 	// target (calculated by the firing action)
   2, 		// boomrange
   1000, 	// activerange
   0, 		// modeinit
   80, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   120,		// endurance
   true,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   1,	 	// controltime
   true, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   40, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90, 		// scanarch 
   90,		// scanarcv
   0,		// Offset above target
   0	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_agm119mk3_Launcher"]];


   // Missile parameters for LGB 1000 Bombs (mando_hud_missile = 9);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10, 	        // speedini 
   200,		// speedmax 
   9.8,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   3500, 	// activerange
   2, 		// modeinit
   150, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",		// smokescript
   "", 		// soundrsc
   29, 		// sounddur 
   5, 		// endurance
   false,	// terrainavoidance
   1, 		// updatefreq
   1, 		// delayinit 
   0,	 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   40, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   60, 		// scanarch 
   90,		// scanarcv
   0,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_Paveway1000Launcher"]];

   // Missile parameters for RKSL_harpoon_Launcher (mando_hud_missile = 10)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   237, 	// speedmax 
   100,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   1000, 	// activerange
   0, 		// modeinit
   80, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   120,		// endurance
   true,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   1,	 	// controltime
   true, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   55, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90, 		// scanarch 
   90,		// scanarcv
   0,		// Offset above target
   0	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_harpoon_Launcher"]];

   // Missile parameters for ALARM (mando_hud_missile = 11)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100,		// speedini 
   800, 	// speedmax 
   150,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   1500, 	// activerange
   1, 		// modeinit
   300, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   25, 		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   0, 		// delayinit 
   0.5, 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   55, 		// hagility
   65, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   75, 		// scanarch 
   75,		// scanarcv
   0,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_ALARM_Launcher"]];

   // Missile parameters for RKSL_stormshadow_Launcher (mando_hud_missile = 12)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   237, 	// speedmax 
   100,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   1000, 	// activerange
   0, 		// modeinit
   100, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   120,		// endurance
   true,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   1,	 	// controltime
   true, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   55, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90, 		// scanarch 
   90,		// scanarcv
   0,		// Offset above target
   0	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKSL_stormshadow_Launcher"]];
