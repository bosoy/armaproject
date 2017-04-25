////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 15 00:01:22 2013 : Created on Sat Jun 15 00:01:22 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_combatdeaf : config.bin{
class CfgPatches
{
	class ace_sys_combatdeaf
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_weapons"};
		version = "1.14.0.594";
		author[] = {"Rocko","Rommel"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_combatdeaf
	{
		clientInit = "call ('\x\ace\addons\sys_combatdeaf\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_combatdeaf
	{
		clientInit = "call ('\x\ace\addons\sys_combatdeaf\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredNear_EventHandlers
{
	class CAManBase
	{
		class ace_sys_combatdeaf
		{
			clientFiredNearPlayer = "_this call ace_sys_combatdeaf_fnc_firedNear";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class StaticWeapon
	{
		class ace_sys_combatdeaf
		{
			clientGetIn = "_this call ace_sys_combatdeaf_fnc_getIn";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class StaticWeapon
	{
		class ace_sys_combatdeaf
		{
			clientGetOut = "_this call ace_sys_combatdeaf_fnc_getOut";
		};
	};
};
class Extended_Respawn_EventHandlers
{
	class CAManBase
	{
		class ace_sys_combatdeaf
		{
			respawnPlayer = "_this call ace_sys_combatdeaf_fnc_killed";
		};
	};
};
class CfgSounds
{
	class ace_combat_deafness
	{
		name = "ace_combat_deafness";
		sound[] = {"\x\ace\addons\sys_combatdeaf\sounds\deafness.ogg",1,1};
		titles[] = {};
	};
};
//};
