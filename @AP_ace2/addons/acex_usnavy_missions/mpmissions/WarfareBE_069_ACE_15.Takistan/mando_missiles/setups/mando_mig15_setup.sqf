[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   [["mig15bis_base"], 0, "", [4,6], [4,6], 15, 15, 0, [4,3,-3], mando_missile_path+"huds\mando_hud_mig15.sqf", 0, +0.04, [[-6,"R73Launcher"]], 0] execVm "mando_missiles\units\mando_assignvehicle_by_type.sqf";
};
