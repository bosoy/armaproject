////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:51:39 2013 : Created on Sat Apr 06 11:51:39 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sys_crewserved : config.bin{
class CfgPatches
{
	class acex_sys_crewserved
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"ace_sys_crewserved"};
		version = "1.14.0.371";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_sys_crewserved
		{
			list[] = {"acex_sys_crewserved"};
		};
	};
};
class CfgVehicles
{
	class ACE_M240_Tripod;
	class ACE_M240M145_Tripod;
	class ACE_M240B_Tripod: ACE_M240_Tripod
	{
		model = "\x\acex\addons\sys_crewserved\ace_m240b_static.p3d";
	};
	class ACE_M240L_Tripod: ACE_M240B_Tripod
	{
		model = "\x\acex\addons\sys_crewserved\ace_m240l_static.p3d";
	};
	class ACE_M240L_M145_Tripod: ACE_M240M145_Tripod
	{
		model = "\x\acex\addons\sys_crewserved\ace_m240l_M145_static.p3d";
	};
	class BRDM2_Base;
	class BRDM2_ATGM_Base: BRDM2_Base
	{
		class Turrets;
	};
	class ACE_BRDM2_ATGM_Base: BRDM2_ATGM_Base
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class ACE_BRDM2_SA9_Base: ACE_BRDM2_ATGM_Base
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[] = {"ACE_9M31","ACE_9M31","ACE_9M31","ACE_9M31"};
			};
		};
	};
};
//};
