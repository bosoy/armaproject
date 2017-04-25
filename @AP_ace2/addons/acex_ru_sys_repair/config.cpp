////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:57:15 2011 : Created on Fri Oct 21 13:57:15 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_sys_repair : config.bin{
class CfgPatches
{
	class acex_ru_sys_repair
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","ace_sys_repair"};
		version = "1.12.0.61";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_ru_sys_repair
		{
			list[] = {"acex_ru_sys_repair"};
		};
	};
};
class CfgVehicles
{
	class KamazRepair;
	class ACE_KamazRepair: KamazRepair
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_repair
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
	class KamazReammo;
	class ACE_KamazReammo: KamazReammo
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_rearm
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
	class KamazRefuel;
	class ACE_KamazRefuel: KamazRefuel
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_refuel
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
	class UralRepair_CDF;
	class ACE_UralRepair_CDF: UralRepair_CDF
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_repair
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
	class UralReammo_CDF;
	class ACE_UralReammo_CDF: UralReammo_CDF
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_rearm
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
	class UralRefuel_CDF;
	class ACE_UralRefuel_CDF: UralRefuel_CDF
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_refuel
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
	class UralRepair_INS;
	class ACE_UralRepair_INS: UralRepair_INS
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_repair
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
	class UralReammo_INS;
	class ACE_UralReammo_INS: UralReammo_INS
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_rearm
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
	class UralRefuel_INS;
	class ACE_UralRefuel_INS: UralRefuel_INS
	{
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class acex_ru_sys_repair_refuel
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
