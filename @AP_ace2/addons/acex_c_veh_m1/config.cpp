////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jul 28 13:16:33 2012 : Created on Sat Jul 28 13:16:33 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_m1 : config.bin{
class CfgPatches
{
	class acex_veh_m1
	{
		Units[] = {"M1A1","M1A1_base","M1A1_US_DES_EP1","ACE_M1A1HC_DESERT","ACE_M1A1_NATO","ACE_M1A1HC_TUSK","ACE_M1A1HC_TUSK_DESERT","ACE_M1A1HA_TUSK","ACE_M1A1HA_TUSK_DESERT","ACE_M1A1HC_TUSK_CSAMM","ACE_M1A1HC_TUSK_CSAMM_DESERT","ACE_M1A1HA_TUSK_CSAMM","ACE_M1A1HA_TUSK_CSAMM_DESERT"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_c_vehicle","Extended_EventHandlers","CATracked","CAWeapons","CA_Anims","CAData"};
		version = "1.13.0.364";
		author[] = {"Mateck","Aushilfe","King Homer"};
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		ACE_Abrams_CommanderOut = "ACE_Abrams_CommanderOut";
		ACE_Abrams_LoaderOut = "ACE_Abrams_LoaderOut";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class KIA_Abrams_Commander: DefaultDie{};
		class Abrams_Commander: Crew{};
		class ACE_Abrams_CommanderOut: Abrams_Commander
		{
			file = "\x\acex\addons\c_veh_m1\anim\ACE_Abrams_CommanderOut.rtm";
			interpolateTo[] = {"KIA_Abrams_Commander",1};
		};
		class ACE_Abrams_LoaderOut: Abrams_Commander
		{
			file = "\x\acex\addons\c_veh_m1\anim\ACE_Abrams_LoaderOut.rtm";
			interpolateTo[] = {"KIA_Abrams_Commander",1};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	acex_veh_m1 = "acex_veh_m1= false; acex_veh_m1_fnc_init= ('\x\acex\addons\c_veh_m1\scripts\init.sqf' call SLX_XEH_COMPILE); acex_veh_m1= true";
};
class Extended_Init_EventHandlers
{
	class M1A1
	{
		acex_veh_m1 = "_this call acex_veh_m1_fnc_init;";
	};
};
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class NewTurret;
		class ViewOptics;
	};
	class Tank: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets
				{
					class CommanderOptics: NewTurret{};
				};
			};
		};
		class HitPoints;
		class ViewOptics: ViewOptics{};
	};
	class M1A1: Tank
	{
		model = "\x\acex\addons\m_veh_m1\ace_m1a1hc.p3d";
		icon = "\x\acex\addons\c_veh_m1\data\icon\icomap_m1a1_hc_ca.paa";
		typicalCargo[] = {"USMC_Soldier_Crew","USMC_Soldier_Crew","USMC_Soldier_Crew","USMC_Soldier_Crew"};
		driverOutOpticsModel = "";
		driverAction = "Abrams_DriverOut";
		driverInAction = "Abrams_Driver";
		driverCompartments = 0;
		castDriverShadow = 0;
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","n1","n2","t1","t2","t3_l","t3_r","t4","t5","clan_sign"};
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\nato\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_track_co.paa"};
		tracksSpeed = 0.522;
		wheelCircumference = 1.954;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				soundServo[] = {"\x\acex\addons\s_veh_m1\Data\Sound\M1A1_turret",0.005623,0.9,30};
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner.p3d";
				gunnerOutOpticsModel = "";
				gunnerOpticsColor[] = {1,0,0,1};
				gunnerForceOptics = 1;
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_commander.p3d";
						gunnerCompartments = 1;
						LODTurnedOut = 1000;
						gunnerOutFireAlsoInInternalCamera = 1;
						gunnerOutOpticsShowCursor = 0;
						gunnerOpticsShowCursor = 0;
						gunnerAction = "ACE_Abrams_CommanderOut";
						gunnerForceOptics = 1;
					};
					class LoaderTurret: NewTurret
					{
						ACE_exposed = "false";
						gunnerCompartments = 1;
						LODTurnedOut = 1000;
						weapons[] = {"ACE_M240_veh_out"};
						magazines[] = {"ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240"};
						gunnerAction = "ACE_Abrams_LoaderOut";
						gunnerInAction = "Abrams_Gunner";
						gunnerOpticsModel = "CA\Tracked_E\driverOptics";
						gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
						gunnerOpticsColor[] = {1,1,1,1};
						gunBeg = "loader_muzzle";
						gunEnd = "loader_chamber";
						viewGunnerInExternal = 0;
						proxyType = "CPGunner";
						proxyIndex = 2;
						gunnerName = "$STR_GN_M1A2_LoaderTurret";
						primaryGunner = 0;
						primaryObserver = 0;
						hasGunner = 1;
						body = "LoaderTurret";
						gun = "LoaderGun";
						animationSourceBody = "LoaderTurret";
						animationSourceGun = "LoaderGun";
						animationSourceHatch = "hatchLoader";
						minElev = -25;
						maxElev = 60;
						initElev = -10;
						minTurn = -30;
						maxTurn = 180;
						initTurn = 145;
						commanding = -1;
						outGunnerMayFire = 1;
						inGunnerMayFire = 0;
						gunnerFireAlsoInInternalCamera = 0;
						gunnerOutForceOptics = 0;
						gunnerOutOpticsShowCursor = 0;
						gunnerForceOptics = 1;
						memoryPointGunnerOutOptics = "loader_weapon_view";
						memoryPointGunnerOptics = "loaderview";
						memoryPointsGetInGunner = "pos driver";
						memoryPointsGetInGunnerDir = "pos driver dir";
						memoryPointGun = "loaderPointGun";
						selectionFireAnim = "zasleh_2";
						castGunnerShadow = 0;
						stabilizedInAxes = "StabilizedInAxesNone";
						gunnerGetInAction = "GetInMedium";
						gunnerGetOutAction = "GetOutMedium";
						startEngine = 0;
						turretInfoType = "RscWeaponEmpty";
						class ViewOptics
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = 0.33333;
							minFov = 0.33333;
							maxFov = 0.33333;
						};
						class ViewGunner
						{
							initAngleX = 0;
							minAngleX = -30;
							maxAngleX = 30;
							initAngleY = 0;
							minAngleY = -100;
							maxAngleY = 100;
							initFov = "0.33333+ 0.41667";
							minFov = 0.33333;
							maxFov = "0.33333+ 0.41667";
						};
						class HitPoints{};
					};
				};
			};
		};
		class AnimationSources
		{
			class baseclass_hide
			{
				animPeriod = 0;
				initPhase = 0;
			};
			class t_stuff_hide: baseclass_hide{};
			class t_stuff_ammo1_hide: baseclass_hide{};
			class t_stuff_ammo2_hide: baseclass_hide{};
			class t_stuff_ammo3_hide: baseclass_hide{};
			class t_stuff_bag1_hide: baseclass_hide{};
			class t_stuff_bag2_hide: baseclass_hide{};
			class t_stuff_bag3_hide: baseclass_hide{};
			class t_stuff_bag4_hide: baseclass_hide{};
			class t_stuff_kolo1_hide: baseclass_hide{};
			class t_stuff_kolo2_hide: baseclass_hide{};
			class t_stuff_kolo3_hide: baseclass_hide{};
			class t_stuff_wor1_hide: baseclass_hide{};
			class t_stuff_wor2_hide: baseclass_hide{};
			class panc1_hide: baseclass_hide{};
			class panc2_hide: baseclass_hide{};
			class panc3_hide: baseclass_hide{};
			class panc4_hide: baseclass_hide{};
			class smk0_1_hide: baseclass_hide{};
			class smk0_2_hide: baseclass_hide{};
			class smk0_3_hide: baseclass_hide{};
			class smk0_4_hide: baseclass_hide{};
			class smk1_1_hide: baseclass_hide{};
			class smk1_2_hide: baseclass_hide{};
			class smk1_3_hide: baseclass_hide{};
			class smk1_4_hide: baseclass_hide{};
			class smk_m257_l_up_hide: baseclass_hide{};
			class smk_m257_l_dn_hide: baseclass_hide{};
			class smk_m257_r_up_hide: baseclass_hide{};
			class smk_m257_r_dn_hide: baseclass_hide{};
			class recoil_main
			{
				source = "reload";
				weapon = "M256";
			};
			class reloadMagazine_m2
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class belt_m2_rotation
			{
				source = "reload";
				weapon = "M2";
			};
			class revolving_m2
			{
				source = "revolving";
				weapon = "M2";
			};
			class recoil_m240
			{
				source = "reload";
				weapon = "ACE_M240_veh_out";
			};
			class reloadMagazine_m240
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_veh_out";
			};
			class belt_m240_rotation
			{
				source = "reload";
				weapon = "ACE_M240_veh_out";
			};
			class revolving_m240
			{
				source = "revolving";
				weapon = "ACE_M240_veh_out";
			};
		};
		smokeLauncherGrenadeCount = 6;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 1;
		smokeLauncherAngle = 120;
		soundGetIn[] = {"\x\acex\addons\s_veh_m1\Data\Sound\HATCHCLSD",0.562341,1};
		soundGetOut[] = {"\x\acex\addons\s_veh_m1\Data\Sound\HATCHCOPN",0.562341,1,50};
		ACE_NBC_Protection = 1;
	};
	class M1A1_base: M1A1{};
	class M1A1_US_DES_EP1: M1A1_base
	{
		model = "\x\acex\addons\m_veh_m1\ace_m1a1_tusk.p3d";
		displayName = "M1A1";
		displayNameShort = "M1A1";
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","n1","n2","t1","t2","t3_l","t3_r","t4","t5_notusedhere","clan_sign","mineprotection","cmg_thermal","loader_armour","loader_tws","arat1_l","arat1_r","csamm","smk_hc"};
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\desert\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_track_co.paa"};
		icon = "\x\acex\addons\c_veh_m1\data\icon\icomap_m1a1_hc_ca.paa";
		tracksSpeed = 0.522;
		wheelCircumference = 1.954;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M256","M240_veh"};
				magazines[] = {"ACE_25Rnd_120mmSABOT_M1A2","ACE_15Rnd_120mmHE_M1A2","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240"};
				gunnerCompartments = 1;
				soundServo[] = {"\x\acex\addons\s_veh_m1\Data\Sound\M1A1_turret",0.005623,0.9,30};
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner.p3d";
				gunnerOutOpticsModel = "";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerForceOptics = 1;
				selectionFireAnim = "coax_muzzleflash";
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerCompartments = 1;
						LODTurnedOut = 1000;
						gunnerOutFireAlsoInInternalCamera = 1;
						gunnerOutOpticsShowCursor = 0;
						gunnerOpticsShowCursor = 0;
						gunnerAction = "ACE_Abrams_CommanderOut";
						gunnerForceOptics = 1;
						selectionFireAnim = "cmg_muzzleflash";
						body = "COmmanderTurret";
						gun = "CommanderGun";
					};
					class LoaderTurret: LoaderTurret
					{
						LODTurnedOut = 1000;
						weapons[] = {"ACE_M240_veh_out"};
						magazines[] = {"ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240"};
						gunnerAction = "ACE_Abrams_LoaderOut";
						gunnerInAction = "Abrams_Gunner";
						gunnerOpticsModel = "CA\Tracked_E\driverOptics";
						gunnerOutOpticsModel = "\ca\Weapons\optika_empty";
						selectionFireAnim = "lmg_muzzleflash";
					};
				};
			};
		};
		class AnimationSources
		{
			class baseclass_hide
			{
				animPeriod = 0;
				initPhase = 0;
			};
			class t_stuff_hide: baseclass_hide{};
			class t_stuff_ammo1_hide: baseclass_hide{};
			class t_stuff_ammo2_hide: baseclass_hide{};
			class t_stuff_ammo3_hide: baseclass_hide{};
			class t_stuff_bag1_hide: baseclass_hide{};
			class t_stuff_bag2_hide: baseclass_hide{};
			class t_stuff_bag3_hide: baseclass_hide{};
			class t_stuff_bag4_hide: baseclass_hide{};
			class t_stuff_kolo1_hide: baseclass_hide{};
			class t_stuff_kolo2_hide: baseclass_hide{};
			class t_stuff_kolo3_hide: baseclass_hide{};
			class t_stuff_wor1_hide: baseclass_hide{};
			class t_stuff_wor2_hide: baseclass_hide{};
			class panc1_hide: baseclass_hide{};
			class panc2_hide: baseclass_hide{};
			class panc3_hide: baseclass_hide{};
			class panc4_hide: baseclass_hide{};
			class recoil_maingun
			{
				source = "reload";
				weapon = "M256";
			};
			class CSAMM_reloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M2_CSAMM";
			};
			class CSAMM_belt_rotation
			{
				source = "reload";
				weapon = "ACE_M2_CSAMM";
			};
			class CSAMM_revolving
			{
				source = "revolving";
				weapon = "ACE_M2_CSAMM";
			};
			class CMG_reloadMagazine
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class CMG_belt_rotation
			{
				source = "reload";
				weapon = "M2";
			};
			class CMG_revolving
			{
				source = "revolving";
				weapon = "M2";
			};
			class LMG_reloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_veh_out";
			};
			class LMG_belt_rotation
			{
				source = "reload";
				weapon = "ACE_M240_veh_out";
			};
			class LMG_revolving
			{
				source = "revolving";
				weapon = "ACE_M240_veh_out";
			};
			class HitLTrack
			{
				source = "Hit";
				hitpoint = "HitLTrack";
				raw = 1;
			};
			class HitRTrack
			{
				source = "Hit";
				hitpoint = "HitRTrack";
				raw = 1;
			};
			class HitHull
			{
				source = "Hit";
				hitpoint = "HitHull";
				raw = 1;
			};
			class HitTurret
			{
				source = "Hit";
				hitpoint = "HitTurret";
				raw = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"Ca\Tracked_E\M1_Abrams\Data\m1_abrams_01_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_01_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_01_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_02_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_02_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_02_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_03_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_03_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_03_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_track_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_track_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_track_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1abrams_mg_mount.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1abrams_mg_mount_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","Ca\wheeled_e\stryker\Data\m2_damage.rvmat","Ca\wheeled_e\stryker\Data\m2_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1a2_loader.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1a2_loader_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1a2_loader_destruct.rvmat","ca\weapons_e\m240\Data\m240.rvmat","ca\weapons\Data\m240_damage.rvmat","ca\weapons\Data\m240_destruct.rvmat","x\acex\addons\c_veh_m1\ace_tusk_stuff.rvmat","x\acex\addons\c_veh_m1\ace_tusk_stuff_damage.rvmat","x\acex\addons\c_veh_m1\ace_tusk_stuff_destruct.rvmat","x\acex\addons\c_veh_m1\m1_abrams_04_metal.rvmat","x\acex\addons\c_veh_m1\m1_abrams_04_metal_damage.rvmat","x\acex\addons\c_veh_m1\m1_abrams_04_metal_destruct.rvmat","x\acex\addons\c_veh_m1\m1_abrams_03_metal_turret.rvmat","x\acex\addons\c_veh_m1\m1_abrams_03_metal_turret_damage.rvmat","x\acex\addons\c_veh_m1\m1_abrams_03_metal_turret_destruct.rvmat"};
		};
	};
	class ACE_M1A1_NATO: M1A1_US_DES_EP1
	{
		vehicleclass = "ArmouredW";
		displayName = "M1A1";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\nato\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_track_co.paa"};
	};
	class ACE_M1A1HC_DESERT: M1A1
	{
		vehicleclass = "ArmouredD";
		displayName = "M1A1";
		crew = "USMC_Soldier_Crew";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\desert\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_track_co.paa"};
	};
	class ACE_M1A1HC_TUSK: M1A1
	{
		ace_era = 1;
		ace_era_hull[] = {{0,0},{150,400},{150,400},{0,0},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0,0.8,0.8,0,0};
		ace_era_blocks_hull[] = {0,16,16,0,0};
		ace_era_turret[] = {{0,0},{0,0},{0,0},{0,0},{0,0}};
		ace_era_coverage_turret[] = {0,0,0,0,0};
		ace_era_blocks_turret[] = {0,0,0,0,0};
		displayName = "M1A1 TUSK";
		model = "\x\acex\addons\m_veh_m1\ace_m1a1_tusk.p3d";
		icon = "\x\acex\addons\c_veh_m1\data\icon\icomap_m1a1_hc_ca.paa";
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","n1","n2","t1","t2","t3_l","t3_r","t4","t5","smk_ha","clan_sign","csamm"};
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\nato\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\nato\m1abrams_track_co.paa","\x\acex\addons\t_veh_m1\nato\ace_tusk_stuff_co.paa"};
		tracksSpeed = 0.522;
		wheelCircumference = 1.954;
		maxSpeed = 45;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M256","M240_veh"};
				magazines[] = {"ACE_25Rnd_120mmSABOT_M1A2","ACE_15Rnd_120mmHE_M1A2","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240"};
				gunnerCompartments = 1;
				soundServo[] = {"\x\acex\addons\s_veh_m1\Data\Sound\M1A1_turret",0.005623,0.9,30};
				gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_M1A1_gunner.p3d";
				gunnerOutOpticsModel = "";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerForceOptics = 1;
				selectionFireAnim = "coax_muzzleflash";
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerCompartments = 1;
						LODTurnedOut = 1000;
						gunnerOutFireAlsoInInternalCamera = 1;
						gunnerOutOpticsShowCursor = 0;
						gunnerOpticsShowCursor = 0;
						gunnerAction = "ACE_Abrams_CommanderOut";
						gunnerForceOptics = 1;
						selectionFireAnim = "cmg_muzzleflash";
						body = "COmmanderTurret";
						gun = "CommanderGun";
					};
					class LoaderTurret: LoaderTurret
					{
						LODTurnedOut = 1000;
						weapons[] = {"ACE_M240_veh_out"};
						magazines[] = {"ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240","ACE_200Rnd_762x51_M240"};
						gunnerAction = "ACE_Abrams_LoaderOut";
						gunnerInAction = "Abrams_Gunner";
						memoryPointGunnerOptics = "loader_weapon_view";
						gunnerOutOpticsModel = "\Ca\weapons_E\MWTS_optic";
						selectionFireAnim = "lmg_muzzleflash";
						class opticsIn
						{
							class MTWS_Monocular_Wide
							{
								initAngleX = 0;
								minAngleX = -30;
								maxAngleX = 30;
								initAngleY = 0;
								minAngleY = -100;
								maxAngleY = 100;
								initFov = "0.33333/ 2";
								minFov = "0.33333/ 2";
								maxFov = "0.33333/ 2";
								visionMode[] = {"Ti"};
								thermalMode[] = {0,1};
								gunnerOpticsModel = "\Ca\weapons_E\MWTS_optic";
								gunnerOpticsEffect[] = {};
							};
							class MTWS_Monocular_Narrow: MTWS_Monocular_Wide
							{
								initFov = "0.33333/ 6";
								minFov = "0.33333/ 6";
								maxFov = "0.33333/ 6";
							};
						};
					};
				};
			};
		};
		class AnimationSources
		{
			class baseclass_hide
			{
				animPeriod = 0;
				initPhase = 0;
			};
			class t_stuff_hide: baseclass_hide{};
			class t_stuff_ammo1_hide: baseclass_hide{};
			class t_stuff_ammo2_hide: baseclass_hide{};
			class t_stuff_ammo3_hide: baseclass_hide{};
			class t_stuff_bag1_hide: baseclass_hide{};
			class t_stuff_bag2_hide: baseclass_hide{};
			class t_stuff_bag3_hide: baseclass_hide{};
			class t_stuff_bag4_hide: baseclass_hide{};
			class t_stuff_kolo1_hide: baseclass_hide{};
			class t_stuff_kolo2_hide: baseclass_hide{};
			class t_stuff_kolo3_hide: baseclass_hide{};
			class t_stuff_wor1_hide: baseclass_hide{};
			class t_stuff_wor2_hide: baseclass_hide{};
			class panc1_hide: baseclass_hide{};
			class panc2_hide: baseclass_hide{};
			class panc3_hide: baseclass_hide{};
			class panc4_hide: baseclass_hide{};
			class recoil_maingun
			{
				source = "reload";
				weapon = "M256";
			};
			class CSAMM_reloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M2_CSAMM";
			};
			class CSAMM_belt_rotation
			{
				source = "reload";
				weapon = "ACE_M2_CSAMM";
			};
			class CSAMM_revolving
			{
				source = "revolving";
				weapon = "ACE_M2_CSAMM";
			};
			class CMG_reloadMagazine
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class CMG_belt_rotation
			{
				source = "reload";
				weapon = "M2";
			};
			class CMG_revolving
			{
				source = "revolving";
				weapon = "M2";
			};
			class LMG_reloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_M240_veh_out";
			};
			class LMG_belt_rotation
			{
				source = "reload";
				weapon = "ACE_M240_veh_out";
			};
			class LMG_revolving
			{
				source = "revolving";
				weapon = "ACE_M240_veh_out";
			};
			class HitLTrack
			{
				source = "Hit";
				hitpoint = "HitLTrack";
				raw = 1;
			};
			class HitRTrack
			{
				source = "Hit";
				hitpoint = "HitRTrack";
				raw = 1;
			};
			class HitHull
			{
				source = "Hit";
				hitpoint = "HitHull";
				raw = 1;
			};
			class HitTurret
			{
				source = "Hit";
				hitpoint = "HitTurret";
				raw = 1;
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"Ca\Tracked_E\M1_Abrams\Data\m1_abrams_01_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_01_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_01_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_02_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_02_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_02_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_03_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_03_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_03_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_track_metal.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_track_metal_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1_abrams_track_metal_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1abrams_mg_mount.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1abrams_mg_mount_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1abrams_mg_mount_destruct.rvmat","ca\weapons_e\m2\data\m2.rvmat","Ca\wheeled_e\stryker\Data\m2_damage.rvmat","Ca\wheeled_e\stryker\Data\m2_destruct.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1a2_loader.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1a2_loader_damage.rvmat","Ca\Tracked_E\M1_Abrams\Data\m1a2_loader_destruct.rvmat","ca\weapons_e\m240\Data\m240.rvmat","ca\weapons\Data\m240_damage.rvmat","ca\weapons\Data\m240_destruct.rvmat","x\acex\addons\c_veh_m1\ace_tusk_stuff.rvmat","x\acex\addons\c_veh_m1\ace_tusk_stuff_damage.rvmat","x\acex\addons\c_veh_m1\ace_tusk_stuff_destruct.rvmat","x\acex\addons\c_veh_m1\m1_abrams_04_metal.rvmat","x\acex\addons\c_veh_m1\m1_abrams_04_metal_damage.rvmat","x\acex\addons\c_veh_m1\m1_abrams_04_metal_destruct.rvmat","x\acex\addons\c_veh_m1\m1_abrams_03_metal_turret.rvmat","x\acex\addons\c_veh_m1\m1_abrams_03_metal_turret_damage.rvmat","x\acex\addons\c_veh_m1\m1_abrams_03_metal_turret_destruct.rvmat"};
		};
	};
	class ACE_M1A1HC_TUSK_DESERT: ACE_M1A1HC_TUSK
	{
		vehicleclass = "ArmouredD";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\desert\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_track_co.paa","\x\acex\addons\t_veh_m1\desert\ace_tusk_stuff_co.paa"};
	};
	class ACE_M1A1HA_TUSK: ACE_M1A1HC_TUSK
	{
		vehicleclass = "ArmouredW";
		scope = 2;
		displayName = "M1A1 TUSK";
		faction = "BIS_US";
		crew = "US_Soldier_Crew_EP1";
		typicalCargo[] = {"US_Soldier_Crew_EP1","US_Soldier_Crew_EP1","US_Soldier_Crew_EP1","US_Soldier_Crew_EP1"};
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","n1","n2","t1","t2","t3_l","t3_r","t4","t5_notusedhere","smk_hc","clan_sign","csamm"};
	};
	class ACE_M1A1HA_TUSK_DESERT: ACE_M1A1HA_TUSK
	{
		vehicleclass = "ArmouredD";
		displayName = "M1A1 TUSK";
		displayNameShort = "M1A1 TUSK";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\desert\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_track_co.paa","\x\acex\addons\t_veh_m1\desert\ace_tusk_stuff_co.paa"};
	};
	class ACE_M1A1HC_TUSK_CSAMM: ACE_M1A1HC_TUSK
	{
		displayName = "M1A1 TUSK CSAMM";
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","n1","n2","t1","t2","t3_l","t3_r","t4","t5","smk_ha","clan_sign"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M256","M240_veh","ACE_M2_CSAMM"};
				magazines[] = {"ACE_25Rnd_120mmSABOT_M1A2","ACE_15Rnd_120mmHE_M1A2","ACE_200Rnd_127x99_M2_SLAP","ACE_200Rnd_127x99_M2_SLAP","ACE_200Rnd_127x99_M2_SLAP","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240","1200Rnd_762x51_M240"};
			};
		};
		ace_tankfcs_maxranges[] = {"ACE_25Rnd_120mmSABOT_M1A2",4000,"ACE_30Rnd_120mmSABOT_M1A2",4000,"ACE_22Rnd_120mmSABOT_M1A2",4000,"20Rnd_120mmSABOT_M1A2",4000,"ACE_6Rnd_120mmHE_M1A2",4000,"ACE_8Rnd_120mmHE_M1A2",4000,"ACE_15Rnd_120mmHE_M1A2",4000,"20Rnd_120mmHE_M1A2",4000,"ACE_200Rnd_127x99_M2_SLAP",2000,"1200Rnd_762x51_M240",1800};
		ace_sa_enabled = 0;
	};
	class ACE_M1A1HC_TUSK_CSAMM_DESERT: ACE_M1A1HC_TUSK_CSAMM
	{
		vehicleclass = "ArmouredD";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\desert\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_track_co.paa","\x\acex\addons\t_veh_m1\desert\ace_tusk_stuff_co.paa"};
	};
	class ACE_M1A1HA_TUSK_CSAMM: ACE_M1A1HC_TUSK_CSAMM
	{
		vehicleclass = "ArmouredW";
		scope = 2;
		displayName = "M1A1 TUSK CSAMM";
		faction = "BIS_US";
		crew = "US_Soldier_Crew_EP1";
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4","Camo5","Camo6","n1","n2","t1","t2","t3_l","t3_r","t4","t5_notusedhere","smk_hc","clan_sign"};
	};
	class ACE_M1A1HA_TUSK_CSAMM_DESERT: ACE_M1A1HA_TUSK_CSAMM
	{
		vehicleclass = "ArmouredD";
		displayName = "M1A1 TUSK CSAMM";
		displayNameShort = "M1A1 TUSK CSAMM";
		hiddenSelectionsTextures[] = {"\x\acex\addons\t_veh_m1\desert\m1abrams_01_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_02_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_03_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_04_co.paa","\x\acex\addons\t_veh_m1\desert\m1abrams_track_co.paa","\x\acex\addons\t_veh_m1\desert\ace_tusk_stuff_co.paa"};
	};
	class M1A2_TUSK_MG: M1A1
	{
		scope = 2;
		faction = "BIS_US";
		crew = "US_Soldier_Crew_EP1";
		maxSpeed = 45;
	};
};
class CfgGroups
{
	class West
	{
		class BIS_US
		{
			class Armored
			{
				class ACE_US_M1A1_TUSK_Platoon
				{
					name = "$STR_ACE_GDN_ACE_US_M1A1_TUSK_PLATOON";
					faction = "BIS_US";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_DESERT";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_DESERT";
						rank = "LIEUTENANT";
						position[] = {5,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_DESERT";
						rank = "LIEUTENANT";
						position[] = {10,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_DESERT";
						rank = "LIEUTENANT";
						position[] = {15,0,0};
					};
				};
				class ACE_US_M1A1_TUSK_Section
				{
					name = "$STR_ACE_GDN_ACE_US_M1A1_TUSK_SECTION";
					faction = "BIS_US";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_DESERT";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_DESERT";
						rank = "LIEUTENANT";
						position[] = {5,0,0};
					};
				};
				class ACE_US_M1A1_TUSK_CSAMM_Section
				{
					name = "$STR_ACE_GDN_ACE_US_M1A1_TUSK_CSAMM_SECTION";
					faction = "BIS_US";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_CSAMM_DESERT";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_CSAMM_DESERT";
						rank = "LIEUTENANT";
						position[] = {5,0,0};
					};
				};
				class ACE_US_M1A1_TUSK_Platoon_WDL
				{
					name = "M1A1 TUSK Platoon (Woodland)";
					faction = "BIS_US";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK";
						rank = "LIEUTENANT";
						position[] = {5,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK";
						rank = "LIEUTENANT";
						position[] = {10,0,0};
					};
					class Unit3
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK";
						rank = "LIEUTENANT";
						position[] = {15,0,0};
					};
				};
				class ACE_US_M1A1_TUSK_Section_WDL
				{
					name = "M1A1 TUSK Section (Woodland)";
					faction = "BIS_US";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK";
						rank = "LIEUTENANT";
						position[] = {5,0,0};
					};
				};
				class ACE_US_M1A1_TUSK_CSAMM_Section_WDL
				{
					name = "M1A1 TUSK CSAMM Section (Woodland)";
					faction = "BIS_US";
					rarityGroup = 0.05;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_CSAMM";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_M1A1HA_TUSK_CSAMM";
						rank = "LIEUTENANT";
						position[] = {5,0,0};
					};
				};
			};
		};
	};
};
//};
