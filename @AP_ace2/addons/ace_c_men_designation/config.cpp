////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:43:08 2013 : Created on Sat Apr 06 11:43:08 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_men_designation : config.bin{
class CfgPatches
{
	class ace_c_men_designation
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CACharacters","CACharacters2","CACharacters_e","ace_main"};
		version = "1.14.0.590";
	};
};
class CfgVehicles
{
	class CAManBase;
	class SoldierWB: CAManBase
	{
		displayName = "$STR_DN_SOLDIER";
	};
	class SoldierEB: CAManBase
	{
		displayName = "$STR_DN_SOLDIER";
	};
	class SoldierGB: CAManBase
	{
		displayName = "$STR_DN_SOLDIER";
	};
	class USMC_Soldier_Base: SoldierWB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class USMC_Soldier: USMC_Soldier_Base
	{
		accuracy = 1000;
	};
	class USMC_Soldier_Light: USMC_Soldier_Base
	{
		accuracy = 1000;
	};
	class USMC_Soldier2: USMC_Soldier_Base
	{
		accuracy = 1000;
	};
	class USMC_Soldier_AT_Base: USMC_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class USMC_Soldier_LAT: USMC_Soldier_AT_Base
	{
		accuracy = 1000;
	};
	class USMC_Soldier_HAT: USMC_Soldier_AT_Base
	{
		accuracy = 1000;
	};
	class USMC_Soldier_AT: USMC_Soldier_AT_Base
	{
		accuracy = 1000;
	};
	class USMC_Soldier_AA: USMC_Soldier_AT_Base
	{
		displayName = "$STR_ACE_VDN_AASPECIALIST";
	};
	class USMC_Soldier_AR: USMC_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class USMC_Soldier_MG: USMC_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class USMC_SoldierM_Marksman: USMC_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_DESIGNATEDMARKSMAN";
	};
	class USMC_LHD_Crew_Base: USMC_Soldier_Base
	{
		faction = "ACE_USNAVY";
	};
	class CDF_Soldier_Base: SoldierWB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class CDF_Soldier: CDF_Soldier_Base
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class CDF_Soldier_Light: CDF_Soldier_Base
	{
		accuracy = 1000;
	};
	class CDF_Soldier_AR: CDF_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class CDF_Soldier_MG: CDF_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class CDF_Soldier_Medic: CDF_Soldier_Base{};
	class CDF_Soldier_RPG: CDF_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class CDF_Soldier_Marksman: CDF_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MARKSMAN";
	};
	class CDF_Soldier_Strela: CDF_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_AASPECIALIST";
	};
	class FR_Base: SoldierWB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class FR_AR: FR_Base
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class RU_Soldier_Base: SoldierEB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class RU_Soldier: RU_Soldier_Base
	{
		accuracy = 1000;
	};
	class RU_Soldier2: RU_Soldier_Base
	{
		accuracy = 1000;
	};
	class RU_Soldier_MG: RU_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class RU_Soldier_AR: RU_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class RU_Soldier_AT: RU_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class RU_Soldier_AA: RU_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_AASPECIALIST";
	};
	class RU_Soldier_Marksman: RU_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MARKSMAN";
	};
	class MVD_Soldier_Base: SoldierEB{};
	class MVD_Soldier_Marksman: MVD_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MARKSMAN";
	};
	class MVD_Soldier: MVD_Soldier_Base{};
	class MVD_Soldier_MG: MVD_Soldier
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class MVD_Soldier_AT: MVD_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class GUE_Soldier_Base: SoldierGB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class GUE_Soldier_1: GUE_Soldier_Base
	{
		accuracy = 1000;
	};
	class GUE_Soldier_2: GUE_Soldier_Base
	{
		accuracy = 1000;
	};
	class GUE_Soldier_3: GUE_Soldier_Base
	{
		accuracy = 1000;
	};
	class GUE_Soldier_AA: GUE_Soldier_Base{};
	class GUE_Soldier_AR: GUE_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class GUE_Soldier_MG: GUE_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class GUE_Soldier_Sniper: GUE_Soldier_Base
	{
		displayName = "$STR_DN_SNIPER";
	};
	class GUE_Soldier_AT: GUE_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class Ins_Soldier_Base: SoldierEB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class Ins_Soldier_1: Ins_Soldier_Base
	{
		accuracy = 1000;
	};
	class Ins_Soldier_2: Ins_Soldier_Base
	{
		accuracy = 1000;
	};
	class Ins_Soldier_AR: Ins_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class Ins_Soldier_MG: Ins_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class Ins_Soldier_AA: Ins_Soldier_Base{};
	class Ins_Soldier_AT: Ins_Soldier_Base
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class GER_Soldier_base_EP1: SoldierWB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class GER_Soldier_EP1: GER_Soldier_base_EP1
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class GER_Soldier_Medic_EP1: GER_Soldier_base_EP1
	{
		displayName = "$STR_DN_MEDIC";
	};
	class GER_Soldier_TL_EP1: GER_Soldier_base_EP1
	{
		displayName = "$STR_DN_TEAMLEADER";
	};
	class GER_Soldier_Scout_EP1: GER_Soldier_base_EP1
	{
		displayName = "$STR_DN_SCOUT";
	};
	class GER_Soldier_MG_EP1: GER_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class US_Soldier_Base_EP1: SoldierWB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class US_Soldier_EP1: US_Soldier_Base_EP1
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class US_Soldier_B_EP1: US_Soldier_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_AMG_EP1: US_Soldier_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_AAR_EP1: US_Soldier_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_AHAT_EP1: US_Soldier_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_AAT_EP1: US_Soldier_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_Light_EP1: US_Soldier_Base_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_AT_Base_EP1: US_Soldier_Base_EP1
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class US_Soldier_LAT_EP1: US_Soldier_AT_Base_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_AT_EP1: US_Soldier_AT_Base_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_HAT_EP1: US_Soldier_AT_Base_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_AA_EP1: US_Soldier_AT_Base_EP1
	{
		displayName = "$STR_ACE_VDN_AASPECIALIST";
	};
	class US_Soldier_AR_EP1: US_Soldier_Base_EP1
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class US_Soldier_MG_EP1: US_Soldier_Base_EP1
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class US_Soldier_Sniper_EP1: US_Soldier_Base_EP1{};
	class US_Soldier_Sniper_NV_EP1: US_Soldier_Sniper_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_SniperH_EP1: US_Soldier_Sniper_EP1
	{
		accuracy = 1000;
	};
	class US_Soldier_Marksman_EP1: US_Soldier_Base_EP1
	{
		displayName = "$STR_ACE_VDN_MARKSMAN";
	};
	class US_Delta_Force_EP1: US_Soldier_Base_EP1{};
	class US_Delta_Force_Assault_EP1: US_Delta_Force_EP1
	{
		accuracy = 1000;
	};
	class US_Delta_Force_SD_EP1: US_Delta_Force_EP1
	{
		accuracy = 1000;
	};
	class US_Delta_Force_MG_EP1: US_Delta_Force_EP1
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class US_Delta_Force_AR_EP1: US_Delta_Force_EP1
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class US_Delta_Force_Night_EP1: US_Delta_Force_EP1
	{
		accuracy = 1000;
	};
	class US_Delta_Force_Marksman_EP1: US_Delta_Force_EP1
	{
		displayName = "$STR_ACE_VDN_MARKSMAN";
	};
	class US_Delta_Force_M14_EP1: US_Delta_Force_EP1
	{
		accuracy = 1000;
	};
	class CZ_Soldier_base_EP1: SoldierWB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class CZ_Soldier_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_SL_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Office_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_B_DES_EP1: CZ_Soldier_DES_EP1
	{
		accuracy = 1000;
	};
	class CZ_Soldier_AMG_DES_EP1: CZ_Soldier_DES_EP1
	{
		accuracy = 1000;
	};
	class CZ_Soldier_AT_DES_EP1: CZ_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_MG_DES_EP1: CZ_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Light_DES_EP1: CZ_Soldier_base_EP1
	{
		accuracy = 1000;
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Pilot_EP1: CZ_Soldier_base_EP1
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Sniper_EP1: CZ_Soldier_base_EP1
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Special_Forces_Scout_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleClass = "ACE_SFMenD";
		displayName = "$STR_DN_SCOUT";
	};
	class CZ_Special_Forces_MG_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleClass = "ACE_SFMenD";
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class CZ_Special_Forces_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleClass = "ACE_SFMenD";
		displayName = "$STR_DN_RIFLEMAN";
	};
	class CZ_Special_Forces_TL_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleClass = "ACE_SFMenD";
		displayName = "$STR_DN_TEAMLEADER";
	};
	class CZ_Special_Forces_GL_DES_EP1: CZ_Soldier_base_EP1
	{
		vehicleClass = "ACE_SFMenD";
		displayName = "$STR_DN_GRENADIER";
	};
	class CZ_Soldier_Base_ACR: CZ_Soldier_base_EP1{};
	class CZ_Soldier_805_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		accuracy = 1000;
	};
	class CZ_Soldier_805g_Dst_ACR: CZ_Soldier_Base_ACR
	{
		accuracy = 1000;
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Crew_Dst_ACR: CZ_Soldier_Base_ACR
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_MG_Wdl_ACR: CZ_Soldier_Base_ACR{};
	class CZ_Soldier_MG2_Wdl_ACR: CZ_Soldier_MG_Wdl_ACR{};
	class CZ_Soldier_MG2_Dst_ACR: CZ_Soldier_MG2_Wdl_ACR
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Recon_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		vehicleClass = "ACE_SFMenW";
	};
	class CZ_Soldier_Spec1_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		vehicleClass = "ACE_SFMenW";
	};
	class CZ_Soldier_Spec3_Wdl_ACR: CZ_Soldier_Spec1_Wdl_ACR
	{
		vehicleClass = "ACE_SFMenW";
	};
	class CZ_Soldier_Spec_Demo_Wdl_ACR: CZ_Soldier_Recon_Wdl_ACR
	{
		vehicleClass = "ACE_SFMenW";
	};
	class CZ_Soldier_Spec_Demo_Dst_ACR: CZ_Soldier_Spec_Demo_Wdl_ACR
	{
		vehicleClass = "ACE_SFMenD";
	};
	class CZ_Soldier_RPG_Dst_ACR: CZ_Soldier_Base_ACR
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Engineer_Dst_ACR: CZ_Soldier_Base_ACR
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Soldier_Light_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		accuracy = 1000;
	};
	class CZ_Soldier_RPG_Ass_Dst_ACR: CZ_Soldier_Base_ACR
	{
		vehicleclass = "MenDDPM";
	};
	class CZ_Sharpshooter_DES_ACR: CZ_Soldier_base_EP1
	{
		vehicleclass = "MenDDPM";
	};
	class UN_CDF_Soldier_base_EP1: SoldierGB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class UN_CDF_Soldier_EP1: UN_CDF_Soldier_base_EP1
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class UN_CDF_Soldier_B_EP1: UN_CDF_Soldier_EP1
	{
		accuracy = 1000;
	};
	class UN_CDF_Soldier_AAT_EP1: UN_CDF_Soldier_EP1
	{
		accuracy = 1000;
	};
	class UN_CDF_Soldier_AMG_EP1: UN_CDF_Soldier_EP1
	{
		accuracy = 1000;
	};
	class UN_CDF_Soldier_AT_EP1: UN_CDF_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class UN_CDF_Soldier_MG_EP1: UN_CDF_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class UN_CDF_Soldier_Light_EP1: UN_CDF_Soldier_base_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_base_EP1: SoldierEB
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class TK_Soldier_EP1: TK_Soldier_base_EP1
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class TK_Soldier_B_EP1: TK_Soldier_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_AAT_EP1: TK_Soldier_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_AMG_EP1: TK_Soldier_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_AT_EP1: TK_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_RPGGRENADIER";
	};
	class TK_Soldier_HAT_EP1: TK_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_ATSPECIALIST";
	};
	class TK_Soldier_AA_EP1: TK_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_AASPECIALIST";
	};
	class TK_Soldier_MG_EP1: TK_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class TK_Soldier_AR_EP1: TK_Soldier_base_EP1
	{
		displayName = "$STR_ACE_VDN_AUTOMATICRIFLEMAN";
	};
	class TK_Soldier_Sniper_EP1: TK_Soldier_base_EP1{};
	class TK_Soldier_SniperH_EP1: TK_Soldier_Sniper_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_Sniper_Night_EP1: TK_Soldier_Sniper_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_Night_1_EP1: TK_Soldier_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_Night_2_EP1: TK_Soldier_EP1
	{
		accuracy = 1000;
	};
	class TK_Soldier_TWS_EP1: TK_Soldier_EP1
	{
		accuracy = 1000;
	};
	class TK_Special_Forces_EP1: TK_Soldier_base_EP1
	{
		displayName = "$STR_DN_RIFLEMAN";
	};
	class TK_Special_Forces_TL_EP1: TK_Special_Forces_EP1
	{
		displayName = "$STR_DN_TEAMLEADER";
	};
	class TK_Special_Forces_MG_EP1: TK_Special_Forces_EP1
	{
		displayName = "$STR_ACE_VDN_MACHINEGUNNER";
	};
	class TK_INS_Soldier_Base_EP1: SoldierEB
	{
		displayName = "$STR_ACE_VDN_MILITIAMAN";
	};
	class TK_GUE_Soldier_Base_EP1: SoldierGB
	{
		displayName = "$STR_ACE_VDN_GUERILLA";
	};
	class US_Delta_Force_Undercover_Takistani_Base_EP1: TK_GUE_Soldier_Base_EP1
	{
		accuracy = 3.99;
	};
};
//};
