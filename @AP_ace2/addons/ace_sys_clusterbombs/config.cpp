////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:44:23 2013 : Created on Sat Apr 06 11:44:23 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_clusterbombs : config.bin{
class CfgPatches
{
	class ace_sys_clusterbombs
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_craters","ace_sys_mfd"};
		version = "1.14.0.590";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_clusterbombs
		{
			list[] = {"ace_sys_clusterbombs"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_clusterbombs
	{
		init = "call ('\x\ace\addons\sys_clusterbombs\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Plane
	{
		ace_sys_clusterbombs_CBU = "if (local (_this select 0)) then {if (getText(configFile >> 'CfgAmmo' >> (_this select 4) >> 'ACE_Simulation') == 'shotCBU') then { _this call ace_sys_clusterbombs_fnc_fired }}";
		ace_sys_clusterbombs_BB = "if (local (_this select 0)) then {if (getText(configFile >> 'CfgAmmo' >> (_this select 4) >> 'ACE_Simulation') == 'shotBunkerBuster') then { _this call ace_sys_clusterbombs_fnc_fired }}";
	};
};
class CfgVehicles
{
	class Thing;
	class ACE_CBU_Splitter: Thing
	{
		scope = 1;
		simulation = "thing";
		animated = 0;
		mapSize = 0.7;
		displayName = "";
		nameSound = "";
		accuracy = 0.2;
		destrType = "DestructNo";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_CBU87_Shell_1: ACE_CBU_Splitter
	{
		model = "\x\ace\addons\sys_clusterbombs\SUU65_Shell_1_fly.p3d";
	};
	class ACE_CBU87_Shell_2: ACE_CBU_Splitter
	{
		model = "\x\ace\addons\sys_clusterbombs\SUU65_Shell_2_fly.p3d";
	};
	class ACE_CBU_87_Core: ACE_CBU_Splitter
	{
		model = "\x\ace\addons\sys_clusterbombs\SUU65_Core_fly.p3d";
	};
	class Parachute_US_EP1;
	class ACE_BLU108B: Parachute_US_EP1
	{
		scope = 1;
		displayName = "";
		model = "\x\ace\addons\sys_clusterbombs\BLU108B.p3d";
		castDriverShadow = 0;
		soundEnviron[] = {"\Ca\sounds\Air\Noises\padak_let",0.316228,1,80};
		soundCrash[] = {"db-30",1};
		soundLandCrash[] = {"db-30",1};
		soundWaterCrash[] = {"db10",1};
		mapSize = 0;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_BLU107BPara: ACE_BLU108B
	{
		model = "\x\ace\addons\sys_clusterbombs\BLU107Bpara.p3d";
	};
};
class CfgAmmo
{
	class LaserBombCore;
	class ACE_LaserCore: LaserBombCore
	{
		class ACE{};
	};
	class ACE_CBU87: ACE_LaserCore
	{
		displayName = "CBU-87/B";
		model = "\x\ace\addons\sys_clusterbombs\SUU65_fly.p3d";
		proxyShape = "\x\ace\addons\sys_clusterbombs\SUU65.p3d";
		cost = 10000;
		hit = 1;
		indirectHit = 1;
		indirectHitRange = 0;
		trackOversteer = 0;
		trackLead = 0;
		maneuverability = 0;
		CraterEffects = "";
		ExplosionEffects = "";
		irLock = 0;
		class ACE: ACE
		{
			class ACE_CLUSTERBOMBS
			{
				ammo[] = {"ACE_BLU97B","ACE_BLU97B_0"};
				count[] = {200};
				deployHight[] = {80,6100};
				simulation = "ACE_CEM";
			};
		};
		ACE_Simulation = "shotCBU";
		ACE_ccip_proxy = "ACE_CBU87_CCIP";
	};
	class ACE_CBU87_CCIP: ACE_CBU87
	{
		simulation = "shotShell";
		timeToLive = 500;
		airFriction = 6.58e-006;
	};
	class ACE_CBU97: ACE_CBU87
	{
		displayName = "CBU-97/B";
		class ACE: ACE
		{
			class ACE_CLUSTERBOMBS: ACE_CLUSTERBOMBS
			{
				ammo[] = {"ACE_BLU108B"};
				count[] = {10};
				simulation = "ACE_SFW";
			};
		};
		ACE_ccip_proxy = "ACE_CBU97_CCIP";
	};
	class ACE_CBU97_CCIP: ACE_CBU97
	{
		simulation = "shotShell";
		timeToLive = 500;
		airFriction = 6.58e-006;
	};
	class ACE_BLU107B: ACE_CBU87
	{
		displayName = "BLU-107/B";
		model = "\x\ace\addons\sys_clusterbombs\BLU107B.p3d";
		proxyShape = "\x\ace\addons\sys_clusterbombs\BLU107B.p3d";
		hit = 1;
		indirectHit = 1;
		indirectHitRange = 1;
		class ACE: ACE
		{
			class ACE_CLUSTERBOMBS: ACE_CLUSTERBOMBS
			{
				ammo[] = {};
				count[] = {1};
				simulation = "ACE_Runway";
			};
		};
		ACE_Simulation = "shotBunkerBuster";
		ACE_ccip_proxy = "ACE_BLU107B_CCIP";
	};
	class ACE_BLU107B_CCIP: ACE_BLU107B
	{
		simulation = "shotShell";
		timeToLive = 500;
		airFriction = 6.58e-006;
	};
	class GrenadeHand;
	class ACE_BLU97B: GrenadeHand
	{
		displayName = "";
		model = "\x\ace\addons\sys_clusterbombs\BLU97B.p3d";
		cost = 600;
		hit = 80;
		indirectHit = 40;
		indirectHitRange = 8;
		ace_hit = 40;
	};
	class ACE_BLU97B_0: ACE_BLU97B
	{
		CraterEffects = "";
		ExplosionEffects = "";
	};
	class ARTY_SADARM_BURST;
	class ACE_BLU108B_BURST: ARTY_SADARM_BURST
	{
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		thrustTime = 0.001;
		thrust = 0.001;
		timeToLive = 0.2;
		explosive = 1;
		CraterEffects = "";
		ExplosionEffects = "AAMissileExplosion";
		whistleDist = 0;
	};
	class ARTY_SADARM_PROJO;
	class ACE_BLU108B_PROJO: ARTY_SADARM_PROJO
	{
		hit = 90;
		indirectHit = 32;
		indirectHitRange = 3;
		ace_hit = 90;
		ace_heat = 1;
		ace_topattack = 1;
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class ACE_CBU_Base: VehicleMagazine
	{
		displayName = "";
		scope = 1;
		initSpeed = 0;
		nameSound = "";
		count = 0;
		maxLeadSpeed = 300;
		ammo = "";
		ACE_EASA = 0;
	};
	class ACE_CBU87: ACE_CBU_Base
	{
		scope = 2;
		displayName = "CBU-87/B";
		ammo = "ACE_CBU87";
		count = 1;
		ACE_EASA_SIDE = 1;
		ACE_EASA_WEAPON = "ACE_CBU87_Bomblauncher";
		ACE_EASA = 1;
		ACE_EASA_NAME = "CBU-87/B";
		ACE_EASA_CARRIER[] = {"Plane"};
	};
	class ACE_2Rnd_CBU87: ACE_CBU87
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_CBU87: ACE_2Rnd_CBU87
	{
		count = 4;
	};
	class ACE_6Rnd_CBU87: ACE_2Rnd_CBU87
	{
		count = 6;
	};
	class ACE_8Rnd_CBU87: ACE_2Rnd_CBU87
	{
		count = 8;
	};
	class ACE_CBU97: ACE_CBU87
	{
		displayName = "CBU-97/B";
		ammo = "ACE_CBU97";
		count = 1;
		ACE_EASA_WEAPON = "ACE_CBU97_Bomblauncher";
		ACE_EASA_NAME = "CBU-97/B";
	};
	class ACE_2Rnd_CBU97: ACE_CBU97
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_CBU97: ACE_2Rnd_CBU97
	{
		count = 4;
	};
	class ACE_6Rnd_CBU97: ACE_2Rnd_CBU97
	{
		count = 6;
	};
	class ACE_8Rnd_CBU97: ACE_2Rnd_CBU97
	{
		count = 8;
	};
	class ACE_BLU107: ACE_CBU87
	{
		displayName = "BLU107";
		ammo = "ACE_BLU107B";
		count = 1;
		ACE_EASA_WEAPON = "ACE_BLU107_Bomblauncher";
		ACE_EASA_NAME = "BLU-107/B";
	};
	class ACE_2Rnd_BLU107: ACE_BLU107
	{
		count = 2;
		ACE_EASA = 0;
	};
	class ACE_4Rnd_BLU107: ACE_2Rnd_BLU107
	{
		count = 4;
	};
	class ACE_6Rnd_BLU107: ACE_2Rnd_BLU107
	{
		count = 6;
	};
	class ACE_8Rnd_BLU107: ACE_2Rnd_BLU107
	{
		count = 8;
	};
};
class CfgWeapons
{
	class BombLauncher;
	class ACE_CBU87_Bomblauncher: BombLauncher
	{
		scope = 2;
		displayName = "CBU-87";
		reloadTime = 1.5;
		minRange = 200;
		minRangeProbab = 0.1;
		midRange = 2000;
		midRangeProbab = 0.7;
		maxRange = 5000;
		maxRangeProbab = 0.4;
		laser = 1;
		namesound = "";
		aiRateOfFireDistance = 100;
		aiRateOfFire = 2;
		autofire = 0;
		magazines[] = {"ACE_CBU87","ACE_2Rnd_CBU87","ACE_4Rnd_CBU87","ACE_6Rnd_CBU87","ACE_8Rnd_CBU87"};
		ACE_EASA = 1;
		ACE_HUD_WeaponType = "bomb";
	};
	class ACE_CBU97_Bomblauncher: ACE_CBU87_Bomblauncher
	{
		displayName = "CBU-97";
		magazines[] = {"ACE_CBU97","ACE_2Rnd_CBU97","ACE_4Rnd_CBU97","ACE_6Rnd_CBU97","ACE_8Rnd_CBU97"};
		ACE_EASA = 1;
		ACE_HUD_WeaponType = "bomb";
	};
	class ACE_BLU107_Bomblauncher: ACE_CBU87_Bomblauncher
	{
		displayName = "BLU-107/B";
		magazines[] = {"ACE_BLU107","ACE_2Rnd_BLU107","ACE_4Rnd_BLU107","ACE_6Rnd_BLU107","ACE_8Rnd_BLU107"};
		reloadTime = 0.1;
		ACE_EASA = 1;
		ACE_HUD_WeaponType = "bomb";
	};
};
//};
