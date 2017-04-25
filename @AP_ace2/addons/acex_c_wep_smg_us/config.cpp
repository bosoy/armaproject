////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Apr 27 16:07:23 2012 : Created on Fri Apr 27 16:07:23 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_smg_us : config.bin{
class CfgPatches
{
	class acex_wep_smg_us
	{
		units[] = {};
		weapons[] = {"ACE_MP5SD","ACE_MP5A5","ACE_MP5A4","ACE_UMP45","ACE_UMP45_SD","ACE_M3A1","ACE_KAC_PDW","ACE_MP7","ACE_MP7_RSAS"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAweapons"};
		version = "1.13.0.361";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_smg_us
		{
			list[] = {"acex_wep_smg_us"};
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class cfgRecoils
{
	ACE_MP7_RECOIL[] = {0,0.003,0,0,0.003,0.005,0.01,0.001,0.005,0.07,0,0};
	ACE_UMP45_Recoil[] = {0,0.005,-0.002,0.01,0.005,0.007,0.03,0.003,0.007,0.08,0,0};
	ACE_KACPDW_Recoil[] = {0,0.005,0.005,0.01,0.005,0.005,0.02,0.0035,0.007,0.1,0,0};
};
class CfgWeapons
{
	class Rifle;
	class MP5SD: Rifle
	{
		model = "\x\acex\addons\m_wep_smg_us\ACE_MP5SD6.p3d";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_mp5sd6_ca.paa";
	};
	class MP5A5: MP5SD
	{
		model = "\x\acex\addons\m_wep_smg_us\ACE_MP5A5.p3d";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_mp5a5_ca.paa";
	};
	class ACE_MP5SD: MP5SD
	{
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_MP5A5: MP5A5
	{
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_MP5A4: MP5A5
	{
		displayName = "MP5A4";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_mp5a4_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\ACE_MP5A4.p3d";
		ace_weight = 2.725;
		dexterity = "(0.5 + 3.75/(2.725 + 0.001) + 0/10)";
		ACE_Size = "67.5*23*6.7";
		class Library
		{
			libTextDesc = "";
		};
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
	};
	class ACE_UMP45: Rifle
	{
		ACE_SYS_WEAPONS_SIDE[] = {"USMC","BIS_GER","BIS_US"};
		scope = 2;
		displayName = "UMP45";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_ump45_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\ACE_UMP45";
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_smg_us\ump_reload.wss",0.0562341,1,20};
		magazines[] = {"ACE_25Rnd_1143x23_B_UMP45","ACE_25Rnd_1143x23_S_UMP45"};
		modes[] = {"Single","Burst","FullAuto"};
		class Single: Mode_SemiAuto
		{
			reloadTime = 0.1;
			recoil = "ACE_UMP45_Recoil";
			recoilProne = "ACE_UMP45_Recoil";
			dispersion = 0.003;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\ump_fire1.wss",2.77828,1,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\ump_fire2.wss",2.77828,1,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\ump_fire3.wss",2.77828,1,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 75;
			midRangeProbab = 0.5;
			maxRange = 150;
			maxRangeProbab = 0.05;
		};
		class Burst: Mode_Burst
		{
			reloadTime = 0.1;
			burst = 2;
			ffCount = 2;
			recoil = "ACE_UMP45_Recoil";
			recoilProne = "ACE_UMP45_Recoil";
			dispersion = 0.003;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\ump_fire1.wss",2.77828,1,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\ump_fire2.wss",2.77828,1,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\ump_fire3.wss",2.77828,1,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 1;
			aiRateOfFireDistance = 100;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime = 0.1;
			ffCount = 25;
			recoil = "ACE_UMP45_Recoil";
			recoilProne = "ACE_UMP45_Recoil";
			dispersion = 0.003;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\ump_fire1.wss",2.77828,1,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\ump_fire2.wss",2.77828,1,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\ump_fire3.wss",2.77828,1,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 40;
			maxRangeProbab = 0.1;
		};
		ace_weight = 2.26;
		dexterity = "(0.5 + 3.75/(2.26 + 0.001) + 0/10)";
		ACE_Size = "45*32.6*6.35";
		descriptionShort = "$STR_DSS_ACE_UMP45";
		class Library
		{
			libTextDesc = "";
		};
		handanim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\HKMP5.rtm"};
		distanceZoomMin = 50;
		distanceZoomMax = 50;
	};
	class ACE_UMP45_SD: ACE_UMP45
	{
		displayname = "UMP45 SD";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_ump45sd_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\ACE_UMP45_SD";
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		descriptionShort = "$STR_DSS_ACE_UMP45_SD";
		ace_weight = 2.6399999;
		dexterity = "(0.5 + 3.75/(2.26+ 0.38 + 0.001) + 0/10)";
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,1,40};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,0.97,40};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,1.025,40};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Burst
		{
			begin1[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,1,40};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,0.97,40};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,1.025,40};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,1,40};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,0.97,40};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\umpsd_fire.wss",0.01,1.025,40};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class ACE_UMP45_AIM: ACE_UMP45
	{
		displayName = "UMP-45 CCO";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_ump45_cco_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\ACE_UMP45_AIM";
		ace_weight = 2.61;
		dexterity = "(0.5 + 3.75/(2.26+ 0.35 + 0.001) + 0/10)";
	};
	class ACE_UMP45_AIM_SD: ACE_UMP45_SD
	{
		displayname = "UMP45 CCO SD";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_ump45sd_cco_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\ACE_UMP45_AIM_SD";
		ace_weight = 2.9899998;
		dexterity = "(0.5 + 3.75/(2.26+ 0.35+ 0.38 + 0.001) + 0/10)";
	};
	class ACE_M3A1: ACE_UMP45
	{
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_smg_us\m3_reload.wss",0.0562341,1,20};
		ACE_SYS_WEAPONS_SIDE[] = {"INS","GUE"};
		displayName = "M3A1";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_m3_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\M3A1";
		magazines[] = {"ACE_30Rnd_1143x23_B_M3"};
		modes[] = {"FullAuto","Burst"};
		class FullAuto: Mode_FullAuto
		{
			reloadTime = 0.133;
			ffCount = 30;
			recoil = "ACE_UMP45_Recoil";
			recoilProne = "ACE_UMP45_Recoil";
			dispersion = 0.0035;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\m3_fire1.wss",2.77828,1.01,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\m3_fire2.wss",2.77828,1.015,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\m3_fire3.wss",2.77828,1.02,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 10;
			midRangeProbab = 0.7;
			maxRange = 40;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			showtoplayer = 0;
			reloadTime = 0.133;
			burst = 3;
			ffCount = 2;
			recoil = "ACE_UMP45_Recoil";
			recoilProne = "ACE_UMP45_Recoil";
			dispersion = 0.0035;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\m3_fire1.wss",2.77828,1.01,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\m3_fire2.wss",2.77828,1.015,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\m3_fire3.wss",2.77828,1.02,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 1;
			aiRateOfFireDistance = 100;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 50;
			midRangeProbab = 0.7;
			maxRange = 100;
			maxRangeProbab = 0.1;
		};
		ace_weight = 3.5;
		dexterity = "(0.5 + 3.75/(3.5 + 0.001) + 0/10)";
		ACE_Size = 8840;
		handAnim[] = {"OFP2_ManSkeleton","x\acex\addons\c_wep_smg_us\Anim\M3.rtm"};
		descriptionShort = "$STR_DSS_ACE_UMP45";
		class Library
		{
			libTextDesc = "";
		};
	};
	class ACE_KAC_PDW: Rifle
	{
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_smg_us\ump_reload.wss",0.0562341,1,20};
		ACE_SYS_WEAPONS_SIDE[] = {"USMC","BIS_US","BIS_BAF"};
		scope = 2;
		displayName = "KAC PDW";
		distanceZoomMin = 100;
		distanceZoomMax = 100;
		picture = "\x\acex\addons\c_wep_smg_us\i\w_pdw_iron_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\RH_PDW";
		magazines[] = {"ACE_30Rnd_6x35_B_PDW"};
		modes[] = {"Single","Burst","FullAuto"};
		class Single: Mode_SemiAuto
		{
			reloadTime = 0.0856;
			recoil = "ACE_KACPDW_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire1.wss",1.77828,1,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire2.wss",1.77828,1,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire3.wss",1.77828,0.96,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class Burst: Mode_Burst
		{
			showtoplayer = 0;
			reloadTime = 0.0856;
			recoil = "ACE_KACPDW_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			ffcount = 3;
			dispersion = 0.0025;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire1.wss",1.77828,1,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire2.wss",1.77828,1,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire3.wss",1.77828,0.96,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 100;
			midRangeProbab = 0.7;
			maxRange = 200;
			maxRangeProbab = 0.1;
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime = 0.0856;
			recoil = "ACE_KACPDW_Recoil";
			recoilProne = "ACE_556x45_Rifle_RecoilProne";
			dispersion = 0.0025;
			ffcount = 30;
			soundBurst = 0;
			begin1[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire1.wss",1.77828,1,750};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire2.wss",1.77828,1,750};
			begin3[] = {"\x\acex\addons\s_wep_smg_us\pdw_fire3.wss",1.77828,0.96,750};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		ace_weight = 1.9;
		dexterity = "(0.5 + 3.75/(1.8+ 0.1 + 0.001) + 1/10)";
		ACE_Size = 8840;
		handAnim[] = {"OFP2_ManSkeleton","x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		descriptionShort = "$STR_DSS_ACE_KAC_PDW";
		class Library
		{
			libTextDesc = "";
		};
	};
	class ACE_MP7: ACE_UMP45
	{
		displayName = "MP7";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_mp7_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\RH_MP7";
		handAnim[] = {"OFP2_ManSkeleton","x\acex\addons\c_wep_smg_us\Anim\MP7.rtm"};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_smg_us\mp7_reload.wss",0.056234,1,25};
		magazines[] = {"ACE_40Rnd_B_46x30_MP7","ACE_40Rnd_S_46x30_MP7"};
		modes[] = {"Single","FullAuto"};
		class Single: Single
		{
			recoil = "ACE_MP7_RECOIL";
			recoilProne = "ACE_MP7_RECOIL";
			begin1[] = {"\x\acex\addons\s_wep_smg_us\mp7_fire1.wss",1.778279,1,900};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\mp7_fire1.wss",1.767168,1,899};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.063;
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_MP7_RECOIL";
			recoilProne = "ACE_MP7_RECOIL";
			begin1[] = {"\x\acex\addons\s_wep_smg_us\mp7_fire1.wss",1.778279,1,899};
			begin2[] = {"\x\acex\addons\s_wep_smg_us\mp7_fire1.wss",1.767168,1,900};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			reloadTime = 0.063;
		};
		ACE_SYS_WEAPONS_SIDE[] = {"BIS_GER"};
		descriptionShort = "$STR_DSS_ACE_MP7";
		class Library
		{
			libTextDesc = "";
		};
		ace_weight = 1.9;
		dexterity = "(0.5 + 3.75/(1.9 + 0.001) + 1/10)";
		ACE_Size = "41.5*16.95*5.1";
	};
	class ACE_MP7_RSAS: ACE_MP7
	{
		displayName = "MP7 RSAS";
		picture = "\x\acex\addons\c_wep_smg_us\i\w_mp7_rsas_ca.paa";
		model = "\x\acex\addons\m_wep_smg_us\RH_MP7_RSAS";
		ace_weight = 2.0;
		dexterity = "(0.5 + 3.75/(1.9+ 0.1 + 0.001) + 1/10)";
	};
};
class CfgMagazines
{
	class 30Rnd_9x19_MP5;
	class ACE_40Rnd_B_46x30_MP7: 30Rnd_9x19_MP5
	{
		model = "\x\acex\addons\m_wep_smg_us\RH_MP7_mag";
		picture = "\x\acex\addons\c_wep_smg_us\i\m_mp7_ca.paa";
	};
};
//};
