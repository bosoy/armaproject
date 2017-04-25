////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:06:56 2013 : Created on Mon Oct 14 23:06:56 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_backblast : config.bin{
class CfgPatches
{
	class ace_sys_backblast
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWeapons","CAWeapons_Warfare_weapons","CAweapons2","CAWeapons_E","CAWeapons_E_M136","CAWeapons_E_Igla","CAWeapons_E_M47","CAWeapons_E_RPG7","CAWeapons_E_RPG18","CAWeapons_E_Metis","CAWeapons_E_Javelin","CAWeapons_E_Stinger","CAWeapons_E_Strela","CAWeapons_E_MAAWS","ace_main","ace_c_weapon","ace_fx"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_backblast
	{
		init = "call ('\x\ace\addons\sys_backblast\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgAmmo
{
	class RocketCore;
	class MissileCore;
	class RocketBase: RocketCore
	{
		class ACE
		{
			class ACE_BACKBLAST
			{
				type = "Backblast";
				confinedSpace = 0;
				overpressureEffect = "ACE_ATShock";
				dangerzone = 60;
				angle = 90;
				cautionzone = 25;
			};
		};
	};
	class MissileBase: MissileCore
	{
		class ACE
		{
			class ACE_BACKBLAST
			{
				type = "Backblast";
				confinedSpace = 0;
				overpressureEffect = "ACE_ATShock";
				dangerzone = 60;
				angle = 90;
				cautionzone = 25;
			};
		};
	};
	class R_M136_AT: RocketBase
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		class ACE: ACE
		{
			class ACE_BACKBLAST: ACE_BACKBLAST
			{
				dangerzone = 15;
				angle = 90;
				cautionzone = 7;
			};
		};
	};
	class ACE_R_M136_CSRS: R_M136_AT
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		class ACE: ACE
		{
			class ACE_BACKBLAST: ACE_BACKBLAST
			{
				confinedSpace = 1;
				dangerzone = 15;
				angle = 90;
			};
		};
	};
	class R_PG7V_AT: RocketBase
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		class ACE: ACE
		{
			class ACE_BACKBLAST: ACE_BACKBLAST
			{
				overpressureEffect = "ACE_RPGShock";
				dangerzone = 10;
				angle = 90;
				cautionzone = 5;
			};
		};
	};
	class R_RPG18_AT: RocketBase
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
	};
	class R_SMAW_HEDP: RocketBase{};
	class R_SMAW_HEAA: R_SMAW_HEDP{};
	class M_TOW_AT;
	class M_47_AT_EP1: M_TOW_AT
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		dangerzone = 30;
		angle = 90;
		cautionzone = 10;
	};
	class R_MEEWS_HEDP: R_SMAW_HEDP
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		dangerzone = 28;
		angle = 120;
		cautionzone = -1;
	};
	class R_MEEWS_HEAT: R_SMAW_HEAA
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		dangerzone = 28;
		angle = 120;
		cautionzone = -1;
	};
	class M_Stinger_AA: MissileBase
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		class ACE: ACE
		{
			class ACE_BACKBLAST: ACE_BACKBLAST
			{
				type = "Softlaunch";
				confinedSpace = 1;
				dangerzone = 30;
				angle = 50;
				cautionzone = 5;
			};
		};
	};
	class M_Strela_AA: MissileBase
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		class ACE: ACE
		{
			class ACE_BACKBLAST: ACE_BACKBLAST
			{
				type = "Softlaunch";
				confinedSpace = 1;
				dangerzone = 30;
				angle = 50;
				cautionzone = 5;
			};
		};
	};
	class M_Javelin_AT: MissileBase
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		class ACE: ACE
		{
			class ACE_BACKBLAST: ACE_BACKBLAST
			{
				type = "Softlaunch";
				confinedSpace = 1;
				dangerzone = 15;
				angle = 60;
				cautionzone = 15;
			};
		};
	};
	class M_NLAW_AT: MissileBase
	{
		ACE_Simulation_global = "shotBackblast";
		whistleOnFire = 0;
		class ACE: ACE
		{
			class ACE_BACKBLAST: ACE_BACKBLAST
			{
				type = "Softlaunch";
				confinedSpace = 1;
				dangerzone = 30;
				angle = 50;
				cautionzone = 10;
			};
		};
	};
	class BulletBase;
	class Ace_ATDebris: BulletBase
	{
		hit = 0.28;
		indirectHit = 0.1;
		indirectHitRange = 0.15;
		visibleFire = 0.07;
		audibleFire = 0.07;
		visibleFireTime = 2;
		typicalSpeed = 1100;
		soundFly[] = {};
		soundHit1[] = {};
		soundHit2[] = {};
		soundHit3[] = {};
		soundHit4[] = {};
		soundHit5[] = {};
		soundHit6[] = {};
		soundHit7[] = {};
		soundHit8[] = {};
		soundHit9[] = {};
		soundHit10[] = {};
		soundHit11[] = {};
		soundHit12[] = {};
		soundHitMan1[] = {};
		soundHitMan2[] = {};
		soundHitMan3[] = {};
		soundHitMan4[] = {};
		soundHitMan5[] = {};
		soundHitMan6[] = {};
		soundHitMan7[] = {};
		soundHitArmor1[] = {};
		soundHitArmor2[] = {};
		soundHitArmor3[] = {};
		soundHitArmor4[] = {};
		soundHitArmor5[] = {};
		soundHitArmor6[] = {};
		soundHitArmor7[] = {};
		soundHitArmor8[] = {};
		soundHitArmor9[] = {};
		soundHitArmor10[] = {};
		soundHitArmor11[] = {};
		soundHitArmor12[] = {};
		soundHitArmor13[] = {};
		soundHitArmor14[] = {};
		soundHitBuilding1[] = {};
		soundHitBuilding2[] = {};
		soundHitBuilding3[] = {};
		soundHitBuilding4[] = {};
		soundHitBuilding5[] = {};
		soundHitBuilding6[] = {};
		soundHitBuilding7[] = {};
		soundHitBuilding8[] = {};
		supersonicCrackNear[] = {};
		supersonicCrackFar[] = {};
		hitGround[] = {};
		hitMan[] = {};
		hitArmor[] = {};
		hitBuilding[] = {};
		deflecting = 360;
	};
	class ACE_ATShock: Ace_ATDebris
	{
		hit = 0.0001;
		indirectHit = 3;
		indirectHitRange = 4;
		visibleFire = 1;
		audibleFire = 1;
		visibleFireTime = 2;
		typicalSpeed = 100;
		timeToLive = 0.6;
	};
	class ACE_RPGShock: ACE_ATShock
	{
		typicalSpeed = 150;
		timeToLive = 0.3;
	};
};
//};
