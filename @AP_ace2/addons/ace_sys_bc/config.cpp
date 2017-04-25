////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Dec 01 21:38:51 2012 : Created on Sat Dec 01 21:38:51 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_bc : config.bin{
class CfgPatches
{
	class ace_sys_bc
	{
		units[] = {"ace_sys_bc_logic"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAData","Extended_EventHandlers","ace_main","ace_sys_menu"};
		version = "1.14.0.584";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_bc
	{
		init = "call ('\x\ace\addons\sys_bc\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ace_sys_bc_logic: ACE_Logic
	{
		scope = 1;
		displayName = "ace_sys_bc";
		class EventHandlers
		{
			init = "(_this select 0) spawn ('\x\ace\addons\sys_bc\init_logic.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
		};
	};
};
//};
