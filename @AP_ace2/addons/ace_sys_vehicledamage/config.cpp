////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.51
//Mon Jul 28 05:52:55 2014 : Source 'file' date Mon Jul 28 05:52:55 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_vehicledamage : config.bin{
class CfgPatches
{
	class ace_sys_vehicledamage
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_c_vehicle","ace_sys_particlefx"};
		version = "1.14.0.597";
		author[] = {"q1184","King Homer"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_vehicledamage
	{
		init = "call ('\x\ace\addons\sys_vehicledamage\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class Tank
	{
		ace_sys_vehicledamage_add_hd_tank = "_this call ace_sys_vehicledamage_fnc_tank_add_hdeh";
	};
	class Wheeled_APC
	{
		ace_sys_vehicledamage_add_hd_wapc = "_this call ace_sys_vehicledamage_fnc_wapc_add_hdeh";
	};
	class Car
	{
		class ace_sys_vehicledamage_add_hd_survival
		{
			init = "_this call ace_sys_vehicledamage_fnc_survival_add_hdeh";
			exclude[] = {"Wheeled_APC"};
		};
	};
};
class Extended_IncomingMissile_EventHandlers
{
	class Tank
	{
		class ace_sys_vehicledamage
		{
			incomingMissile = "_this call ace_sys_vehicledamage_fnc_incoming_missile";
		};
	};
	class Wheeled_APC
	{
		class ace_sys_vehicledamage
		{
			incomingMissile = "_this call ace_sys_vehicledamage_fnc_incoming_missile";
		};
	};
};
class Extended_Killed_EventHandlers
{
	class Land
	{
		class ace_sys_vehicledamage
		{
			killed = "_this call ace_sys_vehicledamage_fnc_handleAmmoTrucks";
			exclude[] = {"Wheeled_APC","Tank"};
		};
	};
	class T72_Base
	{
		class ace_sys_vehicledamage
		{
			killed = "_this spawn ace_sys_vehicledamage_fnc_t72_catastrophicdestruction";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Land
	{
		ace_sys_vehicledamage = "if (local (_this select 0)) then { if ((_this select 6) isKindOf 'MissileBase') then { if (getNumber(configFile >> 'cfgAmmo' >> (_this select 4) >> 'ace_aa') == 1) then {_this call ace_sys_vehicledamage_fnc_AA_missile}}};";
	};
};
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		ace_firepos[] = {0,-2.5,-1};
		ace_minimalhit[] = {10,30};
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0.2;
		deepWaterFording[] = {0,"",0};
	};
	class Tracked_APC: Tank
	{
		ace_firepos[] = {0.5,1.5,-1};
	};
	class Car;
	class Wheeled_APC: Car
	{
		ace_firepos[] = {0,0,-1};
		ace_minimalhit[] = {10,30};
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0.2;
	};
	class T90: Tank
	{
		ace_minimalhit[] = {40,100};
		ace_era = 1;
		ace_p_detonation_hull = 0;
		ace_p_detonation_turret = 0;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0;
		ace_armor_hull[] = {{ 510,540 },{ 70,230 },{ 70,230 },{ 40,40 },{ 40,40 },{ 200,200 }};
		ace_era_hull[] = {{ 200,450 },{ 50,300 },{ 50,300 },{ 0,0 },{ 50,300 },{ 0,0 }};
		ace_era_coverage_hull[] = {0.9,0.5,0.5,0,0};
		ace_era_blocks_hull[] = {4,3,3,0,0};
		ace_armor_turret[] = {{ 560,740 },{ 420,580 },{ 420,580 },{ 140,140 },{ 40,40 }};
		ace_era_turret[] = {{ 250,600 },{ 250,600 },{ 250,600 },{ 0,0 },{ 50,120 }};
		ace_era_coverage_turret[] = {0.7,0.3,0.3,0,0.3};
		ace_era_blocks_turret[] = {6,1,1,0,5};
		ace_sys_vehicledamage_shtora = 1;
	};
	class ACE_T90A: T90
	{
		ace_armor_turret[] = {{ 700,880 },{ 420,580 },{ 420,580 },{ 140,140 },{ 40,40 }};
		ace_era_turret[] = {{ 250,600 },{ 250,600 },{ 250,600 },{ 0,0 },{ 50,120 }};
		ace_era_coverage_turret[] = {0.9,0.3,0.3,0,0.3};
		ace_era_blocks_turret[] = {8,1,1,0,5};
		ace_sys_vehicledamage_shtora = 0;
	};
	class T72_Base: Tank
	{
		ace_minimalhit[] = {40,100};
		ace_era = 0;
		ace_p_detonation_hull = 0.8;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.8;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0.2;
		ace_armor_hull[] = {{ 400,490 },{ 30,170 },{ 30,170 },{ 40,40 },{ 40,40 },{ 200,200 }};
		ace_armor_turret[] = {{ 380,490 },{ 160,200 },{ 160,200 },{ 100,120 },{ 40,40 },{ 0,0 }};
	};
	class T55_Base: Tank
	{
		ace_minimalhit[] = {20,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.5;
		ace_p_detonation_turret = 0.5;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 98,98 },{ 50,50 },{ 50,50 },{ 46,46 },{ 33,33 },{ 20,20 }};
		ace_armor_turret[] = {{ 203,203 },{ 150,150 },{ 150,150 },{ 64,64 },{ 39,39 }};
	};
	class ZSU_Base: Tank
	{
		ace_minimalhit[] = {13,30};
		ace_era = 0;
		ace_p_detonation_hull = 0;
		ace_p_detonation_turret = 0;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0.7;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.8;
		ace_armor_hull[] = {{ 10,10 },{ 10,10 },{ 10,10 },{ 10,10 },{ 10,10 },{ 7,7 }};
		ace_armor_turret[] = {{ 9,9 },{ 9,9 },{ 9,9 },{ 9,9 },{ 9,9 }};
	};
	class T34: Tank
	{
		ace_minimalhit[] = {20,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.8;
		ace_armor_hull[] = {{ 60,60 },{ 35,35 },{ 35,35 },{ 20,20 },{ 20,20 },{ 40,40 }};
		ace_armor_turret[] = {{ 90,110 },{ 60,60 },{ 60,60 },{ 20,20 },{ 20,20 }};
	};
	class 2S6M_Tunguska: Tank
	{
		ace_minimalhit[] = {13,30};
		ace_era = 0;
		ace_p_detonation_hull = 0.4;
		ace_p_detonation_turret = 0.4;
		ace_p_detonation_engine = 0.4;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0.7;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.8;
		ace_armor_hull[] = {{ 14,14 },{ 14,14 },{ 14,14 },{ 14,14 },{ 14,14 },{ 14,14 }};
		ace_armor_turret[] = {{ 16,16 },{ 14,14 },{ 14,14 },{ 14,14 },{ 8,8 }};
	};
	class M1A1: Tank
	{
		ace_minimalhit[] = {40,100};
		ace_era = 0;
		ace_p_detonation_hull = 0;
		ace_p_detonation_turret = 0;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0;
		ace_p_fire_turret = 0;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0;
		ace_armor_hull[] = {{ 590,770 },{ 155,347 },{ 155,347 },{ 40,40 },{ 40,40 },{ 200,200 }};
		ace_armor_turret[] = {{ 850,1300 },{ 478,540 },{ 478,540 },{ 100,120 },{ 40,40 }};
		deepWaterFording[] = {1,"ACE_DWFK",2.4,"out"};
	};
	class M1A2_TUSK_MG: M1A1
	{
		ace_minimalhit[] = {40,100};
		ace_era = 1;
		ace_armor_hull[] = {{ 590,770 },{ 155,347 },{ 155,347 },{ 40,40 },{ 40,40 },{ 300,300 }};
		ace_era_hull[] = {{ 0,0 },{ 150,400 },{ 150,400 },{ 20,200 },{ 0,0 },{ 0,0 }};
		ace_era_coverage_hull[] = {0,0.8,0.8,0.9,0};
		ace_era_blocks_hull[] = {0,8,8,1,0};
		ace_armor_turret[] = {{ 850,1300 },{ 478,540 },{ 478,540 },{ 100,120 },{ 40,40 }};
		ace_era_turret[] = {{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
		deepWaterFording[] = {0,"ACE_DWFK",2.4,"out"};
	};
	class MLRS: Tank
	{
		ace_dmgsys_enable = 0;
		ace_minimalhit[] = {10,40};
		ace_era = 0;
		ace_firepos[] = {0,0,-1};
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.7;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0.5;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.8;
		ace_armor_hull[] = {{ 25,25 },{ 10,10 },{ 10,10 },{ 10,10 },{ 10,10 },{ 10,10 }};
		ace_armor_turret[] = {{ 10,10 },{ 10,10 },{ 10,10 },{ 10,10 },{ 10,10 }};
	};
	class BMP2_Base: Tracked_APC
	{
		ace_minimalhit[] = {18,40};
		ace_era = 0;
		ace_p_detonation_hull = 0;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.8;
		ace_p_fire_turret = 0.5;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 40,40 },{ 18,18 },{ 18,18 },{ 16,16 },{ 16,16 },{ 30,30 }};
		ace_armor_turret[] = {{ 33,33 },{ 19,19 },{ 19,19 },{ 19,19 },{ 16,16 }};
	};
	class BMP2_HQ_Base: BMP2_Base
	{
		ace_firepos[] = {0,0,-3};
	};
	class BMP3: Tracked_APC
	{
		ace_minimalhit[] = {18,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 50,50 },{ 30,30 },{ 30,30 },{ 16,16 },{ 16,16 },{ 50,50 }};
		ace_armor_turret[] = {{ 33,33 },{ 21,21 },{ 21,21 },{ 21,21 },{ 16,16 }};
		ace_firepos[] = {0,-2.5,-1};
	};
	class AAV: Tracked_APC
	{
		ace_minimalhit[] = {20,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.5;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 35,35 },{ 44,44 },{ 44,44 },{ 25,25 },{ 30,30 },{ 30,30 }};
		ace_armor_turret[] = {{ 20,20 },{ 20,20 },{ 20,20 },{ 20,20 },{ 20,20 }};
	};
	class M2A2_Base: Tank
	{
		ace_minimalhit[] = {19,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 130,150 },{ 44,44 },{ 44,44 },{ 38,38 },{ 38,38 },{ 40,40 }};
		ace_armor_turret[] = {{ 110,126 },{ 44,44 },{ 44,44 },{ 20,20 },{ 15,15 }};
		ace_firepos[] = {0.5,1.5,-1};
	};
	class M2A2_EP1: M2A2_Base{};
	class M2A3_EP1: M2A2_EP1
	{
		ace_era = 1;
		ace_era_hull[] = {{ 150,400 },{ 150,400 },{ 150,400 },{ 0,0 },{ 0,0 },{ 0,0 }};
		ace_era_coverage_hull[] = {0.5,0.8,0.8,0,0};
		ace_era_blocks_hull[] = {4,16,16,0,0};
		ace_era_turret[] = {{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
	};
	class M6_EP1: M2A2_Base{};
	class M113_Base: Tank
	{
		ace_minimalhit[] = {19,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 38,38 },{ 44,44 },{ 44,44 },{ 38,38 },{ 38,38 },{ 29,29 }};
		ace_armor_turret[] = {{ 15,15 },{ 15,15 },{ 15,15 },{ 15,15 },{ 0,0 }};
		ace_firepos[] = {0.5,1.5,-1};
	};
	class BAF_FV510_D: Tank
	{
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.2;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_minimalhit[] = {19,70};
		ace_armor_hull[] = {{ 160,180 },{ 44,44 },{ 44,44 },{ 38,38 },{ 38,38 },{ 40,40 }};
		ace_armor_turret[] = {{ 120,140 },{ 44,54 },{ 44,54 },{ 20,30 },{ 15,15 }};
		ace_era = 1;
		ace_era_hull[] = {{ 20,400 },{ 150,400 },{ 150,400 },{ 20,400 },{ 0,0 },{ 0,0 }};
		ace_era_coverage_hull[] = {0.2,0.8,0.8,0.4,0};
		ace_era_blocks_hull[] = {1,16,16,2,0};
		ace_era_turret[] = {{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
		ace_firepos[] = {0.5,1.5,-1};
	};
	class BRDM2_Base: Wheeled_APC
	{
		ace_minimalhit[] = {13,30};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0.7;
		ace_p_fire_engine = 0.7;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 14,14 },{ 7,7 },{ 7,7 },{ 7,7 },{ 3,3 },{ 10,10 }};
		ace_armor_turret[] = {{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 }};
	};
	class BTR60_TK_EP1: BRDM2_Base
	{
		ace_armor_hull[] = {{ 9,9 },{ 7,7 },{ 7,7 },{ 7,7 },{ 5,5 },{ 10,10 }};
		ace_armor_turret[] = {{ 10,10 },{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 }};
	};
	class BTR40_MG_base_EP1: Wheeled_APC
	{
		ace_minimalhit[] = {13,30};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.0;
		ace_p_detonation_engine = 0.1;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0.7;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 8,8 },{ 6,6 },{ 6,6 },{ 6,6 },{ 0,0 },{ 3,3 }};
		ace_armor_turret[] = {{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 },{ 0,0 }};
	};
	class GAZ_Vodnik_HMG: Wheeled_APC
	{
		ace_minimalhit[] = {13,30};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0.1;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0.7;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 14,14 },{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 },{ 10,10 }};
		ace_armor_turret[] = {{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 }};
	};
	class GAZ_Vodnik: GAZ_Vodnik_HMG
	{
		ace_minimalhit[] = {13,30};
		ace_p_detonation_hull = 0;
		ace_p_detonation_turret = 0;
		ace_p_detonation_engine = 0.1;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0;
		ace_armor_hull[] = {{ 14,14 },{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 },{ 10,10 }};
		ace_armor_turret[] = {{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 },{ 7,7 }};
	};
	class BTR90_Base: Wheeled_APC
	{
		ace_minimalhit[] = {19,50};
		ace_era = 0;
		ace_p_detonation_hull = 0.5;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.5;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 35,35 },{ 22,22 },{ 22,22 },{ 22,22 },{ 22,22 },{ 20,20 }};
		ace_armor_turret[] = {{ 33,33 },{ 19,19 },{ 19,19 },{ 19,19 },{ 19,19 }};
	};
	class LAV25_Base: Wheeled_APC
	{
		ace_minimalhit[] = {18,50};
		ace_era = 0;
		ace_firepos[] = {0.5,1.5,-1};
		ace_p_detonation_hull = 0.5;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.5;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 35,35 },{ 18,18 },{ 18,18 },{ 18,18 },{ 18,18 },{ 20,20 }};
		ace_armor_turret[] = {{ 30,30 },{ 22,22 },{ 22,22 },{ 18,18 },{ 22,22 }};
	};
	class StrykerBase_EP1: Wheeled_APC
	{
		ace_minimalhit[] = {19,70};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.5;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.8;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{ 35,35 },{ 18,18 },{ 18,18 },{ 18,18 },{ 18,18 },{ 20,20 }};
		ace_armor_turret[] = {{ 30,30 },{ 18,18 },{ 18,18 },{ 18,18 },{ 18,18 }};
	};
	class ACE_Logic;
	class ACE_Vehicledamage_Enable_Cookoff: ACE_Logic
	{
		displayName = "$STR_DN_ACE_SYS_VEHICLEDAMAGE_ENCOOK";
		icon = "\x\ace\addons\sys_vehicledamage\data\icon\ace_cook_ico_ca.paa";
		picture = "\x\ace\addons\sys_vehicledamage\data\icon\ace_cook_ico_ca.paa";
		vehicleClass = "Modules";
		class EventHandlers
		{
			init = "ace_sys_destruction_enable_cookoff = true";
		};
	};
};
class cfgAmmo
{
	class Default;
	class bulletCore;
	class bulletbase: bulletCore
	{
		ace_incendiary = 0.5;
		ace_tandemheat = 0;
		ace_heat = 0;
		ace_topattack = 0;
	};
	class B_30mm_HE;
	class B_30x113mm_M789_HEDP: B_30mm_HE
	{
		ace_heat = 1;
	};
	class Grenadecore;
	class GrenadeBase: Grenadecore
	{
		ace_incendiary = 0.5;
		ace_tandemheat = 0;
		ace_heat = 0;
		ace_topattack = 0;
	};
	class G_40mm_HE;
	class ACE_M430Round: G_40mm_HE
	{
		ace_heat = 1;
	};
	class Grenade: Default
	{
		ace_incendiary = 0;
		ace_tandemheat = 0;
		ace_heat = 0;
		ace_topattack = 0;
	};
	class RocketCore;
	class RocketBase: RocketCore
	{
		ace_incendiary = 1;
		ace_tandemheat = 0;
		ace_heat = 1;
		ace_topattack = 0;
	};
	class R_SMAW_HEDP: RocketBase{};
	class R_SMAW_HEAA: R_SMAW_HEDP{};
	class R_MEEWS_HEDP: R_SMAW_HEDP{};
	class ACE_R_MEEWS_HE: R_MEEWS_HEDP
	{
		ace_heat = 0;
	};
	class R_MEEWS_HEAT: R_SMAW_HEAA
	{
		ace_tandemheat = 1;
	};
	class R_PG7V_AT;
	class R_PG7VR_AT: R_PG7V_AT
	{
		ace_tandemheat = 1;
	};
	class R_OG7_AT: R_PG7V_AT
	{
		ace_incendiary = 0;
		ace_heat = 0;
	};
	class R_Hydra_HE: RocketBase
	{
		ace_incendiary = 0;
		ace_heat = 0;
	};
	class R_57mm_HE: RocketBase
	{
		ace_incendiary = 0;
		ace_heat = 0;
	};
	class R_80mm_HE: RocketBase
	{
		ace_incendiary = 0;
		ace_heat = 1;
	};
	class R_S8T_AT: RocketBase
	{
		ace_incendiary = 0;
		ace_heat = 1;
		ace_tandemheat = 1;
	};
	class R_PG9_AT;
	class R_OG9_HE: R_PG9_AT
	{
		ace_incendiary = 0;
		ace_heat = 0;
	};
	class ARTY_SADARM_PROJO: RocketBase
	{
		ace_topattack = 1;
	};
	class MissileCore;
	class MissileBase: MissileCore
	{
		ace_incendiary = 1;
		ace_tandemheat = 1;
		ace_heat = 1;
		ace_aa = 0;
		ace_topattack = 0;
		ace_sys_vehicledamage_wire = 1;
		ace_sys_vehicledamage_laser = 0;
		ace_sys_vehicledamage_ir = 0;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_Stinger_AA: MissileBase
	{
		ace_aa = 1;
		ace_sys_vehicledamage_wire = 0;
		ace_sys_vehicledamage_laser = 0;
		ace_sys_vehicledamage_ir = 1;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_Sidewinder_AA: MissileBase
	{
		ace_aa = 1;
		ace_sys_vehicledamage_wire = 0;
		ace_sys_vehicledamage_laser = 0;
		ace_sys_vehicledamage_ir = 1;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_Strela_AA: MissileBase
	{
		ace_aa = 1;
		ace_sys_vehicledamage_wire = 0;
		ace_sys_vehicledamage_laser = 0;
		ace_sys_vehicledamage_ir = 1;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_R73_AA: MissileBase
	{
		ace_aa = 1;
		ace_sys_vehicledamage_wire = 0;
		ace_sys_vehicledamage_laser = 0;
		ace_sys_vehicledamage_ir = 1;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_9M311_AA: MissileBase
	{
		ace_aa = 1;
		ace_sys_vehicledamage_wire = 0;
		ace_sys_vehicledamage_laser = 0;
		ace_sys_vehicledamage_ir = 1;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_AT2_AT: MissileBase
	{
		ace_tandemheat = 0;
	};
	class M_Javelin_AT: MissileBase
	{
		ace_topattack = 1;
		ace_sys_vehicledamage_wire = 0;
		ace_sys_vehicledamage_laser = 0;
		ace_sys_vehicledamage_ir = 1;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_NLAW_AT: MissileBase
	{
		ace_sys_vehicledamage_wire = 0;
		ace_tandemheat = 0;
		ace_topattack = 1;
	};
	class BombCore: Default
	{
		ace_incendiary = 0.1;
		ace_tandemheat = 0;
		ace_topattack = 0;
		ace_heat = 0;
	};
	class TimeBombCore;
	class MineCore;
	class Mine: MineCore
	{
		ace_incendiary = 0.1;
		ace_tandemheat = 1;
		ace_minetype = 1;
		ace_heat = 0;
	};
	class TimeBomb: TimeBombCore
	{
		ace_incendiary = 0.1;
		ace_tandemheat = 1;
		ace_minetype = 0;
		ace_heat = 0;
	};
	class FuelExplosion: Default
	{
		ace_incendiary = 0.1;
		ace_tandemheat = 0;
		ace_heat = 0;
		ace_topattack = 0;
	};
	class M_TOW_AT: MissileBase
	{
		ace_tandemheat = 0;
	};
	class M_TOW2_AT: M_TOW_AT
	{
		ace_tandemheat = 1;
	};
	class M_Hellfire_AT: MissileBase
	{
		ace_topattack = 1;
		ace_sys_vehicledamage_wire = 0;
		ace_sys_vehicledamage_laser = 1;
		ace_sys_vehicledamage_ir = 0;
		ace_sys_vehicledamage_radio = 0;
	};
	class M_AT5_AT: MissileBase
	{
		ace_tandemheat = 0;
	};
	class M_AT10_AT: MissileBase{};
	class M_AT11_AT: M_AT10_AT{};
	class M_AT13_AT: M_AT5_AT
	{
		ace_tandemheat = 1;
	};
	class ACE_M_AT13_TB: M_AT13_AT
	{
		ace_tandemheat = 0;
		ace_incendiary = 1;
	};
	class ACE_9M119: M_AT11_AT
	{
		ace_tandemheat = 0;
	};
	class M_AT6_AT: MissileBase
	{
		ace_tandemheat = 0;
	};
	class M_AT9_AT: M_AT6_AT
	{
		ace_tandemheat = 1;
	};
	class M_CRV7_HEPD;
	class M_CRV7_FAT: M_CRV7_HEPD
	{
		ace_incendiary = 1;
		ace_heat = 1;
	};
	class M_CRV7_AT: M_Hellfire_AT
	{
		ace_tandemheat = 0;
	};
	class ShellCore;
	class ShellBase: ShellCore
	{
		ace_incendiary = 1;
		ace_tandemheat = 0;
		ace_heat = 1;
		ace_topattack = 0;
		ace_hit_distance = 1000;
	};
	class Sh_125_HE: ShellBase
	{
		ace_incendiary = 0.3;
		ace_tandemheat = 0;
	};
	class Sh_125_SABOT;
	class ACE_3BK29Round: Sh_125_SABOT
	{
		ace_tandemheat = 1;
	};
	class Sh_85_HE: ShellBase
	{
		ace_incendiary = 0.3;
		ace_tandemheat = 0;
	};
	class Sh_105_HE: ShellBase
	{
		ace_incendiary = 0.3;
		ace_tandemheat = 0;
	};
	class Sh_122_HE: ShellBase
	{
		ace_incendiary = 0.3;
		ace_tandemheat = 0;
	};
	class ARTY_Sh_Base: ShellBase
	{
		ace_topattack = 1;
	};
	class ACE_AA_explosion: G_40mm_HE
	{
		hit = 50;
		indirecthit = 75;
		indirecthitrange = 15;
		explosiontime = 0.05;
		fusedistance = 0;
		ace_aa = 1;
	};
	class Sh_40_HE: BulletBase
	{
		ace_heat = 1;
		ace_incendiary = 1;
	};
	class Sh_40_SABOT: Sh_40_HE
	{
		ace_heat = 0;
	};
	class Sh_81_HE: ShellBase
	{
		ace_topattack = 1;
	};
	class Sh_82_HE: ShellBase
	{
		ace_topattack = 1;
	};
	class ACE_cookoff_large_1_normal: ShellBase
	{
		hit = 1;
		indirectHit = 20;
		indirectHitRange = 2;
		typicalSpeed = 100;
		explosive = 1;
		cost = 300;
		model = "\ca\weapons\empty";
		airFriction = 0;
		timeToLive = 1;
		explosionTime = 0.0001;
		soundFly[] = {"",1,1};
		soundEngine[] = {"",1,4};
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ExploAmmoExplosion";
		muzzleEffect = "BIS_Effects_Rifle";
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close.wss",56.23413,1,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close.wss",56.2341,1,1800};
		hitGroundSoft[] = {"soundDefault1",1};
		hitGroundHard[] = {"soundDefault1",1};
		hitMan[] = {"soundDefault1",1};
		hitArmor[] = {"soundDefault1",1};
		hitIron[] = {"soundDefault1",1};
		hitBuilding[] = {"soundDefault1",1};
		hitFoliage[] = {"soundDefault1",1};
		hitWood[] = {"soundDefault1",1};
		hitGlass[] = {"soundDefault1",1};
		hitGlassArmored[] = {"soundDefault1",1};
		hitConcrete[] = {"soundDefault1",1};
		hitRubber[] = {"soundDefault1",1};
		hitPlastic[] = {"soundDefault1",1};
		hitDefault[] = {"soundDefault1",1};
		hitMetal[] = {"soundDefault1",1};
		hitMetalplate[] = {"soundDefault1",1};
	};
	class ACE_cookoff_large_1_filtered: ACE_cookoff_large_1_normal
	{
		CraterEffects = "";
		explosionEffects = "";
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close_filtered.wss",56.23413,1.2,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close_filtered.wss",56.2341,1.2,1800};
	};
	class ACE_cookoff_large_2_normal: ACE_cookoff_large_1_normal
	{
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close.wss",56.23413,1.2,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close.wss",56.2341,1.2,1800};
	};
	class ACE_cookoff_large_2_filtered: ACE_cookoff_large_1_filtered
	{
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close_filtered.wss",56.23413,1.2,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close_filtered.wss",56.2341,1.2,1800};
	};
	class ACE_cookoff_large_3_normal: ACE_cookoff_large_1_normal
	{
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close.wss",56.23413,0.9,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close.wss",56.2341,0.9,1800};
	};
	class ACE_cookoff_large_3_filtered: ACE_cookoff_large_1_filtered
	{
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close_filtered.wss",56.23413,0.9,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\cannon_crack_close_filtered.wss",56.2341,0.9,1800};
	};
	class ACE_cookoff_small_1_normal: ACE_cookoff_large_1_normal
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close.wss",56.23413,1,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close.wss",56.2341,1,1800};
	};
	class ACE_cookoff_small_1_filtered: ACE_cookoff_large_1_filtered
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close_filtered.wss",56.23413,1,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close_filtered.wss",56.2341,1,1800};
	};
	class ACE_cookoff_small_2_normal: ACE_cookoff_large_1_normal
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close.wss",56.23413,1,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close.wss",56.2341,1,1800};
	};
	class ACE_cookoff_small_2_filtered: ACE_cookoff_large_1_filtered
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close_filtered.wss",56.23413,1,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close_filtered.wss",56.2341,1,1800};
	};
	class ACE_cookoff_small_3_normal: ACE_cookoff_large_1_normal
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close.wss",56.23413,1.2,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close.wss",56.2341,1.2,1800};
	};
	class ACE_cookoff_small_3_filtered: ACE_cookoff_large_1_filtered
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close_filtered.wss",56.23413,1.2,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\heavy_crack_close_filtered.wss",56.2341,1.2,1800};
	};
	class ACE_cookoff_small_4_normal: ACE_cookoff_large_1_normal
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close.wss",56.23413,1.5,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close.wss",56.2341,1.5,1800};
	};
	class ACE_cookoff_small_4_filtered: ACE_cookoff_large_1_filtered
	{
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close_filtered.wss",56.23413,1.5,1800};
		soundDefault1[] = {"\x\ace\addons\sys_vehicledamage\sound\light_crack_close_filtered.wss",56.2341,1.5,1800};
	};
};
class CfgSounds
{
	class ace_tankpenetration
	{
		name = "ace_tankpenetration";
		sound[] = {"\ca\weapons\data\sound\explosion_big_12_vehicle_A.wss",10,1};
		titles[] = {};
	};
	class ace_penetration_mediumcal_1
	{
		name = "ace_penetration_mediumcal_1";
		sound[] = {"\x\ace\addons\sys_vehicledamage\sound\ap_hit_veh1.wss",10,1};
		titles[] = {};
	};
	class ace_penetration_mediumcal_2
	{
		name = "ace_penetration_mediumcal_2";
		sound[] = {"\x\ace\addons\sys_vehicledamage\sound\ap_hit_veh2.wss",10,1};
		titles[] = {};
	};
	class ace_penetration_mediumcal_3
	{
		name = "ace_penetration_mediumcal_3";
		sound[] = {"\x\ace\addons\sys_vehicledamage\sound\ap_hit_veh3.wss",10,1};
		titles[] = {};
	};
};
class RscTitles
{
	class ace_burn_indicator_1
	{
		idd = 585306;
		movingEnable = "true";
		duration = 0.1;
		fadein = 0.15;
		fadeout = 0.75;
		name = "ace_burn_indicator_1";
		onload = "with uiNamespace do {ace_burn_indicator_1 = _this select 0}";
		class controls
		{
			class ace_burn_indicator_1_control
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.6};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "SafeZoneX";
				y = "SafeZoneY";
				w = "SafeZoneW + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_vehicledamage\data\overlay_burn_1.paa";
			};
		};
	};
	class ace_burn_indicator_2: ace_burn_indicator_1
	{
		idd = 585307;
		name = "ace_burn_indicator_2";
		onload = "with uiNamespace do {ace_burn_indicator_2 = _this select 0}";
		class controls: controls
		{
			class ace_burn_indicator_2_control: ace_burn_indicator_1_control
			{
				text = "\x\ace\addons\sys_vehicledamage\data\overlay_burn_2.paa";
			};
		};
	};
};
class CfgFunctions
{
	class ACE
	{
		class Vehicledamage
		{
			class setVehicleDamage
			{
				description = "Apply damage to a vehicle in a fashion compatable with ACE vehicle damage system. Must be called from machine where target vehicle is local.";
				file = "\x\ace\Addons\sys_vehicledamage\fnc_setVehicleDamage.sqf";
			};
		};
	};
};
//};
