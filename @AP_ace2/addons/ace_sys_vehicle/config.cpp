////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:08:29 2013 : Created on Mon Oct 14 23:08:29 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_vehicle : config.bin{
class CfgPatches
{
	class ace_sys_vehicle
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_vehicle","ace_sys_a10"};
		version = "1.14.0.597";
		class ACE_Options
		{
			group = "VEH";
			title = " ";
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_vehicle
	{
		init = "call ('\x\ace\addons\sys_vehicle\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_vehicle\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class Air
	{
		class ace_sys_vehicle
		{
			init = "_this call ace_sys_vehicle_fnc_vtol";
			exclude[] = {"BIS_Steerable_Parachute","ParachuteBase"};
		};
	};
	class Mi24_Base
	{
		ace_sys_vehicle_hind_cargo = "_this spawn ace_sys_vehicle_fnc_hind_cargo";
	};
};
class Extended_FiredBis_EventHandlers
{
	class AllVehicles
	{
		class ace_sys_vehicle_gatling_spinup
		{
			firedBis = "_this call ace_sys_vehicle_fnc_gatling_spinup";
		};
	};
	class Tank
	{
		class ace_sys_vehicle_tracer
		{
			clientFiredBis = "if ((_this select 4) isKindOf 'ShellBase') then { _this call ace_sys_vehicle_fnc_tracer}";
		};
		class ace_sys_vehicle_tank_loader
		{
			firedBis = "_this call ace_sys_vehicle_fnc_tank_loader";
		};
	};
	class Mi24_Base
	{
		class ace_sys_vehicle_gatling
		{
			firedBis = "if ((_this select 4) isKindOf 'B_127x108_APHE') then { [_this select 0,'MachineGun_1',0.015] call ace_sys_vehicle_fnc_gatling; _this call ace_sys_vehicle_fnc_shadow_weapon }";
			exclude[] = {"Mi24_P"};
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class Mi24_Base
	{
		ace_sys_vehicle_hind_getin = "if (local (_this select 0) && {(_this select 1) == 'cargo'}) then {_this call ace_sys_vehicle_fnc_hind_getinout}";
	};
	class MMT_base
	{
		ace_sys_vehicle_bicycle_brokenlegs = "if (local (_this select 0)) then {_this spawn ace_sys_vehicle_fnc_bicycle}";
	};
	class Air
	{
		class ace_sys_vehicle_crew
		{
			getIn = "_this call ace_sys_vehicle_fnc_getInCrew";
			exclude[] = {"BIS_Steerable_Parachute","ParachuteBase"};
		};
	};
	class Tank
	{
		class ace_sys_vehicle_crew
		{
			getIn = "_this call ace_sys_vehicle_fnc_getInCrew";
		};
	};
	class Wheeled_APC
	{
		class ace_sys_vehicle_crew
		{
			getIn = "_this call ace_sys_vehicle_fnc_getInCrew";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class Mi24_Base
	{
		ace_sys_vehicle_hind_getout = "if (local (_this select 0) && {(_this select 1) == 'cargo'}) then {_this call ace_sys_vehicle_fnc_hind_getinout}";
	};
	class Air
	{
		class ace_sys_vehicle_crew
		{
			getOut = "_this call ace_sys_vehicle_fnc_getOutCrew";
			exclude[] = {"BIS_Steerable_Parachute","ParachuteBase"};
		};
	};
	class Tank
	{
		class ace_sys_vehicle_crew
		{
			getOut = "_this call ace_sys_vehicle_fnc_getOutCrew";
		};
	};
	class Wheeled_APC
	{
		class ace_sys_vehicle_crew
		{
			getOut = "_this call ace_sys_vehicle_fnc_getOutCrew";
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Default;
	class MGun;
	class CannonCore: Default
	{
		ace_loader_speedup = 1;
	};
	class M134: MGun
	{
		class LowROF: Mode_FullAuto
		{
			reloadTime = 0.06;
			ace_spinup_count = 5;
			ace_spinup_max = 2;
			ace_spindown_time = 1;
		};
		class HighROF: LowROF
		{
			reloadTime = 0.06;
			ace_spinup_count = 10;
			ace_spinup_max = 4;
			ace_spindown_time = 2;
		};
		class close;
		class short;
		class medium;
		class far;
	};
	class TwinM134: M134
	{
		class LowROF: LowROF
		{
			reloadTime = 0.03;
			ace_spinup_count = 10;
			ace_spinup_max = 2;
			ace_spindown_time = 1;
		};
		class HighROF: HighROF
		{
			reloadTime = 0.03;
			ace_spinup_count = 20;
			ace_spinup_max = 4;
			ace_spindown_time = 2;
		};
		class close: close
		{
			reloadTime = 0.03;
			ace_spinup_count = 20;
			ace_spinup_max = 4;
			ace_spindown_time = 2;
		};
		class short: short
		{
			reloadTime = 0.03;
			ace_spinup_count = 20;
			ace_spinup_max = 4;
			ace_spindown_time = 2;
		};
		class medium: medium
		{
			reloadTime = 0.03;
			ace_spinup_count = 10;
			ace_spinup_max = 2;
			ace_spindown_time = 1;
		};
		class far: far
		{
			reloadTime = 0.03;
			ace_spinup_count = 10;
			ace_spinup_max = 2;
			ace_spindown_time = 1;
		};
	};
	class M197: CannonCore
	{
		class manual: CannonCore
		{
			reloadTime = 0.16;
			ace_spinup_count = 2;
			ace_spinup_max = 2;
			ace_spindown_time = 1.5;
		};
	};
	class ACE_GAU19: M197
	{
		class manual: manual
		{
			reloadTime = 0.092;
			ace_spinup_count = 2;
			ace_spinup_max = 2;
			ace_spindown_time = 1.5;
		};
	};
	class YakB: MGun
	{
		ace_shadow_weapon = "ACE_YakB_1SL";
		class manual: MGun
		{
			burst = 1;
			multiplier = 5;
			reloadTime = 0.09;
			ace_spinup_count = 2;
			ace_spinup_max = 1.5;
			ace_spindown_time = 2;
		};
		class close: manual
		{
			burst = 2;
		};
		class short: close
		{
			burst = 4;
		};
		class medium: close
		{
			burst = 4;
		};
		class far: close
		{
			burst = 2;
		};
	};
	class ACE_YakB_1SL: YakB
	{
		ace_shadow_weapon = 0;
		class manual: manual
		{
			ace_spinup_max = 0;
		};
	};
	class M168: CannonCore
	{
		class manual: CannonCore
		{
			reloadTime = 0.08;
			ace_spinup_count = 3;
			ace_spinup_max = 4;
			ace_spindown_time = 1.3;
		};
	};
	class GAU8: CannonCore
	{
		class manual;
	};
	class ACE_GAU8: GAU8
	{
		class burst1: manual
		{
			reloadTime = 0.04;
			ace_spinup_count = 5;
			ace_spinup_max = 4;
			ace_spindown_time = 3;
		};
		class burst2: burst1
		{
			reloadTime = 0.04;
			ace_spinup_max = 4.45;
		};
	};
	class GAU12: CannonCore
	{
		class manual: CannonCore
		{
			reloadtime = 0.016;
			ace_spinup_count = 5;
			ace_spinup_max = 1.2;
			ace_spindown_time = 2;
		};
	};
	class M256: CannonCore
	{
		ace_loader_speedup = 1.5;
		reloadTime = 10.5;
	};
	class D81: CannonCore
	{
		ace_loader_speedup = 1;
	};
	class D10: CannonCore
	{
		ace_loader_speedup = 1;
	};
	class ZiS_S_53: CannonCore
	{
		ace_loader_speedup = 1;
	};
	class ACE_2A28_Base: CannonCore
	{
		ace_loader_speedup = 1;
	};
	class RocketPods;
	class SPG9: RocketPods
	{
		ace_loader_speedup = 1;
	};
};
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class AnimationSources;
	};
	class Mi24_Base: Helicopter
	{
		class AnimationSources: AnimationSources
		{
			class Gatling_1
			{
				animPeriod = 60;
				initphase = 0;
				source = "user";
			};
		};
	};
	class LandVehicle;
	class Car: LandVehicle
	{
		ace_loader_path[] = {0};
	};
	class Tank: LandVehicle
	{
		ace_loader_path[] = {0};
	};
	class M1A1: Tank
	{
		ace_loader_path[] = {0,1};
	};
};
class CfgActions
{
	class None;
	class AutoHover: None
	{
		shortcut = "";
		show = 0;
	};
	class AutoHoverCancel: AutoHover
	{
		shortcut = "";
		show = 0;
	};
};
//};
