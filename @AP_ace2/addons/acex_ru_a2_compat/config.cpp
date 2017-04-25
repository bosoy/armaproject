////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed Feb 08 15:24:50 2012 : Created on Wed Feb 08 15:24:50 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_a2_compat : config.bin{
class CfgPatches
{
	class acex_ru_a2_compat
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"ace_main","acex_main","acex_ru_main","ace_sys_survival","CACharacters_E","CATracked_E","CAWheeled_E","CAAir_E"};
	};
	class ace_c_wep_rpg7
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_veh_bmd1
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_c_veh_bmd1
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_veh_bmd2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_c_veh_bmp2
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_c_veh_brdm
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_veh_mi17
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_veh_mi24
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_c_veh_mi24
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_c_veh_t72
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_men_insurgents
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_c_men_insurgents
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_veh_su27
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
	class acex_c_veh_su27
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {};
		version = "1.13.0.65";
		ace_bwc = 1;
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ACE_COMPAT_acex_ru_a2_compat
		{
			list[] = {"acex_ru_a2_compat"};
		};
		class ACE_COMPAT_acex_ru_veh_su27
		{
			list[] = {"acex_ru_veh_su27"};
		};
		class ACE_COMPAT_acex_ru_veh_mi24
		{
			list[] = {"acex_ru_veh_mi24"};
		};
		class ACE_COMPAT_acex_ru_veh_mi17
		{
			list[] = {"acex_ru_veh_mi17"};
		};
		class ACE_COMPAT_acex_ru_veh_t72
		{
			list[] = {"acex_ru_veh_t72"};
		};
		class ACE_COMPAT_acex_ru_veh_brdm
		{
			list[] = {"acex_ru_veh_brdm"};
		};
		class ACE_COMPAT_acex_ru_veh_bmd1
		{
			list[] = {"acex_ru_veh_bmd1"};
		};
		class ACE_COMPAT_acex_ru_veh_bmd2
		{
			list[] = {"acex_ru_veh_bmd2"};
		};
		class ACE_COMPAT_acex_ru_veh_bmp2
		{
			list[] = {"acex_ru_veh_bmp2"};
		};
	};
};
class CfgAmmo
{
	class M_Ch29_AT;
	class ACE_M_Ch29_AT: M_Ch29_AT
	{
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
	};
};
class CfgMagazines
{
	class 20Rnd_B_765x17_Ball;
	class ACE_20Rnd_765x17_vz61: 20Rnd_B_765x17_Ball
	{
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
	};
};
class CfgWeapons
{
	class Sa61_EP1;
	class ACE_Scorpion: Sa61_EP1
	{
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
	};
	class Makarov;
	class ACE_APS: Makarov
	{
		magazines[] = {"ACE_20Rnd_9x18_APS","ACE_20Rnd_9x18_APSB"};
		class Armory
		{
			disabled = 1;
		};
	};
	class MakarovSD;
	class ACE_APSB: MakarovSD
	{
		magazines[] = {"ACE_20Rnd_9x18_APSB","ACE_20Rnd_9x18_APS"};
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgVehicles
{
	class TK_GUE_Soldier_EP1;
	class ACE_Ins_1_1: TK_GUE_Soldier_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_AT_EP1;
	class ACE_Ins_1_2: TK_GUE_Soldier_AT_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_AAT_EP1;
	class ACE_Ins_1_3: TK_GUE_Soldier_AAT_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Bonesetter_EP1;
	class ACE_Ins_1_4: TK_GUE_Bonesetter_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_AR_EP1;
	class ACE_Ins_1_5: TK_GUE_Soldier_AR_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_3_EP1;
	class ACE_Ins_2_1: TK_GUE_Soldier_3_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_2_2: TK_GUE_Soldier_AR_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_Sniper_EP1;
	class ACE_Ins_2_3: TK_GUE_Soldier_Sniper_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_2_4: TK_GUE_Soldier_AT_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_4_EP1;
	class ACE_Ins_2_5: TK_GUE_Soldier_4_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_2_6: TK_GUE_Soldier_AAT_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_2_7: TK_GUE_Soldier_Sniper_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_AA_EP1;
	class ACE_Ins_2_8: TK_GUE_Soldier_AA_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_2_9: TK_GUE_Soldier_AT_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_2_10: TK_GUE_Soldier_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_1: TK_GUE_Soldier_Sniper_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_2: TK_GUE_Soldier_AR_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_3: TK_GUE_Soldier_3_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_4: TK_GUE_Soldier_AA_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_5: TK_GUE_Soldier_AT_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_6: TK_GUE_Soldier_AAT_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_7: TK_GUE_Soldier_AR_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class TK_GUE_Soldier_TL_EP1;
	class ACE_Ins_3_8: TK_GUE_Soldier_TL_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_9: TK_GUE_Soldier_TL_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
	class ACE_Ins_3_10: TK_GUE_Soldier_4_EP1
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
		side = 0;
	};
};
//};
