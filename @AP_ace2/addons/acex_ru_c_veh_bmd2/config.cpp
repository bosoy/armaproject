////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:41 2012 : Created on Fri Nov 09 22:39:41 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//ndefs=4
enum {
	STABILIZEDINAXISX = 1,
	STABILIZEDINAXISY = 2,
	STABILIZEDINAXESBOTH = 3,
	STABILIZEDINAXESNONE = 0
};

//Class acex_ru_c_veh_bmd2 : config.bin{
class CfgPatches
{
	class acex_ru_veh_bmd2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAData","CACharacters","CACharacters2","CAWeapons","CASounds","Extended_EventHandlers","acex_ru_main","acex_ru_t_veh_bmd1","acex_ru_m_veh_bmd1","acex_ru_s_veh_bmd1"};
		version = "1.14.0.76";
		author[] = {"Soul Assassin (RHS)"};
		authorUrl = "http://forums.bistudio.com/showthread.php?t=100678";
	};
};
class Extended_PreInit_EventHandlers
{
	class acex_ru_veh_bmd2
	{
		init = "call ('\x\acex_ru\addons\c_veh_bmd2\scripts\shellEjection.sqf' call SLX_XEH_COMPILE); acex_ru_veh_bmd2_fnc_init= ('\x\acex_ru\addons\c_veh_bmd2\scripts\BMDinit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class ACE_BMD_2_Base
	{
		class acex_ru_veh_bmd2
		{
			init = "_this call acex_ru_veh_bmd2_fnc_init";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class ACE_BMD_2_Base
	{
		class acex_ru_veh_bmd2
		{
			firedBis = "_this call acex_ru_veh_bmd2_cart_fired";
		};
	};
};
class CfgVehicles
{
	class Tank;
	class Tracked_APC: Tank
	{
		class Turrets;
		class NewTurret;
		class ViewOptics;
		class Sounds;
	};
	class BMP2_Base: Tracked_APC
	{
		class HitPoints;
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class Sounds
		{
			class Engine;
			class Movement;
		};
		class AnimationSources;
	};
	class ACE_BMD_2_Base: BMP2_Base
	{
		model = "\x\acex_ru\addons\m_veh_bmd2\sa_bmd2";
		displayName = "$STR_ACE_VDN_BMD_2_BASE";
		vehicleClass = "Armored";
		side = 0;
		faction = "RU";
		icon = "\x\acex_ru\addons\c_veh_bmd2\data\icon\sa_bmd2_icon.paa";
		picture = "\x\acex_ru\addons\c_veh_bmd2\data\picture\sa_bmd2_pic.paa";
		scope = 1;
		mapSize = 5.4;
		nameSound = "tank";
		simulation = "tank";
		crew = "RU_Soldier_Crew";
		hasCommander = 1;
		hasGunner = 1;
		transportsSoldier = 4;
		typicalCargo[] = {};
		ejectDeadCargo = 1;
		unloadInCombat = 1;
		forceHideDriver = 0;
		viewCargoShadow = 1;
		viewCargoShadowDiff = 0.05;
		driverAction = "Abrams_Driverout";
		driverInAction = "Abrams_Driver";
		cargoAction[] = {"SA_BMD2_Cargo01","SA_BMD2_Cargo03","SA_BMD2_Cargo04","SA_BMD2_Cargo05"};
		getInAction = "GetInMedium";
		getOutAction = "GetOutMedium";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		accuracy = 0.7;
		minSpeed = 0.45;
		maxSpeed = 70;
		fuelCapacity = 300;
		acelleration = 9;
		brakeDistance = 25;
		preferRoads = 0;
		animated = 1;
		canFloat = 1;
		type = 1;
		cost = 3000000;
		camouflage = 5;
		hiddenSelections[] = {"n1","n2","n3","i1","i2","body1","body2","body3","antenna2"};
		hiddenSelectionsTextures[] = {"RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_01_rus1_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_02_rus1_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_03_rus1_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
		selectionLeftOffset = "pasanimL";
		selectionRightOffset = "pasanimP";
		animationSourceHatch = "hatchDriver";
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "2A42";
			};
			class suspensionv1
			{
				source = "user";
				animPeriod = 6;
				initPhase = 0;
			};
			class strutmove
			{
				source = "user";
				animPeriod = 6;
				initPhase = 0;
			};
			class crate_l1_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class crate_l2_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class crate_l3_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class crate_r1_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class crate_r2_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class crate_r3_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class wood_1_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class wood_2_unhide_source
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
		};
		class UserActions
		{
			class LowerSusp
			{
				displayName = "$STR_ACE_UA_BMD_LowerSusp";
				position = "";
				radius = 5;
				condition = "(player == driver this) && {(0 == speed this)} && {!(surfaceIsWater getPos this)} && {(this animationPhase ""suspensionv1"" < 0.5)}";
				statement = "this animate[""suspensionv1"",1];this animate[""suspensionv2"",1];this animate[""suspL1"",1];this animate[""suspL2"",1];this animate[""suspL3"",1];this animate[""suspL4"",1];this animate[""suspL5"",1];this animate[""suspP1"",1];this animate[""suspP2"",1];this animate[""suspP3"",1];this animate[""suspP4"",1];this animate[""suspP5"",1];";
				onlyForPlayer = 1;
			};
			class RaiseSusp
			{
				displayName = "$STR_ACE_UA_BMD_RaiseSusp";
				position = "";
				radius = 5;
				condition = "(player == driver this) && {(0 == speed this)} && {!(surfaceIsWater getPos this)} && {(this animationPhase ""suspensionv1"" > 0.5)}";
				statement = "this animate[""suspensionv1"",0];this animate[""suspensionv2"",0];this animate[""suspL1"",0];this animate[""suspL2"",0];this animate[""suspL3"",0];this animate[""suspL4"",0];this animate[""suspL5"",0];this animate[""suspP1"",0];this animate[""suspP2"",0];this animate[""suspP3"",0];this animate[""suspP4"",0];this animate[""suspP5"",0];";
				onlyForPlayer = 1;
			};
		};
		damageResistance = 0.01796;
		armorStructural = 4;
		secondaryExplosion = 1;
		armor = 100;
		threat[] = {0.9,0.5,1};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_bmd2\sa_bmd2_01.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_01_damage.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_01_destruct.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_02.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_02_damage.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_02_destruct.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_03.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_03.rvmat","x\acex_ru\addons\c_veh_bmd2\sa_bmd2_03_destruct.rvmat"};
		};
		class HitPoints: HitPoints
		{
			class HitLTrack
			{
				armor = 0.3;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0.3;
			};
			class HitRTrack
			{
				armor = 0.3;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0.3;
			};
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0.2;
			};
		};
		smokeLauncherGrenadeCount = 0;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 0;
		smokeLauncherAngle = 70;
		memoryPointGun = "kulas";
		memoryPointsGetInGunner = "pos gunner";
		memoryPointsGetInDriver = "pos driver";
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInGunnerDir = "pos gunner dir";
		memoryPointsGetInDriverDir = "pos driver dir";
		memoryPointsGetInCargoDir = "pos cargo dir";
		memoryPointSupply = "doplnovani";
		memoryPointTrack1L = "Stopa ll";
		memoryPointTrack1R = "Stopa lr";
		memoryPointTrack2L = "Stopa rl";
		memoryPointTrack2R = "Stopa rr";
		memoryPointDriverOptics = "driverview";
		class Exhausts
		{
			class Exhaust1
			{
				position = "vyfuk start";
				direction = "vyfuk konec";
				effect = "ExhaustsEffectBig";
			};
			class Exhaust2
			{
				position = "vyfuk1 start";
				direction = "vyfuk1 konec";
				effect = "ExhaustsEffectBig";
			};
		};
		class Reflectors
		{
			class LeftLight
			{
				color[] = {0.8,0.8,1.0,1.0};
				ambient[] = {0.07,0.07,0.07,1.0};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				brightness = 1.0;
			};
			class GunnerLight: LeftLight
			{
				position = "gunner svetlo";
				direction = "konec gunner svetlo";
				hitpoint = "gunner svetlo";
				selection = "gunner svetlo";
			};
		};
		aggregateReflectors[] = {{"GunnerLight"},{"LeftLight"}};
		insideSoundCoef = 1;
		soundGear[] = {"",5.62341e-005,1};
		soundGetIn[] = {"ca\SOUNDS\Vehicles\Tracked\Other\int\int-tracked-getin-01",0.562341,1};
		soundGetOut[] = {"ca\SOUNDS\Vehicles\Tracked\Other\ext\ext-tracked-getout-01",0.562341,1,50};
		soundEngineOnInt[] = {"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-start-01",1.0,1.0};
		soundEngineOnExt[] = {"ca\SOUNDS\Vehicles\Tracked\Other\ext\ext-tracked-start-01",2.51189,1.0,400};
		soundEngineOffInt[] = {"ca\sounds\vehicles\Tracked\Other\int\int-tracked-stop-02.wss",1.0,1.0};
		soundEngineOffExt[] = {"ca\sounds\vehicles\Tracked\Other\ext\ext-tracked-stop-02.wss",1.25893,0.8,400};
		buildCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_building_01",0.707946,1,150};
		buildCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_building_02",0.707946,1,150};
		buildCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_building_03",0.707946,1,150};
		buildCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_building_04",0.707946,1,150};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_wood_01",0.707946,1,150};
		WoodCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_wood_02",0.707946,1,150};
		WoodCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_wood_03",0.707946,1,150};
		WoodCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_wood_04",0.707946,1,150};
		soundWoodCrash[] = {"woodCrash0",0.25,"woodCrash1",0.25,"woodCrash2",0.25,"woodCrash3",0.25};
		ArmorCrash0[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_01",0.707946,1,150};
		ArmorCrash1[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_02",0.707946,1,150};
		ArmorCrash2[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_03",0.707946,1,150};
		ArmorCrash3[] = {"Ca\sounds\Vehicles\Crash\tank_vehicle_04",0.707946,1,150};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		class SoundEvents
		{
			class AccelerationIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-acce-02","db0",1.0};
				limit = 0.15;
				expression = "engineOn*(1-camPos)*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
			class AccelerationOut
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext-tracked-acce-02","db0",1.0,700};
				limit = 0.15;
				expression = "engineOn*camPos*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
		};
		class Sounds
		{
			class Engine
			{
				sound[] = {"\x\acex_ru\addons\s_veh_bmd2\sa_bmd_engine.wss","db0",1.0,1000};
				frequency = "(randomizer*0.05+0.8)*rpm";
				volume = "engineOn*camPos*(rpm factor[0.4, 0.9])";
			};
			class IdleOut
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext-tracked-idle-02",0.562341,1.0,450};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.6, 0.2])";
			};
			class NoiseOut
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\noise2","db0",1.0,100};
				frequency = "1";
				volume = "camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_01","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsOutH1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_02","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsOutH2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_03","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsOutH3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_04","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsOutH4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_hard_05","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*(1-grass)*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class ThreadsOutS0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_01","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsOutS1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_02","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsOutS2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_03","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsOutS3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_04","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsOutS4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\ext\ext_diesel_treads_soft_05","db0",1.0,200};
				frequency = "1";
				volume = "engineOn*camPos*grass*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class Movement
			{
				sound[] = {"","db0",1.0};
				frequency = "0";
				volume = "0";
			};
			class EngineIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-engine-02","db0",1.0};
				frequency = "(randomizer*0.05+0.8)*rpm";
				volume = "engineOn*(1-camPos)*(rpm factor[0.4, 1])";
			};
			class IdleIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int-tracked-idle-02","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(rpm factor[0.6, 0.15])";
			};
			class NoiseIn
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\noise2",0.199526,1.0};
				frequency = "1";
				volume = "(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsInH0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_01","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsInH1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_02","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsInH2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_03","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsInH3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_04","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsInH4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_hard_05","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*(1-grass)*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
			class ThreadsInS0
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_01","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.3, 0.6]) min (rpm factor[0.6, 0.3]))";
			};
			class ThreadsInS1
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_02","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.5, 0.8]) min (rpm factor[0.8, 0.5]))";
			};
			class ThreadsInS2
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_03","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.65, 0.9]) min (rpm factor[0.9, 0.65]))";
			};
			class ThreadsInS3
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_04","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[0.8, 1.2]) min (rpm factor[1.2, 0.8]))";
			};
			class ThreadsInS4
			{
				sound[] = {"ca\sounds\Vehicles\Tracked\Other\int\int_diesel_treads_soft_05","db0",1.0};
				frequency = "1";
				volume = "engineOn*(1-camPos)*grass*((rpm factor[1, 2.0]) min (rpm factor[2.0, 1]))";
			};
		};
		driverForceOptics = 1;
		driverOpticsModel = "\x\acex_ru\addons\m_veh_bmd2\Sights\o915_TNPO170A_sight";
		driverOpticsColor[] = {1,1,1,1};
		driverOpticsEffect[] = {"OpticsCHAbera1"};
		driverOutOpticsEffect[] = {};
		class ViewOptics
		{
			initFov = "0.33333/ 1";
			minFov = "0.33333/ 1";
			maxFov = "0.33333/ 1";
			initAngleX = 0;
			minAngleX = -110;
			maxAngleX = 110;
			initAngleY = 0;
			minAngleY = -110;
			maxAngleY = 110;
			opticsZoomMin = 0.7;
			opticsZoomMax = 0.7;
			distanceZoomMin = 20;
			distanceZoomMax = 2000;
		};
		class Library
		{
			libTextDesc = "$STR_BMD2_LibDesc,";
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				viewGunnerInExternal = 0;
				proxyType = "CPGunner";
				proxyIndex = 1;
				primaryGunner = 1;
				primaryObserver = 0;
				stabilizedInAxes = 0;
				gunnerAction = "sa_bmd2_gunner";
				animationSourceHatch = "hatchGunner";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGun = "kulas";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				weapons[] = {"ACE_2A42","PKT_veh","AT5LauncherSingle","ACE_SACLOS_Guidance"};
				magazines[] = {"ACE_180Rnd_30mmAP_2A42","ACE_120Rnd_30mmHE_2A42","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","ACE_AT5"};
				soundServo[] = {"\ca\sounds\vehicles\servos\turret-1","db-40",1.0,10};
				selectionFireAnim = "zasleh";
				minElev = -5;
				maxElev = 75;
				initElev = 10;
				lockWhenDriverOut = 1;
				forceHideGunner = 0;
				commanding = 5;
				startengine = 0;
				memoryPointMissile[] = {"Konec rakety"};
				memoryPointMissileDir[] = {"Spice rakety"};
				class Turrets{};
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "turret";
						visual = "turret";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 0.3;
						material = -1;
						name = "mantle";
						visual = "mantle";
						passThrough = 0;
					};
				};
				GunnerForceOptics = 1;
				gunnerOpticsModel = "\x\acex_ru\addons\m_veh_bmd2\sights\sa_BPK142_sight";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOutOpticsModel = "\ca\weapons\optika_empty";
				gunnerOpticsEffect[] = {};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.071;
					minFov = 0.071;
					maxFov = 0.071;
				};
				class OpticsIn
				{
					class bpk142
					{
						initAngleX = 0;
						minAngleX = -110;
						maxAngleX = 110;
						initAngleY = 0;
						minAngleY = -110;
						maxAngleY = 110;
						initFov = 0.071;
						minFov = 0.071;
						maxFov = 0.071;
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optics_empty";
						gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera3"};
					};
				};
			};
			class CommanderOptics: NewTurret
			{
				gunnerCompartments = 1;
				proxyType = "CPCommander";
				proxyIndex = 1;
				gunnerName = "$STR_Commander";
				primaryGunner = 0;
				primaryObserver = 1;
				stabilizedInAxes = 2;
				animationSourceBody = "sightCommanderSourceY";
				animationSourceGun = "sightCommanderSourceX";
				animationSourceHatch = "hatchCommander";
				soundServo[] = {"\ca\sounds\vehicles\servos\turret-1","db-40",1.0,10};
				commanding = 6;
				outGunnerMayFire = 0;
				inGunnerMayFire = 0;
				viewGunnerInExternal = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 1;
				memoryPointGunnerOptics = "gunnerview2";
				memoryPointsGetInGunner = "pos commander";
				memoryPointsGetInGunnerDir = "pos commander dir";
				gunnerGetInAction = "GetInMedium";
				gunnerGetOutAction = "GetOutMedium";
				gunnerAction = "sa_bmd2_commander";
				minElev = -15;
				maxElev = 15;
				initElev = 0;
				minTurn = -50;
				maxTurn = 50;
				initTurn = 0;
				gunnerOpticsModel = "\x\acex_ru\addons\m_veh_bmd2\Sights\sa_commander_optics";
				gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
				gunnerOpticsEffect[] = {"TankGunnerOptics1","WeaponsOptics","OpticsCHAbera3"};
				gunnerOutOpticsEffect[] = {};
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOutForceOptics = 0;
				gunnerForceOptics = 1;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 5";
					minFov = "0.33333/ 5";
					maxFov = "0.33333/ 5";
					distanceZoomMin = 100;
					distanceZoomMax = 2000;
					visionMode[] = {"Normal","NVG"};
				};
			};
			class GPMGTurret1: NewTurret
			{
				proxyType = "CPGunner";
				proxyIndex = 2;
				body = "obsTurret2";
				gun = "obsGun2";
				animationSourceBody = "obsTurret2";
				animationSourceGun = "obsGun2";
				animationSourceHatch = "hatchMgGunner";
				selectionFireAnim = "zasleh1";
				gunnerName = "$STR_ACE_BMD_MGFrontRight";
				hasGunner = 0;
				soundServo[] = {};
				forceHideGunner = 0;
				primaryObserver = 0;
				primaryGunner = 0;
				commanding = 4;
				minElev = -10;
				maxElev = 10;
				minTurn = -10;
				maxTurn = 10;
				weapons[] = {"ACE_PKT_out"};
				magazines[] = {"250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				class CargoLight
				{
					ambient[] = {0.6,0,0.15,1};
					brightness = 0.007;
					color[] = {0,0,0,0};
				};
				gunBeg = "muzzle2";
				gunEnd = "end2";
				memoryPointGun = "memoryPointGun2";
				memoryPointGunnerOptics = "gunnerview3";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerAction = "sa_bmd2_mggunner";
				viewGunnerInExternal = 0;
				startengine = 0;
				class Turrets{};
				gunnerOpticsModel = "\x\acex_ru\addons\m_veh_bmd2\Sights\o915_TNPP220A_sight";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerForceOptics = 1;
				gunnerOpticsEffect[] = {"TankGunnerOptics1","WeaponsOptics","OpticsCHAbera3"};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 1.5";
					minFov = "0.33333/ 1.5";
					maxFov = "0.33333/ 1.5";
					distanceZoomMin = 200;
					distanceZoomMax = 2000;
				};
			};
			class LeftBack: NewTurret
			{
				body = "lseat_turret";
				gun = "lseat_gun";
				animationSourceBody = "lseat_Turret";
				animationSourceGun = "lseat_Gun";
				animationSourceHatch = "";
				selectionFireAnim = "";
				minElev = 0;
				maxElev = 0;
				initTurn = 60;
				minTurn = 60;
				maxTurn = 60;
				maxHorizontalRotSpeed = 0;
				maxVerticalRotSpeed = 0;
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "$STR_ACE_BMD_CargoBackLeft";
				commanding = 3;
				gunBeg = "";
				gunEnd = "";
				memoryPointGun = "";
				memoryPointGunnerOptics = "lseat_view";
				gunnerAction = "";
				gunnerInAction = "BMP2_Gunner";
				weapons[] = {"FakeWeapon"};
				magazines[] = {};
				forceHideGunner = 1;
				hasGunner = 0;
				primaryGunner = 0;
				primaryObserver = 0;
				gunnerOpticsModel = "\x\acex_ru\addons\m_veh_bmd2\Sights\o915_TNPO170A_sight";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerForceOptics = 1;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 1";
					minFov = "0.33333/ 1";
					maxFov = "0.33333/ 1";
				};
			};
			class RightBack: LeftBack
			{
				body = "rseat_turret";
				gun = "rseat_gun";
				animationSourceBody = "rseat_Turret";
				animationSourceGun = "rseat_Gun";
				initTurn = -60;
				minTurn = -60;
				maxTurn = -60;
				gunnerName = "$STR_ACE_BMD_CargoBackRight";
				memoryPointGunnerOptics = "rseat_view";
				hasGunner = 0;
				commanding = 2;
			};
			class MainBack: LeftBack
			{
				body = "bseat_turret";
				gun = "bseat_gun";
				animationSourceBody = "bseat_Turret";
				animationSourceGun = "bseat_Gun";
				initTurn = 180;
				minTurn = 180;
				maxTurn = 180;
				gunnerName = "$STR_ACE_BMD_CargoBackCenter";
				memoryPointGunnerOptics = "bseat_view";
				hasGunner = 0;
				commanding = 1;
			};
		};
		ace_minimalhit[] = {7,40};
		ace_era = 0;
		ace_p_detonation_hull = 0.8;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.2;
		ace_armor_hull[] = {{15,15},{10,10},{10,10},{10,10},{10,10},{10,10}};
		ace_armor_turret[] = {{7,7},{7,7},{7,7},{7,7},{7,7}};
		ace_sys_reticles_gunneroptics = 1;
		ace_sys_reticles_gunnersight = "BPK_2_42";
	};
	class ACE_BMD_2_RU: ACE_BMD_2_Base
	{
		scope = 2;
		accuracy = 0.5;
		faction = "ACE_VDV";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_2A42","PKT_veh","AT5LauncherSingle","ACE_SACLOS_Guidance"};
				magazines[] = {"ACE_180Rnd_30mmAP_2A42","ACE_120Rnd_30mmHE_2A42","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","ACE_AT5B"};
			};
			class CommanderOptics: CommanderOptics{};
			class GPMGTurret1: GPMGTurret1{};
			class LeftBack: LeftBack{};
			class RightBack: RightBack{};
			class MainBack: MainBack{};
		};
	};
	class ACE_BMD_2K_RU: ACE_BMD_2_RU
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_BMD_2K_BASE";
		hiddenSelectionsTextures[] = {"RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_01_rus1_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_02_rus1_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_03_rus1_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_01_rus1_co.paa"};
	};
	class ACE_BMD_2_CDF: ACE_BMD_2_Base
	{
		scope = 2;
		accuracy = 0.5;
		crew = "CDF_Soldier_Crew";
		side = 1;
		faction = "CDF";
		hiddenSelectionsTextures[] = {"RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_01_cdf_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_02_cdf_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_03_cdf_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
	class ACE_BMD_2_INS: ACE_BMD_2_Base
	{
		scope = 2;
		accuracy = 0.5;
		crew = "INS_Soldier_Crew";
		faction = "INS";
		hiddenSelectionsTextures[] = {"RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_01_chdkz_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_02_chdkz_co.paa","\x\acex_ru\addons\t_veh_bmd2\sa_bmd2_03_chdkz_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
	class House;
	class ace_casing_30mm: House
	{
		model = "\x\acex_ru\addons\m_veh_bmd2\scripts\sa_casing_30mm";
		displayName = "Cartridge";
		nameSound = "";
		destrType = "DestructNo";
		mapSize = 0.7;
		accuracy = 0;
		armor = 5;
		scope = 1;
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		sa_bmd2_commander = "sa_bmd2_commander";
		sa_bmd2_mggunner = "sa_bmd2_mggunner";
		sa_bmd2_gunner = "sa_bmd2_gunner";
		SA_BMD2_Cargo01 = "SA_BMD2_Cargo01";
		SA_BMD2_Cargo02 = "SA_BMD2_Cargo02";
		SA_BMD2_Cargo03 = "SA_BMD2_Cargo03";
		SA_BMD2_Cargo04 = "SA_BMD2_Cargo04";
		SA_BMD2_Cargo05 = "SA_BMD2_Cargo05";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class sa_bmd2_commander: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_commanderout.rtm";
		};
		class sa_bmd2_mggunner: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_mggunnerout.rtm";
		};
		class sa_bmd2_gunner: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_gunnerout.rtm";
		};
		class sa_bmd2_Cargo01: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_cargo1.rtm";
		};
		class sa_bmd2_Cargo02: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_cargo2.rtm";
		};
		class sa_bmd2_Cargo03: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_cargo3.rtm";
		};
		class sa_bmd2_Cargo04: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_cargo4.rtm";
		};
		class sa_bmd2_Cargo05: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd2\anims\sa_cargo5.rtm";
		};
	};
};
//};
