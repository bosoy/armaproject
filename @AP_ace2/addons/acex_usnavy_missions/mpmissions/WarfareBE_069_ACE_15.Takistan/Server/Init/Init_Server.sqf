if (!isServer || time > 30) exitWith {diag_log Format["[WFBE (WARNING)][frameno:%1 | ticktime:%2] Init_Server: The server initialization cannot be called more than once.",diag_frameno,diag_tickTime]};

Private ['_BIS_WF_HQEASTgrp','_BIS_WF_HQEASTgrp2','_BIS_WF_HQWESTgrp','_BIS_WF_HQWESTgrp2','_WF_GroupLogic','_WF_GroupLogic2','_WF_GroupLogic3','_WF_GroupLogic4','_alice','_allies','_attempts','_eastLocation','_i','_locationLogics','_nearLogics','_oc','_ran','_ssd','_starterVehicle','_total','_type','_upArray','_vehicle','_weat','_westLocation'];

diag_log Format["[WFBE (INIT)][frameno:%2 | ticktime:%3] Init_Server: Init Start at %1",time,diag_frameno,diag_tickTime];

//--- Allow resistance group to be spawned without a placeholder.
createCenter resistance;
resistance setFriend [west,0];
resistance setFriend [east,0];

if (paramAI) then {
	AIBuyUnit = Compile preprocessFile "Server\Functions\Server_BuyUnit.sqf";
	if (WF_A2_Vanilla) then {AISquadRespawn = Compile preprocessFile "Server\AI\AI_SquadRespawn.sqf"};
};
if !(WF_A2_Vanilla) then {AIAdvancedRespawn = Compile preprocessFile "Server\AI\AI_AdvancedRespawn.sqf"};
AIMoveTo = Compile preprocessFile "Server\AI\Orders\AI_MoveTo.sqf";
AIPatrol = Compile preprocessFile "Server\AI\Orders\AI_Patrol.sqf";
AITownPatrol = Compile preprocessFile "Server\AI\Orders\AI_TownPatrol.sqf";
AITownResitance = Compile preprocessFile "Server\AI\AI_Resistance.sqf";
AIUpgrade = Compile preprocessFile "Server\AI\AI_Upgrade.sqf";
AIWPAdd = Compile preprocessFile "Server\AI\Orders\AI_WPAdd.sqf";
AIWPRemove = Compile preprocessFile "Server\AI\Orders\AI_WPRemove.sqf";
BuildingDamaged = Compile preprocessFile "Server\Functions\Server_BuildingDamaged.sqf";
if (paramHandleFF) then {BuildingHandleDamages = Compile preprocessFile "Server\Functions\Server_BuildingHandleDamages.sqf"};
BuildingKilled = Compile preprocessFile "Server\Functions\Server_BuildingKilled.sqf";
CanUpdateTeam = Compile preprocessFile "Server\Functions\Server_CanUpdateTeam.sqf";
ChangeAICommanderFunds = Compile preprocessFile "Server\Functions\Server_ChangeAICommanderFunds.sqf";
ConstructDefense = Compile preprocessFile "Server\Construction\Construction_StationaryDefense.sqf";
CreateTeamTemplate = Compile preprocessFile "Server\Functions\Server_CreateTeam.sqf";
CreateDefenseTemplate = Compile preprocessFile "Server\Functions\Server_CreateDefenseTemplate.sqf";
if (paramUseWorkers) then {HandleBuildingRepair = Compile preprocessFile "Server\Functions\Server_HandleBuildingRepair.sqf"};
GetAICommanderFunds = Compile preprocessFile "Server\Functions\Server_GetAICommanderFunds.sqf";
HandleBuildingDamage = Compile preprocessFile "Server\Functions\Server_HandleBuildingDamage.sqf";
HandleDefense = Compile preprocessFile "Server\Functions\Server_HandleDefense.sqf";
HandleReloadDefense = Compile preprocessFile "Server\Functions\Server_HandleReloadDefense.sqf";
HandleEmptyVehicle = Compile preprocessFile "Server\Functions\Server_HandleEmptyVehicle.sqf";
HandleSPVF = Compile preprocessFile "Server\Functions\Server_HandleSPVF.sqf";
HandleSpecial = Compile preprocessFile "Server\Functions\Server_HandleSpecial.sqf";
HQKilled = Compile preprocessFile "Server\Functions\Server_HQKilled.sqf";
MHQRepair = Compile preprocessFile "Server\Functions\Server_MHQRepair.sqf";
SelectOccupTeam = Compile preprocessFile "Server\Functions\Server_SelectOccupTeam.sqf";
SetCampsToSide = Compile preprocessFile "Server\Functions\Server_SetCampsToSide.sqf";
SideMessage = Compile preprocessFile "Server\Functions\Server_SideMessage.sqf";
SVoteForCommander = Compile preprocessFile "Server\Server_VoteForCommander.sqf";
TrashObject = Compile preprocessFile "Server\Functions\Server_TrashObject.sqf";
UpdateTeam = Compile preprocessFile "Server\Functions\Server_UpdateTeam.sqf";
UpdateSupplyTruck = Compile preprocessFile "Server\AI\AI_UpdateSupplyTruck.sqf";

