////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:40:20 2012 : Created on Fri Nov 09 22:40:20 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_sys_eject : config.bin{
class CfgPatches
{
	class acex_usnavy_sys_eject
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"ace_sys_eject"};
		version = "1.14.0.77";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_usnavy_sys_eject
		{
			list[] = {"acex_usnavy_sys_eject"};
		};
	};
};
class CfgVehicles
{
	class ACE_EjectionSeat;
	class ACE_K36: ACE_EjectionSeat
	{
		model = "\x\acex_usnavy\addons\sys_eject\ace_k36";
	};
	class ACE_MB_Mk12: ACE_EjectionSeat
	{
		model = "\x\acex_usnavy\addons\sys_eject\ace_mb_mk12";
	};
};
//};
