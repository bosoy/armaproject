////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:47:06 2013 : Created on Sat Apr 06 11:47:06 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_weaponrest : config.bin{
class CfgPatches
{
	class ace_sys_weaponrest
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CA_Anims","CA_Anims_Char","CAWeapons","CAWeapons2","ace_main","ace_sys_interaction","CAWeapons_E_scar"};
		version = "1.14.0.590";
		author[] = {"q1184"};
		class ACE_Options
		{
			group = "WEP";
			title = " ";
			class Rest_weapon
			{
				title = "$STR_ACE_MENU_RESTWEAPON";
			};
		};
	};
};
class CfgWeapons
{
	class Rifle;
	class M24: Rifle
	{
		ace_bipod = 1;
	};
	class huntingrifle: M24
	{
		ace_bipod = 0;
	};
	class DMR: Rifle
	{
		ace_bipod = 1;
	};
	class m107: Rifle
	{
		ace_bipod = 1;
	};
	class M240: Rifle
	{
		ace_bipod = 1;
	};
	class M249: Rifle
	{
		ace_bipod = 1;
	};
	class M60A4_EP1: Rifle
	{
		ace_bipod = 1;
	};
	class m8_base;
	class m8_sharpshooter: m8_base
	{
		ace_bipod = 1;
	};
	class m8_SAW: m8_sharpshooter
	{
		ace_bipod = 1;
	};
	class AK_74;
	class PK: Rifle
	{
		ace_bipod = 1;
	};
	class RPK_74: AK_74
	{
		ace_bipod = 1;
	};
	class ksvk: Rifle
	{
		ace_bipod = 1;
	};
	class M110_TWS_EP1: Rifle
	{
		ace_bipod = 1;
	};
	class SCAR_H_Base;
	class SCAR_H_LNG_Sniper: SCAR_H_Base
	{
		ace_bipod = 1;
	};
	class SCAR_H_LNG_Sniper_SD: SCAR_H_Base
	{
		ace_bipod = 1;
	};
	class SCAR_H_STD_TWS_SD: SCAR_H_LNG_Sniper_SD
	{
		ace_bipod = 0;
	};
	class G36C;
	class MG36: G36C
	{
		ace_bipod = 1;
	};
	class BAF_L86A2_ACOG: Rifle
	{
		ace_bipod = 1;
	};
	class BAF_AS50_scoped: Rifle
	{
		ace_bipod = 1;
	};
	class BAF_L110A1_Aim: Rifle
	{
		ace_bipod = 1;
	};
	class UK59_ACR: Rifle
	{
		ace_bipod = 1;
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_weaponrest
	{
		clientInit = "call ('\x\ace\addons\sys_weaponrest\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class cfgAmmo
{
	class Default;
	class ACE_B_Detector: Default
	{
		model = "\x\ace\addons\sys_weaponrest\ace_invisomodel.p3d";
		explosive = 1;
		explosionEffects = "";
		CraterEffects = "";
		visibleFire = 0;
		audibleFire = 0;
		visibleFireTime = 0;
		hit = 0.01;
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
					color[] = {1,1,1,0};
				};
				class T2
				{
					maxT = 1000;
					color[] = {0.2,0.2,0.2,0};
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
	class ACE_B_Detector2: ACE_B_Detector
	{
		model = "\x\ace\addons\sys_weaponrest\ace_collider.p3d";
	};
};
class CfgMovesBasic
{
	class Actions
	{
		class RifleStandActions;
		class RifleStandActions_Steady: RifleStandActions
		{
			stop = "AmovPercMstpSrasWrflDnon_Steady";
			default = "AmovPercMstpSrasWrflDnon_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		class RifleKneelActions;
		class RifleKneelActions_Steady: RifleKneelActions
		{
			stop = "AmovPknlMstpSrasWrflDnon_Steady";
			default = "AmovPknlMstpSrasWrflDnon_Steady";
			weaponOff = "AmovPknlMstpSrasWrflDnon_Steady";
			Stand = "AmovPknlMstpSrasWrflDnon_Steady";
			Crouch = "AmovPknlMstpSrasWrflDnon_Steady";
			CanNotMove = "AmovPknlMstpSrasWrflDnon_Steady";
			FireNotPossible = "AmovPknlMstpSrasWrflDnon_Steady";
			strokeGun = "AmovPknlMstpSrasWrflDnon_Steady";
			limitFast = 1;
			turnSpeed = 0.3;
		};
		class RifleProneActions;
		class RifleProneActions_Bipod: RifleProneActions
		{
			stop = "AmovPpneMstpSrasWrflDnon_Bipod";
			default = "AmovPpneMstpSrasWrflDnon_Bipod";
			weaponOff = "AmovPpneMstpSrasWrflDnon_Bipod";
			limitfast = 1;
			turnSpeed = 0.05;
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class AmovPercMstpSrasWrflDnon;
		class AmovPercMstpSrasWrflDnon_Steady: AmovPercMstpSrasWrflDnon
		{
			actions = "RifleStandActions_Steady";
			aimPrecision = 0.39;
			aiming = "aimingLying";
			camshakefire = 0.4;
			speed = 0.01;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AmovPercMstpSrasWrflDnon_Steady",0.02};
			connectFrom[] = {"AmovPercMstpSrasWrflDnon_Steady",0.02};
			interpolateFrom[] = {"AmovPercMstpSrasWrflDnon",0.02};
			interpolateTo[] = {"AmovPercMstpSrasWrflDnon",0.02};
		};
		class AmovPknlMstpSrasWrflDnon;
		class AmovPknlMstpSrasWrflDnon_Steady: AmovPknlMstpSrasWrflDnon
		{
			actions = "RifleKneelActions_Steady";
			aimPrecision = 0.195;
			aiming = "aimingLying";
			camshakefire = 0.35;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AmovPknlMstpSrasWrflDnon_Steady",0.02};
			connectFrom[] = {"AmovPknlMstpSrasWrflDnon_Steady",0.02};
			interpolateFrom[] = {"AmovPknlMstpSrasWrflDnon",0.02};
			interpolateTo[] = {"AmovPknlMstpSrasWrflDnon",0.02};
		};
		class AmovPpneMstpSrasWrflDnon: AmovPercMstpSrasWrflDnon
		{
			variantsAI[] = {"ACE_AmovPpneMstpSrasWrflDnon_Supported",1};
			variantAfter[] = {1,2,3};
		};
		class AmovPpneMrunSlowWrflDf: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_turnL: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_turnR: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_healed: AmovPpneMstpSrasWrflDnon
		{
			variantsAI[] = {};
		};
		class AmovPpneMstpSrasWrflDnon_Bipod: AmovPpneMstpSrasWrflDnon
		{
			actions = "RifleProneActions_Bipod";
			aimPrecision = 0.095;
			aiming = "aimingLying";
			camshakefire = 0.3;
			onLandEnd = 1;
			onLandBeg = 1;
			connectTo[] = {"AmovPpneMstpSrasWrflDnon_Bipod",0.02};
			connectFrom[] = {"AmovPpneMstpSrasWrflDnon_Bipod",0.02};
			interpolateFrom[] = {"AmovPpneMstpSrasWrflDnon",0.02};
			interpolateTo[] = {"AmovPpneMstpSrasWrflDnon",0.02};
		};
		class ACE_AmovPpneMstpSrasWrflDnon_Supported: AmovPpneMstpSrasWrflDnon_Bipod
		{
			equivalentTo = "AmovPpneMstpSrasWrflDnon";
			aimPrecision = 0.115;
		};
	};
};
class CfgSounds
{
	class ace_deployweapon_1
	{
		name = "ace_deployweapon_1";
		sound[] = {"\x\ace\addons\sys_weaponrest\sound\depl1.ogg",5,1};
		titles[] = {};
	};
	class ace_deployweapon_2
	{
		name = "ace_deployweapon_2";
		sound[] = {"\x\ace\addons\sys_weaponrest\sound\depl2.ogg",5,1};
		titles[] = {};
	};
	class ace_deployweapon_3
	{
		name = "ace_deployweapon_3";
		sound[] = {"\x\ace\addons\sys_weaponrest\sound\depl3.ogg",5,1};
		titles[] = {};
	};
};
//};