//--- Support Functions.
KAT_ParaAmmo = Compile preProcessfile "Server\Support\Support_ParaAmmo.sqf";
KAT_Paratroopers = Compile preProcessfile "Server\Support\Support_Paratroopers.sqf";
KAT_ParaVehicles = Compile preProcessfile "Server\Support\Support_ParaVehicles.sqf";
KAT_UAV = Compile preProcessfile "Server\Support\Support_UAV.sqf";

//--- Call in NEURO System (Taxi Advanced Script).
[] Call Compile preprocessFile "Server\Module\NEURO\NEURO.sqf";

//--- NEURO: Special Condition.
missionNamespace setVariable["NEURO_TAXI_CONDITION", "isNil {_x getVariable 'WFBE_Taxi_Prohib'}"];

//--- Server Init is now complete.
serverInitComplete = true;

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Functions - [Done]",diag_frameno,diag_tickTime];

//--- Run the MySQL Module if defined.
if (mysql) then {
	WF_Logic setVariable ["WF_MYSQL_CLIENT",[],true];
	WF_Logic setVariable ["WF_MYSQL_SERVER",[Format ["MYSQLDATA?WFBE_Insert_Island?%1?%2",worldName,getText (configFile >> "CfgWorlds" >> worldName >> "description")]]];
	[] ExecFSM "Server\FSM\queryhandler.fsm";
	
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: MySQL Module - [Done]",diag_frameno,diag_tickTime];
};

//--- JIP Handler, handle the joining and leaving players.
onPlayerConnected "[_uid,_name] ExecVM 'Server\Server_PlayerConnected.sqf'";
onPlayerDisconnected "[_uid,_name] ExecVM 'Server\Server_PlayerDisconnected.sqf'";

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: JIP - [Done]",diag_frameno,diag_tickTime];

startingLocations = [];
_total = 0;

//--- Getting all locations.
while {!isNil Format["StartingLocation%1",_total]} do {
	startingLocations = startingLocations + [Call Compile Format["StartingLocation%1",_total]];
	_total = _total + 1;
};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Starting Locations - [Done]",diag_frameno,diag_tickTime];

[] Call Compile preprocessFile 'Server\Init\Init_Defenses.sqf';

//--- Waiting for the common part to be executed.
waitUntil {commonInitComplete && townInit};

//--- Fast Time.
if (('WFBE_FASTTIMERATE' Call GetNamespace) > 0) then {
	[] ExecFSM "Server\FSM\fasttime.fsm";
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Fast Time Module - [Done]",diag_frameno,diag_tickTime];
};

