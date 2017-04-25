////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Apr 20 13:05:48 2012 : Created on Fri Apr 20 13:05:48 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_mg : config.bin{
class CfgPatches
{
	class acex_wep_mg
	{
		units[] = {};
		weapons[] = {"ACE_M60","ACE_M249_AIM","ACE_M249_PIP_ACOG","ACE_M240B","ACE_M240L","ACE_M240L_M145"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons_E","CAWeapons_E_M240","acex_m_wep_mg","acex_t_wep_mg"};
		version = "1.13.0.360";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_mg
		{
			list[] = {"acex_wep_mg"};
		};
	};
};
class CfgWeapons
{
	class RifleCore;
	class Rifle: RifleCore
	{
		class ACE;
	};
	class M240: Rifle
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED;
		};
	};
	class m240_scoped_EP1: M240
	{
		model = "\x\acex\addons\m_wep_mg\ACE_M240_M145";
		class OpticsModes
		{
			class M145;
			class Ironsights: M145
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "eye";
				visionMode[] = {};
			};
		};
	};
	class ACE_M240B: M240
	{
		scope = 2;
		displayName = "M240B";
		model = "\x\acex\addons\m_wep_mg\ACE_M240b";
		ace_weight = 11.8;
		dexterity = "(0.5 + 3.75/(11.6+ 0.2 + 0.001) + -3/10)";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_M240B_Tripod";
				canUseTripods[] = {"ACE_M122Tripod"};
			};
		};
	};
	class ACE_M240L: ACE_M240B
	{
		displayName = "M240L";
		model = "\x\acex\addons\m_wep_mg\ACE_M240l";
		ace_weight = 10.3;
		dexterity = "(0.5 + 3.75/(10.1+ 0.2 + 0.001) + -3/10)";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_M240L_Tripod";
				canUseTripods[] = {"ACE_M122Tripod"};
			};
		};
	};
	class ACE_M240L_M145: m240_scoped_EP1
	{
		displayName = "M240L M145";
		model = "\x\acex\addons\m_wep_mg\ACE_M240L_M145";
		ace_weight = 10.79;
		dexterity = "(0.5 + 3.75/(10.1+ 0.69 + 0.001) + -3/10)";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_M240L_M145_Tripod";
				canUseTripods[] = {"ACE_M122Tripod"};
			};
		};
	};
	class M249;
	class M249_EP1;
	class ACE_M249_AIM: M249_EP1
	{
		displayName = "M249 CCO";
		picture = "\x\acex\addons\c_wep_mg\i\w_m249para_cco_ca.paa";
		model = "\x\acex\addons\m_wep_mg\ACE_M249_para_aim.p3d";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons_E\SCAR\Data\Anim\SCAR.rtm"};
		weaponInfoType = "RscWeaponEmpty";
		ace_weight = 7.7639995;
		dexterity = "(0.5 + 3.75/(7.2+ 0.2+ 0.264+ 0.1 + 0.001) + 1/10)";
	};
	class M249_m145_EP1: M249
	{
		model = "\x\acex\addons\m_wep_mg\ACE_M249_para_m145.p3d";
		class manual;
	};
	class ACE_M249_PIP_ACOG: M249_m145_EP1
	{
		displayName = "M249 PIP RCO";
		model = "\x\acex\addons\m_wep_mg\ACE_M249_PIP_ACOG.p3d";
		picture = "\x\acex\addons\c_wep_mg\i\w_m249para_pip_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31ecos";
		class OpticsModes
		{
			class Acog
			{
				opticsID = 1;
				distanceZoomMin = 308;
				distanceZoomMax = 308;
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
			class CQB: Acog
			{
				opticsID = 2;
				distanceZoomMin = 50;
				distanceZoomMax = 50;
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
		class manual: manual
		{
			recoil = "ACE_M249_PIP_Recoil";
		};
		ace_weight = 7.9599996;
		dexterity = "(0.5 + 3.75/(7.2+ 0.2+ 0.46+ 0.1 + 0.001) + 1/10)";
	};
	class M60A4_EP1;
	class ACE_M60: M60A4_EP1
	{
		ACE_sys_weapons_Side[] = {0,4,7};
		ace_weight = 10.5;
		dexterity = "(0.5 + 3.75/(10.5 + 0.001) + -3/10)";
		ACE_Size = 19773.72;
		displayName = "M60";
		model = "\x\acex\addons\m_wep_mg\ACE_M60";
		picture = "\x\acex\addons\c_wep_mg\i\w_m60_ca.paa";
		class Library
		{
			libTextDesc = "";
		};
	};
	class PK: Rifle
	{
		model = "\x\acex\addons\m_wep_mg\ACE_PK";
	};
};
//};
