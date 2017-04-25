class CfgPatches
{
	class ace_sys_map
	{
		units[] = {"ACE_Map_Logic"};
		weapons[] = {"ACE_Map","ACE_ItemMap"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons","ace_main","ace_c_weapon","ace_sys_interaction"};
		version = "1.14.0.597";
		author[] = {"Xeno"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_map
		{
			list[] = {"ace_sys_map"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_map
	{
		init = "call ('\x\ace\addons\sys_map\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_map
	{
		clientInit = "call ('\x\ace\addons\sys_map\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		ace_sys_map_init = "(_this select 0) call ace_sys_map_fnc_unitinit";
	};
};
class CfgWeapons
{
	class ItemMap;
	class ACE_Map: ItemMap{};
	class ACE_ItemMap: ItemMap
	{
		scope = 1;
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_Map_Logic: ACE_Logic
	{
		displayName = "$STR_DN_ACE_MAP_LOGIC";
		icon = "\x\ace\addons\sys_map\data\icon\icon_sys_map_ca.paa";
		picture = "\x\ace\addons\sys_map\data\icon\icon_sys_map_ca.paa";
		vehicleClass = "Modules";
		class EventHandlers
		{
			init = "if (isServer) then {ace_sys_map_enabled = true; publicVariable 'ace_sys_map_enabled'}";
		};
	};
	class ACE_Map_LimitZoom_Logic: ACE_Logic
	{
		displayName = "$STR_DN_ACE_MAP_LIMITZOOM_LOGIC";
		icon = "\x\ace\addons\sys_map\data\icon\icon_sys_map_ca.paa";
		picture = "\x\ace\addons\sys_map\data\icon\icon_sys_map_ca.paa";
		vehicleClass = "Modules";
		class EventHandlers
		{
			init = "if (isServer) then {ace_sys_map_auto_limit = true; ace_sys_map_limitZoom = true; publicVariable 'ace_sys_map_auto_limit'; publicVariable 'ace_sys_map_limitZoom'; }";
		};
	};
};