//--- Weather.
_weat = 'WFBE_WEATHER' Call GetNamespace;
if (_weat == 3) then {
	[] ExecFSM "Server\FSM\weather.fsm";
} else {
	if (isDedicated) then {
		_oc = 0.05;
		switch (_weat) do {
			case 0: {_oc = 0};
			case 1: {_oc = 0.5};
			case 2: {_oc = 1};
		};
		60 setOvercast _oc;
	};
};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Weather Module - [Done]",diag_frameno,diag_tickTime];

//--- Static defenses in town main group, they exchange information about enemies.
WF_ResistanceDefenseTeam = createGroup resistance;

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Common and Towns - [Done]",diag_frameno,diag_tickTime];

//--- Select whether the spawn restriction is enabled or not.
_locationLogics = [];
if (paramSpawnRestriction) then {
	{
		_nearLogics = _x nearEntities[["LocationLogic"],2000];
		if (count _nearLogics > 0) then {{if !(_x in _locationLogics) then {_locationLogics = _locationLogics + [_x]}} forEach _nearLogics};
	} forEach towns;
	if (count _locationLogics < 3) then {{if !(_x in _locationLogics) then {_locationLogics = _locationLogics + [_x]}} forEach [StartingLocation0,StartingLocation1]};
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Spawn Restriction - [Done]",diag_frameno,diag_tickTime];
} else {
	_locationLogics = startingLocations;
};

_total = count _locationLogics;

//--- Getting locations that have a distance above the SIDESTARTINGDISTANCE variable.
_westLocation = StartingLocation0;
_eastLocation = StartingLocation0;
switch ('WFBE_STARTINGLOCATIONMODE' Call GetNamespace) do {
	case 0: {_westLocation = StartingLocation0; _eastLocation = StartingLocation1};//--- West North, East South.
	case 1: {_westLocation = StartingLocation1; _eastLocation = StartingLocation0};//--- West South, East North.
	case 2: {
		//--- Random. Attempt to get a location above the given range.
		_attempts = 0;
		_ssd = 'WFBE_SIDESTARTINGDISTANCE' Call GetNamespace;
		
		//--- Random range?.
		if (_ssd == -1) then {_ssd = floor(random(9500))};
		
		while {_eastLocation distance _westLocation < _ssd && _attempts <= 500} do {
			_eastLocation = _locationLogics select (random (_total - 1));
			_westLocation = _locationLogics select (random (_total - 1));
			_attempts = _attempts + 1;
		};

		//--- Couldn't find a starting location in range.
		if (_attempts >= 500) then {
			if (paramSpawnRestriction) then {
				_westLocation = _locationLogics select 0;
				_eastLocation = _locationLogics select ((count _locationLogics)-1);
			} else {
				_westLocation = StartingLocation0;
				_eastLocation = StartingLocation1;
			};
		};
	};
};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Starting Location Mode (%3) - [Done]",diag_frameno,diag_tickTime,('WFBE_STARTINGLOCATIONMODE' Call GetNamespace)];

//--- Moving each non-owner objects to the location.
EastMHQ setPos getPos _eastLocation;
WestMHQ setPos getPos _westLocation;

//--- NEURO Protection.
EastMHQ setVariable ["WFBE_Taxi_Prohib", true];
WestMHQ setVariable ["WFBE_Taxi_Prohib", true];

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: HQ Placement - [Done]",diag_frameno,diag_tickTime];

//--- Friendly Fire handler.
if (paramHandleFF) then {
	EastMHQ addEventHandler ['handleDamage',{[_this select 0,_this select 2,_this select 3, east] Call BuildingHandleDamages}];
	WestMHQ addEventHandler ['handleDamage',{[_this select 0,_this select 2,_this select 3, west] Call BuildingHandleDamages}];
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Friendly Fire Handling - [Done]",diag_frameno,diag_tickTime];
};

eastStartingLocation = _eastLocation;
westStartingLocation = _westLocation;

publicVariable "eastStartingLocation";
publicVariable "westStartingLocation";

