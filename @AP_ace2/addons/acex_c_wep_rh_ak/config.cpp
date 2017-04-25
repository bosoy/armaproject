////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed May 23 21:40:37 2012 : Created on Wed May 23 21:40:37 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_rh_ak : config.bin{
class CfgPatches
{
	class acex_wep_rh_ak
	{
		units[] = {};
		weapons[] = {"ACE_OC14","ACE_oc14sp","ACE_oc14gl","ACE_oc14glsp","ACE_oc14sd","ACE_oc14sdsp","ACE_gr1","ACE_gr1sp","ACE_gr1sd","ACE_gr1sdsp","ace_ak74m","ace_ak74m_kobra","ace_ak74m_1p29","ace_ak74m_pso","ace_ak74m_gl","ace_ak74m_gl_kobra","ace_ak74m_gl_1p29","ace_ak74m_gl_pso","ace_aks74p","ace_aks74p_kobra","ace_aks74p_1p29","ace_aks74p_pso","ace_aks74p_gl","ace_aks74p_gl_kobra","ace_aks74p_gl_1p29","ace_aks74p_gl_pso","ace_ak105","ace_ak105_kobra","ace_ak105_1p29","ace_ak105_pso","ace_ak103","ace_ak103_kobra","ace_ak103_1p29","ace_ak103_pso","ace_ak103_gl","ace_ak103_gl_kobra","ace_ak103_gl_1p29","ace_ak103_gl_pso","ace_ak104","ace_ak104_kobra","ace_ak104_1p29","ace_ak104_pso","ace_rpk74m","ace_rpk74m_1p29","ace_val","ace_val_kobra","ace_val_pso","ace_rpk","ace_akm_gl","ace_akm","ace_akms"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","acex_main","acex_m_wep_rh_ak","acex_t_wep_rh_ak","acex_s_wep_rh_ak","ace_c_weapon"};
		version = "1.13.0.363";
		author[] = {"Robert Hammer","Solus","zGuba"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_rh_ak
		{
			list[] = {"acex_wep_rh_ak"};
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class 20Rnd_9x39_SP5_VSS;
	class ACE_20Rnd_9x39_B_OC14: 20Rnd_9x39_SP5_VSS
	{
		picture = "\x\acex\addons\c_wep_rh_ak\i\m_oc_ca.paa";
		model = "\x\acex\addons\m_wep_rh_ak\m_oc14.p3d";
	};
	class ACE_20Rnd_9x39_S_OC14: ACE_20Rnd_9x39_B_OC14{};
	class 30Rnd_545x39_AK;
	class ACE_45Rnd_545x39_B_AK: 30Rnd_545x39_AK
	{
		model = "\x\acex\addons\m_wep_rh_ak\m_rpk74.p3d";
	};
	class 75Rnd_545x39_RPK: CA_Magazine
	{
		model = "\x\acex\addons\m_wep_rh_ak\m_rpk74.p3d";
	};
	class 30Rnd_762x39_AK47;
	class ACE_75Rnd_762x39_B_AK47: 30Rnd_762x39_AK47
	{
		model = "\x\acex\addons\m_wep_rh_ak\m_rpk.p3d";
	};
};
class cfgRecoils
{
	ACE_762x39_Groza_Recoil[] = {0,0.009,-0.001,0.02,0.009,0.012,0.03,0.004,0.012,0.1,0,0};
	ACE_762x39_Groza_Recoil_GL[] = {0,0.009,-0.001,0.02,0.009,0.01,0.03,0.005,0.01,0.14,0,0};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class cfgWeapons
{
	class Rifle;
	class AK_BASE;
	class AK_74: AK_BASE
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AK74.p3d";
		class Single;
		class Burst;
		class FullAuto;
		class GP25Muzzle;
	};
	class AK_74_GL: AK_BASE
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AK74_GL.p3d";
		ace_gl_fineadj = 17;
		class Single;
		class Burst;
		class FullAuto;
		class GP25Muzzle;
	};
	class AKS_BASE;
	class AKS_74: AKS_BASE
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AKS74.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		class Single;
		class Burst;
		class FullAuto;
		class GP25Muzzle;
	};
	class ACE_AKS74_GP25: AKS_74
	{
		ace_weight = 4.4;
		dexterity = "(0.5 + 3.75/(2.9+ 1.5 + 0.001) + 0/10)";
		displayName = "AKS-74 GP-25";
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AKS74_GL.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		ace_gl_fineadj = 17;
		muzzles[] = {"this","GP25Muzzle","ACE_GP25Muzzle_AI"};
		class Single: Single
		{
			recoil = "ACE_545x39_Rifle_Recoil_GL";
		};
		class Burst: Burst
		{
			recoil = "ACE_545x39_Rifle_Recoil_GL";
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_545x39_Rifle_Recoil_GL";
		};
	};
	class AKS_74_pso: AKS_BASE
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AKS74_PSO.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		class OpticsModes
		{
			class Scope
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
			class CQB: Scope
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
	};
	class AKS_74_U: AKS_BASE
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AKS74U.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
	};
	class AKS_74_UN_kobra;
	class ACE_AKS74_UN: AKS_74_UN_kobra
	{
		scope = 2;
		displayName = "AKS-74UN";
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AKS74UN.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		ace_weight = 3.1999998;
		dexterity = "(0.5 + 3.75/(2.6+ 0.6 + 0.001) + 0/10)";
	};
	class AK_47_M: AK_BASE
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AKM.p3d";
		class Single;
		class Burst;
		class FullAuto;
		class GP25Muzzle;
		class ACE_GP25Muzzle_AI;
	};
	class AK_47_S: AK_47_M
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_AKS.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		class Single;
		class Burst;
		class FullAuto;
	};
	class RPK_74: AK_74
	{
		model = "\x\acex\addons\m_wep_rh_ak\SLX_RPK74.p3d";
	};
	class ACE_AKS74P: AKS_74
	{
		model = "\x\acex\addons\m_wep_rh_ak\rh_aks74p.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74p.paa";
		displayName = "AKS-74p";
	};
	class ACE_AKS74P_Kobra: ACE_AKS74p
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_aks74pk.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74pk.paa";
		displayName = "AKS-74p Kobra";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 3.25;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35 + 0.001) + 0/10)";
	};
	class ACE_AKS74P_1P29: ACE_AKS74p
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_aks74p1p29.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74p1p29.paa";
		displayName = "AKS-74p 1P29";
		class Single: Single
		{
			dispersion = 0.002;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.002;
		};
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class 1P29
			{
				opticsID = 1;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
			};
			class CQB: 1P29
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		ace_weight = 3.7;
		dexterity = "(0.5 + 3.75/(2.9+ 0.8 + 0.001) + 0/10)";
	};
	class ACE_AKS74P_PSO: ACE_AKS74p
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_aks74psp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74psp.paa";
		displayName = "AKS-74p PSO";
		class Single: Single
		{
			dispersion = 0.002;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.002;
		};
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Scope
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
			class CQB: Scope
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		ace_weight = 3.5;
		dexterity = "(0.5 + 3.75/(2.9+ 0.6 + 0.001) + 0/10)";
	};
	class ACE_AKS74P_GL: AK_74_GL
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_aks74pgl.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74pgl.paa";
		displayName = "AKS-74p GP-30";
		ace_gl_fineadj = 0;
		class GP25Muzzle: GP25Muzzle
		{
			displayName = "$STR_DN_ACE_GP30";
		};
		ace_weight = 4.2;
		dexterity = "(0.5 + 3.75/(2.9+ 1.3 + 0.001) + 0/10)";
	};
	class ACE_AKS74P_GL_Kobra: ACE_AKS74P_GL
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_aks74pkgl.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74pkgl.paa";
		displayName = "AKS-74p GP-30 Kobra";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 4.5499997;
		dexterity = "(0.5 + 3.75/(2.9+ 1.3+ 0.35 + 0.001) + 0/10)";
	};
	class ACE_AKS74P_GL_1P29: ACE_AKS74P_GL
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_aks74pgl1p29.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74pgl1p29.paa";
		displayName = "AKS-74p GP-30 1P29";
		ace_gl_fineadj = -28;
		class Single: Single
		{
			dispersion = 0.002;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.002;
		};
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class 1P29
			{
				opticsID = 1;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
			};
			class CQB: 1P29
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		ace_weight = 5.0;
		dexterity = "(0.5 + 3.75/(2.9+ 1.3+ 0.8 + 0.001) + 0/10)";
	};
	class ACE_AKS74P_GL_PSO: ACE_AKS74P_GL
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_aks74pglsp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\aks74pglsp.paa";
		displayName = "AKS-74p GP-30 PSO";
		ace_gl_fineadj = -28;
		class Single: Single
		{
			dispersion = 0.002;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.002;
		};
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Scope
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
			class CQB: Scope
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		ace_weight = 4.7999997;
		dexterity = "(0.5 + 3.75/(2.9+ 1.3+ 0.6 + 0.001) + 0/10)";
	};
	class ACE_AK105: AK_74
	{
		ace_weight = 3.2;
		dexterity = "(0.5 + 3.75/(3+ 0.2 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak105.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak105.paa";
		displayName = "AK-105";
		discreteDistance[] = {100,200,300,400,500};
		class Single: Single
		{
			dispersion = 0.0025;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			dispersion = 0.0025;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 200;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.0025;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: Burst
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 600;
			minRange = 300;
			minRangeProbab = 0.05;
			midRange = 400;
			midRangeProbab = 0.1;
			maxRange = 600;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		ace_mod_mv = 1;
		ace_mv[] = {"B_545x39_Ball",840,"ACE_B_545x39_T",840,"ACE_B_545x39_S",840,"ACE_B_545x39_EP",840,"ACE_B_545x39_EP_S",840,"ACE_B_545x39_AP",840,"ACE_B_545x39_AP_S",840};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
	};
	class ACE_AK105_Kobra: ACE_AK105
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak105k.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak105k.paa";
		displayName = "AK-105 Kobra";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 3.55;
		dexterity = "(0.5 + 3.75/(3+ 0.35+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK105_1P29: ACE_AK105
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak105_1p29.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak105_1p29.paa";
		displayName = "AK-105 1P29";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class 1P29
			{
				opticsID = 1;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
			};
			class CQB: 1P29
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 600;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		ace_weight = 4.0;
		dexterity = "(0.5 + 3.75/(3+ 0.8+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK105_PSO: ACE_AK105
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak105sp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak105sp.paa";
		displayName = "AK-105 PSO";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Scope
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
			class CQB: Scope
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 600;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		ace_weight = 3.8;
		dexterity = "(0.5 + 3.75/(3+ 0.6+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AKM: AK_47_M
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_akm.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_akm_ca.paa";
	};
	class ACE_AKM_GL: AK_47_M
	{
		ace_weight = 4.35;
		dexterity = "(0.5 + 3.75/(2.85+ 1.5 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_akmgl.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_akmgl_ca.paa";
		displayName = "AKM GP-25";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		muzzles[] = {"this","GP25Muzzle","ACE_GP25Muzzle_AI"};
		class Single: Single
		{
			recoil = "ACE_762x39_Rifle_Recoil_GL";
		};
		class Burst: Burst
		{
			recoil = "ACE_762x39_Rifle_Recoil_GL";
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_762x39_Rifle_Recoil_GL";
		};
		ace_gl_fineadj = 12;
	};
	class ACE_AKMS: AK_47_S
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_akms.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_akms_ca.paa";
		displayName = "AKMS";
	};
	class ACE_AKMS_SD: AK_47_S
	{
		ace_weight = 3.75;
		dexterity = "(0.5 + 3.75/(3.05+ 0.7 + 0.001) + 0/10)";
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		model = "\x\acex\addons\m_wep_rh_ak\RH_akmssd.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\akmssd.paa";
		magazines[] = {"ACE_30Rnd_762x39_SD_AK47","ACE_75Rnd_762x39_SD_AK47"};
		displayName = "AKMS PBS-1";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		discreteDistance[] = {100,200,300,400};
		discreteDistanceInitIndex = 0;
		modes[] = {"FullAuto","Single","Burst"};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1,100};
			soundBegin[] = {"begin1",1};
			recoil = "ACE_762x39_PBS_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
		};
		class Burst: Burst
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1,100};
			soundBegin[] = {"begin1",1};
			recoil = "ACE_762x39_PBS_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1,100};
			soundBegin[] = {"begin1",1};
			recoil = "ACE_762x39_PBS_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
	};
	class ACE_AK103: AK_47_M
	{
		ACE_sys_weapons_Side[] = {"RU"};
		ace_weight = 3.5;
		dexterity = "(0.5 + 3.75/(3.3+ 0.2 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103.paa";
		displayName = "AK-103";
		modes[] = {"FullAuto","Single","Burst"};
		class Single: Single
		{
			recoil = "ACE_762x39_Groza_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			recoil = "ACE_762x39_Groza_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_762x39_Groza_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
	};
	class ACE_AK103_Kobra: ACE_AK103
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103k.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103k.paa";
		displayName = "AK-103 Kobra";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 3.85;
		dexterity = "(0.5 + 3.75/(3.3+ 0.35+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK103_1P29: ACE_AK103
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103_1p29.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103_1p29.paa";
		displayName = "AK-103 1P29";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class 1P29
			{
				opticsID = 1;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
			};
			class CQB: 1P29
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		ace_weight = 4.2999997;
		dexterity = "(0.5 + 3.75/(3.3+ 0.8+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK103_PSO: ACE_AK103
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103sp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103sp.paa";
		displayName = "AK-103 PSO";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Scope
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
			class CQB: Scope
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		ace_weight = 4.1;
		dexterity = "(0.5 + 3.75/(3.3+ 0.6+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK103_GL: ACE_AK103
	{
		ace_weight = 4.6;
		dexterity = "(0.5 + 3.75/(3.3+ 1.3 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103gl.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103gl.paa";
		displayName = "AK-103 GP-30";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		muzzles[] = {"this","GP25Muzzle","ACE_GP25Muzzle_AI"};
		class Single: Single
		{
			recoil = "ACE_762x39_Groza_Recoil_GL";
		};
		class Burst: Burst
		{
			recoil = "ACE_762x39_Groza_Recoil_GL";
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_762x39_Groza_Recoil_GL";
		};
		class GP25Muzzle: GP25Muzzle
		{
			displayName = "$STR_DN_ACE_GP30";
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	class ACE_AK103_GL_Kobra: ACE_AK103_GL
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103kgl.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103kgl.paa";
		displayName = "AK-103 GP-30 Kobra";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 4.95;
		dexterity = "(0.5 + 3.75/(3.3+ 0.35+ 1.3 + 0.001) + 0/10)";
	};
	class ACE_AK103_GL_1P29: ACE_AK103_GL
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103gl1p29.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103gl1p29.paa";
		displayName = "AK-103 GP-30 1P29";
		ace_gl_fineadj = -28;
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class 1P29
			{
				opticsID = 1;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
			};
			class CQB: 1P29
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		ace_weight = 5.3999996;
		dexterity = "(0.5 + 3.75/(3.3+ 0.8+ 1.3 + 0.001) + 0/10)";
	};
	class ACE_AK103_GL_PSO: ACE_AK103_GL
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak103glsp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak103glsp.paa";
		displayName = "AK-103 GP-30 PSO";
		ace_gl_fineadj = -28;
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Scope
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
			class CQB: Scope
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		ace_weight = 5.2;
		dexterity = "(0.5 + 3.75/(3.3+ 0.6+ 1.3 + 0.001) + 0/10)";
	};
	class ACE_AK104: ACE_AK103
	{
		ace_weight = 2.9;
		dexterity = "(0.5 + 3.75/(2.9 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak104.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak104.paa";
		displayName = "AK-104";
		discreteDistance[] = {100,200,300,400,500};
		class Single: Single
		{
			dispersion = 0.0025;
			recoil = "ACE_762x39_Rifle_Recoil";
		};
		class Burst: Burst
		{
			dispersion = 0.0025;
			recoil = "ACE_762x39_Rifle_Recoil";
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.0025;
			recoil = "ACE_762x39_Rifle_Recoil";
		};
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x39_Ball",670,"ACE_B_762x39_T",670,"ACE_B_762x39_AP",690};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	class ACE_AK104_Kobra: ACE_AK104
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak104k.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak104k.paa";
		displayName = "AK-104 Kobra";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 3.25;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35 + 0.001) + 0/10)";
	};
	class ACE_AK104_1P29: ACE_AK104
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak104_1p29.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak104_1p29.paa";
		displayName = "AK-104 1P29";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class 1P29
			{
				opticsID = 1;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
			};
			class CQB: 1P29
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		ace_weight = 3.7;
		dexterity = "(0.5 + 3.75/(2.9+ 0.8 + 0.001) + 0/10)";
	};
	class ACE_AK104_PSO: ACE_AK104
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak104sp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\ak104sp.paa";
		displayName = "AK-104 PSO";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Scope
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
			class CQB: Scope
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		ace_weight = 3.5;
		dexterity = "(0.5 + 3.75/(2.9+ 0.6 + 0.001) + 0/10)";
	};
	class ACE_RPK74M: RPK_74
	{
		ACE_sys_weapons_Side[] = {"RU"};
		model = "\x\acex\addons\m_wep_rh_ak\RH_rpk74m.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\rpk74m.paa";
		displayName = "RPK-74M";
		ace_weight = 5;
		dexterity = "(0.5 + 3.75/(5 + 0.001) + 0/10)";
	};
	class ACE_RPK74M_1P29: ACE_RPK74M
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_rpk74m1p29.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\rpk74m1p29.paa";
		displayName = "RPK-74M 1P29";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class 1P29
			{
				opticsID = 1;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
			};
			class CQB: 1P29
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		modes[] = {"manual","close","short","medium","far","Single","ACE_Burst_Far"};
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		ace_weight = 5.8;
		dexterity = "(0.5 + 3.75/(5+ 0.8 + 0.001) + 0/10)";
	};
	class ACE_RPK: AK_47_M
	{
		ACE_sys_weapons_Side[] = {"CDF","GUE","INS"};
		ACE_sys_weapons_Type = 6;
		model = "\x\acex\addons\m_wep_rh_ak\RH_rpk47.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_rpk47_ca.paa";
		displayName = "RPK";
		type = 1;
		ace_weight = 4.8;
		dexterity = "(0.5 + 3.75/(4.8 + 0.001) + 0/10)";
		ace_mod_mv = 1;
		ace_bipod = 1;
		ace_cf = 1.2;
		ace_mv[] = {"B_762X39_Ball",745,"ACE_B_762X39_T",745,"ACE_B_762x39_AP",765};
		magazines[] = {"ACE_75Rnd_762x39_B_AK47","ACE_75Rnd_762x39_S_AK47","ACE_40Rnd_762x39_B_AK47","ACE_40Rnd_762x39_S_AK47","ACE_40Rnd_762x39_T_AK47","ACE_40Rnd_762x39_AP_AK47","ACE_40Rnd_762x39_AP_S_AK47","30Rnd_762x39_AK47","ACE_30Rnd_762x39_S_AK47","ACE_30Rnd_762x39_T_AK47","ACE_30Rnd_762x39_AP_AK47","ACE_30Rnd_762x39_AP_S_AK47","ACE_30Rnd_762x39_SD_AK47","ACE_75Rnd_762x39_SD_AK47"};
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		modes[] = {"FullAuto","close","short","medium","Single","ACE_Burst_Far"};
		class FullAuto: FullAuto
		{
			recoil = "ACE_762x39_MG_Recoil";
			recoilProne = "ACE_762x39_MG_RecoilProne";
			dispersion = 0.00245;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = "10+ random 10";
			midRangeProbab = 0.7;
			maxRange = "50+ random 50";
			maxRangeProbab = 0.1;
		};
		class Single: Single
		{
			recoil = "ACE_762x39_MG_Recoil";
			recoilProne = "ACE_762x39_MG_RecoilProne";
			dispersion = 0.00245;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 500;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.2;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class close: FullAuto
		{
			burst = "6+round random 6";
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 50;
			minRangeProbab = 0.8;
			midRange = "100+ random 50";
			midRangeProbab = 0.7;
			maxRange = "200+ random 50";
			maxRangeProbab = 0.1;
			showToPlayer = 0;
		};
		class short: close
		{
			burst = "4+round random 8";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 100;
			minRangeProbab = 0.8;
			midRange = "200+ random 50";
			midRangeProbab = 0.7;
			maxRange = "400+ random 50";
			maxRangeProbab = 0.1;
		};
		class medium: close
		{
			burst = "4+round random 6";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 200;
			minRangeProbab = 0.8;
			midRange = "400+ random 50";
			midRangeProbab = 0.7;
			maxRange = "500+ random 50";
			maxRangeProbab = 0.1;
		};
		class far: close
		{
			burst = "2+round random 6";
			aiRateOfFire = 3;
			aiRateOfFireDistance = 800;
			minRange = 400;
			minRangeProbab = 0.8;
			midRange = "600+ random 50";
			midRangeProbab = 0.7;
			maxRange = "700+ random 50";
			maxRangeProbab = 0.1;
		};
		class ACE_Burst_Far: far
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 400;
			minRangeProbab = 0.05;
			midRange = 500;
			midRangeProbab = 0.1;
			maxRange = 600;
			maxRangeProbab = 0.1;
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
	};
	class VSS_vintorez: Rifle
	{
		class Single;
	};
	class ACE_Val: VSS_vintorez
	{
		ACE_sys_weapons_Type = 1;
		model = "\x\acex\addons\m_wep_rh_ak\RH_asval.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\asval.paa";
		displayName = "AS Val";
		magazines[] = {"ACE_20Rnd_9x39_SP6_VSS","20Rnd_9x39_SP5_VSS","ACE_10Rnd_9x39_SP6_VSS","10Rnd_9x39_SP5_VSS"};
		handAnim[] = {"OFP2_ManSkeleton","\Ca\Weapons_PMC\Data\Anim\XM8GL.rtm"};
		opticsZoomMin = 0.25;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.5;
		optics = 1;
		modelOptics = "-";
		opticsPPEffects[] = {};
		ace_sa_enabled = 0;
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		discreteDistance[] = {100,200,300};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponZeroing";
		visionMode[] = {};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		ace_weight = 2.5;
		dexterity = "(0.5 + 3.75/(2.5 + 0.001) + 0/10)";
	};
	class ACE_Val_Kobra: ACE_Val
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_asvalk.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\asvalk.paa";
		displayName = "AS Val Kobra";
		distanceZoomMin = 150;
		distanceZoomMax = 150;
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 2.85;
		dexterity = "(0.5 + 3.75/(2.5+ 0.35 + 0.001) + 0/10)";
	};
	class ACE_Val_PSO: ACE_Val
	{
		model = "\x\acex\addons\m_wep_rh_ak\RH_asvalsp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\asvalsp.paa";
		displayName = "AS Val PSO";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1";
		ace_sa_enabled = 1;
		weaponInfoType = "RscWeaponEmpty";
		class OpticsModes
		{
			class PSO
			{
				opticsID = 1;
				distanceZoomMin = 100;
				distanceZoomMax = 100;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				useModelOptics = 1;
				memoryPointCamera = "opticView";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
			class CQB: PSO
			{
				opticsID = 2;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				opticsPPEffects[] = {};
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				weaponInfoType = "RscWeaponEmpty";
			};
		};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 600;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		ace_weight = 3.1;
		dexterity = "(0.5 + 3.75/(2.5+ 0.6 + 0.001) + 0/10)";
	};
	class ACE_oc14: AK_74
	{
		ACE_sys_weapons_Side[] = {"RU"};
		ace_weight = 2.7;
		dexterity = "(0.5 + 3.75/(2.7 + 0.001) + 2/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_oc14.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_oc14_ca.paa";
		displayName = "Groza-9";
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_rh_ak\ak_reload.wss",0.056234,1,20};
		modes[] = {"Single","Burst","FullAuto"};
		magazines[] = {"ACE_20Rnd_9x39_B_SP6_OC14","ACE_20Rnd_9x39_B_OC14","ACE_20Rnd_9x39_S_SP6_OC14","ACE_20Rnd_9x39_S_OC14"};
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		discreteDistance[] = {100,200,300};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponZeroing";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_rh_ak\anim\RH_oc14.rtm"};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire1.wss",1.778279,1,500};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire2.wss",1.778279,1,500};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire3.wss",1.778279,1,500};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			reloadTime = 0.085;
			dispersion = 0.0023;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire1.wss",1.778279,1,500};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire2.wss",1.778279,1,500};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire3.wss",1.778279,1,500};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			reloadTime = 0.085;
			dispersion = 0.0023;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 200;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire1.wss",1.778279,1,500};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire2.wss",1.778279,1,500};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza939_fire3.wss",1.778279,1,500};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			reloadTime = 0.085;
			ffCount = 20;
			dispersion = 0.0023;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_gp30Muzzle: GP25Muzzle
		{
			displayName = "$STR_DN_ACE_GP30";
		};
		class Library
		{
			libTextDesc = "The OC-14 Groza ( Thunderstorm in Slavic languages), available in either 9 mm or 7.62mm bullpup combined assault rifle and grenade launcher designed by CKIB SOO (Central Design Bureau of Sporting and Hunting Weapons) in Tula, Russia, and manufactured by TOZ (Tula Weapons Plant, Russia). It is nearly identical to AKS-74U in function and can be modified with a suppressor, telescopic sight and or night vision device. The 9 mm uses the family of cartridges developed for suppressed fire during special operations - the subsonic SP-5, SP-6 and PAB-9 rounds. In the rifle grenade launcher version, OC-14 is operated with a single trigger, with a rifle\launcher switch located near the trigger guard. A 7.62x39mm version named Groza-1 was also developed for the Spetsnaz. This version accepts AK-47 standard magazines and may be equipped with a standard issue AK-74 bayonet. The 9 mm version supports 20-round magazines, and the 7.62x39mm allows using AK-type 30-round magazines.";
		};
		descriptionShort = "$STR_DSS_ACE_GROZA_9";
	};
	class ACE_oc14sp: ACE_oc14
	{
		ace_weight = 3.3000002;
		dexterity = "(0.5 + 3.75/(2.7+ 0.6 + 0.001) + 2/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_oc14sp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_oc14sp_ca.paa";
		displayName = "Groza-9 PSO";
		modelOptics = "\x\acex\addons\m_wep_rh_ak\NWD_GScope_1";
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		discreteDistance[] = {100,200,300,400};
		discreteDistanceInitIndex = 0;
		opticsFlare = 1;
		opticsDisablePeripherialVision = 1;
		magazines[] = {"ACE_20Rnd_9x39_B_OC14","ACE_20Rnd_9x39_B_SP6_OC14","ACE_20Rnd_9x39_S_OC14","ACE_20Rnd_9x39_S_SP6_OC14"};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 600;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		descriptionShort = "$STR_DSS_ACE_GROZA_9";
	};
	class ACE_oc14gl: ACE_oc14
	{
		ace_weight = 4.0;
		dexterity = "(0.5 + 3.75/(2.7+ 1.3 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_oc14gl.p3d";
		displayName = "Groza-9 GP-30";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_oc14gl_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\CA\weapons\Data\Anim\Bizon.rtm"};
		muzzles[] = {"this","ACE_gp30Muzzle","ACE_GP25Muzzle_AI"};
		descriptionShort = "$STR_DSS_ACE_GROZA_9GL";
	};
	class ACE_oc14glsp: ACE_oc14sp
	{
		ace_weight = 4.6;
		dexterity = "(0.5 + 3.75/(2.7+ 1.3+ 0.6 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_oc14glsp.p3d";
		displayName = "Groza-9 GP-30 PSO";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_oc14glsp_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\CA\weapons\Data\Anim\Bizon.rtm"};
		muzzles[] = {"this","ACE_gp30Muzzle","ACE_GP25Muzzle_AI"};
		descriptionShort = "$STR_DSS_ACE_GROZA_9GL";
	};
	class ACE_oc14sd: ACE_oc14
	{
		ace_weight = 3.4;
		dexterity = "(0.5 + 3.75/(2.7+ 0.7 + 0.001) + 1/10)";
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		model = "\x\acex\addons\m_wep_rh_ak\RH_oc14sd.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_oc14sd_ca.paa";
		displayName = "Groza-9 SD";
		magazines[] = {"ACE_20Rnd_9x39_S_SP6_OC14","ACE_20Rnd_9x39_S_OC14","ACE_20Rnd_9x39_B_SP6_OC14","ACE_20Rnd_9x39_B_OC14"};
		handAnim[] = {"OFP2_ManSkeleton","\CA\weapons\Data\Anim\Bizon.rtm"};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,1,50};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,1.02,50};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,0.97,50};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Burst
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,1,50};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,1.02,50};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,0.97,50};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,1,50};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,1.02,50};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza939sd_fire.wss",0.562341,0.97,50};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		descriptionShort = "$STR_DSS_ACE_GROZA_9_SD";
	};
	class ACE_oc14sdsp: ACE_oc14sd
	{
		ace_weight = 4.0;
		dexterity = "(0.5 + 3.75/(2.7+ 0.7+ 0.6 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_oc14sdsp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_oc14sdsp_ca.paa";
		displayName = "Groza-9 SD PSO";
		modelOptics = "\x\acex\addons\m_wep_rh_ak\NWD_GScope_1";
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		opticsFlare = 1;
		opticsDisablePeripherialVision = 1;
		discreteDistance[] = {100,200,300,400};
		discreteDistanceInitIndex = 0;
		magazines[] = {"ACE_20Rnd_9x39_S_OC14","ACE_20Rnd_9x39_S_SP6_OC14","ACE_20Rnd_9x39_B_OC14","ACE_20Rnd_9x39_B_SP6_OC14"};
		class Single: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 600;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		descriptionShort = "$STR_DSS_ACE_GROZA_9_SD";
	};
	class ACE_gr1: ACE_oc14
	{
		ace_weight = 3.1;
		dexterity = "(0.5 + 3.75/(3.1 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_gr1.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_gr1_ca.paa";
		displayName = "Groza-7.62";
		handAnim[] = {"OFP2_ManSkeleton","\CA\weapons\Data\Anim\Bizon.rtm"};
		magazines[] = {"30Rnd_762x39_AK47","ACE_30Rnd_762x39_S_AK47","ACE_30Rnd_762x39_T_AK47","ACE_40Rnd_762x39_B_AK47","ACE_40Rnd_762x39_S_AK47","ACE_40Rnd_762x39_T_AK47","ACE_75Rnd_762x39_B_AK47","ACE_75Rnd_762x39_S_AK47","ACE_30Rnd_762x39_AP_AK47","ACE_30Rnd_762x39_AP_S_AK47","ACE_40Rnd_762x39_AP_AK47","ACE_40Rnd_762x39_AP_S_AK47","ACE_30Rnd_762x39_SD_AK47","ACE_75Rnd_762x39_SD_AK47"};
		distanceZoomMin = 300;
		distanceZoomMax = 300;
		discreteDistance[] = {100,200,300,400,500};
		discreteDistanceInitIndex = 2;
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762_fire1.wss",1.778279,1,1700};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza762_fire2.wss",1.778279,1,1700};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.08;
			recoil = "ACE_762x39_Groza_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			dispersion = 0.00225;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class Burst: Burst
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762_fire1.wss",1.778279,1,1700};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza762_fire2.wss",1.778279,1,1700};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.08;
			recoil = "ACE_762x39_Groza_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			dispersion = 0.00225;
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762_fire1.wss",1.778279,1,1700};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza762_fire2.wss",1.778279,1,1700};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.08;
			ffCount = 30;
			recoil = "ACE_762x39_Groza_Recoil";
			recoilProne = "ACE_762x39_Rifle_RecoilProne";
			dispersion = 0.00225;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		descriptionShort = "$STR_DSS_AK47M";
	};
	class ACE_gr1sp: ACE_gr1
	{
		ace_weight = 3.6999998;
		dexterity = "(0.5 + 3.75/(3.1+ 0.6 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_gr1sp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_gr1sp_ca.paa";
		displayName = "Groza-7.62 PSO";
		modelOptics = "\x\acex\addons\m_wep_rh_ak\NWD_GScope_1";
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		opticsFlare = 1;
		opticsDisablePeripherialVision = 1;
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		descriptionShort = "$STR_DSS_AK47M";
	};
	class ACE_gr1sd: ACE_gr1
	{
		ace_weight = 3.8;
		dexterity = "(0.5 + 3.75/(3.1+ 0.7 + 0.001) + 1/10)";
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		model = "\x\acex\addons\m_wep_rh_ak\RH_gr1sd.p3d";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		discreteDistance[] = {100,200,300,400,500};
		discreteDistanceInitIndex = 0;
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_gr1sd_ca.paa";
		displayName = "Groza-7.62 SD";
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_rh_ak\ak_reload.wss",0.056234,1,20};
		magazines[] = {"ACE_30Rnd_762x39_SD_AK47","ACE_75Rnd_762x39_SD_AK47","ACE_30Rnd_762x39_S_AK47","30Rnd_762x39_AK47","ACE_30Rnd_762x39_T_AK47","ACE_40Rnd_762x39_S_AK47","ACE_40Rnd_762x39_B_AK47","ACE_40Rnd_762x39_T_AK47","ACE_75Rnd_762x39_S_AK47","ACE_75Rnd_762x39_B_AK47","ACE_30Rnd_762x39_AP_S_AK47","ACE_30Rnd_762x39_AP_AK47","ACE_40Rnd_762x39_AP_S_AK47","ACE_40Rnd_762x39_AP_AK47"};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1,100};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,0.97,100};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1.02,100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Burst
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1,100};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,0.97,100};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1.02,100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1,100};
			begin2[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,0.97,100};
			begin3[] = {"\x\acex\addons\s_wep_rh_ak\groza762sd_fire.wss",1,1.02,100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			ffCount = 30;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		descriptionShort = "$STR_DSS_ACE_GROZA_762_SD";
	};
	class ACE_gr1sdsp: ACE_gr1sd
	{
		ace_weight = 4.4;
		dexterity = "(0.5 + 3.75/(3.1+ 0.7+ 0.6 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_rh_ak\RH_gr1sdsp.p3d";
		picture = "\x\acex\addons\c_wep_rh_ak\i\w_gr1sdsp_ca.paa";
		displayName = "Groza-7.62 SD PSO";
		modelOptics = "\x\acex\addons\m_wep_rh_ak\NWD_GScope_1";
		opticsZoomMin = 0.071945;
		opticsZoomMax = 0.071945;
		opticsZoomInit = 0.071945;
		opticsFlare = 1;
		opticsDisablePeripherialVision = 1;
		descriptionShort = "$STR_DSS_ACE_GROZA_762_SD";
		class Single: Single
		{
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
	};
};
//};
