////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:52 2012 : Created on Fri Nov 09 22:39:52 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_t72 : config.bin{
class CfgPatches
{
	class acex_ru_veh_t72
	{
		units[] = {"ACE_T72B_RU","ACE_T72B_INS","ACE_T72B_CDF","ACE_T72B_Gue","ACE_T72BA_RU","ACE_T72BA_INS","ACE_T72BA_CDF","ACE_T72BA_Gue"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","acex_veh_t72","acex_m_veh_t72","acex_ru_t_veh_t72","ace_c_vehicle","CATracked"};
		version = "1.14.0.76";
		author[] = {"Dractyum"};
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
		class Sounds;
	};
	class T72_Base: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics{};
				};
			};
		};
	};
	class T72_INS: T72_Base{};
	class ACE_T72B_Base: T72_INS
	{
		hiddenSelections[] = {"camo1","camo2","camo3","camo4","n1","n2","n3","nt","nw"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_t72\t72_ru_1_co.paa","\x\acex_ru\addons\t_veh_t72\t72_ru_2_co.paa","\ca\tracked\data\T72_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_ru_co.paa"};
	};
	class ACE_T72B_RU: ACE_T72B_Base
	{
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_t72\t72_ru_1_co.paa","\x\acex_ru\addons\t_veh_t72\t72_ru_2_co.paa","\ca\tracked\data\T72_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_ru_co.paa"};
	};
	class ACE_T72B_INS: ACE_T72B_Base
	{
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_1_co.paa","\ca\tracked\data\T72_2_co.paa","\ca\tracked\data\T72_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_co.paa"};
	};
	class ACE_T72B_CDF: ACE_T72B_Base
	{
		hiddenSelectionsTextures[] = {"\ca\tracked\data\t72blu_1_co.paa","\ca\tracked\data\t72blu_2_co.paa","\ca\tracked\data\t72blu_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1blu_co.paa"};
	};
	class ACE_T72B_Gue: ACE_T72B_Base
	{
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_KHK_1_co.paa","\ca\tracked\data\T72_KHK_2_co.paa","\ca\tracked\data\T72_KHK_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_khk_co.paa"};
	};
	class ACE_T72BA_Base: ACE_T72B_Base
	{
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_t72\t72ba_ru_1_co.paa","\x\acex_ru\addons\t_veh_t72\t72_ru_2_co.paa","\ca\tracked\data\T72_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_ru_co.paa","\x\acex_ru\addons\t_veh_t72\dz5_ru_co.paa"};
	};
	class ACE_T72BA_RU: ACE_T72BA_Base
	{
		hiddenSelections[] = {"camo1","camo2","camo3","camo4","camo5","n1","n2","n3","nt","nw"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_t72\t72ba_ru_1_co.paa","\x\acex_ru\addons\t_veh_t72\t72_ru_2_co.paa","\ca\tracked\data\T72_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_ru_co.paa","\x\acex_ru\addons\t_veh_t72\dz5_ru_co.paa"};
	};
	class ACE_T72BA_INS: ACE_T72BA_Base
	{
		scope = 1;
		side = 0;
		faction = "INS";
		crew = "Ins_Soldier_Crew";
		typicalCargo[] = {"Ins_Soldier_Crew","Ins_Soldier_Crew","Ins_Soldier_Crew"};
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_1_co.paa","\ca\tracked\data\T72_2_co.paa","\ca\tracked\data\T72_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_co.paa","\x\acex_ru\addons\t_veh_t72\dz5_co.paa"};
	};
	class ACE_T72BA_CDF: ACE_T72BA_Base
	{
		hiddenSelectionsTextures[] = {"\ca\tracked\data\t72blu_1_co.paa","\ca\tracked\data\t72blu_2_co.paa","\ca\tracked\data\t72blu_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1blu_co.paa","\x\acex_ru\addons\t_veh_t72\dz5blu_co.paa"};
	};
	class ACE_T72BA_Gue: ACE_T72BA_Base
	{
		hiddenSelectionsTextures[] = {"\ca\tracked\data\T72_KHK_1_co.paa","\ca\tracked\data\T72_KHK_2_co.paa","\ca\tracked\data\T72_KHK_3_co.paa","\x\acex_ru\addons\t_veh_t72\dz1_khk_co.paa","\x\acex_ru\addons\t_veh_t72\dz5_khk_co.paa"};
	};
};
class CfgGroups
{
	class West
	{
		class CDF
		{
			class Armored
			{
				class CDF_TankPlatoon
				{
					name = "$STR_ACE_GDN_CDF_TANKPLATOON";
				};
				class ACE_CDF_Tank_Platoon_T72B
				{
					name = "$STR_ACE_GDN_ACE_CDF_TANK_PLATOON_T72B";
					faction = "CDF";
					rarityGroup = 0.25;
					class Unit0
					{
						side = 1;
						vehicle = "ACE_T72B_CDF";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 1;
						vehicle = "ACE_T72B_CDF";
						rank = "LIEUTENANT";
						position[] = {7,0,0};
					};
					class Unit2
					{
						side = 1;
						vehicle = "ACE_T72B_CDF";
						rank = "SERGEANT";
						position[] = {-7,0,0};
					};
				};
			};
		};
	};
	class East
	{
		class RU
		{
			class Armored
			{
				class ACE_RU_Tank_Platoon_T90A
				{
					name = "$STR_ACE_GDN_ACE_RU_TANK_PLATOON_T90A";
					faction = "RU";
					rarityGroup = 0.25;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_T90A";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_T90A";
						rank = "LIEUTENANT";
						position[] = {7,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_T90A";
						rank = "SERGEANT";
						position[] = {-7,0,0};
					};
				};
				class RU_TankPlatoon
				{
					name = "$STR_ACE_GDN_RU_TANKPLATOON";
				};
				class ACE_RU_Tank_Platoon_T72BA
				{
					name = "$STR_ACE_GDN_ACE_RU_TANK_PLATOON_T72BA";
					faction = "RU";
					rarityGroup = 0.25;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_T72BA_Base";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_T72BA_Base";
						rank = "LIEUTENANT";
						position[] = {7,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_T72BA_Base";
						rank = "SERGEANT";
						position[] = {-7,0,0};
					};
				};
				class ACE_RU_Tank_Platoon_T72B
				{
					name = "$STR_ACE_GDN_ACE_RU_TANK_PLATOON_T72B";
					faction = "RU";
					rarityGroup = 0.25;
					class Unit0
					{
						side = 0;
						vehicle = "ACE_T72B_Base";
						rank = "CAPTAIN";
						position[] = {0,10,0};
					};
					class Unit1
					{
						side = 0;
						vehicle = "ACE_T72B_Base";
						rank = "LIEUTENANT";
						position[] = {7,0,0};
					};
					class Unit2
					{
						side = 0;
						vehicle = "ACE_T72B_Base";
						rank = "SERGEANT";
						position[] = {-7,0,0};
					};
				};
			};
		};
	};
};
//};