//--- Adding a killed EH to both MHQ.
Call Compile Format ["EastMHQ AddEventHandler ['killed',{[_this select 0,_this select 1,%1,'%2'] Spawn HQKilled}];",east,typeOf EastMHQ];
Call Compile Format ["WestMHQ AddEventHandler ['killed',{[_this select 0,_this select 1,%1,'%2'] Spawn HQKilled}];",west,typeOf WestMHQ];

//--- Radio System - Server.
_WF_GroupLogic = createGroup sideLogic;
_WF_GroupLogic2 = createGroup sideLogic;
_WF_GroupLogic3 = createGroup sideLogic;
_WF_GroupLogic4 = createGroup sideLogic;

_BIS_WF_HQEASTgrp = createGroup east;
_BIS_WF_HQWESTgrp = createGroup west;
_BIS_WF_HQEASTgrp2 = createGroup east;
_BIS_WF_HQWESTgrp2 = createGroup west;

BIS_WF_HQEAST = _WF_GroupLogic createUnit ["Logic",[0,0,0],[],0,"NONE"]; [BIS_WF_HQEAST] joinSilent _BIS_WF_HQEASTgrp;
BIS_WF_HQWEST = _WF_GroupLogic2 createUnit ["Logic",[0,0,0],[],0,"NONE"]; [BIS_WF_HQWEST] joinSilent _BIS_WF_HQWESTgrp;
BIS_WF_HQEAST2 = _WF_GroupLogic3 createUnit ["Logic",[0,0,0],[],0,"NONE"]; [BIS_WF_HQEAST2] joinSilent _BIS_WF_HQEASTgrp2;
BIS_WF_HQWEST2 = _WF_GroupLogic4 createUnit ["Logic",[0,0,0],[],0,"NONE"]; [BIS_WF_HQWEST2] joinSilent _BIS_WF_HQWESTgrp2;

BIS_WF_HQEAST_TI = ('WFBE_EASTANNOUNCERS' Call GetNamespace) select round(random((count ('WFBE_EASTANNOUNCERS' Call GetNamespace))-1));
BIS_WF_HQWEST_TI = ('WFBE_WESTANNOUNCERS' Call GetNamespace) select round(random((count ('WFBE_WESTANNOUNCERS' Call GetNamespace))-1));

BIS_WF_HQEAST setIdentity BIS_WF_HQEAST_TI;
BIS_WF_HQEAST setRank 'COLONEL';
BIS_WF_HQEAST setGroupId ["HQ"];
BIS_WF_HQEAST kbAddTopic [BIS_WF_HQEAST_TI,"Client\kb\hq.bikb","Client\kb\hq.fsm",{call compile preprocessFileLineNumbers "Client\kb\hq.sqf"}];

BIS_WF_HQWEST setIdentity BIS_WF_HQWEST_TI;
BIS_WF_HQWEST setRank 'COLONEL';
BIS_WF_HQWEST setGroupId ["HQ"];
BIS_WF_HQWEST kbAddTopic [BIS_WF_HQWEST_TI,"Client\kb\hq.bikb","Client\kb\hq.fsm",{call compile preprocessFileLineNumbers "Client\kb\hq.sqf"}];

publicVariable 'BIS_WF_HQEAST';
publicVariable 'BIS_WF_HQEAST_TI';
publicVariable 'BIS_WF_HQWEST';
publicVariable 'BIS_WF_HQWEST_TI';

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Registered Radio Announcers (West: %3 East: %4) - [Done]",diag_frameno,diag_tickTime,BIS_WF_HQWEST_TI,BIS_WF_HQEAST_TI];

['WFBE_West_TimeUnderAttack',0,true] Call SetNamespace;
['WFBE_East_TimeUnderAttack',0,true] Call SetNamespace;

['WFBE_West_LastCommander',objNull,true] Call SetNamespace;
['WFBE_East_LastCommander',objNull,true] Call SetNamespace;

