////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.51
//Mon Jul 28 05:52:52 2014 : Source 'file' date Mon Jul 28 05:52:52 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_missileguidance : config.bin{
class CfgPatches
{
	class ace_sys_missileguidance
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_vehicle","ace_c_weapon","ace_sys_modelspecial","ace_sys_crewserved"};
		version = "1.14.0.595";
		author[] = {"Sickboy","zGuba","q1184","Headspace"};
		class ACE_Options
		{
			group = "VEH";
			title = "FCS (Air)";
			class Lase_Kh29
			{
				title = "Toggle Laser KH29";
			};
			class Lase_Kh29_Up
			{
				title = "Laser KH29 up";
			};
			class Lase_Kh29_Left
			{
				title = "Laser KH29 left";
			};
			class Lase_Kh29_Right
			{
				title = "Laser KH29 right";
			};
			class Lase_Kh29_Down
			{
				title = "Laser KH29 down";
			};
			class Lase_Gunship
			{
				title = "Toggle Laser";
			};
			class Javelin_Mode
			{
				title = "Toggle Fire Mode";
			};
			class Longbow_Map
			{
				title = "Toggle Longbow Map";
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_missileguidance
	{
		init = "call ('\x\ace\addons\sys_missileguidance\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_missileguidance
	{
		clientInit = "[] spawn ace_sys_missileguidance_fnc_opt_limitloop";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Land
	{
		ace_sys_missileguidance = "if ((_this select 4) isKindOf 'MissileBase' || {(_this select 4) isKindOf 'LaserBombCore'} || {(_this select 4) isKindOf 'BombCore'}) then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
	class TU_UH60L_ESSS_FLIR
	{
		ace_sys_missileguidance = "if ((_this select 4) isKindOf 'MissileBase' || {(_this select 4) isKindOf 'LaserBombCore'} || {(_this select 4) isKindOf 'BombCore'}) then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
	class AH1_Base
	{
		ace_sys_missileguidance = "if ((_this select 4) isKindOf 'MissileBase' || {(_this select 4) isKindOf 'LaserBombCore'} || {(_this select 4) isKindOf 'BombCore'}) then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
	class AH64_base_EP1
	{
		ace_sys_missileguidance = "if ((_this select 4) isKindOf 'MissileBase' || {(_this select 4) isKindOf 'LaserBombCore'} || {(_this select 4) isKindOf 'BombCore'}) then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
	class Mi24_Base
	{
		ace_sys_missileguidance = "if ((_this select 4) isKindOf 'MissileBase' || {(_this select 4) isKindOf 'LaserBombCore'} || {(_this select 4) isKindOf 'BombCore'}) then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
	class Plane
	{
		ace_sys_missileguidance = "if ((_this select 4) isKindOf 'MissileBase' || {(_this select 4) isKindOf 'LaserBombCore'} || {(_this select 4) isKindOf 'BombCore'}) then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
	class AW159_Lynx_BAF
	{
		ace_sys_missileguidance = "if ((_this select 4) isKindOf 'MissileBase' || {(_this select 4) isKindOf 'LaserBombCore'} || {(_this select 4) isKindOf 'BombCore'}) then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
};
class Extended_IncomingMissile_EventHandlers
{
	class LandVehicle
	{
		class ace_sys_missileguidance
		{
			incomingMissile = "if ((_this select 1) isKindOf 'MissileBase') then { if (local (gunner (_this select 2))) then { _this call ace_sys_missileguidance_fnc_incomingmissile }}";
			exclude[] = {"StaticWeapon","ACE_Stretcher"};
		};
	};
	class Air
	{
		ace_sys_missileguidance = "if ((_this select 1) isKindOf 'MissileBase') then { if (local (gunner (_this select 2))) then { _this call ace_sys_missileguidance_fnc_incomingmissile }}";
	};
	class Ship
	{
		ace_sys_missileguidance = "if ((_this select 1) isKindOf 'MissileBase') then { if (local (gunner (_this select 2))) then { _this call ace_sys_missileguidance_fnc_incomingmissile }}";
	};
};
class CfgAmmo
{
	class MissileBase;
	class M_AT5_AT: MissileBase
	{
		manualControl = 0;
		ace_towsmoke = 2;
		ace_guidance_type = "saclos";
		ace_maxturnrateH = 8;
		ace_maxturnrateV = 8;
		ace_angletoler = 0.0004;
		model = "\x\ace\addons\sys_missileguidance\ace_at1_proxy.p3d";
	};
	class ACE_M_AT3C_AT: M_AT5_AT
	{
		ace_maxturnrateH = 4;
		ace_maxturnrateV = 4;
		model = "\x\ace\addons\sys_missileguidance\ace_at1_proxy.p3d";
	};
	class M_9M311_AA: MissileBase
	{
		manualControl = 0;
		ace_towsmoke = 2;
		ace_guidance_type = "saclos";
		ace_maxturnrateH = 17.5;
		ace_maxturnrateV = 17.5;
		ace_angletoler = 0.0002;
	};
	class M_TOW_AT: MissileBase
	{
		manualControl = 0;
		ace_towsmoke = 1;
		ace_guidance_type = "saclos";
		ace_maxturnrateH = 17.5;
		ace_maxturnrateV = 17.5;
		ace_angletoler = 0.0002;
	};
	class M_AT2_AT: MissileBase
	{
		manualControl = 0;
		ace_towsmoke = 2;
		ace_guidance_type = "saclos";
		ace_maxturnrateH = 7;
		ace_maxturnrateV = 7;
		ace_angletoler = 0.0005;
		model = "\x\ace\addons\sys_missileguidance\ace_at1_proxy.p3d";
	};
	class M_AT6_AT: MissileBase
	{
		manualControl = 0;
		ace_towsmoke = 2;
		ace_guidance_type = "shturm";
		ace_maxturnrateH = 9;
		ace_maxturnrateV = 9;
		ace_angletoler = 0.0003;
		ace_bankSpeed = 720;
		model = "\x\ace\addons\sys_missileguidance\ace_at1_proxy.p3d";
	};
	class M_AT9_AT: M_AT6_AT
	{
		ace_guidance_type = "shturm";
		ace_maxturnrateH = 10;
		ace_maxturnrateV = 10;
		ace_angletoler = 0.0002;
		ace_bankSpeed = 1020;
		manualControl = 0;
	};
	class ACE_M_AT9_Mi28: M_AT9_AT
	{
		ace_guidance_type = 0;
		manualControl = 0;
	};
	class M_AT10_AT: MissileBase
	{
		manualControl = 0;
		ace_towsmoke = 2;
		ace_guidance_type = "saclos";
		ace_maxturnrateH = 10;
		ace_maxturnrateV = 10;
		ace_angletoler = 0.0002;
		ace_guidance_initTime = 0.15;
		model = "\x\ace\addons\sys_missileguidance\ace_at1_proxy.p3d";
	};
	class M_AT11_AT: M_AT10_AT
	{
		manualControl = 0;
	};
	class M_AT13_AT: M_AT5_AT
	{
		manualControl = 0;
		ace_maxturnrateH = 10;
		ace_maxturnrateV = 10;
	};
	class ACE_M_AT13_AT: M_AT13_AT
	{
		manualControl = 0;
	};
	class M_Hellfire_AT: MissileBase
	{
		timeToLive = 500;
		simulationStep = 0.001;
		sideAirFriction = 0.075;
		maxSpeed = 425;
		initTime = 0;
		thrustTime = 3.25;
		thrust = 180;
		manualControl = 0;
		irlock = 1;
		laserlock = 1;
		airLock = 0;
		ace_guidance_type = "hellfire";
	};
	class ACE_M_Hellfire_AT_Coast: M_Hellfire_AT
	{
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
	};
	class LaserBombCore;
	class Bo_GBU12_LGB: LaserBombCore
	{
		irlock = 0;
		airLock = 0;
		timeToLive = 31337;
		ace_guidance_type = "lgb";
	};
	class ACE_M_HellfireL_AT: M_Hellfire_AT
	{
		irLock = 1;
		laserLock = 0;
		airLock = 0;
		ace_guidance_type = "longbow";
	};
	class ACE_M_HellfireL_Fake: ACE_M_HellfireL_AT
	{
		ace_hit = 0;
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		hitarmor[] = {"soundhit",1};
		hitbuilding[] = {"soundhit",1};
		hitconcrete[] = {"soundhit",1};
		hitdefault[] = {"soundhit",1};
		hitfoliage[] = {"soundhit",1};
		hitglass[] = {"soundhit",1};
		hitglassarmored[] = {"soundhit",1};
		hitgroundhard[] = {"soundhit",1};
		hitgroundsoft[] = {"soundhit",1};
		hitiron[] = {"soundhit",1};
		hitman[] = {"soundhit",1};
		hitmetal[] = {"soundhit",1};
		hitmetalplate[] = {"soundhit",1};
		hitplastic[] = {"soundhit",1};
		hitrubber[] = {"soundhit",1};
		hitwood[] = {"soundhit",1};
		soundhit[] = {"",0,1};
	};
	class M_Javelin_AT: MissileBase
	{
		ace_guidance_type = "javelin";
	};
	class ACE_M_Javelin_AT_Direct: M_Javelin_AT{};
	class ShellBase;
	class ace_m47_dragon_serviceCharge: ShellBase
	{
		hit = 1;
		indirectHit = 2;
		indirectHitRange = 1;
		typicalSpeed = 100;
		explosive = 1;
		cost = 300;
		model = "\ca\weapons\empty";
		airFriction = 0;
		timeToLive = 1;
		explosionTime = 0.001;
		soundFly[] = {"",1,1};
		soundEngine[] = {"",1,4};
		CraterEffects = "";
		explosionEffects = "ace_m47_serviceExplosion";
		hitarmor[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitbuilding[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitconcrete[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitdefault[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitfoliage[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitglass[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitglassarmored[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitgroundhard[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitgroundsoft[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitiron[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitman[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitmetal[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitmetalplate[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitplastic[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitrubber[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitwood[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		sounddefault1[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.2341,1,1800};
		sounddefault2[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.2341,1,1800};
		sounddefault3[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.2341,1,1800};
		soundHit[] = {"\x\ace\addons\sys_arty_ammunition\Sounds\base_eject",56.23413,1,1800};
	};
	class M_47_AT_EP1: M_TOW_AT
	{
		ace_towsmoke = 0;
		six_tracerenable = 0;
		ace_guidance_type = "dragon";
		soundFly[] = {"",0,1,0};
		soundEngine[] = {"",0,1,0};
	};
	class ace_missile_dragon: M_47_AT_EP1
	{
		model = "\x\ace\addons\m_wep_dragon\dragon.p3d";
		maxSpeed = 120;
		thrust = 0;
		initTime = 0;
		thrustTime = 0;
		sideAirFriction = 0.025;
		explosionEffects = "";
		CraterEffects = "";
		hitarmor[] = {"soundhit",1};
		hitbuilding[] = {"soundhit",1};
		hitconcrete[] = {"soundhit",1};
		hitdefault[] = {"soundhit",1};
		hitfoliage[] = {"soundhit",1};
		hitglass[] = {"soundhit",1};
		hitglassarmored[] = {"soundhit",1};
		hitgroundhard[] = {"soundhit",1};
		hitgroundsoft[] = {"soundhit",1};
		hitiron[] = {"soundhit",1};
		hitman[] = {"soundhit",1};
		hitmetal[] = {"soundhit",1};
		hitmetalplate[] = {"soundhit",1};
		hitplastic[] = {"soundhit",1};
		hitrubber[] = {"soundhit",1};
		hitwood[] = {"soundhit",1};
		soundhit[] = {"",0,1};
	};
	class ACE_M_Javelin_Fake: M_Javelin_AT
	{
		ace_hit = 0;
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0;
		hitarmor[] = {"soundhit",1};
		hitbuilding[] = {"soundhit",1};
		hitconcrete[] = {"soundhit",1};
		hitdefault[] = {"soundhit",1};
		hitfoliage[] = {"soundhit",1};
		hitglass[] = {"soundhit",1};
		hitglassarmored[] = {"soundhit",1};
		hitgroundhard[] = {"soundhit",1};
		hitgroundsoft[] = {"soundhit",1};
		hitiron[] = {"soundhit",1};
		hitman[] = {"soundhit",1};
		hitmetal[] = {"soundhit",1};
		hitmetalplate[] = {"soundhit",1};
		hitplastic[] = {"soundhit",1};
		hitrubber[] = {"soundhit",1};
		hitwood[] = {"soundhit",1};
		soundhit[] = {"",0,1};
	};
	class Default;
	class ACE_MissileGuidance_LaserPulse: Default
	{
		model = "\ca\Weapons\empty";
		proxyShape = "\ca\weapons\empty";
		caliber = 0;
		typicalSpeed = 600000;
		maxSpeed = 600000;
		explosive = 1;
		explosionEffects = "";
		CraterEffects = "";
		visibleFire = 0;
		audibleFire = 0;
		visibleFireTime = 0;
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
		cost = 0;
		deflecting = 0;
		sideAirFriction = 0;
		airFriction = 0;
		maneuvrability = 0;
		maxControlRange = 0;
		simulation = "shotSmoke";
		simulationStep = 0.001;
		timeToLive = 0.1;
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
class CfgMagazines
{
	class CA_LauncherMagazine;
	class Javelin: CA_LauncherMagazine
	{
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Javelin_Direct: Javelin
	{
		ammo = "ACE_M_Javelin_AT_Direct";
	};
};
class CfgWeapons
{
	class LauncherCore;
	class Launcher: LauncherCore{};
	class MissileLauncher: LauncherCore{};
	class AT2Launcher: MissileLauncher
	{
		canLock = 0;
	};
	class AT6Launcher: MissileLauncher
	{
		canLock = 0;
	};
	class AT9Launcher: MissileLauncher
	{
		canLock = 2;
	};
	class ACE_AT9Launcher_Mi28: AT9Launcher
	{
		canLock = 0;
	};
	class HellfireLauncher: MissileLauncher
	{
		canLock = 0;
	};
	class ACE_HellfireLauncher_Apache: HellfireLauncher
	{
		canLock = 2;
	};
	class Ch29Launcher: MissileLauncher
	{
		ace_sys_missileguidance_enableAirDesignator = 1;
	};
	class ACE_KAB500KRLauncher;
	class ACE_KAB500LLauncher: ACE_KAB500KRLauncher
	{
		ace_sys_missileguidance_enableAirDesignator = 1;
	};
	class RocketPods;
	class CRV7_PG: RocketPods
	{
		canLock = 0;
	};
	class BombLauncher: RocketPods
	{
		canLock = 0;
	};
	class Javelin: Launcher
	{
		weaponInfoType = "ACE_RscWeaponInfoJavelin";
		magazines[] = {"Javelin","ACE_Javelin_Direct"};
		canLock = 2;
		lockingTargetSound[] = {"",0,1};
		lockedTargetSound[] = {"",0,1};
		reloadtime = 1;
	};
	class ACE_Javelin_Direct: Javelin
	{
		class Armory
		{
			disabled = 1;
		};
	};
	class M47Launcher_EP1: Launcher
	{
		canLock = 0;
		opticsZoomMin = 0.25;
		opticsZoomMax = 1.1;
		opticsZoomInit = 0.5;
		modelOptics = "-";
		opticsPPEffects[] = {};
		visionMode[] = {};
		model = "\x\ace\addons\m_wep_dragon\ace_m47_magazine.p3d";
	};
};
class Turrets;
class MainTurret;
class ViewOptics;
class CfgVehicles
{
	class All;
	class LaserTarget: All
	{
		class EventHandlers
		{
			init = "_this spawn ace_sys_missileguidance_fnc_laser_init";
		};
	};
	class ACE_Logic;
	class ACE_Target_FakeLongbow: ACE_Logic
	{
		scope = 1;
	};
	class ACE_Target_FakeLaser: ACE_Logic
	{
		scope = 1;
	};
	class Air;
	class Helicopter: Air
	{
		class UserActions;
		class ACE
		{
			class ACE_MISSILEGUIDANCE
			{
				ACE_DESIGNATOR = 0;
				ACE_RANGEFINDER = 0;
			};
		};
	};
	class AH1_Base: Helicopter
	{
		class UserActions;
		class ACE: ACE
		{
			class ACE_MISSILEGUIDANCE: ACE_MISSILEGUIDANCE
			{
				ACE_DESIGNATOR = 1;
				ACE_RANGEFINDER = 0;
			};
		};
	};
	class AH1Z: AH1_Base
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "M197";
				ace_sys_missileguidance_limitsOn = 1;
				ace_sys_missileguidance_limits[] = {20,20,0,0};
				ace_sys_missileguidance_tracklimits[] = {30,30};
			};
		};
	};
	class AH64_base_EP1: Helicopter
	{
		class UserActions;
	};
	class AH64D: AH64_base_EP1
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "M230";
				ace_sys_missileguidance_limitsOn = 1;
				ace_sys_missileguidance_limits[] = {20,20,0,0};
				ace_sys_missileguidance_tracklimits[] = {30,30};
			};
		};
		class UserActions: UserActions
		{
			class Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(alive this) && {(player == gunner this)} && {isNil {this getVariable 'ace_sys_missileguidance_laser_designation'}}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_designation',true]; [this, currentWeapon this, true] spawn ace_sys_missileguidance_fnc_opt_laserloop";
			};
			class Laser_Off: Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(alive this) && {(player == gunner this)} && {(this getVariable 'ace_sys_missileguidance_laser_designation')}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_off',true]";
			};
		};
		class ACE: ACE
		{
			class ACE_MISSILEGUIDANCE: ACE_MISSILEGUIDANCE
			{
				ACE_DESIGNATOR = 1;
				ACE_RANGEFINDER = 0;
			};
		};
	};
	class AH64D_EP1: AH64_base_EP1
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "M230";
				ace_sys_missileguidance_limitsOn = 1;
				ace_sys_missileguidance_limits[] = {20,20,0,0};
				ace_sys_missileguidance_tracklimits[] = {30,30};
			};
		};
		class UserActions: UserActions
		{
			class Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(alive this) && {(player == gunner this)} && {isNil {this getVariable 'ace_sys_missileguidance_laser_designation'}}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_designation',true]; [this, currentWeapon this, true] spawn ace_sys_missileguidance_fnc_opt_laserloop";
			};
			class Laser_Off: Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(alive this) && {(player == gunner this)} && {(this getVariable 'ace_sys_missileguidance_laser_designation')}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_off',true]";
			};
		};
		class ACE: ACE
		{
			class ACE_MISSILEGUIDANCE: ACE_MISSILEGUIDANCE
			{
				ACE_DESIGNATOR = 1;
				ACE_RANGEFINDER = 0;
			};
		};
	};
	class AW159_Lynx_BAF: Helicopter
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "ACE_SACLOS_Guidance";
				ace_sys_missileguidance_limitsOn = 1;
				ace_sys_missileguidance_limits[] = {20,20,0,0};
				ace_sys_missileguidance_tracklimits[] = {30,30};
			};
		};
		class UserActions: UserActions
		{
			class Hellfire_LOBL
			{
				displayName = "<t color='#FFFF00'>LOBL</t>";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player == gunner this) && {((currentWeapon this) in ['CRV7_PG'])}";
				statement = "this setVariable ['ace_sys_missileguidance_hellfire_mode',0]";
			};
			class Hellfire_LOAL_DIR: Hellfire_LOBL
			{
				displayName = "<t color='#FFFF00'>LOAL-DIR</t>";
				condition = "(player == gunner this) && {((currentWeapon this) in ['CRV7_PG'])}";
				statement = "this setVariable ['ace_sys_missileguidance_hellfire_mode',1]";
			};
			class Hellfire_LOAL_LO: Hellfire_LOBL
			{
				displayName = "<t color='#FFFF00'>LOAL-LO</t>";
				condition = "(player == gunner this) && {((currentWeapon this) in ['CRV7_PG'])}";
				statement = "this setVariable ['ace_sys_missileguidance_hellfire_mode',2]";
			};
			class Hellfire_LOAL_HI: Hellfire_LOBL
			{
				displayName = "<t color='#FFFF00'>LOAL-HI</t>";
				condition = "(player == gunner this) && {((currentWeapon this) in ['CRV7_PG'])}";
				statement = "this setVariable ['ace_sys_missileguidance_hellfire_mode',3]";
			};
			class Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(alive this) && {(player == gunner this)} && {isNil {this getVariable 'ace_sys_missileguidance_laser_designation'}}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_designation',true]; [this, currentWeapon this, true] spawn ace_sys_missileguidance_fnc_opt_laserloop";
			};
			class Laser_Off: Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(alive this) && {(player == gunner this)} && {(this getVariable 'ace_sys_missileguidance_laser_designation')}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_off',true]";
			};
		};
		class ACE: ACE
		{
			class ACE_MISSILEGUIDANCE: ACE_MISSILEGUIDANCE
			{
				ACE_DESIGNATOR = 1;
				ACE_RANGEFINDER = 0;
			};
		};
	};
	class Mi24_Base: Helicopter
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "YakB";
				ace_sys_missileguidance_limitsOn = 1;
				ace_sys_missileguidance_limits[] = {9,30,-4,0};
				ace_sys_missileguidance_tracklimits[] = {60,30};
				initElev = 4;
			};
		};
		class UserActions
		{
			class Rangefinder_On
			{
				displayName = "$STR_ACE_UA_RANGEFINDER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player == gunner this) && {isNil {this getVariable 'ace_sys_missileguidance_laser_designation'}}";
				statement = "[this, currentWeapon this, false] spawn ace_sys_missileguidance_fnc_opt_laserloop; this setVariable ['ace_sys_missileguidance_laser_designation',true]";
			};
			class Rangefinder_Off: Rangefinder_On
			{
				displayName = "$STR_ACE_UA_RANGEFINDER_OFF";
				condition = "(player == gunner this) && {(this getVariable 'ace_sys_missileguidance_laser_designation')}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_off',true]";
			};
		};
		class ACE: ACE
		{
			class ACE_MISSILEGUIDANCE: ACE_MISSILEGUIDANCE
			{
				ACE_DESIGNATOR = 0;
				ACE_RANGEFINDER = 1;
			};
		};
	};
	class Mi24_Base_CDF: Mi24_Base{};
	class Mi24_D: Mi24_Base_CDF
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_limits[] = {15,15,-4,0};
			};
		};
	};
	class Mi24_Base_RU: Mi24_Base{};
	class Mi24_P: Mi24_Base_RU
	{
		class UserActions: UserActions
		{
			class Rangefinder_On: Rangefinder_On
			{
				condition = "false";
			};
			class Rangefinder_Off: Rangefinder_Off
			{
				condition = "false";
			};
		};
	};
	class Kamov_Base: Helicopter
	{
		class UserActions;
		class ACE: ACE
		{
			class ACE_MISSILEGUIDANCE: ACE_MISSILEGUIDANCE
			{
				ACE_DESIGNATOR = 0;
				ACE_RANGEFINDER = 1;
			};
		};
	};
	class Ka52: Kamov_Base
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "2A42";
			};
		};
		class UserActions: UserActions
		{
			class Rangefinder_On
			{
				displayName = "$STR_ACE_UA_RANGEFINDER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player == gunner this) && {isNil {this getVariable 'ace_sys_missileguidance_laser_designation'}}";
				statement = "[this, currentWeapon this, false] spawn ace_sys_missileguidance_fnc_opt_laserloop; this setVariable ['ace_sys_missileguidance_laser_designation',true]";
			};
			class Rangefinder_Off: Rangefinder_On
			{
				displayName = "$STR_ACE_UA_RANGEFINDER_OFF";
				condition = "(player == gunner this) && {(this getVariable 'ace_sys_missileguidance_laser_designation')}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_off',true]";
			};
		};
	};
	class Plane;
	class Plane_LG: Plane
	{
		ace_sys_missileguidance_limits[] = {-30,5,-12,12};
		ace_sys_missileguidance_tracklimits[] = {-30,5,-12,12};
		class UserActions
		{
			class LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player in [gunner this, driver this]) && {(getNumber(configFile>>'cfgWeapons'>>currentWeapon this>>'ace_sys_missileguidance_enableAirDesignator') == 1)}";
				statement = "[this,0,0] call ace_sys_missileguidance_fnc_Kh29_Lase";
			};
			class LaseKh29Off: LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(player in [gunner this, driver this]) && {(this getVariable 'ace_sys_missileguidance_tracking')}";
				statement = "this setVariable ['ace_sys_missileguidance_tracking',nil]";
			};
		};
	};
	class Su25_Base: Plane
	{
		ace_sys_missileguidance_limits[] = {-30,5,-12,12};
		ace_sys_missileguidance_tracklimits[] = {-30,5,-12,12};
		class UserActions
		{
			class LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player in [gunner this, driver this]) && {(getNumber(configFile>>'cfgWeapons'>>currentWeapon this>>'ace_sys_missileguidance_enableAirDesignator') == 1)}";
				statement = "[this,0,0] call ace_sys_missileguidance_fnc_Kh29_Lase";
			};
			class LaseKh29Off: LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(player in [gunner this, driver this]) && {(this getVariable 'ace_sys_missileguidance_tracking')}";
				statement = "this setVariable ['ace_sys_missileguidance_tracking',nil]";
			};
		};
	};
	class Su34: Plane
	{
		ace_sys_missileguidance_limits[] = {-120,15,-180,180};
		ace_sys_missileguidance_tracklimits[] = {-120,15,-180,180};
		class UserActions
		{
			class LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player in [gunner this, driver this]) && {(getNumber(configFile>>'cfgWeapons'>>currentWeapon this>>'ace_sys_missileguidance_enableAirDesignator') == 1)}";
				statement = "[this,0,0] call ace_sys_missileguidance_fnc_Kh29_Lase";
			};
			class LaseKh29Off: LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(player in [gunner this, driver this]) && {(this getVariable 'ace_sys_missileguidance_tracking')}";
				statement = "this setVariable ['ace_sys_missileguidance_tracking',nil]";
			};
		};
	};
	class HMMWV_Base;
	class HMMWV_TOW: HMMWV_Base
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "TOWLauncherSingle";
				gunBeg = "spice rakety";
				gunEnd = "konec rakety";
			};
		};
	};
	class StaticATWeapon;
	class TOW_TriPod_Base: StaticATWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "TOWLauncherSingle";
				gunBeg = "spice rakety";
				gunEnd = "konec rakety";
			};
		};
	};
	class TOW_TriPod: StaticATWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "TOWLauncherSingle";
				gunBeg = "spice rakety";
				gunEnd = "konec rakety";
			};
		};
	};
	class Metis: StaticATWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				ace_sys_missileguidance_tracker = "AT13LauncherSingle";
				gunBeg = "spice rakety";
				gunEnd = "konec rakety";
			};
		};
	};
	class ACE_M47_Static: TOW_TriPod
	{
		scope = 1;
		model = "\x\ace\addons\m_wep_dragon\ace_m47_static.p3d";
		displayName = "M47 Dragon";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerAction = "LowKORD_Gunner";
				ace_sys_missileguidance_tracker = "TOWLauncherSingle";
				gunnerOpticsModel = "\ca\Weapons_e\optics_m47";
				weapons[] = {"ACE_M47StaticLauncher"};
				magazines[] = {};
				class ViewOptics: ViewOptics
				{
					initFov = 0.015;
					minFov = 0.015;
					maxFov = 0.015;
				};
			};
		};
		class AnimationSources
		{
			class rest_rotate
			{
				source = "user";
				animPeriod = 1e-005;
				initPhase = -0.35;
				maxValue = "3.60";
				minValue = "-3.60";
			};
			class optic_hide
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 1;
				maxValue = "1";
				minValue = "0";
			};
			class missile_hide
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
				maxValue = "1";
				minValue = "0";
			};
		};
	};
};
class CfgSounds
{
	class ACE_Javelin_Locking
	{
		name = "ACE_Javelin_Locking";
		sound[] = {"\x\ace\addons\sys_missileguidance\sound\javelin_locking.ogg","db+0",1.0};
		titles[] = {};
	};
	class ACE_Javelin_Locked
	{
		name = "ACE_Javelin_Locked";
		sound[] = {"\x\ace\addons\sys_missileguidance\sound\javelin_locked.ogg","db+0",1.0};
		titles[] = {};
	};
};
class RscControlsGroup;
class RscPicture;
class RscLine;
class RscOpticsValue;
class RscInGameUI
{
	class ACE_RscWeaponInfoJavelin
	{
		idd = 300;
		onLoad = "uiNameSpace setVariable ['ACE_RscWeaponInfoJavelin',_this select 0]; [] call ace_sys_missileguidance_fnc_target_javelin;";
		onUnload = "uiNameSpace setVariable ['ACE_RscWeaponInfoJavelin',nil];";
		controls[] = {"CA_javelin_elements_group","CA_Distance"};
		class CA_Distance: RscOpticsValue
		{
			idc = 151;
			sizeEx = "0";
			colorText[] = {0,0,0,0};
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		class CA_javelin_elements_group: RscControlsGroup
		{
			x = "SafezoneX";
			y = "SafezoneY";
			w = "SafezoneW";
			h = "SafezoneH";
			idc = 170;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_Javelin_Day_mode_off: RscPicture
				{
					idc = 1001;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.03/4)*3*SafezoneH - SafezoneX";
					y = "SafezoneY+SafezoneH*0.031 - SafezoneY";
					w = "0.1045752* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
					h = "SafezoneH*0.1045752";
					colorText[] = {0.2941,0.2941,0.2941,1};
					text = "\ca\ui\data\igui_javelin_day_co.paa";
				};
				class CA_Javelin_Day_mode: CA_Javelin_Day_mode_off
				{
					idc = 160;
					colorText[] = {0.2941,0.8745,0.2157,1};
				};
				class CA_Javelin_WFOV_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1004;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.307/4)*3*SafezoneH - SafezoneX";
					text = "\ca\ui\data\igui_javelin_wfov_co.paa";
				};
				class CA_Javelin_WFOV_mode_group: RscControlsGroup
				{
					x = "SafezoneX";
					y = "SafezoneY";
					w = "SafezoneW";
					h = "SafezoneH";
					idc = 163;
					class VScrollbar
					{
						autoScrollSpeed = -1;
						autoScrollDelay = 5;
						autoScrollRewind = 0;
						color[] = {1,1,1,0};
						width = 0.001;
					};
					class HScrollbar
					{
						color[] = {1,1,1,0};
						height = 0.001;
					};
					class Controls
					{
						class CA_Javelin_WFOV_mode: CA_Javelin_WFOV_mode_off
						{
							idc = -1;
							y = "0.031*SafezoneH - SafezoneY";
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.307/4)*3*SafezoneH - SafezoneX";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaL: RscLine
						{
							x = "0.4899*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaR: RscLine
						{
							x = "0.5109*SafezoneW- SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketL: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.293/4)*3*SafezoneH - SafezoneX";
							y = "0.4677*SafezoneH - SafezoneY";
							w = 0;
							h = "0.0646*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketR: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.70/4)*3*SafezoneH - SafezoneX";
							y = "0.4677*SafezoneH - SafezoneY";
							w = 0;
							h = "0.0646*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketT: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.467/4)*3*SafezoneH - SafezoneX";
							y = "0.3535*SafezoneH - SafezoneY";
							w = "0.065* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = 0;
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketB: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.467/4)*3*SafezoneH - SafezoneX";
							y = "0.6465*SafezoneH - SafezoneY";
							w = "0.065* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = 0;
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
					};
				};
				class CA_Javelin_NFOV_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1003;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.586/4)*3*SafezoneH - SafezoneX";
					text = "\ca\ui\data\igui_javelin_nfov_co.paa";
				};
				class CA_Javelin_NFOV_mode_group: RscControlsGroup
				{
					x = "SafezoneX";
					y = "SafezoneY";
					w = "SafezoneW-SafezoneX";
					h = "SafezoneH-SafezoneY";
					idc = 162;
					class VScrollbar
					{
						autoScrollSpeed = -1;
						autoScrollDelay = 5;
						autoScrollRewind = 0;
						color[] = {1,1,1,0};
						width = 0.001;
					};
					class HScrollbar
					{
						color[] = {1,1,1,0};
						height = 0.001;
					};
					class Controls
					{
						class CA_Javelin_NFOV_mode: CA_Javelin_NFOV_mode_off
						{
							idc = 699003;
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.586/4)*3*SafezoneH - SafezoneX";
							y = "0.031*SafezoneH - SafezoneY";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaL: RscLine
						{
							x = "0.4788*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaR: RscLine
						{
							x = "0.5212*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineHL: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.01/4)*3*SafezoneH - SafezoneX";
							y = "SafezoneH*0.5 - SafezoneY";
							w = "0.29* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = "SafezoneH*0.0";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineHR: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.695/4)*3*SafezoneH - SafezoneX";
							y = "SafezoneH*0.5 - SafezoneY";
							w = "0.29* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = "SafezoneH*0.0";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineVT: RscLine
						{
							x = "0.5*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.1825*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineVB: RscLine
						{
							x = "0.5*SafezoneW - SafezoneX";
							y = "0.6465*SafezoneH - SafezoneY";
							w = 0;
							h = "0.1895*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
					};
				};
				class TargetingConstrains: RscControlsGroup
				{
					idc = 699100;
					x = "SafezoneX";
					y = "SafezoneY";
					w = "SafezoneW-SafezoneX";
					h = "SafezoneH-SafezoneY";
					class VScrollbar
					{
						autoScrollSpeed = -1;
						autoScrollDelay = 5;
						autoScrollRewind = 0;
						color[] = {1,1,1,0};
						width = 0.001;
					};
					class HScrollbar
					{
						color[] = {1,1,1,0};
						height = 0.001;
					};
					class Controls
					{
						class Top: RscPicture
						{
							idc = 699101;
							text = "#(argb,8,8,3)color(1,1,1,1)";
							colorText[] = {0.2941,0.2941,0.2941,1};
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX";
							y = "0.15*SafezoneH-SafezoneY";
							w = "(3/4)*SafezoneH";
							h = "0.21*SafezoneH";
						};
						class Bottom: Top
						{
							idc = 699102;
							y = "0.64*SafezoneH-SafezoneY";
						};
						class Left: Top
						{
							idc = 699103;
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX";
							y = "0.36*SafezoneH-SafezoneY";
							w = "0.31*(3/4)*SafezoneH";
							h = "0.28*SafezoneH";
						};
						class Right: Left
						{
							idc = 699104;
							x = "((SafezoneW -(3/4)*SafezoneH)/2)+ 0.69*(3/4)*SafezoneH - SafezoneX";
						};
						class OpticsBorders: RscPicture
						{
							idc = 699105;
							text = "x\ace\addons\m_wep_optics\t\javelin_ui_border_ca.paa";
							colorText[] = {0,0,0,1};
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX";
							y = "0.15*SafezoneH-SafezoneY";
							w = "(3/4)*SafezoneH";
							h = "0.7*SafezoneH";
						};
					};
				};
				class TargetingGate: TargetingConstrains
				{
					idc = 699200;
					class Controls
					{
						class TargetingGateTL: TargetingConstrains
						{
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX";
							y = "0.15*SafezoneH - SafezoneY";
							idc = 699201;
							class Controls
							{
								class LineH: RscLine
								{
									idc = 699210;
									x = "0";
									y = "0";
									w = "0.025*(3/4)*SafezoneH";
									h = "0";
									colorText[] = {0.8745,0.8745,0.8745,1};
								};
								class LineV: LineH
								{
									idc = 699211;
									w = "0";
									h = "0.025*SafezoneH";
								};
							};
						};
						class TargetingGateTR: TargetingGateTL
						{
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX + 0.975*(3/4)*SafezoneH";
							y = "0.15*SafezoneH - SafezoneY";
							idc = 699202;
							class Controls
							{
								class LineH: RscLine
								{
									idc = 699220;
									x = "0";
									y = "0";
									w = "0.025*(3/4)*SafezoneH";
									h = "0";
									colorText[] = {0.8745,0.8745,0.8745,1};
								};
								class LineV: LineH
								{
									idc = 699221;
									x = "0.025*(3/4)*SafezoneH";
									w = "0";
									h = "0.025*SafezoneH";
								};
							};
						};
						class TargetingGateBL: TargetingGateTL
						{
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX";
							y = "0.825*SafezoneH - SafezoneY";
							idc = 699203;
							class Controls
							{
								class LineH: RscLine
								{
									x = "0";
									y = "0.025*SafezoneH";
									w = "0.025*(3/4)*SafezoneH";
									h = "0";
									colorText[] = {0.8745,0.8745,0.8745,1};
								};
								class LineV: LineH
								{
									y = "0";
									w = "0";
									h = "0.025*SafezoneH";
								};
							};
						};
						class TargetingGateBR: TargetingGateBL
						{
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX + 0.975*(3/4)*SafezoneH";
							y = "0.825*SafezoneH - SafezoneY";
							idc = 699204;
							class Controls
							{
								class LineH: RscLine
								{
									x = "0";
									y = "0.025*SafezoneH";
									w = "0.025*(3/4)*SafezoneH";
									h = "0";
									colorText[] = {0.8745,0.8745,0.8745,1};
								};
								class LineV: LineH
								{
									x = "0.025*(3/4)*SafezoneH";
									y = "0";
									w = "0";
									h = "0.025*SafezoneH";
								};
							};
						};
					};
				};
				class TargetingLines: TargetingConstrains
				{
					idc = 699300;
					class Controls
					{
						class LineH: RscLine
						{
							idc = 699301;
							x = "((SafezoneW -(3/4)*SafezoneH)/2) - SafezoneX";
							y = "0.5*SafezoneH - SafezoneY";
							w = "(3/4)*SafezoneH";
							h = "0";
							colorText[] = {0.8745,0.8745,0.8745,1};
						};
						class LineV: RscLine
						{
							idc = 699302;
							x = "0.5*SafezoneW - SafezoneX";
							y = "0.15*SafezoneH - SafezoneY";
							w = "0";
							h = "0.7*SafezoneH";
							colorText[] = {0.8745,0.8745,0.8745,1};
						};
					};
				};
				class CA_Javelin_SEEK_off: CA_Javelin_Day_mode_off
				{
					idc = 699000;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.863/4)*3*SafezoneH - SafezoneX";
					text = "\ca\ui\data\igui_javelin_seek_co.paa";
				};
				class CA_Javelin_SEEK: CA_Javelin_SEEK_off
				{
					idc = 166;
					colorText[] = {0.2941,0.8745,0.2157,0};
				};
				class CA_Javelin_Missle_off: CA_Javelin_Day_mode_off
				{
					idc = 1032;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (-0.134/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.208*SafezoneH) - SafezoneY";
					colorText[] = {0.2941,0.2941,0.2941,1};
					text = "\ca\ui\data\igui_javelin_missle_co.paa";
				};
				class CA_Javelin_Missle: CA_Javelin_Missle_off
				{
					idc = 167;
					colorText[] = {0.9255,0.5216,0.1216,0};
				};
				class CA_Javelin_CLU_off: CA_Javelin_Missle_off
				{
					idc = 1027;
					y = "(SafezoneY + 0.436*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_clu_co.paa";
				};
				class CA_Javelin_HangFire_off: CA_Javelin_Missle_off
				{
					idc = 1028;
					y = "(SafezoneY + 0.669*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_hangfire_co.paa";
				};
				class CA_Javelin_TOP_off: CA_Javelin_Day_mode_off
				{
					idc = 699001;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.208*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_top_co.paa";
					colorText[] = {0.2941,0.8745,0.2157,1};
				};
				class CA_Javelin_DIR: CA_Javelin_Day_mode
				{
					idc = 699002;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.436*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_dir_co.paa";
					colorText[] = {0.2941,0.2941,0.2941,1};
				};
				class CA_Javelin_FLTR_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1002;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.669*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_fltr_co.paa";
				};
				class CA_Javelin_FLTR_mode: CA_Javelin_FLTR_mode_off
				{
					idc = 161;
					colorText[] = {0.2941,0.8745,0.2157,1};
				};
			};
		};
	};
};
class ace_m47_serviceExplosion
{
	class Light1
	{
		simulation = "light";
		type = "GrenadeExploLight";
		position[] = {0,0,0};
		intensity = 0.005;
		interval = 1;
		lifeTime = 0.5;
	};
	class GrenadeSmoke1
	{
		simulation = "particles";
		type = "ImpactSmoke2";
		position[] = {0,0,0};
		intensity = 0.15;
		interval = 0.1;
		lifeTime = 0.5;
	};
};
//};
