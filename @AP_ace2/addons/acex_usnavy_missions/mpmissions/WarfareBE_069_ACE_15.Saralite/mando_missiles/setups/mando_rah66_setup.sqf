// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of RA66 class choppers

   // RA66 cameras setup (8 onboard hellfires)
    _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire.sqs";
   [["modem_dkmm_usac_rah66_aa","modem_dkmm_usac_rah66_scout","modem_dkmm_usac_rah66_at","modem_dkmm_usmc_rah66_aa","modem_dkmm_usmc_rah66_scout","modem_dkmm_usmc_rah66_at"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], {(driver _plane == player) && !(isPlayer gunner _plane) && ("modem_dkmm_rah66_HellfireLauncher" in weapons _plane)}, 0, "modem_dkmm_rah66_HellfireLauncher", _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // RA66 cameras setup (8 onboard hellfires)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire.sqs";
   [["modem_dkmm_usac_rah66_aa","modem_dkmm_usac_rah66_scout","modem_dkmm_usac_rah66_at","modem_dkmm_usmc_rah66_aa","modem_dkmm_usmc_rah66_scout","modem_dkmm_usmc_rah66_at"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], {(gunner _plane == player) && ("modem_dkmm_rah66_HellfireLauncher" in weapons _plane)}, 0, "modem_dkmm_rah66_HellfireLauncher", _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // HUDs for pilots and gunners
   [["modem_dkmm_usac_rah66_aa","modem_dkmm_usac_rah66_scout","modem_dkmm_usac_rah66_at","modem_dkmm_usmc_rah66_aa","modem_dkmm_usmc_rah66_scout","modem_dkmm_usmc_rah66_at"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_rah66.sqf", 0, 0, [[-1,"modem_dkmm_rah66_StingerLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["modem_dkmm_usac_rah66_aa","modem_dkmm_usac_rah66_scout","modem_dkmm_usac_rah66_at","modem_dkmm_usmc_rah66_aa","modem_dkmm_usmc_rah66_scout","modem_dkmm_usmc_rah66_at"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_rah66_gun.sqf", 0, 0, [[-1,"modem_dkmm_rah66_StingerLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};


