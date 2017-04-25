// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };



   // BIS C130J cameras setup (onboard guns)
   _background_mfd = [];

//
   // C130J cameras setup (scripted light gun AG mode)
   _mcc_tv_script = "mando_missiles\tv\tv_types\mando_tv_gun.sqs";
   [["C130J","C130J_US_EP1","ADF_C130J"], 90, 90, ["Vehicles"], "L. Gun Cam Ground mode", _mcc_tv_script, [-2,0,-2,5], [-3,0,-2,-90,80], {(driver _plane != player) && (((_plane worldToModel (positionCameraToWorld [0,0,0])) distance [0.5, 12.33, -2.06]) < 5)}, -1, 0, _background_mfd, 0.5, 0]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // C130J cameras setup (scripted heavy gun AG mode)
   _mcc_tv_script = "mando_missiles\tv\tv_types\mando_tv_hgun.sqs";
   [["C130J","C130J_US_EP1","ADF_C130J"], 10, 10, ["Vehicles"], "H. Gun Cam Ground mode", _mcc_tv_script, [-2,0,-2,5], [-3,0,-2,-90,80], {(driver _plane != player) && (((_plane worldToModel (positionCameraToWorld [0,0,0])) distance [0.5, 12.33, -2.06]) < 5)}, -1, 1, _background_mfd, 1, 0]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // C130J cameras setup (scripted 40mm gun AG mode)
   _mcc_tv_script = mando_missile_path+"tv\tv_types\mando_tv_40mm.sqs";
   [["C130J","C130J_US_EP1","ADF_C130J"], 40, 40, ["Vehicles"], "40mm Gun Cam Ground mode", _mcc_tv_script, [-2,0,-2,5], [-3,0,-2,-90,80], {(driver _plane != player) && (((_plane worldToModel (positionCameraToWorld [0,0,0])) distance [0.5, 12.33, -2.06]) < 5)}, -1, 2, _background_mfd, 1, 0]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // C130J HUD setup (only flares and ECM)
   [["C130J","C130J_US_EP1","ADF_C130J"], 0, "", [1], [1], 20, 20, 20, [4,3,-7], mando_missile_path+"huds\mando_hud_c130j.sqf", 0, 0, [], 0]execVm"mando_missiles\units\mando_assignvehicle_by_type.sqf";

};
