//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Reezo of SR5 Tactical - www.sr5tactical.net
// Radio Tower creation script by Pirin
// Tweaks by Reezo
//////////////////////////////////////////////////////////////////

if (!isServer) exitWith{};

// get starting spot and range
_marker = _this select 0;
_radius = _this select 1;
_pos = getmarkerpos _marker;
//_radius = 100;

// Find a good spot for the spawn (open area, not in trees)
//_exp = "(1 + meadow) * (1 - forest) * (1 - trees)"; OLD PARAMETER, DOESN'T WORK WELL WITH FALLUJAH
_exp = "1";
_prec = 100;
_bestplace = selectBestPlaces [_pos,_radius,_exp,_prec,1];
_spot = _bestplace select 0;
_spot2 = _spot select 0;

// Create the officer and his escort
AA3GRP = createGroup EAST;
_name = "ZU23_TK_EP1" createVehicle _spot2;
  
  escortAA3a = AA3GRP createUnit ["TK_Soldier_HAT_EP1", _spot2, [], 0, "NONE"];
  escortAA3a setRank "CORPORAL";
  escortAA3b = AA3GRP createUnit ["TK_Soldier_AAT_EP1", _spot2, [], 0, "NONE"];
  escortAA3c = AA3GRP createUnit ["TK_Soldier_AR_EP1", _spot2, [], 0, "NONE"];
  
  escortAA3a moveinGunner _name;
  _name lock TRUE;
  
  waituntil {!isnil "bis_fnc_init"};
  [AA3GRP, getPos escortAA3a] call bis_fnc_taskDefend;

// Name it randomly "radar_87" for example.
_unitname = format["AA3_%1", floor(random 100)];
_name setVehicleInit format ["%1 = this; this setVehicleVarName ""%1""",_unitname];
processInitCommands;

// Create a marker at the tower.
_marker = createMarker["MRK_antiair3",getPos _name];
_marker setMarkerShape "ICON";
_marker setMarkerType "FLAG";
_marker setMarkerText "Anti-Air Site";
_marker setMarkerSize [.50, .50];

// Create a trigger at the tower.
_trigger = createTrigger["EmptyDetector", getPos _name]; 
_trigger setTriggerArea[0,0,0,false];
_trigger setTriggerActivation["None","PRESENT",true];
_trigger setTriggerStatements[format["!alive %1",_name], "OBJ_AA3 setTaskState ""Succeeded"";taskhint [""COMPLETED TASK:\nNeutralize AA Site"", [0, 1, 0, 0.66], ""taskDone""]; deleteMarker ""MRK_antiair3"";", ""]; 

// Create a task to destroy the tower.
OBJ_AA3 = player createSimpleTask ["Neutralize AA Site"];
OBJ_AA3 setSimpleTaskDescription ["<br />The city is well defended by a group of AA sites. Destroy them to make full use of our CAS capabilities.","Neutralize AA Site","Neutralize AA Site"];
OBJ_AA3 setSimpleTaskDestination (getMarkerPos _marker);
//OBJ_AA3 setTaskState "Assigned";
//player setCurrentTask OBJ_AA3;
//taskhint ["Destroy the Radar Tower", [1, 1, 1, 0.66], "taskCurrent"];

if (true) exitWith{};