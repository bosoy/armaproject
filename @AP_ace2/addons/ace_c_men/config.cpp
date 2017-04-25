////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:43:08 2013 : Created on Sat Apr 06 11:43:08 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_men : config.bin{
class CfgPatches
{
	class ace_c_men
	{
		units[] = {"ACE_US_Soldier_M224_G","ACE_US_Soldier_M224_AG","ACE_US_Soldier_M224_AB","ACE_US_Soldier_M252_G","ACE_US_Soldier_M252_AG","ACE_US_Soldier_M252_AB","ACE_TK_Soldier_KonkursG","ACE_TK_Soldier_KonkursAG","ACE_TK_Soldier_2B14_G","ACE_TK_Soldier_2B14_AG","ACE_TK_Soldier_2B14_AB","ACE_TK_CIV_Takistani_Doctor_EP1","ACE_CZ_Medic_EP1","ACE_UN_CDF_Medic_EP1","ACE_TK_INS_Soldier_AK_EP1","ACE_TK_INS_Soldier_AKS_EP1"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CACharacters","CACharacters2","CACharacters_E","CACharacters_BAF","CACharacters_PMC","CA_Animals_E","ace_main","ace_sys_ruck","ace_c_weapon","ace_c_men_designation","ace_sys_crewserved"};
		version = "1.14.0.590";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_c_men
		{
			list[] = {"ace_c_men"};
		};
	};
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class HitPoints
		{
			class HitHead;
			class HitBody;
		};
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
	class Civilian: CAManBase
	{
		languages[] = {"CZ"};
		fsmDanger = "x\ace\addons\c_men\data\ACE_formationCDanger.fsm";
		fsmFormation = "x\ace\addons\c_men\data\ACE_formationC.fsm";
	};
	class Woman: Civilian
	{
		useinternallodinvehicles = 0;
	};
	class Woman_EP1: Civilian
	{
		useinternallodinvehicles = 0;
	};
	class Animal;
	class CAAnimalBase: Animal
	{
		mapSize = 1;
	};
	class Cow: CAAnimalBase
	{
		class SoundEnvironExt
		{
			laydown[] = {{"\CA\animals2\data\sounds\cow01",0.1,1,80},{"\CA\animals2\data\sounds\cow03",0.1,1,80}};
		};
	};
	class Goat: CAAnimalBase
	{
		class SoundEnvironExt
		{
			laydown[] = {{"\CA\animals2\data\sounds\goat01",0.1,1,50},{"\CA\animals2\data\sounds\goat03",0.1,1,50}};
		};
	};
	class Sheep: CAAnimalBase
	{
		class SoundEnvironExt
		{
			laydown[] = {{"\CA\animals2\data\sounds\sheep02",0.1,1,50}};
		};
	};
	class GER_Soldier_base_EP1: SoldierWB
	{
		ACE_Stamina = 0.8;
	};
	class US_Soldier_Base_EP1: SoldierWB
	{
		class TalkTopics;
		class HitPoints: HitPoints
		{
			class HitHead: HitHead{};
		};
	};
	class US_Soldier_Light_EP1: US_Soldier_Base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class ACE_US_Soldier_Terp: US_Soldier_Base_EP1
	{
		scope = 2;
		accuracy = 3.7;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_TRANSLATOR";
		model = "\ca\characters_E\US\US_crewman_Light";
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
			core_ru = "Core_Full";
			core_cz = "Core_Full";
			core_tk = "Core_Full_E";
		};
		languages[] = {"EN","CZ","RU","TK"};
	};
	class ACE_US_Soldier_M224_G: US_Soldier_Base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_M224_G";
		accuracy = 1000;
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224Proxy"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224Proxy"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM"};
	};
	class ACE_US_Soldier_M224_AG: US_Soldier_Base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_M224_AG";
		accuracy = 1000;
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224TripodProxy"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M224TripodProxy"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM"};
	};
	class ACE_US_Soldier_M224_AB: US_Soldier_Base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_M224_AB";
		accuracy = 1000;
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM","ACE_M224HE_CSWDM"};
	};
	class ACE_US_Soldier_M252_G: US_Soldier_Base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_M252_G";
		accuracy = 1000;
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252Proxy"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252Proxy"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag"};
	};
	class ACE_US_Soldier_M252_AG: US_Soldier_Base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_M252_AG";
		accuracy = 1000;
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252TripodProxy"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_M252TripodProxy"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM"};
	};
	class ACE_US_Soldier_M252_AB: US_Soldier_Base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_M252_AB";
		accuracy = 1000;
		weapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM"};
		respawnWeapons[] = {"SCAR_L_STD_HOLO","NVGoggles","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","30Rnd_556x45_Stanag","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM","ACE_M252HE_CSWDM"};
	};
	class CZ_Soldier_base_EP1: SoldierWB
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
		languages[] = {"EN","CZ"};
		class TalkTopics: TalkTopics
		{
			core_cz = "Core_Full";
		};
	};
	class CZ_Special_Forces_DES_EP1: CZ_Soldier_base_EP1
	{
		ACE_Stamina = 0.8;
	};
	class CZ_Special_Forces_Scout_DES_EP1: CZ_Soldier_base_EP1
	{
		ACE_Stamina = 0.8;
	};
	class CZ_Special_Forces_TL_DES_EP1: CZ_Soldier_base_EP1
	{
		ACE_Stamina = 0.8;
	};
	class CZ_Special_Forces_GL_DES_EP1: CZ_Soldier_base_EP1
	{
		ACE_Stamina = 0.8;
	};
	class CZ_Special_Forces_MG_DES_EP1: CZ_Soldier_base_EP1
	{
		ACE_Stamina = 0.8;
	};
	class CZ_Soldier_DES_EP1: CZ_Soldier_base_EP1
	{
		class TalkTopics;
	};
	class ACE_CZ_Soldier_DES_Terp: CZ_Soldier_DES_EP1
	{
		scope = 2;
		accuracy = 3.7;
		model = "\CA\characters_E\ACR\acr_soldier_nic";
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_TRANSLATOR";
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
			core_ru = "Core_Full";
			core_cz = "Core_Full";
			core_tk = "Core_Full_E";
		};
		languages[] = {"EN","CZ","RU","TK"};
	};
	class CZ_Soldier_medik_DES_EP1: CZ_Soldier_DES_EP1
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
	};
	class ACE_CZ_Medic_EP1: CZ_Soldier_DES_EP1
	{
		scope = 1;
		ace_bwc = 1;
	};
	class CZ_Soldier_Office_DES_EP1: CZ_Soldier_base_EP1
	{
		weaponSlots = "1 + 4 + 6* 256 + 2* 4096 + 2 + 4* 16 + 12*131072";
	};
	class CZ_Soldier_Pilot_EP1: CZ_Soldier_base_EP1
	{
		weaponSlots = "1 + 4 + 8* 256 + 2* 4096 + 2 + 4* 16 + 12*131072";
	};
	class CZ_Soldier_Base_ACR: CZ_Soldier_base_EP1{};
	class CZ_Soldier_Crew_Dst_ACR: CZ_Soldier_Base_ACR{};
	class CZ_Soldier_Crew_Wdl_ACR: CZ_Soldier_Crew_Dst_ACR
	{
		weaponSlots = "1 + 4 + 6* 256 + 2* 4096 + 2 + 4* 16 + 12*131072";
	};
	class CZ_Soldier_Medic_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weaponSlots = "1  +  4  + 12*  256  + 2* 4096  +  2  + 8* 16  + 12*131072";
	};
	class CZ_Soldier_Pilot_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		weaponSlots = "1 + 4 + 8* 256 + 2* 4096 + 2 + 4* 16 + 12*131072";
	};
	class CZ_Soldier_Recon_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		ACE_Stamina = 0.8;
	};
	class CZ_Soldier_Spec1_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		ACE_Stamina = 0.8;
	};
	class UN_CDF_Soldier_base_EP1: SoldierGB
	{
		languages[] = {"EN","CZ"};
		class TalkTopics: TalkTopics
		{
			core_cz = "Core_Full";
		};
	};
	class UN_CDF_Soldier_EP1: UN_CDF_Soldier_base_EP1
	{
		class TalkTopics;
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class UN_CDF_Soldier_AT_EP1: UN_CDF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class UN_CDF_Soldier_MG_EP1: UN_CDF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class UN_CDF_Soldier_SL_EP1: UN_CDF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class UN_CDF_Soldier_Guard_EP1: UN_CDF_Soldier_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class ACE_UN_CDF_Medic_EP1: UN_CDF_Soldier_EP1
	{
		accuracy = 3.7;
		displayName = "$STR_EP1_DN_US_SOLDIER_MEDIC_EP1";
		attendant = 1;
		icon = "\Ca\characters2\data\icon\i_medic_CA.paa";
		weapons[] = {"AKS_74","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
		magazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","SmokeShell","SmokeShell","SmokeShell"};
		respawnWeapons[] = {"AKS_74","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Rucksack_EAST_Medic"};
		respawnMagazines[] = {"30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","30Rnd_545x39_AK","SmokeShell","SmokeShell"};
	};
	class TK_Soldier_base_EP1: SoldierEB
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class TK_Soldier_Officer_EP1: TK_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class TK_Soldier_Crew_EP1: TK_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class TK_Soldier_Pilot_EP1: TK_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.7;
			};
		};
	};
	class TK_Special_Forces_EP1: TK_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class TK_Aziz_EP1: TK_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class TK_Commander_EP1: TK_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class ACE_TK_Soldier_2B14_G: TK_Soldier_base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_2B14_G";
		accuracy = 1000;
		weapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_2b14Proxy"};
		magazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL"};
		respawnWeapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_2b14Proxy"};
		respawnMagazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL"};
	};
	class ACE_TK_Soldier_2B14_AG: TK_Soldier_base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_2B14_AG";
		accuracy = 1000;
		weapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_2b14TripodProxy"};
		magazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM"};
		respawnWeapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs","ACE_2b14TripodProxy"};
		respawnMagazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM"};
	};
	class ACE_TK_Soldier_2B14_AB: TK_Soldier_base_EP1
	{
		scope = 2;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_2B14_AB";
		accuracy = 1000;
		weapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		magazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM"};
		respawnWeapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_Earplugs"};
		respawnMagazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM","ACE_2B14HE_CSWDM"};
	};
	class ACE_TK_Soldier_KonkursG: TK_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_ACE_SOLDIERE_KONKURSG";
		accuracy = 1000;
		scope = 2;
		weapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_KonkursTripodProxy"};
		magazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","Smokeshell","Smokeshell"};
		respawnWeapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio","ACE_KonkursTripodProxy"};
		respawnMagazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","Smokeshell"};
	};
	class ACE_TK_Soldier_KonkursAG: TK_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_ACE_SOLDIERE_KONKURSAB";
		accuracy = 1000;
		scope = 2;
		weapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","Smokeshell","ACE_Konkurs_CSWDM","ACE_Konkurs_CSWDM"};
		respawnWeapons[] = {"FN_FAL","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnMagazines[] = {"20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","20Rnd_762x51_FNFAL","Smokeshell","ACE_Konkurs_CSWDM"};
	};
	class TK_INS_Soldier_Base_EP1: SoldierEB
	{
		accuracy = 2;
	};
	class TK_INS_Soldier_EP1: TK_INS_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class TK_INS_Soldier_2_EP1: TK_INS_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class TK_INS_Soldier_3_EP1: TK_INS_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class TK_INS_Soldier_4_EP1: TK_INS_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class ACE_TK_INS_Soldier_AKM_EP1: TK_INS_Soldier_EP1
	{
		displayname = "$STR_ACE_VDN_ACE_TK_INS_SOLDIER_AKM";
		weapons[] = {"AK_47_M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		magazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47","Handgrenade_east"};
		respawnweapons[] = {"AK_47_M","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnmagazines[] = {"30Rnd_762x39_AK47","30Rnd_762x39_AK47","30Rnd_762x39_AK47"};
	};
	class ACE_TK_INS_Soldier_AKMS_EP1: ACE_TK_INS_Soldier_AKM_EP1
	{
		displayname = "$STR_ACE_VDN_ACE_TK_INS_SOLDIER_AKMS";
		weapons[] = {"AK_47_S","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
		respawnweapons[] = {"AK_47_S","Throw","Put","ItemMap","ItemCompass","ItemWatch","ItemRadio"};
	};
	class TK_GUE_Soldier_Base_EP1: SoldierGB
	{
		accuracy = 2;
	};
	class TK_GUE_Soldier_EP1: TK_GUE_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class TK_GUE_Soldier_2_EP1: TK_GUE_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class TK_GUE_Soldier_3_EP1: TK_GUE_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class TK_GUE_Soldier_4_EP1: TK_GUE_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class TK_GUE_Soldier_5_EP1: TK_GUE_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class CIV_Contractor1_BAF: SoldierGB
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class BAF_Soldier_base_EP1: SoldierWB
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class BAF_crewman_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class BAF_Soldier_MTP: BAF_Soldier_base_EP1
	{
		class TalkTopics;
	};
	class BAF_Soldier_L_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class BAF_Soldier_SL_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class BAF_Soldier_Marksman_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class BAF_Soldier_scout_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class BAF_Soldier_spotter_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.6;
			};
		};
	};
	class BAF_Soldier_FAC_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class BAF_Soldier_EN_MTP: BAF_Soldier_base_EP1
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.85;
			};
		};
	};
	class ACE_BAF_Soldier_MTP_Terp: BAF_Soldier_MTP
	{
		scope = 2;
		accuracy = 3.7;
		displayName = "$STR_ACE_VDN_ACE_SOLDIER_TRANSLATOR";
		class TalkTopics: TalkTopics
		{
			core_en = "Core_Full_E";
			core_ru = "Core_Full";
			core_cz = "Core_Full";
			core_tk = "Core_Full_E";
		};
		languages[] = {"EN","CZ","RU","TK"};
	};
	class ACE_BAF_Soldier_DDPM_Terp: ACE_BAF_Soldier_MTP_Terp
	{
		vehicleClass = "MenDDPM";
	};
	class Soldier_Base_PMC: SoldierGB{};
	class Soldier_Pilot_PMC: Soldier_Base_PMC
	{
		class HitPoints: HitPoints
		{
			class HitHead: HitHead
			{
				armor = 0.7;
			};
		};
	};
	class TK_CIV_Takistani_Base_EP1: Civilian
	{
		accuracy = 2;
	};
	class TK_CIV_Takistani04_EP1;
	class ACE_TK_CIV_Takistani_Doctor_EP1: TK_CIV_Takistani04_EP1
	{
		displayName = "$STR_ACE_VDN_ACE_TK_CIV_TAKISTANI_DOCTOR";
		attendant = 1;
	};
};
class CfgGroups
{
	class West
	{
		class BIS_US
		{
			class ACE_CSWInfantry
			{
				name = "$STR_ACE_GN_CSWTEAM";
				class ACE_US_M224Team
				{
					name = "$STR_ACE_GN_ACE_M224TEAM";
					faction = "BIS_US";
					rarityGroup = 0.3;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M224_G";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M224_AG";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M224_AB";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M224_AB";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
				};
				class ACE_US_M252Team
				{
					name = "$STR_ACE_GN_ACE_M252TEAM";
					faction = "BIS_US";
					rarityGroup = 0.3;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M252_G";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M252_AG";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M252_AB";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_US_Soldier_M252_AB";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
				};
			};
		};
	};
	class east
	{
		class BIS_TK
		{
			class ACE_CSWInfantry
			{
				name = "$STR_ACE_GN_CSWTEAM";
				class ACE_TK_2B14Team
				{
					name = "$STR_ACE_GN_ACE_2B14TEAM";
					faction = "BIS_TK";
					rarityGroup = 0.2;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_TK_Soldier_2B14_G";
						rank = "CORPORAL";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_TK_Soldier_2B14_AG";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_TK_Soldier_2B14_AB";
						rank = "PRIVATE";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "ACE_TK_Soldier_2B14_AB";
						rank = "PRIVATE";
						position[] = {7,0,0};
					};
				};
				class ACE_TK_KonkursTeam
				{
					name = "$STR_ACE_VDN_ACE_KONKURST";
					class Unit0
					{
						side = 0;
						vehicle = "ACE_TK_Soldier_KonkursG";
						rank = "SERGEANT";
						position[] = {0,"+6",0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_TK_Soldier_KonkursAG";
						rank = "CORPORAL";
						position[] = {-2,"+4",0};
					};
				};
			};
		};
	};
};
//};
