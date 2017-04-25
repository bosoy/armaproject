////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 28 15:59:48 2011 : Created on Fri Oct 28 15:59:48 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_m88 : config.bin{
class CfgPatches
{
	class acex_veh_m88
	{
		units[] = {"ACE_M88"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_c_vehicle","Extended_EventHandlers","CATracked","CATracked_E","CAWeapons","CA_Anims","CAData"};
		version = "1.12.0.349";
		author[] = {"Frankyman"};
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
	class ACE_M88: M113_UN_EP1
	{
		ace_uber_tower = 1;
		vehicleclass = "ArmouredD";
		simulation = "tank";
		displayName = "M88A2";
		side = 1;
		faction = "BIS_US";
		crew = "US_Soldier_Crew_EP1";
		hasCommander = 1;
		hasGunner = 0;
		maxSpeed = 50;
		displayNameShort = "M88";
		model = "\x\acex\addons\m_veh_m88\m88.p3d";
		icon = "\x\acex\addons\c_veh_m88\data\icon\icomap_m88a2_ca.paa";
		picture = "\x\acex\addons\c_veh_m88\data\picture\m88a_ca.paa";
		mapSize = 9;
		transportSoldier = 0;
		cargoAction[] = {};
		unitInfoType = "UnitInfoShip";
		hiddenSelections[] = {"Camo1","Camo2","Camo3"};
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m88\M88_001_co.paa","\x\acex\addons\t_veh_m88\M88_002_co.paa","\x\acex\addons\t_veh_m88\M88_003_co.paa"};
		driverForceOptics = 1;
		driverOpticsModel = "CA\Tracked_E\driverOptics";
		driverCompartments = 0;
		forceHideDriver = 1;
		viewDriverInExternal = 1;
		LODTurnedOut = "VIEW_GUNNER";
		LODTurnedIn = "VIEW_PILOT";
		hideProxyInCombat = 1;
		weapons[] = {"FakeWeapon"};
		magazines[] = {"FakeWeapon"};
		insideSoundCoef = 0.9;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				proxyType = "CPCommander";
				gunnerName = "$STR_POSITION_COMMANDER";
				proxyIndex = 1;
				gunnerCompartments = 1;
				animationSourceHatch = "HatchCommander";
				gun = "";
				animationSourceGun = "";
				startEngine = 0;
				weapons[] = {"SmokeLauncher"};
				magazines[] = {"SmokeLauncherMag"};
				gunnerAction = "BMP2_GunnerOut";
				gunnerInAction = "BMP2_Gunner";
				primaryGunner = 1;
				primaryObserver = 1;
				primary = 1;
				hasGunner = 1;
				commanding = 1;
				forceHideGunner = 1;
				viewGunnerInExternal = 1;
				gunnerForceOptics = 1;
				gunnerOpticsModel = "CA\Tracked_E\driverOptics";
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				memoryPointGunnerOptics = "commanderview";
			};
			class CoDriverTurret: MainTurret
			{
				proxyType = "CPGunner";
				proxyIndex = 2;
				gunnerName = "$STR_POSITION_GUNNER";
				body = "";
				animationSourceBody = "";
				gun = "";
				animationSourceGun = "";
				gunnerCompartments = 2;
				animationSourceHatch = "HatchGunner";
				startEngine = 0;
				weapons[] = {};
				magazines[] = {};
				gunnerAction = "M113_Driver_EP1";
				gunnerInAction = "M113_Driver_EP1";
				primaryGunner = 0;
				primaryObserver = 0;
				primary = 0;
				hasGunner = 1;
				commanding = 0;
				memoryPointGunnerOptics = "codriverview";
			};
		};
		canFloat = 0;
		class Exhausts
		{
			class Exhaust1
			{
				position = "vyfuk start_1";
				direction = "vyfuk konec_1";
				effect = "ExhaustsEffectBig";
			};
			class Exhaust2
			{
				position = "vyfuk start_2";
				direction = "vyfuk konec_2";
				effect = "ExhaustsEffectBig";
			};
		};
		smokeLauncherGrenadeCount = 6;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 0;
		smokeLauncherAngle = 120;
		class TransportWeapons
		{
			class _xx_ACE_JerryCan_Dummy_15
			{
				weapon = "ACE_JerryCan_Dummy_15";
				count = 3;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 2;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex\addons\c_veh_m88\Kette.rvmat","x\acex\addons\c_veh_m88\Kette_damage.rvmat","x\acex\addons\c_veh_m88\Kette_destruct.rvmat","x\acex\addons\c_veh_m88\M88_001.rvmat","x\acex\addons\c_veh_m88\M88_001_damage.rvmat","x\acex\addons\c_veh_m88\M88_001_destruct.rvmat","x\acex\addons\c_veh_m88\M88_001a.rvmat","x\acex\addons\c_veh_m88\M88_001a_damage.rvmat","x\acex\addons\c_veh_m88\M88_001a_destruct.rvmat","x\acex\addons\c_veh_m88\M88_002.rvmat","x\acex\addons\c_veh_m88\M88_002_damage.rvmat","x\acex\addons\c_veh_m88\M88_002_destruct.rvmat","x\acex\addons\c_veh_m88\M88_003.rvmat","x\acex\addons\c_veh_m88\M88_003_damage.rvmat","x\acex\addons\c_veh_m88\M88_003_destruct.rvmat"};
		};
		ace_dmgsys_enable = 1;
		ace_minimalhit[] = {21,70};
		ace_era = 1;
		ace_p_detonation_hull = 0;
		ace_p_detonation_turret = 0;
		ace_p_detonation_engine = 0.3;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0;
		ace_armor_hull[] = {{130,150},{88,88},{88,88},{88,88},{44,44},{130,150}};
		ace_armor_turret[] = {{130,150},{88,88},{88,88},{88,88},{44,44},{130,150}};
		ace_era_hull[] = {{0,0},{22,22},{22,22},{0,0},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0,0.8,0.8,0,0};
		ace_era_blocks_hull[] = {0,5,5,0,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
};
//};
