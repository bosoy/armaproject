// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   // BIS Su39
   [["Su39","Su25_CDF","Su25_Ins","Su25_TK_EP1","sy25_ge","Su25_SA_SAR", "Su25_Iraq","ATOW_SU25","CSLA_Su25","Su39_JDAM"], 0, "", [4,6], [4,6], 10, 10, 0, [4,3,-4], mando_missile_path+"huds\mando_hud_su25.sqf", 0, 0.05, [[-7,"R73Launcher_2"],[-6,"Ch29Launcher"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
