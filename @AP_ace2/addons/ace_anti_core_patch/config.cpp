/**********************************************
 Original file: config.bin
 Binarized size: 12509b
 Classes count: 3
 Datestamp: 18.04.2017 18:55:25
 Debinarized with Blender's tools
 http://www.arma3.ru
**********************************************/

class CfgPatches {
    class anti_core_patch {
        units[]={};
        weapons[]={};
        requiredVersion = 1.62;
        requiredAddons[]={        
            "CorePatch",
            "CorePatch2"
        };
        version = "1.0";
        author[]={        
            "Blender"
        };
        description = "Removes shitty config vehicle 'overhauls' made by CorePatch";
    };
};
class CfgWeapons {
    class Rifle;
    class AKS_BASE;
    class AKS_74_GOSHAWK:AKS_BASE {
        class OpticsModes {
            class Goshawk {
                discreteDistance[]={                
                    300
                };
                discreteDistanceInitIndex = 0;
            };
            class Ironsights:Goshawk {
                discreteDistance[]={                
                    100,
                    200,
                    300,
                    400,
                    500,
                    600,
                    700,
                    800
                };
                discreteDistanceInitIndex = 2;
            };
        };
    };
    class SVD:Rifle {
        delete weaponInfoType
        class OpticsModes {
            class Scope {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
            class Ironsights:Scope {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class SVD_CAMO:SVD {
        class OpticsModes {
            class Scope {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class SVD_des_EP1:SVD {
        class OpticsModes {
            class Scope {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class VSS_vintorez:Rifle {
        class OpticsModes {
            class Scope {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
            class Ironsights:Scope {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class ksvk:Rifle {
        delete discreteDistance
        delete discreteDistanceInitIndex
        delete weaponInfoType
    };
};
class CfgVehicles {
    class All;
    class AllVehicles:All {
        class AnimationSources;
        class NewTurret;
    };
    class Air:AllVehicles {
    };
    class Helicopter:Air {
        class Turrets {
            class MainTurret;
        };
    };
    class AH1_Base:Helicopter {
    };
    class AH1Z:AH1_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class AH64_base_EP1:Helicopter {
    };
    class AH64D:AH64_base_EP1 {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class AH64D_EP1:AH64_base_EP1 {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class CH47_base_EP1:Helicopter {
    };
    class CH_47F_EP1:CH47_base_EP1 {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
            };
            class BackDoorGun:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Ka60_Base_PMC:Helicopter {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Ka137_Base_PMC:Helicopter {
    };
    class Ka137_PMC:Ka137_Base_PMC {
    };
    class Ka137_MG_PMC:Ka137_Base_PMC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class Kamov_Base:Helicopter {
    };
    class Ka52:Kamov_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Mi24_Base:Helicopter {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class UH1_Base:Helicopter {
    };
    class UH1H_base:Helicopter {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class UH60_Base:Helicopter {
    };
    class MH60S:UH60_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Land:AllVehicles {
    };
    class LandVehicle:Land {
    };
    class Car:LandVehicle {
        class Turrets {
            class MainTurret:NewTurret {
                class ViewOptics;
            };
        };
    };
    class BAF_Jackal2_BASE_D:Car {
        class Turrets:Turrets {
            class M420_Turret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class BAF_Jackal2_GMG_D:BAF_Jackal2_BASE_D {
        class Turrets:Turrets {
            class GMG_Turret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class HMMWV_Base:Car {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class HMMWV_Armored:HMMWV_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class HMMWV_M998_crows_M2_DES_EP1:HMMWV_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class HMMWV_M998_crows_MK19_DES_EP1:HMMWV_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class HMMWV_M998A2_SOV_DES_EP1:HMMWV_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
            class SideTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class HMMWV_MK19:HMMWV_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class LandRover_Base:Car {
    };
    class LandRover_MG_Base_EP1:LandRover_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class LandRover_Special_CZ_EP1:LandRover_Base {
        class Turrets:Turrets {
            class AGS30_Turret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
            class PK_Turret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Offroad_DSHKM_base:Car {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Pickup_PK_base:Car {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Truck:Car {
    };
    class Ural_Base_withTurret:Truck {
    };
    class Ural_ZU23_Base:Ural_Base_withTurret {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class UAZ_Base:Car {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class UAZ_AGS30_Base:UAZ_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class Wheeled_APC:Car {
    };
    class BRDM2_Base:Wheeled_APC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class BRDM2_HQ_Base:BRDM2_Base {
        class Turrets:Turrets {
            class MainTurret:NewTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class BTR60_TK_EP1:BRDM2_Base {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
            };
            class CommanderTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class BTR40_MG_base_EP1:Wheeled_APC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class BTR90_Base:Wheeled_APC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class GAZ_Vodnik_HMG:Wheeled_APC {
        class Turrets {
            class MainTurret:NewTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class GAZ_Vodnik:GAZ_Vodnik_HMG {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class LAV25_Base:Wheeled_APC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete turretInfoType
            };
        };
    };
    class LAV25_HQ:LAV25_Base {
        class Turrets:Turrets {
            class MainTurret:NewTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class StrykerBase_EP1:Wheeled_APC {
    };
    class M1135_ATGMV_EP1:StrykerBase_EP1 {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
            };
        };
    };
    class M1126_ICV_BASE_EP1:StrykerBase_EP1 {
        class Turrets:Turrets {
            class ObsTurret:NewTurret {
            };
        };
    };
    class M1126_ICV_M2_EP1:M1126_ICV_BASE_EP1 {
        class Turrets:Turrets {
            class ObsTurret:ObsTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class M1126_ICV_mk19_EP1:M1126_ICV_BASE_EP1 {
        class Turrets:Turrets {
            class ObsTurret:ObsTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
            };
        };
    };
    class M1128_MGS_EP1:StrykerBase_EP1 {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class StaticWeapon:LandVehicle {
        class Turrets;
    };
    class StaticCanon:StaticWeapon {
        class Turrets:Turrets {
            class MainTurret;
        };
    };
    class ZU23_base:StaticCanon {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class StaticGrenadeLauncher:StaticWeapon {
        class Turrets:Turrets {
            class MainTurret;
        };
    };
    class AGS_base:StaticGrenadeLauncher {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class GMG_TriPod:StaticGrenadeLauncher {
    };
    class BAF_GMG_Tripod_D:GMG_TriPod {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class MK19_TriPod:StaticGrenadeLauncher {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class StaticMGWeapon:StaticWeapon {
        class Turrets:Turrets {
            class MainTurret;
        };
    };
    class DSHKM_base:StaticMGWeapon {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class KORD_Base:StaticMGWeapon {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class M2StaticMG_base:StaticMGWeapon {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class WarfareBMGNest_M240_base:StaticMGWeapon {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class WarfareBMGNest_PK_Base:StaticMGWeapon {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Tank:LandVehicle {
        class Turrets {
            class MainTurret:NewTurret {
                class Turrets {
                    class CommanderOptics:NewTurret {
                        class ViewOptics;
                    };
                };
            };
        };
    };
    class 2S6M_Tunguska:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                discreteDistance[]={                
                    400,
                    500,
                    600,
                    700,
                    800,
                    900,
                    1000,
                    1100,
                    1200,
                    1300
                };
            };
        };
    };
    class BAF_FV510_D:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class M1A1:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                class Turrets:Turrets {
                    class CommanderOptics:CommanderOptics {
                        delete discreteDistance
                        delete discreteDistanceInitIndex
                        delete turretInfoType
                    };
                };
            };
        };
    };
    class M1A2_TUSK_MG:M1A1 {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                class Turrets:Turrets {
                    class LoaderTurret:NewTurret {
                        delete discreteDistance
                        delete discreteDistanceInitIndex
                        delete turretInfoType
                    };
                };
            };
        };
    };
    class M113_Base:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class M2A2_Base:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class M2A2_EP1:M2A2_Base {
    };
    class M2A3_EP1:M2A2_EP1 {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                class Turrets:Turrets {
                    class CommanderOptics:CommanderOptics {
                        delete turretInfoType
                    };
                };
            };
        };
    };
    class T34:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
            class FrontGunner:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                soundServo[]={};
            };
        };
    };
    class T55_Base:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
    class T72_Base:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                class Turrets:Turrets {
                    class CommanderOptics:CommanderOptics {
                        delete discreteDistance
                        delete discreteDistanceInitIndex
                        delete turretInfoType
                    };
                };
            };
        };
    };
    class T90:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                class Turrets:Turrets {
                    class CommanderOptics:NewTurret {
                        delete gunnerOutOpticsModel
                        delete outGunnerMayFire
                        delete discreteDistance
                        delete discreteDistanceInitIndex
                        delete turretInfoType
                    };
                };
            };
        };
    };
    class ZSU_Base:Tank {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                discreteDistance[]={                
                    100,
                    200,
                    300,
                    400,
                    500,
                    600,
                    700,
                    800,
                    900,
                    1000
                };
            };
        };
    };
    class Tracked_APC:Tank {
    };
    class AAV:Tracked_APC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class BMP2_Base:Tracked_APC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class BMP3:Tracked_APC {
        class Turrets:Turrets {
            class MainTurret:MainTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class Ship:AllVehicles {
        class Turrets;
    };
    class Boat:Ship {
    };
    class RHIB:Boat {
        class Turrets:Turrets {
            class MainTurret:NewTurret {
                delete discreteDistance
                delete discreteDistanceInitIndex
                delete turretInfoType
            };
        };
    };
    class RHIB2Turret:RHIB {
        class Turrets:Turrets {
            class BackTurret:MainTurret {
                delete discreteDistance
            };
        };
    };
};
