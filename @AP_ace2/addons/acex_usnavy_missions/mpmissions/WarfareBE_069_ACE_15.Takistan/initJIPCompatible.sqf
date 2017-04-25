//--- Global Init, first file called.
diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_JIPCompatible.sqf: Executing the JIP script..",diag_frameno,diag_tickTime,time];

isClient = false;
//--- Client Init.
if (!isServer || local player) then {
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_JIPCompatible.sqf: Client detected... waiting for non null result...",diag_frameno,diag_tickTime,time];
	waitUntil {!isNull(player)};
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_JIPCompatible.sqf: Client is not null...",diag_frameno,diag_tickTime,time];
	/* Client Init - Begin the blackout on Layer 1 */
	12452 cutText [(localize 'STR_WF_Loading')+"...","BLACK"];
	isHostedServer = if (!isMultiplayer || (isServer && isClient)) then {true} else {false};
	isClient = true;
} else {
	isHostedServer = if (!isMultiplayer || (isServer && isClient)) then {true} else {false};
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_JIPCompatible.sqf: Server detected...",diag_frameno,diag_tickTime,time];
};

//--- Server & Client default View Distance.
setViewDistance 1000;

clientInitComplete = false;
commonInitComplete = false;
serverInitComplete = false;
gameOver = false;
townInit = false;
towns = [];

//--- Define which 'part' of the game to run.
#include "version.sqf"

WF_A2_Vanilla = false;
#ifdef VANILLA
	WF_A2_Vanilla = true;
#endif

WF_A2_Arrowhead = false;
#ifdef ARROWHEAD
	WF_A2_Arrowhead = true;
#endif

WF_A2_CombinedOps = false;
#ifdef COMBINEDOPS
	WF_A2_CombinedOps = true;
#endif

WF_Debug = false;
#ifdef WF_DEBUG
	WF_Debug = true;
#endif

WF_Camo = false;
#ifdef WF_CAMO
	WF_Camo = true;
#endif

WF_ACE = false;
#ifdef ACE
	WF_ACE = true;
#endif

mysql=false;
//--- Gameplay variables.
paramMobileRespawn = true;
paramBalancing = false;
paramAI = true;
paramAIcom = true;
paramRestrictionKamov = false;
paramShowUID = true;
paramArty = true;
paramArtyUI = false;
paramTrackAI = true;
paramTrackPlayer = true;
paramRes = true;
paramOccup = true;
paramGearRespawn = true;
paramGearRestriction = false;
paramHangars = true;
paramAARadar = false;
paramCounterMeasures = false;
paramVolumClouds = true;
paramICBM = true;
paramHighCommand = true;
paramBaseArea = true;
paramSpawnRestriction = true;
paramUpgradesEast = true;
paramUpgradesWest = true;
paramKickTeamswappers = true;
paramRespawnMASH = true;
paramResReinf = false;
paramOccReinf = false;
paramPurchaseInfDepot = true;
paramHandleFF = false;
paramBoundaries = true;
paramBasePatrols = false;
paramAlice = false;
paramEASA = true;
paramDLCBAF = true;
paramDLCPMC = true;
paramBounty = true;
paramResVehLock = false;
paramExtendedInventory = false;
paramSecondaryMissions = true;
paramUPSMON = false;
paramDefenseCollide = true;
paramKeepCamps = true;
paramUseWorkers = false;
paramMandoMissiles = false;
paramMoneyOnly = false;

