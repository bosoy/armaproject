private ['_count'];
diag_log Format["[WFBE (INIT)][frameno:%2 | ticktime:%3] Init_Common: Init Start at %1",time,diag_frameno,diag_tickTime];

Private ['_count'];

if (paramBalancing) then {BalanceInit = Compile preprocessFile "Common\Functions\Common_BalanceInit.sqf"};
if !(WF_A2_Vanilla) then {
	BackpackHasSpace = Compile preprocessFile "Common\Functions\Common_BackpackHasSpace.sqf";
	EquipBackpack = Compile preprocessFile "Common\Functions\Common_EquipBackpack.sqf";
};
BuildingInRange = Compile preprocessFile "Common\Functions\Common_BuildingInRange.sqf";
ChangeSideSupply = Compile preprocessFile "Common\Functions\Common_ChangeSideSupply.sqf";
ChangeTeamFunds = Compile preprocessFile "Common\Functions\Common_ChangeTeamFunds.sqf";
CreateMan = Compile preprocessFile "Common\Functions\Common_CreateUnit.sqf";
CreateVehi = Compile preprocessFile "Common\Functions\Common_CreateVehicle.sqf";
EquipArtillery = Compile preprocessFile "Common\Functions\Common_EquipArtillery.sqf";
EquipLoadout = Compile preprocessFile "Common\Functions\Common_EquipLoadout.sqf";
FireArtillery = Compile preprocessFile "Common\Functions\Common_FireArtillery.sqf";
GetAIDigit = Compile preprocessFile "Common\Functions\Common_GetAIDigit.sqf";
GetClientID = Compile preprocessFile "Common\Functions\Common_GetClientID.sqf";
GetClientTeam = Compile preprocessFile "Common\Functions\Common_GetClientTeam.sqf";
GetClosestLocation = Compile preprocessFile "Common\Functions\Common_GetClosestLocation.sqf";
GetClosestLocationBySide = Compile preprocessFile "Common\Functions\Common_GetClosestLocationBySide.sqf";
GetCommanderFromVotes = Compile preprocessFile "Common\Functions\Common_GetCommanderFromVotes.sqf";
GetCommanderTeam = Compile preprocessFile "Common\Functions\Common_GetCommanderTeam.sqf";
GetCommanderVotes = Compile preprocessFile "Common\Functions\Common_GetCommanderVotes.sqf";
GetConfigInfo = Compile preprocessFile "Common\Functions\Common_GetConfigInfo.sqf";
GetFactories = Compile preprocessFile "Common\Functions\Common_GetFactories.sqf";
GetFriendlyCamps = Compile preprocessFile "Common\Functions\Common_GetFriendlyCamps.sqf";
GetGroupFromConfig = Compile preprocessFile "Common\Functions\Common_GetGroupFromConfig.sqf";
GetHostilesInArea = Compile preprocessFile "Common\Functions\Common_GetHostilesInArea.sqf";
GetLiveUnits = Compile preprocessFile "Common\Functions\Common_GetLiveUnits.sqf";
GetNamespace = Compile preprocessFile "Common\Functions\Common_GetNamespace.sqf";
GetPositionFrom = Compile preprocessFile "Common\Functions\Common_GetPositionFrom.sqf";
GetRandomPosition = Compile preprocessFile "Common\Functions\Common_GetRandomPosition.sqf";
GetRespawnCamps = Compile preprocessFile "Common\Functions\Common_GetRespawnCamps.sqf";
GetSafePlace = Compile preprocessFile "Common\Functions\Common_GetSafePlace.sqf";
GetSideFromID = Compile preprocessFile "Common\Functions\Common_GetSideFromID.sqf";
GetSideHQ = Compile preprocessFile "Common\Functions\Common_GetSideHQ.sqf";
GetSideHQDeployed = Compile preprocessFile "Common\Functions\Common_GetSideHQDeployed.sqf";
GetSideID = Compile preprocessFile "Common\Functions\Common_GetSideID.sqf";
GetSideStructures = Compile preprocessFile "Common\Functions\Common_GetSideStructures.sqf";
GetSideSupply = Compile preprocessFile "Common\Functions\Common_GetSideSupply.sqf";
GetSideUpgrades = Compile preprocessFile "Common\Functions\Common_GetSideUpgrades.sqf";
GetSideTowns = Compile preprocessFile "Common\Functions\Common_GetSideTowns.sqf";
GetSleepFPS = Compile preprocessFile "Common\Functions\Common_GetSleepFPS.sqf";
GetTeamArtillery = Compile preprocessFile "Common\Functions\Common_GetTeamArtillery.sqf";
GetTeamAutonomous = Compile preprocessFile "Common\Functions\Common_GetTeamAutonomous.sqf";
GetTeamFunds = Compile preprocessFile "Common\Functions\Common_GetTeamFunds.sqf";
GetTeamMoveMode = Compile preprocessFile "Common\Functions\Common_GetTeamMoveMode.sqf";
GetTeamMovePos = Compile preprocessFile "Common\Functions\Common_GetTeamMovePos.sqf";
GetTeamRespawn = Compile preprocessFile "Common\Functions\Common_GetTeamRespawn.sqf";
GetTeamType = Compile preprocessFile "Common\Functions\Common_GetTeamType.sqf";
GetTeamVehicles = Compile preprocessFile "Common\Functions\Common_GetTeamVehicles.sqf";
GetTotalCamps = Compile preprocessFile "Common\Functions\Common_GetTotalCamps.sqf";
GetTotalCampsOnSide = Compile preprocessFile "Common\Functions\Common_GetTotalCampsOnSide.sqf";
GetTotalSupplyValue = Compile preprocessFile "Common\Functions\Common_GetTotalSupplyValue.sqf";
GetTownsHeld = Compile preprocessFile "Common\Functions\Common_GetTownsHeld.sqf";
GetTownsIncome = Compile preprocessFile "Common\Functions\Common_GetTownsIncome.sqf";
GetUnitsBelowHeight = Compile preprocessFile "Common\Functions\Common_GetUnitsBelowHeight.sqf";
GetUnitVehicle = Compile preprocessFile "Common\Functions\Common_GetUnitVehicle.sqf";
HandleArtillery = Compile preprocessFile "Common\Functions\Common_HandleArtillery.sqf";
HandleIncomingMissile = Compile preprocessFile "Common\Functions\Common_HandleIncomingMissile.sqf";
IsArtillery = Compile preprocessFile "Common\Functions\Common_IsArtillery.sqf";
MarkerUpdate = Compile preprocessFile "Common\Common_MarkerUpdate.sqf";
PlaceNear = Compile preprocessFile "Common\Functions\Common_PlaceNear.sqf";
PlaceSafe = Compile preprocessFile "Common\Functions\Common_PlaceSafe.sqf";
if !(WF_A2_Vanilla) then {
	GetTurretsMags = Compile preprocessFile "Common\Functions\Common_GetTurretsMags.sqf";
	GetVehicleMags = Compile preprocessFile "Common\Functions\Common_GetVehicleMags.sqf";
	RearmVehicle = Compile preprocessFile "Common\Functions\Common_RearmVehicleOA.sqf";
	SetTurretsMags = Compile preprocessFile "Common\Functions\Common_SetTurretsMags.sqf";
} else {
	RearmVehicle = Compile preprocessFile "Common\Functions\Common_RearmVehicle.sqf";
};
RevealArea = Compile preprocessFile "Common\Functions\Common_RevealArea.sqf";
SetCommanderVotes = Compile preprocessFile "Common\Functions\Common_SetCommanderVotes.sqf";
SetNamespace = Compile preprocessFile "Common\Functions\Common_SetNamespace.sqf";
SetTeamAutonomous = Compile preprocessFile "Common\Functions\Common_SetTeamAutonomous.sqf";
SetTeamRespawn = Compile preprocessFile "Common\Functions\Common_SetTeamRespawn.sqf";
SetTeamMoveMode = Compile preprocessFile "Common\Functions\Common_SetTeamMoveMode.sqf";
SetTeamMovePos = Compile preprocessFile "Common\Functions\Common_SetTeamMovePos.sqf";
SetTeamType = Compile preprocessFile "Common\Functions\Common_SetTeamType.sqf";
SpawnTurrets = Compile preprocessFile "Common\Functions\Common_SpawnTurrets.sqf";
SortByDistance = Compile preprocessFile "Common\Functions\Common_SortByDistance.sqf";
UnitKilled = Compile preprocessFile "Common\Functions\Common_UnitKilled.sqf";
UpdateStatistics = Compile preprocessFile "Common\Functions\Common_UpdateStatistics.sqf";
UseStationaryDefense = Compile preprocessFile "Common\Functions\Common_UseStationaryDefense.sqf";
if (paramICBM) then {
	NukeDammage = Compile preprocessFile "Client\Module\Nuke\damage.sqf";
	NukeRadiation = Compile preprocessFile "Client\Module\Nuke\radzone.sqf";
};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Common: Functions - [Done]",diag_frameno,diag_tickTime];

