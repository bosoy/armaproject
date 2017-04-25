////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:06:53 2013 : Created on Sat Jun 08 13:06:53 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_minesweeper : config.bin{
class CfgPatches
{
	class ace_sys_minesweeper
	{
		units[] = {};
		weapons[] = {"ACE_Minedetector_US","ACE_VMH3","ACE_VMM3","ACE_SearchMirror","ACE_APOBS_A","ACE_APOBS_B","ACE_MineMarkers","ACE_MineMarkers_Light","ACE_MineMarkers_PathSign","ACE_MineMarkers_MineSign","ACE_MineMarkers_MineFlag"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAWeapons","ace_sys_interaction","ace_sys_ruck"};
		version = "1.14.0.593";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_minesweeper
		{
			list[] = {"ace_sys_minesweeper"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_minesweeper
	{
		init = "call ('\x\ace\addons\sys_minesweeper\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_minesweeper\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgVehicles
{
	class NonStrategic;
	class RoadBarrier_light;
	class ACE_MineMarker_Light: RoadBarrier_light
	{
		scope = 1;
		displayName = "";
		mapsize = 0;
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker_light_invisible.p3d";
		class MarkerLights
		{
			class Greenlight
			{
				name = "light";
				color[] = {0,0.5,0.1,0.0025};
				ambient[] = {"äaayyy",0.0025};
				brightness = 0.0015;
				size = 1e-005;
				blinking = "false";
			};
		};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_MineMarker: NonStrategic
	{
		displayName = "$STR_ACE_DN_MINESWEEPER_MINEMARKERS";
		scope = 1;
		animated = 1;
		destrType = "DestructTent";
		armor = 100;
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker.p3d";
		class AnimationSources
		{
			class flip_path
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class remove_path: flip_path
			{
				initPhase = 1;
			};
			class remove_sign: flip_path
			{
				initPhase = 1;
			};
			class remove_light: flip_path
			{
				initPhase = 1;
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class FlagCarrier;
	class ACE_Minemarker_flag: FlagCarrier
	{
		scope = 2;
		displayName = "Markierungsfolie";
		accuracy = 1000;
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker_flag.p3d";
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture '\x\ace\addons\sys_minesweeper\data\ace_markierungsfolie_co.paa'";
		};
	};
	class Thing;
	class ACE_APOBS_MK7MOD2: NonStrategic
	{
		scope = 1;
		displayName = "Mk 7 Mod 2 APOBS";
		model = "\x\ace\addons\sys_minesweeper\ace_apobs_mk7mod2.p3d";
		ACE_Weight = 50.9;
		class AnimationSources
		{
			class hide
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.1;
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_APOBS_MK7MOD2_Rocket: Thing
	{
		scope = 1;
		displayName = "Mk 126 Mod 0 rocket motor";
		model = "\x\ace\addons\sys_minesweeper\ace_apobs_rocket.p3d";
		ACE_Weight = 4.5;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_Rucksack_crate;
	class ACE_APOBS_A_crate: ACE_Rucksack_crate
	{
		displayName = "$STR_ACE_DN_MINESWEEPER_APOBS_FBA";
		model = "\x\ace\addons\sys_minesweeper\ace_apobs_a.p3d";
		ACE_Weight = 27.3;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_APOBS_B_crate: ACE_Rucksack_crate
	{
		displayName = "$STR_ACE_DN_MINESWEEPER_APOBS_RBA";
		model = "\x\ace\addons\sys_minesweeper\ace_apobs_b.p3d";
		ACE_Weight = 23.6;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_Tbox_GP_W;
	class ACE_MinSperMaSatz: ACE_Tbox_GP_W
	{
		displayName = "Minenfeldmarkierung Satz";
		model = "\x\ace\addons\m_veh_crates\ace_minenspermasatz.p3d";
		transportMaxMagazines = 0;
		transportMaxWeapons = 73;
		class TransportMagazines{};
		class TransportWeapons
		{
			class _xx_ACE_MineMarkers
			{
				weapon = "ACE_MineMarkers";
				count = 10;
			};
			class _xx_ACE_MineMarkers_MineSign
			{
				weapon = "ACE_MineMarkers_MineSign";
				count = 6;
			};
			class _xx_ACE_MineMarkers_PathSign
			{
				weapon = "ACE_MineMarkers_PathSign";
				count = 4;
			};
			class _xx_ACE_MineMarkers_Light
			{
				weapon = "ACE_MineMarkers_Light";
				count = 4;
			};
			class _xx_ACE_MineMarkers_MineFlag
			{
				weapon = "ACE_MineMarkers_MineFlag";
				count = 12;
			};
		};
		ACE_Weight = 2.5;
	};
};
class CfgNonAIVehicles
{
	class ProxyFlag;
	class Proxyace_minemarkerflag_proxy: ProxyFlag
	{
		model = "\x\ace\addons\sys_minesweeper\ace_minemarkerflag_proxy.p3d";
	};
};
class CfgAmmo{};
class Mode_SemiAuto;
class CfgWeapons
{
	class Rifle;
	class ACE_Minedetector_US: Rifle
	{
		scope = 2;
		displayName = "AN PSS-14";
		descriptionShort = "";
		model = "\x\ace\addons\sys_minesweeper\ace_anpss14.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_anpss14_ca.paa";
		magazines[] = {};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			displayName = "";
			begin1[] = {"",1.77828,1,1000};
			soundBegin[] = {"begin1",1};
			reloadTime = 0.075;
			recoil = "recoil_single_primary_3outof10";
			recoilProne = "recoil_single_primary_prone_3outof10";
			dispersion = 0.001;
			minRange = 2;
			minRangeProbab = 0.3;
			midRange = 250;
			midRangeProbab = 0.7;
			maxRange = 400;
			maxRangeProbab = 0.05;
		};
		class M203Muzzle{};
		ACE_Weight = 3.8;
		ACE_Size = 4000;
		class ACE
		{
			class ACE_MINESWEEPER
			{
				range = 1;
			};
		};
	};
	class ACE_VMH3: ACE_Minedetector_US
	{
		displayName = "VMH3";
		model = "\x\ace\addons\sys_minesweeper\ace_wallon_vmh3.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_vmh3_ca.paa";
		ACE_Weight = 2.5;
		class ACE: ACE
		{
			class ACE_MINESWEEPER: ACE_MINESWEEPER
			{
				range = 1.5;
			};
		};
	};
	class ACE_VMM3: ACE_VMH3
	{
		displayName = "VMM3";
		model = "\x\ace\addons\sys_minesweeper\ace_wallon_vmm3.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_vmm3_ca.paa";
		ACE_Weight = 1.7;
		class ACE: ACE
		{
			class ACE_MINESWEEPER: ACE_MINESWEEPER
			{
				range = 1.55;
			};
		};
	};
	class M9;
	class ACE_SearchMirror: M9
	{
		displayName = "$STR_ACE_DN_MINESWEEPER_MIRROR";
		drySound[] = {"",0.01,1,20};
		magazines[] = {};
		model = "\x\ace\addons\sys_minesweeper\ace_search_mirror.p3d";
		modelOptics = "\ca\weapons\2Dscope_Acog_4x32";
		cameraDir = "GL look";
		memoryPointCamera = "GL eye";
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1};
			position = "flash dir";
			direction = "flash";
			angle = 30;
			scale[] = {1,1,0.5};
			brightness = 0.1;
		};
	};
	class ACE_Rucksack_MOLLE_Green;
	class ACE_APOBS_A: ACE_Rucksack_MOLLE_Green
	{
		scope = 2;
		displayName = "$STR_ACE_DN_MINESWEEPER_APOBS_FBA";
		model = "\x\ace\addons\sys_minesweeper\ace_apobs_a.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_apobs_ca.paa";
		descriptionShort = "";
		ACE_Weight = 27.3;
		ACE_PackSize = 1;
		ACE_Size = 26401;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_APOBS_B: ACE_APOBS_A
	{
		displayName = "$STR_ACE_DN_MINESWEEPER_APOBS_RBA";
		model = "\x\ace\addons\sys_minesweeper\ace_apobs_b.p3d";
		ACE_Weight = 23.6;
	};
	class ACE_Item;
	class ACE_MineMarkers: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_DN_MINESWEEPER_MINEMARKERS";
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker_w.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_marker_ca.paa";
		ACE_Weight = 1;
	};
	class ACE_MineMarkers_Light: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_DN_MINESWEEPER_MINEMARKERS_LIGHT";
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker_light_w.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_marker_light_ca.paa";
		ACE_Weight = 1;
	};
	class ACE_MineMarkers_PathSign: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_DN_MINESWEEPER_MINEMARKERS_PATHSIGN";
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker_psign_w.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_marker_lane_ca.paa";
		ACE_Weight = 1;
	};
	class ACE_MineMarkers_MineSign: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_DN_MINESWEEPER_MINEMARKERS_MINESIGN";
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker_msign_w.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_marker_sign_ca.paa";
		ACE_Weight = 1;
	};
	class ACE_MineMarkers_MineFlag: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_DN_MINESWEEPER_MINEMARKERFLAG";
		model = "\x\ace\addons\sys_minesweeper\ace_minemarker_flag_w.p3d";
		picture = "\x\ace\addons\sys_minesweeper\data\equip\w_minemarkerflag_ca.paa";
		ACE_Weight = 1;
	};
};
class CfgSounds
{
	class ace_sweep_low
	{
		name = "ace_sweep_low";
		sound[] = {"\x\ace\addons\sys_minesweeper\sound\ace_sweep_low.ogg","db+1",1};
		titles[] = {};
	};
	class ace_sweep_high: ace_sweep_low
	{
		name = "ace_sweep_1";
		sound[] = {"\x\ace\addons\sys_minesweeper\sound\ace_sweep_high.ogg","db+1",1};
	};
};
//};
