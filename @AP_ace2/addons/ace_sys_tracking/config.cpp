class CfgPatches
{
	class ace_sys_tracking
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAData","CAWeapons","CAWeapons2","CACharacters","CATracked","CAWheeled","CAWheeled3","CAAir","CAAir3","CAA10"};
		version = "1.14.0.597";
		author[] = {"Sickboy","Robalo"};
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_tracking
	{
		clientInit = "call ('\x\ace\addons\sys_tracking\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgVehicles
{
	class All
	{
		ace_sys_tracking_marker = "DOT";
	};
	class AllVehicles: All{};
	class Ship: AllVehicles
	{
		ace_sys_tracking_marker = "LightTeam";
	};
	class Land: AllVehicles{};
	class Man: Land
	{
		ace_sys_tracking_marker = "InfantryTeam";
	};
	class LandVehicle: Land
	{
		ace_sys_tracking_marker = "LightTeam";
	};
	class Tank: LandVehicle
	{
		ace_sys_tracking_marker = "HeavyTeam";
	};
	class StaticWeapon: LandVehicle{};
	class StaticCannon;
	class M119: StaticCannon{};
	class D30: StaticWeapon{};
	class Air: AllVehicles
	{
		ace_sys_tracking_marker = "b_air";
	};
	class Helicopter: Air{};
	class ParachuteBase: Helicopter
	{
		ace_sys_tracking_marker = "b_unknown";
	};
	class Plane: Air
	{
		ace_sys_tracking_marker = "b_plane";
	};
	class ACE_Logic;
	class ACE_ForceGroupMarkersOn_Logic: ACE_Logic
	{
		scope = 1;
		displayName = "";
	};
	class ACE_ForceGroupMarkersOff_Logic: ACE_ForceGroupMarkersOn_Logic{};
	class ACE_EnableGPSUnitMarkers_Logic: ACE_ForceGroupMarkersOn_Logic{};
	class ACE_FBCB2_OFF_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_FORCEGROUPMARKERSOFF";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_tracking_enabled = false; publicVariable 'ace_sys_tracking_enabled'};";
		};
	};
};
class CfgMarkers
{
	class Flag;
	class ace_sys_tracking_gpsUM_mkr_inf: Flag
	{
		name = "";
		icon = "\x\ace\addons\sys_tracking\data\markers\inf.paa";
		color[] = {1,0,0,1};
		scope = 0;
	};
	class ace_sys_tracking_gpsUM_mkr_tl: ace_sys_tracking_gpsUM_mkr_inf
	{
		icon = "\x\ace\addons\sys_tracking\data\markers\tl.paa";
	};
	class ace_sys_tracking_gpsUM_mkr_med: ace_sys_tracking_gpsUM_mkr_inf
	{
		icon = "\x\ace\addons\sys_tracking\data\markers\med.paa";
	};
	class ace_sys_tracking_gpsUM_mkr_drv: ace_sys_tracking_gpsUM_mkr_inf
	{
		icon = "\x\ace\addons\sys_tracking\data\markers\drv.paa";
	};
};
class RscObject;
class RscDisplayMainMap
{
	class objects
	{
		class GPS: RscObject
		{
			onMouseButtonDblClick = "if (ace_sys_tracking_gpsUM_enabled) then {[] call ace_sys_tracking_fnc_gpsUMtoggle}";
		};
	};
};