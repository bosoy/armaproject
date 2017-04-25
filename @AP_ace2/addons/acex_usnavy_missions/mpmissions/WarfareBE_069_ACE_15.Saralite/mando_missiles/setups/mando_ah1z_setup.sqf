// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of AH1Z class choppers

   // AH1-Z cameras setup (8 onboard hellfires)
    _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire.sqs";
   [["AFMC_AH1T","AH1Z","p85_us_ah1"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], {(driver _plane == player) && !(isPlayer gunner _plane) && ("HellfireLauncher" in weapons _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // AH1-Z cameras setup (8 onboard hellfires)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire.sqs";
   [["AFMC_AH1T","AH1Z","p85_us_ah1"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], {(gunner _plane == player) && ("HellfireLauncher" in weapons _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // HUDs for pilots and gunners
   [["AFMC_AH1T","AH1Z","p85_us_ah1"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ah1z.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["AFMC_AH1T","AH1Z","p85_us_ah1"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ah1z_gun.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


//   [["AH1Z"], 1, "sight", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0.07, [], 1]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
