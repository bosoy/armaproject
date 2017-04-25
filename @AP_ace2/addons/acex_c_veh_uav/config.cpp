////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 28 15:59:49 2011 : Created on Fri Oct 28 15:59:49 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_uav : config.bin{
class CfgPatches
{
	class acex_veh_uav
	{
		units[] = {"ACE_MQ8B_cargo","ACE_MQ8B_hellfire","ACE_MQ8B_MK90"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAAir_E_AH6J"};
		version = "1.12.0.349";
	};
};
class CfgVehicles
{
	class Helicopter;
	class AH6_Base_EP1: Helicopter
	{
		class Turrets;
	};
	class AH6X_EP1: AH6_Base_EP1
	{
		class Turrets: Turrets
		{
			class ObserverTurret;
			class FakePilot;
		};
	};
	class ACE_MQ8B_Base: AH6X_EP1
	{
		scope = 1;
		ACE_isUAV = 1;
		nameSound = "Firescout";
		selectionHRotorStill = "mainRotorStatic";
		selectionHRotorMove = "mainRotorBlurred";
		selectionVRotorStill = "tailRotorStatic";
		selectionVRotorMove = "tailRotorBlurred";
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
		hiddenSelections[] = {};
		weapons[] = {};
		magazines[] = {};
		class Turrets: Turrets
		{
			class ObserverTurret: ObserverTurret
			{
				weapons[] = {};
				magazines[] = {};
			};
			class FakePilot: FakePilot
			{
				weapons[] = {};
				magazines[] = {};
			};
		};
	};
	class ACE_MQ8B_cargo: ACE_MQ8B_Base
	{
		scope = 2;
		model = "\x\acex\addons\m_veh_uav\ACE_MQ8B_cargo.p3d";
		displayName = "MQ-8B (Cargo)";
		icon = "\x\acex\addons\c_veh_uav\data\icon\icomap_mq8bc_ca.paa";
		picture = "\x\acex\addons\c_veh_uav\data\picture\mq8b_ca.paa";
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
		weapons[] = {};
		magazines[] = {};
		class Turrets: Turrets
		{
			class ObserverTurret: ObserverTurret
			{
				weapons[] = {};
				magazines[] = {};
			};
			class FakePilot: FakePilot
			{
				weapons[] = {};
				magazines[] = {};
			};
		};
	};
	class ACE_MQ8B_hellfire: ACE_MQ8B_Base
	{
		scope = 2;
		model = "\x\acex\addons\m_veh_uav\ACE_MQ8B_hellfire.p3d";
		displayName = "MQ-8B (AGM-114)";
		icon = "\x\acex\addons\c_veh_uav\data\icon\icomap_mq8bh_ca.paa";
		weapons[] = {"HellfireLauncher"};
		magazines[] = {"ACE_2Rnd_Hellfire"};
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
		class Turrets: Turrets
		{
			class ObserverTurret: ObserverTurret
			{
				weapons[] = {};
				magazines[] = {};
			};
			class FakePilot: FakePilot
			{
				weapons[] = {};
				magazines[] = {};
			};
		};
	};
	class ACE_MQ8B_MK90: ACE_MQ8B_Base
	{
		scope = 1;
		model = "\x\acex\addons\m_veh_uav\ACE_MQ8B_MK90.p3d";
		displayName = "MQ-8B (MK90)";
		icon = "\x\acex\addons\c_veh_uav\data\icon\icomap_mq8bmk_ca.paa";
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
		class Turrets: Turrets
		{
			class ObserverTurret: ObserverTurret
			{
				weapons[] = {};
				magazines[] = {};
			};
			class FakePilot: FakePilot
			{
				weapons[] = {};
				magazines[] = {};
			};
		};
	};
};
//};
