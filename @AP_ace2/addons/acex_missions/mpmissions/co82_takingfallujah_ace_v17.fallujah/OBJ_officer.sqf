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
OfficerGRP = createGroup EAST;

  _name = OfficerGRP createUnit ["TK_Soldier_Officer_EP1", _spot2, [], 0, "NONE"];
  _name setRank "CAPTAIN";
  escort1a = OfficerGRP createUnit ["TK_Soldier_Sniper_EP1", _spot2, [], 0, "NONE"];
  escort1b = OfficerGRP createUnit ["TK_Soldier_AR_EP1", _spot2, [], 0, "NONE"];
  escort1c = OfficerGRP createUnit ["TK_Soldier_Medic_EP1", _spot2, [], 0, "NONE"];

  OfficerGRP setBehaviour "AWARE";
  OfficerGRP setSpeedMode "NORMAL";
  OfficerGRP setCombatMode "YELLOW";

  waituntil {!isnil "bis_fnc_init"};
  [OfficerGRP, _marker, _radius] call bis_fnc_taskPatrol;

// Name it randomly "radar_87" for example.
_unitname = format["officer_%1", floor(random 100)];
_name setVehicleInit format ["%1 = this; this setVehicleVarName ""%1""",_unitname];
processInitCommands;

// Create a marker at the tower.
_marker = createMarker["MRK_officer",getPos _name];
_marker setMarkerShape "ICON";
_marker setMarkerType "FLAG";
_marker setMarkerText "Takistani Officer Last Known Position";
_marker setMarkerSize [.50, .50];

// Create a trigger at the tower.
_trigger = createTrigger["EmptyDetector", getPos _name]; 
_trigger setTriggerArea[0,0,0,false];
_trigger setTriggerActivation["None","PRESENT",true];
_trigger setTriggerStatements[format["!alive %1",_name], "OBJ_OFFICER setTaskState ""Succeeded"";taskhint [""COMPLETED TASK:\nKill Enemy Officer"", [0, 1, 0, 0.66], ""taskDone""]; deleteMarker ""MRK_officer"";", ""];

// Create a task to destroy the tower.
OBJ_OFFICER = player createSimpleTask ["Kill Enemy Officer"];
OBJ_OFFICER setSimpleTaskDescription ["<br />A high-rank officer is commanding the operations in the area. It is very important that you neutralize him in order to throw the enemy units into chaos.","Kill Enemy Officer","Kill Enemy Officer"];
OBJ_OFFICER setSimpleTaskDestination (getMarkerPos _marker);
//OBJ_OFFICER setTaskState "Assigned";
//player setCurrentTask OBJ_OFFICER;
//taskhint ["Destroy the Radar Tower", [1, 1, 1, 0.66], "taskCurrent"];

if (true) exitWith{};