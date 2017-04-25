////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:33:16 2012 : Created on Fri Nov 09 22:33:16 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_flares : config.bin{
class CfgPatches
{
	class ace_sys_flares
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main","ace_c_weapon"};
		version = "1.14.0.581";
		author[] = {"Rocko"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_flares
	{
		init = "call ('\x\ace\addons\sys_flares\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgAmmo
{
	class FlareCore;
	class FlareBase: FlareCore
	{
		ACE_Simulation = "shotFlare";
	};
	class F_40mm_White: FlareBase
	{
		soundFly[] = {"\x\ace\addons\sys_flares\sound\flare.ogg",0.1,1};
		ace_sys_flares_SLOW = 1;
		ace_sys_flares_DAY = 1;
		ace_sys_flares_DESCEND = -2;
		ace_sys_flares_COLOR[] = {0.9,0.9,0.9,1};
	};
	class F_40mm_Green: F_40mm_White
	{
		ace_sys_flares_Color[] = {0.05,0.9,0.05,1};
	};
	class F_40mm_Red: F_40mm_White
	{
		ace_sys_flares_COLOR[] = {0.9,0.05,0.05,1};
	};
	class F_40mm_Yellow: F_40mm_White
	{
		ace_sys_flares_COLOR[] = {0.9,0.9,0.05,1};
	};
	class ACE_F_40mm_IR: F_40mm_White
	{
		brightness = 0.35;
		size = 0.45;
		ace_sys_flares_COLOR[] = {0.05,0.05,0.05,0};
		ace_sys_flares_DAY = 0;
	};
	class ACE_StarShell_Base: FlareBase
	{
		brightness = 0.4;
		ACE_Simulation = "shotFlareCluster";
	};
	class ACE_SS_White: ACE_StarShell_Base
	{
		ace_sys_flares_COLOR[] = {0.9,0.9,0.9,1};
		ace_sys_flares_SLOW = 0;
		ace_sys_flares_DAY = 1;
		ace_sys_flares_BURST = 1;
	};
	class ACE_SS_Green: ACE_SS_White
	{
		ace_sys_flares_COLOR[] = {0.5,0.9,0.5,1};
	};
	class ACE_SS_Red: ACE_SS_White
	{
		ace_sys_flares_COLOR[] = {0.9,0.5,0.5,1};
	};
	class ACE_SS_Yellow: ACE_SS_White
	{
		ace_sys_flares_COLOR[] = {0.9,0.9,0.5,1};
	};
	class ACE_SS_White_FG: ACE_SS_White
	{
		ACE_Simulation = "shotFlare";
		ace_sys_flares_BURST = 0;
	};
	class ACE_SS_Green_FG: ACE_SS_Green
	{
		ace_sys_flares_COLOR[] = {0.5,0.9,0.5,1};
	};
	class ACE_SS_Red_FG: ACE_SS_Red
	{
		ace_sys_flares_COLOR[] = {0.9,0.5,0.5,1};
	};
	class ACE_SS_Yellow_FG: ACE_SS_Yellow
	{
		ace_sys_flares_COLOR[] = {0.9,0.9,0.5,1};
	};
};
//};
