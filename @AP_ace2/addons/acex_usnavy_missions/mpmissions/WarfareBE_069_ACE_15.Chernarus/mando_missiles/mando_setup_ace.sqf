if (!isNil "mando_missile_setup_ace") exitWith {};
mando_missile_setup_ace = true;
waitUntil {!isNil "mando_missile_init_done"};
waitUntil {mando_missile_init_done};
Sleep 1;


[] spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   []execVM mando_missile_path+"setups\mando_ace_su27_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ace_ah1z_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ace_ah64d_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ace_ah1w_setup.sqf";

   [["ACE_AH6_GAU19", "ACE_AH6", "oh2_z9a","oh2_z9w"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_locations.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf"; 

   [["ACE_HC130_N"], 0, "", [], [], 20, 20, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_c130j.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // Lift + Navigation Mode + Flares
   [["ACE_UH60M", "ACE_MH6"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lift.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["ACE_M6A1_W", "ACE_M6A1_D"], 1, "ACE_StingerLauncher_four", [8,0], [8,0], 0, 0, 0, [0,-1,0,2], mando_missile_path+"huds\mando_hud_avenger.sqf", 0, 0, [[-1,"ACE_StingerLauncher_four"]], 2] execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

//   [["ACE_M2A2_W", "ACE_M2A2_D"], 1, "TOWLauncher", [0, 2], [0, 2], 0, 0, 0, [0,0,2], mando_missile_path+"huds\mando_hud_hmmwv_tow.sqf", 0, 0, [[-1,"TOWLauncher"]], 0]execVm"mando_missiles\units\mando_assign_portable.sqf";

   // ACE Su25/39
   [["ACE_Su39","ACE_Su25"], 0, "", [4,6], [4,6], 10, 10, 0, [4,3,-4], mando_missile_path+"huds\mando_hud_su25.sqf", 0, 0.05, [[-7,"R73Launcher_2"],[-6,"Ch29Launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   
   
// HJ-9 Camera
   _cam_pos_angles = [0,5.5,-1.4,0,181];
   _weapon_idx = -6;
   _launch_pos = [0,0,-2];
   _background_mfd = [];
   
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_hj9_ace.sqs";
   [["oh2_z9w","oh2_z9a"], 0, 0, ["Vehicles"], "HJ9 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("HJ9Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   [["ACE_L39_base","ACE_L39_TK_FAB250","ACE_L39_RU","ACE_L39_RU_BO"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_locations.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


   // Disable ACE countermeasures
   ACE_Countermeasures = false; 
   publicVariable "ACE_Countermeasures";   
};
