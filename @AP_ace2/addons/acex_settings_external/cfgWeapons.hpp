#define __PSO \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";	\
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "PSO_1_1AK";

#define __1P29 \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty"; \
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "1P29";

#define __1P78 \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty"; \
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "1P78";

#define __1PN100 \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";	\
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "1PN100";

#define __NSPU \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty"; \
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "NSPU";

#define __GrScope \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf"; \
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "Groza";

#define __TA01 \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty"; \
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "ACOG_TA01NSN";

#define __TA31F \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty"; \
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "ACOG_TA31F";

#define __TA31ECOS \
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty"; \
		ace_sys_reticles_enable = 1; \
		ace_sys_reticles_scope = "ACOG_TA31ECOS";

//class cfgweapons
//{
	class Rifle;
	class ACE_AKS74p;
	class ACE_AKS74p_GL;
	class ACE_AK105;
	class ACE_AK103;
	class ACE_AK103_GL;
	class ACE_AK104;
	class ACE_RPK74M;
	class VSS_vintorez;
	class ACE_Val: VSS_vintorez {
		ace_sys_reticles_enable = 0;
	};
	class ACE_AKS74P_1P29: ACE_AKS74p {
		__1P29
	};
	class ACE_AKS74P_GL_1P29: ACE_AKS74P_GL {
		__1P29
	};
	class ACE_AK105_1P29: ACE_AK105 {
		__1P29
	};
	class ACE_AK103_1P29: ACE_AK103 {
		__1P29
	};
	class ACE_AK103_GL_1P29: ACE_AK103_GL {
		__1P29
	};
	class ACE_AK104_1P29: ACE_AK104 {
		__1P29
	};
	class ACE_AKS74P_PSO: ACE_AKS74p {
		__PSO
	};
	class ACE_AKS74P_GL_PSO: ACE_AKS74P_GL {
		__PSO
	};
	class ACE_AK105_PSO: ACE_AK105 {
		__PSO
	};
	class ACE_AK103_PSO: ACE_AK103 {
		__PSO
	};
	class ACE_AK103_GL_PSO: ACE_AK103_GL {
		__PSO
	};
	class ACE_AK104_PSO: ACE_AK104 {
		__PSO
	};
	class ACE_RPK74M_1P29: ACE_RPK74M {
		__1P29
	};
	class ACE_Val_PSO: ACE_Val {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_hf";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "PSO_1_1";
	};
	class ACE_oc14;
	class ACE_oc14sd;
	class ACE_gr1;
	class ACE_gr1sd;
	class ACE_oc14sp: ACE_oc14 {
		__GrScope 
	};
	class ACE_oc14sdsp:  ACE_oc14sd {
		__GrScope 
	};
	class ACE_gr1sp:  ACE_gr1 {
		__GrScope 
	};
	class ACE_gr1sdsp:  ACE_gr1sd {
		__GrScope 
	};

	class ACE_AK74M;
	class ACE_AK74M_GL;
	class ACE_AK74M_SD;
	class ACE_AK74M_PSO: ACE_AK74M {
		__PSO
	};
	class ACE_AK74M_GL_PSO: ACE_AK74M_GL {
		__PSO
	};
	class ACE_AK74M_SD_PSO: ACE_AK74M_SD {
		__PSO
	};
	class ACE_AK74M_NSPU: ACE_AK74M {
		__NSPU
	};
	class ACE_AK74M_GL_NSPU: ACE_AK74M_GL {
		__NSPU
	};
	class ACE_AK74M_SD_NSPU: ACE_AK74M_SD {
		__NSPU
	};
	class ACE_AK74M_1P78: ACE_AK74M {
		__1P78
	};
	class ACE_AK74M_GL_1P78: ACE_AK74M_GL {
		__1P78
	};
	class ACE_AK74M_SD_1P78: ACE_AK74M_SD {
		__1P78
	};
	class ACE_AK74M_1P29: ACE_AK74M_PSO {
		__1P29
	};
	class ACE_AK74M_GL_1P29: ACE_AK74M_GL_PSO {
		__1P29
	};

	class ACE_HK416_D14;
	class ACE_HK416_D14_ACOG_PVS14: ACE_HK416_D14 {
		__TA31F
	};

	class ACE_M27_IAR;
	class ACE_M27_IAR_ACOG: ACE_M27_IAR {
		__TA31F
	};
	class ACE_HK417_Base;
	class ACE_HK417_Shortdot: ACE_HK417_Base {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "SB_CQB_4X";
	};
	class ACE_HK417_leupold: ACE_HK417_Base {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu3510xMildot";
	};
	class ACE_HK417_micro;
	class ACE_HK417_Eotech_4x: ACE_HK417_micro {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Eotech4X";
	};
	class m16a2;
	class ACE_m16a2_scope: m16a2 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Colt4X";
	};
	class m16a2gl;
	class ACE_m16a2gl_scope: m16a2gl {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Colt4X";
	};
	class m16a4;
	class m16a4_acg: m16a4 {
		__TA31F
	};
	class m16a4_gl;
	class M16A4_ACG_GL: M16A4_GL {
		__TA31F
	};
	class m4a1;
	class ACE_M4A1_ACOG: M4A1 {
		__TA31F
	};
	class ACE_SOC_M4A1_SHORTDOT: ACE_M4A1_ACOG {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "SB_CQB_4X";
	};
	class ACE_SOC_M4A1_TWS: ACE_M4A1_ACOG {
		ace_sys_reticles_enable = 0;
	};
	class ACE_SOC_M4A1_Eotech_4x: ACE_M4A1_ACOG {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Eotech4X";
	};
	class M4A1_RCO_GL: M4A1 {
		class M4_ACOG_Muzzle: M4A1 {
			modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		};
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ACOG_TA01NSN";
	};
	class ACE_M4A1_GL;
	class ACE_M4A1_RCO2_GL: ACE_M4A1_GL {
		__TA31F
	};
	class ACE_M4A1_RCO_GL;
	class ACE_SOC_M4A1_RCO_GL: ACE_M4A1_RCO_GL {
		__TA31F
	};
	class M4A1_AIM_SD_camo;
	class ACE_M4A1_ACOG_SD: M4A1_AIM_SD_camo {
		__TA31F
	};
	class ACE_SOC_M4A1_SHORTDOT_SD: ACE_M4A1_ACOG_SD {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "SB_CQB_4X";
	};
	class M4A1_HWS_GL: M4A1_RCO_GL {
		ace_sys_reticles_enable = 0;
	};
	class M249_m145_EP1;
	class ACE_M249_PIP_ACOG: M249_m145_EP1 {
		__TA31ECOS
	};
	class ACE_G3A3;
	class ACE_G3SG1: ACE_G3A3 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "ZF24";
	};
	class M14_EP1;
	class ACE_M14_ACOG: M14_EP1 {
		__TA31F
	};
	class M110_NVG_EP1;
	class ACE_M110: M110_NVG_EP1 {
		modelOptics = "x\ace\addons\sys_reticles\ACE_optics_empty_narrow";
		ace_sys_reticles_enable = 1;
		ace_sys_reticles_scope = "Leu3510xMildot";
	};
	class ACE_AEK_971;
	class ACE_AEK_971_1p78 : ACE_AEK_971 {
		__1P78
	};
	class ACE_AEK_971_1pn100 : ACE_AEK_971 {
		__1PN100
	};
	class ACE_AEK_973s;
	class ACE_AEK_973s_1p78 : ACE_AEK_973s {
		__1P78
	};
	class ACE_AEK_973s_1pn100 : ACE_AEK_973s {
		__1PN100
	};
//};