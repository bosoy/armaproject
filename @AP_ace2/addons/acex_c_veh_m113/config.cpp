////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 02 21:00:05 2012 : Created on Fri Nov 02 21:00:05 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_m113 : config.bin{
class CfgPatches
{
	class acex_veh_m113
	{
		units[] = {"ACE_M113A3","ACE_M113A3_Ambul","ACE_Vulcan"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","ace_c_vehicle","CATracked_E_M113"};
		version = "1.14.0.369";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class ACE_Vulcan
	{
		acex_veh_m113_fired = "if (local (_this select 0)) then {if ((_this select 1) == 'M168') then {(_this select 0) animate ['cannon',((_this select 0) animationPhase 'cannon') + 1]};};";
	};
};
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class Turrets;
	};
	class M113_Base: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class M113_UN_EP1: M113_Base{};
	class ACE_M113A3: M113_UN_EP1
	{
		side = 1;
		faction = "BIS_US";
		crew = "US_Soldier_Crew_EP1";
		displayName = "M113A3";
		vehicleclass = "ArmouredW";
		hiddenSelectionsTextures[] = {"\ca\Tracked_E\M113\Data\m113a3_01_co.paa"};
		class TransportMagazines
		{
			class _xx_30Rnd_556x45_Stanag
			{
				count = 30;
				magazine = "30Rnd_556x45_Stanag";
			};
			class _xx_1Rnd_HE_M203
			{
				count = 16;
				magazine = "1Rnd_HE_M203";
			};
			class _xx_HandGrenade_West
			{
				count = 10;
				magazine = "HandGrenade_West";
			};
			class _xx_100Rnd_762x51_M240
			{
				count = 5;
				magazine = "100Rnd_762x51_M240";
			};
			class _xx_SmokeShell
			{
				count = 2;
				magazine = "SmokeShell";
			};
			class _xx_SmokeShellOrange
			{
				count = 2;
				magazine = "SmokeShellOrange";
			};
		};
		class TransportWeapons
		{
			class _xx_ACE_M4
			{
				count = 2;
				weapon = "ACE_M4";
			};
		};
	};
	class ACE_Vulcan: M113_UN_EP1
	{
		vehicleclass = "ArmouredW";
		displayName = "M163 PIVADS";
		side = 1;
		faction = "BIS_US";
		crew = "US_Soldier_Crew_EP1";
		model = "\x\acex\addons\m_veh_m113\M163_vulcan.p3d";
		picture = "\x\acex\addons\c_veh_m113\data\picture\m163_vulcan_ca.paa";
		icon = "\x\acex\addons\c_veh_m113\data\icon\icomap_vulcan_ca.paa";
		hasCommander = 0;
		transportSoldier = 0;
		weapons[] = {};
		magazines[] = {};
		cost = 1000000;
		threat[] = {1,0.5,1};
		gunnerCanSee = "4+8+16+1";
		irScanRangeMin = 10;
		irScanRangeMax = 4000;
		radartype = 4;
		irScanGround = 0;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				startengine = 1;
				weapons[] = {"M168"};
				magazines[] = {"2100Rnd_20mm_M168"};
				minElev = -5;
				maxElev = 80;
				initElev = 10;
				minTurn = -360;
				maxTurn = 360;
				gunnerAction = "M163_GunnerOut";
				gunnerInAction = "M163_Gunner";
				gunnerOpticsModel = "\ca\weapons\2Dscope_Avenger";
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
			};
		};
		class AnimationSources
		{
			class Cannon
			{
				source = "user";
				animPeriod = 1.3;
			};
			class Revolving
			{
				source = "revolving";
				weapon = "M168";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"Ca\Tracked_E\M113\Data\m113_track.rvmat","Ca\Tracked_E\M113\Data\m113_track.rvmat","Ca\Tracked_E\M113\Data\m113_track_destruct.rvmat","x\acex\addons\c_veh_m113\m163_02_metal.rvmat","x\acex\addons\c_veh_m113\m163_02_metal.rvmat","x\acex\addons\c_veh_m113\m163_02_metal_destruct.rvmat","x\acex\addons\c_veh_m113\m163_01_metal.rvmat","x\acex\addons\c_veh_m113\m163_01_metal.rvmat","x\acex\addons\c_veh_m113\m163_01_metal_destruct.rvmat","Ca\Tracked_E\M113\Data\cargo.rvmat","Ca\Tracked_E\M113\Data\cargo.rvmat","Ca\Tracked_E\M113\Data\cargo_destruct.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default_destruct.rvmat"};
		};
		class TransportMagazines
		{
			class _xx_SmokeShell
			{
				count = 2;
				magazine = "SmokeShell";
			};
			class _xx_SmokeShellOrange
			{
				count = 2;
				magazine = "SmokeShellOrange";
			};
		};
		class TransportWeapons{};
		ace_sys_turret_indicator_enable = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_range = 3600;
		ace_sys_air_rwr_threat_img_spo = 3;
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_vu.paa";
	};
	class M113Ambul_Base;
	class ACE_M113A3_Ambul: M113Ambul_Base
	{
		scope = 2;
		side = 1;
		faction = "BIS_US";
		crew = "US_Soldier_Crew_EP1";
		typicalCargo[] = {"US_Soldier_Crew_EP1","US_Soldier_Crew_EP1"};
		displayName = "$STR_ACE_VDN_M113A3 AMBULANCE";
		displayNameShort = "$STR_ACE_VDN_M113A3 AMBULANCE_SHORT";
		cargoIsDriver[] = {0,0,0};
		hiddenSelectionsTextures[] = {"\ca\Tracked_E\M113\Data\m113a3_01_co.paa","\x\acex\addons\t_veh_m113\m113a3_02_co.paa"};
		model = "\x\acex\addons\m_veh_m113\m113_ambulance.p3d";
		attendant = 0;
		class UserActions
		{
			class ACE_MagicHeal
			{
				displayName = "$STR_ACE_UA_HEAL";
				onlyForPlayer = 1;
				position = "doplnovani";
				radius = 5;
				condition = "((isNil ""ace_sys_wounds_enabled"") && {(damage player > 0)} && {!(player in this)})";
				statement = "player setdamage 0; player playmove ""AinvPknlMstpSlayWrflDnon_medic"";";
			};
		};
	};
};
//};
