if (!isNil "mando_missile_setup_ffaa") exitWith {};
mando_missile_setup_ffaa = true;
waitUntil {!isNil "mando_missile_init_done"};
waitUntil {mando_missile_init_done};
Sleep 1;


[] spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   []execVM mando_missile_path+"setups\mando_ffaa_tigre_setup.sqf";
   []execVM mando_missile_path+"setups\mando_ffaa_ef2000_setup.sqf";

   // FFAA Choppers HUD setup (only flares and ECM)
   [["ffaa_famet_superpuma", "ffaa_famet_CH47_MG","ffaa_famet_cougar"], 0, "", [], [], 20, 20, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_ffaa_superpuma.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

   // C130 HUD setup (only flares and ECM)
   [["ffaa_ea_hercules"], 0, "", [], [], 20, 20, 20, [4,3,-2.5], mando_missile_path+"huds\mando_hud_c130j.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};



