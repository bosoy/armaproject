////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.51
//Mon Jul 28 05:52:52 2014 : Source 'file' date Mon Jul 28 05:52:52 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_planefx : config.bin{
class CfgPatches
{
	class ace_sys_planefx
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.597";
		author[] = {"Maddmatt","Rocko","Xeno"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_planefx
		{
			list[] = {"ace_sys_planefx"};
		};
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_planefx
	{
		clientInit = "call ('\x\ace\addons\sys_planefx\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class A10
	{
		class ace_sys_planefx
		{
			clientInit = "(_this select 0) spawn ace_sys_planefx_fnc_flyby;_this spawn ace_sys_planefx_fnc_avapour";
		};
	};
	class AV8B2
	{
		class ace_sys_planefx
		{
			clientInit = "(_this select 0) spawn ace_sys_planefx_fnc_flyby;_this spawn ace_sys_planefx_fnc_avapour";
		};
	};
	class Su34
	{
		class ace_sys_planefx
		{
			clientInit = "(_this select 0) spawn ace_sys_planefx_fnc_flyby;_this spawn ace_sys_planefx_fnc_avapour;(_this select 0) spawn ace_sys_planefx_fnc_sonicboom";
		};
	};
	class F35_base
	{
		class ace_sys_planefx
		{
			clientInit = "(_this select 0) spawn ace_sys_planefx_fnc_flyby;_this spawn ace_sys_planefx_fnc_avapour;(_this select 0) spawn ace_sys_planefx_fnc_sonicboom";
		};
	};
	class Su25_base
	{
		class ace_sys_planefx
		{
			clientInit = "(_this select 0) spawn ace_sys_planefx_fnc_flyby;_this spawn ace_sys_planefx_fnc_avapour";
		};
	};
	class L39_base
	{
		class ace_sys_planefx
		{
			clientInit = "(_this select 0) spawn ace_sys_planefx_fnc_flyby;_this spawn ace_sys_planefx_fnc_avapour";
		};
	};
};
class CfgSounds
{
	class ace_fx_planeABurner
	{
		name = "ace_fx_planeABurner";
		sound[] = {"\x\ace\addons\sys_planefx\sound\burner.ogg","db+10",1};
		titles[] = {};
	};
	class ace_fx_jetflybyfar
	{
		name = "ace_fx_jetflybyfar";
		sound[] = {"\x\ace\addons\sys_planefx\sound\jet_flyby1.ogg","db+0",1};
		titles[] = {};
	};
	class ace_fx_jetflybyshort
	{
		name = "ace_fx_jetflybyshort";
		sound[] = {"\x\ace\addons\sys_planefx\sound\plane_flyby_short.ogg","db+0",1};
		titles[] = {};
	};
	class ace_fx_jetflybya10
	{
		name = "ace_fx_jetflybya10";
		sound[] = {"\x\ace\addons\sys_planefx\sound\a10_flyby.ogg","db+0",1};
		titles[] = {};
	};
	class ace_fx_jetflybyharrier
	{
		name = "ace_fx_jetflybyharrier";
		sound[] = {"\x\ace\addons\sys_planefx\sound\harrier_flyby.ogg","db-3",1};
		titles[] = {};
	};
	class ace_fx_jetflybysu
	{
		name = "ace_fx_jetflybysu";
		sound[] = {"\x\ace\addons\sys_planefx\sound\su_flyby.ogg","db-3",1};
		titles[] = {};
	};
	class ace_fx_sonicboom
	{
		name = "ace_fx_sonicboom";
		sound[] = {"\x\ace\addons\sys_planefx\sound\sonicboom.ogg","db-2",1};
		titles[] = {};
	};
};
//};
