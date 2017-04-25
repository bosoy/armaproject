// The following scripts are for players only, no need to run on dedi servers


[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };


// HUD Systems setup

// Mig21
   [["ibrPRACS_MiG21"], 0, "", [4,6], [4,6], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ibr.sqf", -0.018, 0, [[-1,"xxx"]], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
