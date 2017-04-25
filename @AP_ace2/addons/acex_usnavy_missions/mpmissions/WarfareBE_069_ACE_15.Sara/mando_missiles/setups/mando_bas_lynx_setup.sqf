// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // Cameras for gunners of Tigre class choppers

   // cameras setup (8 onboard hellfires)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_bas_crv7pg.sqs";
   [["AW159_Lynx_BAF"], 0, 0, ["Vehicles", "REMOTE"], "MMA CRV7 Cam", _mcctypeaascript, [-3,2,-2], [0,7,-0.5,0,181], {(driver _plane == player) && ("CRV7_PG" in (_plane weaponsTurret [-1]))}, 0, -2, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";


[["AW159_Lynx_BAF"], 0, "", [], [], 15, 15, 0, [4,3,-2.5], mando_missile_path+"huds\mando_hud_lift.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";
};

