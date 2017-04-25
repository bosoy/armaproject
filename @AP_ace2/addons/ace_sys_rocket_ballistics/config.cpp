////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Dec 01 21:40:14 2012 : Created on Sat Dec 01 21:40:14 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_rocket_ballistics : config.bin{
class CfgPatches
{
	class ace_sys_rocket_ballistics
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main"};
		version = "1.14.0.584";
		author[] = {"q1184"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_rocket_ballistics
	{
		init = "call ('\x\ace\addons\sys_rocket_ballistics\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class Helicopter
	{
		class ace_sys_rocket_ballistics
		{
			clientInit = "if (local (_this select 0)) then {_this call ace_sys_rocket_ballistics_fnc_ffar_fix_init}";
		};
	};
};
class Extended_Killed_EventHandlers
{
	class Helicopter
	{
		class ace_sys_rocket_ballistics
		{
			clientInit = "if (local (_this select 0)) then {_this call ace_sys_rocket_ballistics_fnc_ffar_fix_killed}";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		ace_sys_rocket_ballistics = "if (local (_this select 0)) then {if ((_this select 4) isKindOf 'RocketBase') then {_this call ace_sys_rocket_ballistics_fnc_fired_rpg}; if (! isDedicated) then {_this call ace_sys_rocket_ballistics_fnc_tracer} }";
	};
	class Plane
	{
		class ace_sys_rocket_ballistics
		{
			clientFiredBis = "if (local (_this select 0)) then { if ((_this select 4) isKindOf 'RocketBase') then { if ((_this select 0) == (vehicle player)) then { _this call ace_sys_rocket_ballistics_fnc_fired_ffar} else { _this call ace_sys_rocket_ballistics_fnc_ffar_fix_ai} } }";
		};
	};
	class Helicopter
	{
		class ace_sys_rocket_ballistics
		{
			clientFiredBis = "if (local (_this select 0)) then { if ((_this select 4) isKindOf 'RocketBase') then { if ((_this select 0) == (vehicle player)) then { _this call ace_sys_rocket_ballistics_fnc_fired_ffar} else { _this call ace_sys_rocket_ballistics_fnc_ffar_fix_ai} } }";
		};
	};
	class SPG9_base
	{
		ace_sys_rocket_ballistics = "if ((_this select 4) isKindOf 'RocketBase') then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_rocket_ballistics_fnc_fired_rpg}; if (! isDedicated) then {_this call ace_sys_rocket_ballistics_fnc_tracer} }";
	};
	class UAZ_SPG9_Base
	{
		ace_sys_rocket_ballistics = "if ((_this select 4) isKindOf 'RocketBase') then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_rocket_ballistics_fnc_fired_rpg}; if (! isDedicated) then {_this call ace_sys_rocket_ballistics_fnc_tracer} }";
	};
	class Offroad_SPG9_Gue
	{
		ace_sys_rocket_ballistics = "if ((_this select 4) isKindOf 'RocketBase') then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_rocket_ballistics_fnc_fired_rpg}; if (! isDedicated) then {_this call ace_sys_rocket_ballistics_fnc_tracer} }";
	};
	class LandRover_SPG9_Base_EP1
	{
		ace_sys_rocket_ballistics = "if ((_this select 4) isKindOf 'RocketBase') then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_rocket_ballistics_fnc_fired_rpg}; if (! isDedicated) then {_this call ace_sys_rocket_ballistics_fnc_tracer} }";
	};
};
class cfgAmmo
{
	class RocketCore;
	class RocketBase: RocketCore
	{
		ACE_DISP = 6;
		ace_at_tracersize = 1.8;
		muzzleeffect = "ACE_Effects_Rocket";
	};
	class R_Hydra_HE: RocketBase
	{
		ACE_DISP = 12;
	};
	class R_57mm_HE: RocketBase
	{
		ACE_DISP = 26;
	};
	class R_80mm_HE: RocketBase
	{
		ACE_DISP = 12;
	};
	class R_S8T_AT: RocketBase
	{
		ACE_DISP = 12;
	};
	class R_M136_AT: RocketBase
	{
		ACE_DISP = 7;
	};
	class R_RPG18_AT: RocketBase
	{
		ACE_DISP = 7;
	};
	class R_PG7V_AT: RocketBase
	{
		ACE_DISP = 7;
	};
	class R_PG7VL_AT: R_PG7V_AT{};
	class R_PG7VR_AT: R_PG7V_AT{};
	class R_OG7_AT: R_PG7V_AT{};
	class R_PG9_AT: RocketBase
	{
		ACE_DISP = 2;
	};
	class R_OG9_HE: R_PG9_AT{};
	class R_SMAW_HEDP: RocketBase
	{
		ACE_DISP = 6;
	};
	class R_SMAW_HEAA: R_SMAW_HEDP{};
};
//};
