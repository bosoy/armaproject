////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:08:09 2013 : Created on Mon Oct 14 23:08:09 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_sandbag : config.bin{
class CfgPatches
{
	class ace_sys_sandbag
	{
		units[] = {"ACE_Sandbag_Build","ACE_Sandbag_NoGeo","ACE_SandBox","ACE_ConcertinaWire","ACE_ConcertinaWireNoGeo","ACE_ConcertinaWireCoil","ACE_Tactical_Ladder"};
		weapons[] = {"ACE_TacticalLadder_Pack"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_interaction","ace_sys_ruck"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_sandbag
		{
			list[] = {"ace_sys_sandbag"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_sandbag
	{
		init = "call ('\x\ace\addons\sys_sandbag\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_sandbag\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgWeapons
{
	class Default;
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_sandbag: ACE_Dummy_Utility
		{
			magazines[] = {"ACE_Sandbag_Magazine"};
		};
	};
	class ACE_Rucksack;
	class ACE_TacticalLadder_Pack: ACE_Rucksack
	{
		scope = 2;
		displayName = "Tactical Ladder";
		model = "\x\ace\addons\sys_sandbag\ace_tacticalladder_pack.p3d";
		picture = "\x\ace\addons\sys_sandbag\data\equip\ace_tactical_ladder_pack_ca.paa";
		descriptionShort = "";
		ACE_PackSize = 1;
		ACE_Size = 20251;
		ACE_Weight = 10.5;
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class ACE_SandBag_Magazine: CA_Magazine
	{
		ACE_Weight = 0.115;
		ACE_Size = 100;
		scope = 2;
		value = 1;
		type = 256;
		ammo = "";
		displayName = "$STR_ACE_M_SBEMPTY";
		picture = "\x\ace\addons\sys_sandbag\data\equip\m_sandbag_ca.paa";
		model = "\x\ace\addons\sys_sandbag\ace_sandbag_m.p3d";
		count = 1;
		initSpeed = 100;
	};
};
class cfgAmmo
{
	class Default;
	class ACE_Sandbag_NoGeo_Det: Default
	{
		model = "\x\ace\addons\sys_sandbag\detector_bag.p3d";
		explosive = 1;
		explosionEffects = "";
		CraterEffects = "";
		visibleFire = 0;
		audibleFire = 0;
		visibleFireTime = 0;
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		typicalSpeed = 0;
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
		cost = 0;
		deflecting = 0;
		sideAirFriction = 0;
		airFriction = 0;
		maneuvrability = 0;
		maxControlRange = 0;
		timeToLive = 3;
		simulation = "shotshell";
		simulationStep = 0.001;
		tracerColor[] = {0,0,0,0};
		tracerColorR[] = {0,0,0,0};
		soundFly[] = {"",1,1};
		soundEngine[] = {"",1,1};
		soundHit[] = {"",1,1};
		supersonicCrackNear[] = {"",1,1};
		supersonicCrackFar[] = {"",1,1};
		hitGround[] = {"soundHit",1};
		hitMan[] = {"soundHit",1};
		hitArmor[] = {"soundHit",1};
		hitBuilding[] = {"soundHit",1};
		class HitEffects
		{
			vehicle = "";
			object = "";
		};
		smokeColor[] = {0,0,0,0};
		class Smoke
		{
			interval = 0.1;
			cloudletDuration = 0;
			cloudletAnimPeriod = 0;
			cloudletSize = 0;
			cloudletAlpha = 0;
			cloudletGrowUp = 0;
			cloudletFadeIn = 0;
			cloudletFadeOut = 0;
			cloudletAccY = 0;
			cloudletMinYSpeed = 0;
			cloudletMaxYSpeed = 0;
			cloudletShape = "";
			cloudletColor[] = {0,0,0,0};
			initT = 1000;
			deltaT = -500;
			class Table
			{
				class T1
				{
					maxT = 0;
					color[] = {1,1,1,1};
				};
				class T2
				{
					maxT = 1000;
					color[] = {0.2,0.2,0.2,1};
				};
			};
			density = 0;
			size = 0;
			initYSpeed = 0;
			timeToLive = 0;
			in = 0;
			out = 0;
		};
	};
};
class CfgVehicleClasses
{
	class ACE_Sandbags
	{
		displayName = "$STR_ACE_VC_ACESB";
	};
};
class CfgVehicles
{
	class Land_HBarrier_large;
	class ACE_Sandbag_Build: Land_HBarrier_large
	{
		vehicleClass = "ACE_Sandbags";
		side = 4;
		picture = "";
		model = "\x\ace\addons\sys_sandbag\ace_sandbag_build.p3d";
		displayName = "$STR_ACE_Sandbag";
		typicalCargo[] = {};
		armor = 12000;
		mapSize = 0.4;
		nameSound = "Bunker";
		icon = "\x\ace\addons\sys_sandbag\data\icons\icon_sandbag_ca.paa";
		accuracy = 1000;
		destrType = "DestructMan";
		class DestructionEffects{};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\ace\addons\sys_sandbag\data\bag_destruct.rvmat","x\ace\addons\sys_sandbag\data\bag_destruct.rvmat","x\ace\addons\sys_sandbag\data\bag_destruct.rvmat"};
		};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		ACE_InteractionMenu = "Sandbag";
		ACE_Interaction = "Move";
	};
	class ACE_Sandbag_NoGeo: ACE_Sandbag_Build
	{
		scope = 1;
		model = "\x\ace\addons\sys_sandbag\ace_sandbag_nogeo.p3d";
		class UserActions{};
	};
	class Land_BagFenceCorner: Land_HBarrier_large
	{
		ACE_InteractionMenu = "Sandbag";
		ACE_Interaction = "Unbuild";
	};
	class Land_BagFenceEnd: Land_BagFenceCorner{};
	class Land_BagFenceLong: Land_BagFenceCorner{};
	class Land_BagFenceRound: Land_BagFenceCorner{};
	class Land_BagFenceShort: Land_BagFenceCorner{};
	class Fence;
	class Thing;
	class NonStrategic;
	class ACE_ConcertinaWireNoGeo: Fence
	{
		scope = 1;
		displayName = "";
		model = "\x\ace\addons\sys_sandbag\ACE_ConcertinaWireNoGeo";
		destrType = "DestructTent";
		accuracy = 0.3;
		mapSize = 2.8;
		animated = 1;
		autocenter = 0;
		attachTo_pos[] = {0,0.5,0.5};
		armor = 200;
		class AnimationSources
		{
			class fix1
			{
				source = "user";
				animPeriod = 1e-007;
				initPhase = 0;
			};
			class fix2: fix1{};
			class fix3: fix1{};
			class fix4: fix1{};
			class rotate
			{
				source = "user";
				animPeriod = 1e-007;
			};
			class wire_2
			{
				source = "user";
				animPeriod = 1e-007;
			};
			class wire_3: wire_2{};
			class wire_4: wire_2{};
			class wire_5: wire_2{};
			class wire_6: wire_2{};
			class wire_7: wire_2{};
			class wire_8: wire_2{};
			class wire_9: wire_2{};
			class wire_10: wire_2{};
			class wire_11: wire_2{};
			class wire_12: wire_2{};
			class wire_13: wire_2{};
			class wire_14: wire_2{};
			class wire_15: wire_2{};
			class wire_16: wire_2{};
			class wire_17: wire_2{};
			class wire_18: wire_2{};
			class wire_2_1: wire_2
			{
				animPeriod = 8;
			};
			class wire_3_1: wire_2_1{};
			class wire_4_1: wire_2_1{};
			class wire_5_1: wire_2_1{};
			class wire_6_1: wire_2_1{};
			class wire_7_1: wire_2_1{};
			class wire_8_1: wire_2_1{};
			class wire_9_1: wire_2_1{};
			class wire_10_1: wire_2_1{};
			class wire_11_1: wire_2_1{};
			class wire_12_1: wire_2_1{};
			class wire_13_1: wire_2_1{};
			class wire_14_1: wire_2_1{};
			class wire_15_1: wire_2_1{};
			class wire_16_1: wire_2_1{};
			class wire_17_1: wire_2_1{};
			class wire_18_1: wire_2_1{};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_ConcertinaWire: ACE_ConcertinaWireNoGeo
	{
		scope = 2;
		vehicleClass = "ACE_Sandbags";
		displayName = "$STR_ACE_CONCERTINA_WIRE";
		model = "\x\ace\addons\sys_sandbag\ACE_ConcertinaWire";
		class Eventhandlers
		{
			killed = "[_this,0] spawn ace_sys_sandbag_fnc_killed";
		};
	};
	class ACE_ConcertinaWireCoil: Thing
	{
		scope = 2;
		displayName = "$STR_ACE_CONCERTINA_WIRECOIL";
		model = "\x\ace\addons\sys_sandbag\ACE_ConcertinaWireCoil";
		vehicleClass = "ACE_Sandbags";
		mapsize = 0.5;
		animated = 0;
		nameSound = "fence";
		typicalCargo[] = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		cost = 0;
		armor = 1000;
		destrType = "DestructNo";
		accuracy = 1000;
		attachTo_pos[] = {0,0.5,0.5};
		autocenter = 0;
		class eventhandlers
		{
			init = "(_this select 0) setvectorup [0,0,1]";
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "true";
		ACE_Weight = 15;
	};
	class Fort_RazorWire: NonStrategic
	{
		armor = 300;
		class Eventhandlers
		{
			killed = "[_this,1] spawn ace_sys_sandbag_fnc_killed";
		};
	};
	class House;
	class ACE_Tactical_Ladder: House
	{
		displayName = "$STR_ACE_TACTICALLADDER";
		class DestructionEffects{};
		model = "\x\ace\addons\sys_sandbag\ace_tacticalladder";
		animated = 1;
		autocenter = 0;
		featureSize = 12;
		ladders[] = {{"start","end"}};
		class AnimationSources
		{
			class rotate
			{
				source = "user";
				animPeriod = 1e-007;
			};
			class extract_1
			{
				source = "user";
				animPeriod = 1e-007;
			};
			class extract_2: extract_1{};
			class extract_3: extract_1{};
			class extract_4: extract_1{};
			class extract_5: extract_1{};
			class extract_6: extract_1{};
			class extract_7: extract_1{};
			class extract_8: extract_1{};
			class extract_9: extract_1{};
			class extract_10: extract_1{};
			class extract_11: extract_1{};
		};
		ACE_Weight = 10.5;
	};
	class ACE_Rucksack_crate;
	class ACE_TacticalLadder_Pack_crate: ACE_Rucksack_crate
	{
		displayName = "$STR_ACE_TACTICALLADDER";
		model = "\x\ace\addons\sys_sandbag\ace_tacticalladder_pack.p3d";
	};
	class ReammoBox;
	class ACE_SandBox: ReammoBox
	{
		vehicleClass = "ACE_Ammunition";
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_ACE_V_SANDBOX";
		model = "\Ca\misc\Misc_cargo_cont_tiny";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Sandbag_Magazine
			{
				magazine = "ACE_Sandbag_Magazine";
				count = 500;
			};
		};
	};
};
//};
