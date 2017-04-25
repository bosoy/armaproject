// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _weapon_idx = -1;
   _launch_pos = [0,0,-2.5];
   _background_mfd = []; // Default values for MDF paa and button placements


   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_generic_gbu12.sqs";
   _cam_pos_angles = [0,0.25,-2.4,0,181];
   [["ADF_SKC_F111_AGM","ADF_SKC_F111_AGM2","ADF_SKC_F111_1r","ADF_SKC_F111_AAM2","ADF_SKC_F111_AAM","ADF_SKC_F111_LGB2","ADF_SKC_F111_LGB"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-12", _mcc_tv_script, _launch_pos, _cam_pos_angles, {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane))) && ("ADF_SKC_F111_GBU12_launcher" in weapons _plane)}, 0, "ADF_SKC_F111_GBU12_launcher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   [["ADF_SKC_F111_AGM","ADF_SKC_F111_AGM2","ADF_SKC_F111_1r","ADF_SKC_F111_AAM2","ADF_SKC_F111_AAM","ADF_SKC_F111_LGB2""ADF_SKC_F111_LGB"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-10", _mcc_tv_script, _launch_pos, _cam_pos_angles, {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane))) && ("ADF_SKC_F111_GBU10_launcher" in weapons _plane)}, 0, "ADF_SKC_F111_GBU10_launcher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_gnt_agm84.sqs";
   [["ADF_SKC_F111_AGM","ADF_SKC_F111_AGM2","ADF_SKC_F111_1r","ADF_SKC_F111_AAM2","ADF_SKC_F111_AAM","ADF_SKC_F111_LGB2","ADF_SKC_F111_LGB"], 8, 8, [], "MMA AGM84 Grnd", _mcctypeaascript, [3,2,-5], [0,0.25,-2.4], {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("ADF_SKC_F111_AGM142L" in weapons _plane)}, 0, "ADF_SKC_F111_AGM142L", [0.35,0.35,0.35,0.5], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_gnt_agm84.sqs";
   [["ADF_SKC_F111_AGM","ADF_SKC_F111_AGM2","ADF_SKC_F111_1r","ADF_SKC_F111_AAM2","ADF_SKC_F111_AAM","ADF_SKC_F111_LGB2","ADF_SKC_F111_LGB"], 8, 8, ["Ships"], "MMA AGM84 Ships", _mcctypeaascript, [3,2,-5], [0,0.25,-2.4], {(((driver _plane == player) && !(isPlayer gunner _plane)) || (gunner _plane == player)) && ("ADF_SKC_F111_AGM142L" in weapons _plane)}, 0, "ADF_SKC_F111_AGM142L", [0.25,0.25,0.25,0.5], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


// F111 Pilot's HUD
   [["ADF_SKC_F111_AGM","ADF_SKC_F111_AGM2","ADF_SKC_F111_1r","ADF_SKC_F111_AAM2","ADF_SKC_F111_AAM","ADF_SKC_F111_LGB2","ADF_SKC_F111_LGB"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_anzac_f111.sqf", -0.05, 0, [[-9,"ADF_SKC_F111_GBU12_launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

// F111 HUD setup for gunner
   [["ADF_SKC_F111_AGM","ADF_SKC_F111_AGM2","ADF_SKC_F111_1r","ADF_SKC_F111_AAM2","ADF_SKC_F111_AAM","ADF_SKC_F111_LGB2","ADF_SKC_F111_LGB"], 1, "", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0, [], 1]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


};
