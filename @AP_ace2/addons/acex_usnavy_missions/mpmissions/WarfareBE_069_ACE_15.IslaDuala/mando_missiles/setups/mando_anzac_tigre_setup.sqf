// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of Tigre class choppers

   // cameras setup (8 onboard hellfires)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hexa_hellfire.sqs";
   [["adf_tiger_HAD_CE"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Cam", _mcctypeaascript, [-3,2,-2], [0,3.2,0.65,0,181], {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane)))&& ("ANZAC_HellfireLauncher" in weapons _plane)}, 0, "ANZAC_HellfireLauncher", _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   // HUDs for pilots and gunners
   [["adf_tiger_HAD_CE"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_anzac_tigre.sqf", 0, 0, [[-1,"ANZAC_HellfireLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // HUDs for pilots and gunners
   [["adf_tiger_HAD_CE"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_anzac_tigre_gun.sqf", 0, 0, [[-1,"ANZAC_HellfireLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
};

