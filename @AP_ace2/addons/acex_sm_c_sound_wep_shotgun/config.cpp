////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:47 2011 : Created on Fri Oct 21 14:00:47 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_shotgun : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_shotgun
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","acex_sm_s_wep_shotgun"};
		version = "1.12.0.97";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle;
	class Saiga12K: Rifle
	{
		bullet1[] = {"x\acex_sm\addons\s_wep_shotgun\shotgunshell_concrete1.wss",0.023,1,15};
		bullet2[] = {"x\acex_sm\addons\s_wep_shotgun\shotgunshell_concrete2.wss",0.033,1,15};
		bullet3[] = {"x\acex_sm\addons\s_wep_shotgun\shotgunshell_concrete3.wss",0.033,1,15};
		soundBullet[] = {"bullet1",0.33,"bullet2",0.33,"bullet3",0.33};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_shotgun\ak_reload.wss",0.031756,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_shotgun\saiga_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_shotgun\saiga_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_shotgun\saiga_fire2.wss",1.77828,0.98,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M1014: Rifle
	{
		bullet1[] = {"x\acex_sm\addons\s_wep_shotgun\shotgunshell_concrete1.wss",0.023,1,15};
		bullet2[] = {"x\acex_sm\addons\s_wep_shotgun\shotgunshell_concrete2.wss",0.023,1,15};
		bullet3[] = {"x\acex_sm\addons\s_wep_shotgun\shotgunshell_concrete3.wss",0.023,1,15};
		soundBullet[] = {"bullet1",0.33,"bullet2",0.33,"bullet3",0.33};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_shotgun\m1014_reload.wss",0.031756,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_shotgun\m1014_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_shotgun\m1014_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_shotgun\m1014_fire1.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
};
//};
