////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Aug 24 17:37:45 2012 : Created on Fri Aug 24 17:37:45 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_c_ai_sensors : config.bin{
class CfgPatches
{
	class ace_c_ai_sensors
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","CACharacters","CACharacters2","CACharacters_E","CACharacters_BAF","CACharacters_PMC","CAWheeled","CAWheeled2","CAWheeled3","CATracked","CATracked2","CAAir","CAAir2","CAAir3","CAA10","CAWeapons"};
		version = "1.13.0.568";
	};
};
class CfgVehicles
{
	class AllVehicles;
	class Land: AllVehicles{};
	class LandVehicle: Land{};
	class StaticWeapon: LandVehicle
	{
		audible = 1;
		sensitivityEar = 1;
	};
	class Car: LandVehicle
	{
		audible = 0.8;
		commanderCanSee = "2+4+8+16+32";
		gunnerCanSee = "2+4+8+16+32";
		driverCanSee = "2+4+8+16+32";
	};
	class Wheeled_APC: Car
	{
		audible = 1.05;
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class Truck: Car
	{
		audible = 1.2;
	};
	class Motorcycle: LandVehicle
	{
		audible = 1.35;
	};
	class Bicycle;
	class Tank: LandVehicle
	{
		audible = 1.3;
		sensitivityEar = 0.001;
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class Tracked_APC: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class Air: AllVehicles
	{
		audible = 5;
		sensitivity = 8;
		driverCanSee = "1+2+4+16";
		gunnerCanSee = "1+2+4+16";
		commanderCanSee = "1+2+4+16";
	};
	class Helicopter: Air
	{
		audible = 5;
	};
	class Plane: Air
	{
		audible = 5;
	};
	class AH1_Base: Helicopter
	{
		audible = 6.5;
	};
	class UH1_Base: Helicopter
	{
		audible = 5;
		driverCanSee = "1+2+4+16";
		gunnerCanSee = "1+2+4+8+16+32";
	};
	class UH1H_Base: Helicopter
	{
		audible = 6;
		driverCanSee = "1+2+4+16";
		gunnerCanSee = "1+2+4+8+16+32";
	};
	class UH60_Base: Helicopter
	{
		audible = 5.5;
		driverCanSee = "1+2+4+16";
		gunnerCanSee = "1+2+4+8+16+32";
	};
	class AV8B2: Plane
	{
		audible = 6.5;
	};
	class A10: Plane
	{
		audible = 5;
	};
	class Mi17_Base: Helicopter
	{
		audible = 6;
		driverCanSee = "1+2+4+16";
		gunnerCanSee = "1+2+4+8+16";
	};
	class Mi24_Base: Helicopter
	{
		audible = 7;
		driverCanSee = "1+2+4+16";
		gunnerCanSee = "1+2+4+16";
	};
	class C130J: Plane
	{
		audible = 7;
	};
	class F35_base: Plane
	{
		audible = 5;
	};
	class Kamov_Base: Helicopter
	{
		audible = 6.5;
	};
	class MV22: Plane
	{
		audible = 5.5;
	};
	class Su25_base: Plane
	{
		audible = 5.5;
	};
	class Su34: Plane
	{
		audible = 5;
	};
	class An2_Base_EP1: Plane
	{
		driverCanSee = "2+4+16";
	};
	class Ship: AllVehicles
	{
		audible = 0.6;
		driverCanSee = "2+4+8+16+32";
		gunnerCanSee = "2+4+8+16+32";
		commanderCanSee = "2+4+8+16+32";
	};
	class ParachuteBase: Helicopter
	{
		audible = 0.1;
		driverCanSee = "2+4+8+16+32";
		gunnerCanSee = "2+4+8+16+32";
		commanderCanSee = "2+4+8+16+32";
	};
	class M1A1: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "1+2+4+8+16";
		sensitivity = 2;
	};
	class M1A2_TUSK_MG: M1A1
	{
		sensitivity = 2.5;
	};
	class ZSU_Base: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class 2S6M_Tunguska: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class T34: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class T55_Base: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class T72_Base: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+2+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class T90: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
		sensitivity = 2;
	};
	class M2A2_Base: Tank
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class M2A2_EP1: M2A2_Base{};
	class M2A3_EP1: M2A2_EP1
	{
		sensitivity = 2;
	};
	class BMP2_Base: Tracked_APC
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class BMP3: Tracked_APC
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class AAV: Tracked_APC
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+2+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class BRDM2_Base: Wheeled_APC
	{
		gunnerCanSee = "1+2+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class BTR60_TK_EP1: BRDM2_Base
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+2+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class GAZ_Vodnik_HMG: Wheeled_APC
	{
		gunnerCanSee = "1+2+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class BTR90_Base: Wheeled_APC
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class LAV25_Base: Wheeled_APC
	{
		commanderCanSee = "1+2+4+8+16";
		gunnerCanSee = "1+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class StrykerBase_EP1: Wheeled_APC
	{
		commanderCanSee = "2+4+8+16";
		gunnerCanSee = "4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class M113_Base: Tank
	{
		gunnerCanSee = "1+2+4+8+16";
		driverCanSee = "2+4+8+16";
	};
	class HMMWV_Base;
	class HMMWV_TOW: HMMWV_Base
	{
		gunnerCanSee = "1+2+4+8+16+32";
	};
	class HMMWV_Avenger: HMMWV_Base
	{
		gunnerCanSee = "1+2+4+8+16";
	};
	class Man: Land
	{
		camouflage = "1.0*0.8";
		audible = 0.0125;
		sensitivityEar = 1.0;
	};
	class CAManBase: Man
	{
		sensitivity = 4;
		sensitivityEar = 0.75;
	};
	class SoldierWB: CAManBase
	{
		sensitivity = 5;
		sensitivityEar = 1.0;
	};
	class SoldierEB: CAManBase
	{
		sensitivity = 5;
		sensitivityEar = 1.0;
	};
	class SoldierGB: CAManBase
	{
		sensitivity = 5;
		sensitivityEar = 1.0;
	};
	class US_Soldier_Base_EP1: SoldierWB
	{
		camouflage = "1.0*0.8";
	};
	class US_Soldier_Officer_EP1: US_Soldier_Base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Soldier_AT_Base_EP1: US_Soldier_Base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Soldier_HAT_EP1: US_Soldier_AT_Base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Soldier_AA_EP1: US_Soldier_AT_Base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Soldier_Pilot_EP1: US_Soldier_Base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Soldier_Crew_EP1: US_Soldier_Base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Soldier_Spotter_EP1: US_Soldier_Base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class US_Soldier_Sniper_EP1: US_Soldier_Base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class US_Delta_Force_EP1: US_Soldier_Base_EP1
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class US_Delta_Force_TL_EP1: US_Soldier_Base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class US_Delta_Force_SD_EP1: US_Delta_Force_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Delta_Force_MG_EP1: US_Delta_Force_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Delta_Force_Night_EP1: US_Delta_Force_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Delta_Force_Air_Controller_EP1: US_Delta_Force_EP1
	{
		camouflage = "1.0*0.8";
	};
	class US_Delta_Force_Marksman_EP1: US_Delta_Force_EP1
	{
		sensitivity = 7;
	};
	class Graves: US_Delta_Force_EP1
	{
		camouflage = "1.0*0.8";
	};
	class UN_CDF_Soldier_base_EP1: SoldierGB
	{
		camouflage = "1.5*0.8";
	};
	class UN_CDF_Soldier_Officer_EP1: UN_CDF_Soldier_base_EP1
	{
		camouflage = "1.5*0.8";
		nightvision = 0;
	};
	class UN_CDF_Soldier_Pilot_EP1: UN_CDF_Soldier_base_EP1
	{
		camouflage = "1.5*0.8";
	};
	class UN_CDF_Soldier_Crew_EP1: UN_CDF_Soldier_base_EP1
	{
		camouflage = "1.5*0.8";
	};
	class UN_CDF_Soldier_Light_EP1: UN_CDF_Soldier_base_EP1
	{
		camouflage = "1.5*0.8";
	};
	class TK_INS_Soldier_Base_EP1: SoldierEB
	{
		camouflage = "1.5*0.8";
	};
	class TK_INS_Soldier_Sniper_EP1: TK_INS_Soldier_Base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
	};
	class TK_GUE_Soldier_Base_EP1: SoldierGB
	{
		camouflage = "2.0*0.8";
	};
	class TK_GUE_Soldier_Sniper_EP1: TK_GUE_Soldier_Base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
	};
	class US_Delta_Force_Undercover_Takistani_Base_EP1: TK_GUE_Soldier_Base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class TK_Soldier_base_EP1: SoldierEB
	{
		camouflage = "1.0*0.8";
	};
	class TK_Soldier_Spotter_EP1: TK_Soldier_base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class TK_Soldier_Sniper_EP1: TK_Soldier_base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class TK_Special_Forces_EP1: TK_Soldier_base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class TK_Special_Forces_TL_EP1: TK_Special_Forces_EP1
	{
		sensitivity = 6;
	};
	class CZ_Soldier_base_EP1: SoldierWB
	{
		camouflage = "1.0*0.8";
	};
	class CZ_Soldier_Pilot_EP1: CZ_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class CZ_Soldier_Office_DES_EP1: CZ_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class CZ_Special_Forces_Scout_DES_EP1: CZ_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class CZ_Special_Forces_MG_DES_EP1: CZ_Soldier_base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class CZ_Special_Forces_DES_EP1: CZ_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class CZ_Special_Forces_TL_DES_EP1: CZ_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class CZ_Special_Forces_GL_DES_EP1: CZ_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class CZ_Soldier_Sniper_EP1: CZ_Soldier_base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class CZ_Soldier_Base_ACR: CZ_Soldier_base_EP1{};
	class CZ_Soldier_Officer_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		camouflage = "1.0*0.8";
	};
	class CZ_Soldier_Pilot_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		camouflage = "1.0*0.8";
	};
	class CZ_Soldier_Recon_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class CZ_Soldier_Spec1_Wdl_ACR: CZ_Soldier_Base_ACR
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class CZ_Soldier_Spec2_Wdl_ACR: CZ_Soldier_Spec1_Wdl_ACR
	{
		camouflage = "1.0*0.8";
	};
	class CZ_Soldier_Sniper_ACR: CZ_Soldier_Base_ACR
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class GER_Soldier_base_EP1: SoldierWB
	{
		camouflage = "1.0*0.8";
	};
	class GER_Soldier_EP1: GER_Soldier_base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class GER_Soldier_Medic_EP1: GER_Soldier_base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class GER_Soldier_TL_EP1: GER_Soldier_base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class GER_Soldier_Scout_EP1: GER_Soldier_base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class GER_Soldier_MG_EP1: GER_Soldier_base_EP1
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class BAF_Soldier_base_EP1: SoldierWB
	{
		camouflage = "1.0*0.8";
	};
	class BAF_Soldier_AT_MTP: BAF_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class BAF_Soldier_HAT_MTP: BAF_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class BAF_Soldier_AA_MTP: BAF_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class BAF_Pilot_MTP: BAF_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class BAF_crewman_MTP: BAF_Soldier_base_EP1
	{
		camouflage = "1.0*0.8";
	};
	class BAF_Soldier_Sniper_MTP: BAF_Soldier_base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class BAF_Soldier_spotter_MTP: BAF_Soldier_base_EP1
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class Soldier_Base_PMC: SoldierGB
	{
		camouflage = "1.5*0.8";
	};
	class Soldier_Sniper_PMC: Soldier_Base_PMC
	{
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class Special_Character_Base_PMC: Soldier_Base_PMC
	{
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class USMC_Soldier_Base: SoldierWB
	{
		camouflage = "1.0*0.8";
	};
	class USMC_Soldier_Officer: USMC_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class USMC_Soldier_AT_Base: USMC_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class USMC_Soldier_HAT: USMC_Soldier_AT_Base
	{
		camouflage = "1.0*0.8";
	};
	class USMC_Soldier_AA: USMC_Soldier_AT_Base
	{
		camouflage = "1.0*0.8";
	};
	class USMC_SoldierS: USMC_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class USMC_Soldier_Pilot: USMC_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class USMC_Soldier_Crew: USMC_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class USMC_SoldierS_Spotter: USMC_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class USMC_SoldierS_Sniper: USMC_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class USMC_LHD_Crew_Base: USMC_Soldier_Base
	{
		camouflage = "2.0*0.8";
	};
	class FR_Base: SoldierWB
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
		nightvision = 0;
	};
	class FR_Commander: FR_Base
	{
		camouflage = "1.0*0.8";
	};
	class FR_Marksman: FR_Base
	{
		camouflage = "1.0*0.8";
		sensitivity = 7;
	};
	class FR_AR: FR_Base
	{
		camouflage = "1.0*0.8";
	};
	class FR_Sapper: FR_Base
	{
		camouflage = "1.0*0.8";
	};
	class FR_AC: FR_Base
	{
		camouflage = "1.0*0.8";
	};
	class FR_Sykes: FR_Marksman
	{
		camouflage = "1.0*0.8";
		sensitivity = 7;
	};
	class FR_Rodriguez: FR_AR
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_Base: SoldierEB
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_Officer: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
		nightvision = 0;
	};
	class RU_Soldier_SL: RU_Soldier_Base
	{
		nightvision = 0;
	};
	class RU_Soldier_TL: RU_Soldier_Base
	{
		nightvision = 0;
	};
	class RU_Commander: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_LAT: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_AT: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
		nightvision = 0;
	};
	class RU_Soldier_HAT: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_AA: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_Pilot: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_Crew: RU_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RU_Soldier_Sniper: RU_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
		nightvision = 0;
	};
	class RU_Soldier_Spotter: RU_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
		nightvision = 0;
	};
	class RU_Soldier_Marksman: RU_Soldier_Base
	{
		nightvision = 0;
	};
	class RUS_Soldier_Base: SoldierEB
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class RUS_Soldier1: RUS_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RUS_Soldier2: RUS_Soldier1
	{
		camouflage = "1.0*0.8";
	};
	class RUS_Soldier3: RUS_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RUS_Commander: RUS_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class RUS_Soldier_Marksman: RUS_Soldier_Base
	{
		camouflage = "1.0*0.8";
		sensitivity = 7;
	};
	class RUS_Soldier_Sab: RUS_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class MVD_Soldier_Base: SoldierEB
	{
		camouflage = "1.0*0.8";
		sensitivity = 6;
		sensitivityEar = 1.25;
	};
	class MVD_Soldier_Marksman: MVD_Soldier_Base
	{
		camouflage = "1.0*0.8";
		sensitivity = 7;
	};
	class MVD_Soldier: MVD_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class MVD_Soldier_Sniper: MVD_Soldier
	{
		camouflage = "1.0*0.8";
		sensitivity = 7;
	};
	class Ins_Soldier_Base: SoldierEB
	{
		camouflage = "1.0*0.8";
	};
	class Ins_Soldier_AT: Ins_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class Ins_Soldier_AA: Ins_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class Ins_Soldier_Sniper: Ins_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
	};
	class Ins_Soldier_Sab: Ins_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class Ins_Soldier_Pilot: Ins_Soldier_Base
	{
		camouflage = "2.0*0.8";
	};
	class Ins_Soldier_Crew: Ins_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class Ins_Worker2: Ins_Soldier_Base
	{
		camouflage = "2.0*0.8";
		sensitivity = 4;
	};
	class Ins_Woodlander1: Ins_Soldier_Base
	{
		camouflage = "2.0*0.8";
		sensitivity = 4;
	};
	class Ins_Villager3: Ins_Soldier_Base
	{
		camouflage = "2.0*0.8";
		sensitivity = 4;
	};
	class Ins_Commander: Ins_Soldier_Base
	{
		camouflage = "2.0*0.8";
	};
	class Ins_Lopotev: Ins_Commander
	{
		camouflage = "2.0*0.8";
	};
	class Ins_Bardak: Ins_Commander
	{
		camouflage = "1.5*0.8";
	};
	class Ins_Soldier_CO: Ins_Soldier_Base
	{
		nightvision = 0;
	};
	class GUE_Soldier_Base: SoldierGB
	{
		camouflage = "1.0*0.8";
	};
	class GUE_Soldier_AT: GUE_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class GUE_Soldier_AA: GUE_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class GUE_Soldier_Sab: GUE_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class GUE_Soldier_Sniper: GUE_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
	};
	class GUE_Soldier_Scout: GUE_Soldier_Sniper
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
	};
	class GUE_Soldier_1: GUE_Soldier_Base{};
	class GUE_Soldier_Pilot: GUE_Soldier_1
	{
		camouflage = "2.0*0.8";
	};
	class GUE_Worker2: GUE_Soldier_Base
	{
		camouflage = "2.0*0.8";
		sensitivity = 4;
	};
	class GUE_Woodlander1: GUE_Soldier_Base
	{
		camouflage = "2.0*0.8";
		sensitivity = 4;
	};
	class GUE_Villager3: GUE_Soldier_Base
	{
		camouflage = "2.0*0.8";
		sensitivity = 4;
	};
	class CDF_Soldier_Base: SoldierWB
	{
		camouflage = "1.0*0.8";
	};
	class CDF_Soldier: CDF_Soldier_Base{};
	class CDF_Soldier_Marksman: CDF_Soldier_Base
	{
		camouflage = "1.0*0.8";
		nightvision = 0;
	};
	class CDF_Soldier_RPG: CDF_Soldier_Base
	{
		camouflage = "1.0*0.8";
		nightvision = 0;
	};
	class CDF_Soldier_Strela: CDF_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class CDF_Soldier_Officer: CDF_Soldier_Base
	{
		camouflage = "1.0*0.8";
		nightvision = 0;
	};
	class CDF_Commander: CDF_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class CDF_Soldier_Pilot: CDF_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class CDF_Soldier_Crew: CDF_Soldier_Base
	{
		camouflage = "1.0*0.8";
	};
	class CDF_Soldier_Engineer: CDF_Soldier
	{
		camouflage = "1.0*0.8";
	};
	class CDF_Soldier_Sniper: CDF_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
	class CDF_Soldier_Spotter: CDF_Soldier_Base
	{
		camouflage = "0.5*0.8";
		sensitivity = 7;
		sensitivityEar = 1.25;
	};
};
//};
