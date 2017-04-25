////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 28 16:02:39 2011 : Created on Fri Oct 28 16:02:39 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_sniper : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_sniper
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons_AK","CAWeapons2","CAweapons_m107","CAWeapons_DMR","CAweapons_ksvk","CAWeapons_E","CAWeapons_E_M110","acex_sm_s_wep_sniper"};
		version = "1.12.0.98";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle;
	class M24: Rifle
	{
		begin1[] = {"x\acex_sm\addons\s_wep_sniper\m24_fire1.wss",1.77828,1,1700};
		begin2[] = {"x\acex_sm\addons\s_wep_sniper\m24_fire2.wss",1.77828,1,1700};
		begin3[] = {"x\acex_sm\addons\s_wep_sniper\m24_fire3.wss",1.77828,1,1700};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		reloadSound[] = {"x\acex_sm\addons\s_wep_sniper\m24_bolt.wss",0.01,1,20};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\m24_reload.wss",0.01,1,20};
	};
	class M107: Rifle
	{
		begin1[] = {"x\acex_sm\addons\s_wep_sniper\m107_fire1.wss",3.51189,1,2200};
		begin2[] = {"x\acex_sm\addons\s_wep_sniper\m107_fire2.wss",3.51189,1,2200};
		begin3[] = {"x\acex_sm\addons\s_wep_sniper\m107_fire3.wss",3.51189,1,2200};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\m107_reload.wss",0.0316228,1,20};
	};
	class KSVK: Rifle
	{
		begin1[] = {"x\acex_sm\addons\s_wep_sniper\ksvk_fire1.wss",3.51189,1,2200};
		begin2[] = {"x\acex_sm\addons\s_wep_sniper\ksvk_fire2.wss",3.51189,1,2200};
		begin3[] = {"x\acex_sm\addons\s_wep_sniper\ksvk_fire3.wss",3.51189,1,2200};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		reloadSound[] = {"x\acex_sm\addons\s_wep_sniper\ksvk_bolt.wss",0.01,1,20};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\ksvk_reload.wss",0.0316228,1,20};
	};
	class DMR: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\m14_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_sniper\m14_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_sniper\m14_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_sniper\m14_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
	};
	class SVD: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\ak_reload.wss",0.0316228,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_sniper\svd_fire1.wss",1.77828,1,1700};
		begin2[] = {"x\acex_sm\addons\s_wep_sniper\svd_fire2.wss",1.77828,1,1700};
		begin3[] = {"x\acex_sm\addons\s_wep_sniper\svd_fire3.wss",1.77828,1,1700};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class VSS_vintorez: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\ak_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_sniper\vss_fire1.wss",0.01,1,20};
			soundBegin[] = {"begin1",1};
		};
		class Full: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_sniper\vss_fire2.wss",0.01,1,20};
			soundBegin[] = {"begin1",1};
		};
	};
	class M110_TWS_EP1: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\762_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_sniper\m110_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_sniper\m110_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_sniper\m110_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class BAF_AS50_scoped: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\m107_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_sniper\as50_fire.wss",3.51189,1,2200};
			soundbegin[] = {"begin1",1};
		};
	};
	class BAF_LRR_scoped: Rifle
	{
		reloadSound[] = {"x\acex_sm\addons\s_wep_sniper\m24_bolt.wss",0.01,1,20};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_sniper\m14_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_sniper\m24_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_sniper\m24_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_sniper\m24_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
};
//};
