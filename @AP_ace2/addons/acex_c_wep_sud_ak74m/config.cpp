////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed May 23 21:40:40 2012 : Created on Wed May 23 21:40:40 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_sud_ak74m : config.bin{
class CfgPatches
{
	class acex_wep_sud_ak74m
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_m_wep_sud_ak74m","acex_t_wep_sud_ak74m"};
		version = "1.13.0.363";
		author[] = {"Sudden"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_sud_ak74m
		{
			list[] = {"acex_wep_sud_ak74m"};
		};
	};
};
class CfgWeapons
{
	class Rifle;
	class AK_BASE: Rifle
	{
		class Single;
		class FullAuto;
		class GP25Muzzle;
	};
	class AK_74: AK_BASE{};
	class AKS_BASE: AK_BASE{};
	class AKS_74_UN_kobra: AKS_BASE
	{
		class Single;
		class FullAuto;
	};
	class ACE_AK74M: AK_74
	{
		displayName = "AK-74M";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m";
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
		discreteDistanceInitIndex = 3;
		distanceZoomMin = 400;
		distanceZoomMax = 400;
		class Single: Single
		{
			reloadTime = 0.092;
		};
		class FullAuto: FullAuto
		{
			reloadTime = 0.092;
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
		modes[] = {"FullAuto","Single","ACE_Burst_AI","ACE_Burst_AI2"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ACE_sys_weapons_Side[] = {"RU"};
		ace_weight = 3.4;
		dexterity = "(0.5 + 3.75/(3.4 + 0.001) + 0/10)";
		class Armory
		{
			author = "Sudden";
			disabled = 0;
		};
	};
	class ACE_AK74M_FL: ACE_AK74M
	{
		displayName = "AK-74M (FL/L)";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M";
		ace_weight = 3.8000002;
		dexterity = "(0.5 + 3.75/(3.4+ 0.2+ 0.2 + 0.001) + 0/10)";
		class Armory
		{
			author = "Sudden";
			disabled = 0;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_gunlight_classes[] = {"ACE_AK74M_FL","ACE_AK74M_FL_F"};
	};
	class ACE_AK74M_FL_F: ACE_AK74M_FL
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_Kobra: ACE_AK74M
	{
		displayName = "AK-74M Kobra";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_C";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_f_c";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 3.75;
		dexterity = "(0.5 + 3.75/(3.4+ 0.35 + 0.001) + 0/10)";
	};
	class ACE_AK74M_Kobra_FL: ACE_AK74M_Kobra
	{
		displayName = "AK-74M Kobra (FL/L)";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_C";
		ace_weight = 4.15;
		dexterity = "(0.5 + 3.75/(3.4+ 0.35+ 0.2+ 0.2 + 0.001) + 0/10)";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_gunlight_classes[] = {"ACE_AK74M_Kobra_FL","ACE_AK74M_Kobra_FL_F"};
	};
	class ACE_AK74M_Kobra_FL_F: ACE_AK74M_Kobra_FL
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_PSO: ACE_AK74M
	{
		displayName = "AK-74M PSO";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_PSO";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_tb_pso";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistanceInitIndex = 3;
			};
		};
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
		ace_weight = 4.0;
		dexterity = "(0.5 + 3.75/(3.4+ 0.6 + 0.001) + 0/10)";
	};
	class ACE_AK74M_PSO_FL: ACE_AK74M_PSO
	{
		displayName = "AK-74M PSO (FL/L)";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_PSO";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 4.3999996;
		dexterity = "(0.5 + 3.75/(3.4+ 0.6+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_PSO_FL","ACE_AK74M_PSO_FL_F"};
	};
	class ACE_AK74M_PSO_FL_F: ACE_AK74M_PSO_FL
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_1P29: ACE_AK74M_PSO
	{
		displayName = "AK-74M 1P29";
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak74m1p29";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\ace_ak74m_1p29";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ace_weight = 4.2000003;
		dexterity = "(0.5 + 3.75/(3.4+ 0.8 + 0.001) + 0/10)";
	};
	class ACE_AK74M_1P78: ACE_AK74M
	{
		displayName = "AK-74M 1P78";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_1P78";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_tb_1p78";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_1P78";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.0994;
				opticsZoomMax = 0.0994;
				opticsZoomInit = 0.0994;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
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
		ace_weight = 4.1;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7 + 0.001) + 0/10)";
	};
	class ACE_AK74M_1P78_FL: ACE_AK74M_1P78
	{
		displayName = "AK-74M 1P78 (FL/L)";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_1P78";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 4.4999995;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_1P78_FL","ACE_AK74M_1P78_FL_F"};
	};
	class ACE_AK74M_1P78_FL_F: ACE_AK74M_1P78_FL
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_TWS: ACE_AK74M
	{
		displayName = "AK-74M Goshawk";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_GS";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_tb_gs";
		modelOptics = "\Ca\weapons_E\TI_goshawk_optic";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {};
				memoryPointCamera = "opticview";
				visionMode[] = {"Ti"};
				thermalmode[] = {0};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.0694444;
				opticsZoomMax = 0.0694444;
				opticsZoomInit = 0.0694444;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800};
				discreteDistanceInitIndex = 2;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 5.0;
		dexterity = "(0.5 + 3.75/(3.4+ 1.6 + 0.001) + 0/10)";
	};
	class ACE_AK74M_TWS_FL: ACE_AK74M_TWS
	{
		displayName = "AK-74M Goshawk (FL/L)";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_GS";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 5.3999996;
		dexterity = "(0.5 + 3.75/(3.4+ 1.6+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_TWS_FL","ACE_AK74M_TWS_FL_F"};
	};
	class ACE_AK74M_TWS_FL_F: ACE_AK74M_TWS_FL
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_NSPU: ACE_AK74M
	{
		displayName = "AK-74M NSPU";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_N";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_tb_n";
		modelOptics = "\Ca\weapons_E\NV_nspu_optic";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {};
				memoryPointCamera = "opticview";
				visionMode[] = {"NVG"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.085333;
				opticsZoomMax = 0.085333;
				opticsZoomInit = 0.085333;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
		ace_weight = 5.6000004;
		dexterity = "(0.5 + 3.75/(3.4+ 2.2 + 0.001) + 0/10)";
	};
	class ACE_AK74M_NSPU_FL: ACE_AK74M_NSPU
	{
		displayName = "AK-74M NSPU (FL/L)";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_N";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 6.0;
		dexterity = "(0.5 + 3.75/(3.4+ 2.2+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_NSPU_FL","ACE_AK74M_NSPU_FL_F"};
	};
	class ACE_AK74M_NSPU_FL_F: ACE_AK74M_NSPU_FL
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_GL: ACE_AK74M
	{
		displayName = "AK-74M GP-25";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_GL";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_gl";
		muzzles[] = {"this","GP25Muzzle","ACE_GP25Muzzle_AI"};
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		class Single: Single
		{
			recoil = "ACE_545x39_Rifle_Recoil_GL";
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_545x39_Rifle_Recoil_GL";
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
		ace_weight = 4.9;
		dexterity = "(0.5 + 3.75/(3.4+ 1.5 + 0.001) + 0/10)";
	};
	class ACE_AK74M_GL_Kobra: ACE_AK74M_GL
	{
		displayName = "AK-74M GP-25 Kobra";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_GL_F_C";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_gl_f_c";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		ace_weight = 5.45;
		dexterity = "(0.5 + 3.75/(3.4+ 1.5+ 0.35+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK74M_GL_PSO: ACE_AK74M_GL
	{
		displayName = "AK-74M GP-25 PSO";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_GL_TB_PSO";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_gl_tb_pso";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistanceInitIndex = 3;
			};
		};
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 5.7;
		dexterity = "(0.5 + 3.75/(3.4+ 1.5+ 0.6+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK74M_GL_1P29: ACE_AK74M_GL_PSO
	{
		displayName = "AK-74M GP-30 1P29";
		model = "\x\acex\addons\m_wep_rh_ak\RH_ak74mgl1p29";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\ace_ak74m_gl_1p29";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_1P29";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
			};
		};
		class GP25Muzzle: GP25Muzzle
		{
			displayName = "$STR_DN_ACE_GP30";
		};
		ace_gl_fineadj = -28;
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ace_weight = 5.5;
		dexterity = "(0.5 + 3.75/(3.4+ 1.3+ 0.8 + 0.001) + 0/10)";
	};
	class ACE_AK74M_GL_1P78: ACE_AK74M_GL
	{
		displayName = "AK-74M GP-25 1P78";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_GL_TB_1p78";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_gl_tb_1p78";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_1P78";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.0994;
				opticsZoomMax = 0.0994;
				opticsZoomInit = 0.0994;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 5.7999997;
		dexterity = "(0.5 + 3.75/(3.4+ 1.5+ 0.7+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK74M_GL_TWS: ACE_AK74M_GL
	{
		displayName = "AK-74M GP-25 Goshawk";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_GL_TB_GS";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_gl_tb_gs";
		modelOptics = "\Ca\weapons_E\TI_goshawk_optic";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {};
				memoryPointCamera = "opticview";
				visionMode[] = {"Ti"};
				thermalmode[] = {0};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.0694444;
				opticsZoomMax = 0.0694444;
				opticsZoomInit = 0.0694444;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800};
				discreteDistanceInitIndex = 2;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 6.7;
		dexterity = "(0.5 + 3.75/(3.4+ 1.5+ 1.6+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK74M_GL_NSPU: ACE_AK74M_GL
	{
		displayName = "AK-74M GP-25 NSPU";
		model = "\x\acex\addons\m_wep_sud_ak74m\SUD_AK74M_GL_TB_N";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_gl_tb_n";
		modelOptics = "\Ca\weapons_E\NV_nspu_optic";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {};
				memoryPointCamera = "opticview";
				visionMode[] = {"NVG"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.085333;
				opticsZoomMax = 0.085333;
				opticsZoomInit = 0.085333;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 7.3;
		dexterity = "(0.5 + 3.75/(3.4+ 1.5+ 2.2+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_AK74M_SD: AKS_74_UN_Kobra
	{
		displayName = "AK-74M SD";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_S";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_s";
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
		discreteDistanceInitIndex = 3;
		distanceZoomMin = 400;
		distanceZoomMax = 400;
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
		modes[] = {"FullAuto","Single","ACE_Burst_AI","ACE_Burst_AI2"};
		class Library
		{
			libTextDesc = "";
		};
		ace_mod_mv = 0;
		ace_sys_weapons_side[] = {"RU"};
		ace_weight = 4.4999995;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7+ 0.2+ 0.2 + 0.001) + 0/10)";
		class Armory
		{
			author = "Sudden";
			disabled = 0;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_gunlight_classes[] = {"ACE_AK74M_SD","ACE_AK74M_SD_F"};
	};
	class ACE_AK74M_SD_F: ACE_AK74M_SD
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_SD_Kobra: ACE_AK74M_SD
	{
		displayName = "AK-74M SD Kobra";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_S_C";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_s_f_c";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 4.8499994;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7+ 0.35+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_SD_Kobra","ACE_AK74M_SD_Kobra_F"};
	};
	class ACE_AK74M_SD_Kobra_F: ACE_AK74M_SD_Kobra
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_SD_PSO: ACE_AK74M_SD
	{
		displayName = "AK-74M SD PSO";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_S_PSO";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_s_tb_pso";
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_PSO_1_1_AK74";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 2;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistanceInitIndex = 3;
			};
		};
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 5.0999994;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7+ 0.6+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_SD_PSO","ACE_AK74M_SD_PSO_F"};
	};
	class ACE_AK74M_SD_PSO_F: ACE_AK74M_SD_PSO
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_SD_1P78: ACE_AK74M_SD
	{
		displayName = "AK-74M SD 1P78";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_S_1P78";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_s_tb_1p78";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_1P78";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.0994;
				opticsZoomMax = 0.0994;
				opticsZoomInit = 0.0994;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsPPEffects[] = {};
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 5.1999993;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7+ 0.7+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_SD_1P78","ACE_AK74M_SD_1P78_F"};
	};
	class ACE_AK74M_SD_1P78_F: ACE_AK74M_SD_1P78
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_SD_TWS: ACE_AK74M_SD
	{
		displayName = "AK-74M SD Goshawk";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_S_GS";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_s_tb_gs";
		modelOptics = "\Ca\weapons_E\TI_goshawk_optic";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {};
				memoryPointCamera = "opticview";
				visionMode[] = {"Ti"};
				thermalmode[] = {0};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.0694444;
				opticsZoomMax = 0.0694444;
				opticsZoomInit = 0.0694444;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				discreteDistance[] = {100,200,300,400,500,600,700,800};
				discreteDistanceInitIndex = 2;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 6.0999994;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7+ 1.6+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_SD_TWS","ACE_AK74M_SD_TWS_F"};
	};
	class ACE_AK74M_SD_TWS_F: ACE_AK74M_SD_TWS
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
	class ACE_AK74M_SD_NSPU: ACE_AK74M_SD
	{
		displayName = "AK-74M SD NSPU";
		model = "\x\acex\addons\m_wep_sud_ak74m\ACE_AK74M_S_N";
		picture = "\x\acex\addons\c_wep_sud_ak74m\i\sud_ak74m_s_tb_n";
		modelOptics = "\Ca\weapons_E\NV_nspu_optic";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {};
				memoryPointCamera = "opticview";
				visionMode[] = {"NVG"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.085333;
				opticsZoomMax = 0.085333;
				opticsZoomInit = 0.085333;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				memoryPointCamera = "eye";
				visionMode[] = {};
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discreteDistanceInitIndex = 3;
			};
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 6.7;
		dexterity = "(0.5 + 3.75/(3.4+ 0.7+ 2.2+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gunlight_classes[] = {"ACE_AK74M_SD_NSPU","ACE_AK74M_SD_NSPU_F"};
	};
	class ACE_AK74M_SD_NSPU_F: ACE_AK74M_SD_NSPU
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "fl_start";
			direction = "fl_dir";
			angle = 20;
			scale[] = {0.15,0.15,0.15};
			brightness = 0.05;
		};
		class Armory
		{
			author = "Sudden";
			disabled = 1;
		};
	};
};
//};
