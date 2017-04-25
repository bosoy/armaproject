////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.51
//Mon Jul 28 05:52:52 2014 : Source 'file' date Mon Jul 28 05:52:52 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_nvg : config.bin{
class CfgPatches
{
	class ace_sys_nvg
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","ace_sys_interaction"};
		version = "1.14.0.597";
		author[] = {"s_hole"};
		class ACE_Options
		{
			group = "ITEMS";
			title = "NVG";
			class brightnessUP
			{
				title = "$STR_ACE_MENU_NVG_BRIGHTNESSUP";
			};
			class brightnessDOWN
			{
				title = "$STR_ACE_MENU_NVG_BRIGHTNESSDN";
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_nvg
	{
		clientInit = "call ('\x\ace\addons\sys_nvg\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_nvg
	{
		clientInit = "call ('\x\ace\addons\sys_nvg\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		class ace_sys_nvg
		{
			killedPlayer = "call ace_sys_nvg_fnc_NVGoff";
		};
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_NVG_RangeLimit_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_NVGRNGLIM_ENABLE";
		icon = "x\ace\addons\sys_nvg\data\icon_ace_nvg_ca.paa";
		picture = "x\ace\addons\sys_nvg\data\icon_ace_nvg_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_nvg_rangelimit_enabled = true;publicVariable 'ace_sys_nvg_rangelimit_enabled'};";
		};
	};
};
class cfgWeapons
{
	class RifleCore;
	class Rifle: RifleCore
	{
		ace_sys_nvg_nvrange = 1050;
		ace_sys_nvg_tirange = 1050;
	};
	class Binocular;
	class NVGoggles: Binocular
	{
		ace_sys_nvg_nvrange = 420;
	};
	class LaserDesignator: Binocular
	{
		ace_sys_nvg_nvrange = 1050;
	};
	class ACE_MX2A: Binocular
	{
		ace_sys_nvg_tirange = 1050;
	};
	class Binocular_Vector: Binocular
	{
		ace_sys_nvg_nvrange = 1050;
	};
	class m8_base;
	class m8_tws: m8_base
	{
		ace_sys_nvg_tirange = 1050;
	};
	class m8_tws_sd: m8_base
	{
		ace_sys_nvg_tirange = 1050;
	};
	class SCAR_L_STD_EGLM_RCO;
	class SCAR_L_STD_EGLM_TWS: SCAR_L_STD_EGLM_RCO
	{
		ace_sys_nvg_tirange = 1050;
	};
	class SCAR_H_LNG_Sniper_SD;
	class SCAR_H_STD_TWS_SD: SCAR_H_LNG_Sniper_SD
	{
		ace_sys_nvg_tirange = 2300;
	};
	class M110_TWS_EP1: Rifle
	{
		ace_sys_nvg_tirange = 2300;
	};
	class M110_NVG_EP1: M110_TWS_EP1
	{
		ace_sys_nvg_nvrange = 2300;
	};
	class m107;
	class m107_TWS_EP1: m107
	{
		ace_sys_nvg_tirange = 6000;
	};
	class FN_FAL;
	class FN_FAL_ANPVS4: FN_FAL
	{
		ace_sys_nvg_nvrange = 850;
	};
	class AKS_BASE;
	class AKS_74_NSPU: AKS_BASE
	{
		ace_sys_nvg_nvrange = 570;
	};
	class AKS_74_GOSHAWK: AKS_BASE
	{
		ace_sys_nvg_tirange = 850;
	};
	class SVD;
	class SVD_NSPU_EP1: SVD
	{
		ace_sys_nvg_nvrange = 570;
	};
	class M249;
	class M249_TWS_EP1: M249
	{
		ace_sys_nvg_tirange = 1050;
	};
};
//};
