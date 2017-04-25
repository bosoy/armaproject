////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:38 2013 : Created on Sat Jun 08 13:05:38 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_air_refuel : config.bin{
class CfgPatches
{
	class ace_sys_air_refuel
	{
		units[] = {"ACE_Refueling_Hose","ACE_HC130_N"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAMisc3","CAMisc","CAAir2_C130J","CAAir_E_C130J","CAAir_E","CAMisc_E","ace_main"};
		version = "1.14.0.593";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_air_refuel
		{
			list[] = {"ace_sys_air_refuel"};
		};
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_AirRefuel_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_AIR_REFUEL";
		icon = "\x\ace\addons\sys_air_refuel\data\icon\icon_ace_refuel_ca.paa";
		picture = "\x\ace\addons\sys_air_refuel\data\icon\icon_ace_refuel_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then { _this spawn ('\x\ace\addons\sys_air_refuel\ACE_Air_Refuel_Init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })}";
		};
	};
	class RoadCone;
	class ACE_Refueling_Hose: RoadCone
	{
		scope = 1;
		displayName = "";
		model = "\x\ace\addons\sys_air_refuel\hose.p3d";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_Refueling_Tanks: RoadCone
	{
		scope = 1;
		displayName = "";
		model = "\x\ace\addons\sys_air_refuel\tanks.p3d";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class C130J_US_EP1;
	class ACE_HC130_N: C130J_US_EP1
	{
		scope = 2;
		accuracy = 1.5;
		displayName = "HC-130J Combat King II";
		transportSoldier = 3;
		fuelCapacity = 80000;
		maxSpeed = 500;
		class UserActions
		{
			class ReleaseHose
			{
				position = "pilot";
				radius = 5;
				onlyForPlayer = 1;
				displayName = "$STR_ACE_AIR_REFUEL_UA_REL";
				condition = "alive this && {(driver this == player)} && {!(this call ace_sys_air_refuel_fnc_hose_pulled)} && {!(this call ace_sys_air_refuel_fnc_busy)}";
				statement = "[this] execFSM ""\x\ace\addons\sys_air_refuel\fnc_release_hose.fsm""";
			};
			class PullHose: ReleaseHose
			{
				displayName = "$STR_ACE_AIR_REFUEL_UA_PUL";
				condition = "alive this && {(driver this == player)} && {(this getVariable ""ace_sys_air_refuel_hose_released"")} && {!(this call ace_sys_air_refuel_fnc_busy)}";
				statement = "[this] execFSM ""\x\ace\addons\sys_air_refuel\fnc_pull_hose.fsm""";
			};
		};
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
		};
		ACE_isTanker = 1;
		ace_sys_tracking_marker = "b_air_refuel";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_air_refuel
	{
		init = "call ('\x\ace\addons\sys_air_refuel\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgMarkers
{
	class b_empty;
	class b_air_refuel: b_empty
	{
		name = "BLUFOR - Airial Refueling";
		icon = "\x\ace\addons\sys_air_refuel\data\markers\b_air_refuel.paa";
		side = 1;
		color[] = {0,0,1,1};
		scope = 1;
		size = 32;
	};
};
//};
