////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed Feb 08 15:20:32 2012 : Created on Wed Feb 08 15:20:32 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_g36 : config.bin{
class CfgPatches
{
	class acex_wep_g36
	{
		units[] = {};
		weapons[] = {"ACE_G36","ACE_G36_CQB","ACE_G36A1","ACE_G36A1_CQB","ACE_G36A1_D","ACE_G36A1_D_CQB","ACE_G36A2","ACE_G36A2_CQB","ACE_G36A2_Bipod","ACE_G36A2_Bipod_CQB","ACE_G36A2_Bipod_D","ACE_G36A2_Bipod_D_CQB","ACE_G36K","ACE_G36K_CQB","ACE_G36K_D","ACE_G36K_D_CQB","ACE_G36K_iron","ACE_G36K_iron_D","ACE_G36K_EOTech","ACE_G36K_EOTech_D","ACE_MG36A1","ACE_MG36A1_CQB","ACE_MG36A1_D","ACE_MG36A1_D_CQB","ACE_G36A1_AG36A1","ACE_G36A1_AG36A1_CQB","ACE_G36A1_AG36A1_D","ACE_G36A1_AG36A1_D_CQB"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons2","CAWeapons_E_G36","acex_main","acex_m_wep_g36","acex_t_wep_g36","ace_c_weapon"};
		version = "1.13.0.354";
		author[] = {"Aushilfe, Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_g36
		{
			list[] = {"acex_wep_g36"};
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class RifleCore;
	class Rifle: RifleCore
	{
		class M203Muzzle;
	};
	class G36C: Rifle
	{
		class Single;
		class FullAuto;
	};
	class G36a: Rifle
	{
		scope = 2;
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		picture = "\x\acex\addons\c_wep_g36\i\w_G36A1_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36A1.p3d";
		class MuzzleFar: G36C
		{
			displayName = "G36";
			class OpticsModes
			{
				class Scope
				{
					opticsID = 1;
					distanceZoomMin = 236;
					distanceZoomMax = 236;
					opticsZoomMin = 0.095903;
					opticsZoomMax = 0.095903;
					opticsZoomInit = 0.095903;
					opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
					useModelOptics = 1;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = 1;
					opticsDisablePeripherialVision = 1;
					cameraDir = "";
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
				class Kolimator: Scope
				{
					opticsID = 2;
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.1;
					opticsZoomInit = 0.5;
					opticsPPEffects[] = {};
					useModelOptics = 0;
					memoryPointCamera = "eye";
					visionMode[] = {};
					opticsFlare = 0;
					opticsDisablePeripherialVision = 0;
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
			};
			class Single;
			class Burst;
			class FullAuto;
		};
	};
	class G36A_camo: G36a
	{
		model = "\x\acex\addons\m_wep_g36\G36A1_D.p3d";
		picture = "\x\acex\addons\c_wep_g36\i\w_G36A1_D_ca.paa";
	};
	class G36K: G36a
	{
		scope = 2;
		htMin = 1;
		htMax = 480;
		afMax = 0;
		mfMax = 0;
		mFact = 1;
		tBody = 100;
		picture = "\x\acex\addons\c_wep_g36\i\w_G36K_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36K.p3d";
		class MuzzleFar: MuzzleFar
		{
			displayName = "G36K";
			class OpticsModes
			{
				class Scope
				{
					opticsID = 1;
					distanceZoomMin = 236;
					distanceZoomMax = 236;
					opticsZoomMin = 0.095903;
					opticsZoomMax = 0.095903;
					opticsZoomInit = 0.095903;
					opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
					useModelOptics = 1;
					memoryPointCamera = "opticView";
					visionMode[] = {"Normal"};
					opticsFlare = 1;
					opticsDisablePeripherialVision = 1;
					cameraDir = "";
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
				class Kolimator: Scope
				{
					opticsID = 2;
					distanceZoomMin = 300;
					distanceZoomMax = 300;
					opticsZoomMin = 0.25;
					opticsZoomMax = 1.1;
					opticsZoomInit = 0.5;
					opticsPPEffects[] = {};
					useModelOptics = 0;
					memoryPointCamera = "eye";
					visionMode[] = {};
					opticsFlare = 0;
					opticsDisablePeripherialVision = 0;
					discreteDistance[] = {};
					discreteDistanceInitIndex = 0;
					weaponInfoType = "RscWeaponEmpty";
				};
			};
			class Single;
		};
	};
	class G36K_camo: G36K
	{
		model = "\x\acex\addons\m_wep_g36\G36K_D.p3d";
		picture = "\x\acex\addons\c_wep_g36\i\w_G36K_D_ca.paa";
	};
	class MG36: G36C
	{
		displayName = "MG36 Holo";
	};
	class MG36_camo: MG36
	{
		displayName = "MG36 Holo";
	};
	class ACE_G36A2: G36A
	{
		displayName = "G36A2";
		model = "\x\acex\addons\m_wep_g36\G36A2.p3d";
		picture = "\x\acex\addons\c_wep_g36\i\w_ace_g36a2_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons_E\SCAR\Data\Anim\SCAR.rtm"};
		class MuzzleFar: MuzzleFar
		{
			displayName = "G36";
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		ace_weight = 3.9199998;
		dexterity = "(0.5 + 3.75/(3.6+ 0.1+ 0.22 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_G36A2","ACE_G36A2_F"};
	};
	class ACE_G36A2_F: ACE_G36A2
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_G36A2_D: ACE_G36A2
	{
		class Armory
		{
			disabled = 1;
		};
		class MuzzleFar: MuzzleFar
		{
			displayName = "G36";
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		ace_gunlight_classes[] = {"ACE_G36A2_D","ACE_G36A2_D_F"};
	};
	class ACE_G36A2_D_F: ACE_G36A2_D
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_G36A2_Bipod: G36a
	{
		ace_weight = 3.8;
		dexterity = "(0.5 + 3.75/(3.6+ 0.2 + 0.001) + 0/10)";
		displayName = "G36A2 Bipod";
		ace_bipod = 1;
		picture = "\x\acex\addons\c_wep_g36\i\w_ace_g36a2_bipod_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36A2_bipod.p3d";
		class MuzzleFar: MuzzleFar
		{
			class Single: Single
			{
				recoilProne = "ACE_556x45_MG_RecoilProne";
			};
			class Burst: Burst
			{
				recoilProne = "ACE_556x45_MG_RecoilProne";
			};
			class FullAuto: FullAuto
			{
				recoilProne = "ACE_556x45_MG_RecoilProne";
			};
		};
	};
	class ACE_G36A2_Bipod_D: ACE_G36A2_Bipod
	{
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_MG36: ACE_G36A2_Bipod
	{
		displayName = "MG36";
		model = "\x\acex\addons\m_wep_g36\MG36A1.p3d";
		picture = "\x\acex\addons\c_wep_g36\i\w_MG36A1_ca.paa";
		ace_cf = 1.2;
		ace_sys_weapons_type = 6;
		magazines[] = {"100Rnd_556x45_BetaCMag","ACE_100Rnd_556x45_S_BetaCMag","30Rnd_556x45_G36","ACE_30Rnd_556x45_S_G36","ACE_30Rnd_556x45_T_G36","30Rnd_556x45_G36SD","ACE_30Rnd_556x45_AP_G36"};
		class MuzzleFar: MuzzleFar
		{
			displayName = "MG36";
		};
	};
	class ACE_MG36_D: ACE_MG36
	{
		model = "\x\acex\addons\m_wep_g36\MG36A1_D.p3d";
		picture = "\x\acex\addons\c_wep_g36\i\w_MG36A1_D_ca.paa";
	};
	class ACE_G36K_iron: G36K
	{
		displayName = "G36K";
		picture = "\x\acex\addons\c_wep_g36\i\w_G36K_iron_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36K_rail.p3d";
		ace_sys_reticles_enable = 0;
		class MuzzleFar: MuzzleFar
		{
			class OpticsModes: OpticsModes
			{
				class Kolimator: Kolimator{};
			};
			class Single: Single
			{
				aiRateOfFire = 1;
				aiRateOfFireDistance = 550;
				minRange = 0;
				minRangeProbab = 0.7;
				midRange = 200;
				midRangeProbab = 0.5;
				maxRange = 500;
				maxRangeProbab = 0.1;
			};
		};
		ace_weight = 3;
		dexterity = "(0.5 + 3.75/(3 + 0.001) + 0/10)";
	};
	class ACE_G36K_iron_D: ACE_G36K_iron
	{
		displayName = "G36K";
		picture = "\x\acex\addons\c_wep_g36\i\w_G36K_iron_D_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36K_rail_D.p3d";
	};
	class ACE_G36K_EOTech: ACE_G36K_iron
	{
		displayName = "G36K Holo";
		picture = "\x\acex\addons\c_wep_g36\i\w_G36K_Eotech_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36K_EOT.p3d";
		ace_weight = 3.35;
		dexterity = "(0.5 + 3.75/(3+ 0.35 + 0.001) + 0/10)";
	};
	class ACE_G36K_EOTech_D: ACE_G36K_EOTech
	{
		picture = "\x\acex\addons\c_wep_g36\i\w_G36K_Eotech_D_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36K_EOT_D.p3d";
	};
	class ACE_G36A1_AG36A1: G36a
	{
		displayName = "G36A1 AG36";
		ace_weight = 5.3199997;
		dexterity = "(0.5 + 3.75/(3.6+ 1.5+ 0.22 + 0.001) + 0/10)";
		ace_gl_zero = 150;
		ace_gl_fineadj = -21;
		picture = "\x\acex\addons\c_wep_g36\i\w_G36A1_AG36A1_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36A1_AG36A1f.p3d";
		muzzles[] = {"MuzzleFar","m203muzzle","ACE_M203Muzzle_AI"};
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
			class Single: Single
			{
				recoil = "ACE_556x45_Rifle_Recoil_GL";
			};
			class Burst: Burst
			{
				recoil = "ACE_556x45_Rifle_Recoil_GL";
			};
			class FullAuto: FullAuto
			{
				recoil = "ACE_556x45_Rifle_Recoil_GL";
			};
		};
		class m203muzzle: m203muzzle
		{
			displayName = "AG36";
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_g36\Anim\XM8GL.rtm"};
		ace_gl_classes[] = {"ACE_G36A1_AG36A1","ACE_G36A1_AG36A1_UP"};
		ace_gunlight_classes[] = {"ACE_G36A1_AG36A1","ACE_G36A1_AG36A1_F"};
	};
	class ACE_G36A1_AG36A1_UP: ACE_G36A1_AG36A1
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_g36\G36A1_AG36A1.p3d";
		ace_gunlight_classes[] = {"ACE_G36A1_AG36A1_UP","ACE_G36A1_AG36_UP_F"};
	};
	class ACE_G36A1_AG36A1_F: ACE_G36A1_AG36A1
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class Armory
		{
			disabled = 1;
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		ace_gl_classes[] = {"ACE_G36A1_AG36A1_F","ACE_G36A1_AG36_UP_F"};
	};
	class ACE_G36A1_AG36_UP_F: ACE_G36A1_AG36A1_UP
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		ace_gl_classes[] = {"ACE_G36A1_AG36A1_F","ACE_G36A1_AG36_UP_F"};
	};
	class ACE_G36A1_AG36A1_D: ACE_G36A1_AG36A1
	{
		picture = "\x\acex\addons\c_wep_g36\i\w_G36A1_AG36A1_D_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36A1_AG36A1f_D.p3d";
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		ace_gl_classes[] = {"ACE_G36A1_AG36A1_D","ACE_G36A1_AG36A1_D_UP"};
		ace_gunlight_classes[] = {"ACE_G36A1_AG36A1_D","ACE_G36A1_AG36A1_D_F"};
	};
	class ACE_G36A1_AG36A1_D_UP: ACE_G36A1_AG36A1_D
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_g36\G36A1_AG36A1_D.p3d";
		ace_gunlight_classes[] = {"ACE_G36A1_AG36A1_D_UP","ACE_G36A1_AG36A1_D_UP_F"};
	};
	class ACE_G36A1_AG36A1_D_F: ACE_G36A1_AG36A1_D
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class Armory
		{
			disabled = 1;
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		ace_gl_classes[] = {"ACE_G36A1_AG36A1_D_F","ACE_G36A1_AG36A1_D_UP_F"};
	};
	class ACE_G36A1_AG36A1_D_UP_F: ACE_G36A1_AG36A1_D_UP
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		ace_gl_classes[] = {"ACE_G36A1_AG36A1_D_F","ACE_G36A1_AG36A1_D_UP_F"};
	};
	class ACE_G36A2_AG36A2: ACE_G36A1_AG36A1
	{
		displayName = "G36A2 AG36";
		picture = "\x\acex\addons\c_wep_g36\i\w_ace_g36a2_ag36a2_ca.paa";
		model = "\x\acex\addons\m_wep_g36\G36A2_AG36A2f.p3d";
		ace_gl_classes[] = {"ACE_G36A2_AG36A2","ACE_G36A2_AG36A2_UP"};
		ace_gunlight_classes[] = {"ACE_G36A2_AG36A2","ACE_G36A2_AG36A2_F"};
	};
	class ACE_G36A2_AG36A2_UP: ACE_G36A2_AG36A2
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_g36\G36A2_AG36A2.p3d";
		ace_gunlight_classes[] = {"ACE_G36A2_AG36A2_UP","ACE_G36A2_AG36A2_UP_F"};
	};
	class ACE_G36A2_AG36A2_F: ACE_G36A2_AG36A2
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class Armory
		{
			disabled = 1;
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		ace_gl_classes[] = {"ACE_G36A2_AG36A2_F","ACE_G36A2_AG36A2_UP_F"};
	};
	class ACE_G36A2_AG36A2_UP_F: ACE_G36A2_AG36A2_UP
	{
		class MuzzleFar: MuzzleFar
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 0;
			class FlashLight
			{
				color[] = {0.9,0.9,0.7,0.9};
				ambient[] = {0.1,0.1,0.1,1.0};
				position = "flash dir";
				direction = "flash";
				angle = 30;
				scale[] = {1,1,0.5};
				brightness = 0.1;
			};
		};
		ace_gl_classes[] = {"ACE_G36A2_AG36A2_F","ACE_G36A2_AG36A2_UP_F"};
	};
};
class CfgMagazines
{
	class 30Rnd_556x45_Stanag;
	class 30Rnd_556x45_G36: 30Rnd_556x45_Stanag
	{
		model = "\x\acex\addons\m_wep_g36\30Rnd_556x45_G36.p3d";
	};
};
//};
