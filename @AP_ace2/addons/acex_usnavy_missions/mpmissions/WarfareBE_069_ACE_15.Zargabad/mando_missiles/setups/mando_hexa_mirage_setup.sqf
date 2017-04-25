// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _weapon_idx = "HEXA_GBU12Launcher";
   _launch_pos = [0,0,-3];
   _background_mfd = []; // Default values for MDF paa and button placements

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_generic_gbu12.sqs";
   _cam_pos_angles = [0.65,3.1,-1.60,0,181];
   [["MAF_mf1", "MAF_mf1_aa", "MAF_mf1_cas","HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-12", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane) && ("HEXA_GBU12Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";
   [["MAF_mf1", "MAF_mf1_aa", "MAF_mf1_cas", "HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-12", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("HEXA_GBU12Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";
   
   _weapon_idx = "BombLauncher_MF1";   
   [["MAF_mf1", "MAF_mf1_aa", "MAF_mf1_cas","HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-12", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane) && ("BombLauncher_MF1" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _weapon_idx = "HEXA_AS30LLauncher";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_as30l.sqs";
   _cam_pos_angles = [0.65,3.1,-1.60,0,90];
   [["MAF_mf1", "MAF_mf1_aa", "MAF_mf1_cas", "HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 0, 0, ["Vehicles", "REMOTE"], "MMA AS-30L", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane) && ("HEXA_AS30LLauncher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   [["MAF_mf1", "MAF_mf1_aa", "MAF_mf1_cas", "HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 0, 0, ["Vehicles", "REMOTE"], "MMA AS-30L", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("HEXA_AS30LLauncher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_mica_em.sqs";   
   [["HEXA_Rafale_B1","HEXA_Rafale_C1", "HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 8, 8, ["Air"], "MMA MICA-EM Console", _mcctypeaascript, [3,2,-3], [0.8,2.8,-1.8], {(gunner _plane == player) && ("HEXA_MicaEMLauncher" in weapons _plane)}, 0, "HEXA_MicaEMLauncher", [], 2] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// HUD Systems setup

// Mirage 5, Mirage F1 and Raffale Pilot's HUD
[["HEXA_Rafale_B1","HEXA_Rafale_C1", "MAF_mf1", "MAF_mf1_aa", "MAF_mf1_cas", "HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-3], mando_missile_path+"huds\mando_hud_hexa_mirage.sqf", 0, 0, [[-6,"HEXA_MicaEMLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

// Mirage 5 and Raffale HUD setup for gunner
//[["HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L","HEXA_Mirage_D_GBU12"], 1, "", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0, [], 1] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
[["HEXA_Rafale_B1","HEXA_Rafale_C1", "HEXA_Mirage_5","HEXA_Mirage_C","HEXA_Mirage_D_AS30L", "HEXA_Mirage_D_GBU12"], 1, "", [4,6], [4,6], 15, 15, 20, [4,3,-3], mando_missile_path+"huds\mando_hud_hexa_gunner.sqf", 0, 0, [[-6,"HEXA_MicaEMLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