['WFBE_West_AIBase',false,true] Call SetNamespace;
['WFBE_East_AIBase',false,true] Call SetNamespace;

['WFBE_West_AISupplyTrucks',[],true] Call SetNamespace;
['WFBE_East_AISupplyTrucks',[],true] Call SetNamespace;

['WFBE_West_AICommanderFunds',round(('WFBE_WESTSTARTINGMONEY' Call GetNamespace)*1.5),true] Call SetNamespace;
['WFBE_East_AICommanderFunds',round(('WFBE_EASTSTARTINGMONEY' Call GetNamespace)*1.5),true] Call SetNamespace;

//--- MHQ Tracking.
_text = "";
if (('WFBE_INCOMINGMISSILEMAXRANGE' Call GetNamespace) != 0) then {_text = "this addEventHandler ['IncomingMissile', {_this Spawn HandleIncomingMissile}];"};
EastMHQ setVehicleInit Format["['Headquarters','ColorGreen',[1,1],'','HQUndeployed',this,0.2,false,'','',false,East] ExecVM 'Common\Common_MarkerUpdate.sqf';%1",_text];
processInitCommands;
WestMHQ setVehicleInit Format["['Headquarters','ColorGreen',[1,1],'','HQUndeployed',this,0.2,false,'','',false,West] ExecVM 'Common\Common_MarkerUpdate.sqf';%1",_text];
processInitCommands;

//--- Statistics variables.
WF_Logic setVariable ["eastUnitsCreated",0,true];
WF_Logic setVariable ["eastCasualties",0,true];
WF_Logic setVariable ["eastVehiclesCreated",0,true];
WF_Logic setVariable ["eastVehiclesLost",0,true];
WF_Logic setVariable ["westUnitsCreated",0,true];
WF_Logic setVariable ["westCasualties",0,true];
WF_Logic setVariable ["westVehiclesCreated",0,true];
WF_Logic setVariable ["westVehiclesLost",0,true];

WF_Logic setVariable ["WF_CHQInUse_West",false];
WF_Logic setVariable ["WF_CHQInUse_East",false];

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Stats Variable - [Done]",diag_frameno,diag_tickTime];

//--- Structures (en: it's possible to add location in the array, just make sure that they match the defined type in config_structures).
EastBaseStructures = [];
WestBaseStructures = [];
publicVariable "EastBaseStructures";
publicVariable "WestBaseStructures";

emptyQueu = [];
trashQueu = [];
ignoreQueu = [];

//--- Starting Vehicles East.
{
	_vehicle = [_x,(getPos EastMHQ),east,false] Call CreateVehi;
	[_vehicle,getPos EastMHQ,45,60,true,false,true] Call PlaceNear;
	clearWeaponCargo _vehicle;
	clearMagazineCargo _vehicle;
	emptyQueu = emptyQueu + [_vehicle];
	_vehicle Spawn HandleEmptyVehicle;
} forEach ('WFBE_EASTSTARTINGVEHICLES' Call GetNamespace);
//--- Starting Vehicles West.
{
	_vehicle = [_x,(getPos WestMHQ),west,false] Call CreateVehi;
	[_vehicle,getPos WestMHQ,45,60,true,false,true] Call PlaceNear;
	clearWeaponCargo _vehicle;
	clearMagazineCargo _vehicle;
	emptyQueu = emptyQueu + [_vehicle];
	_vehicle Spawn HandleEmptyVehicle;
} forEach ('WFBE_WESTSTARTINGVEHICLES' Call GetNamespace);

