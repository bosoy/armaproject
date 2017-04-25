// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of Kiowa class choppers
   _weapon_idx = "HellfireLauncher";
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_hexa_hellfire.sqs";
   _cam_pos_angles = [0,2,1,0,90];
   _launch_pos = [-3, 2, -2];
   [["south_oh58_mgun_hellfire","south_oh58_ffar_hellfire","south_oh58_sting_hellfire","south_oh58_ffar_mgun","south_oh58_ffar","kiowa","OH58c","OH58d","OH58b"," OH58f","OH58g","OH58e"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane) && ("HellfireLauncher" in weapons _plane)}, 0, "HellfireLauncher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

[["south_oh58_mgun_hellfire","south_oh58_ffar_hellfire","south_oh58_sting_hellfire","south_oh58_ffar_mgun","south_oh58_ffar","kiowa","OH58c","OH58d","OH58b"," OH58f","OH58g","OH58e"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(driver _plane == player) && !(isPlayer gunner _plane) && ("Kiowa2rndHellfireLauncher" in weapons _plane)}, 0, "Kiowa2rndHellfireLauncher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   [["south_oh58_mgun_hellfire","south_oh58_ffar_hellfire","south_oh58_sting_hellfire","south_oh58_ffar_mgun","south_oh58_ffar","kiowa","OH58c","OH58d","OH58b"," OH58f","OH58g","OH58e"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("HellfireLauncher" in weapons _plane)}, 0, "HellfireLauncher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

[["south_oh58_mgun_hellfire","south_oh58_ffar_hellfire","south_oh58_sting_hellfire","south_oh58_ffar_mgun","south_oh58_ffar","kiowa","OH58c","OH58d","OH58b"," OH58f","OH58g","OH58e"], 0, 0, ["Vehicles", "REMOTE"], "MMA Hellfire Camera", _mcc_tv_script, _launch_pos, _cam_pos_angles, {(gunner _plane == player) && ("Kiowa2rndHellfireLauncher" in weapons _plane)}, 0, "Kiowa2rndHellfireLauncher", _background_mfd, 1, -3] execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


   // HUDs for pilots and gunners
   [["south_oh58_mgun_hellfire","south_oh58_ffar_hellfire","south_oh58_sting_hellfire","south_oh58_ffar_mgun","south_oh58_ffar","kiowa","OH58c","OH58d","OH58b"," OH58f","OH58g","OH58e"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_kiowa.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

[["south_oh58_mgun_hellfire","south_oh58_ffar_hellfire","south_oh58_sting_hellfire","south_oh58_ffar_mgun","south_oh58_ffar","kiowa"
,"OH58c","OH58d","OH58b"," OH58f","OH58g","OH58e"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_kiowa_gun.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};



