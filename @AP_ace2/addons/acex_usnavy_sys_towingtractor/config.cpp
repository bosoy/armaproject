////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 02 21:01:48 2012 : Created on Fri Nov 02 21:01:48 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_sys_towingtractor : config.bin{
class CfgPatches
{
	class acex_usnavy_sys_towingtractor
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAWeapons","CAWheeled2_TowingTractor"};
		version = "1.14.0.76";
	};
	class ace_sys_towingtractor
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_usnavy_main"};
		version = "1.14.0.76";
	};
};
class CfgVehicles
{
	class Car;
	class TowingTractor: Car
	{
		class UserActions
		{
			class Attaching
			{
				displayName = "$STR_ACE_TT_ATTACH";
				position = "pos driver";
				radius = 3;
				condition = "(driver this == player) && {(alive this)} && {!(this getVariable ['ace_puller_attached',false])}";
				statement = "[this] execFSM '\x\acex_usnavy\addons\sys_towingtractor\fnc_tractor_pull.fsm'";
				onlyForPlayer = 1;
			};
			class Detaching
			{
				displayName = "$STR_ACE_TT_DETACH";
				position = "pos driver";
				radius = 3;
				condition = "(driver this == player) && {(alive this)} && {(this getVariable 'ace_puller_attached')}";
				statement = "[this] execFSM '\x\acex_usnavy\addons\sys_towingtractor\fnc_tractor_detach.fsm'";
				onlyForPlayer = 1;
			};
		};
	};
};
//};
