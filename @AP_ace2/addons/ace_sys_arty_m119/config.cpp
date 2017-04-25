////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:31 2013 : Created on Mon Oct 14 23:06:31 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_arty_m119 : config.bin{
class CfgPatches
{
	class ace_sys_arty_m119
	{
		units[] = {"ace_arty_m119"};
		weapons[] = {"ace_arty_m119"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","ace_sys_arty","ace_main","ace_sys_interaction"};
		version = "1.14.0.597";
		versionStr = "1.14.0.597";
		versionAr[] = {1,14,0,597};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_arty_m119
		{
			list[] = {"ace_sys_arty_m119"};
		};
	};
};
class CfgWeapons
{
	class CannonCore;
	class ace_arty_m119: CannonCore
	{
		magazineReloadTime = 2.5;
		dispersion = 0.0095;
		reloadTime = 2.5;
		magazines[] = {"ace_arty_105mm_m1_m782_pd_chg1","ace_arty_105mm_m1_m782_pd_chg2","ace_arty_105mm_m1_m782_pd_chg3","ace_arty_105mm_m1_m782_pd_chg4","ace_arty_105mm_m1_m782_pd_chg5","ace_arty_105mm_m1_m782_pd_chg6","ace_arty_105mm_m1_m782_pd_chg7","ace_arty_105mm_m1_m782_pd_chg8","ace_arty_105mm_m1_m782_time_chg1","ace_arty_105mm_m1_m782_time_chg2","ace_arty_105mm_m1_m782_time_chg3","ace_arty_105mm_m1_m782_time_chg4","ace_arty_105mm_m1_m782_time_chg5","ace_arty_105mm_m1_m782_time_chg6","ace_arty_105mm_m1_m782_time_chg7","ace_arty_105mm_m1_m782_time_chg8","ace_arty_105mm_m1_m782_prox_chg1","ace_arty_105mm_m1_m782_prox_chg2","ace_arty_105mm_m1_m782_prox_chg3","ace_arty_105mm_m1_m782_prox_chg4","ace_arty_105mm_m1_m782_prox_chg5","ace_arty_105mm_m1_m782_prox_chg6","ace_arty_105mm_m1_m782_prox_chg7","ace_arty_105mm_m1_m782_prox_chg8","ace_arty_105mm_m1_m782_delay_chg1","ace_arty_105mm_m1_m782_delay_chg2","ace_arty_105mm_m1_m782_delay_chg3","ace_arty_105mm_m1_m782_delay_chg4","ace_arty_105mm_m1_m782_delay_chg5","ace_arty_105mm_m1_m782_delay_chg6","ace_arty_105mm_m1_m782_delay_chg7","ace_arty_105mm_m1_m782_delay_chg8","ace_arty_105mm_m314a3_m782_time_chg1","ace_arty_105mm_m314a3_m782_time_chg2","ace_arty_105mm_m314a3_m782_time_chg3","ace_arty_105mm_m314a3_m782_time_chg4","ace_arty_105mm_m314a3_m782_time_chg5","ace_arty_105mm_m314a3_m782_time_chg6","ace_arty_105mm_m314a3_m782_time_chg7","ace_arty_105mm_m84a1_m782_time_chg1","ace_arty_105mm_m84a1_m782_time_chg2","ace_arty_105mm_m84a1_m782_time_chg3","ace_arty_105mm_m84a1_m782_time_chg4","ace_arty_105mm_m84a1_m782_time_chg5","ace_arty_105mm_m84a1_m782_time_chg6","ace_arty_105mm_m84a1_m782_time_chg7","ace_arty_105mm_m916_m782_time_chg1","ace_arty_105mm_m916_m782_time_chg2","ace_arty_105mm_m916_m782_time_chg3","ace_arty_105mm_m916_m782_time_chg4","ace_arty_105mm_m916_m782_time_chg5","ace_arty_105mm_m916_m782_time_chg6","ace_arty_105mm_m916_m782_time_chg7","ace_arty_105mm_m916_m782_time_chg8","ace_arty_105mm_m60a2_m782_pd_chg1","ace_arty_105mm_m60a2_m782_pd_chg2","ace_arty_105mm_m60a2_m782_pd_chg3","ace_arty_105mm_m60a2_m782_pd_chg4","ace_arty_105mm_m60a2_m782_pd_chg5","ace_arty_105mm_m60a2_m782_pd_chg6","ace_arty_105mm_m60a2_m782_pd_chg7"};
		scope = 1;
		displayName = "ACE M119";
		nameSound = "cannon";
		cursor = "Cannon";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursorSize = 1;
		sound[] = {"\ca\Sounds\weapons\cannon\gun120",316.22775,1,1500};
		reloadSound[] = {"\x\ace\addons\sys_arty_m119\sounds\M119breachAction",2.0,1,20};
		autoReload = 0;
		backgroundReload = 0;
		ballisticsComputer = 0;
		canLock = 0;
	};
};
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets;
	};
	class StaticCannon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class ace_arty_howtizer: StaticCannon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class ace_arty_m119_base: ace_arty_howtizer
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
	class ace_arty_m119: ace_arty_m119_base
	{
		ACE_ARTY_ISARTY = 1;
		ACE_ARTY_RECOIL = "\x\ace\addons\sys_arty_m119\fnc_recoil.sqf";
		scope = 2;
		side = 1;
		faction = "BIS_US";
		crew = "US_Soldier_EP1";
		displayName = "ACE M119";
		model = "\x\ace\addons\sys_arty_m119\ace_arty_m119.p3d";
		artilleryScanner = 0;
		ARTY_IsArtyVehicle = 0;
		vehicleClass = "ACE_Howitzers";
		sound[] = {"Ca\sounds\Weapons\cannon\gun120",100.0,1,1800};
		picture = "\ca\Weapons\data\ico\M119_CA.paa";
		mapSize = 7;
		icon = "\Ca\weapons\Data\map_ico\icomap_m119_CA.paa";
		cargoAction[] = {};
		typicalCargo[] = {"US_Soldier_EP1"};
		transportSoldier = 0;
		memoryPointsGetInCargo = "pos_cargo";
		memoryPointsGetInCargoDir = "pos_cargo_dir";
		gunnerHasFlares = 1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ace_arty_m119"};
				magazines[] = {};
				gunnerAction = "M119_Gunner";
				gunnerOpticsModel = "\x\ace\addons\sys_arty_m119\ace_arty_m119_scope";
				gunnerOpticsEffect[] = {"OpticsBlur2"};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";
				gunBeg = "gun_muzzle";
				gunEnd = "gun_chamber";
				class ViewOptics: ViewOptics
				{
					initFov = 0.0787019;
					minFov = 0.0787019;
					maxFov = 0.0787019;
				};
			};
		};
		class Library
		{
			libTextDesc = "$STR_LIB_M119";
		};
		class AnimationSources
		{
			class recoil_source
			{
				source = "user";
				weapon = "ace_arty_m119";
				animPeriod = 0.125;
				minValue = 0;
				maxValue = -1.07;
			};
			class MainTurret
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
				minValue = -6400;
				maxValue = 6400;
			};
			class MainGun
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 300;
				minValue = -100;
				maxValue = 1244;
			};
			class M137OpticElevate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
				minValue = -300;
				maxValue = 300;
			};
			class ElevationMountRotate
			{
				source = "MainGun";
				animPeriod = 0.01;
				initPhase = 300;
				minValue = -100;
				maxValue = 1244;
			};
			class M187MountElevate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 300;
				minValue = -100;
				maxValue = 1244;
			};
			class M137OpticRevolve
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
				minValue = -6400;
				maxValue = 6400;
			};
			class MainTurretTraverse
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
				minValue = -100;
				maxValue = 100;
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_arty_m119
	{
		init = "call ('\x\ace\addons\sys_arty_m119\XEH_pre_init.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class ace_arty_m119
	{
		init = "call ('\x\ace\addons\sys_arty_m119\XEH_init.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_GetIn_Eventhandlers
{
	class ace_arty_m119
	{
		class ace_sys_arty_m119
		{
			clientGetin = "_this call ace_sys_arty_m119_fnc_XEH_getin";
		};
	};
};
class Extended_GetOut_Eventhandlers
{
	class ace_arty_m119
	{
		class ace_sys_arty_m119
		{
			clientGetOut = "_this call ace_sys_arty_m119_fnc_XEH_getout";
		};
	};
};
class CfgAceArtyBatteryType
{
	class M119
	{
		name = "M119A1 105mm Howitzer";
		type = "cannon";
		caliber = 105;
		ammunition[] = {"ace_arty_105mm_m1","ace_arty_105mm_m916","ace_arty_105mm_m84a1","ace_arty_105mm_m314a3"};
		weaponClass = "ace_arty_m119";
	};
};
class acex_arty_m137_RscText
{
	idc = -1;
	type = 0;
	style = "0x02";
	font = "Zeppelin32";
	colorText[] = {1,1,1,1};
	colorBackground[] = {0,0,0,0};
	sizeEx = 0.03;
	w = 0.2;
	h = 0.03;
};
class acex_arty_m137_RscButton
{
	type = 1;
	idc = -1;
	style = "0x02";
	x = 0.0;
	y = 0.0;
	w = 0.1;
	h = 0.03;
	sizeEx = 0.0325;
	offsetX = 0;
	offsetY = 0.002;
	offsetPressedX = 0;
	offsetPressedY = 0.002;
	borderSize = 0;
	colorText[] = {1,1,1,1};
	colorBackground[] = {0.5,0.5,0.5,0.75};
	colorFocused[] = {0.5,0.5,0.5,0};
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {1,1,1,0};
	colorBackgroundActive[] = {0.5,0.5,0.5,0};
	colorDisabled[] = {0.5,0.5,0.5,0};
	colorBackgroundDisabled[] = {0.5,0.5,0.5,0};
	font = "Zeppelin32";
	soundEnter[] = {"",0.2,1};
	soundPush[] = {"",0.2,1};
	soundClick[] = {"",0.2,1};
	soundEscape[] = {"",0.2,1};
	default = "false";
	text = "";
	action = "";
};
class acex_arty_m137_RscPicture: acex_arty_m137_RscButton
{
	type = 0;
	idc = -1;
	style = 48;
	text = "";
};
class acex_arty_m137_dialog
{
	idd = 137137;
	MovingEnable = 0;
	onLoad = "[] spawn ace_sys_arty_m119_fnc_m137_monitorSight";
	onUnload = "[] spawn ace_sys_arty_m119_fnc_m137_stopMonitorSight";
	controlsBackground[] = {};
	objects[] = {};
	onKeyDown = "_this call ace_sys_arty_m119_fnc_m137_keyDown";
	onKeyUp = "_this call ace_sys_arty_m119_fnc_m137_keyUp";
	class controls
	{
		class ace_sys_arty_m119_m137Background: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			h = "0.6 * safeZoneH";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "";
		};
		class ace_sys_arty_m119_m137Title: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "M137 Sight Unit";
		};
		class ace_sys_arty_m119_m137AzimuthLabel: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.035 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Azimuth:";
		};
		class ace_sys_arty_m119_m137Azimuth: acex_arty_m137_RscText
		{
			idc = 137001;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.035 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "0000";
		};
		class ace_sys_arty_m119_m137DeflectionLabel: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.07 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Deflection:";
		};
		class ace_sys_arty_m119_m137Deflection: acex_arty_m137_RscText
		{
			idc = 137002;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.07 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "3200";
		};
		class ace_sys_arty_m119_m187title: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.105 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "M187 Sight Mount";
		};
		class ace_sys_arty_m119_m137ElevationLabel: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.140 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Elevation:";
		};
		class ace_sys_arty_m119_m137Elevation: acex_arty_m137_RscText
		{
			idc = 137003;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.140 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "0300";
		};
		class ace_sys_arty_m119_m137ElevationBubbleLabel: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.175 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Level:";
		};
		class ace_sys_arty_m119_m137ElevationBubble: acex_arty_m137_RscText
		{
			idc = 137004;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.175 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "|---|+|---|";
		};
		class ace_sys_arty_m119_m137AzimuthLeftButton: acex_arty_m137_RscButton
		{
			idc = 137004;
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Def. -";
			action = "[-1] call ace_sys_arty_m119_fnc_m137_adjustAzimuth";
		};
		class ace_sys_arty_m119_m137AzimuthRightButton: acex_arty_m137_RscButton
		{
			idc = 137005;
			x = "(0.0625 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Def. +";
			action = "[1] call ace_sys_arty_m119_fnc_m137_adjustAzimuth";
		};
		class ace_sys_arty_m119_m137ElevationUpButton: acex_arty_m137_RscButton
		{
			idc = 137006;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "El +";
			action = "[1] call ace_sys_arty_m119_fnc_m137_adjustElevation";
		};
		class ace_sys_arty_m119_m137ElevationDownButton: acex_arty_m137_RscButton
		{
			idc = 137007;
			x = "(0.1875 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "El -";
			action = "[-1] call ace_sys_arty_m119_fnc_m137_adjustElevation";
		};
		class ace_sys_arty_m119_m137OpticDownButton: acex_arty_m137_RscButton
		{
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Op. -";
			action = "[-1] call ace_sys_arty_m119_fnc_m137_adjustOpticElevation";
		};
		class ace_sys_arty_m119_m137OpticUpButton: acex_arty_m137_RscButton
		{
			x = "(0.0625 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Op. +";
			action = "[1] call ace_sys_arty_m119_fnc_m137_adjustOpticElevation";
		};
		class ace_sys_arty_m119_m137ResetLeftButton: acex_arty_m137_RscButton
		{
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Re +";
			action = "[1] call ace_sys_arty_m119_fnc_m137_adjustReset";
		};
		class ace_sys_arty_m119_m137ResetRightButton: acex_arty_m137_RscButton
		{
			x = "(0.1875 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Re -";
			action = "[-1] call ace_sys_arty_m119_fnc_m137_adjustReset";
		};
		class ace_sys_arty_m119_m137TraverseIndicatorLabel: acex_arty_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.280 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Traverse:";
		};
		class ace_sys_arty_m119_m137TraverseIndicator: acex_arty_m137_RscText
		{
			idc = 137008;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.280 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "|-----|-----|";
		};
		class ace_sys_arty_m119_m137ChangeViewButton: acex_arty_m137_RscButton
		{
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.315 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			text = "Change View";
			action = "[] call ace_sys_arty_m119_fnc_m137_changeView";
		};
		class ace_sys_arty_m119_m137LevelGun: acex_arty_m137_RscButton
		{
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.350 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			text = "Level Gun";
			action = "[] call ace_sys_arty_m119_fnc_levelGun";
		};
	};
};
//};
