////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:30 2013 : Created on Mon Oct 14 23:07:30 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_magazines : config.bin{
class CfgPatches
{
	class ace_sys_magazines
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_interaction"};
		version = "1.14.0.597";
		author[] = {"q1184","Sickboy"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_magazines
	{
		clientInit = "call ('\x\ace\addons\sys_magazines\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_magazines
	{
		clientInit = "call ('\x\ace\addons\sys_magazines\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class cfgMagazines
{
	class Default;
	class CA_Magazine: Default
	{
		ace_suppressed = 0;
	};
	class 30Rnd_545x39_AK: CA_Magazine
	{
		ace_suppmag = "ACE_30Rnd_545x39_S_AK";
	};
	class ACE_30Rnd_545x39_S_AK: 30Rnd_545x39_AK
	{
		ace_suppressed = 1;
	};
	class ACE_30Rnd_545x39_EP_AK: 30Rnd_545x39_AK
	{
		ace_suppmag = "ACE_30Rnd_545x39_EP_S_AK";
	};
	class ACE_30Rnd_545x39_EP_S_AK: ACE_30Rnd_545x39_EP_AK
	{
		ace_suppressed = 1;
	};
	class ACE_30Rnd_545x39_AP_AK: 30Rnd_545x39_AK
	{
		ace_suppmag = "ACE_30Rnd_545x39_AP_S_AK";
	};
	class ACE_30Rnd_545x39_AP_S_AK: ACE_30Rnd_545x39_AP_AK
	{
		ace_suppressed = 1;
	};
	class ACE_45Rnd_545x39_B_AK: 30Rnd_545x39_AK
	{
		ace_suppmag = "ACE_45Rnd_545x39_S_AK";
	};
	class ACE_45Rnd_545x39_S_AK: ACE_45Rnd_545x39_B_AK
	{
		ace_suppressed = 1;
	};
	class ACE_45Rnd_545x39_EP_AK: ACE_45Rnd_545x39_B_AK
	{
		ace_suppmag = "ACE_45Rnd_545x39_EP_S_AK";
	};
	class ACE_45Rnd_545x39_EP_S_AK: ACE_45Rnd_545x39_EP_AK
	{
		ace_suppressed = 1;
	};
	class ACE_45Rnd_545x39_AP_AK: ACE_45Rnd_545x39_B_AK
	{
		ace_suppmag = "ACE_45Rnd_545x39_AP_S_AK";
	};
	class ACE_45Rnd_545x39_AP_S_AK: ACE_45Rnd_545x39_AP_AK
	{
		ace_suppressed = 1;
	};
	class 30Rnd_545x39_AKSD: 30Rnd_545x39_AK
	{
		ace_suppressed = 1;
		ace_suppmag = "30Rnd_545x39_AKSD";
	};
	class 30Rnd_762x39_AK47: CA_Magazine
	{
		ace_suppmag = "ACE_30Rnd_762x39_S_AK47";
	};
	class ACE_30Rnd_762x39_S_AK47: 30Rnd_762x39_AK47
	{
		ace_suppressed = 1;
	};
	class ACE_40Rnd_762x39_B_AK47: 30Rnd_762x39_AK47
	{
		ace_suppmag = "ACE_40Rnd_762x39_S_AK47";
	};
	class ACE_40Rnd_762x39_S_AK47: ACE_40Rnd_762x39_B_AK47
	{
		ace_suppressed = 1;
	};
	class ACE_75Rnd_762x39_B_AK47: 30Rnd_762x39_AK47
	{
		ace_suppmag = "ACE_75Rnd_762x39_S_AK47";
	};
	class ACE_75Rnd_762x39_S_AK47: ACE_75Rnd_762x39_B_AK47
	{
		ace_suppressed = 1;
	};
	class ACE_30Rnd_762x39_AP_AK47: 30Rnd_762x39_AK47
	{
		ace_suppmag = "ACE_30Rnd_762x39_AP_S_AK47";
	};
	class ACE_30Rnd_762x39_AP_S_AK47: ACE_30Rnd_762x39_AP_AK47
	{
		ace_suppressed = 1;
	};
	class ACE_40Rnd_762x39_AP_AK47: ACE_40Rnd_762x39_B_AK47
	{
		ace_suppmag = "ACE_40Rnd_762x39_AP_S_AK47";
	};
	class ACE_40Rnd_762x39_AP_S_AK47: ACE_40Rnd_762x39_AP_AK47
	{
		ace_suppressed = 1;
	};
	class ACE_75Rnd_762x39_SD_AK47: ACE_75Rnd_762x39_B_AK47
	{
		ace_suppressed = 1;
		ace_suppmag = "ACE_75Rnd_762x39_SD_AK47";
	};
	class ACE_30Rnd_762x39_SD_AK47: 30Rnd_762x39_AK47
	{
		ace_suppressed = 1;
		ace_suppmag = "ACE_30Rnd_762x39_SD_AK47";
	};
	class 75Rnd_545x39_RPK: CA_Magazine
	{
		ace_suppmag = "ACE_75Rnd_545x39_S_RPK";
	};
	class ACE_75Rnd_545x39_S_RPK: 75Rnd_545x39_RPK
	{
		ace_suppressed = 1;
	};
	class 20Rnd_556x45_Stanag: CA_Magazine
	{
		ace_suppmag = "ACE_20Rnd_556x45_S_Stanag";
	};
	class ACE_20Rnd_556x45_S_Stanag: 20Rnd_556x45_Stanag
	{
		ace_suppressed = 1;
	};
	class 30Rnd_556x45_Stanag: 20Rnd_556x45_Stanag
	{
		ace_suppmag = "ACE_30Rnd_556x45_S_Stanag";
	};
	class ACE_30Rnd_556x45_S_Stanag: 30Rnd_556x45_Stanag
	{
		ace_suppressed = 1;
	};
	class ACE_30Rnd_556x45_SB_Stanag: 30Rnd_556x45_Stanag
	{
		ace_suppmag = "ACE_30Rnd_556x45_SB_S_Stanag";
	};
	class ACE_30Rnd_556x45_SB_S_Stanag: ACE_30Rnd_556x45_SB_Stanag
	{
		ace_suppressed = 1;
	};
	class 30Rnd_556x45_StanagSD: 30Rnd_556x45_Stanag
	{
		ace_suppressed = 1;
		ace_suppmag = "30Rnd_556x45_StanagSD";
	};
	class 30Rnd_556x45_G36: 30Rnd_556x45_Stanag
	{
		ace_suppmag = "ACE_30Rnd_556x45_S_G36";
	};
	class ACE_30Rnd_556x45_S_G36: 30Rnd_556x45_G36
	{
		ace_suppressed = 1;
	};
	class 30Rnd_556x45_G36SD: 30Rnd_556x45_G36
	{
		ace_suppressed = 1;
		ace_suppmag = "30Rnd_556x45_G36SD";
	};
	class ACE_30Rnd_556x45_AP_G36: 30Rnd_556x45_G36
	{
		ace_suppmag = "ACE_30Rnd_556x45_AP_S_G36";
	};
	class ACE_30Rnd_556x45_AP_S_G36: ACE_30Rnd_556x45_AP_G36
	{
		ace_suppressed = 1;
	};
	class 100Rnd_556x45_BetaCMag: CA_Magazine
	{
		ace_suppmag = "ACE_100Rnd_556x45_S_BetaCMag";
	};
	class ACE_100Rnd_556x45_S_BetaCMag: 100Rnd_556x45_BetaCMag
	{
		ace_suppressed = 1;
	};
	class 30Rnd_9x19_MP5: CA_Magazine
	{
		ace_suppmag = "ACE_30Rnd_9x19_S_MP5";
	};
	class ACE_30Rnd_9x19_S_MP5: 30Rnd_9x19_MP5
	{
		ace_suppressed = 1;
	};
	class 30Rnd_9x19_MP5SD: CA_Magazine
	{
		ace_suppressed = 1;
		ace_suppmag = "30Rnd_9x19_MP5SD";
	};
	class 20Rnd_9x19_EVO: 30Rnd_9x19_MP5
	{
		ace_suppmag = "ACE_30Rnd_9x19_S_EVO";
	};
	class ACE_30Rnd_9x19_S_EVO: 20Rnd_9x19_EVO
	{
		ace_suppressed = 1;
	};
	class 20Rnd_9x19_EVOSD: 30Rnd_9x19_MP5SD
	{
		ace_suppressed = 1;
		ace_suppmag = "20Rnd_9x19_EVOSD";
	};
	class 64Rnd_9x19_Bizon: CA_Magazine
	{
		ace_suppmag = "ACE_64Rnd_9x19_S_Bizon";
	};
	class ACE_64Rnd_9x19_S_Bizon: 64Rnd_9x19_Bizon
	{
		ace_suppressed = 1;
	};
	class 64Rnd_9x19_SD_Bizon: CA_Magazine
	{
		ace_suppressed = 1;
		ace_suppmag = "64Rnd_9x19_SD_Bizon";
	};
	class ACE_25Rnd_1143x23_B_UMP45: 30Rnd_9x19_MP5
	{
		ace_suppmag = "ACE_25Rnd_1143x23_S_UMP45";
	};
	class ACE_25Rnd_1143x23_S_UMP45: ACE_25Rnd_1143x23_B_UMP45
	{
		ace_suppressed = 1;
	};
	class ACE_40Rnd_B_46x30_MP7: 30Rnd_9x19_MP5
	{
		ace_suppmag = "ACE_40Rnd_S_46x30_MP7";
	};
	class ACE_40Rnd_S_46x30_MP7: ACE_40Rnd_B_46x30_MP7
	{
		ace_suppressed = 1;
	};
	class 20Rnd_762x51_DMR: CA_Magazine
	{
		ace_suppmag = "ACE_20Rnd_762x51_S_DMR";
	};
	class ACE_20Rnd_762x51_S_DMR: 20Rnd_762x51_DMR
	{
		ace_suppressed = 1;
	};
	class ACE_20Rnd_762x51_B_M14: 20Rnd_762x51_DMR
	{
		ace_suppmag = "ACE_20Rnd_762x51_S_M14";
	};
	class ACE_20Rnd_762x51_S_M14: ACE_20Rnd_762x51_B_M14
	{
		ace_suppressed = 1;
	};
	class 20Rnd_762x51_B_SCAR: CA_Magazine
	{
		ace_suppmag = "ACE_20Rnd_762x51_S_SCAR";
	};
	class ACE_20Rnd_762x51_S_SCAR: 20Rnd_762x51_B_SCAR
	{
		ace_suppressed = 1;
	};
	class ACE_20Rnd_762x51_SB_SCAR: 20Rnd_762x51_B_SCAR
	{
		ace_suppmag = "ACE_20Rnd_762x51_SB_S_SCAR";
	};
	class ACE_20Rnd_762x51_SB_S_SCAR: ACE_20Rnd_762x51_SB_SCAR
	{
		ace_suppressed = 1;
	};
	class 20Rnd_762x51_SB_SCAR: CA_Magazine
	{
		ace_suppressed = 1;
		ace_suppmag = "20Rnd_762x51_SB_SCAR";
	};
	class ACE_20Rnd_762x51_B_HK417: 20Rnd_762x51_B_SCAR
	{
		ace_suppmag = "ACE_20Rnd_762x51_S_HK417";
	};
	class ACE_20Rnd_762x51_S_HK417: ACE_20Rnd_762x51_B_HK417
	{
		ace_suppressed = 1;
	};
	class ACE_20Rnd_762x51_SB_HK417: ACE_20Rnd_762x51_B_HK417
	{
		ace_suppmag = "ACE_20Rnd_762x51_SB_S_HK417";
	};
	class ACE_20Rnd_762x51_SB_S_HK417: ACE_20Rnd_762x51_SB_HK417
	{
		ace_suppressed = 1;
	};
	class ACE_20Rnd_762x51_SB_M110: 20Rnd_556x45_Stanag
	{
		ace_suppmag = "ACE_20Rnd_762x51_S_M110";
	};
	class ACE_20Rnd_762x51_S_M110: ACE_20Rnd_762x51_SB_M110
	{
		ace_suppressed = 1;
	};
	class 10Rnd_127x99_m107;
	class ACE_5Rnd_127x99_B_TAC50: 10Rnd_127x99_m107
	{
		ace_suppmag = "ACE_5Rnd_127x99_S_TAC50";
	};
	class ACE_5Rnd_127x99_S_TAC50: ACE_5Rnd_127x99_B_TAC50
	{
		ace_suppressed = 1;
	};
	class 10Rnd_9x39_SP5_VSS: CA_Magazine
	{
		ace_suppressed = 1;
	};
	class 20Rnd_9x39_SP5_VSS: CA_Magazine
	{
		ace_suppressed = 1;
	};
	class ACE_20Rnd_9x39_B_OC14: 20Rnd_9x39_SP5_VSS
	{
		ace_suppressed = 0;
		ace_suppmag = "ACE_20Rnd_9x39_S_OC14";
	};
	class ACE_20Rnd_9x39_S_OC14: ACE_20Rnd_9x39_B_OC14
	{
		ace_suppressed = 1;
	};
	class ACE_20Rnd_9x39_B_SP6_OC14: ACE_20Rnd_9x39_B_OC14
	{
		ace_suppmag = "ACE_20Rnd_9x39_S_SP6_OC14";
	};
	class ACE_20Rnd_9x39_S_SP6_OC14: ACE_20Rnd_9x39_B_SP6_OC14
	{
		ace_suppressed = 1;
	};
	class 8Rnd_9x18_Makarov: CA_Magazine
	{
		ace_suppmag = "8Rnd_9x18_MakarovSD";
	};
	class 8Rnd_9x18_MakarovSD: 8Rnd_9x18_Makarov
	{
		ace_suppressed = 1;
	};
	class 15Rnd_9x19_M9: CA_Magazine
	{
		ace_suppmag = "ACE_15Rnd_9x19_S_M9";
	};
	class ACE_15Rnd_9x19_S_M9: 15Rnd_9x19_M9
	{
		ace_suppressed = 1;
	};
	class 15Rnd_9x19_M9SD: 15Rnd_9x19_M9
	{
		ace_suppressed = 1;
		ace_suppmag = "15Rnd_9x19_M9SD";
	};
	class 30Rnd_9x19_UZI: CA_Magazine
	{
		ace_suppmag = "ACE_30Rnd_9x19_S_UZI";
	};
	class ACE_30Rnd_9x19_S_UZI: 30Rnd_9x19_UZI
	{
		ace_suppressed = 1;
	};
	class 30Rnd_9x19_UZI_SD: CA_Magazine
	{
		ace_suppressed = 1;
		ace_suppmag = "30Rnd_9x19_UZI_SD";
	};
	class 18Rnd_9x19_Phantom: 15Rnd_9x19_M9
	{
		ace_suppmag = "ACE_18Rnd_9x19_S_Phantom";
	};
	class ACE_18Rnd_9x19_S_Phantom: 18Rnd_9x19_Phantom
	{
		ace_suppressed = 1;
	};
	class ACE_16Rnd_9x19_CZ75: 18Rnd_9x19_Phantom
	{
		ace_suppmag = "ACE_16Rnd_9x19_S_CZ75";
	};
	class ACE_16Rnd_9x19_S_CZ75: ACE_16Rnd_9x19_CZ75
	{
		ace_suppressed = 1;
	};
	class 18Rnd_9x19_PhantomSD: 15Rnd_9x19_M9SD
	{
		ace_suppressed = 1;
		ace_suppmag = "18Rnd_9x19_PhantomSD";
	};
	class 8Rnd_B_Beneli_Pellets: CA_Magazine
	{
		ace_sys_magazines_loose_cartridges = 1;
	};
	class 8Rnd_B_Beneli_74Slug: CA_Magazine
	{
		ace_sys_magazines_loose_cartridges = 1;
	};
	class 5Rnd_762x51_M24: CA_Magazine
	{
		ace_sys_magazines_loose_cartridges = 1;
	};
	class 10Rnd_762x51_CZ750: 5Rnd_762x51_M24
	{
		ace_sys_magazines_loose_cartridges = 0;
	};
	class 5x_22_LR_17_HMR: CA_Magazine
	{
		ace_sys_magazines_loose_cartridges = 1;
	};
	class 1Rnd_HE_M203: CA_Magazine
	{
		ace_sys_magazines_loose_cartridges = 1;
	};
	class FlareWhite_M203: CA_Magazine
	{
		ace_sys_magazines_loose_cartridges = 1;
	};
	class 100Rnd_762x51_M240: CA_Magazine
	{
		ace_sys_magazines_belt = 1;
	};
	class 100Rnd_762x54_PK: CA_Magazine
	{
		ace_sys_magazines_belt = 1;
	};
	class 200Rnd_556x45_M249: CA_Magazine
	{
		ace_sys_magazines_belt = 1;
	};
};
class CfgWeapons
{
	class RifleCore;
	class Rifle: RifleCore
	{
		ace_suppressed = 0;
	};
	class MP5SD: Rifle
	{
		ace_suppressed = 1;
	};
	class MP5A5: MP5SD
	{
		ace_suppressed = 0;
	};
	class M4A1;
	class M4A1_Aim: M4A1{};
	class M4A1_AIM_SD_camo: M4A1_Aim
	{
		ace_suppressed = 1;
	};
	class G36C;
	class G36_C_SD_eotech: G36C
	{
		ace_suppressed = 1;
	};
	class SCAR_L_CQC;
	class SCAR_L_CQC_CCO_SD: SCAR_L_CQC
	{
		ace_suppressed = 1;
	};
	class AKS_BASE;
	class AKS_74_UN_kobra: AKS_BASE
	{
		ace_suppressed = 1;
	};
	class bizon: Rifle{};
	class bizon_silenced: bizon
	{
		ace_suppressed = 1;
	};
	class VSS_vintorez: Rifle
	{
		ace_suppressed = 1;
	};
	class SCAR_H_Base;
	class SCAR_H_LNG_Sniper_SD: SCAR_H_Base
	{
		ace_suppressed = 1;
	};
	class SCAR_H_CQC_CCO;
	class SCAR_H_CQC_CCO_SD: SCAR_H_CQC_CCO
	{
		ace_suppressed = 1;
	};
	class m8_base;
	class m8_holo_sd: m8_base
	{
		ace_suppressed = 1;
	};
	class m8_tws_sd: m8_base
	{
		ace_suppressed = 1;
	};
	class M9;
	class M9SD: M9
	{
		ace_suppressed = 1;
	};
	class Makarov;
	class MakarovSD: Makarov
	{
		ace_suppressed = 1;
	};
	class UZI_EP1;
	class UZI_SD_EP1: UZI_EP1
	{
		ace_suppressed = 1;
	};
	class CZ805_A1_ACR: Rifle{};
	class CZ805_A2_ACR: CZ805_A1_ACR{};
	class CZ805_A2_SD_ACR: CZ805_A2_ACR
	{
		ace_suppressed = 1;
	};
};
//};
