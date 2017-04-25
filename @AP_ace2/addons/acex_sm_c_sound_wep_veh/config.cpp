////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:40:31 2012 : Created on Fri Nov 09 22:40:31 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_veh : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_veh
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAAir","CAAir2","CAAir3","CAAir2_C130J","CAWeapons","CAWheeled","CAWheeled2_MTVR","CAWeapons_E","CAWeapons_BAF","acex_sm_s_wep_veh"};
		version = "1.14.0.107";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Default;
	class LauncherCore;
	class MGun;
	class RocketPods;
	class SmokeLauncher;
	class MissileLauncher;
	class CannonCore;
	class CMFlareLauncher: SmokeLauncher
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\Flare.ogg",0.316228,1,300};
		class Single: Mode_SemiAuto
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\Flare.ogg",0.316228,1,300};
		};
		class Burst: Mode_Burst
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\Flare.ogg",0.316228,1,300};
		};
	};
	class 2B14: CannonCore
	{
		class Single1: Mode_SemiAuto
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\mortar_fire.wss",1.564,0.95,800};
		};
		class Burst1: Mode_Burst
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\mortar_fire.wss",1.564,1,800};
		};
	};
	class M252: CannonCore
	{
		class Single1: Mode_SemiAuto
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\mortar_fire.wss",1.564,0.95,800};
		};
		class Burst1: Mode_Burst
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\mortar_fire.wss",1.564,1,800};
		};
	};
	class M256: CannonCore
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\m256_fire.wss",316.228,1,4500};
	};
	class ZiS_S_53: Cannoncore
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\zis_fire.wss",316.228,1,3800};
	};
	class M197: CannonCore
	{
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,1.05,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,0.96,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M621: MGun
	{
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,1.05,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,0.96,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M230: CannonCore
	{
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,0.92,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,0.9,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\m197_fire.wss",10,0.88,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M242: CannonCore
	{
		class LowROF: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,1.03,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,0.97,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class HighROF: LowROF
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,1.03,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,0.97,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class GAU12: CannonCore
	{
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,1.4,3000};
			soundBegin[] = {"begin1",1};
		};
	};
	class AZP85: CannonCore
	{
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire1.wss",13,1.02,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire1.wss",13,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire1.wss",13,0.98,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 1;
		};
		class close: manual
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire4.wss",13,1.02,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire4.wss",13,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire4.wss",13,0.98,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 1;
		};
		class short: close
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire4.wss",13,1.02,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire4.wss",13,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire4.wss",13,0.98,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 1;
		};
		class medium: close
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire3.wss",13,1.02,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire3.wss",13,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire3.wss",13,0.98,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 1;
		};
		class far: close
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire1.wss",12,1.02,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire1.wss",12,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\zsu_fire1.wss",12,0.98,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 1;
		};
	};
	class 2A42: CannonCore
	{
		class LowROF: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,1.02,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,0.98,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class HighROF: LowROF
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,1.02,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,0.98,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class 2A14: CannonCore
	{
		class manual: CannonCore
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\zu_1_fire.wss",10,1,3000};
			soundContinuous = 0;
			soundBurst = 1;
		};
		class close: manual
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\zu_3_fire.wss",10,1,3000};
			soundBurst = 1;
		};
		class short: close
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\zu_4_fire.wss",10,1,3000};
			soundBurst = 1;
		};
		class medium: close
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\zu_3_fire.wss",10,1,3000};
			soundBurst = 1;
		};
		class far: close
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\zu_2_fire.wss",10,1,3000};
			soundBurst = 1;
		};
	};
	class 2A38M: CannonCore
	{
		class manual: CannonCore
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\2a38_fire.wss",10,1,3000};
			soundContinuous = 0;
			soundBurst = 1;
		};
		class close: manual
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\2a38_fire.wss",10,1,3000};
			soundBurst = 0;
		};
		class short: close
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\2a38_fire.wss",10,1,3000};
		};
		class medium: close
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\2a38_fire.wss",10,1,3000};
		};
		class far: close
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\2a38_fire.wss",10,1,3000};
		};
	};
	class 2A72: CannonCore
	{
		soundContinuous = 0;
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,1.02,3400};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,1,3400};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\2a42_fire.wss",10,0.98,3400};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 0;
		};
		class close: manual
		{
			soundBurst = 0;
		};
		class short: close{};
		class medium: close{};
		class far: close{};
	};
	class M119: CannonCore
	{
		reloadSound[] = {"x\acex_sm\addons\s_wep_veh\m119_reload.wss",0.1,1,30};
		sound[] = {"x\acex_sm\addons\s_wep_veh\m119_fire.wss",10,1,4000};
		class Single1: Mode_SemiAuto
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\m119_fire.wss",10,1,4000};
		};
		class Single2: Single1{};
		class Single3: Single1{};
		class Burst1: Mode_Burst
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\m119_fire.wss",10,1,4000};
		};
		class Burst2: Burst1{};
		class Burst3: Burst1{};
	};
	class D30: CannonCore
	{
		reloadSound[] = {"x\acex_sm\addons\s_wep_veh\d30_reload.wss",0.1,1,30};
		class Single1: Mode_SemiAuto
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\d30_fire.wss",10,1,4000};
		};
		class Single2: Single1{};
		class Single3: Single1{};
		class Burst1: Mode_Burst
		{
			soundburst = 0;
		};
		class Burst2: Burst1{};
		class Burst3: Burst1{};
	};
	class D10: CannonCore
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\d81_fire.wss",316.228,0.92,4000};
	};
	class D81: CannonCore
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\d81_fire.wss",316.228,1,4600};
		reloadSound[] = {"x\acex_sm\addons\s_wep_veh\d81_reload.wss",0.001,1,3};
	};
	class FFARLauncher: RocketPods
	{
		class Far_AI: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\ffar_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
		class Burst: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\ffar_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class FFARLauncher_14: FFARLauncher{};
	class CRV7_PG: RocketPods
	{
		class Far_AI: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\ffar_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
		class Burst: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\ffar_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class CRV7_HEPD: CRV7_PG
	{
		class Burst: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\ffar_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class CRV7_FAT: CRV7_PG
	{
		class Burst: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\ffar_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class 57mmLauncher: RocketPods
	{
		class Far_AI: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\57mm_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
		class Burst: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\57mm_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class 57mmLauncher_64: 57mmLauncher{};
	class 57mmLauncher_128: 57mmLauncher{};
	class 80mmLauncher: RocketPods
	{
		class Far_AI: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\80mm_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
		class Burst: RocketPods
		{
			sound[] = {"x\acex_sm\addons\s_wep_veh\80mm_fire.wss",2,1,1700};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class GSh23L: CannonCore
	{
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,1.01,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,1.02,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,1.03,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class GSh301: CannonCore
	{
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,0.99,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,1.0,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,1.01,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class GSh302: CannonCore
	{
		class manual: CannonCore
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,0.99,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,1.0,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\gsh_fire.wss",10,1.01,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
			soundContinuous = 0;
			soundBurst = 0;
		};
	};
	class YakB: MGun
	{
		class manual: MGun
		{
			soundBurst = 1;
			soundContinuous = 0;
			begin1[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.83,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.82,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.81,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
		class close: manual
		{
			soundBurst = 1;
			soundContinuous = 0;
			begin1[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.83,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.82,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.81,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
		class short: close
		{
			soundBurst = 1;
			soundContinuous = 0;
			begin1[] = {"x\acex_sm\addons\s_wep_veh\yakb_16_fire.wss",10,0.83,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\yakb_16_fire.wss",10,0.82,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\yakb_16_fire.wss",10,0.81,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
		class medium: close
		{
			soundBurst = 1;
			soundContinuous = 0;
			begin1[] = {"x\acex_sm\addons\s_wep_veh\yakb_16_fire.wss",10,0.83,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\yakb_16_fire.wss",10,0.82,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\yakb_16_fire.wss",10,0.81,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
		class far: close
		{
			soundBurst = 1;
			soundContinuous = 0;
			begin1[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.83,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.82,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\yakb_8_fire.wss",10,0.81,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
	};
	class BombLauncher: RocketPods
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\bombout.wss",2,1,15};
	};
	class BombLauncherF35: BombLauncher{};
	class BombLauncherA10: BombLauncher{};
	class SPG9: RocketPods
	{
		autoReload = 0;
		sound[] = {"x\acex_sm\addons\s_wep_veh\spg_fire.wss",10,1,1800};
	};
	class AGS30: MGun
	{
		begin1[] = {"x\acex_sm\addons\s_wep_veh\ags_fire.wss",1,1,250};
		begin2[] = {"x\acex_sm\addons\s_wep_veh\ags_fire.wss",1,0.97,250};
		begin3[] = {"x\acex_sm\addons\s_wep_veh\ags_fire.wss",1,0.93,250};
		soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
	};
	class MK19: MGun
	{
		begin1[] = {"x\acex_sm\addons\s_wep_veh\mk19_fire.wss",1,1,250};
		begin2[] = {"x\acex_sm\addons\s_wep_veh\mk19_fire.wss",1,0.98,250};
		begin3[] = {"x\acex_sm\addons\s_wep_veh\mk19_fire.wss",1,0.94,250};
		soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
	};
	class BAF_static_GMG: MGun
	{
		begin1[] = {"x\acex_sm\addons\s_wep_veh\mk19_fire.wss",1,1,250};
		begin2[] = {"x\acex_sm\addons\s_wep_veh\mk19_fire.wss",1,0.98,250};
		begin3[] = {"x\acex_sm\addons\s_wep_veh\mk19_fire.wss",1,0.94,250};
		soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
	};
	class TOWLauncher: MissileLauncher
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\tow_fire",10,1,2800};
	};
	class HellfireLauncher: MissileLauncher
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\hellfire_fire",10,1,2500};
	};
	class AT2Launcher: MissileLauncher
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\atmissile_fire",10,1,2400};
	};
	class AT5Launcher: MissileLauncher
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\at10_fire",10,1,2400};
	};
	class AT6Launcher: MissileLauncher
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\at10_fire",10,1,2400};
	};
	class AT9Launcher: MissileLauncher
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\at10_fire",10,1,2400};
	};
	class AT11LauncherSingle;
	class AT13LauncherSingle: AT11LauncherSingle
	{
		sound[] = {"x\acex_sm\addons\s_wep_veh\at10_fire",10,1,2400};
	};
	class CTWS: CannonCore
	{
		class player: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,1.03,3000};
			begin2[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,1,3000};
			begin3[] = {"x\acex_sm\addons\s_wep_veh\m242_fire.wss",10,0.97,3000};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
};
//};
