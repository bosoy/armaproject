////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 18 19:11:40 2011 : Created on Fri Nov 18 19:11:40 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_rifle : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_rifle
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons_AK","CAWeapons2","CAWeapons_E","CAWeapons_E_scar","CAWeapons_E_LeeEnfield","CAWeapons_E_M14","CAWeapons_E_fnfal","CAWeapons_E_GrenadeLauncher","acex_sm_s_wep_rifle"};
		version = "1.12.0.99";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class PistolCore;
	class RifleCore;
	class MGunCore;
	class LauncherCore;
	class GrenadeCore;
	class GrenadeLauncher;
	class Rifle: RifleCore
	{
		class M203Muzzle;
	};
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle: GrenadeLauncher{};
		class HandGrenadeMuzzle: ThrowMuzzle
		{
			sound[] = {"x\acex_sm\addons\s_wep_rifle\grenade_pin.wss",0.177828,1,20};
		};
		class SmokeShellMuzzle: ThrowMuzzle
		{
			sound[] = {"x\acex_sm\addons\s_wep_rifle\smoke_pin.wss",0.177828,1,20};
		};
	};
	class M16_Base: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m4_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m16_fire1.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",1};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m16_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",1};
			soundBurst = 0;
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m16_fire3.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m16_fire3.wss",1.77828,0.97,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m16_fire3.wss",1.77828,1.03,1100};
			soundBegin[] = {"begin1",0.32,"begin2",0.35,"begin3",0.32};
		};
		class M203Muzzle: M203Muzzle
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m203_fire.wss",1,1,200};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m203_fire.wss",1,0.96,200};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m203_fire.wss",1,0.94,200};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m203_reload.wss",0.0316228,1,20};
		};
	};
	class M4A1: M16_base
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m4_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire2.wss",1.77828,0.97,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.2,"begin2",0.2,"begin3",0.6};
		};
	};
	class M4A1_Aim: M4A1
	{
		class Single;
		class FullAuto;
	};
	class M4A1_AIM_SD_camo: M4A1_Aim
	{
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m4sd_fire.wss",1,1,80};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m4sd_fire.wss",1,0.96,80};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m4sd_fire.wss",1,1.02,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m4sd_fire.wss",1,1,80};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m4sd_fire.wss",1,0.96,80};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m4sd_fire.wss",1,1.03,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M4SPR: M4A1
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m4_reload",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk12_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\mk12_fire2.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
		};
	};
	class G36C: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\g36_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire2.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire3.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire3.wss",1.77828,0.97,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire3.wss",1.77828,1.025,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundBurst = 0;
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36c_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class G36_C_SD_eotech: G36C
	{
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,1,80};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,0.97,80};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,1.025,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,1,80};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,0.98,80};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,1.02,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundBurst = 0;
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,1,80};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,1.03,80};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36sd_fire.wss",1,0.965,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class G36a: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\g36_reload.wss",0.0316228,1,20};
		class MuzzleFar: G36C
		{
			class Single: Mode_SemiAuto
			{
				begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire1.wss",1.77828,1,1100};
				begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire2.wss",1.77828,1,1100};
				soundBegin[] = {"begin1",0.5,"begin2",0.5};
			};
			class Burst: Mode_Burst
			{
				begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire3.wss",1.77828,1,1100};
				begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire3.wss",1.77828,0.97,1100};
				begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire3.wss",1.77828,1.02,1100};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
				soundBurst = 0;
			};
			class FullAuto: Mode_FullAuto
			{
				begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire1.wss",1.77828,1,1100};
				begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire2.wss",1.77828,1,1100};
				begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire2.wss",1.77828,1.02,1100};
				soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			};
		};
	};
	class AK_BASE: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\ak_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\ak74_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class GP25Muzzle: GrenadeLauncher
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\gp30_fire.wss",1,1,100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\gp30_fire.wss",1,0.96,100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\gp30_fire.wss",1,0.94,100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\gp30_reload.wss",0.0316228,1,20};
		};
	};
	class AK_47_M: AK_BASE
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\ak_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1.027,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1.027,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1.027,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class AKS_Base: AK_Base
	{
		class Single: Single{};
		class Burst: Burst{};
		class FullAuto: FullAuto{};
	};
	class AKS_74_U: AKS_BASE
	{
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\aks74u_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class AKS_74_UN_kobra: AKS_BASE
	{
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\aks74un_fire.wss",1,1,80};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\aks74un_fire.wss",1,0.97,80};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\aks74un_fire.wss",1,1.016,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\aks74un_fire.wss",1,1,80};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\aks74un_fire.wss",1,0.97,80};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\aks74un_fire.wss",1,1.016,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class m8_base: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\g36_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
			soundBurst = 0;
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\g36a_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M16A2: M16_Base
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m4_reload.wss",0.0316228,1,20};
	};
	class LeeEnfield: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\enfield_reload.wss",0.0316228,1,20};
		reloadSound[] = {"x\acex_sm\addons\s_wep_rifle\enfield_bolt.wss",0.01,1,20};
		begin1[] = {"x\acex_sm\addons\s_wep_rifle\leeenfield_fire1.wss",2.77828,1,1700};
		begin2[] = {"x\acex_sm\addons\s_wep_rifle\leeenfield_fire2.wss",2.77828,1,1700};
		begin3[] = {"x\acex_sm\addons\s_wep_rifle\leeenfield_fire2.wss",2.77828,0.98,1700};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class M14_EP1: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m14_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m14_fire1.wss",2.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m14_fire2.wss",2.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m14_fire3.wss",2.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.34};
		};
	};
	class SCAR_Base: M16_base
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\g36_reload.wss",0.0316228,1,20};
		class SCAR_L_Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk16_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\mk16_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\mk16_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class SCAR_L_FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk16_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\mk16_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\mk16_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class EGLMMuzzle: M203Muzzle
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m203_fire.wss",1,0.9,200};
			soundBegin[] = {"begin1",1};
		};
	};
	class SCAR_L_Base;
	class SCAR_L_CQC: SCAR_L_Base
	{
		class SCAR_L_Single;
		class SCAR_L_FullAuto;
	};
	class SCAR_L_CQC_CCO_SD: SCAR_L_CQC
	{
		class SCAR_L_SD_Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk16sd_fire.wss",1,1,80};
			soundbegin[] = {"begin1",1};
		};
		class SCAR_L_SD_FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk16sd_fire.wss",1,1,80};
			soundbegin[] = {"begin1",1};
		};
	};
	class SCAR_H_Base: SCAR_Base
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\762_reload.wss",0.0316228,1,20};
		class SCAR_H_Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\mk17_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\mk17_fire2.wss",1.77828,0.98,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
		class SCAR_H_FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\mk17_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\mk17_fire2.wss",1.77828,0.98,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
	};
	class SCAR_H_CQC_CCO: SCAR_H_Base
	{
		class SCAR_H_Single;
	};
	class SCAR_H_CQC_CCO_SD: SCAR_H_CQC_CCO
	{
		class SCAR_H_SD_Single: SCAR_H_Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17sd_fire.wss",1,1,110};
			soundbegin[] = {"begin1",1};
		};
		class SCAR_H_SD_FullAuto: SCAR_H_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17sd_fire.wss",1,1,110};
			soundbegin[] = {"begin1",1};
		};
	};
	class SCAR_H_LNG_Sniper_SD: SCAR_H_Base
	{
		class SCAR_H_SD_Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17sd_fire.wss",1,1,110};
			soundbegin[] = {"begin1",1};
		};
		class SCAR_H_SD_FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17sd_fire.wss",1,1,110};
			soundbegin[] = {"begin1",1};
		};
	};
	class SCAR_H_STD_TWS_SD: SCAR_H_LNG_Sniper_SD
	{
		class SCAR_H_SD_Single: SCAR_H_SD_Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17sd_fire.wss",1,1,110};
			soundbegin[] = {"begin1",1};
		};
		class SCAR_H_SD_FullAuto: SCAR_H_SD_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\mk17sd_fire.wss",1,1,110};
			soundbegin[] = {"begin1",1};
		};
	};
	class FN_FAL: M16A2
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\fal_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\fal_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\fal_fire2.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
		};
		class Burst: Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\fal_fire3.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\fal_fire3.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
		};
	};
	class M4A3_CCO_EP1: M16_base
	{
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire2.wss",1.77828,0.97,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\m4_fire2.wss",1.77828,1.028,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class Sa58P_EP1: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\ak_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1.025,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,0.98,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class Sa58V_EP1: Sa58P_EP1{};
	class Sa58V_RCO_EP1: Sa58V_EP1
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\ak_reload.wss",0.0316228,1,20};
		class Single: Single
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1.027,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\akm_fire2.wss",1.77828,1.027,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class L85A2_base_BAF: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m4_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,0.97,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,0.97,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class BAF_L86A2_ACOG: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m4_reload.wss",0.0316228,1,20};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,0.97,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_rifle\l85_fire2.wss",1.77828,0.97,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class BAF_L17_40mm: GrenadeLauncher
	{
		begin1[] = {"x\acex_sm\addons\s_wep_rifle\m203_fire.wss",1,1,200};
		begin2[] = {"x\acex_sm\addons\s_wep_rifle\m203_fire.wss",1,0.96,200};
		begin3[] = {"x\acex_sm\addons\s_wep_rifle\m203_fire.wss",1,0.94,200};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m203_reload.wss",0.0316228,1,20};
	};
	class GrenadeLauncher_EP1: Rifle
	{
		begin1[] = {"x\acex_sm\addons\s_wep_rifle\m79_fire.wss",1,1,200};
		soundBegin[] = {"begin1",1};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_rifle\m79_reload.wss",0.0316228,1,20};
	};
};
//};
