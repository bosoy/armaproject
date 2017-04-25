////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:57 2013 : Created on Mon Oct 14 23:06:57 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_camshake : config.bin{
class CfgPatches
{
	class ace_sys_camshake
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_vehicle","ace_fx"};
		version = "1.14.0.597";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_camshake
	{
		clientInit = "call ('\x\ace\addons\sys_camshake\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredNear_EventHandlers
{
	class CAManBase
	{
		class ace_sys_camshake
		{
			clientFiredNearPlayer = "_this call ace_sys_camshake_fnc_firedNear";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class All
	{
		class ace_sys_camshake
		{
			firedBis = "_this call ace_sys_camshake_fnc_fired";
			exclude[] = {"StaticMortar"};
		};
	};
	class Car
	{
		class ace_sys_camshake
		{
			clientFiredBis = "if (player in (_this select 0)) then { _this call ace_sys_camshake_fnc_fired_veh}";
		};
	};
	class Tank
	{
		class ace_sys_camshake
		{
			clientFiredBis = "if (player in (_this select 0)) then { _this call ace_sys_camshake_fnc_fired_veh}";
		};
	};
	class StaticWeapon
	{
		class ace_sys_camshake
		{
			clientFiredBis = "if (player in (_this select 0)) then { _this call ace_sys_camshake_fnc_fired_veh}";
		};
	};
	class Air
	{
		class ace_sys_camshake
		{
			clientFiredBis = "if (player in (_this select 0)) then { _this call ace_sys_camshake_fnc_fired_veh}";
		};
	};
};
class CfgVehicles
{
	class Allvehicles;
	class Air: Allvehicles
	{
		ace_camshake_enabled = 1;
	};
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		ace_camshake_enabled = 1;
	};
	class Tank: LandVehicle
	{
		ace_camshake_enabled = 1;
	};
	class Car: LandVehicle
	{
		ace_camshake_enabled = 1;
	};
	class T90: Tank
	{
		ace_camshake_enabled = 0;
	};
	class T72_Base: Tank
	{
		ace_camshake_enabled = 0;
	};
	class T55_Base: Tank
	{
		ace_camshake_enabled = 0;
	};
	class T34: Tank
	{
		ace_camshake_enabled = 0;
	};
	class M1A1: Tank
	{
		ace_camshake_enabled = 0;
	};
};
class CfgAmmo
{
	class MissileCore;
	class BombCore;
	class LaserBombCore;
	class RocketCore;
	class BulletCore;
	class ShellCore;
	class GrenadeCore;
	class BulletBase: BulletCore
	{
		ace_sys_camshake_coef = 0.5;
	};
	class B_30mm_HE;
	class B_30x113mm_M789_HEDP: B_30mm_HE
	{
		ace_sys_camshake_coef = 0.2;
	};
	class GrenadeBase: GrenadeCore
	{
		ace_sys_camshake_coef = 0.7;
	};
	class ShellBase: ShellCore
	{
		ace_sys_camshake_coef = 3;
	};
	class RocketBase: RocketCore
	{
		ace_sys_camshake_coef = 0.7;
	};
	class MissileBase: MissileCore
	{
		ace_sys_camshake_coef = 1;
	};
	class Bo_GBU12_LGB: LaserBombCore
	{
		ace_sys_camshake_coef = 1;
	};
	class Bo_FAB_250: BombCore
	{
		ace_sys_camshake_coef = 1;
	};
};
//};
