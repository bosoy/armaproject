////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 14:00:43 2011 : Created on Fri Oct 21 14:00:43 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_veh_armor : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_veh_armor
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWheeled","CAWheeled2","CAWheeled3","CATracked","CATracked2","CATracked2_2S6M_Tunguska","CATracked2_AAV","CATracked2_BMP3","CATracked2_T90","acex_sm_s_veh_armor"};
		version = "1.12.0.97";
	};
};
class CfgVehicles
{
	class All;
	class AllVehicles: All
	{
		class NewTurret;
	};
	class Land: AllVehicles{};
	class LandVehicle: Land{};
	class Car: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret{};
		};
	};
	class Tank: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets;
			};
		};
	};
	class Tracked_APC: Tank{};
	class Wheeled_APC: Car{};
	class LAV25_Base: Wheeled_APC
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_m2.wss",0.316228,1,15};
			};
		};
	};
	class BTR90_Base: Wheeled_APC
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_btr.wss",0.316228,1,15};
			};
		};
	};
	class M1A1: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_m1.wss",0.316228,1,15};
			};
		};
	};
	class T34: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_bmp.wss",0.316228,1,15};
			};
		};
	};
	class T72_Base: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_t72.wss",0.316228,1,15};
			};
		};
	};
	class T90: Tank
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_t80.wss",0.316228,1,15};
			};
		};
	};
	class BMP2_Base: Tracked_APC
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_btr.wss",0.316228,1,15};
			};
		};
	};
	class BMP3: Tracked_APC
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\turret_btr.wss",0.316228,1,15};
			};
		};
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret{};
		};
	};
	class StaticCannon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret{};
		};
	};
	class StaticMortar: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\mortar_turn.wss",0.316228,1,15};
			};
		};
	};
	class M119: StaticCannon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\m119_turn.wss",0.316228,1,15};
			};
		};
	};
	class D30_base: StaticCannon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				soundServo[] = {"x\acex_sm\addons\s_veh_armor\d30_turn.wss",0.316228,1,15};
			};
		};
	};
};
//};
