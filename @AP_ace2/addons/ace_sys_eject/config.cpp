////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Aug 11 06:47:20 2014 : Created on Mon Aug 11 06:47:20 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_eject : config.bin{
class CfgPatches
{
	class ace_sys_eject
	{
		units[] = {"ACE_Ka52_Blade","ACE_EjectionSeatBase","ACE_ACESII","ACE_K36","ACE_MB_Mk12","ACE_UsedPara_Base","ACE_UsedParachute_MC5","ACE_UsedParachute_Round"};
		weapons[] = {"ACE_ParachutePack","ACE_ParachuteRoundPack"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAWeapons","CAAir","CAAir2","CAAir3","CAAir2_C130J","CAData","CAMisc3","CA_L39","CAAir_E","CAAir_E_UH1H_EP1","CAAir_E_An2","CAAir_E_CH_47F","CAAir_E_AH6J","CAAir_BAF","ace_sys_survival","ace_sys_interaction"};
		version = "1.14.0.592";
		author[] = {"Homer Johnston","tcp","zGuba","Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_eject
		{
			list[] = {"ace_sys_eject"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_eject
	{
		init = "call ('\x\ace\addons\sys_eject\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_eject\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Air
	{
		class ace_sys_eject
		{
			clientInit = "if (player in (_this select 0)) then {_this call ace_sys_eject_fnc_init_jumpout; _this call ace_sys_eject_fnc_init_eject}";
		};
	};
	class LandVehicle
	{
		class ace_sys_eject
		{
			clientInit = "if (player in (_this select 0)) then {_this call ace_sys_eject_fnc_init_jumpout}";
		};
	};
	class Ship
	{
		class ace_sys_eject
		{
			clientInit = "if (player in (_this select 0)) then {_this call ace_sys_eject_fnc_init_jumpout}";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class Air
	{
		class ace_sys_eject
		{
			clientGetIn = "if (_this select 2 == player) then { _this call ace_sys_eject_fnc_getin_jumpout; _this call ace_sys_eject_fnc_getin_eject }";
		};
	};
	class LandVehicle
	{
		class ace_sys_eject
		{
			clientGetIn = "if (_this select 2 == player) then { _this call ace_sys_eject_fnc_getin_jumpout }";
		};
	};
	class Ship
	{
		class ace_sys_eject
		{
			clientGetIn = "if (_this select 2 == player) then { _this call ace_sys_eject_fnc_getin_jumpout }";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class Air
	{
		class ace_sys_eject
		{
			getOut = "if (local (_this select 2)) then {_this call ace_sys_eject_fnc_getout_eh}";
			clientGetOut = "if (player == (_this select 2)) then {_this call ace_sys_eject_fnc_clientGetOut}";
		};
	};
	class LandVehicle
	{
		class ace_sys_eject
		{
			clientGetOut = "if (player == (_this select 2)) then {_this call ace_sys_eject_fnc_clientGetOut}";
		};
	};
	class Ship
	{
		class ace_sys_eject
		{
			clientGetOut = "if (player == (_this select 2)) then {_this call ace_sys_eject_fnc_clientGetOut}";
		};
	};
};
class CfgActions
{
	class None;
	class Eject: None
	{
		show = 0;
		shortcut = "";
	};
};
class CfgWeapons
{
	class Default
	{
		class ACE;
	};
	class ACE_ParachutePack: Default
	{
		ACE_Weight = 23;
		ACE_Size = 9000;
		ACE_NoPack = 1;
		canLock = 0;
		displayName = "$STR_DN_ACE_PARACHUTEPACK";
		enableAttack = 0;
		forceOptics = 0;
		model = "\x\ace\addons\sys_eject\parachutepack.p3d";
		optics = 0;
		picture = "\x\ace\addons\sys_eject\data\equip\para_icon.paa";
		primary = 0;
		scope = 2;
		showEmpty = 0;
		simulation = "ProxyWeapon";
		type = 4;
		class Library
		{
			libTextDesc = "A parachute pack will allow you to deploy a parachute. MC-5 is HALO capable gliding chute ";
		};
		class ACE
		{
			class ACE_EJECT_PARACHUTE
			{
				hasAAD = 1;
			};
		};
	};
	class ACE_ParachuteRoundPack: ACE_ParachutePack
	{
		ACE_Weight = 18;
		ACE_Size = 9000;
		ACE_NoPack = 1;
		displayName = "$STR_DN_ACE_PARACHUTEROUNDPACK";
		picture = "\x\ace\addons\sys_eject\data\equip\parar_icon.paa";
		class Library
		{
			libTextDesc = "A parachute pack will allow you to deploy a parachute. T-10 is standard issued jellyfish chute";
		};
		class ACE: ACE
		{
			class ACE_EJECT_PARACHUTE: ACE_EJECT_PARACHUTE
			{
				hasAAD = 0;
			};
		};
	};
};
class CfgVehicles
{
	class All;
	class AllVehicles: All
	{
		ACE_SYS_EJECT_EJECT = 0;
		ACE_SYS_EJECT_JUMP = 1;
	};
	class Ship: AllVehicles
	{
		ace_sys_eject_side = 0;
		ace_sys_eject_weaponCheck = 0;
	};
	class LandVehicle;
	class Motorcycle: LandVehicle
	{
		ace_sys_eject_side = 0;
		ace_sys_eject_weaponCheck = 0;
	};
	class Car: LandVehicle
	{
		class NewTurret;
		ace_sys_eject_side = 1;
		ace_sys_eject_weaponCheck = 0;
	};
	class ATV_Base_EP1: Car
	{
		ace_sys_eject_weaponCheck = 0;
	};
	class Truck: Car
	{
		ace_sys_eject_side = 0;
		ace_sys_eject_weaponCheck = 0;
	};
	class Wheeled_APC: Car
	{
		ace_sys_eject_side = 0;
		ace_sys_eject_weaponCheck = 1;
	};
	class Tank: LandVehicle
	{
		ace_sys_eject_side = 0;
		ace_sys_eject_weaponCheck = 1;
	};
	class StaticWeapon: LandVehicle
	{
		ACE_SYS_EJECT_JUMP = 0;
		ace_sys_eject_weaponCheck = 0;
	};
	class Air;
	class Helicopter: Air
	{
		ace_sys_eject_weaponCheck = 1;
		class NewTurret;
		ace_ejection_seat = "ParachuteC";
		ace_sys_eject_side = 0;
	};
	class AH6_Base_EP1;
	class Kamov_Base: Helicopter
	{
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ACE_SYS_EJECT_MULTICREW = 1;
		ace_ejection_seat = "ACE_K36";
	};
	class UH60_Base: Helicopter
	{
		ace_sys_eject_side = 1;
	};
	class Mi24_Base: Helicopter
	{
		ace_sys_eject_side = 1;
	};
	class Mi17_base_CZ_EP1;
	class Mi171Sh_Base_EP1: Mi17_base_CZ_EP1
	{
		ace_sys_eject_side = 1;
	};
	class UH1_Base: Helicopter
	{
		ace_sys_eject_side = 1;
	};
	class UH1H_base: Helicopter
	{
		ace_sys_eject_side = 1;
	};
	class AW159_Lynx_BAF: Helicopter
	{
		ace_sys_eject_side = 1;
	};
	class BAF_Merlin_HC3_D: Helicopter
	{
		ace_sys_eject_side = 1;
	};
	class ParachuteBase: Helicopter
	{
		ace_sys_eject_weaponCheck = 0;
		ACE_SYS_EJECT_JUMP = 0;
		model = "\x\ace\addons\sys_eject\para_round.p3d";
		class EventHandlers
		{
			init = "_this spawn ('\x\ace\addons\sys_eject\fnc_parachute_round.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
		};
	};
	class ParachuteWest;
	class Parachute: ParachuteWest
	{
		model = "\ca\air\para";
	};
	class Plane: Air
	{
		ace_sys_eject_weaponCheck = 1;
		class NewTurret;
		ace_ejection_seat = "ParachuteC";
	};
	class A10: Plane
	{
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ace_ejection_seat = "ACE_ACESII";
	};
	class AV8B2: Plane
	{
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ace_ejection_seat = "ACE_MB_Mk12";
	};
	class Su25_base: Plane
	{
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ace_ejection_seat = "ACE_K36";
	};
	class F35_base: Plane
	{
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ace_ejection_seat = "ACE_MB_Mk12";
	};
	class Su34: Plane
	{
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ACE_SYS_EJECT_MULTICREW = 1;
		ace_ejection_seat = "ACE_K36";
	};
	class L39_base: Plane
	{
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ace_ejection_seat = "ACE_K36";
	};
	class C130J: Plane
	{
		ACE_SYS_EJECT_EJECT = 0;
		ACE_SYS_EJECT_JUMP = 1;
	};
	class An2_Base_EP1: Plane
	{
		ACE_SYS_EJECT_EJECT = 0;
		ACE_SYS_EJECT_JUMP = 1;
	};
	class UAV: Plane
	{
		ACE_isUAV = 1;
	};
	class AH6X_EP1: AH6_Base_EP1
	{
		ACE_isUAV = 1;
	};
	class Ka137_Base_PMC: Helicopter
	{
		ACE_isUAV = 1;
	};
	class Thing;
	class ACE_Ka52_Blade: Thing
	{
		scope = 1;
		camouflage = 1000;
		model = "\x\ace\addons\sys_eject\ace_ka52_blade.p3d";
		timeToLive = 300;
	};
	class ACE_EjectionSeat: Motorcycle
	{
		ACE_SYS_EJECT_JUMP = 0;
		icon = "\ca\air\data\map_ico\icomap_Para_CA.paa";
		picture = "\ca\air\data\ico\Para_CA.paa";
		irTarget = 0;
		mapSize = 4;
		minFireTime = 1;
		camouflage = 1;
		crewVulnerable = 1;
		audible = 0;
		castDriverShadow = 1;
		insideSoundCoef = 1;
		occludeSoundsWhenIn = 1;
		obstructSoundsWhenIn = 1;
		transportSoldier = 0;
		hideUnitInfo = 1;
		brakeDistance = 100;
		damperSize = 0;
		damperForce = 0;
		damperDamping = 0;
		wheelCircumference = 10;
		fuelCapacity = 0;
		supplyRadius = -1;
		getInRadius = -1;
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		weapons[] = {};
		displayName = "$STR_ACE_VDN_ACE_EJECTIONSEAT";
		TextPlural = "$STR_ACE_VDN_ACE_EJECTIONSEAT";
		TextSingular = "$STR_ACE_VDN_ACE_EJECTIONSEAT";
		soundEnviron[] = {"\Ca\sounds\Air\Noises\padak_let",0.316228,1.25,80};
		soundCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.0316228,1.125,50};
		soundLandCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.0316228,1.125,50};
		soundWaterCrash[] = {"\Ca\sounds\Air\Noises\padak_dopadvoda",3.16228,1.125,80};
		soundEngine[] = {"",0.354813,1.0};
		soundEngineOnInt[] = {"",0.354813,1.0};
		soundEngineOnExt[] = {"",0.354813,1.0};
		soundEngineOffInt[] = {"",0.354813,1.0};
		soundEngineOffExt[] = {"",0.354813,1.0};
		class Sounds
		{
			class Engine
			{
				sound[] = {"",0.562341,1.0,400};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "0";
			};
			class EngineHighOut
			{
				sound[] = {"",0.562341,1.0,500};
				frequency = "(randomizer*0.05+1.0)*rpm";
				volume = "0";
			};
			class IdleOut
			{
				sound[] = {"",0.316228,1.0,250};
				frequency = "1";
				volume = "0";
			};
			class NoiseOut
			{
				sound[] = {"",0.562341,1.0,60};
				frequency = "1";
				volume = "0";
			};
			class EngineLowIn
			{
				sound[] = {"",0.794328,1.0};
				frequency = "(randomizer*0.05+0.95)*rpm";
				volume = "0";
			};
			class EngineHighIn
			{
				sound[] = {"",0.794328,1.0};
				frequency = "(randomizer*0.05+1.0)*rpm";
				volume = "0";
			};
			class IdleIn
			{
				sound[] = {"",0.316228,1.0};
				frequency = "1";
				volume = "0";
			};
		};
		class DestructionEffects{};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		class Reflectors{};
		class Turrets{};
		class UserActions{};
		nameSound = "pilot";
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"veh_pilot"};
				speechPlural[] = {"veh_pilots"};
			};
			class EN: Default{};
			class CZ
			{
				speechSingular[] = {"veh_pilot_CZ"};
				speechPlural[] = {"veh_pilots_CZ"};
			};
			class CZ_Akuzativ
			{
				speechSingular[] = {"veh_pilot_CZ4P"};
				speechPlural[] = {"veh_pilots_CZ4P"};
			};
			class RU
			{
				speechSingular[] = {"veh_pilot_RU"};
				speechPlural[] = {"veh_pilots_RU"};
			};
		};
	};
	class ACE_ACESII: ACE_EjectionSeat
	{
		scope = 1;
		accuracy = 3;
		displayName = "ACES II";
		crew = "SoldierWPilot";
		driverAction = "A10_Pilot";
		model = "\x\ace\addons\sys_eject\ace_acesii.p3d";
	};
	class ACE_K36: ACE_EjectionSeat
	{
		scope = 1;
		accuracy = 3;
		displayName = "K-36";
		crew = "SoldierEPilot";
		driverAction = "Su34_Gunner";
		model = "\x\ace\addons\sys_eject\ace_k36.p3d";
	};
	class ACE_MB_Mk12: ACE_EjectionSeat
	{
		scope = 1;
		accuracy = 3;
		displayName = "Martin Baker Mk12";
		crew = "SoldierWPilot";
		driverAction = "AV8B_Pilot";
		model = "\x\ace\addons\sys_eject\ace_mb_mk12.p3d";
	};
	class Land_Dirthump01;
	class ACE_UsedPara_Base: Land_Dirthump01
	{
		scope = 1;
		icon = "";
		destrType = "DestructNo";
		displayName = "$STR_DN_PARACHUTE";
		accuracy = 0;
		camouflage = 2;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		class ACE;
	};
	class ACE_UsedParachute_MC5: ACE_UsedPara_Base
	{
		model = "\x\ace\addons\sys_eject\para_round_used.p3d";
		class ACE: ACE
		{
			class ACE_EJECT_PARACHUTE
			{
				pack = "ACE_ParachutePack";
			};
		};
	};
	class ACE_UsedParachute_Round: ACE_UsedParachute_MC5
	{
		model = "\x\ace\addons\sys_eject\para_round_used.p3d";
		class ACE: ACE
		{
			class ACE_EJECT_PARACHUTE: ACE_EJECT_PARACHUTE
			{
				pack = "ACE_ParachuteRoundPack";
			};
		};
	};
	class BIS_Steerable_Parachute: Plane
	{
		ace_sys_eject_weaponCheck = 0;
		accuracy = 0;
		displayName = "$STR_DN_STEERABLE_PARACHUTE";
		displayNameShort = "$STR_DN_PARACHUTE";
		model = "\x\ace\addons\sys_eject\ace_mc5.p3d";
		class TransportMagazines{};
		class TransportWeapons{};
		UnitInfoType = "UnitInfoSoldier";
		bounding = "doplnovani";
		Icon = "\ca\air\data\map_ico\icomap_Para_CA.paa";
		mapSize = 5;
		nameSound = "veh_parachute";
		camouflage = 2;
		audible = 0;
		hasGunner = 0;
		hasDriver = 0;
		transportSoldier = 1;
		fuelCapacity = 0;
		irTarget = 0;
		picture = "\ca\air\data\ico\Para_CA.paa";
		gunnerCanSee = "2+8+32";
		secondaryExplosion = -1;
		extCameraPosition[] = {0,2.5,-8};
		destrType = "DestructNo";
		maxSpeed = 100;
		enableGPS = 0;
		canFloat = 1;
		simulation = "car";
		wheelCircumference = 2.513;
		waterSpeedFactor = 0.2;
		leftDustEffect = "LDustEffects";
		rightDustEffect = "RDustEffects";
		leftWaterEffect = "LWaterEffects";
		rightWaterEffect = "RWaterEffects";
		formationX = 40;
		formationZ = 40;
		precision = 10;
		sensitivity = 3;
		cargoAction[] = {"Para_Pilot"};
		initCargoAngleY = "+185";
		selectionBackLights = "";
		selectionBrakeLights = "";
		selectionClan = "";
		selectionDashboard = "";
		selectionFireAnim = "";
		selectionShowDamage = "";
		memoryPointMissile[] = {"",""};
		memoryPointMissileDir[] = {"",""};
		holdOffroadFormation = 0;
		class Exhausts
		{
			class Exhaust1
			{
				position = "";
				direction = "";
				effect = "ExhaustsEffect";
			};
		};
		class PlateInfos
		{
			name = "spz";
			color[] = {0,0,0,0};
		};
		class HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.2;
			};
			class HitRGlass
			{
				convexComponent = "";
				visual = "";
				armor = 0.3;
				material = -1;
				name = "";
				passThrough = 0;
			};
			class HitLGlass
			{
				convexComponent = "";
				visual = "";
				armor = 0.3;
				material = -1;
				name = "";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 1;
			};
			class HitFuel
			{
				armor = 0.3;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.5;
			};
			class HitLFWheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitRFWheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitLF2Wheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitRF2Wheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitLMWheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitRMWheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitLBWheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitRBWheel
			{
				armor = 0.15;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0.3;
			};
			class HitGlass1
			{
				armor = 0.1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0;
			};
			class HitGlass2
			{
				armor = 0.1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0;
			};
			class HitGlass3
			{
				armor = 0.1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0;
			};
			class HitGlass4
			{
				armor = 0.1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 0;
			};
		};
		alphaTracks = 0;
		memoryPointTrackFLL = "";
		memoryPointTrackFLR = "";
		memoryPointTrackBLL = "";
		memoryPointTrackBLR = "";
		memoryPointTrackFRL = "";
		memoryPointTrackFRR = "";
		memoryPointTrackBRL = "";
		memoryPointTrackBRR = "";
		memoryPointCirculumReference = "";
		gearBox[] = {-8,0,10,6.15,4.44,3.33};
		dammageHalf[] = {};
		dammageFull[] = {};
		armorLights = 0;
		turnCoef = 2;
		terrainCoef = 2;
		scudModel = "";
		damperSize = 0.1;
		damperForce = 1;
		damperDamping = 1;
		soundGear[] = {"",1e-005,1};
		class EventHandlers
		{
			Init = "_this spawn ('\x\ace\addons\sys_eject\fnc_init_chuteSteer.sqf' call {_slx_xeh_compile = uiNamespace getVariable 'SLX_XEH_COMPILE'; if (isNil '_slx_xeh_compile') then { _this call compile preProcessFileLineNumbers 'x\cba\addons\xeh\init_compile.sqf' } else { _this call _slx_xeh_compile } })";
		};
		occludeSoundsWhenIn = 1;
		obstructSoundsWhenIn = 1;
		class SpeechVariants
		{
			class Default
			{
				speechSingular[] = {"veh_Parachute"};
				speechPlural[] = {"veh_Parachutes"};
			};
			class EN: Default{};
			class CZ
			{
				speechSingular[] = {"veh_Parachute_CZ"};
				speechPlural[] = {"veh_Parachutes_CZ"};
			};
			class CZ_Akuzativ
			{
				speechSingular[] = {"veh_Parachute_CZ4P"};
				speechPlural[] = {"veh_Parachutes_CZ4P"};
			};
			class RU
			{
				speechSingular[] = {"veh_Parachute_RU"};
				speechPlural[] = {"veh_Parachutes_RU"};
			};
		};
		TextPlural = "$STR_DN_PARACHUTE";
		TextSingular = "$STR_DN_PARACHUTES";
	};
	class Steerable_Parachute_EP1: Plane
	{
		ace_sys_eject_weaponCheck = 0;
		irTarget = 0;
	};
};
class CfgSounds
{
	class ACE_EjectionSeat
	{
		sound[] = {"\x\ace\addons\sys_eject\sound\EjectionSeat.ogg",7,1};
		name = "ACE_EjectionSeat";
		titles[] = {};
	};
	class ChuteOpen
	{
		name = "ChuteOpen";
		sound[] = {"\x\ace\addons\sys_eject\sound\ChuteOpen.ogg","db+15",1};
		titles[] = {};
	};
	class SkyDiveWind
	{
		name = "SkyDiveWind";
		sound[] = {"\x\ace\addons\sys_eject\sound\SkyDiveWind.ogg","db+100",1};
		titles[] = {};
	};
	class ChuteFlutter2
	{
		name = "ChuteFlutter2";
		sound[] = {"\x\ace\addons\sys_eject\sound\ChuteFlutter2.ogg","db+4",1};
		titles[] = {};
	};
	class ParaLand
	{
		name = "ParaLand";
		sound[] = {"\x\ace\addons\sys_eject\sound\ParaLand.ogg","db-6",1};
		titles[] = {};
	};
	class ParaLandinWater
	{
		name = "ParaLandinWater";
		sound[] = {"\x\ace\addons\sys_eject\sound\ParaLandinWater.ogg","db-6",1};
		titles[] = {};
	};
};
class RscTitles
{
	class ACE_Altimeter_HALO
	{
		idd = -1;
		movingEnable = 0;
		fadein = 0;
		fadeout = 0;
		duration = 10;
		name = "ACE_Altimeter_Halo";
		onload = "uiNameSpace setVariable ['ACE_Altimeter_Halo', _this select 0]";
		class controlsBackground
		{
			class BackGround
			{
				idc = -1;
				type = 0;
				style = 48;
				size = 0.034;
				sizeEx = 0.027;
				font = "BitStream";
				text = "x\ace\addons\sys_eject\data\rsc\ace_alti_bg_ca.paa";
				x = "0.772128 * safezoneW + safezoneX";
				y = "0.337892 * safezoneH + safezoneY";
				w = "0.224087 * safezoneW";
				h = "0.336729 * safezoneH";
				colorText[] = {1,1,1,1};
				colorBackground[] = {1,1,1,0};
				colorBackgroundActive[] = {1,1,1,0.5};
			};
		};
		class controls
		{
			class Alt
			{
				idc = 135;
				type = 0;
				style = "0x02";
				sizeEx = 0.045;
				font = "ACE_Digit";
				text = "1113 m";
				x = "0.835068 * safezoneW + safezoneX";
				y = "0.484184 * safezoneH + safezoneY";
				w = "0.0918573 * safezoneW";
				h = "0.0411793 * safezoneH";
				colorBackground[] = {0.2,0.15,0.1,0};
				colorText[] = {1,1,1,1};
			};
			class Compass: Alt
			{
				idc = 136;
				sizeEx = 0.039;
				text = "NW";
				x = "0.858341 * safezoneW + safezoneX";
				y = "0.539538 * safezoneH + safezoneY";
				w = "0.0468997 * safezoneW";
				h = "0.0322832 * safezoneH";
			};
			class Clock: Alt
			{
				idc = 137;
				sizeEx = 0.039;
				text = "12:22";
				x = "0.844061 * safezoneW + safezoneX";
				y = "0.451566 * safezoneH + safezoneY";
				w = "0.0707007 * safezoneW";
				h = "0.023387 * safezoneH";
			};
		};
	};
};
//};
