////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 02 21:00:06 2012 : Created on Fri Nov 02 21:00:06 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_stryker : config.bin{
class CfgPatches
{
	class acex_veh_stryker
	{
		units[] = {"ACE_StrykerBase","ACE_Stryker_ICV_M2","ACE_Stryker_ICV_M2_SLAT","ACE_Stryker_ICV_MK19","ACE_Stryker_ICV_MK19_SLAT","ACE_Stryker_TOW","ACE_Stryker_TOW_Slat","ACE_Stryker_TOW_MG","ACE_Stryker_TOW_MG_Slat","ACE_Stryker_MGS","ACE_Stryker_MGS_Slat","ACE_Stryker_RV","ACE_Stryker_RV_SLAT"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_m_veh_stryker","acex_t_veh_stryker","acex_s_veh_stryker","ace_c_vehicle"};
		version = "1.14.0.369";
	};
};
class WeaponCloudsMGun;
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
	};
	class Car: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
				class ViewOptics;
			};
		};
		class HitPoints;
		class ViewOptics;
		class ViewGunner;
		class ViewPilot;
	};
	class Wheeled_APC: Car{};
	class ACE_StrykerBase: Wheeled_APC
	{
		scope = 0;
		faction = "BIS_US";
		model = "\x\acex\addons\m_veh_stryker\stryker_ICV";
		accuracy = 0.3;
		displayName = "IAV Stryker";
		picture = "\x\acex\addons\c_veh_stryker\data\picture\stryker_ICV_CA.paa";
		Icon = "\x\acex\addons\c_veh_stryker\data\icon\icomap_Stryker_CA.paa";
		mapSize = 10;
		vehicleclass = "ArmouredW";
		nameSound = "veh_WheeledAPC";
		driverForceOptics = 1;
		commanderCanSee = "2+4+8+16";
		gunnerCanSee = "4+8+16";
		driverCanSee = "2+8+16";
		driveropticsmodel = "\ca\weapons\2Dscope_com1";
		driveropticseffect[] = {"TankCommanderOptics1"};
		class ViewOptics: ViewOptics
		{
			thermalmode[] = {0,1};
			visionmode[] = {"Normal","NVG","Ti"};
		};
		memoryPointsGetInDriver = "pos_driver";
		memoryPointsGetInDriverDir = "pos_driver_dir";
		memoryPointsGetInCommander = "pos_commander";
		memoryPointsGetInCommanderDir = "pos_commander_dir";
		memoryPointsGetInCargo = "pos_cargo";
		memoryPointsGetInCargoDir = "pos_cargo_dir";
		memoryPointsGetInCoDriver = "pos_codriver";
		memoryPointsGetInCoDriverDir = "pos_codriver_dir";
		memoryPointSupply = "supply";
		selectionFireAnim = "zasleh";
		selectionBrakeLights = "light_brake";
		selectionBackLights = "light_back";
		memoryPointExhaust = "exhaust_start";
		memoryPointExhaustDir = "exhaust_end";
		memoryPointTrackFLL = "tyreTrack_1_1l";
		memoryPointTrackFLR = "tyreTrack_1_1r";
		memoryPointTrackBLL = "tyreTrack_1_2l";
		memoryPointTrackBLR = "tyreTrack_1_2r";
		memoryPointTrackFRL = "tyreTrack_2_1l";
		memoryPointTrackFRR = "tyreTrack_2_1r";
		memoryPointTrackBRL = "tyreTrack_2_2l";
		memoryPointTrackBRR = "tyreTrack_2_2r";
		damperSize = 0.1;
		damperForce = 1;
		wheelCircumference = 3.277;
		turnCoef = 4.0;
		steerAheadSimul = 0.6;
		steerAheadPlan = 0.5;
		enableGPS = 1;
		transportSoldier = 9;
		side = 1;
		crew = "US_Soldier_Crew_EP1";
		fuelCapacity = 246;
		armor = 150;
		armorStructural = 3.25;
		damageResistance = 0.01199;
		crewVulnerable = 0;
		maxSpeed = 90;
		threat[] = {0.5,0.5,0.5};
		viewCargoShadow = 1;
		viewCargoShadowDiff = 0.05;
		viewDriverShadowDiff = 0.05;
		viewGunnerShadowDiff = 0.05;
		hideProxyInCombat = 1;
		driverIsCommander = 0;
		weapons[] = {};
		magazines[] = {};
		hasGunner = 1;
		driverAction = "Stryker_DriverOut";
		driverInAction = "Stryker_Driver";
		cargoAction[] = {"Stryker_Cargo01"};
		unitInfoType = "UnitInfoShip";
		typicalCargo[] = {"US_Soldier_Crew_EP1","US_Soldier_Crew_EP1","US_Soldier_Crew_EP1"};
		gunnerHasFlares = "true";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ballisticsComputer = 0;
				soundServo[] = {"\ca\wheeled\Data\Sound\servo3","db-35",1.0};
				body = "mainTurret";
				gun = "mainGun";
				gunnerAction = "Stryker_GunnerOut";
				gunnerInAction = "Stryker_Gunner";
				gunBeg = "gun_muzzle";
				gunEnd = "gun_chamber";
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				memoryPointGun = "machinegun";
				selectionFireAnim = "zasleh";
				gunnerForceOptics = 0;
				outGunnerMayFire = 0;
				memoryPointGunnerOptics = "gunnerview";
				gunnerOpticsModel = "\x\acex\addons\m_veh_stryker\optika_stryker_gunner";
				memoryPointGunnerOutOptics = "";
				gunnerOutOpticsModel = "";
				hasGunner = 1;
				castGunnerShadow = 1;
				minElev = -20;
				maxElev = "+60";
				minTurn = -360;
				maxTurn = "+360";
				gunnerFireAlsoInInternalCamera = 0;
				stabilizedInAxes = 3;
				class ViewGunner: ViewGunner
				{
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.3333+ 0.41667";
					minFov = 0.3333;
					maxFov = "0.3333+ 0.41667";
				};
				class ViewOptics: ViewOptics
				{
					initFov = "0.3333/ 3";
					minFov = "0.3333/ 9";
					maxFov = "0.3333/ 3";
				};
			};
		};
		class ViewPilot: ViewPilot
		{
			initFov = 0.75;
			minFov = 0.75;
			maxFov = 0.75;
		};
		class Reflectors
		{
			class Left
			{
				color[] = {0.9,0.8,0.8,1.0};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "Light_1_1_source";
				direction = "Light_1_1_target";
				hitpoint = "Light_1_1";
				selection = "Light_1_1";
				size = 0.5;
				brightness = 0.5;
			};
			class Right
			{
				color[] = {0.9,0.8,0.8,1.0};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "Light_1_2_source";
				direction = "Light_1_2_target";
				hitpoint = "Light_1_2";
				selection = "Light_1_2";
				size = 0.5;
				brightness = 0.5;
			};
		};
		selectionDamage = "karoserie";
		class HitPoints
		{
			class HitLFWheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitRFWheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitLF2Wheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitRF2Wheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitLMWheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_1_3_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitRMWheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_2_3_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitLBWheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_1_4_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitRBWheel
			{
				armor = 0.4;
				material = -1;
				name = "wheel_2_4_steering";
				visual = "";
				passThrough = 0.4;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0.5;
			};
			class HitBody
			{
				armor = 0.3;
				material = -1;
				name = "NEkaroserie";
				visual = "karoserie";
				passThrough = 1;
			};
			class HitRGlass
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 1;
			};
			class HitLGlass
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 1;
			};
		};
		class AnimationSources
		{
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitLF2Wheel: HitLFWheel
			{
				hitpoint = "HitLF2Wheel";
			};
			class HitRF2Wheel: HitLFWheel
			{
				hitpoint = "HitRF2Wheel";
			};
			class HitLMWheel: HitLFWheel
			{
				hitpoint = "HitLMWheel";
			};
			class HitRMWheel: HitLFWheel
			{
				hitpoint = "HitRMWheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
		};
		class Library
		{
			libTextDesc = "";
		};
		soundGear[] = {"",0,1};
		soundGetIn[] = {"\ca\Sounds_E\Wheeled_E\stryker\stryker_door",1.0,1};
		soundGetOut[] = {"\ca\Sounds_E\Wheeled_E\stryker\stryker_door",1.0,1,30};
		soundEngineOnInt[] = {"\x\acex\addons\s_veh_stryker\Stryker_engine_on_in.wss",1.0,1.0};
		soundEngineOnExt[] = {"\x\acex\addons\s_veh_stryker\Stryker_engine_on_out.wss",1.0,1.0,300};
		soundEngineOffInt[] = {"\x\acex\addons\s_veh_stryker\Stryker_engine_off_in.wss",1.0,1.0};
		soundEngineOffExt[] = {"\x\acex\addons\s_veh_stryker\Stryker_engine_off_out.wss",1.0,1.0,300};
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
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_AccelerationIn.wss",0.972341,1.0};
				limit = "0.15";
				expression = "engineOn*(1-camPos)*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
			class AccelerationOut
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_AccelerationOut.wss",1.352341,1.0,300};
				limit = "0.15";
				expression = "engineOn*camPos*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
		};
		class Sounds
		{
			class Engine
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_engine.wss",2.91189,1.0,500};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "camPos*engineOn*((rpm factor[0.25, 0.4]) min (rpm factor[0.7, 0.5]))";
			};
			class EngineHighOut
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_EngineHighOut.wss",3.25189,1.0,550};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "camPos*engineOn*(rpm factor[0.5, 0.8])";
			};
			class IdleOut
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_IdleOut.wss","db0.110000",1.0,350};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.4, 0])";
			};
			class TiresRockOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-rock2",0.316228,1.0,100};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-sand2",0.316228,1.0,100};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-grass3",0.316228,1.0,100};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-mud2",0.316228,1.0,100};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-gravel1",0.316228,1.0,100};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-asphalt3",0.316228,1.0,100};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_noise.wss",3.6,0.95,350};
				frequency = "1";
				volume = "camPos*(damper0 max 0.04)*(speed factor[0, 8])";
			};
			class EngineLowIn
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_EngineLowIn.wss","db0",1.0};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "(1-camPos)*engineOn*((rpm factor[0.25, 0.4]) min (rpm factor[0.7, 0.5]))";
			};
			class EngineHighIn
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_EngineHighIn.wss","db0.140000",1.0};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "(1-camPos)*engineOn*(rpm factor[0.5, 0.8])";
			};
			class IdleIn
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_Stryker_IdleIn.wss",0.408107,1.0};
				frequency = "1";
				volume = "engineOn*(rpm factor[0.4, 0])*(1-camPos)";
			};
			class TiresRockIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-rock2",0.0562341,1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-sand2",0.0562341,1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-grass3",0.0562341,1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-mud2",0.0562341,1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-gravel3",0.0562341,1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-asphalt3",0.0562341,1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"\x\acex\addons\s_veh_stryker\Stryker_RC.wss",20.0,1.0};
				frequency = "1";
				volume = "(damper0 max 0.04)*(speed factor[0, 8])*(1-camPos)";
			};
			class Movement
			{
				sound = "soundEnviron";
				frequency = "1";
				volume = "0";
			};
		};
		ace_sa_enabled = 0;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ACE_NBC_Protection = 1;
		ace_minimalhit[] = {19,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{35,35},{18,18},{18,18},{18,18},{18,18},{20,20}};
		ace_armor_turret[] = {{30,30},{18,18},{18,18},{18,18},{18,18}};
		ace_sys_repair_jerrycan_count = 2;
	};
	class ACE_Stryker_ICV_M2: ACE_StrykerBase
	{
		scope = 2;
		accuracy = 0.5;
		displayName = "M1126 Stryker ICV (M2)";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\weapons\data\m2.rvmat","ca\weapons\data\m2_damage.rvmat","ca\weapons\data\m2_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_destruct.rvmat"};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "0.3333/ 0.5";
						minFov = "0.3333/ 0.5";
						maxFov = "0.3333/ 0.5";
						gunnerOpticsModel = "\ca\Weapons\2Dscope_RWS";
						gunnerOpticsEffect[] = {};
						visionMode[] = {"Normal"};
					};
					class Medium: Wide
					{
						initFov = "0.3333/ 3";
						minFov = "0.3333/ 3";
						maxFov = "0.3333/ 3";
					};
					class Narrow: Wide
					{
						initFov = "0.3333/ 8.5";
						minFov = "0.3333/ 8.5";
						maxFov = "0.3333/ 8.5";
					};
					class ace_crows_ti_wide: Wide
					{
						initFov = "0.3333/ 3";
						minFov = "0.3333/ 3";
						maxFov = "0.3333/ 3";
						visionMode[] = {"Ti"};
						thermalMode[] = {0,1};
					};
					class ace_crows_ti_narrow: ace_crows_ti_wide
					{
						initFov = "0.3333/ 9";
						minFov = "0.3333/ 9";
						maxFov = "0.3333/ 9";
					};
				};
				weapons[] = {"M2","SmokeLauncher"};
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","SmokeLauncherMag","SmokeLauncherMag"};
			};
		};
		smokeLauncherGrenadeCount = 4;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 1;
		smokeLauncherAngle = 90;
		ace_sa_enabled = 0;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_range_unit = "meters";
		ace_sa_maxelevation = 2000;
		ace_sa_table_elev[] = {{0,0},{100,0.52},{200,1.37},{300,1.9},{400,2.72},{500,4.1},{600,4.6},{700,5.58},{800,6.7},{900,7.93},{1000,9.22},{1100,10.7},{1200,12.18},{1300,13.85},{1400,15.7},{1500,17.75},{1600,19.85},{1700,22.2},{1800,24.76},{1900,27.5},{2000,30.5}};
		class AnimationSources: AnimationSources
		{
			class M2_ammo_belt_rotation
			{
				source = "reload";
				weapon = "M2";
			};
			class M2_recoil
			{
				source = "reload";
				weapon = "M2";
			};
		};
		hiddenSelections[] = {"SELECTION_SLAT"};
		cargoAction[] = {"Stryker_Cargo01","Stryker_Cargo01","Stryker_Cargo01","Stryker_Cargo01","Stryker_Cargo01","Stryker_Cargo01","Stryker_Cargo01","Stryker_Cargo01","Stryker_Cargo01"};
		transportSoldier = 9;
		ace_tankfcs_enabled = 1;
		ace_tankfcs_maxlrfrange = 5000;
		ace_tankfcs_minlrfrange = 200;
		ace_tankfcs_lrfaccuracy = 10;
		ace_tankfcs_lrfcooldowntime = 3;
		ace_tankfcs_maxlead = 0;
		ace_tankfcs_battlesight = 500;
		ace_tankfcs_digitscolor[] = {0.7,0,0,1};
		ace_tankfcs_digitsstyle = 0;
		ace_tankfcs_rdystyle = 1;
		ace_tankfcs_maxranges[] = {"100Rnd_127x99_M2",2000};
	};
	class ACE_Stryker_ICV_M2_SLAT: ACE_Stryker_ICV_M2
	{
		displayName = "M1126 Stryker ICV (M2/SLAT)";
		armor = 200;
		armorStructural = 3.5;
		hiddenSelections[] = {};
		ace_era = 1;
		ace_era_hull[] = {{20,600},{20,600},{20,600},{20,600},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.9,0.9,0.9,0};
		ace_era_blocks_hull[] = {3,8,8,3,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
	class ACE_Stryker_ICV_M2_D: ACE_Stryker_ICV_M2
	{
		vehicleClass = "ArmouredD";
		hiddenSelections[] = {"SELECTION_SLAT","camo1","camo2","camo7","camo9"};
		HiddenSelectionsTextures[] = {"","ca\wheeled_e\stryker\data\stryker_body1_des_co.paa","ca\wheeled_e\stryker\data\stryker_body2_des_co.paa","ca\wheeled_e\stryker\data\icv_des_co.paa","ca\wheeled_e\stryker\data\stryker_alfa_des_ca.paa"};
	};
	class ACE_Stryker_ICV_M2_SLAT_D: ACE_Stryker_ICV_M2_SLAT
	{
		vehicleClass = "ArmouredD";
		hiddenSelections[] = {"SELECTION_SLAT","camo1","camo2","camo7","camo9"};
		HiddenSelectionsTextures[] = {"ca\wheeled_e\stryker\data\slat_armor_des_ca.paa","ca\wheeled_e\stryker\data\stryker_body1_des_co.paa","ca\wheeled_e\stryker\data\stryker_body2_des_co.paa","ca\wheeled_e\stryker\data\icv_des_co.paa","ca\wheeled_e\stryker\data\stryker_alfa_des_ca.paa"};
	};
	class ACE_Stryker_ICV_MK19: ACE_Stryker_ICV_M2
	{
		model = "\x\acex\addons\m_veh_stryker\stryker_mk19";
		picture = "\x\acex\addons\c_veh_stryker\data\picture\stryker_mk19_CA.paa";
		Icon = "\x\acex\addons\c_veh_stryker\data\icon\icomap_Stryker_mk_CA.paa";
		displayName = "M1126 Stryker ICV (Mk19)";
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex\addons\c_veh_stryker\stryker_icv.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_destruct.rvmat","ca\weapons\data\mk19.rvmat","ca\weapons\data\mk19.rvmat","ca\weapons\data\mk19_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_destruct.rvmat"};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_MK19","SmokeLauncher"};
				magazines[] = {"48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","SmokeLauncherMag","SmokeLauncherMag"};
				class GunFire: WeaponCloudsMGun
				{
					interval = 0.01;
				};
			};
		};
		hiddenSelections[] = {"SELECTION_SLAT"};
		ace_sa_enabled = 0;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_maxelevation = 2000;
		ace_sa_minelevation = 300;
		ace_sa_stepelevation = 100;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_TE_enabled = 1;
		ace_sa_table_elev[] = {{0,0},{100,9},{200,18.6},{300,28},{400,39},{500,51},{600,64},{700,78},{800,93},{900,110},{1000,128},{1100,148},{1200,171},{1300,195},{1400,223},{1500,255},{1600,285},{1700,326},{1800,380},{1900,450},{2000,570}};
		ace_tankfcs_enabled = 1;
		ace_tankfcs_maxlrfrange = 5000;
		ace_tankfcs_minlrfrange = 200;
		ace_tankfcs_lrfaccuracy = 10;
		ace_tankfcs_lrfcooldowntime = 3;
		ace_tankfcs_maxlead = 0;
		ace_tankfcs_battlesight = 300;
		ace_tankfcs_digitscolor[] = {0.7,0,0,1};
		ace_tankfcs_digitsstyle = 0;
		ace_tankfcs_rdystyle = 1;
		ace_tankfcs_maxranges[] = {"48Rnd_40mm_MK19",2000};
	};
	class ACE_Stryker_ICV_MK19_SLAT: ACE_Stryker_ICV_MK19
	{
		displayName = "M1126 Stryker ICV (Mk19/SLAT)";
		armor = 200;
		armorStructural = 3.5;
		hiddenSelections[] = {};
		ace_era = 1;
		ace_era_hull[] = {{20,600},{20,600},{20,600},{20,600},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.9,0.9,0.9,0};
		ace_era_blocks_hull[] = {3,8,8,3,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
	class ACE_Stryker_ICV_MK19_D: ACE_Stryker_ICV_MK19
	{
		vehicleClass = "ArmouredD";
		hiddenSelections[] = {"SELECTION_SLAT","camo1","camo2","camo7","camo9"};
		HiddenSelectionsTextures[] = {"","ca\wheeled_e\stryker\data\stryker_body1_des_co.paa","ca\wheeled_e\stryker\data\stryker_body2_des_co.paa","ca\wheeled_e\stryker\data\icv_des_co.paa","ca\wheeled_e\stryker\data\stryker_alfa_des_ca.paa"};
	};
	class ACE_Stryker_ICV_MK19_SLAT_D: ACE_Stryker_ICV_MK19_SLAT
	{
		vehicleClass = "ArmouredD";
		hiddenSelections[] = {"SELECTION_SLAT","camo1","camo2","camo7","camo9"};
		HiddenSelectionsTextures[] = {"ca\wheeled_e\stryker\data\slat_armor_des_ca.paa","ca\wheeled_e\stryker\data\stryker_body1_des_co.paa","ca\wheeled_e\stryker\data\stryker_body2_des_co.paa","ca\wheeled_e\stryker\data\icv_des_co.paa","ca\wheeled_e\stryker\data\stryker_alfa_des_ca.paa"};
	};
	class ACE_Stryker_TOW: ACE_StrykerBase
	{
		scope = 2;
		model = "\x\acex\addons\m_veh_stryker\stryker_tow";
		picture = "\x\acex\addons\c_veh_stryker\data\picture\stryker_tow_CA.paa";
		Icon = "\x\acex\addons\c_veh_stryker\data\icon\icomap_StrykerTOW_CA.paa";
		mapSize = 10;
		accuracy = 0.5;
		displayName = "M1134 Stryker ATGM";
		transportSoldier = 0;
		threat[] = {0.3,1,0.3};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex\addons\c_veh_stryker\stryker_icv_body2.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_tow_body.rvmat","x\acex\addons\c_veh_stryker\stryker_tow_body_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_tow_body_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_tow.rvmat","x\acex\addons\c_veh_stryker\stryker_tow_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_tow_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_destruct.rvmat"};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"TOWLauncher","SmokeLauncher"};
				magazines[] = {"2Rnd_TOW2","2Rnd_TOW2","2Rnd_TOW2","SmokeLauncherMag","SmokeLauncherMag"};
				gunnerOpticsModel = "\ca\weapons_e\TOW_TI";
				gunnerOpticsEffect[] = {};
				gunBeg = "spice rakety";
				gunEnd = "konec rakety";
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.3333/ 6";
					minFov = "0.3333/ 6";
					maxFov = "0.3333/ 6";
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {2,3};
				};
			};
		};
		hiddenSelections[] = {"SELECTION_SLAT"};
		smokeLauncherGrenadeCount = 4;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 1;
		smokeLauncherAngle = 90;
	};
	class ACE_Stryker_TOW_Slat: ACE_Stryker_TOW
	{
		displayName = "M1134 Stryker ATGM (SLAT)";
		armor = 200;
		armorStructural = 3.5;
		hiddenSelections[] = {};
		ace_era = 1;
		ace_era_hull[] = {{20,600},{20,600},{20,600},{20,600},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.9,0.9,0.9,0};
		ace_era_blocks_hull[] = {3,8,8,3,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
	class ACE_Stryker_TOW_MG: ACE_Stryker_TOW
	{
		displayName = "M1134 Stryker ATGM (M240)";
		model = "\x\acex\addons\m_veh_stryker\M1134";
		class AnimationSources
		{
			class M240_ammo_belt_rotation
			{
				source = "reload";
				weapon = "M240_veh";
			};
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitLF2Wheel: HitLFWheel
			{
				hitpoint = "HitLF2Wheel";
			};
			class HitRF2Wheel: HitLFWheel
			{
				hitpoint = "HitRF2Wheel";
			};
			class HitLMWheel: HitLFWheel
			{
				hitpoint = "HitLMWheel";
			};
			class HitRMWheel: HitLFWheel
			{
				hitpoint = "HitRMWheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret{};
			class CommanderOptics: MainTurret
			{
				weapons[] = {"M240_veh"};
				magazines[] = {"ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240"};
				proxyType = "CPCommander";
				proxyIndex = 1;
				gunnerName = "$STR_POSITION_COMMANDER";
				primaryGunner = 0;
				primaryObserver = 1;
				gunnerAction = "Abrams_CommanderOut";
				gunnerInAction = "Stryker_Gunner";
				body = "LGunner_Turret";
				gun = "LGUNNER_Gun";
				animationSourceBody = "LGunner_Turret";
				animationSourceGun = "LGUNNER_Gun";
				animationSourceHatch = "hatchCommander";
				soundServo[] = {"","db1",1};
				minElev = -30;
				maxElev = 45;
				initElev = 0;
				minTurn = -135;
				maxTurn = 135;
				initTurn = 0;
				commanding = 1;
				outGunnerMayFire = 1;
				inGunnerMayFire = 0;
				gunnerForceOptics = 0;
				viewGunnerInExternal = 0;
				gunnerOpticsModel = "CA\Tracked_E\driverOptics";
				gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
				gunnerOutOpticsColor[] = {0,0,0,1};
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 0;
				memoryPointGunnerOutOptics = "lgunner_weapon_view";
				memoryPointGunnerOptics = "commanderview";
				memoryPointsGetInGunner = "pos_commander";
				memoryPointsGetInGunnerDir = "pos_commander_dir";
				gunBeg = "flak_muzzle";
				gunEnd = "flak_chamber";
				memoryPointGun = "flak_muzzle";
				selectionFireAnim = "zasleh";
				startEngine = 0;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -45;
					maxAngleX = 45;
					initAngleY = 0;
					minAngleY = -120;
					maxAngleY = 120;
					initFov = "0.3333/ 1";
					minFov = "0.3333/ 2";
					maxFov = "0.3333/ 1";
				};
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -45;
					maxAngleX = 45;
					initAngleY = 0;
					minAngleY = -135;
					maxAngleY = 135;
					initFov = "0.3333+ 0.41667";
					minFov = 0.3333;
					maxFov = "0.3333+ 0.41667";
				};
			};
		};
		hiddenSelections[] = {"SELECTION_SLAT"};
	};
	class ACE_Stryker_TOW_MG_Slat: ACE_Stryker_TOW_MG
	{
		displayName = "M1134 Stryker ATGM (M240/SLAT)";
		armor = 200;
		armorStructural = 3.5;
		hiddenSelections[] = {};
		ace_era = 1;
		ace_era_hull[] = {{20,600},{20,600},{20,600},{20,600},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.9,0.9,0.9,0};
		ace_era_blocks_hull[] = {3,8,8,3,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
	class ACE_Stryker_MGS: ACE_StrykerBase
	{
		scope = 2;
		accuracy = 0.5;
		model = "\x\acex\addons\m_veh_stryker\M1128";
		displayName = "M1128 Stryker MGS";
		picture = "\x\acex\addons\c_veh_stryker\data\picture\m1128_CA.paa";
		transportSoldier = 0;
		driverIsCommander = 0;
		hasGunner = 1;
		hasCommander = 1;
		class AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_StrykerMgun105";
			};
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitLF2Wheel: HitLFWheel
			{
				hitpoint = "HitLF2Wheel";
			};
			class HitRF2Wheel: HitLFWheel
			{
				hitpoint = "HitRF2Wheel";
			};
			class HitLMWheel: HitLFWheel
			{
				hitpoint = "HitLMWheel";
			};
			class HitRMWheel: HitLFWheel
			{
				hitpoint = "HitRMWheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerOutOpticsModel = "";
				minElev = -10;
				maxElev = 14;
				weapons[] = {"ACE_StrykerMgun105","M240_veh"};
				magazines[] = {"1200Rnd_762x51_M240","1200Rnd_762x51_M240","ACE_1000Rnd_762x51_M240","ACE_9Rnd_M456A2","ACE_9Rnd_M900"};
				gunnerOpticsModel = "CA\Tracked_E\gunnerOptics_M1A1";
				gunnerOpticsEffect[] = {};
				stabilizedInAxes = 3;
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "0.3333/ 3";
						minFov = "0.3333/ 3";
						maxFov = "0.3333/ 3";
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "CA\Tracked_E\gunnerOptics_M1A1";
						gunnerOpticsEffect[] = {};
					};
					class Medium: Wide
					{
						initFov = "0.3333/ 10";
						minFov = "0.3333/ 10";
						maxFov = "0.3333/ 10";
						gunnerOpticsModel = "CA\Tracked_E\gunnerOptics_M1A1";
					};
					class Narrow: Wide
					{
						gunnerOpticsModel = "CA\Tracked_E\gunnerOptics_M1A1";
						initFov = "0.3333/ 18";
						minFov = "0.3333/ 18";
						maxFov = "0.3333/ 18";
					};
				};
				class ViewGunner: ViewGunner
				{
					initFov = "0.3333+ 0.41667";
					minFov = 0.3333;
					maxFov = "0.3333+ 0.41667";
				};
				class ViewOptics: ViewOptics
				{
					initFov = "0.3333/ 3";
					minFov = "0.3333/ 18";
					maxFov = "0.3333/ 3";
				};
			};
			class CommanderOptics: NewTurret
			{
				stabilizedInAxes = "StabilizedInAxesNone";
				ace_sa_enabled = 0;
				weapons[] = {"SmokeLauncher"};
				magazines[] = {"SmokeLauncherMag","SmokeLauncherMag"};
				proxyType = "CPCommander";
				proxyIndex = 1;
				gunnerName = "$STR_POSITION_COMMANDER";
				primaryGunner = 0;
				primaryObserver = 1;
				body = "commsights";
				gun = "commsights_gun";
				gunnerAction = "Stryker_GunnerOut";
				gunnerInAction = "Stryker_Gunner";
				animationSourceBody = "commsights";
				animationSourceGun = "commsights_gun";
				animationSourceHatch = "hatchCommander";
				soundServo[] = {"","db1",1};
				gunBeg = "";
				gunEnd = "";
				minElev = -15;
				maxElev = 20;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				commanding = 2;
				outGunnerMayFire = 0;
				inGunnerMayFire = 1;
				gunnerForceOptics = 0;
				viewGunnerInExternal = 0;
				gunnerOpticsModel = "\ca\Tracked\optika_M1A1_commander";
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
				gunnerOutOpticsColor[] = {0,0,0,1};
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 0;
				memoryPointGunnerOutOptics = "";
				memoryPointGunnerOptics = "commanderview";
				memoryPointsGetInGunner = "pos_commander";
				memoryPointsGetInGunnerDir = "pos_commander_dir";
				memoryPointGun = "gun_muzzle";
				selectionFireAnim = "zasleh_1";
				startEngine = 0;
				class ViewGunner: ViewGunner
				{
					initFov = "0.3333+ 0.41667";
					minFov = 0.3333;
					maxFov = "0.3333+ 0.41667";
				};
				class ViewOptics: ViewOptics
				{
					initFov = "0.3333/ 3";
					minFov = "0.3333/ 3";
					maxFov = "0.3333/ 3";
				};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\weapons\data\m2.rvmat","ca\weapons\data\m2_damage.rvmat","ca\weapons\data\m2_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body1_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_icv_body2_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_damage.rvmat","x\acex\addons\c_veh_stryker\stryker_alfa_destruct.rvmat","x\acex\addons\c_veh_stryker\stryker_mgs_turret.rvmat","x\acex\addons\c_veh_stryker\stryker_mgs_turret.rvmat","x\acex\addons\c_veh_stryker\stryker_mgs_turret_destruct.rvmat"};
		};
		hiddenSelections[] = {"SELECTION_SLAT"};
		smokeLauncherGrenadeCount = 4;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 1;
		smokeLauncherAngle = 90;
		ace_tankfcs_enabled = 1;
		ace_tankfcs_maxlrfrange = 7990;
		ace_tankfcs_minlrfrange = 200;
		ace_tankfcs_lrfaccuracy = 10;
		ace_tankfcs_lrfcooldowntime = 3;
		ace_tankfcs_maxlead = 0;
		ace_tankfcs_battlesight = 1200;
		ace_tankfcs_digitscolor[] = {0.396,0.886,0.396,1};
		ace_tankfcs_digitsstyle = 0;
		ace_tankfcs_rdystyle = 1;
		ace_tankfcs_maxranges[] = {"ACE_9Rnd_M456A2",4000,"ACE_9Rnd_M900",4000,"ACE_1000Rnd_762x51_M240",1800,"1200Rnd_762x51_M240",1800};
		ace_tankfcs_opticsoffsetH = -0.64;
	};
	class ACE_Stryker_MGS_Slat: ACE_Stryker_MGS
	{
		displayName = "M1128 Stryker MGS (SLAT)";
		armor = 200;
		armorStructural = 3.5;
		picture = "\x\acex\addons\c_veh_stryker\data\picture\m1128_slat_CA.paa";
		hiddenSelections[] = {};
		ace_era = 1;
		ace_era_hull[] = {{20,600},{20,600},{20,600},{20,600},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.9,0.9,0.9,0};
		ace_era_blocks_hull[] = {3,8,8,3,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
	class ACE_Stryker_RV: ACE_Stryker_TOW
	{
		displayName = "M1127 Stryker RV";
		model = "\x\acex\addons\m_veh_stryker\M1127_M2";
		transportSoldier = 5;
		enablemanualfire = 0;
		class AnimationSources
		{
			class M2_ammo_belt_rotation
			{
				source = "reload";
				weapon = "M2";
			};
			class M2_recoil
			{
				source = "reload";
				weapon = "M2";
			};
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitLF2Wheel: HitLFWheel
			{
				hitpoint = "HitLF2Wheel";
			};
			class HitRF2Wheel: HitLFWheel
			{
				hitpoint = "HitRF2Wheel";
			};
			class HitLMWheel: HitLFWheel
			{
				hitpoint = "HitLMWheel";
			};
			class HitRMWheel: HitLFWheel
			{
				hitpoint = "HitRMWheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
		};
		class Turrets: Turrets
		{
			class CommanderOptics: MainTurret
			{
				stabilizedInAxes = "StabilizedInAxesBoth";
				class HitTurret
				{
					armor = 0.4;
					material = -1;
					name = "vez";
					visual = "flak_mg_turret";
					passThrough = 0;
				};
				class HitGun
				{
					armor = 0.2;
					material = -1;
					name = "zbran";
					visual = "flak_mg";
					passThrough = 0;
				};
				weapons[] = {"Laserdesignator_mounted","SmokeLauncher"};
				magazines[] = {"Laserbatteries","SmokeLauncherMag","SmokeLauncherMag"};
				proxyType = "CPCommander";
				proxyIndex = 1;
				gunnerName = "$STR_POSITION_COMMANDER";
				primaryGunner = 1;
				primaryObserver = 1;
				body = "commsights";
				gun = "commsights_gun";
				gunnerAction = "BMP2_CommanderOUT";
				gunnerInAction = "Abrams_Commander";
				animationSourceBody = "commsights";
				animationSourceGun = "commsights_gun";
				animationSourceHatch = "hatchCommander";
				soundServo[] = {"","db1",1};
				gunBeg = "";
				gunEnd = "";
				minElev = -20;
				maxElev = 45;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				commanding = 2;
				outGunnerMayFire = 0;
				lockwhendriverout = 1;
				inGunnerMayFire = 1;
				gunnerForceOptics = 0;
				viewGunnerInExternal = 0;
				gunnerOpticsModel = "\ca\weapons\optika_SOFLAM";
				gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
				gunnerOutOpticsColor[] = {0,0,0,1};
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerFireAlsoInInternalCamera = 0;
				memoryPointGunnerOutOptics = "";
				memoryPointGunnerOptics = "commanderview";
				memoryPointsGetInGunner = "pos_commander";
				memoryPointsGetInGunnerDir = "pos_commander_dir";
				memoryPointGun = "gun_muzzle";
				selectionFireAnim = "";
				startEngine = 0;
				class ViewGunner: ViewGunner
				{
					initFov = "0.3333+ 0.41667";
					minFov = 0.3333;
					maxFov = "0.3333+ 0.41667";
				};
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "0.3333/ 1";
						minFov = "0.3333/ 1";
						maxFov = "0.3333/ 1";
						gunnerOpticsModel = "\ca\weapons\optika_SOFLAM";
						gunnerOpticsEffect[] = {};
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
					};
					class Medium: Wide
					{
						initFov = "0.3333/ 3";
						minFov = "0.3333/ 3";
						maxFov = "0.3333/ 3";
					};
					class Narrow: Wide
					{
						initFov = "0.3333/ 8";
						minFov = "0.3333/ 8";
						maxFov = "0.3333/ 8";
					};
					class ACE_RV_VNarrow: Wide
					{
						initFov = "0.3333/ 16";
						minFov = "0.3333/ 16";
						maxFov = "0.3333/ 16";
					};
					class ACE_RV_VVNarrow: Wide
					{
						initFov = "0.3333/ 32";
						minFov = "0.3333/ 32";
						maxFov = "0.3333/ 32";
					};
				};
			};
			class MainTurret: MainTurret
			{
				outGunnerMayFire = 1;
				inGunnerMayFire = 0;
				gunnerInAction = "Stryker_Gunner";
				gunnerAction = "Abrams_CommanderOut";
				memoryPointGunnerOutOptics = "gunner_weapon_view";
				gunnerOpticsModel = "CA\Tracked_E\driverOptics";
				gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
				soundServo[] = {"","db1",1};
				minElev = -20;
				maxElev = 45;
				minTurn = -126;
				maxTurn = 75;
				primarygunner = 0;
				stabilizedinaxes = 0;
				class ViewOptics: ViewOptics
				{
					initFov = 0.3333;
					minFov = "0.3333/ 2";
					maxFov = 0.3333;
					visionmode[] = {};
				};
				class ViewGunner: ViewGunner
				{
					initFov = "0.3333+ 0.41667";
					minFov = 0.3333;
					maxFov = "0.3333+ 0.41667";
				};
				weapons[] = {"M2"};
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
				ace_sa_enabled = 1;
				ace_sa_defaultelevation = 0;
				ace_sa_defaultwindage = 0;
			};
		};
		smokeLauncherGrenadeCount = 10;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 1;
		smokeLauncherAngle = 360;
		hiddenSelections[] = {"SELECTION_SLAT"};
		ace_tankfcs_enabled = 1;
		ace_tankfcs_maxlrfrange = 5000;
		ace_tankfcs_minlrfrange = 200;
		ace_tankfcs_lrfaccuracy = 10;
		ace_tankfcs_lrfcooldowntime = 3;
		ace_tankfcs_maxlead = 0;
		ace_tankfcs_battlesight = 500;
		ace_tankfcs_digitscolor[] = {0.7,0,0,1};
		ace_tankfcs_digitsstyle = 0;
		ace_tankfcs_rdystyle = 1;
		ace_tankfcs_maxranges[] = {};
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_defaultwindage = 0;
	};
	class ACE_Stryker_RV_SLAT: ACE_Stryker_RV
	{
		displayName = "M1127 Stryker RV (SLAT)";
		armor = 200;
		armorStructural = 3.5;
		hiddenSelections[] = {};
		ace_era = 1;
		ace_era_hull[] = {{20,600},{20,600},{20,600},{20,600},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.9,0.9,0.9,0};
		ace_era_blocks_hull[] = {3,8,8,3,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
	class ACE_Stryker_RV_D: ACE_Stryker_RV
	{
		vehicleClass = "ArmouredD";
		hiddenSelections[] = {"SELECTION_SLAT","camo2","camo3","camo7","camo9"};
		HiddenSelectionsTextures[] = {"","ca\wheeled_e\stryker\data\stryker_body2_des_co.paa","ca\wheeled_e\stryker\data\stryker_mgs_body1_des_co.paa","ca\wheeled_e\stryker\data\icv_des_co.paa","ca\wheeled_e\stryker\data\stryker_alfa_des_ca.paa"};
	};
	class ACE_Stryker_RV_SLAT_D: ACE_Stryker_RV_SLAT
	{
		vehicleClass = "ArmouredD";
		hiddenSelections[] = {"SELECTION_SLAT","camo2","camo3","camo7","camo9"};
		HiddenSelectionsTextures[] = {"ca\wheeled_e\stryker\data\slat_armor_des_ca.paa","ca\wheeled_e\stryker\data\stryker_body2_des_co.paa","ca\wheeled_e\stryker\data\stryker_mgs_body1_des_co.paa","ca\wheeled_e\stryker\data\icv_des_co.paa","ca\wheeled_e\stryker\data\stryker_alfa_des_ca.paa"};
	};
};
class CfgGroups
{
	class West
	{
		class BIS_US
		{
			class Mechanized
			{
				class US_MechanizedInfantrySquadICVM2
				{
					class Unit1
					{
						vehicle = "ACE_Stryker_ICV_M2_SLAT";
					};
				};
				class US_MechanizedInfantrySquadICVMK19
				{
					class Unit1
					{
						vehicle = "ACE_Stryker_ICV_MK19_SLAT";
					};
				};
				class ACE_Stryker_Recon_Section
				{
					name = "$STR_ACE_GDN_ACE_STRYKER_RECON_SECTION";
					faction = "BIS_US";
					rarityGroup = 0.6;
					class Unit0
					{
						side = 1;
						vehicle = "US_Soldier_TL_EP1";
						rank = "LIEUTENANT";
						position[] = {3,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_Stryker_RV";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "US_Soldier_AR_EP1";
						rank = "SERGEANT";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "US_Soldier_GL_EP1";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 1;
						vehicle = "US_Soldier_Marksman_EP1";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 1;
						vehicle = "US_Soldier_LAT_EP1";
						rank = "CORPORAL";
						position[] = {9,0,0};
					};
				};
			};
			class Armored
			{
				class US_MGSPlatoon
				{
					class Unit0
					{
						vehicle = "ACE_Stryker_MGS";
					};
					class Unit1
					{
						vehicle = "ACE_Stryker_MGS";
					};
					class Unit2
					{
						vehicle = "ACE_Stryker_MGS";
					};
				};
				class ACE_US_Stryker_TOW_Platoon
				{
					name = "$STR_ACE_GDN_ACE_US_STRYKER_TOW_PLATOON";
					faction = "BIS_US";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_Stryker_TOW_Slat";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_Stryker_TOW_Slat";
						rank = "LIEUTENANT";
						position[] = {5,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_Stryker_TOW_Slat";
						rank = "LIEUTENANT";
						position[] = {10,0,0};
					};
				};
			};
		};
	};
};
class Extended_FiredBis_EventHandlers
{
	class ACE_Stryker_MGS
	{
		class acex_veh_stryker_tracer
		{
			clientFiredBis = "if ((_this select 4) isKindOf 'ShellBase') then { _this call ace_sys_vehicle_fnc_tracer }";
		};
	};
};
//};
