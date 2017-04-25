////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:05:47 2013 : Created on Mon Oct 14 23:05:47 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_vehicle : config.bin{
class CfgPatches
{
	class ace_c_vehicle
	{
		units[] = {};
		weapons[] = {"ACE_AGS30","ACE_Mk19"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Arma2_Ka52","CAA10","CA_AH64D","CAAir","CAAir2","CAAir2_C130J","CA_AIR2_Su25","CAAir_E","CAAir_E_A10","CAAir_E_AH64D","CAAir_E_AH6J","CAAir_E_An2","CAAir_E_C130J","CAAir_E_CH_47F","CAAir_E_Halo","CAAir_E_MI8","CAAir_E_Mi24","CA_AIR_E_Su25","CAAir_E_UH1H_EP1","CAAir_E_UH60M","CAData","CAData_ParticleEffects","CATracked","CATracked2","CATracked2_2S6M_Tunguska","CATracked2_AAV","CATracked2_BMP3","CATracked2_T34","CATracked2_T90","CATracked2_us_m270mlrs","CATracked_E","CATracked_E_M1_Abrams","CATracked_E_M2A2_Bradley","CAWeapons","CAWeapons_E","CAWheeled","CAWheeled_Offroad","CAWheeled_Pickup","CAWheeled2","CAWheeled2_HMMWV_Ambulance","CAWheeled2_HMMWV_BASE","CAWheeled2_Ikarus","CAWheeled2_LADA","CAWheeled2_M1114_Armored","CAWheeled2_M998A2_Avenger","CAWheeled2_MMT","CAWheeled2_MTVR","CAWheeled2_V3S","CAWheeled3","CAWheeled3_M1030","CAWheeled3_TT650","CAWheeled_E","CAWheeled_E_ATV","CAWheeled_E_BRDM2","CAWheeled_E_BTR40","CAWheeled_E_BTR60","CAWheeled_E_Pickup","CAWheeled_E_Offroad","CAWheeled_E_HMMWV","CAWheeled_E_LADA","CAWheeled_E_LandRover","CAWheeled_E_s1203","CAWheeled_E_stryker","CAWheeled_E_UAZ","CAWheeled_E_Ural","CAWheeled_E_V3S","CAWheeled_E_Volha","CAAir_PMC_KA137","CAAir_PMC_KA60","ace_main","ace_m_vehicle","ace_m_veh_wrecks","ace_m_tracer"};
		version = "1.14.0.597";
		author[] = {"King Homer","zGuba"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_c_vehicle
		{
			list[] = {"ace_c_vehicle"};
		};
	};
};
class CfgSurfaces
{
	class Roadway;
	class Cesta: Roadway
	{
		rough = 0.03;
	};
};
class CfgFactionClasses
{
	class BIS_TK
	{
		priority = 14;
	};
	class BIS_TK_INS
	{
		priority = 15;
	};
	class BIS_TK_CIV
	{
		priority = 12;
	};
	class BIS_CIV_special
	{
		priority = 13;
	};
	class BIS_US
	{
		displayName = "$STR_ACE_FAC_BLUFOR_USARMY";
		priority = 8;
	};
	class ACE_USAF
	{
		displayName = "$STR_ACE_FAC_BLUFOR_USAF";
		priority = 9;
		side = 1;
		ACE_Language = "English";
		primaryLanguage = "EN";
	};
	class ACE_USNAVY
	{
		displayName = "$STR_ACE_FAC_BLUFOR_USNAVY";
		priority = 10;
		side = 1;
		ACE_Language = "English";
		primaryLanguage = "EN";
	};
	class ACE_RUNAVY
	{
		displayName = "$STR_ACE_FAC_OPFOR_NAVY";
		side = 0;
		priority = 3;
		ACE_Language = "Russian";
		primaryLanguage = "RU";
	};
	class BIS_CZ
	{
		priority = 12;
	};
	class BIS_GER
	{
		priority = 13;
	};
	class BIS_TK_GUE
	{
		priority = 13;
	};
	class BIS_UN
	{
		priority = 14;
	};
	class PMC_BAF
	{
		primarylanguage = "EN";
	};
	class BIS_BAF
	{
		primarylanguage = "EN";
	};
};
class CfgVehicleClasses
{
	class ACE_Objects
	{
		displayName = "$STR_ACE_VC_OBJECTS";
	};
	class ACE_Mines
	{
		displayName = "$STR_ACE_VC_MINES";
	};
	class MenW
	{
		displayname = "$STR_ACE_VC_MEN_WOOD";
	};
	class MenDDPM
	{
		displayname = "$STR_ACE_VC_MEN_DESERT";
	};
	class ACE_SFMenW
	{
		displayname = "$STR_ACE_VC_SFMEN_WOOD";
	};
	class ACE_SFMenD
	{
		displayname = "$STR_ACE_VC_SFMEN_DESERT";
	};
	class CarW
	{
		displayname = "$STR_ACE_VC_CARS_WOOD";
	};
	class CarD
	{
		displayname = "$STR_ACE_VC_CARS_DESERT";
	};
	class ArmouredW
	{
		displayname = "$STR_ACE_VC_ARMOR_WOOD";
	};
	class ArmouredD
	{
		displayname = "$STR_ACE_VC_ARMOR_DESERT";
	};
};
class CfgVehicles
{
	class All
	{
		class AnimationSources;
	};
	class AllVehicles: All
	{
		class NewTurret;
	};
	class Land: AllVehicles{};
	class LandVehicle: Land
	{
		class ViewOptics;
		class ViewPilot;
		class HeadLimits;
		class Sounds;
	};
	class Tank: LandVehicle
	{
		driverOpticsModel = "\x\ace\addons\m_veh_optics\driver\optika_tank_driver.p3d";
		ACE_exposed = 0;
		ACE_Cargo_exposed = 0;
		ace_sys_nvg_nvrange = 570;
		soundDammage[] = {"",0,1};
		ejectDamageLimit = 0.9;
		class HitPoints;
		class ViewOptics;
		class Turrets
		{
			startEngine = 0;
			class MainTurret: NewTurret
			{
				ACE_exposed = 0;
				ace_sys_nvg_nvrange = 2200;
				ace_sys_nvg_tirange = 10000;
				class Turrets
				{
					class CommanderOptics: NewTurret
					{
						ACE_exposed = 0;
						ace_sys_nvg_nvrange = 2200;
						ace_sys_nvg_tirange = 10000;
					};
				};
			};
		};
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		radarType = 0;
	};
	class Car: LandVehicle
	{
		ACE_exposed = 0;
		ACE_Cargo_exposed = 0;
		ace_sys_nvg_nvrange = 570;
		ejectDamageLimit = 0.95;
		class HitPoints;
		class AnimationSources;
		class Turrets
		{
			startEngine = 0;
			class MainTurret: NewTurret
			{
				ACE_exposed = 1;
				ace_sys_nvg_nvrange = 2200;
				ace_sys_nvg_tirange = 10000;
			};
		};
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		cargoIsCoDriver[] = {1,0};
	};
	class Wheeled_APC: Car
	{
		radarType = 0;
		enableManualFire = 0;
	};
	class Tracked_APC: Tank
	{
		enableManualFire = 0;
	};
	class Motorcycle: LandVehicle
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class Bicycle: Motorcycle
	{
		irTarget = 0;
	};
	class StaticWeapon: LandVehicle
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		irTarget = 0;
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticAAWeapon: StaticWeapon
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class StaticATWeapon: StaticWeapon{};
	class StaticMGWeapon: StaticWeapon{};
	class StaticGrenadeLauncher: StaticWeapon{};
	class StaticCanon: StaticWeapon
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class StaticCannon: StaticWeapon
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
	};
	class Truck: Car
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class Ship;
	class SmallShip: Ship
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class BigShip: Ship
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class Air: AllVehicles
	{
		ACE_exposed = 0;
		ACE_Cargo_exposed = 0;
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class Helicopter: Air
	{
		ejectDamageLimit = 0.9999;
		radarType = 0;
		class AnimationSources;
		class HitPoints
		{
			class HitHull;
			class HitEngine;
			class HitAvionics;
			class HitVRotor;
			class HitHRotor;
			class HitMissiles;
			class HitRGlass;
			class HitLGlass;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
		class Turrets
		{
			class MainTurret;
		};
	};
	class ParachuteBase: Helicopter
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		accuracy = 0;
		castDriverShadow = 1;
	};
	class Plane: Air
	{
		class ViewPilot;
	};
	class BIS_Steerable_Parachute: Plane
	{
		castCargoShadow = 1;
	};
	class Ruins;
	class Strategic;
	class NonStrategic;
	class House;
	class Logic;
	class ACE_Logic;
	class Thing;
	class ACE_Object: Thing
	{
		scope = 1;
		animated = 0;
		vehicleClass = "ACE_Objects";
		destructype = "Destructno";
		cost = 0;
		armor = 30;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class HMMWV_Base: Car
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_HMMWV_BASE";
		displayNameShort = "$STR_ACE_VDNS_HMMWV_BASE";
		maxSpeed = 113;
		fuelCapacity = 163;
		class AnimationSources;
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class HMMWV_M2: HMMWV_Base
	{
		accuracy = 0.5;
		displayName = "M1025 HMMWV (M2)";
		displayNameShort = "HMMWV (M2)";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M2"};
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
			};
		};
	};
	class HMMWV_TOW: HMMWV_Base
	{
		accuracy = 0.5;
		displayName = "M1036 HMMWV (TOW)";
		displayNameShort = "HMMWV (TOW)";
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
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
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {2,3};
				};
				gunnerOpticsModel = "\ca\weapons_e\TOW_TI";
				weapons[] = {"TOWLauncherSingle"};
				magazines[] = {"ACE_TOW2"};
			};
		};
	};
	class HMMWV_MK19: HMMWV_Base
	{
		accuracy = 0.5;
		displayName = "M1025 HMMWV (Mk19)";
		displayNameShort = "HMMWV (Mk19)";
		class AnimationSources: AnimationSources
		{
			class belt_rotation
			{
				source = "reload";
				weapon = "ACE_MK19";
			};
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_MK19";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_MK19";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_MK19";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_MK19"};
			};
		};
	};
	class HMMWV_Armored: HMMWV_Base
	{
		accuracy = 0.5;
		displayName = "M1114 HMMWV (M240)";
		displayNameShort = "HMMWV (M240)";
		armor = 100;
		maxSpeed = 95;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M240_veh_out"};
				magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_M240_veh_out";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_veh_out";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_M240_veh_out";
			};
		};
	};
	class HMMWV: HMMWV_Base
	{
		accuracy = 0.4;
		displayName = "M1025 HMMWV";
		displayNameShort = "HMMWV";
	};
	class HMMWV_Ambulance: HMMWV_Base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_HMMWV_AMBULANCE";
		displayNameShort = "$STR_ACE_VDNS_HMMWV_AMBULANCE";
	};
	class HMMWV_Avenger: HMMWV_Base
	{
		displayname = "M1097 Avenger";
		displayNameShort = "Avenger";
		accuracy = 0.5;
		armor = 40;
		irScanRangeMax = 2000;
		irScanGround = 0;
		maxSpeed = 90;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initFov = "0.33333/ 1";
					minFov = "0.33333/ 6";
					maxFov = "0.33333/ 1";
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
						initFov = "0.33333/ 1";
						minFov = "0.33333/ 1";
						maxFov = "0.33333/ 1";
						gunnerOpticsModel = "\ca\weapons\2Dscope_Avenger";
						visionMode[] = {"Normal","Ti"};
						thermalMode[] = {0,1};
					};
					class Narrow: Wide
					{
						initFov = "0.33333/ 6";
						minFov = "0.33333/ 6";
						maxFov = "0.33333/ 6";
					};
				};
				weapons[] = {"StingerLaucher","M3P"};
				magazines[] = {"ACE_1Rnd_Stinger","ACE_1Rnd_Stinger","ACE_1Rnd_Stinger","ACE_1Rnd_Stinger","ACE_1Rnd_Stinger","ACE_1Rnd_Stinger","ACE_1Rnd_Stinger","ACE_1Rnd_Stinger","250Rnd_127x99_M3P","250Rnd_127x99_M3P"};
			};
		};
	};
	class HMMWV_M1035_DES_EP1: HMMWV_Base
	{
		vehicleclass = "CarD";
		displayname = "$STR_ACE_VDN_HMMWV_UTIL";
		displayNameShort = "$STR_ACE_VDNS_HMMWV_UTIL";
	};
	class HMMWV_DES_EP1: HMMWV
	{
		vehicleclass = "CarD";
	};
	class HMMWV_MK19_DES_EP1: HMMWV_MK19
	{
		vehicleclass = "CarD";
	};
	class HMMWV_Ambulance_base: HMMWV_Ambulance{};
	class HMMWV_Ambulance_DES_EP1: HMMWV_Ambulance_base{};
	class HMMWV_Ambulance_CZ_DES_EP1: HMMWV_Ambulance_base{};
	class HMMWV_Avenger_base: HMMWV_Avenger{};
	class HMMWV_Avenger_DES_EP1: HMMWV_Avenger_base
	{
		vehicleclass = "CarD";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				radarType = 4;
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
			};
		};
	};
	class HMMWV_M1151_M2_DES_Base_EP1: HMMWV_Base
	{
		displayname = "M1151 HMMWV (M2)";
		displayNameShort = "HMMWV (M2)";
		threat[] = {1,0.1,0.6};
		armor = 100;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M2"};
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
				minElev = -25;
				maxElev = 60;
				stabilizedInAxes = 0;
				soundServo[] = {"\x\ace\addons\c_vehicle\data\sound\turret_servo.ogg",0.01,1,10};
			};
		};
	};
	class HMMWV_M1151_M2_CZ_DES_EP1: HMMWV_M1151_M2_DES_Base_EP1{};
	class HMMWV_M1151_M2_DES_EP1: HMMWV_M1151_M2_DES_Base_EP1
	{
		vehicleclass = "CarD";
	};
	class HMMWV_M998_crows_M2_DES_EP1: HMMWV_Base
	{
		vehicleclass = "CarD";
		displayname = "M1114 HMMWV CROWS (M2)";
		displayNameShort = "HMMWV CROWS (M2)";
		armor = 100;
		threat[] = {1,0.1,0.6};
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M2","SmokeLauncher"};
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","SmokeLauncherMag","SmokeLauncherMag"};
				minElev = -20;
				maxElev = 60;
				gunnerForceOptics = 0;
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -170;
					maxAngleX = 170;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.455;
					minFov = 0.25;
					maxFov = 0.7;
				};
				class ViewOptics
				{
					initFov = "0.33333/ 0.5";
					minFov = "0.33333/ 8.5";
					maxFov = "0.33333/ 0.5";
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
						initFov = "0.33333/ 0.5";
						minFov = "0.33333/ 0.5";
						maxFov = "0.33333/ 0.5";
						gunnerOpticsModel = "\ca\Weapons\2Dscope_RWS";
						visionMode[] = {"Normal"};
					};
					class Medium: Wide
					{
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
					};
					class Narrow: Wide
					{
						initFov = "0.33333/ 8.5";
						minFov = "0.33333/ 8.5";
						maxFov = "0.33333/ 8.5";
					};
					class ace_crows_ti_wide: Wide
					{
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
						visionMode[] = {"Ti"};
						thermalMode[] = {0,1};
					};
					class ace_crows_ti_narrow: ace_crows_ti_wide
					{
						initFov = "0.33333/ 9";
						minFov = "0.33333/ 9";
						maxFov = "0.33333/ 9";
					};
				};
				stabilizedInAxes = 3;
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "M2";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "M2";
			};
		};
	};
	class HMMWV_M998_crows_MK19_DES_EP1: HMMWV_Base
	{
		vehicleclass = "CarD";
		displayname = "M1114 HMMWV CROWS (Mk19)";
		displayNameShort = "HMMWV CROWS(Mk19)";
		threat[] = {1,0.5,0.1};
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_MK19","SmokeLauncher"};
				magazines[] = {"48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","SmokeLauncherMag","SmokeLauncherMag"};
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				minElev = -20;
				maxElev = 60;
				gunnerForceOptics = 0;
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -170;
					maxAngleX = 170;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.455;
					minFov = 0.25;
					maxFov = 0.7;
				};
				class ViewOptics
				{
					initFov = "0.33333/ 0.5";
					minFov = "0.33333/ 8.5";
					maxFov = "0.33333/ 0.5";
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
						initFov = "0.33333/ 0.5";
						minFov = "0.33333/ 0.5";
						maxFov = "0.33333/ 0.5";
						gunnerOpticsModel = "\ca\Weapons\2Dscope_RWS";
						visionMode[] = {"Normal"};
					};
					class Medium: Wide
					{
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
					};
					class Narrow: Wide
					{
						initFov = "0.33333/ 8.5";
						minFov = "0.33333/ 8.5";
						maxFov = "0.33333/ 8.5";
					};
					class ace_crows_ti_wide: Wide
					{
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
						visionMode[] = {"Ti"};
						thermalMode[] = {0,1};
					};
					class ace_crows_ti_narrow: ace_crows_ti_wide
					{
						initFov = "0.33333/ 9";
						minFov = "0.33333/ 9";
						maxFov = "0.33333/ 9";
					};
				};
				stabilizedInAxes = 3;
			};
		};
	};
	class HMMWV_M998A2_SOV_DES_EP1: HMMWV_Base
	{
		vehicleclass = "CarD";
		displayname = "Special Operations Vehicle";
		displayNameShort = "SOV";
		armor = 40;
		threat[] = {1,0.1,0.3};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"MK19"};
				magazines[] = {"48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19"};
				primaryGunner = 1;
			};
			class SideTurret: MainTurret
			{
				gunnerName = "front gunner";
				weapons[] = {"M240_veh"};
				magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240"};
				primaryGunner = 0;
			};
		};
	};
	class HMMWV_TOW_DES_EP1: HMMWV_TOW
	{
		vehicleclass = "CarD";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics: Viewoptics
				{
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {2,3};
				};
			};
		};
	};
	class HMMWV_Terminal_EP1: HMMWV_Base
	{
		vehicleclass = "CarD";
		displayName = "M1152 HMMWV UAV GCS";
		displayNameShort = "HMMWV UAV GCS";
	};
	class MTVR: Truck
	{
		displayName = "MK23 MTVR";
		accuracy = 0.4;
		maxSpeed = 115;
		fuelCapacity = 295;
		turnCoef = 5;
	};
	class MTVR_Base;
	class MTVR_DES_EP1: MTVR_base
	{
		vehicleclass = "CarD";
	};
	class MTVRReammo: MTVR
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_MTVRREAMMO";
	};
	class MTVRRefuel: MTVR
	{
		accuracy = 0.42;
		displayName = "$STR_ACE_VDN_MTVRREFUEL";
	};
	class MTVRRepair: MTVR
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_MTVRREPAIR";
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class M1030: Motorcycle
	{
		accuracy = 0.4;
		displayName = "M1030";
	};
	class M1030_base;
	class M1030_US_DES_EP1: M1030_base
	{
		vehicleclass = "CarW";
	};
	class UAZ_Base: Car
	{
		ACE_exposed = 0;
		ACE_Cargo_exposed = 0;
		maxSpeed = 113;
		fuelCapacity = 78;
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_UAZ_BASE";
		displayNameShort = "$STR_ACE_VDNS_UAZ_BASE";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"DShKM"};
				magazines[] = {"50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM"};
			};
		};
		class AnimationSources;
	};
	class UAZ_Unarmed_Base: UAZ_Base
	{
		accuracy = 0.4;
		maxSpeed = 113;
		displayName = "$STR_ACE_VDN_UAZ_UNARMED_BASE";
		displayNameShort = "$STR_ACE_VDNS_UAZ_UNARMED_BASE";
		class Damage
		{
			mat[] = {"Ca\wheeled_E\UAZ\Data\uaz_main_metal.rvmat","Ca\wheeled_E\UAZ\Data\uaz_main_metal_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_main_metal_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_skla.rvmat","Ca\wheeled_E\Data\auta_skla_damage.rvmat","Ca\wheeled_E\Data\auta_skla_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_skla_in.rvmat","Ca\wheeled_E\Data\auta_skla_in_damage.rvmat","Ca\wheeled_E\Data\auta_skla_in_damage.rvmat","ca\weapons\data\dshk.rvmat","ca\weapons\data\dshk_damage.rvmat","ca\weapons\data\dshk_destruct.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default_destruct.rvmat"};
			tex[] = {};
		};
	};
	class UAZ_MG_Base: UAZ_Base
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_UAZ_MG_BASE";
		displayNameShort = "$STR_ACE_VDN_UAZ_MG_BASE";
		class Damage
		{
			mat[] = {"Ca\wheeled_E\UAZ\Data\uaz_main_metal.rvmat","Ca\wheeled_E\UAZ\Data\uaz_main_metal_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_main_metal_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_skla.rvmat","Ca\wheeled_E\Data\auta_skla_damage.rvmat","Ca\wheeled_E\Data\auta_skla_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_skla_in.rvmat","Ca\wheeled_E\Data\auta_skla_in_damage.rvmat","Ca\wheeled_E\Data\auta_skla_in_damage.rvmat","ca\weapons\data\dshk.rvmat","ca\weapons\data\dshk_damage.rvmat","ca\weapons\data\dshk_destruct.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default_destruct.rvmat"};
			tex[] = {};
		};
	};
	class UAZ_AGS30_Base: UAZ_Base
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_UAZ_AGS30_BASE";
		displayNameShort = "$STR_ACE_VDN_UAZ_AGS30_BASE";
		class Damage
		{
			mat[] = {"Ca\wheeled_E\UAZ\Data\uaz_main_metal.rvmat","Ca\wheeled_E\UAZ\Data\uaz_main_metal_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_main_metal_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_other_metal_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_mount_destruct.rvmat","Ca\wheeled_E\UAZ\Data\uaz_skla.rvmat","Ca\wheeled_E\Data\auta_skla_damage.rvmat","Ca\wheeled_E\Data\auta_skla_damage.rvmat","Ca\wheeled_E\UAZ\Data\uaz_skla_in.rvmat","Ca\wheeled_E\Data\auta_skla_in_damage.rvmat","Ca\wheeled_E\Data\auta_skla_in_damage.rvmat","ca\weapons\data\dshk.rvmat","ca\weapons\data\dshk_damage.rvmat","ca\weapons\data\dshk_destruct.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default_destruct.rvmat"};
			tex[] = {};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_AGS30"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_AGS30";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_AGS30";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_AGS30";
			};
		};
	};
	class UAZ_SPG9_Base: UAZ_Base
	{
		ACE_exposed = 1;
		ACE_Cargo_exposed = 1;
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_UAZ_SPG9_BASE";
		displayNameShort = "$STR_ACE_VDN_UAZ_SPG9_BASE";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundservo[] = {"\ca\wheeled\Data\Sound\servo3","1e-006",1};
				stabilizedInAxes = 0;
				minElev = -20;
				maxElev = 30;
				weapons[] = {"SPG9"};
				magazines[] = {"PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE"};
				class OpticsIn
				{
					class HEAT
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9heat";
						initFov = 0.073143;
						minFov = 0.073143;
						maxFov = 0.073143;
						visionMode[] = {"Normal"};
					};
					class HE: HEAT
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9he";
					};
				};
			};
		};
	};
	class UAZ_MG_CDF: UAZ_MG_Base
	{
		accuracy = 0.5;
	};
	class UAZ_AGS30_CDF: UAZ_AGS30_Base
	{
		accuracy = 0.5;
	};
	class UAZ_CDF: UAZ_Unarmed_Base
	{
		accuracy = 0.5;
	};
	class UAZ_MG_INS: UAZ_MG_Base
	{
		accuracy = 0.5;
	};
	class UAZ_AGS30_INS: UAZ_AGS30_Base
	{
		accuracy = 0.5;
	};
	class UAZ_INS: UAZ_Unarmed_Base
	{
		accuracy = 0.5;
	};
	class UAZ_SPG9_INS: UAZ_SPG9_Base
	{
		accuracy = 0.5;
	};
	class UAZ_AGS30_RU: UAZ_AGS30_Base
	{
		accuracy = 0.5;
	};
	class UAZ_RU: UAZ_Unarmed_Base
	{
		accuracy = 0.5;
	};
	class UAZ_MG_TK_EP1: UAZ_MG_Base
	{
		accuracy = 0.5;
	};
	class UAZ_AGS30_TK_EP1: UAZ_AGS30_Base
	{
		accuracy = 0.5;
	};
	class UAZ_Unarmed_TK_EP1: UAZ_Unarmed_Base
	{
		accuracy = 0.5;
	};
	class UAZ_Unarmed_UN_EP1: UAZ_Unarmed_Base
	{
		accuracy = 0.5;
	};
	class UAZ_Unarmed_TK_CIV_EP1: UAZ_Unarmed_Base
	{
		accuracy = 0.5;
	};
	class ACE_UAZ_SPG9_CDF: UAZ_SPG9_INS
	{
		side = 1;
		faction = "CDF";
		crew = "CDF_Soldier_Militia";
		typicalCargo[] = {"CDF_Soldier_Militia","CDF_Soldier","CDF_Soldier_AR"};
		hiddenSelectionsTextures[] = {"\ca\wheeled\data\Uaz_main_002_CO.paa","\ca\wheeled\data\uaz_mount_002_co.paa"};
	};
	class ACE_UAZ_MG_RU: UAZ_MG_INS
	{
		faction = "RU";
		crew = "RU_Soldier";
		typicalCargo[] = {"RU_Soldier","RU_Soldier","RU_Soldier"};
		hiddenSelectionsTextures[] = {"\ca\wheeled\data\Uaz_main_CO.paa","\ca\wheeled\data\uaz_mount_co.paa"};
	};
	class Ural_Base_withTurret: Truck
	{
		maxSpeed = 82;
		fuelCapacity = 300;
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_URAL_BASE_WITHTURRET";
		displayNameShort = "$STR_ACE_VDNS_URAL_BASE_WITHTURRET";
	};
	class Ural_Base: Ural_Base_withTurret
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_URAL_BASE";
		displayNameShort = "$STR_ACE_VDNS_URAL_BASE";
	};
	class UralOpen_Base: Ural_Base
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_URALOPEN_BASE";
		displayNameShort = "$STR_ACE_VDNS_URALOPEN_BASE";
	};
	class UralReammo_Base: Ural_Base
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_URALREAMMO_BASE";
		displayNameShort = "$STR_ACE_VDN_URALREAMMO_BASE";
	};
	class UralRefuel_Base: Ural_Base
	{
		accuracy = 0.42;
		displayName = "$STR_ACE_VDN_URALREFUEL_BASE";
		displayNameShort = "$STR_ACE_VDN_URALREFUEL_BASE";
	};
	class UralRepair_Base: Ural_Base
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_URALREPAIR_BASE";
		displayNameShort = "$STR_ACE_VDN_URALREPAIR_BASE";
	};
	class Ural_ZU23_Base: Ural_Base_withTurret
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_URAL_ZU23_BASE";
		displayNameShort = "$STR_ACE_VDN_URAL_ZU23_BASE";
		class AnimationSources: AnimationSources
		{
			class fire_anim
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0.003;
			};
		};
	};
	class Ural_CDF: Ural_Base
	{
		accuracy = 0.5;
	};
	class Ural_INS: Ural_Base
	{
		accuracy = 0.5;
	};
	class Ural_Gue: Ural_Base
	{
		accuracy = 0.5;
	};
	class UralOpen_CDF: UralOpen_Base
	{
		accuracy = 0.5;
	};
	class UralOpen_INS: UralOpen_Base
	{
		accuracy = 0.5;
	};
	class UralOpen_Gue: UralOpen_Base
	{
		accuracy = 0.5;
	};
	class UralReammo_CDF: UralReammo_Base
	{
		accuracy = 0.5;
	};
	class UralReammo_INS: UralReammo_Base
	{
		accuracy = 0.5;
	};
	class UralReammo_Gue: UralReammo_Base
	{
		accuracy = 0.5;
	};
	class UralRefuel_CDF: UralRefuel_Base
	{
		accuracy = 0.5;
	};
	class UralRefuel_INS: UralRefuel_Base
	{
		accuracy = 0.5;
	};
	class UralRefuel_Gue: UralRefuel_Base
	{
		accuracy = 0.5;
	};
	class UralRepair_CDF: UralRepair_Base
	{
		accuracy = 0.5;
	};
	class UralRepair_INS: UralRepair_Base
	{
		accuracy = 0.5;
	};
	class UralRepair_Gue: UralRepair_Base
	{
		accuracy = 0.5;
	};
	class Ural_ZU23_CDF: Ural_ZU23_Base
	{
		accuracy = 0.5;
	};
	class Ural_ZU23_INS: Ural_ZU23_Base
	{
		accuracy = 0.5;
	};
	class Ural_ZU23_Gue: Ural_ZU23_Base
	{
		accuracy = 0.5;
	};
	class Ural_UN_EP1: Ural_Base
	{
		accuracy = 0.4;
	};
	class UralRepair_TK_EP1: UralRepair_Base
	{
		accuracy = 0.5;
	};
	class UralReammo_TK_EP1: UralReammo_Base
	{
		accuracy = 0.5;
	};
	class UralRefuel_TK_EP1: UralRefuel_Base
	{
		accuracy = 0.5;
	};
	class Ural_ZU23_TK_EP1: Ural_ZU23_Base
	{
		accuracy = 0.5;
	};
	class Ural_ZU23_TK_GUE_EP1: Ural_ZU23_Base
	{
		accuracy = 0.5;
	};
	class UralCivil: Ural_Base
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_URAL_BASE";
	};
	class UralCivil2: UralOpen_Base
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_URALOPEN_BASE";
	};
	class Ural_TK_CIV_EP1: Ural_Base
	{
		accuracy = 0.4;
	};
	class Kamaz_Base: Truck
	{
		accuracy = 0.4;
		maxSpeed = 110;
		displayName = "$STR_ACE_VDN_KAMAZ_BASE";
		displayNameShort = "$STR_ACE_VDNS_KAMAZ_BASE";
	};
	class KamazOpen: Kamaz_Base
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_KAMAZOPEN";
		displayNameShort = "$STR_ACE_VDNS_KAMAZOPEN";
	};
	class KamazReammo: Kamaz_Base
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_KAMAZREAMMO";
		displayNameShort = "$STR_ACE_VDN_KAMAZREAMMO";
	};
	class KamazRefuel: Kamaz_Base
	{
		accuracy = 0.42;
		displayName = "$STR_ACE_VDN_KAMAZREFUEL";
		displayNameShort = "$STR_ACE_VDN_KAMAZREFUEL";
	};
	class KamazRepair: Kamaz_Base
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_KAMAZREPAIR";
		displayNameShort = "$STR_ACE_VDN_KAMAZREPAIR";
	};
	class SkodaBase: Car
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_SKODABASE";
		displayNameShort = "$STR_ACE_VDNS_SKODABASE";
	};
	class Skoda: SkodaBase
	{
		displayName = "$STR_ACE_VDN_SKODAWHITE";
		displayNameShort = "$STR_ACE_VDN_SKODAWHITE";
	};
	class SkodaBlue: SkodaBase
	{
		displayName = "$STR_ACE_VDN_SKODABLUE";
		displayNameShort = "$STR_ACE_VDN_SKODABLUE";
	};
	class SkodaRed: SkodaBase
	{
		displayName = "$STR_ACE_VDN_SKODARED";
		displayNameShort = "$STR_ACE_VDN_SKODARED";
	};
	class SkodaGreen: SkodaBase
	{
		displayName = "$STR_ACE_VDN_SKODAGREEN";
		displayNameShort = "$STR_ACE_VDN_SKODAGREEN";
	};
	class car_sedan: SkodaBase
	{
		accuracy = 0.4;
		displayName = "Toyota Corolla";
		displayNameShort = "Corolla";
	};
	class datsun1_civil_1_open: SkodaBase
	{
		accuracy = 0.4;
		ACE_Cargo_exposed = 1;
		displayName = "Datsun 620";
		displayNameShort = "Datsun";
	};
	class VWGolf: Car
	{
		maxSpeed = 180;
		accuracy = 0.4;
		displayName = "VW Golf IV";
		displayNameShort = "Golf";
	};
	class Lada_base: Car
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_LADA_BASE";
		displayNameShort = "$STR_ACE_VDNS_LADA_BASE";
	};
	class Lada1: Lada_base
	{
		displayName = "$STR_ACE_VDN_LADA1";
		displayNameShort = "$STR_ACE_VDN_LADA1";
	};
	class Lada2: Lada_base
	{
		displayName = "$STR_ACE_VDN_LADA2";
		displayNameShort = "$STR_ACE_VDN_LADA2";
	};
	class LadaLM: Lada_base
	{
		displayName = "$STR_ACE_VDN_LADALM";
		displayNameShort = "$STR_ACE_VDN_LADALM";
	};
	class hilux1_civil_1_open: Car
	{
		ACE_Cargo_exposed = 1;
		accuracy = 0.4;
		displayName = "Toyota Hilux";
		displayNameShort = "Hilux";
	};
	class hilux1_civil_2_covered: hilux1_civil_1_open
	{
		ACE_Cargo_exposed = 0;
		accuracy = 1000;
	};
	class hilux1_civil_3_open: hilux1_civil_1_open
	{
		accuracy = 1000;
	};
	class Pickup_PK_base: Car
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_PICKUP_PK_BASE";
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_PKT_out";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_PKT_out";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_PKT_out"};
			};
		};
	};
	class Pickup_PK_GUE: Pickup_PK_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_PICKUP_PK";
	};
	class Pickup_PK_INS: Pickup_PK_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_PICKUP_PK";
	};
	class Pickup_PK_TK_GUE_EP1: Pickup_PK_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_PICKUP_PK";
	};
	class Offroad_DSHKM_base: Car
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_OFFROAD_DSHKM_BASE";
		unitinfotype = "RscUnitInfo";
	};
	class Offroad_DSHKM_Gue: Offroad_DSHKM_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_OFFROAD_DSHKM";
	};
	class Offroad_SPG9_Gue: Offroad_DSHKM_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_OFFROAD_SPG9";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundservo[] = {"\ca\wheeled\Data\Sound\servo3","1e-006",1};
				minElev = -20;
				maxElev = 30;
				stabilizedInAxes = 0;
				weapons[] = {"SPG9"};
				magazines[] = {"PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE"};
				class OpticsIn
				{
					class HEAT
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9heat";
						initFov = 0.073143;
						minFov = 0.073143;
						maxFov = 0.073143;
						visionMode[] = {"Normal"};
					};
					class HE: HEAT
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9he";
					};
				};
			};
		};
	};
	class ACE_Offroad_SPG9_INS: Offroad_SPG9_Gue
	{
		side = 0;
		faction = "INS";
		crew = "Ins_Soldier_1";
		typicalCargo[] = {"Ins_Soldier_1"};
		hiddenSelectionsTextures[] = {"\ca\wheeled\hilux_armed\data\coyota_trup1_CO.paa"};
	};
	class Offroad_DSHKM_INS: Offroad_DSHKM_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_OFFROAD_DSHKM";
	};
	class Offroad_DSHKM_TK_GUE_EP1: Offroad_DSHKM_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_OFFROAD_DSHKM";
	};
	class Offroad_SPG9_base: Offroad_SPG9_Gue
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_OFFROAD_DSHKM_BASE";
	};
	class Offroad_SPG9_TK_GUE_EP1: Offroad_SPG9_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_OFFROAD_SPG9";
	};
	class Ikarus: Car
	{
		accuracy = 0.4;
		displayName = "Ikarus 260";
		displayNameShort = "Ikarus";
	};
	class V3S_Base: Truck
	{
		accuracy = 0.4;
		displayName = "Praga V3S";
		displayNameShort = "Praga";
	};
	class V3S_Base_EP1: V3S_Base
	{
		accuracy = 0.4;
		displayName = "Praga V3S";
	};
	class V3S_TK_EP1: V3S_Base_EP1
	{
		accuracy = 0.5;
		displayName = "Praga V3S";
	};
	class V3S_Open_TK_EP1: V3S_Base_EP1
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_V3S_OPEN";
	};
	class V3S_Open_TK_CIV_EP1: V3S_Base_EP1
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_V3S_OPEN";
	};
	class V3S_TK_GUE_EP1: V3S_Base_EP1
	{
		accuracy = 0.5;
		displayName = "Praga V3S";
	};
	class V3S_Refuel_TK_GUE_EP1: V3S_Base_EP1
	{
		accuracy = 0.42;
		displayName = "$STR_ACE_VDN_V3S_REFUEL";
		displayNameShort = "$STR_ACE_VDN_V3S_REFUEL";
	};
	class V3S_Repair_TK_GUE_EP1: V3S_Base_EP1
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_V3S_REPAIR";
		displayNameShort = "$STR_ACE_VDN_V3S_REPAIR";
	};
	class V3S_Reammo_TK_GUE_EP1: V3S_Base_EP1
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_V3S_REAMMO";
		displayNameShort = "$STR_ACE_VDN_V3S_REAMMO";
	};
	class S1203_TK_CIV_EP1: Car
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_S1203";
	};
	class S1203_ambulance_EP1: S1203_TK_CIV_EP1
	{
		accuracy = 0.42;
		displayName = "$STR_ACE_VDN_S1203_AMBULANCE";
	};
	class Volha_TK_CIV_Base_EP1: Car
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_VOLGA_BASE";
	};
	class Volha_1_TK_CIV_EP1: Volha_TK_CIV_Base_EP1
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_VOLGA_BLUE";
	};
	class Volha_2_TK_CIV_EP1: Volha_TK_CIV_Base_EP1
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_VOLGA_GRAY";
	};
	class VolhaLimo_TK_CIV_EP1: Volha_TK_CIV_Base_EP1
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_BLACK_VOLGA";
	};
	class LandRover_Base: Car
	{
		accuracy = 0.4;
		displayname = "Land Rover Defender";
	};
	class LandRover_CZ_EP1: LandRover_Base
	{
		accuracy = 0.5;
	};
	class LandRover_TK_CIV_EP1: LandRover_CZ_EP1
	{
		accuracy = 0.5;
		class TransportMagazines{};
		class TransportWeapons{};
	};
	class LandRover_MG_Base_EP1: LandRover_Base
	{
		accuracy = 0.4;
		displayname = "$STR_ACE_VDN_LANDROVER_ARMED";
	};
	class LandRover_MG_TK_INS_EP1: LandRover_MG_Base_EP1
	{
		accuracy = 0.5;
		displayName = "Land Rover (M2)";
	};
	class LandRover_MG_TK_EP1: LandRover_MG_Base_EP1
	{
		accuracy = 0.5;
		displayName = "Land Rover (M2)";
	};
	class LandRover_Special_CZ_EP1: LandRover_Base
	{
		accuracy = 0.5;
		displayName = "Land Rover (SF)";
		class Turrets: Turrets
		{
			class AGS30_Turret: MainTurret
			{
				weapons[] = {"ACE_AGS30"};
			};
			class PK_Turret: MainTurret
			{
				weapons[] = {"ACE_PKT_out"};
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_AGS30";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_AGS30";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_AGS30";
			};
			class ReloadAnim_2
			{
				source = "reload";
				weapon = "ACE_PKT_out";
			};
			class ReloadMagazine_2
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out";
			};
			class Revolving_2
			{
				source = "revolving";
				weapon = "ACE_PKT_out";
			};
		};
	};
	class LandRover_SPG9_Base_EP1: LandRover_Base
	{
		accuracy = 0.4;
		displayname = "$STR_ACE_VDN_LANDROVER_ARMED";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				maxElev = 30;
				gunnerOpticsModel = "\ca\weapons\2Dscope_SPG_4";
				class ViewOptics: ViewOptics
				{
					initFov = 0.2;
					minFov = 0.058;
					maxFov = 0.2;
				};
				weapons[] = {"SPG9"};
				magazines[] = {"PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE","PG9_AT","OG9_HE"};
				class OpticsIn
				{
					class HEAT
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9heat";
						initFov = 0.073143;
						minFov = 0.073143;
						maxFov = 0.073143;
						visionMode[] = {"Normal"};
					};
					class HE: HEAT
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9he";
					};
				};
			};
		};
	};
	class LandRover_SPG9_TK_INS_EP1: LandRover_SPG9_Base_EP1
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_LANDROVER_SPG9";
	};
	class LandRover_SPG9_TK_EP1: LandRover_SPG9_Base_EP1
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_LANDROVER_SPG9";
	};
	class Old_moto_base: Motorcycle
	{
		accuracy = 0.4;
		displayName = "Jawa 353";
	};
	class TT650_Base: Motorcycle
	{
		accuracy = 0.4;
		maxSpeed = 250;
		displayName = "Yamaha TT650";
	};
	class Old_bike_base_EP1: Bicycle
	{
		accuracy = 0.4;
		maxSpeed = 25;
		terrainCoef = 5;
	};
	class Old_bike_TK_CIV_EP1: Old_bike_base_EP1
	{
		accuracy = 0.5;
	};
	class Old_bike_TK_INS_EP1: Old_bike_base_EP1
	{
		accuracy = 0.5;
	};
	class MMT_base: Bicycle
	{
		accuracy = 0.4;
		maxSpeed = 30;
		terrainCoef = 4;
	};
	class MMT_USMC: MMT_base
	{
		accuracy = 0.5;
		displayName = "MMT";
	};
	class MMT_Civ: MMT_base
	{
		accuracy = 0.5;
	};
	class ATV_Base_EP1: Car
	{
		accuracy = 0.4;
		castcargoshadow = 1;
		castdrivershadow = 1;
		obstructsoundswhenin = 1;
		occludesoundswhenin = 1;
		turnCoef = 0.75;
		preferRoads = 0;
		terrainCoef = 1.2;
		damperSize = 0.2;
		damperForce = 1;
		transportMaxMagazines = 21;
		transportMaxWeapons = 3;
	};
	class ATV_US_EP1: ATV_Base_EP1
	{
		accuracy = 0.5;
		vehicleclass = "CarD";
	};
	class ATV_CZ_EP1: ATV_Base_EP1
	{
		accuracy = 0.5;
	};
	class BAF_Jackal2_BASE_D: Car
	{
		accuracy = 0.4;
		displayName = "Jackal 2 MWMIK";
		enablegps = 1;
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class BAF_Jackal2_L2A1_D: BAF_Jackal2_BASE_D
	{
		accuracy = 0.5;
		displayname = "Jackal 2 MWMIK (L2A1)";
		class Turrets: Turrets
		{
			class M2_Turret: MainTurret
			{
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				turretInfoType = "RscWeaponEmpty";
			};
		};
	};
	class BAF_Jackal2_GMG_D: BAF_Jackal2_BASE_D
	{
		displayname = "Jackal 2 MWMIK (GMG)";
		accuracy = 0.5;
		class Turrets: Turrets
		{
			class GMG_Turret: MainTurret
			{
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				turretInfoType = "RscWeaponEmpty";
			};
		};
	};
	class BAF_Offroad_D: LandRover_CZ_EP1
	{
		displayName = "Land Rover Defender";
	};
	class BAF_ATV_D: ATV_Base_EP1
	{
		accuracy = 0.5;
	};
	class LAV25_Base: Wheeled_APC
	{
		vehicleclass = "ArmouredW";
		accuracy = 0.4;
		displayName = "LAV-25A2";
		canFloat = 1;
		maxSpeed = 110;
		fuelCapacity = 269;
		threat[] = {0.9,0.2,0.7};
		armor = 150;
		armorstructural = 3.25;
		damageResistance = 0.02432;
		irScanRangeMax = 2000;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				visual = "";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "zbytek";
				visual = "";
				passThrough = 0;
			};
		};
		driverForceOptics = 1;
		driverOpticsModel = "\x\ace\addons\m_veh_optics\driver\optika_tank_driver_west.p3d";
		forceHideDriver = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M242","M240_veh"};
				magazines[] = {"210Rnd_25mm_M242_APDS","210Rnd_25mm_M242_HEI","ACE_400Rnd_762x51_M240","ACE_400Rnd_762x51_M240","ACE_400Rnd_762x51_M240","ACE_400Rnd_762x51_M240"};
				minElev = -7;
				maxElev = 59;
				maxVerticalRotSpeed = 0.63;
				maxHorizontalRotSpeed = 0.79;
				stabilizedInAxes = 3;
				gunnerForceOptics = 1;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				startengine = 0;
				lockWhenDriverOut = 0;
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.3;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
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
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
						visionMode[] = {"Normal","Ti"};
						thermalMode[] = {2,3};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\2Dscope_LAV_7";
					};
					class Medium: Wide
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\2Dscope_LAV_7";
						initFov = "0.33333/ 10";
						minFov = "0.33333/ 10";
						maxFov = "0.33333/ 10";
					};
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 10";
					minFov = "0.33333/ 1";
					maxFov = "0.33333/ 10";
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
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class Turrets
				{
					class CommanderOptics: NewTurret
					{
						minElev = -4;
						maxElev = 20;
						commanderForceOptics = 1;
						forceHideCommander = 0;
						outGunnerMayFire = 1;
						inGunnerMayFire = 1;
						startengine = 0;
						weapons[] = {"SmokeLauncher"};
						magazines[] = {"SmokeLauncherMag","SmokeLauncherMag"};
						stabilizedInAxes = 3;
					};
				};
			};
		};
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
	};
	class LAV25_HQ: LAV25_Base
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_LAV25_HQ";
	};
	class StrykerBase_EP1: Wheeled_APC
	{
		vehicleclass = "ArmouredD";
		displayName = "IAV Stryker";
		radarType = 4;
		driverOpticsModel = "\ca\weapons\2Dscope_com1";
		driveropticseffect[] = {"TankCommanderOptics1"};
		class ViewOptics: ViewOptics
		{
			visionMode[] = {"Normal","NVG","Ti"};
			thermalMode[] = {0,1};
		};
		irscanrangemax = 2000;
		fuelCapacity = 246;
		armor = 150;
		armorStructural = 3.25;
		maxSpeed = 106;
		threat[] = {0.5,0.5,0.5};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				startengine = 0;
				gunnerOpticsModel = "\ca\Weapons\2Dscope_RWS";
				minElev = -20;
				maxElev = 60;
				minTurn = -360;
				maxTurn = 360;
				initElev = 0;
				initTurn = 0;
				gunnerFireAlsoInInternalCamera = 1;
				gunnerOpticsEffect[] = {};
				class ViewOptics: ViewOptics
				{
					visionMode[] = {"Normal","NVG","Ti"};
					thermalMode[] = {0,1};
				};
				radarType = 4;
			};
		};
	};
	class M1126_ICV_BASE_EP1: StrykerBase_EP1
	{
		displayName = "M1126 Stryker ICV";
		armor = 150;
		class Turrets: Turrets
		{
			class ObsTurret: NewTurret
			{
				startengine = 0;
				gunnerOpticsModel = "\ca\Weapons\2Dscope_RWS";
				stabilizedInAxes = 0;
				minElev = -20;
				maxElev = "+60";
				minTurn = -360;
				maxTurn = "+360";
				class ViewOptics
				{
					initFov = "0.33333/ 0.5";
					minFov = "0.33333/ 0.5";
					maxFov = "0.33333/ 0.5";
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
						initFov = "0.33333/ 0.5";
						minFov = "0.33333/ 0.5";
						maxFov = "0.33333/ 0.5";
						gunnerOpticsModel = "\ca\Weapons\2Dscope_RWS";
						visionMode[] = {"Normal"};
					};
					class Medium: Wide
					{
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
					};
					class Narrow: Wide
					{
						initFov = "0.33333/ 8.5";
						minFov = "0.33333/ 8.5";
						maxFov = "0.33333/ 8.5";
					};
					class ace_crows_ti_wide: Wide
					{
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
						visionMode[] = {"Ti"};
						thermalMode[] = {0,1};
					};
					class ace_crows_ti_narrow: ace_crows_ti_wide
					{
						initFov = "0.33333/ 9";
						minFov = "0.33333/ 9";
						maxFov = "0.33333/ 9";
					};
				};
				radarType = 0;
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "M2";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "M2";
			};
		};
	};
	class M1126_ICV_M2_EP1: M1126_ICV_BASE_EP1
	{
		scope = 1;
		displayName = "M1126 Stryker ICV (M2)";
		class Turrets: Turrets
		{
			class ObsTurret: ObsTurret
			{
				weapons[] = {"M2","SmokeLauncher"};
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","SmokeLauncherMag","SmokeLauncherMag"};
			};
		};
	};
	class M1126_ICV_mk19_EP1: M1126_ICV_BASE_EP1
	{
		scope = 1;
		displayName = "M1126 Stryker ICV (Mk19)";
		threat[] = {1,0.5,0};
		class Turrets: Turrets
		{
			class ObsTurret: ObsTurret
			{
				weapons[] = {"ACE_MK19","SmokeLauncher"};
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				magazines[] = {"48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","SmokeLauncherMag","SmokeLauncherMag"};
			};
		};
	};
	class M1130_CV_EP1: M1126_ICV_M2_EP1
	{
		scope = 1;
		displayName = "M1130 Stryker CV";
	};
	class M1129_MC_EP1: M1126_ICV_mk19_EP1
	{
		scope = 2;
		displayName = "M1129 Stryker MC";
		threat[] = {1,0.3,0};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				turretinfotype = "RscWeaponEmpty";
				soundServo[] = {"","db1",1};
				gunnerforceoptics = 0;
				lockwhenvehiclespeed = 10;
				stabilizedinaxes = 0;
				class ViewOptics: ViewOptics
				{
					visionmode[] = {};
				};
			};
			class ObsTurret: ObsTurret
			{
				startengine = 0;
				stabilizedinaxes = 3;
			};
		};
	};
	class M1135_ATGMV_EP1: StrykerBase_EP1
	{
		displayName = "M1134 Stryker ATGMV";
		armor = 150;
		threat[] = {0.3,1,0.3};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunbeg = "rocket_begin";
				gunend = "rocket_end";
				weapons[] = {"TOWLauncher","SmokeLauncher"};
				magazines[] = {"2Rnd_TOW","SmokeLauncherMag","SmokeLauncherMag"};
				gunnerOpticsModel = "\ca\weapons_e\TOW_TI";
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 0.5";
					minFov = "0.33333/ 0.5";
					maxFov = "0.33333/ 0.5";
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {2,3};
				};
			};
		};
	};
	class M1128_MGS_EP1: StrykerBase_EP1
	{
		scope = 1;
		displayName = "M1128 Stryker MGS";
		threat[] = {1,1,0.3};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "M2";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "M2";
			};
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_M68";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_StrykerMgun105","M2","SmokeLauncher"};
				magazines[] = {"ACE_9Rnd_M456A2","ACE_9Rnd_M900","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","SmokeLauncherMag","SmokeLauncherMag"};
				minElev = -1;
				maxElev = 1;
				initElev = 0;
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
						initFov = "0.33333/ 15";
						minFov = "0.33333/ 15";
						maxFov = "0.33333/ 15";
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {4,5};
						gunnerOpticsModel = "CA\Tracked_E\gunnerOptics_M1A1";
					};
					class Medium: Wide
					{
						initFov = "0.33333/ 16";
						minFov = "0.33333/ 16";
						maxFov = "0.33333/ 16";
					};
					class Narrow: Wide
					{
						gunnerOpticsModel = "CA\Tracked_E\gunnerOptics_M1A1_2";
						initFov = "0.33333/ 18";
						minFov = "0.33333/ 18";
						maxFov = "0.33333/ 18";
					};
				};
			};
		};
	};
	class M1133_MEV_EP1: StrykerBase_EP1
	{
		scope = 2;
		displayName = "M1133 Stryker MEV";
		armor = 150;
	};
	class BRDM2_Base: Wheeled_APC
	{
		displayName = "$STR_ACE_VDN_BRDM2_BASE";
		accuracy = 0.4;
		armor = 100;
		armorStructural = 2;
		maxSpeed = 108;
		fuelCapacity = 290;
		driverForceOptics = 0;
		forceHideDriver = 1;
		canFloat = 1;
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61";
				stabilizedInAxes = 1;
				gunnerForceOptics = 1;
				forceHideGunner = 1;
				inGunnerMayFire = 1;
				gunnerOpticsEffect[] = {};
				startEngine = 0;
				minElev = -5;
				maxElev = 30;
				weapons[] = {"KPVT","PKT_veh"};
				magazines[] = {"ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "23/120";
					minFov = "23/120";
					maxFov = "23/120";
					visionMode[] = {"Normal"};
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
						initFov = "23/120";
						minFov = "23/120";
						maxFov = "23/120";
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61";
						gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera2"};
					};
					class Narrow: Wide
					{
						initFov = 0.128;
						minFov = 0.128;
						maxFov = 0.128;
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61_narrow";
					};
				};
			};
		};
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "FakeWeapon";
			};
		};
		ace_sys_nvg_nvrange = 290;
	};
	class BRDM2_INS: BRDM2_Base
	{
		accuracy = 0.5;
	};
	class BRDM2_CDF: BRDM2_Base
	{
		accuracy = 0.5;
	};
	class BRDM2_Gue: BRDM2_Base
	{
		accuracy = 0.5;
	};
	class BRDM2_TK_EP1: BRDM2_Base
	{
		accuracy = 0.7;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61";
				class ViewOptics: ViewOptics
				{
					initFov = "23/120";
					minFov = "23/120";
					maxFov = "23/120";
					visionMode[] = {"Normal"};
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
						initFov = "23/120";
						minFov = "23/120";
						maxFov = "23/120";
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61";
						gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera2"};
					};
					class Narrow: Wide
					{
						initFov = 0.128;
						minFov = 0.128;
						maxFov = 0.128;
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61_narrow";
					};
				};
			};
		};
	};
	class BRDM2_TK_GUE_EP1: BRDM2_Base
	{
		accuracy = 0.7;
	};
	class BRDM2_ATGM_Base: BRDM2_Base
	{
		accuracy = 0.42;
		displayName = "$STR_ACE_VDN_BRDM2_ATGM_BASE";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initFov = "0.33333/ 2.6";
					minFov = "0.33333/ 2.6";
					maxFov = "0.33333/ 2.6";
				};
				weapons[] = {"AT5Launcher"};
				magazines[] = {"5Rnd_AT5_BRDM2","5Rnd_AT5_BRDM2"};
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
						initFov = "0.33333/ 2.6";
						minFov = "0.33333/ 2.6";
						maxFov = "0.33333/ 2.6";
						visionMode[] = {"Normal","NVG"};
						gunneropticsmodel = "\ca\weapons\2Dscope_ATGM";
						gunnerOpticsEffect[] = {"TankGunnerOptics1","OpticsBlur2","OpticsCHAbera2"};
					};
				};
				ace_sys_nvg_nvrange = 1350;
			};
		};
	};
	class BRDM2_ATGM_INS: BRDM2_ATGM_Base
	{
		accuracy = 0.5;
	};
	class BRDM2_ATGM_CDF: BRDM2_ATGM_Base
	{
		accuracy = 0.5;
	};
	class BRDM2_ATGM_TK_EP1: BRDM2_ATGM_Base
	{
		accuracy = 0.72;
	};
	class BRDM2_HQ_Base: BRDM2_Base
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_BRDM2_HQ_BASE";
	};
	class BRDM2_HQ_Gue: BRDM2_HQ_Base
	{
		accuracy = 0.5;
	};
	class BTR60_TK_EP1: BRDM2_Base
	{
		displayName = "BTR-60BP";
		maxSpeed = 77;
		fuelCapacity = 290;
		threat[] = {1,0.3,0.6};
		radarType = 0;
		class ViewOptics
		{
			initFov = "0.33333+ 0.41667";
			minFov = 0.33333;
			maxFov = "0.33333+ 0.41667";
		};
		class ViewPilot
		{
			initFov = "0.33333+ 0.41667";
			minFov = 0.33333;
			maxFov = "0.33333+ 0.41667";
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"KPVT","PKT_veh"};
				magazines[] = {"ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				radarType = 4;
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61";
				minElev = -5;
				maxElev = 30;
				initElev = 0;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "23/120";
					minFov = "23/120";
					maxFov = "23/120";
					visionMode[] = {"Normal"};
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
						initFov = "23/120";
						minFov = "23/120";
						maxFov = "23/120";
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61";
					};
					class Narrow: Wide
					{
						initFov = 0.128;
						minFov = 0.128;
						maxFov = 0.128;
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61_narrow";
					};
				};
				stabilizedInAxes = 0;
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.3;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
			};
			class CommanderTurret: MainTurret
			{
				radarType = 4;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
					visionMode[] = {"Normal","NVG"};
				};
				class OpticsIn
				{
					class Day
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "10/120";
						minFov = "10/120";
						maxFov = "10/120";
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72_TKN3_day_optics";
						gunnerOutOpticsModel = "";
						gunnerOutOpticsEffect[] = {};
					};
					class Night: Day
					{
						initFov = "(10/120) * (5/4.2)";
						minFov = "(10/120) * (5/4.2)";
						maxFov = "(10/120) * (5/4.2)";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72_TKN3_night_optics";
						visionMode[] = {"NVG"};
					};
				};
				startEngine = 0;
				stabilizedInAxes = 0;
				ace_sys_nvg_nvrange = 420;
			};
		};
	};
	class BTR40_MG_base_EP1: Wheeled_APC
	{
		armor = 40;
		displayName = "$STR_ACE_VDN_BTR40_ARMED";
		accuracy = 0.4;
		maxSpeed = 70;
		gunnerOpticsShowCursor = 0;
		fuelCapacity = 122;
		threat[] = {0.8,0.1,0.6};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"DShKM"};
				stabilizedInAxes = 0;
				magazines[] = {"50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM"};
				minElev = -18;
				maxElev = 60;
				minTurn = -60;
				maxTurn = 60;
				initTurn = 0;
			};
		};
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = 60;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = 51;
				name = "palivo";
				passThrough = 0;
			};
		};
	};
	class BTR40_base_EP1: BTR40_MG_base_EP1
	{
		displayName = "$STR_ACE_VDN_BTR40";
		accuracy = 0.4;
	};
	class BTR40_MG_TK_GUE_EP1: BTR40_MG_base_EP1
	{
		displayName = "$STR_ACE_VDN_BTR40_DSHKM";
		accuracy = 0.5;
	};
	class BTR40_TK_GUE_EP1: BTR40_base_EP1
	{
		accuracy = 0.5;
	};
	class BTR40_MG_TK_INS_EP1: BTR40_MG_base_EP1
	{
		displayName = "$STR_ACE_VDN_BTR40_DSHKM";
		accuracy = 0.5;
	};
	class BTR40_TK_INS_EP1: BTR40_base_EP1
	{
		accuracy = 0.5;
	};
	class GAZ_Vodnik_HMG: Wheeled_APC
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_GAZ_VODNIK_HMG";
		displayNameShort = "$STR_ACE_VDNS_GAZ_VODNIK_HMG";
		maxSpeed = 119;
		fuelCapacity = 144;
		threat[] = {1,0.3,0.7};
		armor = 40;
		armorStructural = 3;
		driverForceOptics = 0;
		forceHideDriver = 1;
		smokelauncherangle = 70;
		smokelaunchergrenadecount = 3;
		smokelauncheronturret = 1;
		smokelaunchervelocity = 14;
		irScanRangeMax = 1500;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				weapons[] = {"ACE_2A42","PKT_veh","SmokeLauncher"};
				magazines[] = {"150Rnd_30mmHE_2A42","150Rnd_30mmAP_2A42","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","SmokeLauncherMag","SmokeLauncherMag"};
				minElev = -5;
				maxElev = 70;
				stabilizedInAxes = 3;
				gunnerForceOptics = 1;
				forceHideGunner = 1;
				inGunnerMayFire = 1;
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optics_empty";
				gunnerOpticsEffect[] = {};
				startEngine = 0;
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
						initFov = "0.33333/ 2.6";
						minFov = "0.33333/ 2.6";
						maxFov = "0.33333/ 2.6";
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optics_empty";
					};
					class Medium: Wide
					{
						initFov = "0.33333/ 4";
						minFov = "0.33333/ 4";
						maxFov = "0.33333/ 4";
					};
					class Narrow: Wide
					{
						initFov = "0.33333/ 5.5";
						minFov = "0.33333/ 5.5";
						maxFov = "0.33333/ 5.5";
						visionMode[] = {"NVG"};
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.3;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				ace_sys_nvg_nvrange = 1350;
			};
		};
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0;
			};
		};
	};
	class GAZ_Vodnik: GAZ_Vodnik_HMG
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_GAZ_VODNIK";
		irScanRangeMax = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_PKT_out"};
				magazines[] = {"100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK","100Rnd_762x54_PK"};
				class OpticsIn
				{
					class Normal
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.7;
						minFov = 0.25;
						maxFov = 1.1;
						gunnerOpticsModel = "\ca\weapons\optika_empty";
						visionMode[] = {};
					};
				};
			};
			class BackTurret: MainTurret
			{
				weapons[] = {"ACE_PKT_out_2"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_PKT_out";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_PKT_out";
			};
			class ReloadAnim_2
			{
				source = "reload";
				weapon = "ACE_PKT_out_2";
			};
			class ReloadMagazine_2
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out_2";
			};
			class Revolving_2
			{
				source = "revolving";
				weapon = "ACE_PKT_out_2";
			};
		};
	};
	class GAZ_Vodnik_MedEvac: GAZ_Vodnik
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_GAZ_VODNIK_MEDEVAC";
		displayNameShort = "$STR_ACE_VDN_GAZ_VODNIK_MEDEVAC";
	};
	class BTR90_Base: Wheeled_APC
	{
		maxSpeed = 116;
		fuelCapacity = 420;
		displayName = "$STR_ACE_VDN_BTR90";
		threat[] = {1,0.7,0.7};
		armor = 200;
		armorStructural = 3.25;
		damageResistance = 0.02432;
		driverForceOptics = 0;
		driverOpticsModel = "\x\ace\addons\m_veh_optics\driver\optika_tank_driver.p3d";
		forceHideDriver = 0;
		irScanRangeMax = 3000;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1;
				material = -1;
				name = "palivo";
				passThrough = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_2A42","PKT","ACE_AT5B_Launcher","AGS17"};
				magazines[] = {"250Rnd_30mmAP_2A42","250Rnd_30mmHE_2A42","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","ACE_AT5B","400Rnd_30mm_AGS17"};
				minElev = -5;
				maxElev = 75;
				stabilizedInAxes = 3;
				gunnerForceOptics = 0;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				startEngine = 0;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 4.75";
					minFov = "0.33333/ 4.75";
					maxFov = "0.33333/ 4.75";
				};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 70;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
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
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optics_empty";
						initFov = 0.071;
						minFov = 0.071;
						maxFov = 0.071;
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
					};
				};
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.3;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				ace_sys_nvg_nvrange = 1350;
				ace_sys_nvg_tirange = 5000;
				class Turrets
				{
					class CommanderOptics: NewTurret
					{
						stabilizedInAxes = 3;
						commanderForceOptics = 0;
						forceHideCommander = 0;
						outGunnerMayFire = 1;
						inGunnerMayFire = 1;
						startEngine = 0;
						weapons[] = {"SmokeLauncher"};
						magazines[] = {"SmokeLauncherMag","SmokeLauncherMag"};
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
								initFov = "0.33333/ 1";
								minFov = "0.33333/ 1";
								maxFov = "0.33333/ 1";
								visionMode[] = {"Normal"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
							};
							class Medium: Wide
							{
								initFov = "0.33333/ 2";
								minFov = "0.33333/ 2";
								maxFov = "0.33333/ 2";
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
							};
							class Narrow: Wide
							{
								initFov = "0.33333/ 4";
								minFov = "0.33333/ 4";
								maxFov = "0.33333/ 4";
								visionMode[] = {"Normal","NVG"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
							};
						};
						class ViewOptics
						{
							initFov = "0.33333/ 1";
							minFov = "0.33333/ 4";
							maxFov = "0.33333/ 1";
							visionMode[] = {"Normal","NVG"};
						};
						ace_sys_nvg_nvrange = 570;
					};
				};
			};
		};
	};
	class BTR90_HQ: BTR90_Base
	{
		accuracy = 0.45;
		displayName = "$STR_ACE_VDN_BTR90_HQ";
	};
	class BMP2_Base: Tracked_APC
	{
		displayName = "$STR_ACE_VDN_BMP2_BASE";
		accuracy = 0.4;
		armor = 140;
		damageResistance = 0.01796;
		armorStructural = 3;
		fuelCapacity = 460;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0;
			};
			class HitHull
			{
				armor = 0.3;
				material = -1;
				name = "NEtelo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 2;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 2;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		maxSpeed = 55;
		cost = 1500000;
		threat[] = {0.9,0.9,0.7};
		driverForceOptics = 0;
		forceHideDriver = 0;
		irScanRangeMax = 1500;
		radarType = 0;
		driverCompartments = 0;
		cargoCompartments[] = {2,2,2,2,2,2,2};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				maxHorizontalRotSpeed = 0.61;
				maxVerticalRotSpeed = 0.104;
				weapons[] = {"ACE_2A42","PKT_veh","AT5LauncherSingle"};
				magazines[] = {"250Rnd_30mmAP_2A42","250Rnd_30mmHE_2A42","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","ACE_AT5"};
				minElev = -5;
				maxElev = 74;
				startEngine = 0;
				stabilizedInAxes = 3;
				gunnerForceOptics = 1;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				lockWhenDriverOut = 0;
				class ViewOptics: ViewOptics
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
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 70;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
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
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optics_empty";
						initFov = 0.071;
						minFov = 0.071;
						maxFov = 0.071;
						visionMode[] = {"Normal","NVG"};
					};
				};
				ace_sys_nvg_nvrange = 1350;
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerCompartments = 1;
						commanderForceOptics = 1;
						forceHideCommander = 0;
						inGunnerMayFire = 1;
						weapons[] = {"SmokeLauncher"};
						magazines[] = {"SmokeLauncherMag","SmokeLauncherMag"};
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
								initFov = "0.33333/ 1";
								minFov = "0.33333/ 1";
								maxFov = "0.33333/ 1";
								visionMode[] = {"Normal"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
							};
							class Medium: Wide
							{
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
								initFov = "0.33333/ 2";
								minFov = "0.33333/ 2";
								maxFov = "0.33333/ 2";
							};
							class Narrow: Wide
							{
								initFov = "0.33333/ 4";
								minFov = "0.33333/ 4";
								maxFov = "0.33333/ 4";
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
								visionMode[] = {"Normal","NVG"};
							};
						};
						class ViewOptics: ViewOptics
						{
							initFov = "0.33333/ 1";
							minFov = "0.33333/ 4";
							maxFov = "0.33333/ 1";
							visionMode[] = {"Normal","NVG"};
						};
						ace_sys_nvg_nvrange = 570;
					};
				};
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.3;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
			};
		};
		ace_sys_nvg_nvrange = 290;
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0;
			};
		};
	};
	class BMP2_INS: BMP2_Base
	{
		accuracy = 0.5;
	};
	class BMP2_CDF: BMP2_Base
	{
		displayName = "$STR_ACE_VDN_BMP2_CDF";
		accuracy = 0.5;
	};
	class BMP2_Gue: BMP2_Base
	{
		accuracy = 0.5;
	};
	class BMP2_HQ_Base: BMP2_Base
	{
		displayName = "$STR_ACE_VDN_BMP2_HQ_BASE";
		accuracy = 0.42;
	};
	class BMP2_HQ_TK_EP1: BMP2_HQ_Base
	{
		radarType = 0;
	};
	class BMP2_HQ_INS: BMP2_HQ_Base
	{
		accuracy = 0.5;
	};
	class BMP2_HQ_CDF: BMP2_HQ_Base
	{
		displayName = "$STR_ACE_VDN_BMP2_HQ_CDF";
		accuracy = 0.5;
	};
	class BMP2_Ambul_Base: BMP2_Base
	{
		displayName = "$STR_ACE_VDN_BMP2_AMBUL_BASE";
		displayNameShort = "$STR_ACE_VDN_BMP2_AMBUL_BASE";
		accuracy = 0.45;
	};
	class BMP2_Ambul_INS: BMP2_Ambul_Base
	{
		accuracy = 0.5;
	};
	class BMP2_Ambul_CDF: BMP2_Ambul_Base
	{
		displayName = "$STR_ACE_VDN_BMP2_AMBUL_CDF";
		displayNameShort = "$STR_ACE_VDN_BMP2_AMBUL_CDF";
		accuracy = 0.5;
	};
	class BMP2_UN_EP1: BMP2_Base{};
	class BMP2_TK_EP1: BMP2_Base{};
	class BMP3: Tracked_APC
	{
		displayName = "$STR_ACE_VDN_BMP3";
		accuracy = 0.4;
		armor = 240;
		damageResistance = 0.01403;
		cost = 1500000;
		threat[] = {1,0.5,0.1};
		armorStructural = 3.25;
		fuelCapacity = 460;
		irScanRangeMax = 3000;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 0;
			};
			class HitHull
			{
				armor = 0.33;
				material = -1;
				name = "NEtelo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 2;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 2;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		maxSpeed = 63;
		driverForceOptics = 0;
		driverOpticsModel = "\x\ace\addons\m_veh_optics\driver\optika_tank_driver.p3d";
		forceHideDriver = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_2A70","ACE_2A72","PKT"};
				magazines[] = {"8Rnd_AT10_BMP3","250Rnd_30mmAP_2A72","250Rnd_30mmHE_2A72","22Rnd_100mm_HE_2A70","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				minElev = -6;
				maxElev = 60;
				initElev = 0;
				startEngine = 0;
				stabilizedInAxes = 3;
				gunnerForceOptics = 0;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				lockWhenDriverOut = 0;
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
						initFov = "0.33333/ 2.6";
						minFov = "0.33333/ 2.6";
						maxFov = "0.33333/ 2.6";
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\ca\weapons\2Dscope_BMP3gun";
					};
					class Medium: Wide
					{
						initFov = "0.33333/ 8";
						minFov = "0.33333/ 8";
						maxFov = "0.33333/ 8";
					};
					class Narrow: Wide
					{
						initFov = "0.33333/ 5.5";
						minFov = "0.33333/ 5.5";
						maxFov = "0.33333/ 5.5";
						visionMode[] = {"NVG"};
					};
				};
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.35;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				ace_sys_nvg_nvrange = 1350;
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						weapons[] = {"SmokeLauncher"};
						magazines[] = {"SmokeLauncherMag","SmokeLauncherMag"};
						minTurn = -360;
						maxTurn = 360;
						initTurn = 0;
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
								initFov = "0.33333/ 1.2";
								minFov = "0.33333/ 1.2";
								maxFov = "0.33333/ 1.2";
								visionMode[] = {"Normal","NVG"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
							};
							class Medium: Wide
							{
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
								initFov = "0.33333/ 4";
								minFov = "0.33333/ 4";
								maxFov = "0.33333/ 4";
							};
						};
						stabilizedInAxes = 3;
						commanderForceOptics = 0;
						forceHideCommander = 0;
						outGunnerMayFire = 1;
						inGunnerMayFire = 1;
						startEngine = 0;
						ace_sys_nvg_nvrange = 720;
					};
				};
			};
			class LeftTurret: NewTurret
			{
				ace_sys_nvg_nvrange = 420;
				weapons[] = {"ACE_PKT_out"};
			};
			class RightTurret: LeftTurret
			{
				ace_sys_nvg_nvrange = 420;
				weapons[] = {"ACE_PKT_out_2"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_2A70";
			};
		};
	};
	class AAV: Tracked_APC
	{
		vehicleclass = "ArmouredW";
		displayName = "AAVP7A1";
		accuracy = 0.4;
		threat[] = {1,0.3,0.3};
		armor = 120;
		damageResistance = 0.01168;
		maxSpeed = 62;
		armorStructural = 3;
		fuelCapacity = 647;
		driverOpticsModel = "\x\ace\addons\m_veh_optics\driver\optika_tank_driver_west.p3d";
		driverForceOptics = 0;
		forceHideDriver = 0;
		irScanRangeMax = 1500;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.3;
				material = -1;
				name = "NEtelo";
				visual = "telo";
				passThrough = 1;
			};
			class HitLTrack
			{
				armor = 2;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 1;
			};
			class HitRTrack
			{
				armor = 2;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 1;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev = -15;
				maxElev = 60;
				maxHorizontalRotSpeed = 1.05;
				stabilizedInAxes = 1;
				gunnerForceOptics = 1;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				startEngine = 0;
				lockWhenDriverOut = 0;
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.3;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 1;
					};
				};
				weapons[] = {"MK19","M2"};
				magazines[] = {"48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
			};
			class CommanderOptics: NewTurret
			{
				startEngine = 0;
				commanderForceOptics = 0;
				forceHideCommander = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
			};
		};
	};
	class M2A2_Base: Tank
	{
		vehicleclass = "ArmouredD";
		displayName = "M2 Bradley";
		accuracy = 0.4;
		maxSpeed = 51;
		transportSoldier = 6;
		fuelCapacity = 662;
		irScanRangeMax = 3000;
		irScanRangeMin = 500;
		radarType = 0;
		irTarget = 1;
		laserScanner = 0;
		enableGPS = 1;
		canFloat = 0;
		LockDetectionSystem = 4;
		IncommingMisslieDetectionSystem = 16;
		commanderCanSee = "2+4+8+16";
		gunnerCanSee = "4+8+16";
		driverCanSee = "2+8+16";
		threat[] = {0.9,0.9,0.7};
		class AnimationSources;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				startEngine = 0;
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				minElev = -9;
				maxElev = 57;
				weapons[] = {"ACE_M242_200","M240_veh","TOWLauncher"};
				magazines[] = {"2Rnd_TOW2","2Rnd_TOW2","2Rnd_TOW2","2Rnd_TOW2","2Rnd_TOW2","ACE_1100Rnd_762x51_M240","ACE_1100Rnd_762x51_M240","ACE_230Rnd_25mm_M242_HEI","ACE_230Rnd_25mm_M242_HEI","ACE_230Rnd_25mm_M242_HEI","ACE_70Rnd_25mm_M242_APFSDS","ACE_70Rnd_25mm_M242_APFSDS","ACE_70Rnd_25mm_M242_APFSDS"};
				radarType = 4;
				maxVerticalRotSpeed = 1.04;
				maxHorizontalRotSpeed = 1.04;
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
						gunnerOpticsModel = "\ca\tracked_e\gunnerOptics_M2A2";
						initFov = "0.33333/ 4";
						minFov = "0.33333/ 4";
						maxFov = "0.33333/ 4";
						visionMode[] = {"Normal","Ti"};
						thermalMode[] = {2,3};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel = "\ca\tracked_e\gunnerOptics_M2A2";
						initFov = "0.33333/ 12";
						minFov = "0.33333/ 12";
						maxFov = "0.33333/ 12";
					};
				};
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						startEngine = 0;
						radarType = 4;
						turretInfoType = "RscWeaponEmpty";
						stabilizedinaxes = 2;
						lockwhendriverout = 1;
						minElev = -4;
						maxElev = 20;
						initElev = 0;
						minTurn = -360;
						maxTurn = 360;
						initTurn = 0;
						weapons[] = {"SmokeLauncher"};
						magazines[] = {"SmokeLauncherMag","SmokeLauncherMag"};
						class ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333/ 3";
							minFov = "0.33333/ 3";
							maxFov = "0.33333/ 3";
						};
						class OpticsOut
						{
							class Monocular
							{
								gunneropticsmodel = "";
								initanglex = 0;
								initangley = 0;
								initfov = "0.33333+ 0.41667";
								maxanglex = 60;
								maxangley = 120;
								maxfov = "0.33333+ 0.41667";
								minanglex = -30;
								minangley = -120;
								minfov = "0.33333/ 1";
								visionmode[] = {"Normal","NVG"};
							};
						};
						gunnerHasFlares = 1;
					};
				};
			};
		};
	};
	class M2A2_EP1: M2A2_Base
	{
		displayName = "M2A2 Bradley";
		armor = 240;
		accuracy = 0.7;
		hiddenselectionstextures[] = {"\ca\tracked_e\m2a2_bradley\data\base_co.paa","\ca\tracked_e\m2a2_bradley\data\a3_co.paa","\ca\tracked_e\m2a2_bradley\data\ultralp_co.paa","","\ca\tracked_e\m2a2_bradley\data\base_co.paa"};
		class AnimationSources
		{
			class recoil_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0;
			};
		};
	};
	class M2A3_EP1: M2A2_EP1
	{
		displayName = "M2A3 Bradley";
		armor = 260;
		accuracy = 0.7;
		class AnimationSources
		{
			class recoil_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						stabilizedInAxes = 3;
						lockwhendriverout = 1;
						class ViewOptics: ViewOptics
						{
							initFov = "0.33333/ 7";
							minFov = "0.33333/ 7";
							maxFov = "0.33333/ 7";
							visionMode[] = {"Normal","NVG","Ti"};
							thermalMode[] = {4,5};
						};
					};
				};
			};
		};
	};
	class M6_EP1: M2A2_Base
	{
		displayName = "M6 Linebacker";
		armor = 240;
		accuracy = 0.7;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M242_200","M240_veh","ACE_StingerLauncher_four"};
				magazines[] = {"ACE_4Rnd_Stinger","ACE_4Rnd_Stinger","ACE_1100Rnd_762x51_M240","ACE_1100Rnd_762x51_M240","ACE_230Rnd_25mm_M242_HEI","ACE_230Rnd_25mm_M242_HEI","ACE_230Rnd_25mm_M242_HEI","ACE_70Rnd_25mm_M242_APFSDS","ACE_70Rnd_25mm_M242_APFSDS","ACE_70Rnd_25mm_M242_APFSDS"};
			};
		};
		hiddenselections[] = {"camo1","camo2","camo3","selection_stinger","selection_tow"};
		hiddenselectionstextures[] = {"\ca\tracked_e\m2a2_bradley\data\base_co.paa","\ca\tracked_e\m2a2_bradley\data\a3_co.paa","\ca\tracked_e\m2a2_bradley\data\ultralp_co.paa","\ca\tracked_e\m2a2_bradley\data\base_co.paa",""};
		class AnimationSources: AnimationSources
		{
			class recoil_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0;
			};
		};
		threat[] = {0.9,0.3,1};
	};
	class M113_Base: Tank
	{
		crewVulnerable = 0;
		viewDriverInExternal = 1;
		displayName = "M113A3";
		accuracy = 0.4;
		armor = 109;
		cost = 100000;
		maxSpeed = 56;
		transportSoldier = 11;
		fuelCapacity = 360;
		gunnerHasFlares = 0;
		radarType = 0;
		weapons[] = {"SmokeLauncher"};
		magazines[] = {"SmokeLauncherMag"};
		smokeLauncherOnTurret = 0;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 2;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0;
			};
			class HitHull
			{
				armor = 0.3;
				material = -1;
				name = "NEtelo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 2;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 2;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		driverCompartments = 0;
		cargoCompartments[] = {1,1,1,1,1,1,1,1,1,1,1};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class HitPoints: HitPoints
				{
					class HitTurret
					{
						armor = 0.3;
						material = -1;
						name = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						passThrough = 0;
					};
				};
				maxVerticalRotSpeed = 1.04;
				maxHorizontalRotSpeed = 1.04;
				minElev = -10;
				maxElev = 65;
				initElev = 0;
				weapons[] = {"M2"};
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
			};
		};
		canFloat = 1;
		threat[] = {0.9,0.1,0.5};
	};
	class M113Ambul_Base: M113_Base
	{
		displayName = "M113A3 (MEDEVAC)";
		accuracy = 0.45;
	};
	class M113Ambul_UN_EP1: M113Ambul_Base
	{
		accuracy = 0.5;
	};
	class M113_UN_EP1: M113_Base
	{
		accuracy = 0.5;
	};
	class M113Ambul_TK_EP1: M113Ambul_Base
	{
		accuracy = 0.5;
	};
	class M113_TK_EP1: M113_Base
	{
		accuracy = 0.5;
	};
	class BAF_FV510_D: Tank
	{
		accuracy = 0.5;
		driverCompartments = 0;
		cargoCompartments[] = {2,2,2,2,2,2,2};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				radarType = 4;
				weapons[] = {"ACE_CTWS","BAF_L94A1"};
				maxVerticalRotSpeed = 1.04;
				maxHorizontalRotSpeed = 1.04;
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
						gunnerOpticsModel = "\ca\tracked_d_baf\gunnerOptics_FW510_2.p3d";
						initFov = "0.33333/ 4";
						minFov = "0.33333/ 4";
						maxFov = "0.33333/ 4";
						visionMode[] = {"Normal","Ti"};
						thermalMode[] = {2,3};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel = "\ca\tracked_d_baf\gunnerOptics_FW510.p3d";
						initFov = "0.33333/ 12";
						minFov = "0.33333/ 12";
						maxFov = "0.33333/ 12";
					};
				};
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						radarType = 4;
						turretInfoType = "RscWeaponEmpty";
						lockwhendriverout = 1;
						class ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333/ 3";
							minFov = "0.33333/ 3";
							maxFov = "0.33333/ 3";
							thermalMode[] = {4,5};
						};
						class OpticsOut
						{
							class Monocular
							{
								gunneropticsmodel = "";
								initanglex = 0;
								initangley = 0;
								initfov = "0.33333+ 0.41667";
								maxanglex = 60;
								maxangley = 120;
								maxfov = "0.33333+ 0.41667";
								minanglex = -30;
								minangley = -120;
								minfov = "0.33333/ 1";
								visionmode[] = {"Normal","NVG"};
							};
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_CTWS";
			};
		};
	};
	class M1A1: Tank
	{
		displayName = "M1A1";
		vehicleclass = "ArmouredW";
		accuracy = 0.4;
		armor = 1320;
		armorStructural = 5;
		damageResistance = 0.00377;
		cost = 4000000;
		driverForceOptics = 1;
		driverOutOpticsModel = "";
		forceHideDriver = 0;
		fuelCapacity = 1909;
		acceleration = 1.2;
		brakeDistance = 35;
		irScanRangeMax = 4000;
		radarType = 0;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.8;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.26;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.26;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		maxSpeed = 62;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				startengine = 0;
				stabilizedInAxes = 3;
				gunnerForceOptics = 1;
				forceHideGunner = 1;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				weapons[] = {"ACE_M256","M240_veh"};
				magazines[] = {"ACE_25Rnd_120mmSABOT_M1A2","ACE_15Rnd_120mmHE_M1A2","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240"};
				minElev = -10;
				maxElev = 22;
				maxHorizontalRotSpeed = 0.7;
				maxVerticalRotSpeed = 0.44;
				class ViewOptics
				{
					initFov = "0.33333/ 3";
					minFov = "0.33333/ 10";
					maxFov = "0.33333/ 3";
				};
				class OpticsIn
				{
					class Wide
					{
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner_3x.p3d";
						visionMode[] = {"Normal","Ti"};
						thermalMode[] = {2,3};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner_10x.p3d";
						initFov = "0.33333/ 10";
						minFov = "0.33333/ 10";
						maxFov = "0.33333/ 10";
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				class Turrets: Turrets
				{
					discreteDistanceInitIndex = 0;
					discreteDistance[] = {};
					turretInfoType = "RscWeaponEmpty";
					class CommanderOptics: CommanderOptics
					{
						minElev = -10;
						maxElev = 60;
						maxVerticalRotSpeed = 0.06;
						startengine = 0;
						stabilizedInAxes = 3;
						commanderForceOptics = 1;
						forceHideCommander = 0;
						outGunnerMayFire = 1;
						inGunnerMayFire = 1;
						lockWhenDriverOut = 0;
						discreteDistanceInitIndex = 0;
						discreteDistance[] = {};
						turretInfoType = "RscWeaponEmpty";
						weapons[] = {"M2","SmokeLauncher"};
						magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","SmokeLauncherMag","SmokeLauncherMag"};
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
								initFov = "0.33333/ 1";
								minFov = "0.33333/ 1";
								maxFov = "0.33333/ 1";
								gunnerOpticsModel = "\ca\Tracked\optika_M1A1_commander";
								gunnerOutOpticsModel = "\ca\weapons\empty";
								gunnerOutOpticsEffect[] = {};
								visionMode[] = {"Normal","NVG"};
							};
							class Narrow: Wide
							{
								gunnerOpticsModel = "\ca\Tracked\optika_M1A1_commander";
								initFov = "0.33333/ 3";
								minFov = "0.33333/ 3";
								maxFov = "0.33333/ 3";
							};
						};
						class OpticsOut
						{
							class Monocular
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
								visionMode[] = {"Normal","NVG"};
								gunnerOpticsModel = "";
							};
						};
					};
				};
			};
		};
		threat[] = {1,1,0.3};
		class Library
		{
			libTextDesc = "The M1A1, famous for its role in the Gulf Wars, is the United States’ primary Main Battle Tank. The M1A1 features an M256 smoothbore cannon capable of firing an armor-piercing fin-stabilized discarding sabot (APFSDS) round with a depleted uranium penetrator. Various other types of ammunition, such as High Explosive Anti-Tank (HEAT), are also available and can be employed to engage lighter armored vehicles. The M1A1 is a fast, well armored and deadly piece of equipment. The USMC uses the M1A1 as 'Heavy Common' version with wich is an overall upgraded M1A1";
		};
		class AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_M256";
			};
		};
	};
	class M1A1_base: M1A1{};
	class M1A1_US_DES_EP1: M1A1_base
	{
		vehicleclass = "ArmouredD";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						maxVerticalRotSpeed = 0.06;
					};
				};
			};
		};
	};
	class M1A2_TUSK_MG: M1A1
	{
		vehicleclass = "ArmouredW";
		displayName = "M1A2 TUSK";
		forceHideDriver = 0;
		driverAction = "Abrams_DriverOut";
		driverOutOpticsModel = "";
		irScanRangeMax = 6000;
		maxSpeed = 65;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.8;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.46;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.46;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		armor = 1620;
		armorStructural = 5.75;
		damageResistance = 0.00516;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				weapons[] = {"ACE_M256","M240_veh"};
				magazines[] = {"ACE_30Rnd_120mmSABOT_M1A2","ACE_8Rnd_120mmHE_M1A2","ACE_4Rnd_M1028","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240"};
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
						initFov = "0.33333/ 3";
						minFov = "0.33333/ 3";
						maxFov = "0.33333/ 3";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner_3x.p3d";
						visionMode[] = {"Normal","Ti"};
						thermalMode[] = {0,1};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner_10x.p3d";
						initFov = "0.33333/ 10";
						minFov = "0.33333/ 10";
						maxFov = "0.33333/ 10";
					};
					class ace_extra: Wide
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner_10x.p3d";
						initFov = "0.33333/ 25";
						minFov = "0.33333/ 25";
						maxFov = "0.33333/ 25";
					};
				};
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						discreteDistanceInitIndex = 0;
						discreteDistance[] = {};
						turretInfoType = "RscWeaponEmpty";
						LODTurnedIn = 1;
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
								initFov = "0.33333/ 0.5";
								minFov = "0.33333/ 0.5";
								maxFov = "0.33333/ 0.5";
								gunnerOpticsModel = "\ca\Weapons\2Dscope_RWS";
								visionMode[] = {"Normal"};
							};
							class Medium: Wide
							{
								initFov = "0.33333/ 3";
								minFov = "0.33333/ 3";
								maxFov = "0.33333/ 3";
							};
							class Narrow: Wide
							{
								initFov = "0.33333/ 8.5";
								minFov = "0.33333/ 8.5";
								maxFov = "0.33333/ 8.5";
							};
							class ace_crows_ti_wide: Wide
							{
								initFov = "0.33333/ 3";
								minFov = "0.33333/ 3";
								maxFov = "0.33333/ 3";
								visionMode[] = {"Ti"};
								thermalMode[] = {0,1};
							};
							class ace_crows_ti_narrow: ace_crows_ti_wide
							{
								initFov = "0.33333/ 9";
								minFov = "0.33333/ 9";
								maxFov = "0.33333/ 9";
							};
						};
						class ViewOptics: ViewOptics
						{
							initFov = "0.33333/ 2.6";
							minFov = "0.33333/ 7.7";
							maxFov = "0.33333/ 2.6";
						};
					};
					class LoaderTurret: NewTurret
					{
						ACE_exposed = 0;
						canHideGunner = 1;
						inGunnerMayfire = 0;
						primaryGunner = 0;
						gunnerGetInAction = "GetInMedium";
						gunnerGetOutAction = "GetOutMedium";
						gunnerFireAlsoInInternalCamera = 0;
						gunnerForceOptics = 1;
						gunnerOpticsColor[] = {1,1,1,1};
						gunnerOpticsModel = "CA\Tracked_E\driverOptics";
						memoryPointGunnerOptics = "loader_turret";
						initElev = -10;
						initTurn = 145;
						maxElev = 60;
						turretInfoType = "RscWeaponEmpty";
						weapons[] = {"ACE_M240_veh_out"};
						magazines[] = {"100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240","100Rnd_762x51_M240"};
						class Turrets{};
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
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333+ 0.41667";
							minFov = 0.33333;
							maxFov = "0.33333+ 0.41667";
						};
					};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim_2
			{
				source = "reload";
				weapon = "ACE_M240_veh_out";
			};
			class ReloadMagazine_2
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_veh_out";
			};
			class Revolving_2
			{
				source = "revolving";
				weapon = "ACE_M240_veh_out";
			};
		};
	};
	class M1A2_TUSK_MG_base: M1A2_TUSK_MG{};
	class M1A2_US_TUSK_MG_EP1: M1A2_TUSK_MG_base
	{
		vehicleclass = "ArmouredD";
		displayName = "M1A2 TUSK";
	};
	class MLRS: Tank
	{
		vehicleclass = "ArmouredW";
		driverOpticsModel = "\x\ace\addons\m_veh_optics\driver\optika_tank_driver_west.p3d";
	};
	class MLRS_base;
	class MLRS_DES_EP1: MLRS_base
	{
		vehicleclass = "ArmouredD";
	};
	class T90: Tank
	{
		displayName = "$STR_ACE_VDN_T90";
		model = "\x\ace\addons\m_vehicle\t90\t90";
		fuelCapacity = 1600;
		accuracy = 0.4;
		brakeDistance = 40;
		armor = 1350;
		armorStructural = 5.5;
		damageResistance = 0.00278;
		cost = 4000000;
		driverForceOptics = 1;
		forceHideDriver = 0;
		driverOutOpticsModel = "";
		irScanRangeMax = 6000;
		lockdetectionsystem = 4;
		incommingmissliedetectionsystem = 16;
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		radarType = 0;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.79;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.39;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.39;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		maxSpeed = 55;
		driverCompartments = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				turretInfoType = "RscWeaponEmpty";
				weapons[] = {"ACE_2A46M_1","PKT"};
				selectionFireAnim = "zasleh";
				magazines[] = {"ACE_3BM42M","ACE_3BK29M","ACE_8Rnd_3OF26","5Rnd_AT11_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				minElev = -6;
				maxElev = 14;
				maxHorizontalRotSpeed = 0.61;
				maxVerticalRotSpeed = 0.09;
				startEngine = 0;
				stabilizedInAxes = 3;
				gunnerForceOptics = 1;
				gunnerOutOpticsModel = "";
				gunnerOutOpticsEffect[] = {};
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				lockWhenDriverOut = 0;
				class ViewOptics
				{
					initFov = "0.33333/ 2.7";
					minFov = "0.33333/ 12";
					maxFov = "0.33333/ 2.7";
					visionMode[] = {"Normal","NVG"};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				ace_sys_nvg_nvrange = 2500;
				ace_sys_nvg_tirange = 10000;
				class Turrets: Turrets
				{
					class CommanderOptics: NewTurret
					{
						gunnerCompartments = 1;
						weapons[] = {"KORD","SmokeLauncher"};
						magazines[] = {"150Rnd_127x108_KORD","150Rnd_127x108_KORD","SmokeLauncherMag","SmokeLauncherMag"};
						commanderForceOptics = 1;
						forceHideCommander = 0;
						outGunnerMayFire = 1;
						inGunnerMayFire = 1;
						startEngine = 0;
						stabilizedInAxes = 3;
						maxVerticalRotSpeed = 0.42;
						maxHorizontalRotSpeed = 0.61;
						minElev = -7;
						maxElev = 80;
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
								initFov = "0.33333/ 1";
								minFov = "0.33333/ 1";
								maxFov = "0.33333/ 1";
								visionMode[] = {"Normal"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_Metis.p3d";
								gunnerOutOpticsModel = "\ca\weapons\empty";
								gunnerOutOpticsEffect[] = {};
							};
							class Medium: Wide
							{
								initFov = "0.33333/ 8";
								minFov = "0.33333/ 8";
								maxFov = "0.33333/ 8";
								gunnerOpticsModel = "\ca\weapons\2Dscope_Metis.p3d";
							};
							class Narrow: Wide
							{
								initFov = "0.33333/ 5.3";
								minFov = "0.33333/ 5.3";
								maxFov = "0.33333/ 5.3";
								visionMode[] = {"NVG"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_Metis.p3d";
							};
						};
						class OpticsOut
						{
							class Monocular
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
								visionMode[] = {"Normal","NVG"};
								gunnerOpticsModel = "";
								gunnerOutOpticsModel = "";
								gunnerOutOpticsEffect[] = {};
							};
						};
						class ViewOptics
						{
							initFov = "0.33333/ 1";
							minFov = "0.33333/ 8";
							maxFov = "0.33333/ 1";
						};
						ace_sys_nvg_nvrange = 1350;
						ace_sys_nvg_tirange = 10000;
					};
				};
			};
		};
		threat[] = {0.9,0.9,0.5};
		class Library
		{
			libTextDesc = "The GPO Uralvagonzavod T-90 is a Russian main battle tank derived from the T-72 and is the most modern tank in the Russian Ground Forces. <br />The T-90's main armament is the 2A46M 125 mm smoothbore anti-tank gun. It also carries the PKT - 7.62 mm coaxial machine gun and the Kord - 12.7 mm anti-aircraft machine gun.";
		};
		ace_sys_nvg_nvrange = 720;
		class AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_2A46M_1";
			};
		};
	};
	class ACE_T90A: T90
	{
		displayName = "T-90A";
		armor = 1480;
		soundlocked[] = {"",1,1};
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.72;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.36;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.36;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 2.7";
					minFov = "0.33333/ 12";
					maxFov = "0.33333/ 2.7";
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {0,1};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
			};
		};
	};
	class T72_Base: Tank
	{
		displayName = "$STR_ACE_VDN_T72_BASE";
		accuracy = 0.4;
		armor = 490;
		fuelCapacity = 1200;
		damageResistance = 0.00544;
		armorStructural = 2.5;
		cost = 4000000;
		irScanRangeMax = 3000;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 1;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.35;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.35;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		aggregateReflectors[] = {{"GunnerLight"},{"LeftLight","RightLight"}};
		class Reflectors
		{
			class LeftLight
			{
				ambient[] = {0.1,0.1,0.1,1};
				brightness = 0.5;
				color[] = {0.9,0.8,0.8,1};
				direction = "konec L svetla";
				hitpoint = "L svetlo";
				position = "L svetlo";
				selection = "L svetlo";
				size = 0.5;
			};
			class RightLight: LeftLight
			{
				direction = "konec P svetla";
				hitpoint = "P svetlo";
				position = "P svetlo";
				selection = "P svetlo";
			};
			class GunnerLight: LeftLight
			{
				ambient[] = {0.01,0.01,0.01,0.001};
				direction = "konec gunner light";
				hitpoint = "gunner light";
				position = "gunner light";
				selection = "gunner light";
			};
		};
		maxSpeed = 50;
		driverForceOptics = 1;
		forceHideDriver = 0;
		threat[] = {0.9,0.9,0.5};
		driverCompartments = 0;
		driverOpticsModel = "CA\Tracked_E\driverOptics";
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				weapons[] = {"ACE_2A46_1","PKT"};
				magazines[] = {"23Rnd_125mmSABOT_T72","22Rnd_125mmHE_T72","ACE_3BK29","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				maxElev = 14;
				minElev = -6;
				maxHorizontalRotSpeed = 0.32;
				maxVerticalRotSpeed = 0.06;
				startEngine = 0;
				stabilizedInAxes = 1;
				gunnerForceOptics = 1;
				gunnerOutOpticsModel = "";
				gunnerOutOpticsEffect[] = {};
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				lockWhenDriverOut = 0;
				gunnerOpticsEffect[] = {};
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
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
						gunnerOutOpticsModel = "";
						gunnerOutOpticsEffect[] = {};
						initFov = "0.33333/ 1";
						minFov = "0.33333/ 1";
						maxFov = "0.33333/ 1";
						gunnerOpticsModel = "CA\Tracked_E\driverOptics";
						visionMode[] = {"Normal"};
					};
					class Narrow: Wide
					{
						initFov = "9/120";
						minFov = "9/120";
						maxFov = "9/120";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72A_TPD249_optics";
						visionMode[] = {"Normal"};
					};
					class Night: Wide
					{
						initFov = "(9/120)*(8/5.5)";
						minFov = "(9/120)*(8/5.5)";
						maxFov = "(9/120)*(8/5.5)";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72A_TPN14923_optics";
						visionMode[] = {"NVG"};
					};
				};
				class ViewOptics
				{
					initFov = "0.33333/ 5.5";
					minFov = "0.33333/ 8";
					maxFov = "0.33333/ 5.5";
				};
				ace_sys_nvg_nvrange = 720;
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerCompartments = 1;
						weapons[] = {"DSHKM","SmokeLauncher"};
						magazines[] = {"150Rnd_127x107_DSHKM","150Rnd_127x107_DSHKM","SmokeLauncherMag","SmokeLauncherMag"};
						minElev = -5;
						maxElev = 45;
						maxVerticalRotSpeed = 0.08;
						class ViewOptics: ViewOptics
						{
							initFov = "0.33333/ 5";
							minFov = "0.33333/ 4.2";
							maxFov = "0.33333/ 5";
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
								gunnerOutOpticsModel = "";
								gunnerOutOpticsEffect[] = {};
								initFov = "0.33333/ 1";
								minFov = "0.33333/ 1";
								maxFov = "0.33333/ 1";
								gunnerOpticsModel = "CA\Tracked_E\driverOptics";
								visionMode[] = {"Normal"};
							};
							class Narrow: Wide
							{
								initFov = "10/120";
								minFov = "10/120";
								maxFov = "10/120";
								visionMode[] = {"Normal"};
								gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72_TKN3_day_optics";
							};
							class Night: Wide
							{
								initFov = "(10/120) * (5/4.2)";
								minFov = "(10/120) * (5/4.2)";
								maxFov = "(10/120) * (5/4.2)";
								gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72_TKN3_night_optics";
								visionMode[] = {"NVG"};
							};
						};
						class OpticsOut
						{
							class Monocular
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
								visionMode[] = {"Normal","NVG"};
								gunnerOpticsModel = "";
								gunnerOutOpticsModel = "";
								gunnerOutOpticsEffect[] = {};
							};
						};
						stabilizedInAxes = 3;
						commanderForceOptics = 1;
						forceHideCommander = 0;
						outGunnerMayFire = 1;
						inGunnerMayFire = 1;
						ace_sys_nvg_nvrange = 570;
					};
				};
			};
		};
		ace_sys_nvg_nvrange = 290;
		class AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_2A46_1";
			};
		};
	};
	class T72_RU: T72_Base
	{
		scope = 1;
		displayName = "$STR_ACE_VDN_T72_A";
		accuracy = 0.5;
	};
	class T72_INS: T72_Base
	{
		displayName = "$STR_ACE_VDN_T72_A";
		accuracy = 0.5;
	};
	class T72_CDF: T72_Base
	{
		displayName = "$STR_ACE_VDN_T72_M";
		accuracy = 0.5;
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
						gunnerOutOpticsModel = "";
						gunnerOutOpticsEffect[] = {};
						initFov = "0.33333/ 1";
						minFov = "0.33333/ 1";
						maxFov = "0.33333/ 1";
						gunnerOpticsModel = "CA\Tracked_E\driverOptics";
						visionMode[] = {"Normal"};
					};
					class Narrow: Wide
					{
						initFov = "9/120";
						minFov = "9/120";
						maxFov = "9/120";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72B_TPDK1_optics";
						visionMode[] = {"Normal"};
					};
					class Night: Wide
					{
						initFov = "(9/120)*(8/5.5)";
						minFov = "(9/120)*(8/5.5)";
						maxFov = "(9/120)*(8/5.5)";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72A_TPN14923_optics";
						visionMode[] = {"NVG"};
					};
				};
			};
		};
	};
	class T72_GUE: T72_Base
	{
		displayName = "$STR_ACE_VDN_T72_A";
		accuracy = 0.5;
	};
	class T72_TK_EP1: T72_Base
	{
		displayName = "$STR_ACE_VDN_T72_M";
		LockDetectionSystem = 4;
		IncommingMisslieDetectionSystem = 16;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				weapons[] = {"ACE_2A46_1","PKT"};
				magazines[] = {"ACE_3BM17","22Rnd_125mmHE_T72","ACE_3BK18","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
			};
		};
	};
	class T55_Base: Tank
	{
		displayName = "T-55A";
		driverForceOptics = 1;
		forceNVG = 1;
		accuracy = 0.4;
		armor = 380;
		fuelCapacity = 961;
		armorStructural = 2;
		irScanRangeMax = 1500;
		cost = 1500000;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.14;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = "0.27,";
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.14;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.14;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		maxSpeed = 48;
		radarType = 0;
		driverCompartments = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				weapons[] = {"ACE_D10","PKT_veh"};
				magazines[] = {"21Rnd_100mmHEAT_D10","ACE_22Rnd_100mm_OF412","ACE_6Rnd_100mm_3BM8","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				gunnerOpticsModel = "\ca\weapons\2Dscope_T90gun12";
				gunnerOutOpticsModel = "";
				gunnerOutOpticsEffect[] = {};
				stabilizedInAxes = 0;
				visionMode[] = {"Normal"};
				discreteDistanceInitIndex = 0;
				discreteDistance[] = {};
				turretInfoType = "RscWeaponEmpty";
				minElev = -3;
				maxElev = 18;
				initElev = 0;
				startengine = 0;
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.55;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
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
						initFov = "0.33333/ 3.5";
						minFov = "0.33333/ 3.5";
						maxFov = "0.33333/ 3.5";
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optics_empty";
					};
					class Medium: Wide
					{
						initFov = 0.0512;
						minFov = 0.0512;
						maxFov = 0.0512;
					};
					class Narrow: Wide
					{
						initFov = "0.33333/ 5.5";
						minFov = "0.33333/ 5.5";
						maxFov = "0.33333/ 5.5";
						visionMode[] = {"NVG"};
					};
				};
				class ViewOptics
				{
					initFov = "0.33333/ 3.5";
					minFov = "0.33333/ 7";
					maxFov = "0.33333/ 3.5";
				};
				ace_sys_nvg_nvrange = 720;
				class Turrets: Turrets
				{
					class CommanderOptics: NewTurret
					{
						gunnerCompartments = 1;
						weapons[] = {};
						magazines[] = {};
						stabilizedInAxes = 0;
						minElev = -25;
						maxElev = 60;
						initElev = 0;
						minTurn = -360;
						maxTurn = 360;
						initTurn = 0;
						gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
						gunnerOutOpticsModel = "";
						forceNVG = 1;
						gunnerOutOpticsColor[] = {};
						gunnerOutForceOptics = 0;
						gunnerOutOpticsShowCursor = 0;
						startEngine = 0;
						class ViewOptics
						{
							initFov = "0.33333/ 2.75";
							minFov = "0.33333/ 2.75";
							maxFov = "0.33333/ 2.75";
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
								initFov = "0.33333/ 2.75";
								minFov = "0.33333/ 2.75";
								maxFov = "0.33333/ 2.75";
								visionMode[] = {"Normal"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_com3";
							};
							class Narrow: Wide
							{
								initFov = "0.33333/ 2.75";
								minFov = "0.33333/ 2.75";
								maxFov = "0.33333/ 2.75";
								visionMode[] = {"NVG"};
							};
						};
						class OpticsOut
						{
							class Monocular
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
								visionMode[] = {"Normal","NVG"};
								gunnerOpticsModel = "";
								ace_sys_nvg_nvrange = 290;
							};
						};
						ace_sys_nvg_nvrange = 570;
					};
				};
			};
		};
		ace_sys_nvg_nvrange = 290;
		class AnimationSources
		{
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_D10";
			};
		};
	};
	class T55_TK_EP1: T55_Base
	{
		accuracy = 0.5;
	};
	class T55_TK_GUE_EP1: T55_Base
	{
		accuracy = 0.5;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_D10","PKT_veh"};
				magazines[] = {"21Rnd_100mmHEAT_D10","ACE_6Rnd_100mm_BR412D","ACE_22Rnd_100mm_OF412","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
			};
		};
	};
	class ZSU_Base: Tank
	{
		displayName = "$STR_ACE_VDN_ZSU_BASE";
		accuracy = 0.4;
		driverForceOptics = 1;
		forceHideDriver = 1;
		driverCompartments = 0;
		irScanGround = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				turretinfotype = "RscWeaponZeroing";
				gunnerCompartments = 1;
				weapons[] = {"AZP85"};
				magazines[] = {"ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT","ACE_4x50Rnd_23mm_OFZT"};
				minElev = -4;
				maxElev = 85;
				stabilizedInAxes = 1;
				gunnerForceOptics = 1;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				startEngine = 1;
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.6;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.33333;
					minFov = "0.33333/ 2";
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
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				ace_sys_nvg_nvrange = 570;
				maxHorizontalRotSpeed = 1.55;
				maxVerticalRotSpeed = 1.55;
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerCompartments = 1;
						class ViewOptics: ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = 0.33333;
							minFov = "0.33333/ 2";
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
							initFov = "0.33333+ 0.41667";
							minFov = 0.33333;
							maxFov = "0.33333+ 0.41667";
						};
						commanderForceOptics = 1;
						forceHideCommander = 0;
						outGunnerMayFire = 0;
						inGunnerMayFire = 1;
						startEngine = 0;
						ace_sys_nvg_nvrange = 570;
					};
				};
			};
		};
		armor = 100;
		damageResistance = 0.02711;
		cost = 1000000;
		armorStructural = 3;
		fuelCapacity = 520;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.6;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 1;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 1;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		maxSpeed = 40;
		irScanRangeMin = 100;
		irScanRangeMax = 7000;
		threat[] = {0.9,0.5,1};
		ace_sys_nvg_nvrange = 290;
	};
	class ZSU_INS: ZSU_Base
	{
		displayName = "$STR_ACE_VDN_ZSU_M";
		accuracy = 0.5;
	};
	class ZSU_CDF: ZSU_Base
	{
		displayName = "$STR_ACE_VDN_ZSU_M";
		accuracy = 0.5;
	};
	class ZSU_TK_EP1: ZSU_Base
	{
		displayName = "$STR_ACE_VDN_ZSU_M";
		accuracy = 0.5;
	};
	class T34: Tank
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_T34";
		forceHideGunner = 0;
		driverForceOptics = 1;
		armor = 330;
		armorStructural = 2;
		fuelCapacity = 810;
		damageResistance = 0.01011;
		cost = 1500000;
		irScanRangeMax = 1200;
		radarType = 0;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.33;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.1;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.1;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		maxSpeed = 43;
		driverCompartments = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartment = 1;
				weapons[] = {"ACE_ZiS_S_53","DT_veh"};
				magazines[] = {"10Rnd_85mmAP","33Rnd_85mmHE","ACE_BR365P","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT"};
				gunnerOpticsModel = "\ca\weapons\2Dscope_T90gun12";
				minElev = -5;
				maxElev = 22;
				maxHorizontalRotSpeed = 0.3;
				stabilizedInAxes = 0;
				gunnerForceOptics = 1;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				startEngine = 1;
				lockWhenDriverOut = 1;
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.11;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333/ 2.5";
					minFov = "0.33333/ 2.5";
					maxFov = "0.33333/ 2.5";
				};
				class Turrets: Turrets
				{
					class CommanderOptics: NewTurret
					{
						gunnerCompartments = 1;
						weapons[] = {};
						magazines[] = {};
						stabilizedInAxes = 0;
						minElev = -25;
						maxElev = 60;
						initElev = 0;
						minTurn = -360;
						maxTurn = 360;
						initTurn = 0;
						gunnerOutOpticsModel = "";
						gunnerOutForceOptics = 0;
						gunnerOutOpticsShowCursor = 0;
						class ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333+ 0.41667";
							minFov = 0.33333;
							maxFov = "0.33333+ 0.41667";
						};
						class ViewGunner
						{
							initAngleX = 5;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333+ 0.41667";
							minFov = 0.33333;
							maxFov = "0.33333+ 0.41667";
						};
						commanderForceOptics = 1;
						forceHideCommander = 0;
						outGunnerMayFire = 0;
						inGunnerMayFire = 0;
						startEngine = 0;
					};
				};
			};
			class FrontGunner: MainTurret
			{
				gunnerCompartments = 2;
				weapons[] = {"DT_veh"};
				magazines[] = {"60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT","60Rnd_762x54_DT"};
			};
		};
		threat[] = {0.4,0.4,0};
	};
	class 2S6M_Tunguska: Tank
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_2S6M_TUNGUSKA";
		maxSpeed = 54;
		fuelCapacity = 320;
		cost = 1000000;
		armorStructural = 3.25;
		armor = 200;
		damageResistance = 0.02711;
		driverForceOptics = 1;
		radarType = 4;
		forceHideDriver = 0;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 1;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 0.8;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 1;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 1;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		threat[] = {0.9,0.5,1};
		driverCompartments = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				discretedistance[] = {400,600,800,1000,1200,1400};
				discretedistanceinitindex = 1;
				turretinfotype = "RscWeaponZeroing";
				gunnerCompartments = 1;
				minElev = -10;
				maxElev = 87;
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 2;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				weapons[] = {"2A38M","9M311Laucher"};
				magazines[] = {"1904Rnd_30mmAA_2A38M","8Rnd_9M311"};
				stabilizedInAxes = 3;
				gunnerForceOptics = 1;
				forceHideGunner = 0;
				inGunnerMayFire = 1;
				outGunnerMayFire = 0;
				gunnerOpticsEffect[] = {};
				startEngine = 0;
				lockWhenDriverOut = 1;
				class ViewOptics
				{
					initFov = "0.33333/ 1";
					minFov = "0.33333/ 8";
					maxFov = "0.33333/ 1";
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					visionMode[] = {"Normal","NVG"};
				};
				ace_sys_nvg_nvrange = 570;
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerCompartments = 1;
						commanderForceOptics = 1;
						forceHideCommander = 0;
						outGunnerMayFire = 0;
						inGunnerMayFire = 1;
						startEngine = 0;
						stabilizedInAxes = 3;
						weapons[] = {};
						magazines[] = {};
						class ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333/ 1";
							minFov = "0.33333/ 8";
							maxFov = "0.33333/ 1";
							visionMode[] = {"Normal","NVG"};
						};
						ace_sys_nvg_nvrange = 570;
					};
				};
			};
		};
		ace_sys_nvg_nvrange = 290;
	};
	class UH60_Base: Helicopter
	{
		accuracy = 0.4;
		displayName = "UH-60 Black Hawk";
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = "8 + 4";
		incommingmissliedetectionsystem = 8;
		radarType = 0;
	};
	class MH60S: UH60_Base
	{
		faction = "ACE_USNAVY";
		accuracy = 0.5;
		displayName = "MH-60S Knighthawk";
		sounddammage[] = {"",1,1};
		radarType = 0;
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_M240H_veh_out";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240H_veh_out";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_M240H_veh_out";
			};
			class ReloadAnim_2
			{
				source = "reload";
				weapon = "ACE_M240H_veh_out2";
			};
			class ReloadMagazine_2
			{
				source = "reloadmagazine";
				weapon = "ACE_M240H_veh_out2";
			};
			class Revolving_2
			{
				source = "revolving";
				weapon = "ACE_M240H_veh_out2";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				weapons[] = {"ACE_M240H_veh_out"};
			};
			class RightDoorGun: MainTurret
			{
				weapons[] = {"ACE_M240H_veh_out2"};
			};
		};
	};
	class UH60M_base_EP1: UH60_Base
	{
		accuracy = 0.4;
		displayName = "UH-60 Black Hawk";
		radarType = 0;
	};
	class UH60M_US_base_EP1: UH60M_base_EP1
	{
		accuracy = 0.4;
		radarType = 0;
	};
	class UH60M_EP1: UH60M_US_base_EP1
	{
		scope = 2;
		accuracy = 0.5;
		displayName = "UH-60M Black Hawk";
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
			};
		};
	};
	class UH60M_MEV_EP1: UH60M_US_base_EP1
	{
		accuracy = 0.5;
		displayName = "UH-60M (MEDEVAC)";
		radarType = 0;
	};
	class UH1_Base: Helicopter
	{
		accuracy = 0.4;
		displayName = "UH-1 Iroquois";
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		memoryPointDriverOptics = "commanderview";
		radarType = 0;
		driverOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
		weapons[] = {"CMFlareLauncher","FFARLauncher_14"};
		magazines[] = {"60Rnd_CMFlareMagazine","14Rnd_FFAR"};
		class ViewOptics
		{
			initAngleX = 0;
			minAngleX = -40;
			maxAngleX = 40;
			initAngleY = -3;
			minAngleY = -155;
			maxAngleY = 155;
			initFov = 0.33333;
			minFov = 0.33333;
			maxFov = 0.33333;
			visionMode[] = {"Normal","TI"};
			thermalMode[] = {0,1};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = 0;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
			};
			class CoPilotObs: MainTurret
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
						opticsDisplayName = "W";
						initFov = "0.33333/1";
						minFov = "0.33333/1";
						maxFov = "0.33333/1";
						visionMode[] = {"Normal","TI"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
					};
					class Medium: Wide
					{
						opticsDisplayName = "M";
						initFov = "0.33333/6";
						minFov = "0.33333/6";
						maxFov = "0.33333/6";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						initFov = "0.33333/18";
						minFov = "0.33333/18";
						maxFov = "0.33333/18";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
					};
				};
			};
		};
	};
	class UH1Y: UH1_Base
	{
		accuracy = 0.5;
		displayName = "UH-1Y Venom";
		lockdetectionsystem = "8 + 4";
		incommingmissliedetectionsystem = 16;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		radarType = 0;
	};
	class UH1H_base: Helicopter
	{
		accuracy = 0.4;
		displayName = "UH-1 Iroquois";
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 0;
		incommingmissliedetectionsystem = 0;
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				weapons[] = {"ACE_M240_veh_out"};
			};
			class LeftDoorGun: MainTurret
			{
				weapons[] = {"ACE_M240_veh_out2"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_M240_veh_out";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_veh_out";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_M240_veh_out";
			};
			class ReloadAnim_2
			{
				source = "reload";
				weapon = "ACE_M240_veh_out2";
			};
			class ReloadMagazine_2
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_veh_out2";
			};
			class Revolving_2
			{
				source = "revolving";
				weapon = "ACE_M240_veh_out2";
			};
		};
	};
	class UH1H_TK_EP1: UH1H_base
	{
		displayName = "UH-1H Iroquois";
		accuracy = 0.5;
		radarType = 0;
	};
	class UH1H_TK_GUE_EP1: UH1H_base
	{
		displayName = "UH-1H Iroquois";
		accuracy = 0.5;
		radarType = 0;
	};
	class AH1_Base: Helicopter
	{
		accuracy = 0.4;
		displayName = "AH-1 Cobra";
		damageResistance = "0.00593*0.5";
		memoryPointDriverOptics = "gunnerview";
		driverOpticsModel = "\x\ace\addons\m_veh_optics\optika_AH1Z_2";
		driverOpticsEffect[] = {};
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
		class ViewOptics
		{
			initAngleX = 0;
			minAngleX = -40;
			maxAngleX = 40;
			initAngleY = -3;
			minAngleY = -155;
			maxAngleY = 155;
			initFov = 0.33333;
			minFov = 0.33333;
			maxFov = 0.33333;
			visionMode[] = {"Normal","TI"};
			thermalMode[] = {0,1};
		};
	};
	class AH1Z: AH1_Base
	{
		accuracy = 0.5;
		displayName = "AH-1Z Viper";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","120Rnd_CMFlareMagazine"};
		damageResistance = "0.00593*0.5";
		lockdetectionsystem = "8 + 4";
		incommingmissliedetectionsystem = 16;
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M197","HellfireLauncher","SidewinderLaucher_AH1Z"};
				magazines[] = {"750Rnd_M197_AH1","8Rnd_Hellfire","2Rnd_Sidewinder_AH1Z"};
				minElev = -50;
				maxElev = 21;
				initElev = 5;
				minTurn = -110;
				maxTurn = 110;
				maxHorizontalRotSpeed = 1.778;
				maxVerticalRotSpeed = 1.333;
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = -3;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = -3;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333/6";
					minFov = "0.33333/32";
					maxFov = "0.33333/1";
					visionMode[] = {"Normal","TI"};
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
						thermalMode[] = {0,1};
						opticsDisplayName = "E";
						visionMode[] = {"Normal","TI"};
						initFov = "0.33333/1";
						minFov = "0.33333/1";
						maxFov = "0.33333/1";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_AH1Z_2";
					};
					class Medium: Wide
					{
						opticsDisplayName = "W";
						initFov = "0.33333/6";
						minFov = "0.33333/6";
						maxFov = "0.33333/6";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_AH1Z_2";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "M";
						initFov = "0.33333/18";
						minFov = "0.33333/18";
						maxFov = "0.33333/18";
						gunnerOpticsModel = "\ca\air\optika_AH1Z";
					};
					class VeryNarrow: Wide
					{
						opticsDisplayName = "N";
						initFov = "0.33333/32";
						minFov = "0.33333/32";
						maxFov = "0.33333/32";
						gunnerOpticsModel = "\ca\air\optika_AH1Z";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "0.33333+ 0.41667";
						minFov = 0.33333;
						maxFov = "0.33333+ 0.41667";
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
	};
	class AH64_base_EP1: Helicopter
	{
		accuracy = 0.4;
		displayName = "AH-64 Apache";
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = "8 + 4";
		incommingmissliedetectionsystem = 16;
		radarType = 4;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor = 1;
			};
			class HitEngine: HitEngine
			{
				armor = 0.25;
			};
			class HitAvionics: HitAvionics
			{
				armor = 0.15;
			};
			class HitVRotor: HitVRotor
			{
				armor = 0.4;
			};
			class HitHRotor: HitHRotor
			{
				armor = 0.33;
			};
		};
		class MFD
		{
			class AirplaneHUD
			{
				class Draw
				{
					class MGun
					{
						class Circle
						{
							width = 0;
						};
					};
				};
			};
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
				opticsDisplayName = "E";
				initFov = "0.33333/1.1";
				minFov = "0.33333/1.1";
				maxFov = "0.33333/1.1";
				visionMode[] = {"Normal","TI"};
				thermalMode[] = {0,1};
				gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
			};
			class Medium: Wide
			{
				opticsDisplayName = "W";
				initFov = "0.33333/6";
				minFov = "0.33333/6";
				maxFov = "0.33333/6";
				gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
			};
			class Narrow: Wide
			{
				opticsDisplayName = "M";
				initFov = "0.33333/18";
				minFov = "0.33333/18";
				maxFov = "0.33333/18";
				gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_2";
			};
			class Narrowest: Wide
			{
				opticsDisplayName = "N";
				initFov = "0.33333/32";
				minFov = "0.33333/32";
				maxFov = "0.33333/32";
				gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
			};
		};
		class OpticsOut
		{
			class Monocular
			{
				initAngleX = 0;
				minAngleX = -30;
				maxAngleX = 30;
				initAngleY = 0;
				minAngleY = -100;
				maxAngleY = 100;
				initFov = "0.33333+ 0.41667";
				minFov = 0.33333;
				maxFov = "0.33333+ 0.41667";
				visionMode[] = {"Normal","NVG"};
				gunnerOpticsModel = "";
				gunnerOpticsEffect[] = {};
			};
		};
	};
	class AH64D: AH64_base_EP1
	{
		scope = 1;
		accuracy = 0.5;
		radarType = 4;
		displayName = "AH-64D Apache Longbow";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","60Rnd_CMFlareMagazine"};
		armor = 75;
		memoryPointDriverOptics = "gunnerview";
		driverOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
		driverOpticsEffect[] = {};
		class ViewOptics
		{
			initAngleX = 0;
			minAngleX = -40;
			maxAngleX = 40;
			initAngleY = 0;
			minAngleY = -155;
			maxAngleY = 155;
			initFov = "0.33333/1.1";
			minFov = "0.33333/1.1";
			maxFov = "0.33333/1.1";
			visionMode[] = {"Normal","TI"};
			thermalMode[] = {0,1};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev = -60;
				maxElev = 11;
				initElev = 0;
				minTurn = -100;
				maxTurn = 100;
				initTurn = 0;
				maxHorizontalRotSpeed = 1.6;
				maxVerticalRotSpeed = 1.6;
				weapons[] = {"M230","ACE_HellfireLauncher_Apache","HellfireLauncher"};
				magazines[] = {"1200Rnd_30x113mm_M789_HEDP","ACE_6Rnd_Hellfire","ACE_2Rnd_Hellfire_L"};
				gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = 0;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = 0;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333/18";
					minFov = "0.33333/32";
					maxFov = "0.33333/6";
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
						opticsDisplayName = "E";
						initFov = "0.33333/1.1";
						minFov = "0.33333/1.1";
						maxFov = "0.33333/1.1";
						visionMode[] = {"Normal","TI"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
					};
					class Medium: Wide
					{
						opticsDisplayName = "W";
						initFov = "0.33333/6";
						minFov = "0.33333/6";
						maxFov = "0.33333/6";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "M";
						initFov = "0.33333/18";
						minFov = "0.33333/18";
						maxFov = "0.33333/18";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_2";
					};
					class Narrowest: Wide
					{
						opticsDisplayName = "N";
						initFov = "0.33333/32";
						minFov = "0.33333/32";
						maxFov = "0.33333/32";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "0.33333+ 0.41667";
						minFov = 0.33333;
						maxFov = "0.33333+ 0.41667";
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
	};
	class AH64D_EP1: AH64_base_EP1
	{
		accuracy = 0.5;
		radarType = 4;
		displayName = "AH-64D Apache Longbow";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","60Rnd_CMFlareMagazine"};
		armor = 75;
		memoryPointDriverOptics = "gunnerview";
		driverOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
		driverOpticsEffect[] = {};
		class ViewOptics
		{
			initAngleX = 0;
			minAngleX = -40;
			maxAngleX = 40;
			initAngleY = 0;
			minAngleY = -155;
			maxAngleY = 155;
			initFov = "0.33333/1.1";
			minFov = "0.33333/1.1";
			maxFov = "0.33333/1.1";
			visionMode[] = {"Normal","TI"};
			thermalMode[] = {0,1};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev = -60;
				maxElev = 11;
				initElev = 0;
				minTurn = -100;
				maxTurn = 100;
				initTurn = 0;
				maxHorizontalRotSpeed = 1.6;
				maxVerticalRotSpeed = 1.6;
				weapons[] = {"M230","ACE_HellfireLauncher_Apache","HellfireLauncher"};
				magazines[] = {"1200Rnd_30x113mm_M789_HEDP","ACE_6Rnd_Hellfire","ACE_2Rnd_Hellfire_L"};
				gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = 0;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = 0;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333/18";
					minFov = "0.33333/32";
					maxFov = "0.33333/6";
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
						opticsDisplayName = "E";
						initFov = "0.33333/1.1";
						minFov = "0.33333/1.1";
						maxFov = "0.33333/1.1";
						visionMode[] = {"Normal","TI"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
					};
					class Medium: Wide
					{
						opticsDisplayName = "W";
						initFov = "0.33333/6";
						minFov = "0.33333/6";
						maxFov = "0.33333/6";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "M";
						initFov = "0.33333/18";
						minFov = "0.33333/18";
						maxFov = "0.33333/18";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_2";
					};
					class Narrowest: Wide
					{
						opticsDisplayName = "N";
						initFov = "0.33333/32";
						minFov = "0.33333/32";
						maxFov = "0.33333/32";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "0.33333+ 0.41667";
						minFov = 0.33333;
						maxFov = "0.33333+ 0.41667";
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
	};
	class AH64D_Sidewinders: AH64D
	{
		scope = 1;
		accuracy = 1000;
		displayName = "AH-64D (AIM-9)";
		weapons[] = {"CMFlareLauncher"};
		magazines[] = {"60Rnd_CMFlareMagazine"};
	};
	class AH6_Base_EP1: Helicopter
	{
		displayName = "AH-6 Little Bird";
		envelope[] = {2.6,3.8,5.3,6.8,8.3,8.3,7.8,7.8,7,8,7.8,6.3,4.8,3.2,3.2,1.7};
		accuracy = 0.4;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
		maxSpeed = 282;
	};
	class AH6J_EP1: AH6_Base_EP1
	{
		accuracy = 1000;
		displayName = "AH-6J Little Bird";
		magazines[] = {"14Rnd_FFAR","ACE_5250Rnd_762x51_M134","60Rnd_CMFlareMagazine"};
		maxSpeed = 282;
		radarType = 0;
	};
	class AH6X_EP1: AH6_Base_EP1
	{
		accuracy = 1000;
		displayName = "AH-6X MELB";
		maxSpeed = 282;
		radarType = 0;
	};
	class MH6J_EP1: AH6_Base_EP1
	{
		displayName = "MH-6J Little Bird";
		displayNameShort = "MH-6 Little Bird";
		maxSpeed = 282;
		radarType = 0;
		weapons[] = {};
		magazines[] = {};
	};
	class CH47_base_EP1: Helicopter
	{
		accuracy = 0.4;
		displayName = "CH-47 Chinook";
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
	};
	class CH_47F_EP1: CH47_base_EP1
	{
		accuracy = 0.5;
		displayName = "CH-47F Chinook";
		lockdetectionsystem = "8 + 4";
		incommingmissliedetectionsystem = 16;
		cargocompartments[] = {"Compartment2"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics
				{
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
			};
			class RightDoorGun: MainTurret{};
			class BackDoorGun: MainTurret
			{
				weapons[] = {"ACE_M240H_veh_out"};
				magazines[] = {"ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_M240H_veh_out";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240H_veh_out";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_M240H_veh_out";
			};
		};
	};
	class Kamov_Base: Helicopter
	{
		accuracy = 0.4;
		damageResistance = 0.001;
		displayName = "$STR_ACE_VDN_KA50_BASE";
		radarType = 0;
	};
	class Ka52: Kamov_Base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_KA52";
		weapons[] = {"ACE_S8Launcher","CMFlareLauncher"};
		magazines[] = {"40Rnd_80mm","120Rnd_CMFlareMagazine"};
		memoryPointDriverOptics = "gunnerview";
		driverOpticsModel = "\ca\air\optika_Ka50_gun";
		driverOpticsEffect[] = {};
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = "8 + 4";
		incommingmissliedetectionsystem = 16;
		radarType = 4;
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
			visionMode[] = {"Normal","TI"};
			thermalMode[] = {0,1};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_2A42","VikhrLauncher"};
				magazines[] = {"230Rnd_30mmHE_2A42","230Rnd_30mmAP_2A42","12Rnd_Vikhr_KA50"};
				initElev = 0;
				minElev = -37;
				maxElev = 3;
				minTurn = -9;
				maxTurn = 2;
				initTurn = 0;
				maxHorizontalRotSpeed = 1.6;
				maxVerticalRotSpeed = 1.6;
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						maxFov = "0.33333/6";
						minFov = "0.33333/6";
						initFov = "0.33333/6";
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\ca\air\optika_Ka50_gun";
						gunnerOpticsEffect[] = {"TVOptics","OpticsBlur2","OpticsCHAbera2"};
					};
					class Medium: Wide
					{
						opticsDisplayName = "M";
						minFov = "0.33333/18";
						maxFov = "0.33333/18";
						initFov = "0.33333/18";
						gunnerOpticsModel = "\ca\air\optika_Ka50_rocket";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						minFov = "0.33333/32";
						maxFov = "0.33333/32";
						initFov = "0.33333/32";
						gunnerOpticsModel = "\ca\air\optika_Ka50_rocket";
					};
				};
			};
		};
	};
	class Mi24_Base: Helicopter
	{
		accuracy = 0.4;
		damageResistance = 0.000345;
		displayName = "$STR_ACE_VDN_MI24_BASE";
		irScanRangeMin = 300;
		irScanRangeMax = 6000;
		irScanToEyeFactor = 1;
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
		model = "\x\ace\addons\m_vehicle\mi24\ace_mi24v";
		weapons[] = {"57mmLauncher","ACE_S8Launcher","CMFlareLauncher"};
		magazines[] = {"64Rnd_57mm","40Rnd_80mm","120Rnd_CMFlareMagazine"};
		class HitPoints: HitPoints
		{
			class HitEngine: HitEngine
			{
				armor = 0.4375;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","AT6Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","ACE_1Rnd_B8V20","ACE_1Rnd_UB32","ACE_1Rnd_UB32","ACE_1Rnd_B8V20","4Rnd_AT6_Mi24V"};
				minElev = -60;
				maxElev = 20;
				initElev = 11;
				minTurn = -60;
				maxTurn = 60;
				maxHorizontalRotSpeed = 1.6;
				maxVerticalRotSpeed = 1.6;
				turretInfoType = "RscWeaponEmpty";
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						maxFov = "22/120";
						minFov = "22/120";
						initFov = "22/120";
						visionMode[] = {"Normal","NVG"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_Mi24_3x.p3d";
						gunnerOpticsEffect[] = {"TVOptics","OpticsBlur2","OpticsCHAbera2"};
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						maxFov = "7.3/120";
						minFov = "7.3/120";
						initFov = "7.3/120";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_Mi24_10x.p3d";
					};
				};
			};
		};
		class UserActions
		{
			class OpenRdoor
			{
				condition = "if (alive this) then {if (this animationPhase 'dvere_p_vrch' == 0) then {if ((getPos this select 2) < 3) then {(abs (speed this) < 3)} else {false}} else {false}} else {false}";
				statement = "['ace_hind_or', this] call ACE_fnc_receiverOnlyEvent;";
			};
			class CloseRdoor
			{
				condition = "if (alive this) then {(this animationPhase 'dvere_p_vrch' > 0)} else {false}";
				statement = "['ace_hind_cr', this] call ACE_fnc_receiverOnlyEvent;";
			};
			class OpenLdoor
			{
				condition = "if (alive this) then {if (this animationPhase 'dvere_l_vrch' == 0) then {if ((getPos this select 2) < 3) then {(abs (speed this) < 3)} else {false}} else {false}} else {false}";
				statement = "['ace_hind_ol', this] call ACE_fnc_receiverOnlyEvent;";
			};
			class CloseLdoor
			{
				condition = "if (alive this) then {(this animationPhase 'dvere_l_vrch' > 0)} else {false}";
				statement = "['ace_hind_cl', this] call ACE_fnc_receiverOnlyEvent;";
			};
			class OpenDoors
			{
				displayName = "$STR_EP1_DN_C130J_STATIC_EP1_USERACTIONS_CARGOOPEN";
				position = "Glass3";
				radius = 5;
				onlyForPlayer = 1;
				condition = "if (alive this) then {if (player in [driver this, gunner this]) then {(this animationPhase 'dvere_l_vrch' == 0) || {(this animationPhase 'dvere_p_vrch' == 0)}} else {false}} else {false}";
				statement = "['ace_hind_od', this] call ACE_fnc_receiverOnlyEvent;";
			};
			class CloseDoors: OpenDoors
			{
				displayName = "$STR_EP1_DN_C130J_STATIC_EP1_USERACTIONS_CARGOCLOSE";
				condition = "if (alive this) then {if (player in [driver this, gunner this]) then {(this animationPhase 'dvere_l_vrch' > 0) || {(this animationPhase 'dvere_p_vrch' > 0)}} else {false}} else {false}";
				statement = "['ace_hind_cd', this] call ACE_fnc_receiverOnlyEvent;";
			};
		};
	};
	class Mi24_Base_RU: Mi24_Base
	{
		accuracy = 0.5;
		irScanRangeMax = 8000;
	};
	class Mi24_Base_CDF: Mi24_Base
	{
		accuracy = 0.5;
		irScanRangeMax = 6000;
	};
	class Mi24_V: Mi24_Base_RU
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI24_V";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","ACE_AT9Launcher_Mi28"};
				magazines[] = {"1470Rnd_127x108_YakB","ACE_1Rnd_B8V20","ACE_1Rnd_UB32","ACE_1Rnd_UB32","ACE_1Rnd_B8V20","ACE_4Rnd_AT9_Mi24V"};
			};
		};
	};
	class ACE_Mi24_V_FAB250_RU: Mi24_V
	{
		displayName = "$STR_ACE_VDN_MI24_V_FAB250";
		weapons[] = {"ACE_S8Launcher","CMFlareLauncher"};
		magazines[] = {"40Rnd_80mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","HeliBombLauncher","ACE_AT9Launcher_Mi28"};
				magazines[] = {"1470Rnd_127x108_YakB","ACE_1Rnd_B8V20","2Rnd_FAB_250","ACE_1Rnd_B8V20","ACE_4Rnd_AT9_Mi24V"};
			};
		};
	};
	class ACE_Mi24_V_UPK23_RU: Mi24_V
	{
		displayName = "$STR_ACE_VDN_MI24_V_UPK23";
		memoryPointGun[] = {"Rocket_1","Rocket_2"};
		weapons[] = {"ACE_S8Launcher","ACE_UPK23","CMFlareLauncher"};
		magazines[] = {"40Rnd_80mm","ACE_500Rnd_23mm_UPK23","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","ACE_AT9Launcher_Mi28"};
				magazines[] = {"1470Rnd_127x108_YakB","ACE_1Rnd_B8V20","ACE_1Rnd_UPK23","ACE_1Rnd_UPK23","ACE_1Rnd_B8V20","ACE_4Rnd_AT9_Mi24V"};
			};
		};
	};
	class Mi24_P: Mi24_Base_RU
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI24_P";
		memoryPointGun = "machinegun";
		gunBeg = "muzzle_1";
		gunEnd = "chamber_1";
		selectionFireAnim = "zasleh";
		model = "\x\ace\addons\m_vehicle\mi24\ace_mi24p";
		weapons[] = {"ACE_GSh302K","ACE_S8Launcher","CMFlareLauncher"};
		magazines[] = {"750Rnd_30mm_GSh301","80Rnd_80mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				selectionFireAnim = "";
				weapons[] = {"FakeWeapon","AT9Launcher"};
				magazines[] = {"ACE_1Rnd_B8V20","ACE_1Rnd_B8V20","ACE_1Rnd_B8V20","ACE_1Rnd_B8V20","4Rnd_AT9_Mi24P"};
			};
		};
	};
	class Mi24_D: Mi24_Base_CDF
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI24_D";
		model = "\x\ace\addons\m_vehicle\mi24\ace_mi24d";
		typicalCargo[] = {"CDF_Soldier_Pilot","CDF_Soldier_Pilot","CDF_Soldier_AR","CDF_Soldier_RPG","CDF_Soldier"};
		weapons[] = {"57mmLauncher_128","CMFlareLauncher"};
		magazines[] = {"128Rnd_57mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","AT2Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","4Rnd_AT2_Mi24D"};
			};
		};
	};
	class Mi24_D_Base: Mi24_Base_CDF
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI24_D";
		model = "\x\ace\addons\m_vehicle\mi24\ace_mi24d";
		weapons[] = {"57mmLauncher_128","CMFlareLauncher"};
		magazines[] = {"128Rnd_57mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","AT2Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","4Rnd_AT2_Mi24D"};
			};
		};
	};
	class Mi24_Base_TK_EP1: Mi24_Base
	{
		accuracy = 0.5;
	};
	class Mi24_D_Base_TK_EP1: Mi24_Base_TK_EP1
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI24_D";
		model = "\x\ace\addons\m_vehicle\mi24\ace_mi24d";
		weapons[] = {"57mmLauncher_128","CMFlareLauncher"};
		magazines[] = {"128Rnd_57mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","AT2Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","4Rnd_AT2_Mi24D"};
			};
		};
	};
	class Mi24_D_TK_EP1: Mi24_D_Base_TK_EP1{};
	class ACE_Mi24_V_CDF: Mi24_D
	{
		irScanRangeMin = 300;
		irScanRangeMax = 6000;
		displayName = "$STR_ACE_VDN_MI24_V";
		model = "\x\ace\addons\m_vehicle\mi24\ace_mi24v";
		weapons[] = {"57mmLauncher","ACE_S8Launcher","CMFlareLauncher"};
		magazines[] = {"64Rnd_57mm","40Rnd_80mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","AT6Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","ACE_1Rnd_B8V20","ACE_1Rnd_UB32","ACE_1Rnd_UB32","ACE_1Rnd_B8V20","4Rnd_AT6_Mi24V"};
			};
		};
		class Library
		{
			libTextDesc = "$STR_LIB_MI24_V";
		};
	};
	class ACE_Mi24_V_FAB250_CDF: ACE_Mi24_V_CDF
	{
		displayName = "$STR_ACE_VDN_MI24_V_FAB250";
		weapons[] = {"ACE_S8Launcher","CMFlareLauncher"};
		magazines[] = {"40Rnd_80mm","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","HeliBombLauncher","AT6Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","ACE_1Rnd_B8V20","2Rnd_FAB_250","ACE_1Rnd_B8V20","4Rnd_AT6_Mi24V"};
			};
		};
	};
	class ACE_Mi24_V_UPK23_CDF: ACE_Mi24_V_CDF
	{
		displayName = "$STR_ACE_VDN_MI24_V_UPK23";
		memoryPointGun[] = {"Rocket_1","Rocket_2"};
		weapons[] = {"ACE_S8Launcher","ACE_UPK23","CMFlareLauncher"};
		magazines[] = {"40Rnd_80mm","ACE_500Rnd_23mm_UPK23","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"YakB","AT6Launcher"};
				magazines[] = {"1470Rnd_127x108_YakB","ACE_1Rnd_B8V20","ACE_1Rnd_UPK23","ACE_1Rnd_UPK23","ACE_1Rnd_B8V20","4Rnd_AT6_Mi24V"};
			};
		};
	};
	class Mi17_base: Helicopter
	{
		accuracy = 0.4;
		displayName = "$STR_ACE_VDN_MI17_BASE";
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_PKT_out"};
			};
			class BackTurret: MainTurret
			{
				weapons[] = {"ACE_PKT_out_2"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_PKT_out";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_PKT_out";
			};
			class ReloadAnim_2
			{
				source = "reload";
				weapon = "ACE_PKT_out_2";
			};
			class ReloadMagazine_2
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out_2";
			};
			class Revolving_2
			{
				source = "revolving";
				weapon = "ACE_PKT_out_2";
			};
		};
	};
	class Mi17_base_Ins: Mi17_Base
	{
		accuracy = 0.5;
	};
	class Mi17_Ins: Mi17_base_Ins
	{
		displayName = "$STR_ACE_VDN_MI17_INS";
	};
	class Mi17_base_TK_EP1: Mi17_base
	{
		accuracy = 0.5;
	};
	class Mi17_TK_EP1: Mi17_base_TK_EP1
	{
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_MI17_TK";
	};
	class Mi17_base_CDF: Mi17_Base
	{
		accuracy = 0.5;
	};
	class Mi17_CDF: Mi17_base_CDF
	{
		displayName = "$STR_ACE_VDN_MI17_CDF";
	};
	class Mi17_base_CZ_EP1: Mi17_Base
	{
		accuracy = 0.5;
	};
	class Mi171Sh_Base_EP1: Mi17_base_CZ_EP1
	{
		displayName = "$STR_ACE_VDN_MI171SH_CZ";
		class Turrets: Turrets
		{
			class RightTurret: MainTurret
			{
				weapons[] = {"ACE_PKT_out_3"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class HUDaction
			{
				animPeriod = 1;
				initPhase = 0;
				source = "user";
			};
			class ReloadAnim_3
			{
				source = "reload";
				weapon = "ACE_PKT_out_3";
			};
			class ReloadMagazine_3
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out_3";
			};
			class Revolving_3
			{
				source = "revolving";
				weapon = "ACE_PKT_out_3";
			};
		};
	};
	class Mi171Sh_CZ_EP1: Mi171Sh_Base_EP1
	{
		displayName = "$STR_ACE_VDN_MI171SH_CZ";
	};
	class Mi17_base_RU: Mi17_Base
	{
		accuracy = 0.5;
	};
	class Mi17_rockets_RU: Mi17_base_RU
	{
		displayName = "$STR_ACE_VDN_MI17_ROCKETS_RU";
		class Turrets: Turrets
		{
			class FrontTurret: MainTurret
			{
				weapons[] = {"ACE_PKT_out_3"};
			};
		};
		class AnimationSources: AnimationSources
		{
			class HUDaction
			{
				animPeriod = 1;
				initPhase = 0;
				source = "user";
			};
			class ReloadAnim_3
			{
				source = "reload";
				weapon = "ACE_PKT_out_3";
			};
			class ReloadMagazine_3
			{
				source = "reloadmagazine";
				weapon = "ACE_PKT_out_3";
			};
			class Revolving_3
			{
				source = "revolving";
				weapon = "ACE_PKT_out_3";
			};
		};
	};
	class Mi17_medevac_base: Mi17_base
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_MI17_MEDEVAC_BASE";
	};
	class Mi17_medevac_base_Ins: Mi17_medevac_base
	{
		accuracy = 0.5;
	};
	class Mi17_medevac_base_CDF: Mi17_medevac_base
	{
		accuracy = 0.5;
	};
	class Mi17_medevac_base_Ru: Mi17_medevac_base
	{
		accuracy = 0.5;
	};
	class Mi17_medevac_Ins: Mi17_medevac_base_Ins
	{
		displayName = "$STR_ACE_VDN_MI17_MEDEVAC_INS";
	};
	class Mi17_medevac_CDF: Mi17_medevac_base_CDF
	{
		displayName = "$STR_ACE_VDN_MI17_MEDEVAC_CDF";
	};
	class Mi17_medevac_RU: Mi17_medevac_base_Ru
	{
		displayName = "$STR_ACE_VDN_MI17_MEDEVAC_RU";
	};
	class Mi17_Civilian_base_Ru: Mi17_base
	{
		accuracy = 0.5;
		lockdetectionsystem = 0;
		incommingmissliedetectionsystem = 0;
		radarType = 0;
	};
	class Mi17_Civilian: Mi17_Civilian_base_Ru
	{
		displayName = "$STR_ACE_VDN_MI17_CIVILIAN";
	};
	class BAF_Apache_AH1_D: AH64D_EP1
	{
		accuracy = 0.5;
		weapons[] = {"CRV7_HEPD","CRV7_FAT","CMFlareLauncher"};
		magazines[] = {"6Rnd_CRV7_HEPD","6Rnd_CRV7_FAT","60Rnd_CMFlareMagazine"};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				name = "notExisting";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M230","ACE_HellfireLauncher_Apache","HellfireLauncher"};
				magazines[] = {"1200Rnd_30x113mm_M789_HEDP","ACE_4Rnd_Hellfire","ACE_4Rnd_Hellfire_L"};
			};
		};
	};
	class AW159_Lynx_BAF: Helicopter
	{
		accuracy = 0.5;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
		class MFD
		{
			class AirplaneHUD
			{
				helmetposition[] = {-0.025,0.0375,0.1};
			};
		};
		magazines[] = {"1200Rnd_20mm_M621","120Rnd_CMFlareMagazine"};
		weapons[] = {"M621","CMFlareLauncher"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"CRV7_PG","ACE_SACLOS_Guidance"};
				magazines[] = {"12Rnd_CRV7","ACE_SACLOS_Guidance"};
			};
		};
	};
	class BAF_Merlin_HC3_D: Helicopter
	{
		accuracy = 0.5;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
	};
	class CH_47F_BAF: CH_47F_EP1
	{
		accuracy = 0.5;
	};
	class Ka137_Base_PMC: Helicopter
	{
		armor = 10;
		radarType = 0;
	};
	class Ka60_Base_PMC: Helicopter
	{
		armor = 30;
		radarType = 0;
	};
	class C130J: Plane
	{
		accuracy = 0.5;
		scope = 1;
		displayName = "C-130J Super Hercules";
		elevatorSensitivity = 1.1;
		wheelSteeringSensitivity = 4.2;
		noseDownCoef = 0;
		flapsFrictionCoef = 1;
		landingAoa = "rad 7";
		landingSpeed = 210;
		transportVehiclesCount = 1;
		transportVehiclesMass = 65536;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 16;
		radarType = 0;
	};
	class C130J_base: C130J
	{
		displayName = "C-130 Hercules";
	};
	class C130J_US_EP1: C130J_base
	{
		accuracy = 1.5;
		displayName = "C-130J Super Hercules";
		faction = "ACE_USAF";
	};
	class A10: Plane
	{
		scope = 1;
		displayName = "A-10A";
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 16;
		radarType = 0;
	};
	class A10_base: A10
	{
		scope = 0;
		accuracy = 0.5;
	};
	class A10_US_EP1: A10_base
	{
		scope = 2;
		faction = "ACE_USAF";
		displayName = "A-10A (GBU-12)";
		accuracy = 1000;
	};
	class ACE_A10_CBU87: A10_US_EP1
	{
		displayName = "A-10A (CBU-87)";
		accuracy = 1000;
		weapons[] = {"ACE_GAU8","MaverickLauncher","SidewinderLaucher_AH1Z","ACE_CBU87_Bomblauncher","FFARLauncher_14","CMFlareLauncher"};
		magazines[] = {"ACE_1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z","ACE_4Rnd_CBU87","14Rnd_FFAR","120Rnd_CMFlare_Chaff_Magazine"};
	};
	class ACE_A10_Mk82: A10_US_EP1
	{
		displayName = "A-10A (Mk82)";
		accuracy = 1000;
		weapons[] = {"ACE_GAU8","MaverickLauncher","SidewinderLaucher_AH1Z","ACE_Mk82BombLauncher","FFARLauncher_14","CMFlareLauncher"};
		magazines[] = {"ACE_1350Rnd_30mmAP_A10","2Rnd_Maverick_A10","2Rnd_Sidewinder_AH1Z","ACE_4Rnd_Mk82","14Rnd_FFAR","120Rnd_CMFlare_Chaff_Magazine"};
	};
	class AV8B2: Plane
	{
		accuracy = 0.5;
		displayName = "AV-8B Harrier II";
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 16;
	};
	class AV8B: AV8B2
	{
		accuracy = 1000;
		displayName = "AV-8B (GBU-12)";
	};
	class F35_base: Plane
	{
		accuracy = 0.5;
		displayName = "F-35 Lightning II";
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 16;
	};
	class F35B: F35_base
	{
		accuracy = 1000;
		displayName = "F-35B Lightning II";
	};
	class MV22: Plane
	{
		displayName = "MV-22 Osprey";
		weapons[] = {"CMFlareLauncher"};
		magazines[] = {"120Rnd_CMFlare_Chaff_Magazine"};
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 16;
		radarType = 0;
	};
	class Su25_base: Plane
	{
		displayName = "$STR_ACE_VDN_SU25_BASE";
		accuracy = 0.5;
		acceleration = 900;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
		weapons[] = {"GSh302","AirBombLauncher","R73Launcher_2","ACE_S8Launcher_Plane","CMFlareLauncher"};
		magazines[] = {"ACE_250Rnd_30mm_GSh302","4Rnd_FAB_250","2Rnd_R73","40Rnd_S8T","40Rnd_80mm","120Rnd_CMFlare_Chaff_Magazine"};
		class ViewPilot: ViewPilot
		{
			initFov = 1;
			minFov = 0.18;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -40;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
	};
	class Su25_CDF: Su25_base
	{
		displayName = "$STR_ACE_VDN_SU25_BASE";
		accuracy = 1.5;
	};
	class Su25_Ins: Su25_base
	{
		displayName = "$STR_ACE_VDN_SU25_BASE";
		accuracy = 1.5;
	};
	class Su25_TK_EP1: Su25_base
	{
		displayName = "$STR_ACE_VDN_SU25_K";
		accuracy = 1.5;
	};
	class Su39: Su25_base
	{
		displayName = "$STR_ACE_VDN_SU25_KH29";
		accuracy = 1000;
		weapons[] = {"GSh302","Ch29Launcher","R73Launcher_2","ACE_S8Launcher_Plane","CMFlareLauncher"};
		magazines[] = {"ACE_250Rnd_30mm_GSh302","4Rnd_Ch29","2Rnd_R73","40Rnd_S8T","40Rnd_80mm","120Rnd_CMFlare_Chaff_Magazine"};
	};
	class Su34: Plane
	{
		displayName = "$STR_ACE_VDN_SU34";
		accuracy = 0.5;
		weapons[] = {"GSh301","ACE_S8Launcher_Plane","CMFlareLauncher"};
		magazines[] = {"180Rnd_30mm_GSh301","40Rnd_S8T","120Rnd_CMFlare_Chaff_Magazine"};
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 16;
		radarType = 4;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				weapons[] = {"Ch29Launcher_Su34","R73Launcher"};
				magazines[] = {"6Rnd_Ch29","4Rnd_R73"};
			};
		};
		class ViewPilot: ViewPilot
		{
			initFov = 1;
			minFov = 0.2;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};
	};
	class An2_Base_EP1: Plane
	{
		accuracy = 0.5;
		displayName = "$STR_ACE_VDN_AN2_BASE";
		radarType = 0;
	};
	class An2_TK_EP1: An2_Base_EP1
	{
		accuracy = 1.5;
		displayName = "$STR_ACE_VDN_AN2_T";
	};
	class An2_1_TK_CIV_EP1: An2_Base_EP1
	{
		accuracy = 1.5;
		displayName = "$STR_ACE_VDN_AN2_P";
	};
	class An2_2_TK_CIV_EP1: An2_1_TK_CIV_EP1
	{
		accuracy = 1000;
	};
	class L39_base: Plane
	{
		accuracy = 0.5;
		displayName = "L-39 Albatros";
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		radarType = 0;
		weapons[] = {"GSh23L_L39","ACE_UB16_Pods"};
		magazines[] = {"ACE_1Rnd_UB16","ACE_1Rnd_UB16","ACE_1Rnd_UB16","ACE_1Rnd_UB16","150Rnd_23mm_GSh23L","64Rnd_57mm"};
	};
	class L39_TK_EP1: L39_base
	{
		accuracy = 1.5;
		displayName = "L-39ZA Albatros";
	};
	class ACE_L39_TK_FAB250: L39_TK_EP1
	{
		accuracy = 1000;
		displayName = "L-39ZA (FAB-250)";
		weapons[] = {"GSh23L_L39","ACE_AirBombLauncher"};
		magazines[] = {"150Rnd_23mm_GSh23L","ACE_4Rnd_FAB_250"};
	};
	class BAF_L2A1_ACOG_base: StaticMGWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class BAF_GPMG_Minitripod_D: BAF_L2A1_ACOG_base
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				discretedistance[] = {308};
				discretedistanceinitindex = 0;
				gunneropticsmodel = "\x\ace\addons\m_wep_optics\ace_optics_m145";
				class ViewOptics
				{
					initfov = 0.085333;
					maxfov = 0.085333;
					minfov = 0.085333;
					initanglex = 0;
					initangley = 0;
					maxanglex = 30;
					maxangley = 100;
					minanglex = -30;
					minangley = -100;
					visionMode[] = {"Normal"};
				};
			};
		};
	};
	class M119_US_EP1;
	class ACE_BAF_M119_D: M119_US_EP1
	{
		faction = "BIS_BAF";
		crew = "BAF_Soldier_MTP";
		typicalCargo[] = {"BAF_Soldier_MTP","BAF_Soldier_DDPM"};
	};
	class ACE_BAF_M119_W: ACE_BAF_M119_D
	{
		crew = "BAF_Soldier_DDPM";
		vehicleClass = "StaticW";
	};
	class M2StaticMG_base: StaticMGWeapon{};
	class MK19_TriPod: StaticGrenadeLauncher
	{
		displayName = "Mk19 Mod 3";
	};
	class TOW_TriPod_Base: StaticATWeapon
	{
		displayName = "M220 TOW-2A";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev = -20;
				maxElev = 30;
				weapons[] = {"TOWLauncherSingle"};
				magazines[] = {"ACE_TOW2","ACE_TOW2","ACE_TOW2"};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
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
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {2,3};
				};
			};
		};
	};
	class TOW_TriPod_US_EP1: TOW_TriPod_Base{};
	class Stinger_Pod_base: StaticAAWeapon
	{
		displayName = "FIM-92F Stinger";
	};
	class M252_Base;
	class M252_US_EP1: M252_Base
	{
		displayName = "$STR_ACE_DN_M252";
	};
	class DSHKM_Base: StaticMGWeapon
	{
		displayName = "$STR_ACE_VDN_DSHKM_BASE";
	};
	class KORD_Base: StaticMGWeapon
	{
		displayName = "$STR_ACE_VDN_KORD_BASE";
	};
	class KORD: KORD_Base{};
	class KORD_high: KORD
	{
		displayName = "$STR_ACE_VDN_KORD_HIGH";
	};
	class AGS_base: StaticGrenadeLauncher
	{
		displayName = "$STR_ACE_VDN_AGS_BASE";
	};
	class SPG9_base: StaticATWeapon
	{
		displayName = "$STR_ACE_VDN_SPG9_BASE";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class OpticsIn
				{
					class HEAT
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9heat";
						initFov = 0.073143;
						minFov = 0.073143;
						maxFov = 0.073143;
						visionMode[] = {"Normal"};
					};
					class HE: HEAT
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pgok9he";
					};
				};
			};
		};
	};
	class Metis: StaticATWeapon
	{
		displayName = "$STR_ACE_VDN_METIS";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"AT13LauncherSingle"};
				magazines[] = {"ACE_AT13","ACE_AT13","ACE_AT13"};
				minElev = -5;
				maxElev = 10;
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewOptics
				{
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {4};
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.078;
					minFov = 0.078;
					maxFov = 0.078;
				};
			};
		};
	};
	class ZU23_base: StaticCanon
	{
		displayName = "$STR_ACE_VDN_ZU23_BASE";
		class AnimationSources
		{
			class fire_anim
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0.003;
			};
		};
	};
	class Igla_AA_pod_East: StaticAAWeapon
	{
		displayName = "$STR_ACE_VDN_IGLA_AA_POD_EAST";
	};
	class Boat: Ship
	{
		class Turrets;
	};
	class RHIB: Boat
	{
		enableManualFire = 0;
		displayName = "RHIB";
		maxSpeed = 80;
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class RHIB2Turret: RHIB
	{
		accuracy = 1000;
		displayName = "RHIB (Mk19)";
		maxSpeed = 75;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret{};
			class BackTurret: MainTurret
			{
				weapons[] = {"ACE_MK19"};
			};
		};
	};
	class Land_runway_edgelight: House
	{
		class DestructionEffects{};
	};
	class Land_NavigLight: House
	{
		class DestructionEffects{};
	};
	class ACE_TankWreckTurret_Base: Car
	{
		accuracy = 0;
		scope = 1;
		model = "\x\ace\addons\m_veh_wrecks\ACE_T72_Turret";
		icon = "\Ca\characters\data\map_ico\i_wojak_CA.paa";
		mapSize = 3;
		displayName = "$STR_ACE_VDN_WRECKTURRET";
		class AnimationSources
		{
			class TurretDirection
			{
				source = "user";
				animPeriod = 0.001;
				initPhase = 0;
			};
		};
	};
	class ACE_T72WreckTurret: ACE_TankWreckTurret_Base
	{
		displayName = "$STR_ACE_VDN_T72WRECKTURRET";
	};
	class ACE_TankWreck_Base: Car
	{
		accuracy = 0;
		scope = 1;
		model = "\x\ace\addons\m_veh_wrecks\ACE_T72_Wreck";
		icon = "\Ca\tracked\Data\map_ico\icomap_t72_CA.paa";
		mapSize = 3;
		displayName = "$STR_DN_TANK";
		class AnimationSources
		{
			class TurretDirection
			{
				source = "user";
				animPeriod = 0.001;
				initPhase = 0;
			};
		};
	};
	class ACE_T72Wreck: ACE_TankWreck_Base
	{
		displayName = "$STR_ACE_VDN_T72_BASE";
	};
	class ACE_GarbageLogic: ACE_Logic
	{
		scope = 1;
		displayName = "";
	};
	class ACE_S2G: ACE_GarbageLogic{};
	class ACE_DisableCAS: ACE_GarbageLogic{};
	class ACE_EnableCAS: ACE_GarbageLogic{};
	class ACE_Help: ACE_GarbageLogic{};
	class RAV_Lifter: ACE_GarbageLogic{};
	class Land_Wall_Gate_Ind1_L;
	class Land_Wall_Gate_Ind1_R: Land_Wall_Gate_Ind1_L
	{
		class UserActions
		{
			class OpenDoors;
		};
	};
	class Land_Wall_Gate_Village: Land_Wall_Gate_Ind1_R
	{
		class UserActions: UserActions
		{
			class OpenDoors: OpenDoors
			{
				radius = 2.5;
			};
		};
	};
	class Land_Wall_Gate_Wood1: Land_Wall_Gate_Ind1_R
	{
		class UserActions: UserActions
		{
			class OpenDoors: OpenDoors
			{
				radius = 2;
			};
		};
	};
	class Land_Gate_wood2_5: Land_Wall_Gate_Ind1_R
	{
		class UserActions: UserActions
		{
			class OpenDoors: OpenDoors
			{
				radius = 2;
			};
		};
	};
	class Land_Gate_Wood1_5: Land_Wall_Gate_Ind1_R
	{
		class UserActions: UserActions
		{
			class OpenDoors: OpenDoors
			{
				radius = 2;
			};
		};
	};
	class CraterLong: NonStrategic
	{
		displayName = "";
		camouflage = 0;
		accuracy = 0;
	};
	class BIS_alice_emptydoor: Car
	{
		ace_camshake_enabled = 1;
		ace_canbecargo = 0;
		ace_canbeload = 0;
		ace_cargo_exposed = 1;
		ace_exposed = 1;
		ace_sa_enabled = 0;
		ace_sa_te_enabled = 0;
		ace_sys_eject_eject = 0;
		ace_sys_eject_jump = 0;
		ace_sys_eject_side = 0;
		ace_sys_repair_rearm = 0;
		ace_sys_repair_refuel = 0;
		ace_sys_repair_repair = 0;
		ace_sys_repair_spare_tyres = 0;
		ace_sys_repair_threshold = 0.8;
		ace_sys_repair_threshold_refuel = 1;
		ace_sys_repair_time = 10;
		ace_tankfcs_enabled = 0;
		displayName = "$STR_DN_HOUSE";
		TextPlural = "$STR_DN_HOUSES";
		TextSingular = "$STR_DN_HOUSE";
		nameSound = "obj_house";
		accuracy = 0;
		camouflage = 0;
		cargoIsCoDriver[] = {0};
		irTarget = 0;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"obj_house"};
				speechPlural[] = {"obj_houses"};
			};
			class EN: Default{};
			class CZ
			{
				speechSingular[] = {"obj_house_CZ"};
				speechPlural[] = {"obj_houses_CZ"};
			};
			class CZ_Akuzativ
			{
				speechSingular[] = {"obj_house_CZ4P"};
				speechPlural[] = {"obj_houses_CZ4P"};
			};
			class RU
			{
				speechSingular[] = {"obj_house_RU"};
				speechPlural[] = {"obj_houses_RU"};
			};
		};
	};
	class FoldChair_with_Cargo: Car
	{
		accuracy = 0;
		scope = 1;
		vehicleClass = "Furniture";
		class TransportWeapons{};
		class TransportMagazines{};
		transportmaxbackpacks = 0;
		transportmaxmagazines = 0;
		transportmaxweapons = 0;
	};
};
class CfgMagazines
{
	class Default;
	class VehicleMagazine;
	class 20Rnd_120mmHE_M1A2: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_120MM_M830A1_HEAT_MP_T";
		ammo = "Sh_120_HE";
		initSpeed = 1400;
		displayNameShort = "HEAT-MP-T";
		tracersEvery = 1;
	};
	class ACE_6Rnd_120mmHE_M1A2: 20Rnd_120mmHE_M1A2
	{
		count = 6;
	};
	class ACE_8Rnd_120mmHE_M1A2: ACE_6Rnd_120mmHE_M1A2
	{
		count = 8;
	};
	class ACE_15Rnd_120mmHE_M1A2: ACE_6Rnd_120mmHE_M1A2
	{
		count = 15;
	};
	class 20Rnd_120mmSABOT_M1A2: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_120MM_M829A3_APFSDS_T";
		initSpeed = 1545;
		tracersEvery = 1;
		displayNameShort = "APFSDS-T";
	};
	class ACE_22Rnd_120mmSABOT_M1A2: 20Rnd_120mmSABOT_M1A2
	{
		count = 22;
	};
	class ACE_30Rnd_120mmSABOT_M1A2: 20Rnd_120mmSABOT_M1A2
	{
		count = 30;
	};
	class ACE_25Rnd_120mmSABOT_M1A2: 20Rnd_120mmSABOT_M1A2
	{
		count = 25;
	};
	class ACE_4Rnd_M1028: 20Rnd_120mmHE_M1A2
	{
		displayName = "$STR_ACE_MDN_120MM_M1018_CANISTER";
		displayNameShort = "CANISTER";
		ammo = "ACE_M1028_Pellet";
		initSpeed = 1410;
		count = 4;
	};
	class ACE_5Rnd_M1028: ACE_4Rnd_M1028
	{
		count = 5;
	};
	class ACE_9Rnd_M900: 20Rnd_120mmSABOT_M1A2
	{
		displayName = "$STR_ACE_MDN_105MM_M900_APFSDS_T";
		ammo = "ACE_M900Round";
		initSpeed = 1505;
		count = 9;
	};
	class ACE_9Rnd_M456A2: 20Rnd_120mmHE_M1A2
	{
		displayName = "$STR_ACE_MDN_105MM_M456A2_HEAT_T";
		ammo = "ACE_M456A2Round";
		initSpeed = 1174;
		count = 9;
	};
	class 30Rnd_105mmHE_M119: VehicleMagazine{};
	class 6RND_105mm_APDS: 30Rnd_105mmHE_M119
	{
		displayName = "$STR_ACE_MDN_105MM_M900_APFSDS_T";
		displayNameShort = "APFSDS-T";
		descriptionShort = "Caliber: 105mm APFSDS-T<br/>Rounds: 6<br/>Used in: Stryker MGS";
		ammo = "Sh_105_APDS";
		count = 6;
	};
	class 12RND_105mm_HESH: 30Rnd_105mmHE_M119
	{
		displayName = "$STR_ACE_MDN_105MM_M456A2_HEAT_T";
		displayNameShort = "HEAT-MP-T";
		descriptionShort = "Caliber: 105mm HEAT-MP-T<br/>Rounds: 12<br/>Used in: Stryker MGS";
		ammo = "Sh_105_HESH";
		count = 12;
	};
	class 22Rnd_125mmHE_T72: VehicleMagazine
	{
		scope = 2;
		displayName = "$STR_ACE_MDN_125MM_3OF26_HE_F_FS_T";
		displayNameShort = "$STR_ACE_MDNS_125MM_3OF26_HE_F_FS_T";
		ammo = "Sh_125_HE";
		count = 13;
		initSpeed = 850;
		maxLeadSpeed = 100;
		nameSound = "heat";
	};
	class ACE_8Rnd_3OF26: 22Rnd_125mmHE_T72
	{
		count = 8;
	};
	class 23Rnd_125mmSABOT_T72: VehicleMagazine
	{
		scope = 2;
		displayName = "$STR_ACE_MDN_125MM_3BM42_APFSDS_T";
		displayNameShort = "$STR_ACE_MDNS_125MM_3BM42_APFSDS_T";
		ammo = "Sh_125_SABOT";
		count = 15;
		initSpeed = 1700;
	};
	class ACE_3BM17: 23Rnd_125mmSABOT_T72
	{
		displayName = "$STR_ACE_MDN_125MM_3BM17_APFSDS_T";
		displayNameShort = "$STR_ACE_MDNS_125MM_3BM17_APFSDS_T";
		ammo = "ACE_3BM17MRound";
		initSpeed = 1780;
	};
	class ACE_3BM42M: 23Rnd_125mmSABOT_T72
	{
		displayName = "$STR_ACE_MDN_125MM_3BM42M_APFSDS_T";
		displayNameShort = "$STR_ACE_MDNS_125MM_3BM42M_APFSDS_T";
		ammo = "ACE_3BM42MRound";
		count = 13;
		initSpeed = 1750;
	};
	class ACE_3BK29: 23Rnd_125mmSABOT_T72
	{
		displayName = "$STR_ACE_MDN_125MM_3BK29_HEAT_FS_T";
		displayNameShort = "$STR_ACE_MDNS_125MM_3BK29_HEAT_FS_T";
		ammo = "ACE_3BK29Round";
		count = 16;
		initSpeed = 915;
		nameSound = "heat";
	};
	class ACE_3BK18: ACE_3BK29
	{
		displayName = "$STR_ACE_MDN_125MM_3BK18_HEAT_FS_T";
		displayNameShort = "$STR_ACE_MDNS_125MM_3BK18_HEAT_FS_T";
		initSpeed = 905;
		ammo = "ACE_3BK18Round";
	};
	class ACE_3BK29M: ACE_3BK29
	{
		displayName = "$STR_ACE_MDN_125MM_3BK29M_HEAT_FS_T";
		displayNameShort = "$STR_ACE_MDNS_125MM_3BK29M_HEAT_FS_T";
		ammo = "ACE_3BK29MRound";
	};
	class 33Rnd_85mmHE: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_85MM_O365K_HE_FRAG_T";
		displayNameShort = "$STR_ACE_MDNS_85MM_O365K_HE_FRAG_T";
		ammo = "Sh_85_HE";
		count = 36;
		initSpeed = 793;
		tracersEvery = 1;
	};
	class 10Rnd_85mmAP: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_85MM_BR365_AP_T";
		displayNameShort = "$STR_ACE_MDNS_85MM_BR365_AP_T";
		ammo = "Sh_85_AP";
		count = 14;
		initSpeed = 800;
		tracersEvery = 1;
	};
	class ACE_BR365P: 10Rnd_85mmAP
	{
		displayName = "$STR_ACE_MDN_85MM_BR365P_APDS_T";
		displayNameShort = "$STR_ACE_MDNS_85MM_BR365P_APDS_T";
		ammo = "ACE_BR365PRound";
		count = 5;
		initSpeed = 1050;
	};
	class 22Rnd_100mm_HE_2A70: 22Rnd_125mmHE_T72
	{
		displayName = "$STR_ACE_MDN_100MM_3OF32_HE_F_FS_T";
		displayNameShort = "$STR_ACE_MDNS_100MM_3OF32_HE_F_FS_T";
		ammo = "Sh_100_HE";
		count = 40;
		initSpeed = 440;
	};
	class 21Rnd_100mmHEAT_D10: VehicleMagazine
	{
		displayName = "3BK17 HEAT-FS-T";
		ammo = "Sh_100_HEAT";
		count = 21;
		initSpeed = 900;
		tracersEvery = 1;
		maxLeadSpeed = 15;
		nameSound = "heat";
		displayNameShort = "HEAT-FS-T";
	};
	class ACE_22Rnd_100mm_OF412: 22Rnd_100mm_HE_2A70
	{
		displayName = "OF-412 HE-FRAG-T";
		ammo = "ACE_OF412Round";
		initSpeed = 900;
		maxLeadSpeed = 15;
		tracersEvery = 1;
		count = 22;
	};
	class ACE_6Rnd_100mm_3BM8: VehicleMagazine
	{
		scope = 2;
		displayName = "3BM8 HVAPDS-T";
		ammo = "ACE_3BM8Round";
		count = 6;
		initSpeed = 1415;
		maxLeadSpeed = 30;
		nameSound = "sabot";
		tracersEvery = 1;
		displayNameShort = "HVAPDS-T";
	};
	class ACE_6Rnd_100mm_BR412D: ACE_6Rnd_100mm_3BM8
	{
		displayName = "BR-412D APCBC-T";
		ammo = "ACE_BR412DRound";
		initSpeed = 887;
		maxLeadSpeed = 15;
		displayNameShort = "APCBC-T";
	};
	class ACE_24Rnd_73mm_PG15V: VehicleMagazine
	{
		scope = 2;
		displayName = "$STR_ACE_MDN_73MM_PG15V";
		displayNameShort = "$STR_ACE_MDNS_73MM_PG15V";
		ammo = "ACE_PG15VRound";
		count = 24;
		nameSound = "heat";
		initSpeed = 700;
	};
	class ACE_16Rnd_73mm_OG15V: ACE_24Rnd_73mm_PG15V
	{
		displayName = "$STR_ACE_MDN_73MM_OG15V";
		displayNameShort = "$STR_ACE_MDNS_73MM_OG15V";
		ammo = "ACE_OG15VRound";
		count = 16;
		initSpeed = 316;
	};
	class 210Rnd_25mm_M242_HEI: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_25MM_M792_HEI_T";
		displayNameShort = "HEI-T";
		ammo = "B_25mm_HEI";
		count = 210;
		initSpeed = 1100;
		tracersEvery = 1;
	};
	class 210Rnd_25mm_M242_APDS: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_25MM_M791_APDS_T";
		displayNameShort = "APDS-T";
		ammo = "B_25mm_APDS";
		count = 210;
		initSpeed = 1345;
		tracersEvery = 1;
	};
	class ACE_230Rnd_25mm_M242_HEI: 210Rnd_25mm_M242_HEI
	{
		count = 230;
	};
	class ACE_70Rnd_25mm_M242_APFSDS: 210Rnd_25mm_M242_APDS
	{
		displayName = "$STR_ACE_MDN_25MM_M919_APFSDS_T";
		displayNameShort = "APFSDS-T";
		ammo = "ACE_B_25mm_APFSDS";
		count = 70;
		initSpeed = 1420;
	};
	class 750Rnd_M197_AH1: VehicleMagazine
	{
		initSpeed = 1050;
		tracersEvery = 1;
		ammo = "B_20mm_AP";
		displayNameShort = "SAPHEI-T";
		displayName = "$STR_ACE_MDN_20MM_PGU28B_SAPHEI_T";
	};
	class 2100Rnd_20mm_M168: VehicleMagazine
	{
		tracersEvery = 3;
		initSpeed = 1050;
		displayName = "$STR_ACE_MDN_20MM_PGU28B_SAPHEI_T";
		displayNameShort = "SAPHEI-T";
		ammo = "B_20mm_AA";
	};
	class 1350Rnd_30mmAP_A10: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_30MM_PGU14AB_API_T";
		displayNameShort = "API-T";
		ammo = "B_30mmA10_AP";
		count = 1350;
		initSpeed = 990;
	};
	class 300Rnd_25mm_GAU12: VehicleMagazine
	{
		tracersEvery = 1;
		displayName = "$STR_ACE_MDN_25MM_M792_HEI_T";
		displayNameShort = "HEI-T";
	};
	class 1200Rnd_30x113mm_M789_HEDP: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_30MM_M789_HEDP_T";
		ammo = "B_30x113mm_M789_HEDP";
		displayNameShort = "HEDP-T";
	};
	class 1200Rnd_762x51_M240: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_762X51_BALL";
		count = 1200;
		initSpeed = 838;
	};
	class ACE_1500Rnd_762x51_M240: 1200Rnd_762x51_M240
	{
		count = 1500;
	};
	class ACE_1100Rnd_762x51_M240: 1200Rnd_762x51_M240
	{
		count = 1100;
	};
	class ACE_1000Rnd_762x51_M240: 1200Rnd_762x51_M240
	{
		count = 1000;
	};
	class ACE_800Rnd_762x51_M240: 1200Rnd_762x51_M240
	{
		count = 800;
	};
	class ACE_400Rnd_762x51_M240: 1200Rnd_762x51_M240
	{
		count = 400;
	};
	class ACE_200Rnd_762x51_M240: 1200Rnd_762x51_M240
	{
		count = 200;
	};
	class 100Rnd_127x99_M2: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_127X99_BALL";
		count = 100;
		initSpeed = 887;
	};
	class ACE_200Rnd_127x99_M2_SLAP: 100Rnd_127x99_M2
	{
		displayName = "$STR_ACE_MDN_127X99_SLAP_T";
		displayNameShort = "SLAP-T";
		ammo = "ACE_B_127x99_SLAP";
		initSpeed = 1219;
		tracersEvery = 1;
		count = 200;
	};
	class ACE_200Rnd_556x45_M249: 1200Rnd_762x51_M240
	{
		displayName = "$STR_DN_200RND_M249";
		count = 200;
		ammo = "B_556x45_Ball";
	};
	class 2000Rnd_762x51_M134;
	class 2000Rnd_762x51_L94A1: 2000Rnd_762x51_M134
	{
		initspeed = 838;
		tracersevery = 4;
		ammo = "B_762x51_Ball";
	};
	class ACE_900Rnd_127x99_GAU19: VehicleMagazine
	{
		scope = 2;
		ammo = "B_127x99_Ball";
		count = 900;
		initSpeed = 887;
		displayName = "$STR_ACE_MDN_127X99_BALL";
		tracersevery = 1;
	};
	class 4000Rnd_762x51_M134: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_762X51_BALL";
		tracersEvery = 1;
	};
	class ACE_2625Rnd_762x51_M134: 4000Rnd_762x51_M134
	{
		count = 2625;
	};
	class ACE_5250Rnd_762x51_M134: 4000Rnd_762x51_M134
	{
		count = 5250;
	};
	class 48Rnd_40mm_MK19: VehicleMagazine
	{
		ammo = "ACE_M430Round";
	};
	class 500Rnd_145x115_KPVT: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_145X115_BZT";
		displayNameShort = "$STR_ACE_MDNS_145X115_BZT";
		tracersEvery = 3;
		initSpeed = 976;
		ammo = "B_145x115_AP";
	};
	class ACE_50Rnd_145x114_KPVT: 500Rnd_145x115_KPVT
	{
		scope = 2;
		count = 50;
	};
	class 100Rnd_762x54_PK;
	class 60Rnd_762x54_DT: 100Rnd_762x54_PK
	{
		displayName = "$STR_ACE_MDN_762X54_BALL";
		ammo = "B_762x54_Ball";
	};
	class 1500Rnd_762x54_PKT: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_762X54_BALL";
		initspeed = 855;
	};
	class 50Rnd_127x107_DSHKM: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_127X108_B32";
		displayNameShort = "$STR_ACE_MDNS_127X108_B32";
		ammo = "B_127x107_Ball";
		initSpeed = 840;
		tracersEvery = 5;
	};
	class 150Rnd_127x107_DSHKM: 50Rnd_127x107_DSHKM
	{
		displayName = "$STR_ACE_MDN_127X108_B32";
		count = 150;
	};
	class 150Rnd_127x108_KORD: 150Rnd_127x107_DSHKM
	{
		displayName = "$STR_ACE_MDN_127X108_B32";
	};
	class 50Rnd_127x108_KORD: 50Rnd_127x107_DSHKM
	{
		displayName = "$STR_ACE_MDN_127X108_B32";
	};
	class 2000Rnd_23mm_AZP85: VehicleMagazine
	{
		ammo = "ACE_B_23mm_ZSU";
		displayName = "$STR_ACE_MDN_23X152_OFZT";
		displayNameShort = "$STR_ACE_MDNS_23X152_OFZT";
		tracersEvery = 1;
		maxLeadSpeed = 900;
	};
	class ACE_4x50Rnd_23mm_OFZT: 2000Rnd_23mm_AZP85
	{
		count = 200;
	};
	class 40Rnd_23mm_AZP85: 2000Rnd_23mm_AZP85
	{
		ammo = "B_23mm_AA";
		count = 40;
	};
	class 1000Rnd_23mm_2A14_HE: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_23X152_OFZT";
		displayNameShort = "$STR_ACE_MDNS_23X152_OFZT";
		tracersEvery = 1;
	};
	class 1000Rnd_23mm_2A14_AP: 1000Rnd_23mm_2A14_HE
	{
		displayName = "$STR_ACE_MDN_23X152_BZT";
		displayNameShort = "$STR_ACE_MDNS_23X152_BZT";
		tracersEvery = 1;
	};
	class 520Rnd_23mm_GSh23L: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_23X115_AM23";
		displayNameShort = "$STR_ACE_MDNS_23X115_AM23";
		tracersEvery = 3;
		initspeed = 715;
	};
	class ACE_500Rnd_23mm_UPK23: 520Rnd_23mm_GSh23L
	{
		count = 500;
	};
	class 230Rnd_30mmHE_2A42: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_30x165_3UOF8_OFZT";
		displayNameShort = "$STR_ACE_MDNS_30x165_3UOF8_OFZT";
		ammo = "B_30mm_HE";
		count = 230;
		initSpeed = 960;
		tracersEvery = 3;
	};
	class 230Rnd_30mmAP_2A42: 230Rnd_30mmHE_2A42
	{
		displayName = "$STR_ACE_MDN_30x165_3UBR8_BT";
		displayNameShort = "$STR_ACE_MDNS_30x165_3UBR8_BT";
		ammo = "B_30mm_AP";
		tracersEvery = 1;
		initSpeed = 1120;
	};
	class 250Rnd_30mmHE_2A42: 230Rnd_30mmHE_2A42
	{
		displayNameShort = "$STR_ACE_MDNS_30x165_3UOF8_OFZT";
		count = 340;
	};
	class 250Rnd_30mmAP_2A42: 230Rnd_30mmAP_2A42
	{
		displayNameShort = "$STR_ACE_MDNS_30x165_3UBR8_BT";
		count = 160;
	};
	class 150Rnd_30mmHE_2A42: 230Rnd_30mmHE_2A42
	{
		displayNameShort = "$STR_ACE_MDNS_30x165_3UOF8_OFZT";
		count = 130;
	};
	class 150Rnd_30mmAP_2A42: 230Rnd_30mmAP_2A42
	{
		displayNameShort = "$STR_ACE_MDNS_30x165_3UBR8_BT";
		count = 70;
	};
	class ACE_120Rnd_30mmHE_2A42: 230Rnd_30mmHE_2A42
	{
		count = 120;
	};
	class ACE_180Rnd_30mmAP_2A42: 230Rnd_30mmAP_2A42
	{
		count = 180;
	};
	class 250Rnd_30mmHE_2A72: 250Rnd_30mmHE_2A42
	{
		displayName = "$STR_ACE_MDN_30x165_3UOF8_OFZT";
		displayNameShort = "$STR_ACE_MDNS_30x165_3UOF8_OFZT";
		count = 305;
	};
	class 250Rnd_30mmAP_2A72: 250Rnd_30mmAP_2A42
	{
		displayName = "$STR_ACE_MDN_30x165_3UBR8_BT";
		displayNameShort = "$STR_ACE_MDNS_30x165_3UBR8_BT";
		count = 195;
	};
	class 1904Rnd_30mmAA_2A38M: 230Rnd_30mmHE_2A42
	{
		displayName = "$STR_ACE_MDN_30x165_3UOF8_OFZT";
		displayNameShort = "$STR_ACE_MDNS_30x165_3UOF8_OFZT";
		tracersEvery = 1;
		ammo = "B_30mm_AA";
	};
	class 1470Rnd_127x108_YakB: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_127X108_1SL";
		displayNameShort = "$STR_ACE_MDNS_127X108_1SL";
		initSpeed = 840;
		tracersEvery = 1;
	};
	class ACE_1470Rnd_127x108_1SL: 1470Rnd_127x108_YakB
	{
		ammo = "ACE_B_127x108_1SL";
	};
	class 180Rnd_30mm_GSh301: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_30x165_3UBR8_BT";
		displayNameShort = "$STR_ACE_MDNS_30x165_3UBR8_BT";
		ammo = "ACE_B_30mm_APHE";
		initSpeed = 820;
		tracersEvery = 2;
	};
	class ACE_180Rnd_30mm_GSh301: 180Rnd_30mm_GSh301{};
	class ACE_150Rnd_30mm_GSh301: ACE_180Rnd_30mm_GSh301
	{
		count = 150;
	};
	class 750Rnd_30mm_GSh301: 180Rnd_30mm_GSh301
	{
		count = 750;
		displayName = "$STR_ACE_MDN_30x165_3UBR8_BT";
		displayNameShort = "$STR_ACE_MDNS_30x165_3UBR8_BT";
		ammo = "ACE_B_30mm_APHE";
		tracersEvery = 1;
		initSpeed = 960;
	};
	class ACE_250Rnd_30mm_GSh302: 750Rnd_30mm_GSh301
	{
		displayNameShort = "$STR_ACE_MDNS_30x165_3UBR8_BT";
		count = 250;
		initSpeed = 890;
	};
	class 1200Rnd_20mm_M621: 1200Rnd_762x51_M240
	{
		ace_magxchange = "";
		ammo = "B_20mm_AP";
		count = 400;
		initSpeed = 1050;
		displayNameShort = "SAPHEI-T";
		displayName = "$STR_ACE_MDN_20MM_PGU28B_SAPHEI_T";
		namesound = "cannon";
		tracersEvery = 1;
	};
	class 14Rnd_FFAR: VehicleMagazine
	{
		displayNameShort = "HE";
		initSpeed = 0.1;
	};
	class 38Rnd_FFAR: 14Rnd_FFAR
	{
		displayNameShort = "HE";
		initSpeed = 0.1;
	};
	class ACE_7Rnd_70mm_FFAR_HE: 14Rnd_FFAR
	{
		count = 7;
	};
	class ACE_19Rnd_70mm_FFAR_HE: 14Rnd_FFAR
	{
		count = 19;
	};
	class 12Rnd_CRV7: 38Rnd_FFAR
	{
		displayNameShort = "FAT-PG";
	};
	class 38Rnd_CRV7: 12Rnd_CRV7{};
	class 6Rnd_CRV7_HEPD: 38Rnd_FFAR
	{
		displayNameShort = "HE";
	};
	class 6Rnd_CRV7_FAT: 38Rnd_FFAR
	{
		displayNameShort = "FAT";
	};
	class 40Rnd_80mm: VehicleMagazine
	{
		displayNameShort = "$STR_MN_S8KOM";
		initSpeed = 0.1;
	};
	class 40Rnd_S8T: VehicleMagazine
	{
		displayNameShort = "$STR_MN_S8T";
		initSpeed = 0.1;
	};
	class 64Rnd_57mm: VehicleMagazine
	{
		displayNameShort = "$STR_MN_S5KO";
		initSpeed = 0.1;
	};
	class ACE_64Rnd_57mm: 64Rnd_57mm{};
	class ACE_32Rnd_57mm: 64Rnd_57mm
	{
		count = 32;
	};
	class CA_LauncherMagazine;
	class PG9_AT: CA_LauncherMagazine
	{
		displayName = "$STR_ACE_MDN_PG9";
		displayNameShort = "$STR_ACE_MDNS_PG9";
		ammo = "R_PG9_AT";
		count = 1;
		initSpeed = 435;
	};
	class OG9_HE: CA_LauncherMagazine
	{
		displayName = "$STR_ACE_MDN_OG9";
		displayNameShort = "$STR_ACE_MDNS_OG9";
		ammo = "R_OG9_HE";
		count = 1;
		initSpeed = 316;
	};
	class 8Rnd_AT5_BMP2: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_AT5";
		displayNameShort = "$STR_ACE_MDNS_AT5";
		ammo = "M_AT5_AT";
		initSpeed = 80;
	};
	class ACE_AT5: 8Rnd_AT5_BMP2
	{
		count = 1;
	};
	class 5Rnd_AT5_BRDM2: 8Rnd_AT5_BMP2
	{
		count = 5;
	};
	class ACE_AT5B: 8Rnd_AT5_BMP2
	{
		displayName = "$STR_ACE_MDN_AT5B";
		displayNameShort = "$STR_ACE_MDNS_AT5B";
		ammo = "ACE_9M113M";
		count = 1;
	};
	class ACE_5Rnd_AT5B_BRDM2: 5Rnd_AT5_BRDM2
	{
		displayName = "$STR_ACE_MDN_AT5B";
		displayNameShort = "$STR_ACE_MDNS_AT5B";
		ammo = "ACE_9M113M";
	};
	class ACE_AT3C: 8Rnd_AT5_BMP2
	{
		displayName = "$STR_ACE_MDN_AT3C";
		displayNameShort = "$STR_ACE_MDNS_AT3C";
		ammo = "ACE_M_AT3C_AT";
		count = 1;
	};
	class ACE_AT3P: ACE_AT3C
	{
		displayName = "$STR_ACE_MDN_AT3P";
		displayNameShort = "$STR_ACE_MDN_AT3P";
		ammo = "ACE_M_AT3P_AT";
	};
	class 5Rnd_AT11_T90: 8Rnd_AT5_BMP2
	{
		displayName = "$STR_ACE_MDN_AT11_T90";
		displayNameShort = "$STR_ACE_MDNS_AT11_T90";
		ammo = "M_AT11_AT";
		count = 6;
		initSpeed = 340;
	};
	class ACE_AT11: 5Rnd_AT11_T90
	{
		displayName = "$STR_ACE_MDN_AT11_T72";
		displayNameShort = "$STR_ACE_MDNS_AT11_T72";
		ammo = "ACE_9M119";
	};
	class 6Rnd_AT13: VehicleMagazine
	{
		scope = 2;
		displayName = "$STR_ACE_MDN_AT13_STATIC";
		displayNameShort = "$STR_ACE_MDNS_AT13_STATIC";
		ammo = "ACE_M_AT13_AT";
		initSpeed = 80;
		count = 6;
	};
	class ACE_AT13: 6Rnd_AT13
	{
		count = 1;
	};
	class 8Rnd_AT10_BMP3: 8Rnd_AT5_BMP2
	{
		displayName = "$STR_ACE_MDN_AT10";
		displayNameShort = "$STR_ACE_MDNS_AT10";
		ammo = "M_AT10_AT";
		initSpeed = 370;
		count = 8;
	};
	class ACE_AT10: 8Rnd_AT10_BMP3
	{
		count = 1;
	};
	class 4Rnd_AT2_Mi24D: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_AT2";
		displayNameShort = "$STR_ACE_MDNS_AT2";
		ammo = "M_AT2_AT";
		maxLeadSpeed = 10;
	};
	class 4Rnd_AT6_Mi24V: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_AT6";
		displayNameShort = "$STR_ACE_MDNS_AT6";
		ammo = "M_AT6_AT";
		maxLeadSpeed = 20;
		initSpeed = 55;
	};
	class 4Rnd_AT9_Mi24P: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_AT9";
		displayNameShort = "$STR_ACE_MDNS_AT9";
		maxLeadSpeed = 20;
		ammo = "ACE_M_AT9_Mi28";
		initSpeed = 55;
	};
	class ACE_4Rnd_AT9_Mi24V: 4Rnd_AT9_Mi24P
	{
		ammo = "M_AT9_AT";
		count = 4;
	};
	class ACE_16Rnd_AT9_Mi28: 4Rnd_AT9_Mi24P
	{
		ammo = "ACE_M_AT9_Mi28";
		count = 16;
	};
	class 12Rnd_Vikhr_KA50: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_VIKHR";
		displayNameShort = "$STR_ACE_MDNS_VIKHR";
		ammo = "M_Vikhr_AT";
		initSpeed = 0;
	};
	class 4Rnd_Ch29: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_CH29";
		displayNameShort = "$STR_ACE_MDN_CH29";
		ammo = "M_Ch29_AT";
		initSpeed = 0;
	};
	class 8Rnd_9M311: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_9M311";
		displayNameShort = "$STR_ACE_MDNS_9M311";
		ammo = "M_9M311_AA";
	};
	class ACE_9M31: VehicleMagazine
	{
		displayName = "$STR_ACE_MDN_9M31";
		displayNameShort = "$STR_ACE_MDNS_9M31";
		count = 1;
		initSpeed = 80;
		ammo = "M_Strela_AA";
	};
	class ACE_9M31_4: ACE_9M31
	{
		count = 4;
	};
	class ACE_9M31_2: ACE_9M31
	{
		count = 2;
	};
	class 8Rnd_Stinger: VehicleMagazine
	{
		displayName = "FIM-92F Stinger";
		displayNameShort = "FIM-92F";
	};
	class 2Rnd_Stinger: 8Rnd_Stinger{};
	class ACE_4Rnd_Stinger: 2Rnd_Stinger
	{
		count = 4;
	};
	class ACE_1Rnd_Stinger: 2Rnd_Stinger
	{
		count = 1;
	};
	class 6Rnd_TOW_HMMWV: VehicleMagazine
	{
		displayName = "BGM-71C iTOW";
		displayNameShort = "BGM-71C";
		ammo = "M_TOW_AT";
		initSpeed = 55.17;
	};
	class 2Rnd_TOW: 6Rnd_TOW_HMMWV
	{
		count = 2;
	};
	class ACE_TOW: 2Rnd_TOW
	{
		count = 1;
	};
	class 6Rnd_TOW2: 6Rnd_TOW_HMMWV
	{
		ammo = "M_TOW2_AT";
		displayName = "BGM-71E TOW-2A";
		displayNameShort = "BGM-71E";
	};
	class 2Rnd_TOW2: 6Rnd_TOW2
	{
		count = 2;
	};
	class ACE_TOW2: 2Rnd_TOW2
	{
		count = 1;
	};
	class ACE_TOW4: 2Rnd_TOW2
	{
		count = 4;
	};
	class ACE_TOW8: 2Rnd_TOW2
	{
		count = 8;
	};
	class 8Rnd_Hellfire: VehicleMagazine
	{
		displayName = "AGM-114K Hellfire II";
		displayNameShort = "AGM-114K";
		ammo = "M_Hellfire_AT";
		maxLeadSpeed = 50;
	};
	class ACE_8Rnd_DAGR: 8Rnd_Hellfire
	{
		displayName = "DAGR";
		displayNameShort = "HE";
		ammo = "ACE_M_DAGR_HE";
		maxLeadSpeed = 45;
		sound[] = {"\ca\weapons\Data\Sound\rockets\rocketLauncher_Shot21",3.16228,1};
	};
	class ACE_8Rnd_Hellfire_L: 8Rnd_Hellfire
	{
		displayName = "AGM-114L Hellfire II";
		displayNameShort = "AGM-114L";
		ammo = "ACE_M_HellfireL_AT";
	};
	class 2Rnd_Maverick_A10: VehicleMagazine
	{
		displayName = "AGM-65D Maverick";
		displayNameShort = "AGM-65D";
		ammo = "M_Maverick_AT";
		initSpeed = 0;
	};
	class 4Rnd_Sidewinder_AV8B: VehicleMagazine
	{
		displayName = "AIM-9X Sidewinder";
		displayNameShort = "AIM-9X";
	};
	class 2Rnd_Sidewinder_AH1Z: 4Rnd_Sidewinder_AV8B
	{
		count = 2;
	};
	class 4Rnd_R73;
	class FakeMagazine: Default
	{
		count = 0;
	};
	class Laserbatteries;
	class ACE_SACLOS_Guidance: Laserbatteries
	{
		type = 65536;
	};
	class 6Rnd_GBU12_AV8B: VehicleMagazine
	{
		displayName = "GBU-12D/B Paveway";
		displayNameShort = "GBU-12D/B";
		maxLeadSpeed = 1000;
	};
	class ACE__1Rnd_B61_03: VehicleMagazine
	{
		ace_bwc = 1;
	};
	class ACE__1Rnd_B61_15: ACE__1Rnd_B61_03{};
	class ACE__1Rnd_B61_50: ACE__1Rnd_B61_03{};
	class ACE_1Rnd_Empty_Dummy: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_Empty_Dummy";
	};
	class ACE_3Rnd_Empty_Dummy: ACE_1Rnd_Empty_Dummy
	{
		count = 3;
	};
	class ACE_4Rnd_Empty_Dummy: ACE_1Rnd_Empty_Dummy
	{
		count = 4;
	};
	class ACE_8Rnd_Empty_Dummy: ACE_1Rnd_Empty_Dummy
	{
		count = 8;
	};
	class ACE_12Rnd_Empty_Dummy: ACE_1Rnd_Empty_Dummy
	{
		count = 12;
	};
	class ACE_16Rnd_Empty_Dummy: ACE_1Rnd_Empty_Dummy
	{
		count = 16;
	};
	class ACE_1Rnd_Mk82Rack: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_MK82Rack";
	};
	class ACE_1Rnd_AGM65Rack: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_AGM65Rack";
	};
	class ACE_1Rnd_AIM9Rail: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_AIM9Rail";
	};
	class ACE_1Rnd_HellfirePod: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_HellfirePod";
	};
	class ACE_1Rnd_LAU61: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_LAU61";
	};
	class ACE_1Rnd_LAU68: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_LAU68";
	};
	class ACE_1Rnd_TOW2: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_TOW2";
	};
	class ACE_1Rnd_TOW4: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_TOW4";
	};
	class ACE_1Rnd_S8T: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_S8T";
	};
	class ACE_2Rnd_S8T: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_S8T_2";
	};
	class ACE_1Rnd_UB16: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_UB16";
	};
	class ACE_1Rnd_UB32: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_UB32";
	};
	class ACE_1Rnd_B8V20: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_R_B8V20";
	};
	class ACE_1Rnd_UPK23: VehicleMagazine
	{
		scope = 2;
		displayName = "";
		count = 1;
		ammo = "ACE_G_UPK23";
	};
	class ACE_1Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 1;
	};
	class ACE_2Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_8Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 8;
		ACE_EASA = 0;
	};
	class ACE_10Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 10;
		ACE_EASA = 0;
	};
	class ACE_12Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 12;
		ACE_EASA = 0;
	};
	class ACE_14Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 14;
		ACE_EASA = 0;
	};
	class ACE_16Rnd_Hellfire: 8Rnd_Hellfire
	{
		count = 16;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 1;
	};
	class ACE_2Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_10Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 10;
		ACE_EASA = 0;
	};
	class ACE_12Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 12;
		ACE_EASA = 0;
	};
	class ACE_14Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 14;
		ACE_EASA = 0;
	};
	class ACE_16Rnd_Hellfire_L: ACE_8Rnd_Hellfire_L
	{
		count = 16;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_Sidewinder: 4Rnd_Sidewinder_AV8B
	{
		count = 1;
	};
	class ACE_2Rnd_Sidewinder: 4Rnd_Sidewinder_AV8B
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_GBU12: 6Rnd_GBU12_AV8B
	{
		ammo = "ACE_Bo_GBU12_LGB";
	};
	class 4Rnd_FAB_250;
	class ACE_1Rnd_FAB_250: 4Rnd_FAB_250
	{
		count = 1;
	};
	class ACE_2Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_8Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 8;
		ACE_EASA = 0;
	};
	class ACE_10Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 10;
		ACE_EASA = 0;
	};
	class ACE_12Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 12;
		ACE_EASA = 0;
	};
	class ACE_14Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 14;
		ACE_EASA = 0;
	};
	class ACE_16Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 16;
		ACE_EASA = 0;
	};
	class ACE_18Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 18;
		ACE_EASA = 0;
	};
	class ACE_20Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 20;
		ACE_EASA = 0;
	};
	class ACE_22Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 22;
		ACE_EASA = 0;
	};
	class ACE_24Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 24;
		ACE_EASA = 0;
	};
	class ACE_26Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 26;
		ACE_EASA = 0;
	};
	class ACE_28Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 28;
		ACE_EASA = 0;
	};
	class ACE_30Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 30;
		ACE_EASA = 0;
	};
	class ACE_31Rnd_FAB_250: ACE_1Rnd_FAB_250
	{
		count = 31;
		ACE_EASA = 0;
	};
	class 6Rnd_Mk82;
	class ACE_1Rnd_Mk82: 6Rnd_Mk82
	{
		ammo = "ACE_Bo_Mk82";
		count = 1;
	};
	class ACE_2Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_3Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 3;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_8Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 8;
		ACE_EASA = 0;
	};
	class ACE_12Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 12;
		ACE_EASA = 0;
	};
	class ACE_14Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 14;
		ACE_EASA = 0;
	};
	class ACE_18Rnd_Mk82: ACE_1Rnd_Mk82
	{
		count = 18;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_R73: 4Rnd_R73
	{
		count = 1;
		ammo = "ACE_M_R73_AA";
	};
	class ACE_2Rnd_R73: ACE_1Rnd_R73
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_R73: ACE_1Rnd_R73
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_R73: ACE_1Rnd_R73
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_R27: 4Rnd_R73
	{
		displayName = "R-27";
		count = 1;
		ammo = "ACE_M_R27_AA";
	};
	class ACE_2Rnd_R27: ACE_1Rnd_R27
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_R27: ACE_1Rnd_R27
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_R27: ACE_1Rnd_R27
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_Kh29: 4Rnd_Ch29
	{
		count = 1;
		ammo = "ACE_M_Kh29_AT";
	};
	class ACE_2Rnd_Kh29: ACE_1Rnd_Kh29
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_Kh29: ACE_1Rnd_Kh29
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_Kh29: ACE_1Rnd_Kh29
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_Maverick: 2Rnd_Maverick_A10
	{
		count = 1;
	};
	class ACE_20Rnd_S8T: 40Rnd_S8T
	{
		ammo = "ACE_R_S8T_AT";
		count = 20;
	};
	class ACE_40Rnd_S8T: ACE_20Rnd_S8T
	{
		count = 40;
		ACE_EASA = 0;
	};
	class ACE_80Rnd_S8T: ACE_20Rnd_S8T
	{
		count = 80;
		ACE_EASA = 0;
	};
	class ACE_120Rnd_S8T: ACE_20Rnd_S8T
	{
		count = 120;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_Kh25: 4Rnd_R73
	{
		displayName = "Kh-25 ML";
		count = 1;
		ammo = "ACE_M_Kh25_AT";
	};
	class ACE_2Rnd_Kh25: ACE_1Rnd_Kh25
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_Kh25: ACE_1Rnd_Kh25
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_Kh25: ACE_1Rnd_Kh25
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_FAB500M62: 6Rnd_Mk82
	{
		displayName = "FAB-500 M62";
		count = 1;
		ammo = "ACE_Bo_FAB500M62";
	};
	class ACE_2Rnd_FAB500M62: ACE_1Rnd_FAB500M62
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_FAB500M62: ACE_1Rnd_FAB500M62
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_FAB500M62: ACE_1Rnd_FAB500M62
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_8Rnd_FAB500M62: ACE_1Rnd_FAB500M62
	{
		count = 8;
		ACE_EASA = 0;
	};
	class ACE_10Rnd_FAB500M62: ACE_1Rnd_FAB500M62
	{
		count = 10;
		ACE_EASA = 0;
	};
	class ACE_12Rnd_FAB500M62: ACE_1Rnd_FAB500M62
	{
		count = 12;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_KAB500KR: 6Rnd_Mk82
	{
		displayName = "KAB-500 KR";
		count = 1;
		ammo = "ACE_Bo_KAB500KR_CGB";
	};
	class ACE_2Rnd_KAB500KR: ACE_1Rnd_KAB500KR
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_KAB500KR: ACE_1Rnd_KAB500KR
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_KAB500KR: ACE_1Rnd_KAB500KR
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ACE_1Rnd_KAB500L: 6Rnd_Mk82
	{
		displayName = "KAB-500 L";
		count = 1;
		ammo = "ACE_Bo_KAB500L_LGB";
	};
	class ACE_2Rnd_KAB500L: ACE_1Rnd_KAB500L
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_KAB500L: ACE_1Rnd_KAB500L
	{
		count = 4;
		ACE_EASA = 0;
	};
	class ACE_6Rnd_KAB500L: ACE_1Rnd_KAB500L
	{
		count = 6;
		ACE_EASA = 0;
	};
	class ARTY_30Rnd_105mmHE_M119;
	class ACE_ARTY_30Rnd_105mmHE_M119: ARTY_30Rnd_105mmHE_M119{};
	class ARTY_30Rnd_105mmWP_M119;
	class ACE_ARTY_30Rnd_105mmWP_M119: ARTY_30Rnd_105mmWP_M119{};
	class ARTY_30Rnd_105mmSADARM_M119;
	class ACE_ARTY_30Rnd_105mmSADARM_M119: ARTY_30Rnd_105mmSADARM_M119{};
	class ARTY_30Rnd_105mmLASER_M119;
	class ACE_ARTY_30Rnd_105mmLASER_M119: ARTY_30Rnd_105mmLASER_M119{};
	class ARTY_30Rnd_105mmSMOKE_M119;
	class ACE_ARTY_30Rnd_105mmSMOKE_M119: ARTY_30Rnd_105mmSMOKE_M119{};
	class ARTY_30Rnd_105mmILLUM_M119;
	class ACE_ARTY_30Rnd_105mmILLUM_M119: ARTY_30Rnd_105mmILLUM_M119{};
	class ARTY_8Rnd_81mmHE_M252;
	class ACE_ARTY_8Rnd_81mmHE_M252: ARTY_8Rnd_81mmHE_M252{};
	class ARTY_8Rnd_81mmWP_M252;
	class ACE_ARTY_8Rnd_81mmWP_M252: ARTY_8Rnd_81mmWP_M252{};
	class ARTY_8Rnd_81mmILLUM_M252;
	class ACE_ARTY_8Rnd_81mmILLUM_M252: ARTY_8Rnd_81mmILLUM_M252{};
	class ARTY_12Rnd_227mmHE_M270;
	class ACE_ARTY_12Rnd_227mmHE_M270: ARTY_12Rnd_227mmHE_M270{};
	class ARTY_30Rnd_122mmHE_D30;
	class ACE_ARTY_30Rnd_122mmHE_D30: ARTY_30Rnd_122mmHE_D30{};
	class ARTY_30Rnd_122mmWP_D30;
	class ACE_ARTY_30Rnd_122mmWP_D30: ARTY_30Rnd_122mmWP_D30{};
	class ARTY_30Rnd_122mmSADARM_D30;
	class ACE_ARTY_30Rnd_122mmSADARM_D30: ARTY_30Rnd_122mmSADARM_D30{};
	class ARTY_30Rnd_122mmLASER_D30;
	class ACE_ARTY_30Rnd_122mmLASER_D30: ARTY_30Rnd_122mmLASER_D30{};
	class ARTY_30Rnd_122mmSMOKE_D30;
	class ACE_ARTY_30Rnd_122mmSMOKE_D30: ARTY_30Rnd_122mmSMOKE_D30{};
	class ARTY_30Rnd_122mmILLUM_D30;
	class ACE_ARTY_30Rnd_122mmILLUM_D30: ARTY_30Rnd_122mmILLUM_D30{};
	class ARTY_8Rnd_82mmHE_2B14;
	class ACE_ARTY_8Rnd_82mmHE_2B14: ARTY_8Rnd_82mmHE_2B14{};
	class ARTY_8Rnd_82mmWP_2B14;
	class ACE_ARTY_8Rnd_82mmWP_2B14: ARTY_8Rnd_82mmWP_2B14{};
	class ARTY_8Rnd_82mmILLUM_2B14;
	class ACE_ARTY_8Rnd_82mmILLUM_2B14: ARTY_8Rnd_82mmILLUM_2B14{};
	class ARTY_40Rnd_120mmHE_BM21;
	class ACE_ARTY_40Rnd_120mmHE_BM21: ARTY_40Rnd_120mmHE_BM21{};
};
class CfgAmmo
{
	class Default;
	class BulletCore;
	class BulletBase;
	class LaserBombCore;
	class MissileBase;
	class RocketBase;
	class BombCore;
	class GrenadeCore;
	class ShellBase;
	class GrenadeBase;
	class SmokeShell;
	class Sh_81_HE: ShellBase
	{
		hit = 160;
		indirectHit = 42;
		indirectHitRange = 8.45;
	};
	class Sh_81_WP: Sh_81_HE
	{
		hit = 35;
		indirectHit = 21;
		indirectHitRange = 8.45;
	};
	class Sh_105_HE: ShellBase
	{
		hit = 250;
		indirecthit = 47;
		indirecthitrange = 10.24;
	};
	class Sh_105_WP: Sh_105_HE
	{
		hit = 60;
		indirecthit = 23.5;
		indirecthitrange = 10.24;
	};
	class Sh_82_HE: ShellBase
	{
		hit = 165;
		indirectHit = 40;
		indirectHitRange = 7.68;
	};
	class Sh_82_WP: Sh_82_HE
	{
		hit = 165;
		indirectHit = 20;
		indirectHitRange = 7.68;
	};
	class Sh_122_HE: ShellBase
	{
		hit = 340;
		indirecthit = 50;
		indirecthitrange = 11.52;
	};
	class Sh_122_WP: Sh_122_HE
	{
		hit = 60;
		indirecthit = 25;
		indirecthitrange = 11.52;
	};
	class ARTY_Sh_Base;
	class ARTY_Sh_81_HE: ARTY_Sh_Base
	{
		hit = 160;
		indirectHit = 40;
		indirectHitRange = 7.68;
	};
	class ARTY_Sh_81_WP: ARTY_Sh_81_HE
	{
		hit = 35;
		indirectHit = 20;
		indirectHitRange = 7.68;
	};
	class ARTY_Sh_105_HE: ARTY_Sh_Base
	{
		hit = 250;
		indirecthit = 47;
		indirecthitrange = 10.24;
	};
	class ARTY_Sh_105_WP: ARTY_Sh_105_HE
	{
		hit = 60;
		indirecthit = 23.5;
		indirecthitrange = 10.24;
	};
	class ARTY_Sh_82_HE: ARTY_Sh_Base
	{
		hit = 165;
		indirectHit = 42;
		indirectHitRange = 8.45;
	};
	class ARTY_Sh_82_WP: ARTY_Sh_82_HE
	{
		hit = 35;
		indirecthit = 21;
		indirectHitRange = 8.45;
	};
	class ARTY_Sh_122_HE: ARTY_Sh_Base
	{
		hit = 340;
		indirecthit = 50;
		indirecthitrange = 11.52;
	};
	class ARTY_Sh_122_WP: ARTY_Sh_122_HE
	{
		hit = 60;
		indirecthit = 25;
		indirecthitrange = 11.52;
	};
	class ACE_ARTY_Sh_Base: ARTY_Sh_Base
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class ARTY_Flare_Small;
	class ACE_ARTY_Flare_Small: ARTY_Flare_Small{};
	class ARTY_Flare_Medium;
	class ACE_ARTY_Flare_Medium: ARTY_Flare_Medium{};
	class ARTY_Sh_Base_NET;
	class ACE_ARTY_Sh_Base_NET: ARTY_Sh_Base_NET{};
	class ARTY_Sh_105_NET;
	class ACE_ARTY_Sh_105_NET: ARTY_Sh_105_NET{};
	class ACE_ARTY_Sh_105_WP_NET: ACE_ARTY_Sh_Base_NET{};
	class ARTY_Sh_105_NET_NOFX;
	class ACE_ARTY_Sh_105_NET_NOFX: ARTY_Sh_105_NET_NOFX
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_105_LASNET;
	class ACE_ARTY_Sh_105_LASNET: ARTY_Sh_105_LASNET{};
	class ACE_ARTY_Sh_105_ILLUM_NET: ACE_ARTY_Sh_105_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_105_SMOKE_NET: ACE_ARTY_Sh_105_NET{};
	class ARTY_Sh_122_NET;
	class ACE_ARTY_Sh_122_NET: ARTY_Sh_122_NET{};
	class ACE_ARTY_Sh_122_WP_NET: ACE_ARTY_Sh_Base_NET{};
	class ARTY_Sh_122_NET_NOFX;
	class ACE_ARTY_Sh_122_NET_NOFX: ARTY_Sh_122_NET_NOFX
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_122_LASNET;
	class ACE_ARTY_Sh_122_LASNET: ARTY_Sh_122_LASNET
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class ACE_ARTY_Sh_122_ILLUM_NET: ACE_ARTY_Sh_122_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_122_SMOKE_NET: ACE_ARTY_Sh_122_NET
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class ARTY_Sh_81_NET;
	class ACE_ARTY_Sh_81_NET: ARTY_Sh_81_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_81_WP_NET: ACE_ARTY_Sh_Base_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_81_ILLUM_NET: ACE_ARTY_Sh_Base_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_82_NET;
	class ACE_ARTY_Sh_82_NET: ARTY_Sh_82_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_82_WP_NET: ACE_ARTY_Sh_Base_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_82_ILLUM_NET: ACE_ARTY_Sh_Base_NET
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_120_NET;
	class ACE_ARTY_Sh_120_NET: ARTY_Sh_120_NET
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class ARTY_Sh_227_NET;
	class ACE_ARTY_Sh_227_NET: ARTY_Sh_227_NET
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class ACE_ARTY_Sh_105_HE: ARTY_Sh_105_HE{};
	class ACE_ARTY_Sh_105_WP: ARTY_Sh_105_WP{};
	class ARTY_Sh_105_SADARM;
	class ACE_ARTY_Sh_105_SADARM: ARTY_Sh_105_SADARM
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_105_LASER;
	class ACE_ARTY_Sh_105_LASER: ARTY_Sh_105_LASER{};
	class ARTY_Sh_105_ILLUM;
	class ACE_ARTY_Sh_105_ILLUM: ARTY_Sh_105_ILLUM
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_105_SMOKE;
	class ACE_ARTY_Sh_105_SMOKE: ARTY_Sh_105_SMOKE{};
	class ACE_ARTY_Sh_81_HE: ARTY_Sh_81_HE
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_81_WP: ARTY_Sh_81_WP{};
	class ARTY_Sh_81_ILLUM;
	class ACE_ARTY_Sh_81_ILLUM: ARTY_Sh_81_ILLUM{};
	class ARTY_R_227mm_HE_Rocket;
	class ACE_ARTY_R_227mm_HE_Rocket: ARTY_R_227mm_HE_Rocket
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class ARTY_R_227mm_HE;
	class ACE_ARTY_R_227mm_HE: ARTY_R_227mm_HE{};
	class ACE_ARTY_Sh_122_HE: ARTY_Sh_122_HE{};
	class ACE_ARTY_Sh_122_WP: ARTY_Sh_122_WP{};
	class ARTY_Sh_122_SADARM;
	class ACE_ARTY_Sh_122_SADARM: ARTY_Sh_122_SADARM
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_122_LASER;
	class ACE_ARTY_Sh_122_LASER: ARTY_Sh_122_LASER{};
	class ARTY_Sh_122_ILLUM;
	class ACE_ARTY_Sh_122_ILLUM: ARTY_Sh_122_ILLUM
	{
		ACE_ARTY_TrailFX = "";
	};
	class ARTY_Sh_122_SMOKE;
	class ACE_ARTY_Sh_122_SMOKE: ARTY_Sh_122_SMOKE{};
	class ARTY_SADARM_PROJO;
	class ACE_ARTY_SADARM_PROJO: ARTY_SADARM_PROJO{};
	class ARTY_SADARM_NET;
	class ACE_ARTY_SADARM_NET: ARTY_SADARM_NET{};
	class ARTY_SADARM_BURST;
	class ACE_ARTY_SADARM_BURST: ARTY_SADARM_BURST{};
	class ARTY_SmokeShellWhite;
	class ACE_ARTY_SmokeShellWhite: ARTY_SmokeShellWhite{};
	class ACE_ARTY_Sh_82_HE: ARTY_Sh_82_HE
	{
		ACE_ARTY_TrailFX = "";
	};
	class ACE_ARTY_Sh_82_WP: ARTY_Sh_82_WP{};
	class ARTY_Sh_82_ILLUM;
	class ACE_ARTY_Sh_82_ILLUM: ARTY_Sh_82_ILLUM{};
	class ARTY_R_120mm_HE_Rocket;
	class ACE_ARTY_R_120mm_HE_Rocket: ARTY_R_120mm_HE_Rocket
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class ARTY_R_120mm_HE;
	class ACE_ARTY_R_120mm_HE: ARTY_R_120mm_HE
	{
		ACE_ARTY_TrailFX = "\ca\modules\ARTY\data\fx\scripts\shellTrailsMedium.sqf";
	};
	class Sh_120_HE: ShellBase
	{
		simulation = "shotShell";
		ace_hit = 580;
		hit = 684;
		indirectHit = 48;
		indirectHitRange = 12;
		typicalSpeed = 1400;
		airFriction = -0.00018;
		explosive = 1;
		explosionEffects = "ExploAmmoExplosion";
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		tracerScale = 4;
		tracerEndTime = 6;
		timeToLive = 12;
		airLock = 0;
		cost = 12;
	};
	class Sh_120_SABOT: ShellBase
	{
		simulation = "shotShell";
		ace_hit = 830;
		hit = 1276;
		indirectHit = 10;
		indirectHitRange = 0.1;
		typicalSpeed = 1545;
		airFriction = -3.75e-005;
		explosive = 0.05;
		deflecting = 0;
		tracerScale = 4;
		tracerEndTime = 4;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		explosionEffects = "ExploAmmoExplosion";
		timeToLive = 42;
		irLock = 1;
	};
	class ACE_M1028_Pellet: BulletBase
	{
		simulation = "shotShell";
		model = "";
		ace_hit = 6;
		hit = 20;
		indirectHit = 5;
		indirectHitRange = 3;
		typicalSpeed = 1400;
		airFriction = -0.003;
		explosive = 0.01;
		timeToLive = 5;
		explosionEffects = "";
		CraterEffects = "";
		deflecting = 30;
		cost = 300;
	};
	class ACE_M900Round: Sh_120_SABOT
	{
		ace_hit = 520;
		hit = 702;
		indirectHit = 0;
		typicalSpeed = 1505;
	};
	class ACE_M456A2Round: Sh_120_HE
	{
		ace_hit = 430;
		hit = 430;
		indirectHit = 42;
		indirectHitRange = 2.6;
		typicalSpeed = 1174;
		CraterEffects = "HEShellCrater";
	};
	class Sh_105_HESH: Sh_120_HE
	{
		ace_hit = 430;
		hit = 430;
		indirectHit = 42;
		indirectHitRange = 2.6;
		explosive = 1;
		typicalSpeed = 1174;
		CraterEffects = "HEShellCrater";
		explosionEffects = "ExploAmmoExplosion";
		cost = 300;
	};
	class Sh_105_APDS: Sh_120_SABOT
	{
		ace_hit = 520;
		hit = 702;
		indirectHit = 0;
		typicalSpeed = 1505;
		deflecting = 0;
		explosionEffects = "ExploAmmoExplosion";
	};
	class Sh_40_HE: BulletBase
	{
		cost = 10;
		ace_hit = 22;
		hit = 40;
		indirectHit = 33;
		indirectHitRange = 1.9;
		explosionEffects = "ExploAmmoExplosion";
	};
	class Sh_40_SABOT: Sh_40_HE
	{
		ace_hit = 47;
		hit = 95;
		indirectHit = 0;
		indirectHitRange = 0;
		cost = 400;
	};
	class Sh_125_HE: ShellBase
	{
		simulation = "shotShell";
		ace_hit = 94;
		hit = 94;
		indirectHit = 75;
		indirectHitRange = 15;
		typicalSpeed = 850;
		airFriction = -0.00015;
		explosive = 1;
		deflecting = 0;
		ExplosionEffects = "HEShellExplosion";
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		tracerScale = 4;
		tracerEndTime = 6;
		timeToLive = 37;
		cost = 12.5;
	};
	class Sh_125_SABOT: ShellBase
	{
		simulation = "shotShell";
		ace_hit = 540;
		hit = 702;
		indirectHit = 10;
		indirectHitRange = 0.1;
		typicalSpeed = 1700;
		airFriction = -5e-005;
		cost = 1000;
		deflecting = 2;
		explosive = 0.05;
		explosionEffects = "ExploAmmoExplosion";
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		tracerScale = 4;
		tracerEndTime = 4;
		timeToLive = 29;
		irLock = 1;
	};
	class ACE_3BM42MRound: Sh_125_SABOT
	{
		ace_hit = 650;
		hit = 910;
		typicalSpeed = 1750;
		airFriction = -4e-005;
		deflecting = 0;
	};
	class ACE_3BM17MRound: Sh_125_SABOT
	{
		ace_hit = 340;
		hit = 442;
		typicalSpeed = 1780;
	};
	class ACE_3BK29Round: Sh_125_SABOT
	{
		ace_hit = 650;
		hit = 802;
		indirectHit = 50;
		indirectHitRange = 3.1;
		typicalSpeed = 915;
		airFriction = -0.0002625;
		explosive = 1;
		timeToLive = 45;
		cost = 300;
		irLock = 0;
	};
	class ACE_3BK18Round: ACE_3BK29Round
	{
		ace_hit = 500;
		hit = 500;
		typicalSpeed = 905;
	};
	class ACE_3BK29MRound: ACE_3BK29Round
	{
		ace_hit = 700;
		hit = 960;
	};
	class Sh_85_HE: ShellBase
	{
		simulation = "shotShell";
		ace_hit = 40;
		hit = 64;
		indirectHit = 51;
		indirectHitRange = 12;
		explosive = 1;
		typicalSpeed = 793;
		ExplosionEffects = "HEShellExplosion";
		tracerScale = 3;
		tracerEndTime = 6;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		cost = 8.5;
	};
	class Sh_85_AP: ShellBase
	{
		simulation = "shotShell";
		ace_hit = 95;
		hit = 115;
		indirectHit = 8.5;
		indirectHitRange = 0.1;
		typicalSpeed = 800;
		cost = 500;
		explosionEffects = "ExploAmmoExplosion";
		CraterEffects = "ExploAmmoCrater";
		tracerScale = 3;
		tracerEndTime = 6;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		irLock = 1;
	};
	class ACE_BR365PRound: Sh_85_AP
	{
		ace_hit = 125;
		hit = 156;
		typicalSpeed = 1050;
		cost = 700;
	};
	class Sh_100_HE: Sh_105_HE
	{
		ace_hit = 75;
		hit = 75;
		indirectHit = 60;
		indirectHitRange = 12.5;
		explosive = 1;
		typicalSpeed = 440;
		airfriction = -1e-005;
		timeToLive = 20;
		deflecting = 0;
		tracerScale = 3;
		tracerStartTime = 0.1;
		tracerEndTime = 6;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		cost = 10;
	};
	class ACE_OF412Round: Sh_100_HE
	{
		simulation = "shotShell";
		airFriction = -0.0002;
	};
	class Sh_100_HEAT: Sh_105_HE
	{
		ace_hit = 380;
		hit = 380;
		indirectHit = 40;
		indirectHitRange = 2.5;
		typicalSpeed = 900;
		airFriction = -0.000193;
		explosive = 1;
		deflecting = 2;
		explosionEffects = "ExploAmmoExplosion";
		CraterEffects = "ExploAmmoCrater";
		simulation = "shotShell";
		tracerScale = 3;
		tracerStartTime = 0.1;
		tracerEndTime = 6;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		cost = 300;
	};
	class ACE_3BM8Round: Sh_125_SABOT
	{
		ace_hit = 287;
		hit = 359;
		typicalSpeed = 1425;
		airFriction = -0.0002;
		explosionEffects = "ExploAmmoExplosion";
	};
	class ACE_BR412DRound: ACE_3BM8Round
	{
		ace_hit = 195;
		hit = 234;
		typicalSpeed = 887;
		airFriction = -1.5e-005;
	};
	class ACE_OG15VRound: ShellBase
	{
		ace_hit = 35;
		hit = 55;
		indirectHit = 24;
		indirectHitRange = 5;
		typicalspeed = 290;
		explosive = 1;
		cost = 7.3;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		initSpeed = 290;
		airfriction = -0.00017;
		deflecting = 0;
		tracerendtime = 6;
		tracerscale = 3;
		tracerstarttime = 0.1;
	};
	class ACE_PG15VRound: ShellBase
	{
		ace_hit = 280;
		hit = 350;
		indirectHit = 29;
		indirectHitRange = 1.9;
		typicalspeed = 700;
		explosive = 0.8;
		cost = 500;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		initSpeed = 700;
		airfriction = -0.00054;
		deflecting = 0;
		tracerendtime = 6;
		tracerscale = 3;
		tracerstarttime = 0.1;
	};
	class SmokeShellVehicle: SmokeShell
	{
		model = "\x\ace\addons\m_wep_magazines\ace_m82_smoke.p3d";
	};
	class B_127x108_APHE: BulletBase
	{
		ace_hit = 12;
		ace_hit_distance = 100;
		ace_mass = 2.7;
		ace_windcoef = 0.36;
		ace_incendiary = 0.5;
		airFriction = -0.0009;
		cost = 10;
		explosive = 0;
		hit = 16;
		indirectHit = 0.9;
		indirectHitRange = 0.01;
		typicalspeed = 840;
		airLock = 1;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		timetolive = 8;
		tracerScale = 1.9;
		tracerStartTime = 0.06;
		tracerEndTime = 3;
		nvgOnly = 0;
		deflecting = 20;
		caliber = 2;
	};
	class ACE_B_127x108_1SL: B_127x108_APHE
	{
		ace_hit = 13;
		ace_mass = 3.1;
		hit = 17;
		simulation = "shotSpread";
		supersoniccrackfar[] = {"",1,1,0};
		supersoniccracknear[] = {"",1,1,0};
	};
	class B_127x107_Ball: BulletBase
	{
		ace_hit = 20;
		ace_hit_distance = 100;
		ace_mass = 4.82;
		ace_incendiary = 1;
		airFriction = -0.0006;
		hit = 26;
		indirectHit = 1.3;
		indirectHitRange = 0.01;
		typicalSpeed = 840;
		airLock = 1;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		timetolive = 8;
		tracerScale = 1.9;
		tracerStartTime = 0.06;
		tracerEndTime = 6;
		nvgOnly = 0;
		deflecting = 20;
		caliber = 3;
	};
	class B_145x115_AP: BulletBase
	{
		ace_hit = 25;
		ace_hit_distance = 100;
		ace_incendiary = 0.1;
		airFriction = -0.00058;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		deflecting = 20;
		hit = 30;
		indirectHit = 1.5;
		indirectHitRange = 0.1;
		caliber = 3.5;
		explosive = 0;
		cost = 7.25;
		typicalSpeed = 976;
		tracerStartTime = 0.06;
		tracerEndTime = 8;
		timetolive = 8;
		airLock = 1;
	};
	class B_23mm_AA: BulletBase
	{
		airFriction = -0.000554;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		tracerEndTime = 5;
		ace_hit = 29;
		ace_hit_distance = 100;
		hit = 29;
		indirectHit = 15;
		indirectHitRange = 1.75;
		explosive = 0.66;
		cost = 11.5;
		typicalSpeed = 980;
		timeToLive = 19;
		airLock = 1;
	};
	class ACE_B_23mm_ZSU: B_23mm_AA
	{
		trackLead = 1;
		weaponLockSystem = "8 + 1";
	};
	class B_23mm_APHE: BulletBase
	{
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		timetolive = 16;
		cost = 11.5;
	};
	class B_30mm_AP: BulletBase
	{
		airFriction = -0.000265;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		cost = 300;
		ace_hit = 31;
		ace_hit_distance = 1000;
		hit = 62;
		indirectHit = 3;
		indirectHitRange = 0.1;
		timeToLive = 10;
		typicalSpeed = 1120;
		explosive = 0;
		airLock = 1;
	};
	class B_30mm_HE: BulletBase
	{
		airFriction = -0.000265;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		cost = 30;
		ace_hit = 21;
		hit = 38;
		indirectHit = 30;
		indirectHitRange = 2.3;
		explosive = 0.6;
		timeToLive = 28;
		typicalSpeed = 960;
		airLock = 1;
	};
	class B_30mm_AA: BulletBase
	{
		airFriction = -0.000265;
		model = "\ca\Weapons\Data\bullettracer\tracer_red";
		cost = 15;
		ace_hit = 21;
		ace_hit_distance = 1000;
		hit = 38;
		indirectHit = 18;
		indirectHitRange = 2.3;
		explosive = 0.1;
		timeToLive = 28;
		typicalSpeed = 960;
		airLock = 1;
	};
	class G_30mm_HE: GrenadeBase
	{
		airFriction = -0.000445;
		timetolive = 27;
	};
	class G_40mm_HE;
	class ACE_M430Round: G_40mm_HE
	{
		airFriction = -0.000552;
		timetolive = 40;
		ace_hit = 50;
		hit = 40;
		ace_heat = 1;
	};
	class B_127x99_Ball;
	class ACE_B_127x99_SLAP: B_127x99_Ball
	{
		ace_hit = 23;
		ace_hit_distance = 100;
		airfriction = -0.0003;
		airLock = 1;
	};
	class B_20mm_AA: BulletBase
	{
		airFriction = -0.00087;
		timetolive = 20;
		ace_hit = 25;
		ace_hit_distance = 100;
		hit = 25;
		indirectHit = 10;
		indirectHitRange = 1.5;
		explosive = 0.1;
		cost = 10;
		airLock = 1;
	};
	class B_20mm_AP: BulletBase
	{
		airFriction = -0.0005;
		timetolive = 20;
		ace_hit = 25;
		ace_hit_distance = 100;
		hit = 25;
		indirectHit = 10;
		indirectHitRange = 1.5;
		explosive = 0.1;
		cost = 10;
		airLock = 1;
	};
	class B_25mm_HE: BulletBase
	{
		tracerEndTime = 3.5;
		ace_hit = 18;
		hit = 31;
		indirectHit = 25;
		indirectHitRange = 1.9;
		explosive = 1;
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ExploAmmoExplosion";
		timeToLive = 28;
		typicalSpeed = 1100;
		deflecting = 0;
		airFriction = -0.0006;
		cost = 12.5;
		airLock = 1;
	};
	class B_25mm_HEI: B_25mm_HE
	{
		ace_hit = 18;
		hit = 31;
		indirectHit = 25;
		indirectHitRange = 1.9;
		airLock = 1;
	};
	class B_25mm_APDS: BulletBase
	{
		ace_hit = 28;
		hit = 62;
		ace_hit_distance = 1000;
		indirectHit = 3;
		indirectHitRange = 0.03;
		timeToLive = 20;
		typicalSpeed = 1345;
		airFriction = -0.00014;
		cost = 250;
		airLock = 1;
	};
	class ACE_B_25mm_APFSDS: B_25mm_APDS
	{
		ace_hit = 40;
		hit = 81;
		typicalSpeed = 1420;
		airLock = 1;
		cost = 300;
	};
	class B_30mmA10_AP: BulletBase
	{
		ace_hit = 69;
		ace_hit_distance = 1000;
		hit = 96;
		indirecthit = 40;
		airFriction = -9.9e-005;
		timetolive = 20;
		explosive = 0.1;
		cost = 15;
		airLock = 1;
	};
	class ACE_B_30mm_APHE: B_30mmA10_AP
	{
		ace_hit = 31;
		ace_hit_distance = 1000;
		hit = 55;
		indirectHit = 15;
		indirectHitRange = 3;
		airFriction = -0.000265;
		typicalSpeed = 890;
		explosive = 0.1;
		timeToLive = 20;
	};
	class B_30x113mm_M789_HEDP: B_30mm_HE
	{
		ace_hit = 25;
		hit = 50;
		indirectHit = 25;
		indirectHitRange = 1.75;
		explosive = 1;
		cost = 15;
		airLock = 1;
		airfriction = -0.0006;
		timeToLive = 40;
	};
	class R_Hydra_HE: RocketBase
	{
		hit = 150;
		indirectHit = 40;
		indirectHitRange = 8;
		thrustTime = 1.07;
		thrust = 900;
		sideAirFriction = 0.1;
		maxSpeed = 720;
		cost = 70;
	};
	class M_CRV7_HEPD: R_Hydra_HE
	{
		hit = 200;
		indirecthit = 50;
		indirecthitrange = 8;
		maxspeed = 820;
	};
	class M_CRV7_FAT: M_CRV7_HEPD
	{
		ace_hit = 350;
		hit = 400;
		indirecthit = 100;
		indirecthitrange = 2;
		explosive = 0.1;
		explosioneffects = "ExploAmmoExplosion";
	};
	class R_57mm_HE: RocketBase
	{
		ace_hit = 130;
		hit = 60;
		indirectHit = 20;
		indirectHitRange = 7;
		maxSpeed = 490;
		thrustTime = 1.1;
		thrust = 620;
		sideAirFriction = 0.2;
		cost = 57;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	class R_80mm_HE: RocketBase
	{
		ace_hit = 400;
		hit = 210;
		indirectHit = 55;
		indirectHitRange = 8;
		maxSpeed = 590;
		thrustTime = 0.69;
		thrust = 1060;
		sideAirFriction = 0.09;
		cost = 8;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	class R_S8T_AT: RocketBase
	{
		ace_hit = 400;
		hit = 430;
		indirectHit = 30;
		indirectHitRange = 5;
		maxSpeed = 440;
		thrustTime = 0.69;
		thrust = 800;
		sideAirFriction = 0.12;
		cost = 80;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	class R_PG9_AT: RocketBase
	{
		ace_hit = 300;
		hit = 300;
		indirectHit = 29;
		indirectHitRange = 1.8;
		timeToLive = 6;
		maxspeed = 200;
		sideAirFriction = 0.48;
		initTime = 0.02;
		thrustTime = 0.55;
		thrust = 928;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	class R_OG9_HE: R_PG9_AT
	{
		timeToLive = 25;
		ace_hit = 24;
		hit = 55;
		indirectHit = 44;
		indirectHitRange = 9;
		maxspeed = 100;
		sideAirFriction = 0.1;
		initTime = 0.01;
		thrustTime = 0.01;
		thrust = 0;
		cost = 7.3;
	};
	class M_TOW_AT: MissileBase
	{
		ace_hit = 800;
		hit = 800;
		indirectHit = 61;
		indirectHitRange = 3.8;
		timeToLive = 20;
		fusedistance = 65;
		maxSpeed = 296;
		thrust = 185;
		sideairfriction = 0.084;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
		maneuvrability = 5;
	};
	class M_TOW2_AT: M_TOW_AT
	{
		ace_hit = 1000;
		hit = 1200;
		indirectHit = 61;
		indirectHitRange = 3.8;
		maxSpeed = 296;
		thrust = 185;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class M_Maverick_AT: MissileBase
	{
		ace_hit = 1800;
		hit = 1800;
		indirectHit = 122;
		indirectHitRange = 7.5;
		maxControlRange = 27000;
		initTime = 0.15;
		timeToLive = 85;
		maneuvrability = 10;
		maxSpeed = 319;
		thrustTime = 2.5;
		thrust = 150;
		effectsMissile = "missile4";
		sideAirFriction = 0.05;
		simulationstep = 0.001;
	};
	class M_Hellfire_AT: MissileBase
	{
		ace_hit = 1400;
		hit = 1440;
		indirectHit = 71;
		indirectHitRange = 4.5;
		irLock = 1;
		laserLock = 1;
		timeToLive = 19;
		simulationStep = 0.001;
		thrust = 180;
		effectsMissile = "missile2";
	};
	class ACE_M_DAGR_HE: M_Hellfire_AT
	{
		ace_hit = 150;
		ace_tandemheat = 0;
		ace_incendiary = 0;
		ace_heat = 0;
		ace_topattack = 1;
		hit = 150;
		indirectHit = 40;
		indirectHitRange = 8;
		irLock = 1;
		laserLock = 1;
		muzzleEffect = "BIS_Effects_Rocket";
		effectsMissile = "missile1";
		CraterEffects = "HERocketCrater";
		explosionEffects = "HERocketExplosion";
	};
	class M_CRV7_AT: M_Hellfire_AT
	{
		ace_hit = 350;
		hit = 400;
		indirecthit = 100;
		indirecthitrange = 2;
		explosive = 0.1;
		inittime = 0.05;
		thrust = 1500;
		thrusttime = 1;
		maxspeed = 820;
		maneuvrability = 6;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATRocketCrater";
	};
	class ACE_M_HellfireL_AT: M_Hellfire_AT
	{
		irLock = 1;
		laserLock = 0;
	};
	class M_AT5_AT: MissileBase
	{
		ace_hit = 650;
		hit = 650;
		indirectHit = 25;
		indirectHitRange = 3.4;
		sideAirFriction = 0.05;
		airFriction = -2e-005;
		maxSpeed = 200;
		maxControlRange = 4000;
		simulationStep = 0.001;
		trackOversteer = 2.5;
		initTime = 0.25;
		timeToLive = 20;
		thrustTime = 1.5;
		thrust = 133.6;
		fusedistance = 70;
		effectsMissile = "missile2";
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
		maneuvrability = 4;
	};
	class ACE_M_AT3C_AT: M_AT5_AT
	{
		ace_hit = 460;
		hit = 460;
		indirectHit = 50;
		indirectHitRange = 3;
		maxSpeed = 200;
		maxControlRange = 3000;
		timeToLive = 26;
		initTime = 0;
		thrustTime = 2.5;
		thrust = 65;
		sideAirFriction = 0.14;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
		maneuvrability = 2;
	};
	class ACE_M_AT3P_AT: ACE_M_AT3C_AT
	{
		ace_hit = 520;
		hit = 520;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class ACE_9M113M: M_AT5_AT
	{
		ace_tandemheat = 1;
		ace_hit = 800;
		hit = 960;
		timeToLive = 19;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class M_AT13_AT: M_AT5_AT
	{
		ace_hit = 950;
		hit = 1140;
		indirectHit = 51;
		indirectHitRange = 1.5;
		maxSpeed = 223;
		sideAirFriction = 0.072;
		initTime = 0;
		thrust = 116;
		maxControlRange = 2000;
		fuseDistance = 80;
		timeToLive = 13;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class ACE_M_AT13_AT: M_AT13_AT{};
	class ACE_M_AT13_TB: M_AT13_AT
	{
		ace_hit = 80;
		hit = 190;
		indirecthit = 90;
		indirecthitrange = 6;
		ace_thermobaric = 1;
		craterEffects = "ACE_FAE_Crater";
		explosionEffects = "ACE_FAE_Explosion";
		soundDefault1[] = {"x\ace\addons\c_weapon\data\sound\fae_hit1.wss",44.6684,1,4000};
		soundDefault2[] = {"x\ace\addons\c_weapon\data\sound\fae_hit2.wss",44.6684,1,4000};
		soundDefault3[] = {"x\ace\addons\c_weapon\data\sound\fae_hit3.wss",44.6684,1,4000};
		soundMetal1[] = {"x\ace\addons\c_weapon\data\sound\fae_hit1.wss",44.6684,1,4000};
		soundMetal2[] = {"x\ace\addons\c_weapon\data\sound\fae_hit2.wss",44.6684,1,4000};
		soundMetal3[] = {"x\ace\addons\c_weapon\data\sound\fae_hit3.wss",44.6684,1,4000};
		hitGroundSoft[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGroundHard[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMan[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitArmor[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitIron[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitBuilding[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitFoliage[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitWood[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlass[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlassArmored[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitConcrete[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitRubber[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitPlastic[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitDefault[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMetal[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitMetalplate[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
	};
	class M_AT10_AT: MissileBase
	{
		ace_hit = 650;
		hit = 780;
		indirectHit = 25;
		indirectHitRange = 2.5;
		maneuvrability = 6;
		timeToLive = 13;
		initTime = 1.5;
		maxSpeed = 420;
		thrustTime = 6;
		thrust = 60;
		sideairfriction = 0.144;
		fuseDistance = 15;
		cost = 5000;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
		maxControlRange = 4000;
	};
	class M_AT11_AT: M_AT10_AT
	{
		ace_hit = 900;
		hit = 1080;
		indirectHit = 25;
		indirectHitRange = 3.1;
		timeToLive = 15;
		maxControlRange = 5000;
		cost = 7500;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class ACE_9M119: M_AT11_AT
	{
		ace_hit = 700;
		hit = 700;
		timeToLive = 14;
		maxControlRange = 4000;
		cost = 5000;
	};
	class M_AT2_AT: MissileBase
	{
		ace_hit = 500;
		hit = 500;
		indirectHit = 59;
		indirectHitRange = 3.7;
		maxControlRange = 4000;
		maneuvrability = 3;
		simulationStep = 0.001;
		maxSpeed = 150;
		timeToLive = 26;
		tracklead = 0.75;
		trackoversteer = 0.75;
		cmImmunity = 0.6;
		thrust = 144;
		sideAirFriction = 0.076;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class M_AT6_AT: MissileBase
	{
		ace_hit = 560;
		hit = 560;
		indirectHit = 52;
		indirectHitRange = 3.25;
		maxControlRange = 7000;
		timeToLive = 17.6;
		maneuvrability = 6;
		maxSpeed = 510;
		simulationStep = 0.001;
		sideAirFriction = 0.033;
		thrusttime = 3.25;
		thrust = 168;
		tracklead = 0.85;
		trackoversteer = 0.85;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class M_AT9_AT: M_AT6_AT
	{
		ace_hit = 920;
		hit = 960;
		maxControlRange = 8000;
		maneuvrability = 8;
		maxSpeed = 550;
		sideAirFriction = 0.03;
		timeToLive = 20;
		thrusttime = 3.5;
		thrust = 172;
		explosionEffects = "GrenadeExplosion";
		CraterEffects = "ATMissileCrater";
	};
	class ACE_M_AT9_Mi28: M_AT9_AT{};
	class M_Vikhr_AT: MissileBase
	{
		ace_hit = 1000;
		hit = 1320;
		indirectHit = 52;
		indirectHitRange = 6.5;
		airLock = 0;
		maxControlRange = 11500;
		simulationStep = 0.001;
		timeToLive = 19;
		maneuvrability = 11;
		maxSpeed = 600;
		thrustTime = 2;
		thrust = 366;
		effectsMissile = "missile3";
		sideAirFriction = 0.04;
	};
	class M_Ch29_AT: MissileBase
	{
		ace_hit = 4200;
		hit = 4200;
		indirectHit = 700;
		indirectHitRange = 17;
		timeToLive = 30;
		irLock = 0;
		laserLock = 1;
		maneuvrability = 10;
		maxControlRange = 10000;
		sideAirFriction = 0.1;
		simulationStep = 0.001;
		maxSpeed = 600;
		initTime = 0.8;
		thrustTime = 2;
		thrust = 350;
		effectsMissile = "missile4";
	};
	class M_9M311_AA: MissileBase
	{
		hit = 155;
		indirectHit = 100;
		indirectHitRange = 5;
		timeToLive = 17;
		maxSpeed = 900;
		initTime = 0;
		thrustTime = 2.5;
		thrust = 475;
		fuseDistance = 150;
		effectsMissile = "missile2";
		weaponLockSystem = 8;
		irlock = 0;
		sideairfriction = 0.05;
		cost = 85000;
	};
	class M_Strela_AA: MissileBase
	{
		hit = 66;
		indirectHit = 33;
		indirectHitRange = 2.5;
		trackLead = 1;
		maxSpeed = 470;
		initTime = 0.3;
		thrustTime = 2.5;
		thrust = 232;
		fuseDistance = 120;
		timeToLive = 17;
		effectsMissile = "missile3";
		cmImmunity = 0.4;
		cost = 50000;
		maneuvrability = 5;
		sideairfriction = 0.162;
	};
	class M_Igla_AA: M_Strela_AA
	{
		maxSpeed = 800;
		cmImmunity = 0.6;
		cost = 75000;
		thrust = 600;
		sideairfriction = 0.038;
		maneuvrability = 7;
		timeToLive = 9;
	};
	class M_Stinger_AA: MissileBase
	{
		hit = 99;
		indirectHit = 33;
		indirectHitRange = 2.5;
		trackLead = 1;
		fuseDistance = 200;
		timeToLive = 14;
		maxSpeed = 750;
		initTime = 0.2;
		thrustTime = 2.5;
		effectsMissile = "missile3";
		cmImmunity = 0.6;
		cost = 75000;
		thrust = 340;
		sideairfriction = 0.026;
		maneuvrability = 7;
	};
	class M_Bolide_AA: MissileBase
	{
		hit = 99;
		indirectHit = 33;
		indirectHitRange = 2.5;
		trackOversteer = 1;
		trackLead = 1;
		thrust = 180;
		thrustTime = 3.5;
		sideAirFriction = 0.03;
		maneuvrability = 7;
		manualControl = 1;
	};
	class M_R73_AA: MissileBase
	{
		cmImmunity = 0.7;
		cost = 80000;
		thrust = 240;
		timeToLive = 40;
		maneuvrability = 12;
		sideairfriction = 0.05;
		maxcontrolrange = 8000;
		simulationstep = 0.001;
	};
	class M_Sidewinder_AA: MissileBase
	{
		cmImmunity = 0.7;
		cost = 80000;
		thrust = 240;
		timeToLive = 40;
		maneuvrability = 18;
		sideairfriction = 0.05;
		maxcontrolrange = 8000;
		simulationstep = 0.001;
	};
	class Bo_FAB_250: BombCore
	{
		ace_hit = 3400;
		hit = 3400;
		indirectHit = 625;
		indirectHitRange = 24;
		maneuvrability = 2.5;
	};
	class Bo_Mk82: Bo_FAB_250
	{
		ace_hit = 3000;
		hit = 3000;
		indirectHit = 500;
		indirectHitRange = 18;
	};
	class Bo_GBU12_LGB: LaserBombCore
	{
		ace_hit = 3000;
		hit = 3000;
		indirectHit = 550;
		indirectHitRange = 18;
		fuseDistance = 50;
	};
	class ACE_NukeBlastEffects: Default
	{
		ace_bwc = 1;
	};
	class ACE_NukeBomb: Default
	{
		ace_bwc = 1;
	};
	class ACE_B61_03: ACE_NukeBomb{};
	class ACE_B61_15: ACE_NukeBomb{};
	class ACE_B61_50: ACE_NukeBomb{};
	class ACE_R_Empty_Dummy: MissileBase{};
	class ACE_R_MK82Rack: MissileBase{};
	class ACE_R_AGM65Rack: MissileBase{};
	class ACE_R_AIM9Rail: MissileBase{};
	class ACE_R_HellfirePod: MissileBase{};
	class ACE_R_LAU61: MissileBase{};
	class ACE_R_LAU68: MissileBase{};
	class ACE_R_TOW2: MissileBase{};
	class ACE_R_TOW4: MissileBase{};
	class ACE_R_UB16: MissileBase
	{
		proxyShape = "\CA\air_e\ub16.p3d";
	};
	class ACE_R_UB32: MissileBase
	{
		proxyShape = "\CA\air_e\ub32.p3d";
	};
	class ACE_R_B8V20: MissileBase
	{
		proxyShape = "\CA\air_e\s8_launcher.p3d";
	};
	class ACE_R_S8T: MissileBase{};
	class ACE_R_S8T_2: MissileBase{};
	class ACE_R_S13T: MissileBase{};
	class ACE_G_UPK23: MissileBase
	{
		proxyShape = "\x\ace\addons\m_wep_upk23\ace_upk_23_250.p3d";
	};
	class ACE_M_Sidewinder_AA: M_Sidewinder_AA{};
	class ACE_M_Maverick_AT: M_Maverick_AT{};
	class ACE_M_Kh29_AT: M_Ch29_AT{};
	class ACE_Bo_GBU12_LGB: Bo_GBU12_LGB{};
	class ACE_Bo_FAB_250: Bo_FAB_250{};
	class ACE_Bo_Mk82: Bo_Mk82{};
	class ACE_R_S8T_AT: R_S8T_AT{};
	class ACE_M_R73_AA: M_R73_AA{};
	class ACE_R_S13T_AT: ACE_R_S8T_AT
	{
		hit = 310;
		indirectHit = 75;
		indirectHitRange = 12;
		maxSpeed = 590;
		thrustTime = 1;
		thrust = 780;
		sideAirFriction = 0.22;
		cost = 80;
	};
	class ACE_M_R27_AA: M_R73_AA
	{
		maxSpeed = 928;
		initTime = 0.5;
		thrustTime = 6;
		weaponLockSystem = 8;
	};
	class ACE_M_Kh25_AT: MissileBase
	{
		ace_hit = 1800;
		hit = 1800;
		indirectHit = 300;
		indirectHitRange = 12;
		timeToLive = 30;
		irLock = 0;
		laserLock = 1;
		maneuvrability = 10;
		maxControlRange = 10000;
		sideAirFriction = 0.1;
		simulationStep = 0.001;
		maxSpeed = 600;
		initTime = 0.8;
		thrustTime = 12;
		thrust = 350;
		effectsMissile = "missile4";
	};
	class ACE_Bo_FAB500: Bo_FAB_250
	{
		ace_hit = 5000;
		hit = 5000;
		indirectHit = 750;
		indirectHitRange = 22;
		fuseDistance = 50;
	};
	class ACE_Bo_FAB500M62: ACE_Bo_FAB500{};
	class ACE_Bo_KAB500KR_CGB: Bo_GBU12_LGB
	{
		ace_hit = 5000;
		hit = 5000;
		indirectHit = 750;
		indirectHitRange = 22;
		fuseDistance = 50;
		irLock = 1;
		laserLock = 0;
	};
	class ACE_Bo_KAB500L_LGB: ACE_Bo_KAB500KR_CGB
	{
		irLock = 0;
		laserLock = 1;
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Default;
	class CannonCore;
	class LauncherCore;
	class MGunCore;
	class MGun;
	class RocketPods;
	class MissileLauncher;
	class Rifle;
	class SmokeLauncher: MGun
	{
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazineReloadTime = 1;
	};
	class CMFlareLauncher: SmokeLauncher
	{
		modes[] = {"Single","Burst","FullAuto","AIBurst"};
		class Burst;
		class FullAuto: Burst
		{
			displayName = "$STR_ACE_DN_MODE_AUTO";
			burst = 240;
			reloadTime = 2;
		};
	};
	class Laserdesignator_mounted: Default
	{
		minRange = 300;
		midRange = 1650;
		maxRange = 3000;
		magazineReloadTime = 0;
		reloadTime = 0;
	};
	class ACE_Laserdesignator_Hidden: Laserdesignator_mounted
	{
		showToPlayer = 0;
		minRange = 0;
		midRange = 0;
		maxRange = 0;
	};
	class ACE_SACLOS_Guidance: Laserdesignator_mounted
	{
		modes[] = {"SACLOS"};
		magazines[] = {"ACE_SACLOS_Guidance"};
		class SACLOS: Laserdesignator_mounted
		{
			shotFromTurret = 1;
			showToPlayer = 0;
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
			minRange = 0;
			midRange = 0;
			maxRange = 0;
		};
	};
	class FakeWeapon: MGunCore
	{
		autoReload = 0;
		displayName = "";
	};
	class M119: CannonCore
	{
		magazines[] = {"30Rnd_105mmHE_M119","30Rnd_105mmWP_M119","30Rnd_105mmSADARM_M119","30Rnd_105mmLASER_M119","30Rnd_105mmSMOKE_M119","30Rnd_105mmILLUM_M119","ARTY_30Rnd_105mmHE_M119","ARTY_30Rnd_105mmWP_M119","ARTY_30Rnd_105mmSADARM_M119","ARTY_30Rnd_105mmLASER_M119","ARTY_30Rnd_105mmSMOKE_M119","ARTY_30Rnd_105mmILLUM_M119","ACE_ARTY_30Rnd_105mmHE_M119","ACE_ARTY_30Rnd_105mmWP_M119","ACE_ARTY_30Rnd_105mmSADARM_M119","ACE_ARTY_30Rnd_105mmLASER_M119","ACE_ARTY_30Rnd_105mmSMOKE_M119","ACE_ARTY_30Rnd_105mmILLUM_M119"};
		class Single1: Mode_SemiAuto
		{
			dispersion = 0.006;
		};
	};
	class D30: CannonCore
	{
		magazines[] = {"30Rnd_122mmHE_D30","30Rnd_122mmWP_D30","30Rnd_122mmSADARM_D30","30Rnd_122mmLASER_D30","30Rnd_122mmSMOKE_D30","30Rnd_122mmILLUM_D30","ARTY_30Rnd_122mmHE_D30","ARTY_30Rnd_122mmWP_D30","ARTY_30Rnd_122mmSADARM_D30","ARTY_30Rnd_122mmLASER_D30","ARTY_30Rnd_122mmSMOKE_D30","ARTY_30Rnd_122mmILLUM_D30","ACE_ARTY_30Rnd_122mmHE_D30","ACE_ARTY_30Rnd_122mmWP_D30","ACE_ARTY_30Rnd_122mmSADARM_D30","ACE_ARTY_30Rnd_122mmLASER_D30","ACE_ARTY_30Rnd_122mmSMOKE_D30","ACE_ARTY_30Rnd_122mmILLUM_D30"};
		class Single1: Mode_SemiAuto
		{
			dispersion = 0.006;
		};
	};
	class GRAD: RocketPods
	{
		magazines[] = {"ARTY_40Rnd_120mmHE_BM21","40Rnd_GRAD","ACE_ARTY_40Rnd_120mmHE_BM21"};
	};
	class MLRS: RocketPods
	{
		magazines[] = {"ARTY_12Rnd_227mmHE_M270","12Rnd_MLRS","ACE_ARTY_12Rnd_227mmHE_M270"};
	};
	class M252: CannonCore
	{
		magazines[] = {"8Rnd_81mmHE_M252","8Rnd_81mmWP_M252","8Rnd_81mmILLUM_M252","ARTY_8Rnd_81mmHE_M252","ARTY_8Rnd_81mmWP_M252","ARTY_8Rnd_81mmILLUM_M252","ACE_ARTY_8Rnd_81mmHE_M252","ACE_ARTY_8Rnd_81mmWP_M252","ACE_ARTY_8Rnd_81mmILLUM_M252","ACE_1Rnd_81mmHE_M252","ACE_1Rnd_81mmWP_M252","ACE_1Rnd_81mmILLUM_M252","ACE_ARTY_1Rnd_81mmHE_M252","ACE_ARTY_1Rnd_81mmWP_M252","ACE_ARTY_1Rnd_81mmILLUM_M252"};
		class Single1: Mode_SemiAuto
		{
			dispersion = 0.009;
		};
	};
	class 2B14: CannonCore
	{
		magazines[] = {"8Rnd_82mmHE_2B14","8Rnd_82mmWP_2B14","8Rnd_82mmILLUM_2B14","ARTY_8Rnd_82mmHE_2B14","ARTY_8Rnd_82mmWP_2B14","ARTY_8Rnd_82mmILLUM_2B14","ACE_ARTY_8Rnd_82mmHE_2B14","ACE_ARTY_8Rnd_82mmWP_2B14","ACE_ARTY_8Rnd_82mmILLUM_2B14","ACE_1Rnd_82mmHE_2B14","ACE_1Rnd_82mmWP_2B14","ACE_1Rnd_82mmILLUM_2B14","ACE_ARTY_1Rnd_82mmHE_2B14","ACE_ARTY_1Rnd_82mmWP_2B14","ACE_ARTY_1Rnd_82mmILLUM_2B14"};
		class Single1: Mode_SemiAuto
		{
			dispersion = 0.009;
		};
	};
	class M120: M252
	{
		class Single1: Single1
		{
			dispersion = 0.009;
		};
	};
	class M240_veh: MGun
	{
		displayName = "$STR_ACE_WDN_M240";
		displayNameShort = "M240";
		autoReload = 0;
		magazineReloadTime = 12;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		aidispersionCoefX = "7*2";
		aidispersionCoefY = "8*2";
		magazines[] = {"100Rnd_762x51_M240","1200Rnd_762x51_M240","ACE_1100Rnd_762x51_M240","ACE_1000Rnd_762x51_M240","ACE_800Rnd_762x51_M240","ACE_400Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_1500Rnd_762x51_M240"};
		class manual: MGun
		{
			autoReload = 0;
			displayName = "$STR_ACE_WDN_M240";
			reloadTime = 0.06;
			dispersion = 0.0027;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class M240: Rifle
	{
		class manual;
		class close;
		class short;
		class medium;
		class far;
	};
	class ACE_M240_veh_out: M240
	{
		class Armory
		{
			disabled = 1;
		};
		scope = 1;
		model = "";
		displayName = "$STR_ACE_WDN_M240";
		displayNameShort = "M240";
		aidispersionCoefX = "12*2";
		aidispersionCoefY = "15*2";
		autoReload = 0;
		magazineReloadTime = 12;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		type = 65536;
		magazines[] = {"100Rnd_762x51_M240","1200Rnd_762x51_M240","ACE_1100Rnd_762x51_M240","ACE_1000Rnd_762x51_M240","ACE_800Rnd_762x51_M240","ACE_400Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_1500Rnd_762x51_M240"};
		class manual: manual
		{
			autoReload = 0;
			displayName = "$STR_ACE_WDN_M240";
			dispersion = 0.0027;
		};
		class close: close
		{
			aiRateOfFire = 1;
			dispersion = 0.0027;
			minRange = 0;
		};
		class short: short
		{
			aiRateOfFire = 2;
			dispersion = 0.0027;
		};
		class medium: medium
		{
			aiRateOfFire = 3;
			dispersion = 0.0027;
		};
		class far: far
		{
			aiRateOfFire = 4;
			dispersion = 0.0027;
		};
	};
	class ACE_M240_veh_out2: ACE_M240_veh_out{};
	class ACE_M240H_veh_out: ACE_M240_veh_out
	{
		displayName = "$STR_ACE_WDN_M240H";
		displayNameShort = "M240H";
		class manual: manual
		{
			displayName = "$STR_ACE_WDN_M240H";
		};
	};
	class ACE_M240H_veh_out2: ACE_M240_veh_out
	{
		displayName = "$STR_ACE_WDN_M240H";
		displayNameShort = "M240H";
		class manual: manual
		{
			displayName = "$STR_ACE_WDN_M240H";
		};
	};
	class M2: MGun
	{
		aidispersionCoefX = "12*2";
		aidispersionCoefY = "15*2";
		displayName = "$STR_ACE_WDN_M2";
		displayNameShort = "M2";
		magazineReloadTime = 16;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		autoReload = 0;
		maxLeadSpeed = 100;
		magazines[] = {"100Rnd_127x99_M2","ACE_200Rnd_127x99_M2_SLAP"};
		class manual: MGun
		{
			autoReload = 0;
			displayName = "$STR_ACE_WDN_M2";
			dispersion = 0.0015;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class ACE_M2_CSAMM: M2
	{
		displayNameShort = "CSAAM";
		aidispersionCoefX = "7*2";
		aidispersionCoefY = "8*2";
	};
	class M3P: M2
	{
		aidispersionCoefX = "7*2";
		aidispersionCoefY = "8*2";
		displayName = "$STR_ACE_WDN_M3P";
		magazines[] = {"250Rnd_127x99_M3P"};
	};
	class M134: MGun
	{
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		displayName = "$STR_ACE_WDN_M134";
		aidispersionCoefX = "12*2";
		aidispersionCoefY = "15*2";
		class LowROF: Mode_FullAuto
		{
			dispersion = 0.0065;
			reloadTime = 0.03;
			displayName = "LO";
			burst = 2;
			soundBurst = 1;
		};
		class HighROF: LowROF
		{
			reloadTime = 0.015;
			displayName = "HI";
			burst = 2;
			soundBurst = 1;
		};
		class close: HighROF
		{
			burst = 20;
			soundBurst = 0;
			aiRateOfFire = 1;
		};
		class short: close
		{
			burst = 16;
			aiRateOfFire = 2;
		};
		class medium: LowROF
		{
			burst = 8;
			soundBurst = 0;
			aiRateOfFire = 3;
		};
		class far: medium
		{
			burst = 10;
			aiRateOfFire = 4;
		};
	};
	class TwinM134: M134
	{
		magazines[] = {"2000Rnd_762x51_M134","4000Rnd_762x51_M134","ACE_5250Rnd_762x51_M134","ACE_2625Rnd_762x51_M134"};
		class LowROF: LowROF
		{
			dispersion = 0.0065;
			reloadTime = 0.015;
			burst = 4;
			displayName = "LO";
		};
		class HighROF: HighROF
		{
			dispersion = 0.0065;
			reloadTime = 0.0075;
			burst = 4;
			displayName = "HI";
		};
		class close: close
		{
			dispersion = 0.0065;
			reloadTime = 0.0075;
			burst = 40;
		};
		class short: short
		{
			dispersion = 0.0065;
			reloadTime = 0.0075;
			burst = 32;
		};
		class medium: medium
		{
			dispersion = 0.0065;
			reloadTime = 0.015;
			burst = 16;
		};
		class far: far
		{
			dispersion = 0.0065;
			reloadTime = 0.015;
			burst = 20;
		};
	};
	class M249: Rifle
	{
		class manual;
		class close;
		class short;
		class medium;
		class far;
	};
	class ACE_GMV_M249_1: M249
	{
		class Armory
		{
			disabled = 1;
		};
		displayNameShort = "M249";
		scope = 1;
		type = 65536;
		magazineReloadTime = 15;
		maxLeadSpeed = 600;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"ACE_200Rnd_556x45_M249"};
		class manual: manual{};
		class close: close
		{
			aiRateOfFire = 1;
			minRange = 0;
		};
		class short: short
		{
			aiRateOfFire = 2;
		};
		class medium: medium
		{
			aiRateOfFire = 3;
		};
		class far: far
		{
			aiRateOfFire = 4;
		};
	};
	class ACE_GMV_M249_2: ACE_GMV_M249_1{};
	class M168: CannonCore
	{
		scope = 2;
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		displayName = "$STR_ACE_WDN_M168";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"2100Rnd_20mm_M168"};
		weaponLockSystem = 8;
		ballisticsComputer = 1;
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_M168";
			dispersion = 0.0045;
			burst = 1;
			multiplier = 1;
			reloadTime = 0.02;
		};
		class close: manual
		{
			aiRateOfFire = 1;
			burst = 30;
		};
		class short: close
		{
			aiRateOfFire = 2;
			burst = 24;
		};
		class medium: close
		{
			aiRateOfFire = 3;
			burst = 12;
		};
		class far: close
		{
			aiRateOfFire = 4;
			burst = 15;
		};
	};
	class M197: CannonCore
	{
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		ballisticsComputer = 0;
		canLock = 0;
		displayName = "$STR_ACE_WDN_M197";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"750Rnd_M197_AH1"};
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_M197";
			dispersion = 0.0075;
			reloadTime = 0.08;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class ACE_GAU19: M197
	{
		displayName = "$STR_ACE_WDN_GAU19";
		magazines[] = {"ACE_900Rnd_127x99_GAU19"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		class manual: manual
		{
			showtoplayer = 1;
			autofire = 1;
			burst = 3;
			soundBurst = 0;
			displayName = "";
			dispersion = 0.0065;
			reloadTime = 0.046;
			maxLeadSpeed = 300;
		};
		class close: manual
		{
			soundBurst = 0;
			showToPlayer = 0;
			burst = 15;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			midRange = 200;
			maxRange = 500;
			minRangeProbab = 0.05;
			midRangeProbab = 0.58;
			maxRangeProbab = 0.04;
		};
		class short: close
		{
			burst = 12;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 300;
			minRange = 300;
			midRange = 600;
			maxRange = 800;
			minRangeProbab = 0.05;
			midRangeProbab = 0.58;
			maxRangeProbab = 0.04;
		};
		class medium: close
		{
			burst = 6;
			aiRateOfFire = 3;
			aiRateOfFireDistance = 600;
			minRange = 700;
			midRange = 900;
			maxRange = 1000;
			minRangeProbab = 0.05;
			midRangeProbab = 0.58;
			maxRangeProbab = 0.04;
		};
		class far: close
		{
			burst = 8;
			aiRateOfFire = 4;
			aiRateOfFireDistance = 1000;
			minRange = 1000;
			midRange = 1200;
			maxRange = 1400;
			minRangeProbab = 0.05;
			midRangeProbab = 0.4;
			maxRangeProbab = 0.01;
		};
	};
	class M230: CannonCore
	{
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		ballisticsComputer = 0;
		canLock = 2;
		displayName = "$STR_ACE_WDN_M230";
		magazines[] = {"1200Rnd_30x113mm_M789_HEDP"};
		cursor = "\ca\Weapons\Data\clear_empty";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_M230";
			reloadTime = 0.096;
			dispersion = 0.0045;
			initspeed = 805;
		};
		class close: manual
		{
			aiRateOfFire = 3;
		};
		class short: close
		{
			aiRateOfFire = 4;
		};
		class medium: close
		{
			aiRateOfFire = 5;
		};
		class far: close
		{
			aiRateOfFire = 6;
		};
	};
	class M242: CannonCore
	{
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		displayName = "$STR_ACE_WDN_M242";
		cursor = "\ca\Weapons\Data\clear_empty";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		canLock = 0;
		burst = 1;
		reloadTime = 0.3;
		magazineReloadTime = 0.5;
		magazines[] = {"210Rnd_25mm_M242_HEI","ACE_230Rnd_25mm_M242_HEI","210Rnd_25mm_M242_APDS","ACE_70Rnd_25mm_M242_APFSDS"};
		class LowROF: Mode_FullAuto
		{
			displayName = "LO";
			reloadTime = 0.6;
			dispersion = 0.0012;
		};
		class HighROF: LowROF
		{
			displayName = "HI";
			reloadTime = 0.3;
		};
		class close: HighROF
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: LowROF
		{
			aiRateOfFire = 3;
		};
		class far: medium
		{
			aiRateOfFire = 4;
			minRange = 2000;
			midRange = 2250;
			midRangeProbab = 0.04;
			maxRange = 2500;
		};
	};
	class ACE_M242_AP: M242
	{
		magazines[] = {"210Rnd_25mm_M242_APDS","ACE_70Rnd_25mm_M242_APFSDS"};
		class LowROF: LowROF
		{
			showToPlayer = 0;
		};
		class HighROF: HighROF
		{
			showToPlayer = 0;
		};
		showToPlayer = 0;
	};
	class ACE_M242: M242
	{
		muzzles[] = {"this","AP"};
		class AP: ACE_M242_AP{};
	};
	class ACE_M242_200: ACE_M242
	{
		class LowROF: LowROF
		{
			showToPlayer = 0;
		};
		class HighROF: HighROF
		{
			displayName = "$STR_ACE_WDN_M242";
		};
	};
	class GAU8: CannonCore
	{
		aiDispersionCoefX = "2*2";
		aiDispersionCoefY = "2*2";
	};
	class GAU12: CannonCore
	{
		aiDispersionCoefX = "2*2";
		aiDispersionCoefY = "2*2";
		displayName = "$STR_ACE_WDN_GAU12";
		weaponLockSystem = 8;
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_GAU12";
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class M621: MGun
	{
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		displayname = "20mm M621";
		class manual: MGun
		{
			displayname = "";
			dispersion = 0.009;
			reloadtime = 0.085;
			aiDispersionCoefX = "3*2";
			aiDispersionCoefY = "3*2";
		};
	};
	class CTWS: CannonCore
	{
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		displayname = "40mm CTWS";
		ballisticsComputer = 0;
		class player: Mode_FullAuto
		{
			aiDispersionCoefX = 1;
			aiDispersionCoefY = 1;
			ballisticsComputer = 0;
			dispersion = 0.001;
			displayName = "40mm CTWS";
		};
		class close: player
		{
			soundBurst = 0;
			aiDispersionCoefX = "3*2";
			aiDispersionCoefY = "3*2";
		};
	};
	class ACE_CTWS_AP: CTWS
	{
		magazines[] = {"200Rnd_40mmSABOT_FV510"};
		class player: player
		{
			showToPlayer = 0;
		};
		showToPlayer = 0;
	};
	class ACE_CTWS: CTWS
	{
		class AP: ACE_CTWS_AP{};
		muzzles[] = {"this","AP"};
	};
	class M256: CannonCore
	{
		displayName = "$STR_ACE_WDN_M256";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"ACE_25Rnd_120mmSABOT_M1A2","ACE_30Rnd_120mmSABOT_M1A2","ACE_22Rnd_120mmSABOT_M1A2","20Rnd_120mmSABOT_M1A2","ACE_6Rnd_120mmHE_M1A2","ACE_8Rnd_120mmHE_M1A2","ACE_15Rnd_120mmHE_M1A2","20Rnd_120mmHE_M1A2","ACE_4Rnd_M1028","ACE_5Rnd_M1028"};
		dispersion = 0.00025;
		aiDispersionCoefY = 0.125;
		midRange = 2500;
		midRangeProbab = 0.9;
		maxRange = 4000;
		maxRangeProbab = 0.6;
		reloadTime = 7;
		ballisticsComputer = 0;
		shotFromTurret = 1;
		aiRateOfFire = 7;
		aiRateOfFireDistance = 250;
	};
	class ACE_M256_HE: M256
	{
		magazines[] = {"ACE_6Rnd_120mmHE_M1A2","ACE_8Rnd_120mmHE_M1A2","ACE_15Rnd_120mmHE_M1A2","20Rnd_120mmHE_M1A2"};
		showToPlayer = 0;
	};
	class ACE_M256_PLT: M256
	{
		magazines[] = {"ACE_4Rnd_M1028","ACE_5Rnd_M1028"};
		showToPlayer = 0;
	};
	class ACE_M256: M256
	{
		class HE: ACE_M256_HE{};
		class PLT: ACE_M256_PLT{};
		muzzles[] = {"this","HE","PLT"};
	};
	class M68: M256
	{
		displayName = "M68A1E4";
		reloadTime = 7;
		magazineReloadTime = 0.1;
		dispersion = 0.0005;
		aiRateOfFire = 7;
		aiRateOfFireDistance = 250;
		magazines[] = {"ACE_9Rnd_M900","6RND_105mm_APDS","ACE_9Rnd_M456A2","12Rnd_105mm_HESH"};
		maxLeadSpeed = 50;
	};
	class ACE_M68_HE: M68
	{
		magazines[] = {"12Rnd_105mm_HESH"};
		showToPlayer = 0;
	};
	class ACE_M68_HEAT: M68
	{
		magazines[] = {"ACE_9Rnd_M456A2"};
		showToPlayer = 0;
	};
	class ACE_M68: M68
	{
		class HE: ACE_M68_HE{};
		class HEAT: ACE_M68_HEAT{};
		muzzles[] = {"this","HE","HEAT"};
	};
	class ACE_StrykerMgun105: ACE_M68{};
	class BombLauncher: RocketPods
	{
		displayName = "GBU-12D/B Paveway";
		magazines[] = {"6Rnd_GBU12_AV8B"};
	};
	class ACE__B61BombLauncher: BombLauncher
	{
		ace_bwc = 1;
	};
	class BAF_L7A2: MGun
	{
		aiDispersionCoefX = "12*2";
		aiDispersionCoefY = "15*2";
		displayNameShort = "L7A2";
		magazines[] = {"100Rnd_762x51_M240","1200Rnd_762x51_M240","ACE_1100Rnd_762x51_M240","ACE_1000Rnd_762x51_M240","ACE_800Rnd_762x51_M240","ACE_400Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_1500Rnd_762x51_M240"};
	};
	class BAF_L94A1: MGun
	{
		aiDispersionCoefX = "7*2";
		aiDispersionCoefY = "8*2";
		displayName = "7.62mm L94A1";
	};
	class PKT: MGun
	{
		displayName = "$STR_ACE_WDN_PKT";
		displayNameShort = "PKMT";
		autoReload = 0;
		magazineReloadTime = 12;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		aidispersionCoefX = "7*2";
		aidispersionCoefY = "8*2";
		class manual: MGun
		{
			autoReload = 0;
			displayName = "$STR_ACE_WDN_PKT";
			dispersion = 0.003;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class DT_veh: PKT
	{
		displayName = "$STR_ACE_WDN_DT";
		autoReload = 0;
		magazineReloadTime = 12;
		aidispersionCoefX = "9*2";
		aidispersionCoefY = "12*2";
		class manual: manual
		{
			autoReload = 0;
			displayName = "$STR_ACE_WDN_DT";
			dispersion = 0.0035;
		};
		class close: close
		{
			dispersion = 0.0035;
		};
		class short: short
		{
			dispersion = 0.0035;
		};
		class medium: medium
		{
			dispersion = 0.0035;
		};
		class far: far
		{
			dispersion = 0.0035;
		};
	};
	class PKT_MG_Nest: PKT
	{
		aidispersionCoefX = "12*2";
		aidispersionCoefY = "15*2";
		class manual: manual
		{
			dispersion = 0.0035;
		};
		class close: close
		{
			dispersion = 0.0035;
		};
		class short: short
		{
			dispersion = 0.0035;
		};
		class medium: medium
		{
			dispersion = 0.0035;
		};
		class far: far
		{
			dispersion = 0.0035;
		};
	};
	class PKT_veh: PKT_MG_Nest
	{
		aidispersionCoefX = "9*2";
		aidispersionCoefY = "12*2";
		class manual: manual
		{
			dispersion = 0.003;
		};
		class close: close
		{
			dispersion = 0.003;
		};
		class short: short
		{
			dispersion = 0.003;
		};
		class medium: medium
		{
			dispersion = 0.003;
		};
		class far: far
		{
			dispersion = 0.003;
		};
	};
	class PK: Rifle
	{
		class manual;
		class close;
		class short;
		class medium;
		class far;
	};
	class ACE_PKT_out: PK
	{
		class Armory
		{
			disabled = 1;
		};
		scope = 1;
		aidispersionCoefX = "12*2";
		aidispersionCoefY = "15*2";
		autoReload = 0;
		magazineReloadTime = 12;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		type = 65536;
		displayName = "$STR_ACE_WDN_PKT";
		displayNameShort = "PKMT";
		magazines[] = {"100Rnd_762x54_PK","1500Rnd_762x54_PKT","2000Rnd_762x54_PKT","250Rnd_762x54_PKT_T90","200Rnd_762x54_PKT"};
		class manual: manual
		{
			displayName = "$STR_ACE_WDN_PKT";
			dispersion = 0.0035;
		};
		class close: close
		{
			dispersion = 0.0035;
			aiRateOfFire = 1;
			minRange = 0;
		};
		class short: short
		{
			dispersion = 0.0035;
			aiRateOfFire = 2;
		};
		class medium: medium
		{
			dispersion = 0.0035;
			aiRateOfFire = 3;
		};
		class far: far
		{
			dispersion = 0.0035;
			aiRateOfFire = 4;
		};
	};
	class ACE_PKT_out_2: ACE_PKT_out{};
	class ACE_PKT_out_3: ACE_PKT_out{};
	class KORD: MGun
	{
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		autoReload = 0;
		magazineReloadTime = 20;
		displayName = "$STR_ACE_WDN_KORD";
		displayNameShort = "Kord";
		maxLeadSpeed = 100;
		class manual: MGun
		{
			displayName = "$STR_ACE_WDN_KORD";
			dispersion = 0.0015;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class ACE_NSVT: KORD
	{
		displayName = "$STR_ACE_WDN_NSVT";
		displayNameShort = "NSVT";
		class manual: manual
		{
			dispersion = 0.002;
			displayName = "$STR_ACE_WDN_NSVT";
		};
		class close: close
		{
			dispersion = 0.002;
		};
		class short: short
		{
			dispersion = 0.002;
		};
		class medium: medium
		{
			dispersion = 0.002;
		};
		class far: far
		{
			dispersion = 0.002;
		};
	};
	class DSHKM: MGun
	{
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		autoReload = 0;
		magazineReloadTime = 20;
		displayName = "$STR_ACE_WDN_DSHKM";
		displayNameShort = "$STR_ACE_VDN_DSHKM_BASE";
		maxLeadSpeed = 100;
		class manual: MGun
		{
			displayName = "$STR_ACE_WDN_DSHKM";
			dispersion = 0.0045;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class YakB: MGun
	{
		displayName = "$STR_ACE_WDN_YAKB";
		ballisticsComputer = 0;
		canLock = 0;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		firespreadangle = "0.5f";
		class manual: MGun
		{
			displayName = "$STR_ACE_WDN_YAKB";
			burst = 4;
			multiplier = 1;
			reloadTime = 0.012;
			dispersion = 0.009;
			soundBurst = 1;
		};
		class close: manual
		{
			burst = 8;
			soundBurst = 0;
			aiRateOfFire = 1;
		};
		class short: close
		{
			burst = 16;
			aiRateOfFire = 2;
		};
		class medium: close
		{
			burst = 16;
			aiRateOfFire = 3;
		};
		class far: close
		{
			burst = 8;
			aiRateOfFire = 4;
		};
	};
	class ACE_YakB_1SL: YakB
	{
		magazines[] = {"ACE_1470Rnd_127x108_1SL"};
		modes[] = {"manual"};
		magazineReloadTime = 0;
		class manual: manual
		{
			burst = 1;
			dispersion = 0.003;
			fireSpreadAngle = "0.029f";
			reloadTime = 0;
			minRange = 0;
			midRange = 0;
			maxRange = 0;
			minRangeProbab = 0;
			midRangeProbab = 0;
			maxRangeProbab = 0;
			showToPlayer = 0;
			soundBegin[] = {};
			soundContinous = 0;
			soundBurst = 1;
		};
	};
	class KPVT: MGun
	{
		displayName = "$STR_ACE_WDN_KPVT";
		autoReload = 0;
		magazineReloadTime = 20;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		aiDispersionCoefX = "8*2";
		aiDispersionCoefY = "10*2";
		magazines[] = {"500Rnd_145x115_KPVT","ACE_50Rnd_145x114_KPVT"};
		class manual: MGun
		{
			displayName = "$STR_ACE_WDN_KPVT";
			autoReload = 0;
			dispersion = 0.0013;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class AZP85: CannonCore
	{
		aiDispersionCoefX = "4*2";
		aiDispersionCoefY = "4*2";
		displayName = "$STR_ACE_WDN_AZP85";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"2000Rnd_23mm_AZP85","ACE_4x50Rnd_23mm_OFZT"};
		magazineReloadTime = 20;
		autoReload = 0;
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_AZP85";
			dispersion = 0.00035;
			burst = 2;
			multiplier = 1;
		};
		class close: manual
		{
			burst = 16;
			aiRateOfFire = 1;
			minRange = 200;
			minRangeProbab = 0.025;
			midRange = 1000;
			midRangeProbab = 0.95;
			maxRange = 1600;
			maxRangeProbab = 0.025;
			aiRateOfFireDistance = 1600;
		};
		class short: close
		{
			burst = 16;
			aiRateOfFire = 1;
			minRange = 1000;
			minRangeProbab = 0.05;
			midRange = 1600;
			midRangeProbab = 0.9;
			maxRange = 2200;
			maxRangeProbab = 0.05;
			aiRateOfFireDistance = 2200;
		};
		class medium: close
		{
			burst = 12;
			aiRateOfFire = 3;
			minRange = 1600;
			minRangeProbab = 0.075;
			midRange = 2200;
			midRangeProbab = 0.85;
			maxRange = 2800;
			maxRangeProbab = 0.075;
			aiRateOfFireDistance = 3400;
		};
		class far: close
		{
			burst = 2;
			aiRateOfFire = 5;
			minRange = 2200;
			minRangeProbab = 0.125;
			midRange = 2800;
			midRangeProbab = 0.75;
			maxRange = 3400;
			maxRangeProbab = 0.125;
			aiRateOfFireDistance = 3400;
		};
	};
	class 2A14: CannonCore
	{
		aiDispersionCoefX = "7*2";
		aiDispersionCoefY = "8*2";
		displayName = "$STR_ACE_WDN_2A14";
		magazineReloadTime = 20;
		autoReload = 0;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_2A14";
			dispersion = 0.0035;
			reloadTime = 0.03;
			burst = 2;
			multiplier = 1;
		};
		class close: manual
		{
			burst = 6;
			aiRateOfFire = 1;
		};
		class short: close
		{
			burst = 8;
			aiRateOfFire = 2;
		};
		class medium: close
		{
			burst = 6;
			aiRateOfFire = 3;
		};
		class far: close
		{
			burst = 4;
			aiRateOfFire = 4;
		};
	};
	class GSh23L: CannonCore
	{
		aiDispersionCoefX = "2*2";
		aiDispersionCoefY = "2*2";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		displayName = "$STR_ACE_WDN_GSH23L";
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_GSH23L";
			burst = 2;
			multiplier = 1;
			reloadTime = 0.012;
			dispersion = 0.0035;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class ACE_UPK23: GSh23L
	{
		displayName = "$STR_ACE_WDN_UPK23";
		magazines[] = {"ACE_500Rnd_23mm_UPK23"};
		class manual: manual
		{
			displayName = "$STR_ACE_WDN_UPK23";
			burst = 4;
			reloadTime = 0.01;
			minRange = 0;
			midRange = 100;
			maxRange = 200;
		};
		class close: close
		{
			reloadTime = 0.01;
			minRange = 0;
			midRange = 150;
			maxRange = 100;
		};
		class short: short
		{
			reloadTime = 0.01;
			minRange = 150;
			midRange = 400;
			maxRange = 550;
		};
		class medium: medium
		{
			reloadTime = 0.01;
			minRange = 400;
			midRange = 550;
			maxRange = 700;
		};
		class far: far
		{
			reloadTime = 0.01;
			minRange = 550;
			midRange = 700;
			maxRange = 850;
		};
	};
	class 2A42: CannonCore
	{
		aiDispersionCoefX = "6*2";
		aiDispersionCoefY = "6*2";
		displayName = "$STR_ACE_WDN_2A42";
		magazineReloadTime = 0.5;
		burst = 1;
		cursor = "\ca\Weapons\Data\clear_empty";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"150Rnd_30mmHE_2A42","230Rnd_30mmHE_2A42","250Rnd_30mmHE_2A42","ACE_120Rnd_30mmHE_2A42","150Rnd_30mmAP_2A42","230Rnd_30mmAP_2A42","250Rnd_30mmAP_2A42","ACE_180Rnd_30mmAP_2A42"};
		class LowROF: Mode_FullAuto
		{
			displayName = "LO";
			dispersion = 0.0017;
			reloadTime = 0.2;
		};
		class HighROF: LowROF
		{
			displayName = "HI";
			dispersion = 0.0025;
			reloadTime = 0.1;
		};
		class close: HighROF
		{
			aiRateOfFire = 1;
			minRange = 0;
			midRange = 400;
			maxRange = 800;
		};
		class short: close
		{
			aiRateOfFire = 2;
			minRange = 400;
			midRange = 800;
			maxRange = 1200;
		};
		class medium: LowROF
		{
			aiRateOfFire = 3;
			minRange = 800;
			midRange = 1200;
			maxRange = 1600;
		};
		class far: medium
		{
			aiRateOfFire = 4;
			minRange = 1200;
			midRange = 1600;
			maxRange = 2000;
			midRangeProbab = 0.04;
		};
	};
	class ACE_2A42_AP: 2A42
	{
		magazines[] = {"150Rnd_30mmAP_2A42","230Rnd_30mmAP_2A42","250Rnd_30mmAP_2A42","ACE_180Rnd_30mmAP_2A42"};
		class LowROF: LowROF
		{
			showToPlayer = 0;
		};
		class HighROF: HighROF
		{
			showToPlayer = 0;
		};
		showToPlayer = 0;
	};
	class ACE_2A42: 2A42
	{
		muzzles[] = {"this","AP"};
		class AP: ACE_2A42_AP{};
	};
	class 2A72: CannonCore
	{
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		displayName = "$STR_ACE_WDN_2A72";
		magazineReloadTime = 0.5;
		magazines[] = {"250Rnd_30mmHE_2A72","250Rnd_30mmAP_2A72"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_2A72";
			dispersion = 0.0017;
			reloadTime = 0.17;
		};
		class close: manual
		{
			aiRateOfFire = 1;
			minRange = 0;
			midRange = 400;
			maxRange = 800;
		};
		class short: close
		{
			aiRateOfFire = 2;
			minRange = 400;
			midRange = 800;
			maxRange = 1200;
		};
		class medium: close
		{
			aiRateOfFire = 3;
			minRange = 800;
			midRange = 1200;
			maxRange = 1600;
		};
		class far: close
		{
			aiRateOfFire = 4;
			minRange = 1200;
			midRange = 1600;
			maxRange = 2000;
		};
	};
	class ACE_2A72_AP: 2A72
	{
		magazines[] = {"250Rnd_30mmAP_2A72"};
		class manual: manual
		{
			showToPlayer = 0;
		};
		showToPlayer = 0;
	};
	class ACE_2A72: 2A72
	{
		muzzles[] = {"this","AP"};
		class AP: ACE_2A72_AP{};
	};
	class GSh302: CannonCore
	{
		aiDispersionCoefX = "2*2";
		aiDispersionCoefY = "2*2";
		displayName = "$STR_ACE_WDN_GSH302";
		magazines[] = {"750Rnd_30mm_GSh301","ACE_250Rnd_30mm_GSh302"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_GSH302";
			dispersion = 0.004;
			burst = 2;
			multiplier = 1;
			reloadTime = 0.02;
			soundBurst = 0;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class ACE_GSh302K: GSh302
	{
		displayName = "$STR_ACE_WDN_GSH302K";
		class manual: manual
		{
			displayName = "$STR_ACE_WDN_GSH302K";
			reloadTime = 0.025;
		};
		class close: close
		{
			reloadTime = 0.025;
		};
		class short: short
		{
			reloadTime = 0.025;
		};
		class medium: medium
		{
			reloadTime = 0.025;
		};
		class far: far
		{
			reloadTime = 0.025;
		};
	};
	class 2A38M: CannonCore
	{
		aiDispersionCoefX = "3*2";
		aiDispersionCoefY = "3*2";
		displayName = "$STR_ACE_WDN_2A38M";
		magazines[] = {"1904Rnd_30mmAA_2A38M"};
		reloadTime = 0.00625;
		multiplier = 1;
		dispersion = 0.0045;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		weaponLockSystem = 8;
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_2A38M";
			reloadTime = 0.00625;
			dispersion = 0.0045;
			multiplier = 1;
		};
		class close: manual
		{
			aiRateOfFire = 1;
			minRange = 200;
			minRangeProbab = 0.025;
			midRange = 1300;
			midRangeProbab = 0.95;
			maxRange = 2350;
			maxRangeProbab = 0.025;
			aiRateOfFireDistance = 2350;
		};
		class short: close
		{
			aiRateOfFire = 2;
			minRange = 1300;
			minRangeProbab = 0.05;
			midRange = 2350;
			midRangeProbab = 0.9;
			maxRange = 3400;
			maxRangeProbab = 0.05;
			aiRateOfFireDistance = 3400;
		};
		class medium: close
		{
			aiRateOfFire = 3;
			minRange = 2350;
			minRangeProbab = 0.075;
			midRange = 3400;
			midRangeProbab = 0.85;
			maxRange = 4450;
			maxRangeProbab = 0.075;
			aiRateOfFireDistance = 4450;
		};
		class far: close
		{
			aiRateOfFire = 4;
			minRange = 3400;
			minRangeProbab = 0.125;
			midRange = 4450;
			midRangeProbab = 0.75;
			maxRange = 5500;
			maxRangeProbab = 0.125;
			aiRateOfFireDistance = 5500;
		};
	};
	class D81: CannonCore
	{
		displayName = "$STR_ACE_WDN_2A46_1";
		magazines[] = {"23Rnd_125mmSABOT_T72","ACE_3BM17","22Rnd_125mmHE_T72","ACE_8Rnd_3OF26","ACE_3BK18","ACE_3BK29"};
		reloadTime = 8;
		magazineReloadTime = 0.1;
		maxLeadSpeed = 75;
		minRange = 1;
		minRangeProbab = 0.1;
		midRange = 1000;
		midRangeProbab = 0.9;
		maxRange = 2000;
		maxRangeProbab = 0.1;
		aiRateOfFire = 7.5;
		aiRateOfFireDistance = 250;
		dispersion = 0.0005;
		aiDispersionCoefY = 0.125;
		ballisticsComputer = 0;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		shotFromTurret = 1;
	};
	class ACE_2A46_1_HE: D81
	{
		magazines[] = {"22Rnd_125mmHE_T72","ACE_8Rnd_3OF26"};
		showToPlayer = 0;
	};
	class ACE_2A46_1_HEAT: D81
	{
		magazines[] = {"ACE_3BK18","ACE_3BK29"};
		showToPlayer = 0;
	};
	class ACE_2A46_1: D81
	{
		displayName = "$STR_ACE_WDN_2A46_1";
		class HE: ACE_2A46_1_HE{};
		class HEAT: ACE_2A46_1_HEAT{};
		muzzles[] = {"this","HE","HEAT"};
	};
	class 2A46M: D81
	{
		displayName = "$STR_ACE_WDN_2A46M_2";
		midRange = 2500;
		maxRange = 4000;
		maxRangeProbab = 0.6;
		ballisticsComputer = 0;
		dispersion = 0.00025;
		aiDispersionCoefY = 0.125;
		magazines[] = {"23Rnd_125mmSABOT_T72","ACE_3BM17","ACE_3BM42M","ACE_3BK29M","ACE_3BK29","ACE_3BK18","5Rnd_AT11_T90","ACE_AT11","22Rnd_125mmHE_T72","ACE_8Rnd_3OF26"};
		magazineReloadTime = 0.1;
		reloadTime = 7;
		canlock = 0;
	};
	class ACE_2A46M_1_HE: D81
	{
		magazines[] = {"22Rnd_125mmHE_T72","ACE_8Rnd_3OF26"};
		showToPlayer = 0;
	};
	class ACE_2A46M_1_HEAT: D81
	{
		magazines[] = {"ACE_3BK18","ACE_3BK29","ACE_3BK29M"};
		showToPlayer = 0;
	};
	class ACE_2A46M_1_AT11: D81
	{
		magazines[] = {"ACE_AT11"};
		showToPlayer = 0;
	};
	class ACE_2A46M_1: 2A46M
	{
		displayName = "$STR_ACE_WDN_2A46M_1";
		class HE: ACE_2A46M_1_HE{};
		class HEAT: ACE_2A46M_1_HEAT{};
		class AT11: ACE_2A46M_1_AT11{};
		muzzles[] = {"this","HE","HEAT","AT11"};
	};
	class D10: CannonCore
	{
		displayName = "D-10T2S";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"ACE_6Rnd_100mm_3BM8","ACE_6Rnd_100mm_BR412D","ACE_22Rnd_100mm_OF412","21Rnd_100mmHEAT_D10"};
		ballisticsComputer = 0;
		minRange = 10;
		minRangeProbab = 0.7;
		midRange = 600;
		midRangeProbab = 0.7;
		maxRange = 1500;
		maxRangeProbab = 0.1;
		reloadTime = 8.5;
		magazineReloadTime = 0.1;
		shotFromTurret = 1;
		dispersion = 0.0008;
		aiRateOfFireDistance = 250;
	};
	class ACE_D10_HE: D10
	{
		magazines[] = {"ACE_22Rnd_100mm_OF412"};
		showToPlayer = 0;
	};
	class ACE_D10_HEAT: D10
	{
		magazines[] = {"21Rnd_100mmHEAT_D10"};
		showToPlayer = 0;
	};
	class ACE_D10: D10
	{
		class HE: ACE_D10_HE{};
		class HEAT: ACE_D10_HEAT{};
		muzzles[] = {"this","HE","HEAT"};
	};
	class ZiS_S_53: CannonCore
	{
		displayName = "$STR_ACE_WDN_ZIS_S_53";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"10Rnd_85mmAP","33Rnd_85mmHE","ACE_BR365P"};
		minRange = 5;
		minRangeProbab = 0.7;
		midRange = 600;
		midRangeProbab = 0.7;
		maxRange = 1000;
		maxRangeProbab = 0.1;
		reloadTime = 8.5;
		magazineReloadTime = 0.1;
		shotFromTurret = 1;
		aiRateOfFireDistance = 250;
	};
	class ACE_ZiS_S_53_HE: ZiS_S_53
	{
		magazines[] = {"33Rnd_85mmHE"};
		showToPlayer = 0;
	};
	class ACE_ZiS_S_53_HVAP: ZiS_S_53
	{
		magazines[] = {"ACE_BR365P"};
		showToPlayer = 0;
	};
	class ACE_ZiS_S_53: ZiS_S_53
	{
		class HE: ACE_ZiS_S_53_HE{};
		class HVAP: ACE_ZiS_S_53_HVAP{};
		muzzles[] = {"this","HE","HVAP"};
	};
	class 2A70: D81
	{
		displayName = "$STR_ACE_WDN_2A70";
		magazineReloadTime = 0.1;
		magazines[] = {"8Rnd_AT10_BMP3","22Rnd_100mm_HE_2A70"};
		canlock = 0;
	};
	class ACE_2A70_HE: 2A70
	{
		magazines[] = {"22Rnd_100mm_HE_2A70"};
		showToPlayer = 0;
	};
	class ACE_2A70: 2A70
	{
		class HE: ACE_2A70_HE{};
		muzzles[] = {"this","HE"};
	};
	class ACE_2A28_Base: CannonCore
	{
		scope = 2;
		reloadSound[] = {"\ca\Sounds\weapons\cannon\gun120reload",1,1,20};
		displayName = "$STR_ACE_WDN_2A28";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		magazines[] = {"ACE_24Rnd_73mm_PG15V","ACE_16Rnd_73mm_OG15V"};
		minRange = 5;
		minRangeProbab = 0.7;
		midRange = 600;
		midRangeProbab = 0.7;
		maxRange = 1300;
		maxRangeProbab = 0.1;
		reloadTime = 8.5;
		shotFromTurret = 1;
		aiRateOfFireDistance = 250;
	};
	class ACE_2A28_HE: ACE_2A28_Base
	{
		magazines[] = {"ACE_16Rnd_73mm_OG15V"};
		showToPlayer = 0;
	};
	class ACE_2A28: ACE_2A28_Base
	{
		class HE: ACE_2A28_HE{};
		muzzles[] = {"this","HE"};
	};
	class FFARLauncher: RocketPods
	{
		canLock = 0;
		cursor = "Vehicle_Grenade_W";
		cursorAim = "Vehicle_Grenade_W";
		displayName = "$STR_ACE_WDN_FFARLAUNCHER";
		magazines[] = {"38Rnd_FFAR","28Rnd_FFAR","ACE_19Rnd_70mm_FFAR_HE"};
		class Far_AI: RocketPods
		{
			maxRange = 300;
			midRange = 200;
			minRange = 100;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.25;
		};
		class Burst: RocketPods
		{
			displayName = "$STR_ACE_WDN_FFARLAUNCHER";
			burst = 1;
			maxRange = 350;
			midRange = 200;
			minRange = 50;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.25;
		};
	};
	class FFARLauncher_14: FFARLauncher
	{
		displayName = "$STR_ACE_WDN_FFARLAUNCHER_14";
		class Burst: Burst
		{
			displayName = "$STR_ACE_WDN_FFARLAUNCHER_14";
			burst = 1;
		};
	};
	class ACE_FFARLauncher_7: FFARLauncher_14
	{
		magazines[] = {"ACE_7Rnd_70mm_FFAR_HE"};
		class Far_AI: Far_AI
		{
			maxRange = 200;
			midRange = 125;
			minRange = 50;
		};
		class Burst: Burst
		{
			maxRange = 200;
			midRange = 125;
			minRange = 50;
		};
	};
	class CRV7_PG: RocketPods
	{
		cursor = "\ca\Weapons\Data\clear_empty";
		cursoraim = "\ca\Weapons\Data\clear_empty";
		displayName = "CRV7";
		class Burst: RocketPods
		{
			displayName = "CRV7";
			autofire = 0;
		};
		autofire = 0;
	};
	class CRV7_HEPD: CRV7_PG
	{
		WeaponLockSystem = 0;
		displayName = "CRV7 HE";
		class Burst: RocketPods
		{
			displayName = "CRV7 HE";
		};
	};
	class CRV7_FAT: CRV7_PG
	{
		WeaponLockSystem = 0;
		displayName = "CRV7 FAT";
		class Burst: RocketPods
		{
			displayName = "CRV7 FAT";
		};
	};
	class 57mmLauncher: RocketPods
	{
		canLock = 0;
		displayName = "$STR_ACE_WDN_57MMLAUNCHER";
		class Far_AI: RocketPods
		{
			maxRange = 300;
			midRange = 200;
			minRange = 100;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.25;
		};
		class Burst: RocketPods
		{
			displayName = "$STR_ACE_WDN_57MMLAUNCHER";
			burst = 1;
			maxRange = 350;
			midRange = 200;
			minRange = 50;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.25;
			reloadTime = 0.08;
		};
	};
	class ACE_UB16_Pods: 57mmLauncher
	{
		displayName = "$STR_ACE_WDN_UB16_PODS";
		magazines[] = {"64Rnd_57mm","ACE_32Rnd_57mm","ACE_64Rnd_57mm"};
		class Far_AI: Far_AI
		{
			maxRange = 1500;
			midRange = 1000;
			minRange = 300;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.4;
			burst = 2;
			aiRateofFire = 1.1;
			aiRateofFireDistance = 1000;
		};
		class Burst: Burst
		{
			displayName = "$STR_ACE_WDN_UB16_PODS";
			burst = 1;
		};
	};
	class 80mmLauncher: RocketPods
	{
		canLock = 0;
		displayName = "$STR_ACE_WDN_80MMLAUNCHER";
		magazineReloadTime = 0;
		class Far_AI: RocketPods
		{
			maxRange = 300;
			midRange = 200;
			minRange = 100;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.25;
		};
		class Burst: RocketPods
		{
			displayName = "$STR_ACE_WDN_80MMLAUNCHER";
			burst = 1;
			maxRange = 350;
			midRange = 200;
			minRange = 50;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.25;
		};
	};
	class S8Launcher: 80mmLauncher
	{
		class Far_AI;
	};
	class ACE_S8Launcher: S8Launcher
	{
		magazines[] = {"ACE_120Rnd_S8T","ACE_80Rnd_S8T","ACE_40Rnd_S8T","ACE_20Rnd_S8T","80Rnd_S8T","40Rnd_S8T"};
		class HE: S8Launcher
		{
			magazines[] = {"80Rnd_80mm","40Rnd_80mm"};
			class Far_AI: Far_AI{};
		};
		muzzles[] = {"this","HE"};
	};
	class ACE_S8Launcher_Plane: ACE_S8Launcher
	{
		magazines[] = {"ACE_120Rnd_S8T","ACE_80Rnd_S8T","ACE_40Rnd_S8T","ACE_20Rnd_S8T","80Rnd_S8T","40Rnd_S8T"};
		class Far_AI: Far_AI
		{
			maxRange = 1500;
			midRange = 1000;
			minRange = 400;
			maxRangeProbab = 0.1;
			midRangeProbab = 0.5;
			minRangeProbab = 0.4;
			burst = 2;
			aiRateofFire = 1.1;
			aiRateofFireDistance = 1000;
		};
		class HE: HE
		{
			class Far_AI: Far_AI
			{
				maxRange = 1500;
				midRange = 1000;
				minRange = 400;
				maxRangeProbab = 0.1;
				midRangeProbab = 0.5;
				minRangeProbab = 0.4;
				burst = 2;
				aiRateofFire = 1.1;
				aiRateofFireDistance = 1000;
			};
		};
	};
	class HeliBombLauncher: RocketPods
	{
		displayName = "$STR_ACE_WDN_HELIBOMBLAUNCHER";
		canLock = 0;
		minRange = 100;
		magazineReloadTime = 0;
	};
	class Mk82BombLauncher: RocketPods
	{
		displayName = "Mk82";
		canLock = 0;
		minRange = 100;
		magazineReloadTime = 0;
	};
	class SPG9: RocketPods
	{
		displayName = "$STR_ACE_WDN_SPG9";
		displayNameShort = "$STR_ACE_VDN_SPG9_BASE";
		autoReload = 0;
		magazines[] = {"PG9_AT","OG9_HE"};
		magazineReloadTime = 0;
		reloadTime = 10;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		ace_at_zero = 30.333332;
		ace_at_zero_fov = 0.073143;
		aiRateOfFireDistance = 225;
	};
	class ACE_SPG9_HE: SPG9
	{
		magazines[] = {"OG9_HE"};
		showToPlayer = 0;
	};
	class ACE_SPG9: SPG9
	{
		class HE: ACE_SPG9_HE{};
		muzzles[] = {"this","HE"};
	};
	class AGS30: MGun
	{
		displayName = "$STR_ACE_WDN_AGS30";
		displayNameShort = "$STR_ACE_VDN_AGS_BASE";
		autoReload = 0;
		reloadtime = 0.15;
		airateoffire = 1;
		airateoffiredistance = 500;
	};
	class ACE_AGS30: AGS30
	{
		modes[] = {"Auto","Burst1","Burst2","Burst3"};
		class Auto: AGS30
		{
			airateoffire = 0.5;
			airateoffiredistance = 300;
			maxrange = 300;
			midrange = 150;
			minrange = 8;
		};
		class Burst1: AGS30
		{
			maxrange = "1400 + round random 100";
			midrange = "350 + round random 100";
			minrange = "150 + round random 100";
			soundburst = 0;
			burst = "2 + round random 10";
			showtoplayer = 0;
		};
		class Burst2: Burst1
		{
			maxrange = "1400 + round random 100";
			midrange = "350 + round random 100";
			minrange = "150 + round random 100";
			burst = "2 + round random 8";
		};
		class Burst3: Burst1
		{
			maxrange = "1400 + round random 100";
			midrange = "350 + round random 100";
			minrange = "150 + round random 100";
			burst = "2 + round random 6";
		};
	};
	class MK19: MGun
	{
		displayName = "$STR_ACE_WDN_MK19";
		displayNameShort = "Mk19";
		autoReload = 0;
		reloadtime = 0.17;
		airateoffire = 1;
		airateoffiredistance = 500;
	};
	class ACE_MK19: MK19
	{
		modes[] = {"Auto","Burst1","Burst2","Burst3"};
		class Auto: MK19
		{
			airateoffire = 0.5;
			airateoffiredistance = 300;
			maxrange = 300;
			midrange = 150;
			minrange = 8;
		};
		class Burst1: MK19
		{
			maxrange = "1400 + round random 100";
			midrange = "350 + round random 100";
			minrange = "150 + round random 100";
			soundburst = 0;
			burst = "2 + round random 10";
			showtoplayer = 0;
		};
		class Burst2: Burst1
		{
			maxrange = "1400 + round random 100";
			midrange = "350 + round random 100";
			minrange = "150 + round random 100";
			burst = "2 + round random 8";
		};
		class Burst3: Burst1
		{
			maxrange = "1400 + round random 100";
			midrange = "350 + round random 100";
			minrange = "150 + round random 100";
			burst = "2 + round random 6";
		};
	};
	class TOWLauncher: MissileLauncher
	{
		displayName = "BGM-71 TOW2A";
		displayNameShort = "TOW";
		magazineReloadTime = 90;
		reloadTime = 2;
		autoReload = 0;
		maxRange = 3750;
		magazines[] = {"2Rnd_TOW","2Rnd_TOW2","ACE_TOW","ACE_TOW2","ACE_TOW4","ACE_TOW8"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		canlock = 0;
	};
	class TOWLauncherSingle: TOWLauncher
	{
		autoFire = 1;
		magazineReloadTime = 20;
		magazines[] = {"6Rnd_TOW_HMMWV","6Rnd_TOW2","ACE_TOW","ACE_TOW2"};
	};
	class StingerLaucher: MissileLauncher
	{
		magazines[] = {"8Rnd_Stinger","ACE_1Rnd_Stinger"};
	};
	class StingerLauncher_twice: MissileLauncher
	{
		displayName = "FIM-92F Stinger";
		magazines[] = {"2Rnd_Stinger","ACE_1Rnd_Stinger"};
	};
	class StingerLaucher_4x: StingerLaucher
	{
		magazines[] = {"4Rnd_Stinger","ACE_1Rnd_Stinger"};
	};
	class HellfireLauncher: MissileLauncher
	{
		magazineReloadTime = 0;
		displayName = "AGM-114K Hellfire II";
		minRange = 250;
		maxRange = 8000;
		reloadTime = 1;
		magazines[] = {"ACE_1Rnd_Hellfire","ACE_2Rnd_Hellfire","ACE_4Rnd_Hellfire","ACE_6Rnd_Hellfire","ACE_8Rnd_Hellfire","ACE_10Rnd_Hellfire","ACE_12Rnd_Hellfire","ACE_14Rnd_Hellfire","ACE_16Rnd_Hellfire","8Rnd_Hellfire"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
	};
	class ACE_DAGR_Launcher: HellfireLauncher
	{
		displayName = "DAGR";
		magazines[] = {"ACE_8Rnd_DAGR"};
		sound[] = {"\ca\Sounds\weapons\cannon\RocketLauncher_Shot21",3.16228,1,1100};
		soundFly[] = {"\ca\Sounds\weapons\cannon\rocket_fly1",5.62341,1.2,700};
	};
	class ACE_HellfireLauncher_Apache: HellfireLauncher
	{
		displayName = "AGM-114L Hellfire II";
		magazines[] = {"ACE_1Rnd_Hellfire_L","ACE_2Rnd_Hellfire_L","ACE_4Rnd_Hellfire_L","ACE_6Rnd_Hellfire_L","ACE_8Rnd_Hellfire_L","ACE_10Rnd_Hellfire_L","ACE_12Rnd_Hellfire_L","ACE_14Rnd_Hellfire_L","ACE_16Rnd_Hellfire_L"};
	};
	class MaverickLauncher: MissileLauncher
	{
		displayName = "AGM-65D Maverick";
		weaponLockDelay = 2;
		minRange = 1000;
		maxRange = 6500;
		magazines[] = {"2Rnd_Maverick_A10"};
		magazineReloadTime = 0;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
	};
	class AALauncher_twice: StingerLauncher_twice
	{
		displayName = "FIM-92F Stinger";
	};
	class ACE_StingerLauncher_four: StingerLauncher_twice
	{
		magazineReloadTime = 0;
		magazines[] = {"2Rnd_Stinger","8Rnd_Stinger","ACE_4Rnd_Stinger"};
	};
	class SidewinderLaucher: MissileLauncher
	{
		displayName = "AIM-9X Sidewinder";
		magazineReloadTime = 0;
		lockingTargetSound[] = {"\x\ace\addons\c_vehicle\data\sound\aim9locktone",0.000316228,1.5};
		lockedTargetSound[] = {"\x\ace\addons\c_vehicle\data\sound\aim9locktone",0.000316228,2.5};
	};
	class Igla_twice: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_9K38_IGLA";
	};
	class 9M311Laucher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_9M311LAUCHER";
		midRange = 4800;
		maxRange = 10000;
		magazineReloadTime = 10;
		weaponLockSystem = 8;
		weaponLockDelay = 4;
		magazines[] = {"8Rnd_9M311"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
	};
	class ACE_9K31Launcher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_ACE_9K31LAUNCHER";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		minRange = 75;
		minRangeProbab = 0.1;
		midRange = 1500;
		midRangeProbab = 0.7;
		maxRange = 6000;
		maxRangeProbab = 0.2;
		maxLeadSpeed = 75;
		autoReload = 0;
		reloadTime = 5;
		canLock = 2;
		initspeed = 20;
		magazineReloadTime = 90;
		sound[] = {"\Ca\sounds\Weapons\rockets\javelin1_A",10,1,1400};
		magazines[] = {"ACE_9M31","ACE_9M31_4","ACE_9M31_2"};
		aiRateOfFire = 10;
		aiRateOfFireDistance = 750;
	};
	class AT2Launcher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_AT2LAUNCHER";
		minRange = 400;
		maxRange = 4000;
		reloadTime = 7.5;
		canlock = 0;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
	};
	class AT6Launcher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_AT6LAUNCHER";
		minRange = 400;
		maxRange = 6000;
		reloadTime = 10;
		canlock = 0;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
	};
	class AT9Launcher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_AT9LAUNCHER";
		minRange = 400;
		maxRange = 8000;
		reloadTime = 10;
		magazines[] = {"4Rnd_AT9_Mi24P","ACE_4Rnd_AT9_Mi24V"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
	};
	class ACE_AT9Launcher_Mi28: AT9Launcher
	{
		magazines[] = {"ACE_16Rnd_AT9_Mi28","ACE_4Rnd_AT9_Mi24V"};
	};
	class VikhrLauncher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_VIKHRLAUNCHER";
		midRange = 4000;
		maxRange = 11500;
		reloadTime = 6;
		magazines[] = {"12Rnd_Vikhr_KA50"};
		cursor = "Laser";
	};
	class AT5Launcher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_AT5LAUNCHER";
		magazineReloadTime = 125;
		autoReload = 0;
		magazines[] = {"5Rnd_AT5_BRDM2"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		canlock = 0;
	};
	class AT5LauncherSingle: AT5Launcher
	{
		magazineReloadTime = 0;
		reloadTime = 45;
		magazines[] = {"8Rnd_AT5_BMP2","ACE_AT5B","ACE_AT5"};
	};
	class ACE_AT5B_Launcher: AT5Launcher
	{
		displayName = "$STR_ACE_WDN_AT5B_LAUNCHER";
		magazines[] = {"ACE_AT5B","ACE_5Rnd_AT5B_BRDM2"};
	};
	class ACE_AT3_Launcher: AT5LauncherSingle
	{
		displayName = "$STR_ACE_WDN_AT3_LAUNCHER";
		maxRange = 3000;
		magazines[] = {"ACE_AT3C","ACE_AT3P"};
	};
	class Ch29Launcher: MissileLauncher
	{
		displayName = "$STR_ACE_WDN_CH29";
		minRange = 2000;
		minRangeProbab = 0.5;
		midRange = 5000;
		midRangeProbab = 0.9;
		maxRange = 10000;
		magazines[] = {"4Rnd_Ch29"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
	};
	class AT11LauncherSingle;
	class AT13LauncherSingle: AT11LauncherSingle
	{
		displayName = "$STR_ACE_WDN_AT13LAUNCHERSINGLE";
		autoReload = 0;
		maxRange = 2000;
		magazineReloadTime = 0;
		reloadTime = 17.5;
		magazines[] = {"6Rnd_AT13","ACE_AT13"};
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		canlock = 0;
	};
	class GSh301: CannonCore
	{
		aiDispersionCoefX = "2*2";
		aiDispersionCoefY = "2*2";
		displayName = "$STR_ACE_WDN_GSH301";
		magazines[] = {"180Rnd_30mm_GSh301","750Rnd_30mm_GSh301","ACE_150Rnd_30mm_GSh301","ACE_180Rnd_30mm_GSh301"};
		class manual: CannonCore
		{
			displayName = "$STR_ACE_WDN_GSH301";
			burst = 20;
			autoFire = 1;
			multiplier = 1;
			reloadTime = 0.04;
		};
		class close: manual
		{
			aiRateOfFire = 1;
		};
		class short: close
		{
			aiRateOfFire = 2;
		};
		class medium: close
		{
			aiRateOfFire = 3;
		};
		class far: close
		{
			aiRateOfFire = 4;
		};
	};
	class ACE_GSh301: GSh301
	{
		displayName = "$STR_ACE_WDN_GSH301";
		magazines[] = {"180Rnd_30mm_GSh301","750Rnd_30mm_GSh301","ACE_150Rnd_30mm_GSh301","ACE_180Rnd_30mm_GSh301"};
		cursorAim = "Air_Dot";
		weaponLockSystem = 8;
		class manual: manual
		{
			displayName = "$STR_ACE_WDN_GSH301";
			burst = 20;
			autoFire = 1;
			multiplier = 1;
			reloadTime = 0.04;
			aiRateOfFire = 0.04;
		};
	};
	class R73Launcher;
	class ACE_R27Launcher: R73Launcher
	{
		displayName = "$STR_ACE_WDN_R27LAUNCHER";
		minRange = 300;
		midRange = 5000;
		maxRange = 10000;
		minRangeProbab = 0.4;
		midRangeProbab = 0.8;
		maxRangeProbab = 0.05;
		reloadTime = 1;
		magazines[] = {"ACE_1Rnd_R27","ACE_2Rnd_R27","ACE_4Rnd_R27","ACE_6Rnd_R27"};
		aiRateOfFire = 5;
		aiRateOfFireDistance = 10000;
		cursor = "Laser";
		weaponLockSystem = 8;
	};
	class Ch29Launcher_Su34;
	class AirBombLauncher;
	class ACE_HellfireLauncher: HellfireLauncher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_Hellfire","ACE_2Rnd_Hellfire","ACE_4Rnd_Hellfire","ACE_8Rnd_Hellfire","ACE_12Rnd_Hellfire","ACE_16Rnd_Hellfire","8Rnd_Hellfire"};
	};
	class ACE_SidewinderLaucher: SidewinderLaucher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_Sidewinder","ACE_2Rnd_Sidewinder","4Rnd_Sidewinder_AV8B"};
	};
	class ACE_BombLauncher: BombLauncher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_GBU12","6Rnd_GBU12_AV8B","2Rnd_GBU12","4Rnd_GBU12"};
	};
	class ACE_Mk82BombLauncher: Mk82BombLauncher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_Mk82","ACE_2Rnd_Mk82","ACE_3Rnd_Mk82","ACE_4Rnd_Mk82","ACE_6Rnd_Mk82","ACE_8Rnd_Mk82","ACE_12Rnd_Mk82","ACE_14Rnd_Mk82","ACE_18Rnd_Mk82","3Rnd_Mk82","6Rnd_Mk82"};
	};
	class ACE_Mk82BombLauncher2: ACE_Mk82BombLauncher
	{
		magazines[] = {"ACE_2Rnd_Mk82"};
	};
	class ACE_MaverickLauncher: MaverickLauncher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_Maverick","2Rnd_Maverick_A10"};
	};
	class ACE_AT2Launcher: AT2Launcher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_AT2_Mi24D","4Rnd_AT2_Mi24D"};
	};
	class ACE_Kh29Launcher: Ch29Launcher_Su34
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_Kh29","ACE_2Rnd_Kh29","ACE_4Rnd_Kh29","ACE_6Rnd_Kh29","6Rnd_Ch29","4Rnd_Ch29"};
	};
	class ACE_Kh25Launcher: Ch29Launcher_Su34
	{
		displayName = "Kh-25M Launcher";
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_Kh25","ACE_2Rnd_Kh25","ACE_4Rnd_Kh25","ACE_6Rnd_Kh25"};
	};
	class ACE_R73Launcher: R73Launcher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_R73","ACE_2Rnd_R73","ACE_4Rnd_R73","ACE_6Rnd_R73","4Rnd_R73","2Rnd_R73"};
	};
	class ACE_AirBombLauncher: AirBombLauncher
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_FAB_250","ACE_2Rnd_FAB_250","ACE_4Rnd_FAB_250","ACE_6Rnd_FAB_250","ACE_8Rnd_FAB_250","ACE_10Rnd_FAB_250","ACE_12Rnd_FAB_250","ACE_14Rnd_FAB_250","ACE_16Rnd_FAB_250","ACE_18Rnd_FAB_250","ACE_20Rnd_FAB_250","ACE_22Rnd_FAB_250","ACE_24Rnd_FAB_250","ACE_26Rnd_FAB_250","ACE_28Rnd_FAB_250","ACE_30Rnd_FAB_250","ACE_31Rnd_FAB_250","4Rnd_FAB_250","2Rnd_FAB_250"};
	};
	class ACE_FAB500M62Launcher: AirBombLauncher
	{
		displayName = "FAB-500 M62 Launcher";
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_FAB500M62","ACE_2Rnd_FAB500M62","ACE_4Rnd_FAB500M62","ACE_6Rnd_FAB500M62","ACE_8Rnd_FAB500M62","ACE_10Rnd_FAB500M62","ACE_12Rnd_FAB500M62"};
	};
	class ACE_KAB500KRLauncher: BombLauncher
	{
		displayName = "KAB-500 KR Launcher";
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_KAB500KR","ACE_2Rnd_KAB500KR","ACE_4Rnd_KAB500KR","ACE_6Rnd_KAB500KR"};
	};
	class ACE_KAB500LLauncher: ACE_KAB500KRLauncher
	{
		displayName = "KAB-500 L Launcher";
		magazineReloadTime = 0;
		magazines[] = {"ACE_1Rnd_KAB500L","ACE_2Rnd_KAB500L","ACE_4Rnd_KAB500L","ACE_6Rnd_KAB500L"};
	};
};
class CfgNonAIVehicles
{
	class ProxyWeapon;
	class Proxyub16: ProxyWeapon
	{
		model = "\CA\air_e\ub16.p3d";
		simulation = "maverickweapon";
	};
	class Proxys8_launcher: ProxyWeapon
	{
		model = "\CA\air_e\s8_launcher.p3d";
		simulation = "maverickweapon";
	};
	class Proxyace_upk_23_250: ProxyWeapon
	{
		model = "\x\ace\addons\m_wep_upk23\ace_upk_23_250.p3d";
		simulation = "maverickweapon";
	};
	class Bird;
	class ACE_Shell_Tracer_Red: Bird
	{
		model = "\x\ace\addons\m_tracer\ace_shell_tracer_red.p3d";
		flySound[] = {"",0,1,1};
		singSound[] = {"",0,1,1};
		canBeShot = 0;
		timeToLive = 40;
		disappearAtContact = 1;
		armor = 0.1;
		autocenter = 0;
	};
	class ACE_40mm_Tracer_Red: ACE_Shell_Tracer_Red
	{
		model = "\x\ace\addons\m_tracer\ace_40mm_tracer_red.p3d";
	};
	class ACE_Shell_Tracer_Yellow: ACE_Shell_Tracer_Red
	{
		model = "\x\ace\addons\m_tracer\ace_shell_tracer_yellow.p3d";
	};
	class ACE_Shell_Tracer_Green: ACE_Shell_Tracer_Red
	{
		model = "\x\ace\addons\m_tracer\ace_shell_tracer_green.p3d";
	};
};
//};
