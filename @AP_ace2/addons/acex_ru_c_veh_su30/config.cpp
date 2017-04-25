////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Aug 11 06:51:17 2014 : Created on Mon Aug 11 06:51:17 2014
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_su30 : config.bin{
class CfgPatches
{
	class acex_ru_veh_su30
	{
		Units[] = {"ACE_Su30"};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_ru_main","acex_c_vehicle","Extended_EventHandlers","CAAir3","CAAir3_Su34","CAWeapons","CA_Anims","CAData","acex_ru_m_veh_su30","acex_ru_t_veh_su30","acex_ru_c_veh_su_common","acex_ru_m_veh_su_common","acex_ru_t_veh_su_common"};
		version = "1.14.0.76";
		author[] = {"Aushilfe"};
	};
};
class CfgVehicles
{
	class Air;
	class Plane: Air
	{
		class NewTurret;
		class ViewPilot;
	};
	class ACE_Su30: Plane
	{
		ACE_hasAfterburner = 1;
		ace_afterburner_engines[] = {{1.14,-8.3,-1.0},{-1.14,-8.3,-1.0}};
		ACE_SYS_EJECT_EJECT = 1;
		ACE_SYS_EJECT_MULTICREW = 1;
		ACE_SYS_EJECT_JUMP = 0;
		ace_ejection_seat = "ACE_K36";
		ace_sys_missileguidance_limits[] = {-120,15,-180,180};
		ace_sys_missileguidance_tracklimits[] = {-120,15,-180,180};
		class UserActions
		{
			class LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player in [gunner this, driver this]) && {(getNumber(configFile>>'cfgWeapons'>>currentWeapon this>>'ace_sys_missileguidance_enableAirDesignator') == 1)}";
				statement = "[this,0,0] call ace_sys_missileguidance_fnc_Kh29_Lase";
			};
			class LaseKh29Off: LaseKh29
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(player in [gunner this, driver this]) && {(this getVariable 'ace_sys_missileguidance_tracking')}";
				statement = "this setVariable ['ace_sys_missileguidance_tracking',nil]";
			};
		};
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		lockdetectionsystem = 8;
		incommingmissliedetectionsystem = 8;
		viewDriverShadow = 1;
		castDriverShadow = 1;
		scope = 2;
		destrType = "DestructWreck";
		displayName = "$STR_ACE_VDN_SU30";
		vehicleClass = "Air";
		model = "\x\acex_ru\addons\m_veh_su30\su30MKK.p3d";
		icon = "\x\acex_ru\addons\c_veh_su30\data\icon\icon_su30MKK_ca.paa";
		mapSize = 20;
		side = 0;
		faction = "RU";
		crew = "RU_Soldier_Pilot";
		typicalCargo[] = {"RU_Soldier_Pilot"};
		camouflage = 10;
		audible = 6;
		accuracy = 0.2;
		supplyRadius = 8;
		memoryPointGun = "machinegun";
		memoryPointLRocket = "L raketa";
		memoryPointRRocket = "P raketa";
		laserScanner = 1;
		minFireTime = 30;
		gunAimDown = 0.065;
		weapons[] = {"ACE_GSh301","CMFlareLauncher"};
		magazines[] = {"ACE_150Rnd_30mm_GSh301","120Rnd_CMFlare_Chaff_Magazine"};
		threat[] = {1,1,1};
		soundGetIn[] = {"ca\sounds\Air\AV8\ext\ext-jetair-cabine-close1",0.056234,1};
		soundGetOut[] = {"ca\sounds\Air\AV8\ext\ext-jetair-cabine-open1",0.056234,1,20};
		soundDammage[] = {"ca\sounds\Air\AV8\int\alarm_loop1",0.562341,1};
		soundEngineOnInt[] = {"ca\sounds\Air\AV8\int\int-av8b-start-1",0.562341,1.0};
		soundEngineOnExt[] = {"ca\sounds\Air\AV8\ext\ext-jetair-start1",0.562341,1.0,900};
		soundEngineOffInt[] = {"ca\sounds\Air\AV8\int\int-av8b-stop-1",0.562341,1.0};
		soundEngineOffExt[] = {"ca\sounds\Air\AV8\ext\ext-jetair-stop1",0.562341,1.0,900};
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_30.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
		class Sounds
		{
			class EngineLowOut
			{
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-engine-low1",2.511886,1.0,1600};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "engineOn*camPos*(rpm factor[0.85, 0])";
			};
			class EngineHighOut
			{
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-engine-high3",2.511886,1.3,1800};
				frequency = "1";
				volume = "engineOn*camPos*(rpm factor[0.55, 1.0])";
			};
			class ForsageOut
			{
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-forsage1",2.511886,1.1,2000};
				frequency = "1";
				volume = "engineOn*camPos*(thrust factor[0.5, 1.0])";
				cone[] = {3.14,3.92,2.0,0.4};
			};
			class WindNoiseOut
			{
				sound[] = {"ca\sounds\Air\AV8\ext\ext-jetair-wind1",1.0,1.0,150};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};
			class EngineLowIn
			{
				sound[] = {"ca\sounds\Air\AV8\int\int-av8b-engine-low",0.562341,1.0};
				frequency = "1.0 min (rpm + 0.5)";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.85, 0]))";
			};
			class EngineHighIn
			{
				sound[] = {"ca\sounds\Air\AV8\int\int-av8b-engine",1.0,1.0};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(rpm factor[0.55, 1.0]))";
			};
			class ForsageIn
			{
				sound[] = {"ca\sounds\Air\AV8\int\int-av8b-forsage-1",0.562341,1.1};
				frequency = "1";
				volume = "(1-camPos)*(engineOn*(thrust factor[0.5, 1.0]))";
			};
			class WindNoiseIn
			{
				sound[] = {"ca\sounds\Air\AV8\int\int-jetair-wind1",0.707946,1.0};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])";
			};
		};
		DriverAction = "Su27_Pilot";
		class ViewPilot
		{
			initFov = 1;
			minFov = 0.3;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -65;
			maxAngleX = 85;
			initAngleY = 0;
			minAngleY = -125;
			maxAngleY = 125;
		};
		hasGunner = 1;
		driverIsCommander = 1;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				body = "";
				gun = "";
				commanding = -1;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				gunnerOpticsModel = "\x\acex_ru\addons\m_veh_su30\optika_SU30_gunner";
				gunnerForceOptics = 0;
				gunnerAction = "Su34_Gunner";
				gunnerInAction = "Su34_Gunner";
				class Viewoptics
				{
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = 0;
					maxAngleY = 0;
					initFov = 0.18;
					minFov = 0.18;
					maxFov = 0.4;
				};
				class ViewGunner
				{
					initFov = 1;
					minFov = 0.3;
					maxFov = 1.2;
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = "+85";
					initAngleY = 0;
					minAngleY = -135;
					maxAngleY = 135;
				};
				weapons[] = {"ACE_R73Launcher","ACE_R27Launcher","ACE_Kh29Launcher"};
				magazines[] = {"ACE_4Rnd_R73","ACE_6Rnd_Kh29","ACE_2Rnd_R27"};
			};
		};
		armor = 60;
		damageResistance = 0.00168;
		armorStructured = 1;
		landingAoa = "rad 10";
		landingSpeed = 235;
		maxSpeed = 1470;
		flapsFrictionCoef = 0.3;
		aileronSensitivity = 1.2;
		elevatorSensitivity = 1;
		gearUpTime = 4.5;
		gearDownTime = 3;
		envelope[] = {0.0,0.4,1.9,4,6.8,8.3,8.5,8,7.2,5.8,4,1.8,0};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_ru\addons\c_veh_su_common\Su_skla.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_in.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_in_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_skla_in_damage.rvmat","x\acex_ru\addons\c_veh_su30\Su30_01.rvmat","x\acex_ru\addons\c_veh_su30\Su30_01_damage.rvmat","x\acex_ru\addons\c_veh_su30\Su30_01_destruct.rvmat","x\acex_ru\addons\c_veh_su30\Su30_02.rvmat","x\acex_ru\addons\c_veh_su30\Su30_02_damage.rvmat","x\acex_ru\addons\c_veh_su30\Su30_02_destruct.rvmat","x\acex_ru\addons\c_veh_su_common\Su_interier.rvmat","x\acex_ru\addons\c_veh_su_common\Su_interier.rvmat","x\acex_ru\addons\c_veh_su_common\Su_interier_destruct.rvmat","x\acex_ru\addons\c_veh_su_common\Su_wheels.rvmat","x\acex_ru\addons\c_veh_su_common\Su_wheels_damage.rvmat","x\acex_ru\addons\c_veh_su_common\Su_wheels_destruct.rvmat"};
		};
		hiddenSelections[] = {"Camo1","Camo2","num1","num2","num3","ExtraJAM","ExtraPH"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_su30\body1_co.paa","\x\acex_ru\addons\t_veh_su30\body2_co.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_B2_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_B4_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_B7_ca.paa"};
		class Library
		{
			libEnable = 0;
			libTextDesc = "$STR_LANGLIB_Su30";
		};
		class Reflectors
		{
			class Left
			{
				color[] = {0.8,0.8,1.0,1.0};
				ambient[] = {0.07,0.07,0.07,1.0};
				position = "light_1_1_source";
				direction = "light_1_1_target";
				hitpoint = "L svetlo";
				selection = "L svetlo";
				size = 1;
				brightness = 1.0;
			};
			class right
			{
				color[] = {0.8,0.8,1.0,1.0};
				ambient[] = {0.07,0.07,0.07,1.0};
				position = "light_1_2_source";
				direction = "light_1_2_target";
				hitpoint = "P svetlo";
				selection = "P svetlo";
				size = 1;
				brightness = 1.0;
			};
		};
		class MarkerLights
		{
			class RedStill
			{
				name = "cerveny pozicni";
				color[] = {1.0,0.1,0.1,1};
				ambient[] = {0.1,0.01,0.01,1};
				brightness = 0.01;
				blinking = 0;
			};
			class GreenStill
			{
				name = "zeleny pozicni";
				color[] = {0.1,1.0,0.1,1};
				ambient[] = {0.01,0.1,0.01,1};
				brightness = 0.01;
				blinking = 0;
			};
			class WhiteStill
			{
				name = "bily pozicni";
				color[] = {1.0,1.0,1.0,1};
				ambient[] = {0.1,0.1,0.1,1};
				brightness = 0.01;
				blinking = 0;
			};
		};
		class MFD
		{
			borderLeft = 0.09;
			borderRight = 0.02;
			borderTop = 0.02;
			borderBottom = 0.1;
			class AirplaneHUD
			{
				topLeft = "HUD LH";
				topRight = "HUD PH";
				bottomLeft = "HUD LD";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0,1,0,0.1};
				class Pos10Vector
				{
					type = "vector";
					pos0[] = {0.5,0.27};
					pos10[] = {"0.5+0.9","0.27+0.7"};
				};
				class Bones
				{
					class AGLMove1
					{
						type = "fixed";
						source = "altitudeAGL";
						Pos[] = {0.78,0.175};
					};
					class AGLMove2
					{
						type = "fixed";
						pos[] = {0.05,0.8};
					};
					class ASLMove1
					{
						type = "linear";
						source = "altitudeASL";
						min = 0;
						max = 500;
						minPos[] = {0.1,0.1};
						maxPos[] = {0.1,0.8};
					};
					class ASLMove2
					{
						type = "fixed";
						pos[] = {0.1,0.8};
					};
					class VertSpeed
					{
						type = "linear";
						source = "vSpeed";
						min = -25;
						max = 25;
						minPos[] = {0,-0.4};
						maxPos[] = {0,0.4};
					};
					class SpdMove2
					{
						source = "speed";
						type = "fixed";
						Pos[] = {0.3,0.175};
					};
					class ILS
					{
						type = "ils";
						pos0[] = {0.5,0.4};
						pos3[] = {0.7,0.6};
					};
					class WeaponAim: Pos10Vector
					{
						source = "weapon";
						pos0[] = {0.5,-1.6};
					};
					class Target: Pos10Vector
					{
						source = "target";
					};
					class TargetDistanceMissile
					{
						type = "rotational";
						source = "targetDist";
						center[] = {0,0};
						min = 100;
						max = 3000;
						minAngle = -120;
						maxAngle = 120;
					};
					class TargetDistanceMGun
					{
						type = "rotational";
						source = "targetDist";
						center[] = {0,0};
						min = 100;
						max = 1000;
						minAngle = -180;
						maxAngle = 90;
					};
					class Level0: Pos10Vector
					{
						type = "horizon";
						angle = 0;
					};
					class LevelP5: Level0
					{
						angle = 5;
					};
					class LevelM5: Level0
					{
						angle = -5;
					};
					class LevelP10: Level0
					{
						angle = 10;
					};
					class LevelM10: Level0
					{
						angle = -10;
					};
					class LevelP15: Level0
					{
						angle = 15;
					};
					class LevelM15: Level0
					{
						angle = -15;
					};
					class Velocity: Pos10Vector
					{
						type = "vector";
						source = "velocity";
						pos0[] = {0.505,0.52};
					};
					class PlaneW
					{
						type = "fixed";
						pos[] = {0.5,0.27};
					};
				};
				class Draw
				{
					alpha = 0.6;
					color[] = {0,0.3,0};
					clipTL[] = {0.0,0.05};
					clipBR[] = {1.0,0.9};
					condition = "on";
					class Altitude
					{
						type = "text";
						align = "right";
						scale = 1;
						source = "altitudeAGL";
						sourceScale = 1;
						pos[] = {"AGLMove1",{-0.05,-0.03},1};
						right[] = {"AGLMove1",{0.01,-0.03},1};
						down[] = {"AGLMove1",{-0.05,0.03},1};
					};
					class DimmedBase
					{
						alpha = 0.3;
						class AltitudeBase
						{
							type = "line";
							points[] = {{"AGLMove2",1},{"ASLMove2",1}};
						};
					};
					class Speed{};
					class SpeedNumber
					{
						type = "text";
						align = "left";
						scale = 1;
						source = "speed";
						sourceScale = 3.6;
						pos[] = {"SpdMove2",{-0.05,-0.03},1};
						right[] = {"SpdMove2",{0.01,-0.03},1};
						down[] = {"SpdMove2",{-0.05,0.03},1};
					};
					class PlaneW
					{
						clipTL[] = {0.0,0.1};
						clipBR[] = {1.0,0.9};
						class LineHL{};
						class Velocity
						{
							type = "line";
							points[] = {{"Velocity",{0,-0.02},1},{"Velocity",{0.02,0},1},{"Velocity",{0,0.02},1},{"Velocity",{-0.02,0},1},{"Velocity",{0,-0.02},1}};
						};
					};
					class MGun
					{
						condition = "mgun";
						class Circle
						{
							type = "line";
							points[] = {{"WeaponAim",{0,-0.07},1},{"WeaponAim",{"+0.7*0.07","-0.7*0.07"},1},{"WeaponAim",{0.07,0},1},{"WeaponAim",{"+0.7*0.07","+0.7*0.07"},1},{"WeaponAim",{0,0.07},1},{"WeaponAim",{"-0.7*0.07","+0.7*0.07"},1},{"WeaponAim",{-0.07,0},1},{"WeaponAim",{"-0.7*0.07","-0.7*0.07"},1},{"WeaponAim",{0,-0.07},1},{},{"WeaponAim",{0,-0.01},1},{"WeaponAim",{"+0.7*0.01","-0.7*0.01"},1},{"WeaponAim",{0.01,0},1},{"WeaponAim",{"+0.7*0.01","+0.7*0.01"},1},{"WeaponAim",{0,0.01},1},{"WeaponAim",{"-0.7*0.01","+0.7*0.01"},1},{"WeaponAim",{-0.01,0},1},{"WeaponAim",{"-0.7*0.01","-0.7*0.01"},1},{"WeaponAim",{0,-0.01},1},{},{"WeaponAim",{"0.03*sin(-180)","-0.03*cos(-180)"},1},{"WeaponAim",{"0.07*sin(-180)","-0.07*cos(-180)"},1},{},{"WeaponAim",{"0.03*sin(+90)","-0.03*cos(+90)"},1},{"WeaponAim",{"0.07*sin(+90)","-0.07*cos(+90)"},1},{},{"WeaponAim",1,"TargetDistanceMGun",{0,0.04},1},{"WeaponAim",1,"TargetDistanceMGun",{0,0.07},1}};
						};
					};
					class Missile
					{
						condition = "missile";
						class Circle
						{
							type = "line";
							points[] = {{"WeaponAim",{0,-0.1},1},{"WeaponAim",{"+0.7*0.1","-0.7*0.1"},1},{"WeaponAim",{0.1,0},1},{"WeaponAim",{"+0.7*0.1","+0.7*0.1"},1},{"WeaponAim",{0,0.1},1},{"WeaponAim",{"-0.7*0.1","+0.7*0.1"},1},{"WeaponAim",{-0.1,0},1},{"WeaponAim",{"-0.7*0.1","-0.7*0.1"},1},{"WeaponAim",{0,-0.1},1},{},{"WeaponAim",{"0.1*0.8*sin(-120)","-0.1*0.8*cos(-120)"},1},{"WeaponAim",{"0.1*1.2*sin(-120)","-0.1*1.2*cos(-120)"},1},{},{"WeaponAim",{"0.1*0.8*sin(+120)","-0.1*0.8*cos(+120)"},1},{"WeaponAim",{"0.1*1.2*sin(+120)","-0.1*1.2*cos(+120)"},1},{},{"WeaponAim",1,"TargetDistanceMissile",{0,"0.1*0.8"},1},{"WeaponAim",1,"TargetDistanceMissile",{0,"0.1*1.2"},1}};
						};
						class Target
						{
							type = "line";
							points[] = {{"Target",{-0.05,-0.05},1},{"Target",{0.05,-0.05},1},{"Target",{0.05,0.05},1},{"Target",{-0.05,0.05},1},{"Target",{-0.05,-0.05},1}};
						};
					};
					class Horizont{};
					class ILS
					{
						condition = "ils";
						class Glideslope
						{
							clipTL[] = {0.29,0.29};
							clipBR[] = {0.71,0.71};
							class ILS
							{
								type = "line";
								points[] = {{"ILS",{-10,0},1},{"ILS",{10,0},1},{},{"ILS",{0,-10},1},{"ILS",{0,10},1}};
							};
						};
						class AOABracket
						{
							type = "line";
							points[] = {{{0.42,0.78},1},{{0.4,0.78},1},{{0.4,0.88},1},{{0.42,0.88},1}};
						};
					};
				};
			};
		};
	};
	class PlaneWreck;
	class ACE_Su30_Wreck: PlaneWreck
	{
		scope = 1;
		class Armory
		{
			disabled = 1;
		};
		model = "\ca\Air3\SU34\SU34Wreck.p3d";
		typicalCargo[] = {};
		irTarget = 0;
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		transportSoldier = 2;
	};
	class ACE_Su30_Des: ACE_Su30
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_ACE_VDN_SU30_MR";
		vehicleClass = "ACE_AirD";
		crew = "ACE_RU_Soldier_Pilot_D";
		hiddenSelections[] = {"Camo1","Camo2","num1","num2","num3","ExtraJAM","ExtraPH"};
		hiddenSelectionsTextures[] = {"\x\acex_ru\addons\t_veh_su30\body1_des_co.paa","\x\acex_ru\addons\t_veh_su30\body2_des_co.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R2_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R3_ca.paa","x\acex_ru\addons\t_veh_su_common\rus_num\number_R7_ca.paa"};
		weapons[] = {"ACE_GSh301","CMFlareLauncher"};
		magazines[] = {"ACE_150Rnd_30mm_GSh301","120Rnd_CMFlare_Chaff_Magazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_R73Launcher","ACE_R27Launcher","ACE_FAB500M62Launcher","ACE_KAB500KRLauncher","ACE_KAB500LLauncher"};
				magazines[] = {"ACE_4Rnd_R73","ACE_2Rnd_KAB500KR","ACE_2Rnd_KAB500L","ACE_2Rnd_FAB500M62","ACE_2Rnd_R27"};
			};
		};
	};
};
//};
