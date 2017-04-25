// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of AH1Z class choppers

   // AH54 cameras setup (up to 16 onboard hellfires)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire_pmc.sqs";
   [["PMC_AH64_closesupport", "PMC_AH64_multirole"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], {(driver _plane == player) && !(isPlayer gunner _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   // AH1-Z cameras setup (8 onboard hellfires)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire_pmc.sqs";
   [["PMC_AH64_closesupport", "PMC_AH64_multirole"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcctypeaascript, [-3,2,-2], [0,6.5,-0.5,0,181], 1, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // HUDs for pilots and gunners
   [["PMC_AH64_closesupport", "PMC_AH64_multirole","PMC_AH64_groundsuppres"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0.07, [], 1]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["PMC_AH64_closesupport", "PMC_AH64_multirole","PMC_AH64_groundsuppres"], 1, "", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0.07, [], 1]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
