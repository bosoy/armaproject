////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Dec 01 21:39:57 2012 : Created on Sat Dec 01 21:39:57 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_mv : config.bin{
class CfgPatches
{
	class ace_sys_mv
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon"};
		version = "1.14.0.584";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_mv
	{
		clientInit = "call ('\x\ace\addons\sys_mv\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class ace_sys_mv
		{
			clientFiredBisPlayer = "if (getNumber(configFile >> 'CfgWeapons' >> (_this select 1) >> 'ace_mod_mv') == 1) then { _this call ace_sys_mv_fnc_fired}";
		};
	};
};
class CfgWeapons
{
	class RifleCore;
	class Rifle: RifleCore
	{
		ace_mod_mv = 0;
	};
	class M16_base;
	class M4A1: M16_base
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790,"ACE_B_556x45_S",880,"ACE_B_556x45_SB_S",790};
	};
	class M4SPR: M4A1
	{
		ace_mod_mv = 0;
	};
	class G36C: Rifle
	{
		ace_mod_mv = 1;
		ace_mv[] = {"ACE_B_556x45_DM11",780,"ACE_B_556x45_DM11_S",780,"B_556x45_Ball",780,"ACE_B_556x45_S",780,"ACE_B_556x45_DM21",745,"ACE_B_556x45_DM31",780,"ACE_B_556x45_DM31_S",780};
	};
	class G36a: Rifle
	{
		ace_mod_mv = 1;
		ace_mv[] = {"ACE_B_556x45_DM11",925,"ACE_B_556x45_DM11_S",925,"B_556x45_Ball",925,"ACE_B_556x45_S",925,"ACE_B_556x45_DM21",890,"ACE_B_556x45_DM31",925,"ACE_B_556x45_DM31_S",925};
	};
	class G36K: G36a
	{
		ace_mv[] = {"ACE_B_556x45_DM11",850,"ACE_B_556x45_DM11_S",850,"B_556x45_Ball",850,"ACE_B_556x45_S",850,"ACE_B_556x45_DM21",815,"ACE_B_556x45_DM31",850,"ACE_B_556x45_DM31_S",850};
	};
	class MG36: G36C
	{
		ace_mod_mv = 0;
	};
	class m8_base: Rifle
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",820,"ACE_B_556x45_T",820,"ACE_B_556x45_SB",760,"ACE_B_556x45_S",820};
	};
	class m8_compact: m8_base
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",740,"ACE_B_556x45_T",740,"ACE_B_556x45_SB",680,"ACE_B_556x45_S",740};
	};
	class m8_sharpshooter: m8_base
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",915,"ACE_B_556x45_T",915,"ACE_B_556x45_S",915};
	};
	class SCAR_Base;
	class SCAR_L_Base: SCAR_Base
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",890,"ACE_B_556x45_T",890,"ACE_B_556x45_S",890,"ACE_B_556x45_SB",814,"ACE_B_556x45_SB_S",814};
	};
	class SCAR_L_CQC: SCAR_L_Base
	{
		ace_mv[] = {"B_556x45_Ball",808,"ACE_B_556x45_T",808,"ACE_B_556x45_S",808,"ACE_B_556x45_SB",740,"ACE_B_556x45_SB_S",740};
	};
	class SCAR_H_Base: SCAR_Base
	{
		ace_mod_mv = 0;
	};
	class SCAR_H_CQC_CCO: SCAR_H_Base
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x51_Ball",774,"ACE_B_762x51_T",774,"ACE_B_762x51_S",774,"B_762x51_noTracer",722,"ACE_B_762x51_SB_S",722};
	};
	class SCAR_H_STD_EGLM_Spect: SCAR_H_CQC_CCO
	{
		ace_mod_mv = 0;
	};
	class SCAR_H_LNG_Sniper: SCAR_H_Base
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x51_Ball",856,"ACE_B_762x51_T",856,"ACE_B_762x51_S",856,"B_762x51_noTracer",798,"ACE_B_762x51_SB_S",798};
	};
	class SCAR_H_LNG_Sniper_SD: SCAR_H_Base
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x51_Ball",856,"ACE_B_762x51_T",856,"ACE_B_762x51_S",856,"B_762x51_noTracer",798,"ACE_B_762x51_SB_S",798};
	};
	class SCAR_H_STD_TWS_SD: SCAR_H_LNG_Sniper_SD
	{
		ace_mod_mv = 0;
	};
	class M240;
	class Mk_48: M240
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x51_Ball",800};
	};
	class M249;
	class M249_EP1: M249
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790};
	};
	class M249_TWS_EP1: M249
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790};
	};
	class M249_m145_EP1: M249
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790};
	};
	class BAF_L110A1_Aim: Rifle
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790};
	};
	class AKS_BASE;
	class AKS_74_U: AKS_BASE
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_545x39_Ball",735,"ACE_B_545x39_T",735,"ACE_B_545x39_S",735,"ACE_B_545x39_EP",735,"ACE_B_545x39_EP_S",735,"ACE_B_545x39_AP",735,"ACE_B_545x39_AP_S",735};
	};
	class AKS_74_UN_kobra: AKS_BASE
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_545x39_Ball",735,"ACE_B_545x39_T",735,"ACE_B_545x39_S",735,"ACE_B_545x39_EP",735,"ACE_B_545x39_EP_S",735,"ACE_B_545x39_AP",735,"ACE_B_545x39_AP_S",735};
	};
	class AK_74;
	class RPK_74: AK_74
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_545x39_Ball",960,"ACE_B_545x39_T",960,"ACE_B_545x39_S",960,"ACE_B_545x39_EP",960,"ACE_B_545x39_EP_S",960,"ACE_B_545x39_AP",960,"ACE_B_545x39_AP_S",960};
	};
	class BAF_L86A2_ACOG: Rifle
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",970,"ACE_B_556x45_T",970,"ACE_B_556x45_S",970,"ACE_B_556x45_SB",890,"ACE_B_556x45_SB_S",890};
	};
	class M9;
	class CZ_75_P_07_DUTY: M9
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_9x19_Ball",350,"ACE_B_9x19_S",350};
	};
	class UK59_ACR: Rifle
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x54_Ball",830};
	};
	class CZ805_A1_ACR: Rifle
	{
		ace_mod_mv = 1;
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_S",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790,"ACE_B_556x45_SB_S",790,"ACE_B_556x45_DM11",880,"ACE_B_556x45_DM11_S",880,"ACE_B_556x45_DM21",790,"ACE_B_556x45_DM31",880,"ACE_B_556x45_DM31_S",880};
	};
	class CZ805_A2_ACR: CZ805_A1_ACR
	{
		ace_mv[] = {"B_556x45_Ball",790,"ACE_B_556x45_S",790,"ACE_B_556x45_T",790,"ACE_B_556x45_SB",740,"ACE_B_556x45_SB_S",740,"ACE_B_556x45_DM11",790,"ACE_B_556x45_DM11_S",790,"ACE_B_556x45_DM21",740,"ACE_B_556x45_DM31",790,"ACE_B_556x45_DM31_S",790};
	};
	class CZ805_B_GL_ACR: CZ805_A1_ACR
	{
		ace_mod_mv = 0;
	};
};
//};
