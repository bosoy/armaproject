////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:40 2012 : Created on Fri Nov 09 22:39:40 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_bmd1 : config.bin{
class CfgPatches
{
	class acex_ru_veh_bmd1
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAData","CACharacters","CACharacters2","CAWeapons","CASounds","Extended_EventHandlers","acex_ru_main","acex_ru_t_veh_bmd1","acex_ru_m_veh_bmd2","acex_ru_m_veh_bmd1","acex_ru_s_veh_bmd1"};
		version = "1.14.0.76";
		author[] = {"Soul Assassin (RHS)"};
	};
};
class Extended_PreInit_EventHandlers
{
	class acex_ru_veh_bmd1
	{
		init = "call ('\x\acex_ru\addons\c_veh_bmd1\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class ACE_BMD_1_Base
	{
		ACE_BMD_1_Base_Init = "_this call acex_ru_veh_bmd1_fnc_bmd_init";
	};
};
class CfgAmmo
{
	class M_AT5_AT;
	class ACE_M_AT3C_AT: M_AT5_AT
	{
		model = "x\acex_ru\addons\m_veh_bmd1\At3";
		proxyShape = "x\acex_ru\addons\m_veh_bmd1\At3_proxy";
	};
};
class CfgWeapons
{
	class CannonCore;
	class ACE_2A28_Base: CannonCore
	{
		sound[] = {"\x\acex_ru\addons\s_veh_bmd1\sa_bmd_cannon_73.wss",316.228,1};
	};
};
class CfgVehicles
{
	class All;
	class AllVehicles: All
	{
		class NewTurret;
	};
	class Land: AllVehicles{};
	class LandVehicle: Land{};
	class Tank: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets;
			};
		};
	};
	class Tracked_APC: Tank{};
	class BMP2_Base: Tracked_APC
	{
		class Sounds
		{
			class Engine;
			class Movement;
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class HitPoints;
		class ViewOptics;
		class AnimationSources;
	};
	class ACE_BMD_1_Base: BMP2_Base
	{
		scope = 1;
		model = "x\acex_ru\addons\m_veh_bmd1\sa_bmd_1.p3d";
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_BMD_1_BASE";
		side = 0;
		faction = "RU";
		icon = "\x\acex_ru\addons\c_veh_bmd1\data\icon\sa_bmd1_icon.paa";
		mapSize = 5.4;
		picture = "\x\acex_ru\addons\c_veh_bmd1\data\picture\bmd1_pic.paa";
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_1","RU_Soldier_1","RU_Soldier_1","RU_Soldier_1","RU_Soldier_1"};
		hasCommander = 0;
		hasGunner = 1;
		transportSoldier = 5;
		ejectDeadCargo = 1;
		unloadInCombat = 1;
		forceHideDriver = 1;
		armorStructural = 3;
		secondaryExplosion = 1;
		smokeLauncherGrenadeCount = 0;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 0;
		smokeLauncherAngle = 70;
		selectionLeftOffset = "pasanimL";
		selectionRightOffset = "pasanimP";
		hiddenSelections[] = {"n1","n2","n3","i1","i2","i3","Camo1","Camo2","Camo3","Camo4","Wheel1","Wheel2","Wheel3"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\num\reg.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_01_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_02_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_03_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_04_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_drivewheel_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel2_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel_co.paa"};
		maxSpeed = 70;
		damperSize = 0.3;
		damperForce = 0.8;
		damperDamping = 0.5;
		brakeDistance = 5;
		armor = 110;
		threat[] = {0.9,0.7,0.3};
		cost = 3000000;
		camouflage = 5;
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
		class Sounds: Sounds
		{
			class Engine: Engine
			{
				sound[] = {"\x\acex_ru\addons\s_veh_bmd1\sa_bmd_engine.wss",1.0,1.0,1000};
			};
		};
		driverAction = "Abrams_Driverout";
		driverInAction = "Abrams_Driver";
		cargoAction[] = {"SA_BMD1_Cargo01","SA_BMD1_Cargo02","SA_BMD1_Cargo03","SA_BMD1_Cargo04","SA_BMD1_Cargo05"};
		getInAction = "GetInMedium";
		getOutAction = "GetOutMedium";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		driverOpticsModel = "x\acex_ru\addons\m_veh_bmd2\sights\o915_TNPO170A_sight";
		driverOpticsColor[] = {1,1,1,1};
		animationSourceHatch = "HatchDriver";
		driverForceOptics = 1;
		class AnimationSources
		{
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
			class wave
			{
				source = "user";
				animPeriod = 6;
				initPhase = 0;
			};
			class Antena1
			{
				source = "user";
				animPeriod = 6;
				initPhase = 0;
			};
			class AT3_Reload
			{
				source = "reload";
				weapon = "ACE_AT3_Launcher";
			};
			class AT3_Revolving
			{
				source = "revolving";
				weapon = "ACE_AT3_Launcher";
			};
		};
		class UserActions
		{
			class LowerSusp
			{
				displayName = "$STR_ACE_UA_BMD_LowerSusp";
				position = "";
				radius = 5;
				condition = "(player == driver this) && {(0 == speed this)} && {!(surfaceIsWater getPos this)} && {(this animationPhase 'suspensionv1' < 0.5)}";
				statement = "this animate['suspensionv1',1];this animate['suspensionv2',1];this animate['suspL1',1];this animate['suspL2',1];this animate['suspL3',1];this animate['suspL4',1];this animate['suspL5',1];";
				onlyForPlayer = 1;
			};
			class RaiseSusp
			{
				displayName = "$STR_ACE_UA_BMD_RaiseSusp";
				position = "";
				radius = 5;
				condition = "(player == driver this) && {(0 == speed this)} && {!(surfaceIsWater getPos this)} && {(this animationPhase 'suspensionv1' > 0.5)}";
				statement = "this animate['suspensionv1',0];this animate['suspensionv2',0];this animate['suspL1',0];this animate['suspL2',0];this animate['suspL3',0];this animate['suspL4',0];this animate['suspL5',0];";
				onlyForPlayer = 1;
			};
			class UpCutwaters
			{
				displayName = "$STR_ACE_UA_BMD_UpCutWet";
				position = "";
				radius = 5;
				condition = "(player == driver this) && {(surfaceIsWater getPos this)} && {(this animationPhase 'wave_l' == 0)}";
				statement = "this animate['wave_l',1]; this animate['wave_r',1]; this animate['wave_c',1];";
				onlyForPlayer = 1;
			};
			class DownCutwaters
			{
				displayName = "$STR_ACE_UA_BMD_DownCutWet";
				position = "";
				radius = 5;
				condition = "(player == driver this) && {(this animationPhase 'wave_l' == 1)}";
				statement = "this animate['wave_l',0]; this animate['wave_r',0]; this animate['wave_c',0];";
				onlyForPlayer = 1;
			};
		};
		class Library
		{
			libTextDesc = "$STR_ACE_LIB_BMD";
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_bmd1\sa_bmd1_01.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_01_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_01_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_destruct.rvmat"};
		};
		cargoCompartments[] = {2,2,2,2,2};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_reticles_gunneroptics = 0;
				gunnerCompartments = 1;
				stabilizedInAxes = 0;
				proxyIndex = 1;
				gunnerAction = "MDL_BMD1_Gunner";
				animationSourceHatch = "HatchGunner";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				body = "otocvez";
				gun = "otochlaven";
				memoryPointGunnerOptics = "gunnerview";
				weapons[] = {"ACE_2A28","PKT_veh","ACE_AT3_Launcher","ACE_SACLOS_Guidance"};
				magazines[] = {"ACE_24Rnd_73mm_PG15V","ACE_16Rnd_73mm_OG15V","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","ACE_AT3C"};
				GunnerForceOptics = 1;
				gunnerOpticsModel = "x\acex_ru\addons\m_veh_bmd2\sights\sa_1PN22M1_sight";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOutOpticsModel = "\ca\weapons\optika_empty";
				gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera3"};
				minElev = -4;
				maxElev = 33;
				lockWhenDriverOut = 1;
				commanding = 1;
				startengine = 0;
				class Turrets{};
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
				};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 70;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 1;
					minFov = 0.33333;
					maxFov = 1;
				};
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 5;
						minAngleX = -30;
						maxAngleX = 70;
						initAngleY = 0;
						minAngleY = -150;
						maxAngleY = 150;
						gunnerOpticsModel = "\ca\weapons\2Dscope_BMPgun";
						gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera3"};
						gunnerOpticsColor[] = {1,1,1,1};
						gunnerOutOpticsModel = "\ca\weapons\optika_empty";
						initFov = "0.33333/ 5";
						minFov = "0.33333/ 5";
						maxFov = "0.33333/ 5";
						visionMode[] = {"Normal","NVG"};
					};
				};
				soundServo[] = {"\x\acex_ru\addons\s_veh_bmd1\turret_bmp.wss",0.316228,1,15};
			};
			class GPMGTurret1: NewTurret
			{
				body = "obsTurret";
				gun = "obsGun";
				animationSourceBody = "obsTurret";
				animationSourceGun = "obsGun";
				animationSourceHatch = "";
				selectionFireAnim = "zasleh1";
				proxyIndex = 2;
				gunnerName = "$STR_ACE_BMD_MGFrontLeft";
				hasGunner = 1;
				soundServo[] = {};
				forceHideGunner = 1;
				primaryObserver = 0;
				commanding = -2;
				minElev = -10;
				maxElev = 10;
				minTurn = -10;
				maxTurn = 10;
				weapons[] = {"ACE_PKT_out"};
				magazines[] = {"250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				gunnerOpticsModel = "x\acex_ru\addons\m_veh_bmd2\sights\o915_TNPP220A_sight";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerForceOptics = 1;
				gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera3"};
				class Turrets{};
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
				};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 70;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 1;
					minFov = 0.33333;
					maxFov = 1;
				};
				gunBeg = "muzzle";
				gunEnd = "end";
				memoryPointGun = "memoryPointGun";
				memoryPointGunnerOptics = "gunnerview2";
				gunnerAction = "BMP2_Gunner";
				startEngine = 0;
			};
			class GPMGTurret2: GPMGTurret1
			{
				body = "obsTurret2";
				gun = "obsGun2";
				animationSourceBody = "Turret_2";
				animationSourceGun = "Gun_2";
				animationSourceHatch = "";
				selectionFireAnim = "zasleh2";
				proxyIndex = 3;
				gunnerName = "$STR_ACE_BMD_MGFrontRight";
				hasGunner = 1;
				soundServo[] = {};
				commanding = -2;
				primaryObserver = 0;
				minElev = -20;
				maxElev = 10;
				minTurn = -20;
				maxTurn = 20;
				gunBeg = "muzzle2";
				gunEnd = "end2";
				memoryPointGun = "memoryPointGun2";
				memoryPointGunnerOptics = "gunnerview3";
				gunnerAction = "BMP2_Gunner";
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
				proxyIndex = 4;
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "$STR_ACE_BMD_CargoBackLeft";
				commanding = -1;
				gunnerOpticsModel = "x\acex_ru\addons\m_veh_bmd2\sights\o915_TNPO170A_sight";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerForceOptics = 1;
				gunBeg = "";
				gunEnd = "";
				memoryPointGun = "";
				memoryPointGunnerOptics = "lseat_view";
				gunnerAction = "";
				gunnerInAction = "BMP2_Gunner";
				weapons[] = {};
				magazines[] = {};
				forceHideGunner = 1;
				hasGunner = 0;
				primaryGunner = 0;
				primaryObserver = 0;
				startEngine = 0;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.33333;
					minFov = 0.33333;
					maxFov = 0.33333;
				};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 70;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 1;
					minFov = 0.33333;
					maxFov = 1;
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
				proxyIndex = 5;
				gunnerName = "$STR_ACE_BMD_CargoBackRight";
				memoryPointGunnerOptics = "rseat_view";
			};
			class MainBack: LeftBack
			{
				body = "bseat_turret";
				gun = "bseat_gun";
				animationSourceBody = "bseat_Turret";
				animationSourceGun = "bseat_Gun";
				initTurn = 170;
				minTurn = 150;
				maxTurn = 190;
				proxyIndex = 6;
				gunnerName = "$STR_ACE_BMD_CargoBackCenter";
				memoryPointGunnerOptics = "bseat_view";
			};
		};
		ace_minimalhit[] = {18,40};
		ace_era = 0;
		ace_p_detonation_hull = 0.8;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.8;
		ace_p_fire_turret = 0.5;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{15,15},{10,10},{10,10},{10,10},{10,10},{10,10}};
		ace_armor_turret[] = {{23,23},{19,19},{19,19},{13,13},{6,6}};
		class CargoLight
		{
			ambient[] = {0.6,0,0.15,1};
			brightness = 0.007;
			color[] = {0,0,0,0};
		};
	};
	class ACE_BMD_1_RU: ACE_BMD_1_Base
	{
		scope = 2;
		side = 0;
		faction = "ACE_VDV";
		accuracy = 0.5;
		model = "\x\acex_ru\addons\m_veh_bmd1\sa_bmd_1.p3d";
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_1","RU_Soldier_1","RU_Soldier_1","RU_Soldier_1","RU_Soldier_1"};
		hiddenSelections[] = {"n1","n2","n3","n4","n5","i1","Camo1","Camo2","Camo3","Camo4","Wheel1","Wheel2","Wheel3"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\num\reg.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_01_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_02_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_03_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_04_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_drivewheel_RUS_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel2_RUS_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel_rus_co.paa"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_2A28","PKT_veh","ACE_AT3_Launcher","ACE_SACLOS_Guidance"};
				magazines[] = {"ACE_24Rnd_73mm_PG15V","ACE_16Rnd_73mm_OG15V","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","ACE_AT3P"};
			};
			class GPMGTurret1: GPMGTurret1{};
			class GPMGTurret2: GPMGTurret2{};
			class LeftBack: LeftBack{};
			class RightBack: RightBack{};
			class MainBack: MainBack{};
		};
	};
	class ACE_BMD_1_CDF: ACE_BMD_1_Base
	{
		scope = 2;
		side = 1;
		accuracy = 0.5;
		faction = "CDF";
		model = "\x\acex_ru\addons\m_veh_bmd1\sa_bmd_1.p3d";
		crew = "CDF_Soldier_Crew";
		typicalCargo[] = {"CDF_Soldier_Crew","CDF_Soldier_Crew","CDF_Soldier_1","CDF_Soldier_1","CDF_Soldier_1","CDF_Soldier_1","CDF_Soldier_1"};
		hiddenSelections[] = {"n1","n2","n3","n4","n5","i1","Camo1","Camo2","Camo3","Camo4","Wheel1","Wheel2","Wheel3"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\num\reg.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_01_CDF_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_02_CDF_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_03_CDF_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_04_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_drivewheel_cdf_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel2_cdf_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel_rus_co.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_bmd1\sa_bmd1_01.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_01_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_01_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_destruct.rvmat"};
		};
	};
	class ACE_BMD_1P_Base: ACE_BMD_1_Base
	{
		displayName = "$STR_ACE_VDN_BMD_1P_BASE";
		accuracy = 0.45;
		model = "\x\acex_ru\addons\m_veh_bmd1\sa_bmd_1p.p3d";
		icon = "\x\acex_ru\addons\c_veh_bmd1\data\icon\sa_bmd1p_icon.paa";
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_destruct.rvmat"};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				commanding = 2;
				gunnerAction = "MDL_BMD1P_Gunner";
				gunnerCompartments = 1;
				soundServo[] = {"\ca\Weapons\Data\Sound\gun_elevate",0.00316228,1.1};
				weapons[] = {"ACE_2A28","PKT_veh"};
				magazines[] = {"ACE_24Rnd_73mm_PG15V","ACE_16Rnd_73mm_OG15V","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				memoryPointMissile[] = {"Konec rakety"};
				memoryPointMissileDir[] = {"Spice rakety"};
				class Turrets
				{
					class CommanderOptics: NewTurret
					{
						gunnerCompartments = 1;
						proxyType = "CPGunner";
						proxyIndex = 1;
						gunnerAction = "MDL_BMD1P_ATGunner";
						gunnerInAction = "BMP2_Gunner";
						gunnerGetInAction = "GetInMedium";
						gunnerGetOutAction = "GetOutMedium";
						hasGunner = 0;
						gunnerName = "$STR_ACE_BMD_AT5Gunner";
						primaryGunner = 0;
						primaryObserver = 0;
						body = "at5_turret";
						gun = "at5_gun";
						animationSourceBody = "at5_turret_source";
						animationSourceGun = "at5_gun_source";
						animationSourceHatch = "hatchGunnerAT5";
						lockWhenDriverOut = 0;
						soundServo[] = {"",0.003162,1.0};
						gunBeg = "gunEnd";
						gunEnd = "gunBeg";
						minElev = -20;
						maxElev = 20;
						initElev = 0;
						minTurn = -5;
						maxTurn = 5;
						initTurn = 0;
						commanding = 2;
						outGunnerMayFire = 1;
						inGunnerMayFire = 0;
						viewGunnerInExternal = 0;
						startengine = 0;
						gunnerOpticsModel = "";
						gunnerOutOpticsModel = "x\acex_ru\addons\m_veh_bmd2\sights\sa_9M135M1_sight";
						gunnerOutOpticsColor[] = {0,0,0,1};
						weapons[] = {"AT5LauncherSingle"};
						magazines[] = {"ACE_AT5B"};
						gunnerOutForceOptics = 0;
						gunnerOutOpticsShowCursor = 0;
						memoryPointGunnerOutOptics = "at5_gunnerview";
						memoryPointGunnerOptics = "at5_gunnerview";
						memoryPointsGetInGunner = "pos at5 gunner";
						memoryPointsGetInGunnerDir = "pos at5 gunner dir";
						maxVerticalRotSpeed = 0.2;
						maxHorizontalRotSpeed = 0.2;
						class ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333/ 6";
							minFov = "0.33333/ 6";
							maxFov = "0.33333/ 6";
						};
						class ViewGunner
						{
							initAngleX = 5;
							minAngleX = -30;
							maxAngleX = 70;
							initAngleY = 0;
							minAngleY = -150;
							maxAngleY = 150;
							initFov = 1;
							minFov = 0.33333;
							maxFov = 1;
						};
					};
				};
			};
			class GPMGTurret1: GPMGTurret1
			{
				class ViewOptics: ViewOptics
				{
					opticsZoomMin = 0.35;
					opticsZoomMax = 0.35;
					initFov = 0.35;
					minFov = 0.35;
					maxFov = 0.35;
				};
			};
			class GPMGTurret2: GPMGTurret2
			{
				class ViewOptics: ViewOptics
				{
					opticsZoomMin = 0.35;
					opticsZoomMax = 0.35;
					initFov = 0.35;
					minFov = 0.35;
					maxFov = 0.35;
				};
			};
			class LeftBack: LeftBack{};
			class RightBack: RightBack
			{
				proxyIndex = 4;
			};
			class MainBack: MainBack
			{
				minTurn = 170;
				maxTurn = 170;
			};
		};
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "AT5LauncherSingle";
				initPhase = 1;
			};
		};
	};
	class ACE_BMD_1P_RU: ACE_BMD_1P_Base
	{
		scope = 2;
		side = 0;
		faction = "ACE_VDV";
		accuracy = 0.5;
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\num\reg.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_01_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_02_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_03_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_04_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_drivewheel_RUS_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel2_RUS_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel_rus_co.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_destruct.rvmat"};
		};
	};
	class ACE_BMD_1P_RUS: ACE_BMD_1P_RU
	{
		scope = 1;
		displayName = "$STR_ACE_VDN_BMD_1P_RUS";
		accuracy = 1000;
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\5.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\num\reg.paa","\x\acex_ru\addons\t_veh_bmd1\num\vdv.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_01_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_02_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_03_RU_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_04_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_drivewheel_RUS_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel2_RUS_co.paa","\x\acex_ru\addons\t_veh_bmd1\sa_bmd1_mainwheel_rus_co.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1p_01_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_02_destruct.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_damage.rvmat","x\acex_ru\addons\c_veh_bmd1\sa_bmd1_03_destruct.rvmat"};
		};
	};
};
class CfgMovesBasic
{
	class ManActions
	{
		MDL_BMD1_Gunner = "MDL_BMD1_Gunner";
		MDL_BMD1P_Gunner = "MDL_BMD1P_Gunner";
		MDL_BMD1P_ATGunner = "MDL_BMD1P_ATGunner";
		SA_BMD1_Cargo01 = "SA_BMD1_Cargo01";
		SA_BMD1_Cargo02 = "SA_BMD1_Cargo02";
		SA_BMD1_Cargo03 = "SA_BMD1_Cargo03";
		SA_BMD1_Cargo04 = "SA_BMD1_Cargo04";
		SA_BMD1_Cargo05 = "SA_BMD1_Cargo05";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class MDL_BMD1_Gunner: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\MODUL_BMD1_gnr.rtm";
			interpolateTo[] = {"MDL_BMD1_Gunner_KIA",1};
		};
		class MDL_BMD1P_Gunner: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\MODUL_BMD1P_gnr.rtm";
			interpolateTo[] = {"MDL_BMD1P_Gunner_KIA",1};
		};
		class MDL_BMD1P_ATGunner: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\MODUL_BMD1P_ATgnr.rtm";
			interpolateTo[] = {"MDL_BMD1P_Gunner_KIA",1};
		};
		class MDL_BMD1_Gunner_KIA: Crew
		{
			actions = "DeadActions";
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\MODUL_BMD1_gnr_KIA.rtm";
			speed = 1.5;
			looped = 0;
			terminal = 1;
			connectTo[] = {"DeadState",0.1};
			soundEnabled = 0;
		};
		class MDL_BMD1P_Gunner_KIA: MDL_BMD1_Gunner_KIA
		{
			actions = "DeadActions";
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\MODUL_BMD1P_gnr_KIA.rtm";
		};
		class SA_BMD1_Cargo01: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\cargo1.rtm";
		};
		class SA_BMD1_Cargo02: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\cargo2.rtm";
		};
		class SA_BMD1_Cargo03: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\cargo3.rtm";
		};
		class SA_BMD1_Cargo04: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\cargo4.rtm";
		};
		class SA_BMD1_Cargo05: Crew
		{
			file = "\x\acex_ru\addons\c_veh_bmd1\anim\cargo5.rtm";
		};
	};
};
//};
