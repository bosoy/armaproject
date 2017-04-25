////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:06:28 2013 : Created on Sat Jun 08 13:06:28 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_flashbang : config.bin{
class CfgPatches
{
	class ace_sys_flashbang
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","CBA_MAIN","ace_main","ace_fx"};
		version = "1.14.0.593";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_flashbang
		{
			list[] = {"ace_sys_flashbang"};
		};
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle;
		class ACE_FlashbangMuzzle: ThrowMuzzle
		{
			displayName = "$STR_DN_ACE_FLASHBANG";
			magazines[] = {"ACE_Flashbang","ACE_Flashbang2","ACE_Flashbang9","ACE_M84","ACE_TORCH_C"};
			sound[] = {"\x\ace\addons\sys_flashbang\grenade_pin.wss",0.177828,1,20};
		};
	};
};
class CfgAmmo
{
	class SmokeShell;
	class ACE_Flashbang: SmokeShell
	{
		cost = 100;
		fuseDistance = 0;
		whistleDist = 0;
		whistleOnFire = 0;
		visibleFire = 0.025;
		audibleFire = 0.025;
		visibleFireTime = 0.5;
		displayName = "$STR_DN_ACE_FLASHBANG";
		model = "\x\ace\addons\sys_flashbang\ace_flashbang_armed.p3d";
		hit = 0.5;
		indirectHit = 0.1;
		indirectHitRange = 0.5;
		explosive = 0;
		deflecting = 2;
		explosionTime = 2;
		timeToLive = 30;
		CraterEffects = "";
		explosionEffects = "NoEffect";
		effectsSmoke = "NoEffect";
		soundDefault1[] = {"\x\ace\addons\sys_flashbang\flashbang_exp1.ogg",3.16228,1,500};
		soundDefault2[] = {"\x\ace\addons\sys_flashbang\flashbang_exp2.ogg",3.16228,1,500};
		soundFly[] = {"",1,1};
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
		ACE_Simulation = "shotFlashbang";
		class ACE
		{
			class ACE_FLASHBANG
			{
				sound = "ACE_Flashbang_1Bang1";
				nofx = 1;
				delay = 0;
			};
		};
	};
	class ACE_M84: ACE_Flashbang
	{
		model = "\x\ace\addons\sys_flashbang\ace_m84_armed.p3d";
		displayName = "$STR_DN_ACE_M84";
	};
	class ACE_TORCH_C: ACE_Flashbang
	{
		model = "\x\ace\addons\sys_flashbang\ace_torch_c_armed.p3d";
		displayName = "$STR_DN_ACE_TORCH_C";
	};
	class ACE_Flashbang2: ACE_Flashbang
	{
		model = "\x\ace\addons\sys_flashbang\ace_irritationskoerper2_armed.p3d";
		displayName = "$STR_DN_ACE_FLASHBANG2";
		explosionEffects = "NoEffect";
		soundDefault1[] = {"\x\ace\addons\sys_flashbang\flashbang2_exp2.ogg",1,1,500};
		soundDefault2[] = {"\x\ace\addons\sys_flashbang\flashbang2_exp2.ogg",1,1,500};
		class ACE: ACE
		{
			class ACE_FLASHBANG: ACE_FLASHBANG
			{
				sound = "ACE_Flashbang_1Bang1";
				nofx = 2;
				delay = 0.3;
			};
		};
	};
	class ACE_Flashbang9: ACE_Flashbang2
	{
		model = "\x\ace\addons\sys_flashbang\ace_irritationskoerper9_armed.p3d";
		displayName = "$STR_DN_ACE_FLASHBANG9";
		explosionEffects = "NoEffect";
		soundDefault1[] = {"\x\ace\addons\sys_flashbang\flashbang9_exp2.ogg",1,1,500};
		soundDefault2[] = {"\x\ace\addons\sys_flashbang\flashbang9_exp2.ogg",1,1,500};
		class ACE: ACE
		{
			class ACE_FLASHBANG: ACE_FLASHBANG
			{
				sound = "ACE_Flashbang_1Bang1";
				nofx = 9;
				delay = 0.3;
			};
		};
	};
	class G_40mm_Smoke;
	class ACE_VG40SZ: G_40mm_Smoke
	{
		fuseDistance = 5;
		displayName = "$STR_DN_ACE_VG40SZ";
		hit = 0.1;
		indirectHit = 0.1;
		indirectHitRange = 0.125;
		simulation = "shotSmoke";
		CraterEffects = "";
		explosionEffects = "NoEffect";
		effectsSmoke = "NoEffect";
		soundFly[] = {"",1,1};
		ACE_Simulation = "shotFlashbangGL";
		class ACE
		{
			class ACE_FLASHBANG
			{
				sound = "ACE_Flashbang_1Bang1";
				nofx = 1;
				delay = 0;
			};
		};
	};
};
class CfgMagazines
{
	class SmokeShell;
	class ACE_Flashbang: SmokeShell
	{
		model = "\x\ace\addons\sys_flashbang\ace_flashbang.p3d";
		picture = "\x\ace\addons\sys_flashbang\data\equip\m_FlashBang_ca.paa";
		displayName = "$STR_DN_ACE_FLASHBANG";
		displaynameshort = "";
		ammo = "ACE_Flashbang";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_FLASHBANG";
		ACE_Weight = 0.235;
		ACE_Size = 340;
	};
	class ACE_M84: ACE_Flashbang
	{
		model = "\x\ace\addons\sys_flashbang\ace_m84.p3d";
		picture = "\x\ace\addons\sys_flashbang\data\equip\m_m84_ca.paa";
		displayName = "$STR_DN_ACE_M84";
		ammo = "ACE_M84";
		ACE_Weight = 0.377;
	};
	class ACE_TORCH_C: ACE_Flashbang
	{
		model = "\x\ace\addons\sys_flashbang\ace_torch_c.p3d";
		picture = "\x\ace\addons\sys_flashbang\data\equip\m_torch_c_ca.paa";
		displayName = "$STR_DN_ACE_TORCH_C";
		ammo = "ACE_TORCH_C";
		ACE_Weight = 0.377;
	};
	class ACE_Flashbang2: ACE_Flashbang
	{
		model = "\x\ace\addons\sys_flashbang\ace_irritationskoerper2.p3d";
		picture = "\x\ace\addons\sys_flashbang\data\equip\w_flashbang9_co.paa";
		displayName = "$STR_DN_ACE_FLASHBANG2";
		ammo = "ACE_Flashbang2";
	};
	class ACE_Flashbang9: ACE_Flashbang2
	{
		model = "\x\ace\addons\sys_flashbang\ace_irritationskoerper9.p3d";
		picture = "\x\ace\addons\sys_flashbang\data\equip\w_flashbang9_co.paa";
		displayName = "$STR_DN_ACE_FLASHBANG9";
		ammo = "ACE_Flashbang9";
	};
	class 1Rnd_SMOKE_GP25;
	class ACE_VG40SZ: 1Rnd_SMOKE_GP25
	{
		displayName = "$STR_DN_ACE_VG40SZ";
		displayNameShort = "";
		ammo = "ACE_VG40SZ";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_FLASHBANG";
		ACE_Weight = 0.235;
		ACE_Size = 250;
	};
};
class CfgSounds
{
	class ACE_Flashbang_1Bang1
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_flashbang\flashbang_exp1.ogg",1,1};
		titles[] = {};
	};
	class ACE_Flashbang_1Bang2
	{
		name = "";
		sound[] = {"\x\ace\addons\sys_flashbang\flashbang_exp2.ogg",1,1};
		titles[] = {};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_flashbang
	{
		init = "call ('\x\ace\addons\sys_flashbang\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
//};