if (paramAI) then {
	//--- Loadout replacement & positioning & variables.
	_i = 1;
	{
		if !(isNil "_x") then {
			if (!isPlayer (leader _x) && alive (leader _x)) then {
				_ran = 1 + round(random(2));
				(leader _x) setPos ([getPos _eastLocation,20,30] Call GetRandomPosition);
				[(leader _x),Format ["WFBE_EASTLEADERWEAPONS0%1",_ran] Call GetNamespace,Format ["WFBE_EASTLEADERAMMO0%1",_ran] Call GetNamespace] Call EquipLoadout;
			};
			_x setVariable ["queue",[]];
			Call Compile Format ["EastSlot%1Funds = %2; publicVariable 'EastSlot%1Funds';",_i,'WFBE_EASTSTARTINGMONEY' Call GetNamespace];
			[_x, false] 	Call SetTeamAutonomous;
			[_x, ""] 		Call SetTeamRespawn;
			[_x, -1] 		Call SetTeamType;
			[_x, "towns"]	Call SetTeamMoveMode;
			[_x, [0,0,0]]	Call SetTeamMovePos;
			if (('WFBE_ISIS' Call GetNamespace) != 0) then {(leader _x) addEventHandler['handleDamage',{_this Call ISIS_Wound}]};
			if !(WF_A2_Vanilla) then {(_x) Call Compile preprocessFile 'Server\AI\AI_AddMultiplayerRespawnEH.sqf'};
			diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: East AI Team (%3) Full Init - [Done]",diag_frameno,diag_tickTime,_x];
		};
		_i = _i + 1;
	} forEach ('WFBE_EASTTEAMS' Call GetNamespace);
	_i = 1;
	{
		if !(isNil "_x") then {
			if (!isPlayer (leader _x) && alive (leader _x)) then {
				_ran = 1 + round(random(2));
				(leader _x) setPos ([getPos _westLocation,20,30] Call GetRandomPosition);
				[(leader _x),Format ["WFBE_WESTLEADERWEAPONS0%1",_ran] Call GetNamespace,Format ["WFBE_WESTLEADERAMMO0%1",_ran] Call GetNamespace] Call EquipLoadout;
			};
			_x setVariable ["queue",[]];
			Call Compile Format ["WestSlot%1Funds = %2; publicVariable 'WestSlot%1Funds';",_i,'WFBE_WESTSTARTINGMONEY' Call GetNamespace];
			[_x, false] 	Call SetTeamAutonomous;
			[_x, ""] 		Call SetTeamRespawn;
			[_x, -1] 		Call SetTeamType;
			[_x, "towns"]	Call SetTeamMoveMode;
			[_x, [0,0,0]]	Call SetTeamMovePos;
			if (('WFBE_ISIS' Call GetNamespace) != 0) then {(leader _x) addEventHandler['handleDamage',{_this Call ISIS_Wound}]};
			if !(WF_A2_Vanilla) then {(_x) Call Compile preprocessFile 'Server\AI\AI_AddMultiplayerRespawnEH.sqf'};
			diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: West AI Team (%3) Full Init - [Done]",diag_frameno,diag_tickTime,_x];
		};
		_i = _i + 1;
	} forEach ('WFBE_WESTTEAMS' Call GetNamespace);
	
	//--- AI Supply Trucks.
	if (('WFBE_SUPPLYSYSTEM' Call GetNamespace) == 0) then {
		[east] Spawn UpdateSupplyTruck;
		[west] Spawn UpdateSupplyTruck;
		diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Truck Supply System - [Done]",diag_frameno,diag_tickTime];
	};
	
	//--- AI Teams (Don't pause the server initialization process).
	[] Spawn {
		waitUntil{townInit};
		{if (!isNil "_x") then {[_x] ExecFSM "Server\FSM\aiteam.fsm"}} forEach ('WFBE_EASTTEAMS' Call GetNamespace);
		{if (!isNil "_x") then {[_x] ExecFSM "Server\FSM\aiteam.fsm"}} forEach ('WFBE_WESTTEAMS' Call GetNamespace);
		diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: AI Teams FSM - [Done]",diag_frameno,diag_tickTime];
	};
} else {
	_i = 1;
	{
		if !(isNil "_x") then {
			Call Compile Format ["EastSlot%1Funds = %2; publicVariable 'EastSlot%1Funds';",_i,'WFBE_EASTSTARTINGMONEY' Call GetNamespace];
			_x setVariable ["identification", Format["EastSlot%1",_i]];
			[_x, false] 	Call SetTeamAutonomous;
			[_x, ""] 		Call SetTeamRespawn;
			[_x, -1] 		Call SetTeamType;
			diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: East AI Team (%3) Partial Init - [Done]",diag_frameno,diag_tickTime,_x];
		};
		_i = _i + 1;
	} forEach ('WFBE_EASTTEAMS' Call GetNamespace);
	_i = 1;
	{
		if !(isNil "_x") then {
			Call Compile Format ["WestSlot%1Funds = %2; publicVariable 'WestSlot%1Funds';",_i,'WFBE_WESTSTARTINGMONEY' Call GetNamespace];
			_x setVariable ["identification", Format["WestSlot%1",_i]];
			[_x, false] 	Call SetTeamAutonomous;
			[_x, ""] 		Call SetTeamRespawn;
			[_x, -1] 		Call SetTeamType;
			diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: West AI Team (%3) Partial Init - [Done]",diag_frameno,diag_tickTime,_x];
		};
		_i = _i + 1;
	} forEach ('WFBE_WESTTEAMS' Call GetNamespace);
};

