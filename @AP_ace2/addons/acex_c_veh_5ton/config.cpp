////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:35:17 2011 : Created on Fri Oct 21 13:35:17 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_5ton : config.bin{
class CfgPatches
{
	class acex_veh_5ton
	{
		units[] = {"Truck5tMG","Truck5tMGOpen","Truck5t","Truck5tOpen","Truck5tRepair","Truck5tReammo","Truck5tRefuel","ACE_Truck5tMG_Base","ACE_Truck5tMG","ACE_Truck5tMGOpen_Base","ACE_Truck5tMGOpen","ACE_Truck5t_Base","ACE_Truck5t","ACE_Truck5tOpen_Base","ACE_Truck5tOpen","ACE_Truck5tRepair_Base","ACE_Truck5tRepair","ACE_Truck5tReammo_Base","ACE_Truck5tReammo","ACE_Truck5tRefuel_Base","ACE_Truck5tRefuel"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_m_veh_5ton","acex_t_veh_5ton"};
		version = "1.12.0.347";
		author[] = {"Rocko"};
	};
};
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class HitPoints;
		class Turrets
		{
			class MainTurret;
		};
	};
	class Truck: Car
	{
		class HitPoints: HitPoints
		{
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitLGlass;
			class HitRGlass;
		};
	};
	class ACE_Truck5tMG_Base: Truck
	{
		htMin = 60;
		htMax = 1800;
		afMax = 200;
		mfMax = 100;
		mFact = 1;
		tBody = 250;
		scope = 1;
		model = "\x\acex\addons\m_veh_5ton\5t_guntruck_closed.p3d";
		picture = "\Ca\wheeled2\data\UI\Picture_MTVR_CA.paa";
		icon = "\x\acex\addons\c_veh_5ton\data\icon\icomap_5tt_mg_closed_ca.paa";
		mapSize = 8;
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_5TTRUCK_ARMED";
		vehicleClass = "CarW";
		class Library
		{
			libTextDesc = "$STR_LIB_5T_TRUCK";
		};
		side = 1;
		faction = "BIS_US";
		crew = "US_Soldier_EP1";
		fuelCapacity = 303;
		maxSpeed = 105;
		wheelCircumference = 4.172;
		cost = 70000;
		turnCoef = 5;
		steerAheadSimul = 0.2;
		steerAheadPlan = 0.3;
		predictTurnSimul = 0.9;
		predictTurnPlan = 1;
		brakeDistance = 3;
		armor = 32;
		damageResistance = 0.00243;
		enableGPS = 0;
		weapons[] = {"TruckHorn"};
		magazines[] = {};
		threat[] = {1,0.1,0.4};
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor = 0.3;
				name = "wheel_1_1_steering";
			};
			class HitLBWheel: HitLBWheel
			{
				armor = 0.3;
				name = "wheel_2_1_steering";
			};
			class HitLMWheel: HitLMWheel
			{
				armor = 0.3;
				name = "wheel_3_1_steering";
			};
			class HitRFWheel: HitRFWheel
			{
				armor = 0.3;
				name = "wheel_1_2_steering";
			};
			class HitRBWheel: HitRBWheel
			{
				armor = 0.3;
				name = "wheel_2_2_steering";
			};
			class HitRMWheel: HitRMWheel
			{
				armor = 0.3;
				name = "wheel_3_2_steering";
			};
			class HitFuel
			{
				armor = 1.4;
				material = -1;
				name = "palivo";
				visual = "";
				passThrough = 1;
			};
			class HitGlass1: HitGlass1
			{
				armor = 0.1;
				material = -1;
				name = "glass1";
				visual = "glass1";
				passThrough = 0;
			};
			class HitGlass2: HitGlass2
			{
				armor = 0.1;
				material = -1;
				name = "glass2";
				visual = "glass2";
				passThrough = 0;
			};
			class HitGlass3: HitGlass3
			{
				armor = 0.1;
				material = -1;
				name = "glass3";
				visual = "glass3";
				passThrough = 0;
			};
			class HitGlass4: HitGlass4
			{
				armor = 0.1;
				material = -1;
				name = "glass4";
				visual = "glass4";
				passThrough = 0;
			};
			class HitRGlass: HitRGlass
			{
				armor = 0.3;
				passThrough = 0;
			};
			class HitLGlass: HitLGlass
			{
				armor = 0.3;
				passThrough = 0;
			};
		};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		transportSoldier = 12;
		driverAction = "Truck_Driver";
		cargoAction[] = {"Truck_Cargo01","Truck_Cargo04","Truck_Cargo04","Truck_Cargo02","Truck_Cargo03","Truck_Cargo04","Truck_Cargo02","Truck_Cargo04","Truck_Cargo04","Truck_Cargo04","Truck_Cargo04","Truck_Cargo03"};
		typicalCargo[] = {"US_Soldier_EP1","US_Soldier_EP1","US_Soldier_LAT_EP1","US_Soldier_LAT_EP1"};
		initCargoAngleY = 185;
		getInAction = "GetInHigh";
		getOutAction = "GetOutHigh";
		cargoIsCoDriver[] = {1,1,0};
		viewCargoShadow = 1;
		SoundGear[] = {"",0.00177828,1};
		soundGetIn[] = {"ca\sounds\vehicles\Wheeled\MTVR\ext\ext-truck-getin",0.707946,1};
		soundGetOut[] = {"ca\sounds\vehicles\Wheeled\MTVR\ext\ext-truck-getout",0.562341,1,50};
		soundEngineOnInt[] = {"ca\sounds\Vehicles\Wheeled\MTVR\int\int-mtvr-start",0.562341,1};
		soundEngineOnExt[] = {"ca\SOUNDS\Vehicles\Wheeled\MTVR\ext\ext-mtvr-start1",0.562341,1,350};
		soundEngineOffInt[] = {"ca\sounds\vehicles\Wheeled\MTVR\int\int-mtvr-stop",0.562341,1};
		soundEngineOffExt[] = {"ca\sounds\vehicles\Wheeled\MTVR\ext\ext-truck-stop",0.562341,1,350};
		buildCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_building_01",0.707946,1,200};
		buildCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_building_02",0.707946,1,200};
		buildCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_building_03",0.707946,1,200};
		buildCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_building_04",0.707946,1,200};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_01",0.707946,1,200};
		WoodCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_02",0.707946,1,200};
		WoodCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_03",0.707946,1,200};
		WoodCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_04",0.707946,1,200};
		WoodCrash4[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_05",0.707946,1,200};
		WoodCrash5[] = {"Ca\sounds\Vehicles\Crash\crash_mix_wood_06",0.707946,1,200};
		soundWoodCrash[] = {"woodCrash0",0.166,"woodCrash1",0.166,"woodCrash2",0.166,"woodCrash3",0.166,"woodCrash4",0.166,"woodCrash5",0.166};
		ArmorCrash0[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_01",0.707946,1,200};
		ArmorCrash1[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_02",0.707946,1,200};
		ArmorCrash2[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_03",0.707946,1,200};
		ArmorCrash3[] = {"Ca\sounds\Vehicles\Crash\crash_vehicle_04",0.707946,1,200};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};
		class SoundEvents
		{
			class AccelerationIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\MTVR\int\int-mtvr-acceleration1",0.398107,1};
				limit = "0.15";
				expression = "engineOn*(1-camPos)*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
			class AccelerationOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\MTVR\ext\ext-mtvr-acceleration1",0.562341,1,390};
				limit = "0.15";
				expression = "engineOn*camPos*2*gmeterZ*((speed factor[1.5, 5]) min (speed factor[5, 1.5]))";
			};
		};
		class Sounds
		{
			class Engine
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\MTVR\ext\ext-truck-low2",1,1,450};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*camPos*(thrust factor[0.7, 0.2])";
			};
			class EngineHighOut
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\MTVR\ext\ext-truck-high",1,0.9,550};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "engineOn*camPos*(thrust factor[0.5, 0.95])";
			};
			class IdleOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\MTVR\ext\ext-mtvr-idle",0.562341,1,350};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.4, 0])";
			};
			class TiresRockOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-rock2",0.1,1,50};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-sand2",0.1,1,50};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-grass3",0.1,1,50};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-mud2",0.1,1,50};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-gravel2",0.1,1,50};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\ext\ext-tires-asphalt3",0.1,1,50};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\ext\noise2",0.1,1,50};
				frequency = "1";
				volume = "camPos*(damper0 max 0.04)*(speed factor[0, 8])";
			};
			class EngineLowIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\MTVR\int\int-mtvr-low2",1,1};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "((engineOn*thrust) factor[0.65, 0.2])*(1-camPos)";
			};
			class EngineHighIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\MTVR\int\int-mtvr-high2",1,0.9};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "((engineOn*thrust) factor[0.4, 1.0])*(1-camPos)";
			};
			class IdleIn
			{
				sound[] = {"\ca\sounds\Vehicles\Wheeled\MTVR\int\int-mtvr-idle1",0.398107,1};
				frequency = "1";
				volume = "engineOn*(rpm factor[0.3, 0])*(1-camPos)";
			};
			class TiresRockIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-rock2",0.177828,1};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-sand2",0.177828,1};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-grass3",0.177828,1};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-mud2",0.177828,1};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-gravel2",0.177828,1};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Tires\int\int-tires-asphalt3",0.177828,1};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"\ca\SOUNDS\Vehicles\Wheeled\Noises\int\noise2",0.177828,1};
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
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ACE_Exposed = "true";
				body = "mainTurret";
				gun = "mainGun";
				hasGunner = 1;
				weapons[] = {"M2"};
				minElev = -25;
				maxElev = "+60";
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
				soundServo[] = {"\ca\wheeled\Data\Sound\servo3","db-75",0.9};
				gunnerAction = "Truck_Gunner";
				gunnerInAction = "Truck_Gunner";
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333+ 0.41667";
					minFov = "0.33333/ 1";
					maxFov = "0.33333+ 0.41667";
				};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = "0.33333+ 0.41667";
					minFov = "0.33333/ 1";
					maxFov = "0.33333+ 0.41667";
				};
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				gunnerForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 0;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				memoryPointGunnerOptics = "gunner_view";
			};
		};
		class Reflectors
		{
			class Left
			{
				color[] = {0.9,0.8,0.8,1};
				ambient[] = {0.1,0.1,0.1,1};
				position = "L svetlo";
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 0.5;
				brightness = 0.5;
			};
			class Right
			{
				color[] = {0.9,0.8,0.8,1};
				ambient[] = {0.1,0.1,0.1,1};
				position = "P svetlo";
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 0.5;
				brightness = 0.5;
			};
		};
		memoryPointExhaust = "vyfuk start";
		memoryPointExhaustDir = "vyfuk konec";
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\data\auta_skla.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_in.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","x\acex\addons\c_veh_5ton\truck5t_01.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash_destruct.rvmat"};
		};
		class AnimationSources
		{
			class reloadMagazine_m2
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class belt_rotation
			{
				source = "reload";
				weapon = "M2";
			};
			class revolving_m2
			{
				source = "revolving";
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
		ace_sys_eject_side = 0;
	};
	class ACE_Truck5tMG: ACE_Truck5tMG_Base
	{
		scope = 2;
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_5TTRUCK_MG";
	};
	class ACE_Truck5tMGOpen_Base: ACE_Truck5tMG_Base
	{
		model = "\x\acex\addons\m_veh_5ton\5t_guntruck_closed.p3d";
		icon = "\x\acex\addons\c_veh_5ton\data\icon\icomap_5tt_mg_ca.paa";
		displayName = "$STR_ACE_VDN_5TTRUCK_ARMED_OPEN";
		hiddenSelections[] = {"__COVER"};
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\data\auta_skla.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_in.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","x\acex\addons\c_veh_5ton\truck5t_01.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash_destruct.rvmat"};
		};
		ace_sys_eject_side = 1;
	};
	class ACE_Truck5tMGOpen: ACE_Truck5tMGOpen_Base
	{
		scope = 2;
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_5TTRUCK_MG_OPEN";
	};
	class ACE_Truck5t_Base: ACE_Truck5tMG_Base
	{
		model = "\x\acex\addons\m_veh_5ton\5t_closed.p3d";
		icon = "\x\acex\addons\c_veh_5ton\data\icon\icomap_5tt_ca.paa";
		displayName = "$STR_ACE_VDN_5TTRUCK";
		transportSoldier = 13;
		class Turrets{};
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\data\auta_skla.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_in.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","x\acex\addons\c_veh_5ton\truck5t_01.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash_destruct.rvmat"};
		};
	};
	class ACE_Truck5t: ACE_Truck5t_Base
	{
		scope = 2;
	};
	class ACE_Truck5tOpen_Base: ACE_Truck5t_Base
	{
		model = "\x\acex\addons\m_veh_5ton\5t_closed.p3d";
		icon = "\x\acex\addons\c_veh_5ton\data\icon\icomap_5tt_open_ca.paa";
		displayName = "$STR_ACE_VDN_5TTRUCK_OPEN";
		hiddenSelections[] = {"__COVER"};
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\data\auta_skla.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_in.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","x\acex\addons\c_veh_5ton\truck5t_01.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash_destruct.rvmat"};
		};
	};
	class ACE_Truck5tOpen: ACE_Truck5tOpen_Base
	{
		scope = 2;
	};
	class ACE_Truck5tRepair_Base: ACE_Truck5t_Base
	{
		model = "\x\acex\addons\m_veh_5ton\5t_service.p3d";
		hiddenSelections[] = {"__REAMMO","__REFUEL"};
		displayName = "$STR_ACE_VDN_5TTRUCK_REPAIR";
		vehicleClass = "Support";
		icon = "\x\acex\addons\c_veh_5ton\data\icon\icomap_5tt_rep_ca.paa";
		transportSoldier = 2;
		cargoAction[] = {"Truck_Cargo01"};
		transportRepair = 2e+008;
		supplyRadius = 7.5;
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\data\auta_skla.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_in.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","x\acex\addons\c_veh_5ton\truck5t_01.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash_destruct.rvmat"};
		};
	};
	class ACE_Truck5tRepair: ACE_Truck5tRepair_Base
	{
		scope = 2;
	};
	class ACE_Truck5tReammo_Base: ACE_Truck5tRepair_Base
	{
		hiddenSelections[] = {"__REFUEL"};
		displayName = "$STR_ACE_VDN_5TTRUCK_AMMO";
		icon = "\x\acex\addons\c_veh_5ton\data\icon\icomap_5tt_rea_ca.paa";
		transportAmmo = 300000;
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\data\auta_skla.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_in.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","x\acex\addons\c_veh_5ton\truck5t_01.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash_destruct.rvmat"};
		};
	};
	class ACE_Truck5tReammo: ACE_Truck5tReammo_Base
	{
		scope = 2;
	};
	class ACE_Truck5tRefuel_Base: ACE_Truck5tRepair_Base
	{
		hiddenSelections[] = {"__REPAIR","__REAMMO"};
		displayName = "$STR_ACE_VDN_5TTRUCK_FUEL";
		icon = "\x\acex\addons\c_veh_5ton\data\icon\icomap_5tt_ref_ca.paa";
		transportFuel = 3000;
		transportAmmo = 0;
		supplyRadius = 6.3;
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\wheeled_e\data\auta_skla.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_damage.rvmat","ca\wheeled_e\data\auta_skla_in.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\wheeled_e\data\auta_skla_in_damage.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount.rvmat","ca\tracked_e\m1_abrams\data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","ca\weapons_e\m2\data\m2.rvmat","x\acex\addons\c_veh_5ton\truck5t_01.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_01_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti.rvmat","x\acex\addons\c_veh_5ton\truck5t_02noti_damage.rvmat","x\acex\addons\c_veh_5ton\truck5t_02_destruct.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash.rvmat","x\acex\addons\c_veh_5ton\truck5t_dash_destruct.rvmat"};
		};
	};
	class ACE_Truck5tRefuel: ACE_Truck5tRefuel_Base
	{
		scope = 2;
	};
};
//};
