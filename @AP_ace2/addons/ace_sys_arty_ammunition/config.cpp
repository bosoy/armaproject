////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:18 2013 : Created on Mon Oct 14 23:06:18 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_arty_ammunition : config.bin{
class CfgPatches
{
	class ace_sys_arty_ammunition
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","ace_sys_arty","ace_main","ace_sys_interaction","ace_sys_huntir","ace_sys_disposal","ace_sys_crewserved"};
		version = "1.14.0.597";
		versionStr = "1.14.0.597";
		versionAr[] = {1,14,0,597};
		author[] = {"Falcone","Nou","Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_arty_ammunition
		{
			list[] = {"ace_sys_arty_ammunition"};
		};
	};
};
class CfgAmmo
{
	class ShellBase;
	class ace_arty_howitzer_base: ShellBase
	{
		whistleOnFire = 200;
		artilleryLock = 0;
	};
	class ace_arty_baseEject: ShellBase
	{
		hit = 20;
		indirectHit = 20;
		indirectHitRange = 10;
		typicalSpeed = 100;
		explosive = 1;
		cost = 300;
		model = "\ca\weapons\empty";
		airFriction = 0;
		timeToLive = 1;
		explosionTime = 0.001;
		soundFly[] = {"",1,1};
		soundEngine[] = {"",1,4};
		CraterEffects = "GrenadeCrater";
		explosionEffects = "GrenadeExplosion";
		muzzleEffect = "BIS_Effects_Rifle";
		soundHit[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.23413,1,1800};
		soundDefault1[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.2341,1,1800};
		soundDefault2[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.2341,1,1800};
		soundDefault3[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.2341,1,1800};
		hitGroundSoft[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGroundHard[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMan[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitArmor[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitIron[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitBuilding[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitFoliage[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitWood[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlass[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlassArmored[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitConcrete[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitRubber[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitPlastic[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitDefault[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMetal[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMetalplate[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
	};
	class GrenadeBase;
	class ace_arty_howitzer_60mm_base: GrenadeBase
	{
		whistleDist = 1500;
		deflecting = 0;
	};
	class ace_arty_60mm_m720a1_m734_pd: ace_arty_howitzer_60mm_base
	{
		hit = 110;
		indirecthit = 20;
		indirecthitrange = 9;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\ace_arty_m720a1_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "GrenadeCrater";
		ExplosionEffects = "GrenadeExplosion";
		caliber = 6;
	};
	class ace_arty_60mm_m720a1_m734_prox: ace_arty_60mm_m720a1_m734_pd
	{
		CraterEffects = "";
		ExplosionEffects = "";
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m734\fuze_prox.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_60mm_m720a1_explosion";
	};
	class ace_arty_60mm_m720a1_m734_delay: ace_arty_60mm_m720a1_m734_prox
	{
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m734\fuze_delay.sqf";
		soundHit[] = {"",0,1,0};
		ACE_FRAG_SKIP = 1;
	};
	class ace_arty_60mm_m720a1_m734_nsb: ace_arty_60mm_m720a1_m734_prox
	{
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m734\fuze_nsb.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_60mm_m720a1_explosion";
	};
	class ace_arty_60mm_m720a1_explosion: ace_arty_howitzer_60mm_base
	{
		hit = 110;
		indirecthit = 20;
		indirecthitrange = 9;
		explosionTime = 0.0001;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\ace_arty_m720a1_shell.p3d";
		CraterEffects = "GrenadeCrater";
		ExplosionEffects = "GrenadeExplosion";
	};
	class ace_arty_60mm_m720a1_delay_action: ace_arty_60mm_m720a1_m734_pd
	{
		explosionTime = 0.05;
		deflecting = 65;
	};
	class ace_arty_60mm_m721_m776_time: ace_arty_howitzer_60mm_base
	{
		hit = 0;
		indirecthit = 0;
		indirecthitrange = 0;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 0.01;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\ace_arty_m721_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "GrenadeExplosion";
		caliber = 6;
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 500;
		ACE_ARTY_BASEEJECT_COMPENSATE = 0;
		ACE_ARTY_BASEEJECT_POWER = 0.25;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m776\fuze_time.sqf";
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\60mm\eject_illum.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_60mm_m722a1_m745_pd: ace_arty_howitzer_60mm_base
	{
		hit = 110;
		indirecthit = 15;
		indirecthitrange = 5;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\ace_arty_m722a1_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "ace_arty_WPExplosion";
		caliber = 6;
	};
	class FlareBase;
	class ace_arty_60mm_m721_m766_flare: FlareBase
	{
		model = "\ca\Weapons\granat";
		lightColor[] = {0.8,0.8,0.8,0};
		deflecting = 65;
	};
	class ace_arty_howitzer_81mm_base: ace_arty_howitzer_base
	{
		whistleDist = 1500;
	};
	class ace_arty_81mm_m821a2_m734_pd: ace_arty_howitzer_81mm_base
	{
		hit = 160;
		indirectHit = 30;
		indirectHitRange = 15;
		typicalSpeed = 800;
		timeToLive = 500;
		explosive = 1;
		cost = 200;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\default_60mm_shell";
		airFriction = -7.58e-005;
		CraterEffects = "ArtyShellCrater";
		ExplosionEffects = "ArtyShellExplosion";
		muzzleEffect = "BIS_Effects_HeavyCaliber";
		caliber = 6;
	};
	class ace_arty_81mm_m821a2_m734_prox: ace_arty_81mm_m821a2_m734_pd
	{
		CraterEffects = "";
		ExplosionEffects = "";
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m734\fuze_prox.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_81mm_m821a2_explosion";
	};
	class ace_arty_81mm_m821a2_m734_nsb: ace_arty_81mm_m821a2_m734_prox
	{
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m734\fuze_nsb.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_81mm_m821a2_explosion";
	};
	class ace_arty_81mm_m821a2_m734_delay: ace_arty_81mm_m821a2_m734_prox
	{
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m734\fuze_delay.sqf";
		soundHit[] = {"",0,1,0};
		ACE_FRAG_SKIP = 1;
	};
	class ace_arty_81mm_m821a2_explosion: ace_arty_howitzer_81mm_base
	{
		hit = 160;
		indirectHit = 30;
		indirectHitRange = 15;
		explosionTime = 0.0001;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\default_60mm_shell";
		CraterEffects = "ArtyShellCrater";
		ExplosionEffects = "ArtyShellExplosion";
	};
	class ace_arty_81mm_m821a2_delay_action: ace_arty_81mm_m821a2_m734_pd
	{
		explosionTime = 0.05;
		deflecting = 65;
	};
	class ace_arty_81mm_m853a1_m772_time: ace_arty_howitzer_81mm_base
	{
		hit = 5;
		indirecthit = 0;
		indirecthitrange = 0;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 0.01;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\default_60mm_shell";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "GrenadeExplosion";
		caliber = 6;
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 500;
		ACE_ARTY_BASEEJECT_COMPENSATE = 0;
		ACE_ARTY_BASEEJECT_POWER = 0.25;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m772\fuze_time.sqf";
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\81mm\eject_illum.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_81mm_m375a3_m524_pd: ace_arty_howitzer_81mm_base
	{
		hit = 110;
		indirecthit = 25;
		indirecthitrange = 7;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\default_60mm_shell";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "ace_arty_WPExplosion";
		caliber = 6;
	};
	class ace_arty_81mm_m853a1_m772_flare: FlareBase
	{
		model = "\ca\Weapons\granat";
		lightColor[] = {0.8,0.8,0.8,0};
		deflecting = 65;
	};
	class ace_arty_howitzer_82mm_base: ace_arty_howitzer_base
	{
		whistleDist = 1500;
	};
	class ace_arty_82mm_he_pd: ace_arty_howitzer_82mm_base
	{
		hit = 110;
		indirecthit = 31;
		indirecthitrange = 15;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\82mm\ace_arty_82mm_he_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "ArtyShellCrater";
		ExplosionEffects = "ArtyShellExplosion";
		muzzleEffect = "BIS_Effects_HeavyCaliber";
		caliber = 6;
	};
	class ace_arty_82mm_he_explosion: ace_arty_howitzer_82mm_base
	{
		hit = 110;
		indirecthit = 31;
		indirecthitrange = 15;
		explosionTime = 0.0001;
		model = "\x\ace\addons\sys_arty_ammunition\82mm\ace_arty_82mm_he_shell.p3d";
		CraterEffects = "ArtyShellCrater";
		ExplosionEffects = "ArtyShellExplosion";
		muzzleEffect = "BIS_Effects_HeavyCaliber";
	};
	class ace_arty_82mm_illum_time: ace_arty_howitzer_82mm_base
	{
		hit = 0;
		indirecthit = 0;
		indirecthitrange = 0;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 0.01;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\82mm\ace_arty_82mm_illum_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "GrenadeExplosion";
		caliber = 6;
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 500;
		ACE_ARTY_BASEEJECT_COMPENSATE = 0;
		ACE_ARTY_BASEEJECT_POWER = 0.25;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\time\fuze_time.sqf";
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\82mm\eject_illum.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_82mm_wp_pd: ace_arty_howitzer_82mm_base
	{
		hit = 110;
		indirecthit = 25;
		indirecthitrange = 7;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\82mm\ace_arty_82mm_smoke_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "ace_arty_WPExplosion";
		caliber = 6;
	};
	class ace_arty_82mm_illum_flare: FlareBase
	{
		model = "\ca\Weapons\granat";
		lightColor[] = {0.8,0.8,0.8,0};
		deflecting = 65;
	};
	class ace_arty_howitzer_105mm_base: ace_arty_howitzer_base
	{
		whistleDist = 1500;
	};
	class ace_arty_105mm_m1_m782_pd: ace_arty_howitzer_105mm_base
	{
		hit = 110;
		indirecthit = 50;
		indirecthitrange = 11.52;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m1_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "ArtyShellCrater";
		ExplosionEffects = "ArtyShellExplosion";
		caliber = 6;
	};
	class ace_arty_105mm_m1_m782_time: ace_arty_105mm_m1_m782_pd
	{
		hit = 0;
		indirecthit = 0;
		indirecthitrange = 0;
		CraterEffects = "";
		ExplosionEffects = "";
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m782\fuze_time.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_105mm_m1_explosion";
	};
	class ace_arty_105mm_m1_m782_prox: ace_arty_105mm_m1_m782_time
	{
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m782\fuze_prox.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_105mm_m1_explosion";
	};
	class ace_arty_105mm_m1_m782_delay: ace_arty_105mm_m1_m782_prox
	{
		ACE_FRAG_SKIP = 1;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m782\fuze_delay.sqf";
		soundHit[] = {"",0,1,0};
	};
	class ace_arty_105mm_m1_explosion: ace_arty_howitzer_105mm_base
	{
		hit = 110;
		indirecthit = 50;
		indirecthitrange = 11.52;
		explosionTime = 0.0001;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m1_shell.p3d";
	};
	class ace_arty_105mm_m1_delay_action: ace_arty_105mm_m1_m782_pd
	{
		explosionTime = 0.05;
		deflecting = 65;
	};
	class ace_arty_105mm_m314a3_m782: ace_arty_howitzer_105mm_base
	{
		hit = 0;
		indirecthit = 0;
		indirecthitrange = 0;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 0.01;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m314a3_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "GrenadeExplosion";
		caliber = 6;
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 500;
		ACE_ARTY_BASEEJECT_COMPENSATE = 0;
		ACE_ARTY_BASEEJECT_POWER = 0.25;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m782\fuze_time.sqf";
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\105mm\eject_illum.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_105mm_m84a1_m782: ace_arty_howitzer_105mm_base
	{
		hit = 0;
		indirecthit = 0;
		indirecthitrange = 0;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 0.01;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m84a1_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "WPExplosion";
		caliber = 6;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m782\fuze_time.sqf";
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 150;
		ACE_ARTY_BASEEJECT_COMPENSATE = 1;
		ACE_ARTY_BASEEJECT_POWER = 0.125;
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\105mm\eject_smoke_m84.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_105mm_m916_m782: ace_arty_howitzer_105mm_base
	{
		hit = 0;
		indirecthit = 0;
		indirecthitrange = 5;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 0.01;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m916_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "";
		caliber = 6;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m782\fuze_time.sqf";
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 50;
		ACE_ARTY_BASEEJECT_COMPENSATE = 1;
		ACE_ARTY_BASEEJECT_POWER = 0.25;
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\105mm\eject_dpicm.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_105mm_m60a2_m782_pd: ace_arty_howitzer_105mm_base
	{
		hit = 110;
		indirecthit = 50;
		indirecthitrange = 11.52;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m60a2_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "ace_arty_WPExplosion";
		caliber = 6;
	};
	class ARTY_SmokeShellWhite;
	class ace_arty_105mm_m84a1_m782_smokeCanisterHC: ARTY_SmokeShellWhite
	{
		explosionTime = 6;
		timeToLive = 120;
		smokeColor[] = {1,1,1,1};
		effectsSmoke = "ace_arty_105mm_m84a1_m782_smokeCanisterHC_effect";
		model = "\ca\Weapons\granat";
	};
	class ace_arty_105mm_m314a3_m782_flare: FlareBase
	{
		model = "\ca\Weapons\granat";
		lightColor[] = {0.8,0.8,0.8,0};
		deflecting = 65;
	};
	class G_40mm_HE;
	class ace_arty_dpicm_m80: G_40mm_HE
	{
		hit = 100;
		ace_hit = 100;
		ace_heat = 1;
		indirectHit = 24;
		indirectHitRange = 5;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m80_bomblet.p3d";
		ExplosionEffects = "ace_arty_dpicmEffects";
	};
	class ace_arty_howitzer_120mm_base: ace_arty_howitzer_base
	{
		whistleDist = 1500;
	};
	class ace_arty_120mm_dm11a5_dm111a1_pd: ace_arty_howitzer_120mm_base
	{
		hit = 290;
		indirectHit = 50;
		indirectHitRange = 20;
		typicalSpeed = 800;
		timeToLive = 500;
		explosive = 0.8;
		cost = 200;
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm11_shell";
		airFriction = -7.58e-005;
		CraterEffects = "ArtyShellCrater";
		ExplosionEffects = "ArtyShellExplosion";
		muzzleEffect = "BIS_Effects_Cannon";
		caliber = 6;
	};
	class ace_arty_120mm_dm61_ppd_prox: ace_arty_120mm_dm11a5_dm111a1_pd
	{
		CraterEffects = "";
		ExplosionEffects = "";
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m734\fuze_prox.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_120mm_dm11dm61_explosion";
	};
	class ace_arty_120mm_dm11dm61_explosion: ace_arty_howitzer_120mm_base
	{
		hit = 290;
		indirectHit = 50;
		indirectHitRange = 20;
		explosionTime = 0.0001;
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm11_shell";
		CraterEffects = "ArtyShellCrater";
		ExplosionEffects = "ArtyShellExplosion";
	};
	class ace_arty_120mm_dm26_dm93_time: ace_arty_howitzer_120mm_base
	{
		hit = 5;
		indirecthit = 0;
		indirecthitrange = 0;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 0.01;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm26_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "GrenadeExplosion";
		caliber = 6;
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 500;
		ACE_ARTY_BASEEJECT_COMPENSATE = 0;
		ACE_ARTY_BASEEJECT_POWER = 0.25;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m772\fuze_time.sqf";
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\120mm\eject_illum.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_120mm_dm35_dm93_time: ace_arty_howitzer_120mm_base
	{
		hit = 0;
		indirecthit = 0;
		indirecthitrange = 0;
		typicalSpeed = 300;
		timeToLive = 500;
		explosive = 1;
		cost = 300;
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm35_shell.p3d";
		airFriction = -7.58e-005;
		CraterEffects = "";
		ExplosionEffects = "WPExplosion";
		caliber = 6;
		ACE_ARTY_FIRE_HANDLER = "\x\ace\addons\sys_arty_ammunition\fuzes\m782\fuze_time.sqf";
		ACE_ARTY_ISBASEEJECTING = 1;
		ACE_ARTY_BASEEJECT_HOB = 150;
		ACE_ARTY_BASEEJECT_COMPENSATE = 1;
		ACE_ARTY_BASEEJECT_POWER = 0.125;
		ACE_ARTY_BASE_EJECT_HANDLER = "\x\ace\addons\sys_arty_ammunition\120mm\eject_smoke_m84.sqf";
		ACE_ARTY_EXPLOSION = "ace_arty_baseEject";
	};
	class ace_arty_120mm_dm26_dm93_flare: FlareBase
	{
		model = "\ca\Weapons\granat";
		lightColor[] = {0.8,0.8,0.8,0};
		deflecting = 65;
	};
	class Sh_125_SABOT;
	class ace_arty_155mm_bonus_EFP: Sh_125_SABOT
	{
		hit = 1000;
		indirectHit = 11;
		indirectHitRange = 2;
		typicalSpeed = 2000;
		deflecting = 0;
		airFriction = -4e-005;
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class VehicleMagazine;
	class ace_arty_howitzer_default: CA_Magazine
	{
		nameSound = "heat";
		ammo = "ace_arty_howitzer_base";
		initSpeed = 0;
		scope = 2;
		count = 1;
	};
	class ace_arty_howitzer_mag: VehicleMagazine
	{
		nameSound = "heat";
		scope = 2;
		count = 1;
	};
	class ace_arty_60mm_default: ace_arty_howitzer_default
	{
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\60mm\tables\ace_arty_60mm_genericBtab_%1_chg%2.sqf";
		ACE_ARTY_BTABS_KEY = "ace_arty_60mm_genericBtab_%1_chg%2";
		scope = 2;
		ACE_Weight = 1.66;
	};
	class ace_arty_60mm_m720a1: ace_arty_60mm_default
	{
		scope = 1;
		type = 0;
		displayName = "60mm M720A1 HE";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_60mm_m720a1_m734_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m720a1_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd","prox","nsb","delay"};
		ACE_ARTY_FUZE_DESC[] = {"Impact Burst","Proximity Burst","Near-Surface Burst","Delay"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_60mm_m720a1_m734_pd","ace_arty_60mm_m720a1_m734_prox","ace_arty_60mm_m720a1_m734_nsb","ace_arty_60mm_m720a1_m734_delay"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "HE";
		ACE_Weight = 1.66;
	};
	class ace_arty_60mm_m720a1_m734_pd_chg0: ace_arty_howitzer_mag
	{
		displayName = "60mm M720A1 IMP Chg. 0";
		ammo = "ace_arty_60mm_m720a1_m734_pd";
		initSpeed = 64;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_60mm_m720a1";
		ACE_Weight = 1.66;
	};
	class ace_arty_60mm_m720a1_m734_pd_chg1: ace_arty_60mm_m720a1_m734_pd_chg0
	{
		initSpeed = 124;
		displayName = "60mm M720A1 IMP Chg. 1";
	};
	class ace_arty_60mm_m720a1_m734_pd_chg2: ace_arty_60mm_m720a1_m734_pd_chg0
	{
		initSpeed = 160.16;
		displayName = "60mm M720A1 IMP Chg. 2";
	};
	class ace_arty_60mm_m720a1_m734_pd_chg3: ace_arty_60mm_m720a1_m734_pd_chg0
	{
		initSpeed = 180.92;
		displayName = "60mm M720A1 IMP Chg. 3";
	};
	class ace_arty_60mm_m720a1_m734_pd_chg4: ace_arty_60mm_m720a1_m734_pd_chg0
	{
		initSpeed = 207.264;
		displayName = "60mm M720A1 IMP Chg. 4";
	};
	class ace_arty_60mm_m720a1_m734_prox_chg0: ace_arty_howitzer_mag
	{
		displayName = "60mm M720A1 PRX Chg. 0";
		ammo = "ace_arty_60mm_m720a1_m734_prox";
		initSpeed = 64;
		ACE_Weight = 1.66;
	};
	class ace_arty_60mm_m720a1_m734_prox_chg1: ace_arty_60mm_m720a1_m734_prox_chg0
	{
		initSpeed = 124;
		displayName = "60mm M720A1 PRX Chg. 1";
	};
	class ace_arty_60mm_m720a1_m734_prox_chg2: ace_arty_60mm_m720a1_m734_prox_chg0
	{
		initSpeed = 160.16;
		displayName = "60mm M720A1 PRX Chg. 2";
	};
	class ace_arty_60mm_m720a1_m734_prox_chg3: ace_arty_60mm_m720a1_m734_prox_chg0
	{
		initSpeed = 180.92;
		displayName = "60mm M720A1 PRX Chg. 3";
	};
	class ace_arty_60mm_m720a1_m734_prox_chg4: ace_arty_60mm_m720a1_m734_prox_chg0
	{
		initSpeed = 207.264;
		displayName = "60mm M720A1 PRX Chg. 4";
	};
	class ace_arty_60mm_m720a1_m734_delay_chg0: ace_arty_howitzer_mag
	{
		displayName = "60mm M720A1 DLY Chg. 0";
		ammo = "ace_arty_60mm_m720a1_m734_delay";
		initSpeed = 64;
		ACE_Weight = 1.66;
	};
	class ace_arty_60mm_m720a1_m734_delay_chg1: ace_arty_60mm_m720a1_m734_delay_chg0
	{
		initSpeed = 124;
		displayName = "60mm M720A1 DLY Chg. 1";
	};
	class ace_arty_60mm_m720a1_m734_delay_chg2: ace_arty_60mm_m720a1_m734_delay_chg0
	{
		initSpeed = 160.16;
		displayName = "60mm M720A1 DLY Chg. 2";
	};
	class ace_arty_60mm_m720a1_m734_delay_chg3: ace_arty_60mm_m720a1_m734_delay_chg0
	{
		initSpeed = 180.92;
		displayName = "60mm M720A1 DLY Chg. 3";
	};
	class ace_arty_60mm_m720a1_m734_delay_chg4: ace_arty_60mm_m720a1_m734_delay_chg0
	{
		initSpeed = 207.264;
		displayName = "60mm M720A1 DLY Chg. 4";
	};
	class ace_arty_60mm_m720a1_m734_nsb_chg0: ace_arty_howitzer_mag
	{
		displayName = "60mm M720A1 NSB Chg. 0";
		ammo = "ace_arty_60mm_m720a1_m734_nsb";
		initSpeed = 64;
		ACE_Weight = 1.66;
	};
	class ace_arty_60mm_m720a1_m734_nsb_chg1: ace_arty_60mm_m720a1_m734_nsb_chg0
	{
		initSpeed = 124;
		displayName = "60mm M720A1 NSB Chg. 1";
	};
	class ace_arty_60mm_m720a1_m734_nsb_chg2: ace_arty_60mm_m720a1_m734_nsb_chg0
	{
		initSpeed = 160.16;
		displayName = "60mm M720A1 NSB Chg. 2";
	};
	class ace_arty_60mm_m720a1_m734_nsb_chg3: ace_arty_60mm_m720a1_m734_nsb_chg0
	{
		initSpeed = 180.92;
		displayName = "60mm M720A1 NSB Chg. 3";
	};
	class ace_arty_60mm_m720a1_m734_nsb_chg4: ace_arty_60mm_m720a1_m734_nsb_chg0
	{
		initSpeed = 207.264;
		displayName = "60mm M720A1 NSB Chg. 4";
	};
	class ace_arty_60mm_m721: ace_arty_60mm_default
	{
		scope = 1;
		type = 0;
		displayName = "60mm M721 Illumination";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_60mm_m721_m776_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m721_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_60mm_m721_m776_time"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "ILLUM";
		ACE_Weight = 1.71;
	};
	class ace_arty_60mm_m721_m776_time_chg0: ace_arty_howitzer_mag
	{
		displayName = "60mm M721 M776 TIME Chg. 0";
		ammo = "ace_arty_60mm_m721_m776_time";
		initSpeed = 64;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_60mm_m721";
		ACE_Weight = 1.71;
	};
	class ace_arty_60mm_m721_m776_time_chg1: ace_arty_60mm_m721_m776_time_chg0
	{
		initSpeed = 124;
		displayName = "60mm M721 M776 TIME Chg. 1";
	};
	class ace_arty_60mm_m721_m776_time_chg2: ace_arty_60mm_m721_m776_time_chg0
	{
		initSpeed = 160.16;
		displayName = "60mm M721 M776 TIME Chg. 2";
	};
	class ace_arty_60mm_m721_m776_time_chg3: ace_arty_60mm_m721_m776_time_chg0
	{
		initSpeed = 180.92;
		displayName = "60mm M721 M776 TIME Chg. 3";
	};
	class ace_arty_60mm_m721_m776_time_chg4: ace_arty_60mm_m721_m776_time_chg0
	{
		initSpeed = 207.264;
		displayName = "60mm M721 M776 TIME Chg. 4";
	};
	class ace_arty_60mm_m722a1: ace_arty_60mm_default
	{
		scope = 1;
		type = 0;
		displayName = "60mm M722A1 WP";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_60mm_m722a1_m745_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m722a1_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd"};
		ACE_ARTY_FUZE_DESC[] = {"Point Detonate"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_60mm_m722a1_m745_pd"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "WP";
		ACE_Weight = 1.68;
	};
	class ace_arty_60mm_m722a1_m745_pd_chg0: ace_arty_howitzer_mag
	{
		displayName = "60mm M722A1 M745 PD Chg. 0";
		ammo = "ace_arty_60mm_m722a1_m745_pd";
		initSpeed = 64;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_60mm_m722a1_m745";
		ACE_Weight = 1.68;
	};
	class ace_arty_60mm_m722a1_m745_pd_chg1: ace_arty_60mm_m722a1_m745_pd_chg0
	{
		initSpeed = 124;
		displayName = "60mm M722A1 M745 PD Chg. 1";
	};
	class ace_arty_60mm_m722a1_m745_pd_chg2: ace_arty_60mm_m722a1_m745_pd_chg0
	{
		initSpeed = 160.16;
		displayName = "60mm M722A1 M745 PD Chg. 2";
	};
	class ace_arty_60mm_m722a1_m745_pd_chg3: ace_arty_60mm_m722a1_m745_pd_chg0
	{
		initSpeed = 180.92;
		displayName = "60mm M722A1 M745 PD Chg. 3";
	};
	class ace_arty_60mm_m722a1_m745_pd_chg4: ace_arty_60mm_m722a1_m745_pd_chg0
	{
		initSpeed = 207.264;
		displayName = "60mm M722A1 M745 PD Chg. 4";
	};
	class ace_arty_81mm_default: ace_arty_howitzer_default
	{
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\81mm\tables\ace_arty_81mm_genericBtab_%1_chg%2.sqf";
		ACE_ARTY_BTABS_KEY = "ace_arty_81mm_genericBtab_%1_chg%2";
		scope = 2;
		ACE_Weight = 4.5;
	};
	class ace_arty_81mm_m821a2: ace_arty_81mm_default
	{
		scope = 1;
		type = 0;
		displayName = "81mm M821A2 HE";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_81mm_m821a2_m734_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m821a2_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd","prox","nsb","delay"};
		ACE_ARTY_FUZE_DESC[] = {"Impact Burst","Proximity Burst","Near-Surface Burst","Delay"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_81mm_m821a2_m734_pd","ace_arty_81mm_m821a2_m734_prox","ace_arty_81mm_m821a2_m734_nsb","ace_arty_81mm_m821a2_m734_delay"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "HE";
		ACE_Weight = 4.5;
	};
	class ace_arty_81mm_m821a2_m734_pd_chg0: ace_arty_howitzer_mag
	{
		displayName = "81mm M821A2 IMP 0";
		ammo = "ace_arty_81mm_m821a2_m734_pd";
		initSpeed = 65.532;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_81mm_m821a2";
		ACE_Weight = 4.5;
	};
	class ace_arty_81mm_m821a2_m734_pd_chg1: ace_arty_81mm_m821a2_m734_pd_chg0
	{
		initSpeed = 133.5;
		displayName = "81mm M821A2 IMP +1";
	};
	class ace_arty_81mm_m821a2_m734_pd_chg2: ace_arty_81mm_m821a2_m734_pd_chg0
	{
		initSpeed = 185.3184;
		displayName = "81mm M821A2 IMP +2";
	};
	class ace_arty_81mm_m821a2_m734_pd_chg3: ace_arty_81mm_m821a2_m734_pd_chg0
	{
		initSpeed = 228.6;
		displayName = "81mm M821A2 IMP +3";
	};
	class ace_arty_81mm_m821a2_m734_pd_chg4: ace_arty_81mm_m821a2_m734_pd_chg0
	{
		initSpeed = 267.9192;
		displayName = "81mm M821A2 IMP +4";
	};
	class ace_arty_81mm_m821a2_m734_prox_chg0: ace_arty_howitzer_mag
	{
		displayName = "81mm M821A2 PRX 0";
		ammo = "ace_arty_81mm_m821a2_m734_prox";
		initSpeed = 65.532;
		ACE_Weight = 4.5;
	};
	class ace_arty_81mm_m821a2_m734_prox_chg1: ace_arty_81mm_m821a2_m734_prox_chg0
	{
		initSpeed = 133.5;
		displayName = "81mm M821A2 PRX +1";
	};
	class ace_arty_81mm_m821a2_m734_prox_chg2: ace_arty_81mm_m821a2_m734_prox_chg0
	{
		initSpeed = 185.3184;
		displayName = "81mm M821A2 PRX +2";
	};
	class ace_arty_81mm_m821a2_m734_prox_chg3: ace_arty_81mm_m821a2_m734_prox_chg0
	{
		initSpeed = 228.6;
		displayName = "81mm M821A2 PRX +3";
	};
	class ace_arty_81mm_m821a2_m734_prox_chg4: ace_arty_81mm_m821a2_m734_prox_chg0
	{
		initSpeed = 267.9192;
		displayName = "81mm M821A2 PRX +4";
	};
	class ace_arty_81mm_m821a2_m734_delay_chg0: ace_arty_howitzer_mag
	{
		displayName = "81mm M821A2 DLY 0";
		ammo = "ace_arty_81mm_m821a2_m734_delay";
		initSpeed = 65.532;
		ACE_Weight = 4.5;
	};
	class ace_arty_81mm_m821a2_m734_delay_chg1: ace_arty_81mm_m821a2_m734_delay_chg0
	{
		initSpeed = 133.5;
		displayName = "81mm M821A2 DLY +1";
	};
	class ace_arty_81mm_m821a2_m734_delay_chg2: ace_arty_81mm_m821a2_m734_delay_chg0
	{
		initSpeed = 185.3184;
		displayName = "81mm M821A2 DLY +2";
	};
	class ace_arty_81mm_m821a2_m734_delay_chg3: ace_arty_81mm_m821a2_m734_delay_chg0
	{
		initSpeed = 228.6;
		displayName = "81mm M821A2 DLY +3";
	};
	class ace_arty_81mm_m821a2_m734_delay_chg4: ace_arty_81mm_m821a2_m734_delay_chg0
	{
		initSpeed = 267.9192;
		displayName = "81mm M821A2 DLY +4";
	};
	class ace_arty_81mm_m821a2_m734_nsb_chg0: ace_arty_howitzer_mag
	{
		displayName = "81mm M821A2 NSB 0";
		ammo = "ace_arty_81mm_m821a2_m734_prox";
		initSpeed = 65.532;
		ACE_Weight = 4.5;
	};
	class ace_arty_81mm_m821a2_m734_nsb_chg1: ace_arty_81mm_m821a2_m734_nsb_chg0
	{
		initSpeed = 133.5;
		displayName = "81mm M821A2 NSB +1";
	};
	class ace_arty_81mm_m821a2_m734_nsb_chg2: ace_arty_81mm_m821a2_m734_nsb_chg0
	{
		initSpeed = 185.3184;
		displayName = "81mm M821A2 NSB +2";
	};
	class ace_arty_81mm_m821a2_m734_nsb_chg3: ace_arty_81mm_m821a2_m734_nsb_chg0
	{
		initSpeed = 228.6;
		displayName = "81mm M821A2 NSB +3";
	};
	class ace_arty_81mm_m821a2_m734_nsb_chg4: ace_arty_81mm_m821a2_m734_nsb_chg0
	{
		initSpeed = 267.9192;
		displayName = "81mm M821A2 NSB +4";
	};
	class ace_arty_81mm_m853a1: ace_arty_81mm_default
	{
		scope = 1;
		type = 0;
		displayName = "81mm M853A1 Illumination";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_81mm_m853a1_m772_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m853a1_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_81mm_m853a1_m772_time"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "ILLUM";
		ACE_Weight = 4.1;
	};
	class ace_arty_81mm_m853a1_m772_time_chg0: ace_arty_howitzer_mag
	{
		displayName = "81mm M853A1 M772 TIME Chg. 0";
		ammo = "ace_arty_81mm_m853a1_m772_time";
		initSpeed = 65.532;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_81mm_m853a1";
		ACE_Weight = 4.1;
	};
	class ace_arty_81mm_m853a1_m772_time_chg1: ace_arty_81mm_m853a1_m772_time_chg0
	{
		initSpeed = 133.5;
		displayName = "81mm M853A1 M772 TIME Chg. 1";
	};
	class ace_arty_81mm_m853a1_m772_time_chg2: ace_arty_81mm_m853a1_m772_time_chg0
	{
		initSpeed = 185.3184;
		displayName = "81mm M853A1 M772 TIME Chg. 2";
	};
	class ace_arty_81mm_m853a1_m772_time_chg3: ace_arty_81mm_m853a1_m772_time_chg0
	{
		initSpeed = 228.6;
		displayName = "81mm M853A1 M772 TIME Chg. 3";
	};
	class ace_arty_81mm_m853a1_m772_time_chg4: ace_arty_81mm_m853a1_m772_time_chg0
	{
		initSpeed = 267.9192;
		displayName = "81mm M853A1 M772 TIME Chg. 4";
	};
	class ace_arty_81mm_m375a3: ace_arty_81mm_default
	{
		scope = 1;
		type = 0;
		displayName = "81mm M375A3 WP";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_81mm_m375a3_m524_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m375a3_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd"};
		ACE_ARTY_FUZE_DESC[] = {"Point Detonate"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_81mm_m375a3_m524_pd"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "WP";
		ACE_Weight = 4.24;
	};
	class ace_arty_81mm_m375a3_m524_pd_chg0: ace_arty_howitzer_mag
	{
		displayName = "81mm M375A3 M524 PD Chg. 0";
		ammo = "ace_arty_81mm_m375a3_m524_pd";
		initSpeed = 65.532;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_81mm_m375a3";
		ACE_Weight = 4.24;
	};
	class ace_arty_81mm_m375a3_m524_pd_chg1: ace_arty_81mm_m375a3_m524_pd_chg0
	{
		initSpeed = 133.5;
		displayName = "81mm M375A3 M524 PD Chg. 1";
	};
	class ace_arty_81mm_m375a3_m524_pd_chg2: ace_arty_81mm_m375a3_m524_pd_chg0
	{
		initSpeed = 185.3184;
		displayName = "81mm M375A3 M524 PD Chg. 2";
	};
	class ace_arty_81mm_m375a3_m524_pd_chg3: ace_arty_81mm_m375a3_m524_pd_chg0
	{
		initSpeed = 228.6;
		displayName = "81mm M375A3 M524 PD Chg. 3";
	};
	class ace_arty_81mm_m375a3_m524_pd_chg4: ace_arty_81mm_m375a3_m524_pd_chg0
	{
		initSpeed = 254;
		displayName = "81mm M375A3 M524 PD Chg. 4";
	};
	class ace_arty_82mm_default: ace_arty_howitzer_default
	{
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\82mm\tables\ace_arty_82mm_genericBtab_%1_chg%2.sqf";
		ACE_ARTY_BTABS_KEY = "ace_arty_82mm_genericBtab_%1_chg%2";
		scope = 2;
		ACE_Weight = 4.5;
	};
	class ace_arty_82mm_he: ace_arty_82mm_default
	{
		scope = 1;
		type = 0;
		displayName = "82mm HE";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_82mm_he_%1_chg%2";
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\82mm\tables\ace_arty_82mm_heBtab_%1_chg%2.sqf";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_82mm_he_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd"};
		ACE_ARTY_FUZE_DESC[] = {"Point Detonate"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_82mm_he_pd"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 6;
		ACE_ARTY_INEFFECT = "HE";
		ACE_Weight = 4.5;
	};
	class ace_arty_82mm_he_pd_chg0: ace_arty_howitzer_mag
	{
		displayName = "82mm HE PD Chg. 0";
		ammo = "ace_arty_82mm_he_pd";
		initSpeed = 70;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_82mm_he";
		ACE_Weight = 4.5;
	};
	class ace_arty_82mm_he_pd_chg1: ace_arty_82mm_he_pd_chg0
	{
		initSpeed = 121;
		displayName = "82mm HE PD Chg. 1";
	};
	class ace_arty_82mm_he_pd_chg2: ace_arty_82mm_he_pd_chg0
	{
		initSpeed = 164;
		displayName = "82mm HE PD Chg. 2";
	};
	class ace_arty_82mm_he_pd_chg3: ace_arty_82mm_he_pd_chg0
	{
		initSpeed = 200;
		displayName = "82mm HE PD Chg. 3";
	};
	class ace_arty_82mm_he_pd_chg4: ace_arty_82mm_he_pd_chg0
	{
		initSpeed = 230;
		displayName = "82mm HE PD Chg. 4";
	};
	class ace_arty_82mm_he_pd_chg5: ace_arty_82mm_he_pd_chg0
	{
		initSpeed = 259;
		displayName = "82mm HE PD Chg. 5";
	};
	class ace_arty_82mm_he_pd_chg6: ace_arty_82mm_he_pd_chg0
	{
		initSpeed = 284;
		displayName = "82mm HE PD Chg. 6";
	};
	class ace_arty_82mm_illum: ace_arty_82mm_default
	{
		scope = 1;
		type = 0;
		displayName = "82mm Illumination";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_82mm_illum_%1_chg%2";
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\82mm\tables\ace_arty_82mm_illumBtab_%1_chg%2.sqf";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_82mm_illum_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_82mm_illum_time"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 3;
		ACE_ARTY_INEFFECT = "ILLUM";
	};
	class ace_arty_82mm_illum_time_chg0: ace_arty_howitzer_mag
	{
		displayName = "82mm ILLUM TIME Chg. 0";
		ammo = "ace_arty_82mm_illum_time";
		initSpeed = 64;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_82mm_illum";
		ACE_Weight = 4.5;
	};
	class ace_arty_82mm_illum_time_chg1: ace_arty_82mm_illum_time_chg0
	{
		initSpeed = 125;
		displayName = "82mm ILLUM TIME Chg. 1";
	};
	class ace_arty_82mm_illum_time_chg2: ace_arty_82mm_illum_time_chg0
	{
		initSpeed = 165;
		displayName = "82mm ILLUM TIME Chg. 2";
	};
	class ace_arty_82mm_illum_time_chg3: ace_arty_82mm_illum_time_chg0
	{
		initSpeed = 199;
		displayName = "82mm ILLUM TIME Chg. 3";
	};
	class ace_arty_82mm_wp: ace_arty_82mm_default
	{
		scope = 1;
		type = 0;
		displayName = "82mm WP";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_82mm_wp_%1_chg%2";
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\82mm\tables\ace_arty_82mm_wpBtab_%1_chg%2.sqf";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_82mm_smoke_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd"};
		ACE_ARTY_FUZE_DESC[] = {"Point Detonate"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_82mm_wp_pd"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 3;
		ACE_ARTY_INEFFECT = "WP";
		ACE_Weight = 4.5;
	};
	class ace_arty_82mm_wp_pd_chg0: ace_arty_howitzer_mag
	{
		displayName = "82mm WP PD Chg. 0";
		ammo = "ace_arty_82mm_wp_pd";
		initSpeed = 70;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_82mm_wp";
		ACE_Weight = 4.5;
	};
	class ace_arty_82mm_wp_pd_chg1: ace_arty_82mm_wp_pd_chg0
	{
		initSpeed = 127;
		displayName = "82mm WP PD Chg. 1";
	};
	class ace_arty_82mm_wp_pd_chg2: ace_arty_82mm_wp_pd_chg0
	{
		initSpeed = 170;
		displayName = "82mm WP PD Chg. 2";
	};
	class ace_arty_82mm_wp_pd_chg3: ace_arty_82mm_wp_pd_chg0
	{
		initSpeed = 206;
		displayName = "82mm WP PD Chg. 3";
	};
	class ace_arty_105mm_default: ace_arty_howitzer_default
	{
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\105mm\tables\ace_arty_105mm_genericBtab_%1_chg%2.sqf";
		ACE_ARTY_BTABS_KEY = "ace_arty_105mm_genericBtab_%1_chg%2";
		scope = 2;
		ACE_Weight = 18.1;
	};
	class ace_arty_105mm_m1: ace_arty_105mm_default
	{
		scope = 1;
		type = 0;
		displayName = "105mm M1 HE";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_105mm_m1_m782_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m14_chg%1.paa";
		ACE_ARTY_SHELL_IMAGE = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m1.paa";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m1_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd","prox","time","delay"};
		ACE_ARTY_FUZE_DESC[] = {"Point Detonate","Proximity","Time","Delay"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_105mm_m1_m782_pd","ace_arty_105mm_m1_m782_prox","ace_arty_105mm_m1_m782_time","ace_arty_105mm_m1_m782_delay"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 8;
		ACE_ARTY_INEFFECT = "HE";
	};
	class ace_arty_105mm_m1_m782_pd_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M1 - M782 PD Chg. 1";
		ammo = "ace_arty_105mm_m1_m782_pd";
		initSpeed = 205;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_105mm_m1";
	};
	class ace_arty_105mm_m1_m782_pd_chg2: ace_arty_105mm_m1_m782_pd_chg1
	{
		initSpeed = 223;
		displayName = "105mm M1 - M782 PD Chg. 2";
	};
	class ace_arty_105mm_m1_m782_pd_chg3: ace_arty_105mm_m1_m782_pd_chg1
	{
		initSpeed = 247;
		displayName = "105mm M1 - M782 PD Chg. 3";
	};
	class ace_arty_105mm_m1_m782_pd_chg4: ace_arty_105mm_m1_m782_pd_chg1
	{
		initSpeed = 278;
		displayName = "105mm M1 - M782 PD Chg. 4";
	};
	class ace_arty_105mm_m1_m782_pd_chg5: ace_arty_105mm_m1_m782_pd_chg1
	{
		initSpeed = 325;
		displayName = "105mm M1 - M782 PD Chg. 5";
	};
	class ace_arty_105mm_m1_m782_pd_chg6: ace_arty_105mm_m1_m782_pd_chg1
	{
		initSpeed = 393;
		displayName = "105mm M1 - M782 PD Chg. 6";
	};
	class ace_arty_105mm_m1_m782_pd_chg7: ace_arty_105mm_m1_m782_pd_chg1
	{
		initSpeed = 494;
		displayName = "105mm M1 - M782 PD Chg. 7";
	};
	class ace_arty_105mm_m1_m782_pd_chg8: ace_arty_105mm_m1_m782_pd_chg1
	{
		initSpeed = 616;
		displayName = "105mm M1 - M782 PD Chg. 8";
	};
	class ace_arty_105mm_m1_m782_time_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M1 - M782 TIME Chg. 1";
		ammo = "ace_arty_105mm_m1_m782_time";
		initSpeed = 205;
	};
	class ace_arty_105mm_m1_m782_time_chg2: ace_arty_105mm_m1_m782_time_chg1
	{
		initSpeed = 223;
		displayName = "105mm M1 - M782 TIME Chg. 2";
	};
	class ace_arty_105mm_m1_m782_time_chg3: ace_arty_105mm_m1_m782_time_chg1
	{
		initSpeed = 247;
		displayName = "105mm M1 - M782 TIME Chg. 3";
	};
	class ace_arty_105mm_m1_m782_time_chg4: ace_arty_105mm_m1_m782_time_chg1
	{
		initSpeed = 278;
		displayName = "105mm M1 - M782 TIME Chg. 4";
	};
	class ace_arty_105mm_m1_m782_time_chg5: ace_arty_105mm_m1_m782_time_chg1
	{
		initSpeed = 325;
		displayName = "105mm M1 - M782 TIME Chg. 5";
	};
	class ace_arty_105mm_m1_m782_time_chg6: ace_arty_105mm_m1_m782_time_chg1
	{
		initSpeed = 393;
		displayName = "105mm M1 - M782 TIME Chg. 6";
	};
	class ace_arty_105mm_m1_m782_time_chg7: ace_arty_105mm_m1_m782_time_chg1
	{
		initSpeed = 494;
		displayName = "105mm M1 - M782 TIME Chg. 7";
	};
	class ace_arty_105mm_m1_m782_time_chg8: ace_arty_105mm_m1_m782_time_chg1
	{
		initSpeed = 616;
		displayName = "105mm M1 - M782 TIME Chg. 8";
	};
	class ace_arty_105mm_m1_m782_prox_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M1 - M782 PROX Chg. 1";
		ammo = "ace_arty_105mm_m1_m782_prox";
		initSpeed = 205;
	};
	class ace_arty_105mm_m1_m782_prox_chg2: ace_arty_105mm_m1_m782_prox_chg1
	{
		initSpeed = 223;
		displayName = "105mm M1 - M782 PROX Chg. 2";
	};
	class ace_arty_105mm_m1_m782_prox_chg3: ace_arty_105mm_m1_m782_prox_chg1
	{
		initSpeed = 247;
		displayName = "105mm M1 - M782 PROX Chg. 3";
	};
	class ace_arty_105mm_m1_m782_prox_chg4: ace_arty_105mm_m1_m782_prox_chg1
	{
		initSpeed = 278;
		displayName = "105mm M1 - M782 PROX Chg. 4";
	};
	class ace_arty_105mm_m1_m782_prox_chg5: ace_arty_105mm_m1_m782_prox_chg1
	{
		initSpeed = 325;
		displayName = "105mm M1 - M782 PROX Chg. 5";
	};
	class ace_arty_105mm_m1_m782_prox_chg6: ace_arty_105mm_m1_m782_prox_chg1
	{
		initSpeed = 393;
		displayName = "105mm M1 - M782 PROX Chg. 6";
	};
	class ace_arty_105mm_m1_m782_prox_chg7: ace_arty_105mm_m1_m782_prox_chg1
	{
		initSpeed = 494;
		displayName = "105mm M1 - M782 PROX Chg. 7";
	};
	class ace_arty_105mm_m1_m782_prox_chg8: ace_arty_105mm_m1_m782_prox_chg1
	{
		initSpeed = 616;
		displayName = "105mm M1 - M782 PROX Chg. 8";
	};
	class ace_arty_105mm_m1_m782_delay_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M1 - M782 DELAY Chg. 1";
		ammo = "ace_arty_105mm_m1_m782_delay";
		initSpeed = 205;
	};
	class ace_arty_105mm_m1_m782_delay_chg2: ace_arty_105mm_m1_m782_delay_chg1
	{
		initSpeed = 223;
		displayName = "105mm M1 - M782 DELAY Chg. 2";
	};
	class ace_arty_105mm_m1_m782_delay_chg3: ace_arty_105mm_m1_m782_delay_chg1
	{
		initSpeed = 247;
		displayName = "105mm M1 - M782 DELAY Chg. 3";
	};
	class ace_arty_105mm_m1_m782_delay_chg4: ace_arty_105mm_m1_m782_delay_chg1
	{
		initSpeed = 278;
		displayName = "105mm M1 - M782 DELAY Chg. 4";
	};
	class ace_arty_105mm_m1_m782_delay_chg5: ace_arty_105mm_m1_m782_delay_chg1
	{
		initSpeed = 325;
		displayName = "105mm M1 - M782 DELAY Chg. 5";
	};
	class ace_arty_105mm_m1_m782_delay_chg6: ace_arty_105mm_m1_m782_delay_chg1
	{
		initSpeed = 393;
		displayName = "105mm M1 - M782 DELAY Chg. 6";
	};
	class ace_arty_105mm_m1_m782_delay_chg7: ace_arty_105mm_m1_m782_delay_chg1
	{
		initSpeed = 494;
		displayName = "105mm M1 - M782 DELAY Chg. 7";
	};
	class ace_arty_105mm_m1_m782_delay_chg8: ace_arty_105mm_m1_m782_delay_chg1
	{
		initSpeed = 616;
		displayName = "105mm M1 - M782 DELAY Chg. 8";
	};
	class ace_arty_105mm_m314a3: ace_arty_105mm_default
	{
		scope = 1;
		type = 0;
		displayName = "105mm M314A3 Illumination";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_105mm_m314a3_m782_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m14_chg%1.paa";
		ACE_ARTY_SHELL_IMAGE = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\M314A3.paa";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m314a3_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_105mm_m314a3_m782"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 7;
		ACE_ARTY_INEFFECT = "ILLUM";
	};
	class ace_arty_105mm_m314a3_m782_time_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M314A3 - M782 TIME Chg. 1";
		ammo = "ace_arty_105mm_m314a3_m782";
		initSpeed = 205;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_105mm_m314a3";
	};
	class ace_arty_105mm_m314a3_m782_time_chg2: ace_arty_105mm_m314a3_m782_time_chg1
	{
		initSpeed = 223;
		displayName = "105mm M314A3 - M782 TIME Chg. 2";
	};
	class ace_arty_105mm_m314a3_m782_time_chg3: ace_arty_105mm_m314a3_m782_time_chg1
	{
		initSpeed = 247;
		displayName = "105mm M314A3 - M782 TIME Chg. 3";
	};
	class ace_arty_105mm_m314a3_m782_time_chg4: ace_arty_105mm_m314a3_m782_time_chg1
	{
		initSpeed = 278;
		displayName = "105mm M314A3 - M782 TIME Chg. 4";
	};
	class ace_arty_105mm_m314a3_m782_time_chg5: ace_arty_105mm_m314a3_m782_time_chg1
	{
		initSpeed = 325;
		displayName = "105mm M314A3 - M782 TIME Chg. 5";
	};
	class ace_arty_105mm_m314a3_m782_time_chg6: ace_arty_105mm_m314a3_m782_time_chg1
	{
		initSpeed = 393;
		displayName = "105mm M314A3 - M782 TIME Chg. 6";
	};
	class ace_arty_105mm_m314a3_m782_time_chg7: ace_arty_105mm_m314a3_m782_time_chg1
	{
		initSpeed = 494;
		displayName = "105mm M314A3 - M782 TIME Chg. 7";
	};
	class ace_arty_105mm_m84a1: ace_arty_105mm_default
	{
		scope = 1;
		type = 0;
		displayName = "105mm M84A1 Base Ejecting HC Smoke";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_105mm_m84a1_m782_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m14_chg%1.paa";
		ACE_ARTY_SHELL_IMAGE = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\M84A1.paa";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m84a1_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_105mm_m84a1_m782"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 7;
		ACE_ARTY_INEFFECT = "SMOKE";
	};
	class ace_arty_105mm_m84a1_m782_time_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M84A1 - M782 TIME Chg. 1";
		ammo = "ace_arty_105mm_m84a1_m782";
		initSpeed = 205;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_105mm_m84a1";
	};
	class ace_arty_105mm_m84a1_m782_time_chg2: ace_arty_105mm_m84a1_m782_time_chg1
	{
		initSpeed = 223;
		displayName = "105mm M84A1 - M782 TIME Chg. 2";
	};
	class ace_arty_105mm_m84a1_m782_time_chg3: ace_arty_105mm_m84a1_m782_time_chg1
	{
		initSpeed = 247;
		displayName = "105mm M84A1 - M782 TIME Chg. 3";
	};
	class ace_arty_105mm_m84a1_m782_time_chg4: ace_arty_105mm_m84a1_m782_time_chg1
	{
		initSpeed = 278;
		displayName = "105mm M84A1 - M782 TIME Chg. 4";
	};
	class ace_arty_105mm_m84a1_m782_time_chg5: ace_arty_105mm_m84a1_m782_time_chg1
	{
		initSpeed = 325;
		displayName = "105mm M84A1 - M782 TIME Chg. 5";
	};
	class ace_arty_105mm_m84a1_m782_time_chg6: ace_arty_105mm_m84a1_m782_time_chg1
	{
		initSpeed = 393;
		displayName = "105mm M84A1 - M782 TIME Chg. 6";
	};
	class ace_arty_105mm_m84a1_m782_time_chg7: ace_arty_105mm_m84a1_m782_time_chg1
	{
		initSpeed = 494;
		displayName = "105mm M84A1 - M782 TIME Chg. 7";
	};
	class ace_arty_105mm_m916: ace_arty_105mm_default
	{
		scope = 1;
		type = 0;
		displayName = "105mm M916 Base Ejecting DPICM";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_105mm_m916_m782_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m14_chg%1.paa";
		ACE_ARTY_SHELL_IMAGE = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\M916.paa";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m916_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_105mm_m916_m782"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 8;
		ACE_ARTY_INEFFECT = "DPICM";
	};
	class ace_arty_105mm_m916_m782_time_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M916 - M782 TIME Chg. 1";
		ammo = "ace_arty_105mm_m916_m782";
		initSpeed = 205;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_105mm_m916";
	};
	class ace_arty_105mm_m916_m782_time_chg2: ace_arty_105mm_m916_m782_time_chg1
	{
		initSpeed = 223;
		displayName = "105mm M916 - M782 TIME Chg. 2";
	};
	class ace_arty_105mm_m916_m782_time_chg3: ace_arty_105mm_m916_m782_time_chg1
	{
		initSpeed = 247;
		displayName = "105mm M916 - M782 TIME Chg. 3";
	};
	class ace_arty_105mm_m916_m782_time_chg4: ace_arty_105mm_m916_m782_time_chg1
	{
		initSpeed = 278;
		displayName = "105mm M916 - M782 TIME Chg. 4";
	};
	class ace_arty_105mm_m916_m782_time_chg5: ace_arty_105mm_m916_m782_time_chg1
	{
		initSpeed = 325;
		displayName = "105mm M916 - M782 TIME Chg. 5";
	};
	class ace_arty_105mm_m916_m782_time_chg6: ace_arty_105mm_m916_m782_time_chg1
	{
		initSpeed = 393;
		displayName = "105mm M916 - M782 TIME Chg. 6";
	};
	class ace_arty_105mm_m916_m782_time_chg7: ace_arty_105mm_m916_m782_time_chg1
	{
		initSpeed = 494;
		displayName = "105mm M916 - M782 TIME Chg. 7";
	};
	class ace_arty_105mm_m916_m782_time_chg8: ace_arty_105mm_m916_m782_time_chg1
	{
		initSpeed = 616;
		displayName = "105mm M916 - M782 TIME Chg. 8";
	};
	class ace_arty_105mm_m60a2: ace_arty_105mm_default
	{
		scope = 1;
		type = 0;
		displayName = "105mm M60A2 WP";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_105mm_m60a2_m782_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m14_chg%1.paa";
		ACE_ARTY_SHELL_IMAGE = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\M60A2.paa";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_m60a2_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd"};
		ACE_ARTY_FUZE_DESC[] = {"Point Detonate"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_105mm_m60a2_m782"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 7;
		ACE_ARTY_INEFFECT = "WP";
	};
	class ace_arty_105mm_m60a2_m782_pd_chg1: ace_arty_howitzer_mag
	{
		displayName = "105mm M60A2 - M782 PD Chg. 1";
		ammo = "ace_arty_105mm_m60a2_m782_pd";
		initSpeed = 205;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_105mm_m60a2";
	};
	class ace_arty_105mm_m60a2_m782_pd_chg2: ace_arty_105mm_m60a2_m782_pd_chg1
	{
		initSpeed = 223;
		displayName = "105mm M60A2 - M782 PD Chg. 2";
	};
	class ace_arty_105mm_m60a2_m782_pd_chg3: ace_arty_105mm_m60a2_m782_pd_chg1
	{
		initSpeed = 247;
		displayName = "105mm M60A2 - M782 PD Chg. 3";
	};
	class ace_arty_105mm_m60a2_m782_pd_chg4: ace_arty_105mm_m60a2_m782_pd_chg1
	{
		initSpeed = 278;
		displayName = "105mm M60A2 - M782 PD Chg. 4";
	};
	class ace_arty_105mm_m60a2_m782_pd_chg5: ace_arty_105mm_m60a2_m782_pd_chg1
	{
		initSpeed = 325;
		displayName = "105mm M60A2 - M782 PD Chg. 5";
	};
	class ace_arty_105mm_m60a2_m782_pd_chg6: ace_arty_105mm_m60a2_m782_pd_chg1
	{
		initSpeed = 393;
		displayName = "105mm M60A2 - M782 PD Chg. 6";
	};
	class ace_arty_105mm_m60a2_m782_pd_chg7: ace_arty_105mm_m60a2_m782_pd_chg1
	{
		initSpeed = 494;
		displayName = "105mm M60A2 - M782 PD Chg. 7";
	};
	class ace_arty_120mm_default: ace_arty_howitzer_default
	{
		ACE_ARTY_BTABS = "\x\ace\addons\sys_arty_ammunition\120mm\tables\ace_arty_120mm_genericBtab_%1_chg%2.sqf";
		ACE_ARTY_BTABS_KEY = "ace_arty_120mm_genericBtab_%1_chg%2";
		scope = 2;
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm11a5: ace_arty_120mm_default
	{
		scope = 1;
		type = 0;
		displayName = "120mm DM 11A5 HE";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_120mm_dm11a5_dm111a1_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_dm11_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"pd"};
		ACE_ARTY_FUZE_DESC[] = {"Impact Burst"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_120mm_dm11a5_dm111a1_pd"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "HE";
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm11a5_dm111a1_pd_chg0: ace_arty_howitzer_mag
	{
		displayName = "120mm DM11A5 IMP 0";
		ammo = "ace_arty_120mm_dm11a5_dm111a1_pd";
		initSpeed = 102;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_120mm_dm11a5";
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm11a5_dm111a1_pd_chg1: ace_arty_120mm_dm11a5_dm111a1_pd_chg0
	{
		initSpeed = 168;
		displayName = "120mm DM11A5 IMP +1";
	};
	class ace_arty_120mm_dm11a5_dm111a1_pd_chg2: ace_arty_120mm_dm11a5_dm111a1_pd_chg0
	{
		initSpeed = 224;
		displayName = "120mm DM11A5 IMP +2";
	};
	class ace_arty_120mm_dm11a5_dm111a1_pd_chg3: ace_arty_120mm_dm11a5_dm111a1_pd_chg0
	{
		initSpeed = 274;
		displayName = "120mm DM11A5 IMP +3";
	};
	class ace_arty_120mm_dm11a5_dm111a1_pd_chg4: ace_arty_120mm_dm11a5_dm111a1_pd_chg0
	{
		initSpeed = 346;
		displayName = "120mm DM11A5 IMP +4";
	};
	class ace_arty_120mm_dm61: ace_arty_120mm_default
	{
		scope = 1;
		type = 0;
		displayName = "120mm DM61 HE";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_120mm_dm61_ppd_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_dm61_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"prox"};
		ACE_ARTY_FUZE_DESC[] = {"Proximity Burst"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_120mm_dm61_ppd_prox"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "HE";
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm61_ppd_prox_chg0: ace_arty_howitzer_mag
	{
		displayName = "120mm DM61 PRX 0";
		ammo = "ace_arty_120mm_dm61_ppd_prox";
		initSpeed = 102;
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm61_ppd_prox_chg1: ace_arty_120mm_dm61_ppd_prox_chg0
	{
		initSpeed = 168;
		displayName = "120mm DM61 PRX +1";
	};
	class ace_arty_120mm_dm61_ppd_prox_chg2: ace_arty_120mm_dm61_ppd_prox_chg0
	{
		initSpeed = 224;
		displayName = "120mm DM61 PRX +2";
	};
	class ace_arty_120mm_dm61_ppd_prox_chg3: ace_arty_120mm_dm61_ppd_prox_chg0
	{
		initSpeed = 274;
		displayName = "120mm DM61 PRX +3";
	};
	class ace_arty_120mm_dm61_ppd_prox_chg4: ace_arty_120mm_dm61_ppd_prox_chg0
	{
		initSpeed = 346;
		displayName = "120mm DM61 PRX +4";
	};
	class ace_arty_120mm_dm26: ace_arty_120mm_default
	{
		scope = 1;
		type = 0;
		displayName = "120mm DM26 Illumination";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_120mm_dm26_dm93_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_dm26_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_120mm_dm26_dm93_time"};
		ACE_ARTY_MINCHARGE = 1;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "ILLUM";
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm26_dm93_time_chg0: ace_arty_howitzer_mag
	{
		displayName = "120mm DM26 DM93 TIME 0";
		ammo = "ace_arty_120mm_dm26_dm93_time";
		initSpeed = 102;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_120mm_m853a1";
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm26_dm93_time_chg1: ace_arty_120mm_dm26_dm93_time_chg0
	{
		initSpeed = 168;
		displayName = "120mm DM26 TIME +1";
	};
	class ace_arty_120mm_dm26_dm93_time_chg2: ace_arty_120mm_dm26_dm93_time_chg0
	{
		initSpeed = 224;
		displayName = "120mm DM26 TIME +2";
	};
	class ace_arty_120mm_dm26_dm93_time_chg3: ace_arty_120mm_dm26_dm93_time_chg0
	{
		initSpeed = 274;
		displayName = "120mm DM26 TIME +3";
	};
	class ace_arty_120mm_dm26_dm93_time_chg4: ace_arty_120mm_dm26_dm93_time_chg0
	{
		initSpeed = 346;
		displayName = "120mm DM26 TIME +4";
	};
	class ace_arty_120mm_dm35: ace_arty_120mm_default
	{
		scope = 1;
		type = 0;
		displayName = "120mm DM35 HC";
		ACE_ARTY_MAGAZINE_FORMAT = "ace_arty_120mm_dm35_dm93_%1_chg%2";
		ACE_ARTY_CHARGE_IMAGE_FORMAT = "";
		ACE_ARTY_SHELL_IMAGE = "";
		ACE_ARTY_SHELL_VEHICLE = "ace_arty_dm35_cartridge";
		ACE_ARTY_FUZE_TYPES[] = {"time"};
		ACE_ARTY_FUZE_DESC[] = {"Time"};
		ACE_ARTY_AMMO_CLASSES[] = {"ace_arty_120mm_dm35_dm93_time"};
		ACE_ARTY_MINCHARGE = 0;
		ACE_ARTY_MAXCHARGE = 4;
		ACE_ARTY_INEFFECT = "SMOKE";
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm35_dm93_time_chg0: ace_arty_howitzer_mag
	{
		displayName = "120mm DM35 DM93 TIME 0";
		ammo = "ace_arty_120mm_dm35_dm93_time";
		initSpeed = 102;
		ACE_ARTY_DEFAULT_CLASS = "ace_arty_120mm_dm35";
		ACE_Weight = 14.15;
	};
	class ace_arty_120mm_dm35_dm93_time_chg1: ace_arty_120mm_dm35_dm93_time_chg0
	{
		initSpeed = 168;
		displayName = "120mm DM35 TIME +1";
	};
	class ace_arty_120mm_dm35_dm93_time_chg2: ace_arty_120mm_dm35_dm93_time_chg0
	{
		initSpeed = 224;
		displayName = "120mm DM35 TIME +2";
	};
	class ace_arty_120mm_dm35_dm93_time_chg3: ace_arty_120mm_dm35_dm93_time_chg0
	{
		initSpeed = 274;
		displayName = "120mm DM35 TIME +3";
	};
	class ace_arty_120mm_dm35_dm93_time_chg4: ace_arty_120mm_dm35_dm93_time_chg0
	{
		initSpeed = 346;
		displayName = "120mm DM35 TIME +4";
	};
};
class CfgSfx
{
	class ace_arty_roundSoundSourceSound
	{
		sounds[] = {"Factory15"};
		name = "$STR_DN_FACTORY15";
		Factory15[] = {"\ca\Sounds\sfx\factory9",10.0,2,900,1,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
};
class ace_arty_105mm_m84a1_m782_smokeCanisterHC_effect
{
	class Smoke1
	{
		simulation = "particles";
		type = "ace_arty_105mm_m84a1_m782_smokeCanisterHC_cloudlet1";
		position[] = {0,0,0};
		intensity = 0.25;
		interval = 0.05;
		lifeTime = 60;
	};
	class Smoke2
	{
		simulation = "particles";
		type = "ace_arty_105mm_m84a1_m782_smokeCanisterHC_cloudlet2";
		position[] = {0,0,0};
		intensity = 0.5;
		interval = 0.25;
		lifeTime = 30;
	};
};
class ace_arty_WPExplosion
{
	class LightExp
	{
		simulation = "light";
		type = "ExploLight";
		position[] = {0,0,0};
		intensity = 0.001;
		interval = 1;
		lifeTime = 1;
	};
	class ExplosionFlame
	{
		simulation = "particles";
		type = "ExplosionParticles";
		position[] = {0,0,0};
		intensity = 3;
		interval = 1;
		lifeTime = 0.25;
	};
	class Explosion1
	{
		simulation = "particles";
		type = "ace_arty_WPCloud";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Explosion2
	{
		simulation = "particles";
		type = "ace_arty_WPCloud2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Trails
	{
		simulation = "particles";
		type = "ace_arty_WPTrails";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class Trails2
	{
		simulation = "particles";
		type = "ace_arty_WPTrails2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
};
class ace_arty_dpicmEffects
{
	class LightExp
	{
		simulation = "light";
		type = "ExploLight";
		position[] = {0,0,0};
		intensity = 0.001;
		interval = 1;
		lifeTime = 0.25;
	};
	class ExploAmmoFlash
	{
		simulation = "particles";
		type = "ExploAmmoFlash";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ExploAmmoSmoke
	{
		simulation = "particles";
		type = "ExploAmmoSmoke";
		position[] = {0,0,0};
		intensity = 0.5;
		interval = 2;
		lifeTime = 0.5;
	};
};
class CfgCloudlets
{
	class ARTY_ExplosionSmoke;
	class ace_arty_105mm_m84a1_m782_smokeCanisterHC_cloudlet1: ARTY_ExplosionSmoke
	{
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		animationSpeedCoef = 1;
		colorCoef[] = {"colorR","colorG","colorB","colorA"};
		sizeCoef = 1;
		position[] = {0,0,0};
		interval = 0.05;
		weight = 10;
		volume = 7.5;
		rubbing = 0.05;
		lifeTime = 30;
		moveVelocity[] = {1,0.5,0.0};
		size[] = {0.75,2,12,16,32,33,34,35};
		color[] = {{1,1,1,0.5},{1,1,1,1},{1,1,1,0.5},{1,1,1,0.25},{1,1,1,0}};
		lifeTimeVar = 1.5;
		positionVar[] = {0,0,0};
		rotationVelocityVar = 1;
		sizeVar = 1.2;
		colorVar[] = {0.1,0.1,0.1,0.2};
		randomDirectionPeriod = 0.025;
		randomDirectionIntensity = 0.05;
		randomDirectionPeriodVar = 0.025;
		randomDirectionIntensityVar = 0.025;
	};
	class ace_arty_105mm_m84a1_m782_smokeCanisterHC_cloudlet2: ace_arty_105mm_m84a1_m782_smokeCanisterHC_cloudlet1
	{
		lifeTime = 60;
		interval = 0.15;
		weight = 10;
		moveVelocity[] = {1,0.5,0.0};
		size[] = {0.5,1,10,24,24,24,24};
		color[] = {{0.9,0.9,0.9,0.5},{0.9,0.9,0.9,0.75},{0.9,0.9,0.9,0.5},{0.9,0.91,0.9,0.25},{1,1,1,0}};
	};
	class Default;
	class ace_arty_WPTrails: Default
	{
		interval = 0.1;
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
		timerPeriod = 0.07;
		lifeTime = 5;
		moveVelocity[] = {0,6,0};
		rotationVelocity = 0;
		weight = 15;
		volume = 7.9;
		rubbing = 0.1;
		size[] = {0.5};
		color[] = {{1,1,1,1}};
		animationSpeed[] = {1};
		randomDirectionPeriod = 1;
		randomDirectionIntensity = 0;
		onTimerScript = "\x\ace\addons\sys_arty_ammunition\effects\scripts\WPTrails.sqf";
		beforeDestroyScript = "\x\ace\addons\sys_arty_ammunition\effects\scripts\WPTrails_END.sqf";
		lifeTimeVar = 3;
		positionVar[] = {2,2,2};
		MoveVelocityVar[] = {12,6,12};
		rotationVelocityVar = 20;
		sizeVar = 0;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ace_arty_WPTrails2: ace_arty_WPTrails
	{
		interval = 0.01;
		lifeTime = 6;
		lifeTimeVar = 4;
		MoveVelocityVar[] = {2,15,2};
		rotationVelocityVar = 30;
		moveVelocity[] = {0,8,0};
		onTimerScript = "\x\ace\addons\sys_arty_ammunition\effects\scripts\WPTrails2.sqf";
		beforeDestroyScript = "\x\ace\addons\sys_arty_ammunition\effects\scripts\WPTrails2.sqf";
	};
	class ace_arty_WPCloud: Default
	{
		interval = 0.02;
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
		lifeTime = 60;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 0;
		weight = 8.9;
		volume = 7;
		rubbing = 0.1;
		size[] = {5,10,13,16,18,20,21,22};
		color[] = {{1,1,1,1},{1,1,1,0}};
		animationSpeed[] = {1000};
		randomDirectionPeriod = 1;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 20;
		positionVar[] = {4,3,4};
		MoveVelocityVar[] = {0.2,0.2,0.2};
		rotationVelocityVar = 20;
		sizeVar = 0.3;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ace_arty_WPCloud2: ace_arty_WPCloud
	{
		interval = 0.001;
		lifeTime = 5;
		lifeTimeVar = 5;
		weight = 32;
		volume = 20;
		color[] = {{1,1,1,1},{1,1,1,0}};
		colorVar[] = {0.1,0.1,0.1,0};
		size[] = {5,10,13,16,18,20,21,22};
		moveVelocity[] = {0,5,0};
		MoveVelocityVar[] = {0.2,5,0.2};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_arty_ammunition
	{
		init = "call ('\x\ace\addons\sys_arty_ammunition\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_arty_ammunition\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_arty_ammunition
	{
		init = "call ('\x\ace\addons\sys_arty_ammunition\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class ace_arty_m119_base
	{
		ace_sys_arty_ammunition = "_this call ace_sys_arty_ammunition_fnc_onFired_cartEject";
	};
};
class Extended_Init_EventHandlers
{
	class ace_arty_60mm_m721_m766_parachute
	{
		class ace_sys_arty_ammunition
		{
			init = "_this call ('\x\ace\addons\sys_arty_ammunition\60mm\XEH_illum_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
	class ace_arty_81mm_m853a1_m772_parachute
	{
		class ace_sys_arty_ammunition
		{
			init = "_this call ('\x\ace\addons\sys_arty_ammunition\81mm\XEH_illum_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
	class ace_arty_82mm_illum_ftsq_parachute
	{
		class ace_sys_arty_ammunition
		{
			init = "_this call ('\x\ace\addons\sys_arty_ammunition\82mm\XEH_illum_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
	class ace_arty_105mm_m314a3_m782_parachute
	{
		class ace_sys_arty_ammunition
		{
			init = "_this call ('\x\ace\addons\sys_arty_ammunition\105mm\XEH_illum_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
	class ace_arty_120mm_dm26_dm93_parachute
	{
		class ace_sys_arty_ammunition
		{
			init = "_this call ('\x\ace\addons\sys_arty_ammunition\120mm\XEH_illum_init.sqf' call SLX_XEH_COMPILE)";
		};
	};
};
class CfgVehicles
{
	class ACE_Arty_BaseThing;
	class ACE_Arty_ShellHolder;
	class ace_arty_m720a1_cartridge: ACE_Arty_ShellHolder
	{
		scope = 1;
		icon = "iconThing";
		mapSize = 0;
		displayName = "M720A1 HE Cartridge";
		vehicleClass = "Objects";
		nameSound = "obj_object";
		picture = "pictureThing";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "";
		destrType = "DestructTree";
		weight = 1000;
		simulation = "house";
		type = 1;
		model = "\x\ace\addons\sys_arty_ammunition\60mm\ace_arty_m720a1_cartridge.p3d";
		animated = 1;
		reversed = 0;
		class EventHandlers
		{
			killed = "_this call ace_sys_arty_ammunition_fnc_onShellDestroyed";
		};
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_60mm_m720a1";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_60mm_m720a1_m734_pd_chg0",{0},"fnord",0,"pd"};
		ACE_Weight = 1.66;
		class AnimationSources
		{
			class hide_inc1
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.1;
			};
			class hide_inc2: hide_inc1{};
			class hide_inc3: hide_inc1{};
			class hide_inc4: hide_inc1{};
			class hide_inc5: hide_inc1{};
			class hide_inc6: hide_inc1{};
			class hide_inc7: hide_inc1{};
			class hide_inc8: hide_inc1{};
			class hide_inc9: hide_inc1{};
			class hide_inc10: hide_inc1{};
		};
	};
	class ace_arty_m721_cartridge: ace_arty_m720a1_cartridge
	{
		displayName = "M721 Illum Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\60mm\ace_arty_m721_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_60mm_m721";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_60mm_m721_m776_time_chg1",{10},"fnord",1,"time"};
		ACE_Weight = 1.71;
	};
	class ace_arty_m722a1_cartridge: ace_arty_m720a1_cartridge
	{
		displayName = "M722A1 WP Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\60mm\ace_arty_m722a1_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_60mm_m722a1";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_60mm_m722a1_m745_pd_chg0",{0},"fnord",0,"pd"};
		ACE_Weight = 1.68;
	};
	class ACE_HuntIR;
	class ace_arty_60mm_m721_m766_parachute: ACE_HuntIR
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
		SLX_XEH_DISABLED = 0;
	};
	class ace_arty_m821a2_cartridge: ACE_Arty_ShellHolder
	{
		scope = 1;
		icon = "iconThing";
		mapSize = 0;
		displayName = "M821A2 HE Cartridge";
		vehicleClass = "Objects";
		nameSound = "obj_object";
		picture = "pictureThing";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "";
		destrType = "DestructTree";
		weight = 1000;
		simulation = "house";
		type = 1;
		model = "\x\ace\addons\sys_arty_ammunition\81mm\ace_arty_m821a2_cartridge.p3d";
		animated = 0;
		reversed = 0;
		class EventHandlers
		{
			killed = "_this call ace_sys_arty_ammunition_fnc_onShellDestroyed";
		};
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_81mm_m821a2";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_81mm_m821a2_m734_pd_chg0",{0},"fnord",0,"pd"};
		ACE_Weight = 4.5;
		class AnimationSources
		{
			class hide_inc1
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.1;
			};
			class hide_inc2: hide_inc1{};
			class hide_inc3: hide_inc1{};
			class hide_inc4: hide_inc1{};
			class hide_inc5: hide_inc1{};
			class hide_inc6: hide_inc1{};
			class hide_inc7: hide_inc1{};
			class hide_inc8: hide_inc1{};
			class hide_inc9: hide_inc1{};
			class hide_inc10: hide_inc1{};
		};
	};
	class ace_arty_m853a1_cartridge: ace_arty_m821a2_cartridge
	{
		displayName = "M853A1 Illum Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\81mm\ace_arty_m853a1_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_81mm_m853a1";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_81mm_m853a1_m772_time_chg1",{10},"fnord",1,"time"};
		ACE_Weight = 4.1;
	};
	class ace_arty_m375a3_cartridge: ace_arty_m821a2_cartridge
	{
		displayName = "M375A3 WP Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\81mm\ace_arty_m375a3_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_81mm_m375a3";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_81mm_m375a3_m524_pd_chg0",{0},"fnord",0,"pd"};
		ACE_Weight = 4.24;
	};
	class ace_arty_81mm_m853a1_m772_parachute: ACE_HuntIR
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
		SLX_XEH_DISABLED = 0;
	};
	class ace_arty_82mm_he_cartridge: ACE_Arty_ShellHolder
	{
		scope = 1;
		icon = "iconThing";
		mapSize = 0;
		displayName = "82mm HE Cartridge";
		vehicleClass = "Objects";
		nameSound = "obj_object";
		picture = "pictureThing";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "";
		destrType = "DestructTree";
		weight = 1000;
		simulation = "house";
		type = 1;
		model = "\x\ace\addons\sys_arty_ammunition\82mm\ace_arty_82mm_he_cartridge.p3d";
		animated = 1;
		reversed = 0;
		class EventHandlers
		{
			killed = "_this call ace_sys_arty_ammunition_fnc_onShellDestroyed";
		};
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_82mm_he";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_82mm_he_pd_chg0",{0},"fnord",0,"pd"};
		ACE_Weight = 4.15;
		class AnimationSources
		{
			class hide_inc1
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.1;
			};
			class hide_inc2: hide_inc1{};
			class hide_inc3: hide_inc1{};
			class hide_inc4: hide_inc1{};
			class hide_inc5: hide_inc1{};
			class hide_inc6: hide_inc1{};
			class hide_inc7: hide_inc1{};
			class hide_inc8: hide_inc1{};
			class hide_inc9: hide_inc1{};
			class hide_inc10: hide_inc1{};
		};
	};
	class ace_arty_82mm_illum_cartridge: ace_arty_82mm_he_cartridge
	{
		displayName = "82mm Illum Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\82mm\ace_arty_82mm_illum_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_82mm_illum";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_82mm_illum_time_chg1",{10},"fnord",1,"time"};
		ACE_Weight = 3.5;
	};
	class ace_arty_82mm_smoke_cartridge: ace_arty_82mm_he_cartridge
	{
		displayName = "82mm WP Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\82mm\ace_arty_82mm_smoke_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_82mm_wp";
		ACE_ARTY_SHELL_PREP[] = {"ace_arty_82mm_wp_pd_chg0",{0},"fnord",0,"pd"};
		ACE_Weight = 4.15;
	};
	class ace_arty_82mm_illum_ftsq_parachute: ace_arty_60mm_m721_m766_parachute{};
	class ace_arty_m1_cartridge: ACE_Arty_ShellHolder
	{
		scope = 1;
		icon = "iconThing";
		mapSize = 0;
		displayName = "M1 HE Cartridge";
		vehicleClass = "Objects";
		nameSound = "obj_object";
		picture = "pictureThing";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "";
		destrType = "DestructTree";
		weight = 1000;
		simulation = "house";
		type = 1;
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m1_cartridge.p3d";
		animated = "false";
		reversed = "false";
		class EventHandlers
		{
			killed = "_this call ace_sys_arty_ammunition_fnc_onShellDestroyed";
		};
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_105mm_m1";
	};
	class ace_arty_m84a1_cartridge: ace_arty_m1_cartridge
	{
		displayName = "M84A1 Smoke Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m84a1_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_105mm_m84a1";
	};
	class ace_arty_m314a3_cartridge: ace_arty_m1_cartridge
	{
		displayName = "M314A3 Illum Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m314a3_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_105mm_m314a3";
	};
	class ace_arty_m916_cartridge: ace_arty_m1_cartridge
	{
		displayName = "M916 DPICM Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m916_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_105mm_m916";
	};
	class ace_arty_m60a2_cartridge: ace_arty_m1_cartridge
	{
		displayName = "M602A2 WP Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m60a2_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_105mm_m60a2";
	};
	class ACE_UsedTubes;
	class ace_arty_m14_casing: ACE_UsedTubes
	{
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_m14_casing.p3d";
	};
	class ace_arty_105mm_m314a3_m782_parachute: ACE_HuntIR
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
		SLX_XEH_DISABLED = 0;
	};
	class ace_arty_dm11_cartridge: ACE_Arty_ShellHolder
	{
		scope = 1;
		icon = "\x\ace\addons\sys_arty_ammunition\120mm\data\icon_120mm_ca.paa";
		mapSize = 0;
		displayName = "DM 11A5 HE Cartridge";
		vehicleClass = "Objects";
		nameSound = "obj_object";
		picture = "pictureThing";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "";
		destrType = "DestructTree";
		weight = 1000;
		simulation = "house";
		type = 1;
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm11_cartridge.p3d";
		animated = 1;
		reversed = 0;
		class EventHandlers
		{
			killed = "_this call ace_sys_arty_ammunition_fnc_onShellDestroyed";
		};
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_120mm_dm11a5";
		ACE_Weight = 4.5;
		class AnimationSources
		{
			class hide_inc1
			{
				source = "user";
				initPhase = 1;
				animPeriod = 0.1;
			};
			class hide_inc2: hide_inc1{};
			class hide_inc3: hide_inc1{};
			class hide_inc4: hide_inc1{};
			class hide_inc5: hide_inc1{};
			class hide_inc6: hide_inc1{};
			class hide_inc7: hide_inc1{};
			class hide_inc8: hide_inc1{};
			class hide_inc9: hide_inc1{};
			class hide_inc10: hide_inc1{};
		};
	};
	class ace_arty_dm61_cartridge: ace_arty_dm11_cartridge
	{
		displayName = "DM 61 HE Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm61_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_120mm_dm61";
		ACE_Weight = 4.1;
	};
	class ace_arty_dm26_cartridge: ace_arty_dm11_cartridge
	{
		displayName = "DM 26 Illum Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm26_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_120mm_dm26";
		ACE_Weight = 4.1;
	};
	class ace_arty_dm35_cartridge: ace_arty_dm11_cartridge
	{
		displayName = "DM 35 Smoke Cartridge";
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_arty_dm35_cartridge.p3d";
		ACE_ARTY_MAGAZINE_CLASS = "ace_arty_120mm_dm35";
		ACE_Weight = 4.24;
	};
	class ace_arty_120mm_dm26_dm93_parachute: ACE_HuntIR
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
		SLX_XEH_DISABLED = 0;
	};
	class ace_arty_155mm_bonus_parachute: ACE_HuntIR
	{
		class EventHandlers
		{
			init = "if(isNil'SLX_XEH_MACHINE')then{call compile preProcessFileLineNumbers '\x\cba\addons\xeh\init_pre.sqf'};_this call SLX_XEH_EH_Init";
			fired = "_this call SLX_XEH_EH_Fired";
			animChanged = "_this call SLX_XEH_EH_AnimChanged";
			animStateChanged = "_this call SLX_XEH_EH_AnimStateChanged";
			animDone = "_this call SLX_XEH_EH_AnimDone";
			dammaged = "_this call SLX_XEH_EH_Dammaged";
			engine = "_this call SLX_XEH_EH_Engine";
			firedNear = "_this call SLX_XEH_EH_FiredNear";
			fuel = "_this call SLX_XEH_EH_Fuel";
			gear = "_this call SLX_XEH_EH_Gear";
			getIn = "_this call SLX_XEH_EH_GetIn";
			getOut = "_this call SLX_XEH_EH_GetOut";
			hit = "_this call SLX_XEH_EH_Hit";
			incomingMissile = "_this call SLX_XEH_EH_IncomingMissile";
			killed = "_this call SLX_XEH_EH_Killed";
			landedTouchDown = "_this call SLX_XEH_EH_LandedTouchDown";
			landedStopped = "_this call SLX_XEH_EH_LandedStopped";
			respawn = "_this call SLX_XEH_EH_Respawn";
		};
		SLX_XEH_DISABLED = 0;
		model = "\x\ace\addons\sys_arty_ammunition\155mm\data\bonus.p3d";
	};
	class USOrdnanceBox_EP1;
	class ACE_Arty_OrdnanceBox: USOrdnanceBox_EP1
	{
		scope = 1;
	};
	class ace_arty_105mm_ammo_m1: ACE_Arty_OrdnanceBox
	{
		scope = 2;
		displayName = "105mm Ammo M1 HE w/Fuze M782";
		model = "\x\ace\addons\sys_arty_ammunition\105mm\ace_arty_105mm_Box.p3d";
		vehicleClass = "ACE_Arty_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_105mm_m1
			{
				magazine = "ace_arty_105mm_m1";
				count = 5;
			};
		};
	};
	class ace_arty_105mm_ammo_m84a1: ace_arty_105mm_ammo_m1
	{
		displayName = "105mm M84A1 BE HC Smoke w/Fuze M782";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_105mm_m84a1
			{
				magazine = "ace_arty_105mm_m84a1";
				count = 5;
			};
		};
	};
	class ace_arty_105mm_ammo_m916: ace_arty_105mm_ammo_m1
	{
		displayName = "105mm M916 BE DPICM w/Fuze M782";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_105mm_m916
			{
				magazine = "ace_arty_105mm_m916";
				count = 5;
			};
		};
	};
	class ace_arty_105mm_ammo_m314a3: ace_arty_105mm_ammo_m1
	{
		displayName = "105mm M314A3 Illum w/Fuze M782";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_105mm_m314a3
			{
				magazine = "ace_arty_105mm_m314a3";
				count = 5;
			};
		};
	};
	class ace_arty_105mm_ammo_m60a2: ace_arty_105mm_ammo_m1
	{
		displayName = "105mm M60A2 Bursting WP Smoke w/Fuze M782";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_105mm_m60a2
			{
				magazine = "ace_arty_105mm_m60a2";
				count = 5;
			};
		};
	};
	class ACE_Tbox_GP_W;
	class ACE_Tbox_GP_R;
	class ACE_Tbox_Mortar_81mmHE: ACE_Tbox_GP_W
	{
		vehicleClass = "ACE_Arty_Ammunition";
		displayName = "81mm M821A2 HE w/Fuze M734";
		transportMaxWeapons = 0;
		transportMaxMagazines = 8;
		class TransportMagazines
		{
			class _xx_ACE_M252HE_CSWDM
			{
				magazine = "ACE_M252HE_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_81mm_m821a2
			{
				magazine = "ace_arty_81mm_m821a2";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_81mmWP: ACE_Tbox_Mortar_81mmHE
	{
		displayName = "81mm M375A3 Bursting WP Smoke w/Fuze M524";
		class TransportMagazines
		{
			class _xx_ACE_M252WP_CSWDM
			{
				magazine = "ACE_M252WP_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_81mm_m375a3
			{
				magazine = "ace_arty_81mm_m375a3";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_81mmIL: ACE_Tbox_Mortar_81mmHE
	{
		displayName = "81mm M853A1 Illum w/Fuze M772";
		class TransportMagazines
		{
			class _xx_ACE_M252IL_CSWDM
			{
				magazine = "ACE_M252IL_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_81mm_m853a1
			{
				magazine = "ace_arty_81mm_m853a1";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_60mmHE: ACE_Tbox_GP_W
	{
		scope = 2;
		vehicleClass = "ACE_Arty_Ammunition";
		displayName = "60mm M720A1 HE w/Fuze M734";
		transportMaxWeapons = 0;
		transportMaxMagazines = 8;
		class TransportMagazines
		{
			class _xx_ACE_M224HE_CSWDM
			{
				magazine = "ACE_M224HE_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_60mm_m720a1
			{
				magazine = "ace_arty_60mm_m720a1";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_60mmWP: ACE_Tbox_Mortar_81mmHE
	{
		scope = 2;
		displayName = "60mm M722A1 Bursting WP Smoke w/Fuze M745";
		class TransportMagazines
		{
			class _xx_ACE_M224WP_CSWDM
			{
				magazine = "ACE_M224WP_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_60mm_m722a1
			{
				magazine = "ace_arty_60mm_m722a1";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_60mmIL: ACE_Tbox_Mortar_81mmHE
	{
		scope = 2;
		displayName = "60mm M721 Illum w/Fuze M776";
		class TransportMagazines
		{
			class _xx_ACE_M224IL_CSWDM
			{
				magazine = "ACE_M224IL_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_60mm_m721
			{
				magazine = "ace_arty_60mm_m721";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_82mmHE: ACE_Tbox_GP_R
	{
		vehicleClass = "ACE_Arty_Ammunition";
		displayName = "$STR_DN_ACE_CSW_BOX_2B14_AMMOHE";
		transportMaxWeapons = 0;
		transportMaxMagazines = 8;
		class TransportMagazines
		{
			class _xx_ACE_2B14HE_CSWDM
			{
				magazine = "ACE_2B14HE_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_82mm_he
			{
				magazine = "ace_arty_82mm_he";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_82mmWP: ACE_Tbox_Mortar_82mmHE
	{
		displayName = "$STR_DN_ACE_CSW_BOX_2B14_AMMOWP";
		class TransportMagazines
		{
			class _xx_ACE_2B14WP_CSWDM
			{
				magazine = "ACE_2B14WP_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_82mm_wp
			{
				magazine = "ace_arty_82mm_wp";
				count = 4;
			};
		};
	};
	class ACE_Tbox_Mortar_82mmIL: ACE_Tbox_Mortar_82mmHE
	{
		displayName = "$STR_DN_ACE_CSW_BOX_2B14_AMMOIL";
		class TransportMagazines
		{
			class _xx_ACE_2B14IL_CSWDM
			{
				magazine = "ACE_2B14IL_CSWDM";
				count = 4;
			};
			class _xx_ace_arty_82mm_illum
			{
				magazine = "ace_arty_82mm_illum";
				count = 4;
			};
		};
	};
	class ace_arty_120mm_ammo_dm11: ACE_Arty_OrdnanceBox
	{
		scope = 2;
		displayName = "120mm DM11A5 HE w/Fuze DM111A1";
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_box_dm11.p3d";
		icon = "\x\ace\addons\sys_arty_ammunition\120mm\data\icomap_dm11_ca.paa";
		vehicleClass = "ACE_Arty_Ammunition";
		transportMaxMagazines = 2;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_120mm_dm11a5
			{
				magazine = "ace_arty_120mm_dm11a5";
				count = 2;
			};
		};
		ACE_Weight = 1.5;
	};
	class ace_arty_120mm_ammo_dm61: ace_arty_120mm_ammo_dm11
	{
		displayName = "120mm DM61 HE w/Fuze PPD324-B3";
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_box_dm61.p3d";
		icon = "\x\ace\addons\sys_arty_ammunition\120mm\data\icomap_dm61_ca.paa";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_120mm_dm61
			{
				magazine = "ace_arty_120mm_dm61";
				count = 2;
			};
		};
	};
	class ace_arty_120mm_ammo_dm26: ace_arty_120mm_ammo_dm11
	{
		displayName = "120mm DM26 Illum w/Fuze DM93";
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_box_dm26.p3d";
		icon = "\x\ace\addons\sys_arty_ammunition\120mm\data\icomap_dm26_ca.paa";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_120mm_dm26
			{
				magazine = "ace_arty_120mm_dm26";
				count = 2;
			};
		};
	};
	class ace_arty_120mm_ammo_dm35: ace_arty_120mm_ammo_dm11
	{
		displayName = "120mm DM35 BE HC Smoke w/Fuze DM93";
		model = "\x\ace\addons\sys_arty_ammunition\120mm\ace_box_dm35.p3d";
		icon = "\x\ace\addons\sys_arty_ammunition\120mm\data\icomap_dm35_ca.paa";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ace_arty_120mm_dm35
			{
				magazine = "ace_arty_120mm_dm35";
				count = 2;
			};
		};
	};
	class Sound;
	class ace_arty_roundSoundSource: Sound
	{
		scope = 2;
		sound = "ace_arty_roundSoundSourceSound";
		displayName = "arty sound";
	};
};
class ace_arty_ammoprep_RscText
{
	idc = -1;
	type = 0;
	style = "0x00";
	font = "Zeppelin32";
	colorText[] = {1,1,1,1};
	colorBackground[] = {0,0,0,0};
	sizeEx = "0.02*SafeZoneH";
	w = "0.5815 * safeZoneW";
	h = "0.02 * safeZoneH";
	lineSpacing = 1;
};
class ace_arty_ammoprep_RscTextBox
{
	idc = -1;
	type = 2;
	style = "0x00";
	w = "0.5815 * safeZoneW";
	h = "0.02 * safeZoneH";
	sizeEx = 0.02;
	font = "Zeppelin32";
	text = "";
	colorText[] = {1,1,1,1};
	autocomplete = "false";
	colorSelection[] = {0,0,0,1};
};
class ace_arty_ammoprep_RscButton
{
	type = 1;
	idc = -1;
	style = "0x02";
	x = 0.0;
	y = 0.0;
	w = "0.2 * safeZoneW";
	h = "0.03 * safeZoneH";
	sizeEx = "0.015*SafeZoneH";
	offsetX = 0;
	offsetY = 0.002;
	offsetPressedX = 0;
	offsetPressedY = 0.002;
	borderSize = 0;
	colorText[] = {1,1,1,1};
	colorBackground[] = {0.5,0.5,0.5,0.75};
	colorFocused[] = {0.5,0.5,0.5,0};
	colorShadow[] = {0,0,0,0};
	colorBorder[] = {1,1,1,0};
	colorBackgroundActive[] = {0.5,0.5,0.5,0};
	colorDisabled[] = {0.5,0.5,0.5,0};
	colorBackgroundDisabled[] = {0.5,0.5,0.5,0};
	font = "Zeppelin32";
	soundEnter[] = {"",0.2,1};
	soundPush[] = {"",0.2,1};
	soundClick[] = {"",0.2,1};
	soundEscape[] = {"",0.2,1};
	default = "false";
	text = "";
	action = "";
};
class RscListNBox;
class ace_arty_ammoprep_RscListNBox: RscListNBox
{
	type = 102;
	idc = -1;
	style = 0;
	color[] = {1,1,1,1};
	colorText[] = {1,1,1,0.75};
	colorScrollbar[] = {0.95,0.95,0.95,1};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorSelect2[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {0.6,0.8392,0.4706,1.0};
	colorSelectBackground2[] = {0.6,0.8392,0.4706,1.0};
	period = 0;
	font = "Zeppelin32";
	sizeEx = "0.015*SafeZoneH";
	colorBackground[] = {1,0,0,1};
	columns[] = {0.1,0.7};
	soundSelect[] = {"",0.0,1};
	soundExpand[] = {"",0.0,1};
	soundCollapse[] = {"",0.0,1};
	rowHeight = "((0.0219*1)*SafeZoneH)";
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	maxHistoryDelay = 0;
	drawSideArrows = 0;
	idcLeft = 10001;
	idcRight = 10002;
	class ScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\ca\ui\data\igui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\igui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\igui_arrow_top_ca.paa";
		border = "\ca\ui\data\igui_border_scroll_ca.paa";
	};
};
class ace_arty_ammoprep_RscComboBox
{
	type = 4;
	style = "0 + 0x10";
	font = "Zeppelin32";
	sizeEx = "0.02*SafeZoneH";
	color[] = {1,1,1,1};
	colorText[] = {1,1,1,1};
	colorScrollbar[] = {1,1,1,1};
	colorSelect[] = {1,1,1,1};
	colorSelect2[] = {"90/255","74/255","36/255",0.75};
	colorSelectBackground[] = {0,0,0,1};
	colorSelectBackground2[] = {"90/255","74/255","36/255",0.75};
	period = 1.2;
	colorBackground[] = {"90/255","74/255","36/255",0.75};
	maxHistoryDelay = 1.0;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	soundSelect[] = {"",0.0,1};
	soundExpand[] = {"",0.0,1};
	soundCollapse[] = {"",0.0,1};
	wholeHeight = "((0.0219*4.1)*SafeZoneH)";
	arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
	arrowFull = "\ca\ui\data\igui_arrow_top_active_ca.paa";
	class ScrollBar
	{
		color[] = {0,1,0,1};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
};
class ace_arty_ammoprep_RscListBox
{
	type = 5;
	style = "0 + 0x10";
	font = "Zeppelin32";
	sizeEx = 0.03921;
	color[] = {1,1,1,1};
	colorText[] = {0.543,0.5742,0.4102,1.0};
	colorScrollbar[] = {0,1,0,1};
	colorSelect[] = {0.95,0.95,0.95,1};
	colorSelect2[] = {0.95,0.95,0.95,1};
	colorSelectBackground[] = {0,0,0,1};
	colorSelectBackground2[] = {0.543,0.5742,0.4102,1.0};
	period = 1.2;
	colorBackground[] = {0,0,0,1};
	maxHistoryDelay = 1.0;
	autoScrollSpeed = -1;
	autoScrollDelay = 5;
	autoScrollRewind = 0;
	soundSelect[] = {"",0.0,1};
	soundExpand[] = {"",0.0,1};
	soundCollapse[] = {"",0.0,1};
	rowHeight = "((0.0219*1)*SafeZoneH)";
	arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
	arrowFull = "\ca\ui\data\igui_arrow_top_active_ca.paa";
	class ScrollBar
	{
		color[] = {0,1,0,1};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
};
class ace_arty_ammoprep_CheckBox
{
	idc = -1;
	type = 6;
	style = "0x00";
	x = 0;
	y = 0;
	w = "((0.029075*2)*SafeZoneW)";
	h = "((0.0219*1)*SafeZoneH)";
	colorText[] = {1,1,1,1};
	color[] = {0,0,0,1};
	colorTextSelect[] = {1,0,0,1};
	colorSelect[] = {0,0,1,1};
	colorTextDisable[] = {0.4,0.4,0.4,1};
	colorDisable[] = {0.4,0.4,0.4,1};
	coloSelectedBg[] = {0.4,0.4,0.4,1};
	font = "Zeppelin32";
	sizeEx = "0.015*SafeZoneH";
	rows = 1;
	columns = 2;
	strings[] = {"No","Yes"};
	values[] = {0,1};
};
class ace_arty_ammoprep_RscPicture: ace_arty_ammoprep_RscButton
{
	type = 0;
	idc = -1;
	style = 48;
	text = "";
};
class RscControlsGroup;
class ace_arty_ammoprep_ControlGroup: RscControlsGroup
{
	type = 15;
	idc = -1;
	style = 16;
	x = "(0.125 * safeZoneW) + safeZoneX";
	y = "(0 * safeZoneH) + safeZoneY";
	w = "0.75 * safeZoneW";
	h = "1 * safeZoneH";
	class VScrollbar
	{
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		color[] = {1,1,1,1};
		width = 0.001;
	};
	class HScrollbar
	{
		color[] = {1,1,1,0};
		height = 0.001;
	};
	class ScrollBar
	{
		color[] = {1,1,1,0.6};
		colorActive[] = {1,1,1,1};
		colorDisabled[] = {1,1,1,0.3};
		thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
		arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
		border = "\ca\ui\data\ui_border_scroll_ca.paa";
	};
	class controls{};
};
class ace_arty_ammoprep_Display
{
	idd = 754;
	movingEnable = 0;
	name = "ace_arty_ammoprep_Display";
	onUnload = "_this call ace_sys_arty_ammunition_fnc_onDialogClose";
	onLoad = "_this call ace_sys_arty_ammunition_fnc_onDialogOpen";
	class controlsBackground
	{
		class ace_arty_ammoprep_Background
		{
			idc = -1;
			access = 0;
			type = 0;
			style = "0x00";
			colorText[] = {0,0,0,1};
			colorBackground[] = {"90/255","74/255","36/255",0.75};
			font = "Zeppelin32";
			sizeEx = "1*SafeZoneH";
			x = "(0.125 * safeZoneW) + safeZoneX";
			y = "(0 * safeZoneH) + safeZoneY";
			w = "0.75 * safeZoneW";
			h = "1 * safeZoneH";
			text = "";
		};
	};
	class objects{};
	class controls
	{
		class ace_arty_ammoprep_main: ace_arty_ammoprep_ControlGroup
		{
			idc = -1;
			class controls
			{
				class ace_sys_arty_ammunition_ammoAvailable: ace_arty_ammoprep_RscText
				{
					x = "((0.029075*0)*SafeZoneW)";
					y = "((0.0219*0)*SafeZoneH)";
					w = "((0.029075*5)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					text = "Available Rounds";
				};
				class ace_sys_arty_ammunition_availabeAmmoBG: ace_arty_ammoprep_RscText
				{
					x = "((0.029075*0)*SafeZoneW)";
					y = "((0.0219*1)*SafeZoneH)";
					w = "((0.029075*7)*SafeZoneW)";
					h = "1*SafeZoneH";
					colorBackground[] = {"90/255","74/255","36/255",0.75};
					text = "";
				};
				class ace_sys_arty_ammunition_availabeAmmo: ace_arty_ammoprep_RscListBox
				{
					idc = 20100;
					x = "((0.029075*0)*SafeZoneW)";
					y = "((0.0219*1)*SafeZoneH)";
					w = "((0.029075*7)*SafeZoneW)";
					h = "1*SafeZoneH";
					onLBSelChanged = "_this call ace_sys_arty_ammunition_fnc_onSelectRound";
				};
				class ace_sys_arty_ammunition_ammoPrepTitle: ace_arty_ammoprep_RscText
				{
					idc = 12555;
					x = "((0.029075*7)*SafeZoneW)";
					y = "((0.0219*0)*SafeZoneH)";
					w = "((0.029075*20)*SafeZoneW)";
					h = "((0.0219*2)*SafeZoneH)";
					sizeEx = "(0.02*SafeZoneH)*2";
					text = "Prepare Ammo";
				};
				class ace_sys_arty_ammunition_ammoCharge: ace_arty_ammoprep_RscText
				{
					x = "((0.029075*7)*SafeZoneW)";
					y = "((0.0219*3)*SafeZoneH)";
					w = "((0.029075*6)*SafeZoneW)";
					h = "((0.0219*2)*SafeZoneH)";
					sizeEx = "(0.02*SafeZoneH)*2";
					text = "Charge";
				};
				class ace_sys_arty_ammunition_ammoCurrentCharge: ace_arty_ammoprep_RscText
				{
					idc = 12556;
					x = "((0.029075*7.5)*SafeZoneW)";
					y = "((0.0219*5)*SafeZoneH)";
					w = "((0.029075*4)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					text = "Current Charge:";
				};
				class ace_sys_arty_ammunition_ammoChargeUp: ace_arty_ammoprep_RscButton
				{
					text = "CHARGE UP";
					x = "((0.029075*12)*SafeZoneW)";
					y = "((0.0219*5)*SafeZoneH)";
					w = "((0.029075*3)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					action = "[1] call ace_sys_arty_ammunition_fnc_changeCharge";
				};
				class ace_sys_arty_ammunition_ammoChargeDown: ace_arty_ammoprep_RscButton
				{
					text = "CHARGE DOWN";
					x = "((0.029075*15)*SafeZoneW)";
					y = "((0.0219*5)*SafeZoneH)";
					w = "((0.029075*3)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					action = "[-1] call ace_sys_arty_ammunition_fnc_changeCharge";
				};
				class ace_sys_arty_ammunition_ammoFuze: ace_arty_ammoprep_RscText
				{
					x = "((0.029075*7)*SafeZoneW)";
					y = "((0.0219*7)*SafeZoneH)";
					w = "((0.029075*6)*SafeZoneW)";
					h = "((0.0219*2)*SafeZoneH)";
					sizeEx = "(0.02*SafeZoneH)*2";
					text = "Fuze";
				};
				class ace_sys_arty_ammunition_ammoFuzeSelect: ace_arty_ammoprep_RscComboBox
				{
					idc = 12557;
					x = "((0.029075*7.5)*SafeZoneW)";
					y = "((0.0219*9)*SafeZoneH)";
					w = "((0.029075*5)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					onLBSelChanged = "_this call ace_sys_arty_ammunition_fnc_onSelectFuze";
				};
				class ace_sys_arty_ammunition_ammoFuzeTimeLabel: ace_arty_ammoprep_RscText
				{
					idc = 12561;
					x = "((0.029075*7.5)*SafeZoneW)";
					y = "((0.0219*11)*SafeZoneH)";
					w = "((0.029075*3)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					text = "Fuze Time:";
				};
				class ace_sys_arty_ammunition_ammoFuzeTime: ace_arty_ammoprep_RscTextBox
				{
					idc = 12560;
					x = "((0.029075*10.5)*SafeZoneW)";
					y = "((0.0219*11)*SafeZoneH)";
					w = "((0.029075*2)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					text = "";
				};
				class ace_sys_arty_ammunition_ammoFuzeTimeFormat: ace_arty_ammoprep_RscText
				{
					idc = 12562;
					x = "((0.029075*12.5)*SafeZoneW)";
					y = "((0.0219*11)*SafeZoneH)";
					w = "((0.029075*3)*SafeZoneW)";
					h = "((0.0219*1)*SafeZoneH)";
					text = "##.#";
				};
				class ace_sys_arty_ammunition_ammoPrepRoundButton: ace_arty_ammoprep_RscButton
				{
					idc = 31337;
					text = "PREP ROUND";
					x = "((0.029075*20)*SafeZoneW)";
					y = "((0.0219*5)*SafeZoneH)";
					w = "((0.029075*3)*SafeZoneW)";
					h = "((0.0219*2)*SafeZoneH)";
					action = "[] call ace_sys_arty_ammunition_fnc_onDoPrep";
				};
				class ace_sys_arty_ammunition_ammoShellImage: ace_arty_ammoprep_RscText
				{
					idc = 12558;
					x = "(0.75*SafeZoneW)-(0.0675*SafeZoneW)";
					y = "0*SafeZoneH";
					w = "0.0875*SafeZoneW";
					h = ".5*SafeZoneH";
					style = 48;
					text = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m1.paa";
				};
				class ace_sys_arty_ammunition_ammoChargeImage: ace_arty_ammoprep_RscText
				{
					idc = 12559;
					x = "(0.75*SafeZoneW)-(0.0675*SafeZoneW)";
					y = ".5*SafeZoneH";
					w = "0.0875*SafeZoneW";
					h = ".5*SafeZoneH";
					style = 48;
					text = "\x\ace\Addons\sys_arty_ammunition\105mm\data\images\m14_chg1.paa";
				};
			};
		};
	};
};
//};
