////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:44:22 2013 : Created on Sat Apr 06 11:44:22 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_carglass : config.bin{
class CfgPatches
{
	class ace_sys_carglass
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.590";
		author[] = {"Xeno"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_carglass
		{
			list[] = {"ace_sys_carglass"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_carglass
	{
		init = "call ('\x\ace\addons\sys_carglass\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Car
	{
		class ace_sys_carglass
		{
			clientInit = "_this call ace_sys_carglass_fnc_init";
		};
	};
};
class Extended_Dammaged_EventHandlers
{
	class Car
	{
		ace_sys_carglass = "_this call ace_sys_carglass_fnc_damaged";
	};
};
class Extended_GetIn_EventHandlers
{
	class Car
	{
		class ace_sys_carglass
		{
			clientGetIn = "if (player == _this select 2) then {_this call ace_sys_carglass_fnc_getIn}";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class Car
	{
		class ace_sys_carglass
		{
			clientGetOut = "if (player == _this select 2) then {_this call ace_sys_carglass_fnc_getOut}";
		};
	};
};
class CfgSounds
{
	class ace_break_glass
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_carglass\break.ogg",1,1};
		titles[] = {};
	};
};
//};
