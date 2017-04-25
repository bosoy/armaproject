////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 02 21:00:05 2012 : Created on Fri Nov 02 21:00:05 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_veh_mah6 : config.bin{
class CfgPatches
{
	class acex_veh_mah6
	{
		units[] = {"ACE_AH6","ACE_MH6","ACE_AH6_GAU19"};
		weapons[] = {"ACE_GAU19","ACE_FFARLauncher_7"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","acex_main","acex_c_vehicle","acex_m_veh_mah6","acex_t_veh_mah6","CAAir_E_AH6J"};
		version = "1.14.0.369";
	};
};
class Extended_Init_EventHandlers
{
	class ACE_AH6J_DAGR_FLIR
	{
		class acex_veh_mah6
		{
			clientInit = "_this call ace_sys_air_fcs_fnc_playerinit";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class ACE_AH6J_DAGR_FLIR
	{
		acex_veh_mah6 = "if ((_this select 4) isKindOf 'MissileBase') then { if (local ((_this call CBA_fnc_getFirer) select 0)) then { _this call ace_sys_missileguidance_fnc_fired }}";
	};
};
class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class Turrets;
	};
	class AH6_Base_EP1: Helicopter
	{
		envelope[] = {2,3,4.25,5,6,6.4,6.4,6.6,6.6,6,4.8,3,2,1.7,1};
		class Turrets: Turrets
		{
			class MainTurret;
		};
	};
	class AH6J_EP1: AH6_Base_EP1
	{
		model = "\x\acex\addons\m_veh_mah6\ace_ah6_m134.p3d";
		dammagefull[] = {"\CA\Air_E\AH64\data\AH64D_mfd_normal_co.paa","\CA\Air_E\AH64\data\AH64D_mfd_malfc_co.paa"};
		dammagehalf[] = {"\CA\Air_E\AH64\data\AH64D_mfd_normal_co.paa","\CA\Air_E\AH64\data\AH64D_mfd_malfc_co.paa"};
	};
	class MH6J_EP1: AH6_Base_EP1
	{
		model = "\x\acex\addons\m_veh_mah6\ace_mh6.p3d";
	};
	class ACE_AH6_GAU19: AH6J_EP1
	{
		scope = 1;
		displayName = "AH-6J (GAU-19)";
		model = "\x\acex\addons\m_veh_mah6\ace_ah6_gau.p3d";
		Icon = "\x\acex\addons\c_veh_mah6\data\icon\icomap_ah6_lb_gau_ca.paa";
		weapons[] = {"ACE_FFARLauncher_7","ACE_GAU19","CMFlareLauncher"};
		magazines[] = {"ACE_7Rnd_70mm_FFAR_HE","ACE_900Rnd_127x99_GAU19","60Rnd_CMFlareMagazine"};
		gunBeg[] = {"muzzle_1"};
		gunEnd[] = {"chamber_1"};
		class AnimationSources
		{
			class Gatling_2
			{
				source = "revolving";
				weapon = "ACE_GAU19";
			};
		};
		ACE_canFastrope = 0;
		ACE_canLift = 0;
	};
	class ACE_AH6_GAU19_FLIR: AH6_Base_EP1
	{
		dammagefull[] = {"\CA\Air_E\AH64\data\AH64D_mfd_normal_co.paa","\CA\Air_E\AH64\data\AH64D_mfd_malfc_co.paa"};
		dammagehalf[] = {"\CA\Air_E\AH64\data\AH64D_mfd_normal_co.paa","\CA\Air_E\AH64\data\AH64D_mfd_malfc_co.paa"};
		scope = 1;
		side = 1;
		faction = "BIS_US";
		displayName = "AH-6J (GAU-19/FLIR)";
		model = "\x\acex\addons\m_veh_mah6\ace_ah6_gau_flir.p3d";
		Icon = "\x\acex\addons\c_veh_mah6\data\icon\icomap_ah6_lb_gau_ca.paa";
		isUAV = 0;
		crew = "US_Soldier_Pilot_EP1";
		typicalCargo[] = {"US_Soldier_Pilot_EP1"};
		weapons[] = {"FFARLauncher","ACE_GAU19","CMFlareLauncher"};
		magazines[] = {"ACE_19Rnd_70mm_FFAR_HE","ACE_900Rnd_127x99_GAU19","60Rnd_CMFlareMagazine"};
		transportSoldier = 0;
		threat[] = {0.6,0.4,0.1};
		radarType = 0;
		gunnerUsesPilotView = 0;
		ace_sys_turret_indicator_enable = 1;
		ACE_mfdClass = "ace_sys_mfd_AH64D_MFD_Dialog";
		class MFD
		{
			class AirplaneHUD
			{
				borderbottom = 0;
				borderleft = 0;
				borderright = 0;
				bordertop = 0;
				bottomleft = "HUD LD";
				color[] = {0,1,0,0.1};
				helmetdown[] = {0,-0.05,0};
				helmetmounteddisplay = 1;
				helmetposition[] = {-0.025,0.023,0.1};
				helmetright[] = {0.05,0,0};
				topleft = "HUD LH";
				topright = "HUD PH";
				class Pos10Vector
				{
					pos0[] = {0.5,"0.27+0.23"};
					pos10[] = {0.85,0.85};
					type = "vector";
				};
				class Bones
				{
					class PlaneW
					{
						pos[] = {0.5,"0.34+0.23"};
						type = "fixed";
					};
					class WeaponAim: Pos10Vector
					{
						pos0[] = {0.5,"0.27+0.23"};
						pos10[] = {0.85,0.85};
						source = "weapon";
						type = "vector";
					};
					class GunnerAim: Pos10Vector
					{
						pos0[] = {0,-0.0025};
						pos10[] = {0.01,0.0025};
						source = "weapon";
						type = "vector";
					};
					class Target: Pos10Vector
					{
						pos0[] = {0.5,"0.27+0.23"};
						pos10[] = {0.85,0.85};
						source = "target";
						type = "vector";
					};
					class Velocity: Pos10Vector
					{
						pos0[] = {0.5,"0.27+0.23"};
						pos10[] = {0.85,0.85};
						source = "velocity";
						type = "vector";
					};
					class ILS_H
					{
						pos0[] = {0.5,"0.27+0.23"};
						pos3[] = {0.605,"0.27+0.23"};
						type = "ils";
					};
					class ILS_W: ILS_H
					{
						pos0[] = {0.5,"0.27+0.23"};
						pos3[] = {0.5,0.605};
						type = "ils";
					};
					class Level0: Pos10Vector
					{
						angle = 0;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelP10: Level0
					{
						angle = 10;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelM10: Level0
					{
						angle = -10;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelP20: Level0
					{
						angle = 20;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelM20: Level0
					{
						angle = -20;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelP30: Level0
					{
						angle = 30;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelM30: Level0
					{
						angle = -30;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelP40: Level0
					{
						angle = 40;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelM40: Level0
					{
						angle = -40;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelP50: Level0
					{
						angle = 50;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
					class LevelM50: Level0
					{
						angle = -50;
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
					};
				};
				class Draw
				{
					alpha = 0.6;
					color[] = {0,0.5,0.05};
					condition = "on";
					class PlaneW
					{
						clipbr[] = {1,0};
						cliptl[] = {0,1};
						points[] = {{"PlaneW",{0,-0.02},1},{"PlaneW",{0.014,-0.014},1},{"PlaneW",{0.02,0},1},{"PlaneW",{0.014,0.014},1},{"PlaneW",{0,0.02},1},{"PlaneW",{-0.014,0.014},1},{"PlaneW",{-0.02,0},1},{"PlaneW",{-0.014,-0.014},1},{"PlaneW",{0,-0.02},1},{}};
						type = "line";
						width = 4;
					};
					class PlaneHeading
					{
						clipbr[] = {1,0};
						cliptl[] = {0,1};
						points[] = {{"Velocity",{0,-0.02},1},{"Velocity",{0.014,-0.014},1},{"Velocity",{0.02,0},1},{"Velocity",{0.014,0.014},1},{"Velocity",{0,0.02},1},{"Velocity",{-0.014,0.014},1},{"Velocity",{-0.02,0},1},{"Velocity",{-0.014,-0.014},1},{"Velocity",{0,-0.02},1},{},{"Velocity",{0.04,0},1},{"Velocity",{0.02,0},1},{},{"Velocity",{-0.04,0},1},{"Velocity",{-0.02,0},1},{},{"Velocity",{0,-0.04},1},{"Velocity",{0,-0.02},1},{}};
						type = "line";
						width = 4;
					};
					class Static
					{
						clipbr[] = {1,0};
						cliptl[] = {0,0.1};
						points[] = {{{0.79,0.52},1},{{0.81,0.5},1},{{0.79,0.48},1},{},{{0.52,"0.08+0.06"},1},{{0.5,"0.06+0.06"},1},{{0.48,"0.08+0.06"},1},{},{{"0.5-0.1","0.9-0.04"},1},{{"0.5-0.1","0.9+0.04"},1},{{"0.5+0.1","0.9+0.04"},1},{{"0.5+0.1","0.9-0.04"},1},{{"0.5-0.1","0.9-0.04"},1},{},{{"0.5-0.1",0.9},1},{{"0.5-0.092",0.9},1},{},{{"0.5+0.1",0.9},1},{{"0.5+0.092",0.9},1},{},{{0.5,"0.9-0.04"},1},{{0.5,"0.9-0.032"},1},{},{{0.5,"0.9+0.04"},1},{{0.5,"0.9+0.032"},1},{}};
						type = "line";
						width = 4;
					};
					class Aim
					{
						type = "line";
						points[] = {{"WeaponAim",{0.05,0},1},{"WeaponAim",{0.015,0},1},{},{"WeaponAim",{0,0.05},1},{"WeaponAim",{0,0.015},1},{},{"WeaponAim",{-0.05,0},1},{"WeaponAim",{-0.015,0},1},{},{"WeaponAim",{0,-0.05},1},{"WeaponAim",{0,-0.015},1},{}};
						width = 4;
					};
					class Gunner
					{
						points[] = {{"GunnerAim",{"0.5-0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9-0.008"},1}};
						type = "line";
						width = 4;
					};
					class Target
					{
						points[] = {{"Target",{-0.05,-0.05},1},{"Target",{0.05,-0.05},1},{"Target",{0.05,0.05},1},{"Target",{-0.05,0.05},1},{"Target",{-0.05,-0.05},1}};
						type = "line";
					};
					class SpeedNumber
					{
						align = "right";
						down[] = {{0.06,0.52},1};
						pos[] = {{0.06,0.47},1};
						right[] = {{"0.14-0.02",0.47},1};
						scale = 1;
						source = "speed";
						sourcescale = 3.6;
						type = "text";
					};
					class AltNumber: SpeedNumber
					{
						align = "right";
						down[] = {{"0.86-0.15",0.52},1};
						pos[] = {{"0.86-0.15",0.47},1};
						right[] = {{"0.94-0.15-0.02",0.47},1};
						scale = 1;
						source = "altitudeAGL";
						sourcescale = 1;
						type = "text";
					};
					class AltScale
					{
						align = "right";
						bottom = 0.2;
						center = 0.5;
						down[] = {0.86,0.87};
						horizontal = 0;
						linexleft = 0.825;
						linexleftmajor = 0.825;
						lineyright = 0.835;
						lineyrightmajor = 0.845;
						majorlineeach = 5;
						max = "none";
						min = "none";
						numbereach = 5;
						pos[] = {0.86,0.82};
						right[] = {"0.94-0.02",0.82};
						scale = 1;
						source = "altitudeAGL";
						sourcescale = 1;
						step = 20;
						stepsize = "(0.85- 0.2)/20";
						top = 0.85;
						type = "scale";
						width = 4;
					};
					class weapons
					{
						align = "right";
						down[] = {{0.1,0.92},1};
						pos[] = {{0.1,0.88},1};
						right[] = {{"0.16-0.02",0.88},1};
						scale = 0.5;
						source = "weapon";
						sourcescale = 1;
						type = "text";
					};
					class ammo
					{
						align = "right";
						down[] = {{0.1,0.97},1};
						pos[] = {{0.1,0.93},1};
						right[] = {{"0.16-0.02",0.93},1};
						scale = 0.5;
						source = "ammo";
						sourcescale = 1;
						type = "text";
					};
					class HeadingScale
					{
						align = "center";
						bottom = 0.7;
						center = 0.5;
						down[] = {"0.32-0.01","0.04+0.05"};
						horizontal = 1;
						linexleft = "0.06+0.05";
						linexleftmajor = "0.07+0.05";
						lineyright = "0.05+0.05";
						lineyrightmajor = "0.04+0.05";
						majorlineeach = 3;
						max = "none";
						min = "none";
						numbereach = 3;
						pos[] = {"0.32-0.01","0.0+0.05"};
						right[] = {"0.38-0.01","0.0+0.05"};
						scale = 1;
						source = "Heading";
						sourcescale = 1;
						step = 10;
						stepsize = "(0.70- 0.3)/15";
						top = 0.3;
						type = "scale";
						width = 4;
					};
					class HorizontalLine
					{
						clipbr[] = {0.8,0.96};
						cliptl[] = {0.2,0.12};
						class HorizontalLineDraw
						{
							points[] = {{"Level0",{"-6*0.075/2",0.02},1},{"Level0",{"-5*0.075/2",0.02},1},{},{"Level0",{"-4*0.075/2",0.02},1},{"Level0",{"-3*0.075/2",0.02},1},{},{"Level0",{"-2*0.075/2",0.02},1},{"Level0",{"-1*0.075/2",0.02},1},{},{"Level0",{"1*0.075/2",0.02},1},{"Level0",{"2*0.075/2",0.02},1},{},{"Level0",{"3*0.075/2",0.02},1},{"Level0",{"4*0.075/2",0.02},1},{},{"Level0",{"5*0.075/2",0.02},1},{"Level0",{"6*0.075/2",0.02},1}};
							source = "Level0";
							type = "line";
						};
					};
				};
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				proxyIndex = 1;
				hasgunner = 1;
				body = "flir_turret";
				gun = "flir_gun";
				animationSourceBody = "flir_turret";
				animationSourceGun = "flir_gun";
				gunBeg = "flir_end";
				gunEnd = "flir_begin";
				memoryPointGun = "flir_end";
				memoryPointGunnerOptics = "flir_end";
				commanding = -1;
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = -3;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333 + 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333 + 0.41667";
				};
				class Viewoptics
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = -3;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333/6";
					minFov = "0.33333/32";
					maxFov = "0.33333/1";
					visionMode[] = {"Normal","Ti"};
					thermalMode[] = {0,1};
				};
				gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
				gunnerForceOptics = 0;
				gunnerOpticsShowCursor = 0;
				gunnerAction = "AH6_Gunner";
				gunnerInAction = "AH6_Gunner";
				gunnerGetInAction = "";
				gunnerGetOutAction = "";
				minElev = -90;
				maxElev = 30;
				minTurn = -180;
				maxTurn = 180;
				weapons[] = {"FakeWeapon","ACE_SACLOS_Guidance"};
				magazines[] = {"ACE_SACLOS_Guidance"};
				ace_sys_missileguidance_tracker = "ACE_SACLOS_Guidance";
				ace_sys_missileguidance_limitsOn = 1;
				ace_sys_missileguidance_limits[] = {20,20,0,0};
				ace_sys_missileguidance_tracklimits[] = {30,30};
				class OpticsIn
				{
					class VeryWide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						opticsDisplayName = "E";
						initFov = "0.33333/1";
						minFov = "0.33333/1";
						maxFov = "0.33333/1";
						visionMode[] = {"Normal","TI"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
					};
					class Wide: VeryWide
					{
						opticsDisplayName = "W";
						initFov = "0.33333/6";
						minFov = "0.33333/6";
						maxFov = "0.33333/6";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64_3";
					};
					class Medium: VeryWide
					{
						opticsDisplayName = "M";
						initFov = "0.33333/18";
						minFov = "0.33333/18";
						maxFov = "0.33333/18";
						gunnerOpticsModel = "\ca\air_e\gunnerOptics_ah64";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = "0.33333 + 0.41667";
						minFov = 0.33333;
						maxFov = "0.33333 + 0.41667";
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
		class TransportWeapons{};
		gunBeg[] = {"muzzle_1"};
		gunEnd[] = {"chamber_1"};
		class AnimationSources
		{
			class Gatling_2
			{
				source = "revolving";
				weapon = "ACE_GAU19";
			};
		};
		ACE_canFastrope = 0;
		ACE_canLift = 0;
		class UserActions
		{
			class Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_ON";
				position = "HitGlass3";
				radius = 6;
				onlyForPlayer = 1;
				condition = "(player == gunner this) && {(alive this)} && {isNil {this getVariable 'ace_sys_missileguidance_laser_designation'}}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_designation',true]; [this, currentWeapon this, true] spawn ace_sys_missileguidance_fnc_opt_laserloop";
			};
			class Laser_Off: Laser_On
			{
				displayName = "$STR_ACE_UA_LASER_OFF";
				condition = "(player == gunner this) && {(alive this)} && {(this getVariable 'ace_sys_missileguidance_laser_designation')}";
				statement = "this setVariable ['ace_sys_missileguidance_laser_off',true]";
			};
		};
	};
	class ACE_AH6J_DAGR_FLIR: ACE_AH6_GAU19_FLIR
	{
		scope = 2;
		displayName = "AH-6J (DAGR/FLIR)";
		model = "\x\acex\addons\m_veh_mah6\ace_ah6_DAGR_FLIR.p3d";
		weapons[] = {"ACE_FFARLauncher_7","TwinM134","CMFlareLauncher"};
		magazines[] = {"ACE_7Rnd_70mm_FFAR_HE","ACE_5250Rnd_762x51_M134","60Rnd_CMFlareMagazine"};
		gunBeg[] = {"muzzle_1","muzzle_2"};
		gunEnd[] = {"chamber_1","chamber_2"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"ACE_DAGR_Launcher","ACE_SACLOS_Guidance"};
				magazines[] = {"ACE_8Rnd_DAGR","ACE_SACLOS_Guidance"};
				gunEnd = "flir_end";
				gunBeg = "flir_begin";
			};
		};
		class AnimationSources
		{
			class Gatling_1
			{
				source = "revolving";
				weapon = "TwinM134";
			};
			class Gatling_2
			{
				source = "revolving";
				weapon = "TwinM134";
			};
		};
		ACE_canFastrope = 0;
		ACE_canLift = 0;
		ace_air_fcs_enabled = 1;
		ACE_mfdClass = "ace_sys_mfd_AH64D_MFD_Dialog";
	};
};
class CfgNonAIVehicles
{
	class ProxyWeapon;
	class Proxyace_dagr: ProxyWeapon
	{
		model = "\x\acex\addons\m_veh_mah6\ace_dagr.p3d";
		simulation = "maverickweapon";
	};
};
class CfgAmmo
{
	class M_Hellfire_AT;
	class ACE_M_DAGR_HE: M_Hellfire_AT
	{
		model = "\x\acex\addons\m_veh_mah6\ace_dagr.p3d";
		proxyShape = "\x\acex\addons\m_veh_mah6\ace_dagr_proxy.p3d";
	};
};
class CfgWeapons
{
	class CannonCore;
	class M197: CannonCore
	{
		class manual;
	};
	class ACE_GAU19: M197
	{
		class manual: manual
		{
			soundBurst = 1;
			begin1[] = {"\x\acex\addons\c_veh_mah6\gau19_fire",10,1.02,2300};
			begin2[] = {"\x\acex\addons\c_veh_mah6\gau19_fire",10,1,2300};
			begin3[] = {"\x\acex\addons\c_veh_mah6\gau19_fire",10,0.98,2300};
			soundBegin[] = {"begin1",0.33,"begin2",0.34,"begin3",0.33};
		};
	};
};
//};
