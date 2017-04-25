////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 18 19:08:49 2011 : Created on Fri Nov 18 19:08:49 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_shotgun : config.bin{
class CfgPatches
{
	class acex_wep_shotgun
	{
		units[] = {};
		weapons[] = {"ACE_SPAS12"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","acex_m_wep_shotgun","acex_t_wep_shotgun","acex_s_wep_shotgun","ace_sys_shotgun"};
		version = "1.12.0.351";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_shotgun
		{
			list[] = {"acex_wep_shotgun"};
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle;
	class ACE_ShotgunBase: Rifle
	{
		ace_shotgun = 1;
		scope = 1;
		autoFire = 0;
		reloadTime = 0.12;
		modelOptics = "-";
		reloadMagazineSound[] = {"\ca\sounds\weapons\rifles\M1014-reload",0.316228,1,20};
		begin1[] = {"ca\sounds\weapons\rifles\sniper_single_03",1.77828,1,1000};
		begin2[] = {"ca\sounds\weapons\rifles\sniper_single_02",1.77828,1,1000};
		soundBegin[] = {"begin1",0.5,"begin2",0.5};
		drySound[] = {"ca\sounds\weapons\rifles\dry",0.01,1,10};
		bullet1[] = {"\x\acex\addons\s_wep_shotgun\shotgunshell_concrete1.wss",0.023,1,15};
		bullet2[] = {"\x\acex\addons\s_wep_shotgun\shotgunshell_concrete2.wss",0.033,1,15};
		bullet3[] = {"\x\acex\addons\s_wep_shotgun\shotgunshell_concrete3.wss",0.033,1,15};
		soundBullet[] = {"bullet1",0.33,"bullet2",0.33,"bullet3",0.33};
		opticsFlare = 0;
		autoReload = 0;
		distanceZoomMin = 80;
		distanceZoomMax = 80;
		maxLeadSpeed = 10;
		flash = "gunfire";
		flashSize = 0.5;
		dispersion = 0.0001;
		recoil = "ACE_Shotgun_Recoil";
		recoilProne = "ACE_Shotgun_RecoilProne";
		aiDispersionCoefX = 200;
		aiDispersionCoefY = 200;
		aiRateofFire = 2;
		aiRateOfFireDistance = 20;
		ffCount = 1;
		minRange = 0;
		minRangeProbab = 0.7;
		midRange = 60;
		midRangeProbab = 0.2;
		maxRange = 120;
		maxRangeProbab = 0.05;
		class Library
		{
			libTextDesc = "";
		};
	};
	class ACE_SPAS12: ACE_ShotgunBase
	{
		ACE_sys_weapons_Side[] = {"USMC","BIS_GER","BIS_BAF","BIS_US","PMC_BAF"};
		scope = 2;
		displayname = "SPAS 12";
		sound[] = {"\x\acex\addons\s_wep_shotgun\m1014_fire1.wss",1.77828,1,1800};
		model = "\x\acex\addons\m_wep_shotgun\RH_SPAS12.p3d";
		picture = "\x\acex\addons\c_wep_shotgun\i\w_spas12_ca.paa";
		magazines[] = {"8Rnd_B_Beneli_74Slug","8Rnd_B_Beneli_Pellets","ACE_8Rnd_12Ga_Slug","ACE_8Rnd_12Ga_Buck00"};
		ace_weight = 4.4;
		dexterity = "(0.5 + 3.75/(4.4 + 0.001) + 0/10)";
		ACE_Size = 3720;
		descriptionShort = "$STR_DSS_M1014";
	};
	class M1014: Rifle
	{
		scope = 2;
		model = "\x\acex\addons\m_wep_shotgun\ACE_M1014.p3d";
		picture = "\x\acex\addons\c_wep_shotgun\i\w_M1014_ca.paa";
	};
	class ACE_M1014_Eotech: M1014
	{
		displayname = "M1014 Holo";
		model = "\x\acex\addons\m_wep_shotgun\ACE_M1014_Eotech.p3d";
		picture = "\x\acex\addons\c_wep_shotgun\i\w_M1014_eotech_ca.paa";
		ace_weight = 4.15;
		dexterity = "(0.5 + 3.75/(3.8+ 0.35 + 0.001) + 0/10)";
	};
};
//};
