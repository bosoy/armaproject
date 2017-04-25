////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon May 11 19:00:27 2015 : Created on Mon May 11 19:00:27 2015
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_explosives : config.bin{
class CfgPatches
{
	class ace_sys_explosives
	{
		units[] = {"ACE_Explosive_Object","ACE_Pipebomb","ACE_Mine","ACE_Mine_Editor","ACE_MineE","ACE_MineE_Editor","ACE_Claymore","ACE_Claymore_Editor","ACE_M18_Editor","ACE_MON50","ACE_MON50_Editor","ACE_C4","ACE_DM12B1","ACE_PMN1","ACE_PMN1_Editor","ACE_PMN2","ACE_PMN2_Editor","ACE_PMN3","ACE_PMN3Editor","ACE_PPM2","ACE_PPM2_Editor","ACE_DM31AT","ACE_DM31AT_Editor","ACE_Pomz","ACE_Pomz_Editor","ACE_TripFlare","ACE_TripFlare_Editor","ACE_M49_Editor","ACE_DM16","ACE_DM16_Editor","ACE_BBetty_burried","ACE_BBetty_burried_Editor","ACE_M16_Editor","ACE_SchMiDM31","ACE_SchMiDM31_burried","ACE_SchMiDM31_burried_Editor","ACE_SchMiDM31_Editor","ACE_M2SLAM","ACE_M4SLAM","ACE_DM12PARM1","ACE_M86PDM_Object","ACE_Explosive_Helper","ACE_Clacker","ACE_Stake","ACE_BreachObject","ACE_M16","ACE_OSM4","ACE_OSM4_Editor","ACE_M18","ACE_M49","ACE_DM21AT","ACE_DM21AT_Editor","ACE_Land_IED_v1_PMC","ACE_Land_IED_v2_PMC","ACE_Land_IED_v3_PMC","ACE_Land_IED_v4_PMC","MineMine","MineMineE","ACE_Tripwire","ACE_Zundmaschine","ACE_pileOfGravel","ACE_pileOfGrass","ACE_pileOfSand","ACE_pileOfRocks","ACE_pileOfPiles","ACE_OSM4_burried_Editor"};
		weapons[] = {"ACE_Cellphone"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons_E","ace_c_weapon","ace_main","ace_sys_interaction"};
		version = "1.14.0.595";
		author[] = {"Rocko","q1184"};
		magazines[] = {"ACE_CLAYMORE_M","ACE_MON50_M","ACE_POMZ_M","ACE_TRIPFLARE_M","ACE_DM16_M","ACE_BBETTY_M","ACE_DM31_M","ACE_OSM4_M","ACE_M2SLAM_M","ACE_M4SLAM_M","ACE_C4_M","ACE_DM12B1_M","ACE_DM12PARM1_M","ACE_PMN1_M","ACE_PMN2_M","ACE_PMN3_M","ACE_PPM2_M"};
		ammo[] = {"ACE_DummyAmmo_Explosives","ACE_B_BallBearing","ACE_B_BallBearing_Test","GrenadeHand","ACE_Explosion","ACE_C4Explosion","ACE_ClaymoreExplosion","ACE_SLAMBottomEFP","ACE_SLAMSideEFP","ACE_SLAMSideEFP_0","ACE_SLAMSideEFP_1","ACE_SLAMSideEFP_2","ACE_SLAMSideEFP_3","ACE_PARMSideP","ACE_PARMSideP_0","ACE_PARMSideP_1","ACE_PARMSideP_2","ACE_PARMSideP_3","ACE_B_Frag","ACE_PomzExplosion","ACE_PMNExplosion","ACE_PipebombExplosion","ACE_MineExplosion","ACE_DM31ATExplosion","ACE_DM21ATExplosion","ACE_ArtyShellExplosion","ACE_M86PDM","ACE_M86PDMExplosion","ACE_DetCordLineGrenade"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_explosives
		{
			list[] = {"ace_sys_explosives"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_explosives
	{
		init = "call ('\x\ace\addons\sys_explosives\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_explosives\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		ace_sys_explosives = "_this call ace_sys_explosives_fnc_killed";
	};
};
class CfgAmmo
{
	class Default;
	class ACE_DummyAmmo_Explosives: Default
	{
		scope = 1;
		hit = 0.001;
		indirectHit = 0.001;
		indirectHitRange = 0.01;
	};
	class BulletBase;
	class ACE_B_BallBearing: BulletBase
	{
		hit = 10;
		ace_hit = 6;
		indirectHit = 0;
		indirectHitRange = 0;
		airFriction = -0.006;
		deflecting = 0;
		visibleFire = 0.07;
		audibleFire = 0.07;
		visibleFireTime = 2;
		typicalSpeed = 1100;
		timeToLive = 1;
	};
	class ACE_B_BallBearing_Test: ACE_B_BallBearing
	{
		hit = "6 * 4.66";
	};
	class Grenade;
	class GrenadeHand: Grenade
	{
		fuseDistance = 0;
	};
	class GrenadeHandTimedWest;
	class ACE_Explosion: GrenadeHandTimedWest
	{
		hit = 25;
		indirectHit = 23;
		indirectHitRange = 6;
		soundDefault1[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		soundDefault2[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		soundDefault3[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		soundDefault4[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		soundDefault5[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		soundDefault6[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		soundDefault7[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		soundDefault8[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",15.8489,1,1000};
		hitGroundSoft[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitGroundHard[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitMan[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitArmor[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitIron[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitBuilding[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitFoliage[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitWood[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitGlass[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitGlassArmored[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitConcrete[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitRubber[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitPlastic[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitDefault[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitMetal[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		hitMetalplate[] = {"soundDefault1",0.12,"soundDefault2",0.12,"soundDefault3",0.12,"soundDefault4",0.12,"soundDefault5",0.12,"soundDefault6",0.12,"soundDefault7",0.12,"soundDefault8",0.12};
		class AnimationSources{};
		animated = 0;
		class ACE;
	};
	class ACE_C4Explosion: ACE_Explosion
	{
		hit = 76;
		indirectHit = 50;
		indirectHitRange = 1;
		typicalSpeed = 20;
		cost = 40;
		simulationStep = 0.05;
		soundHit[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundEngine[] = {"","db-80",4};
		soundDefault1[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundDefault2[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundDefault3[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundDefault4[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundDefault5[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundDefault6[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundDefault7[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		soundDefault8[] = {"\x\ace\addons\sys_explosives\sound\exp\c4_explode.ogg",15.8489,1,1000};
		CraterEffects = "GrenadeCrater";
		explosionEffects = "GrenadeExplosion";
		visibleFire = 0.5;
		audibleFire = 0.05;
		visibleFireTime = 1;
		explosionTime = 0.01;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				force = 25;
			};
		};
		class AnimationSources
		{
			class arming
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
		};
	};
	class ACE_ClaymoreExplosion: ACE_Explosion
	{
		hit = 20;
		indirectHit = 18;
		indirectHitRange = 2;
		typicalSpeed = 20;
		cost = 40;
		simulationStep = 0.05;
		soundHit[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",30,1};
		soundEngine[] = {"","db-80",4};
		CraterEffects = "GrenadeCrater";
		explosionEffects = "GrenadeExplosion";
		visibleFire = 0.5;
		audibleFire = 0.05;
		visibleFireTime = 1;
		explosionTime = 0.01;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				force = 0;
			};
		};
	};
	class G_40mm_HE;
	class ACE_SLAMBottomEFP: ACE_ClaymoreExplosion
	{
		hit = 130;
		indirectHit = 50;
		indirectHitRange = 2;
		fuseDistance = 0;
		ace_hit = 25;
		ace_incendiary = 1;
		ace_tandemheat = 0;
		ace_minetype = 2;
		ace_heat = 1;
	};
	class ACE_SLAMSideEFP: G_40mm_HE
	{
		hit = 80;
		indirectHit = 30;
		indirectHitRange = 2;
		fuseDistance = 0;
		timetolive = 2;
		ace_hit = 40;
		ace_incendiary = 1;
		ace_tandemheat = 0;
		ace_heat = 1;
	};
	class ACE_SLAMSideEFP_0: ACE_SLAMSideEFP
	{
		ace_impactside = 0;
	};
	class ACE_SLAMSideEFP_1: ACE_SLAMSideEFP
	{
		ace_impactside = 1;
	};
	class ACE_SLAMSideEFP_2: ACE_SLAMSideEFP
	{
		ace_impactside = 2;
	};
	class ACE_SLAMSideEFP_3: ACE_SLAMSideEFP
	{
		ace_impactside = 3;
	};
	class ACE_PARMSideP: ACE_SLAMSideEFP
	{
		ace_hit = 700;
		hit = 650;
		indirecthit = 50;
		ace_heat = 1;
		indirectHitRange = 2.5;
	};
	class ACE_PARMSideP_0: ACE_PARMSideP
	{
		ace_impactside = 0;
	};
	class ACE_PARMSideP_1: ACE_PARMSideP
	{
		ace_impactside = 1;
	};
	class ACE_PARMSideP_2: ACE_PARMSideP
	{
		ace_impactside = 2;
	};
	class ACE_PARMSideP_3: ACE_PARMSideP
	{
		ace_impactside = 3;
	};
	class ACE_B_Frag: BulletBase
	{
		hit = 6;
		indirectHit = 0;
		indirectHitRange = 0;
		airFriction = -0.01;
		deflecting = 0;
		visibleFire = 0.07;
		audibleFire = 0.07;
		visibleFireTime = 2;
		typicalSpeed = 700;
		timeToLive = 1;
	};
	class ACE_PomzExplosion: ACE_Explosion
	{
		hit = 8;
		indirectHit = 4;
		indirectHitRange = 10;
		typicalSpeed = 20;
		cost = 40;
		simulationStep = 0.05;
		soundHit[] = {"\x\ace\addons\sys_explosives\sound\exp\explode.ogg",30,1};
		soundEngine[] = {"","db-80",4};
		CraterEffects = "GrenadeCrater";
		explosionEffects = "GrenadeExplosion";
		visibleFire = 0.5;
		audibleFire = 0.05;
		visibleFireTime = 1;
		explosionTime = 0.01;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				force = 0;
			};
		};
	};
	class ACE_PMNExplosion: ACE_PomzExplosion
	{
		hit = 1;
		indirectHit = 1;
		indirectHitRange = 3;
	};
	class ACE_PipebombExplosion: ACE_Explosion
	{
		hit = 800;
		indirectHit = 700;
		indirectHitRange = 4;
		ace_incendiary = 0.1;
		ace_tandemheat = 1;
		ace_minetype = 0;
		ace_heat = 0;
		typicalSpeed = 20;
		cost = 40;
		simulationStep = 0.05;
		soundHit[] = {"Ca\sounds\Weapons\explosions\explosion_mega_08",56.2341,1,1500};
		soundFly[] = {"",0,1};
		soundEngine[] = {"",0,1};
		visibleFire = 0.5;
		audibleFire = 0.05;
		visibleFireTime = 1;
		explosionTime = 0.01;
		CraterEffects = "ATRocketCrater";
		explosionEffects = "ATRocketExplosion";
		model = "\x\ace\addons\sys_explosives\ace_satchel_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				force = 10;
			};
		};
		class AnimationSources
		{
			class arming
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
		};
	};
	class ACE_MineExplosion: ACE_Explosion
	{
		hit = 1100;
		indirectHit = 600;
		indirectHitRange = 5;
		ace_incendiary = 0.1;
		ace_tandemheat = 0;
		ace_minetype = 1;
		ace_heat = 0;
		typicalSpeed = 20;
		cost = 40;
		simulationStep = 0.05;
		visibleFire = 0.5;
		audibleFire = 0.05;
		visibleFireTime = 1;
		explosionTime = 0.01;
		soundHit[] = {"Ca\sounds\Weapons\explosions\explosion_mega_08",56.2341,1,1500};
		soundFly[] = {"",0,1};
		soundEngine[] = {"",0,1};
		explosionEffects = "ATRocketExplosion";
		CraterEffects = "HERocketCrater";
		model = "\x\ace\addons\sys_explosives\ace_mine_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				force = 5;
			};
		};
		class AnimationSources
		{
			class arming
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
		};
	};
	class ACE_DM31ATExplosion: ACE_MineExplosion
	{
		hit = 900;
		indirecthit = 700;
		indirectHitRange = 0.5;
		ace_heat = 1;
		ace_minetype = 3;
		ace_incendiary = 1;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				force = 5;
			};
		};
		class AnimationSources
		{
			class arming
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
		};
	};
	class ACE_DM21ATExplosion: ACE_DM31ATExplosion
	{
		hit = 1100;
		indirectHit = 600;
		indirectHitRange = 5;
		ace_heat = 0;
		ace_minetype = 0;
		ace_incendiary = 0.3;
	};
	class ACE_ArtyShellExplosion: ACE_Explosion
	{
		ace_hit = 580;
		ace_heat = 0;
		ace_tandemheat = 0;
		hit = 684;
		indirectHit = 48;
		indirectHitRange = 12;
		typicalSpeed = 1400;
		explosionEffects = "ExploAmmoExplosion";
		CraterEffects = "HEShellCrater";
	};
	class ACE_M86PDM: ACE_Explosion
	{
		fuseDistance = 0;
		whistleDist = 0;
		WhistleOnFire = 0;
		displayName = "M86";
		model = "\x\ace\addons\sys_explosives\ace_m86pdm_armed.p3d";
		hit = 0.1;
		indirectHit = 1;
		indirectHitRange = 1;
		ace_incendiary = 0;
		ace_tandemheat = 0;
		ace_heat = 0;
		ace_topattack = 0;
		explosive = 1;
		explosionTime = 60;
		typicalSpeed = 30;
		deflecting = 5;
		CraterEffects = "NoCrater";
		ExplosionEffects = "NoExplosion";
		soundHit[] = {"",15.8489,1};
		ACE_Simulation = "shotM86PDM";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				force = 0;
			};
		};
	};
	class ACE_M86PDMExplosion: ACE_PomzExplosion
	{
		hit = 1;
		indirectHit = 1;
		indirectHitRange = 4;
	};
	class ACE_DetCordLineGrenade: ACE_C4Explosion
	{
		explosionTime = 7;
		indirectHitRange = 1.5;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				force = 60;
			};
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class ACE_Explosive_M: CA_Magazine
	{
		type = 256;
		ammo = "ACE_DummyAmmo_Explosives";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_x_ca.paa";
		count = 1;
		initSpeed = 0;
		maxLeadSpeed = 0;
		nameSound = "mine";
	};
	class ACE_CLAYMORE_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_CLAYMORE_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_m18_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_m18.p3d";
		ACE_Weight = 1.6;
		ACE_Size = 630;
		descriptionShort = "$STR_DSS_ACE_CLAYMORE_M";
	};
	class ACE_MON50_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_MON50_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_mon50_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_mon50.p3d";
		ACE_Weight = 1.6;
		ACE_Size = 630;
		descriptionShort = "$STR_DSS_ACE_MON50_M";
	};
	class ACE_POMZ_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_POMZ_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_pomz_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_pomz.p3d";
		ACE_Weight = 2.3;
		ACE_Size = 300;
		descriptionShort = "$STR_DSS_ACE_POMZ_M";
	};
	class ACE_TRIPFLARE_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_TRIPFLARE_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_m49_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_m49.p3d";
		ACE_Weight = 0.37;
		ACE_Size = 240;
		descriptionShort = "$STR_DSS_ACE_TRIPFLARE_M";
	};
	class ACE_DM16_M: ACE_TRIPFLARE_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_DM16_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_dm16_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_dm16.p3d";
		ACE_Weight = 0.37;
		ACE_Size = 240;
		descriptionShort = "$STR_DSS_ACE_DM16_M";
	};
	class ACE_BBETTY_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_BBETTY_M";
		descriptionShort = "$STR_DSS_ACE_BBETTY_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_m16_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_m16.p3d";
		ACE_Weight = 3.6;
		ACE_Size = 3211;
	};
	class ACE_DM31_M: ACE_BBetty_M
	{
		displayName = "$STR_MDN_ACE_DM31_M";
		descriptionShort = "$STR_DSS_ACE_DM31_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_dm31_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_dm31.p3d";
		ACE_Weight = 4.1;
		ACE_Size = 4211;
	};
	class ACE_OSM4_M: ACE_BBetty_M
	{
		displayName = "$STR_MDN_ACE_OSM4_M";
		descriptionShort = "$STR_DSS_ACE_OSM4_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_dm31_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_osm4.p3d";
		ACE_Weight = 4.1;
		ACE_Size = 4211;
	};
	class ACE_M2SLAM_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_M2SLAM_M";
		descriptionShort = "$STR_DSS_ACE_M2SLAM_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_m2_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_slam_m2.p3d";
		ACE_Weight = 0.99;
		ACE_Size = 630;
	};
	class ACE_M4SLAM_M: ACE_M2SLAM_M
	{
		displayName = "$STR_MDN_ACE_M4SLAM_M";
		descriptionShort = "$STR_DSS_ACE_M4SLAM_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_m4_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_slam_m4.p3d";
	};
	class ACE_C4_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_C4_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_c4_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_c4.p3d";
		ACE_Weight = 0.6;
		ACE_Size = 300;
		descriptionShort = "$STR_DSS_ACE_C4_M";
	};
	class ACE_DM12B1_M: ACE_C4_M
	{
		displayName = "$STR_MDN_ACE_DM12B1_M";
		model = "\x\ace\addons\sys_explosives\ace_dm12b1.p3d";
		ACE_Weight = 0.5;
		ACE_Size = 342;
		descriptionShort = "$STR_DSS_ACE_DM12B1_M";
	};
	class ACE_DM12PARM1_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_DM12PARM1_M";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_dm12_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_dm12.p3d";
		type = 512;
		ACE_Weight = 10;
		ACE_Size = 500;
		descriptionShort = "$STR_DSS_ACE_DM12PARM1_M";
	};
	class ACE_PMN1_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_PMN1_M";
		model = "\x\ace\addons\sys_explosives\ace_pmn1.p3d";
		ACE_Weight = 0.6;
		ACE_Size = 702;
		descriptionShort = "$STR_DSS_ACE_PMN1_M";
	};
	class ACE_PMN2_M: ACE_PMN1_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_PMN2_M";
		model = "\x\ace\addons\sys_explosives\ace_pmn2.p3d";
		ACE_Weight = 0.42;
		ACE_Size = 736.2;
		descriptionShort = "$STR_DSS_ACE_PMN2_M";
	};
	class ACE_PMN3_M: ACE_PMN2_M
	{
		displayName = "$STR_MDN_ACE_PMN3_M";
		ACE_Weight = 0.621;
		ACE_Size = 736.2;
		descriptionShort = "$STR_DSS_ACE_PMN3_M";
	};
	class ACE_PPM2_M: ACE_Explosive_M
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_PPM2_M";
		model = "\x\ace\addons\sys_explosives\ace_ppm2.p3d";
		ACE_Weight = 0.37;
		ACE_Size = 1015;
		descriptionShort = "$STR_DSS_ACE_PPM2_M";
	};
	class HandGrenade_Stone;
	class ACE_M86PDM: HandGrenade_Stone
	{
		model = "\x\ace\addons\sys_explosives\ace_m86pdm.p3d";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_pdm_ca.paa";
		displayName = "M86";
		displaynameshort = "";
		descriptionShort = "$STR_DSS_ACE_M86PDM";
		nameSound = "mine";
		ammo = "ACE_M86PDM";
		class Library
		{
			libTextDesc = "";
		};
		ACE_Weight = 0.45;
		ACE_Size = 100;
	};
	class TimeBomb: CA_Magazine
	{
		displayName = "$STR_MDN_ACE_TIMEBOMB_M";
		type = 256;
		useAction = 0;
		ACE_Weight = 9.1;
	};
	class PipeBomb: TimeBomb
	{
		type = 256;
		useAction = 0;
		ACE_Weight = 9.1;
	};
	class Mine: TimeBomb
	{
		displayName = "$STR_MDN_ACE_MINE_M";
		model = "\x\ace\addons\sys_explosives\Mine.p3d";
		type = 256;
		useAction = 0;
		ACE_Weight = 14.157;
	};
	class MineE: TimeBomb
	{
		displayName = "$STR_MDN_ACE_MINEE_M";
		model = "\x\ace\addons\sys_explosives\MineE.p3d";
		type = 256;
		useAction = 0;
		ACE_Weight = 8.6;
	};
	class ACE_DM31AT_M: Mine
	{
		displayName = "DM31 AT";
		model = "\x\ace\addons\sys_explosives\ace_dm31at.p3d";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_dm31_at_ca.paa";
		type = 256;
		useAction = 0;
		ACE_Weight = 10.5;
	};
	class ACE_DM21AT_M: ACE_DM31AT_M
	{
		displayName = "DM21 AT";
		model = "\x\ace\addons\sys_explosives\ace_dm21at.p3d";
		picture = "\x\ace\addons\sys_explosives\data\equip\m_dm21_at_ca.paa";
		type = 256;
		useAction = 0;
		ACE_Weight = 9;
	};
	class BAF_ied_v1: TimeBomb
	{
		displayName = "$STR_MDN_ACE_IED_M";
		useAction = 0;
	};
	class BAF_ied_v2: BAF_ied_v1
	{
		useAction = 0;
	};
	class BAF_ied_v3: BAF_ied_v1
	{
		useAction = 0;
	};
	class BAF_ied_v4: BAF_ied_v1
	{
		useAction = 0;
	};
	class PMC_ied_v1: TimeBomb
	{
		displayName = "$STR_MDN_ACE_IED_M";
		useAction = 0;
	};
	class PMC_ied_v2: PMC_ied_v1
	{
		useAction = 0;
	};
	class PMC_ied_v3: PMC_ied_v1
	{
		useAction = 0;
	};
	class PMC_ied_v4: PMC_ied_v1
	{
		useAction = 0;
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle;
		class ACE_M86PDMMuzzle: ThrowMuzzle
		{
			displayName = "M86 PDM";
			magazines[] = {"ACE_M86PDM"};
		};
	};
	class Default;
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_explosives: ACE_Dummy_Utility
		{
			magazines[] = {"ACE_Pomz_M","ACE_PMN1_M","ACE_PMN2_M","ACE_PMN3_M","ACE_PPM2_M","ACE_DM31AT_M","ACE_DM21AT_M","ACE_MON50_M","ACE_Claymore_M","ACE_TripFlare_M","ACE_DM16_M","ACE_BBetty_M","ACE_DM31_M","ACE_OSM4_M","ACE_M2SLAM_M","ACE_M4SLAM_M","ACE_DM12PARM1_M","ACE_C4_M","ACE_DM12B1_M"};
		};
		class PutMuzzle;
		class TimeBombMuzzle: PutMuzzle
		{
			enableAttack = 0;
			showToPlayer = 0;
		};
		class PipeBombMuzzle: PutMuzzle
		{
			enableAttack = 0;
			showToPlayer = 0;
		};
		class PMC_ied_v1_muzzle: PutMuzzle
		{
			enableAttack = 0;
			showToPlayer = 0;
		};
	};
	class ACE_Item;
	class ACE_Cellphone: ACE_Item
	{
		scope = 2;
		displayName = "$STR_WDN_ACE_CELLPHONE";
		picture = "\x\ace\addons\sys_explosives\data\equip\w_cellphone_ca.paa";
		model = "\x\ace\addons\sys_explosives\ace_cellphone.p3d";
		ACE_Weight = 0.2;
		ACE_Size = 200;
	};
};
class CfgVehicles
{
	class ReammoBox;
	class ACE_Explosive_Object: ReammoBox
	{
		scope = 1;
		displayName = "";
		icon = "\x\ace\addons\sys_explosives\data\icon\icomap_mine_ca.paa";
		class TransportMagazines{};
		class TransportWeapons{};
		forceSupply = 0;
		showWeaponCargo = 0;
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		nameSound = "";
		armor = 150;
		destructype = "DestructMan";
		armorstructural = 1;
		class DestructionEffects{};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		selectionDamage = "zbytek";
		vehicleClass = "ACE_Mines";
		class ACE;
	};
	class ACE_M16: ACE_Explosive_Object
	{
		displayName = "$STR_MDN_ACE_BBETTY_M";
		model = "\x\ace\addons\sys_explosives\ace_m16_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_BBETTY_M";
				animated = 0;
				index = 0;
				mine_type = "M16";
				mine_magazine = "ACE_BBETTY_M";
				disarm = "\x\ace\addons\sys_explosives\M16\disarm.sqf";
				explosion_type = "ACE_PomzExplosion";
				explosion_height = 1.2;
				armor = 10;
				tripwire = 1;
				tripwire_length = 10;
				clacker_length = 0;
				editor_only = 1;
				bury = 2;
				detectable = 1;
			};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_bbetty.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class AnimationSources
		{
			class ace_mine_bouncing
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
		};
	};
	class ACE_M16_Editor: ACE_M16
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\M16\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_SchMiDM31: ACE_Explosive_Object
	{
		displayName = "$STR_MDN_ACE_DM31_M";
		model = "\x\ace\addons\sys_explosives\ace_dm31_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_DM31_M";
				animated = 0;
				index = 1;
				mine_type = "DM31";
				mine_magazine = "ACE_DM31_M";
				disarm = "\x\ace\addons\sys_explosives\DM31\disarm.sqf";
				explosion_type = "ACE_PomzExplosion";
				explosion_height = 0.5;
				armor = 10;
				tripwire = 1;
				tripwire_length = 20;
				editor_only = 0;
				bury = 2;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_dm31.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class AnimationSources
		{
			class ace_mine_bouncing
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
		};
	};
	class ACE_SchMiDM31_Editor: ACE_SchMiDM31
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\DM31\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_OSM4: ACE_Explosive_Object
	{
		displayName = "$STR_MDN_ACE_OSM4_M";
		model = "\x\ace\addons\sys_explosives\ace_osm4_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_OSM4_M";
				animated = 0;
				index = 2;
				mine_type = "OSM4";
				mine_magazine = "ACE_OSM4_M";
				disarm = "\x\ace\addons\sys_explosives\OSM4\disarm.sqf";
				explosion_type = "ACE_PomzExplosion";
				explosion_height = 0.5;
				armor = 10;
				tripwire = 1;
				tripwire_length = 20;
				editor_only = 0;
				bury = 2;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_osm4.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class AnimationSources
		{
			class ace_mine_bouncing
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
		};
	};
	class ACE_OSM4_Editor: ACE_OSM4
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\OSM4\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_Pomz: ACE_Explosive_Object
	{
		displayName = "$STR_MDN_ACE_POMZ_M";
		model = "\x\ace\addons\sys_explosives\ace_pomz_armed.p3d";
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_POMZ_M";
				animated = 0;
				index = 3;
				mine_type = "POMZ";
				mine_magazine = "ACE_POMZ_M";
				disarm = "\x\ace\addons\sys_explosives\POMZ\disarm.sqf";
				explosion_type = "ACE_PomzExplosion";
				armor = 20;
				tripwire = 1;
				tripwire_length = 15;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_pomz.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_Pomz_Editor: ACE_Pomz
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\POMZ\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_M18: ACE_Explosive_Object
	{
		model = "\x\ace\addons\sys_explosives\ace_m18_armed.p3d";
		displayName = "$STR_MDN_ACE_CLAYMORE_M";
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_CLAYMORE_M";
				animated = 0;
				index = 5;
				mine_type = "M18";
				mine_magazine = "ACE_CLAYMORE_M";
				disarm = "\x\ace\addons\sys_explosives\M18\disarm.sqf";
				armor = 5;
				explosion_type = "ACE_ClaymoreExplosion";
				tripwire = 1;
				tripwire_length = 20;
				clacker_length = 60;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_claymore.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_M18_Editor: ACE_M18
	{
		scope = 2;
		icon = "\x\ace\addons\sys_explosives\data\icon\icomap_mine_directed_ca.paa";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\M18\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_MON50: ACE_Explosive_Object
	{
		displayName = "$STR_MDN_ACE_MON50_M";
		model = "\x\ace\addons\sys_explosives\ace_mon50_armed.p3d";
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_MON50_M";
				animated = 0;
				index = 6;
				mine_type = "MON50";
				mine_magazine = "ACE_MON50_M";
				disarm = "\x\ace\addons\sys_explosives\MON50\disarm.sqf";
				explosion_type = "ACE_ClaymoreExplosion";
				armor = 5;
				tripwire = 1;
				tripwire_length = 20;
				clacker_length = 60;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_mon50.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_MON50_Editor: ACE_MON50
	{
		scope = 2;
		icon = "\x\ace\addons\sys_explosives\data\icon\icomap_mine_directed_ca.paa";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\MON50\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_M49: ACE_Explosive_Object
	{
		displayName = "$STR_MDN_ACE_TRIPFLARE_M";
		model = "\x\ace\addons\sys_explosives\ace_m49_armed.p3d";
		armor = 300;
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_TRIPFLARE_M";
				animated = 0;
				index = 7;
				mine_type = "M49";
				mine_magazine = "ACE_TRIPFLARE_M";
				disarm = "\x\ace\addons\sys_explosives\M49\disarm.sqf";
				explosion_type = "Empty";
				armor = 2;
				tripwire = 1;
				tripwire_length = 15;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_tripflare.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_M49_Editor: ACE_M49
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\M49\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_DM16: ACE_M49
	{
		displayName = "$STR_MDN_ACE_DM16_M";
		model = "\x\ace\addons\sys_explosives\ace_dm16_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_DM16_M";
				animated = 0;
				index = 18;
				mine_type = "DM16";
				mine_magazine = "ACE_DM16_M";
				disarm = "\x\ace\addons\sys_explosives\dm16\disarm.sqf";
				tripwire_length = 20;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_dm16.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_DM16_Editor: ACE_DM16
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\M49\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_M2SLAM: ACE_Explosive_Object
	{
		model = "\x\ace\addons\sys_explosives\ace_slam_m2_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_M2SLAM_M";
				animated = 0;
				index = 8;
				mine_type = "M2";
				mine_magazine = "ACE_M2SLAM_M";
				disarm = "\x\ace\addons\sys_explosives\M2\disarm.sqf";
				explosion_type = "ACE_PomzExplosion";
				armor = 5;
				tripwire = 0;
				tripwire_length = -1;
				clacker_length = 60;
				bury = 0;
				detectable = 0.3;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_slam.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class AnimationSources
		{
			class flip
			{
				source = "user";
				animPeriod = 0;
			};
			class pirs: flip
			{
				initPhase = 0;
			};
			class cap: flip
			{
				initPhase = 1;
			};
		};
	};
	class ACE_M4SLAM: ACE_M2SLAM
	{
		model = "\x\ace\addons\sys_explosives\ace_slam_m4_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_M4SLAM_M";
				mine_magazine = "ACE_M4SLAM_M";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_slam.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_C4: ACE_Explosive_Object
	{
		model = "\x\ace\addons\sys_explosives\ace_c4_armed.p3d";
		armor = 1000;
		ACE_canBeCarried = 1;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_C4_M";
				animated = 1;
				index = 9;
				mine_type = "C4";
				mine_magazine = "ACE_C4_M";
				disarm = "\x\ace\addons\sys_explosives\C4\disarm.sqf";
				explosion_type = "ACE_ClaymoreExplosion";
				armor = 100;
				tripwire = 0;
				tripwire_length = -1;
				clacker_length = 60;
				clacker = "ACE_Clacker";
				bury = 0;
				detectable = 0;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_c4.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class AnimationSources
		{
			class arming
			{
				source = "user";
				animPeriod = 0;
				initPhase = 1;
			};
		};
	};
	class ACE_DM12B1: ACE_C4
	{
		model = "\x\ace\addons\sys_explosives\ace_dm12b1_armed.p3d";
		ACE_canBeCarried = 1;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_DM12B1_M";
				animated = 1;
				index = 19;
				mine_type = "C4";
				mine_magazine = "ACE_DM12B1_M";
				clacker_length = 100;
				clacker = "ACE_ZUNDMASCHINE";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_dm12b1.rvmat","x\ace\addons\sys_explosives\data\ace_dm12b1_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_Pipebomb: ACE_Explosive_Object
	{
		model = "\x\ace\addons\sys_explosives\ace_satchel_armed.p3d";
		armor = 9000;
		ACE_canBeCarried = 1;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_TIMEBOMB_M";
				animated = 1;
				index = 10;
				mine_type = "SATCHEL";
				mine_magazine = "PipeBomb";
				disarm = "\x\ace\addons\sys_explosives\SATCHEL\disarm.sqf";
				explosion_type = "ACE_PipebombExplosion";
				armor = 100;
				clacker_length = 200;
				clacker = "ACE_Clacker";
				bury = 0;
				detectable = 0;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\weapons\data\satchel.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class AnimationSources
		{
			class arming
			{
				source = "user";
				animPeriod = 0;
				initPhase = 1;
			};
		};
	};
	class ACE_Mine: ACE_Explosive_Object
	{
		displayName = "$STR_MDN_ACE_MINE_M";
		model = "\x\ace\addons\sys_explosives\ace_Mine_armed.p3d";
		armor = 9000;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_MINE_M";
				animated = 1;
				index = 11;
				mine_type = "MINE";
				mine_magazine = "Mine";
				disarm = "\x\ace\addons\sys_explosives\MINE\disarm.sqf";
				explosion_type = "ACE_MineExplosion";
				armor = 50;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\weapons\data\at15.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
		class AnimationSources
		{
			class arming
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
		};
	};
	class ACE_Mine_Editor: ACE_Mine
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\Mine\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_MineE: ACE_Mine
	{
		displayName = "$STR_MDN_ACE_MINEE_M";
		model = "\x\ace\addons\sys_explosives\ace_MineE_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_MINEE_M";
				animated = 1;
				index = 12;
				mine_magazine = "MineE";
				bury = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\weapons\data\tm46.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class AnimationSources: AnimationSources
		{
			class arming: arming
			{
				initPhase = 0;
			};
		};
	};
	class ACE_MineE_Editor: ACE_MineE
	{
		scope = 2;
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\Mine\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_DM12PARM1: ACE_Explosive_Object
	{
		model = "\x\ace\addons\sys_explosives\ace_dm12_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_DM12PARM1_M";
				animated = 1;
				index = 13;
				mine_type = "DM12";
				mine_magazine = "ACE_DM12PARM1_M";
				disarm = "\x\ace\addons\sys_explosives\dm12\disarm.sqf";
				explosion_type = "ACE_PomzExplosion";
				armor = 10;
				tripwire = 1;
				tripwire_length = 40;
				bury = 0;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_dm12.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_PMN1: ACE_Explosive_Object
	{
		model = "\x\ace\addons\sys_explosives\ace_pmn1_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_PMN1_M";
				animated = 0;
				index = 14;
				mine_type = "PMN";
				mine_magazine = "ACE_PMN1_M";
				disarm = "\x\ace\addons\sys_explosives\pmn\disarm.sqf";
				explosion_type = "ACE_PomzExplosion";
				armor = 10;
				tripwire = 0;
				tripwire_length = 0;
				bury = 2;
				detectable = 0.1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_pmn.rvmat","x\ace\addons\sys_explosives\data\ace_pmn_damage.rvmat","x\ace\addons\sys_explosives\data\ace_pmn_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_PMN1_Editor: ACE_PMN1
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_PMN1_M";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\PMN\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_PMN2: ACE_PMN1
	{
		model = "\x\ace\addons\sys_explosives\ace_pmn2_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_PMN2_M";
				animated = 0;
				index = 15;
				mine_magazine = "ACE_PMN2_M";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_pmn.rvmat","x\ace\addons\sys_explosives\data\ace_pmn_damage.rvmat","x\ace\addons\sys_explosives\data\ace_pmn_destruct.rvmat"};
		};
	};
	class ACE_PMN2_Editor: ACE_PMN2
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_PMN2_M";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\PMN\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_PMN3: ACE_PMN2
	{
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_PMN3_M";
				animated = 0;
				index = 16;
				mine_magazine = "ACE_PMN3_M";
			};
		};
	};
	class ACE_PMN3Editor: ACE_PMN3
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_PMN3_M";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\PMN\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_PPM2: ACE_PMN2
	{
		model = "\x\ace\addons\sys_explosives\ace_ppm2_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_PPM2_M";
				animated = 0;
				index = 17;
				mine_magazine = "ACE_PPM2_M";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_pmn.rvmat","x\ace\addons\sys_explosives\data\ace_pmn_damage.rvmat","x\ace\addons\sys_explosives\data\ace_pmn_destruct.rvmat"};
		};
	};
	class ACE_PPM2_Editor: ACE_PPM2
	{
		scope = 2;
		displayName = "$STR_MDN_ACE_PPM2_M";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\PMN\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_DM31AT: ACE_Mine
	{
		displayName = "DM31 AT";
		model = "\x\ace\addons\sys_explosives\ace_dm31at_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "DM31 AT";
				animated = 1;
				index = 18;
				mine_magazine = "ACE_DM31AT_M";
				explosion_type = "ACE_DM31ATExplosion";
				bury = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_dm31at.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class AnimationSources: AnimationSources
		{
			class arming: arming
			{
				initPhase = 0;
			};
		};
	};
	class ACE_DM31AT_Editor: ACE_DM31AT
	{
		scope = 2;
		displayName = "DM31 AT";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\Mine\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_DM21AT: ACE_DM31AT
	{
		displayName = "DM21 AT";
		model = "\x\ace\addons\sys_explosives\ace_dm21at_armed.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				name = "DM21 AT";
				animated = 1;
				index = 18;
				mine_magazine = "ACE_DM21AT_M";
				explosion_type = "ACE_DM21ATExplosion";
				bury = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_explosives\data\ace_dm21at.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
	};
	class ACE_DM21AT_Editor: ACE_DM21AT
	{
		scope = 2;
		displayName = "DM21 AT";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\Mine\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class Building;
	class NonStrategic: Building
	{
		class ACE;
	};
	class Land_IED_v1_PMC: NonStrategic
	{
		model = "\x\ace\addons\sys_explosives\IED_V1";
		armor = 2000;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_IED_M";
				animated = 0;
				index = 4;
				mine_type = "IED";
				mine_magazine = "PMC_ied_v1";
				disarm = "\x\ace\addons\sys_explosives\IED\disarm.sqf";
				explosion_type = "ACE_MineExplosion";
				armor = 100;
				tripwire = 1;
				tripwire_length = 30;
				clacker_length = 500;
				editor_only = 0;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\weapons_pmc\data\ied.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_explosives\IED\MM\init.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class Land_IED_v2_PMC: Land_IED_v1_PMC
	{
		model = "\x\ace\addons\sys_explosives\IED_V2";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				mine_magazine = "PMC_ied_v2";
				explosion_type = "ACE_ArtyShellExplosion";
			};
		};
	};
	class Land_IED_v3_PMC: Land_IED_v1_PMC
	{
		model = "\x\ace\addons\sys_explosives\IED_V3";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				mine_magazine = "PMC_ied_v3";
				explosion_type = "ACE_ArtyShellExplosion";
			};
		};
	};
	class Land_IED_v4_PMC: Land_IED_v3_PMC
	{
		model = "\x\ace\addons\sys_explosives\IED_V4";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				mine_magazine = "PMC_ied_v4";
				explosion_type = "ACE_ArtyShellExplosion";
			};
		};
	};
	class ACE_Land_IED_v1_PMC: ACE_Explosive_Object
	{
		model = "\x\ace\addons\sys_explosives\IED_V1";
		armor = 2000;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				name = "$STR_MDN_ACE_IED_M";
				animated = 0;
				index = 4;
				mine_type = "IED";
				mine_magazine = "PMC_ied_v1";
				disarm = "\x\ace\addons\sys_explosives\IED\disarm.sqf";
				explosion_type = "ACE_MineExplosion";
				armor = 100;
				tripwire = 1;
				tripwire_length = 30;
				clacker_length = 500;
				editor_only = 0;
				bury = 1;
				detectable = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\weapons_pmc\data\ied.rvmat","x\ace\addons\sys_explosives\data\ace_mine_damage.rvmat","x\ace\addons\sys_explosives\data\ace_mine_destruct.rvmat"};
		};
		class EventHandlers
		{
			handleDamage = "_this call ace_sys_explosives_fnc_handleDamage";
		};
	};
	class ACE_Land_IED_v2_PMC: ACE_Land_IED_v1_PMC
	{
		model = "\x\ace\addons\sys_explosives\IED_V2";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				mine_magazine = "PMC_ied_v2";
				explosion_type = "ACE_ArtyShellExplosion";
			};
		};
	};
	class ACE_Land_IED_v3_PMC: ACE_Land_IED_v2_PMC
	{
		model = "\x\ace\addons\sys_explosives\IED_V3";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				mine_magazine = "PMC_ied_v3";
				explosion_type = "ACE_ArtyShellExplosion";
			};
		};
	};
	class ACE_Land_IED_v4_PMC: ACE_Land_IED_v3_PMC
	{
		model = "\x\ace\addons\sys_explosives\IED_V4";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				mine_magazine = "PMC_ied_v4";
				explosion_type = "ACE_ArtyShellExplosion";
			};
		};
	};
	class MineGeneric;
	class MineMine: MineGeneric
	{
		scope = 1;
	};
	class MineMineE: MineGeneric
	{
		scope = 1;
	};
	class Thing;
	class RoadCone: Thing
	{
		class ACE;
	};
	class ACE_Explosive_Helper: RoadCone
	{
		scope = 1;
		mapsize = 0;
		displayName = "";
		model = "\x\ace\addons\sys_explosives\ace_explosive_helper.p3d";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				mine_type = "Helper";
				detectable = 0;
			};
		};
	};
	class ACE_Stake: ACE_Explosive_Helper
	{
		model = "\x\ace\addons\sys_explosives\ace_stake.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES
			{
				mine_type = "Tripwire";
				detectable = 0;
			};
		};
	};
	class ACE_Tripwire: ACE_Explosive_Helper
	{
		model = "\x\ace\addons\sys_explosives\ace_tripwire.p3d";
		class AnimationSources
		{
			class user0
			{
				source = "user";
				animPeriod = 0.05;
				initPhase = "0";
			};
			class user1: user0{};
			class user2: user0{};
		};
	};
	class ACE_Clacker: ACE_Explosive_Helper
	{
		displayName = "Firing Device, M57";
		model = "\x\ace\addons\sys_explosives\ace_clacker.p3d";
		class ACE: ACE
		{
			class ACE_EXPLOSIVES: ACE_EXPLOSIVES
			{
				mine_type = "Clacker";
			};
		};
	};
	class ACE_Zundmaschine: ACE_Clacker
	{
		displayName = "DM60A1";
		model = "\x\ace\addons\sys_explosives\ace_zundmasch.p3d";
	};
	class M1A1;
	class ACE_BreachObject: M1A1
	{
		scope = 1;
		displayName = "";
		model = "\x\ace\addons\sys_explosives\ace_breachobject.p3d";
		side = 4;
		picture = "";
		animated = 0;
		class TransportMagazines{};
		class TransportWeapons{};
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		class Turrets{};
		class DestructionEffects{};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		destrType = "DestructMan";
	};
	class ACE_M86PDM_Object: ACE_Explosive_Object
	{
		mapsize = 0;
		model = "\x\ace\addons\sys_explosives\ace_m86pdm_armed.p3d";
	};
	class ACE_Tbox_GP_W;
	class ACE_DM60460: ACE_Tbox_GP_W
	{
		displayName = "Munitionskiste DM60460";
		model = "\x\ace\addons\m_veh_crates\ace_dm60460.p3d";
		transportMaxMagazines = 4;
		transportMaxWeapons = 0;
		class TransportMagazines
		{
			class _xx_ACE_DM21AT_M
			{
				magazine = "ACE_DM21AT_M";
				count = 4;
			};
		};
		ACE_Weight = 12.5;
	};
	class ACE_pileOfGravel: ACE_Explosive_Helper
	{
		displayName = "dgdg356__fsdg_24";
		model = "\x\ace\addons\sys_explosives\ace_pogravel.p3d";
	};
	class ACE_pileOfGrass: ACE_pileOfGravel
	{
		model = "\x\ace\addons\sys_explosives\ace_pograss.p3d";
	};
	class ACE_pileOfSand: ACE_pileOfGravel
	{
		model = "\x\ace\addons\sys_explosives\ace_posand.p3d";
	};
	class ACE_pileOfRocks: ACE_pileOfGravel
	{
		model = "\x\ace\addons\sys_explosives\ace_porock.p3d";
	};
	class ACE_pileOfPiles: ACE_pileOfGravel
	{
		model = "\x\ace\addons\sys_explosives\ace_pogravel.p3d";
	};
	class ACE_BBetty_burried: ACE_M16_Editor
	{
		scope = 1;
	};
	class ACE_BBetty_burried_Editor: ACE_M16_Editor
	{
		scope = 1;
	};
	class ACE_SchMiDM31_burried: ACE_SchMiDM31_Editor
	{
		scope = 1;
	};
	class ACE_SchMiDM31_burried_Editor: ACE_SchMiDM31_Editor
	{
		scope = 1;
	};
	class ACE_OSM4_burried_Editor: ACE_OSM4_Editor
	{
		scope = 1;
	};
	class ACE_Claymore: ACE_M18
	{
		scope = 1;
	};
	class ACE_Claymore_Editor: ACE_M18_Editor
	{
		scope = 1;
	};
	class ACE_TripFlare: ACE_M49
	{
		scope = 1;
	};
	class ACE_TripFlare_Editor: ACE_M49_Editor
	{
		scope = 1;
	};
};
class CfgSounds
{
	class PlaceMine
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_explosives\sound\act\placemine.ogg",1,1};
		titles[] = {};
	};
	class ACE_M49_Explosion
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_explosives\sound\exp\m49_explode.ogg",1,1};
		titles[] = {};
	};
};
class CfgActions
{
	class None;
	class TouchOff: None
	{
		show = 0;
		shortcut = "";
	};
	class SetTimer: None
	{
		show = 0;
		shortcut = "";
	};
	class StartTimer: SetTimer
	{
		show = 0;
		shortcut = "";
	};
	class Deactivate: None
	{
		show = 0;
		shortcut = "";
	};
};
class RscTitles
{
	class ACE_Claymore_Sight
	{
		idd = -1;
		movingEnable = 1;
		duration = 1000;
		name = "ACE_Claymore_Sight";
		onLoad = "with uiNameSpace do { ACE_Claymore_Sight = _this select 0 }";
		class controls
		{
			class ACE_Sight
			{
				idc = -1;
				type = 0;
				style = 48;
				text = "\x\ace\addons\sys_explosives\data\rsc\peep_sight_m18.paa";
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,0.8};
				font = "TahomaB";
				size = 1;
				sizeEx = 1;
				x = "SafeZoneX";
				y = "SafeZoneY";
				w = "SafeZoneW";
				h = "SafeZoneH";
				fadein = 0.2;
				fadeout = 0.2;
			};
		};
	};
	class ACE_SLAM_Sight: ACE_Claymore_Sight
	{
		name = "ACE_SLAM_Sight";
		onLoad = "with uiNameSpace do { ACE_SLAM_Sight = _this select 0 }";
		class controls: controls
		{
			class ACE_Sight: ACE_Sight
			{
				text = "\x\ace\addons\sys_explosives\data\rsc\peep_sight_m2.paa";
			};
		};
	};
	class ACE_MON50_Sight: ACE_Claymore_Sight
	{
		name = "ACE_MON50_Sight";
		onLoad = "with uiNameSpace do { ACE_MON50_Sight = _this select 0 }";
	};
	class ACE_DM12PARM1_Sight: ACE_Claymore_Sight
	{
		name = "ACE_DM12PARM1_Sight";
		onLoad = "with uiNameSpace do { ACE_DM12PARM1_Sight = _this select 0 }";
		class controls: controls
		{
			class ACE_Sight: ACE_Sight
			{
				text = "\x\ace\addons\sys_explosives\data\rsc\peep_sight_dm12.paa";
			};
		};
	};
};
class RscPicture;
class RscShortcutButton;
class RscSlider;
class RscText;
class RscStructuredText;
class ACE_RscActiveText_SLAM
{
	type = 11;
	idc = -1;
	style = 2;
	color[] = {0,0,0,1};
	colorActive[] = {1,0,0,1};
	colortext[] = {0,0,0,1};
	colorBackground[] = {0,0,0,1};
	font = "Zeppelin32";
	sizeEx = 0.03921;
	soundEnter[] = {"",0.2,1};
	soundPush[] = {"",0.2,1};
	soundClick[] = {"",0.2,1};
	soundEscape[] = {"",0.2,1};
	default = 0;
	h = 0.035;
	w = 0.035;
	x = 0;
	y = 0;
	size = 0.04;
};
class ACE_SLAM_DEFAULT_BUTTON: ACE_RscActiveText_SLAM
{
	type = 1;
	style = 2;
	colorText[] = {1,0,0,0};
	colorFocused[] = {1,0,0,0};
	colorDisabled[] = {0,0,1,0};
	colorBackground[] = {0,0,0,0};
	colorBackgroundDisabled[] = {0,0,0,0};
	colorBackgroundActive[] = {0,0,0,0};
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {0,0,0,0};
	borderSize = 0;
	font = "Zeppelin32";
	sizeEx = 0.03;
	text = "TEST";
	action = "";
	default = 0;
};
class ACE_SLAM_MENU
{
	name = "ACE_SLAM_MENU";
	idd = 111;
	movingEnable = 0;
	controlsBackground[] = {"ACE_SLAM_MENU_BG"};
	objects[] = {};
	controls[] = {"ACE_SLAM_REMOVE_PIRS_COVER","ACE_SLAM_REMOVE_COMMAND","ACE_SLAM_LEFT","ACE_SLAM_RIGHT","ACE_SLAM_ARM","ACE_SLAM_MODE"};
	onload = "_this execVM '\x\ace\addons\sys_explosives\M2\onload.sqf'";
	class ACE_SLAM_MENU_BG
	{
		idc = 555;
		type = 0;
		style = 48;
		x = 0.2;
		y = 0;
		w = 0.8;
		h = 1;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "\x\ace\addons\sys_explosives\data\rsc\SLAM\ace_slam_menu.paa";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};
	class ACE_SLAM_REMOVE_PIRS_COVER: ACE_SLAM_DEFAULT_BUTTON
	{
		x = 0.35;
		y = 0.78;
		idc = 2021;
		w = 0.3;
		h = 0.1;
		text = "PIRS";
		action = "[ACE_SYS_EXPLOSIVES_SLAM,'REMOVE'] execVM '\x\ace\addons\sys_explosives\M2\timer.sqf'";
	};
	class ACE_SLAM_REMOVE_COMMAND: ACE_SLAM_DEFAULT_BUTTON
	{
		x = 0.8;
		y = 0.82;
		idc = 2022;
		w = 0.1;
		h = 0.1;
		text = "COM";
		action = "[ACE_SYS_EXPLOSIVES_SLAM,'INSERTCAP'] execVM '\x\ace\addons\sys_explosives\M2\timer.sqf'";
	};
	class ACE_SLAM_LEFT: ACE_SLAM_DEFAULT_BUTTON
	{
		x = 0.66;
		y = 0.92;
		idc = -1;
		w = 0.045;
		h = 0.045;
		text = "<";
		action = "[ACE_SYS_EXPLOSIVES_SLAM,'DECREASE'] execVM '\x\ace\addons\sys_explosives\M2\timer.sqf'";
	};
	class ACE_SLAM_MODE: ACE_RscActiveText_SLAM
	{
		x = 0.685;
		y = 0.9;
		idc = 666;
		w = 0.05;
		h = 0.09;
		text = 4;
		action = "";
		sizeEx = 0.02;
		colorText[] = {1,1,1,0.7};
		color[] = {1,1,1,0.7};
		colorActive[] = {1,1,1,0.7};
		colorBackground[] = {1,1,1,0.7};
	};
	class ACE_SLAM_RIGHT: ACE_SLAM_LEFT
	{
		x = 0.72;
		text = ">";
		action = "[ACE_SYS_EXPLOSIVES_SLAM,'INCREASE'] execVM '\x\ace\addons\sys_explosives\M2\timer.sqf'";
	};
	class ACE_SLAM_ARM: ACE_SLAM_DEFAULT_BUTTON
	{
		x = 0.9;
		y = 0.7;
		idc = -1;
		w = 0.1;
		h = 0.1;
		text = "ARM";
		action = "[ACE_SYS_EXPLOSIVES_SLAM] execVM '\x\ace\addons\sys_explosives\M2\arm.sqf'";
	};
};
class ACE_CELLPHONE_MENU
{
	name = "ACE_CELLPHONE_MENU";
	idd = 111;
	movingEnable = 1;
	controlsBackground[] = {"ACE_CELLPHONE_MENU_BG"};
	objects[] = {};
	controls[] = {"ACE_CELLPHONE_MENU_DISPLAY","ACE_CELLPHONE_MENU_1","ACE_CELLPHONE_MENU_2","ACE_CELLPHONE_MENU_3","ACE_CELLPHONE_MENU_4","ACE_CELLPHONE_MENU_5","ACE_CELLPHONE_MENU_6","ACE_CELLPHONE_MENU_7","ACE_CELLPHONE_MENU_8","ACE_CELLPHONE_MENU_9","ACE_CELLPHONE_MENU_0","ACE_CELLPHONE_MENU_C","ACE_CELLPHONE_MENU_DIAL"};
	onload = "_this execVM '\x\ace\addons\sys_explosives\IED\onload.sqf'";
	class ACE_CELLPHONE_MENU_BG
	{
		idc = 555;
		type = 0;
		style = 48;
		x = "0.319847 * SafeZoneW+ SafeZoneX";
		y = "0.163517 * SafeZoneH+ SafeZoneY";
		w = "0.372228 * SafeZoneW";
		h = "0.660292 * SafeZoneH";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "\x\ace\addons\sys_explosives\data\rsc\CELLPHONE\ace_cellphone_menu.paa";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};
	class ACE_CELLPHONE_MENU_1: ACE_SLAM_DEFAULT_BUTTON
	{
		idc = 1600;
		text = "1";
		x = "0.457755 * SafeZoneW+ SafeZoneX";
		y = "0.560711 * SafeZoneH+ SafeZoneY";
		w = "0.026094 * SafeZoneW";
		h = "0.0253997 * SafeZoneH";
		action = "[ACE_SYS_EXPLOSIVES_IED,'1'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\1.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_2: ACE_CELLPHONE_MENU_1
	{
		idc = 1601;
		text = "2";
		x = "0.489916 * SafeZoneW+ SafeZoneX";
		y = "0.562769 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'2'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\2.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_3: ACE_CELLPHONE_MENU_1
	{
		idc = 1602;
		text = "3";
		x = "0.525347 * SafeZoneW+ SafeZoneX";
		y = "0.562769 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'3'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\3.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_4: ACE_CELLPHONE_MENU_1
	{
		idc = 1603;
		text = "4";
		x = "0.454485 * SafeZoneW+ SafeZoneX";
		y = "0.6029 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'4'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\4.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_5: ACE_CELLPHONE_MENU_1
	{
		idc = 1604;
		text = "5";
		x = "0.489915 * SafeZoneW+ SafeZoneX";
		y = "0.604958 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'5'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\5.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_6: ACE_CELLPHONE_MENU_1
	{
		idc = 1605;
		text = "6";
		x = "0.525893 * SafeZoneW+ SafeZoneX";
		y = "0.6029 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'6'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\6.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_7: ACE_CELLPHONE_MENU_1
	{
		idc = 1606;
		text = "7";
		x = "0.456666 * SafeZoneW+ SafeZoneX";
		y = "0.645088 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'7'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\7.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_8: ACE_CELLPHONE_MENU_1
	{
		idc = 1607;
		text = "8";
		x = "0.49373 * SafeZoneW+ SafeZoneX";
		y = "0.645089 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'8'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\8.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_9: ACE_CELLPHONE_MENU_1
	{
		idc = 1608;
		text = "9";
		x = "0.527528 * SafeZoneW+ SafeZoneX";
		y = "0.647146 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'9'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\9.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_0: ACE_CELLPHONE_MENU_1
	{
		idc = 1609;
		text = "0";
		x = "0.492642 * SafeZoneW+ SafeZoneX";
		y = "0.690364 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'0'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\0.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_C: ACE_CELLPHONE_MENU_1
	{
		idc = 1611;
		text = "c";
		x = "0.456119 * SafeZoneW+ SafeZoneX";
		y = "0.483536 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'CLEAR'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\0.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_DIAL: ACE_CELLPHONE_MENU_1
	{
		idc = 1610;
		text = "-";
		x = "0.485555 * SafeZoneW+ SafeZoneX";
		y = "0.481478 * SafeZoneH+ SafeZoneY";
		action = "[ACE_SYS_EXPLOSIVES_IED,'DIAL'] execVM '\x\ace\addons\sys_explosives\IED\dial.sqf'";
		soundPush[] = {"\x\ace\addons\sys_explosives\sound\cell\0.wss",1,1};
	};
	class ACE_CELLPHONE_MENU_DISPLAY: ACE_RscActiveText_SLAM
	{
		idc = 1000;
		text = "";
		x = "0.4583 * SafeZoneW+ SafeZoneX";
		y = "0.351825 * SafeZoneH+ SafeZoneY";
		w = "0.0686113 * SafeZoneW";
		h = "0.0933136 * SafeZoneH";
	};
};
class ACE_FUSE_MENU
{
	name = "ACE_FUSE_MENU";
	idd = 1116;
	movingEnable = 1;
	onLoad = "uiNamespace setVariable ['ACE_FUSE_MENU', _this select 0];((uiNameSpace getVariable 'ACE_FUSE_MENU') displayCtrl 1201) ctrlSetText (getText(configFile >> 'CfgMagazines' >> (getText(configFile >> 'CfgVehicles' >> (typeOf ACE_SYS_EXPLOSIVES_MINE) >> 'ACE' >> 'ACE_EXPLOSIVES' >> 'mine_magazine')) >> 'picture'));((uiNameSpace getVariable 'ACE_FUSE_MENU') displayCtrl 1201) ctrlCommit 0;((uiNameSpace getVariable 'ACE_FUSE_MENU') displayCtrl 1900)sliderSetRange [0,150]";
	class controls
	{
		class ACE_FUSE_MENU_BG: RscPicture
		{
			idc = 1200;
			text = "\ca\ui\data\ui_gameoptions_background_ca.paa";
			x = "0.317176 * safezoneW + safezoneX";
			y = "0.289932 * safezoneH + safezoneY";
			w = "0.339585 * safezoneW";
			h = "0.246387 * safezoneH";
		};
		class ACE_FUSE_MENU_ITEM: RscPicture
		{
			idc = 1201;
			text = "";
			x = "0.327333 * safezoneW + safezoneX";
			y = "0.349951 * safezoneH + safezoneY";
			w = "0.0338073 * safezoneW";
			h = "0.0612415 * safezoneH";
		};
		class ACE_FUSE_MENU_BUTTON_OK: RscShortcutButton
		{
			idc = 1700;
			text = "OK";
			x = "0.483428 * safezoneW + safezoneX";
			y = "0.453714 * safezoneH + safezoneY";
			w = "0.0578632 * safezoneW";
			h = "0.0520859 * safezoneH";
			action = "[ACE_SYS_EXPLOSIVES_MINE] execVM '\x\ace\addons\sys_explosives\SATCHEL\timer.sqf'";
		};
		class ACE_FUSE_MENU_LENGTH_SLIDER: RscSlider
		{
			idc = 1900;
			text = "";
			x = "0.369029 * safezoneW + safezoneX";
			y = "0.385556 * safezoneH + safezoneY";
			w = "0.256725 * safezoneW";
			h = "0.0113945 * safezoneH";
			class ScrollBar
			{
				color[] = {1,1,1,0.6};
				colorActive[] = {1,1,1,1};
				colorDisabled[] = {1,1,1,0.3};
				shadow = 0;
				arrowEmpty = "\x\ace\addons\sys_explosives\data\rsc\FUSE\ui_arrow_left_ca.paa";
				arrowFull = "\x\ace\addons\sys_explosives\data\rsc\FUSE\ui_arrow_left_active_ca.paa";
				border = "\x\ace\addons\sys_explosives\data\rsc\FUSE\ui_border_frame_ca.paa";
				thumb = "\x\ace\addons\sys_explosives\data\rsc\FUSE\ui_slider_bar_ca.paa";
			};
			onSliderPosChanged = "((uiNameSpace getVariable 'ACE_FUSE_MENU') displayCtrl 1103) ctrlSetText format ['%1 cm',(sliderPosition ((uiNameSpace getVariable 'ACE_FUSE_MENU') displayCtrl 1900))]; ((uiNameSpace getVariable 'ACE_FUSE_MENU') displayCtrl 1103) ctrlCommit 0";
		};
		class ACE_FUSE_MENU_BUTTON_ABORT: RscShortcutButton
		{
			idc = 1702;
			text = "$STR_BUTTONS_CANCEL";
			x = "0.547042 * safezoneW + safezoneX";
			y = "0.454731 * safezoneH + safezoneY";
			w = "0.0733659 * safezoneW";
			h = "0.0500513 * safezoneH";
			action = "closeDialog 0";
		};
		class ACE_FUSE_MENU_BURNRATE: RscText
		{
			idc = 1100;
			text = "105-130 sec/m";
			x = "0.433178 * safezoneW + safezoneX";
			y = "0.349951 * safezoneH + safezoneY";
			w = "0.0829882 * safezoneW";
			h = "0.0215674 * safezoneH";
		};
		class ACE_FUSE_MENU_BURNRATE_TEXT: RscText
		{
			idc = 1101;
			text = "Burnrate";
			x = "0.374909 * safezoneW + safezoneX";
			y = "0.349951 * safezoneH + safezoneY";
			w = "0.0503792 * safezoneW";
			h = "0.0215674 * safezoneH";
		};
		class ACE_FUSE_MENU_LENGTH_TEXT: RscText
		{
			idc = 1102;
			text = "Length";
			x = "0.374375 * safezoneW + safezoneX";
			y = "0.410988 * safezoneH + safezoneY";
			w = "0.0503792 * safezoneW";
			h = "0.0215674 * safezoneH";
		};
		class ACE_FUSE_MENU_LENGTH: RscText
		{
			idc = 1103;
			text = "0 cm";
			x = "0.429436 * safezoneW + safezoneX";
			y = "0.410988 * safezoneH + safezoneY";
			w = "0.0503792 * safezoneW";
			h = "0.0215674 * safezoneH";
		};
		class ACE_FUSE_MENU_TYPE: RscText
		{
			idc = 1104;
			text = "Standard";
			x = "0.375444 * safezoneW + safezoneX";
			y = "0.321467 * safezoneH + safezoneY";
			w = "0.0503792 * safezoneW";
			h = "0.0215674 * safezoneH";
		};
	};
};
//};
