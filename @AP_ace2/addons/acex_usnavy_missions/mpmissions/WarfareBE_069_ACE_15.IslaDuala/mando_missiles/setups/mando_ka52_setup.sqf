// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of Ka52 class choppers
   // Ka52 cameras setup (12 onboard Vikhrs, AA mode)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_vikhr_aa.sqs";
[["Ka52Black", "Ka52","Oleg_Ka50"], 0, 0, ["Air"], "MMA Vikhr AA", _mcctypeaascript, [-4,2,-2], [0,3,0.3, 0, 50], {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane)))&& ("VikhrLauncher" in weapons _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // Ka52 cameras setup (12 onboard Vikhrs, AG mode)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_vikhr_ag.sqs";
[["Ka52Black", "Ka52","Oleg_Ka50"], 0, 0, ["Vehicles", "REMOTE"], "MMA Vikhr AG", _mcctypeaascript, [-4,2,-2], [0,3,0.3, 0, 181], {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane)))&& ("VikhrLauncher" in weapons _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // HUDs for pilots and gunners
   [["Ka52Black", "Ka52","Oleg_Ka50"], 0, "", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ka52.sqf", 0, 0, [[-7,"VikhrLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // HUDs for pilots and gunners
   [["Ka52Black", "Ka52","Oleg_Ka50"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ka52_gunner.sqf", 0, 0, [[-7,"VikhrLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";     
};
