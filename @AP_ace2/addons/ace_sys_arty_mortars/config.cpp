////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:40 2013 : Created on Mon Oct 14 23:06:40 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_arty_mortars : config.bin{
class CfgPatches
{
	class ace_sys_arty_mortars
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","ace_sys_arty","ace_main","ace_sys_crewserved","ace_sys_interaction"};
		version = "1.14.0.597";
		versionStr = "1.14.0.597";
		versionAr[] = {1,14,0,597};
		author[] = {"Falcone","Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_arty_mortars
		{
			list[] = {"ace_sys_arty_mortars"};
		};
	};
};
class CfgWeapons
{
	class CannonCore;
	class ace_arty_m224: CannonCore
	{
		magazineReloadTime = 0.5;
		dispersion = 0.0071428;
		reloadTime = 0.5;
		magazines[] = {"ace_arty_60mm_m720a1_m734_pd_chg0","ace_arty_60mm_m720a1_m734_pd_chg1","ace_arty_60mm_m720a1_m734_pd_chg2","ace_arty_60mm_m720a1_m734_pd_chg3","ace_arty_60mm_m720a1_m734_pd_chg4","ace_arty_60mm_m720a1_m734_prox_chg0","ace_arty_60mm_m720a1_m734_prox_chg1","ace_arty_60mm_m720a1_m734_prox_chg2","ace_arty_60mm_m720a1_m734_prox_chg3","ace_arty_60mm_m720a1_m734_prox_chg4","ace_arty_60mm_m720a1_m734_nsb_chg0","ace_arty_60mm_m720a1_m734_nsb_chg1","ace_arty_60mm_m720a1_m734_nsb_chg2","ace_arty_60mm_m720a1_m734_nsb_chg3","ace_arty_60mm_m720a1_m734_nsb_chg4","ace_arty_60mm_m720a1_m734_delay_chg0","ace_arty_60mm_m720a1_m734_delay_chg1","ace_arty_60mm_m720a1_m734_delay_chg2","ace_arty_60mm_m720a1_m734_delay_chg3","ace_arty_60mm_m720a1_m734_delay_chg4","ace_arty_60mm_m721_m776_time_chg0","ace_arty_60mm_m721_m776_time_chg1","ace_arty_60mm_m721_m776_time_chg2","ace_arty_60mm_m721_m776_time_chg3","ace_arty_60mm_m721_m776_time_chg4","ace_arty_60mm_m722a1_m745_pd_chg0","ace_arty_60mm_m722a1_m745_pd_chg1","ace_arty_60mm_m722a1_m745_pd_chg2","ace_arty_60mm_m722a1_m745_pd_chg3","ace_arty_60mm_m722a1_m745_pd_chg4"};
		scope = 1;
		displayName = "M224";
		nameSound = "cannon";
		cursor = "Missile";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursorSize = 1;
		begin1[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\60mm_1","db+27",1,300};
		begin2[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\60mm_1","db+25",1.3,300};
		soundBegin[] = {"begin1",0.5,"begin2",0.5};
		reloadSound[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\mortar_load_long",3,1,12};
		soundServo[] = {"",0.0001,1};
		autoReload = 0;
		backgroundReload = 0;
		ballisticsComputer = 0;
		canLock = 0;
	};
	class ace_arty_m252: ace_arty_m224
	{
		displayName = "M252";
		magazines[] = {"ace_arty_81mm_m821a2_m734_pd_chg0","ace_arty_81mm_m821a2_m734_pd_chg1","ace_arty_81mm_m821a2_m734_pd_chg2","ace_arty_81mm_m821a2_m734_pd_chg3","ace_arty_81mm_m821a2_m734_pd_chg4","ace_arty_81mm_m821a2_m734_prox_chg0","ace_arty_81mm_m821a2_m734_prox_chg1","ace_arty_81mm_m821a2_m734_prox_chg2","ace_arty_81mm_m821a2_m734_prox_chg3","ace_arty_81mm_m821a2_m734_prox_chg4","ace_arty_81mm_m821a2_m734_nsb_chg0","ace_arty_81mm_m821a2_m734_nsb_chg1","ace_arty_81mm_m821a2_m734_nsb_chg2","ace_arty_81mm_m821a2_m734_nsb_chg3","ace_arty_81mm_m821a2_m734_nsb_chg4","ace_arty_81mm_m821a2_m734_delay_chg0","ace_arty_81mm_m821a2_m734_delay_chg1","ace_arty_81mm_m821a2_m734_delay_chg2","ace_arty_81mm_m821a2_m734_delay_chg3","ace_arty_81mm_m821a2_m734_delay_chg4","ace_arty_81mm_m853a1_m772_time_chg0","ace_arty_81mm_m853a1_m772_time_chg1","ace_arty_81mm_m853a1_m772_time_chg2","ace_arty_81mm_m853a1_m772_time_chg3","ace_arty_81mm_m853a1_m772_time_chg4","ace_arty_81mm_m375a3_m524_pd_chg0","ace_arty_81mm_m375a3_m524_pd_chg1","ace_arty_81mm_m375a3_m524_pd_chg2","ace_arty_81mm_m375a3_m524_pd_chg3","ace_arty_81mm_m375a3_m524_pd_chg4"};
		begin1[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\ace_mortar_fire","db+27",1.1,600};
		begin2[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\ace_mortar_fire","db+27",1.03,600};
		begin3[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\ace_mortar_fire","db+26",1.01,600};
		begin4[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\ace_mortar_fire","db+25",1.09,600};
		soundBegin[] = {"begin1",0.25,"begin2",0.25,"begin3",0.25,"begin4",0.25};
		reloadSound[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\mortar_load_short",3,1,8};
		dispersion = 0.018867;
	};
	class ace_arty_2b14: ace_arty_m252
	{
		displayName = "2B14";
		magazines[] = {"ace_arty_82mm_he_pd_chg0","ace_arty_82mm_he_pd_chg1","ace_arty_82mm_he_pd_chg2","ace_arty_82mm_he_pd_chg3","ace_arty_82mm_he_pd_chg4","ace_arty_82mm_he_pd_chg5","ace_arty_82mm_he_pd_chg6","ace_arty_82mm_illum_time_chg0","ace_arty_82mm_illum_time_chg1","ace_arty_82mm_illum_time_chg2","ace_arty_82mm_illum_time_chg3","ace_arty_82mm_wp_pd_chg0","ace_arty_82mm_wp_pd_chg1","ace_arty_82mm_wp_pd_chg2","ace_arty_82mm_wp_pd_chg3"};
		reloadSound[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\mortar_load_long",1.12202,1,12};
	};
	class ace_arty_120tampella: ace_arty_m252
	{
		displayName = "120mm Tampella";
		magazines[] = {"ace_arty_120mm_dm11a5_dm111a1_pd_chg0","ace_arty_120mm_dm11a5_dm111a1_pd_chg1","ace_arty_120mm_dm11a5_dm111a1_pd_chg2","ace_arty_120mm_dm11a5_dm111a1_pd_chg3","ace_arty_120mm_dm11a5_dm111a1_pd_chg4","ace_arty_120mm_dm61_ppd_prox_chg0","ace_arty_120mm_dm61_ppd_prox_chg1","ace_arty_120mm_dm61_ppd_prox_chg2","ace_arty_120mm_dm61_ppd_prox_chg3","ace_arty_120mm_dm61_ppd_prox_chg4","ace_arty_120mm_dm26_dm93_time_chg0","ace_arty_120mm_dm26_dm93_time_chg1","ace_arty_120mm_dm26_dm93_time_chg2","ace_arty_120mm_dm26_dm93_time_chg3","ace_arty_120mm_dm26_dm93_time_chg4","ace_arty_120mm_dm35_dm93_time_chg0","ace_arty_120mm_dm35_dm93_time_chg1","ace_arty_120mm_dm35_dm93_time_chg2","ace_arty_120mm_dm35_dm93_time_chg3","ace_arty_120mm_dm35_dm93_time_chg4"};
		begin1[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\120mm_1",216.228,1,800};
		begin2[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\120mm_2",216.228,1,800};
		begin3[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\120mm_5",216.228,1,800};
		begin4[] = {"\x\ace\addons\sys_arty_mortars\data\sounds\120mm_6",216.228,1,800};
		soundBegin[] = {"begin1",0.25,"begin2",0.25,"begin3",0.25,"begin4",0.25};
		dispersion = 0.01863;
	};
};
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class ACE;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED;
		};
	};
	class StaticMortar: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
		class ACE: ACE
		{
			class ACE_ARTY
			{
				shiftingSpeed[] = {5,20};
			};
		};
	};
	class M252: StaticMortar{};
	class M252_Base: M252{};
	class M252_US_EP1: M252_Base{};
	class ACE_M252: M252_US_EP1
	{
		scope = 2;
		model = "\x\ace\addons\sys_arty_mortars\ACE_M252.p3d";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ace_arty_m252"};
				magazines[] = {};
				gunnerOpticsModel = "\x\ace\addons\sys_arty_mortars\SightUnit";
				soundServo[] = {"",0.0001,1};
				class ViewOptics: ViewOptics
				{
					initFov = 0.0787019;
					minFov = 0.0787019;
					maxFov = 0.0787019;
				};
			};
		};
		vehicleClass = "ACE_Howitzers";
		ACE_ARTY_ISARTY = 1;
		ACE_ARTY_RECOIL = "\x\ace\addons\sys_arty_mortars\fnc_recoil.sqf";
		ACE_ARTY_SETUP_OFFSETPOS[] = {-0.135498,0.214844,0};
		ACE_ARTY_SETUP_OFFSET_STAKEANGLE = -0.55;
		artilleryScanner = 0;
		ARTY_IsArtyVehicle = 0;
		transportMaxWeapons = 1;
		transportSoldier = 0;
		class TransportWeapons
		{
			class _xx_ace_arty_rangeTable_m252
			{
				weapon = "ace_arty_rangeTable_m252";
				count = 1;
			};
		};
		reversed = 1;
		class AnimationSources
		{
			class MainTurret
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
				minValue = -6400;
				maxValue = 6400;
			};
			class MainTurret_RotateFast: MainTurret
			{
				animPeriod = 0.0001;
			};
			class MainGun
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1100;
				minValue = 800;
				maxValue = 1511;
			};
			class OpticElevate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1100;
				minValue = 800;
				maxValue = 1511;
			};
			class OpticRevolve
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
				minValue = -200;
				maxValue = 200;
			};
		};
		class ACE: ACE
		{
			class ACE_ARTY: ACE_ARTY
			{
				shiftingSpeed[] = {5,20};
			};
		};
		ACE_Weight = 41.3;
	};
	class ACE_M224: M252_US_EP1{};
	class ACE_M224_1: ACE_M224
	{
		scope = 2;
		model = "\x\ace\addons\sys_arty_mortars\ACE_M224.p3d";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ace_arty_m224"};
				magazines[] = {};
				gunnerOpticsModel = "\x\ace\addons\sys_arty_mortars\SightUnit";
				soundServo[] = {"",0.0001,1};
				class ViewOptics: ViewOptics
				{
					initFov = 0.0787019;
					minFov = 0.0787019;
					maxFov = 0.0787019;
				};
			};
		};
		vehicleClass = "ACE_Howitzers";
		ACE_ARTY_ISARTY = 1;
		ACE_ARTY_RECOIL = "\x\ace\addons\sys_arty_mortars\fnc_recoil.sqf";
		ACE_ARTY_SETUP_OFFSETPOS[] = {-0.135498,0.214844,0};
		ACE_ARTY_SETUP_OFFSET_STAKEANGLE = 0.37;
		artilleryScanner = 0;
		ARTY_IsArtyVehicle = 0;
		transportMaxWeapons = 1;
		transportSoldier = 0;
		class TransportWeapons
		{
			class _xx_ace_arty_rangeTable_m224
			{
				weapon = "ace_arty_rangeTable_m224";
				count = 1;
			};
		};
		reversed = 1;
		class AnimationSources
		{
			class MainTurret
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
				minValue = -6400;
				maxValue = 6400;
			};
			class MainTurret_RotateFast: MainTurret
			{
				animPeriod = 0.0001;
			};
			class MainGun
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1100;
				minValue = 800;
				maxValue = 1511;
			};
			class OpticElevate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1100;
				minValue = 800;
				maxValue = 1511;
			};
			class OpticRevolve
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
				minValue = -200;
				maxValue = 200;
			};
		};
		class ACE: ACE
		{
			class ACE_ARTY: ACE_ARTY
			{
				shiftingSpeed[] = {5,30};
			};
		};
		ACE_Weight = 21.1;
	};
	class 2b14_82mm: StaticMortar{};
	class 2b14_82mm_base: 2b14_82mm{};
	class 2b14_82mm_TK_GUE_EP1: 2b14_82mm_base{};
	class ACE_2b14_82mm: 2b14_82mm_TK_GUE_EP1
	{
		scope = 2;
		model = "\x\ace\addons\sys_arty_mortars\ACE_2B14.p3d";
		class Turrets: Turrets
		{
			class Mainturret: MainTurret
			{
				weapons[] = {"ace_arty_2b14"};
				magazines[] = {};
				gunnerOpticsModel = "\x\ace\addons\sys_arty_mortars\SightUnit";
				soundServo[] = {"",0.0001,1};
				class ViewOptics: ViewOptics
				{
					initFov = 0.0787019;
					minFov = 0.0787019;
					maxFov = 0.0787019;
				};
			};
		};
		vehicleClass = "ACE_Howitzers";
		ACE_ARTY_ISARTY = 1;
		ACE_ARTY_RECOIL = "\x\ace\addons\sys_arty_mortars\fnc_recoil.sqf";
		ACE_ARTY_SETUP_OFFSETPOS[] = {-0.135498,0.214844,0};
		ACE_ARTY_SETUP_OFFSET_STAKEANGLE = -0.55;
		artilleryScanner = 0;
		ARTY_IsArtyVehicle = 0;
		transportMaxWeapons = 1;
		transportSoldier = 0;
		class TransportWeapons
		{
			class _xx_ace_arty_rangeTable_2b14
			{
				weapon = "ace_arty_rangeTable_2b14";
				count = 1;
			};
		};
		reversed = 1;
		class AnimationSources
		{
			class MainTurret
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
				minValue = -6400;
				maxValue = 6400;
			};
			class MainTurret_RotateFast: MainTurret
			{
				animPeriod = 0.0001;
			};
			class MainGun
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1100;
				minValue = 800;
				maxValue = 1511;
			};
			class OpticElevate
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 1100;
				minValue = 800;
				maxValue = 1511;
			};
			class OpticRevolve
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
				minValue = -200;
				maxValue = 200;
			};
		};
		class ACE: ACE
		{
			class ACE_ARTY: ACE_ARTY
			{
				shiftingSpeed[] = {5,20};
			};
		};
		ACE_Weight = 41.88;
	};
	class ACE_120Tampella: ACE_M252
	{
		displayName = "120mm Tampella";
		model = "\x\ace\addons\sys_arty_mortars\ACE_120_TAMPELLA.p3d";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ace_arty_120tampella"};
				gunnerOpticsModel = "\x\ace\addons\sys_arty_mortars\SightUnit";
				class ViewOptics: ViewOptics
				{
					initFov = 0.0787019;
					minFov = 0.0787019;
					maxFov = 0.0787019;
				};
			};
		};
		class TransportWeapons
		{
			class _xx_ace_arty_rangeTable_m252
			{
				weapon = "ace_arty_rangeTable_tampella";
				count = 1;
			};
		};
		ACE_Weight = 151.2;
		ACE_ARTY_SETUP_OFFSETPOS[] = {-0.135498,0.214844,0};
		ACE_ARTY_SETUP_OFFSET_STAKEANGLE = -0.55;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				disassemblyType = "parts";
				weaponProxy = "ACE_120Tampella_Barrel";
				tripod = "ACE_120Tampella_Baseplate";
				canDrag = 0;
			};
			class ACE_ARTY: ACE_ARTY
			{
				shiftingSpeed[] = {5,20};
			};
		};
	};
	class ACE_120Tampella_Barrel: ACE_120Tampella
	{
		scope = 1;
		armor = 10000;
		displayName = "120mm Tampella Barrel";
		model = "\x\ace\addons\sys_arty_mortars\ACE_120_Tampella_Barrel.p3d";
		class TransportWeapons{};
		class TransportMagazines{};
		transportMaxWeapons = 0;
		transportMaxMagazines = 0;
		ACE_Weight = 86.8;
		class Turrets{};
		hasGunner = 0;
		hssDriver = 0;
		hasCommander = 0;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
				canCarry = 1;
			};
		};
		attachPosFront[] = {0,-2.1,0.8};
		attachPosRear[] = {0,-2.5,0};
	};
	class ACE_120Tampella_Baseplate: ACE_120Tampella
	{
		scope = 1;
		armor = 10000;
		displayName = "120mm Tampella Baseplate";
		model = "\x\ace\addons\sys_arty_mortars\ACE_120_Tampella_Baseplate.p3d";
		class TransportWeapons{};
		class TransportMagazines{};
		transportMaxWeapons = 0;
		transportMaxMagazines = 0;
		class Turrets{};
		hasGunner = 0;
		hssDriver = 0;
		hasCommander = 0;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
				canCarry = 1;
			};
		};
		ACE_Weight = 64;
		attachPosFront[] = {0,-0.6,0.8};
		attachPosRear[] = {0,-1.3,0};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_arty_mortars
	{
		init = "call ('\x\ace\addons\sys_arty_mortars\XEH_pre_init.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_arty_mortars
	{
		clientInit = "call ('\x\ace\addons\sys_arty_mortars\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class ACE_M252
	{
		class ace_sys_arty_mortars
		{
			init = "call ('\x\ace\addons\sys_arty_mortars\XEH_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
	class ACE_M224_1
	{
		class ace_sys_arty_mortars
		{
			init = "call ('\x\ace\addons\sys_arty_mortars\XEH_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
	class ACE_2b14_82mm
	{
		class ace_sys_arty_mortars
		{
			init = "call ('\x\ace\addons\sys_arty_mortars\XEH_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
	class ACE_120Tampella
	{
		class ace_sys_arty_mortars
		{
			init = "call ('\x\ace\addons\sys_arty_mortars\XEH_init.sqf' call SLX_XEH_COMPILE)";
			exclude[] = {"ACE_120Tampella_Barrel","ACE_120Tampella_Baseplate"};
		};
	};
};
class Extended_GetIn_Eventhandlers
{
	class ACE_M252
	{
		clientGetin = "_this call ace_sys_arty_mortars_fnc_XEH_getin";
	};
	class ACE_M224_1
	{
		clientGetin = "_this call ace_sys_arty_mortars_fnc_XEH_getin";
	};
	class ACE_2b14_82mm
	{
		clientGetin = "_this call ace_sys_arty_mortars_fnc_XEH_getin";
	};
	class ACE_120Tampella
	{
		clientGetin = "_this call ace_sys_arty_mortars_fnc_XEH_getin";
	};
};
class Extended_GetOut_Eventhandlers
{
	class ACE_M252
	{
		clientGetout = "_this call ace_sys_arty_mortars_fnc_XEH_getout";
	};
	class ACE_M224_1
	{
		clientGetout = "_this call ace_sys_arty_mortars_fnc_XEH_getout";
	};
	class ACE_2b14_82mm
	{
		clientGetout = "_this call ace_sys_arty_mortars_fnc_XEH_getout";
	};
	class ACE_120Tampella
	{
		clientGetout = "_this call ace_sys_arty_mortars_fnc_XEH_getout";
	};
};
class CfgAceArtyBatteryType
{
	class M224
	{
		name = "M224 60mm Mortar";
		type = "cannon";
		caliber = 60;
		ammunition[] = {"ace_arty_60mm_m720a1","ace_arty_60mm_m721","ace_arty_60mm_m722a1"};
		weaponClass = "ace_arty_m224";
	};
	class M252
	{
		name = "M252 81mm Mortar";
		type = "cannon";
		caliber = 81;
		ammunition[] = {"ace_arty_81mm_m821a2","ace_arty_81mm_m853a1","ace_arty_81mm_m375a3"};
		weaponClass = "ace_arty_m252";
	};
	class Tampella
	{
		name = "Tampella 120mm Mortar";
		type = "cannon";
		caliber = 120;
		ammunition[] = {"ace_arty_120mm_dm11a5","ace_arty_120mm_dm61","ace_arty_120mm_dm26","ace_arty_120mm_dm35"};
		weaponClass = "ace_arty_120tampella";
	};
	class 2B14
	{
		name = "2B14 82mm Mortar";
		type = "cannon";
		caliber = 82;
		ammunition[] = {"ace_arty_82mm_he","ace_arty_82mm_illum","ace_arty_82mm_wp"};
		weaponClass = "ace_arty_2b14";
	};
};
class ace_sys_arty_mortars_m137_RscText
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
class ace_sys_arty_mortars_m137_RscButton
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
class ace_sys_arty_mortars_m137_RscPicture: ace_sys_arty_mortars_m137_RscButton
{
	type = 0;
	idc = -1;
	style = 48;
	text = "";
};
class ace_sys_arty_mortars_dialog
{
	idd = 137137;
	MovingEnable = 0;
	onLoad = "[] spawn ace_sys_arty_mortars_fnc_m137_monitorSight";
	onUnload = "[] spawn ace_sys_arty_mortars_fnc_m137_stopMonitorSight";
	controlsBackground[] = {};
	objects[] = {};
	onKeyDown = "_this call ace_sys_arty_mortars_fnc_m137_keyDown";
	onKeyUp = "_this call ace_sys_arty_mortars_fnc_m137_keyUp";
	class controls
	{
		class ace_sys_arty_mortars_m137Background: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			h = "0.6 * safeZoneH";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "";
		};
		class ace_sys_arty_mortars_m137Title: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Sight Unit";
		};
		class ace_sys_arty_mortars_m137AzimuthLabel: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.035 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Azimuth:";
		};
		class ace_sys_arty_mortars_m137Azimuth: ace_sys_arty_mortars_m137_RscText
		{
			idc = 137001;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.035 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "0000";
		};
		class ace_sys_arty_mortars_m137DeflectionLabel: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.07 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Deflection:";
		};
		class ace_sys_arty_mortars_m137Deflection: ace_sys_arty_mortars_m137_RscText
		{
			idc = 137002;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.07 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "3200";
		};
		class ace_sys_arty_mortars_m187title: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.105 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Sight Mount";
		};
		class ace_sys_arty_mortars_m137ElevationLabel: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.140 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Elevation:";
		};
		class ace_sys_arty_mortars_m137Elevation: ace_sys_arty_mortars_m137_RscText
		{
			idc = 137003;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.140 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "0300";
		};
		class ace_sys_arty_mortars_m137ElevationBubbleLabel: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.175 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Level:";
		};
		class ace_sys_arty_mortars_m137ElevationBubble: ace_sys_arty_mortars_m137_RscText
		{
			idc = 137004;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.175 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "|---|+|---|";
		};
		class ace_sys_arty_mortars_OpticElevationBubbleLabel: ace_sys_arty_mortars_m137ElevationBubbleLabel
		{
			y = "(0.1925 * safeZoneH) + safeZoneY";
			text = "Optic Level:";
		};
		class ace_sys_arty_mortars_OpticElevationBubble: ace_sys_arty_mortars_m137ElevationBubble
		{
			idc = 137009;
			y = "(0.1925 * safeZoneH) + safeZoneY";
			text = "|---|+|---|";
		};
		class ace_sys_arty_mortars_m137AzimuthLeftButton: ace_sys_arty_mortars_m137_RscButton
		{
			idc = 137004;
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Def. -";
			action = "[-1] call ace_sys_arty_mortars_fnc_m137_adjustAzimuth";
		};
		class ace_sys_arty_mortars_m137AzimuthRightButton: ace_sys_arty_mortars_m137_RscButton
		{
			idc = 137005;
			x = "(0.0625 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Def. +";
			action = "[1] call ace_sys_arty_mortars_fnc_m137_adjustAzimuth";
		};
		class ace_sys_arty_mortars_m137ElevationUpButton: ace_sys_arty_mortars_m137_RscButton
		{
			idc = 137006;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "El +";
			action = "[1] call ace_sys_arty_mortars_fnc_m137_adjustElevation";
		};
		class ace_sys_arty_mortars_m137ElevationDownButton: ace_sys_arty_mortars_m137_RscButton
		{
			idc = 137007;
			x = "(0.1875 * safeZoneW) + safeZoneX";
			y = "(0.210 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "El -";
			action = "[-1] call ace_sys_arty_mortars_fnc_m137_adjustElevation";
		};
		class ace_sys_arty_mortars_m137OpticDownButton: ace_sys_arty_mortars_m137_RscButton
		{
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Op. -";
			action = "[-1] call ace_sys_arty_mortars_fnc_m137_adjustOpticElevation";
		};
		class ace_sys_arty_mortars_m137OpticUpButton: ace_sys_arty_mortars_m137_RscButton
		{
			x = "(0.0625 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Op. +";
			action = "[1] call ace_sys_arty_mortars_fnc_m137_adjustOpticElevation";
		};
		class ace_sys_arty_mortars_m137ResetLeftButton: ace_sys_arty_mortars_m137_RscButton
		{
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Re +";
			action = "[1] call ace_sys_arty_mortars_fnc_m137_adjustReset";
		};
		class ace_sys_arty_mortars_m137ResetRightButton: ace_sys_arty_mortars_m137_RscButton
		{
			x = "(0.1875 * safeZoneW) + safeZoneX";
			y = "(0.245 * safeZoneH) + safeZoneY";
			w = "0.062 * safeZoneW";
			text = "Re -";
			action = "[-1] call ace_sys_arty_mortars_fnc_m137_adjustReset";
		};
		class ace_sys_arty_mortars_m137TraverseIndicatorLabel: ace_sys_arty_mortars_m137_RscText
		{
			x = "(0 * safeZoneW) + safeZoneX";
			y = "(0.280 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "Traverse:";
		};
		class ace_sys_arty_mortars_m137TraverseIndicator: ace_sys_arty_mortars_m137_RscText
		{
			idc = 137008;
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0.280 * safeZoneH) + safeZoneY";
			w = "0.125 * safeZoneW";
			colorBackground[] = {0.5,0.5,0.5,0.25};
			text = "|-----|-----|";
		};
		class ace_sys_arty_mortars_m137ChangeViewButton: ace_sys_arty_mortars_m137_RscButton
		{
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.315 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			text = "Change View";
			action = "[] call ace_sys_arty_mortars_fnc_m137_changeView";
		};
		class ace_sys_arty_mortars_m137LevelGun: ace_sys_arty_mortars_m137_RscButton
		{
			x = "(0.0 * safeZoneW) + safeZoneX";
			y = "(0.350 * safeZoneH) + safeZoneY";
			w = "0.25 * safeZoneW";
			text = "Level Gun";
			action = "[] call ace_sys_arty_mortars_fnc_levelGun";
		};
	};
};
//};
