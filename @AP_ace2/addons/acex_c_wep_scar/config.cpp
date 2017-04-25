////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed May 23 21:40:39 2012 : Created on Wed May 23 21:40:39 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_scar : config.bin{
class CfgPatches
{
	class acex_wep_scar
	{
		units[] = {};
		weapons[] = {"ACE_SCAR_H_STD_Spect"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons_E","CAWeapons_E_scar","acex_main","acex_m_wep_scar","acex_t_wep_scar","ace_c_weapon"};
		version = "1.13.0.363";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_scar
		{
			list[] = {"acex_wep_scar"};
		};
	};
};
class CfgWeapons
{
	class SCAR_H_CQC_CCO;
	class SCAR_H_STD_EGLM_Spect: SCAR_H_CQC_CCO
	{
		model = "\x\acex\addons\m_wep_scar\mk17_short_spectre_eglm_laser.p3d";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ace_weight = 5.54;
		dexterity = "(0.5 + 3.75/(3.6+ 0.64+ 1.3 + 0.001) + 0/10)";
		class OpticsModes
		{
			class Specter
			{
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
			};
			class Ironsights: Specter
			{
				opticsID = 2;
				memoryPointCamera = "eye2";
				distanceZoomMin = 100;
				distanceZoomMax = 100;
			};
			class BUIS: Ironsights
			{
				opticsID = 3;
				memoryPointCamera = "eye";
				distanceZoomMin = 300;
				distanceZoomMax = 300;
			};
		};
		class SCAR_H_Single;
		class SCAR_H_FullAuto;
	};
	class ACE_SCAR_H_STD_Spect: SCAR_H_STD_EGLM_Spect
	{
		model = "\x\acex\addons\m_wep_scar\mk17_short_spectre_laser.p3d";
		picture = "\x\acex\addons\c_wep_scar\i\w_ace_mk17_rco_ca.paa";
		ace_weight = 4.5399995;
		dexterity = "(0.5 + 3.75/(3.6+ 0.64+ 0.1+ 0.2 + 0.001) + 1/10)";
		displayName = "Mk17 RCO";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons_E\SCAR\Data\Anim\SCAR.rtm"};
		muzzles[] = {"this"};
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_G3";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		class SCAR_H_Single: SCAR_H_Single
		{
			recoil = "ACE_762x51_G3_Grip_Recoil";
		};
		class SCAR_H_FullAuto: SCAR_H_FullAuto
		{
			recoil = "ACE_762x51_G3_Grip_Recoil";
		};
		class ACE_Burst: SCAR_H_Single
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
		modes[] = {"SCAR_H_Single","SCAR_H_FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
	};
};
//};
