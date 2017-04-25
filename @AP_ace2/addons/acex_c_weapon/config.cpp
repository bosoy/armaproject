////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed Feb 08 15:20:32 2012 : Created on Wed Feb 08 15:20:32 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_weapon : config.bin{
class CfgPatches
{
	class acex_c_weapon
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons2","CAWeapons_e","acex_main","acex_wep_launcher","acex_wep_mg","acex_wep_pistol","acex_wep_shotgun","acex_wep_smg_us","acex_wep_sniper","acex_wep_m16","ace_c_weapon"};
		version = "1.13.0.354";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_c_weapon
		{
			list[] = {"acex_c_weapon"};
		};
	};
};
class CfgVehicles
{
	class USBasicAmmunitionBox_EP1;
	class ACE_USBasicAmmunitionBox: USBasicAmmunitionBox_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M4A1
			{
				weapon = "M4A1";
				count = 4;
			};
			class _xx_M9
			{
				weapon = "M9";
				count = 4;
			};
			class _xx_glock17_EP1
			{
				weapon = "glock17_EP1";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 400;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
				count = 200;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 20;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 20;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 20;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 50;
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine = "200Rnd_556x45_M249";
				count = 50;
			};
			class _xx_ACE_200Rnd_556x45_T_M249
			{
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 50;
			};
			class _xx_30Rnd_9x19_MP5SD
			{
				magazine = "30Rnd_9x19_MP5SD";
				count = 30;
			};
			class _xx_30Rnd_9x19_MP5
			{
				magazine = "30Rnd_9x19_MP5";
				count = 90;
			};
			class _xx_1Rnd_HE_M203
			{
				magazine = "1Rnd_HE_M203";
				count = 80;
			};
			class _xx_FlareWhite_M203
			{
				magazine = "FlareWhite_M203";
				count = 80;
			};
			class _xx_FlareGreen_M203
			{
				magazine = "FlareGreen_M203";
				count = 80;
			};
			class _xx_FlareRed_M203
			{
				magazine = "FlareRed_M203";
				count = 80;
			};
			class _xx_FlareYellow_M203
			{
				magazine = "FlareYellow_M203";
				count = 80;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 30;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 30;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 50;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 30;
			};
			class _xx_ACE_10Rnd_127x99_T_m107
			{
				magazine = "ACE_10Rnd_127x99_T_m107";
				count = 30;
			};
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 30;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 30;
			};
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 30;
			};
			class _xx_HandGrenade_West
			{
				magazine = "HandGrenade_West";
				count = 50;
			};
			class _xx_SmokeShellRed
			{
				magazine = "SmokeShellRed";
				count = 20;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 20;
			};
			class _xx_SmokeShellYellow
			{
				magazine = "SmokeShellYellow";
				count = 20;
			};
			class _xx_SmokeShellBlue
			{
				magazine = "SmokeShellBlue";
				count = 20;
			};
			class _xx_SmokeShellPurple
			{
				magazine = "SmokeShellPurple";
				count = 20;
			};
			class _xx_SmokeShellOrange
			{
				magazine = "SmokeShellOrange";
				count = 20;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 20;
			};
			class _xx_1Rnd_SmokeRed_M203
			{
				magazine = "1Rnd_SmokeRed_M203";
				count = 20;
			};
			class _xx_1Rnd_SmokeGreen_M203
			{
				magazine = "1Rnd_SmokeGreen_M203";
				count = 20;
			};
			class _xx_1Rnd_SmokeYellow_M203
			{
				magazine = "1Rnd_SmokeYellow_M203";
				count = 20;
			};
			class _xx_1Rnd_Smoke_M203
			{
				magazine = "1Rnd_Smoke_M203";
				count = 20;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 30;
			};
		};
	};
	class USLaunchers_EP1;
	class ACE_USLaunchersBox: USLaunchers_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 15;
			};
			class _xx_Stinger
			{
				weapon = "Stinger";
				count = 4;
			};
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 4;
			};
			class _xx_ACE_Javelin_CLU
			{
				weapon = "ACE_Javelin_CLU";
				count = 1;
			};
			class _xx_ACE_M72
			{
				weapon = "ACE_M72";
				count = 6;
			};
		};
		class TransportMagazines
		{
			class _xx_Stinger
			{
				magazine = "Stinger";
				count = 4;
			};
		};
	};
	class USOrdnanceBox_EP1;
	class ACE_USOrdnanceBox: USOrdnanceBox_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_Mine
			{
				magazine = "Mine";
				count = 10;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 20;
			};
			class _xx_HandGrenade_West
			{
				magazine = "HandGrenade_West";
				count = 50;
			};
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 10;
			};
			class _xx_ACE_BBetty_M
			{
				magazine = "ACE_BBetty_M";
				count = 10;
			};
			class _xx_ACE_TripFlare_M
			{
				magazine = "ACE_TripFlare_M";
				count = 10;
			};
		};
	};
	class USBasicWeapons_EP1;
	class ACE_USBasicWeaponsBox: USBasicWeapons_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M4A1_Aim
			{
				weapon = "M4A1_Aim";
				count = 4;
			};
			class _xx_M4A1
			{
				weapon = "M4A1";
				count = 10;
			};
			class _xx_M4A1_RCO_GL
			{
				weapon = "M4A1_RCO_GL";
				count = 2;
			};
			class _xx_M16A2
			{
				weapon = "M16A2";
				count = 4;
			};
			class _xx_M16A2GL
			{
				weapon = "M16A2GL";
				count = 2;
			};
			class _xx_m16a4
			{
				weapon = "m16a4";
				count = 10;
			};
			class _xx_m16a4_acg
			{
				weapon = "m16a4_acg";
				count = 5;
			};
			class _xx_M16A4_GL
			{
				weapon = "M16A4_GL";
				count = 5;
			};
			class _xx_M16A4_ACG_GL
			{
				weapon = "M16A4_ACG_GL";
				count = 5;
			};
			class _xx_MP5A5
			{
				weapon = "MP5A5";
				count = 4;
			};
			class _xx_Colt1911
			{
				weapon = "Colt1911";
				count = 4;
			};
			class _xx_M9
			{
				weapon = "M9";
				count = 4;
			};
			class _xx_glock17_EP1
			{
				weapon = "glock17_EP1";
				count = 4;
			};
			class _xx_ACE_Glock18
			{
				weapon = "ACE_Glock18";
				count = 4;
			};
			class _xx_ACE_M16A4_Iron
			{
				weapon = "ACE_M16A4_Iron";
				count = 4;
			};
			class _xx_ACE_M4A1_GL
			{
				weapon = "ACE_M4A1_GL";
				count = 4;
			};
			class _xx_ACE_M4A1_GL_SD
			{
				weapon = "ACE_M4A1_GL_SD";
				count = 2;
			};
			class _xx_ACE_M4A1_AIM_GL
			{
				weapon = "ACE_M4A1_AIM_GL";
				count = 4;
			};
			class _xx_ACE_M4A1_AIM_GL_SD
			{
				weapon = "ACE_M4A1_AIM_GL_SD";
				count = 2;
			};
			class _xx_ACE_M4A1_ACOG
			{
				weapon = "ACE_M4A1_ACOG";
				count = 2;
			};
			class _xx_ACE_M4A1_ACOG_SD
			{
				weapon = "ACE_M4A1_ACOG_SD";
				count = 2;
			};
			class _xx_ACE_M4A1_Aim_SD
			{
				weapon = "ACE_M4A1_Aim_SD";
				count = 4;
			};
			class _xx_ACE_M4A1_Eotech
			{
				weapon = "ACE_M4A1_Eotech";
				count = 4;
			};
			class _xx_M4A1_HWS_GL
			{
				weapon = "M4A1_HWS_GL";
				count = 2;
			};
			class _xx_ACE_Flaregun
			{
				weapon = "ACE_Flaregun";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 400;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
				count = 200;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 20;
			};
			class _xx_30Rnd_9x19_MP5
			{
				magazine = "30Rnd_9x19_MP5";
				count = 90;
			};
			class _xx_1Rnd_HE_M203
			{
				magazine = "1Rnd_HE_M203";
				count = 80;
			};
			class _xx_FlareWhite_M203
			{
				magazine = "FlareWhite_M203";
				count = 80;
			};
			class _xx_FlareGreen_M203
			{
				magazine = "FlareGreen_M203";
				count = 80;
			};
			class _xx_FlareRed_M203
			{
				magazine = "FlareRed_M203";
				count = 80;
			};
			class _xx_FlareYellow_M203
			{
				magazine = "FlareYellow_M203";
				count = 80;
			};
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 30;
			};
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 30;
			};
			class _xx_1Rnd_SmokeRed_M203
			{
				magazine = "1Rnd_SmokeRed_M203";
				count = 20;
			};
			class _xx_1Rnd_SmokeGreen_M203
			{
				magazine = "1Rnd_SmokeGreen_M203";
				count = 20;
			};
			class _xx_1Rnd_SmokeYellow_M203
			{
				magazine = "1Rnd_SmokeYellow_M203";
				count = 20;
			};
			class _xx_1Rnd_Smoke_M203
			{
				magazine = "1Rnd_Smoke_M203";
				count = 20;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 30;
			};
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 30;
			};
		};
	};
	class USSpecialWeapons_EP1;
	class ACE_USSpecialWeaponsBox: USSpecialWeapons_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_Binocular
			{
				weapon = "Binocular";
				count = 5;
			};
			class _xx_NVGoggles
			{
				weapon = "NVGoggles";
				count = 10;
			};
			class _xx_Laserdesignator
			{
				weapon = "Laserdesignator";
				count = 2;
			};
			class _xx_ACE_Rangefinder_OD
			{
				weapon = "ACE_Rangefinder_OD";
				count = 1;
			};
			class _xx_ACE_KAC_PDW
			{
				weapon = "ACE_KAC_PDW";
				count = 5;
			};
			class _xx_ACE_HK417_Shortdot
			{
				weapon = "ACE_HK417_Shortdot";
				count = 3;
			};
			class _xx_m240_scoped_EP1
			{
				weapon = "m240_scoped_EP1";
				count = 4;
			};
			class _xx_M249_EP1
			{
				weapon = "M249_EP1";
				count = 4;
			};
			class _xx_Mk_48_DES_EP1
			{
				weapon = "Mk_48_DES_EP1";
				count = 2;
			};
			class _xx_m107
			{
				weapon = "m107";
				count = 2;
			};
			class _xx_m107_TWS_EP1
			{
				weapon = "m107_TWS_EP1";
				count = 2;
			};
			class _xx_ACE_HK417_leupold
			{
				weapon = "ACE_HK417_leupold";
				count = 3;
			};
			class _xx_M24_des_EP1
			{
				weapon = "M24_des_EP1";
				count = 2;
			};
			class _xx_ACE_HK417_micro
			{
				weapon = "ACE_HK417_micro";
				count = 5;
			};
			class _xx_ACE_M4SPR_SD
			{
				weapon = "ACE_M4SPR_SD";
				count = 5;
			};
			class _xx_ACE_SOC_M4A1_Aim
			{
				weapon = "ACE_SOC_M4A1_Aim";
				count = 2;
			};
			class _xx_ACE_SOC_M4A1_AIM_SD
			{
				weapon = "ACE_SOC_M4A1_AIM_SD";
				count = 2;
			};
			class _xx_ACE_SOC_M4A1_GL
			{
				weapon = "ACE_SOC_M4A1_GL";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1
			{
				weapon = "ACE_SOC_M4A1";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_SD
			{
				weapon = "ACE_SOC_M4A1_GL_SD";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_Eotech
			{
				weapon = "ACE_SOC_M4A1_Eotech";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_13
			{
				weapon = "ACE_SOC_M4A1_GL_13";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_EOTECH
			{
				weapon = "ACE_SOC_M4A1_GL_EOTECH";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_SD_9
			{
				weapon = "ACE_SOC_M4A1_SD_9";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_SHORTDOT
			{
				weapon = "ACE_SOC_M4A1_SHORTDOT";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_SHORTDOT_SD
			{
				weapon = "ACE_SOC_M4A1_SHORTDOT_SD";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_RCO_GL
			{
				weapon = "ACE_SOC_M4A1_RCO_GL";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_AIMPOINT
			{
				weapon = "ACE_SOC_M4A1_GL_AIMPOINT";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_Eotech_4x
			{
				weapon = "ACE_SOC_M4A1_Eotech_4x";
				count = 4;
			};
			class _xx_ACE_HK416_D10
			{
				weapon = "ACE_HK416_D10";
				count = 4;
			};
			class _xx_ACE_HK416_D10_SD
			{
				weapon = "ACE_HK416_D10_SD";
				count = 4;
			};
			class _xx_ACE_HK416_D14
			{
				weapon = "ACE_HK416_D14";
				count = 4;
			};
			class _xx_ACE_HK416_D14_SD
			{
				weapon = "ACE_HK416_D14_SD";
				count = 4;
			};
			class _xx_ACE_HK416_D10_AIM
			{
				weapon = "ACE_HK416_D10_AIM";
				count = 4;
			};
			class _xx_ACE_HK416_D10_M320
			{
				weapon = "ACE_HK416_D10_M320";
				count = 4;
			};
			class _xx_ACE_HK416_D10_COMPM3_SD
			{
				weapon = "ACE_HK416_D10_COMPM3_SD";
				count = 4;
			};
			class _xx_ACE_HK416_D10_COMPM3
			{
				weapon = "ACE_HK416_D10_COMPM3";
				count = 4;
			};
			class _xx_ACE_HK416_D14_COMPM3_M320
			{
				weapon = "ACE_HK416_D14_COMPM3_M320";
				count = 4;
			};
			class _xx_ACE_HK416_D14_COMPM3
			{
				weapon = "ACE_HK416_D14_COMPM3";
				count = 4;
			};
			class _xx_ACE_HK416_D14_ACOG_PVS14
			{
				weapon = "ACE_HK416_D14_ACOG_PVS14";
				count = 4;
			};
			class _xx_ACE_M27_IAR
			{
				weapon = "ACE_M27_IAR";
				count = 5;
			};
			class _xx_ACE_M27_IAR_ACOG
			{
				weapon = "ACE_M27_IAR_ACOG";
				count = 5;
			};
			class _xx_ACE_GlassesTactical
			{
				weapon = "ACE_GlassesTactical";
				count = 20;
			};
			class _xx_ACE_GlassesLHD_glasses
			{
				weapon = "ACE_GlassesLHD_glasses";
				count = 20;
			};
			class _xx_ACE_GlassesGasMask_US
			{
				weapon = "ACE_GlassesGasMask_US";
				count = 10;
			};
			class _xx_ACE_GlassesBalaklava
			{
				weapon = "ACE_GlassesBalaklava";
				count = 10;
			};
			class _xx_ACE_M109
			{
				weapon = "ACE_M109";
				count = 2;
			};
			class _xx_ACE_M110
			{
				weapon = "ACE_M110";
				count = 2;
			};
			class _xx_ACE_M110_SD
			{
				weapon = "ACE_M110_SD";
				count = 2;
			};
			class _xx_ACE_TAC50
			{
				weapon = "ACE_TAC50";
				count = 2;
			};
			class _xx_ACE_TAC50_SD
			{
				weapon = "ACE_TAC50_SD";
				count = 2;
			};
			class _xx_glock17_EP1
			{
				weapon = "glock17_EP1";
				count = 4;
			};
			class _xx_ACE_Glock18
			{
				weapon = "ACE_Glock18";
				count = 4;
			};
			class _xx_ACE_Flaregun
			{
				weapon = "ACE_Flaregun";
				count = 1;
			};
			class _xx_ACE_USP
			{
				weapon = "ACE_USP";
				count = 4;
			};
			class _xx_ACE_USPSD
			{
				weapon = "ACE_USPSD";
				count = 4;
			};
			class _xx_ACE_P226
			{
				weapon = "ACE_P226";
				count = 4;
			};
			class _xx_ACE_M60
			{
				weapon = "ACE_M60";
				count = 3;
			};
			class _xx_ACE_MP5A4
			{
				weapon = "ACE_MP5A4";
				count = 5;
			};
			class _xx_ACE_UMP45
			{
				weapon = "ACE_UMP45";
				count = 5;
			};
			class _xx_ACE_UMP45_SD
			{
				weapon = "ACE_UMP45_SD";
				count = 5;
			};
			class _xx_ACE_KeyCuffs
			{
				weapon = "ACE_KeyCuffs";
				count = 30;
			};
		};
		class TransportMagazines
		{
			class _xx_Laserbatteries
			{
				magazine = "Laserbatteries";
				count = 10;
			};
			class _xx_ACE_Battery_Rangefinder
			{
				magazine = "ACE_Battery_Rangefinder";
				count = 10;
			};
			class _xx_ACE_30Rnd_6x35_B_PDW
			{
				magazine = "ACE_30Rnd_6x35_B_PDW";
				count = 50;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 100;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
				count = 100;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 50;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 50;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 50;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 40;
			};
			class _xx_ACE_20Rnd_762x51_B_HK417
			{
				magazine = "ACE_20Rnd_762x51_B_HK417";
				count = 40;
			};
			class _xx_ACE_200Rnd_556x45_T_M249
			{
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 40;
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine = "200Rnd_556x45_M249";
				count = 40;
			};
			class _xx_30Rnd_9x19_MP5SD
			{
				magazine = "30Rnd_9x19_MP5SD";
				count = 50;
			};
			class _xx_30Rnd_9x19_MP5
			{
				magazine = "30Rnd_9x19_MP5";
				count = 50;
			};
			class _xx_1Rnd_HE_M203
			{
				magazine = "1Rnd_HE_M203";
				count = 80;
			};
			class _xx_FlareWhite_M203
			{
				magazine = "FlareWhite_M203";
				count = 80;
			};
			class _xx_FlareGreen_M203
			{
				magazine = "FlareGreen_M203";
				count = 80;
			};
			class _xx_FlareRed_M203
			{
				magazine = "FlareRed_M203";
				count = 80;
			};
			class _xx_FlareYellow_M203
			{
				magazine = "FlareYellow_M203";
				count = 80;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 30;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 30;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 30;
			};
			class _xx_ACE_10Rnd_127x99_T_m107
			{
				magazine = "ACE_10Rnd_127x99_T_m107";
				count = 30;
			};
			class _xx_ACE_10Rnd_127x99_Raufoss_m107
			{
				magazine = "ACE_10Rnd_127x99_Raufoss_m107";
				count = 10;
			};
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 30;
			};
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 30;
			};
			class _xx_1Rnd_SmokeRed_M203
			{
				magazine = "1Rnd_SmokeRed_M203";
				count = 20;
			};
			class _xx_1Rnd_SmokeGreen_M203
			{
				magazine = "1Rnd_SmokeGreen_M203";
				count = 20;
			};
			class _xx_1Rnd_SmokeYellow_M203
			{
				magazine = "1Rnd_SmokeYellow_M203";
				count = 20;
			};
			class _xx_1Rnd_Smoke_M203
			{
				magazine = "1Rnd_Smoke_M203";
				count = 20;
			};
			class _xx_ace_flashbang
			{
				magazine = "ace_flashbang";
				count = 10;
			};
			class _xx_ace_m84
			{
				magazine = "ace_m84";
				count = 10;
			};
			class _xx_ace_m7a3
			{
				magazine = "ace_m7a3";
				count = 10;
			};
			class _xx_ace_m34
			{
				magazine = "ace_m34";
				count = 10;
			};
			class _xx_ACE_IRStrobe
			{
				magazine = "ACE_IRStrobe";
				count = 10;
			};
			class _xx_ACE_M86PDM
			{
				magazine = "ACE_M86PDM";
				count = 10;
			};
			class _xx_ACE_5Rnd_25x59_HEDP_Barrett
			{
				magazine = "ACE_5Rnd_25x59_HEDP_Barrett";
				count = 10;
			};
			class _xx_ACE_5Rnd_127x99_B_TAC50
			{
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 10;
			};
			class _xx_ACE_5Rnd_127x99_T_TAC50
			{
				magazine = "ACE_5Rnd_127x99_T_TAC50";
				count = 15;
			};
			class _xx_ACE_25Rnd_1143x23_B_UMP45
			{
				magazine = "ACE_25Rnd_1143x23_B_UMP45";
				count = 20;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 30;
			};
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 30;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 20;
			};
			class _xx_ACE_12Rnd_45ACP_usp
			{
				magazine = "ACE_12Rnd_45ACP_usp";
				count = 20;
			};
		};
	};
	class USVehicleBox_EP1;
	class ACE_USVehicleBox: USVehicleBox_EP1
	{
		scope = 1;
	};
	class TKBasicAmmunitionBox_EP1;
	class ACE_RUBasicAmmunitionBox: TKBasicAmmunitionBox_EP1
	{
		vehicleClass = "ACE_Ammunition";
		scope = 1;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_RDG2
			{
				magazine = "ACE_RDG2";
				count = 100;
			};
			class _xx_ACE_RDGM
			{
				magazine = "ACE_RDGM";
				count = 20;
			};
		};
	};
	class TKLaunchers_EP1;
	class ACE_RULaunchersBox: TKLaunchers_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
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
			class _xx_ACE_RPG7V_PGO7
			{
				weapon = "ACE_RPG7V_PGO7";
				count = 4;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 8;
			};
			class _xx_ACE_RPG29_TBG29
			{
				magazine = "ACE_RPG29_TBG29";
				count = 8;
			};
			class _xx_ACE_PG7V_PGO7
			{
				magazine = "ACE_PG7V_PGO7";
				count = 8;
			};
			class _xx_ACE_PG7VL_PGO7
			{
				magazine = "ACE_PG7VL_PGO7";
				count = 8;
			};
			class _xx_ACE_PG7VR_PGO7
			{
				magazine = "ACE_PG7VR_PGO7";
				count = 8;
			};
			class _xx_ACE_OG7_PGO7
			{
				magazine = "ACE_OG7_PGO7";
				count = 8;
			};
		};
	};
	class TKOrdnanceBox_EP1;
	class ACE_RUOrdnanceBox: TKOrdnanceBox_EP1
	{
		vehicleClass = "ACE_Ammunition";
		scope = 1;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Pomz_M
			{
				magazine = "ACE_Pomz_M";
				count = 20;
			};
		};
	};
	class TKBasicWeapons_EP1;
	class ACE_RUBasicWeaponsBox: TKBasicWeapons_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		displayName = "RU Small Arms Crate";
		class TransportWeapons
		{
			class _xx_ACE_SKS
			{
				weapon = "ACE_SKS";
				count = 10;
			};
			class _xx_ACE_TT
			{
				weapon = "ACE_TT";
				count = 4;
			};
			class _xx_ACE_AK74M
			{
				weapon = "ACE_AK74M";
				count = 20;
			};
			class _xx_ACE_AK74M_Kobra
			{
				weapon = "ACE_AK74M_Kobra";
				count = 20;
			};
			class _xx_ACE_AK74M_1P29
			{
				weapon = "ACE_AK74M_1P29";
				count = 20;
			};
			class _xx_ACE_AK74M_PSO
			{
				weapon = "ACE_AK74M_PSO";
				count = 20;
			};
			class _xx_ACE_AK74M_GL
			{
				weapon = "ACE_AK74M_GL";
				count = 20;
			};
			class _xx_ACE_AK74M_GL_Kobra
			{
				weapon = "ACE_AK74M_GL_Kobra";
				count = 20;
			};
			class _xx_ACE_AK74M_GL_1P29
			{
				weapon = "ACE_AK74M_GL_1P29";
				count = 20;
			};
			class _xx_ACE_AK74M_GL_PSO
			{
				weapon = "ACE_AK74M_GL_PSO";
				count = 20;
			};
			class _xx_ACE_AKS74P
			{
				weapon = "ACE_AKS74P";
				count = 20;
			};
			class _xx_ACE_AKS74P_Kobra
			{
				weapon = "ACE_AKS74P_Kobra";
				count = 20;
			};
			class _xx_ACE_AKS74P_1P29
			{
				weapon = "ACE_AKS74P_1P29";
				count = 20;
			};
			class _xx_ACE_AKS74P_PSO
			{
				weapon = "ACE_AKS74P_PSO";
				count = 20;
			};
			class _xx_ACE_AKS74P_GL
			{
				weapon = "ACE_AKS74P_GL";
				count = 20;
			};
			class _xx_ACE_AKS74P_GL_Kobra
			{
				weapon = "ACE_AKS74P_GL_Kobra";
				count = 20;
			};
			class _xx_ACE_AKS74P_GL_1P29
			{
				weapon = "ACE_AKS74P_GL_1P29";
				count = 20;
			};
			class _xx_ACE_AKS74P_GL_PSO
			{
				weapon = "ACE_AKS74P_GL_PSO";
				count = 20;
			};
			class _xx_ACE_AK105
			{
				weapon = "ACE_AK105";
				count = 20;
			};
			class _xx_ACE_AK105_Kobra
			{
				weapon = "ACE_AK105_Kobra";
				count = 20;
			};
			class _xx_ACE_AK105_1P29
			{
				weapon = "ACE_AK105_1P29";
				count = 20;
			};
			class _xx_ACE_AK105_PSO
			{
				weapon = "ACE_AK105_PSO";
				count = 20;
			};
			class _xx_ACE_AK103
			{
				weapon = "ACE_AK103";
				count = 20;
			};
			class _xx_ACE_AK103_Kobra
			{
				weapon = "ACE_AK103_Kobra";
				count = 20;
			};
			class _xx_ACE_AK103_1P29
			{
				weapon = "ACE_AK103_1P29";
				count = 20;
			};
			class _xx_ACE_AK103_PSO
			{
				weapon = "ACE_AK103_PSO";
				count = 20;
			};
			class _xx_ACE_AK103_GL
			{
				weapon = "ACE_AK103_GL";
				count = 20;
			};
			class _xx_ACE_AK103_GL_Kobra
			{
				weapon = "ACE_AK103_GL_Kobra";
				count = 20;
			};
			class _xx_ACE_AK103_GL_1P29
			{
				weapon = "ACE_AK103_GL_1P29";
				count = 20;
			};
			class _xx_ACE_AK103_GL_PSO
			{
				weapon = "ACE_AK103_GL_PSO";
				count = 20;
			};
			class _xx_ACE_AK104
			{
				weapon = "ACE_AK104";
				count = 20;
			};
			class _xx_ACE_AK104_Kobra
			{
				weapon = "ACE_AK104_Kobra";
				count = 20;
			};
			class _xx_ACE_AK104_1P29
			{
				weapon = "ACE_AK104_1P29";
				count = 20;
			};
			class _xx_ACE_AK104_PSO
			{
				weapon = "ACE_AK104_PSO";
				count = 20;
			};
			class _xx_ACE_RPK74M
			{
				weapon = "ACE_RPK74M";
				count = 20;
			};
			class _xx_ACE_RPK74M_1P29
			{
				weapon = "ACE_RPK74M_1P29";
				count = 20;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_8Rnd_762x25_B_Tokarev
			{
				magazine = "ACE_8Rnd_762x25_B_Tokarev";
				count = 8;
			};
			class _xx_ACE_10Rnd_762x39_B_SKS
			{
				magazine = "ACE_10Rnd_762x39_B_SKS";
				count = 30;
			};
			class _xx_30Rnd_545x39_AK
			{
				magazine = "30Rnd_545x39_AK";
				count = 80;
			};
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 80;
			};
			class _xx_ACE_45Rnd_545x39_B_AK
			{
				magazine = "ACE_45Rnd_545x39_B_AK";
				count = 40;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 80;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 80;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 80;
			};
		};
	};
	class TKSpecialWeapons_EP1;
	class ACE_RUSpecialWeaponsBox: TKSpecialWeapons_EP1
	{
		vehicleClass = "ACE_Ammunition";
		scope = 1;
		displayName = "RU Special Small Arms Crate";
		class TransportWeapons
		{
			class _xx_ACE_GlassesGasMask_RU
			{
				weapon = "ACE_GlassesGasMask_RU";
				count = 10;
			};
			class _xx_ACE_GlassesBalaklava
			{
				weapon = "ACE_GlassesBalaklava";
				count = 10;
			};
			class _xx_ACE_OC14
			{
				weapon = "ACE_OC14";
				count = 10;
			};
			class _xx_ACE_oc14sp
			{
				weapon = "ACE_oc14sp";
				count = 10;
			};
			class _xx_ACE_oc14gl
			{
				weapon = "ACE_oc14gl";
				count = 10;
			};
			class _xx_ACE_oc14glsp
			{
				weapon = "ACE_oc14glsp";
				count = 10;
			};
			class _xx_ACE_oc14sd
			{
				weapon = "ACE_oc14sd";
				count = 10;
			};
			class _xx_ACE_oc14sdsp
			{
				weapon = "ACE_oc14sdsp";
				count = 10;
			};
			class _xx_ACE_gr1
			{
				weapon = "ACE_gr1";
				count = 10;
			};
			class _xx_ACE_gr1sp
			{
				weapon = "ACE_gr1sp";
				count = 10;
			};
			class _xx_ACE_gr1sd
			{
				weapon = "ACE_gr1sd";
				count = 10;
			};
			class _xx_ACE_gr1sdsp
			{
				weapon = "ACE_gr1sdsp";
				count = 10;
			};
			class _xx_KSVK
			{
				weapon = "KSVK";
				count = 10;
			};
			class _xx_RPK_74
			{
				weapon = "RPK_74";
				count = 10;
			};
			class _xx_PK
			{
				weapon = "PK";
				count = 10;
			};
			class _xx_Pecheneg
			{
				weapon = "Pecheneg";
				count = 10;
			};
			class _xx_MakarovSD
			{
				weapon = "MakarovSD";
				count = 10;
			};
			class _xx_ACE_KeyCuffs
			{
				weapon = "ACE_KeyCuffs";
				count = 30;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_30Rnd_545x39_T_AK
			{
				magazine = "ACE_30Rnd_545x39_T_AK";
				count = 80;
			};
			class _xx_ACE_20Rnd_9x39_B_OC14
			{
				magazine = "ACE_20Rnd_9x39_B_OC14";
				count = 80;
			};
			class _xx_30Rnd_762x39_AK47
			{
				magazine = "30Rnd_762x39_AK47";
				count = 80;
			};
			class _xx_ACE_30Rnd_762x39_T_AK47
			{
				magazine = "ACE_30Rnd_762x39_T_AK47";
				count = 80;
			};
			class _xx_75Rnd_545x39_RPK
			{
				magazine = "75Rnd_545x39_RPK";
				count = 80;
			};
			class _xx_ACE_75Rnd_545x39_T_RPK
			{
				magazine = "ACE_75Rnd_545x39_T_RPK";
				count = 80;
			};
			class _xx_100Rnd_762x54_PK
			{
				magazine = "100Rnd_762x54_PK";
				count = 80;
			};
			class _xx_ACE_10Rnd_762x54_T_SVD
			{
				magazine = "ACE_10Rnd_762x54_T_SVD";
				count = 80;
			};
			class _xx_5Rnd_127x108_KSVK
			{
				magazine = "5Rnd_127x108_KSVK";
				count = 80;
			};
			class _xx_ACE_5Rnd_127x108_T_KSVK
			{
				magazine = "ACE_5Rnd_127x108_T_KSVK";
				count = 80;
			};
			class _xx_8Rnd_9x18_Makarov
			{
				magazine = "8Rnd_9x18_Makarov";
				count = 80;
			};
			class _xx_1Rnd_HE_GP25
			{
				magazine = "1Rnd_HE_GP25";
				count = 80;
			};
			class _xx_ACE_1Rnd_CS_GP25
			{
				magazine = "ACE_1Rnd_CS_GP25";
				count = 80;
			};
			class _xx_HandGrenade
			{
				magazine = "HandGrenade";
				count = 50;
			};
			class _xx_HandGrenade_East
			{
				magazine = "HandGrenade_East";
				count = 50;
			};
			class _xx_ACE_RDG2
			{
				magazine = "ACE_RDG2";
				count = 100;
			};
			class _xx_ACE_RDGM
			{
				magazine = "ACE_RDGM";
				count = 20;
			};
			class _xx_ACE_RG60A
			{
				magazine = "ACE_RG60A";
				count = 10;
			};
			class _xx_ACE_TORCH_C
			{
				magazine = "ACE_TORCH_C";
				count = 10;
			};
		};
	};
	class TKVehicleBox_EP1;
	class ACE_RUVehicleBox: TKVehicleBox_EP1
	{
		vehicleClass = "ACE_Ammunition";
		scope = 1;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class UNBasicAmmunitionBox_EP1;
	class ACE_LocalBasicAmmunitionBox: UNBasicAmmunitionBox_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		displayName = "Local Ammunition Crate";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_10Rnd_762x39_B_SKS
			{
				magazine = "ACE_10Rnd_762x39_B_SKS";
				count = 30;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 20;
			};
		};
	};
	class UNBasicWeapons_EP1;
	class ACE_LocalBasicWeaponsBox: UNBasicWeapons_EP1
	{
		scope = 1;
		vehicleClass = "ACE_Ammunition";
		displayName = "Local Weapon Crate";
		class TransportWeapons
		{
			class _xx_ACE_M3A1
			{
				weapon = "ACE_M3A1";
				count = 10;
			};
			class _xx_ACE_SKS
			{
				weapon = "ACE_SKS";
				count = 10;
			};
			class _xx_ACE_G3A3
			{
				weapon = "ACE_G3A3";
				count = 4;
			};
			class _xx_ACE_G3SG1
			{
				weapon = "ACE_G3SG1";
				count = 1;
			};
			class _xx_ACE_SPAS12
			{
				weapon = "ACE_SPAS12";
				count = 5;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
				count = 3;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_30Rnd_1143x23_B_M3
			{
				magazine = "ACE_30Rnd_1143x23_B_M3";
				count = 30;
			};
			class _xx_ACE_10Rnd_762x39_B_SKS
			{
				magazine = "ACE_10Rnd_762x39_B_SKS";
				count = 30;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 20;
			};
			class _xx_ACE_8Rnd_12Ga_Slug
			{
				magazine = "ACE_8Rnd_12Ga_Slug";
				count = 20;
			};
			class _xx_ACE_8Rnd_12Ga_Buck00
			{
				magazine = "ACE_8Rnd_12Ga_Buck00";
				count = 20;
			};
		};
	};
	class GuerillaCacheBox_EP1;
	class ACE_GuerillaCacheBox: GuerillaCacheBox_EP1
	{
		vehicleClass = "ACE_Ammunition";
		scope = 1;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class ACE_SpecialWeaponsBox: USSpecialWeapons_EP1
	{
		vehicleClass = "ACE_Ammunition";
		scope = 1;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class ACE_WeaponBox_Default: USBasicWeapons_EP1
	{
		displayName = "Other Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
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
		};
		class TransportMagazines
		{
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
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
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
	class ACE_MagazineBox_Default: USBasicAmmunitionBox_EP1
	{
		displayName = "Other Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
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
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
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
	class ACE_OrdnanceBox_Default: USBasicWeapons_EP1
	{
		displayName = "Other Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
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
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
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
	class ACE_WeaponBox_Launchers_Default: USBasicWeapons_EP1
	{
		displayName = "Other Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
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
		class TransportMagazines{};
	};
	class ACE_WeaponBox_BIS_US: USBasicWeapons_EP1
	{
		displayName = "US Army Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M9
			{
				weapon = "M9";
				count = 4;
			};
			class _xx_M9SD
			{
				weapon = "M9SD";
				count = 4;
			};
			class _xx_M16A2
			{
				weapon = "M16A2";
				count = 4;
			};
			class _xx_M16A2GL
			{
				weapon = "M16A2GL";
				count = 4;
			};
			class _xx_M4A1
			{
				weapon = "M4A1";
				count = 4;
			};
			class _xx_Colt1911
			{
				weapon = "Colt1911";
				count = 4;
			};
			class _xx_m107
			{
				weapon = "m107";
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
			class _xx_ACE_UMP45
			{
				weapon = "ACE_UMP45";
				count = 4;
			};
			class _xx_ACE_UMP45_SD
			{
				weapon = "ACE_UMP45_SD";
				count = 4;
			};
			class _xx_ACE_KAC_PDW
			{
				weapon = "ACE_KAC_PDW";
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
			class _xx_glock17_EP1
			{
				weapon = "glock17_EP1";
				count = 4;
			};
			class _xx_M60A4_EP1
			{
				weapon = "M60A4_EP1";
				count = 4;
			};
			class _xx_Mk_48_DES_EP1
			{
				weapon = "Mk_48_DES_EP1";
				count = 4;
			};
			class _xx_M249_EP1
			{
				weapon = "M249_EP1";
				count = 4;
			};
			class _xx_M249_TWS_EP1
			{
				weapon = "M249_TWS_EP1";
				count = 4;
			};
			class _xx_M249_m145_EP1
			{
				weapon = "M249_m145_EP1";
				count = 4;
			};
			class _xx_ACE_M249_AIM
			{
				weapon = "ACE_M249_AIM";
				count = 4;
			};
			class _xx_ACE_M249_PIP_ACOG
			{
				weapon = "ACE_M249_PIP_ACOG";
				count = 4;
			};
			class _xx_ACE_M240B
			{
				weapon = "ACE_M240B";
				count = 4;
			};
			class _xx_ACE_M240L
			{
				weapon = "ACE_M240L";
				count = 4;
			};
			class _xx_ACE_M240L_M145
			{
				weapon = "ACE_M240L_M145";
				count = 4;
			};
			class _xx_M24_des_EP1
			{
				weapon = "M24_des_EP1";
				count = 4;
			};
			class _xx_M4A3_CCO_EP1
			{
				weapon = "M4A3_CCO_EP1";
				count = 4;
			};
			class _xx_M4A3_RCO_GL_EP1
			{
				weapon = "M4A3_RCO_GL_EP1";
				count = 4;
			};
			class _xx_G36C_camo
			{
				weapon = "G36C_camo";
				count = 4;
			};
			class _xx_G36_C_SD_camo
			{
				weapon = "G36_C_SD_camo";
				count = 4;
			};
			class _xx_G36A_camo
			{
				weapon = "G36A_camo";
				count = 4;
			};
			class _xx_G36K_camo
			{
				weapon = "G36K_camo";
				count = 4;
			};
			class _xx_MG36_camo
			{
				weapon = "MG36_camo";
				count = 4;
			};
			class _xx_M32_EP1
			{
				weapon = "M32_EP1";
				count = 4;
			};
			class _xx_Mk13_EP1
			{
				weapon = "Mk13_EP1";
				count = 4;
			};
			class _xx_m107_TWS_EP1
			{
				weapon = "m107_TWS_EP1";
				count = 4;
			};
			class _xx_M110_TWS_EP1
			{
				weapon = "M110_TWS_EP1";
				count = 4;
			};
			class _xx_M110_NVG_EP1
			{
				weapon = "M110_NVG_EP1";
				count = 4;
			};
			class _xx_M14_EP1
			{
				weapon = "M14_EP1";
				count = 4;
			};
			class _xx_ACE_M14_ACOG
			{
				weapon = "ACE_M14_ACOG";
				count = 4;
			};
			class _xx_m240_scoped_EP1
			{
				weapon = "m240_scoped_EP1";
				count = 4;
			};
			class _xx_SCAR_L_CQC
			{
				weapon = "SCAR_L_CQC";
				count = 4;
			};
			class _xx_SCAR_L_CQC_Holo
			{
				weapon = "SCAR_L_CQC_Holo";
				count = 4;
			};
			class _xx_SCAR_L_STD_Mk4CQT
			{
				weapon = "SCAR_L_STD_Mk4CQT";
				count = 4;
			};
			class _xx_SCAR_L_STD_EGLM_RCO
			{
				weapon = "SCAR_L_STD_EGLM_RCO";
				count = 4;
			};
			class _xx_SCAR_L_CQC_EGLM_Holo
			{
				weapon = "SCAR_L_CQC_EGLM_Holo";
				count = 4;
			};
			class _xx_SCAR_L_STD_EGLM_TWS
			{
				weapon = "SCAR_L_STD_EGLM_TWS";
				count = 4;
			};
			class _xx_SCAR_L_STD_HOLO
			{
				weapon = "SCAR_L_STD_HOLO";
				count = 4;
			};
			class _xx_SCAR_L_CQC_CCO_SD
			{
				weapon = "SCAR_L_CQC_CCO_SD";
				count = 4;
			};
			class _xx_SCAR_H_CQC_CCO
			{
				weapon = "SCAR_H_CQC_CCO";
				count = 4;
			};
			class _xx_SCAR_H_CQC_CCO_SD
			{
				weapon = "SCAR_H_CQC_CCO_SD";
				count = 4;
			};
			class _xx_SCAR_H_STD_EGLM_Spect
			{
				weapon = "SCAR_H_STD_EGLM_Spect";
				count = 4;
			};
			class _xx_SCAR_H_LNG_Sniper
			{
				weapon = "SCAR_H_LNG_Sniper";
				count = 4;
			};
			class _xx_SCAR_H_LNG_Sniper_SD
			{
				weapon = "SCAR_H_LNG_Sniper_SD";
				count = 4;
			};
			class _xx_SCAR_H_STD_TWS_SD
			{
				weapon = "SCAR_H_STD_TWS_SD";
				count = 4;
			};
			class _xx_m8_carbine_pmc
			{
				weapon = "m8_carbine_pmc";
				count = 4;
			};
			class _xx_m8_compact_pmc
			{
				weapon = "m8_compact_pmc";
				count = 4;
			};
			class _xx_m8_holo_sd
			{
				weapon = "m8_holo_sd";
				count = 4;
			};
			class _xx_m8_tws_sd
			{
				weapon = "m8_tws_sd";
				count = 4;
			};
			class _xx_m8_tws
			{
				weapon = "m8_tws";
				count = 4;
			};
			class _xx_ACE_BAF_L7A2_GPMG
			{
				weapon = "ACE_BAF_L7A2_GPMG";
				count = 4;
			};
			class _xx_ACE_Glock18
			{
				weapon = "ACE_Glock18";
				count = 4;
			};
			class _xx_ACE_USP
			{
				weapon = "ACE_USP";
				count = 4;
			};
			class _xx_ACE_USPSD
			{
				weapon = "ACE_USPSD";
				count = 4;
			};
			class _xx_ACE_P8
			{
				weapon = "ACE_P8";
				count = 4;
			};
			class _xx_ACE_P226
			{
				weapon = "ACE_P226";
				count = 4;
			};
			class _xx_ACE_SPAS12
			{
				weapon = "ACE_SPAS12";
				count = 4;
			};
			class _xx_ACE_M1014_Eotech
			{
				weapon = "ACE_M1014_Eotech";
				count = 4;
			};
			class _xx_ACE_G36A2
			{
				weapon = "ACE_G36A2";
				count = 4;
			};
			class _xx_ACE_G36A2_D
			{
				weapon = "ACE_G36A2_D";
				count = 4;
			};
			class _xx_ACE_G36A2_Bipod
			{
				weapon = "ACE_G36A2_Bipod";
				count = 4;
			};
			class _xx_ACE_G36A2_Bipod_D
			{
				weapon = "ACE_G36A2_Bipod_D";
				count = 4;
			};
			class _xx_ACE_G36K_iron
			{
				weapon = "ACE_G36K_iron";
				count = 4;
			};
			class _xx_ACE_G36K_iron_D
			{
				weapon = "ACE_G36K_iron_D";
				count = 4;
			};
			class _xx_ACE_G36K_EOTech
			{
				weapon = "ACE_G36K_EOTech";
				count = 4;
			};
			class _xx_ACE_G36K_EOTech_D
			{
				weapon = "ACE_G36K_EOTech_D";
				count = 4;
			};
			class _xx_ACE_G36A1_AG36A1
			{
				weapon = "ACE_G36A1_AG36A1";
				count = 4;
			};
			class _xx_ACE_G36A1_AG36A1_D
			{
				weapon = "ACE_G36A1_AG36A1_D";
				count = 4;
			};
			class _xx_ACE_HK416_D10
			{
				weapon = "ACE_HK416_D10";
				count = 4;
			};
			class _xx_ACE_HK416_D10_AIM
			{
				weapon = "ACE_HK416_D10_AIM";
				count = 4;
			};
			class _xx_ACE_HK416_D10_COMPM3
			{
				weapon = "ACE_HK416_D10_COMPM3";
				count = 4;
			};
			class _xx_ACE_HK416_D10_Holo
			{
				weapon = "ACE_HK416_D10_Holo";
				count = 4;
			};
			class _xx_ACE_HK416_D10_M320
			{
				weapon = "ACE_HK416_D10_M320";
				count = 4;
			};
			class _xx_ACE_HK416_D14
			{
				weapon = "ACE_HK416_D14";
				count = 4;
			};
			class _xx_ACE_HK416_D14_COMPM3
			{
				weapon = "ACE_HK416_D14_COMPM3";
				count = 4;
			};
			class _xx_ACE_HK416_D14_COMPM3_M320
			{
				weapon = "ACE_HK416_D14_COMPM3_M320";
				count = 4;
			};
			class _xx_ACE_HK416_D14_ACOG_PVS14
			{
				weapon = "ACE_HK416_D14_ACOG_PVS14";
				count = 4;
			};
			class _xx_ACE_HK416_D14_TWS
			{
				weapon = "ACE_HK416_D14_TWS";
				count = 4;
			};
			class _xx_ACE_M27_IAR
			{
				weapon = "ACE_M27_IAR";
				count = 4;
			};
			class _xx_ACE_M27_IAR_ACOG
			{
				weapon = "ACE_M27_IAR_ACOG";
				count = 4;
			};
			class _xx_ACE_HK416_D10_SD
			{
				weapon = "ACE_HK416_D10_SD";
				count = 4;
			};
			class _xx_ACE_HK416_D10_COMPM3_SD
			{
				weapon = "ACE_HK416_D10_COMPM3_SD";
				count = 4;
			};
			class _xx_ACE_HK416_D14_SD
			{
				weapon = "ACE_HK416_D14_SD";
				count = 4;
			};
			class _xx_ACE_HK417_Shortdot
			{
				weapon = "ACE_HK417_Shortdot";
				count = 4;
			};
			class _xx_ACE_HK417_leupold
			{
				weapon = "ACE_HK417_leupold";
				count = 4;
			};
			class _xx_ACE_HK417_micro
			{
				weapon = "ACE_HK417_micro";
				count = 4;
			};
			class _xx_ACE_HK417_Eotech_4x
			{
				weapon = "ACE_HK417_Eotech_4x";
				count = 4;
			};
			class _xx_ACE_m16a2_scope
			{
				weapon = "ACE_m16a2_scope";
				count = 4;
			};
			class _xx_ACE_m16a2gl_scope
			{
				weapon = "ACE_m16a2gl_scope";
				count = 4;
			};
			class _xx_ACE_M16A4_Iron
			{
				weapon = "ACE_M16A4_Iron";
				count = 4;
			};
			class _xx_ACE_M16A4_CCO_GL
			{
				weapon = "ACE_M16A4_CCO_GL";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1
			{
				weapon = "ACE_SOC_M4A1";
				count = 4;
			};
			class _xx_ACE_M4A1_GL
			{
				weapon = "ACE_M4A1_GL";
				count = 4;
			};
			class _xx_ACE_M4A1_AIM_GL
			{
				weapon = "ACE_M4A1_AIM_GL";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL
			{
				weapon = "ACE_SOC_M4A1_GL";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_13
			{
				weapon = "ACE_SOC_M4A1_GL_13";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_EOTECH
			{
				weapon = "ACE_SOC_M4A1_GL_EOTECH";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_AIMPOINT
			{
				weapon = "ACE_SOC_M4A1_GL_AIMPOINT";
				count = 4;
			};
			class _xx_ACE_M4A1_ACOG
			{
				weapon = "ACE_M4A1_ACOG";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_SHORTDOT
			{
				weapon = "ACE_SOC_M4A1_SHORTDOT";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_TWS
			{
				weapon = "ACE_SOC_M4A1_TWS";
				count = 4;
			};
			class _xx_ACE_M4A1_Eotech
			{
				weapon = "ACE_M4A1_Eotech";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_Eotech
			{
				weapon = "ACE_SOC_M4A1_Eotech";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_Eotech_4x
			{
				weapon = "ACE_SOC_M4A1_Eotech_4x";
				count = 4;
			};
			class _xx_ACE_M4A1_RCO2_GL
			{
				weapon = "ACE_M4A1_RCO2_GL";
				count = 4;
			};
			class _xx_ACE_M4A1_RCO_GL
			{
				weapon = "ACE_M4A1_RCO_GL";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_RCO_GL
			{
				weapon = "ACE_SOC_M4A1_RCO_GL";
				count = 4;
			};
			class _xx_ACE_M4A1_GL_SD
			{
				weapon = "ACE_M4A1_GL_SD";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_GL_SD
			{
				weapon = "ACE_SOC_M4A1_GL_SD";
				count = 4;
			};
			class _xx_ACE_M4A1_AIM_GL_SD
			{
				weapon = "ACE_M4A1_AIM_GL_SD";
				count = 4;
			};
			class _xx_ACE_M4A1_ACOG_SD
			{
				weapon = "ACE_M4A1_ACOG_SD";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_SHORTDOT_SD
			{
				weapon = "ACE_SOC_M4A1_SHORTDOT_SD";
				count = 4;
			};
			class _xx_ACE_M4A1_Aim_SD
			{
				weapon = "ACE_M4A1_Aim_SD";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_SD_9
			{
				weapon = "ACE_SOC_M4A1_SD_9";
				count = 4;
			};
			class _xx_ACE_Mk12mod1
			{
				weapon = "ACE_Mk12mod1";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_Aim
			{
				weapon = "ACE_SOC_M4A1_Aim";
				count = 4;
			};
			class _xx_ACE_SOC_M4A1_AIM_SD
			{
				weapon = "ACE_SOC_M4A1_AIM_SD";
				count = 4;
			};
			class _xx_ACE_M4
			{
				weapon = "ACE_M4";
				count = 4;
			};
			class _xx_ACE_M4_Aim
			{
				weapon = "ACE_M4_Aim";
				count = 4;
			};
			class _xx_ACE_M4_Eotech
			{
				weapon = "ACE_M4_Eotech";
				count = 4;
			};
			class _xx_ACE_M4_ACOG
			{
				weapon = "ACE_M4_ACOG";
				count = 4;
			};
			class _xx_ACE_M4_GL
			{
				weapon = "ACE_M4_GL";
				count = 4;
			};
			class _xx_ACE_M4_AIM_GL
			{
				weapon = "ACE_M4_AIM_GL";
				count = 4;
			};
			class _xx_ACE_M4_RCO_GL
			{
				weapon = "ACE_M4_RCO_GL";
				count = 4;
			};
			class _xx_ACE_G3A3
			{
				weapon = "ACE_G3A3";
				count = 4;
			};
			class _xx_ACE_G3A3_RSAS
			{
				weapon = "ACE_G3A3_RSAS";
				count = 4;
			};
			class _xx_ACE_G3SG1
			{
				weapon = "ACE_G3SG1";
				count = 4;
			};
			class _xx_ACE_SCAR_H_STD_Spect
			{
				weapon = "ACE_SCAR_H_STD_Spect";
				count = 4;
			};
			class _xx_ACE_M4SPR_SD
			{
				weapon = "ACE_M4SPR_SD";
				count = 4;
			};
			class _xx_ACE_Mk12mod1_SD
			{
				weapon = "ACE_Mk12mod1_SD";
				count = 4;
			};
			class _xx_ACE_M110
			{
				weapon = "ACE_M110";
				count = 4;
			};
			class _xx_ACE_M110_SD
			{
				weapon = "ACE_M110_SD";
				count = 4;
			};
			class _xx_ACE_M109
			{
				weapon = "ACE_M109";
				count = 4;
			};
			class _xx_ACE_TAC50
			{
				weapon = "ACE_TAC50";
				count = 4;
			};
			class _xx_ACE_TAC50_SD
			{
				weapon = "ACE_TAC50_SD";
				count = 4;
			};
			class _xx_ACE_AS50
			{
				weapon = "ACE_AS50";
				count = 4;
			};
			class _xx_ACE_M2HBProxy
			{
				weapon = "ACE_M2HBProxy";
				count = 4;
			};
			class _xx_ACE_MK19MOD3Proxy
			{
				weapon = "ACE_MK19MOD3Proxy";
				count = 4;
			};
			class _xx_ACE_M252Proxy
			{
				weapon = "ACE_M252Proxy";
				count = 4;
			};
			class _xx_ACE_M224Proxy
			{
				weapon = "ACE_M224Proxy";
				count = 4;
			};
			class _xx_ACE_M220Proxy
			{
				weapon = "ACE_M220Proxy";
				count = 4;
			};
			class _xx_ACE_M3TripodProxy
			{
				weapon = "ACE_M3TripodProxy";
				count = 4;
			};
			class _xx_ACE_M122TripodProxy
			{
				weapon = "ACE_M122TripodProxy";
				count = 4;
			};
			class _xx_ACE_M252TripodProxy
			{
				weapon = "ACE_M252TripodProxy";
				count = 4;
			};
			class _xx_ACE_M224TripodProxy
			{
				weapon = "ACE_M224TripodProxy";
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
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_Raufoss_m107
			{
				magazine = "ACE_10Rnd_127x99_Raufoss_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_T_m107
			{
				magazine = "ACE_10Rnd_127x99_T_m107";
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
			class _xx_ACE_25Rnd_1143x23_B_UMP45
			{
				magazine = "ACE_25Rnd_1143x23_B_UMP45";
				count = 16;
			};
			class _xx_ACE_30Rnd_6x35_B_PDW
			{
				magazine = "ACE_30Rnd_6x35_B_PDW";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_100Rnd_556x45_M249
			{
				magazine = "100Rnd_556x45_M249";
				count = 16;
			};
			class _xx_200Rnd_556x45_L110A1
			{
				magazine = "200Rnd_556x45_L110A1";
				count = 16;
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine = "200Rnd_556x45_M249";
				count = 16;
			};
			class _xx_ACE_100Rnd_556x45_T_M249
			{
				magazine = "ACE_100Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_ACE_200Rnd_556x45_T_M249
			{
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 16;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36
			{
				magazine = "30Rnd_556x45_G36";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36SD
			{
				magazine = "30Rnd_556x45_G36SD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_G36
			{
				magazine = "ACE_30Rnd_556x45_T_G36";
				count = 16;
			};
			class _xx_6Rnd_HE_M203
			{
				magazine = "6Rnd_HE_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareWhite_M203
			{
				magazine = "6Rnd_FlareWhite_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareGreen_M203
			{
				magazine = "6Rnd_FlareGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareRed_M203
			{
				magazine = "6Rnd_FlareRed_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareYellow_M203
			{
				magazine = "6Rnd_FlareYellow_M203";
				count = 16;
			};
			class _xx_6Rnd_Smoke_M203
			{
				magazine = "6Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeRed_M203
			{
				magazine = "6Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeGreen_M203
			{
				magazine = "6Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeYellow_M203
			{
				magazine = "6Rnd_SmokeYellow_M203";
				count = 16;
			};
			class _xx_20Rnd_762x51_B_SCAR
			{
				magazine = "20Rnd_762x51_B_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_S_SCAR
			{
				magazine = "ACE_20Rnd_762x51_S_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_M110
			{
				magazine = "ACE_20Rnd_762x51_SB_M110";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_M110
			{
				magazine = "ACE_20Rnd_762x51_T_M110";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_M14
			{
				magazine = "ACE_20Rnd_762x51_B_M14";
				count = 16;
			};
			class _xx_20Rnd_762x51_DMR
			{
				magazine = "20Rnd_762x51_DMR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_DMR
			{
				magazine = "ACE_20Rnd_762x51_T_DMR";
				count = 16;
			};
			class _xx_20Rnd_762x51_SB_SCAR
			{
				magazine = "20Rnd_762x51_SB_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_SCAR
			{
				magazine = "ACE_20Rnd_762x51_T_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_SCAR
			{
				magazine = "ACE_20Rnd_762x51_SB_SCAR";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_HK417
			{
				magazine = "ACE_20Rnd_762x51_B_HK417";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_HK417
			{
				magazine = "ACE_20Rnd_762x51_SB_HK417";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_HK417
			{
				magazine = "ACE_20Rnd_762x51_T_HK417";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_G3
			{
				magazine = "ACE_20Rnd_762x51_T_G3";
				count = 16;
			};
			class _xx_ACE_5Rnd_25x59_HEDP_Barrett
			{
				magazine = "ACE_5Rnd_25x59_HEDP_Barrett";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_B_TAC50
			{
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_T_TAC50
			{
				magazine = "ACE_5Rnd_127x99_T_TAC50";
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
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 16;
			};
			class _xx_ACE_M2SLAM_M
			{
				magazine = "ACE_M2SLAM_M";
				count = 16;
			};
			class _xx_ACE_M4SLAM_M
			{
				magazine = "ACE_M4SLAM_M";
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
			class _xx_ACE_TOW_CSWDM
			{
				magazine = "ACE_TOW_CSWDM";
				count = 16;
			};
			class _xx_ACE_M2_CSWDM
			{
				magazine = "ACE_M2_CSWDM";
				count = 16;
			};
			class _xx_ACE_MK19_CSWDM
			{
				magazine = "ACE_MK19_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
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
	class ACE_MagazineBox_BIS_US: USBasicAmmunitionBox_EP1
	{
		displayName = "US Army Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_Raufoss_m107
			{
				magazine = "ACE_10Rnd_127x99_Raufoss_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_T_m107
			{
				magazine = "ACE_10Rnd_127x99_T_m107";
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
			class _xx_ACE_25Rnd_1143x23_B_UMP45
			{
				magazine = "ACE_25Rnd_1143x23_B_UMP45";
				count = 16;
			};
			class _xx_ACE_30Rnd_6x35_B_PDW
			{
				magazine = "ACE_30Rnd_6x35_B_PDW";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_100Rnd_556x45_M249
			{
				magazine = "100Rnd_556x45_M249";
				count = 16;
			};
			class _xx_200Rnd_556x45_L110A1
			{
				magazine = "200Rnd_556x45_L110A1";
				count = 16;
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine = "200Rnd_556x45_M249";
				count = 16;
			};
			class _xx_ACE_100Rnd_556x45_T_M249
			{
				magazine = "ACE_100Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_ACE_200Rnd_556x45_T_M249
			{
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 16;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36
			{
				magazine = "30Rnd_556x45_G36";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36SD
			{
				magazine = "30Rnd_556x45_G36SD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_G36
			{
				magazine = "ACE_30Rnd_556x45_T_G36";
				count = 16;
			};
			class _xx_6Rnd_HE_M203
			{
				magazine = "6Rnd_HE_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareWhite_M203
			{
				magazine = "6Rnd_FlareWhite_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareGreen_M203
			{
				magazine = "6Rnd_FlareGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareRed_M203
			{
				magazine = "6Rnd_FlareRed_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareYellow_M203
			{
				magazine = "6Rnd_FlareYellow_M203";
				count = 16;
			};
			class _xx_6Rnd_Smoke_M203
			{
				magazine = "6Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeRed_M203
			{
				magazine = "6Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeGreen_M203
			{
				magazine = "6Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeYellow_M203
			{
				magazine = "6Rnd_SmokeYellow_M203";
				count = 16;
			};
			class _xx_20Rnd_762x51_B_SCAR
			{
				magazine = "20Rnd_762x51_B_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_S_SCAR
			{
				magazine = "ACE_20Rnd_762x51_S_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_M110
			{
				magazine = "ACE_20Rnd_762x51_SB_M110";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_M110
			{
				magazine = "ACE_20Rnd_762x51_T_M110";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_M14
			{
				magazine = "ACE_20Rnd_762x51_B_M14";
				count = 16;
			};
			class _xx_20Rnd_762x51_DMR
			{
				magazine = "20Rnd_762x51_DMR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_DMR
			{
				magazine = "ACE_20Rnd_762x51_T_DMR";
				count = 16;
			};
			class _xx_20Rnd_762x51_SB_SCAR
			{
				magazine = "20Rnd_762x51_SB_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_SCAR
			{
				magazine = "ACE_20Rnd_762x51_T_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_SCAR
			{
				magazine = "ACE_20Rnd_762x51_SB_SCAR";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_HK417
			{
				magazine = "ACE_20Rnd_762x51_B_HK417";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_HK417
			{
				magazine = "ACE_20Rnd_762x51_SB_HK417";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_HK417
			{
				magazine = "ACE_20Rnd_762x51_T_HK417";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_G3
			{
				magazine = "ACE_20Rnd_762x51_T_G3";
				count = 16;
			};
			class _xx_ACE_5Rnd_25x59_HEDP_Barrett
			{
				magazine = "ACE_5Rnd_25x59_HEDP_Barrett";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_B_TAC50
			{
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_T_TAC50
			{
				magazine = "ACE_5Rnd_127x99_T_TAC50";
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
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 16;
			};
			class _xx_ACE_M2SLAM_M
			{
				magazine = "ACE_M2SLAM_M";
				count = 16;
			};
			class _xx_ACE_M4SLAM_M
			{
				magazine = "ACE_M4SLAM_M";
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
			class _xx_ACE_TOW_CSWDM
			{
				magazine = "ACE_TOW_CSWDM";
				count = 16;
			};
			class _xx_ACE_M2_CSWDM
			{
				magazine = "ACE_M2_CSWDM";
				count = 16;
			};
			class _xx_ACE_MK19_CSWDM
			{
				magazine = "ACE_MK19_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
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
	class ACE_OrdnanceBox_BIS_US: USBasicWeapons_EP1
	{
		displayName = "US Army Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade_West
			{
				magazine = "HandGrenade_West";
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
			class _xx_ACE_M86PDM
			{
				magazine = "ACE_M86PDM";
				count = 16;
			};
			class _xx_ACE_M84
			{
				magazine = "ACE_M84";
				count = 16;
			};
			class _xx_ACE_M7A3
			{
				magazine = "ACE_M7A3";
				count = 16;
			};
			class _xx_ACE_M34
			{
				magazine = "ACE_M34";
				count = 16;
			};
			class _xx_ACE_ANM14
			{
				magazine = "ACE_ANM14";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 16;
			};
			class _xx_Mine
			{
				magazine = "Mine";
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
	class ACE_WeaponBox_Launchers_BIS_US: USBasicWeapons_EP1
	{
		displayName = "US Army Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 4;
			};
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 4;
			};
			class _xx_ACE_Javelin_CLU
			{
				weapon = "ACE_Javelin_CLU";
				count = 4;
			};
			class _xx_Stinger
			{
				weapon = "Stinger";
				count = 4;
			};
			class _xx_MAAWS
			{
				weapon = "MAAWS";
				count = 4;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 4;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
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
			class _xx_ACE_MAAWS_HE
			{
				magazine = "ACE_MAAWS_HE";
				count = 16;
			};
			class _xx_MAAWS_HEAT
			{
				magazine = "MAAWS_HEAT";
				count = 16;
			};
			class _xx_MAAWS_HEDP
			{
				magazine = "MAAWS_HEDP";
				count = 16;
			};
		};
	};
	class ACE_MagazineBox_Launchers_BIS_US: USBasicAmmunitionBox_EP1
	{
		displayName = "US Army Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 16;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 16;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
				count = 16;
			};
			class _xx_Javelin
			{
				weapon = "Javelin";
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
			class _xx_ACE_MAAWS_HE
			{
				magazine = "ACE_MAAWS_HE";
				count = 16;
			};
			class _xx_MAAWS_HEAT
			{
				magazine = "MAAWS_HEAT";
				count = 16;
			};
			class _xx_MAAWS_HEDP
			{
				magazine = "MAAWS_HEDP";
				count = 16;
			};
		};
	};
	class ACE_WeaponBox_BIS_GER: USBasicWeapons_EP1
	{
		displayName = "Germany Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M9
			{
				weapon = "M9";
				count = 4;
			};
			class _xx_M9SD
			{
				weapon = "M9SD";
				count = 4;
			};
			class _xx_Colt1911
			{
				weapon = "Colt1911";
				count = 4;
			};
			class _xx_m107
			{
				weapon = "m107";
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
			class _xx_ACE_UMP45
			{
				weapon = "ACE_UMP45";
				count = 4;
			};
			class _xx_ACE_UMP45_SD
			{
				weapon = "ACE_UMP45_SD";
				count = 4;
			};
			class _xx_ACE_MP7
			{
				weapon = "ACE_MP7";
				count = 4;
			};
			class _xx_ACE_MP7_RSAS
			{
				weapon = "ACE_MP7_RSAS";
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
			class _xx_glock17_EP1
			{
				weapon = "glock17_EP1";
				count = 4;
			};
			class _xx_M60A4_EP1
			{
				weapon = "M60A4_EP1";
				count = 4;
			};
			class _xx_M24_des_EP1
			{
				weapon = "M24_des_EP1";
				count = 4;
			};
			class _xx_G36C_camo
			{
				weapon = "G36C_camo";
				count = 4;
			};
			class _xx_G36_C_SD_camo
			{
				weapon = "G36_C_SD_camo";
				count = 4;
			};
			class _xx_G36A_camo
			{
				weapon = "G36A_camo";
				count = 4;
			};
			class _xx_G36K_camo
			{
				weapon = "G36K_camo";
				count = 4;
			};
			class _xx_MG36_camo
			{
				weapon = "MG36_camo";
				count = 4;
			};
			class _xx_M32_EP1
			{
				weapon = "M32_EP1";
				count = 4;
			};
			class _xx_m107_TWS_EP1
			{
				weapon = "m107_TWS_EP1";
				count = 4;
			};
			class _xx_M110_TWS_EP1
			{
				weapon = "M110_TWS_EP1";
				count = 4;
			};
			class _xx_M110_NVG_EP1
			{
				weapon = "M110_NVG_EP1";
				count = 4;
			};
			class _xx_ACE_Glock18
			{
				weapon = "ACE_Glock18";
				count = 4;
			};
			class _xx_ACE_USP
			{
				weapon = "ACE_USP";
				count = 4;
			};
			class _xx_ACE_USPSD
			{
				weapon = "ACE_USPSD";
				count = 4;
			};
			class _xx_ACE_P8
			{
				weapon = "ACE_P8";
				count = 4;
			};
			class _xx_ACE_P226
			{
				weapon = "ACE_P226";
				count = 4;
			};
			class _xx_ACE_SPAS12
			{
				weapon = "ACE_SPAS12";
				count = 4;
			};
			class _xx_ACE_M1014_Eotech
			{
				weapon = "ACE_M1014_Eotech";
				count = 4;
			};
			class _xx_ACE_G36A2
			{
				weapon = "ACE_G36A2";
				count = 4;
			};
			class _xx_ACE_G36A2_Bipod
			{
				weapon = "ACE_G36A2_Bipod";
				count = 4;
			};
			class _xx_ACE_G36K_iron
			{
				weapon = "ACE_G36K_iron";
				count = 4;
			};
			class _xx_ACE_G36K_iron_D
			{
				weapon = "ACE_G36K_iron_D";
				count = 4;
			};
			class _xx_ACE_G36K_EOTech
			{
				weapon = "ACE_G36K_EOTech";
				count = 4;
			};
			class _xx_ACE_G36K_EOTech_D
			{
				weapon = "ACE_G36K_EOTech_D";
				count = 4;
			};
			class _xx_ACE_G36A1_AG36A1
			{
				weapon = "ACE_G36A1_AG36A1";
				count = 4;
			};
			class _xx_ACE_G36A1_AG36A1_D
			{
				weapon = "ACE_G36A1_AG36A1_D";
				count = 4;
			};
			class _xx_ACE_G36A2_AG36A2
			{
				weapon = "ACE_G36A2_AG36A2";
				count = 4;
			};
			class _xx_ACE_MG36
			{
				weapon = "ACE_MG36";
				count = 4;
			};
			class _xx_ACE_MG36_D
			{
				weapon = "ACE_MG36_D";
				count = 4;
			};
			class _xx_ACE_G3A3
			{
				weapon = "ACE_G3A3";
				count = 4;
			};
			class _xx_ACE_G3A3_RSAS
			{
				weapon = "ACE_G3A3_RSAS";
				count = 4;
			};
			class _xx_ACE_G3SG1
			{
				weapon = "ACE_G3SG1";
				count = 4;
			};
			class _xx_ACE_M110
			{
				weapon = "ACE_M110";
				count = 4;
			};
			class _xx_ACE_M110_SD
			{
				weapon = "ACE_M110_SD";
				count = 4;
			};
			class _xx_ACE_M109
			{
				weapon = "ACE_M109";
				count = 4;
			};
			class _xx_ACE_TAC50
			{
				weapon = "ACE_TAC50";
				count = 4;
			};
			class _xx_ACE_TAC50_SD
			{
				weapon = "ACE_TAC50_SD";
				count = 4;
			};
			class _xx_ACE_AS50
			{
				weapon = "ACE_AS50";
				count = 4;
			};
			class _xx_ACE_M2HBProxy
			{
				weapon = "ACE_M2HBProxy";
				count = 4;
			};
			class _xx_ACE_MK19MOD3Proxy
			{
				weapon = "ACE_MK19MOD3Proxy";
				count = 4;
			};
			class _xx_ACE_M252Proxy
			{
				weapon = "ACE_M252Proxy";
				count = 4;
			};
			class _xx_ACE_M224Proxy
			{
				weapon = "ACE_M224Proxy";
				count = 4;
			};
			class _xx_ACE_M220Proxy
			{
				weapon = "ACE_M220Proxy";
				count = 4;
			};
			class _xx_ACE_M3TripodProxy
			{
				weapon = "ACE_M3TripodProxy";
				count = 4;
			};
			class _xx_ACE_M252TripodProxy
			{
				weapon = "ACE_M252TripodProxy";
				count = 4;
			};
			class _xx_ACE_M224TripodProxy
			{
				weapon = "ACE_M224TripodProxy";
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
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_Raufoss_m107
			{
				magazine = "ACE_10Rnd_127x99_Raufoss_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_T_m107
			{
				magazine = "ACE_10Rnd_127x99_T_m107";
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
			class _xx_ACE_25Rnd_1143x23_B_UMP45
			{
				magazine = "ACE_25Rnd_1143x23_B_UMP45";
				count = 16;
			};
			class _xx_ACE_40Rnd_B_46x30_MP7
			{
				magazine = "ACE_40Rnd_B_46x30_MP7";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 16;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36
			{
				magazine = "30Rnd_556x45_G36";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36SD
			{
				magazine = "30Rnd_556x45_G36SD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_G36
			{
				magazine = "ACE_30Rnd_556x45_T_G36";
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
			class _xx_6Rnd_HE_M203
			{
				magazine = "6Rnd_HE_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareWhite_M203
			{
				magazine = "6Rnd_FlareWhite_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareGreen_M203
			{
				magazine = "6Rnd_FlareGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareRed_M203
			{
				magazine = "6Rnd_FlareRed_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareYellow_M203
			{
				magazine = "6Rnd_FlareYellow_M203";
				count = 16;
			};
			class _xx_6Rnd_Smoke_M203
			{
				magazine = "6Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeRed_M203
			{
				magazine = "6Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeGreen_M203
			{
				magazine = "6Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeYellow_M203
			{
				magazine = "6Rnd_SmokeYellow_M203";
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
			class _xx_20Rnd_762x51_B_SCAR
			{
				magazine = "20Rnd_762x51_B_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_S_SCAR
			{
				magazine = "ACE_20Rnd_762x51_S_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_M110
			{
				magazine = "ACE_20Rnd_762x51_SB_M110";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_M110
			{
				magazine = "ACE_20Rnd_762x51_T_M110";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_G3
			{
				magazine = "ACE_20Rnd_762x51_T_G3";
				count = 16;
			};
			class _xx_ACE_5Rnd_25x59_HEDP_Barrett
			{
				magazine = "ACE_5Rnd_25x59_HEDP_Barrett";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_B_TAC50
			{
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_T_TAC50
			{
				magazine = "ACE_5Rnd_127x99_T_TAC50";
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
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 16;
			};
			class _xx_ACE_M2SLAM_M
			{
				magazine = "ACE_M2SLAM_M";
				count = 16;
			};
			class _xx_ACE_M4SLAM_M
			{
				magazine = "ACE_M4SLAM_M";
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
			class _xx_ACE_TOW_CSWDM
			{
				magazine = "ACE_TOW_CSWDM";
				count = 16;
			};
			class _xx_ACE_M2_CSWDM
			{
				magazine = "ACE_M2_CSWDM";
				count = 16;
			};
			class _xx_ACE_MK19_CSWDM
			{
				magazine = "ACE_MK19_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
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
	class ACE_MagazineBox_BIS_GER: USBasicAmmunitionBox_EP1
	{
		displayName = "Germany Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_Raufoss_m107
			{
				magazine = "ACE_10Rnd_127x99_Raufoss_m107";
				count = 16;
			};
			class _xx_ACE_10Rnd_127x99_T_m107
			{
				magazine = "ACE_10Rnd_127x99_T_m107";
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
			class _xx_ACE_25Rnd_1143x23_B_UMP45
			{
				magazine = "ACE_25Rnd_1143x23_B_UMP45";
				count = 16;
			};
			class _xx_ACE_40Rnd_B_46x30_MP7
			{
				magazine = "ACE_40Rnd_B_46x30_MP7";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
				count = 16;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 16;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36
			{
				magazine = "30Rnd_556x45_G36";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36SD
			{
				magazine = "30Rnd_556x45_G36SD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_G36
			{
				magazine = "ACE_30Rnd_556x45_T_G36";
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
			class _xx_6Rnd_HE_M203
			{
				magazine = "6Rnd_HE_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareWhite_M203
			{
				magazine = "6Rnd_FlareWhite_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareGreen_M203
			{
				magazine = "6Rnd_FlareGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareRed_M203
			{
				magazine = "6Rnd_FlareRed_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareYellow_M203
			{
				magazine = "6Rnd_FlareYellow_M203";
				count = 16;
			};
			class _xx_6Rnd_Smoke_M203
			{
				magazine = "6Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeRed_M203
			{
				magazine = "6Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeGreen_M203
			{
				magazine = "6Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeYellow_M203
			{
				magazine = "6Rnd_SmokeYellow_M203";
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
			class _xx_20Rnd_762x51_B_SCAR
			{
				magazine = "20Rnd_762x51_B_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_S_SCAR
			{
				magazine = "ACE_20Rnd_762x51_S_SCAR";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_SB_M110
			{
				magazine = "ACE_20Rnd_762x51_SB_M110";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_M110
			{
				magazine = "ACE_20Rnd_762x51_T_M110";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_G3
			{
				magazine = "ACE_20Rnd_762x51_T_G3";
				count = 16;
			};
			class _xx_ACE_5Rnd_25x59_HEDP_Barrett
			{
				magazine = "ACE_5Rnd_25x59_HEDP_Barrett";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_B_TAC50
			{
				magazine = "ACE_5Rnd_127x99_B_TAC50";
				count = 16;
			};
			class _xx_ACE_5Rnd_127x99_T_TAC50
			{
				magazine = "ACE_5Rnd_127x99_T_TAC50";
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
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 16;
			};
			class _xx_ACE_M2SLAM_M
			{
				magazine = "ACE_M2SLAM_M";
				count = 16;
			};
			class _xx_ACE_M4SLAM_M
			{
				magazine = "ACE_M4SLAM_M";
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
			class _xx_ACE_TOW_CSWDM
			{
				magazine = "ACE_TOW_CSWDM";
				count = 16;
			};
			class _xx_ACE_M2_CSWDM
			{
				magazine = "ACE_M2_CSWDM";
				count = 16;
			};
			class _xx_ACE_MK19_CSWDM
			{
				magazine = "ACE_MK19_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
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
	class ACE_OrdnanceBox_BIS_GER: USBasicWeapons_EP1
	{
		displayName = "Germany Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade_West
			{
				magazine = "HandGrenade_West";
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
			class _xx_ACE_M86PDM
			{
				magazine = "ACE_M86PDM";
				count = 16;
			};
			class _xx_ACE_Flashbang
			{
				magazine = "ACE_Flashbang";
				count = 16;
			};
			class _xx_ACE_M7A3
			{
				magazine = "ACE_M7A3";
				count = 16;
			};
			class _xx_ACE_M34
			{
				magazine = "ACE_M34";
				count = 16;
			};
			class _xx_ACE_ANM14
			{
				magazine = "ACE_ANM14";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 16;
			};
			class _xx_Mine
			{
				magazine = "Mine";
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
	class ACE_WeaponBox_Launchers_BIS_GER: USBasicWeapons_EP1
	{
		displayName = "Germany Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 4;
			};
			class _xx_Stinger
			{
				weapon = "Stinger";
				count = 4;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 4;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
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
		};
	};
	class ACE_MagazineBox_Launchers_BIS_GER: USBasicAmmunitionBox_EP1
	{
		displayName = "Germany Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 16;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 16;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
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
		};
	};
	class ACE_WeaponBox_BIS_BAF: USBasicWeapons_EP1
	{
		displayName = "BAF Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M9
			{
				weapon = "M9";
				count = 4;
			};
			class _xx_M9SD
			{
				weapon = "M9SD";
				count = 4;
			};
			class _xx_Colt1911
			{
				weapon = "Colt1911";
				count = 4;
			};
			class _xx_ACE_L9A1
			{
				weapon = "ACE_L9A1";
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
			class _xx_ACE_KAC_PDW
			{
				weapon = "ACE_KAC_PDW";
				count = 4;
			};
			class _xx_BAF_AS50_scoped
			{
				weapon = "BAF_AS50_scoped";
				count = 4;
			};
			class _xx_BAF_AS50_TWS
			{
				weapon = "BAF_AS50_TWS";
				count = 4;
			};
			class _xx_BAF_LRR_scoped
			{
				weapon = "BAF_LRR_scoped";
				count = 4;
			};
			class _xx_BAF_LRR_scoped_W
			{
				weapon = "BAF_LRR_scoped_W";
				count = 4;
			};
			class _xx_BAF_L85A2_RIS_Holo
			{
				weapon = "BAF_L85A2_RIS_Holo";
				count = 4;
			};
			class _xx_BAF_L85A2_UGL_Holo
			{
				weapon = "BAF_L85A2_UGL_Holo";
				count = 4;
			};
			class _xx_BAF_L85A2_RIS_SUSAT
			{
				weapon = "BAF_L85A2_RIS_SUSAT";
				count = 4;
			};
			class _xx_BAF_L85A2_UGL_SUSAT
			{
				weapon = "BAF_L85A2_UGL_SUSAT";
				count = 4;
			};
			class _xx_BAF_L85A2_RIS_ACOG
			{
				weapon = "BAF_L85A2_RIS_ACOG";
				count = 4;
			};
			class _xx_BAF_L85A2_UGL_ACOG
			{
				weapon = "BAF_L85A2_UGL_ACOG";
				count = 4;
			};
			class _xx_BAF_L85A2_RIS_CWS
			{
				weapon = "BAF_L85A2_RIS_CWS";
				count = 4;
			};
			class _xx_BAF_L86A2_ACOG
			{
				weapon = "BAF_L86A2_ACOG";
				count = 4;
			};
			class _xx_BAF_L110A1_Aim
			{
				weapon = "BAF_L110A1_Aim";
				count = 4;
			};
			class _xx_BAF_L7A2_GPMG
			{
				weapon = "BAF_L7A2_GPMG";
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
			class _xx_glock17_EP1
			{
				weapon = "glock17_EP1";
				count = 4;
			};
			class _xx_ACE_Glock18
			{
				weapon = "ACE_Glock18";
				count = 4;
			};
			class _xx_ACE_USP
			{
				weapon = "ACE_USP";
				count = 4;
			};
			class _xx_ACE_USPSD
			{
				weapon = "ACE_USPSD";
				count = 4;
			};
			class _xx_ACE_P8
			{
				weapon = "ACE_P8";
				count = 4;
			};
			class _xx_ACE_P226
			{
				weapon = "ACE_P226";
				count = 4;
			};
			class _xx_ACE_SPAS12
			{
				weapon = "ACE_SPAS12";
				count = 4;
			};
			class _xx_ACE_M1014_Eotech
			{
				weapon = "ACE_M1014_Eotech";
				count = 4;
			};
			class _xx_ACE_M252Proxy
			{
				weapon = "ACE_M252Proxy";
				count = 4;
			};
			class _xx_ACE_M224Proxy
			{
				weapon = "ACE_M224Proxy";
				count = 4;
			};
			class _xx_ACE_BAF_L2A1Proxy
			{
				weapon = "ACE_BAF_L2A1Proxy";
				count = 4;
			};
			class _xx_ACE_BAF_static_GMGProxy
			{
				weapon = "ACE_BAF_static_GMGProxy";
				count = 4;
			};
			class _xx_ACE_M3TripodProxy
			{
				weapon = "ACE_M3TripodProxy";
				count = 4;
			};
			class _xx_ACE_M122TripodProxy
			{
				weapon = "ACE_M122TripodProxy";
				count = 4;
			};
			class _xx_ACE_M252TripodProxy
			{
				weapon = "ACE_M252TripodProxy";
				count = 4;
			};
			class _xx_ACE_M224TripodProxy
			{
				weapon = "ACE_M224TripodProxy";
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
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 16;
			};
			class _xx_ACE_13Rnd_9x19_L9A1
			{
				magazine = "ACE_13Rnd_9x19_L9A1";
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
			class _xx_ACE_30Rnd_6x35_B_PDW
			{
				magazine = "ACE_30Rnd_6x35_B_PDW";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_5Rnd_127x99_as50
			{
				magazine = "5Rnd_127x99_as50";
				count = 16;
			};
			class _xx_5Rnd_86x70_L115A1
			{
				magazine = "5Rnd_86x70_L115A1";
				count = 16;
			};
			class _xx_ACE_5Rnd_86x70_T_L115A1
			{
				magazine = "ACE_5Rnd_86x70_T_L115A1";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_100Rnd_556x45_M249
			{
				magazine = "100Rnd_556x45_M249";
				count = 16;
			};
			class _xx_200Rnd_556x45_L110A1
			{
				magazine = "200Rnd_556x45_L110A1";
				count = 16;
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine = "200Rnd_556x45_M249";
				count = 16;
			};
			class _xx_ACE_100Rnd_556x45_T_M249
			{
				magazine = "ACE_100Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_ACE_200Rnd_556x45_T_M249
			{
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
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
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 16;
			};
			class _xx_ACE_M2SLAM_M
			{
				magazine = "ACE_M2SLAM_M";
				count = 16;
			};
			class _xx_ACE_M4SLAM_M
			{
				magazine = "ACE_M4SLAM_M";
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
			class _xx_ACE_M2_CSWDM
			{
				magazine = "ACE_M2_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
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
	class ACE_MagazineBox_BIS_BAF: USBasicAmmunitionBox_EP1
	{
		displayName = "BAF Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
				count = 16;
			};
			class _xx_ACE_13Rnd_9x19_L9A1
			{
				magazine = "ACE_13Rnd_9x19_L9A1";
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
			class _xx_ACE_30Rnd_6x35_B_PDW
			{
				magazine = "ACE_30Rnd_6x35_B_PDW";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_5Rnd_127x99_as50
			{
				magazine = "5Rnd_127x99_as50";
				count = 16;
			};
			class _xx_5Rnd_86x70_L115A1
			{
				magazine = "5Rnd_86x70_L115A1";
				count = 16;
			};
			class _xx_ACE_5Rnd_86x70_T_L115A1
			{
				magazine = "ACE_5Rnd_86x70_T_L115A1";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_100Rnd_556x45_M249
			{
				magazine = "100Rnd_556x45_M249";
				count = 16;
			};
			class _xx_200Rnd_556x45_L110A1
			{
				magazine = "200Rnd_556x45_L110A1";
				count = 16;
			};
			class _xx_200Rnd_556x45_M249
			{
				magazine = "200Rnd_556x45_M249";
				count = 16;
			};
			class _xx_ACE_100Rnd_556x45_T_M249
			{
				magazine = "ACE_100Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_ACE_200Rnd_556x45_T_M249
			{
				magazine = "ACE_200Rnd_556x45_T_M249";
				count = 16;
			};
			class _xx_100Rnd_762x51_M240
			{
				magazine = "100Rnd_762x51_M240";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
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
			class _xx_ACE_Claymore_M
			{
				magazine = "ACE_Claymore_M";
				count = 16;
			};
			class _xx_ACE_M2SLAM_M
			{
				magazine = "ACE_M2SLAM_M";
				count = 16;
			};
			class _xx_ACE_M4SLAM_M
			{
				magazine = "ACE_M4SLAM_M";
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
			class _xx_ACE_M2_CSWDM
			{
				magazine = "ACE_M2_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 16;
			};
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
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
	class ACE_OrdnanceBox_BIS_BAF: USBasicWeapons_EP1
	{
		displayName = "BAF Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_BAF_L109A1_HE
			{
				magazine = "BAF_L109A1_HE";
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
			class _xx_ACE_M86PDM
			{
				magazine = "ACE_M86PDM";
				count = 16;
			};
			class _xx_ACE_Flashbang
			{
				magazine = "ACE_Flashbang";
				count = 16;
			};
			class _xx_ACE_M7A3
			{
				magazine = "ACE_M7A3";
				count = 16;
			};
			class _xx_ACE_M34
			{
				magazine = "ACE_M34";
				count = 16;
			};
			class _xx_ACE_ANM14
			{
				magazine = "ACE_ANM14";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
				count = 16;
			};
			class _xx_Mine
			{
				magazine = "Mine";
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
	class ACE_WeaponBox_Launchers_BIS_BAF: USBasicWeapons_EP1
	{
		displayName = "BAF Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 4;
			};
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 4;
			};
			class _xx_ACE_Javelin_CLU
			{
				weapon = "ACE_Javelin_CLU";
				count = 4;
			};
			class _xx_Stinger
			{
				weapon = "Stinger";
				count = 4;
			};
			class _xx_BAF_NLAW_Launcher
			{
				weapon = "BAF_NLAW_Launcher";
				count = 4;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 4;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
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
		};
	};
	class ACE_MagazineBox_Launchers_BIS_BAF: USBasicAmmunitionBox_EP1
	{
		displayName = "BAF Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 16;
			};
			class _xx_BAF_NLAW_Launcher
			{
				weapon = "BAF_NLAW_Launcher";
				count = 16;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 16;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
				count = 16;
			};
			class _xx_Javelin
			{
				weapon = "Javelin";
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
		};
	};
	class ACE_WeaponBox_PMC_BAF: USBasicWeapons_EP1
	{
		displayName = "PMC Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M9
			{
				weapon = "M9";
				count = 4;
			};
			class _xx_M9SD
			{
				weapon = "M9SD";
				count = 4;
			};
			class _xx_M16A2
			{
				weapon = "M16A2";
				count = 4;
			};
			class _xx_M16A2GL
			{
				weapon = "M16A2GL";
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
			class _xx_Colt1911
			{
				weapon = "Colt1911";
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
			class _xx_glock17_EP1
			{
				weapon = "glock17_EP1";
				count = 4;
			};
			class _xx_M24_des_EP1
			{
				weapon = "M24_des_EP1";
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
			class _xx_G36C_camo
			{
				weapon = "G36C_camo";
				count = 4;
			};
			class _xx_G36_C_SD_camo
			{
				weapon = "G36_C_SD_camo";
				count = 4;
			};
			class _xx_G36A_camo
			{
				weapon = "G36A_camo";
				count = 4;
			};
			class _xx_G36K_camo
			{
				weapon = "G36K_camo";
				count = 4;
			};
			class _xx_MG36_camo
			{
				weapon = "MG36_camo";
				count = 4;
			};
			class _xx_M32_EP1
			{
				weapon = "M32_EP1";
				count = 4;
			};
			class _xx_Mk13_EP1
			{
				weapon = "Mk13_EP1";
				count = 4;
			};
			class _xx_M14_EP1
			{
				weapon = "M14_EP1";
				count = 4;
			};
			class _xx_AA12_PMC
			{
				weapon = "AA12_PMC";
				count = 4;
			};
			class _xx_PMC_AS50_scoped
			{
				weapon = "PMC_AS50_scoped";
				count = 4;
			};
			class _xx_PMC_AS50_TWS
			{
				weapon = "PMC_AS50_TWS";
				count = 4;
			};
			class _xx_m8_carbine_pmc
			{
				weapon = "m8_carbine_pmc";
				count = 4;
			};
			class _xx_m8_compact_pmc
			{
				weapon = "m8_compact_pmc";
				count = 4;
			};
			class _xx_m8_holo_sd
			{
				weapon = "m8_holo_sd";
				count = 4;
			};
			class _xx_m8_tws_sd
			{
				weapon = "m8_tws_sd";
				count = 4;
			};
			class _xx_m8_tws
			{
				weapon = "m8_tws";
				count = 4;
			};
			class _xx_ACE_Glock18
			{
				weapon = "ACE_Glock18";
				count = 4;
			};
			class _xx_ACE_USP
			{
				weapon = "ACE_USP";
				count = 4;
			};
			class _xx_ACE_USPSD
			{
				weapon = "ACE_USPSD";
				count = 4;
			};
			class _xx_ACE_P8
			{
				weapon = "ACE_P8";
				count = 4;
			};
			class _xx_ACE_P226
			{
				weapon = "ACE_P226";
				count = 4;
			};
			class _xx_ACE_BackPack
			{
				weapon = "ACE_BackPack";
				count = 4;
			};
			class _xx_ACE_Combat_Pack
			{
				weapon = "ACE_Combat_Pack";
				count = 4;
			};
			class _xx_ACE_SPAS12
			{
				weapon = "ACE_SPAS12";
				count = 4;
			};
			class _xx_ACE_M1014_Eotech
			{
				weapon = "ACE_M1014_Eotech";
				count = 4;
			};
			class _xx_ACE_G36A2
			{
				weapon = "ACE_G36A2";
				count = 4;
			};
			class _xx_ACE_G36A2_D
			{
				weapon = "ACE_G36A2_D";
				count = 4;
			};
			class _xx_ACE_G36A2_Bipod
			{
				weapon = "ACE_G36A2_Bipod";
				count = 4;
			};
			class _xx_ACE_G36A2_Bipod_D
			{
				weapon = "ACE_G36A2_Bipod_D";
				count = 4;
			};
			class _xx_ACE_G36K_iron
			{
				weapon = "ACE_G36K_iron";
				count = 4;
			};
			class _xx_ACE_G36K_iron_D
			{
				weapon = "ACE_G36K_iron_D";
				count = 4;
			};
			class _xx_ACE_G36K_EOTech
			{
				weapon = "ACE_G36K_EOTech";
				count = 4;
			};
			class _xx_ACE_G36K_EOTech_D
			{
				weapon = "ACE_G36K_EOTech_D";
				count = 4;
			};
			class _xx_ACE_G36A1_AG36A1
			{
				weapon = "ACE_G36A1_AG36A1";
				count = 4;
			};
			class _xx_ACE_G36A1_AG36A1_D
			{
				weapon = "ACE_G36A1_AG36A1_D";
				count = 4;
			};
			class _xx_ACE_m16a2_scope
			{
				weapon = "ACE_m16a2_scope";
				count = 4;
			};
			class _xx_ACE_m16a2gl_scope
			{
				weapon = "ACE_m16a2gl_scope";
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
			class _xx_ACE_SVD_Bipod
			{
				weapon = "ACE_SVD_Bipod";
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
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 16;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36
			{
				magazine = "30Rnd_556x45_G36";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36SD
			{
				magazine = "30Rnd_556x45_G36SD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_G36
			{
				magazine = "ACE_30Rnd_556x45_T_G36";
				count = 16;
			};
			class _xx_6Rnd_HE_M203
			{
				magazine = "6Rnd_HE_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareWhite_M203
			{
				magazine = "6Rnd_FlareWhite_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareGreen_M203
			{
				magazine = "6Rnd_FlareGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareRed_M203
			{
				magazine = "6Rnd_FlareRed_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareYellow_M203
			{
				magazine = "6Rnd_FlareYellow_M203";
				count = 16;
			};
			class _xx_6Rnd_Smoke_M203
			{
				magazine = "6Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeRed_M203
			{
				magazine = "6Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeGreen_M203
			{
				magazine = "6Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeYellow_M203
			{
				magazine = "6Rnd_SmokeYellow_M203";
				count = 16;
			};
			class _xx_20Rnd_762x51_DMR
			{
				magazine = "20Rnd_762x51_DMR";
				count = 16;
			};
			class _xx_20Rnd_B_AA12_74Slug
			{
				magazine = "20Rnd_B_AA12_74Slug";
				count = 16;
			};
			class _xx_20Rnd_B_AA12_HE
			{
				magazine = "20Rnd_B_AA12_HE";
				count = 16;
			};
			class _xx_20Rnd_B_AA12_Pellets
			{
				magazine = "20Rnd_B_AA12_Pellets";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_5Rnd_127x99_as50
			{
				magazine = "5Rnd_127x99_as50";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
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
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
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
	class ACE_MagazineBox_PMC_BAF: USBasicAmmunitionBox_EP1
	{
		displayName = "PMC Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_15Rnd_9x19_M9
			{
				magazine = "15Rnd_9x19_M9";
				count = 16;
			};
			class _xx_15Rnd_9x19_M9SD
			{
				magazine = "15Rnd_9x19_M9SD";
				count = 16;
			};
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_7Rnd_45ACP_1911
			{
				magazine = "7Rnd_45ACP_1911";
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
			class _xx_17Rnd_9x19_glock17
			{
				magazine = "17Rnd_9x19_glock17";
				count = 16;
			};
			class _xx_ACE_33Rnd_9x19_G18
			{
				magazine = "ACE_33Rnd_9x19_G18";
				count = 16;
			};
			class _xx_5Rnd_762x51_M24
			{
				magazine = "5Rnd_762x51_M24";
				count = 16;
			};
			class _xx_ACE_5Rnd_762x51_T_M24
			{
				magazine = "ACE_5Rnd_762x51_T_M24";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36
			{
				magazine = "30Rnd_556x45_G36";
				count = 16;
			};
			class _xx_30Rnd_556x45_G36SD
			{
				magazine = "30Rnd_556x45_G36SD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_G36
			{
				magazine = "ACE_30Rnd_556x45_T_G36";
				count = 16;
			};
			class _xx_6Rnd_HE_M203
			{
				magazine = "6Rnd_HE_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareWhite_M203
			{
				magazine = "6Rnd_FlareWhite_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareGreen_M203
			{
				magazine = "6Rnd_FlareGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareRed_M203
			{
				magazine = "6Rnd_FlareRed_M203";
				count = 16;
			};
			class _xx_6Rnd_FlareYellow_M203
			{
				magazine = "6Rnd_FlareYellow_M203";
				count = 16;
			};
			class _xx_6Rnd_Smoke_M203
			{
				magazine = "6Rnd_Smoke_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeRed_M203
			{
				magazine = "6Rnd_SmokeRed_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeGreen_M203
			{
				magazine = "6Rnd_SmokeGreen_M203";
				count = 16;
			};
			class _xx_6Rnd_SmokeYellow_M203
			{
				magazine = "6Rnd_SmokeYellow_M203";
				count = 16;
			};
			class _xx_20Rnd_762x51_DMR
			{
				magazine = "20Rnd_762x51_DMR";
				count = 16;
			};
			class _xx_20Rnd_B_AA12_74Slug
			{
				magazine = "20Rnd_B_AA12_74Slug";
				count = 16;
			};
			class _xx_20Rnd_B_AA12_HE
			{
				magazine = "20Rnd_B_AA12_HE";
				count = 16;
			};
			class _xx_20Rnd_B_AA12_Pellets
			{
				magazine = "20Rnd_B_AA12_Pellets";
				count = 16;
			};
			class _xx_10Rnd_127x99_m107
			{
				magazine = "10Rnd_127x99_m107";
				count = 16;
			};
			class _xx_5Rnd_127x99_as50
			{
				magazine = "5Rnd_127x99_as50";
				count = 16;
			};
			class _xx_ACE_12Rnd_45ACP_USP
			{
				magazine = "ACE_12Rnd_45ACP_USP";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P8
			{
				magazine = "ACE_15Rnd_9x19_P8";
				count = 16;
			};
			class _xx_ACE_15Rnd_9x19_P226
			{
				magazine = "ACE_15Rnd_9x19_P226";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_74Slug
			{
				magazine = "8Rnd_B_Beneli_74Slug";
				count = 16;
			};
			class _xx_8Rnd_B_Beneli_Pellets
			{
				magazine = "8Rnd_B_Beneli_Pellets";
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
			class _xx_ACE_MON50_M
			{
				magazine = "ACE_MON50_M";
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
	class ACE_OrdnanceBox_PMC_BAF: USBasicWeapons_EP1
	{
		displayName = "PMC Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade_West
			{
				magazine = "HandGrenade_West";
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
			class _xx_ACE_RDGM
			{
				magazine = "ACE_RDGM";
				count = 16;
			};
			class _xx_ACE_Flashbang
			{
				magazine = "ACE_Flashbang";
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
	class ACE_WeaponBox_Launchers_PMC_BAF: USBasicWeapons_EP1
	{
		displayName = "PMC Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 4;
			};
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
			class _xx_MAAWS
			{
				weapon = "MAAWS";
				count = 4;
			};
			class _xx_ACE_RPG7V_PGO7
			{
				weapon = "ACE_RPG7V_PGO7";
				count = 4;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 4;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
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
			class _xx_ACE_MAAWS_HE
			{
				magazine = "ACE_MAAWS_HE";
				count = 16;
			};
			class _xx_MAAWS_HEAT
			{
				magazine = "MAAWS_HEAT";
				count = 16;
			};
			class _xx_MAAWS_HEDP
			{
				magazine = "MAAWS_HEDP";
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
	class ACE_MagazineBox_Launchers_PMC_BAF: USBasicAmmunitionBox_EP1
	{
		displayName = "PMC Launchers Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_M136
			{
				weapon = "M136";
				count = 16;
			};
			class _xx_RPG18
			{
				weapon = "RPG18";
				count = 16;
			};
			class _xx_ACE_M136_CSRS
			{
				weapon = "ACE_M136_CSRS";
				count = 16;
			};
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
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
			class _xx_ACE_MAAWS_HE
			{
				magazine = "ACE_MAAWS_HE";
				count = 16;
			};
			class _xx_MAAWS_HEAT
			{
				magazine = "MAAWS_HEAT";
				count = 16;
			};
			class _xx_MAAWS_HEDP
			{
				magazine = "MAAWS_HEDP";
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
	class ACE_WeaponBox_CIV: USBasicWeapons_EP1
	{
		displayName = "Chernarus Weapon Crate";
		model = "\ca\weapons\AmmoBoxes\USSpecialWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
			class _xx_ACE_BackPack
			{
				weapon = "ACE_BackPack";
				count = 4;
			};
			class _xx_ACE_Combat_Pack
			{
				weapon = "ACE_Combat_Pack";
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
		};
		class TransportMagazines
		{
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
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
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
	class ACE_MagazineBox_CIV: USBasicAmmunitionBox_EP1
	{
		displayName = "Chernarus Ammunition Crate";
		model = "\ca\weapons\AmmoBoxes\USBasicWeapons.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
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
			class _xx_ACE_SandBag_Magazine
			{
				magazine = "ACE_SandBag_Magazine";
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
	class ACE_OrdnanceBox_CIV: USBasicWeapons_EP1
	{
		displayName = "Chernarus Ordnance Crate";
		model = "\ca\weapons\AmmoBoxes\USOrdnance.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_HandGrenade_Stone
			{
				magazine = "HandGrenade_Stone";
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
			class _xx_ACE_Knicklicht_B
			{
				magazine = "ACE_Knicklicht_B";
				count = 16;
			};
			class _xx_ACE_Knicklicht_G
			{
				magazine = "ACE_Knicklicht_G";
				count = 16;
			};
			class _xx_ACE_Knicklicht_IR
			{
				magazine = "ACE_Knicklicht_IR";
				count = 16;
			};
			class _xx_ACE_Knicklicht_R
			{
				magazine = "ACE_Knicklicht_R";
				count = 16;
			};
			class _xx_ACE_Knicklicht_W
			{
				magazine = "ACE_Knicklicht_W";
				count = 16;
			};
			class _xx_ACE_Knicklicht_Y
			{
				magazine = "ACE_Knicklicht_Y";
				count = 16;
			};
			class _xx_PipeBomb
			{
				magazine = "PipeBomb";
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
	class ACE_WeaponBox_Launchers_CIV: USBasicWeapons_EP1
	{
		displayName = "Chernarus Launchers Crate";
		model = "\ca\weapons\AmmoBoxes\USLaunchers.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons
		{
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
		class TransportMagazines{};
	};
	class ACE_Tbox_US;
	class ACE_Tbox_RU;
	class ACE_Tbox_GP_W;
	class ACE_Tbox_GP_R;
	class ACE_Tbox_ACE_M72A2: ACE_Tbox_GP_W
	{
		scope = 2;
		displayName = "M72A2 Transport Box";
		model = "x\ace\addons\m_veh_crates\ace_launcher_AT4_us.p3d";
		class TransportWeapons
		{
			class _xx_ACE_M72A2
			{
				weapon = "ACE_M72A2";
				count = 4;
			};
		};
	};
	class ACE_Tbox_ACE_RPG29: ACE_Tbox_GP_R
	{
		scope = 2;
		displayName = "RPG-29 Transport Box";
		class TransportWeapons
		{
			class _xx_ACE_RPG29
			{
				weapon = "ACE_RPG29";
				count = 1;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_RPG29_PG29
			{
				magazine = "ACE_RPG29_PG29";
				count = 2;
			};
		};
	};
	class ACE_Tbox_ACE_RPG22: ACE_Tbox_GP_R
	{
		scope = 2;
		displayName = "RPG-22 Transport Box";
		class TransportWeapons
		{
			class _xx_ACE_RPG22
			{
				weapon = "ACE_RPG22";
				count = 4;
			};
		};
	};
	class ACE_Tbox_ACE_RPG27: ACE_Tbox_GP_R
	{
		scope = 2;
		displayName = "RPG-27 Transport Box";
		class TransportWeapons
		{
			class _xx_ACE_RPG27
			{
				weapon = "ACE_RPG27";
				count = 2;
			};
		};
	};
	class ACE_Tbox_ACE_RPOM: ACE_Tbox_GP_R
	{
		scope = 2;
		displayName = "RPO-M Transport Box";
		class TransportWeapons
		{
			class _xx_ACE_RPOM
			{
				weapon = "ACE_RPOM";
				count = 3;
			};
		};
	};
	class ACE_WeaponBox_BIS_TK: USBasicWeapons_EP1
	{
		displayName = "Takistani Army Weapon Crate";
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
			class _xx_M16A2
			{
				weapon = "M16A2";
				count = 4;
			};
			class _xx_M16A2GL
			{
				weapon = "M16A2GL";
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
			class _xx_FN_FAL
			{
				weapon = "FN_FAL";
				count = 4;
			};
			class _xx_FN_FAL_ANPVS4
			{
				weapon = "FN_FAL_ANPVS4";
				count = 4;
			};
			class _xx_M79_EP1
			{
				weapon = "M79_EP1";
				count = 4;
			};
			class _xx_ACE_m16a2_scope
			{
				weapon = "ACE_m16a2_scope";
				count = 4;
			};
			class _xx_ACE_m16a2gl_scope
			{
				weapon = "ACE_m16a2gl_scope";
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
			class _xx_ACE_G3A3
			{
				weapon = "ACE_G3A3";
				count = 4;
			};
			class _xx_ACE_G3SG1
			{
				weapon = "ACE_G3SG1";
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
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_20Rnd_762x51_FNFAL
			{
				magazine = "20Rnd_762x51_FNFAL";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_FAL
			{
				magazine = "ACE_20Rnd_762x51_B_FAL";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_FAL
			{
				magazine = "ACE_20Rnd_762x51_T_FAL";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_G3
			{
				magazine = "ACE_20Rnd_762x51_T_G3";
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
	class ACE_MagazineBox_BIS_TK: USBasicAmmunitionBox_EP1
	{
		displayName = "Takistani Army Ammunition Crate";
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
			class _xx_100Rnd_556x45_BetaCMag
			{
				magazine = "100Rnd_556x45_BetaCMag";
				count = 16;
			};
			class _xx_20Rnd_556x45_Stanag
			{
				magazine = "20Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_Stanag
			{
				magazine = "30Rnd_556x45_Stanag";
				count = 16;
			};
			class _xx_30Rnd_556x45_StanagSD
			{
				magazine = "30Rnd_556x45_StanagSD";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_SB_Stanag
			{
				magazine = "ACE_30Rnd_556x45_SB_Stanag";
				count = 16;
			};
			class _xx_ACE_30Rnd_556x45_T_Stanag
			{
				magazine = "ACE_30Rnd_556x45_T_Stanag";
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
			class _xx_20Rnd_762x51_FNFAL
			{
				magazine = "20Rnd_762x51_FNFAL";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_FAL
			{
				magazine = "ACE_20Rnd_762x51_B_FAL";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_FAL
			{
				magazine = "ACE_20Rnd_762x51_T_FAL";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_B_G3
			{
				magazine = "ACE_20Rnd_762x51_B_G3";
				count = 16;
			};
			class _xx_ACE_20Rnd_762x51_T_G3
			{
				magazine = "ACE_20Rnd_762x51_T_G3";
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
	class ACE_OrdnanceBox_BIS_TK: USBasicWeapons_EP1
	{
		displayName = "Takistani Army Ordnance Crate";
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
	class ACE_WeaponBox_Launchers_BIS_TK: USBasicWeapons_EP1
	{
		displayName = "Takistani Army Launchers Crate";
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
			class _xx_Strela
			{
				magazine = "Strela";
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
	class ACE_MagazineBox_Launchers_BIS_TK: USBasicAmmunitionBox_EP1
	{
		displayName = "Takistani Army Launchers Ammunition Crate";
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
			class _xx_Strela
			{
				magazine = "Strela";
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
