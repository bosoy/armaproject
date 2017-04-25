// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_lgb_GLT_Falcon.sqs";
   _cam_pos_angles = [0,-0.4,0.8,0,181];
   _weapon_idx = "RKSL_Paveway4500Launcher";
   _launch_pos = [0,0,-0.5];

   _background_mfd = []; // Default values for MDF paa and button placements
   [["rksl_efa_base"], 0, 0, ["Vehicles", "REMOTE"], "MMA Paveway 500 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("RKSL_Paveway4500Launcher" in weapons _plane)}, 0, "RKSL_Paveway4500Launcher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _background_mfd = []; // Default values for MDF paa and button placements
   [["rksl_efa_base"], 0, 0, ["Vehicles", "REMOTE"], "MMA Paveway 500 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("RKSL_Paveway500Launcher" in weapons _plane)}, 0, "RKSL_Paveway500Launcher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _background_mfd = []; // Default values for MDF paa and button placements
   [["rksl_efa_base"], 0, 0, ["Vehicles", "REMOTE"], "MMA Paveway 1000 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("RKSL_Paveway1000Launcher" in weapons _plane)}, 0, "RKSL_Paveway1000Launcher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _weapon_idx = "RKSL_MaverickLauncher";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_agm65_2.sqs";
   [["rksl_efa_base"], 0, 0, ["Vehicles"], "MMA AGM65 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("RKSL_MaverickLauncher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// HUD Systems setup

// Typhoon
   [["rksl_efa_base"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-0.5], mando_missile_path+"huds\mando_hud_RKSL_Typhoon.sqf", 0, 0, [[-6,"GLT_SidewinderXLauncher"],[-8,"GLT_AIM120Launcher"],[-7,"GLT_AIM7Launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