varQueu = (random 10)+(random 100)+(random 1000);

EastCommanderTeam = ObjNull;
WestCommanderTeam = ObjNull;

/* Starting Supply */
if (isNil "EastSupplies") then {EastSupplies = if (WF_Debug) then {900000} else {1200}};
if (isNil "WestSupplies") then {WestSupplies = if (WF_Debug) then {900000} else {1200}};

diag_log Format["[WFBE (INIT)][frameno:%3 | ticktime:%4] Init_Common: Starting Supply (West: %1 East: %2) - [Done]",WestSupplies,EastSupplies,diag_frameno,diag_tickTime];

/* Starting Money */
['WFBE_EASTSTARTINGMONEY',if (WF_Debug) then {900000} else {800},false] Call SetNamespace;
['WFBE_WESTSTARTINGMONEY',if (WF_Debug) then {900000} else {800},false] Call SetNamespace;

diag_log Format["[WFBE (INIT)][frameno:%3 | ticktime:%4] Init_Common: Starting Funds (West: %1 East: %2) - [Done]",'WFBE_WESTSTARTINGMONEY' Call GetNamespace,'WFBE_EASTSTARTINGMONEY' Call GetNamespace,diag_frameno,diag_tickTime];

/* Allies */
if (('WFBE_ALLIES' Call GetNamespace) > 0) then {
	westAlliesFunds = ('WFBE_WESTSTARTINGMONEY' Call GetNamespace)*5;
	eastAlliesFunds = ('WFBE_EASTSTARTINGMONEY' Call GetNamespace)*5;
	
	diag_log Format["[WFBE (INIT)][frameno:%3 | ticktime:%4] Init_Common: Allies Starting Funds (West: %1 East: %2) - [Done]",('WFBE_WESTSTARTINGMONEY' Call GetNamespace)*5,('WFBE_EASTSTARTINGMONEY' Call GetNamespace)*5,diag_frameno,diag_tickTime];
};

