////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Aug 24 17:37:44 2012 : Created on Fri Aug 24 17:37:44 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_ai_dispersion : config.bin{
class CfgPatches
{
	class ace_c_ai_dispersion
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","CAWeapons","CAWeapons2","CAWeapons_E","CAWeapons_BAF","CAWeapons_PMC"};
		version = "1.13.0.568";
	};
};
class CfgWeapons
{
	class Default;
	class PistolCore;
	class RifleCore;
	class GrenadeLauncher: Default
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle: GrenadeLauncher
		{
			aiDispersionCoefX = 15;
			aiDispersionCoefY = 16;
		};
	};
	class Pistol: PistolCore
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class Rifle: RifleCore
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class GrenadeLauncher_EP1: Rifle
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class M16_base: Rifle{};
	class M16A2: M16_base{};
	class m16a4: M16A2{};
	class M16A4_GL: m16a4{};
	class M4A1: M16_base{};
	class m16a4_acg: m16a4
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class M16A4_ACG_GL: M16A4_GL
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class M4SPR: M4A1
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class M4A1_RCO_GL: M4A1
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class M4A1_HWS_GL: M4A1_RCO_GL
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class AK_BASE: Rifle{};
	class AKS_BASE: AK_BASE{};
	class AK_107_BASE: AK_BASE{};
	class AK_107_GL_kobra: AK_107_BASE{};
	class AK_107_GL_pso: AK_107_GL_kobra
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class AK_107_pso: AK_107_BASE
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class AKS_74_pso: AKS_BASE
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class AKS_74_GOSHAWK: AKS_BASE
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class AK_74: AK_BASE{};
	class RPK_74: AK_74
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class M24: Rifle
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class M240: Rifle
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class m240_scoped_EP1: m240
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class M249: Rifle
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class M249_m145_EP1: M249
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class PK: Rifle
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class SVD: Rifle
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class G36a: Rifle
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class ksvk: Rifle
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class m107: Rifle
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class BAF_AS50_scoped: Rifle
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class BAF_LRR_scoped: Rifle
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class L85A2_base_BAF: Rifle{};
	class BAF_L85A2_RIS_SUSAT: L85A2_base_BAF
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class BAF_L85A2_RIS_ACOG: L85A2_base_BAF
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class BAF_L85A2_RIS_CWS: L85A2_base_BAF
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class BAF_L86A2_ACOG: Rifle
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class BAF_L110A1_Aim: Rifle
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class M60A4_EP1: Rifle
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class Sa58P_EP1: Rifle{};
	class Sa58V_EP1: Sa58P_EP1{};
	class Sa58V_RCO_EP1: Sa58V_EP1
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class M4A3_CCO_EP1: M16_base{};
	class M4A3_RCO_GL_EP1: M4A3_CCO_EP1
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class FN_FAL: M16A2{};
	class FN_FAL_ANPVS4: FN_FAL
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class M110_TWS_EP1: Rifle
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class SCAR_Base: M16_base{};
	class SCAR_L_Base: SCAR_Base{};
	class SCAR_H_Base: SCAR_Base{};
	class SCAR_L_STD_Mk4CQT: SCAR_L_Base
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class SCAR_L_STD_EGLM_RCO: SCAR_L_STD_Mk4CQT{};
	class SCAR_L_STD_EGLM_TWS: SCAR_L_STD_EGLM_RCO
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class SCAR_H_CQC_CCO: SCAR_H_Base{};
	class SCAR_H_STD_EGLM_Spect: SCAR_H_CQC_CCO
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class SCAR_H_LNG_Sniper: SCAR_H_Base
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class SCAR_H_LNG_Sniper_SD: SCAR_H_Base
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class SCAR_H_STD_TWS_SD: SCAR_H_LNG_Sniper_SD
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
	class m8_base: Rifle{};
	class m8_carbine: m8_base
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class m8_sharpshooter: m8_base
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class m8_SAW: m8_sharpshooter
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class DMR: Rifle
	{
		aiDispersionCoefX = 5;
		aiDispersionCoefY = 6;
	};
	class VSS_vintorez: Rifle
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class CZ805_A1_ACR: Rifle{};
	class CZ805_B_GL_ACR: CZ805_A1_ACR
	{
		aiDispersionCoefX = 10;
		aiDispersionCoefY = 11;
	};
	class UK59_ACR: Rifle
	{
		aiDispersionCoefX = 15;
		aiDispersionCoefY = 16;
	};
};
//};
