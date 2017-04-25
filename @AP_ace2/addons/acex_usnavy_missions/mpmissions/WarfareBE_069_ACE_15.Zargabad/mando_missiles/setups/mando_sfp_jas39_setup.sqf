// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _cam_pos_angles = [0,-0.4,0.8,0,181];
   _launch_pos = [0,0,-2];

   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_agm65_2.sqs";
   [["sfp_jas39"], 0, 0, ["Vehicles"], "MMA RBS75 Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {("sfp_rbs75_launcher" in weapons _plane)}, 0, "sfp_rbs75_launcher", _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

// HUD Systems setup

// Jas39
   [["sfp_jas39"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_sfp.sqf", 0, 0, [[-1,"xxx"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
