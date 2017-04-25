////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 02 21:00:04 2012 : Created on Fri Nov 02 21:00:04 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_btr70 : config.bin{
class CfgPatches
{
	class acex_veh_btr70
	{
		units[] = {"ACE_BTR70_TK","ACE_BTR70_UN"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"CATracked","Extended_EventHandlers","acex_main","acex_m_veh_btr70","acex_t_veh_btr70","rhs_decals"};
		version = "1.14.0.369";
		author[] = {"Manfred and Soul Assassin (RHS)"};
		authorUrl = "http://forums.bistudio.com/showthread.php?t=106906";
	};
};
class Extended_PreInit_EventHandlers
{
	class acex_veh_btr70
	{
		init = "call ('\x\acex\addons\c_veh_btr70\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class ACE_BTR70_Base
	{
		class acex_veh_btr70
		{
			init = "_this call acex_veh_btr70_fnc_init";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class ACE_BTR70_Base
	{
		class acex_veh_btr70
		{
			getout = "_this call acex_veh_btr70_fnc_btr_doors";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class ACE_BTR70_Base
	{
		class acex_veh_btr70
		{
			getin = "_this call acex_veh_btr70_fnc_btr_doors";
		};
	};
};
class WeaponCloudsMGun;
class CfgVehicles
{
	class Wheeled_APC;
	class BRDM2_Base: Wheeled_APC
	{
		class Turrets;
	};
	class BTR60_TK_EP1: BRDM2_Base
	{
		class Turrets: Turrets
		{
			class MainTurret;
			class CommanderTurret;
		};
		class AnimationSources;
	};
	class ACE_BTR70_Base: BTR60_TK_EP1
	{
		damageResistance = 0.01849;
		scope = 1;
		picture = "\x\acex\addons\c_veh_btr70\data\picture\rhs_btr70_icon_ca.paa";
		Icon = "\x\acex\addons\c_veh_btr70\data\icon\rhs_btr70_mapicon_ca.paa";
		model = "\x\acex\addons\m_veh_btr70\mnf_btr70.p3d";
		displayName = "$STR_ACE_VDN_BTR70";
		class Library
		{
			libTextDesc = "$STR_BTR70_LIB";
		};
		threat[] = {1,0.3,0.6};
		cargogetinaction[] = {"GetInLow"};
		cargogetoutaction[] = {"GetOutLow"};
		ace_sys_eject_side = 1;
		class AnimationSources: AnimationSources
		{
			class driverViewHatch
			{
				source = "user";
				animPeriod = 2;
				initPhase = 0;
			};
			class commanderViewHatch: driverViewHatch{};
			class dHatch: driverViewHatch{};
			class cHatch: driverViewHatch{};
			class l_door: driverViewHatch{};
			class r_door: l_door{};
			class windows: l_door{};
			class t_door_1: l_door{};
			class t_door_2: l_door{};
			class engineHatches: l_door{};
			class propDoor: l_door{};
			class crate_l1_unhide_source: driverViewHatch
			{
				animPeriod = 0.1;
			};
			class crate_l2_unhide_source: crate_l1_unhide_source{};
			class crate_l3_unhide_source: crate_l1_unhide_source{};
			class crate_l4_unhide_source: crate_l1_unhide_source{};
			class crate_r1_unhide_source: crate_l1_unhide_source{};
			class crate_r2_unhide_source: crate_l1_unhide_source{};
			class crate_r3_unhide_source: crate_l1_unhide_source{};
			class crate_r4_unhide_source: crate_l1_unhide_source{};
			class water_1_unhide_source: crate_l1_unhide_source{};
			class water_2_unhide_source: crate_l1_unhide_source{};
			class wheel_1_unhide_source: crate_l1_unhide_source{};
			class wheel_2_unhide_source: crate_l1_unhide_source{};
		};
		driverOpticsModel = "\x\ace\addons\m_veh_optics\driver\optika_tank_driver.p3d";
		memoryPointDriverOptics = "driverview";
		radarType = 0;
		driveropticseffect[] = {"TankCommanderOptics1"};
		class ViewOptics
		{
			initFov = 0.7;
			minFov = 0.7;
			maxFov = 0.7;
			initAngleX = 0;
			minAngleX = -110;
			maxAngleX = 110;
			initAngleY = 0;
			minAngleY = -110;
			maxAngleY = 110;
			opticsZoomMin = 0.7;
			opticsZoomMax = 0.7;
			distanceZoomMin = 20;
			distanceZoomMax = 2000;
			visionMode[] = {"Normal","NVG"};
		};
		class ViewPilot
		{
			initAngleX = 10;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 20;
			minAngleY = -150;
			maxAngleY = 150;
			initFov = 0.7;
			minFov = 0.25;
			maxFov = 1.4;
		};
		driverAction = "rhs_btr70_driver";
		driverInAction = "rhs_btr70_driver";
		cargoAction[] = {"BRDM2_Cargo01","BRDM2_Cargo01","BRDM2_Cargo01","BRDM2_Cargo01","BRDM2_Cargo01","BRDM2_Cargo01","BRDM2_Cargo01","BRDM2_Cargo01"};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex\addons\c_veh_btr70\btr_main.rvmat","x\acex\addons\c_veh_btr70\btr_main_damage.rvmat","x\acex\addons\c_veh_btr70\btr_main_destruct.rvmat","x\acex\addons\c_veh_btr70\btr_main2.rvmat","x\acex\addons\c_veh_btr70\btr_main2_damage.rvmat","x\acex\addons\c_veh_btr70\btr_main2_destruct.rvmat","x\acex\addons\c_veh_btr70\btr_in.rvmat","x\acex\addons\c_veh_btr70\btr_in.rvmat","x\acex\addons\c_veh_btr70\btr_in_destruct.rvmat","ca\wheeled_e\Data\auta_skla.rvmat","ca\wheeled_e\Data\auta_skla_damage.rvmat","ca\wheeled_e\Data\auta_skla_damage.rvmat","ca\wheeled_e\Data\auta_skla_in.rvmat","ca\wheeled_e\Data\auta_skla_in_damage.rvmat","ca\wheeled_e\Data\auta_skla_in_damage.rvmat"};
		};
		hiddenSelections[] = {"camo1","camo2","i1","i2","i3","i4","i5","i6","i7","n1","n2","n3","n4","n5","n6","n7","n8","n9","n10","n11","i8","i9"};
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_btr70\btr70_tak_1_co.paa","\x\acex\addons\t_veh_btr70\btr70_tak_2_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
		class UserActions
		{
			class openDriverViewHatch
			{
				displayName = "$STR_ACE_UA_OpenShield";
				position = "";
				radius = 5;
				showWindow = 0;
				condition = "(player == driver this) && {(this animationPhase 'driverViewHatch' < 0.5)}";
				statement = "this animate['driverViewHatch',1];";
				onlyForPlayer = "true";
			};
			class closeDriverViewHatch
			{
				displayName = "$STR_ACE_UA_CloseShield";
				position = "";
				radius = 5;
				showWindow = 0;
				condition = "(player == driver this) && {(this animationPhase 'driverViewHatch' > 0.5)}";
				statement = "this animate['driverViewHatch',0];";
				onlyForPlayer = "true";
			};
			class openCommanderViewHatch
			{
				displayName = "$STR_ACE_UA_OpenShield";
				position = "";
				radius = 5;
				showWindow = 0;
				condition = "((this turretUnit [1]) == player) && {(this animationPhase 'commanderViewHatch' < 0.5)}";
				statement = "this animate['commanderViewHatch',1];";
				onlyForPlayer = "true";
			};
			class closeCommanderViewHatch
			{
				displayName = "$STR_ACE_UA_CloseShield";
				position = "";
				radius = 5;
				showWindow = 0;
				condition = "((this turretUnit [1]) == player) && {(this animationPhase 'commanderViewHatch' > 0.5)}";
				statement = "this animate['commanderViewHatch',0];";
				onlyForPlayer = "true";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				radarType = 0;
				weapons[] = {"KPVT","PKT_veh"};
				magazines[] = {"ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","ACE_50Rnd_145x114_KPVT","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				minElev = -5;
				maxElev = 30;
				gunnerAction = "rhs_btr70_gunner";
				gunnerInAction = "rhs_btr70_gunner";
				LODTurnedIn = 0;
				LODTurnedOut = 0;
				gunnerOutOpticsModel = "";
				selectionFireAnim = "zasleh1";
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\pp61";
				gunnerOpticsColor[] = {1,1,1,1};
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class GunFire: WeaponCloudsMGun
				{
					interval = 0.01;
				};
			};
			class CommanderTurret: CommanderTurret
			{
				LODTurnedIn = 1100;
				animationSourceHatch = "commanderHatch";
				outGunnerMayFire = 1;
				minElev = -5;
				maxElev = 10;
				minTurn = -36;
				maxTurn = 36;
				commanding = 1;
				viewGunnerInExternal = 1;
				radarType = 0;
				gunnerOpticsModel = "\x\acex\addons\m_veh_btr70\sights\sa_TKN3_sight";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOutOpticsColor[] = {1,1,1,1};
				memoryPointGunnerOutOptics = "obsView_out";
				memoryPointGunnerOptics = "obsView";
				gunnerUsesPilotView = 1;
				class ViewGunner
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					opticsZoomMin = 0.14;
					opticsZoomMax = 0.14;
					initFov = 0.14;
					minFov = 0.14;
					maxFov = 0.14;
					visionMode[] = {"Normal","NVG"};
				};
				gunnerAction = "rhs_btr70_commander";
				gunnerInAction = "rhs_btr70_commander";
			};
		};
		ace_minimalhit[] = {13,30};
		ace_era = 0;
		ace_p_detonation_hull = 0.2;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0;
		ace_p_fire_hull = 0.7;
		ace_p_fire_turret = 0.7;
		ace_p_fire_engine = 0.7;
		ace_p_firedetonation = 0.5;
		ace_armor_hull[] = {{9,9},{7,7},{7,7},{7,7},{5,5}};
		ace_armor_turret[] = {{10,10},{7,7},{7,7},{7,7},{7,7}};
	};
	class ACE_BTR70_TK: ACE_BTR70_Base
	{
		scope = 2;
		accuracy = 0.5;
	};
	class ACE_BTR70_UN: ACE_BTR70_Base
	{
		scope = 2;
		accuracy = 0.5;
		side = 2;
		faction = "BIS_UN";
		crew = "UN_CDF_Soldier_Crew_EP1";
		typicalCargo[] = {"UN_CDF_Soldier_Crew_EP1","UN_CDF_Soldier_Crew_EP1"};
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_btr70\btr70_UN_1_co.paa","\x\acex\addons\t_veh_btr70\btr70_UN_2_co.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa","RHS_Decals\Data\Labels\Misc\no_ca.paa"};
	};
};
class CfgGroups
{
	class East
	{
		class BIS_TK
		{
			class Mechanized
			{
				class ACE_TK_Mechanized_Squad_BTR70
				{
					name = "$STR_ACE_GDN_ACE_TK_MECHANIZED_SQUAD_BTR70";
					faction = "BIS_TK";
					rarityGroup = 0.9;
					class Unit0
					{
						side = 0;
						vehicle = "TK_Soldier_SL_EP1";
						rank = "LIEUTENANT";
						position[] = {3,5,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_BTR70_TK";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "TK_Soldier_MG_EP1";
						rank = "SERGEANT";
						position[] = {5,0,0};
					};
					class Unit3
					{
						side = 0;
						vehicle = "TK_Soldier_GL_EP1";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit4
					{
						side = 0;
						vehicle = "TK_Soldier_AT_EP1";
						rank = "CORPORAL";
						position[] = {9,0,0};
					};
					class Unit5
					{
						side = 0;
						vehicle = "TK_Soldier_MG_EP1";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit6
					{
						side = 0;
						vehicle = "TK_Soldier_GL_EP1";
						rank = "SERGEANT";
						position[] = {13,0,0};
					};
					class Unit7
					{
						side = 0;
						vehicle = "TK_Soldier_LAT_EP1";
						rank = "CORPORAL";
						position[] = {15,0,0};
					};
					class Unit8
					{
						side = 0;
						vehicle = "TK_Soldier_EP1";
						rank = "CORPORAL";
						position[] = {17,0,0};
					};
				};
				class TK_MechanizedSpecialSquad
				{
					class Unit1
					{
						vehicle = "ACE_BTR70_TK";
					};
				};
			};
		};
	};
	class Guerrila
	{
		class BIS_UN
		{
			class Mechanized
			{
				class ACE_UN_Mechanized_Patrol_BTR70
				{
					name = "$STR_ACE_GDN_ACE_UN_MECHANIZED_PATROL_BTR70";
					faction = "BIS_UN";
					rarityGroup = 0.5;
					class Unit0
					{
						side = 2;
						vehicle = "UN_CDF_Soldier_SL_EP1";
						rank = "SERGEANT";
						position[] = {0,5,0};
					};
					class Unit1
					{
						side = 2;
						vehicle = "ACE_BTR70_UN";
						rank = "SERGEANT";
						position[] = {-5,0,0};
					};
					class Unit2
					{
						side = 2;
						vehicle = "UN_CDF_Soldier_AT_EP1";
						rank = "CORPORAL";
						position[] = {3,0,0};
					};
					class Unit3
					{
						side = 2;
						vehicle = "UN_CDF_Soldier_MG_EP1";
						rank = "CORPORAL";
						position[] = {5,0,0};
					};
					class Unit4
					{
						side = 2;
						vehicle = "UN_CDF_Soldier_MG_EP1";
						rank = "CORPORAL";
						position[] = {7,0,0};
					};
					class Unit5
					{
						side = 2;
						vehicle = "UN_CDF_Soldier_EP1";
						rank = "PRIVATE";
						position[] = {9,0,0};
					};
					class Unit6
					{
						side = 2;
						vehicle = "UN_CDF_Soldier_EP1";
						rank = "PRIVATE";
						position[] = {11,0,0};
					};
					class Unit7
					{
						side = 2;
						vehicle = "UN_CDF_Soldier_EP1";
						rank = "PRIVATE";
						position[] = {13,0,0};
					};
				};
			};
		};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		rhs_btr70_driver = "rhs_btr70_driver";
		rhs_btr70_gunner = "rhs_btr70_gunner";
		rhs_btr70_commander = "rhs_btr70_commander";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class rhs_btr70_driver: Crew
		{
			file = "\x\acex\addons\c_veh_btr70\anims\driver.rtm";
			interpolateTo[] = {"rhs_btr70_KIA_driver",1};
		};
		class rhs_btr70_gunner: Crew
		{
			file = "\x\acex\addons\c_veh_btr70\anims\gunner.rtm";
			interpolateTo[] = {"rhs_btr70_KIA_gunner",1};
		};
		class rhs_btr70_commander: Crew
		{
			file = "\x\acex\addons\c_veh_btr70\anims\commander.rtm";
			interpolateTo[] = {"rhs_btr70_KIA_commander",1};
		};
		class rhs_btr70_commander_out: Crew
		{
			file = "\x\acex\addons\c_veh_btr70\anims\commanderout.rtm";
			interpolateTo[] = {"rhs_btr70_KIA_commander_out",1};
		};
		class rhs_btr70_KIA_driver: DefaultDie
		{
			actions = "DeadActions";
			file = "\x\acex\addons\c_veh_btr70\anims\driver.rtm";
			speed = 0.5;
			terminal = 1;
			soundEnabled = 0;
			looped = 1;
			connectTo[] = {"DeadState",0.1};
		};
		class rhs_btr70_KIA_gunner: DefaultDie
		{
			actions = "DeadActions";
			file = "\x\acex\addons\c_veh_btr70\anims\gunner.rtm";
			speed = 0.5;
			looped = 1;
			terminal = 1;
			connectTo[] = {"DeadState",0.1};
			soundEnabled = 0;
		};
		class rhs_btr70_KIA_commander: DefaultDie
		{
			actions = "DeadActions";
			file = "\x\acex\addons\c_veh_btr70\anims\commander.rtm";
			speed = 0.5;
			looped = 1;
			terminal = 1;
			connectTo[] = {"DeadState",0.1};
			soundEnabled = 0;
		};
		class rhs_btr70_KIA_commander_out: DefaultDie
		{
			actions = "DeadActions";
			file = "\x\acex\addons\c_veh_btr70\anims\commanderout.rtm";
			speed = 0.5;
			looped = 1;
			terminal = 1;
			connectTo[] = {"DeadState",0.1};
			soundEnabled = 0;
		};
	};
};
//};
