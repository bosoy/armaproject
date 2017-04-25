////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jul 28 13:16:32 2012 : Created on Sat Jul 28 13:16:32 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_gmv : config.bin{
class CfgPatches
{
	class acex_veh_gmv
	{
		units[] = {"ACE_HMMWV_GMV_M2","ACE_HMMWV_GMV_MK19"};
		weapons[] = {"ACE_GMV_M249_1","ACE_GMV_M249_2"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWheeled_E_HMMWV","acex_main","acex_c_vehicle"};
		version = "1.13.0.364";
	};
};
class WeaponCloudsMGun;
class CfgVehicles
{
	class LandVehicle;
	class Car: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class HMMWV_Base: Car
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class HMMWV_M2: HMMWV_Base{};
	class ACE_HMMWV_GMV: HMMWV_M2
	{
		vehicleclass = "CarW";
		Picture = "\Ca\wheeled\data\ico\HMMWV50_CA.paa";
		Icon = "\Ca\wheeled\data\map_ico\icomap_hmwv50_CA.paa";
		displayName = "GMV (M2)";
		displayNameShort = "GMV-S";
		faction = "BIS_US";
		crew = "US_Soldier_EP1";
		model = "\x\acex\addons\m_veh_gmv\ACE_GMV_HMMWV_M2.p3d";
		transportSoldier = 3;
		commanding = 0;
		maxSpeed = 105;
		enableGPS = 1;
		terrainCoef = 2.6;
		armorWheels = 0.15;
		damperSize = 0.1;
		damperForce = 1;
		damperDamping = 1;
		class HitPoints
		{
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 1;
			};
			class HitRGlass
			{
				armor = 0.1;
				material = -1;
				name = "";
				passThrough = 0;
			};
			class HitLGlass
			{
				armor = 0.1;
				material = -1;
				name = "sklo predni L";
				passThrough = 0;
			};
			class HitFuel
			{
				armor = 1.4;
				material = -1;
				name = "palivo";
				passThrough = 1;
			};
			class HitLFWheel
			{
				armor = 0.38;
				material = -1;
				name = "wheel_1_1_steering";
				visual = "";
				passThrough = 0;
			};
			class HitRFWheel
			{
				armor = 0.38;
				material = -1;
				name = "wheel_2_1_steering";
				visual = "";
				passThrough = 0;
			};
			class HitLBWheel
			{
				armor = 0.38;
				material = -1;
				name = "wheel_1_2_steering";
				visual = "";
				passThrough = 0;
			};
			class HitRBWheel
			{
				armor = 0.38;
				material = -1;
				name = "wheel_2_2_steering";
				visual = "";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = -1;
				name = "karoserie";
				visual = "";
				passThrough = 0;
			};
			class HitLF2Wheel
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 1;
			};
			class HitRF2Wheel
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 1;
			};
			class HitLMWheel
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 1;
			};
			class HitRMWheel
			{
				armor = 1;
				material = -1;
				name = "";
				visual = "";
				passThrough = 1;
			};
		};
		class Turrets: Turrets
		{
			class HatchTurret: MainTurret
			{
				ACE_exposed = "true";
				startEngine = 0;
				commanding = 3;
				primaryGunner = 1;
				body = "MainTurret";
				gun = "MainGun";
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				gunnerName = "$STR_POSITION_GUNNER";
				animationSourceBody = "MainTurretSource";
				animationSourceGun = "MainGunSource";
				animationSourceHatch = "";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				memoryPointGun = "machinegun";
				memoryPointGunnerOptics = "gunnerview";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				selectionFireAnim = "zasleh";
				proxyIndex = 1;
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				gunnerOutOpticsShowCursor = 0;
				gunnerOpticsShowCursor = 0;
				gunnerAction = "HMMWV_Gunner01";
				gunnerInAction = "HMMWV_Gunner01";
				hasGunner = 1;
				weapons[] = {"M2"};
				magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2"};
				soundServo[] = {"\ca\wheeled\Data\Sound\servo3","db-75",0.9};
				minElev = -25;
				maxElev = 60;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
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
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				gunnerForceOptics = 0;
			};
			class RightTurret: HatchTurret
			{
				ACE_exposed = "true";
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				animationSourceBody = "RightTurretSource";
				animationSourceGun = "RightGunSource";
				animationSourceHatch = "";
				body = "RightTurret";
				gun = "RightGun";
				gunBeg = "usti hlavne_2";
				gunEnd = "konec hlavne_2";
				gunnerName = "$STR_DN_ACE_GMV_HMMWV_CODRIVER";
				memoryPointGun = "weaponpoint_2";
				memoryPointGunnerOptics = "gunnerview_2";
				selectionFireAnim = "zasleh1";
				proxyIndex = 2;
				commanding = 2;
				hasGunner = 1;
				weapons[] = {"ACE_GMV_M249_1","SmokeLauncher"};
				magazines[] = {"ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","SmokeLauncherMag","SmokeLauncherMag"};
				soundServo[] = {"\ca\wheeled\Data\Sound\servo3","db-75",0.9};
				minElev = -25;
				maxElev = 60;
				initElev = 0;
				minTurn = -35;
				maxTurn = 35;
				initTurn = 0;
				gunnerInAction = "HMMWV_Cargo01";
				gunnerAction = "HMMWV_Cargo01";
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				class ViewGunner: ViewGunner{};
				class ViewOptics: ViewOptics{};
				gunnerOpticsModel = "\ca\weapons\optika_empty";
				gunnerForceOptics = 0;
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
			};
			class LeftTurret: RightTurret
			{
				ACE_exposed = "true";
				body = "LeftTurret";
				gun = "LeftGun";
				gunBeg = "usti hlavne_3";
				gunEnd = "konec hlavne_3";
				gunnerName = "$STR_DN_ACE_GMV_HMMWV_BACKSEAT";
				memoryPointGun = "weaponpoint_3";
				memoryPointGunnerOptics = "gunnerview_3";
				animationSourceBody = "LeftTurretSource";
				animationSourceGun = "LeftGunSource";
				selectionFireAnim = "zasleh2";
				proxyIndex = 3;
				primaryObserver = 0;
				commanding = 1;
				hasGunner = 1;
				weapons[] = {"ACE_GMV_M249_2"};
				magazines[] = {"ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249","ACE_200Rnd_556x45_M249"};
				soundServo[] = {"\ca\wheeled\Data\Sound\servo3","db-75",0.9};
				minElev = -20;
				maxElev = 40;
				minTurn = 0;
				maxTurn = 130;
				initTurn = 65;
				gunnerAction = "HMMWV_Cargo01";
				castGunnerShadow = 1;
				class ViewGunner: ViewGunner{};
				class ViewOptics: ViewOptics{};
				memoryPointsGetInGunner = "pos gunner_back";
				memoryPointsGetInGunnerDir = "pos gunner_back dir";
			};
		};
		class AnimationSources
		{
			class MainGunAmmoBeltRotationSource
			{
				source = "reload";
				weapon = "M2";
			};
			class RightGunAmmoBeltRotationSource: MainGunAmmoBeltRotationSource
			{
				weapon = "ACE_GMV_M249_1";
			};
			class LeftGunAmmoBeltRotationSource: MainGunAmmoBeltRotationSource
			{
				weapon = "ACE_GMV_M249_2";
			};
			class ReloadMagazine
			{
				source = "reloadmagazine";
				weapon = "M2";
			};
			class reloadMagazine_RightGun: ReloadMagazine
			{
				weapon = "ACE_GMV_M249_1";
			};
			class reloadMagazine_LeftGun: ReloadMagazine
			{
				weapon = "ACE_GMV_M249_2";
			};
			class revolving_m2
			{
				source = "revolving";
				weapon = "M2";
			};
			class revolving_m249_right: revolving_m2
			{
				weapon = "ACE_GMV_M249_1";
			};
			class revolving_m249_left: revolving_m2
			{
				weapon = "ACE_GMV_M249_2";
			};
			class HitLFWheel
			{
				source = "Hit";
				hitpoint = "HitLFWheel";
				raw = 1;
			};
			class HitRFWheel: HitLFWheel
			{
				hitpoint = "HitRFWheel";
			};
			class HitLBWheel: HitLFWheel
			{
				hitpoint = "HitLBWheel";
			};
			class HitRBWheel: HitLFWheel
			{
				hitpoint = "HitRBWheel";
			};
		};
		selectionBrakeLights = "brzdove svetlo";
		selectionBackLights = "zadni svetlo";
		class Reflectors
		{
			class Left
			{
				color[] = {0.9,0.8,0.8,1};
				ambient[] = {0.1,0.1,0.1,1};
				position = "L svetlo";
				direction = "Konec L svetla";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 0.5;
				brightness = 0.5;
			};
			class Right
			{
				color[] = {0.9,0.8,0.8,1};
				ambient[] = {0.1,0.1,0.1,1};
				position = "P svetlo";
				direction = "Konec P svetla";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 0.5;
				brightness = 0.5;
			};
		};
		aggregateReflectors[] = {{"Left"},{"Right"}};
		smokeLauncherGrenadeCount = 4;
		smokeLauncherVelocity = 14;
		smokeLauncherOnTurret = 0;
		smokeLauncherAngle = 90;
		selectionDamage = "karoserie";
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex\addons\c_veh_gmv\hmmwv_body.rvmat","x\acex\addons\c_veh_gmv\hmmwv_body.rvmat","x\acex\addons\c_veh_gmv\hmmwv_body_destruct.rvmat","x\acex\addons\c_veh_gmv\hmmwv_hood.rvmat","x\acex\addons\c_veh_gmv\hmmwv_hood.rvmat","x\acex\addons\c_veh_gmv\hmmwv_hood_destruct.rvmat","x\acex\addons\c_veh_gmv\M249.rvmat","x\acex\addons\c_veh_gmv\M249.rvmat","x\acex\addons\c_veh_gmv\M249_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_details.rvmat","Ca\wheeled\HMMWV\data\hmmwv_details_damage.rvmat","Ca\wheeled\HMMWV\data\hmmwv_details_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_body.rvmat","Ca\wheeled\HMMWV\data\hmmwv_body_damage.rvmat","Ca\wheeled\HMMWV\data\hmmwv_body_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat","ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat","ca\wheeled\data\hmmwv_clocks_destruct.rvmat","ca\weapons\data\m2.rvmat","ca\weapons\data\m2.rvmat","ca\weapons\data\m2_destruct.rvmat","ca\tracked\data\detailmapy\m1abrams_mg_mount.rvmat","ca\tracked\data\detailmapy\m1abrams_mg_mount.rvmat","ca\tracked\data\detailmapy\m1abrams_mg_mount_destruct.rvmat"};
		};
		ACE_exposed = "true";
		ACE_Cargo_exposed = "true";
	};
	class ACE_HMMWV_GMV_MK19: ACE_HMMWV_GMV
	{
		picture = "\Ca\wheeled\data\ico\HMMWVmk19_CA.paa";
		Icon = "\Ca\wheeled\data\map_ico\icomap_hmwvmk19_CA.paa";
		displayName = "GMV (Mk19)";
		displayNameShort = "GMV-R";
		model = "\x\acex\addons\m_veh_gmv\ACE_GMV_HMMWV_MK19.p3d";
		class Turrets: Turrets
		{
			class HatchTurret: HatchTurret
			{
				weapons[] = {"ACE_MK19"};
				magazines[] = {"48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19","48Rnd_40mm_MK19"};
				soundServo[] = {"\Ca\sounds\Vehicles\Servos\turret-1",0.01,1,10};
				gunnerAction = "HMMWV_Gunner02";
				class GunFire: WeaponCloudsMGun
				{
					interval = 0.01;
				};
			};
			class RightTurret: RightTurret{};
			class LeftTurret: LeftTurret{};
		};
		class AnimationSources: AnimationSources
		{
			class MainGunAmmoBeltRotationSource
			{
				source = "reload";
				weapon = "ACE_Mk19";
			};
			class ReloadMagazin
			{
				source = "reloadmagazine";
				weapon = "ACE_Mk19";
			};
			class revolving_mk19
			{
				source = "revolving";
				weapon = "ACE_Mk19";
			};
			class revolving_m249_right: revolving_mk19
			{
				weapon = "ACE_GMV_M249_1";
			};
			class revolving_m249_left: revolving_mk19
			{
				weapon = "ACE_GMV_M249_2";
			};
			class HitLFWheel: HitLFWheel{};
			class HitRFWheel: HitLFWheel{};
			class HitLBWheel: HitLFWheel{};
			class HitRBWheel: HitLFWheel{};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex\addons\c_veh_gmv\hmmwv_body.rvmat","x\acex\addons\c_veh_gmv\hmmwv_body.rvmat","x\acex\addons\c_veh_gmv\hmmwv_body_destruct.rvmat","x\acex\addons\c_veh_gmv\hmmwv_hood.rvmat","x\acex\addons\c_veh_gmv\hmmwv_hood.rvmat","x\acex\addons\c_veh_gmv\hmmwv_hood_destruct.rvmat","x\acex\addons\c_veh_gmv\M249.rvmat","x\acex\addons\c_veh_gmv\M249.rvmat","x\acex\addons\c_veh_gmv\M249_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_details.rvmat","Ca\wheeled\HMMWV\data\hmmwv_details_damage.rvmat","Ca\wheeled\HMMWV\data\hmmwv_details_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_body.rvmat","Ca\wheeled\HMMWV\data\hmmwv_body_damage.rvmat","Ca\wheeled\HMMWV\data\hmmwv_body_destruct.rvmat","ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat","ca\wheeled\hmmwv\data\hmmwv_clocks.rvmat","ca\wheeled\data\hmmwv_clocks_destruct.rvmat","ca\weapons\data\mk19.rvmat","ca\weapons\data\mk19.rvmat","ca\weapons\data\mk19_destruct.rvmat","ca\tracked\data\detailmapy\m1abrams_mg_mount.rvmat","ca\tracked\data\detailmapy\m1abrams_mg_mount.rvmat","ca\tracked\data\detailmapy\m1abrams_mg_mount_destruct.rvmat"};
		};
		ace_sa_defaultelevation = 46;
		ace_sa_defaultwindage = -7;
	};
};
//};
