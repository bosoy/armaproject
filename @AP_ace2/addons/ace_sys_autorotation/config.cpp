////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Dec 01 21:38:50 2012 : Created on Sat Dec 01 21:38:50 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_autorotation : config.bin{
class CfgPatches
{
	class ace_sys_autorotation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.584";
		author[] = {"q1184","Panda[pl]","zGuba"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_autorotation
		{
			list[] = {"ace_sys_autorotation"};
		};
	};
};
class CfgSounds
{
	class ACE_EngineFailureAlarm_1
	{
		name = "ACE_EngineFailureAlarm_1";
		sound[] = {"\x\ace\addons\sys_autorotation\sound\ACE_Warning.ogg","db+20",1};
		titles[] = {};
	};
	class ACE_EngineFailureAlarm_2
	{
		name = "ACE_EngineFailureAlarm_2";
		sound[] = {"\x\ace\addons\sys_autorotation\sound\ACE_Warning.ogg","db+6",1};
		titles[] = {};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_autorotation
	{
		clientinit = "call ('\x\ace\addons\sys_autorotation\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Helicopter
	{
		class ace_sys_autorotation
		{
			clientInit = "_this call ace_sys_autorotation_fnc_init";
		};
	};
};
class Extended_Engine_EventHandlers
{
	class Helicopter
	{
		class ace_sys_autorotation
		{
			clientEngine = "if (isDedicated) then {_this spawn ace_sys_autorotation_fnc_autorotate} else {_this call ace_sys_autorotation_fnc_autorotate_client;_this call ace_sys_autorotation_fnc_alarm}";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class Helicopter
	{
		class ace_sys_autorotation
		{
			clientGetIn = "if (player == _this select 2) then {_this spawn ace_sys_autorotation_fnc_getIn}";
		};
	};
};
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		ace_sys_autorotation_vertical_gain = "0.75/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
	class AH1_Base: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.8/1.5";
		ace_sys_autorotation_horizontal_gain = "1.1/75";
	};
	class UH60_Base: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.6/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
	class Mi17_Base: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.6/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
	class AH64_base_EP1: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.6/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
	class Mi24_Base: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.6/1.5";
		ace_sys_autorotation_horizontal_gain = "1.2/75";
	};
	class Kamov_Base: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.75/1.5";
		ace_sys_autorotation_horizontal_gain = "1.2/75";
	};
	class UH1_base: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.75/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
	class CruiseMissile1: Helicopter
	{
		ace_sys_autorotation_vertical_gain = 0;
		ace_sys_autorotation_horizontal_gain = 0;
	};
	class AH6_Base_EP1: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.9/1.5";
		ace_sys_autorotation_horizontal_gain = "1.2/75";
	};
	class CH47_base_EP1: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.5/1.5";
		ace_sys_autorotation_horizontal_gain = "0.75/75";
	};
	class UH1H_base: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.7/1.5";
		ace_sys_autorotation_horizontal_gain = "0.9/75";
	};
	class Ka137_Base_PMC: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.45/1.5";
		ace_sys_autorotation_horizontal_gain = "0.6/75";
	};
	class Ka60_Base_PMC: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.75/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
	class AW159_Lynx_BAF: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.75/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
	class BAF_Merlin_HC3_D: Helicopter
	{
		ace_sys_autorotation_vertical_gain = "0.6/1.5";
		ace_sys_autorotation_horizontal_gain = "1.0/75";
	};
};
//};
