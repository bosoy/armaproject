// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

// CSLA Mig29 HUD setup for pilot
   [["CSLA_MiG29_2xB8M1","CSLA_MiG29_6xR73","CSLA_MiG29_4xB500","CSLA_MiG29_6xB500","CSLA_CA_MiG29"], 0, "sight", [4,6], [4,6], 15, 15, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_csla_mig29.sqf", 0, 0, [[-7,"R73Launcher"],[-6,"Ch29Launcher_Su34"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";     
};
