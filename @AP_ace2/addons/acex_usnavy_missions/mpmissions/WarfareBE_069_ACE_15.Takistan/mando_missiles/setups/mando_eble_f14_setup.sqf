// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };



   // The MCC script is executed upon activation of the corresponding TV, and setting up all the TV parameters
   // including missile parameters, this is the control script for this TV system and mission editors can 
   // create their owns at will. "mando_missiles\tv\tv_types\" folder has several preconfigured types.
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_eble_aim7.sqs";

   // TV camera position relative to launcher + angles
   // angles is composed by initial horizontal angle (relative to TV vehicle) and max angle diff with origin
   // [0, 181] = 100% free camera initially heading to vehicle direction
   _cam_pos_angles = [0,7.5,-1.6,0,65];

   // Weapon index, if >= 0, it is a virtual missile, non existing in the TV vehicle
   // if < 0, then it is (the arma weapon idx + 1) in negative. -6 to use ArmA AV8 idx 5 (LGB bomb)
   _weapon_idx = -1;

   // Launch position is the relative position to the TV vehicle 
   // or a displacement offset to be applied to real weapons fired from the TV vehicle
   // with mando_tv_keepgeo = true for the first case and false for the second (set in the control script)
   // [0,0,-2] makes each LGB bomb dropped to be displayed 2m below the plane at spawn time 
   // This prevents collissions between AV8B and the LGB in air.
   _launch_pos = [0,0,-2];


   _background_mfd = []; // Default values for MDF paa and button placements
   [["IkaR_F14_AIM_54L","IkaR_F14_AIM_54","IkaR_F14_AGM_65","IkaR_F14_GBU_12","IkaR_F14_AIM_54_ir","IkaR_F14_AGM_65_ir","IkaR_F14_GBU_12_ir","IRAN_F14_CAP","IRAN_F14_CAS","IkaR_F14_GBU_12_racs"], 0, 0, ["Air"], "MMA AIM-7", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("RKTF4SparrowRail" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_generic_gbu12.sqs";
   _cam_pos_angles = [3.2,0,-4,0,181];
   [["IkaR_F14_AIM_54L", "IkaR_F14_AIM_54","IkaR_F14_AGM_65","IkaR_F14_GBU_12","IkaR_F14_AIM_54_ir","IkaR_F14_AGM_65_ir","IkaR_F14_GBU_12_ir","IRAN_F14_CAP","IRAN_F14_CAS","IkaR_F14_GBU_12_racs"], 0, 0, ["Vehicles", "REMOTE"], "MMA GBU-12", _mcc_tv_script, _launch_pos, _cam_pos_angles, {((gunner _plane == player) || ((driver _plane == player) && !(isPlayer gunner _plane))) && ("IkaR_F14_GBU12Launcher5_ir" in weapons _plane)}, 0, "IkaR_F14_GBU12Launcher5_ir", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _cam_pos_angles = [0,7.5,-3.8,0,60];
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_eble_agm65.sqs";
   [["IkaR_F14_AIM_54L","IkaR_F14_AIM_54","IkaR_F14_AGM_65","IkaR_F14_GBU_12","IkaR_F14_AIM_54_ir","IkaR_F14_AGM_65_ir","IkaR_F14_GBU_12_ir","IRAN_F14_CAP","IRAN_F14_CAS","IkaR_F14_GBU_12_racs"], 0, 0, ["Vehicles"], "MMA AGM-65", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("IkaR_F14_AGM65Launcher4_ir" in weapons _plane)}, 0, _weapon_idx, _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   _mcctypeaascript = "mando_missiles\mcc\mcc_types\mando_missilecontrolon_aim54.sqs";
   [["IkaR_F14_AIM_54L","IkaR_F14_AIM_54","IkaR_F14_AGM_65","IkaR_F14_GBU_12", "IkaR_F14_AIM_54_ir","IkaR_F14_AGM_65_ir","IkaR_F14_GBU_12_ir","IRAN_F14_CAP","IRAN_F14_CAS","IkaR_F14_GBU_12_racs"], 8, 8, ["Air"], "MMA RIO Console", _mcctypeaascript, [3,2,-3], [0,7.5,-3.8], {(gunner _plane == player) && ("IkaR_F14_AIM54Launcher6_ir" in weapons _plane)}, 0, "IkaR_F14_AIM54Launcher6_ir", [], 2]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

// HUD Systems setup


// F14 Pilot's HUD
   [["IkaR_F14_AIM_54L","IkaR_F14_AIM_54","IkaR_F14_AGM_65","IkaR_F14_GBU_12","IkaR_F14_AIM_54_ir","IkaR_F14_AGM_65_ir","IkaR_F14_GBU_12_ir","IRAN_F14_CAP","IRAN_F14_CAS","IkaR_F14_GBU_12_racs"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_eble_f14.sqf", 0, 0, [[-6,"GLT_SidewinderXLauncher"],[-8,"GLT_AIM120Launcher"],[-7,"GLT_AIM7Launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

// F14 HUD setup for gunner
   [["IkaR_F14_AIM_54L","IkaR_F14_AIM_54","IkaR_F14_AGM_65","IkaR_F14_GBU_12","IkaR_F14_AIM_54_ir","IkaR_F14_AGM_65_ir","IkaR_F14_GBU_12_ir","IRAN_F14_CAP","IRAN_F14_CAS","IkaR_F14_GBU_12_racs"], 1, "", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0, [], 1]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


};
