////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:07 2013 : Created on Mon Oct 14 23:06:07 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_arty_aimingpoints : config.bin{
class CfgPatches
{
	class ace_sys_arty_aimingpoints
	{
		units[] = {};
		weapons[] = {"ACE_Arty_AimingPost_M1A2_M58","ACE_Arty_AimingPost_M1A2_M59","ACE_Arty_M1A1_Collimator","ACE_Arty_M2A2_Aiming_Circle"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","ace_sys_arty","ace_sys_interaction","ace_main"};
		author[] = {"Nou"};
		version = "1.14.0.597";
		versionStr = "1.14.0.597";
		versionAr[] = {1,14,0,597};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_arty_aimingpoints
		{
			list[] = {"ace_sys_arty_aimingpoints"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_arty_aimingpoints
	{
		init = "call ('\x\ace\addons\sys_arty_aimingpoints\XEH_pre_init.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_arty_aimingpoints
	{
		clientInit = "call ('\x\ace\addons\sys_arty_aimingpoints\XEH_post_init.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class ACE_Arty_M1A1_Collimator
	{
		init = "call ('\x\ace\addons\sys_arty_aimingpoints\XEH_collimator_init.sqf' call SLX_XEH_COMPILE)";
	};
	class ACE_Arty_M2A2_Aiming_Circle
	{
		init = "_this call ace_sys_arty_aimingpoints_fnc_aimingCircleInit";
	};
};
class Extended_GetIn_Eventhandlers
{
	class ACE_Arty_M2A2_Aiming_Circle
	{
		clientGetin = "_this call ace_sys_arty_aimingpoints_fnc_aimingCircleGetIn";
	};
};
class Extended_GetOut_Eventhandlers
{
	class ACE_Arty_M2A2_Aiming_Circle
	{
		clientGetout = "_this call ace_sys_arty_aimingpoints_fnc_aimingCircleGetOut";
	};
};
class CfgWeapons
{
	class Launcher;
	class ACE_BaseAimingPost: Launcher
	{
		displayName = "Aiming Post";
		descriptionShort = "";
		type = 4;
		model = "\x\ace\addons\sys_arty_aimingpoints\ACE_ARTY_AimingStakesW.p3d";
		picture = "\x\ace\addons\sys_arty_aimingpoints\data\equip\w_stake_ca.paa";
		class Library
		{
			libTextDesc = "";
		};
		ACE_Weight = 3;
	};
	class ACE_Arty_AimingPost_M1A2_M58: ACE_BaseAimingPost
	{
		scope = 2;
		displayName = "$STR_DN_ACE_ARTY_AIMINGPOST_M1A2_M58";
		descriptionShort = "$STR_DSS_ACE_ARTY_AIMINGPOST_M1A2_M58";
	};
	class ACE_Arty_AimingPost_M1A2_M59: ACE_BaseAimingPost
	{
		scope = 2;
		displayName = "$STR_DN_ACE_ARTY_AIMINGPOST_M1A2_M59";
		descriptionShort = "$STR_DSS_ACE_ARTY_AIMINGPOST_M1A2_M59";
	};
	class ACE_Arty_M1A1_Collimator: ACE_BaseAimingPost
	{
		scope = 2;
		displayName = "$STR_DSS_ACE_ARTY_COLLIMATOR_M1A1";
		descriptionShort = "$STR_DSS_ACE_ARTY_COLLIMATOR_M1A1";
		picture = "\x\ace\addons\sys_arty_aimingpoints\data\equip\collimator_item_ca.paa";
		model = "\x\ace\addons\sys_arty_aimingpoints\sa_collimator_wep.p3d";
		ACE_Weight = 14.5;
	};
	class ACE_Arty_M2A2_Aiming_Circle: ACE_BaseAimingPost
	{
		scope = 2;
		displayName = "$STR_DSS_ACE_ARTY_AIMINGCIRCLE_M2A2";
		descriptionShort = "$STR_DSS_ACE_ARTY_AIMINGCIRCLE_M2A2";
		picture = "\x\ace\addons\sys_arty_aimingpoints\data\equip\m2a2_item_ca.paa";
		model = "\x\ace\addons\sys_arty_aimingpoints\ace_arty_m2a2_aiming_circle_wep.p3d";
		ACE_Weight = 20.5;
	};
};
class CfgVehicles
{
	class Thing;
	class ReammoBox;
	class ACE_Arty_BaseThing;
	class ACE_Arty_AimingStakes: ACE_Arty_BaseThing
	{
		destrType = "DestructTree";
		weight = 1000;
		simulation = "house";
		model = "\x\ace\addons\sys_arty_aimingpoints\ACE_ARTY_AimingStakes.p3d";
		animated = 0;
		reversed = 0;
		autocenter = 1;
		sectionsInherit = "ACE_ARTY_AimingStakes";
		hiddenSelections[] = {"all"};
		class AnimationSources{};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		ACE_Weight = 10000;
	};
	class ACE_Arty_AimingPost_M1A2_M58: ACE_Arty_AimingStakes
	{
		scope = 2;
		displayName = "$STR_DN_ACE_ARTY_AIMINGPOST_M1A2_M58";
		hiddenSelections[] = {"lamp_1","lightpoint_1"};
		class MarkerLights
		{
			class Greenlight
			{
				name = "lightpoint_0";
				color[] = {0,0.5,0.1,0.0025};
				ambient[] = {0,0.5,0.1,0.0025};
				brightness = 0.0015;
				size = 1e-005;
				blinking = "false";
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		ACE_Weight = 3;
	};
	class ACE_Arty_AimingPost_M1A2_M59: ACE_Arty_AimingPost_M1A2_M58
	{
		displayName = "$STR_DN_ACE_ARTY_AIMINGPOST_M1A2_M59";
		class MarkerLights: MarkerLights
		{
			class Orangelight: Greenlight
			{
				color[] = {"255/255","74/255","0/255",0.0025};
				ambient[] = {"255/255","74/255","0/255",0.0025};
			};
		};
	};
	class ACE_ArtyEquip_Box: ReammoBox
	{
		vehicleClass = "ACE_Arty_Equipment";
		picture = "pictureThing";
		class TransportWeapons
		{
			class _xx_ACE_Arty_AimingPost_M1A2_M58
			{
				weapon = "ACE_Arty_AimingPost_M1A2_M58";
				count = 12;
			};
			class _xx_ACE_Arty_AimingPost_M1A2_M59
			{
				weapon = "ACE_Arty_AimingPost_M1A2_M59";
				count = 12;
			};
			class _xx_ACE_Arty_M1A1_Collimator
			{
				weapon = "ACE_Arty_M1A1_Collimator";
				count = 6;
			};
			class _xx_ACE_Arty_M2A2_Aiming_Circle
			{
				weapon = "ACE_Arty_M2A2_Aiming_Circle";
				count = 2;
			};
		};
		class TransportMagazines{};
	};
	class ACE_Arty_M1A1_Collimator: ACE_Arty_AimingStakes
	{
		scope = 2;
		displayName = "$STR_DSS_ACE_ARTY_COLLIMATOR_M1A1";
		model = "\x\ace\addons\sys_arty_aimingpoints\sa_collimator.p3d";
		animated = 1;
		reversed = 0;
		autocenter = 0;
		class Reflectors
		{
			class Reflector
			{
				color[] = {1,1,1,1};
				ambient[] = {1,1,1,1};
				position = "optic_backlight";
				direction = "optic_proxy";
				hitpoint = "optic_backlight";
				selection = "optic_backlight";
				brightness = 0.001;
				size = 0.01;
			};
		};
		class AnimationSources
		{
			class elevate_optic
			{
				source = "user";
				animPeriod = 0.01;
				minValue = "-300";
				maxValue = "300";
			};
			class rotate_optic
			{
				source = "user";
				animPeriod = 0.01;
				minValue = "-6400";
				maxValue = "6400";
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		ACE_Weight = 14.5;
	};
	class ACE_Arty_Collimator_Proxy: ACE_Arty_BaseThing
	{
		scope = 1;
		displayName = "Collimator Proxy";
		destrType = "DestructTree";
		weight = 1000;
		simulation = "house";
		model = "\x\ace\addons\sys_arty_aimingpoints\collimator_test.p3d";
		animated = 1;
		reversed = 0;
		autocenter = 0;
		sectionsInherit = "collimator_test";
		class AnimationSources
		{
			class offset
			{
				source = "user";
				animPeriod = 1e-005;
				minValue = -100;
				maxValue = 100;
			};
			class expand_ul
			{
				source = "user";
				animPeriod = 1e-005;
				minValue = -1;
				maxValue = 1;
			};
			class expand_ur
			{
				source = "user";
				animPeriod = 1e-005;
				minValue = -1;
				maxValue = 1;
			};
			class expand_ll
			{
				source = "user";
				animPeriod = 1e-005;
				minValue = -1;
				maxValue = 1;
			};
			class expand_lr
			{
				source = "user";
				animPeriod = 1e-005;
				minValue = -1;
				maxValue = 1;
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		ACE_Weight = 14.5;
	};
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets;
	};
	class StaticCannon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class ace_aimingcircle_base: StaticCannon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
	};
	class ACE_Arty_M2A2_Aiming_Circle: ace_aimingcircle_base
	{
		scope = 2;
		displayName = "$STR_DSS_ACE_ARTY_AIMINGCIRCLE_M2A2";
		model = "\x\ace\addons\sys_arty_aimingpoints\ace_arty_m2a2_aiming_circle.p3d";
		icon = "\x\ace\addons\sys_arty_aimingpoints\data\equip\m2a2_icon_ca.paa";
		vehicleClass = "ACE_Arty_Equipment";
		animated = 0;
		reversed = 0;
		autocenter = 0;
		mapSize = 0.5;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {};
				magazines[] = {};
				memoryPointsGetInGunner = "pos_gunner_dir";
				memoryPointsGetInGunnerDir = "pos_gunner";
				gunnerOpticsModel = "\x\ace\addons\sys_arty_m119\ace_arty_m119_scope";
				gunnerAction = "M2_Gunner";
				gunBeg = "gunBegin";
				gunEnd = "gunEnd";
				proxyIndex = 1;
				maxHorizontalRotSpeed = 4;
				class ViewOptics: ViewOptics
				{
					initFov = 0.0787019;
					minFov = 0.0787019;
					maxFov = 0.0787019;
				};
			};
		};
		class AnimationSources
		{
			class MainGun
			{
				source = "user";
				animPeriod = 0.02;
				initPhase = 0;
				minValue = "-400";
				maxValue = "800";
			};
			class MainTurret
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-6400";
				maxValue = "6400";
			};
			class upper_motion
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.002;
				minValue = "-6400";
				maxValue = "6400";
			};
			class deflection_knob
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-100";
				maxValue = "100";
			};
			class deflection_knob_coarse
			{
				type = "rotation";
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-64";
				maxValue = "64";
			};
			class elevation_knob
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-100";
				maxValue = "100";
			};
			class elevation_knob_coarse
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-4";
				maxValue = "8";
			};
			class orienting_knobs
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-6400";
				maxValue = "6400";
			};
			class left_cover
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				minValue = "0";
				maxValue = "1";
			};
			class right_cover
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				minValue = "0";
				maxValue = "1";
			};
			class compass_needle
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.02;
				minValue = "-360";
				maxValue = "360";
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		ACE_Weight = 20.5;
	};
};
class ace_sys_aimingpoints_aimingCircleDisplay
{
	idd = 7832;
	movingEnable = 0;
	name = "ace_sys_aimingpoints_aimingCircleDisplay";
	onLoad = "_this call ace_sys_arty_aimingpoints_fnc_aimingCircleInitDisplay";
	onUnload = "_this call ace_sys_arty_aimingpoints_fnc_aimingCircleCloseDisplay";
	onKeyDown = "_this call ace_sys_arty_aimingpoints_fnc_aimingCircleHandleKey";
	class controlsBackground{};
	class objects{};
	class controls{};
};
//};
