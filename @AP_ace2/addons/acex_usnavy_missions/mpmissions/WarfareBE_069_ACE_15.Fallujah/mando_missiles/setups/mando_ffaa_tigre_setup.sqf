// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of AH1Z class choppers

   // Tigre cameras setup (8 onboard spikes)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_ffaa_spike.sqs";
   [["ffaa_famet_tigre","ffaa_famet_tigre_AT"], 0, 0, ["Vehicles", "REMOTE"], "MMA Spike Cam", _mcctypeaascript, [-3,2,-2], [0,2.5,0.75,0,181], {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane)))&& ("ffaa_spike_tig" in weapons _plane)}, 0, "ffaa_spike_tig", _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   // HUDs for pilots and gunners
   [["ffaa_famet_tigre","ffaa_famet_tigre_AT"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ffaa_tigre.sqf", 0, 0, [[-9,"HellfireLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // HUDs for pilots and gunners
   [["ffaa_famet_tigre","ffaa_famet_tigre_AT"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ffaa_tigre_gun.sqf", 0, 0, [[-9,"HellfireLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
};
