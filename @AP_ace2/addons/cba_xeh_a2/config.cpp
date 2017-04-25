////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Thu Jan 03 12:00:57 2013 : Created on Thu Jan 03 12:00:57 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_xeh_a2 : config.bin{
class CfgPatches
{
	class cba_xeh_a2
	{
		units[] = {};
		weapons[] = {};
		worlds[] = {};
		requiredAddons[] = {"CBA_Main","CBA_XEH","CAData","HALO_Test","CA_Modules","CA_Missions_AlternativeInjurySimulation","CA_Modules_Alice","CA_Missions_AmbientCombat","CA_Modules_Animals","CA_Missions_BattlefieldClearance","CA_Modules_clouds","CA_Modules_Coin","CA_Missions_FirstAidSystem","CA_Modules_Functions","CA_Missions_GarbageCollector","CA_HighCommand","CA_Modules_Marta","CA_Modules_Silvie","BI_SRRS","CA_Modules_UAV","CA_Modules_ZoRA","CA_Animals2_Chicken","CA_Modules_ARTY","CA_Missions_SecOps","CA_Modules_StratLayer","CAAir","CAMisc3","CAA10","CAAir2","CAAir3","CAUI"};
		requiredVersion = 0.1;
		version = "1.0.1.196";
		versionStr = "1.0.1.196";
		versionAr[] = {1,0,1,196};
		author[] = {"CBA Team","Solus","Killswitch"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
	class CBA_A2_xeh
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = {};
	};
};
class Extended_Init_EventHandlers
{
	class StaticCannon
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class M252
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class 2b14_82mm
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class FR_Miles
	{
		SLX_BIS = "(_this select 0) setidentity ""Miles""";
	};
	class FR_Cooper
	{
		SLX_BIS = "(_this select 0) setidentity ""Cooper""";
	};
	class FR_Sykes
	{
		SLX_BIS = "(_this select 0) setidentity ""Sykes""";
	};
	class FR_OHara
	{
		SLX_BIS = "(_this select 0) setidentity ""Ohara""";
	};
	class FR_Rodriguez
	{
		SLX_BIS = "(_this select 0) setidentity ""Rodriguez""";
	};
	class Land_Fire_burning
	{
		SLX_BIS = "(_this select 0) inflame true";
	};
	class Land_Campfire_burning
	{
		SLX_BIS = "(_this select 0) inflame true";
	};
	class Land_Fire_barrel_burning
	{
		SLX_BIS = "(_this select 0) inflame true";
	};
	class FlagCarrierUSA
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_usa_co.paa""";
	};
	class FlagCarrierCDF
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_Chernarus_co.paa""";
	};
	class FlagCarrierRU
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_rus_co.paa""";
	};
	class FlagCarrierINS
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_ChDKZ_co.paa""";
	};
	class FlagCarrierGUE
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\data\flag_NAPA_co.paa""";
	};
	class FlagCarrierChecked
	{
		SLX_BIS = "(_this select 0) setFlagTexture ""\ca\structures\misc\armory\checkered_flag\data\checker_flag_co.paa""";
	};
	class Barrack2
	{
		SLX_BIS = "(_this select 0) setdir getdir (_this select 0)";
	};
	class Mass_grave
	{
		SLX_BIS = "dummy = _this spawn ('ca\characters2\OTHER\scripts\fly.sqf' call SLX_XEH_COMPILE)";
	};
	class AAV
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)};_this spawn ('\ca\tracked2\AAV\scripts\init.sqf' call SLX_XEH_COMPILE)";
	};
	class A10
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
	class Su34
	{
		SLX_BIS = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	};
};
class Extended_firedBis_Eventhandlers
{
	class StaticCannon
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class M252
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class 2b14_82mm
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class A10
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
	class Su34
	{
		SLX_BIS = "_this call BIS_Effects_EH_Fired";
	};
};
class Extended_firednear_Eventhandlers
{
	class CAAnimalBase
	{
		SLX_BIS = "_this execFSM ""CA\animals2\Data\scripts\reactFire.fsm""";
	};
};
class Extended_hit_Eventhandlers
{
	class TargetPopUpTarget
	{
		SLX_BIS = "[(_this select 0)] spawn ('ca\misc\scripts\PopUpTarget.sqf' call SLX_XEH_COMPILE)";
	};
	class TargetEpopup
	{
		SLX_BIS = "[(_this select 0)] spawn ('ca\misc\scripts\PopUpTarget.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_killed_Eventhandlers
{
	class A10
	{
		SLX_BIS = "_this call BIS_Effects_EH_Killed";
	};
	class Su34
	{
		SLX_BIS = "_this call BIS_Effects_EH_Killed";
	};
};
class DefaultEventHandlers;
class CfgVehicles
{
	class All
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
	};
	class Static: All
	{
		class EventHandlers{};
	};
	class LandVehicle;
	class Car: LandVehicle
	{
		class Eventhandlers: DefaultEventhandlers
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
	};
	class Tank: LandVehicle
	{
		class Eventhandlers: DefaultEventhandlers
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
	};
	class Air;
	class Helicopter: Air
	{
		class Eventhandlers: DefaultEventhandlers
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
	};
	class Plane: Air
	{
		class Eventhandlers: DefaultEventhandlers
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
	};
	class AllVehicles;
	class Ship: AllVehicles
	{
		class Eventhandlers: DefaultEventhandlers
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
	};
	class StaticWeapon;
	class StaticCannon: StaticWeapon
	{
		class Eventhandlers
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
	};
	class Animal;
	class CAAnimalBase: Animal
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
	};
	class StaticMortar;
	class M252: StaticMortar
	{
		class Eventhandlers
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
	};
	class 2b14_82mm: StaticMortar
	{
		class Eventhandlers
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
	};
	class SoldierWB;
	class FR_Base: SoldierWB
	{
		class EventHandlers;
	};
	class FR_Miles: FR_Base
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
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
	};
	class FR_GL: FR_Base
	{
		class EventHandlers;
	};
	class FR_Cooper: FR_GL
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
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
	};
	class FR_Marksman: FR_Base
	{
		class EventHandlers;
	};
	class FR_Sykes: FR_Marksman
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
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
	};
	class FR_Corpsman: FR_Base
	{
		class EventHandlers;
	};
	class FR_OHara: FR_Corpsman
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
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
	};
	class FR_AR: FR_Base
	{
		class EventHandlers;
	};
	class FR_Rodriguez: FR_AR
	{
		class EventHandlers: EventHandlers
		{
			handleidentity = "true";
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
	};
	class Civilian;
	class SoldierEB;
	class SoldierGB;
	class HelicopterWreck;
	class AH1ZWreck: HelicopterWreck
	{
		class Eventhandlers
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
	};
	class MH60Wreck: HelicopterWreck
	{
		class Eventhandlers
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
	};
	class PlaneWreck;
	class AV8BWreck: PlaneWreck
	{
		class Eventhandlers
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
	};
	class Mi17Wreck: HelicopterWreck
	{
		class Eventhandlers
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
	};
	class Land_Fire;
	class Land_Fire_burning: Land_Fire
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
	};
	class Land_Campfire;
	class Land_Campfire_burning: Land_Campfire
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
	};
	class Land_Fire_barrel: Land_Fire{};
	class Land_Fire_barrel_burning: Land_Fire_barrel
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
	};
	class FlagCarrier;
	class FlagCarrierUSA: FlagCarrier
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
	};
	class FlagCarrierCDF: FlagCarrierUSA
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
	};
	class FlagCarrierRU: FlagCarrierUSA
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
	};
	class FlagCarrierINS: FlagCarrierUSA
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
	};
	class FlagCarrierGUE: FlagCarrierUSA
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
	};
	class FlagCarrierCore;
	class FlagCarrierChecked: FlagCarrierCore
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
	};
	class TargetBase;
	class TargetPopUpTarget: TargetBase
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
	};
	class TargetEpopup: TargetBase
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
	};
	class Land_Barrack2;
	class Barrack2: Land_Barrack2
	{
		class Eventhandlers
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
	};
	class Grave;
	class Mass_grave: Grave
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
	};
	class Tracked_APC;
	class AAV: Tracked_APC
	{
		class EventHandlers: DefaultEventhandlers
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
	};
	class Pickup_PK_base: Car
	{
		class Eventhandlers;
	};
	class A10: Plane
	{
		class Eventhandlers
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
	};
	class A10Wreck: PlaneWreck
	{
		class Eventhandlers
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
	};
	class SU25Wreck: PlaneWreck
	{
		class Eventhandlers
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
	};
	class Mi24Wreck: HelicopterWreck
	{
		class Eventhandlers
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
	};
	class F35bWreck: PlaneWreck
	{
		class Eventhandlers
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
	};
	class MQ9PredatorWreck: PlaneWreck
	{
		class Eventhandlers
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
	};
	class MV22Wreck: PlaneWreck
	{
		class Eventhandlers
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
	};
	class C130JWreck: PlaneWreck
	{
		class Eventhandlers
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
	};
	class Ka52Wreck: HelicopterWreck
	{
		class Eventhandlers
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
	};
	class UH1YWreck: HelicopterWreck
	{
		class Eventhandlers
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
	};
	class Su34: Plane
	{
		class Eventhandlers
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
	};
	class MQ9PredatorB;
	class CruiseMissile2: MQ9PredatorB
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
	};
};
//};
