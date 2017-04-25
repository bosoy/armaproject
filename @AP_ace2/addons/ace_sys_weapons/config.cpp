////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Dec 01 21:40:45 2012 : Created on Sat Dec 01 21:40:45 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_weapons : config.bin{
class CfgPatches
{
	class ace_sys_weapons
	{
		units[] = {"ace_sys_weapons_magicbox"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAData","CAWeapons","CAWeapons2","Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_crewserved","ace_sys_wirecutter"};
		version = "1.14.0.584";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_weapons
	{
		init = "call ('\x\ace\addons\sys_weapons\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_Eventhandlers
{
	class ace_sys_weapons_magicbox
	{
		ace_sys_weapons_init = "_this call ace_sys_weapons_fnc_init";
	};
};
class CfgFunctions
{
	class ACE
	{
		class Weapons
		{
			class changeLoadout
			{
				description = "changes the loadout of given unit";
				file = "\x\ace\Addons\sys_weapons\fnc_changeLoadout.sqf";
			};
			class enum
			{
				description = "Enumurates the available weapons and magazines for specified unit";
				file = "\x\ace\Addons\sys_weapons\fnc_enum.sqf";
			};
			class enumMagazines
			{
				description = "Enumurates the available Magazines for specified Weapon";
				file = "\x\ace\Addons\sys_weapons\fnc_enumMagazines.sqf";
			};
			class enumWeapons
			{
				description = "Enumurates the available weapons and their types for specified side and type";
				file = "\x\ace\Addons\sys_weapons\fnc_enumWeapons.sqf";
			};
			class swapM4forSCAR
			{
				description = "Switches M4 weapons for SCAR's";
				file = "\x\ace\Addons\sys_weapons\fnc_swapM4forSCAR.sqf";
			};
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class HandGrenade: CA_Magazine
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class HandGrenade_Stone: HandGrenade
	{
		ace_sys_weapons_SIDE[] = {"CIV"};
	};
	class HandGrenade_West: HandGrenade
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","PMC_BAF"};
	};
	class BAF_L109A1_HE: HandGrenade_West
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class HandGrenade_East: HandGrenade_West
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class ACE_DM51: HandGrenade_West
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class SmokeShell: HandGrenade
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
	};
	class ACE_RDG2: SmokeShell
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class ACE_RDGM: SmokeShell
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class ACE_M7A3: SmokeShell
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_RG60A: ACE_M7A3
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class ACE_M34: SmokeShell
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_ANM14: SmokeShell
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_DM25: SmokeShell
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class SmokeShellGreen;
	class ACE_DM31: SmokeShellGreen
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class SmokeShellOrange;
	class ACE_DM32: SmokeShellOrange
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class SmokeShellRed;
	class ACE_DM33: SmokeShellRed
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class SmokeShellPurple;
	class ACE_DM34: SmokeShellPurple
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class SmokeShellYellow;
	class ACE_DM36: SmokeShellYellow
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class ACE_Flashbang: SmokeShell
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF","PMC_BAF"};
	};
	class ACE_M84: ACE_Flashbang
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US"};
	};
	class ACE_TORCH_C: ACE_Flashbang
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class ACE_Flashbang2: ACE_Flashbang
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class TimeBomb;
	class Mine: TimeBomb
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class MineE: TimeBomb
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class PipeBomb: TimeBomb{};
	class BAF_ied_v1: TimeBomb
	{
		ace_sys_weapons_SIDE[] = {"INS","GUE"};
	};
	class ACE_M86PDM: HandGrenade_Stone
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_Explosive_M: CA_Magazine{};
	class ACE_C4_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"USMC","CDF","RU","INS","GUE","BIS_GER","BIS_TK","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class ACE_M2SLAM_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_BBetty_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"USMC","CDF","RU","INS","BIS_TK","BIS_US","BIS_BAF"};
	};
	class ACE_TripFlare_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"USMC","CDF","RU","INS","GUE","BIS_GER","BIS_TK","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class ACE_Pomz_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class ACE_Claymore_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_MON50_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK","BIS_GER"};
	};
	class ACE_DM31_M: ACE_BBetty_M
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class ACE_DM12PARM1_M: ACE_Explosive_M
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class ACE_CSWDM;
	class ACE_KORD_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"RU"};
	};
	class ACE_DSHKM_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"CDF","INS","GUE","BIS_TK"};
	};
	class ACE_M2_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_MK19_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US"};
	};
	class ACE_GMG_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class ACE_AGS30_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_Konkurs_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_KonkursM_CSWDM: ACE_Konkurs_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU"};
	};
	class ACE_M252HE_CSWDM: CA_Magazine
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_2B14HE_CSWDM: CA_Magazine
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_TOW_CSWDM: ACE_CSWDM
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US"};
	};
};
class CfgWeapons
{
	class Default;
	class GrenadeLauncher: Default
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
	};
	class Put: Default
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
	};
	class Throw: GrenadeLauncher
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
	};
	class Binocular: Default
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
	};
	class ItemCore: Default
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
	};
	class RifleCore;
	class Rifle: RifleCore
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
		ace_sys_weapons_TYPE = 1;
	};
	class M16_base: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US"};
	};
	class M16A2: M16_base
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_TK","BIS_US","PMC_BAF"};
	};
	class m16a4: M16A2
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US"};
	};
	class FN_FAL: M16A2
	{
		ace_sys_weapons_SIDE[] = {"BIS_TK"};
	};
	class AK_BASE: Rifle
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK","PMC_BAF"};
	};
	class AK_107_BASE: AK_BASE
	{
		ace_sys_weapons_SIDE[] = {"RU"};
	};
	class AKS_BASE: AK_BASE
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class AK_47_M: AK_BASE
	{
		ace_sys_weapons_SIDE[] = {"CDF","INS","GUE"};
	};
	class bizon: Rifle
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","BIS_TK"};
	};
	class Saiga12K: Rifle
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class LeeEnfield: Rifle
	{
		ace_sys_weapons_SIDE[] = {"INS","GUE"};
	};
	class G36a: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER","PMC_BAF"};
	};
	class G36C: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER","PMC_BAF"};
	};
	class m8_base: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","PMC_BAF"};
	};
	class M1014: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF","PMC_BAF","BIS_CZ"};
	};
	class MP5SD: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","CDF","BIS_GER","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class MP5A5: MP5SD{};
	class Sa58P_EP1: Rifle
	{
		ace_sys_weapons_SIDE[] = {"INS","GUE","BIS_CZ","PMC_BAF"};
	};
	class Sa58V_EP1: Sa58P_EP1{};
	class Sa58V_RCO_EP1: Sa58V_EP1
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","PMC_BAF"};
	};
	class Sa58V_CCO_EP1: Sa58V_EP1
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","PMC_BAF"};
	};
	class M14_EP1: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","PMC_BAF"};
	};
	class MGun;
	class PK: Rifle
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK","PMC_BAF"};
		ace_sys_weapons_TYPE = 5;
	};
	class Pecheneg: PK
	{
		ace_sys_weapons_SIDE[] = {"RU"};
	};
	class AK_74;
	class RPK_74: AK_74
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
		ace_sys_weapons_TYPE = 6;
	};
	class M249: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_CZ"};
		ace_sys_weapons_TYPE = 6;
	};
	class m8_sharpshooter;
	class m8_SAW: m8_sharpshooter
	{
		ace_sys_weapons_TYPE = 6;
	};
	class MG36: G36C
	{
		ace_sys_weapons_SIDE[] = {"PMC_BAF"};
		ace_sys_weapons_TYPE = 6;
	};
	class M240: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US"};
		ace_sys_weapons_TYPE = 5;
	};
	class M60A4_EP1: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_CZ"};
		ace_sys_weapons_TYPE = 5;
	};
	class BAF_L7A2_GPMG: M240
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class M240_veh: MGun
	{
		ace_sys_weapons_type = 5;
	};
	class PKT: MGun
	{
		ace_sys_weapons_type = 5;
	};
	class M2: MGun
	{
		ace_sys_weapons_type = 5;
	};
	class DSHKM: MGun
	{
		ace_sys_weapons_type = 5;
	};
	class KORD: MGun
	{
		ace_sys_weapons_type = 5;
	};
	class KPVT: MGun
	{
		ace_sys_weapons_type = 5;
	};
	class SVD: Rifle
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK","PMC_BAF","BIS_CZ"};
		ace_sys_weapons_TYPE = 3;
	};
	class VSS_vintorez: Rifle
	{
		ace_sys_weapons_SIDE[] = {"RU"};
		ace_sys_weapons_TYPE = 3;
	};
	class KSVK: Rifle
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
		ace_sys_weapons_TYPE = 3;
	};
	class M24: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_US","PMC_BAF"};
		ace_sys_weapons_TYPE = 3;
	};
	class huntingrifle: M24
	{
		ace_sys_weapons_SIDE[] = {"INS","GUE"};
	};
	class M40A3: M24
	{
		ace_sys_weapons_SIDE[] = {"USMC"};
	};
	class DMR: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC"};
		ace_sys_weapons_TYPE = 3;
	};
	class m107: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_CZ"};
		ace_sys_weapons_TYPE = 3;
	};
	class M110_TWS_EP1: Rifle
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US"};
		ace_sys_weapons_TYPE = 3;
	};
	class PistolCore;
	class Pistol: PistolCore
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
	};
	class Makarov: Pistol
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK"};
	};
	class M9: Pistol
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class M9SD: M9{};
	class Sa61_EP1: Pistol
	{
		ace_sys_weapons_SIDE[] = {"CDF","INS","GUE","BIS_TK","PMC_BAF","BIS_CZ"};
	};
	class UZI_EP1: Pistol
	{
		ace_sys_weapons_SIDE[] = {"USMC","INS","GUE","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class glock17_EP1: Pistol
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF","PMC_BAF","BIS_CZ"};
	};
	class LauncherCore;
	class Launcher: LauncherCore
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
		ace_sys_weapons_TYPE = 4;
	};
	class RPG7V: Launcher
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK","PMC_BAF","BIS_CZ"};
	};
	class RPG18: Launcher
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","GUE","BIS_TK","PMC_BAF"};
	};
	class Javelin: Launcher
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class M136: Launcher
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class SMAW: Launcher
	{
		ace_sys_weapons_SIDE[] = {"USMC"};
	};
	class MetisLauncher: Launcher
	{
		ace_sys_weapons_SIDE[] = {"RU","BIS_TK"};
	};
	class MAAWS: Launcher
	{
		ace_sys_weapons_SIDE[] = {"BIS_US","PMC_BAF","BIS_CZ"};
	};
	class Stinger: Launcher
	{
		ace_sys_weapons_SIDE[] = {"USMC","GUE","BIS_GER","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class Strela: Launcher
	{
		ace_sys_weapons_SIDE[] = {"CDF","INS","BIS_TK"};
	};
	class Igla: Strela
	{
		ace_sys_weapons_SIDE[] = {"RU","BIS_TK"};
	};
	class GrenadeLauncher_EP1;
	class M32_EP1: GrenadeLauncher_EP1
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","PMC_BAF"};
	};
	class M79_EP1: GrenadeLauncher_EP1
	{
		ace_sys_weapons_SIDE[] = {"GUE","BIS_TK"};
	};
	class Mk13_EP1: GrenadeLauncher_EP1
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","PMC_BAF"};
	};
	class M47Launcher_EP1: Launcher
	{
		ace_sys_weapons_SIDE[] = {"INS","GUE","BIS_TK"};
	};
	class revolver_EP1: Pistol
	{
		ace_sys_weapons_SIDE[] = {"USMC","CDF","RU","INS","GUE","BIS_GER","BIS_TK","BIS_US","BIS_BAF","PMC_BAF"};
	};
	class BAF_AS50_scoped: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
		ace_sys_weapons_TYPE = 3;
	};
	class BAF_LRR_scoped: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
		ace_sys_weapons_TYPE = 3;
	};
	class BAF_NLAW_Launcher: Launcher
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class L85A2_base_BAF: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class BAF_L86A2_ACOG: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class BAF_L110A1_Aim: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
		ace_sys_weapons_TYPE = 6;
	};
	class AA12_PMC: Rifle
	{
		ace_sys_weapons_SIDE[] = {"PMC_BAF"};
	};
	class PMC_AS50_scoped: BAF_AS50_scoped
	{
		ace_sys_weapons_SIDE[] = {"PMC_BAF"};
	};
	class BAF_AS50_TWS;
	class PMC_AS50_TWS: BAF_AS50_TWS
	{
		ace_sys_weapons_SIDE[] = {"PMC_BAF"};
	};
	class CZ_750_S1_ACR: M40A3
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","PMC_BAF"};
	};
	class evo_sd_ACR: MP5SD
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ"};
	};
	class Evo_ACR: MP5A5
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ"};
	};
	class CZ_75_P_07_DUTY: M9
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","PMC_BAF"};
	};
	class CZ_75_D_COMPACT: M9
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","PMC_BAF"};
	};
	class CZ_75_SP_01_PHANTOM: M9
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","PMC_BAF"};
	};
	class CZ_75_SP_01_PHANTOM_SD: M9SD
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","PMC_BAF"};
	};
	class CZ805_A1_ACR: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ"};
	};
	class UK59_ACR: Rifle
	{
		ace_sys_weapons_SIDE[] = {"BIS_CZ","INS","GUE","PMC_BAF"};
		ace_sys_weapons_TYPE = 5;
	};
	class ACE_Rucksack: Launcher
	{
		ace_sys_weapons_SIDE[] = {"DEFAULT"};
		ace_sys_weapons_TYPE = 4094;
	};
	class ACE_Rucksack_RD90: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_Rucksack_MOLLE_Green: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_VTAC_RUSH72: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_VTAC_RUSH72_TT_MEDIC: ACE_VTAC_RUSH72
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class ACE_CharliePack: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_FAST_PackEDC: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_Coyote_Pack: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_BackPack_ACR: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_BackPack_ACR_FL: ACE_BackPack_ACR
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class ACE_BackPack_ACR_DPM: ACE_BackPack_ACR
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class ACE_Backpack_US: ACE_BackPack_ACR
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_Backpack_FL: ACE_Backpack_US
	{
		ace_sys_weapons_SIDE[] = {"BIS_GER"};
	};
	class ACE_Rucksack_EAST_Medic: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_BackPack: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"CIV","PMC_BAF"};
	};
	class ACE_Combat_Pack: ACE_Rucksack
	{
		ace_sys_weapons_SIDE[] = {"CIV"};
	};
	class ACE_CrewMGunProxy: Launcher
	{
		ace_sys_weapons_TYPE = 4094;
	};
	class ACE_M2HBProxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US"};
	};
	class ACE_BAF_L2A1Proxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class ACE_MK19MOD3Proxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US"};
	};
	class ACE_BAF_static_GMGProxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"BIS_BAF"};
	};
	class ACE_KORDProxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"RU"};
	};
	class ACE_DSHKMProxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"CDF","INS","GUE","BIS_TK"};
	};
	class ACE_AGS30Proxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_CrewTripodProxy;
	class ACE_M3TripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_M122TripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
	};
	class ACE_6T7TripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"RU"};
	};
	class ACE_AGS30TripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_DSHKMTripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"CDF","INS","GUE","BIS_TK"};
	};
	class ACE_KonkursTripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_M220Proxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US"};
	};
	class ACE_2b14Proxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_2b14TripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"CDF","RU","INS","BIS_TK"};
	};
	class ACE_M252Proxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_M252TripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_M224Proxy: ACE_CrewMGunProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_M224TripodProxy: ACE_CrewTripodProxy
	{
		ace_sys_weapons_SIDE[] = {"USMC","BIS_GER","BIS_US","BIS_BAF"};
	};
	class ACE_WireCutter: Rifle
	{
		ace_sys_weapons_TYPE = 131072;
	};
	class ACE_Stretcher: Launcher
	{
		ace_sys_weapons_TYPE = 4094;
	};
};
class CfgVehicles
{
	class NonStrategic;
	class ace_sys_weapons_magicbox: NonStrategic
	{
		scope = 2;
		displayName = "MagicBox";
		model = "\ca\weapons\empty";
		fsmdanger = "";
		fsmformation = "";
		namesound = "unknown";
		picture = "pictureLogic";
		icon = "\Ca\weapons\Data\map_ico\icomap_ammo_CA.paa";
		vehicleClass = "ACE_Ammunition";
		mapSize = 2;
		class EventHandlers
		{
			init = "if(isnil'SLX_XEH_objects')then{call ('extended_eventhandlers\init_pre.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })};_this call SLX_XEH_EH_Init";
		};
	};
};
//};
