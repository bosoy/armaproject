////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:40:19 2012 : Created on Fri Nov 09 22:40:19 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_c_veh_ah1 : config.bin{
class CfgPatches
{
	class acex_usnavy_veh_ah1
	{
		units[] = {"ACE_AH1_Base","ACE_AH1","ACE_AH1W","ACE_AH1Z"};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAAir","acex_usnavy_main","acex_usnavy_m_veh_ah1","acex_usnavy_s_veh_ah1","acex_usnavy_t_veh_ah1","acex_usnavy_veh_air_wep"};
		version = "1.14.0.77";
		author[] = {"Aushilfe"};
	};
};
class Extended_PreInit_EventHandlers
{
	class acex_usnavy_veh_ah1
	{
		init = "call ('\x\acex_usnavy\addons\c_veh_ah1\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_GetIn_EventHandlers
{
	class AH1_Base
	{
		acex_usnavy_veh_ah1_cobra_getin = "if (local (_this select 0)) then { _this spawn acex_usnavy_veh_ah1_fnc_cobra_getinout}";
	};
};
class Extended_GetOut_EventHandlers
{
	class AH1_Base
	{
		acex_usnavy_veh_ah1_cobra_getout = "if (local (_this select 0)) then { _this spawn acex_usnavy_veh_ah1_fnc_cobra_getinout}";
	};
};
class Extended_FiredBis_EventHandlers
{
	class AH1_Base
	{
		class acex_usnavy_veh_ah1_gatling
		{
			clientFiredBis = "if ((_this select 4) isKindOf 'BulletBase' && local (_this select 0)) then { [_this select 0,'20mmBarrels',0.5] call ace_sys_vehicle_fnc_gatling }";
		};
	};
};
class CfgVehicles
{
	class AllVehicles;
	class Air: AllVehicles
	{
		class NewTurret;
		class ViewPilot;
	};
	class Helicopter: Air
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
			};
		};
		class HitPoints;
		class HitRGlass;
		class HitLGlass;
		class HitGlass1;
		class HitGlass2;
		class HitGlass3;
		class HitGlass4;
		class HitGlass5;
		class AnimationSources;
		class UserActions;
	};
	class AH1_Base: Helicopter
	{
		ACE_mfdClass = "ace_sys_mfd_AH64D_MFD_Dialog";
	};
	class ACE_AH1_Base: AH1_Base
	{
		scope = 1;
		selectionHRotorStill = "mainRotorStatic";
		selectionHRotorMove = "mainRotorBlurred";
		selectionVRotorStill = "tailRotorStatic";
		selectionVRotorMove = "tailRotorBlurred";
		memoryPointLMissile = "Missile_1";
		memoryPointRMissile = "Missile_2";
		memoryPointLRocket = "Rocket_1";
		memoryPointRRocket = "Rocket_2";
		selectionFireAnim = "muzzleflash";
		crew = "USMC_Soldier_Pilot";
		side = 1;
		faction = "ACE_USMC_Desert";
		displayName = "AH-1 Cobra";
		driverAction = "AH1Z_Pilot";
		memoryPointsGetInDriver = "pos_driver";
		memoryPointsGetInDriverDir = "pos_driver_dir";
		getInAction = "GetInHigh";
		getOutAction = "GetOutHigh";
		maxSpeed = 320;
		typicalCargo[] = {"USMC_Soldier_Pilot","USMC_Soldier_Pilot"};
		driverCompartments = "Compartment1";
		armor = 60;
		laserScanner = 1;
		destrType = "DestructWreck";
		crewVulnerable = 1;
		cost = 10000000;
		fuelCapacity = "120 * 4";
		model = "\ca\air\ah1z";
		picture = "\ca\air\data\ico\ah1z_CA.paa";
		mapSize = 15.5;
		Icon = "\ca\air\data\map_ico\icomap_ah1z_CA.paa";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				gunnerAction = "AH1Z_Gunner";
				gunnerInAction = "AH1Z_Gunner";
				gunnerCompartments = "Compartment2";
				weapons[] = {"M197","HellfireLauncher"};
				magazines[] = {"ACE_1Rnd_HellfirePod","ACE_1Rnd_HellfirePod","ACE_1Rnd_LAU61","ACE_1Rnd_LAU68","750Rnd_M197_AH1","8Rnd_Hellfire"};
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				memoryPointGun = "machinegun";
				minElev = -50;
				maxElev = 21;
				initElev = 5;
				minTurn = -110;
				maxTurn = 110;
				gunnerOpticsModel = "\ca\air\optika_AH1Z";
				gunnerOpticsEffect[] = {};
				enableManualFire = 1;
				ace_sys_missileguidance_tracker = "M197";
				ace_sys_missileguidance_limitsOn = 1;
				ace_sys_missileguidance_limits[] = {20,20,0,0};
				ace_sys_missileguidance_tracklimits[] = {30,30};
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = -3;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewOptics
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
					visionMode[] = {"Normal","TI"};
				};
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
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_AH1Z_2";
					};
					class Wide: VeryWide
					{
						opticsDisplayName = "W";
						initFov = "0.33333/6";
						minFov = "0.33333/6";
						maxFov = "0.33333/6";
						gunnerOpticsModel = "\x\ace\addons\m_veh_optics\optika_AH1Z_2";
					};
					class Medium: VeryWide
					{
						opticsDisplayName = "M";
						initFov = "0.33333/18";
						minFov = "0.33333/18";
						maxFov = "0.33333/18";
						gunnerOpticsModel = "\ca\air\optika_AH1Z";
					};
					class Narrow: VeryWide
					{
						opticsDisplayName = "N";
						initFov = "0.33333/32";
						minFov = "0.33333/32";
						maxFov = "0.33333/32";
						gunnerOpticsModel = "\ca\air\optika_AH1Z";
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
						initFov = "0.33333+ 0.41667";
						minFov = 0.33333;
						maxFov = "0.33333+ 0.41667";
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
			};
		};
		class HitPoints: HitPoints
		{
			class HitRGlass: HitRGlass
			{
				armor = 1.5;
			};
			class HitLGlass: HitLGlass
			{
				armor = 1.5;
			};
			class HitGlass2: HitGlass2
			{
				armor = 1.5;
			};
			class HitGlass3: HitGlass3
			{
				armor = 1.5;
			};
			class HitGlass4: HitGlass4
			{
				armor = 1.5;
			};
			class HitGlass5: HitGlass5
			{
				armor = 1.5;
			};
		};
		threat[] = {0.3,1,0.8};
		hiddenSelections[] = {"body","engine"};
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1w_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1w_engines_co.paa"};
		class AnimationSources: AnimationSources
		{
			class 20mmBarrels
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class PilotDoor
			{
				source = "user";
				animPeriod = 0.75;
				initPhase = 0;
			};
			class GunnerDoor
			{
				source = "user";
				animPeriod = 0.75;
				initPhase = 0;
			};
		};
		class UserActions: UserActions
		{
			class OpenPDoor
			{
				displayName = "$STR_ACE_UA_PWINDOWOPEN";
				position = "PilotWindow";
				radius = 1.8;
				onlyForPlayer = 1;
				condition = "if (alive this) then {if (gunner this != player) then {if (this animationPhase 'PilotWindow' == 0) then {if ((getPos this select 2) < 3) then {(abs (speed this) < 3)} else {false}} else {false}} else {false}} else {false};";
				statement = "['ace_cobra_op', this] call CBA_fnc_globalEvent;";
			};
			class ClosePDoor: OpenPDoor
			{
				displayName = "$STR_ACE_UA_PWINDOWCLOSE";
				condition = "if (alive this) then {if (gunner this != player) then {(this animationPhase 'PilotWindow' > 0)} else {false}} else {false};";
				statement = "['ace_cobra_cp', this] call CBA_fnc_globalEvent;";
			};
			class OpenGDoor: OpenPDoor
			{
				displayName = "$STR_ACE_UA_GWINDOWOPEN";
				position = "GunnerWindow";
				condition = "if (alive this) then {if (driver this != player) then {if (this animationPhase 'GunnerWindow' == 0) then {if ((getPos this select 2) < 3) then {(abs (speed this) < 3)} else {false}} else {false}} else {false}} else {false};";
				statement = "['ace_cobra_og', this] call CBA_fnc_globalEvent;";
			};
			class CloseGDoor: OpenGDoor
			{
				displayName = "$STR_ACE_UA_GWINDOWCLOSE";
				condition = "if (alive this) then {if (driver this != player) then {(this animationPhase 'GunnerWindow' > 0)} else {false}} else {false};";
				statement = "['ace_cobra_cg', this] call CBA_fnc_globalEvent;";
			};
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
		class Library
		{
			libTextDesc = "$STR_LIB_AH1Z";
		};
		dammageHalf[] = {"\Ca\air\data\ah1z_monitor_glass_ca.paa","\Ca\air\data\ah1z_monitor_glass_destr_co.paa"};
		dammageFull[] = {"\Ca\air\data\ah1z_monitor_glass_ca.paa","\Ca\air\data\ah1z_monitor_glass_destr_co.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\air\data\ah1z_body.rvmat","ca\air\data\ah1z_body_damage.rvmat","ca\air\data\ah1z_body_destruct.rvmat","ca\air\data\ah1z_glass.rvmat","ca\air\data\ah1z_glass_damage.rvmat","ca\air\data\ah1z_glass_damage.rvmat","ca\air\data\ah1z_glass_in.rvmat","ca\air\data\ah1z_glass_in_damage.rvmat","ca\air\data\ah1z_glass_in_damage.rvmat","ca\air\data\ah1z_cockpit.rvmat","ca\air\data\ah1z_cockpit.rvmat","ca\air\data\ah1z_cockpit_destruct.rvmat","ca\air\data\ah1z_engines.rvmat","ca\air\data\ah1z_engines_damage.rvmat","ca\air\data\ah1z_engines_destruct.rvmat","Ca\air\data\ah1z_monitors.rvmat","Ca\air\data\ah1z_monitors.rvmat","Ca\air\data\ah1z_monitors_destruct.rvmat"};
		};
	};
	class AH1Z: AH1_Base
	{
		displayName = "AH-1Z (AGM-114/FFAR)";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","120Rnd_CMFlareMagazine"};
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1z_d_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1z_d_engines_co.paa"};
		selectionHRotorStill = "mainRotorStatic";
		selectionHRotorMove = "mainRotorBlurred";
		selectionVRotorStill = "tailRotorStatic";
		selectionVRotorMove = "tailRotorBlurred";
		memoryPointLMissile = "Missile_1";
		memoryPointRMissile = "Missile_2";
		memoryPointLRocket = "Rocket_1";
		memoryPointRRocket = "Rocket_2";
		selectionFireAnim = "muzzleflash";
		crew = "USMC_Soldier_Pilot";
		side = 1;
		driverAction = "AH1Z_Pilot";
		memoryPointsGetInDriver = "pos_driver";
		memoryPointsGetInDriverDir = "pos_driver_dir";
		getInAction = "GetInHigh";
		getOutAction = "GetOutHigh";
		maxSpeed = 320;
		driverCompartments = "Compartment1";
		armor = 60;
		laserScanner = 1;
		destrType = "DestructWreck";
		crewVulnerable = 1;
		cost = 10000000;
		fuelCapacity = "120 * 4";
		picture = "\ca\air\data\ico\ah1z_CA.paa";
		mapSize = 15.5;
		Icon = "\ca\air\data\map_ico\icomap_ah1z_CA.paa";
		accuracy = 1000;
		model = "\x\acex_usnavy\addons\m_veh_ah1\AUS_AH1Z";
		class Sounds
		{
			class Engine
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1z_t.wss",1.77828,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1zRb.wss",5.62341,1,4000};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\uh1y_a.wss",5.62341,1,4000};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1z_int.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1zRb.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))*0.75";
			};
			class RotorHighIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\uh1y_a.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)*0.75";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M197","SidewinderLaucher_AH1Z","ACE_HellfireLauncher"};
				magazines[] = {"2Rnd_Sidewinder_AH1Z","ACE_1Rnd_HellfirePod","ACE_1Rnd_HellfirePod","ACE_1Rnd_LAU61","ACE_1Rnd_LAU61","750Rnd_M197_AH1","ACE_8Rnd_Hellfire"};
				gunnerAction = "AH1Z_Gunner";
				gunnerInAction = "AH1Z_Gunner";
				gunnerCompartments = "Compartment2";
				memoryPointsGetInGunner = "pos_gunner";
				memoryPointsGetInGunnerDir = "pos_gunner_dir";
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				memoryPointGun = "machinegun";
				minElev = -50;
				maxElev = 21;
				initElev = 5;
				minTurn = -110;
				maxTurn = 110;
				gunnerOpticsModel = "\ca\air\optika_AH1Z";
				enableManualFire = 1;
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = -3;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333+ 0.41667";
					minFov = 0.33333;
					maxFov = "0.33333+ 0.41667";
				};
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -40;
					maxAngleX = 40;
					initAngleY = -3;
					minAngleY = -155;
					maxAngleY = 155;
					initFov = "0.33333+ 0.41667";
					minFov = 0.04;
					maxFov = "0.33333+ 0.41667";
				};
			};
		};
		class HitPoints: HitPoints
		{
			class HitRGlass: HitRGlass
			{
				armor = 1.5;
			};
			class HitLGlass: HitLGlass
			{
				armor = 1.5;
			};
			class HitGlass2: HitGlass2
			{
				armor = 1.5;
			};
			class HitGlass3: HitGlass3
			{
				armor = 1.5;
			};
			class HitGlass4: HitGlass4
			{
				armor = 1.5;
			};
			class HitGlass5: HitGlass5
			{
				armor = 1.5;
			};
		};
		threat[] = {0.3,1,0.8};
		hiddenSelections[] = {"body","engine"};
		class AnimationSources: AnimationSources
		{
			class 20mmBarrels
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class PilotDoor
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
			class GunnerDoor
			{
				source = "user";
				animPeriod = 1;
				initPhase = 0;
			};
		};
		class UserActions: UserActions
		{
			class OpenPDoor
			{
				displayName = "$STR_ACE_UA_PWINDOWOPEN";
				position = "PilotWindow";
				radius = 1.8;
				onlyForPlayer = 1;
				condition = "if (alive this) then {if (gunner this != player) then {if (this animationPhase 'PilotWindow' == 0) then {if ((getPos this select 2) < 3) then {(abs (speed this) < 3)} else {false}} else {false}} else {false}} else {false};";
				statement = "['ace_cobra_op', this] call CBA_fnc_globalEvent;";
			};
			class ClosePDoor: OpenPDoor
			{
				displayName = "$STR_ACE_UA_PWINDOWCLOSE";
				condition = "if (alive this) then {if (gunner this != player) then {(this animationPhase 'PilotWindow' > 0)} else {false}} else {false};";
				statement = "['ace_cobra_cp', this] call CBA_fnc_globalEvent;";
			};
			class OpenGDoor: OpenPDoor
			{
				displayName = "$STR_ACE_UA_GWINDOWOPEN";
				position = "GunnerWindow";
				condition = "if (alive this) then {if (driver this != player) then {if (this animationPhase 'GunnerWindow' == 0) then {if ((getPos this select 2) < 3) then {(abs (speed this) < 3)} else {false}} else {false}} else {false}} else {false};";
				statement = "['ace_cobra_og', this] call CBA_fnc_globalEvent;";
			};
			class CloseGDoor: OpenGDoor
			{
				displayName = "$STR_ACE_UA_GWINDOWCLOSE";
				condition = "if (alive this) then {if (driver this != player) then {(this animationPhase 'GunnerWindow' > 0)} else {false}} else {false};";
				statement = "['ace_cobra_cg', this] call CBA_fnc_globalEvent;";
			};
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
		class Library
		{
			libTextDesc = "$STR_LIB_AH1Z";
		};
		dammageHalf[] = {"\Ca\air\data\ah1z_monitor_glass_ca.paa","\Ca\air\data\ah1z_monitor_glass_destr_co.paa"};
		dammageFull[] = {"\Ca\air\data\ah1z_monitor_glass_ca.paa","\Ca\air\data\ah1z_monitor_glass_destr_co.paa"};
		class Damage
		{
			tex[] = {};
			mat[] = {"ca\air\data\ah1z_body.rvmat","ca\air\data\ah1z_body_damage.rvmat","ca\air\data\ah1z_body_destruct.rvmat","ca\air\data\ah1z_glass.rvmat","ca\air\data\ah1z_glass_damage.rvmat","ca\air\data\ah1z_glass_damage.rvmat","ca\air\data\ah1z_glass_in.rvmat","ca\air\data\ah1z_glass_in_damage.rvmat","ca\air\data\ah1z_glass_in_damage.rvmat","ca\air\data\ah1z_cockpit.rvmat","ca\air\data\ah1z_cockpit.rvmat","ca\air\data\ah1z_cockpit_destruct.rvmat","ca\air\data\ah1z_engines.rvmat","ca\air\data\ah1z_engines_damage.rvmat","ca\air\data\ah1z_engines_destruct.rvmat","Ca\air\data\ah1z_monitors.rvmat","Ca\air\data\ah1z_monitors.rvmat","Ca\air\data\ah1z_monitors_destruct.rvmat"};
		};
		class MFD
		{
			class AirplaneHUD
			{
				class Pos10Vector
				{
					type = "vector";
					pos0[] = {0.5,"0.27+0.23"};
					pos10[] = {0.85,0.85};
				};
				topLeft = "HUD LH";
				topRight = "HUD PH";
				bottomLeft = "HUD LD";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0,1,0,0.1};
				class Bones
				{
					class PlaneW
					{
						type = "fixed";
						pos[] = {0.5,"0.34+0.23"};
					};
					class WeaponAim: Pos10Vector
					{
						source = "weapon";
					};
					class GunnerAim: Pos10Vector
					{
						source = "weapon";
						pos0[] = {0,-0.0025};
						pos10[] = {0.01,0.0025};
					};
					class Target: Pos10Vector
					{
						source = "target";
					};
					class Velocity: Pos10Vector
					{
						type = "vector";
						source = "velocity";
						pos0[] = {0.5,"0.27+0.23"};
						pos10[] = {0.85,0.85};
					};
					class ILS_H
					{
						type = "ils";
						pos0[] = {0.5,"0.27+0.23"};
						pos3[] = {0.605,"0.27+0.23"};
					};
					class ILS_W: ILS_H
					{
						pos3[] = {0.5,0.605};
					};
					class Level0: Pos10Vector
					{
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
						angle = 0;
					};
					class LevelP10: Level0
					{
						angle = 10;
					};
					class LevelM10: Level0
					{
						angle = -10;
					};
					class LevelP20: Level0
					{
						angle = 20;
					};
					class LevelM20: Level0
					{
						angle = -20;
					};
					class LevelP30: Level0
					{
						angle = 30;
					};
					class LevelM30: Level0
					{
						angle = -30;
					};
					class LevelP40: Level0
					{
						angle = 40;
					};
					class LevelM40: Level0
					{
						angle = -40;
					};
					class LevelP50: Level0
					{
						angle = 50;
					};
					class LevelM50: Level0
					{
						angle = -50;
					};
				};
				class Draw
				{
					alpha = 0.6;
					color[] = {0,0.5,0.05};
					condition = "on";
					class PlaneW
					{
						clipTL[] = {0,1};
						clipBR[] = {1,0};
						type = "line";
						width = 4;
						points[] = {{"PlaneW",{0,-0.02},1},{"PlaneW",{0.014,-0.014},1},{"PlaneW",{0.02,0},1},{"PlaneW",{0.014,0.014},1},{"PlaneW",{0,0.02},1},{"PlaneW",{-0.014,0.014},1},{"PlaneW",{-0.02,0},1},{"PlaneW",{-0.014,-0.014},1},{"PlaneW",{0,-0.02},1},{}};
					};
					class PlaneHeading
					{
						clipTL[] = {0,1};
						clipBR[] = {1,0};
						type = "line";
						width = 4;
						points[] = {{"Velocity",{0,-0.02},1},{"Velocity",{0.014,-0.014},1},{"Velocity",{0.02,0},1},{"Velocity",{0.014,0.014},1},{"Velocity",{0,0.02},1},{"Velocity",{-0.014,0.014},1},{"Velocity",{-0.02,0},1},{"Velocity",{-0.014,-0.014},1},{"Velocity",{0,-0.02},1},{},{"Velocity",{0.04,0},1},{"Velocity",{0.02,0},1},{},{"Velocity",{-0.04,0},1},{"Velocity",{-0.02,0},1},{},{"Velocity",{0,-0.04},1},{"Velocity",{0,-0.02},1},{}};
					};
					class Static
					{
						clipTL[] = {0,0.1};
						clipBR[] = {1,0};
						type = "line";
						width = 4;
						points[] = {{{0.79,0.52},1},{{0.81,0.5},1},{{0.79,0.48},1},{},{{0.52,"0.08+0.06"},1},{{0.5,"0.06+0.06"},1},{{0.48,"0.08+0.06"},1},{},{{"0.5-0.1","0.9-0.04"},1},{{"0.5-0.1","0.9+0.04"},1},{{"0.5+0.1","0.9+0.04"},1},{{"0.5+0.1","0.9-0.04"},1},{{"0.5-0.1","0.9-0.04"},1},{},{{"0.5-0.1",0.9},1},{{"0.5-0.092",0.9},1},{},{{"0.5+0.1",0.9},1},{{"0.5+0.092",0.9},1},{},{{0.5,"0.9-0.04"},1},{{0.5,"0.9-0.032"},1},{},{{0.5,"0.9+0.04"},1},{{0.5,"0.9+0.032"},1},{}};
					};
					class Gunner
					{
						type = "line";
						width = 4;
						points[] = {{"GunnerAim",{"0.5-0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9-0.008"},1}};
					};
					class MGun
					{
						condition = "mgun";
						class Circle
						{
							type = "line";
							width = 0;
							points[] = {{"WeaponAim",{0.05,0},1},{"WeaponAim",{0.015,0},1},{},{"WeaponAim",{0,0.05},1},{"WeaponAim",{0,0.015},1},{},{"WeaponAim",{-0.05,0},1},{"WeaponAim",{-0.015,0},1},{},{"WeaponAim",{0,-0.05},1},{"WeaponAim",{0,-0.015},1},{}};
						};
					};
					class Bomb
					{
						condition = "bomb";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{0,-0.1},1},{"WeaponAim",{0.05,-0.087},1},{"WeaponAim",{0.087,-0.05},1},{"WeaponAim",{0.1,0},1},{"WeaponAim",{0.087,0.05},1},{"WeaponAim",{0.05,0.087},1},{"WeaponAim",{0,0.1},1},{"WeaponAim",{-0.05,0.087},1},{"WeaponAim",{-0.087,0.05},1},{"WeaponAim",{-0.1,0},1},{"WeaponAim",{-0.087,-0.05},1},{"WeaponAim",{-0.05,-0.087},1},{"WeaponAim",{0,-0.1},1},{},{"Velocity",0.001,"WeaponAim",{0,0},1},{"Velocity",{0,0},1},{},{"Target",{0,-0.07},1},{"Target",{0.07,0},1},{"Target",{0,0.07},1},{"Target",{-0.07,0},1},{"Target",{0,-0.07},1}};
						};
					};
					class AAMissile
					{
						condition = "AAmissile";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{0,-0.25},1},{"WeaponAim",{0.125,-0.2175},1},{"WeaponAim",{0.2175,-0.125},1},{"WeaponAim",{0.25,0},1},{"WeaponAim",{0.2175,0.125},1},{"WeaponAim",{0.125,0.2175},1},{"WeaponAim",{0,0.25},1},{"WeaponAim",{-0.125,0.2175},1},{"WeaponAim",{-0.2175,0.125},1},{"WeaponAim",{-0.25,0},1},{"WeaponAim",{-0.2175,-0.125},1},{"WeaponAim",{-0.125,-0.2175},1},{"WeaponAim",{0,-0.25},1},{},{"Target",{0,-0.07},1},{"Target",{0.07,0},1},{"Target",{0,0.07},1},{"Target",{-0.07,0},1},{"Target",{0,-0.07},1}};
						};
					};
					class ATMissile
					{
						condition = "ATmissile";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{-0.15,"-0.15+0.02"},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{-0.15,"+0.15-0.02"},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{0.15,"-0.15+0.02"},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{0.15,"+0.15-0.02"},1},{},{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{"-0.15+0.02",-0.15},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{"-0.15+0.02",0.15},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{"0.15-0.02",-0.15},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{"0.15-0.02",0.15},1},{}};
						};
					};
					class Rockets
					{
						condition = "Rocket";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{-0.25,"-0.25+0.05"},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{-0.25,"+0.25-0.05"},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{0.25,"-0.25+0.05"},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{0.25,"+0.25-0.05"},1},{},{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{"-0.25+0.05",-0.25},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{"-0.25+0.05",0.25},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{"0.25-0.05",-0.25},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{"0.25-0.05",0.25},1},{}};
						};
					};
					class SpeedNumber
					{
						type = "text";
						align = "right";
						scale = 1;
						source = "speed";
						sourceScale = 3.6;
						pos[] = {{0.06,0.47},1};
						right[] = {{"0.14-0.02",0.47},1};
						down[] = {{0.06,0.52},1};
					};
					class AltNumber: SpeedNumber
					{
						source = "altitudeAGL";
						sourceScale = 1;
						pos[] = {{"0.86-0.15",0.47},1};
						right[] = {{"0.94-0.15-0.02",0.47},1};
						down[] = {{"0.86-0.15",0.52},1};
					};
					class AltScale
					{
						type = "scale";
						scale = 1;
						source = "altitudeAGL";
						sourceScale = 1;
						align = "right";
						width = 4;
						pos[] = {0.86,0.82};
						right[] = {"0.94-0.02",0.82};
						down[] = {0.86,0.87};
						lineXleft = 0.825;
						lineYright = 0.835;
						lineXleftMajor = 0.825;
						lineYrightMajor = 0.845;
						bottom = 0.2;
						top = 0.85;
						center = 0.5;
						step = 20;
						StepSize = "(0.85- 0.2)/20";
						horizontal = 0;
						min = "none";
						max = "none";
						numberEach = 5;
						majorLineEach = 5;
					};
					class weapons
					{
						type = "text";
						source = "weapon";
						align = "right";
						scale = 0.5;
						sourceScale = 1;
						pos[] = {{0.1,0.88},1};
						right[] = {{"0.16-0.02",0.88},1};
						down[] = {{0.1,0.92},1};
					};
					class ammo
					{
						type = "text";
						source = "ammo";
						align = "right";
						scale = 0.5;
						sourceScale = 1;
						pos[] = {{0.1,0.93},1};
						right[] = {{"0.16-0.02",0.93},1};
						down[] = {{0.1,0.97},1};
					};
					class HeadingScale
					{
						type = "scale";
						scale = 1;
						source = "Heading";
						sourceScale = 1;
						align = "center";
						width = 4;
						pos[] = {"0.32-0.01","0.0+0.05"};
						right[] = {"0.38-0.01","0.0+0.05"};
						down[] = {"0.32-0.01","0.04+0.05"};
						lineXleft = "0.06+0.05";
						lineYright = "0.05+0.05";
						lineXleftMajor = "0.07+0.05";
						lineYrightMajor = "0.04+0.05";
						bottom = 0.7;
						center = 0.5;
						top = 0.3;
						step = 10;
						StepSize = "(0.70- 0.3)/15";
						horizontal = 1;
						min = "none";
						max = "none";
						numberEach = 3;
						majorLineEach = 3;
					};
					class HorizontalLine
					{
						clipTL[] = {0.2,0.12};
						clipBR[] = {0.8,0.96};
						class HorizontalLineDraw
						{
							type = "line";
							source = "Level0";
							points[] = {{"Level0",{"-6*0.075/2",0.02},1},{"Level0",{"-5*0.075/2",0.02},1},{},{"Level0",{"-4*0.075/2",0.02},1},{"Level0",{"-3*0.075/2",0.02},1},{},{"Level0",{"-2*0.075/2",0.02},1},{"Level0",{"-1*0.075/2",0.02},1},{},{"Level0",{"1*0.075/2",0.02},1},{"Level0",{"2*0.075/2",0.02},1},{},{"Level0",{"3*0.075/2",0.02},1},{"Level0",{"4*0.075/2",0.02},1},{},{"Level0",{"5*0.075/2",0.02},1},{"Level0",{"6*0.075/2",0.02},1}};
						};
					};
				};
				helmetMountedDisplay = 1;
				helmetPosition[] = {-0.025,0.025,0.085};
				helmetRight[] = {0.05,0,0};
				helmetDown[] = {0,-0.044,0};
			};
		};
	};
	class ACE_AH1W: ACE_AH1_Base
	{
		scope = 1;
		displayName = "AH-1W Super Cobra";
		accuracy = 1000;
		model = "\x\acex_usnavy\addons\m_veh_ah1\AUS_AH1W";
		mainRotorSpeed = 1.5;
		backRotorSpeed = 1.5;
		destrType = "DestructDefault";
		soundGetIn[] = {"ca\sounds\air\noises\heli_door_01","db-10",1};
		soundGetOut[] = {"ca\sounds\air\noises\heli_door_01","db-10",1,50};
		soundDammage[] = {"ca\sounds\air\noises\alarm_loop1",0.001,1};
		soundEngineOnInt[] = {"\x\acex_usnavy\addons\s_veh_ah1\int\AH_1Z_Start_in.wss",0.0316228,1.0};
		soundEngineOnExt[] = {"\x\acex_usnavy\addons\s_veh_ah1\ext\AH_1Z_Start_out.wss",1.76828,1.0,700};
		soundEngineOffInt[] = {"\x\acex_usnavy\addons\s_veh_ah1\int\AH_1Z_Stop_in.wss",0.0316228,1.0};
		soundEngineOffExt[] = {"\x\acex_usnavy\addons\s_veh_ah1\ext\AH_1Z_Stop_out.wss",1.76828,1.0,700};
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_1w.paa";
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
		class Sounds
		{
			class Engine
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ext\AH1_EngineOut.wss","db10",1.0,800};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\rotor\AH1_RotorLow.wss","db15",1.0,4000};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\rotor\AH1_RotorHigh.wss","db14",1.0,4000};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2.0,0.9};
			};
			class EngineIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\int\AH1_EngineIn.wss","db6",1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\rotor\AH1_RotorLow.wss","db7",1.0};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))*0.75";
			};
			class RotorHighIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\rotor\AH1_RotorHigh.wss","db7",1.0};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)*0.75";
			};
			class WindNoiseOut
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\misc\wind_out.wss",5.3,2.0,150};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "camPos*(speed factor[1, 150])";
			};
			class WindNoiseIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\misc\wind_in.wss",3.3,2.0};
				frequency = "(0.1+(1.2*(speed factor[1, 150])))";
				volume = "(1-camPos)*(speed factor[1, 150])*0.75";
			};
		};
		class Damage
		{
			tex[] = {};
			mat[] = {"x\acex_usnavy\addons\c_veh_ah1\ah1w_body.rvmat","x\acex_usnavy\addons\c_veh_ah1\ah1w_body_damage.rvmat","x\acex_usnavy\addons\c_veh_ah1\ah1w_body_destruct.rvmat","Ca\air\data\ah1z_glass.rvmat","Ca\air\data\ah1z_glass_damage.rvmat","Ca\air\data\ah1z_glass_damage.rvmat","Ca\air\data\ah1z_glass_in.rvmat","Ca\air\data\ah1z_glass_in_damage.rvmat","Ca\air\data\ah1z_glass_in_damage.rvmat","Ca\air\data\ah1z_cockpit.rvmat","Ca\air\data\ah1z_cockpit.rvmat","ca\air\data\ah1z_cockpit_destruct.rvmat","x\acex_usnavy\addons\c_veh_ah1\ah1w_engines.rvmat","x\acex_usnavy\addons\c_veh_ah1\ah1w_engines_damage.rvmat","x\acex_usnavy\addons\c_veh_ah1\ah1w_engines_destruct.rvmat","Ca\air\data\ah1z_monitors.rvmat","Ca\air\data\ah1z_monitors.rvmat","Ca\air\data\ah1z_monitors_destruct.rvmat"};
		};
	};
	class ACE_AH1Z: ACE_AH1_Base
	{
		scope = 1;
		displayName = "AH-1Z Viper";
		accuracy = 1000;
		model = "\x\acex_usnavy\addons\m_veh_ah1\AUS_AH1Z";
		lockdetectionsystem = "8 + 4";
		incommingmissliedetectionsystem = 16;
		soundincommingmissile[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,4};
		soundlocked[] = {"\ca\Tracked\Data\Sound\alarm_loop1",0.000316228,2};
		class Sounds
		{
			class Engine
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1z_t.wss",1.77828,1,1000};
				frequency = "rotorSpeed";
				volume = "camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorLowOut
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1zRb.wss",5.62341,1,4000};
				frequency = "rotorSpeed";
				volume = "camPos*(0 max (rotorSpeed-0.1))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class RotorHighOut
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\uh1y_a.wss",5.62341,1,4000};
				frequency = "rotorSpeed";
				volume = "camPos*10*(0 max (rotorThrust-0.95))";
				cone[] = {1.8,3.14,2,0.9};
			};
			class EngineIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1z_int.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorLowIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\ah1zRb.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "2*(1-camPos)*((rotorSpeed factor[0.3, 1.1]) min (rotorSpeed factor[1.1, 0.3]))*0.75";
			};
			class RotorHighIn
			{
				sound[] = {"\x\acex_usnavy\addons\s_veh_ah1\uh1y_a.wss",1.77828,1};
				frequency = "rotorSpeed";
				volume = "(1-camPos)*3*(rotorThrust-0.9)*0.75";
			};
		};
		class MFD
		{
			class AirplaneHUD
			{
				class Pos10Vector
				{
					type = "vector";
					pos0[] = {0.5,"0.27+0.23"};
					pos10[] = {0.85,0.85};
				};
				topLeft = "HUD LH";
				topRight = "HUD PH";
				bottomLeft = "HUD LD";
				borderLeft = 0;
				borderRight = 0;
				borderTop = 0;
				borderBottom = 0;
				color[] = {0,1,0,0.1};
				class Bones
				{
					class PlaneW
					{
						type = "fixed";
						pos[] = {0.5,"0.34+0.23"};
					};
					class WeaponAim: Pos10Vector
					{
						source = "weapon";
					};
					class GunnerAim: Pos10Vector
					{
						source = "weapon";
						pos0[] = {0,-0.0025};
						pos10[] = {0.01,0.0025};
					};
					class Target: Pos10Vector
					{
						source = "target";
					};
					class Velocity: Pos10Vector
					{
						type = "vector";
						source = "velocity";
						pos0[] = {0.5,"0.27+0.23"};
						pos10[] = {0.85,0.85};
					};
					class ILS_H
					{
						type = "ils";
						pos0[] = {0.5,"0.27+0.23"};
						pos3[] = {0.605,"0.27+0.23"};
					};
					class ILS_W: ILS_H
					{
						pos3[] = {0.5,0.605};
					};
					class Level0: Pos10Vector
					{
						pos0[] = {0.5,"0.34+0.23"};
						pos10[] = {0.85,0.92};
						type = "horizon";
						angle = 0;
					};
					class LevelP10: Level0
					{
						angle = 10;
					};
					class LevelM10: Level0
					{
						angle = -10;
					};
					class LevelP20: Level0
					{
						angle = 20;
					};
					class LevelM20: Level0
					{
						angle = -20;
					};
					class LevelP30: Level0
					{
						angle = 30;
					};
					class LevelM30: Level0
					{
						angle = -30;
					};
					class LevelP40: Level0
					{
						angle = 40;
					};
					class LevelM40: Level0
					{
						angle = -40;
					};
					class LevelP50: Level0
					{
						angle = 50;
					};
					class LevelM50: Level0
					{
						angle = -50;
					};
				};
				class Draw
				{
					alpha = 0.6;
					color[] = {0,0.5,0.05};
					condition = "on";
					class PlaneW
					{
						clipTL[] = {0,1};
						clipBR[] = {1,0};
						type = "line";
						width = 4;
						points[] = {{"PlaneW",{0,-0.02},1},{"PlaneW",{0.014,-0.014},1},{"PlaneW",{0.02,0},1},{"PlaneW",{0.014,0.014},1},{"PlaneW",{0,0.02},1},{"PlaneW",{-0.014,0.014},1},{"PlaneW",{-0.02,0},1},{"PlaneW",{-0.014,-0.014},1},{"PlaneW",{0,-0.02},1},{}};
					};
					class PlaneHeading
					{
						clipTL[] = {0,1};
						clipBR[] = {1,0};
						type = "line";
						width = 4;
						points[] = {{"Velocity",{0,-0.02},1},{"Velocity",{0.014,-0.014},1},{"Velocity",{0.02,0},1},{"Velocity",{0.014,0.014},1},{"Velocity",{0,0.02},1},{"Velocity",{-0.014,0.014},1},{"Velocity",{-0.02,0},1},{"Velocity",{-0.014,-0.014},1},{"Velocity",{0,-0.02},1},{},{"Velocity",{0.04,0},1},{"Velocity",{0.02,0},1},{},{"Velocity",{-0.04,0},1},{"Velocity",{-0.02,0},1},{},{"Velocity",{0,-0.04},1},{"Velocity",{0,-0.02},1},{}};
					};
					class Static
					{
						clipTL[] = {0,0.1};
						clipBR[] = {1,0};
						type = "line";
						width = 4;
						points[] = {{{0.79,0.52},1},{{0.81,0.5},1},{{0.79,0.48},1},{},{{0.52,"0.08+0.06"},1},{{0.5,"0.06+0.06"},1},{{0.48,"0.08+0.06"},1},{},{{"0.5-0.1","0.9-0.04"},1},{{"0.5-0.1","0.9+0.04"},1},{{"0.5+0.1","0.9+0.04"},1},{{"0.5+0.1","0.9-0.04"},1},{{"0.5-0.1","0.9-0.04"},1},{},{{"0.5-0.1",0.9},1},{{"0.5-0.092",0.9},1},{},{{"0.5+0.1",0.9},1},{{"0.5+0.092",0.9},1},{},{{0.5,"0.9-0.04"},1},{{0.5,"0.9-0.032"},1},{},{{0.5,"0.9+0.04"},1},{{0.5,"0.9+0.032"},1},{}};
					};
					class Gunner
					{
						type = "line";
						width = 4;
						points[] = {{"GunnerAim",{"0.5-0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9-0.008"},1}};
					};
					class MGun
					{
						condition = "mgun";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{0.05,0},1},{"WeaponAim",{0.015,0},1},{},{"WeaponAim",{0,0.05},1},{"WeaponAim",{0,0.015},1},{},{"WeaponAim",{-0.05,0},1},{"WeaponAim",{-0.015,0},1},{},{"WeaponAim",{0,-0.05},1},{"WeaponAim",{0,-0.015},1},{}};
						};
					};
					class Bomb
					{
						condition = "bomb";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{0,-0.1},1},{"WeaponAim",{0.05,-0.087},1},{"WeaponAim",{0.087,-0.05},1},{"WeaponAim",{0.1,0},1},{"WeaponAim",{0.087,0.05},1},{"WeaponAim",{0.05,0.087},1},{"WeaponAim",{0,0.1},1},{"WeaponAim",{-0.05,0.087},1},{"WeaponAim",{-0.087,0.05},1},{"WeaponAim",{-0.1,0},1},{"WeaponAim",{-0.087,-0.05},1},{"WeaponAim",{-0.05,-0.087},1},{"WeaponAim",{0,-0.1},1},{},{"Velocity",0.001,"WeaponAim",{0,0},1},{"Velocity",{0,0},1},{},{"Target",{0,-0.07},1},{"Target",{0.07,0},1},{"Target",{0,0.07},1},{"Target",{-0.07,0},1},{"Target",{0,-0.07},1}};
						};
					};
					class AAMissile
					{
						condition = "AAmissile";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{0,-0.25},1},{"WeaponAim",{0.125,-0.2175},1},{"WeaponAim",{0.2175,-0.125},1},{"WeaponAim",{0.25,0},1},{"WeaponAim",{0.2175,0.125},1},{"WeaponAim",{0.125,0.2175},1},{"WeaponAim",{0,0.25},1},{"WeaponAim",{-0.125,0.2175},1},{"WeaponAim",{-0.2175,0.125},1},{"WeaponAim",{-0.25,0},1},{"WeaponAim",{-0.2175,-0.125},1},{"WeaponAim",{-0.125,-0.2175},1},{"WeaponAim",{0,-0.25},1},{},{"Target",{0,-0.07},1},{"Target",{0.07,0},1},{"Target",{0,0.07},1},{"Target",{-0.07,0},1},{"Target",{0,-0.07},1}};
						};
					};
					class ATMissile
					{
						condition = "ATmissile";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{-0.15,"-0.15+0.02"},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{-0.15,"+0.15-0.02"},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{0.15,"-0.15+0.02"},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{0.15,"+0.15-0.02"},1},{},{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{"-0.15+0.02",-0.15},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{"-0.15+0.02",0.15},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{"0.15-0.02",-0.15},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{"0.15-0.02",0.15},1},{}};
						};
					};
					class Rockets
					{
						condition = "Rocket";
						class Circle
						{
							type = "line";
							width = 4;
							points[] = {{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{-0.25,"-0.25+0.05"},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{-0.25,"+0.25-0.05"},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{0.25,"-0.25+0.05"},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{0.25,"+0.25-0.05"},1},{},{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{"-0.25+0.05",-0.25},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{"-0.25+0.05",0.25},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{"0.25-0.05",-0.25},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{"0.25-0.05",0.25},1},{}};
						};
					};
					class SpeedNumber
					{
						type = "text";
						align = "right";
						scale = 1;
						source = "speed";
						sourceScale = 3.6;
						pos[] = {{0.06,0.47},1};
						right[] = {{"0.14-0.02",0.47},1};
						down[] = {{0.06,0.52},1};
					};
					class AltNumber: SpeedNumber
					{
						source = "altitudeAGL";
						sourceScale = 1;
						pos[] = {{"0.86-0.15",0.47},1};
						right[] = {{"0.94-0.15-0.02",0.47},1};
						down[] = {{"0.86-0.15",0.52},1};
					};
					class AltScale
					{
						type = "scale";
						scale = 1;
						source = "altitudeAGL";
						sourceScale = 1;
						align = "right";
						width = 4;
						pos[] = {0.86,0.82};
						right[] = {"0.94-0.02",0.82};
						down[] = {0.86,0.87};
						lineXleft = 0.825;
						lineYright = 0.835;
						lineXleftMajor = 0.825;
						lineYrightMajor = 0.845;
						bottom = 0.2;
						top = 0.85;
						center = 0.5;
						step = 20;
						StepSize = "(0.85- 0.2)/20";
						horizontal = 0;
						min = "none";
						max = "none";
						numberEach = 5;
						majorLineEach = 5;
					};
					class weapons
					{
						type = "text";
						source = "weapon";
						align = "right";
						scale = 0.5;
						sourceScale = 1;
						pos[] = {{0.1,0.88},1};
						right[] = {{"0.16-0.02",0.88},1};
						down[] = {{0.1,0.92},1};
					};
					class ammo
					{
						type = "text";
						source = "ammo";
						align = "right";
						scale = 0.5;
						sourceScale = 1;
						pos[] = {{0.1,0.93},1};
						right[] = {{"0.16-0.02",0.93},1};
						down[] = {{0.1,0.97},1};
					};
					class HeadingScale
					{
						type = "scale";
						scale = 1;
						source = "Heading";
						sourceScale = 1;
						align = "center";
						width = 4;
						pos[] = {"0.32-0.01","0.0+0.05"};
						right[] = {"0.38-0.01","0.0+0.05"};
						down[] = {"0.32-0.01","0.04+0.05"};
						lineXleft = "0.06+0.05";
						lineYright = "0.05+0.05";
						lineXleftMajor = "0.07+0.05";
						lineYrightMajor = "0.04+0.05";
						bottom = 0.7;
						center = 0.5;
						top = 0.3;
						step = 10;
						StepSize = "(0.70- 0.3)/15";
						horizontal = 1;
						min = "none";
						max = "none";
						numberEach = 3;
						majorLineEach = 3;
					};
					class HorizontalLine
					{
						clipTL[] = {0.2,0.12};
						clipBR[] = {0.8,0.96};
						class HorizontalLineDraw
						{
							type = "line";
							source = "Level0";
							points[] = {{"Level0",{"-6*0.075/2",0.02},1},{"Level0",{"-5*0.075/2",0.02},1},{},{"Level0",{"-4*0.075/2",0.02},1},{"Level0",{"-3*0.075/2",0.02},1},{},{"Level0",{"-2*0.075/2",0.02},1},{"Level0",{"-1*0.075/2",0.02},1},{},{"Level0",{"1*0.075/2",0.02},1},{"Level0",{"2*0.075/2",0.02},1},{},{"Level0",{"3*0.075/2",0.02},1},{"Level0",{"4*0.075/2",0.02},1},{},{"Level0",{"5*0.075/2",0.02},1},{"Level0",{"6*0.075/2",0.02},1}};
						};
					};
				};
				helmetMountedDisplay = 1;
				helmetPosition[] = {-0.025,0.025,0.085};
				helmetRight[] = {0.05,0,0};
				helmetDown[] = {0,-0.044,0};
			};
		};
	};
	class ACE_AH1W_AGM: ACE_AH1W
	{
		scope = 1;
		faction = "USMC";
		displayName = "AH-1W (AGM-114/FFAR)";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M197","ACE_HellfireLauncher"};
				magazines[] = {"ACE_1Rnd_HellfirePod","ACE_1Rnd_HellfirePod","ACE_1Rnd_LAU61","ACE_1Rnd_LAU61","750Rnd_M197_AH1","ACE_8Rnd_Hellfire"};
			};
		};
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1w_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1w_engines_co.paa"};
	};
	class ACE_AH1W_TOW: ACE_AH1W
	{
		scope = 1;
		faction = "USMC";
		displayName = "AH-1W (4xBGM-71)";
		weapons[] = {"FFARLauncher_14","CMFlareLauncher"};
		magazines[] = {"14Rnd_FFAR","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M197","TOWLauncher"};
				magazines[] = {"ACE_1Rnd_TOW2","ACE_1Rnd_TOW2","ACE_1Rnd_LAU68","ACE_1Rnd_LAU68","750Rnd_M197_AH1","ACE_TOW4","ACE_8Rnd_Empty_Dummy"};
			};
		};
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1w_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1w_engines_co.paa"};
	};
	class ACE_AH1W_TOW_TOW: ACE_AH1W_TOW
	{
		scope = 1;
		displayName = "AH-1W (8xBGM-71)";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				magazines[] = {"ACE_1Rnd_TOW4","ACE_1Rnd_TOW4","ACE_1Rnd_LAU61","ACE_1Rnd_LAU61","750Rnd_M197_AH1","ACE_TOW8","ACE_8Rnd_Empty_Dummy"};
			};
		};
	};
	class ACE_AH1W_AGM_W: ACE_AH1W_AGM
	{
		scope = 2;
	};
	class ACE_AH1W_TOW_W: ACE_AH1W_TOW
	{
		scope = 2;
	};
	class ACE_AH1W_TOW_TOW_W: ACE_AH1W_TOW_TOW
	{
		scope = 2;
	};
	class ACE_AH1W_AGM_D: ACE_AH1W_AGM
	{
		scope = 2;
		vehicleClass = "ACE_AirD";
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1w_d_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1w_d_engines_co.paa"};
	};
	class ACE_AH1W_TOW_D: ACE_AH1W_TOW
	{
		scope = 2;
		vehicleClass = "ACE_AirD";
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1w_d_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1w_d_engines_co.paa"};
	};
	class ACE_AH1W_TOW_TOW_D: ACE_AH1W_TOW_TOW
	{
		scope = 2;
		vehicleClass = "ACE_AirD";
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1w_d_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1w_d_engines_co.paa"};
	};
	class ACE_AH1Z_AGM: ACE_AH1Z
	{
		scope = 1;
		displayName = "AH-1Z (AGM-114/FFAR)";
		faction = "USMC";
		weapons[] = {"FFARLauncher","CMFlareLauncher"};
		magazines[] = {"38Rnd_FFAR","120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M197","SidewinderLaucher_AH1Z","ACE_HellfireLauncher"};
				magazines[] = {"2Rnd_Sidewinder_AH1Z","ACE_1Rnd_HellfirePod","ACE_1Rnd_HellfirePod","ACE_1Rnd_LAU61","ACE_1Rnd_LAU61","750Rnd_M197_AH1","ACE_8Rnd_Hellfire"};
			};
		};
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1z_d_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1z_d_engines_co.paa"};
	};
	class ACE_AH1Z_AGM_AGM: ACE_AH1Z
	{
		scope = 1;
		displayName = "AH-1Z (AGM-114)";
		faction = "USMC";
		weapons[] = {"CMFlareLauncher","FakeWeapon"};
		magazines[] = {"120Rnd_CMFlareMagazine"};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[] = {"M197","SidewinderLaucher_AH1Z","ACE_HellfireLauncher"};
				magazines[] = {"2Rnd_Sidewinder_AH1Z","ACE_1Rnd_HellfirePod","ACE_1Rnd_HellfirePod","ACE_1Rnd_HellfirePod","ACE_1Rnd_HellfirePod","750Rnd_M197_AH1","ACE_16Rnd_Hellfire"};
			};
		};
		hiddenSelectionsTextures[] = {"\x\acex_usnavy\addons\t_veh_ah1\ah1z_d_body_co.paa","\x\acex_usnavy\addons\t_veh_ah1\ah1z_d_engines_co.paa"};
	};
	class ACE_AH1Z_AGM_W: ACE_AH1Z_AGM
	{
		scope = 1;
	};
	class ACE_AH1Z_AGM_AGM_W: ACE_AH1Z_AGM_AGM
	{
		scope = 2;
	};
	class ACE_AH1Z_AGM_D: ACE_AH1Z_AGM
	{
		scope = 2;
		vehicleClass = "ACE_AirD";
	};
	class ACE_AH1Z_AGM_AGM_D: ACE_AH1Z_AGM_AGM
	{
		scope = 2;
		vehicleClass = "ACE_AirD";
	};
};
//};
