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

// Create the radar tower
_name = "TK_WarfareBAntiAirRadar_Base_EP1" createVehicle _spot2;

// Name it randomly "radar_87" for example.
_unitname = format["radar_%1", floor(random 100)];
_name setVehicleInit format ["%1 = this; this setVehicleVarName ""%1""",_unitname];
processInitCommands;

// Create a marker at the tower.
_marker = createMarker["MRK_radiotower",getPos _name];
_marker setMarkerShape "ICON";
_marker setMarkerType "FLAG";
_marker setMarkerText "Radio Tower";
_marker setMarkerSize [.50, .50];

// Create a trigger at the tower.
_trigger = createTrigger["EmptyDetector", getPos _name]; 
_trigger setTriggerArea[0,0,0,false];
_trigger setTriggerActivation["None","PRESENT",true];
_trigger setTriggerStatements[format["!alive %1",_name], "OBJ_RADIOTOWER setTaskState ""Succeeded"";taskhint [""COMPLETED TASK:\nDestroy Radio Tower"", [0, 1, 0, 0.66], ""taskDone""]; deleteMarker ""MRK_radiotower"";", ""]; 

// Create a task to destroy the tower.
OBJ_RADIOTOWER = player createSimpleTask ["Destroy Radio Tower"];
OBJ_RADIOTOWER setSimpleTaskDescription ["<br />Cut down the enemy communications system by blowing up their radio tower.","Destroy Radio Tower","Destroy Radio Tower"];
OBJ_RADIOTOWER setSimpleTaskDestination (getMarkerPos _marker);
//OBJ_RADIOTOWER setTaskState "Assigned";
//player setCurrentTask OBJ_RADIOTOWER;
//taskhint ["Destroy the Radar Tower", [1, 1, 1, 0.66], "taskCurrent"];

if (true) exitWith{};