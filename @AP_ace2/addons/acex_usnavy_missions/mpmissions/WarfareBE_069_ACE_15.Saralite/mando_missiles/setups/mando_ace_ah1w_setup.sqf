[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };
	
   // AH1-Z cameras setup - Pilot - AGM-114K (laserguided)
    _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire_ace.sqs";
   [["ACE_AH1W_AGM_W", "ACE_AH1W_AGM_D", "ACE_AH1W_TOW_W", "ACE_AH1W_TOW_TOW_W", "ACE_AH1W_TOW_D", "ACE_AH1W_TOW_TOW_D"], 0, 0, ["Vehicles", "REMOTE"], "MMA AGM-114K", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], {(driver _plane == player) && ("ACE_HellfireLauncher" in weapons _plane) && !(isPlayer gunner _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";
   
   // AH1-Z cameras setup - Gunner - AGM-114K (laserguided)
    _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire_ace.sqs";
   [["ACE_AH1W_AGM_W", "ACE_AH1W_AGM_D", "ACE_AH1W_TOW_W", "ACE_AH1W_TOW_TOW_W", "ACE_AH1W_TOW_D", "ACE_AH1W_TOW_TOW_D"], 0, 0, ["Vehicles", "REMOTE"], "MMA AGM-114K", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], {(gunner _plane == player) && ("ACE_HellfireLauncher" in weapons _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


	// HUDs for pilots and gunners
   //[["ACE_AH1W_AGM_W", "ACE_AH1W_AGM_D", "ACE_AH1W_TOW_W", "ACE_AH1W_TOW_TOW_W", "ACE_AH1W_TOW_D", "ACE_AH1W_TOW_TOW_D"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ace_ah1w.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   //[["ACE_AH1W_AGM_W", "ACE_AH1W_AGM_D", "ACE_AH1W_TOW_W", "ACE_AH1W_TOW_TOW_W", "ACE_AH1W_TOW_D", "ACE_AH1W_TOW_TOW_D"], 1, "sight", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ace_ah1w.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["ACE_AH1W_AGM_W", "ACE_AH1W_AGM_D", "ACE_AH1W_TOW_W", "ACE_AH1W_TOW_TOW_W", "ACE_AH1W_TOW_D", "ACE_AH1W_TOW_TOW_D"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ah1z.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["ACE_AH1W_AGM_W", "ACE_AH1W_AGM_D", "ACE_AH1W_TOW_W", "ACE_AH1W_TOW_TOW_W", "ACE_AH1W_TOW_D", "ACE_AH1W_TOW_TOW_D"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ah1z_gun.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
};