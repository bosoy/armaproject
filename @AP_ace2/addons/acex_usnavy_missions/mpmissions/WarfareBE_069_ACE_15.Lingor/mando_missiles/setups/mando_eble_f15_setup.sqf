// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _weapon_idx = "RKTF15E_GBU10_8Rail";
   _launch_pos = [0,0,-2];
   _background_mfd = []; // Default values for MDF paa and button placements

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_generic_gbu12.sqs";
   _cam_pos_angles = [0.8,2.8,-1.8,0,181];
   [["f15c_blue_mesh","f15c_grey_mesh","f15c_mod_mesh","f15e_blue_mesh","f15e_mk84_mesh","f15e_cbu_mesh","f15e_cbug_mesh"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-12", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane) && ("RKTF15E_GBU10_8Rail" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   [["f15c_blue_mesh","f15c_grey_mesh","f15c_mod_mesh","f15e_blue_mesh","f15e_mk84_mesh","f15e_cbu_mesh","f15e_cbug_mesh"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-12", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("RKTF15E_GBU10_8Rail" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_aim120.sqs";
   [["f15c_blue_mesh","f15c_grey_mesh","f15c_mod_mesh","f15e_blue_mesh","f15e_mk84_mesh","f15e_cbu_mesh","f15e_cbug_mesh"], 8, 8, ["Air"], "MMA RIO Console", _mcctypeaascript, [3,2,-3], [0.8,2.8,-1.8], {(gunner _plane == player) && ("RKT_F15_AIM120_2Rail" in weapons _plane)}, 0, "RKT_F15_AIM120_2Rail", [], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

[["f15c_blue_mesh","f15c_grey_mesh","f15c_mod_mesh","f15e_blue_mesh","f15e_mk84_mesh","f15e_cbu_mesh","f15e_cbug_mesh"], 8, 8, ["Air"], "MMA RIO Console", _mcctypeaascript, [3,2,-3], [0.8,2.8,-1.8], {(gunner _plane == player) && ("RKT_F15_AIM120_4Rail" in weapons _plane)}, 0, "RKT_F15_AIM120_4Rail", [], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

// HUD Systems setup

// F15 Pilot's HUD
[["f15c_blue_mesh","f15c_grey_mesh","f15c_mod_mesh","f15e_blue_mesh","f15e_mk84_mesh","f15e_cbu_mesh","f15e_cbug_mesh"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_eble_f15.sqf", 0, 0.04, [[-6,"RKT_F15_AIM120_6Rail"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

// F15 HUD setup for gunner
[["f15c_blue_mesh","f15c_grey_mesh","f15c_mod_mesh","f15e_blue_mesh","f15e_mk84_mesh","f15e_cbu_mesh","f15e_cbug_mesh"], 1, "", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0, [], 1]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


};
