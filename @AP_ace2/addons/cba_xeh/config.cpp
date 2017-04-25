////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Tue Feb 12 00:27:26 2013 : Created on Tue Feb 12 00:27:26 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class cba_xeh : config.bin{
class CfgPatches
{
	class cba_xeh
	{
		units[] = {};
		weapons[] = {};
		worlds[] = {};
		requiredAddons[] = {};
		requiredVersion = 1.0;
		version = "1.0.1.196";
		versionStr = "1.0.1.196";
		versionAr[] = {1,0,1,196};
		author[] = {"CBA Team","Solus","Killswitch"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
	class Extended_EventHandlers
	{
		units[] = {};
		weapons[] = {};
		worlds[] = {};
		requiredAddons[] = {};
		requiredVersion = 1.0;
		version = "4.0.0";
		versionStr = "4.0.0";
		versionAr[] = {4,0,0};
		author[] = {"CBA Team","Solus","Killswitch"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
	class CBA_Extended_EventHandlers
	{
		units[] = {};
		weapons[] = {};
		worlds[] = {};
		requiredAddons[] = {};
		requiredVersion = 1.0;
		version = "1.0.1.196";
		versionStr = "1.0.1.196";
		versionAr[] = {1,0,1,196};
		author[] = {"CBA Team","Solus","Killswitch"};
		authorUrl = "http://dev-heaven.net/projects/cca";
	};
};
class Extended_EventHandlers
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
class Extended_PreInit_EventHandlers{};
class Extended_PostInit_EventHandlers{};
class Extended_InitPost_EventHandlers{};
class Extended_init_Eventhandlers{};
class Extended_firednear_Eventhandlers{};
class Extended_dammaged_Eventhandlers{};
class Extended_hit_Eventhandlers{};
class Extended_fired_Eventhandlers{};
class Extended_firedBis_Eventhandlers{};
class Extended_killed_Eventhandlers{};
class Extended_AnimChanged_EventHandlers{};
class Extended_AnimStateChanged_EventHandlers{};
class Extended_AnimDone_EventHandlers{};
class Extended_Engine_EventHandlers{};
class Extended_Fuel_EventHandlers{};
class Extended_Gear_EventHandlers{};
class Extended_IncomingMissile_EventHandlers{};
class Extended_LandedTouchDown_EventHandlers{};
class Extended_LandedStopped_EventHandlers{};
class Extended_HandleDamage_EventHandlers{};
class Extended_GetIn_EventHandlers
{
	class AllVehicles
	{
		class SLX_GetInMan
		{
			scope = 2;
			getIn = "_this call SLX_XEH_EH_GetInMan";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class AllVehicles
	{
		class SLX_GetOutMan
		{
			scope = 2;
			getOut = "_this call SLX_XEH_EH_GetOutMan";
		};
	};
};
class Extended_GetInMan_EventHandlers{};
class Extended_GetOutMan_EventHandlers{};
class Extended_Respawn_EventHandlers
{
	class CAManBase
	{
		class SLX_RespawnInit
		{
			scope = 2;
			respawn = "_this call SLX_XEH_EH_RespawnInit";
		};
	};
};
class DefaultEventhandlers
{
	init = "if(isNil 'BIS_Effects_Init') then { call ('\ca\Data\ParticleEffects\SCRIPTS\init.sqf' call SLX_XEH_COMPILE)}";
	delete fired;
	firedBis = "_this call BIS_Effects_EH_Fired";
	killed = "_this call BIS_Effects_EH_Killed";
};
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
	class Logic;
	class SLX_XEH_Logic: Logic
	{
		displayName = "XEH (backup) Initialization Logic";
		vehicleClass = "Modules";
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
