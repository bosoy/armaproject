////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:34:04 2012 : Created on Fri Nov 09 22:34:04 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_lademeister : config.bin{
class CfgPatches
{
	class ace_sys_lademeister
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAAir_E_UH60M","CAAir_E_UH1H_EP1","CAAir_E_MI8","CAAir_E_Mi24","CAAir_E_AH64D","CAAir_E_AH6J","CAAir_E_CH_47F","ace_main"};
		version = "1.14.0.581";
		author[] = {"Rocko"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_lademeister
	{
		init = "call ('\x\ace\addons\sys_lademeister\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Helicopter
	{
		class ace_sys_lademeister
		{
			clientInit = "_this call ace_sys_lademeister_fnc_init";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class Helicopter
	{
		class ace_sys_lademeister
		{
			clientGetIn = "if (player == _this select 2) then { _this call ace_sys_lademeister_fnc_getIn}";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class Helicopter
	{
		class ace_sys_lademeister
		{
			clientGetOut = "if (player == _this select 2) then { _this call ace_sys_lademeister_fnc_getOut}";
		};
	};
};
class Turrets;
class MainTurret;
class SideTurret;
class BackTurret;
class FrontTurret;
class CfgVehicles
{
	class Helicopter;
	class AH64_base_EP1: Helicopter
	{
		ACE_Lademeister = 0;
	};
	class AH6_Base_EP1: Helicopter
	{
		ACE_Lademeister = 0;
	};
	class CH47_base_EP1;
	class CH_47F_EP1: CH47_base_EP1
	{
		ACE_Lademeister = 1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -90;
			};
			class RightDoorGun: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = 90;
			};
			class BackDoorGun: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -180;
			};
		};
	};
	class UH60_Base;
	class MH60S: UH60_Base
	{
		ACE_Lademeister = 1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -90;
			};
			class RightDoorGun: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = 90;
			};
		};
	};
	class UH60M_US_base_EP1;
	class UH60M_EP1: UH60M_US_base_EP1
	{
		ACE_Lademeister = 1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -90;
			};
			class RightDoorGun: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = 90;
			};
		};
	};
	class UH60M_MEV_EP1: UH60M_US_base_EP1
	{
		ACE_Lademeister = 0;
	};
	class UH1H_base: Helicopter
	{
		ACE_Lademeister = 1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = 90;
			};
			class LeftDoorGun: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -90;
			};
		};
	};
	class Mi17_base: Helicopter
	{
		ACE_Lademeister = 1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -90;
			};
			class BackTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = 155;
			};
		};
	};
	class Mi17_base_CZ_EP1;
	class Mi171Sh_Base_EP1: Mi17_base_CZ_EP1
	{
		ACE_Lademeister = 1;
		class Turrets: Turrets
		{
			class LeftTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -90;
			};
			class BackTurret: BackTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -180;
			};
			class RightTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = 90;
			};
		};
	};
	class Mi17_base_RU;
	class Mi17_rockets_RU: Mi17_base_RU
	{
		ACE_Lademeister = 1;
		class Turrets: Turrets
		{
			class SideTurret: MainTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = -90;
			};
			class BackTurret: BackTurret
			{
				ACE_Lademeister = 1;
				ACE_Viewport = 110;
			};
			class FrontTurret: MainTurret
			{
				ACE_Lademeister = 0;
				ACE_Viewport = 360;
			};
		};
	};
	class Mi24_Base: Helicopter
	{
		ACE_Lademeister = 0;
	};
};
//};
