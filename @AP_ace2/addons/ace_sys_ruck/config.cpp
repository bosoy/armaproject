////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:57 2013 : Created on Mon Oct 14 23:07:57 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_ruck : config.bin{
class CfgPatches
{
	class ace_sys_ruck
	{
		units[] = {"ACE_InvisWeaponHolder","ACE_InvisWeaponHolder2","ACE_RUCK_Box_Base","ACE_RuckBox_West","ACE_RuckBox_East","ACE_RuckBox_Ind","ACE_Rucksack_crate","ACE_Rucksack_MOLLE_Green_crate","ACE_Rucksack_MOLLE_Brown_crate","ACE_Rucksack_MOLLE_Wood_crate","ACE_Rucksack_MOLLE_ACU_crate","ACE_Rucksack_MOLLE_WMARPAT_crate","ACE_Rucksack_MOLLE_DMARPAT_crate","ACE_Rucksack_MOLLE_Green_Medic_crate","ACE_Rucksack_MOLLE_Brown_Medic_crate","ACE_Rucksack_MOLLE_ACU_Medic_crate","ACE_Rucksack_MOLLE_WMARPAT_Medic_crate","ACE_Rucksack_MOLLE_DMARPAT_Medic_crate","ACE_VTAC_RUSH72_crate","ACE_CharliePack_crate","ACE_FAST_PackEDC_crate","ACE_Combat_Pack_crate","ACE_Rucksack_RD90_crate","ACE_Rucksack_RD91_crate","ACE_Rucksack_RD92_crate","ACE_Rucksack_RD54_crate","ACE_Rucksack_RD99_crate","ACE_Rucksack_EAST_crate","ACE_Rucksack_EAST_Medic_crate","ACE_BackPack_crate"};
		weapons[] = {"ACE_Rucksack","ACE_Rucksack_MOLLE_Brown","ACE_Rucksack_MOLLE_Brown_Medic","ACE_Rucksack_MOLLE_Green","ACE_Rucksack_MOLLE_Green_Medic","ACE_Rucksack_MOLLE_Green_Miner","ACE_Rucksack_MOLLE_Wood","ACE_Rucksack_MOLLE_ACU","ACE_Rucksack_MOLLE_ACU_Medic","ACE_Rucksack_MOLLE_ACU_Miner","ACE_Rucksack_MOLLE_DMARPAT","ACE_Rucksack_MOLLE_DMARPAT_Medic","ACE_Rucksack_SB_Marpat","ACE_Rucksack_MOLLE_WMARPAT","ACE_Rucksack_MOLLE_WMARPAT_Medic","ACE_Rucksack_EAST","ACE_Rucksack_EAST_Medic","ACE_VTAC_RUSH72","ACE_VTAC_RUSH72_ACU","ACE_VTAC_RUSH72_TT_MEDIC","ACE_VTAC_RUSH72_FT_MEDIC","ACE_CharliePack","ACE_CharliePack_WMARPAT","ACE_CharliePack_ACU","ACE_CharliePack_ACU_Medic","ACE_FAST_PackEDC","ACE_FAST_PackEDC_ACU","ACE_Coyote_Pack","ACE_Coyote_Pack_Black","ACE_PRC119","ACE_PRC119_MAR","ACE_PRC119_ACU","ACE_ANPRC77","ACE_Backpack_US","ACE_ALICE_Backpack","ACE_BackPack_ACR_FL","ACE_BackPack_ACR_TT","ACE_Backpack_FL","ACE_Backpack_TT","ACE_BackPack_ACR_DPM","ACE_BackPack_ACR_DDPM","ACE_Combat_Pack","ACE_BackPack","ACE_P159_RD99","ACE_P159_RD54","ACE_P159_RD90","ACE_P168_RD90","ACE_Rucksack_RD99","ACE_Rucksack_RD54","ACE_Rucksack_RD92","ACE_Rucksack_RD91","ACE_Rucksack_RD90","ACE_BackPack_ACR_Small","ACE_BackPack_ACR"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","ace_sys_interaction","ace_sys_stamina","ace_main","CAWeapons","CAAir","CAAir2","CAAir3","CAData","CAUI","CAWeapons_E","CACharacters"};
		version = "1.14.0.597";
		author[] = {"Joel","q1184","tcp"};
		class ACE_Options
		{
			group = "OTHER";
			title = " ";
		};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_ruck
		{
			list[] = {"ace_sys_ruck"};
		};
	};
};
class CfgVehicleClasses
{
	class ACE_Ammunition_Ruck
	{
		displayName = "$STR_VC_ACE_AMMO_RUCK";
	};
};
class CfgVehicles
{
	class WeaponHolder;
	class ACE_WOBHolder: WeaponHolder
	{
		model = "\x\ace\addons\sys_ruck\ace_weapononback_holder.p3d";
		class TransportMagazines{};
		forceSupply = 0;
		transportMaxMagazines = 1e+009;
		transportMaxWeapons = 1e+009;
		supplyRadius = -100;
	};
	class ACE_InvisWeaponHolder: WeaponHolder
	{
		showWeaponCargo = 0;
		transportMaxMagazines = 1e+009;
		transportMaxWeapons = 1e+009;
		supplyradius = 3;
	};
	class ACE_InvisWeaponHolder2: ACE_InvisWeaponHolder
	{
		transportMaxMagazines = 0;
		transportMaxWeapons = 1;
		supplyradius = 0;
		forceSupply = 0;
		showWeaponCargo = 1;
	};
	class Land;
	class Man: Land
	{
		class ACE;
	};
	class CAManBase: Man
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				weapons[] = {};
				magazines[] = {};
			};
		};
	};
	class ReammoBox;
	class ACE_RUCK_Box_Base: ReammoBox
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition_Ruck";
		displayName = "";
		model = "\Ca\misc\Misc_cargo_cont_tiny";
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class ACE_RuckBox: ACE_RUCK_Box_Base
	{
		scope = 2;
		displayName = "$STR_VDN_ACE_RUCK_BOX";
		class TransportWeapons
		{
			class _xx_ACE_Rucksack_MOLLE_Green
			{
				weapon = "ACE_Rucksack_MOLLE_Green";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_Wood
			{
				weapon = "ACE_Rucksack_MOLLE_Wood";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_ACU
			{
				weapon = "ACE_Rucksack_MOLLE_ACU";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_DMARPAT
			{
				weapon = "ACE_Rucksack_MOLLE_DMARPAT";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_WMARPAT
			{
				weapon = "ACE_Rucksack_MOLLE_WMARPAT";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_Green_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_Green_Medic";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_ACU_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_ACU_Medic";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_DMARPAT_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_DMARPAT_Medic";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_WMARPAT_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_WMARPAT_Medic";
				count = 10;
			};
			class _xx_ACE_VTAC_RUSH72
			{
				weapon = "ACE_VTAC_RUSH72";
				count = 10;
			};
			class _xx_ACE_FAST_PackEDC
			{
				weapon = "ACE_FAST_PackEDC";
				count = 10;
			};
			class _xx_ACE_CharliePack
			{
				weapon = "ACE_CharliePack";
				count = 10;
			};
			class _xx_ACE_CharliePack_WMARPAT
			{
				weapon = "ACE_CharliePack_WMARPAT";
				count = 10;
			};
			class _xx_ACE_PRC119
			{
				weapon = "ACE_PRC119";
				count = 2;
			};
			class _xx_ACE_PRC119_MAR
			{
				weapon = "ACE_PRC119_MAR";
				count = 2;
			};
			class _xx_ACE_PRC119_ACU
			{
				weapon = "ACE_PRC119_ACU";
				count = 2;
			};
			class _xx_ACE_VTAC_RUSH72_ACU
			{
				weapon = "ACE_VTAC_RUSH72_ACU";
				count = 10;
			};
			class _xx_ACE_CharliePack_ACU
			{
				weapon = "ACE_CharliePack_ACU";
				count = 10;
			};
			class _xx_ACE_Rucksack_RD90
			{
				weapon = "ACE_Rucksack_RD90";
				count = 10;
			};
			class _xx_ACE_Rucksack_EAST
			{
				weapon = "ACE_Rucksack_EAST";
				count = 10;
			};
			class _xx_ACE_Rucksack_EAST_Medic
			{
				weapon = "ACE_Rucksack_EAST_Medic";
				count = 10;
			};
			class _xx_ACE_P159_RD90
			{
				weapon = "ACE_P159_RD90";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_Brown
			{
				weapon = "ACE_Rucksack_MOLLE_Brown";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_Brown_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_Brown_Medic";
				count = 10;
			};
		};
	};
	class ACE_RuckBox_West: ACE_RUCK_Box_Base
	{
		scope = 2;
		displayName = "$STR_VDN_ACE_RUCK_BOX_WEST";
		class TransportWeapons
		{
			class _xx_ACE_Rucksack_MOLLE_Green
			{
				weapon = "ACE_Rucksack_MOLLE_Green";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_Wood
			{
				weapon = "ACE_Rucksack_MOLLE_Wood";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_ACU
			{
				weapon = "ACE_Rucksack_MOLLE_ACU";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_DMARPAT
			{
				weapon = "ACE_Rucksack_MOLLE_DMARPAT";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_WMARPAT
			{
				weapon = "ACE_Rucksack_MOLLE_WMARPAT";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_Green_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_Green_Medic";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_ACU_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_ACU_Medic";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_DMARPAT_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_DMARPAT_Medic";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_WMARPAT_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_WMARPAT_Medic";
				count = 10;
			};
			class _xx_ACE_VTAC_RUSH72
			{
				weapon = "ACE_VTAC_RUSH72";
				count = 10;
			};
			class _xx_ACE_VTAC_RUSH72_ACU
			{
				weapon = "ACE_VTAC_RUSH72_ACU";
				count = 10;
			};
			class _xx_ACE_VTAC_RUSH72_OD
			{
				weapon = "ACE_VTAC_RUSH72_OD";
				count = 10;
			};
			class _xx_ACE_VTAC_RUSH72_TT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_TT_MEDIC";
				count = 10;
			};
			class _xx_ACE_VTAC_RUSH72_FT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_FT_MEDIC";
				count = 10;
			};
			class _xx_ACE_CharliePack
			{
				weapon = "ACE_CharliePack";
				count = 10;
			};
			class _xx_ACE_CharliePack_WMARPAT
			{
				weapon = "ACE_CharliePack_WMARPAT";
				count = 10;
			};
			class _xx_ACE_CharliePack_ACU
			{
				weapon = "ACE_CharliePack_ACU";
				count = 10;
			};
			class _xx_ACE_CharliePack_ACU_Medic
			{
				weapon = "ACE_CharliePack_ACU_Medic";
				count = 10;
			};
			class _xx_ACE_CharliePack_Multicam
			{
				weapon = "ACE_CharliePack_Multicam";
				count = 10;
			};
			class _xx_ACE_PRC119
			{
				weapon = "ACE_PRC119";
				count = 2;
			};
			class _xx_ACE_PRC119_MAR
			{
				weapon = "ACE_PRC119_MAR";
				count = 2;
			};
			class _xx_ACE_PRC119_ACU
			{
				weapon = "ACE_PRC119_ACU";
				count = 2;
			};
			class _xx_ACE_ANPRC77
			{
				weapon = "ACE_ANPRC77";
				count = 2;
			};
			class _xx_ACE_FAST_PackEDC
			{
				weapon = "ACE_FAST_PackEDC";
				count = 10;
			};
			class _xx_ACE_FAST_PackEDC_ACU
			{
				weapon = "ACE_FAST_PackEDC_ACU";
				count = 10;
			};
			class _xx_ACE_Coyote_Pack
			{
				weapon = "ACE_Coyote_Pack";
				count = 10;
			};
			class _xx_ACE_Coyote_Pack_Black
			{
				weapon = "ACE_Coyote_Pack_Black";
				count = 10;
			};
			class _xx_ACE_Coyote_Pack_Wood
			{
				weapon = "ACE_Coyote_Pack_Wood";
				count = 10;
			};
			class _xx_ACE_Coyote_Pack_Multicam
			{
				weapon = "ACE_Coyote_Pack_Multicam";
				count = 10;
			};
			class _xx_ACE_BackPack_ACR_DPM
			{
				weapon = "ACE_BackPack_ACR_DPM";
				count = 10;
			};
			class _xx_ACE_BackPack_ACR_DDPM
			{
				weapon = "ACE_BackPack_ACR_DDPM";
				count = 10;
			};
			class _xx_ACE_BackPack_ACR_MTP
			{
				weapon = "ACE_BackPack_ACR_MTP";
				count = 10;
			};
			class _xx_ACE_BackPack_ACR_FL
			{
				weapon = "ACE_BackPack_ACR_FL";
				count = 10;
			};
			class _xx_ACE_BackPack_ACR_TT
			{
				weapon = "ACE_BackPack_ACR_TT";
				count = 10;
			};
			class _xx_ACE_BackPack_ACR
			{
				weapon = "ACE_BackPack_ACR";
				count = 10;
			};
			class _xx_ACE_Backpack_US
			{
				weapon = "ACE_Backpack_US";
				count = 10;
			};
			class _xx_ACE_Backpack_FL
			{
				weapon = "ACE_Backpack_FL";
				count = 10;
			};
			class _xx_ACE_Backpack_TT
			{
				weapon = "ACE_Backpack_TT";
				count = 10;
			};
			class _xx_ACE_Backpack_ACU
			{
				weapon = "ACE_Backpack_ACU";
				count = 10;
			};
			class _xx_ACE_Backpack_Olive
			{
				weapon = "ACE_Backpack_Olive";
				count = 10;
			};
			class _xx_ACE_Backpack_Wood
			{
				weapon = "ACE_Backpack_Wood";
				count = 10;
			};
			class _xx_ACE_Backpack_Multicam
			{
				weapon = "ACE_Backpack_Multicam";
				count = 10;
			};
		};
	};
	class ACE_RuckBox_East: ACE_RUCK_Box_Base
	{
		scope = 2;
		displayName = "$STR_VDN_ACE_RUCK_BOX_EAST";
		model = "\ca\misc\drevena_bedna.p3d";
		class TransportWeapons
		{
			class _xx_ACE_CharliePack_FLORA
			{
				weapon = "ACE_CharliePack_FLORA";
				count = 10;
			};
			class _xx_ACE_Coyote_Pack_Flora
			{
				weapon = "ACE_Coyote_Pack_Flora";
				count = 10;
			};
			class _xx_ACE_Rucksack_RD90
			{
				weapon = "ACE_Rucksack_RD90";
				count = 20;
			};
			class _xx_ACE_Rucksack_EAST
			{
				weapon = "ACE_Rucksack_EAST";
				count = 10;
			};
			class _xx_ACE_Rucksack_EAST_Medic
			{
				weapon = "ACE_Rucksack_EAST_Medic";
				count = 10;
			};
			class _xx_ACE_P159_RD90
			{
				weapon = "ACE_P159_RD90";
				count = 10;
			};
		};
	};
	class ACE_RuckBox_Ind: ACE_RUCK_Box_Base
	{
		scope = 2;
		displayName = "$STR_VDN_ACE_RUCK_BOX_IND";
		model = "\ca\misc\drevena_bedna.p3d";
		class TransportWeapons
		{
			class _xx_ACE_Rucksack_MOLLE_Brown
			{
				weapon = "ACE_Rucksack_MOLLE_Brown";
				count = 10;
			};
			class _xx_ACE_Rucksack_MOLLE_Brown_Medic
			{
				weapon = "ACE_Rucksack_MOLLE_Brown_Medic";
				count = 10;
			};
			class _xx_ACE_P159_RD54
			{
				weapon = "ACE_P159_RD54";
				count = 10;
			};
		};
	};
	class ACE_Rucksack_crate: ReammoBox
	{
		scope = 1;
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_ruck_crate.p3d";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		accuracy = 1000;
		class TransportWeapons{};
		class TransportMagazines{};
		vehicleClass = "ACE_Ammunition_Ruck";
		displayName = "$STR_DN_ACE_RUCKSACK";
		supplyRadius = 3.0;
		armor = 1250;
		hiddenSelections[] = {"TEXTURE"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_ruck\backpack_data\np_sabot_co.paa"};
		class DestructionEffects{};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "true";
	};
	class ACE_Rucksack_MOLLE_Green_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_green.p3d";
	};
	class ACE_Rucksack_MOLLE_Brown_crate: ACE_Rucksack_MOLLE_Green_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\res_ruck_brown.p3d";
	};
	class ACE_Rucksack_MOLLE_Wood_crate: ACE_Rucksack_MOLLE_Green_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_wood.p3d";
	};
	class ACE_Rucksack_MOLLE_ACU_crate: ACE_Rucksack_MOLLE_Green_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_acu.p3d";
	};
	class ACE_Rucksack_MOLLE_WMARPAT_crate: ACE_Rucksack_MOLLE_Green_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_marpat_w.p3d";
	};
	class ACE_Rucksack_MOLLE_DMARPAT_crate: ACE_Rucksack_MOLLE_Green_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_marpat_d.p3d";
	};
	class ACE_Rucksack_MOLLE_Green_Medic_crate: ACE_Rucksack_MOLLE_Green_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic.p3d";
	};
	class ACE_Rucksack_MOLLE_Brown_Medic_crate: ACE_Rucksack_MOLLE_Green_Medic_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\res_ruck_medic.p3d";
	};
	class ACE_Rucksack_MOLLE_ACU_Medic_crate: ACE_Rucksack_MOLLE_Green_Medic_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic_acu.p3d";
	};
	class ACE_Rucksack_MOLLE_WMARPAT_Medic_crate: ACE_Rucksack_MOLLE_Green_Medic_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic_marpat_w.p3d";
	};
	class ACE_Rucksack_MOLLE_DMARPAT_Medic_crate: ACE_Rucksack_MOLLE_Green_Medic_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic_marpat_d.p3d";
	};
	class ACE_ANPRC77_crate: ACE_Rucksack_MOLLE_Green_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote_prc77.p3d";
	};
	class ACE_VTAC_RUSH72_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_black.p3d";
	};
	class ACE_VTAC_RUSH72_ACU_crate: ACE_VTAC_RUSH72_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_acu.p3d";
	};
	class ACE_VTAC_RUSH72_TT_MEDIC_crate: ACE_VTAC_RUSH72_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_tropentarn_medic.p3d";
	};
	class ACE_VTAC_RUSH72_FT_MEDIC_crate: ACE_VTAC_RUSH72_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_flecktarn_medic.p3d";
	};
	class ACE_CharliePack_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_green.p3d";
	};
	class ACE_CharliePack_WMARPAT_crate: ACE_CharliePack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_wmarpat.p3d";
	};
	class ACE_CharliePack_ACU_crate: ACE_CharliePack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_acu.p3d";
	};
	class ACE_CharliePack_ACU_Medic_crate: ACE_CharliePack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_acu_medic.p3d";
	};
	class ACE_PRC119_crate: ACE_CharliePack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_green_prc119.p3d";
		armor = 800;
	};
	class ACE_PRC119_MAR_crate: ACE_PRC119_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_wmarpat_prc119.p3d";
	};
	class ACE_PRC119_ACU_crate: ACE_PRC119_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_acu_prc119.p3d";
	};
	class ACE_FAST_PackEDC_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_fastpack.p3d";
	};
	class ACE_FAST_PackEDC_ACU_crate: ACE_FAST_PackEDC_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_fastpack_acu.p3d";
	};
	class ACE_Coyote_Pack_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote.p3d";
	};
	class ACE_Coyote_Pack_Black_crate: ACE_Coyote_Pack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote_black.p3d";
	};
	class ACE_BackPack_ACR_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr.p3d";
	};
	class ACE_BackPack_ACR_FL_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_fl.p3d";
	};
	class ACE_BackPack_ACR_TT_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_tt.p3d";
	};
	class ACE_BackPack_ACR_DPM_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_dpm.p3d";
	};
	class ACE_BackPack_ACR_DDPM_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_ddpm.p3d";
	};
	class ACE_BackPack_ACR_MTP_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_mtp.p3d";
	};
	class ACE_BackPack_ACR_Small_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_small.p3d";
	};
	class ACE_ALICE_Backpack_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_alice_backpack.p3d";
	};
	class ACE_Backpack_US_crate: ACE_BackPack_ACR_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_us.p3d";
	};
	class ACE_Backpack_FL_crate: ACE_Backpack_US_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_fl.p3d";
	};
	class ACE_Backpack_TT_crate: ACE_Backpack_US_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_tt.p3d";
	};
	class ACE_Rucksack_EAST_Medic_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\np_ruck_green.p3d";
	};
	class ACE_P159_RD90_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_alice_backpack_p159.p3d";
		armor = 800;
	};
	class ACE_P159_RD54_crate: ACE_P159_RD90_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_alice_backpack_p159.p3d";
	};
	class ACE_P159_RD99_crate: ACE_P159_RD90_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_alice_backpack_p159.p3d";
	};
	class ACE_P168_RD90_crate: ACE_P159_RD90_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_alice_backpack_p159.p3d";
	};
	class ACE_Rucksack_RD90_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\np_ruck_green.p3d";
		armor = 800;
	};
	class ACE_Rucksack_RD91_crate: ACE_Rucksack_RD90_crate{};
	class ACE_Rucksack_RD92_crate: ACE_Rucksack_RD90_crate{};
	class ACE_Rucksack_RD54_crate: ACE_Rucksack_RD90_crate{};
	class ACE_Rucksack_RD99_crate: ACE_Rucksack_RD90_crate{};
	class ACE_Rucksack_EAST_crate: ACE_Rucksack_RD90_crate{};
	class ACE_BackPack_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\res_ruck.p3d";
	};
	class ACE_Combat_Pack_crate: ACE_Rucksack_crate
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_marpatSP_w.p3d";
	};
	class ACE_PRC119_MAR: ACE_PRC119_MAR_crate
	{
		scope = 1;
		armor = 800;
	};
	class ACE_PRC119_ACU: ACE_PRC119_ACU_crate
	{
		scope = 1;
	};
	class ReammoBox_EP1;
	class Bag_Base_EP1: ReammoBox_EP1
	{
		ACE_Weight = 2.0;
		class ACE;
	};
	class USBasicBag: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"USBasicBag","ACE_FAST_PackEDC_ACU"};
			};
		};
	};
	class US_Assault_Pack_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Assault_Pack_EP1","ACE_FAST_PackEDC_ACU"};
			};
		};
	};
	class US_Assault_Pack_Ammo_EP1: US_Assault_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Assault_Pack_Ammo_EP1","ACE_FAST_PackEDC_ACU"};
			};
		};
	};
	class US_Assault_Pack_AmmoSAW_EP1: US_Assault_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Assault_Pack_AmmoSAW_EP1","ACE_FAST_PackEDC_ACU"};
			};
		};
	};
	class US_Assault_Pack_AT_EP1: US_Assault_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Assault_Pack_AT_EP1","ACE_FAST_PackEDC_ACU"};
			};
		};
	};
	class US_Assault_Pack_Explosives_EP1: US_Assault_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Assault_Pack_Explosives_EP1","ACE_FAST_PackEDC_ACU"};
			};
		};
	};
	class US_Patrol_Pack_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Patrol_Pack_EP1","ACE_Coyote_Pack"};
			};
		};
	};
	class US_Patrol_Pack_Ammo_EP1: US_Patrol_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Patrol_Pack_Ammo_EP1","ACE_Coyote_Pack"};
			};
		};
	};
	class US_Patrol_Pack_Specops_EP1: US_Patrol_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Patrol_Pack_Specops_EP1","ACE_Coyote_Pack"};
			};
		};
	};
	class US_Backpack_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Backpack_EP1","ACE_Backpack_US"};
			};
		};
	};
	class US_Backpack_AmmoMG_EP1: US_Backpack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Backpack_AmmoMG_EP1","ACE_Backpack_US"};
			};
		};
	};
	class US_Backpack_AT_EP1: US_Backpack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Backpack_AT_EP1","ACE_Backpack_US"};
			};
		};
	};
	class US_Backpack_Specops_EP1: US_Backpack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"US_Backpack_Specops_EP1","ACE_Backpack_US"};
			};
		};
	};
	class DE_Backpack_Specops_EP1: US_Backpack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"DE_Backpack_Specops_EP1","ACE_Backpack_TT"};
			};
		};
	};
	class CZ_Backpack_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_Backpack_EP1","ACE_BackPack_ACR"};
			};
		};
	};
	class CZ_Backpack_Ammo_EP1: CZ_Backpack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_Backpack_Ammo_EP1","ACE_BackPack_ACR"};
			};
		};
	};
	class CZ_Backpack_Specops_EP1: CZ_Backpack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_Backpack_Specops_EP1","ACE_BackPack_ACR"};
			};
		};
	};
	class CZ_Backpack_AmmoMG_EP1: CZ_Backpack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_Backpack_AmmoMG_EP1","ACE_BackPack_ACR"};
			};
		};
	};
	class CZ_VestPouch_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_VestPouch_EP1","ACE_BackPack_ACR_Small"};
			};
		};
	};
	class CZ_VestPouch_Sa58_EP1: CZ_VestPouch_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_VestPouch_Sa58_EP1","ACE_BackPack_ACR_Small"};
			};
		};
	};
	class CZ_VestPouch_M4_EP1: CZ_VestPouch_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_VestPouch_M4_EP1","ACE_BackPack_ACR_Small"};
			};
		};
	};
	class TK_ALICE_Pack_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TK_ALICE_Pack_EP1","ACE_ALICE_Backpack"};
			};
		};
	};
	class TK_ALICE_Pack_Explosives_EP1: TK_ALICE_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TK_ALICE_Pack_Explosives_EP1","ACE_ALICE_Backpack"};
			};
		};
	};
	class TK_ALICE_Pack_AmmoMG_EP1: TK_ALICE_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TK_ALICE_Pack_AmmoMG_EP1","ACE_ALICE_Backpack"};
			};
		};
	};
	class TKA_ALICE_Pack_Ammo_EP1: TK_ALICE_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TKA_ALICE_Pack_Ammo_EP1","ACE_ALICE_Backpack"};
			};
		};
	};
	class TKG_ALICE_Pack_AmmoAK47_EP1: TK_ALICE_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TKG_ALICE_Pack_AmmoAK47_EP1","ACE_ALICE_Backpack"};
			};
		};
	};
	class TKG_ALICE_Pack_AmmoAK74_EP1: TK_ALICE_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TKG_ALICE_Pack_AmmoAK74_EP1","ACE_ALICE_Backpack"};
			};
		};
	};
	class TK_RPG_Backpack_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TK_RPG_Backpack_EP1","ACE_Backpack_RPG"};
			};
		};
	};
	class TK_Assault_Pack_EP1: Bag_Base_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TK_Assault_Pack_EP1","ACE_Backpack_CivAssault"};
			};
		};
	};
	class TK_Assault_Pack_RPK_EP1: TK_Assault_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TK_Assault_Pack_RPK_EP1","ACE_Backpack_CivAssault"};
			};
		};
	};
	class TKA_Assault_Pack_Ammo_EP1: TK_Assault_Pack_EP1
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"TKA_Assault_Pack_Ammo_EP1","ACE_Backpack_CivAssault"};
			};
		};
	};
	class Bag_Base_BAF: ReammoBox_EP1
	{
		class ACE;
	};
	class BAF_AssaultPack_RifleAmmo: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_RifleAmmo","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_ARAmmo: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_ARAmmo","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_MGAmmo: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_MGAmmo","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_ATAmmo: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_ATAmmo","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_HATAmmo: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_HATAmmo","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_Special: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_Special","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_FAC: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_FAC","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_HAAAmmo: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_HAAAmmo","ACE_AssaultPack_BAF"};
			};
		};
	};
	class BAF_AssaultPack_LRRAmmo: Bag_Base_BAF
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"BAF_AssaultPack_LRRAmmo","ACE_AssaultPack_BAF"};
			};
		};
	};
	class ReammoBox_ACR: ReammoBox{};
	class Bag_Base_ACR: ReammoBox_ACR
	{
		class ACE;
	};
	class CZ_Assault_Pack_ACR: Bag_Base_ACR{};
	class CZ_Assault_Pack_Explosives_ACR: CZ_Assault_Pack_ACR
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_Assault_Pack_Explosives_ACR","ACE_BackPack_ACR"};
			};
		};
	};
	class CZ_Assault_Pack_MG_ACR: CZ_Assault_Pack_ACR
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_Assault_Pack_Explosives_ACR","ACE_BackPack_ACR"};
			};
		};
	};
	class CZ_Backpack_RPG_ACR: Bag_Base_ACR
	{
		class ACE: ACE
		{
			class sys_ruck
			{
				convert[] = {"CZ_Backpack_RPG_ACR","ACE_Backpack_RPG"};
			};
		};
	};
};
class CfgAmmo
{
	class Default;
	class ACE_PackDummyAmmo: Default
	{
		hit = 0.001;
		indirectHit = 0.001;
		indirectHitRange = 0.01;
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class 6Rnd_45ACP: CA_Magazine
	{
		ACE_Size = 100;
	};
	class 10Rnd_B_765x17_Ball: CA_Magazine
	{
		ACE_Size = 120;
	};
	class 17Rnd_9x19_glock17: CA_Magazine
	{
		ACE_Size = 130;
	};
	class ACE_33Rnd_9x19_G18: 17Rnd_9x19_glock17
	{
		ACE_Size = 240;
	};
	class 20Rnd_B_765x17_Ball: 10Rnd_B_765x17_Ball
	{
		ACE_Size = 240;
	};
	class 20Rnd_762x51_DMR: CA_Magazine
	{
		ACE_Size = 400;
	};
	class 20Rnd_762x51_FNFAL: CA_Magazine
	{
		ACE_Size = 400;
	};
	class IR_Strobe_Target: CA_Magazine
	{
		ACE_Size = 210;
	};
	class IR_Strobe_Marker: IR_Strobe_Target{};
	class IRStrobe: IR_Strobe_Marker{};
	class 10x_303: CA_Magazine
	{
		ACE_Size = 120;
	};
	class 30Rnd_9x19_UZI: CA_Magazine
	{
		ACE_Size = 200;
	};
	class 30Rnd_9x19_UZI_SD: CA_Magazine
	{
		ACE_Size = 200;
	};
	class 30Rnd_762x39_SA58: CA_Magazine
	{
		ACE_Size = 550;
	};
	class 8Rnd_9x18_Makarov: CA_Magazine
	{
		ACE_Size = 70;
	};
	class 8Rnd_9x18_MakarovSD: 8Rnd_9x18_Makarov
	{
		ACE_Size = 70;
	};
	class 15Rnd_9x19_M9: CA_Magazine
	{
		ACE_Size = 150;
	};
	class 15Rnd_9x19_M9SD: 15Rnd_9x19_M9
	{
		ACE_Size = 150;
	};
	class 30Rnd_9x19_MP5SD: CA_Magazine
	{
		ACE_Size = 250;
	};
	class 30Rnd_9x19_MP5: CA_Magazine
	{
		ACE_Size = 250;
	};
	class 7Rnd_45ACP_1911: CA_Magazine
	{
		ACE_Size = 70;
	};
	class 30Rnd_545x39_AK: CA_Magazine
	{
		ACE_Size = 500;
	};
	class 30Rnd_545x39_AKSD: 30Rnd_545x39_AK
	{
		ACE_Size = 500;
	};
	class 75Rnd_545x39_RPK: CA_Magazine
	{
		ACE_Size = 750;
	};
	class 30Rnd_762x39_AK47: CA_Magazine
	{
		ACE_Size = 550;
	};
	class ACE_40Rnd_762x39_B_AK47: 30Rnd_762x39_AK47
	{
		ACE_Size = 750;
	};
	class ACE_40Rnd_762x39_T_AK47: 30Rnd_762x39_AK47
	{
		ACE_Size = 750;
	};
	class ACE_75Rnd_762x39_B_AK47: 30Rnd_762x39_AK47
	{
		ACE_Size = 1250;
	};
	class 20Rnd_556x45_Stanag: CA_Magazine
	{
		ACE_Size = 256;
	};
	class 30Rnd_556x45_Stanag: 20Rnd_556x45_Stanag
	{
		ACE_Size = 385;
	};
	class 30Rnd_556x45_StanagSD: 30Rnd_556x45_Stanag{};
	class 20Rnd_762x51_B_SCAR: CA_Magazine
	{
		ACE_Size = 500;
	};
	class 20Rnd_762x51_SB_SCAR: CA_Magazine
	{
		ACE_Size = 500;
	};
	class 30Rnd_556x45_G36: 30Rnd_556x45_Stanag{};
	class 30Rnd_556x45_G36SD: 30Rnd_556x45_G36{};
	class 200Rnd_556x45_M249: CA_Magazine
	{
		ACE_Size = 2050;
	};
	class 100Rnd_556x45_M249: 200Rnd_556x45_M249
	{
		ACE_Size = 1120;
	};
	class 100Rnd_556x45_BetaCMag: CA_Magazine
	{
		ACE_Size = 1250;
	};
	class 5Rnd_762x51_M24: CA_Magazine
	{
		ACE_Size = 50;
	};
	class 100Rnd_762x51_M240: CA_Magazine
	{
		ACE_Size = 3233;
	};
	class 10Rnd_762x54_SVD: CA_Magazine
	{
		ACE_Size = 250;
	};
	class 100Rnd_762x54_PK: CA_Magazine
	{
		ACE_Size = 2500;
	};
	class 60Rnd_762x54_DT: 100Rnd_762x54_PK
	{
		ACE_Size = 1200;
	};
	class 64Rnd_9x19_Bizon: CA_Magazine
	{
		ACE_Size = 750;
	};
	class 64Rnd_9x19_SD_Bizon: CA_Magazine
	{
		ACE_Size = 750;
	};
	class 10Rnd_9x39_SP5_VSS: CA_Magazine
	{
		ACE_Size = 250;
	};
	class 20Rnd_9x39_SP5_VSS: CA_Magazine
	{
		ACE_Size = 500;
	};
	class 8Rnd_B_Saiga12_74Slug: CA_Magazine
	{
		ACE_Size = 750;
	};
	class 8Rnd_B_Beneli_74Slug: CA_Magazine
	{
		ACE_Size = 750;
	};
	class 5Rnd_127x108_KSVK: CA_Magazine
	{
		ACE_Size = 750;
	};
	class 10Rnd_127x99_m107: CA_Magazine
	{
		ACE_Size = 1250;
	};
	class 5Rnd_86x70_L115A1: CA_Magazine
	{
		ACE_Size = 200;
	};
	class 5Rnd_127x99_as50: CA_Magazine
	{
		ACE_Size = 1250;
	};
	class 10Rnd_762x51_CZ750: 5Rnd_762x51_M24
	{
		ACE_Size = 250;
	};
	class 1Rnd_HE_M203: CA_Magazine
	{
		ACE_Size = 160;
	};
	class 6Rnd_HE_M203: 1Rnd_HE_M203
	{
		ACE_Size = 960;
	};
	class FlareWhite_M203: CA_Magazine
	{
		ACE_Size = 225;
	};
	class 6Rnd_FlareWhite_M203: FlareWhite_M203
	{
		ACE_Size = 1050;
	};
	class FlareGreen_M203: FlareWhite_M203{};
	class 6Rnd_FlareGreen_M203: FlareGreen_M203
	{
		ACE_Size = 1050;
	};
	class FlareRed_M203: FlareWhite_M203{};
	class 6Rnd_FlareRed_M203: FlareRed_M203
	{
		ACE_Size = 1050;
	};
	class FlareYellow_M203: FlareWhite_M203{};
	class 6Rnd_FlareYellow_M203: FlareYellow_M203
	{
		ACE_Size = 1050;
	};
	class 1Rnd_Smoke_M203: 1Rnd_HE_M203
	{
		ACE_Size = 160;
	};
	class 6Rnd_Smoke_M203: 1Rnd_Smoke_M203
	{
		ACE_Size = 1050;
	};
	class 1Rnd_SmokeRed_M203: 1Rnd_Smoke_M203{};
	class 6Rnd_SmokeRed_M203: 1Rnd_SmokeRed_M203
	{
		ACE_Size = 1050;
	};
	class 1Rnd_SmokeGreen_M203: 1Rnd_Smoke_M203{};
	class 6Rnd_SmokeGreen_M203: 1Rnd_SmokeGreen_M203
	{
		ACE_Size = 1050;
	};
	class 1Rnd_SmokeYellow_M203: 1Rnd_Smoke_M203{};
	class 6Rnd_SmokeYellow_M203: 1Rnd_SmokeYellow_M203
	{
		ACE_Size = 1050;
	};
	class 1Rnd_HE_GP25: CA_Magazine
	{
		ACE_Size = 175;
	};
	class FlareWhite_GP25: CA_Magazine
	{
		ACE_Size = 225;
	};
	class FlareGreen_GP25: FlareWhite_GP25{};
	class FlareRed_GP25: FlareWhite_GP25{};
	class FlareYellow_GP25: FlareWhite_GP25{};
	class 1Rnd_SMOKE_GP25: 1Rnd_HE_GP25
	{
		ACE_Size = 175;
	};
	class 1Rnd_SmokeRed_GP25: 1Rnd_SMOKE_GP25{};
	class 1Rnd_SmokeGreen_GP25: 1Rnd_SMOKE_GP25{};
	class CA_LauncherMagazine: CA_Magazine{};
	class M136: CA_LauncherMagazine
	{
		ACE_Size = 8000;
	};
	class Javelin: CA_LauncherMagazine
	{
		ACE_Size = 20000;
	};
	class AT13: CA_LauncherMagazine
	{
		ACE_Size = 13000;
	};
	class PG7V: CA_LauncherMagazine
	{
		ACE_Size = 5000;
	};
	class PG7VL: PG7V
	{
		ACE_Size = 6657;
	};
	class PG7VR: PG7V
	{
		ACE_Size = 11308;
	};
	class OG7: CA_LauncherMagazine
	{
		ACE_Size = 1432;
	};
	class OG9_HE: CA_LauncherMagazine
	{
		ACE_Size = 4183;
	};
	class PG9_AT: CA_LauncherMagazine
	{
		ACE_Size = 4183;
	};
	class Stinger: CA_LauncherMagazine
	{
		ACE_Size = 20000;
	};
	class Strela: CA_LauncherMagazine
	{
		ACE_Size = 20000;
	};
	class RPG18: CA_LauncherMagazine
	{
		ACE_Size = 3000;
	};
	class SMAW_HEDP: CA_LauncherMagazine
	{
		ACE_Size = 8000;
	};
	class SMAW_HEAA: SMAW_HEDP
	{
		ACE_Size = 8000;
	};
	class Igla: Strela
	{
		ACE_Size = 20000;
	};
	class Dragon_EP1: CA_LauncherMagazine
	{
		ACE_Size = 13000;
	};
	class MAAWS_HEDP: CA_LauncherMagazine
	{
		ACE_Size = 8000;
	};
	class MAAWS_HEAT: MAAWS_HEDP{};
	class NLAW: CA_LauncherMagazine
	{
		ACE_Size = 13000;
	};
	class TimeBomb: CA_Magazine
	{
		ACE_Size = 540;
	};
	class Mine: TimeBomb
	{
		ACE_Size = 11087;
	};
	class MineE: TimeBomb
	{
		ACE_Size = 7890;
	};
	class PipeBomb: TimeBomb{};
	class HandGrenade: CA_Magazine
	{
		ACE_Size = 410;
	};
	class HandGrenade_West: HandGrenade
	{
		ACE_Size = 368;
	};
	class SmokeShell: HandGrenade
	{
		ACE_Size = 409;
	};
	class SmokeShellGreen: SmokeShell
	{
		ACE_Size = 409;
	};
	class SmokeShellRed: SmokeShell
	{
		ACE_Size = 409;
	};
	class SmokeShellYellow: SmokeShell
	{
		ACE_Size = 409;
	};
	class SmokeShellPurple: SmokeShell
	{
		ACE_Size = 409;
	};
	class SmokeShellBlue: SmokeShell
	{
		ACE_Size = 409;
	};
	class SmokeShellOrange: SmokeShell
	{
		ACE_Size = 409;
	};
};
class CfgWeapons
{
	class RifleCore;
	class LauncherCore;
	class PistolCore;
	class Default;
	class Rifle: RifleCore
	{
		ACE_Size = 9000;
	};
	class M16_Base: Rifle
	{
		ACE_Size = 8500;
	};
	class LeeEnfield: Rifle
	{
		ACE_Size = 9000;
	};
	class M14_EP1: Rifle
	{
		ACE_Size = 9000;
	};
	class M110_TWS_EP1: Rifle
	{
		ACE_Size = 11500;
		ACE_NoPack = 1;
	};
	class GrenadeLauncher_EP1: Rifle
	{
		ACE_Size = 12500;
		ACE_NoPack = 1;
	};
	class M79_EP1: GrenadeLauncher_EP1
	{
		ACE_Size = 9000;
		ACE_NoPack = 0;
	};
	class Mk13_EP1: GrenadeLauncher_EP1
	{
		ACE_Size = 9000;
		ACE_NoPack = 0;
	};
	class M32_EP1: GrenadeLauncher_EP1
	{
		ACE_Size = 9000;
		ACE_NoPack = 1;
	};
	class M60A4_EP1: Rifle
	{
		ACE_Size = 10080;
		ACE_NoPack = 1;
	};
	class Sa58P_EP1: Rifle
	{
		ACE_Size = 8500;
	};
	class SCAR_Base: M16_Base
	{
		ACE_Size = 11000;
	};
	class M16A2: M16_base
	{
		ACE_Size = 8500;
	};
	class M16A2GL: M16A2
	{
		ACE_Size = 8500;
	};
	class m16a4: M16A2
	{
		ACE_Size = 8500;
	};
	class m16a4_acg: m16a4
	{
		ACE_Size = 8500;
	};
	class M16A4_GL: m16a4
	{
		ACE_Size = 8500;
	};
	class M16A4_ACG_GL: M16A4_GL
	{
		ACE_Size = 8500;
	};
	class FN_FAL: M16A2
	{
		ACE_Size = 9000;
	};
	class M24: Rifle
	{
		ACE_Size = 10900;
	};
	class M40A3: M24
	{
		ACE_Size = 10900;
	};
	class M240: Rifle
	{
		ACE_Size = 10080;
		ACE_NoPack = 1;
	};
	class Mk_48: M240
	{
		ACE_Size = 10080;
	};
	class M249: Rifle
	{
		ACE_Size = 10080;
	};
	class M4A1: M16_base
	{
		ACE_Size = 7140;
	};
	class M4A1_Aim: M4A1
	{
		ACE_Size = 7140;
	};
	class M4A1_Aim_camo: M4A1_Aim
	{
		ACE_Size = 7140;
	};
	class M4SPR: M4A1
	{
		ACE_Size = 7140;
	};
	class M4A1_RCO_GL: M4A1
	{
		ACE_Size = 7140;
	};
	class M4A1_AIM_SD_camo: M4A1_Aim
	{
		ACE_Size = 7565;
	};
	class M4A1_HWS_GL_SD_Camo: M4A1_AIM_SD_camo
	{
		ACE_Size = 7565;
	};
	class M4A1_HWS_GL: M4A1_RCO_GL
	{
		ACE_Size = 7140;
	};
	class M4A1_HWS_GL_camo: M4A1_HWS_GL
	{
		ACE_Size = 7140;
	};
	class MP5SD: Rifle
	{
		ACE_Size = "66*23*6.7";
	};
	class MP5A5: MP5SD
	{
		ACE_Size = "55*23*6.7";
	};
	class PK: Rifle
	{
		ACE_Size = 19200;
		ACE_NoPack = 1;
	};
	class Pecheneg: PK
	{
		ACE_Size = 19200;
	};
	class SVD: Rifle
	{
		ACE_Size = 12300;
	};
	class SVD_CAMO: SVD
	{
		ACE_Size = 12300;
	};
	class G36C: Rifle
	{
		ACE_Size = 6480;
	};
	class G36_C_SD_eotech: G36C
	{
		ACE_Size = 6600;
	};
	class G36a: Rifle
	{
		ACE_Size = 9000;
	};
	class G36K: G36a
	{
		ACE_Size = 9000;
	};
	class MG36: G36C
	{
		ACE_Size = 9200;
	};
	class AK_BASE: Rifle
	{
		ACE_Size = 6525;
	};
	class AKS_BASE: AK_BASE
	{
		ACE_Size = 6525;
	};
	class AK_107_BASE: AK_BASE
	{
		ACE_Size = 6525;
	};
	class AK_47_M: AK_BASE
	{
		ACE_Size = 6525;
	};
	class AK_47_S: AK_47_M
	{
		ACE_Size = 6525;
	};
	class AKS_GOLD: AK_47_S
	{
		ACE_Size = 6525;
	};
	class AK_74: AK_BASE
	{
		ACE_Size = 6525;
	};
	class AK_74_GL: AK_BASE
	{
		ACE_Size = 6525;
	};
	class AK_107_kobra: AK_107_BASE
	{
		ACE_Size = 6525;
	};
	class AK_107_GL_kobra: AK_107_BASE
	{
		ACE_Size = 6525;
	};
	class AK_107_GL_pso: AK_107_GL_kobra
	{
		ACE_Size = 6525;
	};
	class AK_107_pso: AK_107_BASE
	{
		ACE_Size = 6525;
	};
	class AKS_74_kobra: AKS_BASE
	{
		ACE_Size = 6525;
	};
	class AKS_74_pso: AKS_BASE
	{
		ACE_Size = 6525;
	};
	class AKS_74_U: AKS_BASE
	{
		ACE_Size = 6525;
	};
	class AKS_74_UN_kobra: AKS_BASE
	{
		ACE_Size = 6525;
	};
	class RPK_74: AK_74
	{
		ACE_Size = 7950;
	};
	class bizon: Rifle
	{
		ACE_Size = 4950;
	};
	class bizon_silenced: bizon
	{
		ACE_Size = 5325;
	};
	class Pistol: PistolCore
	{
		ACE_Size = 900;
	};
	class M9: Pistol
	{
		ACE_Size = "21.7 * 13.7 * 3.8";
	};
	class M9SD: M9
	{
		ACE_Size = "(21.7 *13.7 * 3.8) + (3.1416 * 1.59 * 1.59 * 17.78)";
	};
	class Makarov: Pistol
	{
		ACE_Size = "16.1 * 12.675 * 3.05";
	};
	class MakarovSD: Makarov
	{
		ACE_Size = "31 * 12.675 * 3.05";
	};
	class Colt1911: M9
	{
		ACE_Size = "21.59 * 13.97 * 3.175";
	};
	class glock17_EP1: Pistol
	{
		ACE_Size = "18.6 * 13.8 * 3";
	};
	class revolver_EP1: Pistol
	{
		ACE_Size = 1200;
	};
	class Sa61_EP1: Pistol
	{
		ACE_Size = "27 * 15.2 * 4.3";
	};
	class UZI_EP1: Pistol
	{
		ACE_Size = 2000;
	};
	class UZI_SD_EP1: UZI_EP1
	{
		ACE_Size = 2300;
	};
	class DMR: Rifle
	{
		ACE_Size = 8500;
	};
	class ksvk: Rifle
	{
		ACE_Size = 14000;
		ACE_NoPack = 1;
	};
	class M1014: Rifle
	{
		ACE_Size = 6645;
	};
	class m107: Rifle
	{
		ACE_Size = 14500;
		ACE_NoPack = 1;
	};
	class VSS_vintorez: Rifle
	{
		ACE_Size = 8940;
	};
	class m8_base: Rifle
	{
		ACE_Size = 8380;
	};
	class m8_carbine: m8_base
	{
		ACE_Size = 8380;
	};
	class m8_carbineGL: m8_base
	{
		ACE_Size = 8380;
	};
	class m8_compact: m8_base
	{
		ACE_Size = 7610;
	};
	class m8_sharpshooter: m8_base
	{
		ACE_Size = 10280;
	};
	class m8_SAW: m8_sharpshooter
	{
		ACE_Size = 10280;
	};
	class huntingrifle: M24
	{
		ACE_Size = 10900;
	};
	class L85A2_base_BAF: Rifle
	{
		ACE_Size = 8500;
	};
	class BAF_L86A2_ACOG: Rifle
	{
		ACE_Size = 9000;
	};
	class BAF_L110A1_Aim: Rifle
	{
		ACE_Size = 10080;
	};
	class BAF_LRR_scoped: Rifle
	{
		ACE_Size = 10900;
	};
	class BAF_AS50_scoped: Rifle
	{
		ACE_Size = 9000;
		ACE_NoPack = 1;
	};
	class UK59_ACR: Rifle
	{
		ACE_Size = 20200;
		ACE_NoPack = 1;
	};
	class CZ_750_S1_ACR: M40A3
	{
		ACE_Size = 11800;
	};
	class Evo_ACR: MP5A5
	{
		ACE_Size = 9130;
	};
	class evo_sd_ACR: MP5SD
	{
		ACE_Size = 9180;
	};
	class CZ_75_P_07_DUTY: M9
	{
		ACE_Size = "18.5*13*3.7";
	};
	class CZ_75_D_COMPACT: M9
	{
		ACE_Size = "18.4*12.8*3.5";
	};
	class CZ_75_SP_01_PHANTOM: M9
	{
		ACE_Size = "21*15*3.8";
	};
	class CZ_75_SP_01_PHANTOM_SD: M9SD
	{
		ACE_Size = "21*15*3.8 + 50";
	};
	class CZ805_A1_ACR: Rifle
	{
		ACE_Size = "67*7.7*26";
	};
	class CZ805_A2_ACR: CZ805_A1_ACR
	{
		ACE_Size = "58.7*7.7*26";
	};
	class Launcher: LauncherCore
	{
		ACE_Size = 8000;
	};
	class M136: Launcher
	{
		ACE_Size = 7170;
	};
	class RPG18: Launcher
	{
		ACE_Size = 2890;
	};
	class SMAW: Launcher
	{
		ACE_Size = 5300;
	};
	class Javelin: Launcher
	{
		ACE_Size = 24200;
		ACE_NoPack = 1;
	};
	class M47Launcher_EP1: Launcher
	{
		ACE_Size = 18200;
		ACE_NoPack = 1;
	};
	class MAAWS: Launcher
	{
		ACE_Size = 14000;
		ACE_NoPack = 1;
	};
	class MetisLauncher: Launcher
	{
		ACE_Size = 25000;
		ACE_NoPack = 1;
	};
	class Stinger: Launcher
	{
		ACE_Size = 29400;
		ACE_NoPack = 1;
	};
	class AT13: Launcher
	{
		ACE_Size = 13020;
		ACE_NoPack = 1;
	};
	class RPG7V: Launcher
	{
		ACE_Size = 6900;
	};
	class Strela: Launcher
	{
		ACE_Size = 7500;
		ACE_NoPack = 1;
	};
	class Igla: Strela
	{
		ACE_Size = 8190;
		ACE_NoPack = 1;
	};
	class BAF_NLAW_Launcher: Launcher
	{
		ACE_Size = 18000;
		ACE_NoPack = 1;
	};
	class Binocular: Default
	{
		ACE_Size = 1600;
	};
	class NVGoggles: Binocular
	{
		ACE_Size = 800;
	};
	class Laserdesignator: Binocular
	{
		ACE_Size = 6557;
	};
	class ItemCore: Default
	{
		ACE_Size = 100;
	};
	class Kostey_photos: ItemCore
	{
		ACE_Size = 5;
	};
	class Kostey_map_case: ItemCore
	{
		ACE_Size = 10;
	};
	class Kostey_notebook: ItemCore
	{
		ACE_Size = 300;
	};
	class CDF_dogtags: ItemCore
	{
		ACE_Size = 5;
	};
	class Moscow_Bombing_File: ItemCore
	{
		ACE_Size = 5;
	};
	class Cobalt_File: ItemCore
	{
		ACE_Size = 5;
	};
	class ItemCompass: ItemCore
	{
		ACE_Size = 25;
	};
	class ItemGPS: ItemCore
	{
		ACE_Size = 80;
	};
	class ItemRadio: ItemCore
	{
		ACE_Size = 400;
	};
	class ItemMap: ItemCore
	{
		ACE_Size = 5;
	};
	class EvPhoto: ItemCore
	{
		ACE_Size = 75;
	};
	class EvMap: ItemCore
	{
		ACE_Size = 2;
	};
	class EvMoscow: ItemCore
	{
		ACE_Size = 5;
	};
	class EvKobalt: ItemCore
	{
		ACE_Size = 5;
	};
	class EvMoney: ItemCore
	{
		ACE_Size = 5;
	};
	class EvDogTags: ItemCore
	{
		ACE_Size = 5;
	};
	class ACE_Rucksack: Launcher
	{
		ACE_PackSize = 20000;
		ACE_Size = 20001;
		ACE_Weight = 1.15;
		ACE_NoPack = 1;
		scope = 1;
		displayName = "$STR_DN_ACE_RUCKSACK";
		nameSound = "weapon";
		picture = "";
		icon = "\ca\weapons_e\data\icons\mapIcon_backpack_CA.paa";
		mapsize = 1.8;
		simulation = "ProxyWeapon";
		modelOptics = "";
		model = "\x\ace\addons\sys_ruck\backpack_data\np_ruck_green.p3d";
		autoReload = 1;
		backgroundReload = 0;
		magazineReloadTime = 0;
		reloadSound[] = {1,1};
		reloadMagazineSound[] = {1,1};
		reloadTime = 0;
		canLock = 0;
		enableAttack = 0;
		valueWeapon = 20;
		optics = 0;
		uiPicture = "";
		ffMagnitude = 0;
		ffFrequency = 0;
		ffCount = 0;
		primary = 1;
		showEmpty = 0;
		dispersion = 0.0009;
		minRange = 0.1;
		minRangeProbab = 0.1;
		midRange = 1;
		midRangeProbab = 0.1;
		maxRange = 2;
		maxRangeProbab = 0.1;
		magazines[] = {};
		class Library
		{
			libTextDesc = "$STR_LIB_ACE_RUCKSACK";
		};
		descriptionShort = "$STR_LIB_ACE_RUCKSACK";
	};
	class ACE_Rucksack_MOLLE_Green: ACE_Rucksack
	{
		scope = 2;
		displayName = "MOLLE Assault";
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_green.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_g_ca.paa";
		descriptionShort = "Green";
		ACE_PackSize = 20250;
		ACE_Size = 20251;
		ACE_Weight = 1.15;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Rucksack_MOLLE_Brown: ACE_Rucksack_MOLLE_Green
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\res_ruck_brown.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_b_ca.paa";
		descriptionShort = "Brown";
	};
	class ACE_Rucksack_MOLLE_Wood: ACE_Rucksack_MOLLE_Green
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_wood.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_w_ca.paa";
		descriptionShort = "Woodland";
	};
	class ACE_Rucksack_MOLLE_ACU: ACE_Rucksack_MOLLE_Green
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_acu.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_a_ca.paa";
		descriptionShort = "ACU";
	};
	class ACE_Rucksack_MOLLE_WMARPAT: ACE_Rucksack_MOLLE_Green
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_marpat_w.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_mw_ca.paa";
		descriptionShort = "Marpat W";
	};
	class ACE_Rucksack_MOLLE_DMARPAT: ACE_Rucksack_MOLLE_Green
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_marpat_d.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_md_ca.paa";
		descriptionShort = "Marpat D";
	};
	class ACE_Rucksack_MOLLE_Green_Medic: ACE_Rucksack_MOLLE_Green
	{
		ACE_Size = 15179;
		ACE_PackSize = 15178;
		displayName = "MOLLE Medic";
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_medic_g_ca.paa";
		descriptionShort = "Green";
	};
	class ACE_Rucksack_MOLLE_Brown_Medic: ACE_Rucksack_MOLLE_Green_Medic
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\res_ruck_medic.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_medic_b_ca.paa";
		descriptionShort = "Brown";
	};
	class ACE_Rucksack_MOLLE_ACU_Medic: ACE_Rucksack_MOLLE_Green_Medic
	{
		displayName = "MOLLE Medic";
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic_acu.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_medic_a_ca.paa";
		descriptionShort = "ACU";
	};
	class ACE_Rucksack_MOLLE_WMARPAT_Medic: ACE_Rucksack_MOLLE_Green_Medic
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic_marpat_w.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_medic_mw_ca.paa";
		descriptionShort = "Marpat W";
	};
	class ACE_Rucksack_MOLLE_DMARPAT_Medic: ACE_Rucksack_MOLLE_Green_Medic
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_medic_marpat_d.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_medic_md_ca.paa";
		descriptionShort = "Marpat D";
	};
	class ACE_ANPRC77: ACE_Rucksack_MOLLE_Green
	{
		displayName = "AN/PRC-77";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote_prc77.p3d";
		picture = "\ca\weapons_e\data\icons\backpack_us_assault_coyote_ca.paa";
		descriptionShort = "AN/PRC-77 | Brown";
		ACE_PackSize = 2000;
		ACE_Size = 2001;
		ACE_Weight = 6.2;
		ACE_is_radio = 1;
	};
	class ACE_VTAC_RUSH72: ACE_Rucksack
	{
		scope = 2;
		displayName = "VTAC RUSH 72";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_black.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_rush_ca.paa";
		descriptionShort = "Black";
		ACE_PackSize = 46304;
		ACE_Size = 46305;
		ACE_Weight = 1.15;
	};
	class ACE_VTAC_RUSH72_ACU: ACE_VTAC_RUSH72
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_acu.p3d";
		descriptionShort = "ACU";
	};
	class ACE_VTAC_RUSH72_OD: ACE_VTAC_RUSH72
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_olive.p3d";
		descriptionShort = "Olive Drab";
	};
	class ACE_VTAC_RUSH72_TT_MEDIC: ACE_VTAC_RUSH72
	{
		displayName = "VTAC RUSH 72 Medic";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_tropentarn_medic.p3d";
		descriptionShort = "Flecktarn Tropen";
		ACE_PackSize = 34728;
		ACE_Size = 34729;
	};
	class ACE_VTAC_RUSH72_FT_MEDIC: ACE_VTAC_RUSH72_TT_MEDIC
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_vtac_rush_flecktarn_medic.p3d";
		descriptionShort = "Flecktarn";
	};
	class ACE_CharliePack: ACE_Rucksack
	{
		scope = 2;
		displayName = "Arc Teryx Charlie";
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_green.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_charlie_ca.paa";
		descriptionShort = "Green";
		ACE_Weight = 1;
		ACE_PackSize = 26400;
		ACE_Size = 26401;
	};
	class ACE_CharliePack_WMARPAT: ACE_CharliePack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_wmarpat.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_charlie_wm_ca.paa";
		descriptionShort = "Marpat W";
	};
	class ACE_CharliePack_ACU: ACE_CharliePack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_acu.p3d";
		descriptionShort = "ACU";
	};
	class ACE_CharliePack_FLORA: ACE_CharliePack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_flora.p3d";
		descriptionShort = "Flora";
	};
	class ACE_CharliePack_Multicam: ACE_CharliePack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_multicam.p3d";
		descriptionShort = "Multicam";
	};
	class ACE_CharliePack_ACU_Medic: ACE_CharliePack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_acu_medic.p3d";
		displayName = "Arc Teryx Charlie Medic";
		descriptionShort = "ACU";
		ACE_PackSize = 19800;
		ACE_Size = 19801;
	};
	class ACE_PRC119: ACE_CharliePack
	{
		displayName = "PRC-119";
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_green_prc119.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_charlie_radio_ca.paa";
		descriptionShort = "AN/PRC-119 SINCGARS (ASIP) | Green";
		ACE_PackSize = 12630;
		ACE_Size = 12631;
		ACE_Weight = 5;
		ACE_is_radio = 1;
	};
	class ACE_PRC119_MAR: ACE_PRC119
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_wmarpat_prc119.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_charlie_wm_radio_ca.paa";
		descriptionShort = "AN/PRC-119 SINCGARS (ASIP) | Marpat W";
	};
	class ACE_PRC119_ACU: ACE_PRC119
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\charliepack_acu_prc119.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_charlie_acu_radio_ca.paa";
		descriptionShort = "AN/PRC-119 SINCGARS (ASIP) | ACU";
	};
	class ACE_FAST_PackEDC: ACE_Rucksack
	{
		scope = 2;
		displayName = "F.A.S.T. Pack EDC v3";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_fastpack.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_fastpack_ca.paa";
		descriptionShort = "Brown";
		ACE_Weight = 2.04;
		ACE_PackSize = 28800;
		ACE_Size = 28801;
	};
	class ACE_FAST_PackEDC_ACU: ACE_FAST_PackEDC
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_fastpack_acu.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_fastpack_ca.paa";
		descriptionShort = "ACU";
	};
	class ACE_Coyote_Pack: ACE_Rucksack
	{
		scope = 2;
		displayName = "Coyote Pack";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote.p3d";
		picture = "\ca\weapons_e\data\icons\backpack_us_assault_coyote_ca.paa";
		descriptionShort = "Brown";
		ACE_Weight = 2.04;
		ACE_PackSize = 28800;
		ACE_Size = 28801;
	};
	class ACE_Coyote_Pack_Black: ACE_Coyote_Pack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote_black.p3d";
		descriptionShort = "Black";
	};
	class ACE_Coyote_Pack_Wood: ACE_Coyote_Pack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote_woodland.p3d";
		descriptionShort = "Woodland";
	};
	class ACE_Coyote_Pack_Multicam: ACE_Coyote_Pack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote_multicam.p3d";
		descriptionShort = "Multicam";
	};
	class ACE_Coyote_Pack_Flora: ACE_Coyote_Pack
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_coyote_flora.p3d";
		descriptionShort = "Flora";
	};
	class ACE_BackPack_ACR: ACE_Rucksack
	{
		scope = 2;
		displayName = "ACR Backpack";
		picture = "\ca\weapons_e\data\icons\backpack_ACR_CA.paa";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr.p3d";
		ACE_Weight = 3;
		ACE_PackSize = 38800;
		ACE_Size = 38801;
		descriptionShort = "Woodland";
	};
	class ACE_BackPack_ACR_FL: ACE_BackPack_ACR
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_fl.p3d";
		descriptionShort = "Flecktarn";
	};
	class ACE_BackPack_ACR_TT: ACE_BackPack_ACR_FL
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_tt.p3d";
		descriptionShort = "Flecktarn Tropen";
	};
	class ACE_BackPack_ACR_DPM: ACE_BackPack_ACR
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_dpm.p3d";
		descriptionShort = "DPM";
	};
	class ACE_BackPack_ACR_DDPM: ACE_BackPack_ACR_DPM
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_ddpm.p3d";
		descriptionShort = "DDPM";
	};
	class ACE_BackPack_ACR_MTP: ACE_BackPack_ACR_DPM
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_mtp.p3d";
		descriptionShort = "MTP";
	};
	class ACE_AssaultPack_BAF: ACE_Rucksack
	{
		scope = 2;
		displayName = "$STR_BAF_BAG_BASE_BAF0";
		picture = "\ca\weapons_baf\data\UI\backpack_BAF_CA.paa";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_Backpack_Small_BAF.p3d";
		ACE_Weight = 1.6;
		ACE_PackSize = 42600;
		ACE_Size = 42601;
		descriptionShort = "Brown";
	};
	class ACE_BackPack_ACR_Small: ACE_BackPack_ACR
	{
		displayName = "ACR Bag";
		picture = "\ca\weapons_e\data\icons\backpack_ACR_small_CA.paa";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acr_small.p3d";
		ACE_Weight = 1;
		ACE_PackSize = 8800;
		ACE_Size = 8801;
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_ALICE_Backpack: ACE_BackPack_ACR
	{
		displayName = "ALICE Pack";
		picture = "\ca\weapons_e\data\icons\backpack_TK_ALICE_CA.paa";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_alice_backpack.p3d";
		ACE_Weight = 1.5;
		ACE_PackSize = 18800;
		ACE_Size = 18801;
		descriptionShort = "Brown";
	};
	class ACE_Backpack_CivAssault: ACE_ALICE_Backpack
	{
		displayName = "Assault Pack";
		picture = "\ca\weapons_e\data\icons\backpack_CIVIL_ASSAULT_CA.paa";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_civil_assault.p3d";
		descriptionShort = "Woodland";
	};
	class ACE_Backpack_RPG: ACE_BackPack_ACR
	{
		displayName = "$STR_EP1_DN_TK_RPG_Backpack_EP1";
		picture = "\ca\weapons_e\data\icons\backpack_RPG_CA.paa";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_rpg.p3d";
		ACE_Weight = 1;
		ACE_PackSize = 40000;
		ACE_Size = 40001;
		descriptionShort = "";
	};
	class ACE_Backpack_US: ACE_BackPack_ACR
	{
		displayName = "Backpack";
		picture = "\ca\weapons_e\data\icons\backpack_US_CA.paa";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_us.p3d";
		ACE_Weight = 1.5;
		ACE_PackSize = 18800;
		ACE_Size = 18801;
		descriptionShort = "Brown";
	};
	class ACE_Backpack_FL: ACE_Backpack_US
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_fl.p3d";
		descriptionShort = "Flecktarn";
	};
	class ACE_Backpack_TT: ACE_Backpack_FL
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_tt.p3d";
		descriptionShort = "Flecktarn Tropen";
	};
	class ACE_Backpack_ACU: ACE_Backpack_FL
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_acu.p3d";
		descriptionShort = "ACU";
	};
	class ACE_Backpack_Olive: ACE_Backpack_FL
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_olive.p3d";
		descriptionShort = "Olive Drab";
	};
	class ACE_Backpack_Wood: ACE_Backpack_FL
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_woodland.p3d";
		descriptionShort = "Woodland";
	};
	class ACE_Backpack_Multicam: ACE_Backpack_FL
	{
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_backpack_multicam.p3d";
		descriptionShort = "Multicam";
	};
	class ACE_Rucksack_EAST_Medic: ACE_Rucksack
	{
		displayName = "Medic Bag";
		model = "\x\ace\addons\sys_ruck\backpack_data\np_ruck_green.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_medic_gg_ca.paa";
		ACE_PackSize = 10000;
		ACE_Size = 10001;
		scope = 2;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_P159_RD90: ACE_Rucksack
	{
		scope = 2;
		displayName = "P159 VHF Radio (RD90)";
		model = "\x\ace\addons\sys_ruck\backpack_data\ace_alice_backpack_p159.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\ANPRC77inv.paa";
		ACE_PackSize = 4000;
		ACE_Size = 4001;
		ACE_Weight = 10.7;
		ACE_is_radio = 1;
	};
	class ACE_P159_RD54: ACE_P159_RD90
	{
		displayName = "P159 VHF Radio (RD54)";
	};
	class ACE_P159_RD99: ACE_P159_RD90
	{
		displayName = "P159 VHF Radio (RD99)";
	};
	class ACE_P168_RD90: ACE_P159_RD90
	{
		displayName = "P168 VHF Radio (RD90)";
		ACE_PackSize = 2300;
		ACE_Size = 2301;
		ACE_Weight = 6.5;
	};
	class ACE_Rucksack_RD90: ACE_Rucksack
	{
		scope = 2;
		displayName = "RD90";
		model = "\x\ace\addons\sys_ruck\backpack_data\np_ruck_green.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_gg_ca.paa";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Rucksack_RD91: ACE_Rucksack_RD90
	{
		displayName = "RD91";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Rucksack_RD92: ACE_Rucksack_RD90
	{
		displayName = "RD92";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Rucksack_RD54: ACE_Rucksack_RD90
	{
		displayName = "RD54";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Rucksack_RD99: ACE_Rucksack_RD90
	{
		displayName = "RD99";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Rucksack_EAST: ACE_Rucksack_RD90
	{
		displayName = "Rucksack Green";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_BackPack: ACE_Rucksack
	{
		scope = 2;
		displayName = "Rucksack";
		model = "\x\ace\addons\sys_ruck\backpack_data\res_ruck.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_b_ca.paa";
		descriptionShort = "";
	};
	class ACE_Combat_Pack: ACE_Rucksack
	{
		scope = 2;
		displayName = "Square Pack";
		model = "\x\ace\addons\sys_ruck\backpack_data\us_ruck_marpatSP_w.p3d";
		picture = "\x\ace\addons\sys_ruck\data\equip\w_molle_b_ca.paa";
		descriptionShort = "";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_ruck
	{
		init = "call ('\x\ace\addons\sys_ruck\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_ruck\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_ruck
	{
		init = "call ('\x\ace\addons\sys_ruck\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class CAManBase
	{
		class ace_sys_ruck
		{
			init = "_this call ace_sys_ruck_fnc_eh_init_from_config; _this call ace_sys_ruck_fnc_initConvert";
		};
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		ace_sys_ruck = "_this call ace_sys_ruck_fnc_killedEH";
	};
};
class Extended_Respawn_EventHandlers
{
	class CAManBase
	{
		ace_sys_ruck = "_this call ace_sys_ruck_fnc_respawnEH; if (isNil 'ace_sys_ruck_no_ruck_conversion') then {_this call ace_sys_ruck_fnc_convertRuck}";
	};
};
class Extended_GetOut_EventHandlers
{
	class AllVehicles
	{
		class ace_sys_ruck
		{
			GetOut = "if (isNil 'ace_sys_ruck_no_ruck_conversion') then {_this call ace_sys_ruck_fnc_convertRuck}";
		};
	};
};
class CA_IGUI_Title;
class RscText;
class RscPicture;
class RscButton;
class RscControlsGroup;
class RscGearShortcutButton;
class RscIGUIListNBox;
class RscStructuredText;
class RscActiveText;
class RscLineBreak;
class RscIGUIShortcutButton;
class RscDisplayGear
{
	movingEnable = 1;
	emptyGun = "\ca\ui\data\ui_gear_gun_gs.paa";
	emptySec = "\ca\ui\data\ui_gear_sec_gs.paa";
	emptyEq = "\ca\ui\data\ui_gear_eq_gs.paa";
	emptyMag = "\ca\ui\data\ui_gear_mag_gs.paa";
	emptyMag2 = "\ca\ui\data\ui_gear_mag2_gs.paa";
	emptyHGun = "\ca\ui\data\ui_gear_hgun_gs.paa";
	emptyHGunMag = "\ca\ui\data\ui_gear_hgunmag_gs.paa";
	onLoad = "if (isNil('IGUI_GEAR_activeFilter')) then { IGUI_GEAR_activeFilter = 0}; [[_this, 'onLoad'], {_this call ace_sys_ruck_fnc_handleGear}]call cba_common_fnc_directCall";
	onUnload = "call ace_sys_ruck_fnc_unloadGear;";
	onKeyDown = "[_this,'onKeyDown'] call ace_sys_ruck_fnc_handleGear";
	class Filters
	{
		class All
		{
			name = "All";
			mask = -1;
			image = "\ca\ui\data\igui_gear_filter_1_ca.paa";
		};
		class Primary
		{
			name = "Primary";
			mask = 769;
			image = "\ca\ui\data\igui_gear_filter_2_ca.paa";
		};
		class Secondary
		{
			name = "Secondary";
			mask = 516;
			image = "\ca\ui\data\igui_gear_filter_3_ca.paa";
		};
		class HandGun
		{
			name = "HandGun";
			mask = 18;
			image = "\ca\ui\data\igui_gear_filter_4_ca.paa";
		};
		class Items
		{
			name = "Items";
			mask = 135168;
			image = "\ca\ui\data\igui_gear_filter_5_ca.paa";
		};
	};
	class ControlsBackground
	{
		class Mainback: RscPicture
		{
			idc = 1005;
			x = "(SafeZoneX + 0.01)";
			y = "(SafeZoneY + 0.01)";
			w = 1.1;
			h = 1.14;
			moving = 1;
			text = "\x\ace\addons\sys_ruck\data\ui\ui_gear_background.paa";
		};
	};
	class controls
	{
		class Gear_Title: CA_IGUI_Title
		{
			idc = 1001;
			x = "(SafeZoneX + 0.02)";
			y = "(SafeZoneY + 0.02)";
			text = "$STR_ACE_GEAR_NAME";
		};
		class CA_Filter_Icon: RscPicture
		{
			idc = 148;
			style = "0x30+ 0x800";
			x = "(SafeZoneX + 0.025)";
			y = "(SafeZoneY + 0.09)- 0.001";
			w = 0.458;
			h = 0.075;
			text = "\ca\ui\data\igui_gear_filter_1_ca.paa";
		};
		class CA_Filter_Left_Icon: RscPicture
		{
			idc = 1301;
			style = "0x30+ 0x800";
			x = "(SafeZoneX + 0.025)+ 0.01";
			y = "(SafeZoneY + 0.09)";
			w = 0.036;
			h = 0.075;
			text = "\ca\ui\data\arrow_left_ca.paa";
		};
		class CA_Filter_Right_Icon: RscPicture
		{
			idc = 1302;
			style = "0x30+ 0x800";
			x = "(SafeZoneX + 0.025)+ 0.413";
			y = "(SafeZoneY + 0.09)";
			w = 0.036;
			h = 0.075;
			text = "\ca\ui\data\arrow_right_ca.paa";
		};
		class CA_Filter_Arrow_Left: RscButton
		{
			idc = 150;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = "(SafeZoneX + 0.025)+ 0.01";
			y = "(SafeZoneY + 0.09)";
			w = 0.056;
			h = 0.075;
			text = "";
		};
		class CA_Filter_Arrow_Right: RscButton
		{
			idc = 151;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = "(SafeZoneX + 0.025)+ 0.403";
			y = "(SafeZoneY + 0.09)";
			w = 0.056;
			h = 0.075;
			text = "";
		};
		class CA_Filter_Icon1: RscButton
		{
			idc = 149;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = "(SafeZoneX + 0.025)+ 0.059";
			y = "(SafeZoneY + 0.02)";
			w = 0.341;
			h = 0.075;
			text = "";
		};
		class Unit_Title: RscText
		{
			idc = 101;
			style = "0x02";
			x = "(SafeZoneX + 0.66)";
			y = "(SafeZoneY + 0.09)";
			w = 0.4;
		};
		class ACE_Unit_Arrow_Left: RscPicture
		{
			idc = 90110;
			style = "0x30+ 0x800";
			colorBackground[] = {0,0,0,1};
			x = "(SafeZoneX + 0.66)- 0.030";
			y = "(SafeZoneY + 0.09)";
			w = 0.03;
			h = 0.037;
			text = "\ca\ui\data\arrow_left_ca.paa";
		};
		class ACE_Unit_Arrow_Right: RscPicture
		{
			idc = 90111;
			style = "0x30+ 0x800";
			colorBackground[] = {0,0,0,1};
			x = "(SafeZoneX + 0.66)+ 0.4";
			y = "(SafeZoneY + 0.09)";
			w = 0.03;
			h = 0.037;
			text = "\ca\ui\data\arrow_right_ca.paa";
		};
		class ACE_Unit_Button_Left: RscButton
		{
			idc = 90112;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = "(SafeZoneX + 0.66)- 0.030";
			y = "(SafeZoneY + 0.09)";
			w = 0.03;
			h = 0.037;
			text = "";
			onButtonClick = "[_this, false] call ace_sys_ruck_fnc_cycleUnit";
		};
		class ACE_Unit_Button_Right: RscButton
		{
			idc = 90112;
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			x = "(SafeZoneX + 0.66)+ 0.4";
			y = "(SafeZoneY + 0.09)";
			w = 0.03;
			h = 0.037;
			text = "";
			onButtonClick = "[_this, true] call ace_sys_ruck_fnc_cycleUnit";
		};
		class Available_items_Text: RscText
		{
			idc = 156;
			x = "(SafeZoneX + 0.025)+ 0.0033014";
			y = "(SafeZoneY + 0.18)";
			w = 0.389709;
			h = 0.04;
			text = "$STR_GEAR_ITEMS";
		};
		class ListboxArrows: RscControlsGroup
		{
			x = "(SafeZoneX + 0.025)";
			y = "(SafeZoneY + 0.22)";
			w = 0.48;
			h = 0.36;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_B_Add: RscGearShortcutButton
				{
					idc = 146;
					x = -2;
					style = "0x800";
					onSetFocus = "[_this, 'onAddFocus'] call ace_sys_ruck_fnc_handleGear";
					onButtonClick = "[_this, 'onLBListSelChanged'] call ace_sys_ruck_fnc_handleGear";
					text = "&lt;";
				};
				class Available_items: RscIGUIListNBox
				{
					idc = 105;
					columns[] = {0.075,0.175,0.81,0.67};
					drawSideArrows = 1;
					idcRight = 147;
					idcLeft = 146;
					onLBSelChanged = "[_this, 'onLBSelChanged'] call ace_sys_ruck_fnc_handleGear";
					onLBListSelChanged = "[_this, 'onLBListSelChanged'] call ace_sys_ruck_fnc_handleGear";
					onSetFocus = "[_this, 'onFocus'] call ace_sys_ruck_fnc_handleGear";
					onKillFocus = "[_this, 'onKillFocus'] call ace_sys_ruck_fnc_handleGear";
					x = 0.0;
					y = 0.0;
					w = 0.46;
					h = 0.36;
					canDrag = 1;
				};
				class CA_B_Remove: CA_B_Add
				{
					idc = 147;
					x = -2;
					onSetFocus = "[_this, 'onRemFocus'] call ace_sys_ruck_fnc_handleGear";
					onButtonClick = "[_this, 'onLBListSelChanged'] call ace_sys_ruck_fnc_handleGear";
					text = "&gt;";
				};
			};
		};
		class CA_ItemName: Available_items_Text
		{
			idc = 1101;
			x = "(SafeZoneX + 0.025)+ 0.0016704";
			y = "(SafeZoneY + 0.59)";
			h = 0.04;
			text = "$STR_GEAR_UNIT";
		};
		class CA_Item_Picture: RscPicture
		{
			idc = 1104;
			style = "0x30+ 0x800";
			x = "(SafeZoneX + 0.465)";
			y = "(SafeZoneY + 0.64)";
			w = 0.156863;
			h = 0.104575;
			text = "";
		};
		class CA_CustomDescription: RscStructuredText
		{
			idc = 1106;
			x = "(SafeZoneX + 0.02)";
			y = "(SafeZoneY + 0.64)";
			w = 0.458;
			h = 0.152;
			colorText[] = {0.95,0.95,0.95,1};
			class Attributes
			{
				font = "Zeppelin32";
				color = "#F2F2F2";
				align = "left";
				shadow = 1;
			};
		};
		class ACE_Ruck_Items: RscText
		{
			idc = 90000;
			x = "(SafeZoneX + 0.025)+ 0.0033014";
			y = "(SafeZoneY + 0.80)";
			w = 0.389709;
			h = 0.04;
			text = "$STR_ACE_RUCK_ITEMS";
		};
		class ACE_RLock_InUse: ACE_Ruck_Items
		{
			idc = 90123;
			y = "(SafeZoneY + 0.84)";
			text = "";
		};
		class ACE_Ruck_ListboxArrows: RscControlsGroup
		{
			x = "(SafeZoneX + 0.025)";
			y = "(SafeZoneY + 0.84)";
			w = 0.48;
			h = 0.25;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class ACE_Ruck_B_Add: RscGearShortcutButton
				{
					idc = 90001;
					x = -2;
					style = "0x02";
					onSetFocus = "[_this, 'Ruck_onAddFocus'] call ace_sys_ruck_fnc_handleGear";
					onButtonClick = "[_this, 'Ruck_onAddClick'] call ace_sys_ruck_fnc_handleGear";
					text = "&lt;";
				};
				class ACE_Ruck_Contents: RscIGUIListNBox
				{
					idc = 90002;
					columns[] = {0.075,0.175,0.81,0.67};
					drawSideArrows = 1;
					idcRight = 90003;
					idcLeft = 90001;
					onLBSelChanged = "[_this, 'Ruck_onLBSelChanged'] call ace_sys_ruck_fnc_handleGear";
					onLBListSelChanged = "[_this, 'Ruck_onLBListSelChanged'] call ace_sys_ruck_fnc_handleGear";
					onSetFocus = "[_this, 'Ruck_onFocus'] call ace_sys_ruck_fnc_handleGear";
					onKillFocus = "[_this, 'Ruck_onKillFocus'] call ace_sys_ruck_fnc_handleGear";
					onLBDblClick = "[_this, 'Ruck_onDblClick'] call ace_sys_ruck_fnc_handleGear";
					x = 0.0;
					y = 0.0;
					w = 0.46;
					h = 0.25;
					canDrag = 1;
				};
				class ACE_Ruck_B_Remove: ACE_Ruck_B_Add
				{
					idc = 90003;
					x = -2;
					onSetFocus = "[_this, 'Ruck_onRemFocus'] call ace_sys_ruck_fnc_handleGear";
					onButtonClick = "[_this, 'Ruck_onRemClick'] call ace_sys_ruck_fnc_handleGear";
					text = "&gt;";
				};
			};
		};
		class ACE_Item_Weight: RscText
		{
			idc = 90005;
			x = "(SafeZoneX + 0.485)";
			y = "(SafeZoneY + 0.80)";
			w = 0.2;
			h = 0.04;
			text = "";
		};
		class ACE_Item_Volume: RscText
		{
			idc = 90007;
			x = "(SafeZoneX + 0.485)";
			y = "(SafeZoneY + 0.84)";
			w = 0.2;
			h = 0.04;
			text = "";
		};
		class ACE_Total_Weight: RscText
		{
			idc = 90009;
			x = "(SafeZoneX + 0.40)";
			y = "(SafeZoneY + 0.02)";
			w = 0.3;
			h = 0.04;
			text = "";
		};
		class ACE_Total_Volume: RscText
		{
			idc = 90011;
			x = "(SafeZoneX + 0.025)+ 0.15";
			y = "(SafeZoneY + 0.80)";
			w = 0.35;
			h = 0.04;
			text = "";
		};
		class ACE_RLock_Text: RscText
		{
			idc = 90121;
			x = "(SafeZoneX + 0.465)- 0.05";
			y = "(SafeZoneY + 0.80)";
			w = 0.025;
			h = 0.04;
			text = "";
		};
		class ACE_RLock_Pic: RscPicture
		{
			idc = 90120;
			style = "0x30+ 0x800";
			x = "(SafeZoneX + 0.465)- 0.025";
			y = "(SafeZoneY + 0.80)";
			w = 0.025;
			h = 0.04;
			text = "\ca\ui\data\lock_on_ca.paa";
		};
		class ACE_RLock_Btn: RscButton
		{
			idc = 90122;
			x = "(SafeZoneX + 0.465)- 0.05";
			y = "(SafeZoneY + 0.80)";
			w = 0.05;
			h = "0.04- 0.008";
			colorText[] = {1,1,1,0};
			colorDisabled[] = {1,1,1,0};
			colorBackground[] = {1,1,1,0};
			colorBackgroundDisabled[] = {1,1,1,0};
			colorBackgroundActive[] = {1,1,1,0};
			colorShadow[] = {1,1,1,0};
			colorFocused[] = {1,1,1,0};
			onButtonClick = "[_this, 'ACE_RLockButton'] call ace_sys_ruck_fnc_handleGear";
		};
		class ACE_RLock_Cnx_Pic: ACE_RLock_Pic
		{
			idc = 90124;
			x = "(SafeZoneX + 0.465)- 0.05 - 0.025 - 0.010";
			text = "\ca\ui\data\cursor_map_unsel_ca.paa";
		};
		class ACE_RLock_Cnx_Btn: ACE_RLock_Btn
		{
			idc = 90125;
			x = "(SafeZoneX + 0.465)- 0.05 - 0.025 - 0.014";
			w = 0.026;
			onButtonClick = "[_this, 'ACE_RLockCnxButton'] call ace_sys_ruck_fnc_handleGear";
		};
		class CA_Money: RscText
		{
			idc = 1102;
			style = "0x01";
			show = 0;
			x = -2.50409;
			y = -2.85784;
			w = 0.228;
			text = "$STR_GEAR_MONEY";
		};
		class CA_Money_Value: RscText
		{
			idc = 1103;
			x = -2.72794;
			y = -2.85784;
			w = 0.228;
			text = "0";
		};
		class G_GearItems: RscControlsGroup
		{
			idc = 160;
			x = "(SafeZoneX + 0.13 + 0.502)";
			y = "(SafeZoneY + 0.05 + 0.09)";
			w = 0.463;
			h = 0.776;
			class Controls
			{
				class CA_Gear_slot_primary: RscActiveText
				{
					idc = 107;
					x = 0;
					y = 0;
					w = 0.286;
					h = 0.15;
					style = "0x30+ 0x800";
					soundDoubleClick[] = {"",0.1,1};
					color[] = {1,1,1,1};
					colorBackground[] = {0.6,0.8392,0.4706,1.0};
					colorBackgroundSelected[] = {0.6,0.8392,0.4706,1.0};
					colorFocused[] = {0.0,0.0,0.0,0};
					canDrag = 1;
					onButtonClick = "[_this, 'ACE_GearClick'] call ace_sys_ruck_fnc_handleGear";
				};
				class CA_Gear_slot_secondary: CA_Gear_slot_primary
				{
					idc = 108;
					y = "(0.244 - 0.09)";
				};
				class CA_Gear_slot_item1: CA_Gear_slot_primary
				{
					idc = 109;
					x = "(0.79 - 0.502)";
					y = 0;
					w = 0.055;
					h = 0.074;
				};
				class CA_Gear_slot_item2: CA_Gear_slot_item1
				{
					idc = 110;
					x = "(0.847 - 0.502)";
					y = 0;
				};
				class CA_Gear_slot_item3: CA_Gear_slot_item1
				{
					idc = 111;
					x = "(0.904366 - 0.502)";
					y = 0;
				};
				class CA_Gear_slot_item4: CA_Gear_slot_item1
				{
					idc = 112;
					x = "(0.79 - 0.502)";
					y = "(0.167 - 0.09)";
				};
				class CA_Gear_slot_item5: CA_Gear_slot_item1
				{
					idc = 113;
					x = "(0.847 - 0.502)";
					y = "(0.167 - 0.09)";
				};
				class CA_Gear_slot_item6: CA_Gear_slot_item1
				{
					idc = 114;
					x = "(0.904366 - 0.502)";
					y = "(0.167 - 0.09)";
				};
				class CA_Gear_slot_item7: CA_Gear_slot_item1
				{
					idc = 115;
					x = "(0.79 - 0.502)";
					y = "(0.244 - 0.09)";
				};
				class CA_Gear_slot_item8: CA_Gear_slot_item7
				{
					idc = 116;
					x = "(0.847 - 0.502)";
					y = "(0.244 - 0.09)";
				};
				class CA_Gear_slot_item9: CA_Gear_slot_item7
				{
					idc = 117;
					x = "(0.904366 - 0.502)";
					y = "(0.244 - 0.09)";
				};
				class CA_Gear_slot_item10: CA_Gear_slot_item7
				{
					idc = 118;
					x = "(0.79 - 0.502)";
					y = "(0.321 - 0.09)";
				};
				class CA_Gear_slot_item11: CA_Gear_slot_item7
				{
					idc = 119;
					x = "(0.847 - 0.502)";
					y = "(0.321 - 0.09)";
				};
				class CA_Gear_slot_item12: CA_Gear_slot_item7
				{
					idc = 120;
					x = "(0.904366 - 0.502)";
					y = "(0.321 - 0.09)";
				};
				class CA_Gear_slot_handgun: CA_Gear_slot_primary
				{
					idc = 121;
					x = 0;
					y = "(0.551 - 0.09)";
					w = 0.113;
					h = 0.15;
				};
				class CA_Gear_slot_handgun_item1: CA_Gear_slot_item1
				{
					idc = 122;
					x = "(0.617 - 0.502)";
					y = "(0.551 - 0.09)";
					w = 0.055;
					h = 0.074;
				};
				class CA_Gear_slot_handgun_item2: CA_Gear_slot_handgun_item1
				{
					idc = 123;
					x = "(0.674 - 0.502)";
					y = "(0.551 - 0.09)";
				};
				class CA_Gear_slot_handgun_item3: CA_Gear_slot_handgun_item1
				{
					idc = 124;
					x = "(0.733 - 0.502)";
					y = "(0.551 - 0.09)";
				};
				class CA_Gear_slot_handgun_item4: CA_Gear_slot_handgun_item1
				{
					idc = 125;
					x = "(0.79 - 0.502)";
					y = "(0.551 - 0.09)";
				};
				class CA_Gear_slot_handgun_item5: CA_Gear_slot_handgun_item1
				{
					idc = 126;
					x = "(0.617 - 0.502)";
					y = "(0.628 - 0.09)";
				};
				class CA_Gear_slot_handgun_item6: CA_Gear_slot_handgun_item5
				{
					idc = 127;
					x = "(0.674 - 0.502)";
					y = "(0.628 - 0.09)";
				};
				class CA_Gear_slot_handgun_item7: CA_Gear_slot_handgun_item5
				{
					idc = 128;
					x = "(0.733 - 0.502)";
					y = "(0.628 - 0.09)";
				};
				class CA_Gear_slot_handgun_item8: CA_Gear_slot_handgun_item5
				{
					idc = 129;
					x = "(0.79 - 0.502)";
					y = "(0.628 - 0.09)";
				};
				class CA_Gear_slot_special1: CA_Gear_slot_item1
				{
					idc = 130;
					x = "(0.847 - 0.502)";
					y = "(0.551 - 0.09)";
					w = 0.113;
					h = 0.15;
				};
				class CA_Gear_slot_special2: CA_Gear_slot_special1
				{
					idc = 131;
					x = "(0.847 - 0.502)";
					y = "(0.705 - 0.09)";
				};
				class CA_Gear_slot_inventory1: CA_Gear_slot_special1
				{
					idc = 134;
					x = 0;
					y = "(0.705 - 0.09)";
					w = 0.055;
					h = 0.074;
				};
				class CA_Gear_slot_inventory2: CA_Gear_slot_inventory1
				{
					idc = 135;
					x = "(0.56 - 0.502)";
					y = "(0.705 - 0.09)";
				};
				class CA_Gear_slot_inventory3: CA_Gear_slot_inventory1
				{
					idc = 136;
					x = "(0.617 - 0.502)";
					y = "(0.705 - 0.09)";
				};
				class CA_Gear_slot_inventory4: CA_Gear_slot_inventory1
				{
					idc = 137;
					x = "(0.674 - 0.502)";
					y = "(0.705 - 0.09)";
				};
				class CA_Gear_slot_inventory5: CA_Gear_slot_inventory1
				{
					idc = 138;
					x = "(0.733 - 0.502)";
					y = "(0.705 - 0.09)";
				};
				class CA_Gear_slot_inventory6: CA_Gear_slot_inventory1
				{
					idc = 139;
					x = "(0.79 - 0.502)";
					y = "(0.705 - 0.09)";
				};
				class CA_Gear_slot_inventory7: CA_Gear_slot_inventory1
				{
					idc = 140;
					x = 0;
					y = "(0.782 - 0.09)";
				};
				class CA_Gear_slot_inventory8: CA_Gear_slot_inventory7
				{
					idc = 141;
					x = "(0.56 - 0.502)";
					y = "(0.782 - 0.09)";
				};
				class CA_Gear_slot_inventory9: CA_Gear_slot_inventory7
				{
					idc = 142;
					x = "(0.617 - 0.502)";
					y = "(0.782 - 0.09)";
				};
				class CA_Gear_slot_inventory10: CA_Gear_slot_inventory7
				{
					idc = 143;
					x = "(0.674 - 0.502)";
					y = "(0.782 - 0.09)";
				};
				class CA_Gear_slot_inventory11: CA_Gear_slot_inventory7
				{
					idc = 144;
					x = "(0.733 - 0.502)";
					y = "(0.782 - 0.09)";
				};
				class CA_Gear_slot_inventory12: CA_Gear_slot_inventory7
				{
					idc = 145;
					x = "(0.79 - 0.502)";
					y = "(0.782 - 0.09)";
				};
				class CA_Gear_slot_inventory13: CA_Gear_slot_inventory7
				{
					idc = 1122;
					x = 0.1;
					y = 0.1;
				};
				class ACE_Gear_slot_WOB: CA_Gear_slot_primary
				{
					idc = 90020;
					x = 0;
					y = "(0.398 - 0.09)";
					color[] = {1,1,1,0.5};
					colorFocused[] = {1,1,1,1};
					onButtonClick = "[_this, 'ACE_WOBClick'] call ace_sys_ruck_fnc_handleGear";
				};
				class ACE_ButtonWOB: RscIGUIShortcutButton
				{
					idc = 90100;
					x = "(0.79 - 0.502)- 0.01";
					y = "(0.398 - 0.09)";
					text = "$STR_ACE_ON_BACK";
					onButtonClick = "[_this, 'ACE_WOBButton'] call ace_sys_ruck_fnc_handleGear";
				};
				class ACE_IFAK_1P: RscPicture
				{
					idc = 90104;
					style = "0x30+ 0x800";
					x = "(0.79 - 0.502)";
					y = "(0.398 - 0.09)+ 0.05";
					w = 0.043;
					h = 0.043;
					text = "";
				};
				class ACE_IFAK_2P: RscPicture
				{
					idc = 90105;
					style = "0x30+ 0x800";
					x = "(0.79 - 0.502)+ 0.001+ 0.043";
					y = "(0.398 - 0.09)+ 0.05";
					w = 0.043;
					h = 0.043;
					text = "";
				};
				class ACE_IFAK_3P: RscPicture
				{
					idc = 90106;
					style = "0x30+ 0x800";
					x = "(0.79 - 0.502)+ (0.001+ 0.043) * 2";
					y = "(0.398 - 0.09)+ 0.05";
					w = 0.043;
					h = 0.043;
					text = "";
				};
				class ACE_IFAK_1C: RscText
				{
					idc = 90107;
					style = "0x02";
					x = "(0.79 - 0.502)";
					y = "(0.398 - 0.09)+ 0.05* 2";
					w = 0.043;
					h = "0.043* 0.7";
					text = "";
				};
				class ACE_IFAK_2C: ACE_IFAK_1C
				{
					idc = 90108;
					x = "(0.79 - 0.502)+ 0.001+ 0.043";
				};
				class ACE_IFAK_3C: ACE_IFAK_1C
				{
					idc = 90109;
					x = "(0.79 - 0.502)+ (0.001+ 0.043) * 2";
				};
				class ACE_IFAK_1B: RscButton
				{
					idc = 90114;
					colorText[] = {1,1,1,0};
					colorDisabled[] = {1,1,1,0};
					colorBackground[] = {1,1,1,0};
					colorBackgroundDisabled[] = {1,1,1,0};
					colorBackgroundActive[] = {1,1,1,0};
					colorShadow[] = {1,1,1,0};
					colorFocused[] = {1,1,1,0};
					x = "(0.79 - 0.502)";
					y = "(0.398 - 0.09)+ 0.05* 2";
					w = 0.043;
					h = "0.043* 0.7";
					text = "";
					onButtonClick = "[_this, 0] call ace_sys_ruck_fnc_DropIFAK";
				};
				class ACE_IFAK_2B: ACE_IFAK_1B
				{
					idc = 90115;
					x = "(0.79 - 0.502)+ 0.001+ 0.043";
					onButtonClick = "[_this, 1] call ace_sys_ruck_fnc_DropIFAK";
				};
				class ACE_IFAK_3B: ACE_IFAK_1B
				{
					idc = 90116;
					x = "(0.79 - 0.502)+ (0.001+ 0.043) * 2";
					onButtonClick = "[_this, 2] call ace_sys_ruck_fnc_DropIFAK";
				};
				class ACE_IFAK_1T: ACE_IFAK_1B
				{
					idc = 90117;
					x = "(0.79 - 0.502)";
					y = "(0.398 - 0.09)+ 0.05";
					w = 0.043;
					h = 0.043;
					onButtonClick = "";
					soundEnter[] = {"",0,1};
					soundPush[] = {"",0,1};
					soundClick[] = {"",0,1};
					soundEscape[] = {"",0,1};
				};
				class ACE_IFAK_2T: ACE_IFAK_1T
				{
					idc = 90118;
					x = "(0.79 - 0.502)+ 0.001+ 0.043";
				};
				class ACE_IFAK_3T: ACE_IFAK_1T
				{
					idc = 90119;
					x = "(0.79 - 0.502)+ (0.001+ 0.043) * 2";
				};
			};
		};
		class BagItemsGroup: RscControlsGroup
		{
			x = "(SafeZoneX + 0.13 + 0.502)";
			y = "(SafeZoneY + 0.05 + 0.09)";
			w = 0.463;
			h = 0.776;
			idc = 159;
		};
		class Break_7: RscLineBreak{};
		class ButtonClose: RscIGUIShortcutButton
		{
			idc = 2;
			shortcuts[] = {"0x00050000+1"};
			x = "(SafeZoneX + 0.0392216)";
			y = "(SafeZoneY + 1.1)";
			text = "$STR_DISP_CLOSE";
		};
		class ButtonFilters: RscIGUIShortcutButton
		{
			idc = 148;
			shortcuts[] = {"0x00050000+3"};
			x = "(SafeZoneX + 0.333336)";
			y = "(SafeZoneY + 1.1)";
			text = "$STR_GEAR_FILTER";
		};
		class ButtonRearm: RscIGUIShortcutButton
		{
			idc = 132;
			shortcuts[] = {"0x00050000+2"};
			x = "(SafeZoneX + 0.554743)";
			y = "(SafeZoneY + 1.1)";
			text = "$STR_GEAR_REARM";
		};
		class ButtonOpenBag: RscIGUIShortcutButton
		{
			idc = 157;
			shortcuts[] = {"0x00050000 + 2"};
			x = "(SafeZoneX + 0.554743)";
			y = "(SafeZoneY + 1.1)";
		};
		class ButtonCloseBag: RscIGUIShortcutButton
		{
			idc = 158;
			shortcuts[] = {"0x00050000 + 2"};
			x = "(SafeZoneX + 0.554743)";
			y = "(SafeZoneY + 1.1)";
		};
		class ButtonContinue: RscIGUIShortcutButton
		{
			idc = 1;
			shortcuts[] = {"0x00050000+0",28,57,156};
			x = "(SafeZoneX + 0.77615)";
			y = "(SafeZoneY + 1.1)";
			default = 1;
			onButtonClick = "[_this, 'ButtonContinue'] call ace_sys_ruck_fnc_handleGear";
		};
		class ACE_ButtonPack: RscIGUIShortcutButton
		{
			idc = 90101;
			x = "(SafeZoneX + 0.9)";
			y = "(SafeZoneY + 1.0)";
			text = "$STR_ACE_PACK";
			onButtonClick = "[_this, 'ACE_PackButton'] call ace_sys_ruck_fnc_handleGear";
		};
		class ACE_ButtonUnPack: RscIGUIShortcutButton
		{
			idc = 90102;
			x = "(SafeZoneX + 0.9)";
			y = "(SafeZoneY + 1.05)";
			text = "$STR_ACE_UNPACK";
			onButtonClick = "[_this, 'ACE_UnpackButton'] call ace_sys_ruck_fnc_handleGear";
		};
		class ACE_ButtonDRuck: RscIGUIShortcutButton
		{
			idc = 90103;
			x = "(SafeZoneX + 0.554743)";
			y = "(SafeZoneY + 1.05)";
			class TextPos
			{
				left = 0.02;
				top = 0.002;
				right = 0.002;
				bottom = 0.016;
			};
			size = 0.029408;
			sizeEx = 0.029408;
			text = "$STR_ACE_SYS_RUCK_DRUCK";
			onButtonClick = "[_this, 'ACE_DRuckButton'] call ace_sys_ruck_fnc_handleGear";
		};
	};
};
class CfgFunctions
{
	class ACE
	{
		class Ruck
		{
			class AddWeaponOnBack
			{
				description = "Adds a weapon into the 'On Back' slot, performing checks to see if it fits.";
				file = "\x\ace\Addons\sys_ruck\fnc_AddWeaponOnBack.sqf";
			};
			class FindRuck
			{
				description = "Return name of ruck.";
				file = "\x\ace\Addons\sys_ruck\fnc_FindRuck.sqf";
			};
			class HasRadio
			{
				description = "Determine if a unit has a radio.";
				file = "\x\ace\Addons\sys_ruck\fnc_HasRadio.sqf";
			};
			class HasRuck
			{
				description = "Determine if a unit has a ruck.";
				file = "\x\ace\Addons\sys_ruck\fnc_HasRuck.sqf";
			};
			class HasWeapon
			{
				description = "Check Weapon on Back Slot in addition to regular slots when checking for presence of a weapon.";
				file = "\x\ace\Addons\sys_ruck\fnc_HasWeapon.sqf";
			};
			class PackIFAK
			{
				description = "Pack IFAK items. Use this function instead of adding IFAK magazines manually.";
				file = "\x\ace\Addons\sys_ruck\fnc_PackIFAK.sqf";
			};
			class PackMagazine
			{
				description = "Pack a magazine into a ruck, performing checks to see if it fits.";
				file = "\x\ace\Addons\sys_ruck\fnc_PackMagazine.sqf";
			};
			class PackWeapon
			{
				description = "Pack a weapon into a ruck, performing checks to see if it fits.";
				file = "\x\ace\Addons\sys_ruck\fnc_PackWeapon.sqf";
			};
			class PutWeaponOnBack
			{
				description = "Move a weapon into the 'On Back' slot, performing checks to see if it fits. The weapon must already be in that unit's weapon inventory.";
				file = "\x\ace\Addons\sys_ruck\fnc_PutWeaponOnBack.sqf";
			};
			class RemoveGear
			{
				description = "Remove gear from Ruck or Weapon on Back.";
				file = "\x\ace\Addons\sys_ruck\fnc_RemoveGear.sqf";
			};
			class RemWeapon
			{
				description = "Remove from Weapon on Back Slot first, in addition to regular slots, when removing a weapon.";
				file = "\x\ace\Addons\sys_ruck\fnc_RemWeapon.sqf";
			};
			class RuckMagazinesList
			{
				description = "Returns list of lists detailing magazines in a ruck.";
				file = "\x\ace\Addons\sys_ruck\fnc_RuckMagazinesList.sqf";
			};
			class RuckWeaponsList
			{
				description = "Returns list of lists detailing weapons in a ruck.";
				file = "\x\ace\Addons\sys_ruck\fnc_RuckWeaponsList.sqf";
			};
			class WeaponOnBackName
			{
				description = "Returns class name of weapon in Weapon On Back slot.";
				file = "\x\ace\Addons\sys_ruck\fnc_WeaponOnBackName.sqf";
			};
		};
	};
};
//};
