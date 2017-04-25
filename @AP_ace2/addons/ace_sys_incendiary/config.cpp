////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:33:47 2012 : Created on Fri Nov 09 22:33:47 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_incendiary : config.bin{
class CfgPatches
{
	class ace_sys_incendiary
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","CBA_MAIN","ace_main"};
		version = "1.14.0.581";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_incendiary
		{
			list[] = {"ace_sys_incendiary"};
		};
	};
};
class ACE_Incendiary
{
	class Cmeasures1
	{
		simulation = "particles";
		type = "Cmeasures1";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Cmeasures2
	{
		simulation = "particles";
		type = "Cmeasures2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Light1
	{
		simulation = "light";
		type = "CmeasuresLight";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class CfgAmmo
{
	class SmokeShell;
	class ACE_ANM14TH3: SmokeShell
	{
		ace_fire = 1;
		fuseDistance = 0;
		whistleDist = 0;
		whistleOnFire = 0;
		displayName = "$STR_DN_ACE_ANM14";
		model = "\x\ace\addons\sys_incendiary\ace_anm14th3_armed.p3d";
		hit = 5;
		indirectHit = 4;
		indirectHitRange = 1.1;
		deflecting = 20;
		explosionTime = 3;
		soundHit[] = {"\x\ace\addons\sys_incendiary\incen_exp1.ogg",0,1};
		soundDefault1[] = {"\x\ace\addons\sys_incendiary\incen_exp1.ogg",3.16228,1,500};
		soundDefault2[] = {"\x\ace\addons\sys_incendiary\incen_exp2.ogg",3.16228,1,500};
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
		ACE_Simulation = "shotIncendiary";
		timeToLive = 40;
		effectsSmoke = "ACE_Incendiary";
	};
};
class CfgMagazines
{
	class SmokeShell;
	class ACE_ANM14: SmokeShell
	{
		model = "\x\ace\addons\sys_incendiary\ace_anm14th3.p3d";
		picture = "\x\ace\addons\sys_incendiary\data\equip\m_ace_anm14th3_ca.paa";
		displayName = "$STR_DN_ACE_ANM14";
		displaynameshort = "$STR_DN_ACE_ANM14";
		ammo = "ACE_ANM14TH3";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_ANM14";
		ACE_Weight = 0.907;
		ACE_Size = 409;
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle;
		class ACE_IncendiaryMuzzle: ThrowMuzzle
		{
			displayName = "$STR_WDN_ACE_INCENDIARYRULEZ";
			magazines[] = {"ACE_ANM14"};
			sound[] = {"\x\ace\addons\sys_incendiary\grenade_pin.wss",0.177828,1,20};
		};
	};
};
class CfgVehicles
{
	class Thing;
	class ACE_IncendiaryWreck: Thing
	{
		scope = 1;
		displayName = "";
		model = "\x\ace\addons\sys_incendiary\ace_garbage.p3d";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_incendiary
	{
		init = "call ('\x\ace\addons\sys_incendiary\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
//};
