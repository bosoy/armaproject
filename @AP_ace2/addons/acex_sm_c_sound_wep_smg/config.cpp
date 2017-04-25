////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:48 2011 : Created on Fri Oct 21 14:00:48 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_smg : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_smg
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons_E","acex_sm_s_wep_smg"};
		version = "1.12.0.97";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle;
	class MP5SD: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_smg\mp5_reload.wss",0.0562341,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire1.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire2.wss",0.01,1,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire3.wss",0.01,1,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire1.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire2.wss",0.01,1,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire3.wss",0.01,1,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire1.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire2.wss",0.01,1,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\mp5sd6_fire3.wss",0.01,1,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class MP5A5: MP5SD
	{
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire1.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire2.wss",1.77828,1,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire3.wss",1.77828,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire3.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire3.wss",1.77828,1.02,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire3.wss",1.77828,1.04,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire1.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire2.wss",1.77828,1,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\mp5_fire3.wss",1.77828,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
		};
	};
	class bizon: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_smg\bizon_reload.wss",0.0562341,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire1.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire2.wss",1.77828,1,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire3.wss",1.77828,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire1.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire2.wss",1.77828,1,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire3.wss",1.77828,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire1.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire2.wss",1.77828,1,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\bizon_fire3.wss",1.77828,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class bizon_silenced: bizon
	{
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1.02,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1.04,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1.02,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1.04,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1.02,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\bizonsd_fire.wss",0.01,1.04,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class Pistol;
	class UZI_EP1: Pistol
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_smg\mp_reload.wss",0.0562341,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\uzi_fire1.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\uzi_fire2.wss",1.77828,1,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\uzi_fire3.wss",1.77828,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\uzi_fire1.wss",1.77828,1,700};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\uzi_fire2.wss",1.77828,1,700};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\uzi_fire3.wss",1.77828,1,700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class UZI_SD_EP1: UZI_EP1
	{
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\uzisd_fire1.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\uzisd_fire2.wss",0.01,1,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\uzisd_fire3.wss",0.01,1,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_smg\uzisd_fire1.wss",0.01,1,10};
			begin2[] = {"x\acex_sm\addons\s_wep_smg\uzisd_fire2.wss",0.01,1,10};
			begin3[] = {"x\acex_sm\addons\s_wep_smg\uzisd_fire3.wss",0.01,1,10};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
};
//};
