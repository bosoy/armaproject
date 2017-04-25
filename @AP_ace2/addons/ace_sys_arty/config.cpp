////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:05:43 2013 : Created on Sat Jun 08 13:05:43 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_arty : config.bin{
class CfgPatches
{
	class ace_sys_arty
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CA_Modules_ARTY","CAWeapons_E_M252_81mm_Mortar","CAWeapons_E_Podnos_2b14_82mm","CAWeapons_E_M119_Howitzer","CAWeapons_E_D30","cba_main","ace_main"};
		version = "1.14.0.593";
		author[] = {"Sandiford","Nou"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_arty
	{
		init = "call ('\x\ace\addons\sys_arty\XEH_preinit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class StaticMortar
	{
		class ace_sys_arty
		{
			init = "_this call ace_sys_arty_fnc_gunInit";
		};
	};
	class StaticCannon
	{
		class ace_sys_arty
		{
			init = "_this call ace_sys_arty_fnc_gunInit";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class StaticMortar
	{
		ace_sys_arty = "_this call ace_sys_arty_fnc_fired";
	};
	class StaticCannon
	{
		ace_sys_arty = "_this call ace_sys_arty_fnc_fired";
	};
};
class CfgVehicles
{
	class StaticMortar;
	class M252: StaticMortar
	{
		ACE_ARTY_DefaultDispersion = 100;
	};
	class 2b14_82mm: StaticMortar
	{
		ACE_ARTY_DefaultDispersion = 100;
	};
	class StaticCannon;
	class M119: StaticCannon
	{
		ACE_ARTY_DefaultDispersion = 60;
	};
	class D30_Base: StaticCannon
	{
		ACE_ARTY_DefaultDispersion = 60;
	};
	class ReammoBox;
	class ACE_ArtyEquip_Box: ReammoBox
	{
		scope = 2;
		displayName = "Aiming Post Box (Orange,Green)";
		vehicleClass = "ACE_Arty_Equipment";
		model = "\Ca\misc\Misc_cargo_cont_tiny";
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class Thing;
	class ACE_Arty_BaseThing: Thing
	{
		scope = 0;
		icon = "iconThing";
		mapSize = 0.3;
		vehicleClass = "ACE_Arty_Equipment";
		nameSound = "obj_object";
		TextPlural = "Objects";
		TextSingular = "Object";
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"obj_object"};
				speechPlural[] = {"obj_objects"};
			};
			class EN: Default{};
			class CZ
			{
				speechSingular[] = {"obj_object_CZ"};
				speechPlural[] = {"obj_objects_CZ"};
			};
			class CZ_Akuzativ
			{
				speechSingular[] = {"obj_object_CZ4P"};
				speechPlural[] = {"obj_objects_CZ4P"};
			};
			class RU
			{
				speechSingular[] = {"obj_object_RU"};
				speechPlural[] = {"obj_objects_RU"};
			};
		};
		picture = "pictureThing";
		displayName = "";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "";
		camouflage = 0.1;
		accuracy = 0.15;
		coefInside = 1;
		coefInsideHeur = 0.25;
		canBeShot = 1;
		armor = 0;
		armorStructural = 0;
		damageResistance = 0;
		irTarget = 0;
		laserTarget = 0;
		hideUnitInfo = 1;
		side = 4;
		type = 1;
		cost = 0;
		threat[] = {0,0,0};
		airFriction0[] = {25,12,2.5};
		airFriction1[] = {25,12,2.5};
		airFriction2[] = {25,12,2.5};
		airFriction3[] = {25,12,2.5};
		airRotation = 0;
		minHeight = 0;
		maxHeight = 40000;
		avgHeight = 1000;
		ladders[] = {};
		timeToLive = 0;
		disappearAtContact = 0;
		submerged = 0.0;
		submergeSpeed = 0.0;
		soundCrash[] = {"",100,1};
		soundDammage[] = {"",100,1};
		soundEngine[] = {"",100,1};
		soundEnviron[] = {"",100,1};
		soundLandCrash[] = {"",100,1};
		destrType = "DestructNo";
		simulation = "thing";
		weight = 1.0;
		gravityFactor = 1;
		maxSpeed = 10000;
		canFloat = 0;
		model = "";
		animated = 1;
		reversed = 0;
		autocenter = 1;
		sectionsInherit = "";
		hiddenSelections[] = {"all"};
		class AnimationSources{};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		class UserActions{};
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 0;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		ACE_Weight = 10000;
	};
	class ACE_Arty_ShellHolder: ACE_Arty_BaseThing
	{
		ACE_canBeLoad = 0;
		ACE_canBeCargo = 1;
		ACE_canGear = 0;
		ACE_canLoadFront = 0;
		ACE_Weight = 18.1;
	};
};
class CfgVehicleClasses
{
	class ACE_Howitzers
	{
		displayName = "$STR_ACE_ARTY_VEHCLS_HOWITZERS";
	};
	class ACE_Arty_Equipment
	{
		displayName = "$STR_ACE_ARTY_VEHCLS_EQUIPMENT";
	};
	class ACE_Arty_Ammunition
	{
		displayName = "$STR_ACE_ARTY_VEHCLS_AMMO";
	};
};
class cfgAmmo
{
	class ShellBase;
	class Sh_81_HE: ShellBase{};
	class Sh_81_WP: Sh_81_HE
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class Sh_81_ILLUM: Sh_81_HE
	{
		ace_sys_arty_deploy = "ARTY_Flare_Small";
		ace_sys_arty_deployAltitude = 250;
	};
	class ACE_Sh_60_HE: Sh_81_HE{};
	class ACE_Sh_60_WP: Sh_81_WP
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class ACE_Sh_60_ILLUM: Sh_81_ILLUM
	{
		ace_sys_arty_deploy = "ARTY_Flare_Small";
		ace_sys_arty_deployAltitude = 250;
	};
	class Sh_120_HE: ShellBase
	{
		indirecthit = 50;
		indirecthitrange = 11.52;
	};
	class ACE_Sh_120_WP: Sh_120_HE
	{
		cratereffects = "ExploAmmoCrater";
		explosioneffects = "WPExplosion";
		explosive = 0.8;
		hit = 60;
		indirecthit = 25;
		indirecthitrange = 11.52;
		soundhit[] = {"\ca\weapons\data\sound\explosion\grenade_new1",3.16228,1};
		whistledist = 60;
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class ACE_Sh_120_ILLUM: Sh_120_HE
	{
		cratereffects = "";
		explosioneffects = "";
		explosive = 0;
		hit = 8;
		indirecthit = 0;
		indirecthitrange = 0;
		soundhit[] = {"",0,1};
		whistledist = 0;
		ace_sys_arty_deploy = "ARTY_Flare_Medium";
		ace_sys_arty_deployAltitude = 300;
	};
	class Sh_105_HE: ShellBase{};
	class Sh_105_WP: Sh_105_HE
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class Sh_105_SMOKE: Sh_105_HE
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class Sh_105_ILLUM: Sh_105_HE
	{
		ace_sys_arty_deploy = "ARTY_Flare_Medium";
		ace_sys_arty_deployAltitude = 300;
	};
	class ACE_Sh_155_HE: Sh_105_HE
	{
		indirecthit = 55;
		indirecthitrange = 15.36;
	};
	class ACE_Sh_155_WP: Sh_105_WP
	{
		indirecthit = 27.5;
		indirecthitrange = 15.36;
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class ACE_Sh_155_SMOKE: Sh_105_SMOKE
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class ACE_Sh_155_ILLUM: Sh_105_ILLUM
	{
		ace_sys_arty_deploy = "ARTY_Flare_Medium";
		ace_sys_arty_deployAltitude = 300;
	};
	class Sh_82_HE: ShellBase{};
	class Sh_82_WP: Sh_82_HE
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class Sh_82_ILLUM: Sh_82_HE
	{
		ace_sys_arty_deploy = "ARTY_Flare_Small";
		ace_sys_arty_deployAltitude = 250;
	};
	class Sh_122_HE: ShellBase{};
	class Sh_122_WP: Sh_122_HE
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class Sh_122_SMOKE: Sh_122_HE
	{
		ace_sys_arty_deploy = "ARTY_SmokeShellWhite";
		ace_sys_arty_deployOnImpact = 1;
	};
	class Sh_122_ILLUM: Sh_122_HE
	{
		ace_sys_arty_deploy = "ARTY_Flare_Medium";
		ace_sys_arty_deployAltitude = 300;
	};
	class B_762x54_noTracer;
	class ace_sys_arty_shrapnel: B_762x54_noTracer
	{
		timeToLive = 2;
	};
};
//};
