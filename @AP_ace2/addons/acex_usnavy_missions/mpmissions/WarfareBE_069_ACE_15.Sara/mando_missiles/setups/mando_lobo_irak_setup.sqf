// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };



   _launch_pos = [0,0,-2];
   _background_mfd = [];

   _cam_pos_angles = [0,7,-1.7,0,75];
   _weapon_idx = "su17tmd_h29T";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_ch29.sqs";
   // Pilots camera
   [["LoBo_Iraq_Mig27_Grey", "LoBo_Iraq_Mig27_Cammo","LoBo_Iraq_MiG23","LoBo_Iraq_Su22B", "LoBo_Iraq_Su22"], 0, 0, ["Vehicles"], "MMA Ch29T Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("su17tmd_h29T" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _cam_pos_angles = [0,7,-0.7,0,180];

   _weapon_idx = "RKT_27_AS7_Rail";

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_as7.sqs";
   // Pilots camera
   [["LoBo_Iraq_Mig27_Grey", "LoBo_Iraq_Mig27_Cammo","LoBo_Iraq_MiG23","LoBo_Iraq_Su22B", "LoBo_Iraq_Su22"], 0, 0, ["Vehicles"], "MMA AS-7 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("RKT_27_AS7_Rail" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   _weapon_idx = "RKT_27_KAB500_Rail";

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_lgb_GLT_Falcon.sqs";
   // Pilots camera
   [["LoBo_Iraq_Mig27_Grey", "LoBo_Iraq_Mig27_Cammo","LoBo_Iraq_MiG23","LoBo_Iraq_Su22B", "LoBo_Iraq_Su22"], 0, 0, ["Vehicles"], "MMA KAB500 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("RKT_27_KAB500_Rail" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _weapon_idx = "GLT_KAB500_Launcher";

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_lgb_GLT_Falcon.sqs";
   // Pilots camera
   [["LoBo_Iraq_Mig27_Grey", "LoBo_Iraq_Mig27_Cammo","LoBo_Iraq_MiG23","LoBo_Iraq_Su22B", "LoBo_Iraq_Su22"], 0, 0, ["Vehicles"], "MMA KAB500 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("GLT_KAB500_Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// Irak planes HUD setup for pilot
   [["LoBo_Iraq_MiG23"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lobo_irak.sqf", 0, 0.08, [[-7,"R73Launcher"],[-6,"Ch29Launcher_Su34"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

// Irak planes HUD setup for pilot
   [["LoBo_Iraq_Mig29a","LoBo_Iraq_Mig29b"], 0, "sight", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lobo_irak.sqf", 0, 0.08, [[-7,"R73Launcher"],[-6,"Ch29Launcher_Su34"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
   
   
// Irak planes HUD setup for pilot
   [["LoBo_Iraq_Mig27_Grey", "LoBo_Iraq_Mig27_Cammo","LoBo_Iraq_Su22B", "LoBo_Iraq_Su22"], 0, "", [4,6], [4,6], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lobo_irak.sqf", 0, 0.07, [[-7,"R73Launcher"],[-6,"Ch29Launcher_Su34"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
