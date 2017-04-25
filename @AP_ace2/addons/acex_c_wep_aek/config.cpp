////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Sep 22 15:14:54 2012 : Created on Sat Sep 22 15:14:54 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_aek : config.bin{
class CfgPatches
{
	class acex_wep_aek
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_m_wep_aek","acex_t_wep_aek","acex_wep_rh_ak","acex_wep_sud_ak74m"};
		version = "1.13.0.367";
		author[] = {"yvandrey"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_aek
		{
			list[] = {"acex_wep_aek"};
		};
	};
};
class cfgRecoils
{
	AEK_971_Recoil[] = {0,0,0,0.06,0.008,0.00416,0.1,0,-0.0066,0.1,-0.008,0.0034,0.05,0,0};
	AEK_971_Recoil_prone[] = {0,0,0,0.06,0.0075,0.00396,0.1,0,-0.006,0.1,-0.0075,0.003,0.05,0,0};
	AEK_973_Recoil[] = {0,0,0,0.06,0.01,0.00416,0.1,0,-0.0066,0.1,-0.01,0.0034,0.05,0,0};
	AEK_973_Recoil_prone[] = {0,0,0,0.06,0.008,0.00396,0.1,0,-0.006,0.1,-0.008,0.003,0.05,0,0};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Rifle;
	class AK_BASE;
	class AK_107_BASE: AK_BASE
	{
		class Single;
		class Burst;
		class FullAuto;
	};
	class AKS_74_UN_kobra;
	class ACE_AK74M_SD: AKS_74_UN_Kobra
	{
		class Single;
		class Burst;
		class FullAuto;
	};
	class AK_47_M;
	class ACE_AK103: AK_47_M
	{
		class Single;
		class Burst;
		class FullAuto;
	};
	class AK_47_S;
	class ACE_AKMS_SD: AK_47_S
	{
		class Single;
		class Burst;
		class FullAuto;
	};
	class ACE_AEK_971: AK_107_BASE
	{
		scope = 2;
		htMax = 480;
		ace_sys_weapons_side[] = {"RU"};
		displayName = "$STR_AEK_971";
		model = "\x\acex\addons\m_wep_aek\aek-971";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971";
		ace_size = "72*8.6*20.7";
		ace_weight = 3.3;
		dexterity = "(0.5 + 3.75/(3.3 + 0.001) + 0/10)";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		ace_mod_mv = 1;
		ace_mv[] = {"B_545x39_Ball",880,"ACE_B_545x39_T",880,"ACE_B_545x39_S",880,"ACE_B_545x39_EP",880,"ACE_B_545x39_EP_S",880,"ACE_B_545x39_AP",880,"ACE_B_545x39_AP_S",880};
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
		discreteDistanceInitIndex = 2;
		modes[] = {"FullAuto","Burst","Single"};
		class Single: Single
		{
			reloadTime = 0.0667;
			recoil = "AEK_971_Recoil";
			recoilProne = "AEK_971_Recoil_prone";
		};
		class Burst: Burst
		{
			reloadTime = 0.0667;
			recoil = "AEK_971_Recoil";
			recoilProne = "AEK_971_Recoil_prone";
			burst = 3;
			showtoplayer = 1;
		};
		class FullAuto: FullAuto
		{
			reloadTime = 0.0667;
			recoil = "AEK_971_Recoil";
			recoilProne = "AEK_971_Recoil_prone";
		};
		class Library
		{
			libTextDesc = "$STR_LIB_AEK_971";
		};
		descriptionShort = "$STR_DSS_AK74";
		class Armory
		{
			author = "yvandrey";
			disabled = 0;
		};
	};
	class ACE_AEK_971_gp: ACE_AEK_971
	{
		displayName = "$STR_AEK_971_gp_34";
		descriptionShort = "$STR_DSS_AK74_GL";
		model = "\x\acex\addons\m_wep_aek\aek-971_gp";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971_GP_34";
		muzzles[] = {"this","ACE_GP34Muzzle","ACE_GP34Muzzle_AI"};
		class ACE_GP34Muzzle: GrenadeLauncher
		{
			displayname = "$STR_DN_ACE_GP34";
			magazines[] = {"1Rnd_HE_GP25","ACE_1Rnd_HE_GP25P","FlareWhite_GP25","FlareGreen_GP25","FlareRed_GP25","FlareYellow_GP25","1Rnd_SMOKE_GP25","1Rnd_SMOKERED_GP25","1Rnd_SMOKEGREEN_GP25","1Rnd_SMOKEYELLOW_GP25","ace_1rnd_cs_gp25","ACE_SSWhite_GP25","ACE_SSGreen_GP25","ACE_SSRed_GP25","ACE_SSYellow_GP25"};
			magazineReloadTime = 0;
			reloadTime = 0.1;
			recoil = "ACE_GL_Recoil";
			optics = 1;
			modelOptics = "-";
			cameraDir = "GL look";
			memoryPointCamera = "GL eye";
			opticsZoomMin = 0.3;
			opticsZoomMax = 0.5;
			opticsZoomInit = 0.5;
			ACE_GRENADE_TYPE = "GP25";
			opticsPPEffects[] = {};
			weaponInfoType = "RscWeaponEmpty";
		};
		class ACE_GP34Muzzle_AI: ACE_GP34Muzzle
		{
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = 0;
		};
		ace_gl_fineadj = 29;
		ace_weight = 4.7;
		dexterity = "(0.5 + 3.75/(3.3+ 1.4 + 0.001) + 0/10)";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
	};
	class ACE_AEK_971_1p63: ACE_AEK_971
	{
		displayName = "$STR_AEK_971_1P63";
		model = "\x\acex\addons\m_wep_aek\aek-971_1p63";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971_1P63";
		ace_weight = 3.9;
		dexterity = "(0.5 + 3.75/(3.3+ 0.6 + 0.001) + 0/10)";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_AEK_971_gp_1p63: ACE_AEK_971_gp
	{
		displayName = "$STR_AEK_971_1P63_GP_34";
		model = "\x\acex\addons\m_wep_aek\aek-971_gp_1p63";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971_GP_34_1P63";
		ace_weight = 5.3;
		dexterity = "(0.5 + 3.75/(3.3+ 0.6+ 1.4 + 0.001) + 0/10)";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_AEK_971_1p78: ACE_AEK_971
	{
		displayName = "$STR_AEK_971_1P78";
		model = "\x\acex\addons\m_wep_aek\aek-971_1p78";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971_1P78";
		ace_weight = 4.0;
		dexterity = "(0.5 + 3.75/(3.3+ 0.7 + 0.001) + 0/10)";
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
				discreteDistance[] = {100};
				discreteDistanceInitIndex = 0;
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
	};
	class ACE_AEK_971_1pn100: ACE_AEK_971
	{
		displayName = "$STR_AEK_971_1PN100";
		model = "\x\acex\addons\m_wep_aek\aek-971_1pn100";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971_1PN100";
		ace_weight = 5.0;
		dexterity = "(0.5 + 3.75/(3.3+ 1.7 + 0.001) + 0/10)";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_1pn100";
		class OpticsModes
		{
			class 1pn100
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal","NVG"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.069252;
				opticsZoomMax = 0.069252;
				opticsZoomInit = 0.069252;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: 1pn100
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
				discreteDistance[] = {100};
				discreteDistanceInitIndex = 0;
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
	};
	class ACE_AEK_971_shahin: ACE_AEK_971
	{
		displayName = "$STR_aek_971_shahin";
		model = "\x\acex\addons\m_wep_aek\aek-971_shahin";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971_SHAHIN";
		ace_weight = 4.9;
		dexterity = "(0.5 + 3.75/(3.3+ 1.6 + 0.001) + 0/10)";
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
				discreteDistanceInitIndex = 2;
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
	};
	class ACE_AEK_971_tgp_cln: ACE_AK74M_SD
	{
		htMax = 480;
		displayName = "$STR_AEK_971_tgp_cln";
		model = "\x\acex\addons\m_wep_aek\aek-971_tgp_cln";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_971_TGPA_CLN1K";
		ace_size = 12800;
		ace_weight = 4.38;
		dexterity = "(0.5 + 3.75/(3.3+ 0.7+ 0.38 + 0.001) + 0/10)";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_mod_mv = 1;
		ace_mv[] = {"B_545x39_Ball",880,"ACE_B_545x39_T",880,"ACE_B_545x39_S",880,"ACE_B_545x39_EP",880,"ACE_B_545x39_EP_S",880,"ACE_B_545x39_AP",880,"ACE_B_545x39_AP_S",880};
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
		discreteDistanceInitIndex = 2;
		modes[] = {"FullAuto","Burst","Single"};
		class Single: Single
		{
			reloadTime = 0.0667;
			recoil = "AEK_971_Recoil";
			recoilProne = "AEK_971_Recoil_prone";
		};
		class Burst: Single
		{
			reloadTime = 0.0667;
			recoil = "AEK_971_Recoil";
			recoilProne = "AEK_971_Recoil_prone";
			burst = 3;
			showtoplayer = 1;
			soundburst = 0;
			displayName = "$STR_DN_MODE_BURST";
		};
		class FullAuto: FullAuto
		{
			reloadTime = 0.0667;
			recoil = "AEK_971_Recoil";
			recoilProne = "AEK_971_Recoil_prone";
		};
		class Library
		{
			libTextDesc = "$STR_LIB_AEK_971";
		};
		class Armory
		{
			author = "yvandrey";
			disabled = 0;
		};
	};
	class ACE_AEK_973s: ACE_AK103
	{
		htMax = 480;
		displayName = "$STR_AEK_973s";
		model = "\x\acex\addons\m_wep_aek\aek-973s";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S";
		ace_size = 12800;
		ace_weight = 3.25;
		dexterity = "(0.5 + 3.75/(3.25 + 0.001) + 0/10)";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x39_Ball",700,"ACE_B_762x39_T",700,"ACE_B_762x39_AP",700};
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
		discreteDistanceInitIndex = 2;
		irdistance = 0;
		modes[] = {"FullAuto","Burst","Single"};
		class Single: Single
		{
			reloadTime = 0.0667;
			recoil = "AEK_973_Recoil";
			recoilProne = "AEK_973_Recoil_prone";
		};
		class Burst: Burst
		{
			reloadTime = 0.0667;
			recoil = "AEK_973_Recoil";
			recoilProne = "AEK_973_Recoil_prone";
			burst = 3;
			showtoplayer = 1;
		};
		class FullAuto: FullAuto
		{
			reloadTime = 0.0667;
			recoil = "AEK_973_Recoil";
			recoilProne = "AEK_973_Recoil_prone";
		};
		class Library
		{
			libTextDesc = "$STR_LIB_AEK_973s";
		};
		class Armory
		{
			author = "yvandrey";
			disabled = 0;
		};
	};
	class ACE_AEK_973s_gp: ACE_AEK_973s
	{
		displayName = "$STR_AEK_973s_gp_34";
		model = "\x\acex\addons\m_wep_aek\aek-973s_gp";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S_GP_34";
		muzzles[] = {"this","ACE_GP34Muzzle","ACE_GP34Muzzle_AI"};
		class ACE_GP34Muzzle: GrenadeLauncher
		{
			displayname = "$STR_DN_ACE_GP34";
			magazines[] = {"1Rnd_HE_GP25","ACE_1Rnd_HE_GP25P","FlareWhite_GP25","FlareGreen_GP25","FlareRed_GP25","FlareYellow_GP25","1Rnd_SMOKE_GP25","1Rnd_SMOKERED_GP25","1Rnd_SMOKEGREEN_GP25","1Rnd_SMOKEYELLOW_GP25","ace_1rnd_cs_gp25","ACE_SSWhite_GP25","ACE_SSGreen_GP25","ACE_SSRed_GP25","ACE_SSYellow_GP25"};
			magazineReloadTime = 0;
			reloadTime = 0.1;
			recoil = "ACE_GL_Recoil";
			optics = 1;
			modelOptics = "-";
			cameraDir = "GL look";
			memoryPointCamera = "GL eye";
			opticsZoomMin = 0.3;
			opticsZoomMax = 0.5;
			opticsZoomInit = 0.5;
			ACE_GRENADE_TYPE = "GP25";
			opticsPPEffects[] = {};
			weaponInfoType = "RscWeaponEmpty";
		};
		class ACE_GP34Muzzle_AI: ACE_GP34Muzzle
		{
			cameraDir = "";
			memoryPointCamera = "";
			showToPlayer = 0;
		};
		ace_gl_fineadj = 29;
		ace_weight = 4.65;
		dexterity = "(0.5 + 3.75/(3.25+ 1.4 + 0.001) + 0/10)";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
	};
	class ACE_AEK_973s_1p63: ACE_AEK_973s
	{
		displayName = "$STR_AEK_973s_1P63";
		model = "\x\acex\addons\m_wep_aek\aek-973s_1p63";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S_1P63";
		ace_weight = 3.85;
		dexterity = "(0.5 + 3.75/(3.25+ 0.6 + 0.001) + 0/10)";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_AEK_973s_gp_1p63: ACE_AEK_973s_gp
	{
		displayName = "$STR_AEK_973s_1P63_GP_34";
		model = "\x\acex\addons\m_wep_aek\aek-973s_gp_1p63";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S_GP_34_1P63";
		ace_weight = 5.25;
		dexterity = "(0.5 + 3.75/(3.25+ 0.6+ 1.4 + 0.001) + 0/10)";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		weaponInfoType = "RscWeaponEmpty";
	};
	class ACE_AEK_973s_1p78: ACE_AEK_973s
	{
		displayName = "$STR_AEK_973s_1P78";
		model = "\x\acex\addons\m_wep_aek\aek-973s_1p78";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S_1P78";
		ace_weight = 3.95;
		dexterity = "(0.5 + 3.75/(3.25+ 0.7 + 0.001) + 0/10)";
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
				discreteDistance[] = {100};
				discreteDistanceInitIndex = 0;
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
	class ACE_AEK_973s_1pn100: ACE_AEK_973s
	{
		displayName = "$STR_AEK_973s_1PN100";
		model = "\x\acex\addons\m_wep_aek\aek-973s_1pn100";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S_1PN100";
		ace_weight = 4.95;
		dexterity = "(0.5 + 3.75/(3.25+ 1.7 + 0.001) + 0/10)";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_1pn100";
		class OpticsModes
		{
			class 1pn100
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				memoryPointCamera = "opticview";
				visionMode[] = {"Normal","NVG"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsZoomMin = 0.069252;
				opticsZoomMax = 0.069252;
				opticsZoomInit = 0.069252;
				distanceZoomMin = 400;
				distanceZoomMax = 400;
				discreteDistance[] = {};
				discreteDistanceInitIndex = 0;
				cameraDir = "";
			};
			class Ironsights: 1pn100
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
				discreteDistance[] = {100};
				discreteDistanceInitIndex = 0;
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
	class ACE_AEK_973s_shahin: ACE_AEK_973s
	{
		displayName = "$STR_aek_973s_shahin";
		model = "\x\acex\addons\m_wep_aek\aek-973s_shahin";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S_SHAHIN";
		ace_weight = 4.85;
		dexterity = "(0.5 + 3.75/(3.25+ 1.6 + 0.001) + 0/10)";
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
				discreteDistanceInitIndex = 2;
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
	class ACE_AEK_973s_tgp_cln: ACE_AKMS_SD
	{
		htMax = 480;
		displayName = "$STR_AEK_973s_tgp_cln";
		model = "\x\acex\addons\m_wep_aek\aek-973s_tgp_cln";
		picture = "\x\acex\addons\c_wep_aek\i\AEK_973S_TGPA_CLN1K";
		descriptionShort = "$STR_DSS_ACE_GROZA_762_SD";
		ace_size = 12800;
		ace_weight = 4.33;
		dexterity = "(0.5 + 3.75/(3.25+ 0.7+ 0.38 + 0.001) + 0/10)";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\AK.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_mod_mv = 1;
		ace_mv[] = {"B_762x39_Ball",700,"ACE_B_762x39_T",700,"ACE_B_762x39_AP",700,"ACE_B_762x39_S",700,"ACE_B_762x39_AP_S",700};
		magazines[] = {"30Rnd_762x39_AK47","ACE_30Rnd_762x39_S_AK47","ACE_30Rnd_762x39_T_AK47","ACE_40Rnd_762x39_B_AK47","ACE_40Rnd_762x39_S_AK47","ACE_40Rnd_762x39_T_AK47","ACE_75Rnd_762x39_B_AK47","ACE_75Rnd_762x39_S_AK47","ACE_30Rnd_762x39_AP_AK47","ACE_30Rnd_762x39_AP_S_AK47","ACE_40Rnd_762x39_AP_AK47","ACE_40Rnd_762x39_AP_S_AK47","ACE_30Rnd_762x39_SD_AK47","ACE_75Rnd_762x39_SD_AK47"};
		weaponInfoType = "RscWeaponZeroing";
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
		discreteDistanceInitIndex = 0;
		modes[] = {"FullAuto","Burst","Single"};
		class Single: Single
		{
			reloadTime = 0.0667;
			recoil = "AEK_973_Recoil";
			recoilProne = "AEK_973_Recoil_prone";
		};
		class Burst: Single
		{
			reloadTime = 0.0667;
			recoil = "AEK_973_Recoil";
			recoilProne = "AEK_973_Recoil_prone";
			burst = 3;
			showtoplayer = 1;
			soundburst = 0;
			displayName = "$STR_DN_MODE_BURST";
		};
		class FullAuto: FullAuto
		{
			reloadTime = 0.0667;
			recoil = "AEK_973_Recoil";
			recoilProne = "AEK_973_Recoil_prone";
		};
		class Library
		{
			libTextDesc = "$STR_LIB_AEK_973s";
		};
		class Armory
		{
			author = "yvandrey";
			disabled = 0;
		};
	};
};
//};
