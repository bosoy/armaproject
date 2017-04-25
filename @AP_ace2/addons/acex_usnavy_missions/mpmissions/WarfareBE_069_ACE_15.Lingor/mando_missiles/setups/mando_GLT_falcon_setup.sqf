// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   mando_f16s = ["GLT_Falcon_MR"];

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_lgb_GLT_Falcon.sqs";
   _cam_pos_angles = [-0.6,2.7,-2,0,181];
   _weapon_idx = "GLT_GBU12_Launcher";
   _launch_pos = [0,0,-2];


   _background_mfd = []; // Default values for MDF paa and button placements
   [mando_f16s, 0, 0, ["Vehicles", "REMOTE"], "MMA GBU12 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("GLT_GBU12_Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   // GLT_Falcon_GBU cameras setup (onboard Harpoons)
   _weapon_idx = "GLT_AGM84_Launcher";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_84_GLT_Falcon.sqs";
   [mando_f16s, 0, 0, ["Vehicles", "REMOTE"], "MMA Harpoon Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("GLT_AGM84_Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // GLT_Falcon_GBU cameras setup (onboard Mavericks)
   _weapon_idx = "GLT_AGM65_Launcher";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_agm65_2.sqs";
   [mando_f16s, 0, 0, ["Vehicles"], "MMA AGM65 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("GLT_AGM65_Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// HUD Systems setup


// F16
   [mando_f16s, 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_GLT_Falcon.sqf", 0, 0, [[-6,"GLT_SidewinderXLauncher"],[-8,"GLT_AIM120Launcher"],[-7,"GLT_AIM7Launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
