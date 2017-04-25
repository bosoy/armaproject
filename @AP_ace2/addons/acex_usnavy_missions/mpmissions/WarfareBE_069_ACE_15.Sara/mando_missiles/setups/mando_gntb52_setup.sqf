// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_gnt_agm86.sqs";
   [["GNTB52","GNTB52u"], 8, 8, [], "MMA AGM86", _mcctypeaascript, [3,2,-5], [0,23,2], {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("AGM86Launcher" in weapons _plane)}, 0, "AGM86Launcher", [0.35,0.35,0.35,0.5], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_gnt_agm84.sqs";
   [["GNTB52","GNTB52u"], 8, 8, [], "MMA AGM84 Grnd", _mcctypeaascript, [3,2,-5], [0,23,2], {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("GLT_AGM84_Launcher" in weapons _plane)}, 0, "GLT_AGM84_Launcher", [0.35,0.35,0.35,0.5], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_gnt_agm84.sqs";
   [["GNTB52","GNTB52u"], 8, 8, ["vehicles","Ships", "REMOTE"], "MMA AGM84", _mcctypeaascript, [3,2,-5], [0,23,2], {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("GLT_AGM84_Launcher" in weapons _plane)}, 0, "GLT_AGM84_Launcher", [0.35,0.35,0.35,0.5], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// Gnat's B52
   [["GNTB52","GNTB52u"], 0, "", [4,6], [4,6], 15, 15, 20, [0,3,-5], mando_missile_path+"huds\mando_hud_gntb52.sqf", 0, 0, [[-1, "GNTMK82BombRail"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
   [["GNTB52","GNTB52u"], 1, "", [4,6], [4,6], 15, 15, 0, [0,3,-5], mando_missile_path+"huds\mando_hud_gntb52.sqf", 0, 0, [[-1, "GNTMK82BombRail"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
};