unitMarker = 0;

for [{_count = 0},{_count < maxPlayers},{_count = _count + 1}] do {
	Call Compile Format["if (IsNil 'EastTeam%1Vote') then {EastTeam%1Vote = -1}",_count + 1];
	Call Compile Format["if (IsNil 'WestTeam%1Vote') then {WestTeam%1Vote = -1}",_count + 1];
};

/* Respawn Markers */
createMarkerLocal ["respawn_east",getMarkerPos "EastTempRespawnMarker"];
"respawn_east" setMarkerColorLocal "ColorGreen";
"respawn_east" setMarkerShapeLocal "RECTANGLE";
"respawn_east" setMarkerBrushLocal "BORDER";
"respawn_east" setMarkerSizeLocal [15,15];
"respawn_east" setMarkerAlphaLocal 0;
createMarkerLocal ["respawn_west",getMarkerPos "WestTempRespawnMarker"];
"respawn_west" setMarkerColorLocal "ColorGreen";
"respawn_west" setMarkerShapeLocal "RECTANGLE";
"respawn_west" setMarkerBrushLocal "BORDER";
"respawn_west" setMarkerSizeLocal [15,15];
"respawn_west" setMarkerAlphaLocal 0;

/* Prepare the common constants */
[] Call Compile preprocessFile "Common\Init\Init_CommonConstants.sqf";

if (('WFBE_ISIS' Call GetNamespace) != 0) then {
	ISIS_Heal = Compile preprocessFile "Client\Module\ISIS\ISIS_Heal.sqf";
	ISIS_Wound = Compile preprocessFile "Client\Module\ISIS\ISIS_Wound.sqf";
	ISIS_Wounded = Compile preprocessFile "Client\Module\ISIS\ISIS_Wounded.sqf";
};

/* Wait for BIS Module Init */
waitUntil {!(isNil 'BIS_fnc_init')};
waitUntil {BIS_fnc_init};

