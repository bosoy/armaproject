////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed May 23 21:40:35 2012 : Created on Wed May 23 21:40:35 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_hk : config.bin{
class CfgPatches
{
	class acex_wep_hk
	{
		units[] = {};
		weapons[] = {"ACE_HK416_D10","ACE_HK416_D10_AIM","ACE_HK416_D10_COMPM3","ACE_HK416_D10_Holo","ACE_HK416_D10_M320","ACE_HK416_D14","ACE_HK416_D14_COMPM3","ACE_HK416_D14_COMPM3_M320","ACE_HK416_D14_ACOG_PVS14","ACE_HK416_D14_TWS","ACE_HK416_D10_SD","ACE_HK416_D10_COMPM3_SD","ACE_HK416_D14_SD","ACE_HK417_Shortdot","ACE_HK417_leupold","ACE_HK417_micro","ACE_HK417_Eotech_4x","ACE_M27_IAR","ACE_M27_IAR_ACOG","ACE_M27_IAR_CCO"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons2","acex_main","acex_m_wep_hk","acex_t_wep_hk","acex_s_wep_hk","ace_c_weapon","ace_sys_attachments"};
		version = "1.13.0.363";
		author[] = {"Panda[pl]"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_hk
		{
			list[] = {"acex_wep_hk"};
		};
	};
};
class CfgWeapons
{
	class M16_base;
	class M4A1: M16_base
	{
		class Single;
		class FullAuto;
	};
	class M4A1_Aim;
	class M4A1_AIM_SD_camo: M4A1_Aim
	{
		class Single;
		class FullAuto;
	};
	class M4A1_RCO_GL: M4A1
	{
		class M203Muzzle;
	};
	class M4A1_HWS_GL: M4A1_RCO_GL
	{
		class Single;
		class FullAuto;
	};
	class ACE_HK416_D10: M4A1
	{
		scope = 2;
		displayName = "HK416-D10RS";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_iron_ca.paa";
		ace_weight = 3.1;
		dexterity = "(0.5 + 3.75/(3+ 0.1 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_hk\D10_iron.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		ace_mv[] = {"B_556x45_Ball",780,"ACE_B_556x45_SB",720,"ACE_B_556x45_T",780,"ACE_B_556x45_S",780,"ACE_B_556x45_SB_S",720};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_hk\m4_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4_fire1.wss",1,1.04,1100};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4_fire2.wss",1,1.03,1100};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4_fire3.wss",1,1.02,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
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
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4_fire1.wss",1,1.04,1100};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4_fire2.wss",1,1.03,1100};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4_fire3.wss",1,1.02,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
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
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		class Library
		{
			libTextDesc = "";
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400};
		discreteDistanceInitIndex = 0;
	};
	class ACE_HK416_D10_AIM: M4A1
	{
		displayName = "HK416-D10RS microCCO";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_cco_ca.paa";
		ace_weight = 3.1999998;
		dexterity = "(0.5 + 3.75/(3+ 0.1+ 0.1 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_hk\D10_micro.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		ace_mv[] = {"B_556x45_Ball",780,"ACE_B_556x45_SB",720,"ACE_B_556x45_T",780,"ACE_B_556x45_S",780,"ACE_B_556x45_SB_S",720};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_hk\m4_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4_fire1.wss",1,1.04,1100};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4_fire2.wss",1,1.03,1100};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4_fire3.wss",1,1.02,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
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
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4_fire1.wss",1,1.04,1100};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4_fire2.wss",1,1.03,1100};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4_fire3.wss",1,1.02,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
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
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		class Library
		{
			libTextDesc = "";
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	class ACE_HK416_D10_COMPM3: ACE_HK416_D10_AIM
	{
		displayName = "HK416-D10RS CompM3";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_cco_2_ca.paa";
		ace_weight = 3.564;
		dexterity = "(0.5 + 3.75/(3+ 0.264+ 0.2+ 0.1 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_hk\D10_compm3.p3d";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
	};
	class ACE_HK416_D10_Holo: ACE_HK416_D10_COMPM3
	{
		displayName = "HK416-D10RS Holo";
		picture = "\x\acex\addons\c_wep_hk\i\w_ace_hk416_holo_ca.paa";
		ace_weight = 3.4499998;
		dexterity = "(0.5 + 3.75/(3+ 0.35+ 0.1 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_hk\D10_EOtech.p3d";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	class ACE_HK416_D10_M320: M4A1_HWS_GL
	{
		scope = 2;
		displayName = "HK416-D10RS M320";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_iron_m320_ca.paa";
		ace_weight = 4.5;
		dexterity = "(0.5 + 3.75/(3+ 1.5 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_hk\D10_M320f.p3d";
		class m203muzzle: m203muzzle
		{
			displayName = "M320";
		};
		ace_gl_fineadj = 0;
		ace_mv[] = {"B_556x45_Ball",780,"ACE_B_556x45_SB",720,"ACE_B_556x45_T",780,"ACE_B_556x45_S",780,"ACE_B_556x45_SB_S",720};
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_hk\Anim\XM8GL.rtm"};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_hk\m4_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4_fire1.wss",1,1.04,1100};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4_fire2.wss",1,1.03,1100};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4_fire3.wss",1,1.02,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
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
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4_fire1.wss",1,1.04,1100};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4_fire2.wss",1,1.03,1100};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4_fire3.wss",1,1.02,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
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
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		class Library
		{
			libTextDesc = "";
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ace_gl_classes[] = {"ACE_HK416_D10_M320","ACE_HK416_D10_M320_UP"};
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400};
		discreteDistanceInitIndex = 0;
	};
	class ACE_HK416_D10_M320_UP: ACE_HK416_D10_M320
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_hk\D10_M320.p3d";
	};
	class ACE_HK416_D14: ACE_HK416_D10
	{
		displayName = "HK416-D14.5RS";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_iron_ca.paa";
		ace_weight = 3.6;
		dexterity = "(0.5 + 3.75/(3.5+ 0.1 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_hk\D14_iron.p3d";
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790,"ACE_B_556x45_S",880,"ACE_B_556x45_SB_S",790};
		class Single: Single
		{
			dispersion = 0.00225;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.00225;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		discreteDistanceInitIndex = 2;
	};
	class ACE_HK416_D14_COMPM3: ACE_HK416_D14
	{
		displayName = "HK416-D14.5RS CompM3";
		picture = "\x\acex\addons\c_wep_hk\i\w_d14_cco_2_ca.paa";
		model = "\x\acex\addons\m_wep_hk\D14_compm3.p3d";
		ace_weight = 4.064;
		dexterity = "(0.5 + 3.75/(3.5+ 0.264+ 0.2+ 0.1 + 0.001) + 1/10)";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_HK416_D14_COMPM3_M320: ACE_HK416_D10_M320
	{
		displayName = "HK416-D14.5RS CompM3 M320";
		model = "\x\acex\addons\m_wep_hk\D14_m320f_compm3.p3d";
		picture = "\x\acex\addons\c_wep_hk\i\w_d14_cco_gl_ca.paa";
		ace_weight = 5.4639997;
		dexterity = "(0.5 + 3.75/(3.5+ 0.264+ 0.2+ 1.5 + 0.001) + 0/10)";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_mv[] = {"B_556x45_Ball",880,"ACE_B_556x45_T",880,"ACE_B_556x45_SB",790,"ACE_B_556x45_S",880,"ACE_B_556x45_SB_S",790};
		ace_gl_fineadj = -13;
		ace_gl_classes[] = {"ACE_HK416_D14_COMPM3_M320","ACE_HK416_D14_COMPM3_M320_UP"};
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		class Single: Single
		{
			dispersion = 0.00225;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.00225;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
	};
	class ACE_HK416_D14_COMPM3_M320_UP: ACE_HK416_D14_COMPM3_M320
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_hk\D14_m320_compm3.p3d";
	};
	class ACE_HK416_D14_ACOG_PVS14: ACE_HK416_D14
	{
		displayName = "HK416-D14.5RS ACOG PVS14";
		picture = "\x\acex\addons\c_wep_hk\i\w_ace_hk416_rco_pvs_ca.paa";
		model = "\x\acex\addons\m_wep_hk\D14_PVS14_ACOG.p3d";
		ace_weight = 4.46;
		dexterity = "(0.5 + 3.75/(3.5+ 0.46+ 0.4+ 0.1 + 0.001) + 1/10)";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		class OpticsModes
		{
			class ACOG_NV
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				memoryPointCamera = "opticView";
				visionMode[] = {"NVG"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				cameraDir = "";
			};
			class CQB: ACOG_NV
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsPPEffects[] = {};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "eye";
				visionMode[] = {};
			};
		};
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_sys_nvg_nvrange = 850;
	};
	class ACE_HK416_D14_TWS: ACE_HK416_D14
	{
		displayName = "HK416-D14.5RS TWS";
		picture = "\x\acex\addons\c_wep_hk\i\w_ace_hk416_tws_ca.paa";
		model = "\x\acex\addons\m_wep_hk\D14_thermal.p3d";
		ace_weight = 4.5;
		dexterity = "(0.5 + 3.75/(3.5+ 0.9+ 0.1 + 0.001) + 1/10)";
		modelOptics = "\Ca\weapons_E\LWTS_optic.p3d";
		class OpticsModes
		{
			class LTWS
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomMin = 0.1606;
				opticsZoomMax = 0.1606;
				opticsZoomInit = 0.1606;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "eye";
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				opticsPPEffects[] = {};
				visionMode[] = {"Ti"};
				thermalMode[] = {0,1};
			};
		};
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_sys_nvg_tirange = 1050;
	};
	class ACE_M27_IAR: ACE_HK416_D14
	{
		displayName = "M27 IAR";
		model = "\x\acex\addons\m_wep_hk\M27_IAR.p3d";
		picture = "\x\acex\addons\c_wep_hk\i\w_ace_m27_ca.paa";
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m27_fire1.wss",1,1,1100};
			soundBegin[] = {"begin1",1};
			dispersion = 0.0018;
			recoilProne = "ACE_556x45_MG_RecoilProne";
			reloadtime = 0.1;
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m27_fire2.wss",1,1,1100};
			soundBegin[] = {"begin1",1};
			dispersion = 0.0018;
			recoilProne = "ACE_556x45_MG_RecoilProne";
			reloadtime = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		class ACE_Burst_Far: ACE_Burst_AI
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 600;
			minRange = 500;
			minRangeProbab = 0.05;
			midRange = 600;
			midRangeProbab = 0.1;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2","ACE_Burst_Far"};
		ace_weight = 4.0;
		dexterity = "(0.5 + 3.75/(3.6+ 0.2+ 0.2 + 0.001) + 1/10)";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_bipod = 1;
		ace_cf = 1.2;
		ace_mv[] = {"B_556x45_Ball",890,"ACE_B_556x45_T",890,"ACE_B_556x45_SB",820,"ACE_B_556x45_S",890,"ACE_B_556x45_SB_S",820};
		discreteDistance[] = {200,300,400,500,600};
		discreteDistanceInitIndex = 1;
	};
	class ACE_M27_IAR_CCO: ACE_M27_IAR
	{
		displayName = "M27 IAR CCO";
		model = "\x\acex\addons\m_wep_hk\M27_IAR_CCO.p3d";
		picture = "\x\acex\addons\c_wep_hk\i\w_ace_m27_ca.paa";
		ace_weight = 4.35;
		dexterity = "(0.5 + 3.75/(3.6+ 0.2+ 0.2+ 0.35 + 0.001) + 1/10)";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_M27_IAR_ACOG: ACE_M27_IAR
	{
		displayName = "M27 IAR RCO";
		picture = "\x\acex\addons\c_wep_hk\i\w_ace_m27_rco_ca.paa";
		model = "\x\acex\addons\m_wep_hk\M27_IAR_acog.p3d";
		ace_weight = 4.46;
		dexterity = "(0.5 + 3.75/(3.6+ 0.2+ 0.2+ 0.46 + 0.001) + 1/10)";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		class OpticsModes
		{
			class ACOG
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
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
			class CQB: ACOG
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_bipod = 1;
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
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_HK416_D10_SD: M4A1_AIM_SD_camo
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		displayName = "HK416-D10RS SD";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_iron_sd_ca.paa";
		ace_weight = 3.6;
		dexterity = "(0.5 + 3.75/(3+ 0.1+ 0.5 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_hk\D10_iron_sd.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		ace_mv[] = {"ACE_B_556x45_S",780,"ACE_B_556x45_SB_S",720,"ACE_B_556x45_T",780,"B_556x45_Ball",780,"ACE_B_556x45_SB",720};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_hk\m4_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4sd_fire.wss",1,1,80};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4sd_fire.wss",1,0.97,80};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4sd_fire.wss",1,1.02,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
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
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_hk\m4sd_fire.wss",1,1,80};
			begin2[] = {"\x\acex\addons\s_wep_hk\m4sd_fire.wss",1,0.98,80};
			begin3[] = {"\x\acex\addons\s_wep_hk\m4sd_fire.wss",1,1.02,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			dispersion = 0.0025;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 30;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		class Library
		{
			libTextDesc = "";
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400};
		discreteDistanceInitIndex = 0;
	};
	class ACE_HK416_D10_COMPM3_SD: ACE_HK416_D10_SD
	{
		scope = 2;
		displayName = "HK416-D10RS CompM3 SD";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_cco_2_sd_ca.paa";
		model = "\x\acex\addons\m_wep_hk\D10_compm3_SD.p3d";
		ace_weight = 4.064;
		dexterity = "(0.5 + 3.75/(3+ 0.264+ 0.2+ 0.1+ 0.5 + 0.001) + 1/10)";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_HK416_D14_SD: ACE_HK416_D10_SD
	{
		scope = 2;
		displayName = "HK416-D14.5RS SD";
		picture = "\x\acex\addons\c_wep_hk\i\w_d10_iron_sd_ca.paa";
		ace_weight = 4.1;
		dexterity = "(0.5 + 3.75/(3.5+ 0.1+ 0.5 + 0.001) + 1/10)";
		model = "\x\acex\addons\m_wep_hk\D14_iron_sd.p3d";
		ace_mv[] = {"ACE_B_556x45_S",880,"ACE_B_556x45_SB_S",790,"ACE_B_556x45_T",880,"B_556x45_Ball",880,"ACE_B_556x45_SB",790};
		class Single: Single
		{
			dispersion = 0.00225;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 550;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.00225;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		discreteDistanceInitIndex = 2;
	};
	class ACE_HK417_Base: M4A1
	{
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_hk\762_reload.wss",0.0316228,1,20};
		scope = 1;
		ace_weight = 4.15;
		dexterity = "(0.5 + 3.75/(4.15 + 0.001) + 0/10)";
		class Library
		{
			libTextDesc = "";
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		handAnim[] = {};
		magazines[] = {"ACE_20Rnd_762x51_B_HK417","ACE_20Rnd_762x51_SB_HK417","ACE_20Rnd_762x51_T_HK417","ACE_20Rnd_762x51_S_HK417","ACE_20Rnd_762x51_SB_S_HK417"};
		class Single: Single
		{
			reloadTime = 0.1;
			dispersion = 0.0017;
			begin1[] = {"\x\acex\addons\s_wep_hk\hk417_fire1.wss",1,1,1700};
			begin2[] = {"\x\acex\addons\s_wep_hk\hk417_fire2.wss",1,1,1700};
			begin3[] = {"\x\acex\addons\s_wep_hk\hk417_fire1.wss",1,0.98,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			recoil = "ACE_762x51_SCAR_Recoil";
			recoilProne = "ACE_762x51_SCAR_RecoilProne";
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			reloadTime = 0.1;
			dispersion = 0.0017;
			begin1[] = {"\x\acex\addons\s_wep_hk\hk417_fire1.wss",1,1,1700};
			begin2[] = {"\x\acex\addons\s_wep_hk\hk417_fire2.wss",1,1,1700};
			begin3[] = {"\x\acex\addons\s_wep_hk\hk417_fire1.wss",1,0.98,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			recoil = "ACE_762x51_SCAR_Recoil";
			recoilProne = "ACE_762x51_SCAR_RecoilProne";
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 20;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 4";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 4";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		ace_mod_mv = 0;
		descriptionShort = "$STR_DSS_ACE_HK417";
	};
	class ACE_HK417_Shortdot: ACE_HK417_Base
	{
		scope = 2;
		displayName = "HK417 12'' Shortdot";
		ace_weight = 4.7200003;
		dexterity = "(0.5 + 3.75/(4+ 0.72 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_hk\M417_12in_shortdot.p3d";
		picture = "\x\acex\addons\c_wep_hk\i\417\w_ace_hk417_shortdot_ca.paa";
		class Single: Single
		{
			dispersion = 0.0023;
			aiRateOfFire = 3;
			aiRateOfFireDistance = 700;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 300;
			midRangeProbab = 0.6;
			maxRange = 700;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.0023;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 4";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 4";
		};
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x51_Ball",760,"ACE_B_762x51_T",760,"ACE_B_762x51_S",760,"B_762x51_noTracer",709,"ACE_B_762x51_SB_S",709};
		modelOptics = "\x\ace\addons\m_wep_optics\SB_CQB_optic_4x";
		class OpticsModes
		{
			class Shortdot
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.22;
				opticsZoomInit = 0.22;
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
			class CQB: Shortdot
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
	class ACE_HK417_leupold: ACE_HK417_Base
	{
		scope = 2;
		displayName = "HK417 16'' Leupold";
		ace_weight = 4.89;
		dexterity = "(0.5 + 3.75/(4.15+ 0.54+ 0.2 + 0.001) + 0/10)";
		ace_bipod = 1;
		model = "\x\acex\addons\m_wep_hk\M417_16in_leupold.p3d";
		picture = "\x\acex\addons\c_wep_hk\i\417\w_ace_hk417_leu_ca.paa";
		magazines[] = {"ACE_20Rnd_762x51_SB_HK417","ACE_20Rnd_762x51_B_HK417","ACE_20Rnd_762x51_T_HK417","ACE_20Rnd_762x51_S_HK417","ACE_20Rnd_762x51_SB_S_HK417"};
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
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_10x_round_mildot";
		opticsZoomMin = 0.029624;
		opticsZoomMax = 0.085714;
		opticsZoomInit = 0.085714;
		opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
		class OpticsModes
		{
			class StepScope
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsZoomMin = 0.033574;
				opticsZoomMax = 0.087666;
				opticsZoomInit = 0.087666;
				memoryPointCamera = "eye";
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				cameraDir = "";
				visionMode[] = {"Normal"};
			};
		};
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 9;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 300;
		ace_sa_zerooffset = 0;
		ace_sa_minelevation = -10;
		ace_sa_maxelevation = 51;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 35;
		ace_sa_stepwindage = 0.5;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_drift[] = {{0,0},{100,0.03},{200,0.08},{300,0.18},{400,0.305},{500,0.57},{600,0.92},{700,1.3},{800,1.85},{900,2.5},{1000,3.3}};
		ace_sa_table_elev[] = {{0,0},{100,3},{200,6},{300,9},{400,13},{500,18},{600,23},{700,28},{800,35},{900,41},{1000,50}};
	};
	class ACE_HK417_micro: ACE_HK417_Base
	{
		scope = 2;
		displayName = "HK417 12'' Aimpoint Micro";
		picture = "\x\acex\addons\c_wep_hk\i\417\w_ace_hk417_cco_ca.paa";
		ace_weight = 4.1;
		dexterity = "(0.5 + 3.75/(4+ 0.1 + 0.001) + 0/10)";
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x51_Ball",760,"ACE_B_762x51_T",760,"ACE_B_762x51_S",760,"B_762x51_noTracer",709,"ACE_B_762x51_SB_S",709};
		model = "\x\acex\addons\m_wep_hk\M417_12in_micro.p3d";
		class Single: Single
		{
			dispersion = 0.0023;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.0023;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 4";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 4";
		};
	};
	class ACE_HK417_Eotech_4x: ACE_HK417_micro
	{
		displayName = "HK417 12'' Holo 4x";
		ace_weight = 4.69;
		dexterity = "(0.5 + 3.75/(4+ 0.35+ 0.34 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_hk\M417_12in_EOtech4x.p3d";
		picture = "\x\acex\addons\c_wep_hk\i\417\w_ace_hk417_eotech4_ca.paa";
		modelOptics = "\x\acex\addons\m_wep_socom\ACE_Eotech_magn_optic_4x.p3d";
		class OpticsModes
		{
			class EOTech4x
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
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
			class CQB: EOTech4x
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
	};
};
class CfgMagazines
{
	class 20Rnd_762x51_B_SCAR;
	class ACE_20Rnd_762x51_B_HK417: 20Rnd_762x51_B_SCAR
	{
		model = "\x\acex\addons\m_wep_hk\hk417_mag.p3d";
	};
};
//};