//--- Town starting mode.
if (('WFBE_TOWNSTARTINGMODE' Call GetNamespace) != 0 || ('WFBE_RESPATROL' Call GetNamespace) > 0 || ('WFBE_RESSTRIKER' Call GetNamespace) > 0) then {[] Call Compile preprocessFile "Server\Init\Init_Towns.sqf"};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Starting Vehicles - [Done]",diag_frameno,diag_tickTime];

//--- Pre-initialization of the Garbage Collector & Empty vehicle collector.
if (WF_A2_Vanilla) then {WF_Logic setVariable ["trash",[],true]};
WF_Logic setVariable ["emptyVehicles",[],true];

//--- Civilians Module.
if (('WFBE_CIVILIANFACTION' Call GetNamespace) > 0) then {
	//--- Create a group center.
	createCenter civilian;
	//--- Civilian Kill function.
	CivilianKilled = Compile preprocessFile "Common\Functions\Common_CivilianKilled.sqf";
	//--- Execute the config file.
	[] Call Compile preprocessFile "Server\Config\Config_Civilians.sqf";
};

//--- Don't pause the server init script.
[] Spawn {
	waitUntil {townInit};
	[] ExecFSM "Server\FSM\updateserver.fsm";
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server (Delayed): Server Module - [Done]",diag_frameno,diag_tickTime];
	[] ExecFSM "Server\FSM\updateresources.fsm";
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server (Delayed): Ressources Module - [Done]",diag_frameno,diag_tickTime];
};
[] ExecFSM "Server\FSM\garbagecollector.fsm";
diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Garbage Collector Module - [Done]",diag_frameno,diag_tickTime];
[] ExecFSM "Server\FSM\emptyvehiclescollector.fsm";
diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Empty Vehicles Collector Module - [Done]",diag_frameno,diag_tickTime];

//--- Network System Part 2.
EastMHQDeployed = false; publicVariable 'EastMHQDeployed';
WestMHQDeployed = false; publicVariable 'WestMHQDeployed';

WFBE_East_Upgrading = false; publicVariable 'WFBE_East_Upgrading';
WFBE_West_Upgrading = false; publicVariable 'WFBE_West_Upgrading';

if !(paramMoneyOnly) then {
	WF_Logic setVariable ["EastSupplies",EastSupplies,true];
	WF_Logic setVariable ["WestSupplies",WestSupplies,true];
};

WF_Logic setVariable ["EastCommanderVoteTime",60,true];
WF_Logic setVariable ["WestCommanderVoteTime",60,true];

WF_Logic setVariable ["EastCommanderTeam",EastCommanderTeam,true];
WF_Logic setVariable ["WestCommanderTeam",WestCommanderTeam,true];

