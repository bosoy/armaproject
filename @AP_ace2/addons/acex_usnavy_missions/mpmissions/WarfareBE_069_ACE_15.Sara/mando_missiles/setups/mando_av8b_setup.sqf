// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };


   if (isNil "mando_av8s") then
   {
      mando_av8s = ["AV8B2_JDAM","AV8B", "AV8B2", "AV8B_CBU87","AV8B_MK20", "ASZ_AV8B_MM_GBU","ASZ_AV8B_MM_GA","ASZ_AV8B_MM_AA"];
   }
   else
   {
      mando_av8s = mando_av8s + ["AV8B2_JDAM","AV8B", "AV8B2", "AV8B_CBU87","AV8B_MK20", "ASZ_AV8B_MM_GBU","ASZ_AV8B_MM_GA","ASZ_AV8B_MM_AA"];
   };

   // BIS AV8B cameras setup (onboard LGBs)
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_lgb_av8b.sqs";
   _cam_pos_angles = [0,2.6,-1.8,0,181];
   _weapon_idx = -1;
   _launch_pos = [0,0,-2];
   _background_mfd = []; // Default values for MDF paa and button placements
   [mando_av8s, 0, 0, ["Vehicles", "REMOTE"], "MMA LGB Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("BombLauncher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_lgb_a10.sqs";
   [mando_av8s, 0, 0, ["Vehicles", "REMOTE"], "MMA LGB Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("BombLauncherA10" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_agm65.sqs";
   [mando_av8s, 0, 0, ["Vehicles"], "MMA AGM65 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("MaverickLauncher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   
// BIS AV8B2 and AV8B HUDs
   [mando_av8s, 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_av8b2.sqf", 0, 0, [[-7,"SidewinderLaucher_AH1Z"],[-6, "Mk82BombLauncher_6"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};

