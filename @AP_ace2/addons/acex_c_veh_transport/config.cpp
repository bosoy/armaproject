////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Mar 26 13:00:06 2012 : Created on Mon Mar 26 13:00:06 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_transport : config.bin{
class CfgPatches
{
	class acex_c_veh_transport
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_c_vehicle"};
		version = "1.13.0.356";
	};
};
class CfgVehicles
{
	class BMP2_Base;
	class ACE_BMP2_TK: BMP2_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_KonkursM_CSWDM
			{
				magazine = "ACE_KonkursM_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_BRDM2_ATGM_Base;
	class ACE_BRDM2_SA9_Base: ACE_BRDM2_ATGM_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_9M31_CSWDM
			{
				magazine = "ACE_9M31_CSWDM";
				count = 2;
			};
		};
	};
};
//};
