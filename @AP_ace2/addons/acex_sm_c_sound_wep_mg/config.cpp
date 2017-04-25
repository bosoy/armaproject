////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:46 2011 : Created on Fri Oct 21 14:00:46 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_mg : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_mg
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons_AK","CAWeapons_E","CAWeapons_BAF","acex_sm_s_wep_mg"};
		version = "1.12.0.97";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle;
	class MGun;
	class G36C;
	class AK_74;
	class M240: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_mg\mg_reload.wss",0.0562341,1,20};
		class manual: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m240_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m240_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m240_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
	};
	class MG36: G36C
	{
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.32,"begin2",0.33,"begin3",0.34};
		};
		class Burst: Mode_Burst
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\g36a_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M249: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_mg\saw_reload.wss",0.0562341,1,20};
		class manual: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m249_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m249_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m249_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M249_EP1: M249
	{
		class manual: manual
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M249_m145_EP1: M249
	{
		class manual: manual
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M249_TWS_EP1: M249
	{
		class manual: manual
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class BAF_L110A1_Aim: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_mg\saw_reload.wss",0.0562341,1,20};
		class manual: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m249p_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual{};
		class short: close{};
		class medium: close{};
		class far: close{};
	};
	class PK: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_mg\mg_reload.wss",0.0562341,1,20};
		class manual: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class PKT: MGun
	{
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1.03,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close;
		class short;
		class medium;
		class far;
	};
	class PKT_MG_Nest: PKT
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_mg\mg_reload.wss",0.0562341,1,20};
		class manual: manual
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: close
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class short: short
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class medium: medium
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class far: far
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkm_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class PKT_veh: PKT_MG_Nest
	{
		reloadmagazinesound[] = {"",1,1};
		class manual: manual
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1.03,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: close
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1.03,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class short: short
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1.03,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class medium: medium
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1.03,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class far: far
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1.03,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\pkt_fire.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class M134: MGun
	{
		class LowROF: Mode_FullAuto
		{
			sound[] = {"",0,0,0};
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m134_lo_fire.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",1};
		};
		class HighROF: LowROF
		{
			sound[] = {"",0,0,0};
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m134_hi_fire.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",1};
		};
		class close: HighROF
		{
			soundBurst = 0;
		};
		class medium: LowROF
		{
			soundBurst = 0;
		};
	};
	class M240_veh: MGun
	{
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m240coax_fire.wss",1.77828,1.03,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m240coax_fire.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m240coax_fire.wss",1.77828,0.97,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual
		{
			soundBurst = 0;
		};
		class short;
		class medium;
		class far;
	};
	class KORD: MGun
	{
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\dshk_fire.wss",5.62341,1,2200};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\dshk_fire.wss",5.62341,0.98,2200};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\dshk_fire.wss",5.62341,0.96,2200};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual
		{
			soundBurst = 0;
		};
	};
	class KPVT: MGun
	{
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\kpvt_fire.wss",5.62341,1,2500};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\kpvt_fire.wss",5.62341,0.98,2500};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\kpvt_fire.wss",5.62341,0.96,2500};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual
		{
			soundBurst = 0;
		};
	};
	class M2: MGun
	{
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,1,2220};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,0.98,2200};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,0.96,2200};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual
		{
			soundBurst = 0;
		};
	};
	class DSHKM: MGun
	{
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\dshk_fire.wss",5.62341,1,2200};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\dshk_fire.wss",5.62341,0.98,2200};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\dshk_fire.wss",5.62341,0.96,2200};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual
		{
			soundBurst = 0;
		};
	};
	class Mk_48: M240
	{
		class manual: manual
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\mk48_fire1.wss",1.62341,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\mk48_fire2.wss",1.62341,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\mk48_fire3.wss",1.62341,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class RPK_74: AK_74
	{
		class FullAuto: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class manual: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual{};
		class short: close{};
		class medium: close{};
		class far: close{};
		class Single: Mode_SemiAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire1.wss",1.77828,1,1100};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire2.wss",1.77828,1,1100};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\rpk74_fire3.wss",1.77828,1,1100};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
	};
	class M60A4_EP1: Rifle
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_mg\mg_reload.wss",0.0562341,1,20};
		class manual: Mode_FullAuto
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m60_fire1.wss",1.77828,1,1700};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m60_fire2.wss",1.77828,1,1700};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m60_fire3.wss",1.77828,1,1700};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		class close: manual{};
		class short: close{};
		class medium: close{};
		class far: close{};
	};
	class BAF_L7A2: MGun
	{
		begin1[] = {"x\acex_sm\addons\s_wep_mg\m240_fire1.wss",1.77828,1,1700};
		begin2[] = {"x\acex_sm\addons\s_wep_mg\m240_fire2.wss",1.77828,1,1700};
		begin3[] = {"x\acex_sm\addons\s_wep_mg\m240_fire3.wss",1.77828,1,1700};
		soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
	};
	class BAF_L2A1: M2
	{
		begin1[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,1,2220};
		begin2[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,0.98,2200};
		begin3[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,0.96,2200};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		class manual: MGun
		{
			begin1[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,1,2220};
			begin2[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,0.98,2200};
			begin3[] = {"x\acex_sm\addons\s_wep_mg\m2hb_fire.wss",5.62341,0.96,2200};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
	};
	class BAF_L94A1: MGun
	{
		begin1[] = {"x\acex_sm\addons\s_wep_mg\m240coax_fire.wss",1.77828,1.03,1700};
		begin2[] = {"x\acex_sm\addons\s_wep_mg\m240coax_fire.wss",1.77828,1,1700};
		begin3[] = {"x\acex_sm\addons\s_wep_mg\m240coax_fire.wss",1.77828,0.97,1700};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
};
//};
