////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:12 2013 : Created on Mon Oct 14 23:07:12 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_destruction : config.bin{
class CfgPatches
{
	class ace_sys_destruction
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons","ace_main","CAData","CAData_ParticleEffects"};
		version = "1.14.0.597";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_destruction
	{
		init = "call ('\x\ace\addons\sys_destruction\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_destruction
	{
		init = "call ('\x\ace\addons\sys_destruction\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Hit_EventHandlers{};
class Extended_Killed_EventHandlers
{
	class AllVehicles
	{
		class ace_sys_destruction
		{
			killed = "_this call ace_sys_destruction_fnc_destr";
			exclude[] = {"Man"};
		};
	};
};
class CfgCloudlets{};
class CfgLights
{
	class ExploLightSmall
	{
		color[] = {20,19,17.74};
		ambient[] = {5,5,5};
		diffuse[] = {0,0,0};
		brightness = 0.02;
	};
};
class ExploAmmoExplosion
{
	class ExploAmmoFlash
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ExploAmmoFlash";
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class LightExplosion
	{
		simulation = "light";
		type = "ExploLightSmall";
		position[] = {0,0,0};
		intensity = 0.001;
		interval = 1;
		lifeTime = 0.15;
	};
	class ExploAmmoSmoke
	{
		position[] = {0,0,0};
		simulation = "particles";
		type = "ExploAmmoSmoke";
		intensity = 1.5;
		interval = 1.5;
		lifeTime = 1.5;
	};
};
class CfgVehicles
{
	class Land;
	class LandVehicle: Land{};
	class Tank: LandVehicle
	{
		class DestructionEffects
		{
			class Fire1
			{
				intensity = 0;
				interval = 1;
				lifetime = 0;
				position = "destructionEffect1";
				simulation = "particles";
				type = "ObjectDestructionFire1";
			};
			class Fire2
			{
				intensity = 0;
				interval = 1;
				lifetime = 0;
				position = "destructionEffect1";
				simulation = "particles";
				type = "ObjectDestructionFire1";
			};
		};
	};
	class Car: LandVehicle
	{
		class DestructionEffects
		{
			class Fire1
			{
				intensity = 0;
				interval = 1;
				lifetime = 0;
				position = "destructionEffect1";
				simulation = "particles";
				type = "ObjectDestructionFire1";
			};
			class Fire2
			{
				intensity = 0;
				interval = 1;
				lifetime = 0;
				position = "destructionEffect1";
				simulation = "particles";
				type = "ObjectDestructionFire1";
			};
		};
	};
	class Sign_sphere100cm_EP1;
	class ace_flameout_1: Sign_sphere100cm_EP1
	{
		model = "\ca\weapons\empty.p3d";
		class EventHandlers
		{
			init = "_this call ace_sys_destruction_fnc_flameOut";
		};
	};
	class ace_flameout_2: Sign_sphere100cm_EP1
	{
		model = "\ca\weapons\empty.p3d";
		class EventHandlers
		{
			init = "_this call ace_sys_destruction_fnc_flameOut";
		};
	};
	class Sound;
	class ace_flameout: Sound
	{
		scope = 2;
		sound = "ace_flameout";
		displayName = "$STR_DN_ALARM";
		class EventHandlers
		{
			init = "_this call ace_sys_destruction_fnc_flameOut";
		};
	};
	class Helicopter;
	class ParachuteBase: Helicopter
	{
		ace_sys_destruction_no_killed_fx = 1;
	};
	class Plane;
	class BIS_Steerable_Parachute: Plane
	{
		ace_sys_destruction_no_killed_fx = 1;
	};
	class Strategic;
	class ReammoBox: Strategic
	{
		class EventHandlers
		{
			killed = "_this call ace_sys_destruction_fnc_destr";
		};
	};
};
class CfgAmmo
{
	class ShellBase;
	class BulletBase;
	class ace_fuelexpbig: ShellBase
	{
		hit = 100;
		indirectHit = 80;
		indirectHitRange = 3;
		soundHit[] = {"Ca\sounds\Weapons\explosions\multisamples\expl_vehicle_2","db16",1,1600};
		typicalSpeed = 100;
		explosive = 1;
		cost = 300;
		model = "\ca\weapons\empty";
		airFriction = 0;
		timeToLive = 1;
		explosionTime = 0.001;
		soundFly[] = {"",1,1};
		soundEngine[] = {"",1,4};
		explosionEffects = "VehicleExplosionEffects";
	};
	class ace_fuelexpsmall: ace_fuelexpbig
	{
		hit = 50;
		indirectHit = 40;
		indirectHitRange = 2;
		soundHit[] = {"Ca\sounds\Weapons\explosions\multisamples\expl_vehicle_1","db16",1,1600};
		explosionEffects = "ExploAmmoExplosion";
	};
	class ace_fuelexpspark: BulletBase
	{
		hit = 7.5;
		indirectHit = 6;
		indirectHitRange = 1;
		explosive = 0.1;
		craterEffects = "ImpactEffectsBig";
		explosionEffects = "NoExplosion";
		soundHit[] = {"Ca\sounds\Weapons\explosions\supersonic_crack_50meters","db16",0.7,100};
		soundCrack1[] = {"Ca\sounds\Weapons\explosions\supersonic_crack_close","db16",0.6,100};
		soundCrack2[] = {"Ca\sounds\Weapons\explosions\supersonic_crack_50meters","db16",0.7,100};
		soundCrack3[] = {"Ca\sounds\Weapons\explosions\supersonic_crack_50meters","db16",0.8,100};
		hitGroundSoft[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitGroundHard[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitMan[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitArmor[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitIron[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitBuilding[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitFoliage[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitWood[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitGlass[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitGlassArmored[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitConcrete[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitRubber[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitPlastic[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitDefault[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitMetal[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
		hitMetalplate[] = {"soundCrack1",0.33,"soundCrack2",0.34,"soundCrack3",0.33};
	};
	class HelicopterExploSmall: ShellBase{};
	class HelicopterExploBig: HelicopterExploSmall{};
	class ACE_HelicopterExploSmall: HelicopterExploSmall
	{
		hit = 250;
		indirectHit = 50;
		indirectHitRange = 6;
		explosionEffects = "VehicleExplosionEffects";
	};
	class ACE_HelicopterExploBig: HelicopterExploBig
	{
		hit = 1000;
		indirecthit = 20;
		indirecthitrange = 10;
	};
	class B_30mmA10_AP: BulletBase
	{
		ace_smokemultiplier = 5;
	};
};
class CfgSounds
{
	class Fire
	{
		sound[] = {"\x\ace\addons\sys_destruction\sfx\burning",0.316228,1};
	};
	class ace_electricspark1
	{
		name = "ace_electricspark1";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric1.wss",3,1};
		titles[] = {};
	};
	class ace_electricspark2
	{
		name = "ace_electricspark2";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric2.wss",3,1};
		titles[] = {};
	};
	class ace_electricspark3
	{
		name = "ace_electricspark3";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric3.wss",3,1};
		titles[] = {};
	};
	class ace_electricspark4
	{
		name = "ace_electricspark4";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric4.wss",3,1};
		titles[] = {};
	};
	class ace_electricspark5
	{
		name = "ace_electricspark5";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric5.wss",3,1};
		titles[] = {};
	};
	class ace_electricspark6
	{
		name = "ace_electricspark6";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric6.wss",3,1};
		titles[] = {};
	};
	class ace_electricspark7
	{
		name = "ace_electricspark7";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric7.wss",3,1};
		titles[] = {};
	};
	class ace_electricspark8
	{
		name = "ace_electricspark8";
		sound[] = {"\x\ace\addons\sys_destruction\sfx\electric8.wss",3,1};
		titles[] = {};
	};
};
class CfgSFX
{
	class ace_flameout
	{
		sounds[] = {"ace_flameoutsound"};
		name = "flame out";
		ace_flameoutsound[] = {"\x\ace\addons\sys_destruction\sfx\flame_out_sound.wss",4.1622777,1,500,1,0.0,0.0,0.0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
};
//};