WF_Logic setVariable ["EastMHQRepair",false,true];
WF_Logic setVariable ["WestMHQRepair",false,true];

//--- Upgrades.
_upArray = if (paramUpgradesEast) then {[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]} else {'WFBE_UPGRADELEVELS' Call GetNamespace};
EASTUpgrades = _upArray;
PublicVariable 'EASTUpgrades';
_upArray = if (paramUpgradesWest) then {[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]} else {'WFBE_UPGRADELEVELS' Call GetNamespace};
WESTUpgrades = _upArray;
PublicVariable 'WESTUpgrades';

//--- Building Limits.
WestBuildingsCurrent = [];
EastBuildingsCurrent = [];
for '_i' from 0 to ((count ('WFBE_WESTSTRUCTURES' Call GetNamespace))-2) do {WestBuildingsCurrent set [_i, 0]};
for '_i' from 0 to ((count ('WFBE_EASTSTRUCTURES' Call GetNamespace))-2) do {EastBuildingsCurrent set [_i, 0]};
PublicVariable 'WestBuildingsCurrent';
PublicVariable 'EastBuildingsCurrent';

if (paramRespawnMASH) then {
	WF_Logic setVariable ["EastMASH",objNull,true];
	WF_Logic setVariable ["WestMASH",objNull,true];
};

//--- Base Area (grouped base)
if (paramBaseArea) then {
	WF_Logic setVariable ["EastArea",[],true];
	WF_Logic setVariable ["WestArea",[],true];
	
	[] ExecFSM "Server\FSM\basearea.fsm";
};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Network Variables - [Done]",diag_frameno,diag_tickTime];

//--- Allies base.
_allies = 'WFBE_ALLIES' Call GetNamespace;
if (_allies > 0 && (WF_A2_Vanilla || WF_A2_CombinedOps)) then {
	AlliesBuyUnit = Compile preprocessFile "Server\Functions\Server_AlliesBuyUnit.sqf";
	[] Call Compile preprocessFile "Server\Config\Config_Allies.sqf";
	if (_allies in [1,3]) then {[west] ExecFSM "Server\FSM\allies.fsm"};
	if (_allies in [2,3]) then {[east] ExecFSM "Server\FSM\allies.fsm"};

	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Allies Module - [Done]",diag_frameno,diag_tickTime];
};

//--- Use Workers?
if (paramUseWorkers) then {
	WF_WestWorkers = [];
	publicVariable "WF_WestWorkers";
	WF_EastWorkers = [];
	publicVariable "WF_EastWorkers";
	
	["WFBE_WORKERS_WESTLOGIC",[],true] Call SetNamespace;
	["WFBE_WORKERS_EASTLOGIC",[],true] Call SetNamespace;
};

//--- Create base / town defenses group.
WF_DefenseWestGrp = createGroup west;
WF_DefenseEastGrp = createGroup east;

//--- ALICE Module.
if (paramAlice) then {
	_type = if (WF_A2_Vanilla) then {'AliceManager'} else {'Alice2Manager'};
	(createGroup sideLogic) createUnit [_type,[0,0,0],[],0,"NONE"];
	
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: ALICE Module - [Done]",diag_frameno,diag_tickTime];
};

//--- Mission Module
if (paramSecondaryMissions) then {
	ExecFSM 'Server\FSM\missions.fsm';

	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Server: Missions Init - [Done]",diag_frameno,diag_tickTime];
};

//--- UPSMON AI
if (paramUPSMON) then {
	Call Compile preprocessFileLineNumbers "Server\Module\UPSMON\Init_UPSMON.sqf";
};

diag_log Format["[WFBE (INIT)][frameno:%2 | ticktime:%3] Init_Server: Init End at %1",time,diag_frameno,diag_tickTime];

//--- Waiting until that the game is launched.
waitUntil {time > 0};

//--- Launch votes.
[East] Spawn SVoteForCommander;
[West] Spawn SVoteForCommander;