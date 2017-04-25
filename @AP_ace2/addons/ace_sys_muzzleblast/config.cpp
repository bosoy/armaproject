////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:46:04 2013 : Created on Sat Apr 06 11:46:04 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_muzzleblast : config.bin{
class CfgPatches
{
	class ace_sys_muzzleblast
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons","ace_main","ace_sys_backblast"};
		version = "1.14.0.590";
		author[] = {"Rocko"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_muzzleblast
	{
		init = "call ('\x\ace\addons\sys_muzzleblast\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Tank
	{
		ace_sys_muzzleblast = "if ( ((_this select 4) isKindOf 'ShellBase') || {((_this select 4) isKindOf 'MissileBase')} || {((_this select 4) isKindOf 'RocketBase')} ) then { _this call ace_sys_muzzleblast_fnc_fired }";
	};
	class Car
	{
		ace_sys_muzzleblast = "if ( ((_this select 4) isKindOf 'ShellBase') || {((_this select 4) isKindOf 'MissileBase')} || {((_this select 4) isKindOf 'RocketBase')} ) then { _this call ace_sys_muzzleblast_fnc_fired }";
	};
	class StaticWeapon
	{
		ace_sys_muzzleblast = "if ( ((_this select 4) isKindOf 'MissileBase') || {((_this select 4) isKindOf 'RocketBase')} ) then { _this call ace_sys_muzzleblast_fnc_fired }";
	};
};
class CfgAmmo
{
	class ShellCore;
	class ShellBase: ShellCore
	{
		ACE_Muzzle_FX = "ace_sys_muzzleblast_fnc_tank";
		whistleOnFire = 0;
	};
	class MissileCore;
	class MissileBase: MissileCore
	{
		ACE_Muzzle_FX = "ace_sys_muzzleblast_fnc_atgm";
	};
	class RocketCore;
	class RocketBase: RocketCore
	{
		ACE_Muzzle_FX = "ace_sys_muzzleblast_fnc_atgm";
	};
	class Sh_105_HE: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class Sh_120_HE: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class Sh_120_SABOT: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class Sh_122_HE: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class Sh_125_HE: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class Sh_125_SABOT: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class Sh_85_HE: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class Sh_85_AP: ShellBase
	{
		whistleOnFire = 0;
		whistleDist = 0;
	};
	class ACE_OG15VRound: ShellBase
	{
		ACE_Muzzle_FX = 0;
	};
	class ACE_PG15VRound: ShellBase
	{
		ACE_Muzzle_FX = 0;
	};
};
//};
