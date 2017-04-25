////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri May 11 20:55:10 2012 : Created on Fri May 11 20:55:10 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_pistol : config.bin{
class CfgPatches
{
	class acex_wep_pistol
	{
		units[] = {};
		weapons[] = {"ACE_Glock18","ACE_TT","ACE_Flaregun","ACE_APS","ACE_APSB","ACE_P226","ACE_USP","ACE_USPSD","ACE_P8"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons_E","acex_m_wep_pistol","acex_t_wep_pistol","acex_s_wep_pistol"};
		version = "1.13.0.362";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_pistol
		{
			list[] = {"acex_wep_pistol"};
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class 15Rnd_9x19_M9;
	class 7Rnd_45ACP_1911;
	class 8Rnd_9x18_MakarovSD;
	class 17Rnd_9x19_glock17: CA_Magazine
	{
		model = "\x\acex\addons\m_wep_pistol\glock18_mag.p3d";
	};
	class ACE_15Rnd_9x19_P226: 15Rnd_9x19_M9
	{
		displayName = "$STR_MN_ACE_15RND_9X19_P226";
		model = "\x\acex\addons\m_wep_pistol\usp_mag.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\m_usp_ca.paa";
		descriptionShort = "$STR_DSS_ACE_15RND_9X19_P226";
		initSpeed = 365;
	};
	class ACE_12Rnd_45ACP_USP: 7Rnd_45ACP_1911
	{
		displayName = "$STR_MN_ACE_12RND_45ACP_USP";
		count = 12;
		model = "\x\acex\addons\m_wep_pistol\usp_mag.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\m_usp_ca.paa";
		descriptionShort = "$STR_DSS_ACE_12RND_45ACP_USP";
		ace_suppmag = "ACE_12Rnd_45ACP_USPSD";
	};
	class ACE_12Rnd_45ACP_USPSD: ACE_12Rnd_45ACP_USP
	{
		ace_suppressed = 1;
		class Armory
		{
			disabled = 1;
		};
		ammo = "ACE_B_1143x23_S";
	};
	class ACE_15Rnd_9x19_P8: 15Rnd_9x19_M9
	{
		displayName = "$STR_MN_ACE_15RND_9X19_P8";
		model = "\x\acex\addons\m_wep_pistol\usp_mag.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\m_usp_ca.paa";
		descriptionShort = "$STR_DSS_ACE_15RND_9X19_P8";
		initSpeed = 365;
	};
	class ACE_8Rnd_762x25_B_Tokarev: 8Rnd_9x18_MakarovSD
	{
		displayName = "$STR_MN_ACE_8RND_762X25_B_TOKAREV";
		displayNameShort = "";
		scope = 2;
		ammo = "ACE_Bullet_762x25_B";
		picture = "\x\acex\addons\c_wep_pistol\i\m_tt33_ca.paa";
		model = "\x\acex\addons\m_wep_pistol\tt_33_mag.p3d";
		initSpeed = 420;
		descriptionShort = "$STR_DSS_ACE_8RND_762X25_B_TOKAREV";
		ace_size = 80;
	};
	class 8Rnd_9x18_Makarov;
	class ACE_20Rnd_9x18_APS: 8Rnd_9x18_Makarov
	{
		scope = 2;
		displayName = "$STR_MN_ACE_20Rnd_9x18_APS";
		initSpeed = 340;
		count = 20;
		picture = "\CA\weapons\data\equip\m_makarov_ca.paa";
		model = "\x\acex\addons\m_wep_pistol\apb_mag.p3d";
		descriptionShort = "$STR_DSS_ACE_20RND_9X18_APS";
		ace_weight = 0.22;
	};
	class ACE_20Rnd_9x18_APSB: ACE_20Rnd_9x18_APS
	{
		displayName = "$STR_MN_ACE_20Rnd_9x18_APSB";
		ammo = "B_9x18_SD";
		descriptionShort = "$STR_DSS_ACE_20RND_9X18_APSB";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Makarov;
	class M9;
	class glock17_EP1;
	class Colt1911: M9
	{
		model = "\x\acex\addons\m_wep_pistol\ACE_M1911.p3d";
	};
	class ACE_Glock18: glock17_EP1
	{
		displayName = "Glock 18";
		model = "\x\acex\addons\m_wep_pistol\RH_glock18.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\w_glock18_ca.paa";
		magazines[] = {"ACE_33Rnd_9x19_G18","17Rnd_9x19_glock17"};
		modes[] = {"Single","FullAuto"};
		class Single: Mode_SemiAuto
		{
			soundContinuous = 0;
			dispersion = 0.004;
			reloadTime = 0.05;
			recoil = "ACE_9x19_PistolRecoil";
			recoilProne = "ACE_9x19_PistolRecoil";
			ffCount = 1;
			ffMagnitude = 0.5;
			ffFrequency = 11;
			flash = "gunfire";
			flashSize = 0.1;
			showToPlayer = 1;
			aiRateOfFire = 0.6;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.5;
			midRange = 20;
			midRangeProbab = 0.3;
			maxRange = 80;
			maxRangeProbab = 0.01;
			begin1[] = {"\x\acex\addons\s_wep_pistol\glock_fire1.wss",0.794328,1,700};
			begin2[] = {"\x\acex\addons\s_wep_pistol\glock_fire2.wss",0.794328,1,700};
			begin3[] = {"\x\acex\addons\s_wep_pistol\glock_fire3.wss",0.794328,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			soundContinuous = 0;
			multiplier = 1;
			burst = 1;
			dispersion = 0.004;
			reloadTime = 0.05;
			recoil = "ACE_Glock_Auto_Recoil";
			recoilProne = "ACE_Glock_Auto_Recoil";
			ffCount = 3;
			ffMagnitude = 0.5;
			ffFrequency = 11;
			autofire = 2;
			flash = "gunfire";
			flashSize = 0.1;
			useAction = 0;
			useActionTitle = "";
			showToPlayer = 1;
			aiRateOfFire = 0.4;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.6;
			midRange = 10;
			midRangeProbab = 0.4;
			maxRange = 20;
			maxRangeProbab = 0.05;
			begin1[] = {"\x\acex\addons\s_wep_pistol\glock_fire1.wss",0.794328,1,700};
			begin2[] = {"\x\acex\addons\s_wep_pistol\glock_fire2.wss",0.794328,1,700};
			begin3[] = {"\x\acex\addons\s_wep_pistol\glock_fire3.wss",0.794328,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		ace_weight = 0.624;
		dexterity = "(1 + 0.75/(0.624 + 0.001))";
		ACE_Size = 867.7;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_GLOCK18";
		class Flashlight{};
	};
	class ACE_USP: M9
	{
		displayName = "USP Tactical";
		model = "\x\acex\addons\m_wep_pistol\RH_usp.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\w_usp_ca.paa";
		recoil = "ACE_45ACP_PistolRecoil";
		drySound[] = {"\ca\Weapons\Data\Sound\T33_dry_v1",0.01,1,20};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_pistol\m9_reload.wss",0.1,1,20};
		magazines[] = {"ACE_12Rnd_45ACP_USP","ACE_12Rnd_45ACP_USPSD"};
		begin1[] = {"\x\acex\addons\s_wep_pistol\m1911_fire1.wss",0.794328,1,700};
		begin2[] = {"\x\acex\addons\s_wep_pistol\m1911_fire2.wss",0.794328,1,700};
		begin3[] = {"\x\acex\addons\s_wep_pistol\m1911_fire3.wss",0.794328,1,700};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_USP";
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "flash dir";
			direction = "flash";
			angle = 15;
			scale[] = {0.9,0.9,0.4};
			brightness = 0.08;
		};
		ace_weight = 0.92;
		dexterity = "(1 + 0.75/(0.82 + 0.1 + 0.001))";
		ACE_Size = "21.8*15.4*3.8";
	};
	class ACE_USPSD: ACE_USP
	{
		displayName = "$STR_DN_ACE_USPSD";
		model = "\x\acex\addons\m_wep_pistol\RH_uspsd.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\w_uspsd_ca.paa";
		recoil = "ACE_45ACP_SUP_PistolRecoil";
		begin1[] = {"\x\acex\addons\s_wep_pistol\m9sd_fire.wss",0.01,0.9,15};
		soundBegin[] = {"begin1",1};
		magazines[] = {"ACE_12Rnd_45ACP_USPSD","ACE_12Rnd_45ACP_USP"};
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		dispersion = 0.0081;
		descriptionShort = "$STR_DSS_ACE_USPSD";
		ace_weight = 1.36;
		dexterity = "(1 + 0.75/(0.82 + 0.1 + 0.44 + 0.001))";
		ACE_Size = "21.8*15.4*3.8 + 3.1416*1.75*1.75*19.685";
	};
	class ACE_P8: M9
	{
		displayName = "P8";
		model = "\x\acex\addons\m_wep_pistol\ACE_P8.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\w_p8_ca.paa";
		magazines[] = {"ACE_15Rnd_9x19_P8"};
		ace_weight = 0.72;
		dexterity = "(1 + 0.75/(0.72 + 0.001))";
		ACE_Size = "19.4*13.6*3.2";
		class Library
		{
			libTextDesc = "";
		};
	};
	class ACE_P226: M9
	{
		displayName = "SIG P226";
		model = "\x\acex\addons\m_wep_pistol\RH_p226.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\w_p226_ca.paa";
		begin1[] = {"\x\acex\addons\s_wep_pistol\glock_fire1.wss",0.794328,1,700};
		soundBegin[] = {"begin1",1};
		drySound[] = {"\ca\Weapons\Data\Sound\T33_dry_v1",0.01,1,20};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_pistol\m9_reload.wss",0.1,1,20};
		magazines[] = {"ACE_15Rnd_9x19_P226"};
		class Library
		{
			libTextDesc = "";
		};
		ace_weight = 0.74;
		dexterity = "(1 + 0.75/(0.74 + 0.001))";
		ACE_Size = "19.558*13.97*3.81";
	};
	class ACE_TT: Makarov
	{
		ACE_sys_weapons_Side[] = {"INS","GUE"};
		displayName = "TT33";
		model = "\x\acex\addons\m_wep_pistol\RH_TT33.p3d";
		picture = "\x\acex\addons\c_wep_pistol\i\w_tt33_ca.paa";
		magazines[] = {"ACE_8Rnd_762x25_B_Tokarev"};
		recoil = "ACE_762x25_PistolRecoil";
		ace_weight = 0.854;
		dexterity = "(1 + 0.75/(0.854 + 0.001))";
		ACE_Size = 777.1;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_TT";
		begin1[] = {"\x\acex\addons\s_wep_pistol\tt_fire1.wss",0.794328,1,700};
		begin2[] = {"\x\acex\addons\s_wep_pistol\tt_fire2.wss",0.794328,1,700};
		begin3[] = {"\x\acex\addons\s_wep_pistol\tt_fire3.wss",0.794328,0.98,700};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class ACE_Flaregun: M9
	{
		ACE_sys_weapons_Side[] = {"DEFAULT"};
		displayName = "$STR_DN_ACE_FLAREGUN";
		picture = "\x\acex\addons\c_wep_pistol\i\w_flaregun_ca.paa";
		model = "\x\acex\addons\m_wep_pistol\ST_flaregun.p3d";
		magazines[] = {"ACE_SSWhite_FG","ACE_SSRed_FG","ACE_SSGreen_FG","ACE_SSYellow_FG"};
		descriptionShort = "";
		begin1[] = {"\x\acex\addons\s_wep_pistol\flare_fire.wss",0.794328,1,60};
		soundBegin[] = {"begin1",1};
		class Library
		{
			libTextDesc = "";
		};
	};
	class ACE_L9A1: M9
	{
		displayName = "L9A1";
		picture = "\x\acex\addons\c_wep_pistol\i\w_L9A1_ca.paa";
		model = "\x\acex\addons\m_wep_pistol\RH_browningHP.p3d";
		magazines[] = {"ACE_13Rnd_9x19_L9A1"};
		ace_weight = 0.9;
		dexterity = "(1 + 0.75/(0.9 + 0.001))";
		ACE_sys_weapons_Side[] = {"BIS_BAF"};
		class Library
		{
			libTextDesc = "";
		};
		ACE_Size = "19.7*12.75*2.55";
	};
};
//};
