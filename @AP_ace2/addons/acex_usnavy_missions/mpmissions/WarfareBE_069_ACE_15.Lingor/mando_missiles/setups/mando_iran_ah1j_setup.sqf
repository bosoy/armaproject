// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   // HUDs for pilots and gunners
   [["IRAN_AH1J","Panha2091"], 0, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_iran_ah1j.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   [["IRAN_AH1J","Panha2091"], 1, "sight", [4], [4], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_iran_ah1j_gun.sqf", 0, 0, [[-9,"SidewinderLaucher_AH1Z"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
