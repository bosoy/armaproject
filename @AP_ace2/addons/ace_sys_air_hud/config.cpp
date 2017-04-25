////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:38 2013 : Created on Sat Jun 08 13:05:38 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_air_hud : config.bin{
class CfgPatches
{
	class ace_sys_air_hud
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_vehicle","ace_sys_missileguidance","ace_sys_mfd","CAA10","CAAir"};
		version = "1.14.0.593";
		author[] = {"Nou"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_air_hud
	{
		init = "call ('\x\ace\addons\sys_air_hud\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_air_hud
	{
		clientInit = "call ('\x\ace\addons\sys_air_hud\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Air
	{
		class ace_sys_air_hud
		{
			clientFiredBis = "_this call ace_sys_air_hud_fnc_fired";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class Air
	{
		class ace_sys_air_hud
		{
			clientGetIn = "_this call ace_sys_air_hud_fnc_getIn";
		};
	};
};
class RscMapControl;
class cba_ui_canvas
{
	idc = -1;
	type = 100;
	style = 48;
	x = 0;
	y = 0;
	w = 1;
	h = 1;
	colorBackground[] = {1.0,1.0,1.0,0};
	colorText[] = {0.0,0.0,0.0,0};
	colorSea[] = {0.56,0.8,0.98,0};
	colorForest[] = {0.6,0.8,0.2,0};
	colorRocks[] = {0.5,0.5,0.5,0};
	colorCountlines[] = {0.65,0.45,0.27,0};
	colorMainCountlines[] = {0.65,0.45,0.27,0};
	colorCountlinesWater[] = {0.0,0.53,1.0,0};
	colorMainCountlinesWater[] = {0.0,0.53,1.0,0};
	colorForestBorder[] = {0.4,0.8,0.0,0};
	colorRocksBorder[] = {0.5,0.5,0.5,0};
	colorPowerLines[] = {0.0,0.0,0.0,0};
	colorNames[] = {0.0,0.0,0.0,0};
	colorInactive[] = {1.0,1.0,1.0,0};
	colorLevels[] = {0.0,0.0,0.0,0};
	colorRailWay[] = {0.0,0.0,0.0,0};
	colorOutside[] = {0.56,0.8,0.98,0};
	font = "TahomaB";
	sizeEx = 0.0;
	stickX[] = {0.0,{"Gamma",0.0,0.0}};
	stickY[] = {0.0,{"Gamma",0.0,0.0}};
	ptsPerSquareSea = 0;
	ptsPerSquareTxt = 0;
	ptsPerSquareCLn = 0;
	ptsPerSquareExp = 0;
	ptsPerSquareCost = 0;
	ptsPerSquareFor = "0f";
	ptsPerSquareForEdge = "0f";
	ptsPerSquareRoad = 0;
	ptsPerSquareObj = 0;
	fontLabel = "Zeppelin32";
	sizeExLabel = 0.0;
	fontGrid = "Zeppelin32";
	sizeExGrid = 0.0;
	fontUnits = "Zeppelin32";
	sizeExUnits = 0.0;
	fontNames = "Zeppelin32";
	sizeExNames = 0.0;
	fontInfo = "Zeppelin32";
	sizeExInfo = 0.0;
	fontLevel = "Zeppelin32";
	sizeExLevel = 0.0;
	scaleMax = 1000;
	scaleMin = 1e-006;
	text = "";
	onDraw = "_this call ace_sys_air_hud_fnc_drawHud;";
	maxSatelliteAlpha = 0;
	alphaFadeStartScale = 1.0;
	alphaFadeEndScale = 1.1;
	showCountourInterval = 0;
	scaleDefault = 2;
	class Task
	{
		icon = "\ca\ui\data\ui_taskstate_current_CA.paa";
		color[] = {1,0.537,0,0};
		size = 27;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
		iconCreated = "";
		iconCanceled = "";
		iconDone = "";
		iconFailed = "";
		colorCreated[] = {1,1,1,0};
		colorCanceled[] = {1,1,1,0};
		colorDone[] = {1,1,1,0};
		colorFailed[] = {1,1,1,0};
	};
	class CustomMark
	{
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		color[] = {0.6471,0.6706,0.6235,0};
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Legend
	{
		x = "SafeZoneX";
		y = "SafeZoneY";
		w = 0.34;
		h = 0.152;
		font = "Zeppelin32";
		sizeEx = 0.03921;
		colorBackground[] = {0.906,0.901,0.88,0};
		color[] = {0,0,0,0};
	};
	class Bunker
	{
		icon = "\ca\ui\data\map_bunker_ca.paa";
		color[] = {0.55,0.64,0.43,0};
		size = 14;
		importance = "1.5 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Bush
	{
		icon = "\ca\ui\data\map_bush_ca.paa";
		color[] = {0.45,0.64,0.33,0.0};
		size = 14;
		importance = "0.2 * 14 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class BusStop
	{
		icon = "\ca\ui\data\map_busstop_ca.paa";
		color[] = {0.15,0.26,0.87,0};
		size = 12;
		importance = "1 * 10 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Command
	{
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		color[] = {0,0.9,0,0};
		size = 18;
		importance = 1;
		coefMin = 1;
		coefMax = 1;
	};
	class Cross
	{
		icon = "\ca\ui\data\map_cross_ca.paa";
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "0.7 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fortress
	{
		icon = "\ca\ui\data\map_bunker_ca.paa";
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Fuelstation
	{
		icon = "\ca\ui\data\map_fuelstation_ca.paa";
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.75;
		coefMax = 4;
	};
	class Fountain
	{
		icon = "\ca\ui\data\map_fountain_ca.paa";
		color[] = {0.2,0.45,0.7,0};
		size = 11;
		importance = "1 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Hospital
	{
		icon = "\ca\ui\data\map_hospital_ca.paa";
		color[] = {0.78,0,0.05,0};
		size = 16;
		importance = "2 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Chapel
	{
		icon = "\ca\ui\data\map_chapel_ca.paa";
		color[] = {0.55,0.64,0.43,0};
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Church
	{
		icon = "\ca\ui\data\map_church_ca.paa";
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Lighthouse
	{
		icon = "\ca\ui\data\map_lighthouse_ca.paa";
		size = 14;
		color[] = {0,0.9,0,0};
		importance = "3 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Quay
	{
		icon = "\ca\ui\data\map_quay_ca.paa";
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Rock
	{
		icon = "\ca\ui\data\map_rock_ca.paa";
		color[] = {0.1,0.1,0.1,0.0};
		size = 12;
		importance = "0.5 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Ruin
	{
		icon = "\ca\ui\data\map_ruin_ca.paa";
		size = 16;
		color[] = {0,0.9,0,0};
		importance = "1.2 * 16 * 0.05";
		coefMin = 1;
		coefMax = 4;
	};
	class SmallTree
	{
		icon = "\ca\ui\data\map_smalltree_ca.paa";
		color[] = {0.45,0.64,0.33,0.0};
		size = 12;
		importance = "0.6 * 12 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Stack
	{
		icon = "\ca\ui\data\map_stack_ca.paa";
		size = 20;
		color[] = {0,0.9,0,0};
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Tree
	{
		icon = "\ca\ui\data\map_tree_ca.paa";
		color[] = {0.45,0.64,0.33,0.0};
		size = 12;
		importance = "0.9 * 16 * 0.05";
		coefMin = 0.25;
		coefMax = 4;
	};
	class Tourism
	{
		icon = "\ca\ui\data\map_tourism_ca.paa";
		color[] = {0.78,0,0.05,0};
		size = 16;
		importance = "1 * 16 * 0.05";
		coefMin = 0.7;
		coefMax = 4;
	};
	class Transmitter
	{
		icon = "\ca\ui\data\map_transmitter_ca.paa";
		color[] = {0,0.9,0,0};
		size = 20;
		importance = "2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class ViewTower
	{
		icon = "\ca\ui\data\map_viewtower_ca.paa";
		color[] = {0,0.9,0,0};
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class Watertower
	{
		icon = "\ca\ui\data\map_watertower_ca.paa";
		color[] = {0.2,0.45,0.7,0};
		size = 20;
		importance = "1.2 * 16 * 0.05";
		coefMin = 0.9;
		coefMax = 4;
	};
	class Waypoint
	{
		icon = "\ca\ui\data\map_waypoint_ca.paa";
		color[] = {0,0.35,0.7,0};
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class WaypointCompleted
	{
		icon = "\ca\ui\data\map_waypoint_completed_ca.paa";
		color[] = {0,0.35,0.7,0};
		size = 16;
		importance = "2.5 * 16 * 0.05";
		coefMin = 0.5;
		coefMax = 4;
	};
	class ActiveMarker
	{
		color[] = {0.3,0.1,0.9,0};
		size = 50;
	};
};
class rscTitles
{
	class ace_ccip_hud_dialog
	{
		idd = 83905;
		movingEnable = 0;
		enableSimulation = 0;
		enableDisplay = 0;
		name = "ace_ccip_hud_dialog";
		onload = "_this call ace_sys_air_hud_fnc_hudOpen";
		duration = 2147483647;
		class controlsBackground{};
		class objects{};
		class controls
		{
			class canvas: cba_ui_canvas
			{
				idc = 83909;
				x = "safeZoneX";
				y = "safeZoneY";
				w = 0;
				h = 0;
			};
		};
	};
};
class CfgMagazines{};
class CfgVehicles
{
	class Plane;
	class AV8B2: Plane
	{
		ACE_HUD_ENABLED = 1;
		class MFD
		{
			class HUD
			{
				class Draw
				{
					class PlaneHeading
					{
						points[] = {};
					};
					class RadarTargets
					{
						points[] = {};
					};
					class Bomb
					{
						class Circle
						{
							points[] = {};
						};
					};
				};
			};
		};
	};
	class A10: Plane
	{
		ACE_HUD_ENABLED = 1;
		ACE_HUD_SPOTTRACK = 1;
		class MFD
		{
			class AirplaneHUD
			{
				class Draw
				{
					class PlaneHeading
					{
						points[] = {};
					};
					class RadarTargets
					{
						points[] = {};
					};
					class Bomb
					{
						class Circle
						{
							points[] = {};
						};
					};
					class MGun
					{
						class Circle
						{
							points[] = {};
						};
					};
				};
			};
		};
	};
};
class CfgAmmo
{
	class Bo_FAB_250;
	class Bo_Mk82: Bo_FAB_250
	{
		ACE_ccip_proxy = "Bo_Mk82_CCIP";
	};
	class Bo_Mk82_CCIP: Bo_Mk82
	{
		simulation = "shotShell";
		timeToLive = 500;
		airFriction = 6.58e-006;
	};
	class LaserBombCore;
	class Bo_GBU12_LGB: LaserBombCore
	{
		ACE_CCIP_GRAVITY = 5.68665;
		ACE_CCIP_AIRFRIC = -0.000203;
	};
};
class CfgWeapons
{
	class RocketPods;
	class ACE_CCRP_Launcher: RocketPods
	{
		displayName = "CCRP Consent Release";
		nameSound = "";
		magazines[] = {};
		aiRateOfFire = 5.0;
		aiRateOfFireDistance = 500;
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		cursorSize = 1;
	};
	class Mk82BombLauncher: RocketPods
	{
		reloadTime = 0.0;
		ACE_HUD_WeaponType = "bomb";
	};
	class GAU8;
	class ACE_GAU8: GAU8
	{
		ACE_HUD_WeaponType = "gun";
	};
	class BombLauncher: RocketPods
	{
		ACE_HUD_WeaponType = "lgb";
	};
};
class CfgSounds
{
	class ace_bombrelease
	{
		name = "ace_bombrelease";
		sound[] = {"\x\ace\addons\sys_air_hud\sounds\bombdrop.ogg",3,1};
		titles[] = {};
	};
};
//};
