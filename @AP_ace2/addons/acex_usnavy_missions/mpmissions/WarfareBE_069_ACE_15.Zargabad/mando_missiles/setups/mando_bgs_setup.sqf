// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };


// Galactica Viper
   [["viper1","CylonRaider"], 0, "", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_bgs_viper.sqf", 0, 0, [[-1,"bsg_launcher_viper2"],[-1, "bsg_launcher_lg80"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["viper2"], 0, "sight", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_bgs_viper.sqf", 0, 0, [[-1,"bsg_launcher_viper2"],[-1, "bsg_launcher_lg80"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // Rator
   [["raptor"], 0, "", [2], [2], 10, 10, 15, [3,3,-2.5], mando_missile_path+"huds\mando_hud_raptor.sqf", 0, 0.0, [[0,""]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};

