// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   // BIS Mi28 cameras setup (onboard AT9)

   // The MCC script is executed upon activation of the corresponding TV, and setting up all the TV parameters
   // including missile parameters, this is the control script for this TV system and mission editors can 
   // create their owns at will. "mando_missiles\tv\tv_types\" folder has several preconfigured types.
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_cma_at9_mi28.sqs";

   // TV camera position relative to launcher + angles
   // angles is composed by initial horizontal angle (relative to TV vehicle) and max angle diff with origin
   // [0, 181] = 100% free camera initially heading to vehicle direction
   _cam_pos_angles = [0.25,7,-2,0,181];

   // Weapon index, if >= 0, it is a virtual missile, non existing in the TV vehicle
   // if < 0, then it is (the arma weapon idx + 1) in negative. -6 to use ArmA AV8 idx 5 (LGB bomb)
   _weapon_idx = -1;

   // Launch position is the relative position to the TV vehicle 
   // or a displacement offset to be applied to real weapons fired from the TV vehicle
   // with mando_tv_keepgeo = true for the first case and false for the second (set in the control script)
   _launch_pos = [-3,2,-3];


   _background_mfd = []; // Default values for MDF paa and button placements
   [["CMA_Mi28_N_RUS"], 0, 0, ["Vehicles"], "MMA Ataka-V Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane)}, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   [["CMA_Mi28_N_RUS"], 0, 0, ["Vehicles"], "MMA Ataka-V Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, 1, 0, _weapon_idx, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";



// Mi28 HUD setup for pilot
   [["CMA_Mi28_N_RUS"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_locations.sqf", 0, 0.08, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";


// Mi28 HUD setup for gunner
   [["CMA_Mi28_N_RUS"], 1, "", [], [], 15, 15, 0, [4,3,-2.5], "", 0, 0.08, [], 1]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
