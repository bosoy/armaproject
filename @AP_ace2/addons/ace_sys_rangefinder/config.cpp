////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:07:06 2013 : Created on Sat Jun 08 13:07:06 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_rangefinder : config.bin{
class CfgPatches
{
	class ace_sys_rangefinder
	{
		units[] = {"ACE_SoflamTripod"};
		weapons[] = {"ACE_Rangefinder_OD","ACE_Laserdesignator_D","ACE_YardAge450"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_c_vehicle","ace_m_wep_magazines","ace_sys_recognize","ace_sys_interaction"};
		version = "1.14.0.593";
		author[] = {"Spooner","tcp"};
		class ACE_Options
		{
			group = "ITEMS";
			title = "$STR_DSS_ACE_RANGEFINDER_OD";
			class toggle_power
			{
				title = "Toggle power";
			};
			class cycle_mils
			{
				title = "Cycle display";
			};
			class preload_battery
			{
				title = "Load battery";
			};
			class LaserCode_Up
			{
				title = "Lasercode (+)";
			};
			class LaserCode_Down
			{
				title = "Lasercode (-)";
			};
		};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_rangefinder
		{
			list[] = {"ace_sys_rangefinder"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_rangefinder
	{
		clientInit = "call ('\x\ace\addons\sys_rangefinder\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
		init = "call ('\x\ace\addons\sys_rangefinder\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class ace_sys_rangefinder
		{
			init = "if (local (_this select 0)) then {_this call ace_sys_rangefinder_fnc_giveBattery}";
		};
	};
};
class CfgAmmo
{
	class Laserbeam;
	class ACE_Laserbeam_Fake: Laserbeam
	{
		irLock = "false";
		laserLock = "false";
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class Laserbatteries: CA_Magazine
	{
		model = "\x\ace\addons\m_wep_magazines\ba5590.p3d";
		displayName = "$STR_DN_ACE_LASERBATTERIES";
		descriptionShort = "$STR_DSS_LASERBATTERIES";
		picture = "\x\ace\addons\sys_rangefinder\data\equip\m_soflam_ca.paa";
		ace_weight = 1;
		ACE_Size = 883;
	};
	class ACE_Laserbatteries_D: Laserbatteries
	{
		ammo = "FakeAmmo";
	};
	class ACE_Battery_Rangefinder: LaserBatteries
	{
		displayName = "$STR_DN_ACE_BATTERY_RANGEFINDER";
		descriptionShort = "$STR_DSS_ACE_BATTERY_RANGEFINDER";
		picture = "\x\ace\addons\sys_rangefinder\data\equip\m_vector_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\2cr5.p3d";
		ammo = "ACE_Laserbeam_Fake";
		ace_weight = 0.045;
		ACE_Size = 26;
	};
	class ACE_Battery_Rangefinder_D: ACE_Battery_Rangefinder
	{
		ammo = "FakeAmmo";
	};
	class ACE_BB2847: Laserbatteries
	{
		displayName = "$STR_DN_ACE_BB2847";
		ace_weight = 0.4;
		ACE_Size = 235;
	};
};
class cfgWeapons
{
	class ACE_Item;
	class ACE_SOFLAMTripod: ACE_Item
	{
		scope = 2;
		displayName = "$STR_DN_ACE_SPOTTINGSCOPE";
		picture = "\Ca\weapons\Data\Equip\W_SOFLAM_CA.paa";
		descriptionShort = "";
		model = "\x\ace\addons\sys_rangefinder\soflam_tripod.p3d";
		ACE_Weight = 0.867;
		ACE_Size = 3000;
	};
	class Binocular;
	class Laserdesignator: Binocular
	{
		opticsZoomMin = 0.01;
		opticsZoomMax = 0.1;
		opticsZoomInit = 0.03125;
		forceOptics = 0;
		displayName = "$STR_DN_ACE_LASERDESIGNATOR";
		descriptionShort = "$STR_DSS_LASERDESIGNATOR";
		ace_weight = 6.6;
		ACE_Size = 6557;
		weaponInfoType = "RscWeaponEmpty";
		visionMode[] = {"Normal","NVG"};
	};
	class ACE_Laserdesignator_D: Laserdesignator
	{
		displayName = "$STR_DN_ACE_LASERDESIGNATOR_D";
		descriptionShort = "$STR_DSS_ACE_LASERDESIGNATOR_D";
		magazines[] = {};
		class Armory
		{
			disabled = 1;
		};
		visionMode[] = {"Normal"};
	};
	class ACE_Rangefinder_OD: Laserdesignator
	{
		forceOptics = 0;
		displayName = "$STR_DN_ACE_RANGEFINDER_OD";
		model = "\x\ace\addons\sys_rangefinder\ace_vector_21.p3d";
		magazines[] = {"ACE_Battery_Rangefinder"};
		descriptionShort = "$STR_DSS_ACE_RANGEFINDER_OD";
		picture = "\x\ace\addons\sys_rangefinder\data\equip\w_vector21OD_ca.paa";
		modelOptics = "\x\ace\addons\sys_rangefinder\vector_optic.p3d";
		ace_weight = 1.786;
		ACE_Size = 2992;
		weaponInfoType = "RscWeaponEmpty";
		class OpticsModes
		{
			class Day
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 1;
				memoryPointCamera = "eye";
				cameraDir = "";
				opticsZoomMin = "0.33333/7";
				opticsZoomMax = "0.33333/7";
				opticsZoomInit = "0.33333/7";
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discretefov[] = {"0.33333/7"};
				discreteInitIndex = 0;
				visionMode[] = {"Normal"};
			};
			class Night: Day
			{
				opticsID = 2;
				opticsPPEffects[] = {};
				opticsZoomMin = "0.33333/4.5";
				opticsZoomMax = "0.33333/4.5";
				opticsZoomInit = "0.33333/4.5";
				discretefov[] = {"0.33333/4.5"};
				visionMode[] = {"NVG"};
			};
		};
	};
	class ACE_YardAge450: ACE_Rangefinder_OD
	{
		displayName = "YardAge 450";
		model = "\x\ace\addons\sys_rangefinder\ace_yardage_pro_450.p3d";
		picture = "\x\ace\addons\sys_rangefinder\data\equip\w_bushnell_ca.paa";
		modelOptics = "\x\ace\addons\sys_rangefinder\bushnell_optic.p3d";
		ACE_Size = "0.048*0.107*0.091";
		ace_weight = 0.21;
		class OpticsModes
		{
			class Day
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 1;
				memoryPointCamera = "eye";
				cameraDir = "";
				opticsZoomMin = "0.33333/4";
				opticsZoomMax = "0.33333/4";
				opticsZoomInit = "0.33333/4";
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discretefov[] = {"0.33333/4"};
				discreteInitIndex = 0;
				visionMode[] = {"Normal"};
			};
		};
	};
	class ACE_MX2A: Binocular
	{
		forceOptics = 0;
		displayName = "$STR_DN_ACE_MX2A";
		descriptionShort = "$STR_DSS_ACE_MX2A";
		model = "\x\ace\addons\sys_rangefinder\ace_mx2a.p3d";
		picture = "\x\ace\addons\sys_rangefinder\data\equip\w_mx2a_ca.paa";
		modelOptics = "\Ca\weapons_E\LWTS_optic.p3d";
		showSwitchAction = 1;
		simulation = "weapon";
		class OpticsModes
		{
			class MX2A
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				memoryPointCamera = "eye";
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMax = 0.1;
				distanceZoomMax = 120;
				opticsZoomMin = 0.05;
				distanceZoomMin = 400;
				opticsZoomInit = 0.1;
				cameraDir = "";
				visionMode[] = {"Ti"};
				thermalMode[] = {0,1};
				discretefov[] = {"0.33333/1","0.33333/2"};
				discreteInitIndex = 0;
				discreteDistance[] = {120,400};
				discreteDistanceInitIndex = 1;
			};
		};
		ace_weight = 1.2;
	};
	class Binocular_Vector: Binocular
	{
		simulation = "weapon";
		Laser = 1;
		showSwitchAction = 1;
		forceOptics = 0;
		displayName = "$STR_DN_ACE_RANGEFINDER_OD";
		descriptionShort = "$STR_DSS_ACE_RANGEFINDER_OD";
		magazines[] = {"ACE_Battery_Rangefinder"};
		modelOptics = "\x\ace\addons\sys_rangefinder\vector_optic.p3d";
		ace_weight = 1.786;
		ACE_Size = 2992;
		weaponInfoType = "RscWeaponEmpty";
		class OpticsModes
		{
			class Day
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 1;
				memoryPointCamera = "eye";
				cameraDir = "";
				opticsZoomMin = "0.33333/7";
				opticsZoomMax = "0.33333/7";
				opticsZoomInit = "0.33333/7";
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discretefov[] = {"0.33333/7"};
				discreteInitIndex = 0;
				visionMode[] = {"Normal"};
			};
			class Night: Day
			{
				opticsID = 2;
				opticsPPEffects[] = {};
				opticsZoomMin = "0.33333/4.5";
				opticsZoomMax = "0.33333/4.5";
				opticsZoomInit = "0.33333/4.5";
				discretefov[] = {"0.33333/4.5"};
				visionMode[] = {"NVG"};
			};
		};
	};
	class LRTV_ACR: LaserDesignator
	{
		displayName = "$STR_DN_ACE_LRTV";
		discretefov[] = {"0.33333/3","0.33333/9"};
		discreteInitIndex = 0;
		visionMode[] = {"Normal","Ti"};
		ace_weight = 3.2;
		magazines[] = {"ACE_BB2847"};
	};
};
class CfgVehicles
{
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets;
	};
	class StaticATWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class ACE_SoflamTripod: StaticATWeapon
	{
		scope = 1;
		side = 1;
		faction = "USMC";
		crew = "USMC_Soldier";
		typicalCargo[] = {"USMC_Soldier"};
		displayName = "$STR_DN_ACE_SOFLAMTRIPOD";
		model = "\x\ace\addons\sys_rangefinder\soflam_tripod.p3d";
		class Library
		{
			libTextDesc = "";
		};
		picture = "\Ca\characters\data\Ico\i_null_CA.paa";
		Icon = "\Ca\characters\data\map_ico\i_wojak_CA.paa";
		mapSize = 0.5;
		transportSoldier = 0;
		getInAction = "Metis_Gunner";
		getOutAction = "PlayerProne";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minTurn = -45;
				maxTurn = 45;
				initTurn = 0;
				minElev = -10;
				maxElev = 40;
				initElev = 0;
				gun = "mainGun";
				gunBeg = "gun_begin";
				gunEnd = "gun_end";
				memoryPointGun = "gun_begin";
				memoryPointGunnerOptics = "gun_begin";
				weapons[] = {};
				magazines[] = {};
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOpticsmodel = "\x\ace\addons\m_wep_optics\NWD_GTLD_5x";
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 0;
				gunnerAction = "Metis_Gunner";
				gunnerGetInAction = "Metis_Gunner";
				gunnerGetOutAction = "PlayerProne";
				gunnerForceOptics = 0;
				ejectDeadGunner = 1;
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.7;
					maxFov = 0.7;
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					minFov = 0.01;
					maxFov = 0.1;
					initFov = 0.03125;
				};
			};
		};
		class UserActions
		{
			class ACE_PickupSOFLAMTripod
			{
				displayName = "$STR_ACE_PICKUPSOFLAMTRIPOD";
				position = "pos_gunner";
				radius = 4;
				condition = "(alive this) && {(count (crew this) == 0)}";
				statement = "[this,player] spawn ace_sys_rangefinder_fnc_pickUpSoflam";
				onlyForPlayer = 1;
			};
		};
		class ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "XXX";
			};
		};
	};
};
class RscTitles
{
	class SPON_rscText
	{
		type = 0;
		idc = -1;
		style = "0x00";
		font = "Zeppelin32";
		sizeEx = "0.027 * SafeZoneH";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
	};
	class RedDigit
	{
		type = 0;
		idc = -1;
		style = 48;
		x = 0;
		y = 0;
		w = "0.035 * SafeZoneH";
		h = "0.048 * SafeZoneH";
		text = "\x\ace\addons\sys_rangefinder\data\red_blank.paa";
		colorBackground[] = {0,0,0,0};
		colorText[] = {1,1,1,1};
		font = "Zeppelin32";
		sizeEx = 0;
		waitForLoad = 0;
	};
	class ACE_RF_display
	{
		idd = 720040;
		movingEnable = 0;
		duration = 100000;
		fadein = 0;
		fadeout = 0;
		name = "ACE_Vector_display";
		onLoad = "with uiNameSpace do { ACE_RF_display = _this select 0; };";
		onUnload = "with uiNameSpace do { ACE_RF_display = displayNull; };";
		class Controls
		{
			class ACE_Vector_Azimuth: SPON_rscText
			{
				idc = 1;
				style = "0x02";
				x = "0.5 - (0.1689 * SafeZoneH)";
				y = "0.5 + (0.04 * SafeZoneH)";
				w = "0.13 * SafeZoneH";
				h = "0.07 * SafeZoneH";
				colorText[] = {1,0,0,0.7};
				text = "";
				sizeEx = "0.07 * SafeZoneH";
			};
			class ACE_Vector_Range: ACE_Vector_Azimuth
			{
				idc = 2;
				style = "0x02";
				x = "0.5 + (0.0442 * SafeZoneH)";
			};
		};
	};
	class EMP_RF_DISPLAY
	{
		idd = 751000;
		onLoad = "with uiNameSpace do { EMP_RF_DISPLAY = _this select 0; };";
		onUnload = "with uiNameSpace do { EMP_RF_DISPLAY = displayNull; };";
		movingEnable = 0;
		duration = 100000;
		fadein = 0;
		fadeout = 0;
		name = "Rangefinder Display";
		controls[] = {"CodeDigit1","CodeDigit2","CodeDigit3","CodeDigit4","RangeDigit1","RangeDigit2","RangeDigit3","RangeDigit4","RangeDigit5","AzimuthDigit1","AzimuthDigit2","AzimuthDigit3","AzimuthDigit4","ElevationDigit1","ElevationDigit2","ElevationDigit3","ElevationDigit4","XMT","MLT","HOT","BAT"};
		class RangeDigit1: RedDigit
		{
			idc = 751011;
			x = "0.5 - (0.078 * SafeZoneH)";
			y = "0.5 + (0.432 * SafeZoneH)";
		};
		class RangeDigit2: RedDigit
		{
			idc = 751012;
			x = "0.5 - (0.047 * SafeZoneH)";
			y = "0.5 + (0.432 * SafeZoneH)";
		};
		class RangeDigit3: RedDigit
		{
			idc = 751013;
			x = "0.5 - (0.016 * SafeZoneH)";
			y = "0.5 + (0.432 * SafeZoneH)";
		};
		class RangeDigit4: RedDigit
		{
			idc = 751014;
			x = "0.5 + (0.015 * SafeZoneH)";
			y = "0.5 + (0.432 * SafeZoneH)";
		};
		class RangeDigit5: RedDigit
		{
			idc = 751015;
			x = "0.5 + (0.0465 * SafeZoneH)";
			y = "0.5 + (0.432 * SafeZoneH)";
		};
		class AzimuthDigit1: RedDigit
		{
			idc = 751021;
			x = "0.5 - (0.133 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class AzimuthDigit2: RedDigit
		{
			idc = 751022;
			x = "0.5 - (0.102 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class AzimuthDigit3: RedDigit
		{
			idc = 751023;
			x = "0.5 - (0.071 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class AzimuthDigit4: RedDigit
		{
			idc = 751024;
			x = "0.5 - (0.04 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class ElevationDigit1: RedDigit
		{
			idc = 751031;
			x = "0.5 + (0.006 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class ElevationDigit2: RedDigit
		{
			idc = 751032;
			x = "0.5 + (0.037 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class ElevationDigit3: RedDigit
		{
			idc = 751033;
			x = "0.5 + (0.069 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class ElevationDigit4: RedDigit
		{
			idc = 751034;
			x = "0.5 + (0.099 * SafeZoneH)";
			y = "0.5 - (0.462 * SafeZoneH)";
		};
		class XMT: RedDigit
		{
			idc = 751041;
			x = "0.5 - (0.006816 * SafeZoneH)";
			y = "0.5 - (0.43 * SafeZoneH)";
			w = "0.015633 * SafeZoneH";
			h = "0.020847 * SafeZoneH";
			text = "\x\ace\addons\sys_rangefinder\data\red_light.paa";
		};
		class MLT: RedDigit
		{
			idc = 751042;
			x = "0.5 - (0.006816 * SafeZoneH)";
			y = "0.5 + (0.41 * SafeZoneH)";
			w = "0.015633 * SafeZoneH";
			h = "0.020847 * SafeZoneH";
			text = "\x\ace\addons\sys_rangefinder\data\red_light.paa";
		};
		class HOT: RedDigit
		{
			idc = 751043;
			x = "0.5 - (0.183 * SafeZoneH)";
			y = "0.5 + (0.41 * SafeZoneH)";
			w = "0.015633 * SafeZoneH";
			h = "0.020847 * SafeZoneH";
			text = "\x\ace\addons\sys_rangefinder\data\red_light.paa";
		};
		class BAT: RedDigit
		{
			idc = 751044;
			x = "0.5 + (0.167 * SafeZoneH)";
			y = "0.5 + (0.41 * SafeZoneH)";
			w = "0.015633 * SafeZoneH";
			h = "0.020847 * SafeZoneH";
			text = "\x\ace\addons\sys_rangefinder\data\red_light.paa";
		};
		class CodeDigit1: RedDigit
		{
			idc = 751045;
			x = "SafeZoneX + (0.109 * SafeZoneH)";
			y = "SafeZoneY + (0.432 * SafeZoneH)";
		};
		class CodeDigit2: RedDigit
		{
			idc = 751046;
			x = "SafeZoneX + (0.078 * SafeZoneH)";
			y = "SafeZoneY + (0.432 * SafeZoneH)";
		};
		class CodeDigit3: RedDigit
		{
			idc = 751047;
			x = "SafeZoneX + (0.047 * SafeZoneH)";
			y = "SafeZoneY + (0.432 * SafeZoneH)";
		};
		class CodeDigit4: RedDigit
		{
			idc = 751048;
			x = "SafeZoneX + (0.016 * SafeZoneH)";
			y = "SafeZoneY + (0.432 * SafeZoneH)";
		};
	};
};
class CfgInGameUI
{
	class Cursor
	{
		font = "ACE_EmptyFont";
	};
};
class CfgNonAIVehicles
{
	class ProxyDalekohled_Proxy;
	class ProxyVector21dt: ProxyDalekohled_Proxy
	{
		model = "\ca\weapons_E\vector\vector21dt";
	};
	class ProxyAce_vector_21: ProxyDalekohled_Proxy
	{
		model = "\x\ace\addons\sys_rangefinder\ace_vector_21.p3d";
	};
	class ProxyAce_yardage_pro_450: ProxyDalekohled_Proxy
	{
		model = "\x\ace\addons\sys_rangefinder\ace_yardage_pro_450.p3d";
	};
	class ProxyAce_mx2a: ProxyDalekohled_Proxy
	{
		model = "\x\ace\addons\sys_rangefinder\ace_mx2a.p3d";
	};
};
//};
