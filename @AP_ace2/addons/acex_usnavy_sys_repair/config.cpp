////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:59:54 2011 : Created on Fri Oct 21 13:59:54 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_sys_repair : config.bin{
class CfgPatches
{
	class acex_usnavy_sys_repair
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_usnavy_main","ace_sys_repair"};
		version = "1.12.0.64";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_usnavy_sys_repair
		{
			list[] = {"acex_usnavy_sys_repair"};
		};
	};
};
class CfgVehicles
{
	class MTVRRepair;
	class ACE_MTVRRepair: MTVRRepair
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_usnavy_sys_repair_repair
			{
				displayName = "$STR_ACE_UA_REPAIR";
				position = "doplnovanii";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "[this, vehicle player, nil, 'repair'] call ace_sys_repair_fnc_action";
			};
		};
	};
	class MTVRReammo;
	class ACE_MTVRReammo: MTVRReammo
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_usnavy_sys_repair_rearm
			{
				displayName = "$STR_ACE_UA_REARM";
				position = "doplnovanii";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "[this, vehicle player, nil, 'rearm'] call ace_sys_repair_fnc_action";
			};
		};
	};
	class MTVRRefuel;
	class ACE_MTVRRefuel: MTVRRefuel
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_usnavy_sys_repair_refuel
			{
				displayName = "$STR_ACE_UA_REFUEL";
				position = "doplnovanii";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "[this, vehicle player, nil, 'refuel'] call ace_sys_repair_fnc_action";
			};
		};
	};
};
//};
