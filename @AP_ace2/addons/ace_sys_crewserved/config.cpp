////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:58 2013 : Created on Mon Oct 14 23:06:58 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_crewserved : config.bin{
class CfgPatches
{
	class ace_sys_crewserved
	{
		units[] = {"ACE_M3Tripod","ACE_M3Tripod_NoGeo","ACE_M252Tripod","ACE_M252Tripod_NoGeo","ACE_M224Tripod","ACE_M224Tripod_NoGeo","ACE_M122Tripod","ACE_M122Tripod_NoGeo","ACE_6T7Tripod","ACE_6T7Tripod_NoGeo","ACE_AGS30Tripod","ACE_AGS30Tripod_NoGeo","ACE_DSHKMTripod","ACE_DSHKMTripod_NoGeo","ACE_2b14Tripod","ACE_2b14Tripod_NoGeo","ACE_KonkursTripod_NoGeo","ACE_M252","ACE_M224","ACE_M240_Tripod","ACE_M240M145_Tripod","ACE_2b14_82mm","ACE_Konkurs","ACE_NSV","ACE_CSW_Box_M2","ACE_CSW_Box_Mk19","ACE_CSW_Box_M252","ACE_CSW_Box_M224","ACE_CSW_Box_AGS30","ACE_CSW_Box_KORD","ACE_CSW_Box_DSHKM","ACE_CSW_Box_KONKURS","ACE_CSW_Box_Metis","ACE_CSW_Box_2B14","ACE_Tbox_Mortar_81mmHE","ACE_Tbox_Mortar_81mmWP","ACE_Tbox_Mortar_81mmIL","ACE_Tbox_Mortar_60mmHE","ACE_Tbox_Mortar_60mmWP","ACE_Tbox_Mortar_60mmIL","ACE_Tbox_Mortar_82mmHE","ACE_Tbox_Mortar_82mmWP","ACE_Tbox_Mortar_82mmIL"};
		weapons[] = {"ACE_CrewMGunProxy","ACE_M2HBProxy","ACE_MK19MOD3Proxy","ACE_M252Proxy","ACE_M224Proxy","ACE_BAF_L2A1Proxy","ACE_BAF_static_GMGProxy","ACE_KORDProxy","ACE_DSHKMProxy","ACE_AGS30Proxy","ACE_2b14Proxy","ACE_CrewTripodProxy","ACE_M3TripodProxy","ACE_M122TripodProxy","ACE_M252TripodProxy","ACE_6T7TripodProxy","ACE_AGS30TripodProxy","ACE_DSHKMTripodProxy","ACE_2b14TripodProxy","ACE_KonkursTripodProxy","ACE_M2_Tri","ACE_Mk19_Tri","ACE_M252_Tri","ACE_M224_Tri","ACE_M240_Tri","ACE_BAF_L2A1_Tri","ACE_BAF_static_GMG_Tri","ACE_DSHKM_Tri","ACE_KORD_Tri","ACE_AGS30_Tri","ACE_2B14_Tri","ACE_AT5LauncherSingle_Static","ACE_AT13LauncherSingle_Static","ACE_SPG9"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","CAWeapons2","CAWeapons_Kord","CAWeapons_Warfare_weapons","CAWeapons_Metis_AT_13","CAWeapons_SPG9","CACharacters","CAWeapons_E","CAWeapons_E_M2StaticMG","CAWeapons_E_KORD","CAWeapons_E_DSHKM","CAWeapons_E_AGS","CAWeapons_E_Metis","CAWeapons_E_Mk19_MiniTriPod","CAWeapons_E_SPG9","CAWeapons_BAF","CAWeapons_E_M47","ace_main","ace_c_vehicle","ace_c_weapon","ace_sys_interaction","ace_sys_sight_adjustment","ace_m_veh_crates","ace_sys_ruck","ace_sys_sniper_tools","ace_sys_overheating","ace_sys_cargo"};
		version = "1.14.0.597";
		author[] = {"Rocko","Killswitch"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_crewserved
		{
			list[] = {"ace_sys_crewserved"};
		};
	};
};
class CfgActions
{
	class None;
	class Assemble: None
	{
		show = 0;
	};
	class DisAssemble: None
	{
		show = 0;
	};
};
class CfgAmmo
{
	class ARTY_Sh_81_HE;
	class ARTY_Sh_81_WP;
	class ARTY_Sh_81_ILLUM;
	class ARTY_Sh_81_NET;
	class ACE_ARTY_Sh_60_HE: ARTY_Sh_81_HE
	{
		hit = 100;
		indirectHit = 38;
		indirectHitRange = 6.9;
		ARTY_TrailFX = "";
		ARTY_NetShell = "ACE_ARTY_Sh_60_NET";
		typicalspeed = 185;
	};
	class ACE_ARTY_Sh_60_WP: ARTY_Sh_81_WP
	{
		hit = 20;
		indirectHit = 19;
		indirectHitRange = 6.9;
		ARTY_DeployOnImpact = "ARTY_SmokeShellWhite";
		typicalspeed = 185;
	};
	class ACE_ARTY_Sh_60_ILLUM: ARTY_Sh_81_ILLUM
	{
		hit = 3;
		ARTY_DeployAltitude = 210;
		typicalspeed = 185;
	};
	class ACE_ARTY_Sh_60_NET: ARTY_Sh_81_NET
	{
		airFriction = -0.00055;
		typicalspeed = 185;
		ARTY_TrailFX = "";
	};
	class Sh_81_HE;
	class Sh_81_WP;
	class Sh_81_ILLUM;
	class ACE_Sh_60_HE: Sh_81_HE
	{
		hit = 100;
		indirectHit = 38;
		indirectHitRange = 6.9;
		typicalspeed = 185;
	};
	class ACE_Sh_60_WP: Sh_81_WP
	{
		hit = 20;
		indirectHit = 19;
		indirectHitRange = 6.9;
		typicalspeed = 185;
	};
	class ACE_Sh_60_ILLUM: Sh_81_ILLUM
	{
		hit = 3;
		typicalspeed = 185;
	};
};
class CfgMagazines
{
	class Default
	{
		class ACE;
	};
	class CA_Magazine: Default
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED{};
		};
	};
	class VehicleMagazine: CA_Magazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED;
		};
	};
	class CA_LauncherMagazine: CA_Magazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED;
		};
	};
	class 100Rnd_762x51_M240: CA_Magazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "this";
				ACE_magXchange_veh = "this";
				ACE_magXchange_wep = "m240_scoped_EP1";
				loadType = "ACE_200Rnd_762x51_M240";
			};
		};
	};
	class 200Rnd_556x45_M249: CA_Magazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange_veh = "ACE_200Rnd_556x45_M249";
				ACE_magXchange_wep = "m249";
			};
		};
	};
	class 1200Rnd_762x51_M240: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "100Rnd_762x51_M240";
			};
		};
	};
	class ACE_200Rnd_762x51_M240: 1200Rnd_762x51_M240
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "100Rnd_762x51_M240";
				ACE_magXchange = "100Rnd_762x51_M240";
			};
		};
	};
	class ACE_200Rnd_556x45_M249: 1200Rnd_762x51_M240
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "200Rnd_556x45_M249";
			};
		};
	};
	class 100Rnd_127x99_M2: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "ACE_M2_CSWDM";
			};
		};
	};
	class ACE_200Rnd_127x99_M2: 100Rnd_127x99_M2
	{
		count = 200;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M2_CSWDM";
			};
		};
	};
	class 48Rnd_40mm_MK19: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "ACE_MK19_CSWDM";
			};
		};
	};
	class ACE_64Rnd_40mm_MK19: 48Rnd_40mm_MK19
	{
		count = 64;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_MK19_CSWDM";
			};
		};
	};
	class ACE_96Rnd_40mm_MK19: 48Rnd_40mm_MK19
	{
		count = 96;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_MK19_CSWDM";
			};
		};
	};
	class 32Rnd_40mm_GMG: 48Rnd_40mm_MK19
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_GMG_CSWDM";
				ACE_magXchange = "ACE_GMG_CSWDM";
			};
		};
	};
	class ACE_64Rnd_40mm_GMG: 32Rnd_40mm_GMG
	{
		count = 64;
	};
	class ACE_96Rnd_40mm_GMG: ACE_64Rnd_40mm_GMG
	{
		count = 96;
	};
	class ACE_32Rnd_40mm_GMW_DM111: 32Rnd_40mm_GMG
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_GMW_DM111_CSWDM";
				ACE_magXchange = "ACE_GMW_DM111_CSWDM";
			};
		};
	};
	class ACE_32Rnd_40mm_GMW_DM42: ACE_32Rnd_40mm_GMW_DM111
	{
		ammo = "ACE_G_40mm_HEDP_DM42";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_GMW_DM42_CSWDM";
				ACE_magXchange = "ACE_GMW_DM42_CSWDM";
			};
		};
	};
	class ACE_32Rnd_40mm_GMW_DM111DM42: ACE_32Rnd_40mm_GMW_DM111
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_GMW_DM111DM42_CSWDM";
				ACE_magXchange = "ACE_GMW_DM111DM42_CSWDM";
			};
		};
	};
	class 100Rnd_762x54_PK: CA_Magazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "this";
				ACE_magXchange_veh = "this";
				ACE_magXchange_wep = "PK";
			};
		};
	};
	class 50Rnd_127x107_DSHKM: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "ACE_DSHKM_CSWDM";
			};
		};
	};
	class ACE_100Rnd_127x107_DSHKM: 50Rnd_127x107_DSHKM
	{
		count = 100;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_DSHKM_CSWDM";
			};
		};
	};
	class 50Rnd_127x108_KORD: 50Rnd_127x107_DSHKM
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "ACE_KORD_CSWDM";
			};
		};
	};
	class ACE_100Rnd_127x108_KORD: 50Rnd_127x108_KORD
	{
		count = 100;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_KORD_CSWDM";
			};
		};
	};
	class 29Rnd_30mm_AGS30: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange = "ACE_AGS30_CSWDM";
			};
		};
	};
	class ACE_29Rnd_30mm_AGS30: 29Rnd_30mm_AGS30
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_AGS30_CSWDM";
			};
		};
	};
	class ACE_58Rnd_30mm_AGS30: 29Rnd_30mm_AGS30
	{
		count = 58;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_AGS30_CSWDM";
			};
		};
	};
	class ACE_CSWDM: CA_Magazine
	{
		ACE_Weight = 11;
		ACE_Size = 5600;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_m2_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_kord_mag.p3d";
		displayName = "CSWDM Mag";
		descriptionShort = "";
		type = 256;
		ammo = "ACE_DummyAmmo";
		count = 1;
	};
	class ACE_KORD_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 11;
		ACE_Size = 5600;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_m2_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_kord_mag.p3d";
		displayName = "KORD Mag";
		type = 256;
		scope = 2;
		count = 50;
		descriptionShort = "$STR_DSS_ACE_KORD_CSWDM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_100Rnd_127x108_KORD";
				ACE_magXchange_veh = "50Rnd_127x108_KORD";
			};
		};
	};
	class ACE_KORD_CSWDM_90: ACE_KORD_CSWDM{};
	class ACE_KORD_CSWDM_80: ACE_KORD_CSWDM_90{};
	class ACE_KORD_CSWDM_70: ACE_KORD_CSWDM_90{};
	class ACE_KORD_CSWDM_60: ACE_KORD_CSWDM_90{};
	class ACE_KORD_CSWDM_50: ACE_KORD_CSWDM_90{};
	class ACE_KORD_CSWDM_40: ACE_KORD_CSWDM_90{};
	class ACE_KORD_CSWDM_30: ACE_KORD_CSWDM_90{};
	class ACE_KORD_CSWDM_20: ACE_KORD_CSWDM_90{};
	class ACE_KORD_CSWDM_10: ACE_KORD_CSWDM_90{};
	class ACE_DSHKM_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 11;
		ACE_Size = 5600;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_m2_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_dshkm_mag.p3d";
		displayName = "DShKM Mag";
		type = 256;
		scope = 2;
		count = 50;
		descriptionShort = "$STR_DSS_ACE_DSHKM_CSWDM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_100Rnd_127x107_DSHKM";
				ACE_magXchange_veh = "50Rnd_127x107_DSHKM";
			};
		};
	};
	class ACE_DSHKM_CSWDM_90: ACE_DSHKM_CSWDM{};
	class ACE_DSHKM_CSWDM_80: ACE_DSHKM_CSWDM_90{};
	class ACE_DSHKM_CSWDM_70: ACE_DSHKM_CSWDM_90{};
	class ACE_DSHKM_CSWDM_60: ACE_DSHKM_CSWDM_90{};
	class ACE_DSHKM_CSWDM_50: ACE_DSHKM_CSWDM_90{};
	class ACE_DSHKM_CSWDM_40: ACE_DSHKM_CSWDM_90{};
	class ACE_DSHKM_CSWDM_30: ACE_DSHKM_CSWDM_90{};
	class ACE_DSHKM_CSWDM_20: ACE_DSHKM_CSWDM_90{};
	class ACE_DSHKM_CSWDM_10: ACE_DSHKM_CSWDM_90{};
	class ACE_M2_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 16;
		ACE_Size = 12672;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_m2_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_m2_mag.p3d";
		displayName = "M2 Mag";
		type = "2*256";
		scope = 2;
		count = 100;
		descriptionShort = "$STR_DSS_ACE_M2_CSWDM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_200Rnd_127x99_M2";
				ACE_magXchange_veh = "100Rnd_127x99_M2";
			};
		};
	};
	class ACE_M2_CSWDM_90: ACE_M2_CSWDM{};
	class ACE_M2_CSWDM_80: ACE_M2_CSWDM_90{};
	class ACE_M2_CSWDM_70: ACE_M2_CSWDM_90{};
	class ACE_M2_CSWDM_60: ACE_M2_CSWDM_90{};
	class ACE_M2_CSWDM_50: ACE_M2_CSWDM_90{};
	class ACE_M2_CSWDM_40: ACE_M2_CSWDM_90{};
	class ACE_M2_CSWDM_30: ACE_M2_CSWDM_90{};
	class ACE_M2_CSWDM_20: ACE_M2_CSWDM_90{};
	class ACE_M2_CSWDM_10: ACE_M2_CSWDM_90{};
	class ACE_MK19_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 21;
		ACE_Size = 12672;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_mk19_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_mk19_mag.p3d";
		displayName = "Mk19 Mag";
		type = "2*256";
		scope = 2;
		count = 48;
		descriptionShort = "$STR_DSS_ACE_MK19_CSWDM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_96Rnd_40mm_MK19";
				ACE_magXchange_veh = "48Rnd_40mm_MK19";
			};
		};
	};
	class ACE_MK19_CSWDM_90: ACE_MK19_CSWDM{};
	class ACE_MK19_CSWDM_80: ACE_MK19_CSWDM_90{};
	class ACE_MK19_CSWDM_70: ACE_MK19_CSWDM_90{};
	class ACE_MK19_CSWDM_60: ACE_MK19_CSWDM_90{};
	class ACE_MK19_CSWDM_50: ACE_MK19_CSWDM_90{};
	class ACE_MK19_CSWDM_40: ACE_MK19_CSWDM_90{};
	class ACE_MK19_CSWDM_30: ACE_MK19_CSWDM_90{};
	class ACE_MK19_CSWDM_20: ACE_MK19_CSWDM_90{};
	class ACE_MK19_CSWDM_10: ACE_MK19_CSWDM_90{};
	class ACE_GMG_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 21;
		ACE_Size = 12672;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_mk19_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_mk19_mag.p3d";
		displayName = "GMG Mag";
		type = "2*256";
		scope = 2;
		count = 32;
		descriptionShort = "$STR_DSS_ACE_GMG_CSWDM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_64Rnd_40mm_GMG";
				ACE_magXchange_veh = "ACE_64Rnd_40mm_GMG";
			};
		};
	};
	class ACE_GMG_CSWDM_90: ACE_GMG_CSWDM{};
	class ACE_GMG_CSWDM_80: ACE_GMG_CSWDM_90{};
	class ACE_GMG_CSWDM_70: ACE_GMG_CSWDM_90{};
	class ACE_GMG_CSWDM_60: ACE_GMG_CSWDM_90{};
	class ACE_GMG_CSWDM_50: ACE_GMG_CSWDM_90{};
	class ACE_GMG_CSWDM_40: ACE_GMG_CSWDM_90{};
	class ACE_GMG_CSWDM_30: ACE_GMG_CSWDM_90{};
	class ACE_GMG_CSWDM_20: ACE_GMG_CSWDM_90{};
	class ACE_GMG_CSWDM_10: ACE_GMG_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 21;
		ACE_Size = 12672;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_dmxxx_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_dm111_mag.p3d";
		displayName = "40mm x 53 DM111";
		type = "2*256";
		scope = 2;
		count = 32;
		descriptionShort = "$STR_DSS_ACE_GMG_CSWDM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_32Rnd_40mm_GMW_DM111";
				ACE_magXchange_veh = "ACE_32Rnd_40mm_GMW_DM111";
			};
		};
	};
	class ACE_GMW_DM111_CSWDM_90: ACE_GMW_DM111_CSWDM{};
	class ACE_GMW_DM111_CSWDM_80: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM_70: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM_60: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM_50: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM_40: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM_30: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM_20: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111_CSWDM_10: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM: ACE_GMW_DM111_CSWDM
	{
		displayName = "40mm x 53 DM42";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_dm42_mag.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_32Rnd_40mm_GMW_DM42";
				ACE_magXchange_veh = "ACE_32Rnd_40mm_GMW_DM42";
			};
		};
	};
	class ACE_GMW_DM42_CSWDM_90: ACE_GMW_DM42_CSWDM{};
	class ACE_GMW_DM42_CSWDM_80: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM_70: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM_60: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM_50: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM_40: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM_30: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM_20: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM42_CSWDM_10: ACE_GMW_DM42_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM: ACE_GMW_DM111_CSWDM
	{
		displayName = "40mm x 53 DM111:DM42";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_dm111dm42_mag.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_32Rnd_40mm_GMW_DM111DM42";
				ACE_magXchange_veh = "ACE_32Rnd_40mm_GMW_DM111DM42";
			};
		};
	};
	class ACE_GMW_DM111DM42_CSWDM_90: ACE_GMW_DM111DM42_CSWDM{};
	class ACE_GMW_DM111DM42_CSWDM_80: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM_70: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM_60: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM_50: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM_40: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM_30: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM_20: ACE_GMW_DM111_CSWDM_90{};
	class ACE_GMW_DM111DM42_CSWDM_10: ACE_GMW_DM111_CSWDM_90{};
	class ACE_AGS30_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 14;
		ACE_Size = 19008;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_ags30_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_ags30_mag.p3d";
		displayName = "AGS-30 Mag";
		type = "2*256";
		scope = 2;
		count = 29;
		descriptionShort = "$STR_DSS_ACE_AGS30_CSWDM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_58Rnd_30mm_AGS30";
				ACE_magXchange_veh = "ACE_58Rnd_30mm_AGS30";
			};
		};
	};
	class ACE_AGS30_CSWDM_90: ACE_AGS30_CSWDM{};
	class ACE_AGS30_CSWDM_80: ACE_AGS30_CSWDM_90{};
	class ACE_AGS30_CSWDM_70: ACE_AGS30_CSWDM_90{};
	class ACE_AGS30_CSWDM_60: ACE_AGS30_CSWDM_90{};
	class ACE_AGS30_CSWDM_50: ACE_AGS30_CSWDM_90{};
	class ACE_AGS30_CSWDM_40: ACE_AGS30_CSWDM_90{};
	class ACE_AGS30_CSWDM_30: ACE_AGS30_CSWDM_90{};
	class ACE_AGS30_CSWDM_20: ACE_AGS30_CSWDM_90{};
	class ACE_AGS30_CSWDM_10: ACE_AGS30_CSWDM_90{};
	class Dragon_EP1: CA_LauncherMagazine
	{
		model = "\x\ace\addons\m_wep_dragon\ace_m47_magazine.p3d";
	};
	class 6Rnd_TOW2;
	class 2Rnd_TOW2: 6Rnd_TOW2
	{
		class ACE;
	};
	class ACE_TOW2: 2Rnd_TOW2
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "ACE_TOW_CSWDM";
				ACE_magXchange = "ACE_TOW_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_TOW_CSWDM: ACE_CSWDM
	{
		scope = 2;
		type = "4*256";
		displayName = "TOW Mag";
		displayNameShort = "TOW";
		ACE_Weight = 30;
		ACE_Size = 27000;
		model = "x\ace\addons\m_wep_magazines\ace_tow_mag.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange_veh = "ACE_TOW2";
				loadType = "ACE_TOW2";
			};
		};
	};
	class 8Rnd_Stinger;
	class 2Rnd_Stinger: 8Rnd_Stinger
	{
		class ACE;
	};
	class ACE_1Rnd_Stinger: 2Rnd_Stinger
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "ACE_Stinger_CSWDM";
				ACE_magXchange = "ACE_Stinger_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_Stinger_CSWDM: ACE_CSWDM
	{
		scope = 2;
		type = "4*256";
		displayName = "Stinger Mag";
		model = "x\ace\addons\m_wep_magazines\ace_tow_mag.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange_veh = "ACE_1Rnd_Stinger";
				loadType = "ACE_1Rnd_Stinger";
			};
		};
	};
	class ACE_9M31: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_9M31_CSWDM";
				ACE_magXchange = "ACE_9M31_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_9M31_CSWDM: ACE_CSWDM
	{
		scope = 2;
		type = "4*256";
		displayName = "$STR_ACE_MDN_9M31";
		model = "x\ace\addons\m_wep_magazines\ace_tow_mag.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange_veh = "ACE_9M31";
				loadType = "ACE_9M31";
			};
		};
	};
	class Igla;
	class 2Rnd_Igla: Igla
	{
		class ACE;
	};
	class ACE_1Rnd_Igla: 2Rnd_Igla
	{
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "ACE_9K38_CSWDM";
				ACE_magXchange = "ACE_9K38_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_9K38_CSWDM: ACE_CSWDM
	{
		scope = 2;
		type = "4*256";
		displayName = "9K38";
		model = "x\ace\addons\m_wep_magazines\ace_tow_mag.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange_veh = "ACE_1Rnd_Igla";
				loadType = "ACE_1Rnd_Igla";
			};
		};
	};
	class 8Rnd_AT5_BMP2: VehicleMagazine
	{
		class ACE;
	};
	class ACE_AT5: 8Rnd_AT5_BMP2
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "ACE_Konkurs_CSWDM";
				ACE_magXchange = "ACE_Konkurs_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_Konkurs_CSWDM: ACE_CSWDM
	{
		ACE_Weight = 26.5;
		ACE_Size = 25500;
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_konkurs_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_konkurs_mag.p3d";
		displayName = "$STR_ACE_MDN_AT5";
		type = "4*256";
		scope = 2;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_AT5";
				ACE_magXchange_veh = "ACE_AT5";
			};
		};
	};
	class ACE_AT5B: 8Rnd_AT5_BMP2
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "ACE_KonkursM_CSWDM";
				ACE_magXchange = "ACE_KonkursM_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_KonkursM_CSWDM: ACE_Konkurs_CSWDM
	{
		displayName = "$STR_ACE_MDN_AT5B";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_AT5B";
				ACE_magXchange_veh = "ACE_AT5B";
			};
		};
	};
	class ACE_9K113M_1: ACE_AT5
	{
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
	};
	class 6Rnd_AT13: VehicleMagazine
	{
		class ACE;
	};
	class ACE_9K115M_1: 6Rnd_AT13
	{
		displaynameshort = "9M131M";
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "AT13";
			};
		};
	};
	class AT13: CA_LauncherMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_9K115M_1";
			};
		};
	};
	class ACE_1Rnd_9M131F: ACE_9K115M_1
	{
		displaynameshort = "9M131F";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_AT13TB";
			};
		};
	};
	class ACE_AT13TB: AT13
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_9M131F";
			};
		};
	};
	class ACE_AT3C: 8Rnd_AT5_BMP2
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "ACE_AT3C_CSWDM";
				ACE_magXchange = "ACE_AT3C_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_AT3C_CSWDM: ACE_CSWDM
	{
		scope = 2;
		type = "3*256";
		displayName = "$STR_ACE_MDN_AT3C";
		model = "x\ace\addons\m_wep_magazines\ace_tow_mag.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange_veh = "ACE_AT3C";
				loadType = "ACE_AT3C";
			};
		};
		ACE_Size = 10553;
		ACE_Weight = 10.9;
	};
	class ACE_AT3P: ACE_AT3C
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				unloadType = "ACE_AT3P_CSWDM";
				ACE_magXchange = "ACE_AT3P_CSWDM";
				ACE_magXchange_external = 1;
			};
		};
	};
	class ACE_AT3P_CSWDM: ACE_AT3C_CSWDM
	{
		displayName = "$STR_ACE_MDN_AT3P";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				ACE_magXchange_veh = "ACE_AT3P";
				loadType = "ACE_AT3P";
			};
		};
	};
	class PG9_AT;
	class OG9_HE;
	class ACE_PG9_AT: PG9_AT{};
	class ACE_OG9_HE: OG9_HE{};
	class ACE_M252HE_CSWDM: CA_Magazine
	{
		scope = 2;
		displayName = "81mm M821A1 HE";
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_mortarshell_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_mortarshell_mag.p3d";
		type = 256;
		count = 1;
		ammo = "ACE_DummyAmmo";
		ACE_Weight = 4.14;
		ACE_Size = 200;
		descriptionShort = "";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_81mmHE_M252";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m821a2_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_81mm_m821a2";
	};
	class ACE_M252WP_CSWDM: ACE_M252HE_CSWDM
	{
		displayName = "81mm M375A3 WP";
		ACE_Weight = 4.7;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_81mmWP_M252";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m375a3_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_81mm_m375a3";
	};
	class ACE_M252IL_CSWDM: ACE_M252HE_CSWDM
	{
		displayName = "81mm M853A1 ILLUM";
		ACE_Weight = 4;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_81mmILLUM_M252";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m853a1_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_81mm_m853a1";
	};
	class ACE_M224HE_CSWDM: ACE_M252HE_CSWDM
	{
		displayName = "60mm M720 HE";
		ACE_Weight = 1.9;
		ACE_Size = 200;
		descriptionShort = "";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_60mmHE_M224";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m720a1_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_60mm_m720a1";
	};
	class ACE_M224WP_CSWDM: ACE_M224HE_CSWDM
	{
		displayName = "60mm M722 WP";
		ACE_Weight = 1.9;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_60mmWP_M224";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m722a1_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_60mm_m722a1";
	};
	class ACE_M224IL_CSWDM: ACE_M224HE_CSWDM
	{
		displayName = "60mm M721 ILLUM";
		ACE_Weight = 1.9;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_60mmILLUM_M224";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m721_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_60mm_m721";
	};
	class ACE_M224_HE_CSWDM: ACE_M224HE_CSWDM
	{
		class Armory
		{
			disabled = 1;
		};
		ace_bwc = 1;
	};
	class ACE_2B14HE_CSWDM: CA_Magazine
	{
		scope = 2;
		displayName = "82mm VO-832DU HE";
		picture = "\x\ace\addons\sys_crewserved\data\equip\m_mortarshell_ca.paa";
		model = "\x\ace\addons\sys_crewserved\magazines\ace_mortarshell_mag.p3d";
		type = 256;
		count = 1;
		ammo = "ACE_DummyAmmo";
		ACE_Weight = 3.1;
		ACE_Size = 200;
		descriptionShort = "";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_82mmHE_2B14";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_82mm_he_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_82mm_he";
	};
	class ACE_2B14WP_CSWDM: ACE_2B14HE_CSWDM
	{
		displayName = "82mm WP";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_82mmWP_2B14";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_82mm_smoke_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_82mm_wp";
	};
	class ACE_2B14IL_CSWDM: ACE_2B14HE_CSWDM
	{
		displayName = "82mm ILLUM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				loadType = "ACE_1Rnd_82mmILLUM_2B14";
			};
		};
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_82mm_illum_cartridge";
		ACE_ARTY_SHELL_MAGAZINE = "ace_arty_82mm_illum";
	};
	class ARTY_8Rnd_81mmHE_M252: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252HE_CSWDM";
			};
		};
	};
	class ARTY_8Rnd_81mmWP_M252: ARTY_8Rnd_81mmHE_M252
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252WP_CSWDM";
			};
		};
	};
	class ARTY_8Rnd_81mmILLUM_M252: ARTY_8Rnd_81mmHE_M252
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252IL_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_81mmHE_M252: ARTY_8Rnd_81mmHE_M252
	{
		count = 1;
		displayName = "M821";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252HE_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_81mmWP_M252: ARTY_8Rnd_81mmWP_M252
	{
		count = 1;
		displayName = "M819";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252WP_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_81mmILLUM_M252: ARTY_8Rnd_81mmILLUM_M252
	{
		count = 1;
		displayName = "M853A1";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252IL_CSWDM";
			};
		};
	};
	class 8Rnd_81mmHE_M252: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252HE_CSWDM";
			};
		};
	};
	class 8Rnd_81mmWP_M252: 8Rnd_81mmHE_M252
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252WP_CSWDM";
			};
		};
	};
	class 8Rnd_81mmILLUM_M252: 8Rnd_81mmHE_M252
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252IL_CSWDM";
			};
		};
	};
	class ACE_1Rnd_81mmHE_M252: 8Rnd_81mmHE_M252
	{
		count = 1;
		displayName = "M821";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252HE_CSWDM";
			};
		};
	};
	class ACE_1Rnd_81mmWP_M252: 8Rnd_81mmWP_M252
	{
		count = 1;
		displayName = "M819";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252WP_CSWDM";
			};
		};
	};
	class ACE_1Rnd_81mmILLUM_M252: 8Rnd_81mmILLUM_M252
	{
		count = 1;
		displayName = "M853A1";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M252IL_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_60mmHE_M224: ACE_ARTY_1Rnd_81mmHE_M252
	{
		count = 1;
		displayName = "M720";
		ammo = "ACE_ARTY_Sh_60_HE";
		initspeed = 185;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M224HE_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_60mmWP_M224: ACE_ARTY_1Rnd_60mmHE_M224
	{
		count = 1;
		displayName = "M722";
		ammo = "ACE_ARTY_Sh_60_WP";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M224WP_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_60mmILLUM_M224: ACE_ARTY_1Rnd_60mmHE_M224
	{
		count = 1;
		displayName = "M721";
		ammo = "ACE_ARTY_Sh_60_ILLUM";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M224IL_CSWDM";
			};
		};
	};
	class ACE_1Rnd_60mmHE_M224: 8Rnd_81mmHE_M252
	{
		count = 1;
		displayName = "M720";
		ammo = "ACE_Sh_60_HE";
		initspeed = 185;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M224HE_CSWDM";
			};
		};
	};
	class ACE_1Rnd_60mmWP_M224: 8Rnd_81mmWP_M252
	{
		count = 1;
		displayName = "M722";
		ammo = "ACE_Sh_60_WP";
		initspeed = 185;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M224WP_CSWDM";
			};
		};
	};
	class ACE_1Rnd_60mmILLUM_M224: 8Rnd_81mmILLUM_M252
	{
		count = 1;
		displayName = "M721";
		ammo = "ACE_Sh_60_ILLUM";
		initspeed = 185;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_M224IL_CSWDM";
			};
		};
	};
	class 8Rnd_82mmHE_2B14: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14HE_CSWDM";
			};
		};
	};
	class 8Rnd_82mmWP_2B14: 8Rnd_82mmHE_2B14
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14WP_CSWDM";
			};
		};
	};
	class 8Rnd_82mmILLUM_2B14: 8Rnd_82mmHE_2B14
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14IL_CSWDM";
			};
		};
	};
	class ACE_1Rnd_82mmHE_2B14: 8Rnd_82mmHE_2B14
	{
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14HE_CSWDM";
			};
		};
	};
	class ACE_1Rnd_82mmWP_2B14: 8Rnd_82mmWP_2B14
	{
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14WP_CSWDM";
			};
		};
	};
	class ACE_1Rnd_82mmILLUM_2B14: 8Rnd_82mmILLUM_2B14
	{
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14IL_CSWDM";
			};
		};
	};
	class ARTY_8Rnd_82mmHE_2B14: VehicleMagazine
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14HE_CSWDM";
			};
		};
	};
	class ARTY_8Rnd_82mmWP_2B14: ARTY_8Rnd_82mmHE_2B14
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14WP_CSWDM";
			};
		};
	};
	class ARTY_8Rnd_82mmILLUM_2B14: ARTY_8Rnd_82mmHE_2B14
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14IL_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_82mmHE_2B14: ARTY_8Rnd_82mmHE_2B14
	{
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14HE_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_82mmWP_2B14: ARTY_8Rnd_82mmWP_2B14
	{
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14WP_CSWDM";
			};
		};
	};
	class ACE_ARTY_1Rnd_82mmILLUM_2B14: ARTY_8Rnd_82mmILLUM_2B14
	{
		count = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				unloadType = "ACE_2B14IL_CSWDM";
			};
		};
	};
	class ACE_Mortar81W_CSWDM: CA_Magazine
	{
		displayName = "81mm HE Mortar";
		type = 256;
		ACE_Weight = 100000;
		ACE_Size = 100000;
	};
	class ACE_Mortar81WP_CSWDM: ACE_Mortar81W_CSWDM
	{
		displayName = "81mm WP Mortar";
	};
	class ACE_Mortar81PF_CSWDM: ACE_Mortar81W_CSWDM
	{
		displayName = "81mm HEPF Mortar";
	};
	class ACE_Mortar82E_CSWDM: CA_Magazine
	{
		displayName = "82mm HE Mortar";
		type = 256;
		ACE_Weight = 100000;
		ACE_Size = 100000;
	};
	class ACE_Mortar82WP_CSWDM: ACE_Mortar82E_CSWDM
	{
		displayName = "82mm WP Mortar";
	};
	class ACE_Mortar82PF_CSWDM: ACE_Mortar82E_CSWDM
	{
		displayName = "82mm HEPF Mortar";
	};
	class ACE_Mortar60W_CSWDM: CA_Magazine
	{
		displayName = "60mm HE Mortar";
		type = 256;
		ACE_Weight = 100000;
		ACE_Size = 100000;
	};
	class ACE_Mortar60WP_CSWDM: ACE_Mortar60W_CSWDM
	{
		displayName = "60mm WP Mortar";
	};
	class ACE_Mortar60PF_CSWDM: ACE_Mortar60W_CSWDM
	{
		displayName = "60mm HEPF Mortar";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Default;
	class CannonCore;
	class LauncherCore;
	class Launcher: LauncherCore
	{
		class ACE;
	};
	class ACE_CrewMGunProxy: Launcher
	{
		scope = 1;
		displayName = "";
		nameSound = "weapon";
		picture = "";
		simulation = "ProxyWeapon";
		modelOptics = "";
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
			libTextDesc = "";
		};
		ACE_Weight = 1;
		ACE_NoPack = 1;
		ACE_Size = 9000;
		muzzlePos = "";
		muzzleEnd = "";
		descriptionShort = "";
		class ACE: ACE
		{
			class ACE_CREWSERVED{};
		};
	};
	class ACE_M2HBProxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "M2";
		descriptionshort = "$STR_DSS_ACE_M2HBPROXY";
		ACE_Weight = 38;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "M2HD_mini_TriPod_US_EP1";
				canUseTripods[] = {"ACE_M3Tripod"};
			};
		};
	};
	class ACE_MK19MOD3Proxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "Mk19";
		descriptionshort = "$STR_DSS_ACE_MK19PROXY";
		ACE_Weight = 33;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "MK19_TriPod_US_EP1";
				canUseTripods[] = {"ACE_M3Tripod"};
			};
		};
	};
	class ACE_M252Proxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "M253+M177";
		descriptionshort = "$STR_DSS_ACE_M252PROXY";
		ACE_Weight = 28;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_M252";
				canUseTripods[] = {"ACE_M252Tripod"};
			};
		};
	};
	class ACE_M224Proxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "M225+M170";
		descriptionshort = "$STR_DSS_ACE_M224PROXY";
		ACE_Weight = 13.5;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_M224_1";
				canUseTripods[] = {"ACE_M224Tripod"};
			};
		};
	};
	class ACE_M220Proxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "TOW ";
		descriptionshort = "";
		ACE_Weight = 13.5;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "TOW_TriPod_US_EP1";
				canUseTripods[] = {"ACE_M220Tripod"};
			};
		};
	};
	class ACE_BAF_L2A1Proxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "L2A1";
		descriptionshort = "$STR_DSS_ACE_M2HBPROXY";
		ACE_Weight = 38;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "BAF_L2A1_Minitripod_D";
				canUseTripods[] = {"ACE_M3Tripod"};
			};
		};
	};
	class ACE_BAF_static_GMGProxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "GMG";
		descriptionshort = "$STR_DSS_ACE_MK19PROXY";
		ACE_Weight = 29.4;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "BAF_GMG_Tripod_D";
				canUseTripods[] = {"ACE_GMGTripod"};
			};
		};
	};
	class ACE_KORDProxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "$STR_DN_KORD";
		descriptionshort = "$STR_DSS_ACE_KORDPROXY";
		ACE_Weight = 25;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "KORD_UN_EP1";
				canUseTripods[] = {"ACE_6T7Tripod"};
			};
		};
	};
	class ACE_DSHKMProxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "$STR_DN_DSHKM";
		descriptionshort = "$STR_DSS_ACE_DSHKMPROXY";
		ACE_Weight = 34;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "DSHkM_Mini_TriPod_TK_GUE_EP1";
				canUseTripods[] = {"ACE_DSHKMTripod"};
			};
		};
	};
	class ACE_AGS30Proxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "$STR_DN_AGS30";
		descriptionshort = "$STR_DSS_ACE_AGS30PROXY";
		ACE_Weight = 10.5;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "AGS_TK_INS_EP1";
				canUseTripods[] = {"ACE_AGS30Tripod"};
			};
		};
	};
	class ACE_2b14Proxy: ACE_CrewMGunProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "2B14 Podnos";
		descriptionshort = "$STR_DSS_ACE_2B14PROXY";
		ACE_Weight = 25;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_2b14_82mm";
				canUseTripods[] = {"ACE_2b14Tripod"};
			};
		};
	};
	class ACE_CrewTripodProxy: ACE_CrewMGunProxy
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				isTripod = 1;
				mountTime = 10;
			};
		};
	};
	class ACE_M3TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_M3TRIPOD";
		ACE_Weight = 20;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_M3Tripod_NoGeo";
				tripod = "ACE_M3Tripod";
				mountTime = 15;
			};
		};
	};
	class ACE_GMGTripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_GMGTRIPOD";
		ACE_Weight = 15;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_GMGTripod_NoGeo";
				tripod = "ACE_GMGTripod";
				mountTime = 15;
			};
		};
	};
	class ACE_M122TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswy.p3d";
		picture = "\ca\weapons_e\data\icons\staticy_ca.paa";
		displayName = "$STR_DN_ACE_M122TRIPOD";
		ACE_Weight = 7.26;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_M122Tripod_NoGeo";
				tripod = "ACE_M122Tripod";
				mountTime = 10;
			};
		};
	};
	class ACE_M252TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_M252TRIPOD";
		descriptionshort = "$STR_DSS_ACE_M252TRIPOD";
		ACE_Weight = 13;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_M252Tripod_NoGeo";
				tripod = "ACE_M252Tripod";
				mountTime = 15;
			};
		};
	};
	class ACE_M224TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_M224TRIPOD";
		descriptionshort = "$STR_DSS_ACE_M224TRIPOD";
		ACE_Weight = 6.6;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_M224Tripod_NoGeo";
				tripod = "ACE_M224Tripod";
				mountTime = 10;
			};
		};
	};
	class ACE_M224TripodProxy2: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_M224TRIPOD2";
		descriptionshort = "$STR_DSS_ACE_M224TRIPOD2";
		ACE_Weight = 1.6;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_M224Tripod2_NoGeo";
				tripod = "ACE_M224Tripod2";
				mountTime = 5;
			};
		};
	};
	class ACE_M220TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "TOW Tripod";
		descriptionshort = "";
		ACE_Weight = 6.6;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_M220Tripod_NoGeo";
				tripod = "ACE_M220Tripod";
				mountTime = 15;
			};
		};
	};
	class ACE_6T7TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_6T7TRIPOD";
		ACE_Weight = 16;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_6T7Tripod_NoGeo";
				tripod = "ACE_6T7Tripod";
				mountTime = 15;
			};
		};
	};
	class ACE_AGS30TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_AGS30TRIPOD";
		ACE_Weight = 6;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_AGS30Tripod_NoGeo";
				tripod = "ACE_AGS30Tripod";
				mountTime = 10;
			};
		};
	};
	class ACE_DSHKMTripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_DSHKMTRIPOD";
		ACE_Weight = 6;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_AGS30Tripod_NoGeo";
				tripod = "ACE_DSHKMTripod";
				mountTime = 15;
			};
		};
	};
	class ACE_2b14TripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "$STR_DN_ACE_2B14TRIPOD";
		descriptionshort = "$STR_DSS_ACE_2B14TRIPOD";
		ACE_Weight = 14;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_2b14Tripod_NoGeo";
				tripod = "ACE_2b14Tripod";
				mountTime = 10;
			};
		};
	};
	class ACE_KonkursTripodProxy: ACE_CrewTripodProxy
	{
		scope = 2;
		model = "\x\ace\addons\sys_ruck\backpack_data\cswx.p3d";
		picture = "\ca\weapons_e\data\icons\staticx_ca.paa";
		displayName = "9P135M";
		displayNameShort = "$STR_DSS_ACE_KonkursTripodProxy";
		ACE_Weight = 22;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodGhost = "ACE_KonkursTripod_NoGeo";
				tripod = "ACE_Konkurs";
				mountTime = 15;
			};
		};
	};
	class MetisLauncher: Launcher
	{
		ACE_NoPack = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				isTripod = 1;
				tripodGhost = "Metis_TK_EP1";
				tripod = "Metis_TK_EP1";
			};
		};
	};
	class M2;
	class ACE_M2_Tri: M2
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_200Rnd_127x99_M2","100Rnd_127x99_M2"};
	};
	class MK19;
	class ACE_MK19_Tri: MK19
	{
		reloadTime = 0.1846;
		magazineReloadTime = 0;
		magazines[] = {"ACE_96Rnd_40mm_MK19","ACE_64Rnd_40mm_MK19","48Rnd_40mm_MK19"};
	};
	class M252: CannonCore
	{
		reloadTime = 1.5;
		magazineReloadTime = 1.5;
		class Single1;
		class Single2;
		class Single3;
	};
	class ACE_M252_Tri: M252
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_ARTY_1Rnd_81mmHE_M252","ACE_ARTY_1Rnd_81mmWP_M252","ACE_ARTY_1Rnd_81mmILLUM_M252","ACE_1Rnd_81mmHE_M252","ACE_1Rnd_81mmWP_M252","ACE_1Rnd_81mmILLUM_M252"};
		class Single1: Single1
		{
			reloadTime = 1;
		};
		class Single2: Single2
		{
			reloadTime = 1;
		};
		class Single3: Single3
		{
			reloadTime = 1;
		};
	};
	class ACE_M224_Tri: ACE_M252_Tri
	{
		displayName = "M224";
		magazineReloadTime = 0;
		magazines[] = {"ACE_ARTY_1Rnd_60mmHE_M224","ACE_ARTY_1Rnd_60mmWP_M224","ACE_ARTY_1Rnd_60mmILLUM_M224","ACE_1Rnd_60mmHE_M224","ACE_1Rnd_60mmWP_M224","ACE_1Rnd_60mmILLUM_M224"};
	};
	class ACE_M240_veh_out;
	class ACE_M240_Tri: ACE_M240_veh_out
	{
		magazineReloadTime = 0;
		ballisticsComputer = 2;
	};
	class ACE_M240_M145_Tri: ACE_M240_Tri
	{
		ballisticsComputer = 0;
	};
	class BAF_L2A1;
	class ACE_BAF_L2A1_Tri: BAF_L2A1
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_200Rnd_127x99_M2","100Rnd_127x99_M2"};
	};
	class BAF_static_GMG;
	class ACE_BAF_static_GMG_Tri: BAF_static_GMG
	{
		reloadTime = 0.171;
		magazineReloadTime = 0;
		magazines[] = {"ACE_96Rnd_40mm_GMG","ACE_64Rnd_40mm_GMG","32Rnd_40mm_GMG","ACE_32Rnd_40mm_GMW_DM111DM42","ACE_32Rnd_40mm_GMW_DM42","ACE_32Rnd_40mm_GMW_DM111"};
	};
	class BAF_L7A2;
	class ACE_BAF_L7A2_Tri: BAF_L7A2
	{
		magazineReloadTime = 0;
	};
	class ACE_BAF_L7A2_M145_Tri: ACE_BAF_L7A2_Tri
	{
		ballisticsComputer = 0;
	};
	class KORD;
	class ACE_KORD_Tri: KORD
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_100Rnd_127x108_KORD","150Rnd_127x108_KORD","50Rnd_127x108_KORD"};
	};
	class DSHKM;
	class ACE_DSHKM_Tri: DSHKM
	{
		magazineReloadTime = 0;
		magazines[] = {"ACE_100Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","150Rnd_127x107_DSHKM"};
	};
	class AGS30;
	class ACE_AGS30_Tri: AGS30
	{
		reloadTime = 0.15;
		magazineReloadTime = 0;
		magazines[] = {"ACE_58Rnd_30mm_AGS30","ACE_29Rnd_30mm_AGS30"};
	};
	class 2B14: CannonCore
	{
		reloadTime = 1.5;
		magazineReloadTime = 1.5;
		class Single1;
		class Single2;
		class Single3;
	};
	class ACE_2B14_Tri: 2B14
	{
		magazineReloadtime = 0;
		magazines[] = {"ACE_ARTY_1Rnd_82mmHE_2B14","ACE_ARTY_1Rnd_82mmWP_2B14","ACE_ARTY_1Rnd_82mmILLUM_2B14","ACE_1Rnd_82mmHE_2B14","ACE_1Rnd_82mmWP_2B14","ACE_1Rnd_82mmILLUM_2B14"};
		class Single1: Single1
		{
			reloadTime = 1;
		};
		class Single2: Single2
		{
			reloadTime = 1;
		};
		class Single3: Single3
		{
			reloadTime = 1;
		};
	};
	class AT5Launcher;
	class AT5LauncherSingle: AT5Launcher
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		ace_magXchange_max = 1;
	};
	class ACE_AT5B_Launcher: AT5Launcher
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		ace_magXchange_max = 1;
	};
	class ACE_AT5LauncherSingle_Static: AT5LauncherSingle
	{
		magazines[] = {"ACE_AT5","ACE_AT5B","ACE_9K113M_1"};
		ace_magXchange_max = 0;
	};
	class AT13LauncherSingle;
	class ACE_AT13LauncherSingle_Static: AT13LauncherSingle
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		magazines[] = {"ACE_9K115M_1","ACE_1Rnd_9M131F"};
	};
	class SPG9;
	class ACE_SPG9: SPG9
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		magazines[] = {"ACE_PG9_AT","ACE_OG9_HE"};
	};
	class MissileLauncher;
	class TOWLauncher: MissileLauncher
	{
		ace_magXchange_max = 1;
	};
	class TOWLauncherSingle;
	class ACE_TOWLauncherSingle_Tri: TOWLauncherSingle
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		magazines[] = {"ACE_TOW2"};
	};
	class StingerLaucher: MissileLauncher
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		ace_magXchange_max = 1;
	};
	class StingerLauncher_twice: MissileLauncher
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		ace_magXchange_max = 1;
	};
	class Igla_twice: MissileLauncher
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		ace_magXchange_max = 1;
	};
	class ACE_9K31Launcher: MissileLauncher
	{
		magazineReloadTime = 0;
		reloadTime = 1;
		ace_magXchange_max = 1;
	};
	class RifleCore;
	class Rifle: RifleCore
	{
		class ACE;
	};
	class M240: Rifle
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				weapon = "ACE_M240_Tripod";
				canUseTripods[] = {"ACE_M122Tripod"};
			};
		};
	};
	class BAF_L7A2_GPMG: M240
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_BAF_GPMG_Minitripod_D";
			};
		};
	};
	class m240_scoped_EP1: M240
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "ACE_M240M145_Tripod";
			};
		};
	};
	class ACE_BAF_L7A2_GPMG: m240_scoped_EP1
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "BAF_GPMG_Minitripod_D";
			};
		};
	};
	class Mk_48: M240
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weapon = "";
				canUseTripods[] = {};
			};
		};
	};
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_crewserved: ACE_Dummy_Utility
		{
			magazines[] = {"ACE_M2_CSWDM","ACE_M2_CSWDM_90","ACE_M2_CSWDM_80","ACE_M2_CSWDM_70","ACE_M2_CSWDM_60","ACE_M2_CSWDM_50","ACE_M2_CSWDM_40","ACE_M2_CSWDM_30","ACE_M2_CSWDM_20","ACE_M2_CSWDM_10","ACE_MK19_CSWDM","ACE_MK19_CSWDM_90","ACE_MK19_CSWDM_80","ACE_MK19_CSWDM_70","ACE_MK19_CSWDM_60","ACE_MK19_CSWDM_50","ACE_MK19_CSWDM_40","ACE_MK19_CSWDM_30","ACE_MK19_CSWDM_20","ACE_MK19_CSWDM_10","ACE_KORD_CSWDM","ACE_KORD_CSWDM_90","ACE_KORD_CSWDM_80","ACE_KORD_CSWDM_70","ACE_KORD_CSWDM_60","ACE_KORD_CSWDM_50","ACE_KORD_CSWDM_40","ACE_KORD_CSWDM_30","ACE_KORD_CSWDM_20","ACE_KORD_CSWDM_10","ACE_DSHKM_CSWDM","ACE_DSHKM_CSWDM_90","ACE_DSHKM_CSWDM_80","ACE_DSHKM_CSWDM_70","ACE_DSHKM_CSWDM_60","ACE_DSHKM_CSWDM_50","ACE_DSHKM_CSWDM_40","ACE_DSHKM_CSWDM_30","ACE_DSHKM_CSWDM_20","ACE_DSHKM_CSWDM_10","ACE_AGS30_CSWDM","ACE_AGS30_CSWDM_90","ACE_AGS30_CSWDM_80","ACE_AGS30_CSWDM_70","ACE_AGS30_CSWDM_60","ACE_AGS30_CSWDM_50","ACE_AGS30_CSWDM_40","ACE_AGS30_CSWDM_30","ACE_AGS30_CSWDM_20","ACE_AGS30_CSWDM_10","ACE_AGS30_CSWDM","ACE_GMG_CSWDM_90","ACE_GMG_CSWDM_80","ACE_GMG_CSWDM_70","ACE_GMG_CSWDM_60","ACE_GMG_CSWDM_50","ACE_GMG_CSWDM_40","ACE_GMG_CSWDM_30","ACE_GMG_CSWDM_20","ACE_GMG_CSWDM_10","ACE_GMG_CSWDM","ACE_Konkurs_CSWDM","ACE_KonkursM_CSWDM","ACE_M252HE_CSWDM","ACE_M252WP_CSWDM","ACE_M252IL_CSWDM","ACE_2B14HE_CSWDM","ACE_2B14WP_CSWDM","ACE_2B14IL_CSWDM","ACE_TOW_CSWDM","ACE_Stinger_CSWDM","ACE_M224HE_CSWDM","ACE_M224WP_CSWDM","ACE_M224IL_CSWDM"};
		};
	};
	class ACE_M47StaticLauncher: TOWLauncher
	{
		displayName = "M47 Dragon";
		canLock = 0;
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons_E\Data\Anim\M47.rtm"};
		sound[] = {"Ca\Sounds_E\Weapons_E\M47\M47_1",3.1622777,1,1200};
		drySound[] = {"Ca\Sounds_E\Weapons_E\M47\dry",0.0001,1,10};
		reloadMagazineSound[] = {"Ca\Sounds_E\Weapons_E\M47\rocket_reload",1.0,1,30};
		soundFly[] = {"",3.1622777,1,500};
		initSpeed = 20;
		magazines[] = {"Dragon_EP1"};
		reloadTime = 0;
		magazineReloadTime = 0;
	};
	class M47Launcher_EP1: Launcher
	{
		model = "\x\ace\addons\m_wep_dragon\ace_m47_magazine.p3d";
		picture = "\x\ace\addons\m_wep_dragon\t\m47_dragon_item_ca.paa";
	};
	class ACE_M47_Daysight: M47Launcher_EP1
	{
		ace_weight = 3.1;
		dexterity = "(0.5 + 3.75/(3.1 + 0.001) + -3/10)";
		displayName = "$STR_DN_ACE_DRAGONSUP36";
		model = "\x\ace\addons\m_wep_dragon\ace_m47_optic.p3d";
		picture = "\x\ace\addons\m_wep_dragon\t\m47_daysight_item_ca.paa";
		optics = 1;
		weaponInfoType = "RscWeaponEmpty";
		modelOptics = "\ca\Weapons_e\optics_m47";
		reloadaction = "";
		showSwitchAction = 1;
		useAsBinocular = 1;
		uipicture = "";
		descriptionshort = "SU-36/P Daysight";
		ace_disposable = 0;
		magazines[] = {};
		type = 4096;
		opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
		opticsZoomMin = 0.015;
		opticsZoomMax = 0.015;
	};
	class ACE_BulletCounter: Rifle
	{
		scope = 1;
		displayName = "";
		model = "\ca\weapons_e\m16\M16A2";
		magazines[] = {"100Rnd_762x51_M240","200Rnd_556x45_M249","ACE_M2_CSWDM","ACE_MK19_CSWDM","ACE_GMG_CSWDM","ACE_GMW_DM111_CSWDM","ACE_GMW_DM42_CSWDM","ACE_GMW_DM111DM42_CSWDM","100Rnd_762x54_PK","ACE_DSHKM_CSWDM","ACE_KORD_CSWDM","ACE_AGS30_CSWDM"};
	};
};
class CfgVehicleClasses
{
	class ACE_Ammunition_CSW
	{
		displayName = "$STR_ACE_VC_ACE_AMMO_CSW";
	};
	class ACE_AmmunitionTransportCSW
	{
		displayName = "$STR_VC_ACE_AMMO_TRANSPORT_CSW";
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_CSW_AI: ACE_Logic
	{
		displayName = "$STR_ACE_CSW_AI";
		icon = "\x\ace\addons\sys_crewserved\data\icon\icon_ace_cswai_ca.paa";
		picture = "\x\ace\addons\sys_crewserved\data\icon\icon_ace_cswai_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "ACE_CSWFORAI = true; publicVariable ""ACE_CSWFORAI"";";
		};
	};
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
		class AnimationSources;
		class ViewPilot;
		class ViewGunner;
		class ViewOptics;
		class ACE;
	};
	class Car: LandVehicle
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				reloadtime = 22;
			};
		};
	};
	class Tank: LandVehicle
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				reloadtime = 22;
			};
		};
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "GetInOnly";
				reloadtime = 12;
				mountTime = 15;
				disassemblyType = "proxy";
				canDrag = 1;
				canCarry = 1;
				canChangeHeight = 0;
				nilMagazine = 0;
				nilMagazineAnim[] = {};
				emptyVirtualMagazine = 0;
			};
		};
	};
	class StaticATWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				reloadtime = 22;
			};
		};
	};
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class StaticGrenadeLauncher: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class StaticMortar: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				reloadtime = 1;
				canCarry = 0;
			};
		};
	};
	class StaticAAWeapon: StaticWeapon
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
				canCarry = 0;
				reloadtime = 22;
			};
		};
	};
	class Stinger_Pod_base: StaticAAWeapon
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				reloadtime = 18;
			};
		};
	};
	class Igla_AA_pod_East: StaticAAWeapon
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				reloadtime = 18;
			};
		};
	};
	class StaticCanon: StaticWeapon
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class WarfareBMGNest_M240_base: StaticMGWeapon
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
			};
		};
	};
	class WarfareBMGNest_PK_Base: StaticMGWeapon
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class UH1Wreck: StaticWeapon
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class M2StaticMG_base: StaticMGWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M2_Tri"};
				magazines[] = {"ACE_200Rnd_127x99_M2"};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_M2_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M2_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_M2_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "GetInOnly";
				isCSW = 0;
				weaponProxy = "ACE_M2HBProxy";
				tripod = "";
				magazines[] = {"ACE_M2_CSWDM","ACE_M2_CSWDM_90","ACE_M2_CSWDM_80","ACE_M2_CSWDM_70","ACE_M2_CSWDM_60","ACE_M2_CSWDM_50","ACE_M2_CSWDM_40","ACE_M2_CSWDM_30","ACE_M2_CSWDM_20","ACE_M2_CSWDM_10"};
				links[] = {100,1};
				max = 200;
				gunnerCanReload = 0;
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class M2HD_mini_TriPod: M2StaticMG_base
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_M2HBProxy";
				tripod = "ACE_M3Tripod";
				magazines[] = {"ACE_M2_CSWDM","ACE_M2_CSWDM_90","ACE_M2_CSWDM_80","ACE_M2_CSWDM_70","ACE_M2_CSWDM_60","ACE_M2_CSWDM_50","ACE_M2_CSWDM_40","ACE_M2_CSWDM_30","ACE_M2_CSWDM_20","ACE_M2_CSWDM_10"};
				links[] = {100,1};
				max = 200;
				gunnerCanReload = 0;
				canCarry = 1;
			};
		};
		ACE_Weight = 58;
		attachPosFront[] = {0,-0.1,1};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class Mk19_Tripod: StaticGrenadeLauncher
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_MK19_Tri"};
				magazines[] = {"ACE_96Rnd_40mm_MK19"};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_MK19MOD3Proxy";
				tripod = "ACE_M3Tripod";
				magazines[] = {"ACE_MK19_CSWDM","ACE_MK19_CSWDM_90","ACE_MK19_CSWDM_80","ACE_MK19_CSWDM_70","ACE_MK19_CSWDM_60","ACE_MK19_CSWDM_50","ACE_MK19_CSWDM_40","ACE_MK19_CSWDM_30","ACE_MK19_CSWDM_20","ACE_MK19_CSWDM_10"};
				links[] = {48,1};
				max = 96;
				canCarry = 1;
			};
		};
		ACE_Weight = 55;
		attachPosFront[] = {-0.4,-0.5,1};
		attachPosRear[] = {-0.9,-0.4,0};
	};
	class ACE_M240_Tripod: M2HD_mini_TriPod
	{
		scope = 1;
		mapSize = 1.5;
		displayName = "M122 M240";
		picture = "\CA\weapons_baf\data\UI\gpmg_c97_minitripod_ca.paa";
		model = "\x\ace\addons\sys_crewserved\ace_m240_static.p3d";
		getInAction = "Metis_Gunner";
		getOutAction = "PlayerProne";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M240_Tri"};
				magazines[] = {"ACE_200Rnd_762x51_M240"};
				gunnerAction = "Metis_Gunner";
				gunnerInAction = "Metis_Gunner";
				gunnerGetInAction = "Metis_Gunner";
				gunnerGetOutAction = "PlayerProne";
				discretedistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discretedistanceinitindex = 3;
				turretinfotype = "RscWeaponZeroing";
				maxHorizontalRotSpeed = 0.25;
				minTurn = -40;
				maxTurn = 40;
				initTurn = 0;
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_M240_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_M240_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				isCSW = 1;
				weaponProxy = "M240";
				tripod = "ACE_M122Tripod";
				magazines[] = {"100Rnd_762x51_M240"};
				links[] = {100,1};
				max = 200;
				gunnerCanReload = 1;
				reloadTime = 10;
				mountTime = 6;
				canCarry = 1;
			};
		};
		ACE_Weight = 18.26;
		attachPosFront[] = {-0.4,-0.1,0.5};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class ACE_M240M145_Tripod: ACE_M240_Tripod
	{
		scope = 2;
		displayName = "M122 M240 M145";
		model = "\x\ace\addons\sys_crewserved\ace_m240_M145_static.p3d";
		faction = "BIS_US";
		crew = "US_Soldier_EP1";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M240_M145_Tri"};
				turretinfotype = "RscWeaponEmpty";
				discretedistance[] = {312};
				discretedistanceinitindex = 0;
				gunneropticsmodel = "\x\ace\addons\m_wep_optics\ace_optics_m145";
				optics = 1;
				class ViewOptics
				{
					initfov = 0.085333;
					maxfov = 0.085333;
					minfov = 0.085333;
					initanglex = 0;
					initangley = 0;
					maxanglex = 30;
					maxangley = 100;
					minanglex = -30;
					minangley = -100;
					visionMode[] = {"Normal"};
				};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_M240_M145_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_M145_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_M240_M145_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weaponProxy = "m240_scoped_EP1";
			};
		};
	};
	class ACE_M240B_Tripod: ACE_M240_Tripod
	{
		scope = 1;
		displayName = "M122 M240B";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				discretedistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discretedistanceinitindex = 3;
				turretinfotype = "RscWeaponZeroing";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weaponProxy = "ACE_M240B";
			};
		};
	};
	class ACE_M240L_Tripod: ACE_M240B_Tripod
	{
		displayName = "M122 M240L";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weaponProxy = "ACE_M240L";
			};
		};
	};
	class ACE_M240L_M145_Tripod: ACE_M240M145_Tripod
	{
		scope = 1;
		displayName = "M122 M240L M145";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weaponProxy = "ACE_M240L_M145";
			};
		};
	};
	class BAF_L2A1_ACOG_base: StaticMGWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_BAF_L2A1_Tri"};
				magazines[] = {"ACE_200Rnd_127x99_M2"};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_BAF_L2A1_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_BAF_L2A1_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_BAF_L2A1_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "GetInOnly";
				isCSW = 0;
				weaponProxy = "ACE_BAF_L2A1Proxy";
				tripod = "";
				magazines[] = {"ACE_M2_CSWDM","ACE_M2_CSWDM_90","ACE_M2_CSWDM_80","ACE_M2_CSWDM_70","ACE_M2_CSWDM_60","ACE_M2_CSWDM_50","ACE_M2_CSWDM_40","ACE_M2_CSWDM_30","ACE_M2_CSWDM_20","ACE_M2_CSWDM_10"};
				links[] = {100,1};
				max = 200;
				canCarry = 0;
			};
		};
	};
	class BAF_L2A1_Minitripod_D: BAF_L2A1_ACOG_base
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_BAF_L2A1Proxy";
				tripod = "ACE_M3Tripod";
				magazines[] = {"ACE_M2_CSWDM","ACE_M2_CSWDM_90","ACE_M2_CSWDM_80","ACE_M2_CSWDM_70","ACE_M2_CSWDM_60","ACE_M2_CSWDM_50","ACE_M2_CSWDM_40","ACE_M2_CSWDM_30","ACE_M2_CSWDM_20","ACE_M2_CSWDM_10"};
				links[] = {100,1};
				max = 200;
				canCarry = 1;
			};
		};
		attachPosFront[] = {0,-0.1,1};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class BAF_GPMG_Minitripod_D: BAF_L2A1_ACOG_base
	{
		model = "\x\ace\addons\sys_crewserved\ace_m240_M145_static.p3d";
		displayName = "GPMG Minitripod (M145)";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerAction = "Metis_Gunner";
				gunnerInAction = "Metis_Gunner";
				gunnerGetInAction = "Metis_Gunner";
				gunnerGetOutAction = "PlayerProne";
				weapons[] = {"ACE_BAF_L7A2_M145_Tri"};
				magazines[] = {"ACE_200Rnd_762x51_M240"};
				discretedistance[] = {100,200,300,400,500,600,700,800,900,1000};
				discretedistanceinitindex = 3;
				turretinfotype = "RscWeaponZeroing";
				maxHorizontalRotSpeed = 0.25;
				minTurn = -40;
				maxTurn = 40;
				initTurn = 0;
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_BAF_L7A2_M145_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_BAF_L7A2_M145_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_BAF_L7A2_M145_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_BAF_L7A2_GPMG";
				tripod = "ACE_M122Tripod";
				magazines[] = {"100Rnd_762x51_M240"};
				links[] = {100,1};
				max = 200;
				gunnerCanReload = 1;
				reloadTime = 8;
				mountTime = 6;
				canCarry = 1;
			};
		};
		ACE_Weight = 18.26;
		attachPosFront[] = {-0.4,-0.1,0.5};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class ACE_BAF_GPMG_Minitripod_D: BAF_GPMG_Minitripod_D
	{
		displayName = "GPMG Minitripod";
		model = "\x\ace\addons\sys_crewserved\ace_m240_static.p3d";
		getInAction = "Metis_Gunner";
		getOutAction = "PlayerProne";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_BAF_L7A2_Tri"};
				gunnerAction = "Metis_Gunner";
				gunnerInAction = "Metis_Gunner";
				gunnerGetInAction = "Metis_Gunner";
				gunnerGetOutAction = "PlayerProne";
				optics = 1;
				gunnerOpticsModel = "\ca\Weapons\optika_empty";
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_BAF_L7A2_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_BAF_L7A2_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_BAF_L7A2_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				weaponProxy = "BAF_L7A2_GPMG";
			};
		};
	};
	class GMG_TriPod: StaticGrenadeLauncher
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class BAF_GMG_Tripod_D: GMG_TriPod
	{
		flash = "gunfire";
		flashSize = 0.1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_BAF_static_GMG_Tri"};
				magazines[] = {"32Rnd_40mm_GMG"};
				selectionFireAnim = "";
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_BAF_static_GMG_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_BAF_static_GMG_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_BAF_static_GMG_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_BAF_static_GMGProxy";
				tripod = "ACE_GMGTripod";
				magazines[] = {"ACE_GMG_CSWDM","ACE_GMG_CSWDM_90","ACE_GMG_CSWDM_80","ACE_GMG_CSWDM_70","ACE_GMG_CSWDM_60","ACE_GMG_CSWDM_50","ACE_GMG_CSWDM_40","ACE_GMG_CSWDM_30","ACE_GMG_CSWDM_20","ACE_GMG_CSWDM_10","ACE_GMW_DM42_CSWDM","ACE_GMW_DM42_CSWDM_90","ACE_GMW_DM42_CSWDM_80","ACE_GMW_DM42_CSWDM_70","ACE_GMW_DM42_CSWDM_60","ACE_GMW_DM42_CSWDM_50","ACE_GMW_DM42_CSWDM_40","ACE_GMW_DM42_CSWDM_30","ACE_GMW_DM42_CSWDM_20","ACE_GMW_DM42_CSWDM_10","ACE_GMW_DM111_CSWDM","ACE_GMW_DM111_CSWDM_90","ACE_GMW_DM111_CSWDM_80","ACE_GMW_DM111_CSWDM_70","ACE_GMW_DM111_CSWDM_60","ACE_GMW_DM111_CSWDM_50","ACE_GMW_DM111_CSWDM_40","ACE_GMW_DM111_CSWDM_30","ACE_GMW_DM111_CSWDM_20","ACE_GMW_DM111_CSWDM_10","ACE_GMW_DM111DM42_CSWDM","ACE_GMW_DM111DM42_CSWDM_90","ACE_GMW_DM111DM42_CSWDM_80","ACE_GMW_DM111DM42_CSWDM_70","ACE_GMW_DM111DM42_CSWDM_60","ACE_GMW_DM111DM42_CSWDM_50","ACE_GMW_DM111DM42_CSWDM_40","ACE_GMW_DM111DM42_CSWDM_30","ACE_GMW_DM111DM42_CSWDM_20","ACE_GMW_DM111DM42_CSWDM_10"};
				links[] = {32,0};
				max = 32;
				canCarry = 1;
			};
		};
		ACE_Weight = 55;
		attachPosFront[] = {-0.5,-0.5,1};
		attachPosRear[] = {-0.9,-0.2,0};
	};
	class KORD_Base: StaticMGWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_KORD_Tri"};
				magazines[] = {"ACE_100Rnd_127x108_KORD"};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_KORD_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_KORD_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_KORD_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_KORDProxy";
				tripod = "ACE_6T7Tripod";
				magazines[] = {"ACE_KORD_CSWDM","ACE_KORD_CSWDM_90","ACE_KORD_CSWDM_80","ACE_KORD_CSWDM_70","ACE_KORD_CSWDM_60","ACE_KORD_CSWDM_50","ACE_KORD_CSWDM_40","ACE_KORD_CSWDM_30","ACE_KORD_CSWDM_20","ACE_KORD_CSWDM_10"};
				links[] = {50,1};
				max = 100;
				canCarry = 1;
			};
		};
		ACE_Weight = 41;
		attachPosFront[] = {-0.5,-0.3,1};
		attachPosRear[] = {-0.8,0.1,0};
	};
	class KORD: KORD_Base{};
	class KORD_high: KORD
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "GetInOnly";
				isCSW = 0;
				weaponProxy = "ACE_KORDProxy";
				tripod = "";
				magazines[] = {"ACE_KORD_CSWDM","ACE_KORD_CSWDM_90","ACE_KORD_CSWDM_80","ACE_KORD_CSWDM_70","ACE_KORD_CSWDM_60","ACE_KORD_CSWDM_50","ACE_KORD_CSWDM_40","ACE_KORD_CSWDM_30","ACE_KORD_CSWDM_20","ACE_KORD_CSWDM_10"};
				links[] = {50,1};
				max = 100;
				canCarry = 0;
			};
		};
	};
	class DSHKM_base: StaticMGWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_DSHKM_Tri"};
				magazines[] = {"ACE_100Rnd_127x107_DSHKM"};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_DSHKM_Tri";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_DSHKM_Tri";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_DSHKM_Tri";
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "GetInOnly";
				isCSW = 0;
				weaponProxy = "ACE_DSHKMProxy";
				tripod = "";
				magazines[] = {"ACE_DSHKM_CSWDM","ACE_DSHKM_CSWDM_90","ACE_DSHKM_CSWDM_80","ACE_DSHKM_CSWDM_70","ACE_DSHKM_CSWDM_60","ACE_DSHKM_CSWDM_50","ACE_DSHKM_CSWDM_40","ACE_DSHKM_CSWDM_30","ACE_DSHKM_CSWDM_20","ACE_DSHKM_CSWDM_10"};
				links[] = {50,1};
				max = 100;
				canCarry = 0;
			};
		};
	};
	class DSHkM_Mini_TriPod: DSHKM_base
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_DSHKMProxy";
				tripod = "ACE_DSHKMTripod";
				magazines[] = {"ACE_DSHKM_CSWDM","ACE_DSHKM_CSWDM_90","ACE_DSHKM_CSWDM_80","ACE_DSHKM_CSWDM_70","ACE_DSHKM_CSWDM_60","ACE_DSHKM_CSWDM_50","ACE_DSHKM_CSWDM_40","ACE_DSHKM_CSWDM_30","ACE_DSHKM_CSWDM_20","ACE_DSHKM_CSWDM_10"};
				links[] = {50,1};
				max = 100;
				canCarry = 1;
			};
		};
		ACE_Weight = 40;
		attachPosFront[] = {-0.5,-0.3,1};
		attachPosRear[] = {-0.8,0.1,0};
	};
	class AGS_base: StaticGrenadeLauncher
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_AGS30_Tri"};
				magazines[] = {"ACE_58Rnd_30mm_AGS30"};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_AGS30Proxy";
				tripod = "ACE_AGS30Tripod";
				magazines[] = {"ACE_AGS30_CSWDM","ACE_AGS30_CSWDM_90","ACE_AGS30_CSWDM_80","ACE_AGS30_CSWDM_70","ACE_AGS30_CSWDM_60","ACE_AGS30_CSWDM_50","ACE_AGS30_CSWDM_40","ACE_AGS30_CSWDM_30","ACE_AGS30_CSWDM_20","ACE_AGS30_CSWDM_10"};
				links[] = {29,1};
				max = 58;
				canCarry = 1;
			};
		};
		ACE_Weight = 16.5;
		attachPosFront[] = {-0.4,-0.5,1};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class ACE_NoGeo_Tripod_Base: StaticWeapon
	{
		scope = 1;
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m3.p3d";
		icon = "\ca\data\data\Unknown_object.paa";
		displayName = "";
		nameSound = "";
		destrType = "DestructNo";
		transportSoldier = 0;
		typicalCargo[] = {};
		crew = "";
		hasDriver = 0;
		hasGunner = 0;
		hasCommander = 0;
		ejectDamageLimit = -1;
		getInRadius = 0;
		class Turrets{};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "";
				canDrag = 0;
			};
		};
	};
	class ACE_Tripod_Base: ACE_NoGeo_Tripod_Base
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Tripod";
				canDrag = 1;
				pickupTime = 10;
			};
		};
		ACE_Weight = 20;
	};
	class ACE_M3Tripod: ACE_Tripod_Base
	{
		displayName = "$STR_DN_ACE_M3TRIPOD";
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m3.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_M3TripodProxy";
				pickupTime = 8;
			};
		};
		ACE_Weight = 20;
	};
	class ACE_M3Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m3_NoGeo.p3d";
	};
	class ACE_GMGTripod: ACE_Tripod_Base
	{
		displayName = "$STR_DN_ACE_GMGTRIPOD";
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m3.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_GMGTripodProxy";
				pickupTime = 12;
			};
		};
		ACE_Weight = 20;
	};
	class ACE_GMGTripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m3_NoGeo.p3d";
	};
	class ACE_M122Tripod: ACE_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m122.p3d";
		displayName = "$STR_DN_ACE_M122TRIPOD";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_M122TripodProxy";
				pickupTime = 4;
			};
		};
		ACE_Weight = 7.26;
	};
	class ACE_M122Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m122_NoGeo.p3d";
	};
	class ACE_6T7Tripod: ACE_Tripod_Base
	{
		displayName = "$STR_DN_ACE_6T7TRIPOD";
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_kord.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_6T7TripodProxy";
				pickupTime = 8;
			};
		};
		ACE_Weight = 16;
	};
	class ACE_6T7Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_kord_NoGeo.p3d";
	};
	class ACE_AGS30Tripod: ACE_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_ags30.p3d";
		displayName = "$STR_DN_ACE_AGS30TRIPOD";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_AGS30TripodProxy";
				pickupTime = 8;
			};
		};
		ACE_Weight = 6;
	};
	class ACE_AGS30Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_ags30_NoGeo.p3d";
	};
	class ACE_DSHKMTripod: ACE_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_ags30.p3d";
		displayName = "$STR_DN_ACE_DSHKMTRIPOD";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_DSHKMTripodProxy";
			};
		};
		ACE_Weight = 6;
	};
	class ACE_DSHKMTripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_ags30_NoGeo.p3d";
	};
	class ACE_KonkursTripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_konkurs_NoGeo.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				pickupTime = 6;
			};
		};
	};
	class M252: StaticMortar
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_M252Proxy";
				tripod = "ACE_M252Tripod";
				magazines[] = {"ACE_M252HE_CSWDM","ACE_M252WP_CSWDM","ACE_M252IL_CSWDM"};
				links[] = {0,0};
				max = 1;
				fireOnReload = 0;
				mountTime = 10;
				canDrag = 0;
				canCarry = 0;
			};
		};
		ACE_Weight = 41.3;
	};
	class M252_Base: M252{};
	class M252_US_EP1: M252_Base{};
	class ACE_M252: M252_US_EP1
	{
		scope = 1;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M252_Tri"};
				magazines[] = {};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				magazines[] = {};
				fireOnReload = 2;
			};
		};
	};
	class ACE_M224: M252_US_EP1
	{
		scope = 1;
		displayName = "$STR_DN_ACE_M224";
		model = "\x\ace\addons\sys_crewserved\ace_m224.p3d";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_M224_Tri"};
				magazines[] = {};
				minElev = -17.36875;
				maxElev = 22.63125;
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				isCSW = 1;
				weaponProxy = "ACE_M224Proxy";
				tripod = "ACE_M224Tripod";
				magazines[] = {"ACE_M224HE_CSWDM","ACE_M224WP_CSWDM","ACE_M224IL_CSWDM"};
				links[] = {0,0};
				max = 1;
				fireOnReload = 0;
				mountTime = 10;
				canDrag = 1;
				canCarry = 1;
			};
		};
		ACE_Weight = 21.1;
		attachPosFront[] = {-0.4,-0.35,0.2};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class ACE_M224_1: ACE_M224
	{
		scope = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				magazines[] = {};
				fireonreload = 0;
			};
		};
	};
	class 2b14_82mm: StaticMortar
	{
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_2b14Proxy";
				tripod = "ACE_2b14Tripod";
				magazines[] = {"ACE_2B14HE_CSWDM","ACE_2B14WP_CSWDM","ACE_2B14IL_CSWDM"};
				links[] = {0,0};
				max = 1;
				fireOnReload = 0;
				mountTime = 10;
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class 2b14_82mm_base: 2b14_82mm{};
	class 2b14_82mm_TK_GUE_EP1: 2b14_82mm_base{};
	class ACE_2b14_82mm: 2b14_82mm_TK_GUE_EP1
	{
		scope = 1;
		displayname = "$STR_DN_ACE_2B14";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_2B14_Tri"};
				magazines[] = {};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				magazines[] = {};
				fireonreload = 2;
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class TOW_TriPod: StaticATWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_TOWLauncherSingle_Tri"};
				magazines[] = {"ACE_TOW2"};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_M220Proxy";
				tripod = "ACE_M220Tripod";
				magazines[] = {"ACE_TOW_CSWDM"};
				links[] = {0,0};
				max = 1;
				canDrag = 0;
				canCarry = 0;
			};
		};
		ACE_Weight = 60.1;
	};
	class TOW_TriPod_Base: StaticATWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_TOWLauncherSingle_Tri"};
				magazines[] = {"ACE_TOW2"};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_M220Proxy";
				tripod = "ACE_M220Tripod";
				magazines[] = {"ACE_TOW_CSWDM"};
				links[] = {0,0};
				max = 1;
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class TOW_TriPod_US_EP1: TOW_TriPod_Base
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_TOWLauncherSingle_Tri"};
				magazines[] = {"ACE_TOW2"};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_M220Proxy";
				tripod = "ACE_M220Tripod";
				magazines[] = {"ACE_TOW_CSWDM"};
				links[] = {0,0};
				max = 1;
				canDrag = 0;
				canCarry = 0;
			};
		};
	};
	class ACE_M47_Static: TOW_TriPod
	{
		scope = 1;
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "XXX";
			};
		};
	};
	class ACE_Konkurs: StaticATWeapon
	{
		scope = 1;
		side = 0;
		faction = "RU";
		crew = "RU_Soldier";
		displayName = "$STR_DN_ACE_KONKURS";
		typicalCargo[] = {"RU_Soldier"};
		model = "\x\ace\addons\sys_crewserved\ace_konkurs.p3d";
		class Library
		{
			libTextDesc = "";
		};
		picture = "\Ca\weapons\data\ico\metis_at13_CA.paa";
		icon = "\Ca\weapons\data\map_ico\icomap_metis_at13_CA.paa";
		mapSize = 3;
		getInAction = "Metis_Gunner";
		getOutAction = "PlayerProne";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minTurn = -45;
				maxTurn = 45;
				initTurn = 0;
				minElev = -10;
				maxElev = 40;
				initElev = 0;
				weapons[] = {"ACE_AT5LauncherSingle_Static"};
				magazines[] = {"ACE_AT5B"};
				gunnerOpticsModel = "\ca\weapons\2Dscope_Metis";
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 0;
				gunnerAction = "Metis_Gunner";
				gunnerInAction = "Metis_Gunner";
				gunnerGetInAction = "Metis_Gunner";
				gunnerGetOutAction = "PlayerProne";
				gunBeg = "spice rakety";
				gunEnd = "konec rakety";
				gunnerForceOptics = 0;
				ejectDeadGunner = 0;
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -165;
					maxAngleY = 125;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.078;
					minFov = 0.078;
					maxFov = 0.078;
					visionmode[] = {"Normal"};
				};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "ACE_KonkursTripodProxy";
				tripodProxy = "ACE_KonkursTripodProxy";
				tripod = "Logic";
				magazines[] = {"ACE_Konkurs_CSWDM","ACE_KonkursM_CSWDM"};
				links[] = {0,0};
				max = 1;
				canDrag = 0;
				canCarry = 1;
				nilMagazine = 1;
				nilMagazineAnim[] = {{"hide_magazine",1}};
			};
		};
		ACE_Weight = 22;
		attachPosFront[] = {-0.35,0,0.8};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class ACE_Konkurs_TK: ACE_Konkurs
	{
		scope = 2;
		faction = "BIS_TK";
		crew = "TK_Soldier_EP1";
		typicalCargo[] = {"TK_Soldier_EP1"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[] = {"ACE_AT5"};
			};
		};
	};
	class Metis: StaticATWeapon
	{
		getInAction = "Metis_Gunner";
		getOutAction = "PlayerProne";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerGetInAction = "Metis_Gunner";
				gunnerGetOutAction = "PlayerProne";
				weapons[] = {"ACE_AT13LauncherSingle_Static"};
				magazines[] = {"ACE_9K115M_1"};
			};
		};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Crewserved";
				isCSW = 1;
				weaponProxy = "MetisLauncher";
				tripodProxy = "MetisLauncher";
				tripod = "Logic";
				magazines[] = {"AT13","ACE_AT13TB"};
				links[] = {0,0};
				max = 1;
				canDrag = 0;
				canCarry = 1;
			};
		};
		ACE_Weight = 13.8;
		attachPosFront[] = {-0.6,-0.6,1};
		attachPosRear[] = {-0.8,-0.3,0};
	};
	class ACE_M252Tripod: ACE_Tripod_Base
	{
		displayName = "$STR_DN_ACE_M252TRIPOD";
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m252.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_M252TripodProxy";
				mountTime = 8;
				pickupTime = 4;
			};
		};
	};
	class ACE_M252Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m252_NoGeo.p3d";
	};
	class ACE_M224Tripod: ACE_Tripod_Base
	{
		displayName = "$STR_DN_ACE_M224TRIPOD";
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m224.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_M224TripodProxy";
				mountTime = 5;
				pickupTime = 2;
			};
		};
	};
	class ACE_M224Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m224_NoGeo.p3d";
	};
	class ACE_M220Tripod: ACE_Tripod_Base
	{
		displayName = "TOW Tripod";
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m220.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_M220TripodProxy";
				mountTime = 20;
				pickupTime = 15;
			};
		};
	};
	class ACE_M220Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m220_NoGeo.p3d";
	};
	class ACE_2b14Tripod: ACE_Tripod_Base
	{
		displayName = "$STR_DN_ACE_2B14TRIPOD";
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m252.p3d";
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				tripodProxy = "ACE_2b14TripodProxy";
				mountTime = 8;
				pickupTime = 6;
			};
		};
	};
	class ACE_2b14Tripod_NoGeo: ACE_NoGeo_Tripod_Base
	{
		model = "\x\ace\addons\sys_crewserved\tripods\ace_tripod_m252_NoGeo.p3d";
	};
	class ReammoBox;
	class ACE_CSW_Box_Base: ReammoBox
	{
		scope = 1;
		vehicleClass = "ACE_AmmunitionTransportCSW";
		displayName = "";
		model = "\ca\misc\drevena_bedna.p3d";
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class ACE_CSW_Box_M2: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_M2";
		class TransportWeapons
		{
			class _xx_ACE_M2HBProxy
			{
				weapon = "ACE_M2HBProxy";
				count = 1;
			};
			class _xx_ACE_M3TripodProxy
			{
				weapon = "ACE_M3TripodProxy";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_M2_CSWDM
			{
				magazine = "ACE_M2_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_Mk19: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_MK19";
		class TransportWeapons
		{
			class _xx_ACE_MK19MOD3Proxy
			{
				weapon = "ACE_MK19MOD3Proxy";
				count = 1;
			};
			class _xx_ACE_M3TripodProxy
			{
				weapon = "ACE_M3TripodProxy";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_MK19_CSWDM
			{
				magazine = "ACE_MK19_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_M252: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_M252";
		vehicleClass = "ACE_Arty_Equipment";
		class TransportWeapons
		{
			class _xx_ACE_M252Proxy
			{
				weapon = "ACE_M252Proxy";
				count = 1;
			};
			class _xx_ACE_M252TripodProxy
			{
				weapon = "ACE_M252TripodProxy";
				count = 1;
			};
		};
	};
	class ACE_CSW_Box_M224: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_M224";
		vehicleClass = "ACE_Arty_Equipment";
		class TransportWeapons
		{
			class _xx_ACE_M224Proxy
			{
				weapon = "ACE_M224Proxy";
				count = 1;
			};
			class _xx_ACE_M224TripodProxy
			{
				weapon = "ACE_M224TripodProxy";
				count = 1;
			};
		};
	};
	class ACE_CSW_Box_AGS30: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_AGS30";
		class TransportWeapons
		{
			class _xx_ACE_AGS30Proxy
			{
				weapon = "ACE_AGS30Proxy";
				count = 1;
			};
			class _xx_ACE_AGS30TripodProxy
			{
				weapon = "ACE_AGS30TripodProxy";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_AGS30_CSWDM
			{
				magazine = "ACE_AGS30_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_GMG: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_GMG";
		class TransportWeapons
		{
			class _xx_ACE_BAF_static_GMGProxy
			{
				weapon = "ACE_BAF_static_GMGProxy";
				count = 1;
			};
			class _xx_ACE_GMGTripodProxy
			{
				weapon = "ACE_GMGTripodProxy";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_GMG_CSWDM
			{
				magazine = "ACE_GMG_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_KORD: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_KORD";
		class TransportWeapons
		{
			class _xx_ACE_KORDProxy
			{
				weapon = "ACE_KORDProxy";
				count = 1;
			};
			class _xx_ACE_6T7TripodProxy
			{
				weapon = "ACE_6T7TripodProxy";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_KORD_CSWDM
			{
				magazine = "ACE_KORD_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_DSHKM: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_DSHKM";
		class TransportWeapons
		{
			class _xx_ACE_DSHKMProxy
			{
				weapon = "ACE_DSHKMProxy";
				count = 1;
			};
			class _xx_ACE_DSHKMTripodProxy
			{
				weapon = "ACE_DSHKMTripodProxy";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_DSHKM_CSWDM
			{
				magazine = "ACE_DSHKM_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_KONKURS: ACE_CSW_Box_Base
	{
		scope = 1;
		displayName = "$STR_DN_ACE_CSW_BOX_KONKURS";
		class TransportWeapons
		{
			class _xx_ACE_KonkursTripodProxy
			{
				weapon = "ACE_KonkursTripodProxy";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_Metis: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_METIS";
		class TransportWeapons
		{
			class _xx_MetisLauncher
			{
				weapon = "MetisLauncher";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_AT13
			{
				magazine = "AT13";
				count = 4;
			};
		};
	};
	class ACE_CSW_Box_2B14: ACE_CSW_Box_Base
	{
		scope = 2;
		displayName = "$STR_DN_ACE_CSW_BOX_2B14";
		vehicleClass = "ACE_Arty_Equipment";
		class TransportWeapons
		{
			class _xx_ACE_2b14TripodProxy
			{
				weapon = "ACE_2b14TripodProxy";
				count = 1;
			};
			class _xx_ACE_2b14Proxy
			{
				weapon = "ACE_2b14Proxy";
				count = 1;
			};
		};
	};
	class ACE_Tbox_GP_W;
	class ACE_Tbox_GP_R;
	class ACE_Tbox_Konkurs_CSWDM: ACE_Tbox_GP_R
	{
		vehicleClass = "ACE_Ammunition_CSW";
		displayName = "$STR_DN_ACE_CSW_BOX_KONKURS_AMMO";
		transportMaxWeapons = 0;
		transportMaxMagazines = 2;
		class TransportMagazines
		{
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 2;
			};
		};
	};
	class ACE_Tbox_KonkursM_CSWDM: ACE_Tbox_Konkurs_CSWDM
	{
		displayName = "$STR_DN_ACE_CSW_BOX_KONKURSM_AMMO";
		class TransportMagazines
		{
			class _xx_ACE_KonkursM_CSWDM
			{
				magazine = "ACE_KonkursM_CSWDM";
				count = 2;
			};
		};
	};
	class ACE_Tbox_Metis_CSWDM: ACE_Tbox_GP_R
	{
		vehicleClass = "ACE_Ammunition_CSW";
		displayName = "$STR_DN_ACE_CSW_BOX_METIS_AMMO";
		transportMaxWeapons = 0;
		transportMaxMagazines = 2;
		class TransportMagazines
		{
			class _xx_AT13
			{
				magazine = "AT13";
				count = 2;
			};
		};
	};
	class ACE_Tbox_MetisTB_CSWDM: ACE_Tbox_Konkurs_CSWDM
	{
		displayName = "$STR_DN_ACE_CSW_BOX_METISTB_AMMO";
		class TransportMagazines
		{
			class _xx_ACE_AT13TB
			{
				magazine = "ACE_AT13TB";
				count = 2;
			};
		};
	};
	class ACE_Tbox_Mortar_81mmHE: ACE_Tbox_GP_W
	{
		vehicleClass = "ACE_Ammunition_CSW";
		displayName = "$STR_DN_ACE_CSW_BOX_M252_AMMOHE";
		transportMaxWeapons = 0;
		transportMaxMagazines = 4;
		class TransportMagazines
		{
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_81mmWP: ACE_Tbox_Mortar_81mmHE
	{
		displayName = "$STR_DN_ACE_CSW_BOX_M252_AMMOWP";
		class TransportMagazines
		{
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_81mmIL: ACE_Tbox_Mortar_81mmHE
	{
		displayName = "$STR_DN_ACE_CSW_BOX_M252_AMMOIL";
		class TransportMagazines
		{
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_60mmHE: ACE_Tbox_GP_W
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition_CSW";
		displayName = "$STR_DN_ACE_CSW_BOX_M224_AMMOHE";
		transportMaxWeapons = 0;
		transportMaxMagazines = 8;
		class TransportMagazines
		{
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 8;
			};
		};
	};
	class ACE_Tbox_Mortar_60mmWP: ACE_Tbox_Mortar_81mmHE
	{
		scope = 1;
		displayName = "$STR_DN_ACE_CSW_BOX_M224_AMMOWP";
		class TransportMagazines
		{
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 8;
			};
		};
	};
	class ACE_Tbox_Mortar_60mmIL: ACE_Tbox_Mortar_81mmHE
	{
		scope = 1;
		displayName = "$STR_DN_ACE_CSW_BOX_M224_AMMOIL";
		class TransportMagazines
		{
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
				count = 8;
			};
		};
	};
	class ACE_Tbox_Mortar_82mmHE: ACE_Tbox_GP_R
	{
		vehicleClass = "ACE_Ammunition_CSW";
		displayName = "$STR_DN_ACE_CSW_BOX_2B14_AMMOHE";
		transportMaxWeapons = 0;
		transportMaxMagazines = 4;
		class TransportMagazines
		{
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_82mmWP: ACE_Tbox_Mortar_82mmHE
	{
		displayName = "$STR_DN_ACE_CSW_BOX_2B14_AMMOWP";
		class TransportMagazines
		{
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_82mmIL: ACE_Tbox_Mortar_82mmHE
	{
		displayName = "$STR_DN_ACE_CSW_BOX_2B14_AMMOIL";
		class TransportMagazines
		{
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 4;
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_crewserved
	{
		init = "call ('\x\ace\addons\sys_crewserved\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_crewserved\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_crewserved
	{
		init = "call ('\x\ace\addons\sys_crewserved\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Tank
	{
		class ace_sys_crewserved_reload
		{
			firedBis = "if (local (_this select 0) && {!isPlayer (_this select 0)}) then { _this call ace_sys_crewserved_fnc_fired }";
		};
	};
	class Car
	{
		class ace_sys_crewserved_reload
		{
			firedBis = "if (local (_this select 0) && {!isPlayer (_this select 0)}) then { _this call ace_sys_crewserved_fnc_fired }";
		};
	};
	class StaticWeapon
	{
		class ace_sys_crewserved_reload
		{
			firedBis = "if (local (_this select 0) && {!isPlayer (_this select 0)}) then { _this call ace_sys_crewserved_fnc_fired }";
		};
	};
	class BAF_GMG_Tripod_D
	{
		class ace_sys_crewserved_tracer
		{
			clientFiredBis = "if ((_this select 4) isKindOf 'GrenadeBase') then { _this call ace_sys_vehicle_fnc_40mm_tracer }";
		};
	};
	class ACE_M47_Static
	{
		class ace_sys_crewserved_dragon_x
		{
			firedBis = "if (local (_this select 0)) then { _this call ace_sys_crewserved_fnc_dragonLauncherFired }";
		};
	};
};
class Extended_GetIn_Eventhandlers
{
	class ACE_M47_Static
	{
		clientGetin = "_this call ace_sys_crewserved_fnc_getInDragon";
	};
};
class Extended_GetOut_Eventhandlers
{
	class ACE_M47_Static
	{
		clientGetout = "_this call ace_sys_crewserved_fnc_getOutDragon";
	};
};
class RscText;
class RscPicture;
class RscActiveText;
class MGCrewMenu
{
	idd = 2020;
	movingEnable = 1;
	onload = "uinamespace setVariable ['MGCrewMenu', _this select 0]";
	class controlsBackground
	{
		class DLG_BACK1: RscText
		{
			style = 128;
			colorBackground[] = {0.1882,0.2588,0.149,0.76};
			text = "";
			colorText[] = {1,1,1,1};
			font = "Zeppelin32";
			sizeEx = 0.04;
			x = "0.344822 * safezoneW + safezoneX";
			y = "0.422687 * safezoneH + safezoneY";
			w = "0.417162 * safezoneW";
			h = "0.212739 * safezoneH";
		};
		class MGCrewMenuFrame: RscText
		{
			idc = -1;
			style = 64;
			font = "Zeppelin32";
			colorText[] = {0.937,0.937,0.937,0};
			colorBackground[] = {1,1,1,0};
			sizeEx = 0.03;
			text = "";
			x = "0.346252 * safezoneW + safezoneX";
			y = "0.42273 * safezoneH + safezoneY";
			w = "0.414518 * safezoneW";
			h = "0.20974 * safezoneH";
		};
		class LoadPicture: RscPicture
		{
			type = 0;
			idc = 1021;
			style = 48;
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			font = "Zeppelin32";
			sizeEx = 0.04;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_load.paa";
			x = "0.42121 * safezoneW + safezoneX";
			y = "0.431225 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0660243 * safezoneH";
		};
		class UnloadPicture: LoadPicture
		{
			idc = 1022;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_unload.paa";
			x = "0.42121 * safezoneW + safezoneX";
			y = "0.541265 * safezoneH + safezoneY";
		};
		class RotateLeftPicture: LoadPicture
		{
			idc = 1023;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_rotateleft.paa";
			x = "0.478512 * safezoneW + safezoneX";
			y = "0.541265 * safezoneH + safezoneY";
		};
		class RotateRightPicture: LoadPicture
		{
			idc = 1024;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_rotateright.paa";
			x = "0.478512 * safezoneW + safezoneX";
			y = "0.431225 * safezoneH + safezoneY";
		};
		class PitchUpPicture: LoadPicture
		{
			idc = 1031;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_pitchup.paa";
			x = "0.535814 * safezoneW + safezoneX";
			y = "0.431225 * safezoneH + safezoneY";
		};
		class PitchDnPicture: LoadPicture
		{
			idc = 1032;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_pitchdn.paa";
			x = "0.535814 * safezoneW + safezoneX";
			y = "0.541265 * safezoneH + safezoneY";
		};
		class UnmountPicture: LoadPicture
		{
			idc = 1025;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_unmount.paa";
			x = "0.591683 * safezoneW + safezoneX";
			y = "0.486234 * safezoneH + safezoneY";
		};
		class GetInPicture: LoadPicture
		{
			idc = 1028;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_getin.paa";
			x = "0.648985 * safezoneW + safezoneX";
			y = "0.486234 * safezoneH + safezoneY";
		};
		class CancelPicture: LoadPicture
		{
			idc = 1026;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_cancel.paa";
			x = "0.706288 * safezoneW + safezoneX";
			y = "0.486234 * safezoneH + safezoneY";
		};
		class ChangeBarrelPicture: LoadPicture
		{
			idc = 1030;
			text = "\x\ace\addons\sys_crewserved\data\dialog\icon_changebarrel.paa";
			x = "0.363907 * safezoneW + safezoneX";
			y = "0.486245 * safezoneH + safezoneY";
		};
	};
	class controls
	{
		class LoadActivetext: RscActiveText
		{
			type = 11;
			idc = 2021;
			style = 2;
			colorText[] = {1,1,1,0};
			font = "Zeppelin32";
			sizeEx = 0.13;
			text = "  ";
			colorActive[] = {0,1,0,0};
			action = "";
			default = 0;
			x = "0.42121 * safezoneW + safezoneX";
			y = "0.431225 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class UnloadActivetext: LoadActivetext
		{
			idc = 2022;
			x = "0.42121 * safezoneW + safezoneX";
			y = "0.541265 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class RotateLeftActivetext: LoadActivetext
		{
			idc = 2023;
			x = "0.478512 * safezoneW + safezoneX";
			y = "0.541265 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class RotateRightActivetext: LoadActivetext
		{
			idc = 2024;
			x = "0.478512 * safezoneW + safezoneX";
			y = "0.431225 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class PitchUpActivetext: LoadActivetext
		{
			idc = 2031;
			x = "0.533586 * safezoneW + safezoneX";
			y = "0.43754 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class PitchDnActivetext: LoadActivetext
		{
			idc = 2032;
			x = "0.534645 * safezoneW + safezoneX";
			y = "0.54647 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class UnmountActivetext: LoadActivetext
		{
			idc = 2025;
			x = "0.591154 * safezoneW + safezoneX";
			y = "0.488233 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class GetInActivetext: LoadActivetext
		{
			idc = 2028;
			x = "0.648985 * safezoneW + safezoneX";
			y = "0.486234 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class CancelActivetext: LoadActivetext
		{
			idc = 2026;
			action = "closeDialog 0";
			x = "0.706288 * safezoneW + safezoneX";
			y = "0.486234 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class ChangeBarrelActiveText: LoadActivetext
		{
			idc = 2030;
			x = "0.363002 * safezoneW + safezoneX";
			y = "0.487426 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0654741 * safezoneH";
		};
		class LoadText: RscText
		{
			idc = 3021;
			style = "2 + 256";
			colorText[] = {1,1,1,1};
			colorBackground[] = {0,0,0,0};
			font = "Zeppelin32";
			sizeEx = 0.02;
			text = "$STR_ACE_CREW_LOAD";
			x = "0.428372 * safezoneW + safezoneX";
			y = "0.5 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class UnloadText: LoadText
		{
			idc = 3022;
			text = "$STR_ACE_CREW_UNLOAD";
			x = "0.42121 * safezoneW + safezoneX";
			y = "0.61004 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class RotateLeftText: LoadText
		{
			idc = 3023;
			text = "$STR_ACE_CREW_LEFT";
			x = "0.478512 * safezoneW + safezoneX";
			y = "0.61004 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class RotateRightText: LoadText
		{
			idc = 3024;
			text = "$STR_ACE_CREW_RIGHT";
			x = "0.478512 * safezoneW + safezoneX";
			y = "0.5 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class PitchUpText: LoadText
		{
			idc = 3031;
			text = "$STR_ACE_CREW_PITCHUP";
			x = "0.535814 * safezoneW + safezoneX";
			y = "0.5 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class PitchDnText: LoadText
		{
			idc = 3032;
			text = "$STR_ACE_CREW_PITCHDN";
			x = "0.535814 * safezoneW + safezoneX";
			y = "0.61004 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class UnmountText: LoadText
		{
			idc = 3025;
			text = "$STR_ACE_CREW_UNMOUNT";
			x = "0.591683 * safezoneW + safezoneX";
			y = "0.55502 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class CancelText: LoadText
		{
			idc = 3026;
			text = "$STR_ACE_CREW_CANCEL";
			x = "0.706288 * safezoneW + safezoneX";
			y = "0.55502 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class GetInText: LoadText
		{
			idc = 3028;
			text = "$STR_AC_GETIN";
			x = "0.648985 * safezoneW + safezoneX";
			y = "0.55502 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
		class ChangeBarrelText: LoadText
		{
			idc = 3030;
			text = "$STR_ACE_SWAPBARRELACT";
			x = "0.356745 * safezoneW + safezoneX";
			y = "0.55502 * safezoneH + safezoneY";
			w = "0.0412575 * safezoneW";
			h = "0.0203795 * safezoneH";
		};
	};
};
//};
