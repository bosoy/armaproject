////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:35:15 2011 : Created on Fri Oct 21 13:35:15 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_men : config.bin{
class CfgPatches
{
	class acex_c_men
	{
		units[] = {"ACE_TK_Soldier_RPOM"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","CACharacters","CACharacters2","ace_main","ace_sys_ruck","ace_c_men","acex_c_vehicle"};
		version = "1.12.0.347";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_c_men
		{
			list[] = {"acex_c_men"};
		};
	};
};
class CfgVehicles
{
	class SoldierWB;
	class SoldierEB;
	class SoldierGB;
	class US_Soldier_Base_EP1: SoldierWB{};
	class TK_Soldier_base_EP1: SoldierEB{};
	class ACE_TK_Soldier_RPOM: TK_Soldier_base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_RIFLEMAN_RPOM";
		weapons[] = {"M16A2","ACE_RPOM","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_East","HandGrenade_East"};
		respawnWeapons[] = {"M16A2","ACE_RPOM","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","HandGrenade_East","HandGrenade_East"};
	};
};
//};