/* CORE SYSTEM - Start
	Different Core are added depending on the current ArmA Version running, add yours bellow.
*/
switch (true) do {
	case WF_A2_Vanilla: {
		/* Gear Core */
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_Vanilla_G.sqf';
		/* Class Core */
		[] Call Compile preprocessFile 'Common\Config\Core\Core_CDF.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_CIV.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_FR.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_GUE.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_INS.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_MVD.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_RU.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_Spetsnaz.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_USMC.sqf';

		/* Call in the teams template - Vanilla */
		[] Call Compile preprocessFile 'Common\Config\Core_Definition\Vanilla\Definition_USMC_RU.sqf';
	};
	case WF_A2_Arrowhead: {
		/* Gear Core */
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_Arrowhead_G.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_BAF_G.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_PMC_G.sqf';
		/* Class Core */
		[] Call Compile preprocessFile 'Common\Config\Core\Core_ACR.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_BAF.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_BAFD.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_BAFW.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_DeltaForce.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_KSK.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_PMC.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKA.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKCIV.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKGUE.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKSF.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_US.sqf';

		/* Call in the teams template - Arrowhead */
		[] Call Compile preprocessFile 'Common\Config\Core_Definition\Arrowhead\Definition_US_TKA.sqf';
	};
	case WF_A2_CombinedOps: {
		/* Gear Core */
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_Vanilla_G.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_Arrowhead_G.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_BAF_G.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core_Gear\Core_PMC_G.sqf';
		/* Class Core */
		[] Call Compile preprocessFile 'Common\Config\Core\Core_ACR.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_BAF.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_BAFD.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_BAFW.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_CDF.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_CIV.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_DeltaForce.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_FR.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_GUE.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_INS.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_KSK.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_MVD.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_PMC.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_RU.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_Spetsnaz.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKA.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKCIV.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKGUE.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_TKSF.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_US.sqf';
		[] Call Compile preprocessFile 'Common\Config\Core\Core_USMC.sqf';

		/* Call in the teams template - Combined Operations */
		[] Call Compile preprocessFile 'Common\Config\Core_Definition\CombinedOps\Definition_US_RU.sqf';

	WFBE_V_East_SquadsRootVersion = 'Vanilla';
	WFBE_V_East_SquadsFaction = 'RU';
	};
};
/* CORE SYSTEM - End */

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Common: Core Loading - [Done]",diag_frameno,diag_tickTime];

//--- Common Exec.
[] Call Compile preprocessFile "Common\Init\Init_PublicVariables.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Special.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Artillery.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Barracks.sqf";
[] Call Compile preprocessFile "Common\Config\Config_LightFactory.sqf";
[] Call Compile preprocessFile "Common\Config\Config_HeavyFactory.sqf";
[] Call Compile preprocessFile "Common\Config\Config_AircraftFactory.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Airport.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Depot.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Structures.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Squads.sqf";
[] Call Compile preprocessFile "Common\Config\Config_Loadouts.sqf";

//--- Server Exec.
if (isServer) then {
	[] Call Compile preprocessFile "Common\Config\Config_Resistance.sqf";
	[] Call Compile preprocessFile "Common\Config\Config_Occupation.sqf";
	
	//--- Allies.
	if (('WFBE_ALLIES' Call GetNamespace) > 0) then {[] Call Compile preprocessFile "Common\Config\Config_Allies.sqf"};
};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Common: Config Loading - [Done]",diag_frameno,diag_tickTime];

//--- Boundaries, use setPos to find the perfect spot on other islands and worldName to determine the island name (editor: diag_log worldName; player setPos [0,5120,0]; ).
[] Call Compile preprocessFile "Common\Init\Init_Boundaries.sqf";
diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Common: Boundaries Loading - [Done]",diag_frameno,diag_tickTime];

//--- Mando Missiles.
if (paramMandoMissiles) then {
	[false] execVM "mando_missiles\mando_missileinit.sqf";

	//--- Wait for Mando Missile initialization 
	waitUntil {!isNil "mando_missile_init_done"};
	waitUntil {mando_missile_init_done};

	[] execVM "mando_missiles\mando_setup_full.sqf";
	[] execVM "mando_missiles\mando_setup_ffaa.sqf";
	[] execVM "mando_missiles\mando_setup_ace.sqf";
	[] execVM "mando_missiles\mando_gun\mando_guninit.sqf";
	
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Common: Mando Missiles - [Done]",diag_frameno,diag_tickTime];
};

//--- CIPHER Module - Functions.
[] Call Compile preprocessFile "Common\Module\CIPHER\CIPHER_Init.sqf";

//--- Common initilization is complete at this point.
diag_log Format["[WFBE (INIT)][frameno:%2 | ticktime:%3] Init_Common: Init End at %1",time,diag_frameno,diag_tickTime];
commonInitComplete = true;

//--- Variable Destruction.
{Call Compile Format ["%1 = nil",_x]} forEach ['WFBE_V_West_UnitsRootVersion','WFBE_V_East_UnitsRootVersion','WFBE_V_West_Faction',
'WFBE_V_East_Faction','WFBE_V_East_SquadsFaction','WFBE_V_West_SquadsFaction','WFBE_V_East_SquadsRootVersion','WFBE_V_West_SquadsRootVersion','WFBE_V_East_Loadout',
'WFBE_V_West_Loadout','WFBE_V_East_LoadoutRootVersion','WFBE_V_West_LoadoutRootVersion','WFBE_V_West_StructuresFaction','WFBE_V_East_StructuresFaction','WFBE_V_East_StructuresRootVersion',
'WFBE_V_West_StructuresRootVersion','WFBE_V_West_ArtilleryRootVersion','WFBE_V_West_ArtilleryFaction','WFBE_V_East_ArtilleryRootVersion','WFBE_V_East_ArtilleryFaction'];