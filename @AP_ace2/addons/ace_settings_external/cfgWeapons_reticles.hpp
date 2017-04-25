//class cfgweapons
//{
	//class Rifle;
	class AKS_BASE;
	class AKS_74_pso: AKS_BASE {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PSO_1_1AK";
	};
	class AKS_74_NSPU: AKS_BASE {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "NSPU";
	};
	class AK_107_BASE;
	class AK_107_pso: AK_107_BASE {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PSO_1_1AK";
	};
	class AK_107_GL_kobra;
	class AK_107_GL_pso: AK_107_GL_kobra {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PSO_1_1AK";
	};
	class VSS_vintorez: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PSO_1_1";
		ace_sys_reticles_enable_sa = 1;
	};
	class SVD: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PSO_1";
		ace_sys_reticles_enable_sa = 1;
	};
	class SVD_NSPU_EP1: SVD {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "NSPU";
		ace_sys_reticles_enable_sa = 1;
	};
	class KSVK: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PSO_3";
		ace_sys_reticles_enable_sa = 1;
	};
	class PK;
	class Pecheneg: PK {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PKP";
	};
	class M4A1;
	class M4A1_RCO_GL: M4A1 {
		class M4_ACOG_Muzzle: M4A1 {
			modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		};
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ACOG_TA01NSN";
	};
	class M4A3_CCO_EP1;
	class M4A3_RCO_GL_EP1: M4A3_CCO_EP1 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ACOG_TA01NSN";
	};
	class SCAR_L_Base;
	class SCAR_L_STD_Mk4CQT: SCAR_L_Base {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "MK4CQT";
	};
	class SCAR_L_STD_EGLM_RCO: SCAR_L_STD_Mk4CQT {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ACOG_TA31F";
	};
	class SCAR_L_STD_EGLM_TWS: SCAR_L_STD_EGLM_RCO {
		ace_sys_reticles_enable = 0;
	};
	class SCAR_H_Base;
	class SCAR_H_LNG_Sniper_SD: SCAR_H_Base {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "SB_CQB_4X";
	};
	class SCAR_H_STD_TWS_SD: SCAR_H_LNG_Sniper_SD {
		ace_sys_reticles_enable = 0;
	};
	class SCAR_H_LNG_Sniper: SCAR_H_Base {
		//opticsZoomMin = 0.033574; // 8.75x magnification, 45 mil FOV, 15 px/mil
		//opticsZoomMax = 0.087666; // 3.35x magnification, 117.5 mil FOV
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu39xTMR";
	};
	class SCAR_H_CQC_CCO;
	class SCAR_H_STD_EGLM_Spect: SCAR_H_CQC_CCO {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Specter_4x";
	};
	class M4SPR: M4A1 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu3510xMildot";
	};
	class M24: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu10xMildot";
	};
	class huntingrifle: M24 {
		ace_sys_reticles_enable = 0;
	};
	class DMR: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu10xMildot";
	};
	class M110_TWS_EP1;
	class M110_NVG_EP1: M110_TWS_EP1 { //0.912
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu875xMildot";
		//opticsZoomMin = 0.033574; // 8.75x magnification, 45 mil FOV, 15 px/mil
	};
	class m107: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu14xMildot";
	};
	class m107_TWS_EP1: m107 {
		ace_sys_reticles_enable = 0;
	};
	class Sa58V_EP1;
	class Sa58V_RCO_EP1: Sa58V_EP1 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ACOG_762x39";
	};
	class L85A2_base_BAF;
	class BAF_L85A2_RIS_SUSAT: L85A2_base_BAF {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "SUSAT";
	};
	class BAF_L85A2_RIS_ACOG: L85A2_base_BAF {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ACOG_TA31DOC";
	};
	class BAF_L86A2_ACOG: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ACOG_TA31DOC";
	};
	class BAF_AS50_scoped: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "SB312x";
	};
	class PMC_AS50_scoped : BAF_AS50_scoped {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
	};
	class BAF_AS50_TWS: BAF_AS50_scoped {
		ace_sys_reticles_enable = 0;
	};
	class BAF_LRR_scoped: Rifle {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "SB312x";
	};

	class M240;
	class M249;
	class m240_scoped_EP1: M240 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "M145";
	};
	class M249_m145_EP1: M249 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "M145";
	};
	class G36C;
	class G36a: Rifle {
		class MuzzleFar: G36C {
			modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		};
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "G36";
	};
	class FN_FAL;
	class FN_FAL_ANPVS4: FN_FAL  {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ANPVS4";
	};
	
	class RPG7V;
	class ACE_RPG7V_PGO7: RPG7V {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PGO7V";	
	};

//};