//--- Multiplayers Parameter, the order it the same as Parameters.hpp
if !(isNil "paramsArray") then {
	Private['_u'];
	_u = 0;
	missionNamespace setVariable ['WFBE_MAXGROUPSIZEAI',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_MAXGROUPSIZE',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramKeepAI = false} else {paramKeepAI = true};_u = _u + 1; //--- Keep AI Units over JIP.
	if ((paramsArray select _u) == 0) then {paramAI = false} else {paramAI = true};_u = _u + 1; //--- AI Enabled.
	if ((paramsArray select _u) == 0) then {paramArty = false} else {paramArty = true};_u = _u + 1; //--- Enable Artillery.
	if !(WF_A2_Vanilla) then {missionNamespace setVariable ['WFBE_ARTILLERYCOMPUTER',(paramsArray select _u)];_u = _u + 1};
	if ((paramsArray select _u) == 0) then {paramArtyUI = false} else {paramArtyUI = true};_u = _u + 1; //--- Enable Artillery Interface (Artillery Module).
	missionNamespace setVariable ['WFBE_ARTILLERYMAXRANGE',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramAIcom = false} else {paramAIcom = true};_u = _u + 1; //--- AI Commander Enabled.
	if !(WF_A2_Arrowhead) then {missionNamespace setVariable ['WFBE_ALLIES',(paramsArray select _u)];_u = _u + 1};
	if ((paramsArray select _u) == 0) then {paramAARadar = false} else {paramAARadar = true};_u = _u + 1; //--- Anti Air Radar.
	if ((paramsArray select _u) == 0) then {paramBaseArea = false} else {paramBaseArea = true};_u = _u + 1; //--- Base Area.
	missionNamespace setVariable ['WFBE_BASEAREAMAX',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_AIDEFENSE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_DEFENSEMANRANGE',(paramsArray select _u)];_u = _u + 1;
	//--- Building Limits.
	missionNamespace setVariable ['WFBE_BUILDINGMAXBARRACKS',(paramsArray select _u)];
	missionNamespace setVariable ['WFBE_BUILDINGMAXLIGHT',(paramsArray select _u)];
	missionNamespace setVariable ['WFBE_BUILDINGMAXCOMMANDCENTER',(paramsArray select _u)];
	missionNamespace setVariable ['WFBE_BUILDINGMAXHEAVY',(paramsArray select _u)];
	missionNamespace setVariable ['WFBE_BUILDINGMAXAIRCRAFT',(paramsArray select _u)];
	missionNamespace setVariable ['WFBE_BUILDINGMAXSERVICEPOINT',(paramsArray select _u)*2];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramUseWorkers = false} else {paramUseWorkers = true};_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramDefenseCollide = false} else {paramDefenseCollide = true};_u = _u + 1;
	missionNamespace setVariable ['WFBE_HQDEPLOYPRICE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_HQDEPLOYRANGE',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramBasePatrols = false} else {paramBasePatrols = true};_u = _u + 1; //--- Base patrols.
	if ((paramsArray select _u) == 0) then {paramSpawnRestriction = false} else {paramSpawnRestriction = true};_u = _u + 1; //--- Restrict the Spawn logic to 2km within a town.
	missionNamespace setVariable ['WFBE_SIDESTARTINGDISTANCE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_STARTINGLOCATIONMODE',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramMoneyOnly = false} else {paramMoneyOnly = true};_u = _u + 1;
	missionNamespace setVariable ['WFBE_INCOMEINTERVAL',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_INCOMESYSTEM',(paramsArray select _u)];_u = _u + 1;
	//--- Funds.
	missionNamespace setVariable ['WFBE_EASTSTARTINGMONEY',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_WESTSTARTINGMONEY',(paramsArray select _u)];_u = _u + 1;
	//--- Supply.
	EastSupplies = (paramsArray select _u);_u = _u + 1;
	WestSupplies = (paramsArray select _u);_u = _u + 1;
	missionNamespace setVariable ['WFBE_SUPPLYSYSTEM',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_FASTTIMERATE', paramsArray select _u];_u = _u + 1;
	if (time < 2) then {setDate [(date select 0),(date select 1),(date select 2),(paramsArray select _u),(date select 3)]};_u = _u + 1; //--- Time of Day.
	missionNamespace setVariable ['WFBE_WEATHER',(paramsArray select _u)];_u = _u + 1;
	if !(WF_A2_Vanilla) then {if ((paramsArray select _u) == 0) then {paramDLCBAF = false} else {paramDLCBAF = true};_u = _u + 1};
	if !(WF_A2_Vanilla) then {if ((paramsArray select _u) == 0) then {paramDLCPMC = false} else {paramDLCPMC = true};_u = _u + 1};
	if ((paramsArray select _u) == 0) then {paramAlice = false} else {paramAlice = true};_u = _u + 1; //--- Ambient Civilians.
	if ((paramsArray select _u) == 0) then {paramHangars = false} else {paramHangars = true};_u = _u + 1; //--- Airport Hangars.
	missionNamespace setVariable ['WFBE_UNITREMOVEDLAY',(paramsArray select _u)];_u = _u + 1;
	if (WF_ACE) then {paramDefenseReloading = (paramsArray select _u);_u = _u + 1};
	missionNamespace setVariable ['WFBE_ABANDONVEHICLETIMER', paramsArray select _u];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramExtendedInventory = false} else {paramExtendedInventory = true};_u = _u + 1;
	missionNamespace setVariable ['WFBE_FASTTRAVEL',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramHandleFF = false} else {paramHandleFF = true};_u = _u + 1; //--- Base Friendly Fire.
	missionNamespace setVariable ['WFBE_MAXCLUTTERDISTANCE',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramKickTeamswappers = false} else {paramKickTeamswappers = true};_u = _u + 1; //--- Kick teamswappers.
	if ((paramsArray select _u) == 0) then {paramBoundaries = false} else {paramBoundaries = true};_u = _u + 1; //--- Prevent players from going outside of the map, they're killed after x seconds.
	if ((paramsArray select _u) == 0) then {paramMandoMissiles = false} else {paramMandoMissiles = true};_u = _u + 1;
	missionNamespace setVariable ['WFBE_MAPCOLORATION',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_INCOMINGMISSILEMAXRANGE',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramSecondaryMissions = false} else {paramSecondaryMissions = true};_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramShowUID = false} else {paramShowUID = true};_u = _u + 1; //--- Show User ID.
	missionNamespace setVariable ['WFBE_BALANCEPRICE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_THERMALIMAGING',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramTrackAI = false} else {paramTrackAI = true};_u = _u + 1; //--- Track AI (Yellow dots) on map.
	if ((paramsArray select _u) == 0) then {paramTrackPlayer = false} else {paramTrackPlayer = true};_u = _u + 1; //--- Track players.
	if ((paramsArray select _u) == 0) then {paramBalancing = false} else {paramBalancing = true};_u = _u + 1; //--- Balance the given units weapon loadout.
	if ((paramsArray select _u) == 0) then {paramBounty = false} else {paramBounty = true};_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramUpgradesEast = false} else {paramUpgradesEast = true};_u = _u + 1; //--- Upgrades.
	if ((paramsArray select _u) == 0) then {paramUpgradesWest = false} else {paramUpgradesWest = true};_u = _u + 1; //--- Upgrades.
	missionNamespace setVariable ['WFBE_VICTORYCONDITION',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_MAXVIEWDISTANCE',(paramsArray select _u)];_u = _u + 1;
	if (WF_ACE) then {if ((paramsArray select _u) == 0) then {paramAceWounds = false} else {paramAceWounds = true};_u = _u + 1;} else {paramAceWounds = false}; //--- ACE Wounds
	if (WF_A2_Vanilla) then {if ((paramsArray select _u) == 0) then {paramCounterMeasures = false} else {paramCounterMeasures = true};_u = _u + 1}; //--- Countermeasures.
	if ((paramsArray select _u) == 0) then {paramEASA = false} else {paramEASA = true};_u = _u + 1; //--- EASA.
	if ((paramsArray select _u) == 0) then {paramHighCommand = false} else {paramHighCommand = true};_u = _u + 1; //--- High Command.
	if ((paramsArray select _u) == 0) then {paramICBM = false} else {paramICBM = true};_u = _u + 1; //--- ICBM.
	missionNamespace setVariable ['WFBE_ISIS',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramUPSMON = false} else {paramUPSMON = true};_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramVolumClouds = false} else {paramVolumClouds = true};_u = _u + 1; //--- Volumetric Clouds.
	missionNamespace setVariable ['WFBE_RESPAWNCAMPSMODE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_RESPAWNCAMPSRULEMODE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_RESPAWNDELAY',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramRespawnMASH = false} else {paramRespawnMASH = true};_u = _u + 1; //--- MASH respawn's enabled.
	if ((paramsArray select _u) == 0) then {paramMobileRespawn = false} else {paramMobileRespawn = true};_u = _u + 1; //--- Mobile respawn's enabled.
	missionNamespace setVariable ['WFBE_RESPAWNPENALTY',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_RESPAWNRANGE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_RESTRICTIONADVAIR',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramGearRestriction = false} else {paramGearRestriction = true};_u = _u + 1; //--- Player have a gear restriction in camps.
	if !(WF_A2_Arrowhead) then {if ((paramsArray select _u) == 0) then {paramRestrictionKamov = false} else {paramRestrictionKamov = true};_u = _u + 1}; //--- Kamov enabled.
	_u = _u + 1; //--- Town Amount System, leave blank.
	missionNamespace setVariable ['WFBE_RESSTRIKER',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramKeepCamps = false} else {paramKeepCamps = true};_u = _u + 1;
	missionNamespace setVariable ['WFBE_TOWNCAPTUREMODE',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_CIVILIANFACTION',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramOccup = false} else {paramOccup = true};_u = _u + 1; //--- Town Occupation.
	missionNamespace setVariable ['WFBE_TOWNOCCUPATIONDIFFICULTY',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_OCCUPATIONEASTFACTION',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_OCCUPATIONWESTFACTION',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramOccReinf = false} else {paramOccReinf = true};_u = _u + 1; //--- Town Occupation Reinforcement.
	missionNamespace setVariable ['WFBE_RESPATROL',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_TOWNBUILDPROTECTIONRANGE',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramPurchaseInfDepot = false} else {paramPurchaseInfDepot = true};_u = _u + 1; //--- Town Milita Purchase.
	if ((paramsArray select _u) == 0) then {paramRes = false} else {paramRes = true};_u = _u + 1; //--- Town Resistance.
	missionNamespace setVariable ['WFBE_TOWNRESISTANCEDIFFICULTY',(paramsArray select _u)];_u = _u + 1;
	missionNamespace setVariable ['WFBE_RESISTANCEFACTION',(paramsArray select _u)];_u = _u + 1;
	if ((paramsArray select _u) == 0) then {paramResReinf = false} else {paramResReinf = true};_u = _u + 1; //--- Town Resistance Reinforcement.
	if ((paramsArray select _u) == 0) then {paramResVehLock = false} else {paramResVehLock = true};_u = _u + 1; //--- Town Resistance Vehicles Lock.
	missionNamespace setVariable ['WFBE_TOWNSTARTINGMODE',(paramsArray select _u)];_u = _u + 1;
};

//--- Debug.
if (WF_Debug) then {
	paramUpgradesEast = false;
	paramUpgradesWest = false;
	//paramRes = false;
	//paramOccup = false;
};

//--- All parameters are set and ready.
initJIP = true;

//--- Advanced squads
missionNamespace setVariable ['WFBE_EASTSLOTNAMES',[vehicleVarName EastSlot1,vehicleVarName EastSlot2,vehicleVarName EastSlot3,vehicleVarName EastSlot4,vehicleVarName EastSlot5,vehicleVarName EastSlot6,vehicleVarName EastSlot7,vehicleVarName EastSlot8,vehicleVarName EastSlot9,vehicleVarName EastSlot10,vehicleVarName EastSlot11,vehicleVarName EastSlot12,vehicleVarName EastSlot13,vehicleVarName EastSlot14,vehicleVarName EastSlot15,vehicleVarName EastSlot16]];
missionNamespace setVariable ['WFBE_WESTSLOTNAMES',[vehicleVarName WestSlot1,vehicleVarName WestSlot2,vehicleVarName WestSlot3,vehicleVarName WestSlot4,vehicleVarName WestSlot5,vehicleVarName WestSlot6,vehicleVarName WestSlot7,vehicleVarName WestSlot8,vehicleVarName WestSlot9,vehicleVarName WestSlot10,vehicleVarName WestSlot11,vehicleVarName WestSlot12,vehicleVarName WestSlot13,vehicleVarName WestSlot14,vehicleVarName WestSlot15,vehicleVarName WestSlot16]];

missionNamespace setVariable ['WFBE_EASTTEAMS',[Group EastSlot1,Group EastSlot2,Group EastSlot3,Group EastSlot4,Group EastSlot5,Group EastSlot6,Group EastSlot7,Group EastSlot8,Group EastSlot9,Group EastSlot10,Group EastSlot11,Group EastSlot12,Group EastSlot13,Group EastSlot14,Group EastSlot15,Group EastSlot16]];
missionNamespace setVariable ['WFBE_WESTTEAMS',[Group WestSlot1,Group WestSlot2,Group WestSlot3,Group WestSlot4,Group WestSlot5,Group WestSlot6,Group WestSlot7,Group WestSlot8,Group WestSlot9,Group WestSlot10,Group WestSlot11,Group WestSlot12,Group WestSlot13,Group WestSlot14,Group WestSlot15,Group WestSlot16]];

//--- Maximum players, try to keep the same amount of player on east & west.
maxPlayers = count (missionNamespace getVariable 'WFBE_EASTTEAMS');

//--- Execute the common files.
ExecVM "Common\Init\Init_Common.sqf";
//--- Execute the towns file.
ExecVM "Common\Init\Init_Towns.sqf";

//--- Run the client's part.
if (isClient) then {
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] init_JIPCompatible.sqf: Executing Client Initialization...",diag_frameno,diag_tickTime,time];
	ExecVM "Client\Init\Init_Client.sqf";
};

//--- Run the server's part.
if (isServer) then {
	diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] init_JIPCompatible.sqf: Executing Server Initialization...",diag_frameno,diag_tickTime,time];
	ExecVM "Server\Init\Init_Server.sqf";
};

//--- Fast Get/Set.
_i = 1;
{if !(isNil '_x') then {_x setVariable ["identification", Format["EastSlot%1",_i]]};_i = _i + 1} forEach (missionNamespace getVariable 'WFBE_EASTTEAMS');
_i = 1;
{if !(isNil '_x') then {_x setVariable ["identification", Format["WestSlot%1",_i]]};_i = _i + 1} forEach (missionNamespace getVariable 'WFBE_WESTTEAMS');