////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed May 23 21:40:39 2012 : Created on Wed May 23 21:40:39 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_sniper : config.bin{
class CfgPatches
{
	class acex_wep_sniper
	{
		units[] = {};
		weapons[] = {"ACE_M4SPR_SD","ACE_Mk12mod1_SD","ACE_M110","ACE_M110_SD","ACE_M109","ACE_TAC50","ACE_TAC50_SD","ACE_AS50"};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","CAWeapons","CAWeapons2","CAWeapons_E","CAWeapons_E_M110","ace_c_weapon"};
		version = "1.13.0.363";
		author[] = {"Rocko","Scubaman3D","Dan","Macko","zGuba"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_sniper
		{
			list[] = {"acex_wep_sniper"};
		};
	};
};
class CfgMagazines
{
	class 10Rnd_127x99_m107;
	class ACE_5Rnd_25x59_HEDP_Barrett: 10Rnd_127x99_m107
	{
		model = "\x\acex\addons\m_wep_sniper\ace_m109_mag.p3d";
	};
	class ACE_5Rnd_127x99_B_TAC50: 10Rnd_127x99_m107
	{
		model = "\x\acex\addons\m_wep_sniper\ace_tac50d_mag.p3d";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Rifle;
	class M110_TWS_EP1: Rifle
	{
		class OpticsModes;
		class Single;
	};
	class M110_NVG_EP1: M110_TWS_EP1
	{
		class OpticsModes: OpticsModes
		{
			class StepScope;
		};
		class Single;
	};
	class ACE_M110: M110_NVG_EP1
	{
		ace_bipod = 1;
		ace_weight = 6.7200003;
		dexterity = "(0.5 + 3.75/(6+ 0.72 + 0.001) + 0/10)";
		displayName = "M110";
		model = "\x\acex\addons\m_wep_sniper\ace_m110.p3d";
		picture = "\x\acex\addons\c_wep_sniper\i\w_m110_ca.paa";
		ace_sa_zerooffset = 0;
		visionMode[] = {"Normal"};
		modelOptics = "\x\ace\addons\m_wep_optics\NWD_10x_round_mildot";
		class OpticsModes: OpticsModes
		{
			class DayStepScope: StepScope
			{
				visionMode[] = {"Normal"};
				opticsZoomMin = 0.029624;
				opticsZoomMax = 0.085714;
				opticsZoomInit = 0.085714;
			};
		};
		class Library
		{
			libTextDesc = "";
		};
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
	};
	class ACE_M110_SD: ACE_M110
	{
		ace_weight = 7.6200004;
		dexterity = "(0.5 + 3.75/(6+ 0.72+ 0.9 + 0.001) + 0/10)";
		ACE_Size = 9000;
		ACE_NoPack = 1;
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		displayName = "M110 SD";
		model = "\x\acex\addons\m_wep_sniper\ace_m110_sd.p3d";
		picture = "\x\acex\addons\c_wep_sniper\i\w_m110sd_ca.paa";
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_sniper\m110sd_fire.wss",0.1,1.1,100};
			begin2[] = {"\x\acex\addons\s_wep_sniper\m110sd_fire.wss",0.1,1.025,100};
			begin3[] = {"\x\acex\addons\s_wep_sniper\m110sd_fire.wss",0.1,0.97,100};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
	};
	class m107: Rifle
	{
		class OpticsModes
		{
			class StepScope;
		};
	};
	class ACE_M109: m107
	{
		class OpticsModes: OpticsModes
		{
			class StepScope: StepScope
			{
				memoryPointCamera = "eye";
			};
		};
		ace_weight = 15.9;
		dexterity = "(0.5 + 3.75/(15.9 + 0.001) + -3/10)";
		ACE_Size = 9000;
		ACE_NoPack = 1;
		displayName = "M109";
		picture = "\x\acex\addons\c_wep_sniper\i\w_m109_ca.paa";
		model = "\x\acex\addons\m_wep_sniper\ace_m109.p3d";
		magazines[] = {"ACE_5Rnd_25x59_HEDP_Barrett"};
		dispersion = 0.0007;
		minRange = 10;
		minRangeProbab = 0.7;
		midRange = 1000;
		midRangeProbab = 0.85;
		maxRange = 2200;
		maxRangeProbab = 0.2;
		distanceZoomMin = 660;
		distanceZoomMax = 660;
		ace_sa_enabled = 1;
		ace_sa_adj_mode = "angle";
		ace_sa_defaultelevation = 18;
		ace_sa_zerooffset = 0;
		ace_sa_defaultwindage = 0;
		ace_sa_defaultrange = 500;
		ace_sa_minelevation = -20;
		ace_sa_maxelevation = 250;
		ace_sa_stepelevation = 1;
		ace_sa_windage = 100;
		ace_sa_stepwindage = 1;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 2000;
		ace_sa_elev_unit = "moa";
		ace_sa_wind_unit = "moa";
		ace_sa_range_unit = "meters";
		ace_sa_zeroelev = 100;
		ace_sa_table_elev[] = {{0,0},{100,1},{200,5},{300,9},{400,13},{500,17},{600,22},{700,28},{800,35},{900,43},{1000,51},{1100,60},{1200,71},{1300,83},{1400,97},{1500,114},{1600,131},{1700,152},{1800,176},{1900,203},{2000,235}};
		ace_drift[] = {{0,0},{100,0.03},{200,0.07},{300,0.12},{400,0.14},{500,0.2},{600,0.36},{700,0.48},{800,0.78},{900,0.93},{1000,1.27},{1100,1.65},{1200,2.15},{1300,2.8},{1400,3.44},{1500,4.33},{1600,5.37},{1700,6.5},{1800,8},{1900,9.75},{2000,11.9}};
		descriptionShort = "$STR_ACE_DSS_M109";
		begin1[] = {"\x\acex\addons\s_wep_sniper\m109_fire1.wss",3.51189,0.93,3000};
		begin2[] = {"\x\acex\addons\s_wep_sniper\m109_fire2.wss",3.51189,0.89,3000};
		begin3[] = {"\x\acex\addons\s_wep_sniper\m109_fire3.wss",3.51189,0.87,3000};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		class Library
		{
			libTextDesc = "";
		};
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
	};
	class ACE_TAC50: m107
	{
		class OpticsModes: OpticsModes
		{
			class StepScope: StepScope
			{
				memoryPointCamera = "eye";
				opticsZoomInit = 0.0825;
				opticsZoomMin = 0.01875;
				opticsZoomMax = 0.066;
			};
		};
		ace_bipod = 1;
		ace_weight = 12.88;
		dexterity = "(0.5 + 3.75/(11.8+ 1.08 + 0.001) + -3/10)";
		ACE_Size = 9000;
		ACE_NoPack = 1;
		scope = 2;
		displayName = "TAC-50";
		model = "\x\acex\addons\m_wep_sniper\ace_tac50d.p3d";
		picture = "\x\acex\addons\c_wep_sniper\i\w_tac50_ca.paa";
		magazines[] = {"ACE_5Rnd_127x99_B_TAC50","ACE_5Rnd_127x99_S_TAC50","ACE_5Rnd_127x99_T_TAC50"};
		reloadtime = 2;
		dispersion = 0.00015;
		handAnim[] = {};
		begin1[] = {"\x\acex\addons\s_wep_sniper\tac50_fire1.wss",3.51189,1,3000};
		begin2[] = {"\x\acex\addons\s_wep_sniper\tac50_fire2.wss",3.51189,1,3000};
		begin3[] = {"\x\acex\addons\s_wep_sniper\tac50_fire3.wss",3.51189,1,3000};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		reloadSound[] = {"\x\acex\addons\s_wep_sniper\ksvk_bolt.wss",0.1,1,20};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_sniper\ksvk_reload.wss",0.0316228,1,20};
		class Library
		{
			libTextDesc = "";
		};
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
	};
	class ACE_TAC50_SD: ACE_TAC50
	{
		ace_suppressed = 1;
		fireLightDuration = 0.0125;
		fireLightIntensity = 0.003;
		ace_weight = 14.95;
		dexterity = "(0.5 + 3.75/(11.8+ 1.08+ 2.07 + 0.001) + -3/10)";
		ACE_Size = 9000;
		ACE_NoPack = 1;
		displayName = "TAC-50 SD";
		model = "\x\acex\addons\m_wep_sniper\ace_tac50d_sd.p3d";
		picture = "\x\acex\addons\c_wep_sniper\i\w_tac50sd_ca.paa";
		magazines[] = {"ACE_5Rnd_127x99_S_TAC50","ACE_5Rnd_127x99_B_TAC50","ACE_5Rnd_127x99_T_TAC50"};
		handAnim[] = {};
		begin1[] = {"\x\acex\addons\s_wep_sniper\tac50sd_fire.wss",0.15,1.03,125};
		begin2[] = {"\x\acex\addons\s_wep_sniper\tac50sd_fire.wss",0.15,1,125};
		begin3[] = {"\x\acex\addons\s_wep_sniper\tac50sd_fire.wss",0.15,0.97,125};
		soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
	};
	class ACE_AS50: m107
	{
		class OpticsModes: OpticsModes
		{
			class StepScope: StepScope
			{
				memoryPointCamera = "eye";
			};
		};
		ace_bipod = 0;
		ace_weight = 14.52;
		dexterity = "(0.5 + 3.75/(13.8+ 0.72 + 0.001) + -3/10)";
		ACE_Size = 9000;
		ACE_NoPack = 1;
		scope = 2;
		displayName = "AS50";
		model = "\x\acex\addons\m_wep_sniper\ace_as50.p3d";
		picture = "\x\acex\addons\c_wep_sniper\i\w_as50_ca.paa";
		magazines[] = {"5Rnd_127x99_as50","ACE_5Rnd_127x99_B_TAC50","ACE_5Rnd_127x99_S_TAC50","ACE_5Rnd_127x99_T_TAC50"};
		handAnim[] = {};
		class Library
		{
			libTextDesc = "";
		};
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
	};
	class SVD: Rifle
	{
		model = "\x\acex\addons\m_wep_sniper\ace_svd.p3d";
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsPPEffects[] = {"OpticsCHAbera3","OpticsBlur3"};
				distanceZoomMax = 330;
				distanceZoomMin = 330;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				memoryPointCamera = "scope";
				visionMode[] = {"Normal"};
				cameraDir = "";
			};
			class Ironsights: Optics
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsPPEffects[] = {};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				memoryPointCamera = "eye";
				visionMode[] = {};
			};
		};
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
	};
	class ACE_SVD_Bipod: SVD
	{
		displayname = "SVD (bipod)";
		ace_weight = 4.5;
		dexterity = "(0.5 + 3.75/(3.7+ 0.6+ 0.2 + 0.001) + 0/10)";
		ace_bipod = 1;
		model = "\x\acex\addons\m_wep_sniper\ace_svd_bipod.p3d";
	};
	class SVD_CAMO: SVD
	{
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsPPEffects[] = {"OpticsCHAbera3","OpticsBlur3"};
				distanceZoomMax = 330;
				distanceZoomMin = 330;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				memoryPointCamera = "eye";
				visionMode[] = {"Normal"};
				cameraDir = "";
			};
		};
	};
	class SVD_des_EP1: SVD
	{
		class OpticsModes
		{
			class Optics
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				opticsPPEffects[] = {"OpticsCHAbera3","OpticsBlur3"};
				distanceZoomMax = 330;
				distanceZoomMin = 330;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				memoryPointCamera = "eye";
				visionMode[] = {"Normal"};
				cameraDir = "";
			};
		};
		class Armory
		{
			disabled = 0;
		};
	};
};
//};
