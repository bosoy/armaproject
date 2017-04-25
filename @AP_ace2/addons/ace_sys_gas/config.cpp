////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:07 2013 : Created on Sat Apr 06 11:45:07 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_gas : config.bin{
class CfgPatches
{
	class ace_sys_gas
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","CBA_MAIN","ace_main","ace_sys_viewblock"};
		version = "1.14.0.590";
		author[] = {"Rocko"};
	};
};
class CfgCloudlets
{
	class Default;
	class ACE_Teargas_Smoke: Default
	{
		animationSpeedCoef = 1;
		colorCoef[] = {"colorR","colorG","colorB","colorA"};
		sizeCoef = 1;
		position[] = {0,0,0};
		interval = "0.03";
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\Ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 7;
		particleFSFrameCount = 48;
		particleFSLoop = 1;
		angleVar = 0.1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = "20";
		moveVelocity[] = {0.2,0.1,0.1};
		rotationVelocity = 1;
		weight = 1.2777;
		volume = 1;
		rubbing = 0.015;
		size[] = {0.12,2.1,7};
		color[] = {{0.9,0.9,0.9,0.2},{0.9,0.9,0.9,0.4},{0.9,0.9,0.9,0}};
		animationSpeed[] = {1.5,0.5};
		randomDirectionPeriod = 1;
		randomDirectionIntensity = 0.04;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 2;
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0.25,0.25,0.25};
		rotationVelocityVar = 1;
		sizeVar = 0.7;
		colorVar[] = {0,0,0,0.35};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};
class ACE_Teargas_Smoke
{
	class ACE_Teargas_Smoke
	{
		simulation = "particles";
		type = "ACE_Teargas_Smoke";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class CfgAmmo
{
	class GrenadeHand;
	class SmokeShell: GrenadeHand
	{
		class ACE;
	};
	class ACE_M7A3: SmokeShell
	{
		ACE_Simulation = "shotCS";
		whistleOnFire = 0;
		displayName = "$STR_DN_ACE_M7A3";
		model = "\x\ace\addons\sys_gas\ace_m7a3_armed.p3d";
		deflecting = 30;
		timeToLive = 25;
		effectsSmoke = "ACE_Teargas_Smoke";
		class ACE: ACE
		{
			class ACE_GAS
			{
				range = 20;
				ingestiontime = 2;
				buildtime = 5;
			};
		};
	};
	class ACE_RG60A: ACE_M7A3
	{
		displayName = "$STR_DN_ACE_RG60A";
		model = "\x\ace\addons\sys_gas\ACE_RG60A_armed.p3d";
	};
	class G_40mm_Smoke: SmokeShell
	{
		class ACE;
	};
	class ACE_G_40mm_CS: G_40mm_Smoke
	{
		ACE_Simulation = "shotCS";
		whistleOnFire = 0;
		deflecting = 10;
		timeToLive = 25;
		effectsSmoke = "ACE_Teargas_Smoke";
		class ACE: ACE
		{
			class ACE_GAS
			{
				range = 20;
				ingestiontime = 2;
				buildtime = 5;
			};
		};
	};
	class ACE_GVOZD_CS: ACE_G_40mm_CS
	{
		model = "\x\ace\addons\m_wep_magazines\ace_gvozd_armed.p3d";
	};
};
class CfgMagazines
{
	class SmokeShell;
	class ACE_M7A3: SmokeShell
	{
		model = "\x\ace\addons\sys_gas\ace_m7a3.p3d";
		picture = "\x\ace\addons\sys_gas\data\equip\m_m7a3_ca.paa";
		displayName = "$STR_DN_ACE_M7A3";
		displaynameshort = "";
		ammo = "ACE_M7A3";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_M7A3";
		ACE_Weight = 0.524;
		ACE_Size = 100;
	};
	class ACE_RG60A: ACE_M7A3
	{
		model = "\x\ace\addons\sys_gas\ACE_RG60A.p3d";
		picture = "\x\ace\addons\sys_gas\data\equip\m_rg60a_ca.paa";
		displayName = "$STR_DN_ACE_RG60A";
		ammo = "ACE_RG60A";
	};
	class 1Rnd_Smoke_M203;
	class ACE_1Rnd_CS_M203: 1Rnd_Smoke_M203
	{
		displayName = "$STR_DN_ACE_1RND_CS_M203";
		displaynameshort = "CN";
		ammo = "ACE_G_40mm_CS";
		model = "\x\ace\addons\m_wep_magazines\ace_m651.p3d";
		picture = "\x\ace\addons\sys_gas\data\equip\m_m651_CN_ca.paa";
		descriptionShort = "$STR_DSS_ACE_1RND_CS_M203";
		class Library
		{
			libTextDesc = "";
		};
		ACE_Weight = 0.29;
		ACE_Size = 146;
	};
	class ACE_6Rnd_CS_M32: ACE_1Rnd_CS_M203
	{
		displayName = "$STR_DN_ACE_6RND_CS_M32";
		count = 6;
		type = 512;
		descriptionShort = "$STR_DSS_ACE_6RND_CS_M32";
		ACE_Weight = "0.29 * 6";
		ACE_Size = "146 * 6";
	};
	class 1Rnd_SMOKE_GP25;
	class ACE_1Rnd_CS_GP25: 1Rnd_SMOKE_GP25
	{
		displayName = "$STR_DN_ACE_1RND_CS_GP25";
		displaynameshort = "CS";
		ammo = "ACE_GVOZD_CS";
		picture = "\x\ace\addons\sys_gas\data\equip\m_gvozd_ca.paa";
		model = "\x\ace\addons\m_wep_magazines\ace_gvozd.p3d";
		descriptionShort = "$STR_DSS_ACE_1RND_CS_GP25";
		class Library
		{
			libTextDesc = "";
		};
		ACE_Weight = 0.29;
		ACE_Size = 146;
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle;
		class ACE_TeargasMuzzle: ThrowMuzzle
		{
			displayName = "$STR_WDN_ACE_TEARGAS";
			magazines[] = {"ACE_M7A3","ACE_RG60A"};
			sound[] = {"\x\ace\addons\sys_gas\grenade_pin.wss",0.177828,1,20};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_gas
	{
		init = "call ('\x\ace\addons\sys_gas\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_gas\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
//};
