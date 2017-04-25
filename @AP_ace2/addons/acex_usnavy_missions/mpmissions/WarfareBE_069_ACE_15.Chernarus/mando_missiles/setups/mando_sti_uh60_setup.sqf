// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of Kiowa class choppers
   _weapon_idx = "HellfireLauncher";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_hexa_hellfire.sqs";
   _cam_pos_angles = [0,6,-2.2,0,90];
   _launch_pos = [-3, 2, -2];
   [["STI_UH60L_HF"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane) && ("HellfireLauncher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   [["STI_UH60L_HF"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("HellfireLauncher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   // HUDs for pilots and gunners
   [["STI_UH60L_HF","STI_UH60L","STI_UH60L_FFAR","STI_UH60L_FUEL","STI_UH60Q_MED"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lift.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["STI_UH60L_HF","STI_UH60L","STI_UH60L_FFAR","STI_UH60L_FUEL","STI_UH60Q_MED"], 1, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lift.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};



