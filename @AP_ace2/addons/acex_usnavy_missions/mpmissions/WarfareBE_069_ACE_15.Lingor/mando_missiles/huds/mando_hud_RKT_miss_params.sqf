// Missile parameters setup
   mando_hud_misp = [];
   mando_missileidxbase = [];

   // Missile parameters for R73 (mando_hud_missile = 0);
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
   5, 		// boomrange
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
   0.5,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"R73Launcher_2"]];


   // Missile parameters for R73 Su34 (mando_hud_missile = 1);
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
   5, 		// boomrange
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
   0.5,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"R73Launcher"]];


   // Missile parameters for Ch29 Su34 (mando_hud_missile = 2)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   278, 	// speedmax 
   120,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   800, 	// activerange
   1, 		// modeinit
   300, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   10,		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   1,	 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   40, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90,		// scanarch 
   90,		// scanarcv
   1,		// Offset above target
   0	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"Ch29Launcher_Su34"]];

   // Missile parameters for Ch29 (mando_hud_missile = 3)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   278, 	// speedmax 
   120,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   800, 	// activerange
   1, 		// modeinit
   300, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   10,		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   1,	 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   40, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90,		// scanarch 
   90,		// scanarcv
   1,		// Offset above target
   0	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"Ch29Launcher"]];


   // Missile parameters for AirBombLauncher (mando_hud_missile = 4)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"AirBombLauncher"]];


   // Missile parameters for R27 (mando_hud_missile = 5)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   100,		// speedini 
   750, 	// speedmax 
   200,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   10000, 	// activerange
   2, 		// modeinit
   100, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   25, 		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   0, 		// delayinit 
   1, 		// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   35, 		// hagility
   35, 		// vagility
   1, 		// accuracy
   false, 	// intercept
   35, 		// scanarch 
   35,		// scanarcv
   1,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKTR27Launcher"]];

   // Missile parameters for RKTR73Launcher (mando_hud_missile = 6);
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
   5, 		// boomrange
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
   0.5,		// Offset above target
   mando_minchaffdist	// Countermeasures extent
   ]];

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKTR73Launcher"]];


   // Missile parameters for RKT_Kitchen_Rail (mando_hud_missile = 7)

   if ((vehicle player) isKindOf "RKT_BackfireA") then
   {
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   500, 	// speedmax 
   120,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   3000, 	// activerange
   1, 		// modeinit
   300, 	// cruisealt
   mando_missile_path+"warheads\echo\w80.sqf", 	// boomscript
   "",	// smokescript
   "", 	// soundrsc
   29, 		// sounddur 
   120,		// endurance
   true,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   4,	 	// controltime
   true, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   30, 		// hagility
   30, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   45,		// scanarch 
   90,		// scanarcv
   0,		// Offset above target
   0	// Countermeasures extent
   ]];  

   }
   else
   {
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   500, 	// speedmax 
   120,		// acceleration
   objNull, 	// target (calculated by the firing action)
   0, 		// boomrange
   3000, 	// activerange
   1, 		// modeinit
   300, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   120,		// endurance
   true,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   4,	 	// controltime
   true, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   30, 		// hagility
   30, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   45,		// scanarch 
   90,		// scanarcv
   0,		// Offset above target
   0	// Countermeasures extent
   ]];  
   };

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_Kitchen_Rail"]];


   // Missile parameters for RKTCh29Launcher (mando_hud_missile = 8)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 	// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   10,		// speedini 
   278, 	// speedmax 
   120,		// acceleration
   objNull, 	// target (calculated by the firing action)
   2, 		// boomrange
   800, 	// activerange
   1, 		// modeinit
   300, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   mando_missile_path+"exhausts\mando_missilesmoke1a.sqf",	// smokescript
   "mando_missile1", 	// soundrsc
   29, 		// sounddur 
   10,		// endurance
   false,	// terrainavoidance
   2, 		// updatefreq
   1, 		// delayinit 
   1,	 	// controltime
   false, 	// detectable 
   false, 	// debug
   "", 		// launchscript
   40, 		// hagility
   40, 		// vagility
   1, 		// accuracy
   true, 	// intercept
   90,		// scanarch 
   90,		// scanarcv
   1,		// Offset above target
   0	// Countermeasures extent
   ]];  

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKTCh29Launcher"]];


   // Missile parameters for RKT_kb500Launcher (mando_hud_missile = 9)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_kb500Launcher"]];


   // Missile parameters for RKT_fb250Launcher (mando_hud_missile = 10)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_fb250Launcher"]];

   // Missile parameters for RKT F15 AIM9 (mando_hud_missile = 11);
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
   5, 		// boomrange
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_F15_AIM9_4Rail"]]; 


   // Missile parameters for RKT F15 AIM9 (mando_hud_missile = 12);
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
   5, 		// boomrange
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_F15_AIM9_2Rail"]]; 



   // Missile parameters for RKT F15 AMRAAM (mando_hud_missile = 13)
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_F15_AIM120_6Rail"]];

   // Missile parameters for RKT F15 AMRAAM (mando_hud_missile = 14)
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_F15_AIM120_4Rail"]];


   // Missile parameters for RKT F15 AMRAAM (mando_hud_missile = 15)
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKT_F15_AIM120_2Rail"]];

   // Missile parameters for RKTF15E_cbu_6Rail (mando_hud_missile = 16)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKTF15E_cbu_6Rail"]];

   // Missile parameters for RKTF15E_mk82_6Rail (mando_hud_missile = 17)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKTF15E_mk82_6Rail"]];

   // Missile parameters for RKTF15E_mk84_6Rail (mando_hud_missile = 18)
   mando_hud_misp = mando_hud_misp + [[
   vehicle player, 	// _launcher
   "", 		// missilebody ("" for BIS used weapons when class of fired missile must be kept
   [0,0,0], 	// launchpos (calculated by the firing action)
   0, 		// dir (calculated by the firing action)
   0, 		// vangle (calculated by the firing action)
   0, 	// speedini 
   0, 	// speedmax 
   0,		// acceleration
   objNull, 	// target (calculated by the firing action)
   5, 		// boomrange
   5000, 	// activerange
   2, 		// modeinit
   500, 	// cruisealt
   mando_missile_path+"warheads\mando_missilehead1a.sqf", 	// boomscript
   "",	// smokescript
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"RKTF15E_mk84_6Rail"]];

   // Missile parameters for KH31A(P) Missile (mando_hud_missile = 19);
   mando_hud_misp = mando_hud_misp + [[
   vehicle player,
   "",
   [0,0,0],
   0,
   0,
   10,
   600,
   100,
   objNull,
   0,
   2000,
   1,
   300,
   mando_missile_path+"warheads\mando_missilehead1a.sqf",
   "",
   "",
   29,
   120,
   true,
   2,
   0,
   0,	
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

   mando_missileidxbase = mando_missileidxbase + [[-1,"GLT_CH31_Launcher"]];

