////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Wed May 23 21:40:36 2012 : Created on Wed May 23 21:40:36 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_m16 : config.bin{
class CfgPatches
{
	class acex_wep_m16
	{
		units[] = {};
		weapons[] = {"ACE_M16A4_Iron","ACE_M16A4_CCO_GL","ACE_M4A1_Eotech","ACE_M4A1_Aim_SD","ACE_M4A1_ACOG_SD","ACE_M4A1_ACOG","ACE_M4A1_GL_SD","ACE_M4A1_GL","ACE_m16a2_scope","ACE_m16a2gl_scope","ACE_Mk12mod1","ACE_SOC_M4A1","ACE_SOC_M4A1_GL","ACE_SOC_M4A1_GL_13","ACE_SOC_M4A1_GL_EOTECH","ACE_SOC_M4A1_GL_AIMPOINT","ACE_SOC_M4A1_SHORTDOT","ACE_SOC_M4A1_TWS","ACE_SOC_M4A1_Eotech","ACE_SOC_M4A1_Eotech_4x","ACE_M4A1_RCO2_GL","ACE_M4A1_RCO_GL","ACE_SOC_M4A1_RCO_GL","ACE_SOC_M4A1_GL_SD","ACE_M4A1_AIM_GL_SD","ACE_SOC_M4A1_SHORTDOT_SD","ACE_SOC_M4A1_SD_9","ACE_SOC_M4A1_Aim","ACE_SOC_M4A1_AIM_SD"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons2","acex_main","acex_m_wep_m16","acex_m_wep_socom","acex_t_wep_m16","ace_c_weapon","ace_sys_attachments","ace_sys_stamina"};
		version = "1.13.0.363";
		author[] = {"Panda[pl]","zGuba","RobertHammer"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_m16
		{
			list[] = {"acex_wep_m16"};
		};
	};
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
	class M16_base;
	class M16A2: M16_base
	{
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		model = "\x\acex\addons\m_wep_m16\RH_M16A2.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_m16a2_ca.paa";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class Single;
	};
	class M16A2GL: M16A2
	{
		model = "\x\acex\addons\m_wep_m16\RH_M16A2glf.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_m16a2gl_ca.paa";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ace_gl_classes[] = {"M16A2GL","ACE_M16A2GL_UP"};
	};
	class ACE_M16A2GL_UP: M16A2GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\RH_M16A2gl.p3d";
	};
	class ACE_m16a2_scope: m16a2
	{
		displayName = "M16A2 Scope";
		model = "\x\acex\addons\m_wep_m16\RH_M16A2s.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_m16a2s_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_colt4X";
		class OpticsModes
		{
			class SCOPE4X
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: SCOPE4X
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
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		ace_weight = 4.17;
		dexterity = "(0.5 + 3.75/(3.77+ 0.4 + 0.001) + 0/10)";
	};
	class ACE_m16a2gl_scope: m16a2gl
	{
		displayName = "M16A2 M203 Scope";
		model = "\x\acex\addons\m_wep_m16\RH_M16A2sglf.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_m16a2sgl_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_optics_colt4X";
		class OpticsModes
		{
			class SCOPE4X
			{
				opticsID = 1;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: SCOPE4X
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
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		ace_weight = 5.47;
		dexterity = "(0.5 + 3.75/(3.77+ 1.3+ 0.4 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_m16a2gl_scope","ACE_m16a2gl_scope_UP"};
	};
	class ACE_m16a2gl_scope_UP: ACE_m16a2gl_scope
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\RH_M16A2sgl.p3d";
	};
	class m16a4: M16A2
	{
		displayName = "M16A4 CCO";
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		model = "x\acex\addons\m_wep_m16\six_M16A4_Aimpoint.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_aim_ca.paa";
		class Single;
		class Burst;
		class M203Muzzle;
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 4.0899997;
		dexterity = "(0.5 + 3.75/(3.54+ 0.35+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_M16A4_EOT: m16a4
	{
		displayName = "M16A4 EOT";
		model = "x\acex\addons\m_wep_m16\six_M16A4_EOTech.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_eot_ca.paa";
		ace_weight = 4.0899997;
		dexterity = "(0.5 + 3.75/(3.54+ 0.35+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_M16A4_Iron: m16a4
	{
		scope = 2;
		displayname = "M16A4";
		model = "\x\acex\addons\m_wep_m16\six_M16A4.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_iron_ca.paa";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 3.74;
		dexterity = "(0.5 + 3.75/(3.54+ 0.2 + 0.001) + 0/10)";
	};
	class m16a4_acg: m16a4
	{
		displayName = "M16A4 RCO";
		scope = 2;
		model = "\x\acex\addons\m_wep_m16\six_M16A4_ACOG.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_acog_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		class OpticsModes
		{
			class ACOG4X
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: ACOG4X
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 4.2;
		dexterity = "(0.5 + 3.75/(3.54+ 0.46+ 0.2 + 0.001) + 0/10)";
	};
	class M16A4_GL: m16a4
	{
		displayName = "M16A4 M203";
		scope = 2;
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203f.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_gl_ca.paa";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
		class Single: Single
		{
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		class Burst: Burst
		{
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		ace_weight = 5.04;
		dexterity = "(0.5 + 3.75/(3.54+ 1.3+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"M16A4_GL","ACE_M16A4_GL_UP"};
	};
	class ACE_M16A4_GL_UP: M16A4_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203.p3d";
	};
	class ACE_M16A4_CCO_GL: M16A4_GL
	{
		displayName = "M16A4 M203 CCO";
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203f_Aimpoint.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_gl_cco_ca.paa";
		ace_weight = 5.3899994;
		dexterity = "(0.5 + 3.75/(3.54+ 0.35+ 1.3+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_M16A4_CCO_GL","ACE_M16A4_CCO_GL_UP"};
	};
	class ACE_M16A4_CCO_GL_UP: ACE_M16A4_CCO_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203_Aimpoint.p3d";
	};
	class ACE_M16A4_EOT_GL: ACE_M16A4_CCO_GL
	{
		displayName = "M16A4 M203 EOT";
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203f_EOTech.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_gl_eot_ca.paa";
		ace_weight = 5.3899994;
		dexterity = "(0.5 + 3.75/(3.54+ 0.35+ 1.3+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_M16A4_EOT_GL","ACE_M16A4_EOT_GL_UP"};
	};
	class ACE_M16A4_EOT_GL_UP: ACE_M16A4_EOT_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203_EOTech.p3d";
	};
	class M16A4_ACG_GL: M16A4_GL
	{
		displayName = "M16A4 M203 RCO";
		scope = 2;
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203f_ACOG.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m16a4_gl_acg_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		class OpticsModes
		{
			class ACOG4X
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: ACOG4X
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
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 5.5;
		dexterity = "(0.5 + 3.75/(3.54+ 0.46+ 1.3+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"M16A4_ACG_GL","ACE_M16A4_ACG_GL_UP"};
	};
	class ACE_M16A4_ACG_GL_UP: M16A4_ACG_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\six_M16A4_203_ACOG.p3d";
	};
	class M4A1: M16_base
	{
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_ca.paa";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		class Single;
		class FullAuto;
		class M203Muzzle;
		ace_weight = 3.4;
		dexterity = "(0.5 + 3.75/(2.9+ 0.1+ 0.2+ 0.2 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"M4A1","ACE_M4A1_F"};
	};
	class ACE_M4A1_F: M4A1
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4A1_C: M4A1
	{
		handAnim[] = {};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		ace_weight = 2.9;
		dexterity = "(0.5 + 3.75/(2.9 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_m16\ACE_M4_C.p3d";
	};
	class ACE_SOC_M4A1: M4A1
	{
		displayname = "M4A1";
		model = "\x\acex\addons\m_wep_socom\SIX_M4.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_ca.paa";
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 3.2;
		dexterity = "(0.5 + 3.75/(2.9+ 0.1+ 0.2 + 0.001) + 1/10)";
	};
	class ACE_M4A1_GL: M4A1
	{
		displayname = "M4A1 M203";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203f.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_203_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
		class Single: Single
		{
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 150;
			midRangeProbab = 0.7;
			maxRange = 250;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "3 + round random 5";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "3 + round random 5";
		};
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		ace_weight = 4.5999994;
		dexterity = "(0.5 + 3.75/(2.9+ 1.3+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_M4A1_GL","ACE_M4A1_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4A1_GL","ACE_M4A1_GL_F"};
	};
	class ACE_M4A1_GL_UP: ACE_M4A1_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203.p3d";
		ace_gunlight_classes[] = {"ACE_M4A1_GL_UP","ACE_M4A1_GL_UP_F"};
	};
	class ACE_M4A1_GL_F: ACE_M4A1_GL
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
		ace_gl_classes[] = {"ACE_M4A1_GL_F","ACE_M4A1_GL_UP_F"};
	};
	class ACE_M4A1_GL_UP_F: ACE_M4A1_GL_UP
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
		ace_gl_classes[] = {"ACE_M4A1_GL_F","ACE_M4A1_GL_UP_F"};
	};
	class ACE_M4A1_AIM_GL: ACE_M4A1_GL
	{
		displayname = "M4A1 M203 CCO";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203f_Aimpoint.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_m4a1_m203_aim_ca";
		ace_weight = 4.95;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 1.3+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_M4A1_AIM_GL","ACE_M4A1_AIM_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4A1_AIM_GL","ACE_M4A1_AIM_GL_F"};
	};
	class ACE_M4A1_AIM_GL_UP: ACE_M4A1_AIM_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_Aimpoint.p3d";
		ace_gunlight_classes[] = {"ACE_M4A1_AIM_GL_UP","ACE_M4A1_AIM_GL_UP_F"};
	};
	class ACE_M4A1_AIM_GL_F: ACE_M4A1_AIM_GL
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
		ace_gl_classes[] = {"ACE_M4A1_AIM_GL_F","ACE_M4A1_AIM_GL_UP_F"};
	};
	class ACE_M4A1_AIM_GL_UP_F: ACE_M4A1_AIM_GL_UP
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
		ace_gl_classes[] = {"ACE_M4A1_AIM_GL_F","ACE_M4A1_AIM_GL_UP_F"};
	};
	class ACE_SOC_M4A1_GL: ACE_M4A1_GL
	{
		displayname = "M4A1 M203";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203f.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_m203_ca.paa";
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
		ace_weight = 4.3999996;
		dexterity = "(0.5 + 3.75/(2.9+ 1.3+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_SOC_M4A1_GL","ACE_SOC_M4A1_GL_UP"};
	};
	class ACE_SOC_M4A1_GL_UP: ACE_SOC_M4A1_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203.p3d";
	};
	class ACE_SOC_M4A1_GL_13: ACE_M4A1_GL
	{
		displayName = "M4A1 M203";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203_13in.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_m203_13in_ca.paa";
		ace_mv[] = {"B_556x45_Ball",830,"ACE_B_556x45_T",830,"ACE_B_556x45_SB",750,"ACE_B_556x45_S",830,"ACE_B_556x45_SB_S",750};
		ace_weight = 4.2;
		dexterity = "(0.5 + 3.75/(2.7+ 1.3+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_SOC_M4A1_GL_EOTECH: ACE_M4A1_GL
	{
		displayName = "M4A1 M203 Holo";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203_13in_eotech.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_m203_13in_eotech_ca.paa";
		ace_mv[] = {"B_556x45_Ball",830,"ACE_B_556x45_T",830,"ACE_B_556x45_SB",750,"ACE_B_556x45_S",830,"ACE_B_556x45_SB_S",750};
		ace_weight = 4.5499997;
		dexterity = "(0.5 + 3.75/(2.7+ 0.35+ 1.3+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_SOC_M4A1_GL_AIMPOINT: ACE_M4A1_GL
	{
		displayName = "M4A1 M203 microCCO";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203_13in_micro.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_m203_aim_ca.paa";
		ace_mv[] = {"B_556x45_Ball",830,"ACE_B_556x45_T",830,"ACE_B_556x45_SB",750,"ACE_B_556x45_S",830,"ACE_B_556x45_SB_S",750};
		ace_weight = 4.2999997;
		dexterity = "(0.5 + 3.75/(2.7+ 0.1+ 1.3+ 0.2 + 0.001) + 0/10)";
	};
	class ACE_M4A1_ACOG: M4A1
	{
		displayname = "M4A1 RCO";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_ACOG.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_acog_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		class OpticsModes
		{
			class ACOG4X
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: ACOG4X
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
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		ace_weight = 3.8600001;
		dexterity = "(0.5 + 3.75/(2.9+ 0.46+ 0.1+ 0.2+ 0.2 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_M4A1_ACOG","ACE_M4A1_ACOG_F"};
	};
	class ACE_M4A1_ACOG_F: ACE_M4A1_ACOG
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4A1_ACOG_PVS14: ACE_M4A1_ACOG
	{
		displayname = "M4A1 RCO PVS14";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_ACOG_PVS14.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_acog_pvs14_ca.paa";
		class OpticsModes
		{
			class ACOG_NV
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				memoryPointCamera = "opticView";
				visionMode[] = {"NVG"};
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				cameraDir = "";
			};
			class CQB: ACOG_NV
			{
				opticsID = 2;
				useModelOptics = 0;
				opticsFlare = 0;
				opticsDisablePeripherialVision = 0;
				opticsPPEffects[] = {};
				opticsZoomMin = 0.25;
				opticsZoomMax = 1.1;
				opticsZoomInit = 0.5;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "eye";
				visionMode[] = {};
			};
		};
		ace_weight = 4.2599998;
		dexterity = "(0.5 + 3.75/(2.9+ 0.46+ 0.4+ 0.1+ 0.2+ 0.2 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_M4A1_ACOG_PVS14","ACE_M4A1_ACOG_PVS14_F"};
	};
	class ACE_M4A1_ACOG_PVS14_F: ACE_M4A1_ACOG_PVS14
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_SHORTDOT: ACE_M4A1_ACOG
	{
		displayName = "M4A1 Shortdot";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_shortdot.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_shortdot_ca.paa";
		modelOptics = "\x\ace\addons\m_wep_optics\SB_CQB_optic_4x";
		class OpticsModes
		{
			class Shortdot
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.22;
				opticsZoomInit = 0.22;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: Shortdot
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
		ace_weight = 4.12;
		dexterity = "(0.5 + 3.75/(2.9+ 0.72+ 0.1+ 0.2+ 0.2 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_SHORTDOT","ACE_SOC_M4A1_SHORTDOT_F"};
	};
	class ACE_SOC_M4A1_SHORTDOT_F: ACE_SOC_M4A1_SHORTDOT
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_TWS: ACE_M4A1_ACOG
	{
		displayName = "M4A1 TWS";
		model = "\x\acex\addons\m_wep_socom\ACE_M4_TWS.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_tws_ca.paa";
		modelOptics = "\Ca\weapons_E\LWTS_optic.p3d";
		class OpticsModes
		{
			class LTWS
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsZoomMin = 0.1606;
				opticsZoomMax = 0.1606;
				opticsZoomInit = 0.1606;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "eye";
				opticsFlare = 1;
				opticsDisablePeripherialVision = 1;
				cameraDir = "";
				opticsPPEffects[] = {};
				visionMode[] = {"Ti"};
				thermalMode[] = {0,1};
			};
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
		ace_weight = 4.2999997;
		dexterity = "(0.5 + 3.75/(2.9+ 0.9+ 0.1+ 0.2+ 0.2 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_TWS","ACE_SOC_M4A1_TWS_F"};
		ace_sys_nvg_tirange = 1050;
	};
	class ACE_SOC_M4A1_TWS_F: ACE_SOC_M4A1_TWS
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
		class Armory
		{
			disabled = 1;
		};
	};
	class M4A1_Aim: M4A1
	{
		scope = 2;
		model = "\x\acex\addons\m_wep_m16\SIX_M4_Aimpoint.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_aimpoint_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		ace_weight = 3.75;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 0.1+ 0.2+ 0.2 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"M4A1_Aim","ACE_M4A1_Aim_F"};
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
	};
	class ACE_M4A1_Aim_F: M4A1_Aim
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4A1_Eotech: M4A1_Aim
	{
		displayname = "M4A1 Holo";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_eotech.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_eotech_ca.paa";
		ace_weight = 3.75;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 0.1+ 0.2+ 0.2 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_M4A1_Eotech","ACE_M4A1_Eotech_F"};
	};
	class ACE_M4A1_Eotech_F: ACE_M4A1_Eotech
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_Eotech: ACE_M4A1_Eotech
	{
		displayname = "M4A1 Holo SOCOM";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_eotech.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_eotech_ca.paa";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_Eotech","ACE_SOC_M4A1_Eotech_F"};
	};
	class ACE_SOC_M4A1_Eotech_F: ACE_SOC_M4A1_Eotech
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_Eotech_4x: ACE_M4A1_ACOG
	{
		displayName = "M4A1 Holo 4x";
		model = "\x\acex\addons\m_wep_socom\ACE_M4_eotech_magnified_cqb.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_eotech4x_ca.paa";
		modelOptics = "\x\acex\addons\m_wep_socom\ACE_Eotech_magn_optic_4x.p3d";
		class OpticsModes
		{
			class EOTech4x
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: EOTech4x
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
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		ace_weight = 4.09;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 0.1+ 0.2+ 0.2+ 0.34 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_Eotech_4x","ACE_SOC_M4A1_Eotech_4x_F"};
	};
	class ACE_SOC_M4A1_Eotech_4x_F: ACE_SOC_M4A1_Eotech_4x
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
		class Armory
		{
			disabled = 1;
		};
	};
	class M4A1_RCO_GL: M4A1
	{
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
	};
	class ACE_M4A1_RCO2_GL: ACE_M4A1_GL
	{
		displayName = "M4A1 M203 RCO";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203f_ACOG.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_203_acog_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		class OpticsModes
		{
			class ACOG4X
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: ACOG4X
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
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		ace_weight = 5.0599995;
		dexterity = "(0.5 + 3.75/(2.9+ 0.46+ 1.3+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_M4A1_RCO2_GL","ACE_M4A1_RCO2_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4A1_RCO2_GL","ACE_M4A1_RCO2_GL_F"};
	};
	class ACE_M4A1_RCO2_GL_F: ACE_M4A1_RCO2_GL
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
		ace_gl_classes[] = {"ACE_M4A1_RCO2_GL_F","ACE_M4A1_RCO2_GL_UP_F"};
	};
	class ACE_M4A1_RCO2_GL_UP: ACE_M4A1_RCO2_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_ACOG.p3d";
		ace_gunlight_classes[] = {"ACE_M4A1_RCO2_GL_UP","ACE_M4A1_RCO2_GL_UP_F"};
	};
	class ACE_M4A1_RCO2_GL_UP_F: ACE_M4A1_RCO2_GL_UP
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
		ace_gl_classes[] = {"ACE_M4A1_RCO2_GL_F","ACE_M4A1_RCO2_GL_UP_F"};
	};
	class ACE_M4A1_RCO_GL: ACE_M4A1_RCO2_GL
	{
		class Armory
		{
			disabled = 1;
		};
		ace_gl_classes[] = {"ACE_M4A1_RCO_GL","ACE_M4A1_RCO2_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4A1_RCO_GL","ACE_M4A1_RCO2_GL_F"};
	};
	class ACE_SOC_M4A1_RCO_GL: ACE_M4A1_RCO_GL
	{
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203f_ACOG.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_m203_aocg_ca.paa";
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		ace_gl_classes[] = {"ACE_SOC_M4A1_RCO_GL","ACE_SOC_M4A1_RCO_GL_UP"};
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_RCO_GL","ACE_SOC_M4A1_RCO_GL_F"};
	};
	class ACE_SOC_M4A1_RCO_GL_F: ACE_SOC_M4A1_RCO_GL
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
		ace_gl_classes[] = {"ACE_SOC_M4A1_RCO_GL_F","ACE_SOC_M4A1_RCO_GL_UP_F"};
	};
	class ACE_SOC_M4A1_RCO_GL_UP: ACE_SOC_M4A1_RCO_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203_ACOG.p3d";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_RCO_GL_UP","ACE_SOC_M4A1_RCO_GL_UP_F"};
	};
	class ACE_SOC_M4A1_RCO_GL_UP_F: ACE_SOC_M4A1_RCO_GL_UP
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
		ace_gl_classes[] = {"ACE_SOC_M4A1_RCO_GL_F","ACE_SOC_M4A1_RCO_GL_UP_F"};
	};
	class M4A1_AIM_SD_camo: M4A1_Aim
	{
		class Single;
		class FullAuto;
		handAnim[] = {};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4A1_GL_SD: M4A1_AIM_SD_camo
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		displayname = "M4A1 M203 SD";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203f_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_203_sd_ca.paa";
		muzzles[] = {"this","M203Muzzle","ACE_M203Muzzle_AI"};
		class Single: Single
		{
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		class FullAuto: FullAuto
		{
			recoil = "ACE_556x45_Rifle_Recoil_GL";
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		descriptionShort = "$STR_DSS_M4A1_HWS_GL_SD_CAMO";
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
		ace_weight = 5.1999993;
		dexterity = "(0.5 + 3.75/(2.9+ 1.3+ 0.2+ 0.2+ 0.6 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_M4A1_GL_SD","ACE_M4A1_GL_SD_UP"};
		ace_gunlight_classes[] = {"ACE_M4A1_GL_SD","ACE_M4A1_GL_SD_F"};
	};
	class ACE_M4A1_GL_SD_F: ACE_M4A1_GL_SD
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
		ace_gl_classes[] = {"ACE_M4A1_GL_SD_F","ACE_M4A1_GL_SD_UP_F"};
	};
	class ACE_M4A1_GL_SD_UP: ACE_M4A1_GL_SD
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_SD.p3d";
		ace_gunlight_classes[] = {"ACE_M4A1_GL_SD_UP","ACE_M4A1_GL_SD_UP_F"};
	};
	class ACE_M4A1_GL_SD_UP_F: ACE_M4A1_GL_SD_UP
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
		ace_gl_classes[] = {"ACE_M4A1_GL_SD_F","ACE_M4A1_GL_SD_UP_F"};
	};
	class ACE_SOC_M4A1_GL_SD: ACE_M4A1_GL_SD
	{
		displayname = "M4A1 M203 SD";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203f_SD.p3d";
		descriptionShort = "$STR_DSS_M4A1_HWS_GL_SD_CAMO";
		ace_gl_classes[] = {"ACE_SOC_M4A1_GL_SD","ACE_SOC_M4A1_GL_SD_UP"};
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_GL_SD","ACE_SOC_M4A1_GL_SD_F"};
	};
	class ACE_SOC_M4A1_GL_SD_F: ACE_SOC_M4A1_GL_SD
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
		ace_gl_classes[] = {"ACE_SOC_M4A1_GL_SD_F","ACE_SOC_M4A1_GL_SD_UP_F"};
	};
	class ACE_SOC_M4A1_GL_SD_UP: ACE_SOC_M4A1_GL_SD
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203_SD.p3d";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_GL_SD_UP","ACE_SOC_M4A1_GL_SD_UP_F"};
	};
	class ACE_SOC_M4A1_GL_SD_UP_F: ACE_SOC_M4A1_GL_SD_UP
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
		ace_gl_classes[] = {"ACE_SOC_M4A1_GL_SD_F","ACE_SOC_M4A1_GL_SD_UP_F"};
	};
	class ACE_M4A1_AIM_GL_SD: ACE_M4A1_GL_SD
	{
		displayName = "M4A1 M203 CCO SD";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203f_Aimpoint_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_m4a1_m203_aim_sd_ca.paa";
		ace_weight = 5.5499997;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 1.3+ 0.2+ 0.2+ 0.6 + 0.001) + 0/10)";
		ace_gl_classes[] = {"ACE_M4A1_AIM_GL_SD","ACE_M4A1_AIM_GL_SD_UP"};
		ace_gunlight_classes[] = {"ACE_M4A1_AIM_GL_SD","ACE_M4A1_AIM_GL_SD_F"};
	};
	class ACE_M4A1_AIM_GL_SD_F: ACE_M4A1_AIM_GL_SD
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
		ace_gl_classes[] = {"ACE_M4A1_AIM_GL_SD_F","ACE_M4A1_AIM_GL_SD_UP_F"};
	};
	class ACE_M4A1_AIM_GL_SD_UP: ACE_M4A1_AIM_GL_SD
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_Aimpoint_SD.p3d";
		ace_gunlight_classes[] = {"ACE_M4A1_AIM_GL_SD_UP","ACE_M4A1_AIM_GL_SD_UP_F"};
	};
	class ACE_M4A1_AIM_GL_SD_UP_F: ACE_M4A1_AIM_GL_SD_UP
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
		ace_gl_classes[] = {"ACE_M4A1_AIM_GL_SD_F","ACE_M4A1_AIM_GL_SD_UP_F"};
	};
	class ACE_M4A1_ACOG_SD: M4A1_AIM_SD_camo
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		displayname = "M4A1 RCO SD";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_ACOG_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_acog_sd_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		modelOptics = "\x\ace\addons\m_wep_optics\ACE_acog_ta31rco";
		class OpticsModes
		{
			class ACOG4X
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.071945;
				opticsZoomInit = 0.071945;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: ACOG4X
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
		descriptionShort = "$STR_DSS_M4A1_AIM_SD_CAMO";
		class Single: Single
		{
			aiRateOfFire = 2;
			aiRateOfFireDistance = 800;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 200;
			midRangeProbab = 0.6;
			maxRange = 650;
			maxRangeProbab = 0.1;
		};
		ace_weight = 4.46;
		dexterity = "(0.5 + 3.75/(2.9+ 0.46+ 0.1+ 0.2+ 0.2+ 0.6 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_M4A1_ACOG_SD","ACE_M4A1_ACOG_SD_F"};
	};
	class ACE_M4A1_ACOG_SD_F: ACE_M4A1_ACOG_SD
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_SHORTDOT_SD: ACE_M4A1_ACOG_SD
	{
		displayName = "M4A1 Shortdot SD";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_shortdot_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_shortdot_sd_ca.paa";
		descriptionShort = "$STR_DSS_M4A1_AIM_SD_CAMO";
		modelOptics = "\x\ace\addons\m_wep_optics\SB_CQB_optic_4x";
		class OpticsModes
		{
			class Shortdot
			{
				opticsID = 1;
				distanceZoomMin = 189;
				distanceZoomMax = 189;
				opticsZoomMin = 0.071945;
				opticsZoomMax = 0.22;
				opticsZoomInit = 0.22;
				opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
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
			class CQB: Shortdot
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
		ace_weight = 4.72;
		dexterity = "(0.5 + 3.75/(2.9+ 0.72+ 0.1+ 0.2+ 0.2+ 0.6 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_SHORTDOT_SD","ACE_SOC_M4A1_SHORTDOT_SD_F"};
	};
	class ACE_SOC_M4A1_SHORTDOT_SD_F: ACE_SOC_M4A1_SHORTDOT_SD
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4A1_Aim_SD: M4A1_AIM_SD_camo
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		displayname = "M4A1 CCO SD";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_Aimpoint_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_aimpoint_sd_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		descriptionShort = "$STR_DSS_M4A1_AIM_SD_CAMO";
		ace_weight = 4.35;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 0.1+ 0.2+ 0.2+ 0.6 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_M4A1_Aim_SD","ACE_M4A1_Aim_SD_F"};
	};
	class ACE_M4A1_Aim_SD_F: ACE_M4A1_Aim_SD
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4A1_EOT_SD: ACE_M4A1_Aim_SD
	{
		displayname = "M4A1 EOT SD";
		model = "\x\acex\addons\m_wep_m16\SIX_M4_EOTech_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_eotech_sd_ca.paa";
		ace_weight = 4.35;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 0.1+ 0.2+ 0.2+ 0.6 + 0.001) + 1/10)";
		ace_gunlight_classes[] = {"ACE_M4A1_EOT_SD","ACE_M4A1_EOT_SD_F"};
	};
	class ACE_M4A1_EOT_SD_F: ACE_M4A1_EOT_SD
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_EOT_SD: ACE_M4A1_EOT_SD
	{
		model = "\x\acex\addons\m_wep_socom\SIX_M4_EOTech_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_eotech_sd_ca.paa";
		ace_gunlight_classes[] = {"ACE_SOC_M4A1_EOT_SD","ACE_SOC_M4A1_EOT_SD_F"};
	};
	class ACE_SOC_M4A1_EOT_SD_F: ACE_SOC_M4A1_EOT_SD
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_SD_9: ACE_M4A1_Aim_SD
	{
		displayName = "M4A1 SD 9in";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_sd_9in.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_sd_9in_ca.paa";
		ace_mv[] = {"ACE_B_556x45_S",750,"ACE_B_556x45_SB_S",690,"ACE_B_556x45_T",750,"B_556x45_Ball",750,"ACE_B_556x45_SB",690};
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		descriptionShort = "$STR_DSS_M4A1_AIM_SD_CAMO";
		class Single: Single
		{
			dispersion = 0.0025;
			aiRateOfFire = 1;
			aiRateOfFireDistance = 400;
			minRange = 0;
			minRangeProbab = 0.7;
			midRange = 150;
			midRangeProbab = 0.5;
			maxRange = 400;
			maxRangeProbab = 0.1;
		};
		class FullAuto: FullAuto
		{
			dispersion = 0.0025;
			aiRateOfFire = 0.1;
			aiRateOfFireDistance = 50;
			minRange = 0;
			minRangeProbab = 0.9;
			midRange = 60;
			midRangeProbab = 0.7;
			maxRange = 120;
			maxRangeProbab = 0.1;
		};
		class ACE_Burst: Single
		{
			aiRateOfFire = 1;
			aiRateOfFireDistance = 200;
			minRange = 0;
			minRangeProbab = 0.8;
			midRange = 40;
			midRangeProbab = 0.7;
			maxRange = 80;
			maxRangeProbab = 0.1;
			displayName = "$STR_DN_MODE_BURST";
			burst = 3;
			soundBurst = 0;
		};
		class ACE_Burst_AI: ACE_Burst
		{
			burst = "2 + round random 3";
			showtoplayer = 0;
		};
		class ACE_Burst_AI2: ACE_Burst_AI
		{
			burst = "2 + round random 3";
		};
		modes[] = {"Single","FullAuto","ACE_Burst_AI","ACE_Burst_AI2"};
		ace_weight = 3.1999998;
		dexterity = "(0.5 + 3.75/(2.3+ 0.1+ 0.2+ 0.6 + 0.001) + 1/10)";
	};
	class M4SPR: M4A1
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		displayName = "Mk12 Mod 0";
		handAnim[] = {};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		model = "\x\acex\addons\m_wep_m16\RH_MK12.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_mk12_ca.paa";
	};
	class ACE_Mk12mod1: M4SPR
	{
		displayName = "Mk12 Mod 1";
		model = "\x\acex\addons\m_wep_m16\RH_MK12mod1.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_mk12mod1_ca.paa";
	};
	class ACE_M4SPR_SD: M4SPR
	{
		displayName = "Mk12 Mod 0 SD";
		picture = "\x\acex\addons\c_wep_m16\i\w_mk12sd_ca.paa";
		model = "\x\acex\addons\m_wep_m16\rh_mk12sd";
		class Single: Single
		{
			begin1[] = {"\x\acex\addons\s_wep_m16\m4sd_fire.wss",0.1,1,80};
			begin2[] = {"\x\acex\addons\s_wep_m16\m4sd_fire.wss",0.1,1.03,80};
			begin3[] = {"\x\acex\addons\s_wep_m16\m4sd_fire.wss",0.1,1.01,80};
			soundBegin[] = {"begin1",0.33,"begin2",0.33,"begin3",0.33};
		};
		ace_suppressed = 1;
		fireLightDuration = 0;
		fireLightIntensity = 0;
		ace_weight = 4.6;
		dexterity = "(0.5 + 3.75/(4+ 0.6 + 0.001) + 0/10)";
	};
	class ACE_Mk12mod1_SD: ACE_M4SPR_SD
	{
		displayName = "Mk12 Mod 1 SD";
		picture = "\x\acex\addons\c_wep_m16\i\w_mk12mod1sd_ca.paa";
		model = "\x\acex\addons\m_wep_m16\rh_mk12mod1sd";
	};
	class M4A1_Aim_camo: M4A1_Aim
	{
		handAnim[] = {};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_SOC_M4A1_Aim: M4A1_Aim_camo
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		displayName = "M4A1 microCCO";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_Aimpoint.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_aim_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 3.3;
		dexterity = "(0.5 + 3.75/(2.9+ 0.1+ 0.1+ 0.2 + 0.001) + 1/10)";
	};
	class ACE_SOC_M4A1_AIM_SD: M4A1_AIM_SD_camo
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		displayname = "M4A1 microCCO SD";
		model = "\x\acex\addons\m_wep_socom\SIX_M4_Aimpoint_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_aim_sd_ca.paa";
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_m16\Anim\rocko_M4_Grip.rtm"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		ace_weight = 3.9;
		dexterity = "(0.5 + 3.75/(2.9+ 0.1+ 0.1+ 0.2+ 0.6 + 0.001) + 1/10)";
	};
	class M4A1_HWS_GL: M4A1_RCO_GL
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		ace_gl_fineadj = 17;
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203f_Eotech.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\w_ace_m4_203_eotech.paa";
		ace_weight = 4.95;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 1.3+ 0.2+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"M4A1_HWS_GL","ACE_M4A1_HWS_GL_UP"};
		ace_gunlight_classes[] = {"M4A1_HWS_GL","ACE_M4A1_HWS_GL_F"};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 300;
		class M203Muzzle: M203Muzzle
		{
			irLaserPos = "laser pos";
			irLaserEnd = "laser dir";
			irDistance = 300;
		};
	};
	class ACE_M4A1_HWS_GL_UP: M4A1_HWS_GL
	{
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_Eotech.p3d";
		class Armory
		{
			disabled = 1;
		};
		ace_gunlight_classes[] = {"ACE_M4A1_HWS_GL_UP","ACE_M4A1_HWS_GL_UP_F"};
	};
	class ACE_M4A1_HWS_GL_F: M4A1_HWS_GL
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
		class Armory
		{
			disabled = 1;
		};
		ace_gl_classes[] = {"ACE_M4A1_HWS_GL_F","ACE_M4A1_HWS_GL_UP_F"};
	};
	class ACE_M4A1_HWS_GL_UP_F: ACE_M4A1_HWS_GL_UP
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
		ace_gl_classes[] = {"ACE_M4A1_HWS_GL_F","ACE_M4A1_HWS_GL_UP_F"};
	};
	class M4A1_HWS_GL_camo: M4A1_HWS_GL
	{
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203f_Eotech.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_203_eotech.paa";
		ace_weight = 4.75;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 1.3+ 0.2 + 0.001) + 0/10)";
		ace_gl_classes[] = {"M4A1_HWS_GL_camo","ACE_M4A1_HWS_GL_camo_UP"};
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
	};
	class ACE_M4A1_HWS_GL_camo_UP: M4A1_HWS_GL_camo
	{
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203_Eotech.p3d";
		class Armory
		{
			disabled = 1;
		};
	};
	class M4A1_HWS_GL_SD_Camo: M4A1_AIM_SD_camo
	{
		scope = 2;
		class Armory
		{
			disabled = 0;
			author = "A.C.E.";
		};
		ace_gl_fineadj = 17;
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203f_Eotech_SD.p3d";
		picture = "\x\acex\addons\c_wep_m16\i\socom\w_ace_m4_203_eotech_sd.paa";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\M16GL.rtm"};
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
		ace_weight = 5.35;
		dexterity = "(0.5 + 3.75/(2.9+ 0.35+ 1.3+ 0.2+ 0.6 + 0.001) + 0/10)";
		ace_gl_classes[] = {"M4A1_HWS_GL_SD_Camo","ACE_M4A1_HWS_GL_SD_Camo_UP"};
	};
	class ACE_M4A1_HWS_GL_SD_Camo_UP: M4A1_HWS_GL_SD_Camo
	{
		model = "\x\acex\addons\m_wep_socom\SIX_M4_203_Eotech_SD.p3d";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4: M4A1
	{
		displayname = "M4";
		modes[] = {"Single","ACE_Burst"};
		ace_gunlight_classes[] = {"ACE_M4","ACE_M4_F"};
	};
	class ACE_M4_F: ACE_M4
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4_Aim: M4A1_Aim
	{
		displayname = "M4 CCO";
		modes[] = {"Single","ACE_Burst"};
		ace_gunlight_classes[] = {"ACE_M4_Aim","ACE_M4_Aim_F"};
	};
	class ACE_M4_Aim_F: ACE_M4_Aim
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4_Eotech: ACE_M4A1_Eotech
	{
		displayname = "M4 Holo";
		modes[] = {"Single","ACE_Burst"};
		ace_gunlight_classes[] = {"ACE_M4_Eotech","ACE_M4_Eotech_F"};
	};
	class ACE_M4_Eotech_F: ACE_M4_Eotech
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4_ACOG: ACE_M4A1_ACOG
	{
		displayname = "M4 RCO";
		modes[] = {"Single","ACE_Burst"};
		ace_gunlight_classes[] = {"ACE_M4_ACOG","ACE_M4_ACOG_F"};
	};
	class ACE_M4_ACOG_F: ACE_M4_ACOG
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4_ACOG_PVS14: ACE_M4A1_ACOG_PVS14
	{
		displayname = "M4 RCO PVS14";
		modes[] = {"Single","ACE_Burst"};
		ace_gunlight_classes[] = {"ACE_M4_ACOG_PVS14","ACE_M4_ACOG_PVS14_F"};
	};
	class ACE_M4_ACOG_PVS14_F: ACE_M4_ACOG_PVS14
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
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M4_GL: ACE_M4A1_GL
	{
		displayname = "M4 M203";
		modes[] = {"Single","ACE_Burst"};
		ace_gl_classes[] = {"ACE_M4_GL","ACE_M4_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4_GL","ACE_M4_GL_F"};
	};
	class ACE_M4_GL_F: ACE_M4_GL
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
		ace_gl_classes[] = {"ACE_M4_GL_F","ACE_M4_GL_UP_F"};
	};
	class ACE_M4_GL_UP: ACE_M4_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203.p3d";
		ace_gunlight_classes[] = {"ACE_M4_GL_UP","ACE_M4_GL_UP_F"};
	};
	class ACE_M4_GL_UP_F: ACE_M4_GL_UP
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
		ace_gl_classes[] = {"ACE_M4_GL_F","ACE_M4_GL_UP_F"};
	};
	class ACE_M4_AIM_GL: ACE_M4A1_AIM_GL
	{
		displayname = "M4 M203 CCO";
		modes[] = {"Single","ACE_Burst"};
		ace_gl_classes[] = {"ACE_M4_AIM_GL","ACE_M4_AIM_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4_AIM_GL","ACE_M4_AIM_GL_F"};
	};
	class ACE_M4_AIM_GL_F: ACE_M4_AIM_GL
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
		ace_gl_classes[] = {"ACE_M4_AIM_GL_F","ACE_M4_AIM_GL_UP_F"};
	};
	class ACE_M4_AIM_GL_UP: ACE_M4_AIM_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_Aimpoint.p3d";
		ace_gunlight_classes[] = {"ACE_M4_AIM_GL_UP","ACE_M4_AIM_GL_UP_F"};
	};
	class ACE_M4_AIM_GL_UP_F: ACE_M4_AIM_GL_UP
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
		ace_gl_classes[] = {"ACE_M4_AIM_GL_F","ACE_M4_AIM_GL_UP_F"};
	};
	class ACE_M4_RCO_GL: ACE_M4A1_RCO2_GL
	{
		displayname = "M4 M203 RCO";
		modes[] = {"Single","ACE_Burst"};
		ace_gl_classes[] = {"ACE_M4_RCO_GL","ACE_M4_RCO_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4_RCO_GL","ACE_M4_RCO_GL_F"};
	};
	class ACE_M4_RCO_GL_F: ACE_M4_RCO_GL
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
		ace_gl_classes[] = {"ACE_M4_RCO_GL_F","ACE_M4_RCO_GL_UP_F"};
	};
	class ACE_M4_RCO_GL_UP: ACE_M4_RCO_GL
	{
		class Armory
		{
			disabled = 1;
		};
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_ACOG.p3d";
		ace_gunlight_classes[] = {"ACE_M4_RCO_GL_UP","ACE_M4_RCO_GL_UP_F"};
	};
	class ACE_M4_RCO_GL_UP_F: ACE_M4_RCO_GL_UP
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
		ace_gl_classes[] = {"ACE_M4_RCO_GL_F","ACE_M4_RCO_GL_UP_F"};
	};
	class ACE_M4_Eotech_GL: M4A1_HWS_GL
	{
		displayName = "M4 M203 Holo";
		modes[] = {"Single","ACE_Burst"};
		ace_gl_classes[] = {"ACE_M4_Eotech_GL","ACE_M4_Eotech_GL_UP"};
		ace_gunlight_classes[] = {"ACE_M4_Eotech_GL","ACE_M4_Eotech_GL_F"};
	};
	class ACE_M4_Eotech_GL_UP: ACE_M4_Eotech_GL
	{
		model = "\x\acex\addons\m_wep_m16\SIX_M4_203_Eotech.p3d";
		class Armory
		{
			disabled = 1;
		};
		ace_gunlight_classes[] = {"ACE_M4_Eotech_GL_UP","ACE_M4_Eotech_GL_UP_F"};
	};
	class ACE_M4_Eotech_GL_F: ACE_M4_Eotech_GL
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
		class Armory
		{
			disabled = 1;
		};
		ace_gl_classes[] = {"ACE_M4_Eotech_GL_F","ACE_M4_Eotech_GL_UP_F"};
	};
	class ACE_M4_Eotech_GL_UP_F: ACE_M4_Eotech_GL_UP
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
		ace_gl_classes[] = {"ACE_M4_Eotech_GL_F","ACE_M4_Eotech_GL_UP_F"};
	};
};
//};
