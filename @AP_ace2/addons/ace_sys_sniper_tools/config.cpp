////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:46:44 2013 : Created on Sat Apr 06 11:46:44 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_sniper_tools : config.bin{
class CfgPatches
{
	class ace_sys_sniper_tools
	{
		units[] = {"ACE_SpottingScope","ACE_SSVZ"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main","ace_c_weapon","ace_c_vehicle","ace_m_wep_optics","ace_sys_interaction"};
		version = "1.14.0.590";
		author[] = {"Rocko","Scubaman3D"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_sniper_tools
		{
			list[] = {"ace_sys_sniper_tools"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_sniper_tools
	{
		clientInit = "call ('\x\ace\addons\sys_sniper_tools\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgWeapons
{
	class ACE_Item;
	class ACE_SpottingScope: ACE_Item
	{
		scope = 2;
		displayName = "$STR_DN_ACE_SPOTTINGSCOPE";
		picture = "\x\ace\addons\sys_sniper_tools\data\equip\w_spottingscope_ca.paa";
		descriptionShort = "";
		model = "\x\ace\addons\sys_sniper_tools\w_spottingscope.p3d";
		ACE_Weight = 0.87;
		ACE_Size = 3000;
	};
	class ACE_SniperTripod: ACE_Item
	{
		scope = 2;
		displayName = "$STR_DN_ACE_SNIPERTRIPOD";
		picture = "\x\ace\addons\sys_sniper_tools\data\equip\w_sniper_tripod_ca.paa";
		descriptionShort = "";
		model = "\x\ace\addons\sys_sniper_tools\w_sniper_tripod.p3d";
		class ACE
		{
			class ACE_CREWSERVED
			{
				isTripod = 1;
				mountTime = 5;
			};
		};
		ACE_Weight = 2.95;
		ACE_Size = 21300;
	};
	class M9;
	class ACE_SSVZ: M9
	{
		scope = 2;
		displayName = "SSVZ-S";
		picture = "\x\ace\addons\sys_sniper_tools\data\equip\w_ssvz_s_ca.paa";
		descriptionShort = "Scout Sniper Periscope Kit";
		drySound[] = {"",0.01,1,20};
		magazines[] = {};
		model = "\x\ace\addons\sys_sniper_tools\ace_ssvzs.p3d";
		modelOptics = "\x\ace\addons\sys_sniper_tools\optic_ssvzs.p3d";
		cameraDir = "GL look";
		memoryPointCamera = "GL eye";
		ACE_Weight = 0.53;
		ACE_Size = 3000;
		class OpticsModes
		{
			class FourTimes
			{
				opticsID = 1;
				useModelOptics = 1;
				opticsPPEffects[] = {"OpticsCHAbera1","OpticsBlur1"};
				opticsFlare = 1;
				opticsZoomMin = 0.0623;
				opticsZoomMax = 0.0277;
				opticsZoomInit = 0.0623;
				distanceZoomMin = 300;
				distanceZoomMax = 300;
				memoryPointCamera = "GL eye";
				cameraDir = "GL look";
				visionMode[] = {};
				thermalMode[] = {0,1};
				opticsDisablePeripherialVision = 1;
				discretefov[] = {0.0623,0.0277};
				discreteInitIndex = 0;
			};
		};
	};
};
class CfgVehicles
{
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets;
	};
	class StaticATWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class ACE_SpottingScope: StaticATWeapon
	{
		scope = 1;
		side = 1;
		faction = "USMC";
		crew = "USMC_Soldier";
		typicalCargo[] = {"USMC_Soldier"};
		displayName = "$STR_DN_ACE_SPOTTINGSCOPE";
		model = "\x\ace\addons\sys_sniper_tools\spottingscope.p3d";
		class Library
		{
			libTextDesc = "";
		};
		picture = "\Ca\characters\data\Ico\i_null_CA.paa";
		Icon = "\Ca\characters\data\map_ico\i_wojak_CA.paa";
		mapSize = 0.5;
		transportSoldier = 0;
		getInAction = "Metis_Gunner";
		getOutAction = "PlayerProne";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minTurn = -45;
				maxTurn = 45;
				initTurn = 0;
				minElev = -10;
				maxElev = 40;
				initElev = 0;
				weapons[] = {};
				magazines[] = {};
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOpticsmodel = "x\ace\addons\m_wep_optics\m144_optic.p3d";
				gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 0;
				gunnerAction = "Metis_Gunner";
				gunnerGetInAction = "Metis_Gunner";
				gunnerGetOutAction = "PlayerProne";
				gunnerForceOptics = 0;
				ejectDeadGunner = 0;
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.7;
					maxFov = 0.7;
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.014812;
					minFov = 0.014812;
					maxFov = 0.014812;
				};
			};
		};
		class UserActions
		{
			class ACE_PickupSpottingScope
			{
				displayName = "$STR_ACE_PICKUPSPOTTINGSCOPE";
				position = "pos_gunner";
				radius = 4;
				condition = "(alive this) && {(count (crew this) == 0)}";
				statement = "[this,player] spawn ACE_SYS_SNIPER_TOOLS_FNC_PICKUP";
				onlyForPlayer = 1;
			};
		};
		class ACE
		{
			class ACE_CREWSERVED
			{
				interaction = "XXX";
				canDrag = 0;
			};
		};
	};
	class ACE_SniperTripod: ACE_SpottingScope
	{
		displayName = "$STR_DN_ACE_SNIPERTRIPOD";
		model = "\x\ace\addons\sys_sniper_tools\sniper_tripod.p3d";
		class Library
		{
			libTextDesc = "";
		};
		class Turrets{};
		class UserActions{};
		class ACE: ACE
		{
			class ACE_CREWSERVED: ACE_CREWSERVED
			{
				interaction = "Tripod";
				canDrag = 0;
				tripodProxy = "ACE_SniperTripod";
				canChangeHeight = 1;
				mountTime = 5;
				pickupTime = 4;
			};
		};
		class AnimationSources
		{
			class slide_down_tripod
			{
				source = "user";
				animPeriod = 0.02;
				initPhase = 0;
				minValue = 0;
				maxValue = 1;
			};
			class retract_leg_1: slide_down_tripod{};
			class retract_leg_2: retract_leg_1{};
			class retract_leg_3: retract_leg_2{};
		};
		ACE_Weight = 2.95;
	};
};
//};
