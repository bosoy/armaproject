////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:35:33 2012 : Created on Fri Nov 09 22:35:33 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_willipete : config.bin{
class CfgPatches
{
	class ace_sys_willipete
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","CBA_MAIN","ace_main","ace_sys_viewblock"};
		version = "1.14.0.581";
		author[] = {"Rocko"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_willipete
	{
		init = "call ('\x\ace\addons\sys_willipete\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgAmmo
{
	class Grenade;
	class GrenadeHand: Grenade
	{
		class ACE;
	};
	class ACE_M34: GrenadeHand
	{
		cost = 150;
		ACE_Simulation = "shotWP";
		whistleOnFire = 0;
		displayName = "M34";
		model = "\x\ace\addons\sys_willipete\ACE_M34_armed.p3d";
		hit = 5;
		indirectHit = 7;
		indirectHitRange = 10;
		explosionTime = 4;
		smokeColor[] = {1,1,1,0.7};
		timeToLive = 90;
		ExplosionEffects = "ACE_WPExplosion";
		CraterEffects = "ExploAmmoCrater";
		deflecting = 1;
		soundDefault1[] = {"\x\ace\addons\sys_willipete\wp_exp1.wss",3.16228,1,900};
		soundDefault2[] = {"\x\ace\addons\sys_willipete\wp_exp2.wss",3.16228,1,900};
		hitGroundSoft[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitGroundHard[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitMan[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitArmor[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitIron[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitBuilding[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitFoliage[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitWood[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitGlass[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitGlassArmored[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitConcrete[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitRubber[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitPlastic[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitDefault[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitMetal[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		hitMetalplate[] = {"soundDefault1",0.5,"soundDefault2",0.5};
		class ACE: ACE
		{
			class ACE_GAS
			{
				range = 20;
				ingestiontime = 10;
				buildtime = 1;
			};
		};
		ACE_FRAG_FORCE = 0.7;
		ACE_FRAG_MULTIPLIER = 0.6;
	};
	class ACE_M15: ACE_M34
	{
		hit = 3;
		indirectHit = 5;
		indirectHitRange = 7;
		displayName = "M15";
		model = "\x\ace\addons\sys_willipete\ACE_M15_armed.p3d";
		ExplosionEffects = "ACE_WPExplosion_M15";
		class ACE: ACE
		{
			class ACE_GAS: ACE_GAS
			{
				range = 10;
			};
		};
	};
};
class CfgMagazines
{
	class SmokeShell;
	class ACE_M34: SmokeShell
	{
		model = "\x\ace\addons\sys_willipete\ACE_M34.p3d";
		picture = "\x\ace\addons\sys_willipete\data\equip\m_m34_ca.paa";
		displayName = "$STR_DN_ACE_M34";
		displaynameshort = "";
		ammo = "ACE_M34";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_M34";
		ACE_Weight = 0.765;
		ACE_Size = 600;
	};
	class ACE_M15: ACE_M34
	{
		model = "\x\ace\addons\sys_willipete\ACE_M15.p3d";
		picture = "\x\ace\addons\sys_willipete\data\equip\m_m15_ca.paa";
		displayName = "$STR_DN_ACE_M15";
		ammo = "ACE_M15";
		descriptionShort = "$STR_DSS_ACE_M34";
		ACE_Weight = 0.425;
		ACE_Size = 409;
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle;
		class ACE_WPMuzzle: ThrowMuzzle
		{
			displayName = "$STR_WDN_ACE_WP";
			magazines[] = {"ACE_M34","ACE_M15"};
			sound[] = {"\x\ace\addons\sys_willipete\grenade_pin.wss",0.177828,1,20};
		};
	};
};
class CfgCloudlets
{
	class Default;
	class ACE_WPCloud: Default
	{
		interval = "0.005 * interval + 0.005";
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 13;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 90;
		moveVelocity[] = {0.075,0.1,0.075};
		rotationVelocity = 1;
		weight = 1.275;
		volume = 1.0;
		rubbing = 0.0025;
		size[] = {5,10,13,16,18,20,21,22};
		color[] = {{1,1,1,0.5},{1,1,1,1},{1,1,1,0}};
		animationSpeed[] = {1000};
		randomDirectionPeriod = 1;
		randomDirectionIntensity = 0.1;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 4;
		positionVar[] = {4,3,4};
		MoveVelocityVar[] = {0.075,1.75,0.075};
		rotationVelocityVar = 1;
		sizeVar = 0.3;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 1;
		randomDirectionIntensityVar = 0.1;
	};
	class ACE_WPCloud2: ACE_WPCloud
	{
		interval = "0.005 * interval + 0.005";
		size[] = {2.5,4,5,6,8,9,10,11};
		lifeTimeVar = 3;
		positionVar[] = {3,2,3};
		MoveVelocityVar[] = {0.05,1.5,0.05};
		rotationVelocityVar = 1;
		sizeVar = 0.1;
	};
	class ACE_WPTrails: Default
	{
		interval = 0.02;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 2;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 0.007;
		lifeTime = 1.25;
		moveVelocity[] = {4,4,4};
		rotationVelocity = 1;
		weight = 15;
		volume = 7.9;
		rubbing = 0.1;
		size[] = {0.5};
		color[] = {{1,1,0,-5}};
		animationSpeed[] = {1000};
		randomDirectionPeriod = 1;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.125;
		positionVar[] = {2,1.5,2};
		MoveVelocityVar[] = {3,4,3};
		rotationVelocityVar = 1;
		sizeVar = 0;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};
class CfgLights
{
	class ACE_WPExploLight
	{
		color[] = {20,20,0};
		ambient[] = {4,4,0};
		diffuse[] = {0,0,0};
		brightness = "0.5 * fireIntensity + 0.5";
	};
};
class ACE_WPExplosion
{
	class LightExp
	{
		simulation = "light";
		type = "ACE_WPExploLight";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Trails
	{
		simulation = "particles";
		type = "ACE_WPTrails";
		position[] = {0,0,0.25};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Explosion1
	{
		simulation = "particles";
		type = "ACE_WPCloud";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 3;
	};
};
class ACE_WPExplosion_M15
{
	class LightExp
	{
		simulation = "light";
		type = "ACE_WPExploLight";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Trails
	{
		simulation = "particles";
		type = "ACE_WPTrails";
		position[] = {0,0,0.25};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Explosion1
	{
		simulation = "particles";
		type = "ACE_WPCloud2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 3;
	};
};
//};
