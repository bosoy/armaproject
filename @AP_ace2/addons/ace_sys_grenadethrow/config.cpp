////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:16 2013 : Created on Sat Apr 06 11:45:16 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_grenadethrow : config.bin{
class CfgPatches
{
	class ace_sys_grenadethrow
	{
		units[] = {"ACE_Grenade_Geometry"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_interaction","ace_c_weapon","CA_Anims","CA_Anims_E","ace_anims"};
		version = "1.14.0.590";
		author[] = {"q1184"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_grenadethrow
		{
			list[] = {"ace_sys_grenadethrow"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_grenadethrow
	{
		clientinit = "call ('\x\ace\addons\sys_grenadethrow\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class ace_sys_grenadethrow
		{
			clientFiredBisPlayer = "if (ace_sys_grenadethrow_opt_enabled == 1) then { if ((_this select 1) == 'Throw') then { _this call ace_sys_grenadethrow_fnc_fired}}";
		};
	};
};
class ACE_Progressbar_RscText;
class RscTitles
{
	class ACE_RscCursorG
	{
		idd = -1;
		onLoad = "with uiNameSpace do { ACE_RscCursorG = _this select 0 };call ace_sys_grenadethrow_mkey_add";
		onUnload = "call ace_sys_grenadethrow_mkey_remove";
		movingEnable = 1;
		duration = 10000;
		fadeIn = 0;
		fadeOut = 0;
		controls[] = {"ACE_RscCursor_1","ACE_RscCursor_ModePic","ACE_ThrowBackground","ACE_ThrowStrengthBar"};
		class ACE_RscCursor_1
		{
			idc = 159155;
			type = 0;
			style = "48 + 0x800";
			movingEnable = 1;
			font = "TahomaB";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			text = "\ca\UI\Data\cursor_w_grenade_gs.paa";
			sizeEx = 0.03;
			x = 0.1;
			y = 0.1;
			w = 0.35;
			h = 0.35;
			size = 0.034;
			shadow = 0;
			fixedWidth = 0;
			lineSpacing = 0;
		};
		class ACE_RscCursor_ModePic: ACE_RscCursor_1
		{
			idc = 159156;
			type = 0;
			style = "48 + 0x800";
			movingEnable = 1;
			font = "TahomaB";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			text = "";
			sizeEx = 0.03;
			x = 0.1;
			y = 0.1;
			w = 0.35;
			h = 0.35;
			size = 0.034;
			shadow = 0;
			fixedWidth = 0;
			lineSpacing = 0;
		};
		class ACE_ThrowBackground: ACE_Progressbar_RscText
		{
			style = 128;
			idc = 1;
			x = "SafeZoneX + 0.001";
			y = "SafeZoneY + 0.04";
			h = 0.12;
			w = 0.385;
			colorBackground[] = {0,0,0,0.5};
		};
		class ACE_ThrowStrengthBar: ACE_Progressbar_RscText
		{
			style = 128;
			idc = 2;
			x = "SafeZoneX + 0.011";
			y = "SafeZoneY + 0.045";
			h = 0.02;
			w = 0;
			colorBackground[] = {0.4,0.6745,0.2784,1};
		};
	};
};
class CfgVehicles
{
	class Motorcycle;
	class ACE_Grenade_Geometry: Motorcycle
	{
		access = 3;
		scope = 1;
		side = -5;
		accuracy = 0;
		camouflage = 2;
		autocenter = 0;
		displayName = "$STR_SN_GRENADE";
		mapSize = 0;
		model = "\x\ace\addons\sys_grenadethrow\ace_grenade_helper2.p3d";
		crew = "Civilian";
		audible = 1;
		cost = 500000;
		hasCommander = 0;
		hasGunner = 0;
		memoryPointsGetInCoDriver = "";
		memoryPointsGetInCoDriverDir = "";
		memoryPointTrack1L = "";
		memoryPointTrack1R = "";
		memoryPointTrack2L = "";
		memoryPointTrack2R = "";
		hideWeaponsDriver = 1;
		hideWeaponsCargo = 1;
		ejectDeadDriver = 1;
		ejectDeadCargo = 1;
		getInRadius = 0;
		driverIsCommander = 0;
		transportSoldier = 0;
		transportAmmo = 0;
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		isBicycle = 1;
		canFloat = 0;
		preferRoads = 0;
		terrainCoef = 10;
		maxSpeed = 0;
		limitedSpeedCoef = 1;
		brakeDistance = 0.2;
		turnCoef = 10;
		fuelCapacity = 0;
		wheelCircumference = 0;
		precision = 0.01;
		irTarget = 0;
		unitInfoType = "UnitInfoCar";
		hideUnitInfo = 1;
		type = 0;
		unloadInCombat = 0;
		sensitivity = 0;
		damperSize = 0;
		damperForce = 0;
		damperDamping = 0;
		armor = 5;
		armorStructural = 1;
		selectionDamage = "Component01";
		damageResistance = 0;
		dammageHalf[] = {};
		dammageFull[] = {};
		additionalSound[] = {"",0.005,1};
		soundEnviron[] = {"",0.003,0.25};
		soundEngine[] = {"",0.001,0.3};
		soundCrash[] = {"",0,1};
		soundLandCrash[] = {"",0,1};
		soundWaterCrash[] = {"",0,1};
		soundGear[] = {"",0,1};
		soundGetIn[] = {"",0,1};
		soundGetOut[] = {"",0,1};
		weapons[] = {};
		magazines[] = {};
		getInAction = "Crouch";
		getOutAction = "Crouch";
		driverAction = "Crouch";
		cargoAction[] = {"Crouch"};
		cargoIsCoDriver[] = {0,0,0};
		threat[] = {0,0,0};
		destrType = "DestructNo";
		class HitBody
		{
			armor = 1;
			material = -1;
			name = "Component01";
			visual = "Component01";
			passThrough = 0;
		};
		class AnimationSources{};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		class Reflectors{};
		class Turrets{};
	};
};
class CfgMovesBasic
{
	class Default;
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class AwopPercMstpSgthWrflDnon_Start1: Default
		{
			actions = "RifleLowStandActions";
			file = "\x\ace\addons\sys_grenadethrow\anim\smk_CombatStand_GrenadeThrowStart.rtm";
			rightHandIKCurve[] = {0.1,1,0.2,0};
			leftHandIKCurve[] = {0};
			speed = 1.5;
			looped = 0;
			soundEnabled = 0;
			duty = 0.6;
			canPullTrigger = 0;
			headBobMode = 2;
			ConnectTo[] = {"AwopPercMstpSgthWrflDnon_Throw1",0.1};
			InterpolateTo[] = {"AdthPercMstpSlowWrflDnon_1",0.01};
			leaningFactorBeg = 0.75;
			leaningFactorEnd = 0.75;
		};
		class AwopPercMstpSgthWrflDnon_Throw1: AwopPercMstpSgthWrflDnon_Start1
		{
			file = "\x\ace\addons\sys_grenadethrow\anim\smk_CombatStand_GrenadeThrowThrow.rtm";
			rightHandIKCurve[] = {0};
			leftHandIKCurve[] = {0};
			speed = 3.51;
			canPullTrigger = 0;
			ConnectTo[] = {"AwopPercMstpSgthWrflDnon_End1",0.1};
			InterpolateTo[] = {"AdthPercMstpSlowWrflDnon_1",0.01};
		};
		class AwopPercMstpSgthWrflDnon_End1: AwopPercMstpSgthWrflDnon_Start1
		{
			file = "\x\ace\addons\sys_grenadethrow\anim\smk_CombatStand_GrenadeThrowEnd.rtm";
			speed = 1.11;
			rightHandIKCurve[] = {0.2,0,0.3,1};
			leftHandIKCurve[] = {0.3,0,0.4,1};
			showItemInRightHand = 0;
			canPullTrigger = 0;
			ConnectTo[] = {"AmovPercMstpSlowWrflDnon",0.1};
			InterpolateTo[] = {"AdthPercMstpSlowWrflDnon_1",0.01};
		};
		class AwopPknlMstpSgthWrflDnon_Start: Default
		{
			actions = "RifleKneelActions";
			file = "\x\ace\addons\sys_grenadethrow\anim\smk_CombatCrouch_GrenadeThrowStart.rtm";
			speed = 0.87;
			looped = 0;
			soundEnabled = 0;
			leaningFactorBeg = 0.75;
			leaningFactorEnd = 0.75;
			duty = 0.6;
			collisionShape = "ca\Anims\Characters\Data\Geom\Sdr\Pknl_Wrfl.p3d";
			headBobMode = 2;
			ConnectTo[] = {"AwopPknlMstpSgthWrflDnon_Throw",0.1};
			InterpolateTo[] = {"AdthPknlMstpSrasWrflDnon_1",0.01};
		};
		class AwopPknlMstpSgthWrflDnon_Throw: AwopPknlMstpSgthWrflDnon_Start
		{
			file = "\x\ace\addons\sys_grenadethrow\anim\smk_CombatCrouch_GrenadeThrowThrow.rtm";
			speed = 4.33;
			ConnectTo[] = {"AwopPknlMstpSgthWrflDnon_End",0.1};
			InterpolateTo[] = {"AdthPknlMstpSrasWrflDnon_1",0.01};
		};
		class AwopPknlMstpSgthWrflDnon_End: AwopPknlMstpSgthWrflDnon_Start
		{
			file = "\x\ace\addons\sys_grenadethrow\anim\smk_CombatCrouch_GrenadeThrowEnd.rtm";
			speed = 0.8;
			ConnectTo[] = {"AmovPknlMstpSrasWrflDnon",0.1};
			InterpolateTo[] = {"AdthPknlMstpSrasWrflDnon_1",0.01};
		};
	};
};
class cfgMagazines
{
	class CA_Magazine;
	class HandGrenade: CA_Magazine
	{
		maxThrowIntensityCoef = 1;
	};
	class IR_Strobe_Target: CA_Magazine
	{
		maxThrowIntensityCoef = 1;
	};
};
//};
