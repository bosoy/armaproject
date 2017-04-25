////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:07:05 2013 : Created on Sat Jun 08 13:07:05 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_particlefx : config.bin{
class CfgPatches
{
	class ace_sys_particlefx
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons","ace_main","CAData","CAData_ParticleEffects","CA_E_ParticleEffects","ace_sys_destruction","ace_c_weapon","ace_c_vehicle"};
		version = "1.14.0.593";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_particlefx
	{
		clientInit = "call ('\x\ace\addons\sys_particlefx\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBis_EventHandlers
{
	class CAManBase
	{
		class ace_sys_particlefx_BIS_Effects
		{
			clientFiredBis = "_this call BIS_Effects_EH_Fired";
		};
	};
	class LandVehicle
	{
		class ace_sys_particlefx_Turret_Effects
		{
			clientFiredBis = "_this call ace_sys_particlefx_fnc_fired_turret";
		};
	};
	class StaticWeapon
	{
		class ace_sys_particlefx_BIS_Effects
		{
			clientFiredBis = "_this call BIS_Effects_EH_Fired";
		};
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		class ace_sys_particlefx
		{
			clientKilled = "_this call BIS_Effects_EH_Killed";
		};
	};
};
class CfgCloudlets
{
	class Default;
	class MissileFire: Default
	{
		size[] = {0.2,0};
	};
	class MissileManualEffects1: Default
	{
		size[] = {"0.5/3","10/3"};
	};
	class Missile1: Default
	{
		size[] = {"1/3","3.5/3",1.5};
	};
	class Missile2: Default
	{
		size[] = {"1/3","2/3"};
	};
	class Missile3: Default
	{
		size[] = {"2.5/3","3.5/3","4/3"};
	};
	class Missile4: Default
	{
		size[] = {0.5,1};
	};
	class Missile5: Default
	{
		size[] = {1,3};
	};
	class CloudletsMissile
	{
		cloudletSize = "1 + random 0.5";
	};
	class CircleDustBig: Default
	{
		lifeTime = "6+(intensity*.3)";
		lifeTimeVar = "1+(intensity*.2)";
	};
	class CircleDustMed: Default
	{
		lifeTime = "6+(intensity*.3)";
		lifeTimeVar = "1+(intensity*.2)";
	};
	class CloudBigLight: Default
	{
		lifeTime = "8+(intensity*.4)";
		lifeTimeVar = "4+(intensity*.1)";
	};
	class CloudMedLight: Default
	{
		lifeTime = "12+(intensity*.4)";
		lifeTimeVar = "4+(intensity*.1)";
	};
	class CloudBigDark: Default
	{
		lifeTime = "18+(intensity*.4)";
		lifeTimeVar = "6+(intensity*.1)";
	};
	class CloudMedDark: Default
	{
		lifeTime = "14+(intensity*.4)";
		lifeTimeVar = "5+(intensity*.1)";
	};
	class SmokeBig: Default
	{
		lifeTime = "4+(intensity*.4)";
		lifeTimeVar = "0.5+(intensity*.1)";
	};
	class BombSmk1: Default
	{
		lifeTime = "9+(intensity*.4)";
		lifeTimeVar = "3+(intensity*.1)";
	};
	class BombSmk2: Default
	{
		lifeTime = "7+(intensity*.4)";
		lifeTimeVar = "1+(intensity*.1)";
	};
	class BombSmk3: Default
	{
		lifeTime = "15+(intensity*.4)";
		lifeTimeVar = "3+(intensity*.1)";
	};
	class GrenadeSmoke1;
	class ACE_GrenadeSmoke1_Practice: GrenadeSmoke1
	{
		size[] = {"0.013 * intensity + 1","0.0125 * intensity + 2","0.013 * intensity + 4","0.013 * intensity + 6"};
		color[] = {{0.9,0.4,0,1},{0.9,0.4,0,0.5},{0.9,0.45,0,0.25},{1,0.5,0,0}};
	};
	class ACE_M433_ExploAmmoFlash: Default
	{
		interval = 0.1;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Ca_E\data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 0;
		particleFSFrameCount = 32;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.1;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 1;
		weight = "10, 8";
		volume = 7.9;
		rubbing = 0.1;
		size[] = {1.5,1};
		color[] = {{1,1,1,-10},{1,1,1,-10}};
		animationSpeed[] = {100};
		randomDirectionPeriod = 0.2;
		randomDirectionIntensity = 0.2;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0;
		positionVar[] = {0,0.2,0};
		MoveVelocityVar[] = {0.2,0.5,0.2};
		rotationVelocityVar = 1;
		sizeVar = 0.5;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_M433_ImpactSparks1: Default
	{
		interval = 0.0001;
		circleRadius = 0.0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Ca_E\data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 0;
		particleFSFrameCount = 2;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 0.1;
		lifeTime = 0.005;
		moveVelocity[] = {1,1,1};
		rotationVelocity = 1;
		weight = 70;
		volume = 0.1;
		rubbing = 0;
		size[] = {0.1,0.05};
		color[] = {{1,1,0.7,-10},{1,1,0.7,-8},{1,1,0.7,-6},{1,1,0.7,-4}};
		colorCoef[] = {1,1,1,1};
		animationSpeed[] = {-2};
		randomDirectionPeriod = 1;
		randomDirectionIntensity = 1;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.2;
		positionVar[] = {0,0.5,0};
		MoveVelocityVar[] = {15,15,15};
		rotationVelocityVar = 1;
		sizeVar = 0.5;
		colorVar[] = {0.05,0.05,0.05,0};
		randomDirectionPeriodVar = 1;
		randomDirectionIntensityVar = 1;
	};
	class ACE_M433_ImpactSparks2: ACE_M433_ImpactSparks1
	{
		timerPeriod = 1.0;
		lifeTime = 0.03;
		size[] = {0.1};
		color[] = {{1,1,0.7,-10},{1,1,0.7,-8},{1,1,0.7,-6},{1,1,0.7,-4}};
		MoveVelocityVar[] = {10,10,10};
		sizeVar = 1;
	};
	class ACE_M433_ImpactSmoke1: Default
	{
		interval = "0.02 * interval + 0.04";
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Ca_E\data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 13;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 14;
		moveVelocity[] = {0,2,0};
		rotationVelocity = 1;
		weight = 0.053;
		volume = 0.04;
		rubbing = 0.2;
		size[] = {"0.013 * intensity + 4","0.0125 * intensity + 6","0.013 * intensity + 8","0.013 * intensity + 12"};
		color[] = {{0.5,0.4,0.3,0.2},{0.5,0.4,0.3,0.3},{0.5,0.4,0.3,0.2},{0.5,0.4,0.3,0.15},{0.5,0.4,0.3,0.05},{0.6,0.5,0.4,0}};
		animationSpeed[] = {1000};
		randomDirectionPeriod = 0.2;
		randomDirectionIntensity = 0.2;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 3;
		positionVar[] = {1.2,0.6,1.2};
		MoveVelocityVar[] = {4,2,4};
		rotationVelocityVar = 2;
		sizeVar = 0.4;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0.5;
		randomDirectionIntensityVar = 0.02;
	};
	class ACE_M433_ExplosionSmoke1: ACE_M433_ImpactSmoke1
	{
		interval = "0.05 * interval + 0.05";
		lifeTime = 6;
		size[] = {"0.0125 * intensity + 2.5","0.0125 * intensity + 3.5","0.0125 * intensity + 4","0.0125 * intensity + 5"};
		color[] = {{0.5,0.4,0.3,0.2},{0.5,0.4,0.3,0.3},{0.5,0.4,0.3,0.2},{0.5,0.4,0.3,0.15},{0.5,0.4,0.3,0.05},{0.6,0.5,0.4,0}};
		animationSpeed[] = {1000};
		lifeTimeVar = 2;
		positionVar[] = {0.5,0.3,0.5};
		MoveVelocityVar[] = {1.6,3,1.7};
		sizeVar = 0.5;
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_M433_GrenadeExp: Default
	{
		interval = 0.1;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Ca_E\data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 0;
		particleFSFrameCount = 32;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.1;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 1;
		weight = 10;
		volume = 7.9;
		rubbing = 0.1;
		size[] = {1.5};
		color[] = {{1,1,1,-10},{1,1,1,0}};
		animationSpeed[] = {5};
		randomDirectionPeriod = 0.2;
		randomDirectionIntensity = 0.2;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0;
		positionVar[] = {0,0.5,0};
		MoveVelocityVar[] = {0.2,0.5,0.2};
		rotationVelocityVar = 1;
		sizeVar = 0.2;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_FX_NoFX: Default
	{
		lifeTime = 0;
		lifeTimeVar = 0;
	};
	class ACE_FX_API_ExploAmmoFlash: Default
	{
		circleVelocity[] = {0,0,0};
		moveVelocity[] = {0,0,0};
		size[] = {"0.7 + intensity * 0.25"};
		color[] = {{1,1,1,-10}};
		colorCoef[] = {1,1,1,1};
		animationSpeed[] = {1000};
		position[] = {0,0,0};
		positionVar[] = {0,0,0};
		moveVelocityVar[] = {0,0,0};
		colorVar[] = {0.05,0.05,0.05,5};
		interval = 1;
		circleRadius = 0;
		particleShape = "\ca\Ca_E\data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 2;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = 0.03;
		rotationVelocity = 0;
		weight = 1.275;
		volume = 1;
		rubbing = 0;
		sizeCoef = 1;
		animationSpeedCoef = 100;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0;
		rotationVelocityVar = 0;
		sizeVar = 0.3;
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_FX_API_ImpactSmoke: Default
	{
		circleVelocity[] = {0,0,0};
		moveVelocity[] = {0,0.3,0};
		size[] = {0.5,0.7,1};
		color[] = {{0.6,0.6,0.6,0.6},{0.65,0.65,0.65,0.4},{0.75,0.75,0.75,0.25},{0.8,0.8,0.8,0.1},{0.85,0.85,0.85,0}};
		colorCoef[] = {1,1,1,1};
		animationSpeed[] = {1};
		position[] = {0,0,0};
		positionVar[] = {0.2,0.2,0.2};
		moveVelocityVar[] = {0.1,0.4,0.1};
		colorVar[] = {0.05,0.05,0.05,0.3};
		interval = 0.004;
		circleRadius = 0;
		particleShape = "\ca\Ca_E\data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = 2;
		rotationVelocity = 1;
		weight = 1.3;
		volume = 1;
		rubbing = 0.5;
		sizeCoef = 1;
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.05;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 1;
		rotationVelocityVar = 0;
		sizeVar = 0.2;
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_FX_API_ExpSparks: Default
	{
		interval = 0.001;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Ca_E\data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 13;
		particleFSFrameCount = 2;
		particleFSLoop = 0;
		angleVar = 360;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.4;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 1;
		weight = 150;
		volume = 7.9;
		rubbing = 70;
		size[] = {0.02,0.02,0.02,0.015,0.01,0.008,0.008,0.005,0.003,0};
		color[] = {{3,1,1,-50}};
		animationSpeed[] = {2000};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.1;
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {7,8,7};
		rotationVelocityVar = 1;
		sizeVar = 0;
		colorVar[] = {0.05,0.05,0.05,5};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_ImpactDust: Default
	{
		interval = 0.05;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		moveVelocity[] = {"surfNormalX * (0.2+(intensity*2))","surfNormalY * (.2+(intensity*.4))","surfNormalZ * (0.2+(intensity*2))"};
		moveVelocityVar[] = {".2+(intensity*.5)",".1+(intensity*0.2)",".2+(intensity*.5)"};
		particleShape = "\ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 7;
		particleFSFrameCount = 48;
		particleFSLoop = 1;
		animationSpeed[] = {0.8,0.4};
		animationSpeedCoef = 1;
		angle = 0;
		angleVar = 0;
		rotationVelocityVar = 0;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = "1+(intensity*3.5)";
		lifeTimeVar = ".2+(intensity*.5)";
		weight = "1.275*20";
		volume = "1*20";
		rubbing = 2;
		size[] = {".05+(intensity*.2)","1.2+(intensity*1)","1.3+(intensity*1.0)","1.4+(intensity*1.1)","1.5+(intensity*1.2)","1.6+(intensity*1.3)","1.7+(intensity*1.4)","1.8+(intensity*1.5)"};
		sizeCoef = 1;
		sizeVar = 0.1;
		color[] = {{0.85,0.73,0.77,0.15},{0.75,0.74,0.71,0}};
		colorCoef[] = {1,1,1,1};
		colorVar[] = {0.05,0.05,0.05,0.05};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		position[] = {0,0,0};
		positionVar[] = {0,0,0};
	};
	class ACE_LingeringDust: ACE_ImpactDust
	{
		interval = 0.1;
		lifeTime = "2+(intensity*5)";
		lifeTimeVar = "1+(intensity*2)";
		rubbing = 2;
		size[] = {".05+(intensity*.2)","2+(intensity*2.5)","3.5+(intensity*3.5)","4+(intensity*4)"};
		sizeCoef = 1;
		sizeVar = 0.2;
		color[] = {{0.85,0.73,0.67,0.15},{0.85,0.73,0.67,0.15},{0.85,0.73,0.67,0.13},{0.75,0.74,0.71,0.1},{0.75,0.74,0.71,0.08},{0.75,0.74,0.71,0}};
	};
	class ACE_ImpactDustDirt: Default
	{
		interval = 0.5;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 9;
		particleFSLoop = 0;
		animationSpeed[] = {1000};
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = "intensity*2";
		lifeTimeVar = "intensity*0.5";
		moveVelocity[] = {0,"surfNormalY * (.5+(intensity*.5))",0};
		moveVelocityVar[] = {0,".1+(intensity*0.1)",0};
		rotationVelocity = 0;
		weight = "2*20";
		volume = "1*20";
		rubbing = 1;
		size[] = {"intensity*.4","intensity*4"};
		sizeVar = 0.3;
		color[] = {{0.35,0.23,0.07,1},{0.35,0.23,0.01,0}};
		colorCoef[] = {"1 + 0.02 * dustColor","1 - 0.08 * dustColor","1 - 0.34 * dustColor","intensity*5"};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		positionVar[] = {0,0,0};
		rotationVelocityVar = 50;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_ImpactDustDust: Default
	{
		interval = 0.5;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\Ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 1;
		animationSpeed[] = {2};
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = "0.6";
		lifeTimeVar = "0.1";
		moveVelocity[] = {0,0,0};
		rotationVelocity = 0;
		weight = "1.275*20";
		volume = "1*20";
		rubbing = 0.5;
		size[] = {".2","intensity*3"};
		sizeVar = 0.2;
		color[] = {{0.55,0.43,0.27,1},{0.55,0.43,0.27,0.9},{0.65,0.53,0.37,0.1},{0.65,0.53,0.37,0}};
		colorCoef[] = {"1 + 0.02 * dustColor","1 - 0.08 * dustColor","1 - 0.34 * dustColor",1};
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0,0,0};
		rotationVelocityVar = 1;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_ImpactDustGlass: Default
	{
		interval = 0.01;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 3;
		lifeTime = 0.6;
		lifeTimeVar = 0.2;
		moveVelocity[] = {"(surfNormalX / 2) * inSpeed / 350 * 0.66","(surfNormalY / 2) * inSpeed / 350 * 0.66","(surfNormalZ / 2) * inSpeed / 350 * 0.66"};
		moveVelocityVar[] = {0.2,0.2,0.2};
		rotationVelocity = 1;
		weight = 1.3;
		volume = 1;
		rubbing = 0.1;
		size[] = {0.1,0.6};
		sizeCoef = 1;
		color[] = {{0.2,0.2,0.25,1},{0.6,0.6,0.7,0.1},{0.6,0.6,0.7,0.08},{0.6,0.6,0.7,0.06},{0.7,0.7,0.8,0}};
		colorCoef[] = {1,1,1,1};
		animationSpeed[] = {1};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.05;
		onTimerScript = "";
		beforeDestroyScript = "";
		position[] = {0,0,0};
		positionVar[] = {0,0,0};
		rotationVelocityVar = 0;
		sizeVar = 0.5;
		colorVar[] = {0.05,0.05,0.05,0.2};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_ImpactDustGlass2: ACE_ImpactDustGlass
	{
		moveVelocity[] = {"-((surfNormalX / 2) * inSpeed / 350 * 0.66)","-((surfNormalY / 2) * inSpeed / 350 * 0.66)","-((surfNormalZ / 2) * inSpeed / 350 * 0.66)"};
	};
	class ImpactDustWood;
	class ACE_ImpactDustWoodOut: ImpactDustWood
	{
		moveVelocity[] = {"-((surfNormalX / 2) * inSpeed / 350 * 0.66)","-((surfNormalY / 2) * inSpeed / 350 * 0.66)","-((surfNormalZ / 2) * inSpeed / 350 * 0.66)"};
	};
	class WoodChippings;
	class ACE_WoodChippingsOut: WoodChippings
	{
		moveVelocity[] = {"-((- inDirX * 2 + surfNormalX / 2) * inSpeed / 350 * 0.66)","-(( - inDirY * 2 + surfNormalY / 2) * inSpeed / 350 * 0.66)","-(( - inDirZ * 2 + surfNormalZ / 2) * inSpeed / 350 * 0.66)"};
	};
	class WoodChippings2;
	class ACE_WoodChippings2Out: WoodChippings2
	{
		moveVelocity[] = {"-((outDirX * 2) * outSpeed / 250 * 0.66)","-((outDirY * 2) * outSpeed / 250 * 0.66)","-((outDirZ * 2) * outSpeed / 250 * 0.66)"};
	};
};
class WeaponFireGun
{
	access = 0;
	cloudletDuration = 0.2;
	cloudletAnimPeriod = 1;
	cloudletSize = 1;
	cloudletAlpha = 0.6;
	cloudletGrowUp = 0.2;
	cloudletFadeIn = 0.01;
	cloudletFadeOut = 1;
	cloudletAccY = 0;
	cloudletMinYSpeed = -100;
	cloudletMaxYSpeed = 100;
	cloudletShape = "cloudletFire";
	cloudletColor[] = {1,1,1,0};
	interval = 0.01;
	size = 3;
	sourceSize = 0.5;
	timeToLive = 0;
	initT = 0;
	deltaT = 2250;
	class Table
	{
		class T0
		{
			maxT = 0;
			color[] = {1,1,1,0};
		};
		class T1
		{
			maxT = 250;
			color[] = {1,1,1,0};
		};
		class T2
		{
			maxT = 350;
			color[] = {1,0.9,0.6,0};
		};
		class T3
		{
			maxT = 700;
			color[] = {0.05,0.05,0.05,0};
		};
		class T4
		{
			maxT = 4200;
			color[] = {0,0,0,0};
		};
	};
};
class WeaponFireMGun: WeaponFireGun
{
	cloudletDuration = 0;
	cloudletGrowUp = 0.06;
	cloudletFadeIn = 0;
	cloudletFadeOut = 0.12;
	interval = 0.005;
	size = 0.12;
	sourceSize = 0.01;
	initT = 3200;
	deltaT = -4000;
};
class WeaponCloudsGun
{
	access = 0;
	cloudletDuration = 0.4;
	cloudletAnimPeriod = 1;
	cloudletSize = 1.3;
	cloudletAlpha = 0.4;
	cloudletGrowUp = 1;
	cloudletFadeIn = 0.1;
	cloudletFadeOut = 1.4;
	cloudletAccY = 0.4;
	cloudletMinYSpeed = 0.1;
	cloudletMaxYSpeed = 0.4;
	cloudletShape = "cloudletClouds";
	cloudletColor[] = {0.8,0.8,0.8,0};
	interval = 0.05;
	size = 3;
	sourceSize = 0.5;
	timeToLive = 0;
	initT = 0;
	deltaT = 0;
	class Table
	{
		class T0
		{
			maxT = 0;
			color[] = {0.8,0.8,0.8,0};
		};
	};
};
class WeaponCloudsMGun: WeaponCloudsGun
{
	access = 3;
	cloudletGrowUp = 0;
	cloudletFadeIn = 0;
	cloudletFadeOut = 0;
	cloudletDuration = 0;
	cloudletColor[] = {1,1,1,0};
	cloudletAlpha = 0;
	cloudletShape = "\ca\data\cl_basic";
	cloudletAccY = 0;
	cloudletMinYSpeed = 0;
	cloudletMaxYSpeed = 0;
	interval = 1;
	size = 0;
	sourceSize = 0;
};
class ImpactEffectsSmall
{
	class ImpactDust
	{
		simulation = "particles";
		type = "ACE_ImpactDust";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactConcrete
	{
		simulation = "particles";
		type = "ACE_LingeringDust";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_ImpactDustDust
	{
		simulation = "particles";
		type = "ACE_ImpactDustDust";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactEffectsSmall06
	{
		simulation = "particles";
		type = "ACE_ImpactDustDirt";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ImpactConcrete
{
	class ImpactDust
	{
		type = "ACE_ImpactDust";
	};
	class ACE_LingeringDust
	{
		simulation = "particles";
		type = "ACE_LingeringDust";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ImpactPlaster
{
	class ACE_LingeringDust
	{
		simulation = "particles";
		type = "ACE_LingeringDust";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ImpactGlass
{
	class ImpactDust
	{
		simulation = "particles";
		type = "ACE_ImpactDustGlass";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactDust2
	{
		simulation = "particles";
		type = "ACE_ImpactDustGlass2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ImpactGlassThin
{
	class ImpactDust
	{
		simulation = "particles";
		type = "ACE_ImpactDustGlass";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactDust2
	{
		simulation = "particles";
		type = "ACE_ImpactDustGlass2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ImpactWood
{
	class ImpactDustOut
	{
		simulation = "particles";
		type = "ACE_ImpactDustWoodOut";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class WoodChippingsOut
	{
		simulation = "particles";
		type = "ACE_WoodChippingsOut";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class WoodChippings2Out
	{
		simulation = "particles";
		type = "ACE_WoodChippings2Out";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ACE_GrenadeExplosion_Practice
{
	class ACE_GrenadeSmoke1_Practice
	{
		simulation = "particles";
		type = "ACE_GrenadeSmoke1_Practice";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ACE_GrenadeExplosion_M433HEDP
{
	class GrenadeExploLight
	{
		simulation = "light";
		type = "GrenadeExploLight";
		position[] = {0,0,0};
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.15;
	};
	class ACE_M433_ExploAmmoFlash
	{
		simulation = "particles";
		type = "ACE_M433_ExploAmmoFlash";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.15;
	};
	class ACE_M433_GrenadeExp
	{
		simulation = "particles";
		type = "ACE_M433_GrenadeExp";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.15;
	};
	class ImpactSparks2
	{
		simulation = "particles";
		type = "ImpactSparks2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.25;
	};
	class ACE_M433_ImpactSparks2
	{
		simulation = "particles";
		type = "ACE_M433_ImpactSparks2";
		position[] = {0,0,0};
		intensity = 3;
		interval = 1;
		lifeTime = 0.25;
	};
	class ACE_M433_ImpactSparks1
	{
		simulation = "particles";
		type = "ACE_M433_ImpactSparks1";
		position[] = {0,0,0};
		intensity = 3;
		interval = 1;
		lifeTime = 0.25;
	};
	class ACE_M433_ExplosionSmoke1
	{
		simulation = "particles";
		type = "ACE_M433_ExplosionSmoke1";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_M433_ImpactSmoke1
	{
		simulation = "particles";
		type = "ACE_M433_ImpactSmoke1";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ACE_VOG25P_Explosion
{
	class Light1
	{
		position[] = {0,0,1.8};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 1;
	};
	class GrenadeExp1
	{
		position[] = {0,0,1};
		simulation = "particles";
		type = "GrenadeExp";
		intensity = 1;
		interval = 1;
		lifeTime = 0.5;
	};
	class GrenadeSmoke1
	{
		position[] = {0,0,1};
		simulation = "particles";
		type = "GrenadeSmoke1";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ACE_FX_API_ImpactMetal
{
	class SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "SparksLight";
		intensity = 0.001;
		interval = 1;
		lifeTime = 0.5;
	};
	class ImpactSparks2
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactSparks2";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactSmoke2
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactSmoke2";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
	class ACE_FX_ExpSparks
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class ACE_FX_ExpSparks1
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 0.001;
		lifeTime = 0.3;
	};
};
class ACE_FX_API_ImpactGlass
{
	class GlassShards
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "GlassShards";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class GlassShards2
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "GlassShards2";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class GlassDust
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "GlassDust";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class GlassHole
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "GlassHole";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
	class ACE_FX_ExpSparks
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class ACE_FX_ExpSparks1
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 0.001;
		lifeTime = 0.3;
	};
};
class ACE_FX_API_ImpactGlassThin
{
	class GlassShards
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "GlassShards";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class GlassShards2
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "GlassShards2";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class GlassDust
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "GlassDust";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
};
class ACE_FX_API_ImpactWood
{
	class ImpactDust
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactDustWood";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class WoodChippings
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "WoodChippings";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class WoodChippings2
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "WoodChippings2";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class WoodHole
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "WoodHole";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
};
class ACE_FX_API_ImpactPlaster
{
	class ImpactDust
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactDustPlaster";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactConcrete
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactConcrete";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
	class ACE_FX_ExpSparks
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class ACE_FX_ExpSparks1
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 0.001;
		lifeTime = 0.3;
	};
};
class ACE_FX_API_ImpactRubber
{
	class ImpactDust
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactSmoke";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
};
class ACE_FX_API_ImpactBlood
{
	class Blood
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "Blood";
		intensity = 1;
		interval = 1;
		lifeTime = 2;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
};
class ACE_FX_API_ImpactConcrete
{
	class ImpactDust
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactDustConcrete";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactDust2
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactDustConcrete2";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactConcrete
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactConcrete";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactConcrete2
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ImpactConcrete2";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_FX_SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ACE_FX_ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
	class ACE_FX_ExpSparks
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class ACE_FX_ExpSparks1
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 0.001;
		lifeTime = 0.3;
	};
};
class ACE_FX_Empty
{
	class Nada
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_NoFX";
		intensity = 0;
		interval = 1;
		lifeTime = 0;
	};
};
class ACE_FX_API_ExploAmmoExplosion
{
	class ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 0.1;
		interval = 1;
		lifeTime = 0.3;
	};
	class SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.2;
	};
	class ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 0.4;
	};
};
class ACE_FX_API_ExploAmmoCrater
{
	class ExploAmmoStones
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "DirtSmall";
		intensity = 0.5;
		interval = 1;
		lifeTime = 1;
	};
	class ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 0.1;
		interval = 1;
		lifeTime = 0.3;
	};
	class SparksLight
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.2;
	};
	class ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 0.4;
	};
};
class ace_pfx_ammo_apfsds_120mm
{
	class Light1
	{
		simulation = "light";
		type = "GrenadeExploLight";
		position[] = {0.1,0,0};
		intensity = "0.01 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
		interval = "0.09 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
		lifeTime = "0.09 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
	};
	class Light2
	{
		simulation = "light";
		type = "GrenadeExploLight";
		position[] = {0.2,0.1,0.1};
		intensity = "0.01 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
		interval = "0.09 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
		lifeTime = "0.09 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
	};
	class SparksLight
	{
		simulation = "light";
		type = "SparksLight";
		position[] = {0,0,0};
		intensity = 0.001;
		interval = 1;
		lifeTime = 0.5;
	};
};
class ace_pfx_ammo_heat_120mm
{
	class Light1
	{
		simulation = "light";
		type = "ExploLightMed";
		position[] = {0,0,0};
		intensity = "0.02 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
		interval = "0.09 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
		lifeTime = "0.09 - ((random 0.01 - random 0.01) - (random 0.01 - random 0.01))";
	};
	class GrenadeExp1
	{
		simulation = "particles";
		type = "GrenadeExp";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.5;
	};
	class GrenadeSmoke1
	{
		simulation = "particles";
		type = "GrenadeSmoke1";
		position[] = {"(((random 0.5) - (random 0.5)) - ((random 0.5) - (random 0.5)))","(((random 0.5) - (random 0.5)) - ((random 0.5) - (random 0.5)))","(((random 0.5) - (random 0.5)) - ((random 0.5) - (random 0.5)))"};
		intensity = 0.7;
		interval = 0.5;
		lifeTime = 0.4;
	};
};
class ace_pfx_ammo_he_120mm
{
	class Light1
	{
		simulation = "light";
		type = "GrenadeExploLight";
		position[] = {0,0,0};
		intensity = 0.03;
		interval = 1;
		lifeTime = 1;
	};
	class GrenadeExp1
	{
		simulation = "particles";
		type = "GrenadeExp";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.5;
	};
	class GrenadeSmoke1
	{
		simulation = "particles";
		type = "GrenadeSmoke1";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ACE_FX_SABOT120_ImpactMetal
{
	class SparksLight1
	{
		simulation = "light";
		type = "SparksLight";
		position[] = {0,0,0};
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.5;
	};
	class ImpactSparks1
	{
		simulation = "particles";
		type = "ImpactSparks1";
		position[] = {0.05,0.05,0.05};
		intensity = 1;
		interval = 0.4;
		lifeTime = 1.3;
	};
	class ImpactSparks2
	{
		simulation = "particles";
		type = "ImpactSparks2";
		position[] = {0.01,0.01,0.01};
		intensity = 1;
		interval = 0.4;
		lifeTime = 1.6;
	};
	class ImpactSparks3
	{
		simulation = "particles";
		type = "ImpactSparks2";
		position[] = {0.1,0.1,0.1};
		intensity = 1;
		interval = 0.4;
		lifeTime = 1.5;
	};
	class ImpactSparks4
	{
		simulation = "particles";
		type = "ImpactSparks2";
		position[] = {0.08,0.08,0.08};
		intensity = 1.1;
		interval = 0.4;
		lifeTime = 1.5;
	};
	class ImpactSmoke
	{
		simulation = "particles";
		type = "ImpactSmoke";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ImpactSmoke2
	{
		simulation = "particles";
		type = "ImpactSmoke2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Light1
	{
		simulation = "light";
		type = "GrenadeExploLight";
		position[] = {0,0,0};
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.05;
	};
	class ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class SparksLight2
	{
		position[] = {0,0,0};
		simulation = "light";
		type = "GrenadeExploLight";
		intensity = 0.01;
		interval = 1;
		lifeTime = 0.1;
	};
	class ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ACE_FX_API_ImpactSmoke";
		intensity = 2;
		interval = 1;
		lifeTime = 2;
	};
	class ExpSparks1
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.3;
	};
	class ExpSparks2
	{
		simulation = "particles";
		type = "ACE_FX_API_ExpSparks";
		position[] = {0,0,0};
		intensity = 1;
		interval = 0.001;
		lifeTime = 0.3;
	};
};
class CfgAmmo
{
	class ShellCore;
	class ShellBase: ShellCore
	{
		muzzleEffect = "ACE_Effects_Cannon";
	};
	class BulletBase;
	class MissileBase;
	class M_AT10_AT: MissileBase
	{
		muzzleEffect = "ACE_Effects_Cannon_Missile";
	};
	class B_127x108_Ball: BulletBase
	{
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		CraterEffects = "ACE_FX_Empty";
		explosionEffects = "ACE_FX_Empty";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ACE_FX_API_ImpactConcrete";
			Hit_Foliage = "ImpactLeaves";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Glass = "ACE_FX_API_ImpactGlass";
			Hit_Glass_Thin = "ACE_FX_API_ImpactGlassThin";
			Hit_Wood = "ACE_FX_API_ImpactWood";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
			Hit_Plaster = "ACE_FX_API_ImpactPlaster";
			Hit_Rubber = "ACE_FX_API_ImpactRubber";
			Hit_Concrete = "ACE_FX_API_ImpactConcrete";
			Hit_Blood = "ACE_FX_API_ImpactBlood";
		};
	};
	class B_127x107_Ball: BulletBase
	{
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		CraterEffects = "ACE_FX_Empty";
		explosionEffects = "ACE_FX_Empty";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ACE_FX_API_ImpactConcrete";
			Hit_Foliage = "ImpactLeaves";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Glass = "ACE_FX_API_ImpactGlass";
			Hit_Glass_Thin = "ACE_FX_API_ImpactGlassThin";
			Hit_Wood = "ACE_FX_API_ImpactWood";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
			Hit_Plaster = "ACE_FX_API_ImpactPlaster";
			Hit_Rubber = "ACE_FX_API_ImpactRubber";
			Hit_Concrete = "ACE_FX_API_ImpactConcrete";
			Hit_Blood = "ACE_FX_API_ImpactBlood";
		};
	};
	class B_145x115_AP: BulletBase
	{
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		CraterEffects = "ACE_FX_Empty";
		explosionEffects = "ACE_FX_Empty";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ACE_FX_API_ImpactConcrete";
			Hit_Foliage = "ImpactLeaves";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Glass = "ACE_FX_API_ImpactGlass";
			Hit_Glass_Thin = "ACE_FX_API_ImpactGlassThin";
			Hit_Wood = "ACE_FX_API_ImpactWood";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
			Hit_Plaster = "ACE_FX_API_ImpactPlaster";
			Hit_Rubber = "ACE_FX_API_ImpactRubber";
			Hit_Concrete = "ACE_FX_API_ImpactConcrete";
			Hit_Blood = "ACE_FX_API_ImpactBlood";
		};
	};
	class B_127x99_Ball: BulletBase
	{
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		CraterEffects = "ACE_FX_Empty";
		explosionEffects = "ACE_FX_Empty";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ACE_FX_API_ImpactConcrete";
			Hit_Foliage = "ImpactLeaves";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Glass = "ACE_FX_API_ImpactGlass";
			Hit_Glass_Thin = "ACE_FX_API_ImpactGlassThin";
			Hit_Wood = "ACE_FX_API_ImpactWood";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
			Hit_Plaster = "ACE_FX_API_ImpactPlaster";
			Hit_Rubber = "ACE_FX_API_ImpactRubber";
			Hit_Concrete = "ACE_FX_API_ImpactConcrete";
			Hit_Blood = "ACE_FX_API_ImpactBlood";
		};
	};
	class ACE_B_127x99_Raufoss: B_127x99_Ball
	{
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		CraterEffects = "ACE_FX_Empty";
		explosionEffects = "ACE_FX_Empty";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ACE_FX_API_ImpactConcrete";
			Hit_Foliage = "ImpactLeaves";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Glass = "ACE_FX_API_ImpactGlass";
			Hit_Glass_Thin = "ACE_FX_API_ImpactGlassThin";
			Hit_Wood = "ACE_FX_API_ImpactWood";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
			Hit_Plaster = "ACE_FX_API_ImpactPlaster";
			Hit_Rubber = "ACE_FX_API_ImpactRubber";
			Hit_Concrete = "ACE_FX_API_ImpactConcrete";
			Hit_Blood = "ACE_FX_API_ImpactBlood";
		};
	};
	class ACE_B_127x99_SLAP: B_127x99_Ball
	{
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		CraterEffects = "ACE_FX_Empty";
		explosionEffects = "ACE_FX_Empty";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ACE_FX_API_ImpactConcrete";
			Hit_Foliage = "ImpactLeaves";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Glass = "ACE_FX_API_ImpactGlass";
			Hit_Glass_Thin = "ACE_FX_API_ImpactGlassThin";
			Hit_Wood = "ACE_FX_API_ImpactWood";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
			Hit_Plaster = "ACE_FX_API_ImpactPlaster";
			Hit_Rubber = "ACE_FX_API_ImpactRubber";
			Hit_Concrete = "ACE_FX_API_ImpactConcrete";
			Hit_Blood = "ACE_FX_API_ImpactBlood";
		};
	};
	class B_127x99_Ball_noTracer: B_127x99_Ball
	{
		explosive = 0;
		indirectHit = 0;
		class HitEffects
		{
			vehicle = "ImpactMetal";
			object = "ImpactConcrete";
			Hit_Foliage = "ImpactLeaves";
			Hit_Foliage_green = "ImpactLeavesGreen";
			Hit_Glass = "ImpactGlass";
			Hit_Glass_Thin = "ImpactGlassThin";
			Hit_Wood = "ImpactWood";
			Hit_Metal = "ImpactMetal";
			Hit_Plaster = "ImpactPlaster";
			Hit_Rubber = "ImpactRubber";
			Hit_Concrete = "ImpactConcrete";
			Hit_Blood = "ImpactBlood";
		};
	};
	class Sh_120_SABOT: ShellBase
	{
		explosive = 0;
		model = "\ca\Weapons\shell";
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ace_pfx_ammo_apfsds_120mm";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ImpactConcrete";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
		};
	};
	class ACE_M900Round: Sh_120_SABOT
	{
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ace_pfx_ammo_apfsds_120mm";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ImpactConcrete";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
		};
	};
	class Sh_125_SABOT: ShellBase
	{
		explosive = 0;
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ace_pfx_ammo_apfsds_120mm";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ImpactConcrete";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
		};
	};
	class ACE_3BM42MRound: Sh_125_SABOT{};
	class Sh_85_AP: ShellBase
	{
		explosive = 0;
		explosionEffects = "ace_pfx_ammo_apfsds_120mm";
		class HitEffects
		{
			vehicle = "ACE_FX_API_ImpactMetal";
			object = "ImpactConcrete";
			Hit_Metal = "ACE_FX_API_ImpactMetal";
		};
	};
	class Sh_120_HE: ShellBase
	{
		explosive = 0.8;
		model = "\ca\Weapons\shell";
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ace_pfx_ammo_heat_120mm";
	};
	class ACE_3BK29Round: Sh_125_SABOT
	{
		CraterEffects = "ExploAmmoCrater";
		explosionEffects = "ace_pfx_ammo_heat_120mm";
	};
};
class CfgWeapons
{
	class MGun;
	class CannonCore;
	class KPVT: MGun
	{
		class ace_sys_particlefx
		{
			shape = "ca\data\cl_exp";
			timerPeriod = 0.05;
			lifeTime = 0.05;
			position[] = {0,0.1,0};
			size[] = {0,0.8,1.0};
			color[] = {{1.0,1.0,1.0,-2},{0.9,0.9,0.9,-1},{0.8,0.8,0.8,0}};
		};
	};
	class M242: CannonCore
	{
		class ace_sys_particlefx
		{
			shape = "ca\data\cl_exp";
			timerPeriod = 0.075;
			lifeTime = 0.075;
			position[] = {0,0.05,0};
			size[] = {0,0.9,1.2};
			color[] = {{1.0,1.0,1.0,-2},{0.9,0.9,0.9,-1},{0.8,0.8,0.8,0}};
		};
	};
	class ACE_M242: M242{};
	class ACE_M242_200: ACE_M242
	{
		class ace_sys_particlefx: ace_sys_particlefx
		{
			position[] = {0,0.7,0};
		};
	};
	class 2A42: CannonCore
	{
		class ace_sys_particlefx
		{
			shape = "ca\data\cl_exp";
			timerPeriod = 0.1;
			lifeTime = 0.1;
			position[] = {0,0.05,0};
			size[] = {0,1.0,1.25};
			color[] = {{1.0,1.0,1.0,-2},{0.9,0.9,0.9,-1},{0.8,0.8,0.8,0}};
		};
	};
	class 2A72: CannonCore
	{
		class ace_sys_particlefx
		{
			shape = "ca\data\cl_exp";
			timerPeriod = 0.1;
			lifeTime = 0.1;
			position[] = {0.19,-0.375,0};
			size[] = {0,1.0,1.25};
			color[] = {{1.0,1.0,1.0,-2},{0.9,0.9,0.9,-1},{0.8,0.8,0.8,0}};
		};
	};
};
//};
