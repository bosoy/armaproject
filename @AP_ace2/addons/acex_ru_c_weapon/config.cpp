////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Aug 24 17:42:25 2012 : Created on Fri Aug 24 17:42:25 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_weapon : config.bin{
class CfgPatches
{
	class acex_ru_c_weapon
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","acex_main","CAWeapons","ace_c_weapon"};
		version = "1.13.0.72";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_ru_c_weapon
		{
			list[] = {"acex_ru_c_weapon"};
		};
	};
};
class CfgVehicles
{
	class USBasicAmmunitionBox_EP1;
	class USBasicWeapons_EP1;
	class ACE_WeaponBox_RU: USBasicWeapons_EP1
	{
		displayName = "Russia Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_Makarov
			{
				weapon = "Makarov";
				count = 4;
			};
			class _xx_MakarovSD
			{
				weapon = "MakarovSD";
				count = 4;
			};
			class _xx_PK
			{
				weapon = "PK";
				count = 4;
			};
			class _xx_Pecheneg
			{
				weapon = "Pecheneg";
				count = 4;
			};
			class _xx_SVD
			{
				weapon = "SVD";
				count = 4;
			};
			class _xx_SVD_CAMO
			{
				weapon = "SVD_CAMO";
				count = 4;
			};
			class _xx_AK_74
			{
				weapon = "AK_74";
				count = 4;
			};
			class _xx_AK_74_GL
			{
				weapon = "AK_74_GL";
				count = 4;
			};
			class _xx_AK_107_kobra
			{
				weapon = "AK_107_kobra";
				count = 4;
			};
			class _xx_AK_107_GL_kobra
			{
				weapon = "AK_107_GL_kobra";
				count = 4;
			};
			class _xx_AK_107_GL_pso
			{
				weapon = "AK_107_GL_pso";
				count = 4;
			};
			class _xx_AK_107_pso
			{
				weapon = "AK_107_pso";
				count = 4;
			};
			class _xx_AKS_74_kobra
			{
				weapon = "AKS_74_kobra";
				count = 4;
			};
			class _xx_AKS_74_pso
			{
				weapon = "AKS_74_pso";
				count = 4;
			};
			class _xx_AKS_74_U
			{
				weapon = "AKS_74_U";
				count = 4;
			};
			class _xx_AKS_74_UN_kobra
			{
				weapon = "AKS_74_UN_kobra";
				count = 4;
			};
			class _xx_RPK_74
			{
				weapon = "RPK_74";
				count = 4;
			};
			class _xx_bizon
			{
				weapon = "bizon";
				count = 4;
			};
			class _xx_bizon_silenced
			{
				weapon = "bizon_silenced";
				count = 4;
			};
			class _xx_ksvk
			{
				weapon = "ksvk";
				count = 4;
			};
			class _xx_Saiga12K
			{
				weapon = "Saiga12K";
				count = 4;
			};
			class _xx_VSS_vintorez
			{
				weapon = "VSS_vintorez";
				count = 4;
			};
			class _xx_Sa61_EP1
			{
				weapon = "Sa61_EP1";
				count = 4;
			};
			class _xx_revolver_EP1
			{
				weapon = "revolver_EP1";
				count = 4;
			};
			class _xx_revolver_gold_EP1
			{
				weapon = "revolver_gold_EP1";
				count = 4;
			};
			class _xx_SVD_des_EP1
			{
				weapon = "SVD_des_EP1";
				count = 4;
			};
			class _xx_SVD_NSPU_EP1
			{
				weapon = "SVD_NSPU_EP1";
				count = 4;
			};
			class _xx_AK_74_GL_kobra
			{
				weapon = "AK_74_GL_kobra";
				count = 4;
			};
			class _xx_AKS_74
			{
				weapon = "AKS_74";
				count = 4;
			};
			class _xx_AKS_74_NSPU
			{
				weapon = "AKS_74_NSPU";
				count = 4;
			};
			class _xx_AKS_74_GOSHAWK
			{
				weapon = "AKS_74_GOSHAWK";
				count = 4;
			};
			class _xx_ACE_AKS74_GP25
			{
				weapon = "ACE_AKS74_GP25";
				count = 4;
			};
			class _xx_ACE_AKS74_UN
			{
				weapon = "ACE_AKS74_UN";
				count = 4;
			};
			class _xx_ACE_AK74M
			{
				weapon = "ACE_AK74M";
				count = 4;
			};
			class _xx_ACE_AK74M_Kobra
			{
				weapon = "ACE_AK74M_Kobra";
				count = 4;
			};
			class _xx_ACE_AK74M_PSO
			{
				weapon = "ACE_AK74M_PSO";
				count = 4;
			};
			class _xx_ACE_AK74M_1P78
			{
				weapon = "ACE_AK74M_1P78";
				count = 4;
			};
			class _xx_ACE_AK74M_TWS
			{
				weapon = "ACE_AK74M_TWS";
				count = 4;
			};
			class _xx_ACE_AK74M_NSPU
			{
				weapon = "ACE_AK74M_NSPU";
				count = 4;
			};
			class _xx_ACE_AK74M_FL
			{
				weapon = "ACE_AK74M_FL";
				count = 4;
			};
			class _xx_ACE_AK74M_Kobra_FL
			{
				weapon = "ACE_AK74M_Kobra_FL";
				count = 4;
			};
			class _xx_ACE_AK74M_PSO_FL
			{
				weapon = "ACE_AK74M_PSO_FL";
				count = 4;
			};
			class _xx_ACE_AK74M_1P78_FL
			{
				weapon = "ACE_AK74M_1P78_FL";
				count = 4;
			};
			class _xx_ACE_AK74M_TWS_FL
			{
				weapon = "ACE_AK74M_TWS_FL";
				count = 4;
			};
			class _xx_ACE_AK74M_NSPU_FL
			{
				weapon = "ACE_AK74M_NSPU_FL";
				count = 4;
			};
			class _xx_ACE_AK74M_GL
			{
				weapon = "ACE_AK74M_GL";
				count = 4;
			};
			class _xx_ACE_AK74M_GL_Kobra
			{
				weapon = "ACE_AK74M_GL_Kobra";
				count = 4;
			};
			class _xx_ACE_AK74M_GL_PSO
			{
				weapon = "ACE_AK74M_GL_PSO";
				count = 4;
			};
			class _xx_ACE_AK74M_GL_1P78
			{
				weapon = "ACE_AK74M_GL_1P78";
				count = 4;
			};
			class _xx_ACE_AK74M_GL_TWS
			{
				weapon = "ACE_AK74M_GL_TWS";
				count = 4;
			};
			class _xx_ACE_AK74M_GL_NSPU
			{
				weapon = "ACE_AK74M_GL_NSPU";
				count = 4;
			};
			class _xx_ACE_AK74M_SD
			{
				weapon = "ACE_AK74M_SD";
				count = 4;
			};
			class _xx_ACE_AK74M_SD_Kobra
			{
				weapon = "ACE_AK74M_SD_Kobra";
				count = 4;
			};
			class _xx_ACE_AK74M_SD_PSO
			{
				weapon = "ACE_AK74M_SD_PSO";
				count = 4;
			};
			class _xx_ACE_AK74M_SD_1P78
			{
				weapon = "ACE_AK74M_SD_1P78";
				count = 4;
			};
			class _xx_ACE_AK74M_SD_TWS
			{
				weapon = "ACE_AK74M_SD_TWS";
				count = 4;
			};
			class _xx_ACE_AK74M_SD_NSPU
			{
				weapon = "ACE_AK74M_SD_NSPU";
				count = 4;
			};
			class _xx_ACE_AKS74P
			{
				weapon = "ACE_AKS74P";
				count = 4;
			};
			class _xx_ACE_AKS74P_Kobra
			{
				weapon = "ACE_AKS74P_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_1P29
			{
				weapon = "ACE_AKS74P_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_PSO
			{
				weapon = "ACE_AKS74P_PSO";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL
			{
				weapon = "ACE_AKS74P_GL";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_Kobra
			{
				weapon = "ACE_AKS74P_GL_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_1P29
			{
				weapon = "ACE_AKS74P_GL_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_PSO
			{
				weapon = "ACE_AKS74P_GL_PSO";
				count = 4;
			};
			class _xx_ACE_AK105
			{
				weapon = "ACE_AK105";
				count = 4;
			};
			class _xx_ACE_AK105_Kobra
			{
				weapon = "ACE_AK105_Kobra";
				count = 4;
			};
			class _xx_ACE_AK105_1P29
			{
				weapon = "ACE_AK105_1P29";
				count = 4;
			};
			class _xx_ACE_AK105_PSO
			{
				weapon = "ACE_AK105_PSO";
				count = 4;
			};
			class _xx_ACE_AK103
			{
				weapon = "ACE_AK103";
				count = 4;
			};
			class _xx_ACE_AK103_Kobra
			{
				weapon = "ACE_AK103_Kobra";
				count = 4;
			};
			class _xx_ACE_AK103_1P29
			{
				weapon = "ACE_AK103_1P29";
				count = 4;
			};
			class _xx_ACE_AK103_PSO
			{
				weapon = "ACE_AK103_PSO";
				count = 4;
			};
			class _xx_ACE_AK103_GL
			{
				weapon = "ACE_AK103_GL";
				count = 4;
			};
			class _xx_ACE_AK103_GL_Kobra
			{
				weapon = "ACE_AK103_GL_Kobra";
				count = 4;
			};
			class _xx_ACE_AK103_GL_1P29
			{
				weapon = "ACE_AK103_GL_1P29";
				count = 4;
			};
			class _xx_ACE_AK103_GL_PSO
			{
				weapon = "ACE_AK103_GL_PSO";
				count = 4;
			};
			class _xx_ACE_AK104
			{
				weapon = "ACE_AK104";
				count = 4;
			};
			class _xx_ACE_AK104_Kobra
			{
				weapon = "ACE_AK104_Kobra";
				count = 4;
			};
			class _xx_ACE_AK104_1P29
			{
				weapon = "ACE_AK104_1P29";
				count = 4;
			};
			class _xx_ACE_AK104_PSO
			{
				weapon = "ACE_AK104_PSO";
				count = 4;
			};
			class _xx_ACE_RPK74M
			{
				weapon = "ACE_RPK74M";
				count = 4;
			};
			class _xx_ACE_RPK74M_1P29
			{
				weapon = "ACE_RPK74M_1P29";
				count = 4;
			};
			class _xx_ACE_Val
			{
				weapon = "ACE_Val";
				count = 4;
			};
			class _xx_ACE_Val_Kobra
			{
				weapon = "ACE_Val_Kobra";
				count = 4;
			};
			class _xx_ACE_Val_PSO
			{
				weapon = "ACE_Val_PSO";
				count = 4;
			};
			class _xx_ACE_oc14
			{
				weapon = "ACE_oc14";
				count = 4;
			};
			class _xx_ACE_oc14sp
			{
				weapon = "ACE_oc14sp";
				count = 4;
			};
			class _xx_ACE_oc14gl
			{
				weapon = "ACE_oc14gl";
				count = 4;
			};
			class _xx_ACE_oc14glsp
			{
				weapon = "ACE_oc14glsp";
				count = 4;
			};
			class _xx_ACE_oc14sd
			{
				weapon = "ACE_oc14sd";
				count = 4;
			};
			class _xx_ACE_oc14sdsp
			{
				weapon = "ACE_oc14sdsp";
				count = 4;
			};
			class _xx_ACE_gr1
			{
				weapon = "ACE_gr1";
				count = 4;
			};
			class _xx_ACE_gr1sp
			{
				weapon = "ACE_gr1sp";
				count = 4;
			};
			class _xx_ACE_gr1sd
			{
				weapon = "ACE_gr1sd";
				count = 4;
			};
			class _xx_ACE_gr1sdsp
			{
				weapon = "ACE_gr1sdsp";
				count = 4;
			};
			class _xx_ACE_SVD_Bipod
			{
				weapon = "ACE_SVD_Bipod";
				count = 4;
			};
			class _xx_ACE_AEK_971
			{
				weapon = "ACE_AEK_971";
				count = 4;
			};
			class _xx_ACE_AEK_971_gp
			{
				weapon = "ACE_AEK_971_gp";
				count = 4;
			};
			class _xx_ACE_AEK_971_1p63
			{
				weapon = "ACE_AEK_971_1p63";
				count = 4;
			};
			class _xx_ACE_AEK_971_gp_1p63
			{
				weapon = "ACE_AEK_971_gp_1p63";
				count = 4;
			};
			class _xx_ACE_AEK_971_1p78
			{
				weapon = "ACE_AEK_971_1p78";
				count = 4;
			};
			class _xx_ACE_AEK_971_1pn100
			{
				weapon = "ACE_AEK_971_1pn100";
				count = 4;
			};
			class _xx_ACE_AEK_971_shahin
			{
				weapon = "ACE_AEK_971_shahin";
				count = 4;
			};
			class _xx_ACE_AEK_971_tgp_cln
			{
				weapon = "ACE_AEK_971_tgp_cln";
				count = 4;
			};
			class _xx_ACE_AEK_973s
			{
				weapon = "ACE_AEK_973s";
				count = 4;
			};
			class _xx_ACE_AEK_973s_gp
			{
				weapon = "ACE_AEK_973s_gp";
				count = 4;
			};
			class _xx_ACE_AEK_973s_1p63
			{
				weapon = "ACE_AEK_973s_1p63";
				count = 4;
			};
			class _xx_ACE_AEK_973s_gp_1p63
			{
				weapon = "ACE_AEK_973s_gp_1p63";
				count = 4;
			};
			class _xx_ACE_AEK_973s_1p78
			{
				weapon = "ACE_AEK_973s_1p78";
				count = 4;
			};
			class _xx_ACE_AEK_973s_1pn100
			{
				weapon = "ACE_AEK_973s_1pn100";
				count = 4;
			};
			class _xx_ACE_AEK_973s_shahin
			{
				weapon = "ACE_AEK_973s_shahin";
				count = 4;
			};
			class _xx_ACE_AEK_973s_tgp_cln
			{
				weapon = "ACE_AEK_973s_tgp_cln";
				count = 4;
			};
			class _xx_ACE_KORDProxy
			{
				weapon = "ACE_KORDProxy";
				count = 4;
			};
			class _xx_ACE_AGS30Proxy
			{
				weapon = "ACE_AGS30Proxy";
				count = 4;
			};
			class _xx_ACE_2b14Proxy
			{
				weapon = "ACE_2b14Proxy";
				count = 4;
			};
			class _xx_ACE_6T7TripodProxy
			{
				weapon = "ACE_6T7TripodProxy";
				count = 4;
			};
			class _xx_ACE_AGS30TripodProxy
			{
				weapon = "ACE_AGS30TripodProxy";
				count = 4;
			};
			class _xx_ACE_2b14TripodProxy
			{
				weapon = "ACE_2b14TripodProxy";
				count = 4;
			};
			class _xx_ACE_KonkursTripodProxy
			{
				weapon = "ACE_KonkursTripodProxy";
				count = 4;
			};
			class _xx_Binocular
			{
				weapon = "Binocular";
				count = 4;
			};
			class _xx_Laserdesignator
			{
				weapon = "Laserdesignator";
				count = 4;
			};
			class _xx_NVGoggles
			{
				weapon = "NVGoggles";
				count = 4;
			};
			class _xx_Binocular_Vector
			{
				weapon = "Binocular_Vector";
				count = 4;
			};
			class _xx_ACE_KeyCuffs
			{
				weapon = "ACE_KeyCuffs";
				count = 4;
			};
			class _xx_ACE_M60
			{
				weapon = "ACE_M60";
				count = 4;
			};
			class _xx_ACE_Flaregun
			{
				weapon = "ACE_Flaregun";
				count = 4;
			};
			class _xx_ACE_Earplugs
			{
				weapon = "ACE_Earplugs";
				count = 4;
			};
			class _xx_ACE_GlassesSunglasses
			{
				weapon = "ACE_GlassesSunglasses";
				count = 4;
			};
			class _xx_ACE_GlassesTactical
			{
				weapon = "ACE_GlassesTactical";
				count = 4;
			};
			class _xx_ACE_GlassesLHD_glasses
			{
				weapon = "ACE_GlassesLHD_glasses";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_US
			{
				weapon = "ACE_GlassesGasMask_US";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_RU
			{
				weapon = "ACE_GlassesGasMask_RU";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklava
			{
				weapon = "ACE_GlassesBalaklava";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaOlive
			{
				weapon = "ACE_GlassesBalaklavaOlive";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaGray
			{
				weapon = "ACE_GlassesBalaklavaGray";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72
			{
				weapon = "ACE_VTAC_RUSH72";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_ACU
			{
				weapon = "ACE_VTAC_RUSH72_ACU";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_TT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_TT_MEDIC";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_FT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_FT_MEDIC";
				count = 4;
			};
			class _xx_ACE_CharliePack
			{
				weapon = "ACE_CharliePack";
				count = 4;
			};
			class _xx_ACE_CharliePack_WMARPAT
			{
				weapon = "ACE_CharliePack_WMARPAT";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU
			{
				weapon = "ACE_CharliePack_ACU";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU_Medic
			{
				weapon = "ACE_CharliePack_ACU_Medic";
				count = 4;
			};
			class _xx_ACE_PRC119
			{
				weapon = "ACE_PRC119";
				count = 4;
			};
			class _xx_ACE_PRC119_MAR
			{
				weapon = "ACE_PRC119_MAR";
				count = 4;
			};
			class _xx_ACE_PRC119_ACU
			{
				weapon = "ACE_PRC119_ACU";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC
			{
				weapon = "ACE_FAST_PackEDC";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC_ACU
			{
				weapon = "ACE_FAST_PackEDC_ACU";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack
			{
				weapon = "ACE_Coyote_Pack";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack_Black
			{
				weapon = "ACE_Coyote_Pack_Black";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR
			{
				weapon = "ACE_BackPack_ACR";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_FL
			{
				weapon = "ACE_BackPack_ACR_FL";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_TT
			{
				weapon = "ACE_BackPack_ACR_TT";
				count = 4;
			};
			class _xx_ACE_ALICE_Backpack
			{
				weapon = "ACE_ALICE_Backpack";
				count = 4;
			};
			class _xx_ACE_Backpack_US
			{
				weapon = "ACE_Backpack_US";
				count = 4;
			};
			class _xx_ACE_Backpack_FL
			{
				weapon = "ACE_Backpack_FL";
				count = 4;
			};
			class _xx_ACE_Backpack_TT
			{
				weapon = "ACE_Backpack_TT";
				count = 4;
			};
			class _xx_ACE_P159_RD90
			{
				weapon = "ACE_P159_RD90";
				count = 4;
			};
			class _xx_ACE_P159_RD54
			{
				weapon = "ACE_P159_RD54";
				count = 4;
			};
			class _xx_ACE_P159_RD99
			{
				weapon = "ACE_P159_RD99";
				count = 4;
			};
			class _xx_ACE_Kestrel4500
			{
				weapon = "ACE_Kestrel4500";
				count = 4;
			};
			class _xx_ACE_WireCutter
			{
				weapon = "ACE_WireCutter";
				count = 4;
			};
			class _xx_ACE_HuntIR_monitor
			{
				weapon = "ACE_HuntIR_monitor";
				count = 4;
			};
			class _xx_ACE_Rangefinder_OD
			{
				weapon = "ACE_Rangefinder_OD";
				count = 4;
			};
			class _xx_ACE_YardAge450
			{
				weapon = "ACE_YardAge450";
				count = 4;
			};
			class _xx_ACE_MX2A
			{
				weapon = "ACE_MX2A";
				count = 4;
			};
			class _xx_ACE_SpottingScope
			{
				weapon = "ACE_SpottingScope";
				count = 4;
			};
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 4;
			};
			class _xx_ACE_M220TripodProxy
			{
				weapon = "ACE_M220TripodProxy";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_EP_AK
			{
				magazine = "ACE_30Rnd_545x39_EP_AK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_AP_AK
			{
				magazine = "ACE_30Rnd_545x39_AP_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_EP_AK
			{
				magazine = "ACE_45Rnd_545x39_EP_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_AP_AK
			{
				magazine = "ACE_45Rnd_545x39_AP_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_64Rnd_9x19_Bizon
			{
				magazine = "64Rnd_9x19_Bizon";
				count = 16;
			};
			class _xx_64Rnd_9x19_SD_Bizon
			{
				magazine = "64Rnd_9x19_SD_Bizon";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_10Rnd_9x39_SP5_VSS
			{
				magazine = "10Rnd_9x39_SP5_VSS";
				count = 16;
			};
			class _xx_ACE_10Rnd_9x39_SP6_VSS
			{
				magazine = "ACE_10Rnd_9x39_SP6_VSS";
				count = 16;
			};
			class _xx_20Rnd_9x39_SP5_VSS
			{
				magazine = "20Rnd_9x39_SP5_VSS";
				count = 16;
			};
			class _xx_ACE_20Rnd_9x39_SP6_VSS
			{
				magazine = "ACE_20Rnd_9x39_SP6_VSS";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_AP_AK47
			{
				magazine = "ACE_30Rnd_762x39_AP_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_AP_AK47
			{
				magazine = "ACE_40Rnd_762x39_AP_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_20Rnd_9x39_B_OC14
			{
				magazine = "ACE_20Rnd_9x39_B_OC14";
				count = 16;
			};
			class _xx_ACE_20Rnd_9x39_B_SP6_OC14
			{
				magazine = "ACE_20Rnd_9x39_B_SP6_OC14";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_BBetty_M
			{
				magazine = "ACE_BBetty_M";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_KORD_CSWDM
			{
				magazine = "ACE_KORD_CSWDM";
				count = 16;
			};
			class _xx_ACE_AGS30_CSWDM
			{
				magazine = "ACE_AGS30_CSWDM";
				count = 16;
			};
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 16;
			};
			class _xx_ACE_KonkursM_CSWDM
			{
				magazine = "ACE_KonkursM_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_RU: USBasicAmmunitionBox_EP1
	{
		displayName = "Russia Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_EP_AK
			{
				magazine = "ACE_30Rnd_545x39_EP_AK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_AP_AK
			{
				magazine = "ACE_30Rnd_545x39_AP_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_EP_AK
			{
				magazine = "ACE_45Rnd_545x39_EP_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_AP_AK
			{
				magazine = "ACE_45Rnd_545x39_AP_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_64Rnd_9x19_Bizon
			{
				magazine = "64Rnd_9x19_Bizon";
				count = 16;
			};
			class _xx_64Rnd_9x19_SD_Bizon
			{
				magazine = "64Rnd_9x19_SD_Bizon";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_10Rnd_9x39_SP5_VSS
			{
				magazine = "10Rnd_9x39_SP5_VSS";
				count = 16;
			};
			class _xx_ACE_10Rnd_9x39_SP6_VSS
			{
				magazine = "ACE_10Rnd_9x39_SP6_VSS";
				count = 16;
			};
			class _xx_20Rnd_9x39_SP5_VSS
			{
				magazine = "20Rnd_9x39_SP5_VSS";
				count = 16;
			};
			class _xx_ACE_20Rnd_9x39_SP6_VSS
			{
				magazine = "ACE_20Rnd_9x39_SP6_VSS";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_AP_AK47
			{
				magazine = "ACE_30Rnd_762x39_AP_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_AP_AK47
			{
				magazine = "ACE_40Rnd_762x39_AP_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_20Rnd_9x39_B_OC14
			{
				magazine = "ACE_20Rnd_9x39_B_OC14";
				count = 16;
			};
			class _xx_ACE_20Rnd_9x39_B_SP6_OC14
			{
				magazine = "ACE_20Rnd_9x39_B_SP6_OC14";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_BBetty_M
			{
				magazine = "ACE_BBetty_M";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_KORD_CSWDM
			{
				magazine = "ACE_KORD_CSWDM";
				count = 16;
			};
			class _xx_ACE_AGS30_CSWDM
			{
				magazine = "ACE_AGS30_CSWDM";
				count = 16;
			};
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 16;
			};
			class _xx_ACE_KonkursM_CSWDM
			{
				magazine = "ACE_KonkursM_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_OrdnanceBox_RU: USBasicWeapons_EP1
	{
		displayName = "Russia Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 16;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 16;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 16;
			};
			class _xx_SmokeShellBlue
			{
				magazine = "SmokeShellBlue";
				count = 16;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 16;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 16;
			};
			class _xx_SmokeShellPurple
			{
				magazine = "SmokeShellPurple";
				count = 16;
			};
			class _xx_SmokeShellRed
			{
				magazine = "SmokeShellRed";
				count = 16;
			};
			class _xx_SmokeShellYellow
			{
				magazine = "SmokeShellYellow";
				count = 16;
			};
			class _xx_IR_Strobe_Marker
			{
				magazine = "IR_Strobe_Marker";
				count = 16;
			};
			class _xx_IR_Strobe_Target
			{
				magazine = "IR_Strobe_Target";
				count = 16;
			};
			class _xx_ACE_RDG2
			{
				magazine = "ACE_RDG2";
				count = 16;
			};
			class _xx_ACE_RDGM
			{
				magazine = "ACE_RDGM";
				count = 16;
			};
			class _xx_ACE_TORCH_C
			{
				magazine = "ACE_TORCH_C";
				count = 16;
			};
			class _xx_ACE_RG60A
			{
				magazine = "ACE_RG60A";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 16;
			};
			class _xx_MineE
			{
				magazine = "MineE";
				count = 16;
			};
			class _xx_PMC_ied_v1
			{
				magazine = "PMC_ied_v1";
				count = 16;
			};
			class _xx_PMC_ied_v2
			{
				magazine = "PMC_ied_v2";
				count = 16;
			};
			class _xx_PMC_ied_v3
			{
				magazine = "PMC_ied_v3";
				count = 16;
			};
			class _xx_PMC_ied_v4
			{
				magazine = "PMC_ied_v4";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_Launchers_RU: USBasicWeapons_EP1
	{
		displayName = "Russia Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_RPG7V
			{
				weapon = "RPG7V";
				count = 4;
			};
			class _xx_Igla
			{
				weapon = "Igla";
				count = 4;
			};
			class _xx_MetisLauncher
			{
				weapon = "MetisLauncher";
				count = 4;
			};
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 4;
			};
			class _xx_ACE_RPG7V_PGO7
			{
				weapon = "ACE_RPG7V_PGO7";
				count = 4;
			};
			class _xx_ACE_RPG29
			{
				weapon = "ACE_RPG29";
				count = 4;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 4;
			};
			class _xx_ACE_RPG27
			{
				weapon = "ACE_RPG27";
				count = 4;
			};
			class _xx_ACE_RPOM
			{
				weapon = "ACE_RPOM";
				count = 4;
			};
			class _xx_ACE_RSHG1
			{
				weapon = "ACE_RSHG1";
				count = 4;
			};
			class _xx_ACE_RMG
			{
				weapon = "ACE_RMG";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 4;
			};
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_JerryCan_Dummy_15
			{
				weapon = "ACE_JerryCan_Dummy_15";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Igla
			{
				magazine = "Igla";
				count = 16;
			};
			class _xx_ACE_AT13TB
			{
				magazine = "ACE_AT13TB";
				count = 16;
			};
			class _xx_AT13
			{
				magazine = "AT13";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_Launchers_RU: USBasicAmmunitionBox_EP1
	{
		displayName = "Russia Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 16;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 16;
			};
			class _xx_ACE_RPG27
			{
				weapon = "ACE_RPG27";
				count = 16;
			};
			class _xx_ACE_RPOM
			{
				weapon = "ACE_RPOM";
				count = 16;
			};
			class _xx_ACE_RSHG1
			{
				weapon = "ACE_RSHG1";
				count = 16;
			};
			class _xx_ACE_RMG
			{
				weapon = "ACE_RMG";
				count = 16;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Igla
			{
				magazine = "Igla";
				count = 16;
			};
			class _xx_ACE_AT13TB
			{
				magazine = "ACE_AT13TB";
				count = 16;
			};
			class _xx_AT13
			{
				magazine = "AT13";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_CDF: USBasicWeapons_EP1
	{
		displayName = "CDF Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_Makarov
			{
				weapon = "Makarov";
				count = 4;
			};
			class _xx_MakarovSD
			{
				weapon = "MakarovSD";
				count = 4;
			};
			class _xx_MP5SD
			{
				weapon = "MP5SD";
				count = 4;
			};
			class _xx_MP5A5
			{
				weapon = "MP5A5";
				count = 4;
			};
			class _xx_PK
			{
				weapon = "PK";
				count = 4;
			};
			class _xx_SVD
			{
				weapon = "SVD";
				count = 4;
			};
			class _xx_SVD_CAMO
			{
				weapon = "SVD_CAMO";
				count = 4;
			};
			class _xx_AK_47_M
			{
				weapon = "AK_47_M";
				count = 4;
			};
			class _xx_AK_47_S
			{
				weapon = "AK_47_S";
				count = 4;
			};
			class _xx_AKS_GOLD
			{
				weapon = "AKS_GOLD";
				count = 4;
			};
			class _xx_AK_74
			{
				weapon = "AK_74";
				count = 4;
			};
			class _xx_AK_74_GL
			{
				weapon = "AK_74_GL";
				count = 4;
			};
			class _xx_AKS_74_kobra
			{
				weapon = "AKS_74_kobra";
				count = 4;
			};
			class _xx_AKS_74_pso
			{
				weapon = "AKS_74_pso";
				count = 4;
			};
			class _xx_AKS_74_U
			{
				weapon = "AKS_74_U";
				count = 4;
			};
			class _xx_AKS_74_UN_kobra
			{
				weapon = "AKS_74_UN_kobra";
				count = 4;
			};
			class _xx_RPK_74
			{
				weapon = "RPK_74";
				count = 4;
			};
			class _xx_bizon
			{
				weapon = "bizon";
				count = 4;
			};
			class _xx_bizon_silenced
			{
				weapon = "bizon_silenced";
				count = 4;
			};
			class _xx_ksvk
			{
				weapon = "ksvk";
				count = 4;
			};
			class _xx_Saiga12K
			{
				weapon = "Saiga12K";
				count = 4;
			};
			class _xx_ACE_MP5SD
			{
				weapon = "ACE_MP5SD";
				count = 4;
			};
			class _xx_ACE_MP5A5
			{
				weapon = "ACE_MP5A5";
				count = 4;
			};
			class _xx_ACE_MP5A4
			{
				weapon = "ACE_MP5A4";
				count = 4;
			};
			class _xx_Sa61_EP1
			{
				weapon = "Sa61_EP1";
				count = 4;
			};
			class _xx_revolver_EP1
			{
				weapon = "revolver_EP1";
				count = 4;
			};
			class _xx_revolver_gold_EP1
			{
				weapon = "revolver_gold_EP1";
				count = 4;
			};
			class _xx_SVD_des_EP1
			{
				weapon = "SVD_des_EP1";
				count = 4;
			};
			class _xx_SVD_NSPU_EP1
			{
				weapon = "SVD_NSPU_EP1";
				count = 4;
			};
			class _xx_AK_74_GL_kobra
			{
				weapon = "AK_74_GL_kobra";
				count = 4;
			};
			class _xx_AKS_74
			{
				weapon = "AKS_74";
				count = 4;
			};
			class _xx_AKS_74_NSPU
			{
				weapon = "AKS_74_NSPU";
				count = 4;
			};
			class _xx_AKS_74_GOSHAWK
			{
				weapon = "AKS_74_GOSHAWK";
				count = 4;
			};
			class _xx_ACE_AKS74_GP25
			{
				weapon = "ACE_AKS74_GP25";
				count = 4;
			};
			class _xx_ACE_AKS74_UN
			{
				weapon = "ACE_AKS74_UN";
				count = 4;
			};
			class _xx_ACE_AKS74P
			{
				weapon = "ACE_AKS74P";
				count = 4;
			};
			class _xx_ACE_AKS74P_Kobra
			{
				weapon = "ACE_AKS74P_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_1P29
			{
				weapon = "ACE_AKS74P_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_PSO
			{
				weapon = "ACE_AKS74P_PSO";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL
			{
				weapon = "ACE_AKS74P_GL";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_Kobra
			{
				weapon = "ACE_AKS74P_GL_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_1P29
			{
				weapon = "ACE_AKS74P_GL_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_PSO
			{
				weapon = "ACE_AKS74P_GL_PSO";
				count = 4;
			};
			class _xx_ACE_AKM
			{
				weapon = "ACE_AKM";
				count = 4;
			};
			class _xx_ACE_AKM_GL
			{
				weapon = "ACE_AKM_GL";
				count = 4;
			};
			class _xx_ACE_AKMS
			{
				weapon = "ACE_AKMS";
				count = 4;
			};
			class _xx_ACE_AKMS_SD
			{
				weapon = "ACE_AKMS_SD";
				count = 4;
			};
			class _xx_ACE_RPK
			{
				weapon = "ACE_RPK";
				count = 4;
			};
			class _xx_ACE_SVD_Bipod
			{
				weapon = "ACE_SVD_Bipod";
				count = 4;
			};
			class _xx_ACE_DSHKMProxy
			{
				weapon = "ACE_DSHKMProxy";
				count = 4;
			};
			class _xx_ACE_AGS30Proxy
			{
				weapon = "ACE_AGS30Proxy";
				count = 4;
			};
			class _xx_ACE_2b14Proxy
			{
				weapon = "ACE_2b14Proxy";
				count = 4;
			};
			class _xx_ACE_AGS30TripodProxy
			{
				weapon = "ACE_AGS30TripodProxy";
				count = 4;
			};
			class _xx_ACE_DSHKMTripodProxy
			{
				weapon = "ACE_DSHKMTripodProxy";
				count = 4;
			};
			class _xx_ACE_2b14TripodProxy
			{
				weapon = "ACE_2b14TripodProxy";
				count = 4;
			};
			class _xx_ACE_KonkursTripodProxy
			{
				weapon = "ACE_KonkursTripodProxy";
				count = 4;
			};
			class _xx_Binocular
			{
				weapon = "Binocular";
				count = 4;
			};
			class _xx_Laserdesignator
			{
				weapon = "Laserdesignator";
				count = 4;
			};
			class _xx_NVGoggles
			{
				weapon = "NVGoggles";
				count = 4;
			};
			class _xx_Binocular_Vector
			{
				weapon = "Binocular_Vector";
				count = 4;
			};
			class _xx_ACE_KeyCuffs
			{
				weapon = "ACE_KeyCuffs";
				count = 4;
			};
			class _xx_ACE_M60
			{
				weapon = "ACE_M60";
				count = 4;
			};
			class _xx_ACE_Flaregun
			{
				weapon = "ACE_Flaregun";
				count = 4;
			};
			class _xx_ACE_Earplugs
			{
				weapon = "ACE_Earplugs";
				count = 4;
			};
			class _xx_ACE_GlassesSunglasses
			{
				weapon = "ACE_GlassesSunglasses";
				count = 4;
			};
			class _xx_ACE_GlassesTactical
			{
				weapon = "ACE_GlassesTactical";
				count = 4;
			};
			class _xx_ACE_GlassesLHD_glasses
			{
				weapon = "ACE_GlassesLHD_glasses";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_US
			{
				weapon = "ACE_GlassesGasMask_US";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_RU
			{
				weapon = "ACE_GlassesGasMask_RU";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklava
			{
				weapon = "ACE_GlassesBalaklava";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaOlive
			{
				weapon = "ACE_GlassesBalaklavaOlive";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaGray
			{
				weapon = "ACE_GlassesBalaklavaGray";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72
			{
				weapon = "ACE_VTAC_RUSH72";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_ACU
			{
				weapon = "ACE_VTAC_RUSH72_ACU";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_TT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_TT_MEDIC";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_FT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_FT_MEDIC";
				count = 4;
			};
			class _xx_ACE_CharliePack
			{
				weapon = "ACE_CharliePack";
				count = 4;
			};
			class _xx_ACE_CharliePack_WMARPAT
			{
				weapon = "ACE_CharliePack_WMARPAT";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU
			{
				weapon = "ACE_CharliePack_ACU";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU_Medic
			{
				weapon = "ACE_CharliePack_ACU_Medic";
				count = 4;
			};
			class _xx_ACE_PRC119
			{
				weapon = "ACE_PRC119";
				count = 4;
			};
			class _xx_ACE_PRC119_MAR
			{
				weapon = "ACE_PRC119_MAR";
				count = 4;
			};
			class _xx_ACE_PRC119_ACU
			{
				weapon = "ACE_PRC119_ACU";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC
			{
				weapon = "ACE_FAST_PackEDC";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC_ACU
			{
				weapon = "ACE_FAST_PackEDC_ACU";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack
			{
				weapon = "ACE_Coyote_Pack";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack_Black
			{
				weapon = "ACE_Coyote_Pack_Black";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR
			{
				weapon = "ACE_BackPack_ACR";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_FL
			{
				weapon = "ACE_BackPack_ACR_FL";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_TT
			{
				weapon = "ACE_BackPack_ACR_TT";
				count = 4;
			};
			class _xx_ACE_ALICE_Backpack
			{
				weapon = "ACE_ALICE_Backpack";
				count = 4;
			};
			class _xx_ACE_Backpack_US
			{
				weapon = "ACE_Backpack_US";
				count = 4;
			};
			class _xx_ACE_Backpack_FL
			{
				weapon = "ACE_Backpack_FL";
				count = 4;
			};
			class _xx_ACE_Backpack_TT
			{
				weapon = "ACE_Backpack_TT";
				count = 4;
			};
			class _xx_ACE_P159_RD90
			{
				weapon = "ACE_P159_RD90";
				count = 4;
			};
			class _xx_ACE_P159_RD54
			{
				weapon = "ACE_P159_RD54";
				count = 4;
			};
			class _xx_ACE_P159_RD99
			{
				weapon = "ACE_P159_RD99";
				count = 4;
			};
			class _xx_ACE_Kestrel4500
			{
				weapon = "ACE_Kestrel4500";
				count = 4;
			};
			class _xx_ACE_WireCutter
			{
				weapon = "ACE_WireCutter";
				count = 4;
			};
			class _xx_ACE_HuntIR_monitor
			{
				weapon = "ACE_HuntIR_monitor";
				count = 4;
			};
			class _xx_ACE_Rangefinder_OD
			{
				weapon = "ACE_Rangefinder_OD";
				count = 4;
			};
			class _xx_ACE_YardAge450
			{
				weapon = "ACE_YardAge450";
				count = 4;
			};
			class _xx_ACE_MX2A
			{
				weapon = "ACE_MX2A";
				count = 4;
			};
			class _xx_ACE_SpottingScope
			{
				weapon = "ACE_SpottingScope";
				count = 4;
			};
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 4;
			};
			class _xx_ACE_M220TripodProxy
			{
				weapon = "ACE_M220TripodProxy";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_30Rnd_9x19_MP5
			{
				magazine = "30Rnd_9x19_MP5";
				count = 16;
			};
			class _xx_30Rnd_9x19_MP5SD
			{
				magazine = "30Rnd_9x19_MP5SD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_64Rnd_9x19_Bizon
			{
				magazine = "64Rnd_9x19_Bizon";
				count = 16;
			};
			class _xx_64Rnd_9x19_SD_Bizon
			{
				magazine = "64Rnd_9x19_SD_Bizon";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_BBetty_M
			{
				magazine = "ACE_BBetty_M";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_DSHKM_CSWDM
			{
				magazine = "ACE_DSHKM_CSWDM";
				count = 16;
			};
			class _xx_ACE_AGS30_CSWDM
			{
				magazine = "ACE_AGS30_CSWDM";
				count = 16;
			};
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 16;
			};
			class _xx_ACE_KonkursM_CSWDM
			{
				magazine = "ACE_KonkursM_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_CDF: USBasicAmmunitionBox_EP1
	{
		displayName = "CDF Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_30Rnd_9x19_MP5
			{
				magazine = "30Rnd_9x19_MP5";
				count = 16;
			};
			class _xx_30Rnd_9x19_MP5SD
			{
				magazine = "30Rnd_9x19_MP5SD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_64Rnd_9x19_Bizon
			{
				magazine = "64Rnd_9x19_Bizon";
				count = 16;
			};
			class _xx_64Rnd_9x19_SD_Bizon
			{
				magazine = "64Rnd_9x19_SD_Bizon";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_BBetty_M
			{
				magazine = "ACE_BBetty_M";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_DSHKM_CSWDM
			{
				magazine = "ACE_DSHKM_CSWDM";
				count = 16;
			};
			class _xx_ACE_AGS30_CSWDM
			{
				magazine = "ACE_AGS30_CSWDM";
				count = 16;
			};
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 16;
			};
			class _xx_ACE_KonkursM_CSWDM
			{
				magazine = "ACE_KonkursM_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_OrdnanceBox_CDF: USBasicWeapons_EP1
	{
		displayName = "CDF Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 16;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 16;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 16;
			};
			class _xx_SmokeShellBlue
			{
				magazine = "SmokeShellBlue";
				count = 16;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 16;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 16;
			};
			class _xx_SmokeShellPurple
			{
				magazine = "SmokeShellPurple";
				count = 16;
			};
			class _xx_SmokeShellRed
			{
				magazine = "SmokeShellRed";
				count = 16;
			};
			class _xx_SmokeShellYellow
			{
				magazine = "SmokeShellYellow";
				count = 16;
			};
			class _xx_IR_Strobe_Marker
			{
				magazine = "IR_Strobe_Marker";
				count = 16;
			};
			class _xx_IR_Strobe_Target
			{
				magazine = "IR_Strobe_Target";
				count = 16;
			};
			class _xx_ACE_RDG2
			{
				magazine = "ACE_RDG2";
				count = 16;
			};
			class _xx_ACE_RDGM
			{
				magazine = "ACE_RDGM";
				count = 16;
			};
			class _xx_ACE_TORCH_C
			{
				magazine = "ACE_TORCH_C";
				count = 16;
			};
			class _xx_ACE_RG60A
			{
				magazine = "ACE_RG60A";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 16;
			};
			class _xx_MineE
			{
				magazine = "MineE";
				count = 16;
			};
			class _xx_PMC_ied_v1
			{
				magazine = "PMC_ied_v1";
				count = 16;
			};
			class _xx_PMC_ied_v2
			{
				magazine = "PMC_ied_v2";
				count = 16;
			};
			class _xx_PMC_ied_v3
			{
				magazine = "PMC_ied_v3";
				count = 16;
			};
			class _xx_PMC_ied_v4
			{
				magazine = "PMC_ied_v4";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_Launchers_CDF: USBasicWeapons_EP1
	{
		displayName = "CDF Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_RPG7V
			{
				weapon = "RPG7V";
				count = 4;
			};
			class _xx_Strela
			{
				weapon = "Strela";
				count = 4;
			};
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 4;
			};
			class _xx_ACE_RPG7V_PGO7
			{
				weapon = "ACE_RPG7V_PGO7";
				count = 4;
			};
			class _xx_ACE_RPG29
			{
				weapon = "ACE_RPG29";
				count = 4;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 4;
			};
			class _xx_ACE_RPG27
			{
				weapon = "ACE_RPG27";
				count = 4;
			};
			class _xx_ACE_RSHG1
			{
				weapon = "ACE_RSHG1";
				count = 4;
			};
			class _xx_ACE_RMG
			{
				weapon = "ACE_RMG";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 4;
			};
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_JerryCan_Dummy_15
			{
				weapon = "ACE_JerryCan_Dummy_15";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Strela
			{
				magazine = "Strela";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_Launchers_CDF: USBasicAmmunitionBox_EP1
	{
		displayName = "CDF Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 16;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 16;
			};
			class _xx_ACE_RPG27
			{
				weapon = "ACE_RPG27";
				count = 16;
			};
			class _xx_ACE_RSHG1
			{
				weapon = "ACE_RSHG1";
				count = 16;
			};
			class _xx_ACE_RMG
			{
				weapon = "ACE_RMG";
				count = 16;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Strela
			{
				magazine = "Strela";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_INS: USBasicWeapons_EP1
	{
		displayName = "Insurgents Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_Makarov
			{
				weapon = "Makarov";
				count = 4;
			};
			class _xx_MakarovSD
			{
				weapon = "MakarovSD";
				count = 4;
			};
			class _xx_PK
			{
				weapon = "PK";
				count = 4;
			};
			class _xx_SVD
			{
				weapon = "SVD";
				count = 4;
			};
			class _xx_SVD_CAMO
			{
				weapon = "SVD_CAMO";
				count = 4;
			};
			class _xx_AK_47_M
			{
				weapon = "AK_47_M";
				count = 4;
			};
			class _xx_AK_47_S
			{
				weapon = "AK_47_S";
				count = 4;
			};
			class _xx_AKS_GOLD
			{
				weapon = "AKS_GOLD";
				count = 4;
			};
			class _xx_AK_74
			{
				weapon = "AK_74";
				count = 4;
			};
			class _xx_AK_74_GL
			{
				weapon = "AK_74_GL";
				count = 4;
			};
			class _xx_AKS_74_kobra
			{
				weapon = "AKS_74_kobra";
				count = 4;
			};
			class _xx_AKS_74_pso
			{
				weapon = "AKS_74_pso";
				count = 4;
			};
			class _xx_AKS_74_U
			{
				weapon = "AKS_74_U";
				count = 4;
			};
			class _xx_AKS_74_UN_kobra
			{
				weapon = "AKS_74_UN_kobra";
				count = 4;
			};
			class _xx_RPK_74
			{
				weapon = "RPK_74";
				count = 4;
			};
			class _xx_ksvk
			{
				weapon = "ksvk";
				count = 4;
			};
			class _xx_Saiga12K
			{
				weapon = "Saiga12K";
				count = 4;
			};
			class _xx_ACE_M3A1
			{
				weapon = "ACE_M3A1";
				count = 4;
			};
			class _xx_huntingrifle
			{
				weapon = "huntingrifle";
				count = 4;
			};
			class _xx_Sa61_EP1
			{
				weapon = "Sa61_EP1";
				count = 4;
			};
			class _xx_UZI_EP1
			{
				weapon = "UZI_EP1";
				count = 4;
			};
			class _xx_UZI_SD_EP1
			{
				weapon = "UZI_SD_EP1";
				count = 4;
			};
			class _xx_revolver_EP1
			{
				weapon = "revolver_EP1";
				count = 4;
			};
			class _xx_revolver_gold_EP1
			{
				weapon = "revolver_gold_EP1";
				count = 4;
			};
			class _xx_SVD_des_EP1
			{
				weapon = "SVD_des_EP1";
				count = 4;
			};
			class _xx_SVD_NSPU_EP1
			{
				weapon = "SVD_NSPU_EP1";
				count = 4;
			};
			class _xx_AK_74_GL_kobra
			{
				weapon = "AK_74_GL_kobra";
				count = 4;
			};
			class _xx_AKS_74
			{
				weapon = "AKS_74";
				count = 4;
			};
			class _xx_AKS_74_NSPU
			{
				weapon = "AKS_74_NSPU";
				count = 4;
			};
			class _xx_AKS_74_GOSHAWK
			{
				weapon = "AKS_74_GOSHAWK";
				count = 4;
			};
			class _xx_LeeEnfield
			{
				weapon = "LeeEnfield";
				count = 4;
			};
			class _xx_ACE_TT
			{
				weapon = "ACE_TT";
				count = 4;
			};
			class _xx_ACE_AKS74_GP25
			{
				weapon = "ACE_AKS74_GP25";
				count = 4;
			};
			class _xx_ACE_AKS74_UN
			{
				weapon = "ACE_AKS74_UN";
				count = 4;
			};
			class _xx_ACE_AKS74P
			{
				weapon = "ACE_AKS74P";
				count = 4;
			};
			class _xx_ACE_AKS74P_Kobra
			{
				weapon = "ACE_AKS74P_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_1P29
			{
				weapon = "ACE_AKS74P_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_PSO
			{
				weapon = "ACE_AKS74P_PSO";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL
			{
				weapon = "ACE_AKS74P_GL";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_Kobra
			{
				weapon = "ACE_AKS74P_GL_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_1P29
			{
				weapon = "ACE_AKS74P_GL_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_PSO
			{
				weapon = "ACE_AKS74P_GL_PSO";
				count = 4;
			};
			class _xx_ACE_AKM
			{
				weapon = "ACE_AKM";
				count = 4;
			};
			class _xx_ACE_AKM_GL
			{
				weapon = "ACE_AKM_GL";
				count = 4;
			};
			class _xx_ACE_AKMS
			{
				weapon = "ACE_AKMS";
				count = 4;
			};
			class _xx_ACE_AKMS_SD
			{
				weapon = "ACE_AKMS_SD";
				count = 4;
			};
			class _xx_ACE_RPK
			{
				weapon = "ACE_RPK";
				count = 4;
			};
			class _xx_ACE_SKS
			{
				weapon = "ACE_SKS";
				count = 4;
			};
			class _xx_ACE_SVD_Bipod
			{
				weapon = "ACE_SVD_Bipod";
				count = 4;
			};
			class _xx_ACE_DSHKMProxy
			{
				weapon = "ACE_DSHKMProxy";
				count = 4;
			};
			class _xx_ACE_AGS30Proxy
			{
				weapon = "ACE_AGS30Proxy";
				count = 4;
			};
			class _xx_ACE_2b14Proxy
			{
				weapon = "ACE_2b14Proxy";
				count = 4;
			};
			class _xx_ACE_AGS30TripodProxy
			{
				weapon = "ACE_AGS30TripodProxy";
				count = 4;
			};
			class _xx_ACE_DSHKMTripodProxy
			{
				weapon = "ACE_DSHKMTripodProxy";
				count = 4;
			};
			class _xx_ACE_2b14TripodProxy
			{
				weapon = "ACE_2b14TripodProxy";
				count = 4;
			};
			class _xx_ACE_KonkursTripodProxy
			{
				weapon = "ACE_KonkursTripodProxy";
				count = 4;
			};
			class _xx_Binocular
			{
				weapon = "Binocular";
				count = 4;
			};
			class _xx_Laserdesignator
			{
				weapon = "Laserdesignator";
				count = 4;
			};
			class _xx_NVGoggles
			{
				weapon = "NVGoggles";
				count = 4;
			};
			class _xx_Binocular_Vector
			{
				weapon = "Binocular_Vector";
				count = 4;
			};
			class _xx_ACE_KeyCuffs
			{
				weapon = "ACE_KeyCuffs";
				count = 4;
			};
			class _xx_ACE_M60
			{
				weapon = "ACE_M60";
				count = 4;
			};
			class _xx_ACE_Flaregun
			{
				weapon = "ACE_Flaregun";
				count = 4;
			};
			class _xx_ACE_Earplugs
			{
				weapon = "ACE_Earplugs";
				count = 4;
			};
			class _xx_ACE_GlassesSunglasses
			{
				weapon = "ACE_GlassesSunglasses";
				count = 4;
			};
			class _xx_ACE_GlassesTactical
			{
				weapon = "ACE_GlassesTactical";
				count = 4;
			};
			class _xx_ACE_GlassesLHD_glasses
			{
				weapon = "ACE_GlassesLHD_glasses";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_US
			{
				weapon = "ACE_GlassesGasMask_US";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_RU
			{
				weapon = "ACE_GlassesGasMask_RU";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklava
			{
				weapon = "ACE_GlassesBalaklava";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaOlive
			{
				weapon = "ACE_GlassesBalaklavaOlive";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaGray
			{
				weapon = "ACE_GlassesBalaklavaGray";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72
			{
				weapon = "ACE_VTAC_RUSH72";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_ACU
			{
				weapon = "ACE_VTAC_RUSH72_ACU";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_TT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_TT_MEDIC";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_FT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_FT_MEDIC";
				count = 4;
			};
			class _xx_ACE_CharliePack
			{
				weapon = "ACE_CharliePack";
				count = 4;
			};
			class _xx_ACE_CharliePack_WMARPAT
			{
				weapon = "ACE_CharliePack_WMARPAT";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU
			{
				weapon = "ACE_CharliePack_ACU";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU_Medic
			{
				weapon = "ACE_CharliePack_ACU_Medic";
				count = 4;
			};
			class _xx_ACE_PRC119
			{
				weapon = "ACE_PRC119";
				count = 4;
			};
			class _xx_ACE_PRC119_MAR
			{
				weapon = "ACE_PRC119_MAR";
				count = 4;
			};
			class _xx_ACE_PRC119_ACU
			{
				weapon = "ACE_PRC119_ACU";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC
			{
				weapon = "ACE_FAST_PackEDC";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC_ACU
			{
				weapon = "ACE_FAST_PackEDC_ACU";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack
			{
				weapon = "ACE_Coyote_Pack";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack_Black
			{
				weapon = "ACE_Coyote_Pack_Black";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR
			{
				weapon = "ACE_BackPack_ACR";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_FL
			{
				weapon = "ACE_BackPack_ACR_FL";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_TT
			{
				weapon = "ACE_BackPack_ACR_TT";
				count = 4;
			};
			class _xx_ACE_ALICE_Backpack
			{
				weapon = "ACE_ALICE_Backpack";
				count = 4;
			};
			class _xx_ACE_Backpack_US
			{
				weapon = "ACE_Backpack_US";
				count = 4;
			};
			class _xx_ACE_Backpack_FL
			{
				weapon = "ACE_Backpack_FL";
				count = 4;
			};
			class _xx_ACE_Backpack_TT
			{
				weapon = "ACE_Backpack_TT";
				count = 4;
			};
			class _xx_ACE_P159_RD90
			{
				weapon = "ACE_P159_RD90";
				count = 4;
			};
			class _xx_ACE_P159_RD54
			{
				weapon = "ACE_P159_RD54";
				count = 4;
			};
			class _xx_ACE_P159_RD99
			{
				weapon = "ACE_P159_RD99";
				count = 4;
			};
			class _xx_ACE_Kestrel4500
			{
				weapon = "ACE_Kestrel4500";
				count = 4;
			};
			class _xx_ACE_WireCutter
			{
				weapon = "ACE_WireCutter";
				count = 4;
			};
			class _xx_ACE_HuntIR_monitor
			{
				weapon = "ACE_HuntIR_monitor";
				count = 4;
			};
			class _xx_ACE_Rangefinder_OD
			{
				weapon = "ACE_Rangefinder_OD";
				count = 4;
			};
			class _xx_ACE_YardAge450
			{
				weapon = "ACE_YardAge450";
				count = 4;
			};
			class _xx_ACE_MX2A
			{
				weapon = "ACE_MX2A";
				count = 4;
			};
			class _xx_ACE_SpottingScope
			{
				weapon = "ACE_SpottingScope";
				count = 4;
			};
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 4;
			};
			class _xx_ACE_M220TripodProxy
			{
				weapon = "ACE_M220TripodProxy";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_ACE_30Rnd_1143x23_B_M3
			{
				magazine = "ACE_30Rnd_1143x23_B_M3";
				count = 16;
			};
			class _xx_5x_22_LR_17_HMR
			{
				magazine = "5x_22_LR_17_HMR";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_30Rnd_9x19_UZI
			{
				magazine = "30Rnd_9x19_UZI";
				count = 16;
			};
			class _xx_30Rnd_9x19_UZI_SD
			{
				magazine = "30Rnd_9x19_UZI_SD";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_10x_303
			{
				magazine = "10x_303";
				count = 16;
			};
			class _xx_ACE_10Rnd_77x56_T_SMLE
			{
				magazine = "ACE_10Rnd_77x56_T_SMLE";
				count = 16;
			};
			class _xx_ACE_8Rnd_762x25_B_Tokarev
			{
				magazine = "ACE_8Rnd_762x25_B_Tokarev";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_B_SKS
			{
				magazine = "ACE_10Rnd_762x39_B_SKS";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_T_SKS
			{
				magazine = "ACE_10Rnd_762x39_T_SKS";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_BBetty_M
			{
				magazine = "ACE_BBetty_M";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_DSHKM_CSWDM
			{
				magazine = "ACE_DSHKM_CSWDM";
				count = 16;
			};
			class _xx_ACE_AGS30_CSWDM
			{
				magazine = "ACE_AGS30_CSWDM";
				count = 16;
			};
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_INS: USBasicAmmunitionBox_EP1
	{
		displayName = "Insurgents Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_ACE_30Rnd_1143x23_B_M3
			{
				magazine = "ACE_30Rnd_1143x23_B_M3";
				count = 16;
			};
			class _xx_5x_22_LR_17_HMR
			{
				magazine = "5x_22_LR_17_HMR";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_30Rnd_9x19_UZI
			{
				magazine = "30Rnd_9x19_UZI";
				count = 16;
			};
			class _xx_30Rnd_9x19_UZI_SD
			{
				magazine = "30Rnd_9x19_UZI_SD";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_10x_303
			{
				magazine = "10x_303";
				count = 16;
			};
			class _xx_ACE_10Rnd_77x56_T_SMLE
			{
				magazine = "ACE_10Rnd_77x56_T_SMLE";
				count = 16;
			};
			class _xx_ACE_8Rnd_762x25_B_Tokarev
			{
				magazine = "ACE_8Rnd_762x25_B_Tokarev";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_B_SKS
			{
				magazine = "ACE_10Rnd_762x39_B_SKS";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_T_SKS
			{
				magazine = "ACE_10Rnd_762x39_T_SKS";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_BBetty_M
			{
				magazine = "ACE_BBetty_M";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_DSHKM_CSWDM
			{
				magazine = "ACE_DSHKM_CSWDM";
				count = 16;
			};
			class _xx_ACE_AGS30_CSWDM
			{
				magazine = "ACE_AGS30_CSWDM";
				count = 16;
			};
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_OrdnanceBox_INS: USBasicWeapons_EP1
	{
		displayName = "Insurgents Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 16;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 16;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 16;
			};
			class _xx_SmokeShellBlue
			{
				magazine = "SmokeShellBlue";
				count = 16;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 16;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 16;
			};
			class _xx_SmokeShellPurple
			{
				magazine = "SmokeShellPurple";
				count = 16;
			};
			class _xx_SmokeShellRed
			{
				magazine = "SmokeShellRed";
				count = 16;
			};
			class _xx_SmokeShellYellow
			{
				magazine = "SmokeShellYellow";
				count = 16;
			};
			class _xx_IR_Strobe_Marker
			{
				magazine = "IR_Strobe_Marker";
				count = 16;
			};
			class _xx_IR_Strobe_Target
			{
				magazine = "IR_Strobe_Target";
				count = 16;
			};
			class _xx_ACE_RDG2
			{
				magazine = "ACE_RDG2";
				count = 16;
			};
			class _xx_ACE_RDGM
			{
				magazine = "ACE_RDGM";
				count = 16;
			};
			class _xx_ACE_TORCH_C
			{
				magazine = "ACE_TORCH_C";
				count = 16;
			};
			class _xx_ACE_RG60A
			{
				magazine = "ACE_RG60A";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 16;
			};
			class _xx_MineE
			{
				magazine = "MineE";
				count = 16;
			};
			class _xx_BAF_ied_v1
			{
				magazine = "BAF_ied_v1";
				count = 16;
			};
			class _xx_BAF_ied_v2
			{
				magazine = "BAF_ied_v2";
				count = 16;
			};
			class _xx_BAF_ied_v3
			{
				magazine = "BAF_ied_v3";
				count = 16;
			};
			class _xx_BAF_ied_v4
			{
				magazine = "BAF_ied_v4";
				count = 16;
			};
			class _xx_PMC_ied_v1
			{
				magazine = "PMC_ied_v1";
				count = 16;
			};
			class _xx_PMC_ied_v2
			{
				magazine = "PMC_ied_v2";
				count = 16;
			};
			class _xx_PMC_ied_v3
			{
				magazine = "PMC_ied_v3";
				count = 16;
			};
			class _xx_PMC_ied_v4
			{
				magazine = "PMC_ied_v4";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_Launchers_INS: USBasicWeapons_EP1
	{
		displayName = "Insurgents Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_RPG7V
			{
				weapon = "RPG7V";
				count = 4;
			};
			class _xx_Strela
			{
				weapon = "Strela";
				count = 4;
			};
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 4;
			};
			class _xx_M47Launcher_EP1
			{
				weapon = "M47Launcher_EP1";
				count = 4;
			};
			class _xx_ACE_RPG7V_PGO7
			{
				weapon = "ACE_RPG7V_PGO7";
				count = 4;
			};
			class _xx_ACE_RPG29
			{
				weapon = "ACE_RPG29";
				count = 4;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 4;
			};
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_JerryCan_Dummy_15
			{
				weapon = "ACE_JerryCan_Dummy_15";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Strela
			{
				magazine = "Strela";
				count = 16;
			};
			class _xx_Dragon_EP1
			{
				magazine = "Dragon_EP1";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_Launchers_INS: USBasicAmmunitionBox_EP1
	{
		displayName = "Insurgents Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 16;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 16;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Strela
			{
				magazine = "Strela";
				count = 16;
			};
			class _xx_Dragon_EP1
			{
				magazine = "Dragon_EP1";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_GUE: USBasicWeapons_EP1
	{
		displayName = "Guerillas Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_Makarov
			{
				weapon = "Makarov";
				count = 4;
			};
			class _xx_MakarovSD
			{
				weapon = "MakarovSD";
				count = 4;
			};
			class _xx_PK
			{
				weapon = "PK";
				count = 4;
			};
			class _xx_SVD
			{
				weapon = "SVD";
				count = 4;
			};
			class _xx_SVD_CAMO
			{
				weapon = "SVD_CAMO";
				count = 4;
			};
			class _xx_AK_47_M
			{
				weapon = "AK_47_M";
				count = 4;
			};
			class _xx_AK_47_S
			{
				weapon = "AK_47_S";
				count = 4;
			};
			class _xx_AKS_GOLD
			{
				weapon = "AKS_GOLD";
				count = 4;
			};
			class _xx_AK_74
			{
				weapon = "AK_74";
				count = 4;
			};
			class _xx_AK_74_GL
			{
				weapon = "AK_74_GL";
				count = 4;
			};
			class _xx_AKS_74_kobra
			{
				weapon = "AKS_74_kobra";
				count = 4;
			};
			class _xx_AKS_74_pso
			{
				weapon = "AKS_74_pso";
				count = 4;
			};
			class _xx_AKS_74_U
			{
				weapon = "AKS_74_U";
				count = 4;
			};
			class _xx_AKS_74_UN_kobra
			{
				weapon = "AKS_74_UN_kobra";
				count = 4;
			};
			class _xx_RPK_74
			{
				weapon = "RPK_74";
				count = 4;
			};
			class _xx_ksvk
			{
				weapon = "ksvk";
				count = 4;
			};
			class _xx_Saiga12K
			{
				weapon = "Saiga12K";
				count = 4;
			};
			class _xx_ACE_M3A1
			{
				weapon = "ACE_M3A1";
				count = 4;
			};
			class _xx_huntingrifle
			{
				weapon = "huntingrifle";
				count = 4;
			};
			class _xx_Sa61_EP1
			{
				weapon = "Sa61_EP1";
				count = 4;
			};
			class _xx_revolver_EP1
			{
				weapon = "revolver_EP1";
				count = 4;
			};
			class _xx_revolver_gold_EP1
			{
				weapon = "revolver_gold_EP1";
				count = 4;
			};
			class _xx_SVD_des_EP1
			{
				weapon = "SVD_des_EP1";
				count = 4;
			};
			class _xx_SVD_NSPU_EP1
			{
				weapon = "SVD_NSPU_EP1";
				count = 4;
			};
			class _xx_AK_74_GL_kobra
			{
				weapon = "AK_74_GL_kobra";
				count = 4;
			};
			class _xx_AKS_74
			{
				weapon = "AKS_74";
				count = 4;
			};
			class _xx_AKS_74_NSPU
			{
				weapon = "AKS_74_NSPU";
				count = 4;
			};
			class _xx_AKS_74_GOSHAWK
			{
				weapon = "AKS_74_GOSHAWK";
				count = 4;
			};
			class _xx_M79_EP1
			{
				weapon = "M79_EP1";
				count = 4;
			};
			class _xx_LeeEnfield
			{
				weapon = "LeeEnfield";
				count = 4;
			};
			class _xx_ACE_TT
			{
				weapon = "ACE_TT";
				count = 4;
			};
			class _xx_ACE_AKS74_GP25
			{
				weapon = "ACE_AKS74_GP25";
				count = 4;
			};
			class _xx_ACE_AKS74_UN
			{
				weapon = "ACE_AKS74_UN";
				count = 4;
			};
			class _xx_ACE_AKS74P
			{
				weapon = "ACE_AKS74P";
				count = 4;
			};
			class _xx_ACE_AKS74P_Kobra
			{
				weapon = "ACE_AKS74P_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_1P29
			{
				weapon = "ACE_AKS74P_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_PSO
			{
				weapon = "ACE_AKS74P_PSO";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL
			{
				weapon = "ACE_AKS74P_GL";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_Kobra
			{
				weapon = "ACE_AKS74P_GL_Kobra";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_1P29
			{
				weapon = "ACE_AKS74P_GL_1P29";
				count = 4;
			};
			class _xx_ACE_AKS74P_GL_PSO
			{
				weapon = "ACE_AKS74P_GL_PSO";
				count = 4;
			};
			class _xx_ACE_AKM
			{
				weapon = "ACE_AKM";
				count = 4;
			};
			class _xx_ACE_AKM_GL
			{
				weapon = "ACE_AKM_GL";
				count = 4;
			};
			class _xx_ACE_AKMS
			{
				weapon = "ACE_AKMS";
				count = 4;
			};
			class _xx_ACE_AKMS_SD
			{
				weapon = "ACE_AKMS_SD";
				count = 4;
			};
			class _xx_ACE_RPK
			{
				weapon = "ACE_RPK";
				count = 4;
			};
			class _xx_ACE_SKS
			{
				weapon = "ACE_SKS";
				count = 4;
			};
			class _xx_ACE_SVD_Bipod
			{
				weapon = "ACE_SVD_Bipod";
				count = 4;
			};
			class _xx_ACE_DSHKMProxy
			{
				weapon = "ACE_DSHKMProxy";
				count = 4;
			};
			class _xx_ACE_DSHKMTripodProxy
			{
				weapon = "ACE_DSHKMTripodProxy";
				count = 4;
			};
			class _xx_Binocular
			{
				weapon = "Binocular";
				count = 4;
			};
			class _xx_Laserdesignator
			{
				weapon = "Laserdesignator";
				count = 4;
			};
			class _xx_NVGoggles
			{
				weapon = "NVGoggles";
				count = 4;
			};
			class _xx_Binocular_Vector
			{
				weapon = "Binocular_Vector";
				count = 4;
			};
			class _xx_ACE_KeyCuffs
			{
				weapon = "ACE_KeyCuffs";
				count = 4;
			};
			class _xx_ACE_M60
			{
				weapon = "ACE_M60";
				count = 4;
			};
			class _xx_ACE_Flaregun
			{
				weapon = "ACE_Flaregun";
				count = 4;
			};
			class _xx_ACE_Earplugs
			{
				weapon = "ACE_Earplugs";
				count = 4;
			};
			class _xx_ACE_GlassesSunglasses
			{
				weapon = "ACE_GlassesSunglasses";
				count = 4;
			};
			class _xx_ACE_GlassesTactical
			{
				weapon = "ACE_GlassesTactical";
				count = 4;
			};
			class _xx_ACE_GlassesLHD_glasses
			{
				weapon = "ACE_GlassesLHD_glasses";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_US
			{
				weapon = "ACE_GlassesGasMask_US";
				count = 4;
			};
			class _xx_ACE_GlassesGasMask_RU
			{
				weapon = "ACE_GlassesGasMask_RU";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklava
			{
				weapon = "ACE_GlassesBalaklava";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaOlive
			{
				weapon = "ACE_GlassesBalaklavaOlive";
				count = 4;
			};
			class _xx_ACE_GlassesBalaklavaGray
			{
				weapon = "ACE_GlassesBalaklavaGray";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72
			{
				weapon = "ACE_VTAC_RUSH72";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_ACU
			{
				weapon = "ACE_VTAC_RUSH72_ACU";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_TT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_TT_MEDIC";
				count = 4;
			};
			class _xx_ACE_VTAC_RUSH72_FT_MEDIC
			{
				weapon = "ACE_VTAC_RUSH72_FT_MEDIC";
				count = 4;
			};
			class _xx_ACE_CharliePack
			{
				weapon = "ACE_CharliePack";
				count = 4;
			};
			class _xx_ACE_CharliePack_WMARPAT
			{
				weapon = "ACE_CharliePack_WMARPAT";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU
			{
				weapon = "ACE_CharliePack_ACU";
				count = 4;
			};
			class _xx_ACE_CharliePack_ACU_Medic
			{
				weapon = "ACE_CharliePack_ACU_Medic";
				count = 4;
			};
			class _xx_ACE_PRC119
			{
				weapon = "ACE_PRC119";
				count = 4;
			};
			class _xx_ACE_PRC119_MAR
			{
				weapon = "ACE_PRC119_MAR";
				count = 4;
			};
			class _xx_ACE_PRC119_ACU
			{
				weapon = "ACE_PRC119_ACU";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC
			{
				weapon = "ACE_FAST_PackEDC";
				count = 4;
			};
			class _xx_ACE_FAST_PackEDC_ACU
			{
				weapon = "ACE_FAST_PackEDC_ACU";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack
			{
				weapon = "ACE_Coyote_Pack";
				count = 4;
			};
			class _xx_ACE_Coyote_Pack_Black
			{
				weapon = "ACE_Coyote_Pack_Black";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR
			{
				weapon = "ACE_BackPack_ACR";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_FL
			{
				weapon = "ACE_BackPack_ACR_FL";
				count = 4;
			};
			class _xx_ACE_BackPack_ACR_TT
			{
				weapon = "ACE_BackPack_ACR_TT";
				count = 4;
			};
			class _xx_ACE_ALICE_Backpack
			{
				weapon = "ACE_ALICE_Backpack";
				count = 4;
			};
			class _xx_ACE_Backpack_US
			{
				weapon = "ACE_Backpack_US";
				count = 4;
			};
			class _xx_ACE_Backpack_FL
			{
				weapon = "ACE_Backpack_FL";
				count = 4;
			};
			class _xx_ACE_Backpack_TT
			{
				weapon = "ACE_Backpack_TT";
				count = 4;
			};
			class _xx_ACE_P159_RD90
			{
				weapon = "ACE_P159_RD90";
				count = 4;
			};
			class _xx_ACE_P159_RD54
			{
				weapon = "ACE_P159_RD54";
				count = 4;
			};
			class _xx_ACE_P159_RD99
			{
				weapon = "ACE_P159_RD99";
				count = 4;
			};
			class _xx_ACE_Kestrel4500
			{
				weapon = "ACE_Kestrel4500";
				count = 4;
			};
			class _xx_ACE_WireCutter
			{
				weapon = "ACE_WireCutter";
				count = 4;
			};
			class _xx_ACE_HuntIR_monitor
			{
				weapon = "ACE_HuntIR_monitor";
				count = 4;
			};
			class _xx_ACE_Rangefinder_OD
			{
				weapon = "ACE_Rangefinder_OD";
				count = 4;
			};
			class _xx_ACE_YardAge450
			{
				weapon = "ACE_YardAge450";
				count = 4;
			};
			class _xx_ACE_MX2A
			{
				weapon = "ACE_MX2A";
				count = 4;
			};
			class _xx_ACE_SpottingScope
			{
				weapon = "ACE_SpottingScope";
				count = 4;
			};
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 4;
			};
			class _xx_ACE_M220TripodProxy
			{
				weapon = "ACE_M220TripodProxy";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_ACE_30Rnd_1143x23_B_M3
			{
				magazine = "ACE_30Rnd_1143x23_B_M3";
				count = 16;
			};
			class _xx_5x_22_LR_17_HMR
			{
				magazine = "5x_22_LR_17_HMR";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_1Rnd_HE_M203
			{
				magazine = "1Rnd_HE_M203";
				count = 16;
			};
			class _xx_FlareWhite_M203
			{
				magazine = "FlareWhite_M203";
				count = 16;
			};
			class _xx_FlareGreen_M203
			{
				magazine = "FlareGreen_M203";
				count = 16;
			};
			class _xx_FlareRed_M203
			{
				magazine = "FlareRed_M203";
				count = 16;
			};
			class _xx_FlareYellow_M203
			{
				magazine = "FlareYellow_M203";
				count = 16;
			};
			class _xx_1Rnd_Smoke_M203
			{
				magazine = "1Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_M203
			{
				magazine = "1Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_M203
			{
				magazine = "1Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_M203
			{
				magazine = "1Rnd_SmokeYellow_M203";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_M203
			{
				magazine = "ACE_1Rnd_HE_M203";
				count = 16;
			};
			class _xx_ACE_1Rnd_PR_M203
			{
				magazine = "ACE_1Rnd_PR_M203";
				count = 16;
			};
			class _xx_ACE_FlareIR_M203
			{
				magazine = "ACE_FlareIR_M203";
				count = 16;
			};
			class _xx_ACE_SSWhite_M203
			{
				magazine = "ACE_SSWhite_M203";
				count = 16;
			};
			class _xx_ACE_SSGreen_M203
			{
				magazine = "ACE_SSGreen_M203";
				count = 16;
			};
			class _xx_ACE_SSRed_M203
			{
				magazine = "ACE_SSRed_M203";
				count = 16;
			};
			class _xx_ACE_SSYellow_M203
			{
				magazine = "ACE_SSYellow_M203";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_M203
			{
				magazine = "ACE_1Rnd_CS_M203";
				count = 16;
			};
			class _xx_ACE_HuntIR_M203
			{
				magazine = "ACE_HuntIR_M203";
				count = 16;
			};
			class _xx_10x_303
			{
				magazine = "10x_303";
				count = 16;
			};
			class _xx_ACE_10Rnd_77x56_T_SMLE
			{
				magazine = "ACE_10Rnd_77x56_T_SMLE";
				count = 16;
			};
			class _xx_ACE_8Rnd_762x25_B_Tokarev
			{
				magazine = "ACE_8Rnd_762x25_B_Tokarev";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_B_SKS
			{
				magazine = "ACE_10Rnd_762x39_B_SKS";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_T_SKS
			{
				magazine = "ACE_10Rnd_762x39_T_SKS";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_DSHKM_CSWDM
			{
				magazine = "ACE_DSHKM_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_GUE: USBasicAmmunitionBox_EP1
	{
		displayName = "Guerillas Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 16;
			};
			class _xx_8Rnd_9x18_MakarovSD
			{
				magazine = "8Rnd_9x18_MakarovSD";
				count = 16;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 16;
			};
			class _xx_10Rnd_762x54_SVD
			{
				magazine = "10Rnd_762x54_SVD";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 16;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_SD_AK47
			{
				magazine = "ACE_30Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_B_AK47
			{
				magazine = "ACE_40Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_40Rnd_762x39_T_AK47
			{
				magazine = "ACE_40Rnd_762x39_T_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_B_AK47
			{
				magazine = "ACE_75Rnd_762x39_B_AK47";
				count = 16;
			};
			class _xx_ACE_75Rnd_762x39_SD_AK47
			{
				magazine = "ACE_75Rnd_762x39_SD_AK47";
				count = 16;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 16;
			};
			class _xx_30Rnd_545x39_AKSD
			{
				magazine = "30Rnd_545x39_AKSD";
				count = 16;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 16;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 16;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 16;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 16;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SMOKE_GP25
			{
				magazine = "1Rnd_SMOKE_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_GP25
			{
				magazine = "1Rnd_SmokeGreen_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_GP25
			{
				magazine = "1Rnd_SmokeRed_GP25";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_GP25
			{
				magazine = "1Rnd_SmokeYellow_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_GP25P
			{
				magazine = "ACE_1Rnd_HE_GP25P";
				count = 16;
			};
			class _xx_ACE_SSGreen_GP25
			{
				magazine = "ACE_SSGreen_GP25";
				count = 16;
			};
			class _xx_ACE_SSRed_GP25
			{
				magazine = "ACE_SSRed_GP25";
				count = 16;
			};
			class _xx_ACE_SSWhite_GP25
			{
				magazine = "ACE_SSWhite_GP25";
				count = 16;
			};
			class _xx_ACE_SSYellow_GP25
			{
				magazine = "ACE_SSYellow_GP25";
				count = 16;
			};
			class _xx_FlareGreen_GP25
			{
				magazine = "FlareGreen_GP25";
				count = 16;
			};
			class _xx_FlareRed_GP25
			{
				magazine = "FlareRed_GP25";
				count = 16;
			};
			class _xx_FlareWhite_GP25
			{
				magazine = "FlareWhite_GP25";
				count = 16;
			};
			class _xx_FlareYellow_GP25
			{
				magazine = "FlareYellow_GP25";
				count = 16;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_74Slug
			{
				magazine = "8Rnd_B_Saiga12_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Saiga12_Pellets
			{
				magazine = "8Rnd_B_Saiga12_Pellets";
				count = 16;
			};
			class _xx_ACE_30Rnd_1143x23_B_M3
			{
				magazine = "ACE_30Rnd_1143x23_B_M3";
				count = 16;
			};
			class _xx_5x_22_LR_17_HMR
			{
				magazine = "5x_22_LR_17_HMR";
				count = 16;
			};
			class _xx_10Rnd_B_765x17_Ball
			{
				magazine = "10Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_20Rnd_B_765x17_Ball
			{
				magazine = "20Rnd_B_765x17_Ball";
				count = 16;
			};
			class _xx_6Rnd_45ACP
			{
				magazine = "6Rnd_45ACP";
				count = 16;
			};
			class _xx_1Rnd_HE_M203
			{
				magazine = "1Rnd_HE_M203";
				count = 16;
			};
			class _xx_FlareWhite_M203
			{
				magazine = "FlareWhite_M203";
				count = 16;
			};
			class _xx_FlareGreen_M203
			{
				magazine = "FlareGreen_M203";
				count = 16;
			};
			class _xx_FlareRed_M203
			{
				magazine = "FlareRed_M203";
				count = 16;
			};
			class _xx_FlareYellow_M203
			{
				magazine = "FlareYellow_M203";
				count = 16;
			};
			class _xx_1Rnd_Smoke_M203
			{
				magazine = "1Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_1Rnd_SmokeRed_M203
			{
				magazine = "1Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_1Rnd_SmokeGreen_M203
			{
				magazine = "1Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_1Rnd_SmokeYellow_M203
			{
				magazine = "1Rnd_SmokeYellow_M203";
				count = 16;
			};
			class _xx_ACE_1Rnd_HE_M203
			{
				magazine = "ACE_1Rnd_HE_M203";
				count = 16;
			};
			class _xx_ACE_1Rnd_PR_M203
			{
				magazine = "ACE_1Rnd_PR_M203";
				count = 16;
			};
			class _xx_ACE_FlareIR_M203
			{
				magazine = "ACE_FlareIR_M203";
				count = 16;
			};
			class _xx_ACE_SSWhite_M203
			{
				magazine = "ACE_SSWhite_M203";
				count = 16;
			};
			class _xx_ACE_SSGreen_M203
			{
				magazine = "ACE_SSGreen_M203";
				count = 16;
			};
			class _xx_ACE_SSRed_M203
			{
				magazine = "ACE_SSRed_M203";
				count = 16;
			};
			class _xx_ACE_SSYellow_M203
			{
				magazine = "ACE_SSYellow_M203";
				count = 16;
			};
			class _xx_ACE_1Rnd_CS_M203
			{
				magazine = "ACE_1Rnd_CS_M203";
				count = 16;
			};
			class _xx_ACE_HuntIR_M203
			{
				magazine = "ACE_HuntIR_M203";
				count = 16;
			};
			class _xx_10x_303
			{
				magazine = "10x_303";
				count = 16;
			};
			class _xx_ACE_10Rnd_77x56_T_SMLE
			{
				magazine = "ACE_10Rnd_77x56_T_SMLE";
				count = 16;
			};
			class _xx_ACE_8Rnd_762x25_B_Tokarev
			{
				magazine = "ACE_8Rnd_762x25_B_Tokarev";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_B_SKS
			{
				magazine = "ACE_10Rnd_762x39_B_SKS";
				count = 16;
			};
			class _xx_ACE_10Rnd_762x39_T_SKS
			{
				magazine = "ACE_10Rnd_762x39_T_SKS";
				count = 16;
			};
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 16;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 16;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 16;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 16;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 16;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 16;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 16;
			};
			class _xx_ACE_C4_M
			{
				magazine = "ACE_C4_M";
				count = 16;
			};
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 16;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 16;
			};
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
				count = 16;
			};
			class _xx_ACE_DSHKM_CSWDM
			{
				magazine = "ACE_DSHKM_CSWDM";
				count = 16;
			};
			class _xx_ACE_Rope_M_120
			{
				magazine = "ACE_Rope_M_120";
				count = 16;
			};
			class _xx_ACE_Rope_M_50
			{
				magazine = "ACE_Rope_M_50";
				count = 16;
			};
			class _xx_ACE_Rope_M_60
			{
				magazine = "ACE_Rope_M_60";
				count = 16;
			};
			class _xx_ACE_Rope_M_90
			{
				magazine = "ACE_Rope_M_90";
				count = 16;
			};
			class _xx_ACE_VS17Panel_M
			{
				magazine = "ACE_VS17Panel_M";
				count = 16;
			};
			class _xx_ACE_Rope_M5
			{
				magazine = "ACE_Rope_M5";
				count = 16;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_ACE_SSGreen_FG
			{
				magazine = "ACE_SSGreen_FG";
				count = 16;
			};
			class _xx_ACE_SSRed_FG
			{
				magazine = "ACE_SSRed_FG";
				count = 16;
			};
			class _xx_ACE_SSWhite_FG
			{
				magazine = "ACE_SSWhite_FG";
				count = 16;
			};
			class _xx_ACE_SSYellow_FG
			{
				magazine = "ACE_SSYellow_FG";
				count = 16;
			};
		};
	};
	class ACE_OrdnanceBox_GUE: USBasicWeapons_EP1
	{
		displayName = "Guerillas Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 16;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 16;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 16;
			};
			class _xx_SmokeShellBlue
			{
				magazine = "SmokeShellBlue";
				count = 16;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 16;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 16;
			};
			class _xx_SmokeShellPurple
			{
				magazine = "SmokeShellPurple";
				count = 16;
			};
			class _xx_SmokeShellRed
			{
				magazine = "SmokeShellRed";
				count = 16;
			};
			class _xx_SmokeShellYellow
			{
				magazine = "SmokeShellYellow";
				count = 16;
			};
			class _xx_IR_Strobe_Marker
			{
				magazine = "IR_Strobe_Marker";
				count = 16;
			};
			class _xx_IR_Strobe_Target
			{
				magazine = "IR_Strobe_Target";
				count = 16;
			};
			class _xx_ACE_RDG2
			{
				magazine = "ACE_RDG2";
				count = 16;
			};
			class _xx_ACE_RDGM
			{
				magazine = "ACE_RDGM";
				count = 16;
			};
			class _xx_ACE_TORCH_C
			{
				magazine = "ACE_TORCH_C";
				count = 16;
			};
			class _xx_ACE_RG60A
			{
				magazine = "ACE_RG60A";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 16;
			};
			class _xx_MineE
			{
				magazine = "MineE";
				count = 16;
			};
			class _xx_BAF_ied_v1
			{
				magazine = "BAF_ied_v1";
				count = 16;
			};
			class _xx_BAF_ied_v2
			{
				magazine = "BAF_ied_v2";
				count = 16;
			};
			class _xx_BAF_ied_v3
			{
				magazine = "BAF_ied_v3";
				count = 16;
			};
			class _xx_BAF_ied_v4
			{
				magazine = "BAF_ied_v4";
				count = 16;
			};
			class _xx_PMC_ied_v1
			{
				magazine = "PMC_ied_v1";
				count = 16;
			};
			class _xx_PMC_ied_v2
			{
				magazine = "PMC_ied_v2";
				count = 16;
			};
			class _xx_PMC_ied_v3
			{
				magazine = "PMC_ied_v3";
				count = 16;
			};
			class _xx_PMC_ied_v4
			{
				magazine = "PMC_ied_v4";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_Launchers_GUE: USBasicWeapons_EP1
	{
		displayName = "Guerillas Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_Stinger
			{
				weapon = "Stinger";
				count = 4;
			};
			class _xx_RPG7V
			{
				weapon = "RPG7V";
				count = 4;
			};
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 4;
			};
			class _xx_M47Launcher_EP1
			{
				weapon = "M47Launcher_EP1";
				count = 4;
			};
			class _xx_ACE_RPG7V_PGO7
			{
				weapon = "ACE_RPG7V_PGO7";
				count = 4;
			};
			class _xx_ACE_RPG29
			{
				weapon = "ACE_RPG29";
				count = 4;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 4;
			};
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_JerryCan_Dummy_15
			{
				weapon = "ACE_JerryCan_Dummy_15";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_Stinger
			{
				magazine = "Stinger";
				count = 16;
			};
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Dragon_EP1
			{
				magazine = "Dragon_EP1";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_Launchers_GUE: USBasicAmmunitionBox_EP1
	{
		displayName = "Guerillas Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 16;
			};
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 16;
			};
		};
		class TransportMagazines
		{
			class _xx_Stinger
			{
				magazine = "Stinger";
				count = 16;
			};
			class _xx_ACE_PG7VM
			{
				magazine = "ACE_PG7VM";
				count = 16;
			};
			class _xx_ACE_TBG7V
			{
				magazine = "ACE_TBG7V";
				count = 16;
			};
			class _xx_OG7
			{
				magazine = "OG7";
				count = 16;
			};
			class _xx_PG7V
			{
				magazine = "PG7V";
				count = 16;
			};
			class _xx_PG7VL
			{
				magazine = "PG7VL";
				count = 16;
			};
			class _xx_PG7VR
			{
				magazine = "PG7VR";
				count = 16;
			};
			class _xx_Dragon_EP1
			{
				magazine = "Dragon_EP1";
				count = 16;
			};
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 16;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 16;
			};
		};
	};
};
//};
