// The following scripts are for players only, no need to run on dedi servers
[]spawn
{
   while {!alive player} do
   {
      Sleep 1;
   };

   _background_mfd = [];

   // AH64 cameras setup (8 onboard hellfires)
   _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire_ace_apache.sqs";
   [["AH64D","AH64D_Sidewinders","AH64D_EP1","BAF_Apache_AH1_D"], 0, 0, ["Vehicles"], "MMA AGM-114L", _mcctypeaascript, [-3,2,-2], [0.05,6.5,-.25,0,181], {(driver _plane == player) && ("ACE_HellfireLauncher_Apache" in weapons _plane) && !(isPlayer gunner _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";

   // AH64 cameras setup (8 onboard hellfires)
    _mcctypeaascript = "mando_missiles\tv\tv_types\mando_tv_hellfire_ace_apache.sqs";
[["AH64D","AH64D_Sidewinders","AH64D_EP1","BAF_Apache_AH1_D"], 0, 0, ["Vehicles"], "MMA AGM-114L", _mcctypeaascript, [-3,2,-2], [0.1,6.5,0,0,181], {(gunner _plane == player) && ("ACE_HellfireLauncher_Apache" in weapons _plane)}, 0, -1, _background_mfd, 1, -3]execVM"mando_missiles\mcc\mando_mccallow_by_type.sqf";
};
