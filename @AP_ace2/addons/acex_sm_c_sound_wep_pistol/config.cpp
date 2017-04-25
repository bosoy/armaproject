////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:46 2011 : Created on Fri Oct 21 14:00:46 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_pistol : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_pistol
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons_Colt1911","CAWeapons_E","acex_sm_s_wep_pistol"};
		version = "1.12.0.97";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Pistol;
	class M9: Pistol
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_pistol\m9_reload.wss",0.0316228,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_pistol\m9_fire1.wss",1.794328,1,800};
		begin2[] = {"x\acex_sm\addons\s_wep_pistol\m9_fire2.wss",1.794328,1,800};
		begin3[] = {"x\acex_sm\addons\s_wep_pistol\m9_fire3.wss",1.794328,1,800};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class M9SD: M9
	{
		begin1[] = {"x\acex_sm\addons\s_wep_pistol\m9sd_fire1.wss",0.01,1,10};
		begin2[] = {"x\acex_sm\addons\s_wep_pistol\m9sd_fire2.wss",0.01,0.97,10};
		begin3[] = {"x\acex_sm\addons\s_wep_pistol\m9sd_fire3.wss",0.01,1.03,10};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class Colt1911: M9
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_pistol\m1911_reload.wss",0.0316228,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_pistol\m1911_fire1.wss",2.794328,1,1000};
		begin2[] = {"x\acex_sm\addons\s_wep_pistol\m1911_fire2.wss",2.794328,1,1000};
		begin3[] = {"x\acex_sm\addons\s_wep_pistol\m1911_fire3.wss",2.794328,1,1000};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class Makarov: Pistol
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_pistol\makarov_reload.wss",0.0316228,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire1.wss",1.794328,1,750};
		begin2[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire2.wss",1.794328,1,750};
		begin3[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire3.wss",1.794328,1,750};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class MakarovSD: Makarov
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_pistol\makarov_reload.wss",0.0316228,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_pistol\pb_fire.wss",0.01,1,10};
		begin2[] = {"x\acex_sm\addons\s_wep_pistol\pb_fire.wss",0.01,0.95,10};
		begin3[] = {"x\acex_sm\addons\s_wep_pistol\pb_fire.wss",0.01,1.04,10};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class revolver_EP1: Pistol
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_pistol\revolver_reload.wss",0.0316228,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_pistol\revolver_fire.wss",2.794328,1.03,1000};
		begin2[] = {"x\acex_sm\addons\s_wep_pistol\revolver_fire.wss",2.794328,1,1000};
		begin3[] = {"x\acex_sm\addons\s_wep_pistol\revolver_fire.wss",2.794328,1.05,1000};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class glock17_EP1: Pistol
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_pistol\m9_reload.wss",0.0316228,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_pistol\glock_fire1.wss",1.794328,1,800};
		begin2[] = {"x\acex_sm\addons\s_wep_pistol\glock_fire2.wss",1.794328,1,800};
		begin3[] = {"x\acex_sm\addons\s_wep_pistol\glock_fire3.wss",1.794328,1,800};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class Sa61_EP1: Pistol
	{
		class Single: Mode_SemiAuto
		{
			reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_pistol\mp_reload.wss",0.0316228,1,20};
			begin1[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire1.wss",1.794328,1,800};
			begin2[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire2.wss",1.794328,1,800};
			begin3[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire3.wss",1.794328,1,800};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire1.wss",1.794328,1,800};
			begin2[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire2.wss",1.794328,1,800};
			begin3[] = {"x\acex_sm\addons\s_wep_pistol\makarov_fire3.wss",1.794328,1,800};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
};
//};
