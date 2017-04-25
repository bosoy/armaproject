/* Parameters */

class Params {
	class aiGroupSizeAI {
		title = "$STR_WF_Gameplay_GroupSizeAI";
		values[] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,35,40,45,50,60,70,80,90,100};
		texts[] = {"2","4","6","8","10","12","14","16","18","20","22","24","26","28","30","35","40","45","50","60","70","80","90","100"};
		default = 10;
	};
	class aiGroupSizePlayer {
		title = "$STR_WF_Gameplay_GroupSizePlayer";
		values[] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,35,40,45,50,60,70,80,90,100};
		texts[] = {"2","4","6","8","10","12","14","16","18","20","22","24","26","28","30","35","40","45","50","60","70","80","90","100"};
		default = 12;
	};
	class aiKeepUnits {
		title = "$STR_WF_Gameplay_KeepAI";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class aiTeams {
		title = "$STR_WF_Gameplay_AI";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class artilleryCalls {
		title = "$STR_WF_Gameplay_Arty";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	#ifndef VANILLA
		class artilleryComputer {
			title = "$STR_WF_Gameplay_ArtilleryComputer";
			values[] = {0,1,2};
			texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled_Upgrade","$STR_WF_Enabled"};
			default = 1;
		};	
	#endif
	class artilleryUI {
		title = "$STR_WF_Gameplay_ArtilleryUI";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class artilleryRange {
		title = "$STR_WF_Gameplay_Artillery";
		values[] = {1,2,3};
		texts[] = {"$STR_WF_Short","$STR_WF_Medium","$STR_WF_Long"};
		default = 3;
	};
	class baseAICommander {
		title = "$STR_WF_Gameplay_AICommander";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	//--- OA has no suitable allies for both side (yet).
	#ifndef ARROWHEAD
		class baseAllies {
			title = "$STR_WF_Gameplay_Allies";
			values[] = {0,1,2,3};
			texts[] = {"$STR_WF_Disabled","$STR_WF_Side_West","$STR_WF_Side_East","$STR_WF_Respawn_CampsRule_WestEast"};
			default = 0;
		};
	#endif
	class baseAAR {
		title = "$STR_WF_Gameplay_AntiAirRadar";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class baseArea {
		title = "$STR_WF_BaseArea";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class baseAreaLimit {
		title = "$STR_WF_BaseArea_Limit";
		values[] = {1,2,3,4,5,6,7,8,9,10,12,14,16,18,20,22,24};
		texts[] = {"1","2","3","4","5","6","7","8","9","10","12","14","16","18","20","22","24"};
		default = 2;
	};
	class baseAutoDefenses {
		title = "$STR_WF_Gameplay_AutoDefense";
		values[] = {0,10,20,30,40,50,60,70,80,90,100};
		texts[] = {"$STR_WF_Disabled","10","20","30","40","50","60","70","80","90","100"};
		default = 30;
	};
	class baseAutoDefensesRange {
		title = "$STR_WF_Gameplay_AutoDefense_Range";
		values[] = {50,100,150,200,250,300,350,400,450,500,600,700,800,900,1000};
		texts[] = {"50m","100m","150m","200m","250m","300m","350m","400m","450m","500m","600m","700m","800m","900m","1000m"};
		default = 250;
	};
	class baseBuildingsLimit {
		title = "$STR_WF_Gameplay_BuildingsLimit";
		values[] = {1,2,3,4,5,6,7,8,9,10};
		texts[] = {"1","2","3","4","5","6","7","8","9","10"};
		default = 2;
	};
	class baseConstructionMode {
		title = "$STR_WF_Gameplay_ConstructionMode";
		values[] = {0,1};
		texts[] = {"$STR_WF_Time","$STR_WF_Workers"};
		default = 0;
	};
	class baseDefensePlacement {
		title = "$STR_WF_Gameplay_DefensePlacement";
		values[] = {0,1};
		texts[] = {"$STR_WF_Collide_No","$STR_WF_Collide"};
		default = 1;
	};
	class baseHQDeploycost {
		title = "$STR_WF_Gameplay_HQDeployCost";
		values[] = {100,200,300,400,500,600,700,800,900,1000,1500,2000,2500,3000,3500,4000,5000,6000,7000,8000,9000,10000};
		texts[] = {"S 100.","S 200.","S 300.","S 400.","S 500.","S 600.","S 700.","S 800.","S 900.","S 1000.","S 1500.","S 2000.","S 2500.","S 3000.","S 3500.","S 4000.","S 5000.","S 6000.","S 7000.","S 8000.","S 9000.","S 10000"};
		default = 100;
	};
	class baseHQDeployRange {
		title = "$STR_WF_Gameplay_HQDeployRange";
		values[] = {50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,220,240,260,280,300,320,340,360,380,400};
		texts[] = {"50m","60m","70m","80m","90m","100m","110m","120m","130m","140m","150m","160m","170m","180m","190m","200m","220m","240m","260m","280m","300m","320m","340m","360m","380m","400m"};
		default = 120;
	};
	class basePatrols {
		title = "$STR_WF_Gameplay_BasePatrols";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class baseSpawnSystemRestrict {
		title = "$STR_WF_Gameplay_SpawnSystemRestrict";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class baseStartingDistance {
		title = "$STR_WF_Gameplay_StartingDistance";
		values[] = {-1,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000};
		texts[] = {"$STR_WF_Gameplay_StartingLocations_Random","1000m","1500m","2000m","2500m","3000m","3500m","4000m","4500m","5000m","5500m","6000m","6500m","7000m","7500m","8000m","8500m","9000m"};
		default = 5500;
	};
	class baseStartingLocations {
		title = "$STR_WF_Gameplay_StartingLocations";
		values[] = {0,1,2};
		texts[] = {"$STR_WF_Gameplay_StartingLocations_WestNorth","$STR_WF_Gameplay_StartingLocations_WestSouth","$STR_WF_Gameplay_StartingLocations_Random"};
		default = 2;
	};
	class economyCurrency {
		title = "$STR_WF_Gameplay_Currency";
		values[] = {0,1};
		texts[] = {"$STR_WF_Money_Supply","$STR_WF_Money"};
		default = 0;
	};
	class economyIncomeInterval {
		title = "$STR_WF_Gameplay_IncomeInterval";
		values[] = {30,60,120,180,240,300,360,420,480,540,600};
		texts[] = {"30 Seconds", "1 Minute","2 Minutes","3 Minutes","4 Minutes","5 Minutes","6 Minutes","7 Minutes","8 Minutes","9 Minutes","10 Minutes"};
		default = 60;
	};
	class economyIncomeSystem {
		title = "$STR_WF_Gameplay_IncomeSystem";
		values[] = {1,2,3,4};
		texts[] = {"$STR_WF_Gameplay_IncomeSystem_Full","$STR_WF_Gameplay_IncomeSystem_Half","$STR_WF_Income_Sys_Param","$STR_WF_Income_Sys_Param_Full"};
		default = 3;
	};
	class economyStartingFundsEast {
		title = "$STR_WF_Gameplay_Funds_East";
		values[] = {800,1600,2400,3200,4000,4800,6400,8000,12800,25600,51200,102400,204800,409600,819200};
		texts[] = {"$ 800.","$ 1600.","$ 2400.","$ 3200.","$ 4000.","$ 4800.","$ 6400.","$ 8000.","$ 12800.","$ 25600.","$ 51200.","$ 102400.","$ 204800.","$ 409600.","$ 819200."};
		default = 800;
	};
	class economyStartingFundsWest {
		title = "$STR_WF_Gameplay_Funds_West";
		values[] = {800,1600,2400,3200,4000,4800,6400,8000,12800,25600,51200,102400,204800,409600,819200};
		texts[] = {"$ 800.","$ 1600.","$ 2400.","$ 3200.","$ 4000.","$ 4800.","$ 6400.","$ 8000.","$ 12800.","$ 25600.","$ 51200.","$ 102400.","$ 204800.","$ 409600.","$ 819200."};
		default = 800;
	};
	class economyStartingSupplyEast {
		title = "$STR_WF_Gameplay_Supply_East";
		values[] = {1200,2400,3600,4800,6000,7200,8400,9600,19200,38400,76800};
		texts[] = {"S 1200.","S 2400.","S 3600.","S 4800.","S 6000.","S 7200.","S 8400.","S 9600.","S 19200.","S 38400.","S 76800."};
		default = 1200;
	};
	class economyStartingSupplyWest {
		title = "$STR_WF_Gameplay_Supply_West";
		values[] = {1200,2400,3600,4800,6000,7200,8400,9600,19200,38400,76800};
		texts[] = {"S 1200.","S 2400.","S 3600.","S 4800.","S 6000.","S 7200.","S 8400.","S 9600.","S 19200.","S 38400.","S 76800."};
		default = 1200;
	};
	class economySupplySystem {
		title = "$STR_WF_Gameplay_SupplySystem";
		values[] = {0,1};
		texts[] = {"$STR_WF_Gameplay_SupplySystem_Truck","$STR_WF_Time"};
		default = 1;
	};
	class environmentFastTime {
		title = "$STR_WF_Gameplay_FastTime";
		values[] = {0,1,2,3,4,5,6,7,8,9};
		texts[] = {"$STR_WF_Disabled","1 Second = 2 Seconds","1 Second = 3 Seconds","1 Second = 4 Seconds","1 Second = 5 Seconds","1 Second = 10 Seconds","1 Second = 15 Seconds","1 Second = 20 Seconds","1 Second = 25 Seconds","1 Second = 30 Seconds"};
		default = 0;
	};
	class environmentTimeOfDay {
		title = "$STR_WF_Gameplay_TimeOfDay";
		values[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
		texts[] = {"00:00","01:00","02:00","03:00","04:00","05:00","06:00","07:00","08:00","09:00","10:00","11:00",
		"12:00","13:00","14:00","15:00","16:00","17:00","18:00","19:00","20:00","21:00","22:00","23:00"};
		default = 9;
	};
	class environmentWeather {
		title = "$STR_WF_Gameplay_Weather";
		values[] = {0,1,2,3};
		texts[] = {"$STR_WF_Weather_Clear","$STR_WF_Weather_Cloudy","$STR_WF_Weather_Rainy","$STR_WF_Weather_Dynamic"};
		default = 0;
	};
	#ifndef VANILLA
		class extensionBAF {
			title = "$STR_WF_Gameplay_BAF";
			values[] = {0,1};
			texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
			default = 1;
		};
		class extensionPMC {
			title = "$STR_WF_Gameplay_PMC";
			values[] = {0,1};
			texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
			default = 1;
		};
	#endif
	class gameplayAlice {
		title = "$STR_WF_Gameplay_Alice";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class gameplayHangars {
		title = "$STR_WF_Gameplay_Hangars";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayBodiesTimeout {
		title = "$STR_WF_Gameplay_BodiesTimeout";
		values[] = {60,120,180,240,300,600,1200,1800,2400,3000,3600};
		texts[] = {"1 Minute","2 Minutes","3 Minutes","4 Minutes","5 Minutes","10 Minutes","20 Minutes","30 Minutes","40 Minutes","50 Minutes","1 Hour"};
		default = 240;
	};
	#ifdef ACE
	class gameplayDefenseAmmo {
		title = "$STR_WF_Gameplay_DefenseAmmo";
		values[] = {0,1,2,3};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Base_Only","$STR_WF_Base_And_Towns","$STR_WF_All"};
		default = 2;
	};
	#endif
	class gameplayVehiclesTimeout {
		title = "$STR_WF_Gameplay_VehicleDelay";
		values[] = {60,120,180,240,300,600,1200,1800,2400,3000,3600};
		texts[] = {"1 Minute","2 Minutes","3 Minutes","4 Minutes","5 Minutes","10 Minutes","20 Minutes","30 Minutes","40 Minutes","50 Minutes","1 Hour"};
		default = 1200;
	};
	class gameplayExtendedInventory {
		title = "$STR_WF_Gameplay_Extended_Inventory";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayFastTravel {
		title = "$STR_WF_Gameplay_FastTravel";
		values[] = {0,1,2};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Free","$STR_WF_Fee"};
		default = 0;
	};
	class gameplayFriendlyFire {
		title = "$STR_WF_Gameplay_FriendlyFire";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class gameplayGrass {
		title = "$STR_WF_Gameplay_Grass";
		values[] = {10,20,30,50};
		texts[] = {"Far","Medium","Short","Toggleable"};
		default = 50;
	};
	class gameplayKickTeamswap {
		title = "$STR_WF_Gameplay_KickTeamswapper";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayLimitedBoundaries {
		title = "$STR_WF_Gameplay_LimitedBoundaries";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayMandoMissiles {
		title = "$STR_WF_Gameplay_MandoMissiles";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class gameplayMapColoration {
		title = "$STR_WF_Gameplay_Coloration";
		values[] = {0,1};
		texts[] = {"$STR_WF_Default","$STR_WF_NATO_Coloration"};
		default = 0;
	};
	class gameplayMissileRange {
		title = "$STR_WF_Gameplay_MissileRange";
		values[] = {0,500,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000,9500,10000};
		texts[] = {"$STR_WF_Disabled","500m","1000m","1500m","2000m","2500m","3000m","3500m","4000m","4500m","5000m","5500m","6000m","6500m","7000m","7500m","8000m","8500m","9000m","9500m","10000m"};
		default = 0;
	};
	class gameplaySecondaryMissions {
		title = "$STR_WF_Gameplay_SecondaryMissions";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class gameplayShowUID {
		title = "$STR_WF_Gameplay_ShowUID";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplaySpecialization {
		title = "$STR_WF_Gameplay_Specialization";
		values[] = {0,1,2,3};
		texts[] = {"$STR_WF_None","$STR_WF_Infantry","$STR_WF_LandVehicles","$STR_WF_Aircraft"};
		default = 0;
	};
	class gameplayThermalImaging {
		title = "$STR_WF_Gameplay_ThermalImaging";
		values[] = {0,1,2,3};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Weapons","$STR_WF_Vehicles","$STR_WF_Enabled"};
		default = 3;
	};
	class gameplayTrackAI {
		title = "$STR_WF_Gameplay_TrackAI";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class gameplayTrackPlayers {
		title = "$STR_WF_Gameplay_TrackPlayers";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayUnitsBalancing {
		title = "$STR_WF_Balance";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class gameplayUnitsBounty {
		title = "$STR_WF_Gameplay_UnitsBounty";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayUpgradesEast {
		title = "$STR_WF_Upgrades_East";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayUpgradesWest {
		title = "$STR_WF_Upgrades_West";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class gameplayVictoryConditions {
		title = "$STR_WF_Gameplay_VictoryCondition";
		values[] = {0,1,2,3};
		texts[] = {"$STR_WF_Victory_Annihilation","$STR_WF_Victory_Assassination","$STR_WF_Victory_Supremacy","$STR_WF_Victory_Towns"};
		default = 2;
	};
	class gameplayViewDistance {
		title = "$STR_WF_Gameplay_ViewDistance";
		values[] = {200,500,800,1000,1500,2000,2500,3000,3500,4000,4500,5000};
		texts[] = {"200m","500m","800m","1000m","1500m","2000m","2500m","3000m","3500m","4000m","4500m","5000m"};
		default = 4000;
	};
	#ifdef ACE
	class gameplayAceWounds {
		title = "$STR_WF_Gameplay_AceWounds";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	#endif
	#ifdef VANILLA
		class moduleCM {
			title = "$STR_WF_Gameplay_Countermeasures";
			values[] = {0,1};
			texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
			default = 0;
		};
	#endif
	class moduleEASA {
		title = "$STR_WF_Gameplay_EASA";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class moduleHC {
		title = "$STR_WF_Gameplay_HighCommand";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class moduleICBM {
		title = "$STR_WF_Gameplay_ICBM";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class moduleISIS {
		title = "$STR_WF_Gameplay_ISIS";
		values[] = {0,1,2};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Leader","$STR_WF_All"};
		default = 0;
	};
	class moduleUPSMON {
		title = "$STR_WF_Gameplay_UPSMON";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class moduleVC {
		title = "$STR_WF_Gameplay_Clouds";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class respawnCamps {
		title = "$STR_WF_Gameplay_Camp";
		values[] = {0,1,2,3};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Classic","$STR_WF_Respawn_CampsNearby","$STR_WF_Respawn_Defender"};
		default = 2;
	};
	class respawnCampsRule {
		title = "$STR_WF_Gameplay_CampRespawnRule";
		values[] = {0,1,2};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Respawn_CampsRule_WestEast","$STR_WF_Respawn_CampsRule_WestEastRes"};
		default = 2;
	};
	class respawnDelay {
		title = "$STR_WF_Gameplay_Respawn";
		values[] = {10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90};
		texts[] = {"10 Seconds","15 Seconds","20 Seconds","25 Seconds","30 Seconds","35 Seconds","40 Seconds","45 Seconds","50 Seconds",
		"55 Seconds","60 Seconds","65 Seconds","70 Seconds","75 Seconds","80 Seconds","85 Seconds","90 Seconds"};
		default = 30;
	};
	class respawnMASH {
		title = "$STR_WF_Gameplay_Respawn_MASH";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class respawnMobile {
		title = "$STR_WF_Gameplay_MobileRespawn";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class respawnPenalty {
		title = "$STR_WF_Respawn_Penalty";
		values[] = {0,1,2,3,4,5};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Respawn_Penalty_Remove","$STR_WF_Respawn_Penalty_Full","$STR_WF_Respawn_Penalty_OneHalf","$STR_WF_Respawn_Penalty_OneFourth","$STR_WF_Respawn_Penalty_Mobile"};
		default = 5;
	};
	class respawnTownsRange {
		title = "$STR_WF_Gameplay_TownRespawnRange";
		values[] = {50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1500,2000,2500,3000,3500,4000};
		texts[] = {"50m","100m","150m","200m","250m","300m","350m","400m","450m","500m","550m","600m","650m","700m","750m","800m","850m","900m","950m","1000m","1500m","2000m","2500m","3000m","3500m","4000m"};
		default = 400;
	};
	class restrictionAdvancedAir {
		title = "$STR_WF_Gameplay_AdvancedAir";
		values[] = {0,1,2};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Restriction_Air_H","$STR_WF_Restriction_Air_HTransport"};
		default = 0;
	};
	class restrictionGear {
		title = "$STR_WF_Gameplay_GearRestriction";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	#ifndef ARROWHEAD
		class restrictionKamov {
			title = "$STR_WF_Gameplay_Kamov";
			values[] = {0,1};
			texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
			default = 0;
		};
	#endif
	class townsAmount {
		title = "$STR_WF_Gameplay_TownsAmount";
		values[] = {0,1,2,3,4};
		texts[] = {"$STR_WF_Extra_Small","$STR_WF_Small","$STR_WF_Medium","$STR_WF_Large","$STR_WF_Full"};
		default = 3;
	};
	class townsStrikerMax {
		title = "$STR_WF_Gameplay_MaxResStriker";
		values[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,24,26,28,30,32,34,36,38,40,50,60,70,80,90,100};
		texts[] = {"$STR_WF_Disabled","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","22","24","26","28","30","32","34","36","38","40","50","60","70","80","90","100"};
		default = 0;
	};
	class townsCamps {
		title = "$STR_WF_Gameplay_TownsCamps";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class townsCaptureMode {
		title = "$STR_WF_Gameplay_TownsCaptureMode";
		values[] = {0,1,2};
		texts[] = {"$STR_WF_Classic","$STR_WF_Gameplay_TownsCaptureMode_Threshold","$STR_WF_Gameplay_TownsCaptureMode_AllCamps"};
		default = 1;
	};
	#ifdef VANILLA
		class townsCivilians {
			title = "$STR_WF_Gameplay_TownCivilians";
			values[] = {0,1};
			texts[] = {"$STR_WF_Disabled","Chernarus Civilians"};
			default = 0;
		};
	#endif
	#ifdef ARROWHEAD
		class townsCivilians {
			title = "$STR_WF_Gameplay_TownCivilians";
			values[] = {0,1};
			texts[] = {"$STR_WF_Disabled","Takistan Civilians"};
			default = 0;
		};
	#endif
	#ifdef COMBINEDOPS
		class townsCivilians {
			title = "$STR_WF_Gameplay_TownCivilians";
			values[] = {0,1,2};
			texts[] = {"$STR_WF_Disabled","Chernarus Civilians","Takistan Civilians"};
			default = 0;
		};
	#endif
	class townsOccupation {
		title = "$STR_WF_Gameplay_Occupation";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class townsOccupDifficulty {
		title = "$STR_WF_Gameplay_Difficulty_Occupation";
		values[] = {1,2,3,4,5};
		texts[] = {"$STR_WF_Light","$STR_WF_Medium","$STR_WF_Hard","$STR_WF_Impossible","$STR_WF_Automatic"};
		default = 1;
	};
	#ifdef VANILLA
		class townsOccupationFactionEast {
			title = "$STR_WF_Gameplay_Occupation_Type_East";
			values[] = {0,1};
			texts[] = {"Insurgents","Russians"};
			default = 1;
		};
		class townsOccupationFactionWest {
			title = "$STR_WF_Gameplay_Occupation_Type_West";
			values[] = {0,1};
			texts[] = {"Chernarussian Defence Force","United States Marine Corps"};
			default = 1;
		};
	#endif
	#ifdef ARROWHEAD
		class townsOccupationFactionEast {
			title = "$STR_WF_Gameplay_Occupation_Type_East";
			values[] = {0};
			texts[] = {"Takistan Army"};
			default = 0;
		};
		class townsOccupationFactionWest {
			title = "$STR_WF_Gameplay_Occupation_Type_West";
			values[] = {0};
			texts[] = {"United States"};
			default = 0;
		};
	#endif
	#ifdef COMBINEDOPS
		class townsOccupationFactionEast {
			title = "$STR_WF_Gameplay_Occupation_Type_East";
			values[] = {0,1,2};
			texts[] = {"Insurgents","Russians","Takistan Army"};
			default = 1;
		};
		class townsOccupationFactionWest {
			title = "$STR_WF_Gameplay_Occupation_Type_West";
			values[] = {0,1,2};
			texts[] = {"Chernarussian Defence Force","United States","United States Marine Corps"};
			default = 1;
		};
	#endif
	class townsOccupReinforcement {
		title = "$STR_WF_Gameplay_Reinforcement_Occupation";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class townsMaxPatrol {
		title = "$STR_WF_Gameplay_MaxResPatrols";
		values[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,24,26,28,30,32,34,36,38,40,50,60,70,80,90,100};
		texts[] = {"$STR_WF_Disabled","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","22","24","26","28","30","32","34","36","38","40","50","60","70","80","90","100"};
		default = 0;
	};
	class townsProtectionRange {
		title = "$STR_WF_Gameplay_TownProtectionRange";
		values[] = {0,50,100,150,200,250,300,350,400,450,500};
		texts[] = {"0m","50m","100m","150m","200m","250m","300m","350m","400m","450m","500m"};
		default = 400;
	};
	class townsPurchaseInfantry {
		title = "$STR_WF_Gameplay_TownsPurchaseMilita";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class townsResistance {
		title = "$STR_WF_Gameplay_Resistance";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 1;
	};
	class townsResistanceDifficulty {
		title = "$STR_WF_Gameplay_Difficulty_Resistance";
		values[] = {1,2,3,4};
		texts[] = {"$STR_WF_Light","$STR_WF_Medium","$STR_WF_Hard","$STR_WF_Impossible"};
		default = 1;
	};
	#ifdef VANILLA
		class townsResistanceFaction {
			title = "$STR_WF_Gameplay_Reinforcement_Type";
			values[] = {0};
			texts[] = {"Guerillas"};
			default = 0;
		};
	#endif
	#ifdef ARROWHEAD
		class townsResistanceFaction {
			title = "$STR_WF_Gameplay_Reinforcement_Type";
			values[] = {0,1};
			texts[] = {"Private Military Company","Takistani Locals"};
			default = 1;
		};
	#endif
	#ifdef COMBINEDOPS
		class townsResistanceFaction {
			title = "$STR_WF_Gameplay_Reinforcement_Type";
			values[] = {0,1,2};
			texts[] = {"Guerillas","Private Military Company","Takistani Locals"};
			default = 2;
		};
	#endif
	class townsResistanceReinforcement {
		title = "$STR_WF_Gameplay_Reinforcement_Resistance";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class townsResistanceVehicleLock {
		title = "$STR_WF_Gameplay_Resistance_VehLock";
		values[] = {0,1};
		texts[] = {"$STR_WF_Disabled","$STR_WF_Enabled"};
		default = 0;
	};
	class townsStartingMode {
		title = "$STR_WF_Gameplay_StartingMode";
		values[] = {0,1,2,3};
		texts[] = {"$STR_WF_None","$STR_WF_Divided_Towns","$STR_WF_Nearby_Town","$STR_WF_Gameplay_StartingLocations_Random"};
		default = 0;
	};
};