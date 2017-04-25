////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:44 2011 : Created on Fri Oct 21 14:00:44 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_crack : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_crack
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons2","acex_sm_s_wep_crack"};
		version = "1.12.0.97";
	};
};
class CfgAmmo
{
	class BulletCore;
	class BulletBase: BulletCore
	{
		bulletFly1[] = {"x\acex_sm\addons\s_wep_crack\bullet_fly1.wss",1.0,1,50};
		bulletFly2[] = {"x\acex_sm\addons\s_wep_crack\bullet_fly2.wss",1.0,1,50};
		bulletFly3[] = {"x\acex_sm\addons\s_wep_crack\bullet_fly3.wss",1.0,1,50};
		bulletFly4[] = {"x\acex_sm\addons\s_wep_crack\bullet_fly4.wss",1.0,1,50};
		bulletFly5[] = {"x\acex_sm\addons\s_wep_crack\bullet_fly1.wss",1.0,1,50};
		bulletFly[] = {"bulletFly1",0.125,"bulletFly2",0.25,"bulletFly3",0.25,"bulletFly4",0.25,"bulletFly5",0.125};
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\light_crack_close.wss",1,1,100};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\ak74_crack_far.wss",1,1,800};
	};
	class B_9x18_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\pistol_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\pistol_crack_far.wss",1,1,700};
	};
	class B_9x18_SD: B_9x18_Ball
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",1,1,0};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",1,1,0};
	};
	class B_9x19_Ball: B_9x18_Ball
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\pistol_crack_close.wss",0,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\pistol_crack_far.wss",0,1,700};
	};
	class B_9x19_SD: B_9x19_Ball
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\sd_passby.wss",1,1,0};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",1,1,0};
	};
	class B_45ACP_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\pistol_crack_close.wss",11,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",0,1,600};
	};
	class B_545x39_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\light_crack_close.wss",1,1,100};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\ak74_crack_far.wss",1,1,800};
	};
	class B_545x39_SD: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\sd_passby.wss",1,1,25};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",1,1,0};
	};
	class B_556x45_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\light_crack_close.wss",1,1,100};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\m16_crack_far.wss",1,1,800};
	};
	class B_556x45_SD: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\sd_passby.wss",1,1,25};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",1,1,0};
	};
	class B_9x39_SP5: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\sd_passby.wss",1,1.1,0};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",1,1,0};
	};
	class B_12Gauge_74Slug: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,0};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\empty.wss",1,1,0};
	};
	class B_762x39_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\akm_crack_far.wss",1,1,900};
	};
	class B_762x51_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\m240_crack_far.wss",1,1,900};
	};
	class B_762x51_3RndBurst: B_762x51_Ball
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\m240_crack_far.wss",1,1,900};
	};
	class B_762x51_noTracer: B_762x51_Ball
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\m24_crack_far.wss",1,1,900};
	};
	class B_762x54_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\pkm_crack_far",1,1,900};
	};
	class B_762x54_noTracer: B_762x54_Ball
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\svd_crack_far.wss",1,1,900};
	};
	class B_303_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\m24_crack_far.wss",1,1,900};
	};
	class B_77x56_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\pkm_crack_far",1,0.95,900};
	};
	class B_86x70_Ball_noTracer: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,150};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\pkm_crack_far",1,0.95,900};
	};
	class B_127x99_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\50_crack_far",1,1,1000};
	};
	class B_127x99_Ball_noTracer: B_127x99_Ball
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\50_crack_far",1,1,1000};
	};
	class B_127x107_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\50_crack_far",1,1,1000};
	};
	class B_127x108_Ball: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\50_crack_far",1,1,1000};
	};
	class B_127x108_APHE: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\50_crack_far",1,1,1000};
	};
	class B_145x115_AP: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\50_crack_far",1,1,1100};
	};
	class B_19mm_HE: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1200};
	};
	class B_20mm_AP: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1200};
	};
	class B_20mm_AA: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1200};
	};
	class B_23mm_AA: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1300};
	};
	class B_23mm_HE: B_23mm_AA
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1300};
	};
	class B_23mm_AP: B_23mm_AA
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1300};
	};
	class B_23mm_APHE: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1300};
	};
	class B_25mm_HE: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1400};
	};
	class B_25mm_HEI: B_25mm_HE
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1400};
	};
	class B_25mm_APDS: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1400};
	};
	class B_30mm_AP: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1500};
	};
	class B_30mm_HE: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1500};
	};
	class B_30mmA10_AP: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\krrr.wss",1,1,1500};
	};
	class B_30mm_AA: BulletBase
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\autocannon_crack_far",1,1,1500};
	};
	class ShellCore;
	class ShellBase: ShellCore
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\cannon_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\shellfly1",1,1,800};
	};
	class RocketCore;
	class RocketBase: RocketCore
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\rocket_crack_far",1,1,2000};
		soundFly[] = {"x\acex_sm\addons\s_wep_crack\rpg_fly.wss",1,1,400};
	};
	class R_M136_AT: RocketBase
	{
		soundFly[] = {"x\acex_sm\addons\s_wep_crack\m136_fly.wss",1,1,400};
	};
	class MissileCore;
	class MissileBase: MissileCore
	{
		supersonicCrackNear[] = {"x\acex_sm\addons\s_wep_crack\heavy_crack_close.wss",1,1,200};
		supersonicCrackFar[] = {"x\acex_sm\addons\s_wep_crack\rocket_crack_far",1,1,2000};
		soundFly[] = {"x\acex_sm\addons\s_wep_crack\missile_fly.wss",1,1,800};
	};
	class M_TOW_AT;
	class M_47_AT_EP1: M_TOW_AT
	{
		soundFly[] = {"x\acex_sm\addons\s_wep_crack\dragon_fly.wss",1.3561,1,1000};
	};
};
//};
