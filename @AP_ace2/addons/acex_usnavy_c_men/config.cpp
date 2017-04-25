////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 28 16:02:21 2011 : Created on Fri Oct 28 16:02:21 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_c_men : config.bin{
class CfgPatches
{
	class acex_usnavy_men
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CACharacters2"};
		version = "1.12.0.65";
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class TalkTopics;
	};
	class SoldierWB: CAManBase
	{
		class TalkTopics: TalkTopics{};
	};
	class SoldierEB: CAManBase
	{
		class TalkTopics: TalkTopics{};
	};
	class SoldierGB: CAManBase
	{
		class TalkTopics: TalkTopics{};
	};
	class USMC_Soldier_Base: SoldierWB
	{
		identityTypes[] = {"Language_EN_EP1","Head_USMC","USMC_Glasses"};
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
		};
	};
	class USMC_SoldierS_Engineer: USMC_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ACE_ENGINEER";
		engineer = 1;
		picture = "\ca\characters_d_baf\Data\i_eng_ca.paa";
	};
	class FR_Base: SoldierWB
	{
		identityTypes[] = {"Language_EN_EP1","Head_USMC_Camo","FR_Glasses"};
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
			core_tk = "Core_Full_E";
		};
	};
	class CDF_Soldier_Base: SoldierWB
	{
		identityTypes[] = {"Language_CZ","Head_CDF","CDF_Glasses"};
		languages[] = {"CZ","EN","RU"};
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
			core_ru = "Core_Full";
		};
	};
	class RU_Soldier_Base: SoldierEB
	{
		identityTypes[] = {"Language_RU","Head_RU","RU_Glasses"};
		accuracy = 2;
	};
	class RUS_Soldier_Base: SoldierEB
	{
		identityTypes[] = {"Language_RU","Head_RU_Camo","RU_Glasses"};
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
			core_tk = "Core_Full_E";
		};
	};
	class MVD_Soldier_Base: SoldierEB
	{
		identityTypes[] = {"Language_RU","Head_RU"};
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
			core_tk = "Core_Full_E";
		};
	};
	class Ins_Soldier_Base: SoldierEB
	{
		identityTypes[] = {"Language_RU","Head_INS","INS_Glasses"};
	};
	class GUE_Soldier_Base: SoldierGB
	{
		identitytypes[] = {"Language_CZ","Head_GUE","INS_Glasses"};
	};
};
//};
