////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:05:45 2013 : Created on Mon Oct 14 23:05:45 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_veh_transport : config.bin{
class CfgPatches
{
	class ace_c_veh_transport
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","ace_c_vehicle"};
		version = "1.14.0.597";
		author[] = {"Sickboy"};
	};
};
class CfgVehicles
{
	class AllVehicles;
	class Ship: AllVehicles
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class LandVehicle;
	class Car: LandVehicle
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class Truck: Car{};
	class Tracked_APC;
	class Wheeled_APC;
	class MTVR: Truck
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_Base: Car
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_Ambulance: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class HMMWV_M1035_DES_EP1: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_M1151_M2_DES_Base_EP1: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_M998_crows_M2_DES_EP1: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_M998_crows_MK19_DES_EP1: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_M998A2_SOV_DES_EP1: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_Terminal_EP1: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_TOW: HMMWV_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_TOW_CSWDM
			{
				magazine = "ACE_TOW_CSWDM";
				count = 5;
			};
		};
	};
	class HMMWV_TOW_DES_EP1: HMMWV_TOW
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_TOW_CSWDM
			{
				magazine = "ACE_TOW_CSWDM";
				count = 5;
			};
		};
	};
	class HMMWV_MK19;
	class HMMWV_MK19_DES_EP1: HMMWV_MK19
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV;
	class HMMWV_DES_EP1: HMMWV
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_Ambulance_base;
	class HMMWV_Ambulance_DES_EP1: HMMWV_Ambulance_base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class HMMWV_Ambulance_CZ_DES_EP1: HMMWV_Ambulance_base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class HMMWV_Avenger: HMMWV_base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Stinger_CSWDM
			{
				magazine = "ACE_Stinger_CSWDM";
				count = 4;
			};
		};
	};
	class HMMWV_Avenger_base;
	class HMMWV_Avenger_DES_EP1: HMMWV_Avenger_base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Stinger_CSWDM
			{
				magazine = "ACE_Stinger_CSWDM";
				count = 4;
			};
		};
	};
	class HMMWV_M1151_M2_CZ_DES_EP1: HMMWV_M1151_M2_DES_Base_EP1
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class HMMWV_M1151_M2_DES_EP1: HMMWV_M1151_M2_DES_Base_EP1
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
		};
	};
	class BMP2_Base: Tracked_APC
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Konkurs_CSWDM
			{
				magazine = "ACE_Konkurs_CSWDM";
				count = 4;
			};
		};
	};
	class BMP2_Ambul_Base: BMP2_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class BTR90_Base: Wheeled_APC
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_KonkursM_CSWDM
			{
				magazine = "ACE_KonkursM_CSWDM";
				count = 4;
			};
		};
	};
	class Camp_base;
	class MASH: Camp_base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 100;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 50;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 50;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 50;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 25;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 10;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 25;
			};
		};
	};
	class S1203_TK_CIV_EP1;
	class S1203_ambulance_EP1: S1203_TK_CIV_EP1
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class StrykerBase_EP1;
	class M1133_MEV_EP1: StrykerBase_EP1
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class BASE_WarfareBFieldhHospital: Camp_base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 100;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 50;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 50;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 50;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 25;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 10;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 25;
			};
		};
	};
	class M113_Base;
	class M113Ambul_Base: M113_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class GAZ_Vodnik;
	class GAZ_Vodnik_MedEvac: GAZ_Vodnik
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class Air;
	class Helicopter: Air
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 1;
			};
		};
	};
	class Plane: Air
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 1;
			};
		};
	};
	class UH60_Base: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 12;
			};
		};
	};
	class MH60S: UH60_Base
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 12;
			};
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class UH60M_US_base_EP1;
	class UH60M_EP1: UH60M_US_base_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 12;
			};
		};
	};
	class UH60M_MEV_EP1: UH60M_US_base_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 12;
			};
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class AH1_Base: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 2;
			};
		};
	};
	class AH64_base_EP1: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 2;
			};
		};
	};
	class CH47_base_EP1: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 5;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 24;
			};
		};
	};
	class AH64D_EP1: AH64_base_EP1{};
	class BAF_Apache_AH1_D: AH64D_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 2;
			};
		};
	};
	class AW159_Lynx_BAF: Helicopter
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 2;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 8;
			};
		};
	};
	class BAF_Merlin_HC3_D: Helicopter
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 2;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 17;
			};
		};
	};
	class CH_47F_EP1;
	class CH_47F_BAF: CH_47F_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 5;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 24;
			};
		};
	};
	class Mi17_base: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 20;
			};
		};
	};
	class Mi17_medevac_base: Mi17_base
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 20;
			};
			class _xx_ACE_Stretcher
			{
				weapon = "ACE_Stretcher";
				count = 2;
			};
		};
		class TransportMagazines
		{
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 15;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 15;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 5;
			};
			class _xx_ACE_Bodybag
			{
				magazine = "ACE_Bodybag";
				count = 5;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 5;
			};
		};
	};
	class Mi17_base_CZ_EP1;
	class Mi171Sh_Base_EP1: Mi17_base_CZ_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 20;
			};
		};
	};
	class Mi17_base_TK_EP1;
	class Mi17_TK_EP1: Mi17_base_TK_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 20;
			};
		};
	};
	class Mi24_Base: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 10;
			};
		};
		class TransportMagazines{};
	};
	class Mi24_D_Base_TK_EP1;
	class Mi24_D_TK_EP1: Mi24_D_Base_TK_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 10;
			};
		};
		class TransportMagazines{};
	};
	class UH1_Base: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 7;
			};
		};
	};
	class UH1H_base: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 7;
			};
		};
	};
	class UH1H_TK_EP1: UH1H_base
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 7;
			};
		};
	};
	class UH1H_TK_GUE_EP1: UH1H_base
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 4;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 7;
			};
		};
	};
	class AH6_Base_EP1: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 1;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 5;
			};
		};
	};
	class AH6J_EP1: AH6_Base_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 2;
			};
		};
	};
	class MH6J_EP1: AH6_Base_EP1
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 1;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 5;
			};
		};
	};
	class C130J: Plane
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 27;
			};
		};
	};
	class C130J_base;
	class C130J_US_EP1: C130J_base
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 27;
			};
		};
	};
	class An2_Base_EP1: Plane
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 16;
			};
		};
	};
	class MV22: Plane
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 2;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 23;
			};
		};
	};
	class Ka60_Base_PMC: Helicopter
	{
		class TransportWeapons
		{
			class _xx_ACE_ParachuteRoundPack
			{
				weapon = "ACE_ParachuteRoundPack";
				count = 1;
			};
			class _xx_ACE_ParachutePack
			{
				weapon = "ACE_ParachutePack";
				count = 9;
			};
		};
	};
	class LandRover_CZ_EP1;
	class LandRover_TK_CIV_EP1: LandRover_CZ_EP1
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class UAZ_Unarmed_Base;
	class UAZ_Unarmed_TK_CIV_EP1: UAZ_Unarmed_Base
	{
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Rope_TOW_M_5
			{
				magazine = "ACE_Rope_TOW_M_5";
				count = 1;
			};
			class _xx_SmokeShell
			{
				magazine = "SmokeShell";
				count = 2;
			};
			class _xx_SmokeShellGreen
			{
				magazine = "SmokeShellGreen";
				count = 2;
			};
			class _xx_20Rnd_762x51_FNFAL
			{
				count = 0;
				magazine = "20Rnd_762x51_FNFAL";
			};
			class _xx_HandGrenade_East
			{
				count = 0;
				magazine = "HandGrenade_East";
			};
		};
	};
	class Ural_Base;
	class UralOpen_Base;
	class UralCivil: Ural_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class UralCivil2: UralOpen_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines{};
	};
	class Ural_TK_CIV_EP1: Ural_Base
	{
		transportMaxMagazines = 9999;
		transportMaxWeapons = 9999;
		transportMaxBackpacks = 9999;
		class TransportWeapons{};
		class TransportMagazines{};
	};
};
//};
