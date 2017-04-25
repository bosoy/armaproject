////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 02 21:00:07 2012 : Created on Fri Nov 02 21:00:07 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_rifle : config.bin{
class CfgPatches
{
	class acex_wep_rifle
	{
		units[] = {};
		weapons[] = {"ACE_SKS","ACE_G3A3","ACE_G3SG1","ACE_G3A3_RSAS"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons_AK","CAWeapons2","acex_main","ace_c_weapon"};
		version = "1.14.0.369";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_rifle
		{
			list[] = {"acex_wep_rifle"};
		};
	};
};
class cfgMagazines
{
	class 20Rnd_556x45_Stanag;
	class 30Rnd_762x39_AK47;
	class ACE_10Rnd_762x39_B_SKS: 30Rnd_762x39_AK47
	{
		model = "\x\acex\addons\m_wep_rifle\bwc_SKS_mag.p3d";
		picture = "\x\acex\addons\c_wep_rifle\i\m_SKS_ca.paa";
	};
	class ACE_20Rnd_762x51_B_G3: 20Rnd_556x45_Stanag
	{
		model = "\x\acex\addons\m_wep_rifle\ace_g3_mag.p3d";
		picture = "\x\acex\addons\c_wep_rifle\i\m_g3_ca.paa";
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class cfgWeapons
{
	class Rifle;
	class M16_BASE;
	class AK_BASE;
	class M16A2: M16_BASE
	{
		class Single;
		class FullAuto;
	};
	class AK_47_M: AK_BASE
	{
		class Single;
	};
	class ACE_SKS: AK_47_M
	{
		ACE_sys_weapons_Side[] = {"INS","GUE"};
		displayName = "$STR_WN_ACE_SKS";
		scope = 2;
		model = "\x\acex\addons\m_wep_rifle\bwc_SKS.p3d";
		picture = "\x\acex\addons\c_wep_rifle\i\w_SKS_ca.paa";
		modes[] = {"Single"};
		magazines[] = {"ACE_10Rnd_762x39_B_SKS","ACE_10Rnd_762x39_T_SKS"};
		reloadSound[] = {"x\acex\addons\s_wep_rifle\sks_bolt.wss",0.0316228,1,20};
		reloadMagazineSound[] = {"x\acex\addons\s_wep_rifle\ak_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			dispersion = 0.0016;
			begin1[] = {"x\acex\addons\s_wep_rifle\sks_fire.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",1};
			aiRateOfFire = 2;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.5;
			maxRange = 500;
			maxRangeProbab = 0.1;
		};
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M24.rtm"};
		ace_weight = 3.9;
		dexterity = "(0.5 + 3.75/(3.9 + 0.001) + 0/10)";
		ACE_Size = 4590;
		descriptionShort = "$STR_DSS_ACE_SKS";
		class Library
		{
			libTextDesc = "";
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
	};
	class ACE_G3A3: M16A2
	{
		ACE_sys_weapons_Side[] = {"BIS_GER","BIS_TK","INS","GUE"};
		scope = 2;
		displayName = "$STR_WN_ACE_HK_G3A3";
		model = "\x\acex\addons\m_wep_rifle\g3.p3d";
		picture = "\x\acex\addons\c_wep_rifle\i\w_g3_ca.paa";
		magazines[] = {"ACE_20Rnd_762x51_B_G3","ACE_20Rnd_762x51_T_G3"};
		reloadMagazineSound[] = {"x\acex\addons\s_wep_rifle\fal_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			reloadTime = 0.09;
			recoil = "ACE_762x51_FAL_Recoil";
			recoilProne = "ACE_762x51_SCAR_RecoilProne";
			dispersion = 0.0017;
			begin1[] = {"x\acex\addons\s_wep_rifle\fal_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex\addons\s_wep_rifle\fal_fire2.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
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
			recoil = "ACE_762x51_FAL_Recoil";
			recoilProne = "ACE_762x51_SCAR_RecoilProne";
			dispersion = 0.0017;
			reloadTime = 0.09;
			begin1[] = {"x\acex\addons\s_wep_rifle\fal_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex\addons\s_wep_rifle\fal_fire2.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
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
		modes[] = {"Single","ACE_Burst_AI","ACE_Burst_AI2","FullAuto"};
		weaponInfoType = "RscWeaponZeroing";
		distancezoomMin = 300;
		distancezoomMax = 300;
		discreteDistance[] = {100,200,300,400};
		discreteDistanceInitIndex = 2;
		class Library
		{
			libTextDesc = "$STR_DS_ACE_HK_G3";
		};
		ace_weight = 4.4;
		dexterity = "(0.5 + 3.75/(4.4 + 0.001) + 0/10)";
		ACE_Size = 8720;
		descriptionShort = "$STR_DSS_ACE_G3";
		handAnim[] = {"OFP2_ManSkeleton","x\acex\addons\c_wep_rifle\anim\aus_hk_g3.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	class ACE_G3A3_RSAS: ACE_G3A3
	{
		ACE_sys_weapons_Side[] = {"USMC","BIS_GER","BIS_US"};
		displayName = "HK G3A3 RSA-S";
		model = "\x\acex\addons\m_wep_rifle\g3rsas.p3d";
		picture = "\x\acex\addons\c_wep_rifle\i\w_g3rsas_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","x\acex\addons\c_wep_rifle\anim\g3rsas5.rtm"};
		class Single: Single
		{
			recoil = "ACE_762x51_G3_Grip_Recoil";
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_762x51_G3_Grip_Recoil";
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		weaponInfoType = "RscWeaponEmpty";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		ace_weight = 4.7999997;
		dexterity = "(0.5 + 3.75/(4.4+ 0.1+ 0.2+ 0.1 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_G3A3_RSAS","ACE_G3A3_RSAS_F"};
	};
	class ACE_G3A3_RSAS_F: ACE_G3A3_RSAS
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "flash dir";
			direction = "flash";
			angle = 30;
			scale[] = {1,1,0.5};
			brightness = 0.1;
		};
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_G3SG1: ACE_G3A3
	{
		displayName = "$STR_WN_ACE_HK_G3SG1";
		model = "\x\acex\addons\m_wep_rifle\g3sg1.p3d";
		picture = "\x\acex\addons\c_wep_rifle\i\w_g3sg1_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_ZF24.p3d";
		opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
		opticsFlare = 1;
		opticsDisablePeripherialVision = 1;
		opticsZoomMin = 0.05;
		opticsZoomMax = 0.2;
		opticsZoomInit = 0.2;
		distanceZoomMin = 360;
		distanceZoomMax = 360;
		class Single: Single
		{
			dispersion = 0.001;
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
			dispersion = 0.0012;
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
		class Library
		{
			libTextDesc = "$STR_DS_ACE_HK_G3";
		};
		weaponInfoType = "RscWeaponEmpty";
		discreteDistance[] = {};
		discreteDistanceInitIndex = 0;
		ace_weight = 5.54;
		dexterity = "(0.5 + 3.75/(5.54 + 0.001) + 0/10)";
		ACE_Size = 8720;
		descriptionShort = "$STR_DSS_ACE_G3";
		handAnim[] = {"OFP2_ManSkeleton","x\acex\addons\c_wep_rifle\anim\aus_hk_g3.rtm"};
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "range";
		ace_sa_defaultrange = 300;
		ace_sa_defaultelevation = 2.7;
		ace_sa_zerooffset = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 600;
		ace_sa_windage = 10;
		ace_sa_stepwindage = 1;
		ace_sa_elev_unit = "mil";
		ace_sa_wind_unit = "mil";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 0;
		ace_sa_table_elev[] = {{0,0},{100,0.8},{200,1.7},{300,2.7},{400,3.9},{500,5.3},{600,6.8}};
		ace_drift[] = {{0,0},{100,0.002},{200,0.04},{300,0.113},{400,0.264},{500,0.495},{600,0.815}};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	class M14_EP1: Rifle
	{
		author[] = {"WinteR5"};
		class Single;
		model = "\x\acex\addons\m_wep_rifle\ACE_M14_Aimpoint.p3d";
		picture = "\x\acex\addons\c_wep_rifle\data\wr5_m14_aimpoint_ca.paa";
		class OpticsModes
		{
			class Optics
			{
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				memorypointcamera = "scope";
				opticsdisableperipherialvision = 0;
				opticsflare = 0;
				opticsid = 0;
				opticsppeffects[] = {};
				opticszoominit = 0.5;
				opticszoommax = 1.1;
				opticszoommin = 0.25;
				usemodeloptics = 0;
				visionmode[] = {};
			};
			class Ironsights: Optics
			{
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memorypointcamera = "eye";
				opticsid = 1;
			};
		};
	};
	class ACE_M14_ACOG: M14_EP1
	{
		author[] = {"WinteR5"};
		displayName = "$STR_ACE_WDN_M14_ACOG";
		model = "\x\acex\addons\m_wep_rifle\ACE_M14_ACOG.p3d";
		picture = "\x\acex\addons\c_wep_rifle\data\wr5_m14_acog_ca.paa";
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
			class Kolimator: ACOG
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
		ace_weight = 5.36;
		dexterity = "(0.5 + 3.75/(4.9+ 0.46 + 0.001) + 0/10)";
	};
};
//};
