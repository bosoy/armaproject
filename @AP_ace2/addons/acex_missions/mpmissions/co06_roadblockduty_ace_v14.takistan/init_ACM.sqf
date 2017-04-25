//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Assembled by: Reezo of SR5 Tactical - www.sr5tactical.net
// This script initializes the Ambient Combat Parameters.
// I've gathered most of these info from forums, so it's nothing I've really come up with..
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

//ACM settings    
waitUntil {!isNil {BIS_ACM getVariable "initDone"}};
waitUntil {BIS_ACM getVariable "initDone"};

_intenzity = 0.22;
if (isMultiplayer) then { _intenzity = (paramsArray select 11) / 100; };

[] spawn {
  waitUntil {!(isnil "BIS_fnc_init")};
  [_intenzity, BIS_ACM1] call BIS_ACM_setIntensityFunc;               //Sets the intensity of the ACM, in other words, determines how active it will be. Starts at 0 ends at 1.0, its been known to fail using 0.7 and 0.8
  [BIS_ACM1, 400, 700] call BIS_ACM_setSpawnDistanceFunc;      // This is the radius on where the units will spawn around the unit the module is sync'd to, 400m being the minimal distance and 700m being the maximum. Minimum is 1 I believe. 
  [["BIS_TK_INS"], BIS_ACM1] call BIS_ACM_setFactionsFunc;     // This tells the ACM which faction of units it will spawn. In this case it will spawn Takistani Insurgents
  [0, 0.66, BIS_ACM1] call BIS_ACM_setSkillFunc;                // This determines what the skill rating for the spawned units will be
  [0.2, 0.5, BIS_ACM1] call BIS_ACM_setAmmoFunc;               // This sets their amount of ammo they spawn with
  ["ground_patrol", 0.9, BIS_ACM1] call BIS_ACM_setTypeChanceFunc; //If you want ground patrols then leave it as a 1, if you don't put a 0. They will use random paths
  ["air_patrol", 0.1, BIS_ACM1] call BIS_ACM_setTypeChanceFunc;    // Same thing for air patrols
  [BIS_ACM1, ["TK_INS_Group", "TK_INS_Patrol", "TK_INS_AATeam", "TK_INS_ATTeam", "TK_INS_Technicals", "TK_INS_MotorizedGroup"]] call BIS_ACM_addGroupClassesFunc;   // This determines which exact units will spawn from the group **Citation needed**
};

// Debug
if (!isMultiplayer) then {
  sleep 1;
  player globalChat "INIT_ACM COMPLETED";
  sleep 1;
};
   
if (true) exitWith{};