// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _cam_pos_angles = [0.2,7.7,0.5,0,181];
   _weapon_idx = -1;
   _launch_pos = [0,0,-2];
   _background_mfd = [];

   // Pilots camera
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_gnt_kb500.sqs";
   [["RKTSU33MR", "RKTSU33AA","RKTSU33AG","RKTSU33B1","RKTSU33TAA","RKTSU33TAG","RKTSU33TB1"], 0, 0, ["REMOTE"], "MMA KB500 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("RKT_kb500Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _cam_pos_angles = [0.2,7.7,0.5,0,55];
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_gnt_ch29.sqs";
   [["RKTSU33MR", "RKTSU33AA","RKTSU33AG","RKTSU33B1","RKTSU33TAA","RKTSU33TAG","RKTSU33TB1"], 0, 0, ["Vehicles"], "MMA Kh29 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("RKTCh29Launcher" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

/*
// Kh22 rem
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_gnt_kitchen.sqs";
   [["RKTSU33MR", "RKTSU33AA","RKTSU33AG","RKTSU33B1","RKTSU33TAA","RKTSU33TAG","RKTSU33TB1"], 0, 0, ["REMOTE"], "MMA Kh22", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("RKT_Kitchen_Rail" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// Kh22 SEAD
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_gnt_kitchen_sead.sqs";
   [["RKTSU33MR", "RKTSU33AA","RKTSU33AG","RKTSU33B1","RKTSU33TAA","RKTSU33TAG","RKTSU33TB1"], 0, 0, ["RADAR"], "MMA Kh22 SEAD", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && ("RKT_Kitchen_Rail" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";
*/

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_gnt_kitchen.sqs";
   [["RKTSU33MR", "RKTSU33AA","RKTSU33AG","RKTSU33B1","RKTSU33TAA","RKTSU33TAG","RKTSU33TB1"], 8, 8, ["Vehicles", "REMOTE", "RADAR"], "MMA Kh22", _mcctypeaascript, [3,2,-3], [0.2,7.7,0.5], {(driver _plane == player) && ("RKT_Kitchen_Rail" in weapons _plane)}, 0, "RKT_Kitchen_Rail", [], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   [["RKTSU33MR", "RKTSU33AA","RKTSU33AG","RKTSU33B1","RKTSU33TAA","RKTSU33TAG","RKTSU33TB1"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_GNT_Su33.sqf", 0, 0, [[-7,"R73Launcher"],[-6,"Ch29Launcher_Su34"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
