[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _cam_pos_angles = [0,-0.4,0.8,0,181];
   _launch_pos = [0,0,-0.5];
   _background_mfd = [];
   _weapon_idx = "MaverickLauncher6_ASZ";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_agm65_2.sqs";
   [["ASZ_EFA_AM_AA","ASZ_EFA_AM_GA","ASZ_EFA_AM_GBU"], 0, 0, ["Vehicles"], "MMA AGM65 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("MaverickLauncher6_ASZ" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// PED EF2000 HUD
   [["ASZ_EFA_AM_AA","ASZ_EFA_AM_GA","ASZ_EFA_AM_GBU"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2], mando_missile_path+"huds\mando_hud_ped_ef2000.sqf", 0, 0, [[-6,"GLT_SidewinderXLauncher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


// PED Harriers MAV TV (Harriers huds in av8 setup)
   _cam_pos_angles = [0,2.6,-1.8,0,181];
   _launch_pos = [0,0,-2];
   _weapon_idx = "MaverickLauncher6_ASZ";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_agm65_2.sqs";
   [["ASZ_AV8B_MM_GBU","ASZ_AV8B_MM_GA","ASZ_AV8B_MM_AA"], 0, 0, ["Vehicles"], "MMA AGM65 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("MaverickLauncher6_ASZ" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";



// A129 cameras setup (8 onboard hellfires)
   _cam_pos_angles = [0,4,1,0,181];

   _launch_pos = [-3,2,-2];
    _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire.sqs";
   [["ASZ_A129_GA","ASZ_A129_AT","ASZ_A129_AA"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcctypeaascript, _launch_pos, _cam_pos_angles, {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane))) && ("HellfireLauncher" in weapons _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // HUDs for pilots and gunners
   [["ASZ_A129_GA","ASZ_A129_AT","ASZ_A129_AA"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ped_a129.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["ASZ_A129_GA","ASZ_A129_AT","ASZ_A129_AA"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ped_a129.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";



};
