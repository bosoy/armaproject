////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Aug 03 19:48:48 2012 : Created on Fri Aug 03 19:48:48 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_t72 : config.bin{
class CfgPatches
{
	class acex_veh_t72
	{
		units[] = {"ACE_T72B_Base","ACE_T72B_RU","ACE_T72B_INS","ACE_T72B_CDF","ACE_T72B_Gue","ACE_T72BA_Base","ACE_T72BA_RU","ACE_T72BA_INS","ACE_T72BA_CDF","ACE_T72BA_Gue"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"acex_main","acex_m_veh_t72","acex_t_veh_t72","ace_c_vehicle","CATracked","CATracked_E"};
		version = "1.13.0.365";
		author[] = {"Dractyum","Aushilfe","King Homer","zGuba"};
	};
};
class CfgMovesBasic
{
	class ManActions
	{
		t72_mehvod_zalez = "t72_mehvod_zalez";
		t72_mehvod_vilez = "t72_mehvod_vilez";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInLow;
		class t72_mehvod_zalez: AmovPercMstpSnonWnonDnon_AcrgPknlMstpSnonWnonDnon_getInLow
		{
			file = "\x\acex\addons\c_veh_t72\anim\t72_mehvod_zalez";
			speed = 0.22;
			canPullTrigger = 0;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.02};
			InterpolateTo[] = {};
		};
		class t72_mehvod_vilez: t72_mehvod_zalez
		{
			file = "\x\acex\addons\c_veh_t72\anim\t72_mehvod_vilez";
			speed = 0.15;
			canPullTrigger = 0;
			ConnectTo[] = {"AmovPercMstpSnonWnonDnon",0.1};
			InterpolateTo[] = {};
		};
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
		class HitPoints;
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
		class ViewOptics: ViewOptics{};
	};
	class T72_Base: Tank
	{
		model = "x\acex\addons\m_veh_t72\ACE_T72A.p3d";
		forceHideDriver = 0;
		driverAction = "T90_DriverOut";
		driverInAction = "T90_Driver";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						weapons[] = {"ACE_NSVT","SmokeLauncher"};
						magazines[] = {"150Rnd_127x108_KORD","150Rnd_127x108_KORD","SmokeLauncherMag","SmokeLauncherMag"};
						gunnerAction = "Abrams_CommanderOUT";
						gunnerInAction = "Abrams_Commander";
					};
				};
			};
		};
		class AnimationSources
		{
			class ReloadAnim
			{
				source = "reload";
				weapon = "ACE_NSVT";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "ACE_NSVT";
			};
			class Revolving
			{
				source = "revolving";
				weapon = "ACE_NSVT";
			};
			class recoil_source
			{
				source = "reload";
				weapon = "ACE_2A46_1";
			};
			class turret_hide
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
		};
		hiddenSelections[] = {"camo1","camo2","camo3","n1","n2","n3","nt","nw"};
	};
	class T72_INS: T72_Base{};
	class ACE_T72B_Base: T72_INS
	{
		model = "x\acex\addons\m_veh_t72\ACE_T72B.p3d";
		picture = "\x\acex\addons\t_veh_t72\t72b_pic.paa";
		Icon = "\x\acex\addons\t_veh_t72\icomap_t72b_CA.paa";
		displayName = "T-72B";
		accuracy = 0.5;
		armor = 910;
		damageResistance = 0.00335;
		armorStructural = 3.5;
		driverCompartments = 0;
		irScanRangeMax = 4000;
		sensitivity = 2;
		class HitPoints: HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "motor";
				passThrough = 1;
			};
			class HitHull
			{
				armor = 1;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.59;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.59;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerCompartments = 1;
				gunnerOpticsEffect[] = {};
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.93;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				maxHorizontalRotSpeed = 0.42;
				maxVerticalRotSpeed = 0.09;
				weapons[] = {"ACE_2A46M_1","PKT"};
				magazines[] = {"23Rnd_125mmSABOT_T72","ACE_3BK29","ACE_8Rnd_3OF26","ACE_AT11","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				stabilizedInAxes = 3;
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						gunnerOpticsEffect[] = {};
						gunnerOutOpticsModel = "";
						gunnerOutOpticsEffect[] = {};
						initFov = "0.33333/ 1";
						minFov = "0.33333/ 1";
						maxFov = "0.33333/ 1";
						gunnerOpticsModel = "CA\Tracked_E\driverOptics";
						visionMode[] = {"Normal"};
					};
					class Narrow: Wide
					{
						initFov = "9/120";
						minFov = "9/120";
						maxFov = "9/120";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72B_TPDK1_optics";
						visionMode[] = {"Normal"};
					};
					class Night: Wide
					{
						initFov = "(9/120)*(8/5.5)";
						minFov = "(9/120)*(8/5.5)";
						maxFov = "(9/120)*(8/5.5)";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72B_TPN349_optics";
						visionMode[] = {"NVG"};
					};
				};
				class ViewOptics
				{
					initFov = "0.33333/ 5.5";
					minFov = "0.33333/ 8";
					maxFov = "0.33333/ 5.5";
				};
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						gunnerCompartments = 1;
						stabilizedInAxes = 3;
						maxVerticalRotSpeed = 0.42;
						maxHorizontalRotSpeed = 0.61;
						weapons[] = {"ACE_NSVT","SmokeLauncher"};
						magazines[] = {"150Rnd_127x108_KORD","150Rnd_127x108_KORD","SmokeLauncherMag","SmokeLauncherMag"};
						gunnerAction = "Abrams_CommanderOUT";
						gunnerInAction = "Abrams_Commander";
						class ViewOptics: ViewOptics
						{
							initFov = "0.33333/ 5";
							minFov = "0.33333/ 4.2";
							maxFov = "0.33333/ 5";
						};
						class OpticsIn
						{
							class Wide
							{
								initAngleX = 0;
								minAngleX = -30;
								maxAngleX = 30;
								initAngleY = 0;
								minAngleY = -100;
								maxAngleY = 100;
								gunnerOpticsEffect[] = {};
								gunnerOutOpticsModel = "";
								gunnerOutOpticsEffect[] = {};
								initFov = "0.33333/ 1";
								minFov = "0.33333/ 1";
								maxFov = "0.33333/ 1";
								gunnerOpticsModel = "CA\Tracked_E\driverOptics";
								visionMode[] = {"Normal"};
							};
							class Narrow: Wide
							{
								initFov = "10/120";
								minFov = "10/120";
								maxFov = "10/120";
								visionMode[] = {"Normal"};
								gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72_TKN3_day_optics";
							};
							class Night: Wide
							{
								initFov = "(10/120) * (5/4.2)";
								minFov = "(10/120) * (5/4.2)";
								maxFov = "(10/120) * (5/4.2)";
								gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72_TKN3_night_optics";
								visionMode[] = {"NVG"};
							};
						};
					};
				};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"Ca\Tracked_E\T72\data\t72_track.rvmat","Ca\Tracked_E\T72\data\t72_track_damage.rvmat","Ca\Tracked_E\T72\data\t72_track_destruct.rvmat","Ca\Tracked_E\T72\data\t72_1.rvmat","Ca\Tracked_E\T72\data\t72_1_damage.rvmat","Ca\Tracked_E\T72\data\t72_1_destruct.rvmat","Ca\Tracked_E\T72\data\t72_2.rvmat","Ca\Tracked_E\T72\data\t72_2_damage.rvmat","Ca\Tracked_E\T72\data\t72_2_destruct.rvmat","Ca\Tracked_E\T72\data\t72_3.rvmat","Ca\Tracked_E\T72\data\t72_3_damage.rvmat","Ca\Tracked_E\T72\data\t72_3_destruct.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default_destruct.rvmat","x\acex\addons\c_veh_t72\dz1.rvmat","x\acex\addons\c_veh_t72\dz1_damage.rvmat","x\acex\addons\c_veh_t72\dz1_destruct.rvmat"};
		};
		class AnimationSources: AnimationSources
		{
			class recoil_source: recoil_source
			{
				weapon = "ACE_2A46M_1";
			};
		};
		smokeLauncherGrenadeCount = 6;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 1;
		smokeLauncherAngle = 120;
		ace_minimalhit[] = {39,100};
		ace_era = 1;
		ace_p_detonation_hull = 0.8;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.8;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0.2;
		ace_armor_hull[] = {{365,540},{30,170},{30,170},{40,40},{40,40},{200,200}};
		ace_era_hull[] = {{120,370},{120,370},{120,370},{0,0},{0,0},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.5,0.5,0,0};
		ace_era_blocks_hull[] = {16,10,10,0,0};
		ace_armor_turret[] = {{430,470},{260,340},{260,340},{100,120},{40,40},{0,0}};
		ace_era_turret[] = {{120,370},{120,370},{120,370},{0,0},{120,370}};
		ace_era_coverage_turret[] = {0.9,0.5,0.5,0,0.3};
		ace_era_blocks_turret[] = {16,8,8,0,6};
		ace_tankfcs_maxranges[] = {"23Rnd_125mmSABOT_T72",3000,"ACE_8Rnd_3OF26",4000,"ACE_3BK29",3000,"250Rnd_762x54_PKT_T90",1600};
		ACE_NBC_Protection = 1;
		side = 0;
		faction = "RU";
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_ru_1_co.paa","\ca\tracked\data\T72_ru_2_co.paa","\ca\tracked\data\T72_ru_3_co.paa"};
	};
	class ACE_T72B_RU: ACE_T72B_Base
	{
		scope = 1;
	};
	class ACE_T72B_INS: ACE_T72B_Base
	{
		side = 0;
		faction = "INS";
		crew = "Ins_Soldier_Crew";
		typicalCargo[] = {"Ins_Soldier_Crew","Ins_Soldier_Crew","Ins_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_1_co.paa","\ca\tracked\data\T72_2_co.paa","\ca\tracked\data\T72_3_co.paa"};
		ACE_NBC_Protection = 0;
	};
	class ACE_T72B_CDF: ACE_T72B_Base
	{
		side = 1;
		faction = "CDF";
		crew = "CDF_Soldier_Crew";
		typicalCargo[] = {"CDF_Soldier_Crew","CDF_Soldier_Crew","CDF_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\t72blu_1_co.paa","\ca\tracked\data\t72blu_2_co.paa","\ca\tracked\data\t72blu_3_co.paa",""};
	};
	class ACE_T72B_Gue: ACE_T72B_Base
	{
		scope = 1;
		side = 2;
		faction = "GUE";
		crew = "GUE_Soldier_1";
		typicalCargo[] = {"GUE_Soldier_1","GUE_Soldier_1","GUE_Soldier_1"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_KHK_1_co.paa","\ca\tracked\data\T72_KHK_2_co.paa","\ca\tracked\data\T72_KHK_3_co.paa"};
		ACE_NBC_Protection = 0;
	};
	class ACE_T72BA_Base: ACE_T72B_Base
	{
		model = "x\acex\addons\m_veh_t72\ACE_T72BA.p3d";
		picture = "\x\acex\addons\t_veh_t72\t72ba_pic.paa";
		Icon = "\x\acex\addons\t_veh_t72\icomap_t72ba_CA.paa";
		mapSize = 9.5;
		displayName = "T-72BA";
		armor = 1320;
		armorStructural = 3;
		damageResistance = 0.00335;
		class HitPoints: HitPoints
		{
			class HitHull
			{
				armor = 0.75;
				material = -1;
				name = "telo";
				visual = "telo";
				passThrough = 0;
			};
			class HitLTrack
			{
				armor = 0.35;
				material = -1;
				name = "pas_L";
				visual = "pas_L";
				passThrough = 0;
			};
			class HitRTrack
			{
				armor = 0.35;
				material = -1;
				name = "pas_P";
				visual = "pas_P";
				passThrough = 0;
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				maxHorizontalRotSpeed = 0.42;
				maxVerticalRotSpeed = 0.09;
				weapons[] = {"ACE_2A46M_1","PKT"};
				magazines[] = {"23Rnd_125mmSABOT_T72","ACE_8Rnd_3OF26","ACE_3BK29","5Rnd_AT11_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90","250Rnd_762x54_PKT_T90"};
				class ViewOptics: ViewOptics
				{
					initFov = "0.33333/ 5.5";
					minFov = "0.33333/ 8";
					maxFov = "0.33333/ 5.5";
				};
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						gunnerOpticsEffect[] = {};
						gunnerOutOpticsModel = "";
						gunnerOutOpticsEffect[] = {};
						initFov = "0.33333/ 1";
						minFov = "0.33333/ 1";
						maxFov = "0.33333/ 1";
						gunnerOpticsModel = "CA\Tracked_E\driverOptics";
						visionMode[] = {"Normal"};
					};
					class Narrow: Wide
					{
						initFov = "9/120";
						minFov = "9/120";
						maxFov = "9/120";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72B_TPDK1_optics";
						visionMode[] = {"Normal"};
					};
					class Night: Wide
					{
						initFov = "(9/120)*(8/5.5)";
						minFov = "(9/120)*(8/5.5)";
						maxFov = "(9/120)*(8/5.5)";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\T72B_TPN349_optics";
						visionMode[] = {"NVG"};
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "vez";
						visual = "vez";
						passThrough = 0;
					};
					class HitGun
					{
						armor = 1;
						material = -1;
						name = "zbran";
						visual = "zbran";
						passThrough = 0;
					};
				};
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
						maxVerticalRotSpeed = 0.08;
						minElev = -5;
						maxElev = 80;
						class OpticsIn
						{
							class Wide
							{
								initAngleX = 0;
								minAngleX = -30;
								maxAngleX = 30;
								initAngleY = 0;
								minAngleY = -100;
								maxAngleY = 100;
								initFov = "0.33333/ 1";
								minFov = "0.33333/ 1";
								maxFov = "0.33333/ 1";
								visionMode[] = {"Normal"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_Metis.p3d";
								gunnerOpticsEffect[] = {};
								gunnerOutOpticsModel = "";
								gunnerOutOpticsEffect[] = {};
							};
							class Medium: Wide
							{
								initFov = "0.33333/ 8";
								minFov = "0.33333/ 8";
								maxFov = "0.33333/ 8";
								gunnerOpticsModel = "\ca\weapons\2Dscope_Metis.p3d";
							};
							class Narrow: Wide
							{
								initFov = "0.33333/ 5.3";
								minFov = "0.33333/ 5.3";
								maxFov = "0.33333/ 5.3";
								visionMode[] = {"NVG"};
								gunnerOpticsModel = "\ca\weapons\2Dscope_Metis.p3d";
							};
						};
						class ViewOptics
						{
							initFov = "0.33333/ 1";
							minFov = "0.33333/ 8";
							maxFov = "0.33333/ 1";
						};
					};
				};
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"Ca\Tracked_E\T72\data\t72_track.rvmat","Ca\Tracked_E\T72\data\t72_track_damage.rvmat","Ca\Tracked_E\T72\data\t72_track_destruct.rvmat","Ca\Tracked_E\T72\data\t72_1.rvmat","Ca\Tracked_E\T72\data\t72_1_damage.rvmat","Ca\Tracked_E\T72\data\t72_1_destruct.rvmat","Ca\Tracked_E\T72\data\t72_2.rvmat","Ca\Tracked_E\T72\data\t72_2_damage.rvmat","Ca\Tracked_E\T72\data\t72_2_destruct.rvmat","Ca\Tracked_E\T72\data\t72_3.rvmat","Ca\Tracked_E\T72\data\t72_3_damage.rvmat","Ca\Tracked_E\T72\data\t72_3_destruct.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default.rvmat","Ca\Ca_E\data\default_destruct.rvmat","x\acex\addons\c_veh_t72\dz1.rvmat","x\acex\addons\c_veh_t72\dz1_damage.rvmat","x\acex\addons\c_veh_t72\dz1_destruct.rvmat","x\acex\addons\c_veh_t72\dz5.rvmat","x\acex\addons\c_veh_t72\dz5_damage.rvmat","x\acex\addons\c_veh_t72\dz5_destruct.rvmat"};
		};
		class AnimationSources: AnimationSources
		{
			class recoil_source: recoil_source
			{
				weapon = "ACE_2A46M_1";
			};
		};
		ace_minimalhit[] = {39,100};
		ace_era = 1;
		ace_p_detonation_hull = 0.8;
		ace_p_detonation_turret = 0.2;
		ace_p_detonation_engine = 0.2;
		ace_p_fire_hull = 0.8;
		ace_p_fire_turret = 0.2;
		ace_p_fire_engine = 0.5;
		ace_p_firedetonation = 0.2;
		ace_armor_hull[] = {{510,540},{30,170},{30,170},{40,40},{40,40},{200,200}};
		ace_era_hull[] = {{200,450},{50,300},{50,300},{0,0},{50,300},{0,0}};
		ace_era_coverage_hull[] = {0.9,0.5,0.5,0,0};
		ace_era_blocks_hull[] = {8,5,5,0,0};
		ace_armor_turret[] = {{560,720},{260,340},{260,340},{100,120},{40,40}};
		ace_era_turret[] = {{250,600},{250,600},{250,600},{0,0},{50,300}};
		ace_era_coverage_turret[] = {0.9,0.3,0.3,0,0.3};
		ace_era_blocks_turret[] = {8,5,5,0,4};
		ace_tankfcs_enabled = 1;
		ace_tankfcs_maxlrfrange = 5000;
		ace_tankfcs_minlrfrange = 200;
		ace_tankfcs_lrfaccuracy = 10;
		ace_tankfcs_lrfcooldowntime = 3;
		ace_tankfcs_maxlead = 2;
		ace_tankfcs_battlesight = 1200;
		ace_tankfcs_digitscolor[] = {0.396,0.886,0.396,1};
		ace_tankfcs_digitsstyle = 1;
		ace_tankfcs_rdystyle = 1;
		ace_tankfcs_maxranges[] = {"23Rnd_125mmSABOT_T72",3000,"ACE_3BK29",3000,"ACE_8Rnd_3OF26",4000,"250Rnd_762x54_PKT_T90",1600};
		side = 0;
		faction = "RU";
		crew = "RU_Soldier_Crew";
		typicalCargo[] = {"RU_Soldier_Crew","RU_Soldier_Crew","RU_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_RU_1_CO.paa","\ca\tracked\data\T72_RU_2_CO.paa","\ca\tracked\data\T72_RU_3_CO.paa"};
	};
	class ACE_T72BA_RU: ACE_T72BA_Base
	{
		scope = 1;
	};
	class ACE_T72BA_INS: ACE_T72BA_Base
	{
		scope = 1;
		side = 0;
		faction = "INS";
		crew = "Ins_Soldier_Crew";
		typicalCargo[] = {"Ins_Soldier_Crew","Ins_Soldier_Crew","Ins_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_1_co.paa","\ca\tracked\data\T72_2_co.paa","\ca\tracked\data\T72_3_co.paa"};
		ACE_NBC_Protection = 0;
	};
	class ACE_T72BA_CDF: ACE_T72BA_Base
	{
		scope = 1;
		side = 1;
		faction = "CDF";
		crew = "CDF_Soldier_Crew";
		typicalCargo[] = {"CDF_Soldier_Crew","CDF_Soldier_Crew","CDF_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\t72blu_1_co.paa","\ca\tracked\data\t72blu_2_co.paa","\ca\tracked\data\t72blu_3_co.paa"};
	};
	class ACE_T72BA_Gue: ACE_T72BA_Base
	{
		scope = 1;
		side = 2;
		faction = "GUE";
		crew = "GUE_Soldier_1";
		typicalCargo[] = {"GUE_Soldier_1","GUE_Soldier_1","GUE_Soldier_1"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_KHK_1_co.paa","\ca\tracked\data\T72_KHK_2_co.paa","\ca\tracked\data\T72_KHK_3_co.paa"};
		ACE_NBC_Protection = 0;
	};
};
//};
