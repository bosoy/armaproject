////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:28 2013 : Created on Sat Apr 06 11:45:28 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_huntir : config.bin{
class CfgPatches
{
	class ace_sys_huntir
	{
		units[] = {"ACE_HuntIR","ACE_HuntIRBox"};
		weapons[] = {"ACE_HuntIR_monitor"};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","CAAir","CAAir2","CAAir3","ace_c_useractions","ace_c_weapon","Extended_EventHandlers","ace_main","ace_sys_interaction"};
		version = "1.14.0.590";
		author[] = {"Norrin","Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_huntir
		{
			list[] = {"ace_sys_huntir"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_huntir
	{
		clientInit = "call ('\x\ace\addons\sys_huntir\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class Man
	{
		class ace_sys_huntir
		{
			clientFiredBisPlayer = "if ((_this Select 4) == 'F_HuntIR') then { _this call ace_sys_huntir_fnc_fired}";
		};
	};
};
class CfgVehicles
{
	class Parachute_US_EP1;
	class ACE_HuntIR: Parachute_US_EP1
	{
		scope = 1;
		displayName = "HuntIR";
		model = "\x\ace\addons\sys_huntir\huntir.p3d";
		castDriverShadow = 0;
		soundEnviron[] = {"\Ca\sounds\Air\Noises\padak_let",0.316228,1,80};
		soundCrash[] = {"db-30",1};
		soundLandCrash[] = {"db-30",1};
		soundWaterCrash[] = {"db10",1};
		mapSize = 0;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class USBasicAmmunitionBox_EP1;
	class ACE_HuntIRBox: USBasicAmmunitionBox_EP1
	{
		vehicleClass = "ACE_Ammunition";
		model = "\x\ace\addons\sys_huntir\ace_huntirbox.p3d";
		displayName = "$STR_DN_ACE_HUNTIRBOX";
		accuracy = 1000;
		class TransportMagazines
		{
			class _xx_ACE_HuntIR_M203
			{
				magazine = "ACE_HuntIR_M203";
				count = 20;
			};
		};
		class TransportWeapons
		{
			class _xx_ACE_HuntIR_monitor
			{
				weapon = "ACE_HuntIR_monitor";
				count = 5;
			};
		};
	};
};
class CfgWeapons
{
	class ACE_Item;
	class ACE_HuntIR_monitor: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_HUNTIR_MON";
		picture = "\x\ace\addons\sys_huntir\data\equip\w_huntir_monitor_ca.paa";
		descriptionShort = "$STR_ACE_HUNTIR_MON";
		model = "\x\ace\addons\sys_huntir\ace_huntir_monitor.p3d";
		ACE_Weight = 0.25;
		ACE_Size = 900;
	};
};
class CfgAmmo
{
	class FlareBase;
	class F_HuntIR: FlareBase
	{
		model = "\x\ace\addons\sys_huntir\ace_m1070_armed.p3d";
		lightColor[] = {0,0,0,0};
		ACE_Simulation = "shotHuntIR";
	};
	class ShellBase;
	class ACE_HuntIR_Propell: ShellBase
	{
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 1;
		typicalSpeed = 100;
		cost = 300;
		model = "\ca\weapons\empty";
		airFriction = 0;
		timeToLive = 1;
		explosionTime = 0.001;
		soundHit[] = {"ca\Sounds\weapons\cannon\rocket_fly1",3.16228,3,250};
		soundDefault1[] = {"ca\Sounds\weapons\cannon\rocket_fly1",3.16228,3,250};
		soundDefault2[] = {"ca\Sounds\weapons\cannon\rocket_fly1",3.16228,3,250};
		soundDefault3[] = {"ca\Sounds\weapons\cannon\rocket_fly1",3.16228,3,250};
		supersonicCrackNear[] = {"",1,1,100};
		supersonicCrackFar[] = {"",1,1,150};
		soundFly[] = {"",1,1};
		soundEngine[] = {"",1,4};
		CraterEffects = "NoCrater";
		explosionEffects = "ACE_HuntIR_Propell_Fx";
		class HitEffects{};
	};
};
class CfgMagazines
{
	class 1Rnd_HE_M203;
	class ACE_HuntIR_M203: 1Rnd_HE_M203
	{
		displayName = "$STR_ACE_HUNTIR_ROUND";
		displaynameshort = "";
		picture = "\x\ace\addons\sys_huntir\data\equip\m_m1070_ca.paa";
		ammo = "F_HuntIR";
		initSpeed = 80;
		count = 1;
	};
};
class ACE_HuntIR_Propell_Fx
{
	class ACE_HuntIR_ExploAmmoFlash
	{
		simulation = "particles";
		type = "ACE_HuntIR_ExploAmmoFlash";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 1;
	};
	class ACE_HuntIR_ExploAmmoSmoke
	{
		simulation = "particles";
		type = "ACE_HuntIR_ExploAmmoSmoke";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.8;
	};
};
class CfgCloudlets
{
	class Default;
	class ACE_HuntIR_ExploAmmoFlash: Default
	{
		interval = 0.1;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\Ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 0;
		particleFSFrameCount = 32;
		particleFSLoop = 0;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.5;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 1;
		weight = 10;
		volume = 7.9;
		rubbing = 0.1;
		size[] = {"0.0125 * intensity + 0.25","0.0125 * intensity + 0.125"};
		color[] = {{1,1,1,-1},{1,1,1,0}};
		animationSpeed[] = {2};
		randomDirectionPeriod = 0.2;
		randomDirectionIntensity = 0.2;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0;
		positionVar[] = {0,0.1,0};
		MoveVelocityVar[] = {0.2,0.5,0.2};
		rotationVelocityVar = 1;
		sizeVar = 0.5;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class ACE_HuntIR_ExploAmmoSmoke: Default
	{
		interval = "0.02 * interval + 0.02";
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\Ca\Data\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 7;
		particleFSFrameCount = 48;
		particleFSLoop = 1;
		angleVar = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.25;
		moveVelocity[] = {0,1,0};
		rotationVelocity = 1;
		weight = 0.053;
		volume = 0.04;
		rubbing = 0.2;
		size[] = {"0.0125 * intensity + 0.25","0.0125 * intensity + 1.25","0.0125 * intensity + 2.75","0.0125 * intensity + 3.75"};
		color[] = {{0.6,0.6,0.6,1},{0.7,0.7,0.7,0.5},{0.78,0.78,0.78,0.25}};
		animationSpeed[] = {1.7,0.6,0.4,0.3,0.3};
		randomDirectionPeriod = 0.2;
		randomDirectionIntensity = 0.2;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 2;
		positionVar[] = {0.5,0.3,0.5};
		MoveVelocityVar[] = {1.5,2,1.5};
		rotationVelocityVar = 1;
		sizeVar = 0.5;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
};
class ace_huntir_cam_dialog
{
	idd = 18880;
	movingEnable = "true";
	controlsBackground[] = {};
	objects[] = {};
	controls[] = {"TOP_BORDER","BOTTOM_BORDER","LEFT_BORDER","RIGHT_BORDER","CAM_BG","CAM_HEIGHT","CAM_ALT","CAM_No","CAM_NO_x","CAM_TIME_REMAIN","CAM_TIME","CAM_ZOOM","ZOOM_X","CAM_POS","CAM_POS_X","CAM_DIR","CAM_DIR_x"};
	class TOP_BORDER
	{
		idc = -1;
		type = 0;
		style = "0x02";
		x = "SafeZoneXAbs";
		y = "SafeZoneY";
		w = "SafeZoneWAbs";
		h = 0.08;
		font = "Zeppelin32";
		sizeEx = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,1};
		text = "";
		blinkingPeriod = 0;
	};
	class BOTTOM_BORDER: TOP_BORDER
	{
		y = "SafeZoneY+ SafeZoneH- 0.05";
		h = 0.05;
	};
	class LEFT_BORDER: TOP_BORDER
	{
		w = "(abs(SafeZoneXAbs) - abs(SafeZoneX)) + 0.05";
		h = "SafeZoneH";
	};
	class RIGHT_BORDER: TOP_BORDER
	{
		x = "SafeZoneX+ SafeZoneW- 0.05";
		w = "(SafeZoneWAbs- SafeZoneW) + 0.05";
		h = "SafeZoneH";
	};
	class HELP_DIALOG
	{
		idc = -1;
		type = 1;
		style = "0x02";
		default = "false";
		font = "Zeppelin32";
		sizeEx = 0.025;
		colorText[] = {1,1,1,1};
		colorFocused[] = {0.31,0.31,0.31,0.31};
		colorDisabled[] = {0,0,1,0.7};
		colorBackground[] = {0,0,0,0};
		colorBackgroundDisabled[] = {1,1,1,0.5};
		colorBackgroundActive[] = {0.5,0.5,0.5,0.5};
		offsetX = 0.003;
		offsetY = 0.003;
		offsetPressedX = 0.002;
		offsetPressedY = 0.002;
		colorShadow[] = {0,0,0,0.5};
		colorBorder[] = {0,0,0,0};
		borderSize = 0;
		soundEnter[] = {"",0,1};
		soundPush[] = {"buttonpushed.ogg",0.1,1};
		soundClick[] = {"",0,1};
		soundEscape[] = {"",0,1};
		x = "SafeZoneX+ (2*0.8)";
		y = "SafeZoneY+ 0.045";
		w = 0.05;
		h = 0.02;
		text = "$STR_ACE_HUNTIR_HELP";
		action = "createDialog 'ace_huntir_help_dialog'";
	};
	class CAM_BG
	{
		idc = -1;
		type = 0;
		style = 48;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0.4,0.4,0.4,1};
		font = "BitStream";
		sizeEx = 0.021;
		lineSpacing = 1;
		x = "SafeZoneX";
		y = "SafeZoneY+ 0.08";
		w = "SafeZoneW";
		h = "SafeZoneH+ 0.2";
		border = 0;
		text = "\x\ace\addons\sys_huntir\data\rsc\ace_huntir_monitor_on.paa";
	};
	class CAM_HEIGHT
	{
		type = 0;
		idc = 1;
		style = "0x00";
		colorBackground[] = {0,0,0,0};
		colorText[] = {1,1,1,1};
		font = "Zeppelin32";
		sizeEx = 0.02;
		x = "SafeZoneX+ 0.42";
		y = "SafeZoneY+ 0.32";
		w = 0.08;
		h = 0.04;
		text = "";
		default = "true";
		blinkingPeriod = 0;
	};
	class CAM_ALT: CAM_HEIGHT
	{
		x = "SafeZoneX+ 0.3";
		text = "$STR_ACE_HUNTIR_ALT";
	};
	class CAM_No: CAM_HEIGHT
	{
		x = "SafeZoneX+ SafeZoneW- 0.64";
		text = "$STR_ACE_HUNTIR_CAM";
	};
	class CAM_NO_x: CAM_HEIGHT
	{
		idc = 2;
		x = "SafeZoneX+ SafeZoneW- 0.52";
		y = "SafeZoneY+ 0.32";
		text = "";
	};
	class CAM_TIME: CAM_HEIGHT
	{
		x = "SafeZoneX+ 0.32";
		y = "SafeZoneY+ SafeZoneH- 0.65";
		w = 0.12;
		text = "$STR_ACE_HUNTIR_TIME";
	};
	class CAM_TIME_REMAIN: CAM_TIME
	{
		idc = 3;
		x = "SafeZoneX+ 0.44";
		text = "";
	};
	class CAM_ZOOM: CAM_No
	{
		y = "SafeZoneY+ 0.36";
		text = "Zoom:";
	};
	class ZOOM_X: CAM_ZOOM
	{
		idc = 4;
		x = "SafeZoneX+ SafeZoneW- 0.54";
		text = "";
	};
	class CAM_POS: CAM_HEIGHT
	{
		x = "SafeZoneX+ 0.3";
		y = "SafeZoneY+ 0.36";
		text = "GPS Pos:";
	};
	class CAM_POS_X: CAM_POS
	{
		idc = 5;
		x = "SafeZoneX+ 0.42";
		w = 0.16;
		text = "";
	};
	class CAM_DIR: CAM_POS
	{
		y = "SafeZoneY+ 0.4";
		text = "";
	};
	class CAM_DIR_x: CAM_DIR
	{
		idc = 6;
		x = "SafeZoneX+ 0.42";
		w = 0.16;
		text = "";
	};
};
class ace_huntir_cam_dialog_inactive: ace_huntir_cam_dialog
{
	idd = 18881;
	controls[] = {"TOP_BORDER","BOTTOM_BORDER","LEFT_BORDER","RIGHT_BORDER","CAM_BG","SEARCHING_CAM"};
	class TOP_BORDER: TOP_BORDER{};
	class BOTTOM_BORDER: BOTTOM_BORDER{};
	class LEFT_BORDER: LEFT_BORDER{};
	class RIGHT_BORDER: RIGHT_BORDER{};
	class PRESS_HELP
	{
		idc = -1;
		type = 0;
		style = "0x00";
		x = "SafeZoneX+ (SafeZoneW- 0.2)";
		y = "SafeZoneY+ 0.06";
		w = 0.4;
		h = 0.02;
		font = "Zeppelin32";
		sizeEx = 0.02;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "";
		blinkingPeriod = 0;
		default = "true";
	};
	class HELP_DIALOG
	{
		idc = -1;
		type = 0;
		style = "0x00";
		x = "SafeZoneX+ (SafeZoneW- 0.2)";
		y = "SafeZoneY+ 0.03";
		w = 0.4;
		h = 0.02;
		font = "Zeppelin32";
		sizeEx = 0.02;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_HUNTIR_ESC";
		blinkingPeriod = 0;
		default = "true";
	};
	class CAM_BG: CAM_BG{};
	class SEARCHING_CAM
	{
		idc = 1;
		type = 0;
		style = "0x00";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		x = "SafeZoneX+ (SafeZoneW/2) - 0.07";
		y = "SafeZoneY+ (SafeZoneH/2)";
		w = 0.3;
		h = 0.04;
		font = "Zeppelin32";
		sizeEx = 0.02;
		text = "";
		default = "true";
		blinkingPeriod = 0;
	};
};
class ace_huntir_cam_dialog_off: ace_huntir_cam_dialog_inactive
{
	idd = 18882;
	controls[] = {"TOP_BORDER","BOTTOM_BORDER","LEFT_BORDER","RIGHT_BORDER","CAM_BG"};
	class TOP_BORDER: TOP_BORDER{};
	class BOTTOM_BORDER: BOTTOM_BORDER{};
	class LEFT_BORDER: LEFT_BORDER{};
	class RIGHT_BORDER: RIGHT_BORDER{};
	class PRESS_HELP: PRESS_HELP{};
	class HELP_DIALOG: HELP_DIALOG{};
	class CAM_BG: CAM_BG
	{
		text = "\x\ace\addons\sys_huntir\data\rsc\ace_huntir_monitor_off.paa";
	};
};
class ace_huntir_help_dialog: ace_huntir_cam_dialog
{
	idd = -1;
	controls[] = {"TOP_BORDER","BOTTOM_BORDER","LEFT_BORDER","RIGHT_BORDER","CAM_BG","CAM_HEIGHT","CAM_ALT","CAM_TIME_REMAIN","CAM_TIME","CAM_ZOOM","ZOOM_X","CAM_POS","CAM_POS_x","CAM_No","CAM_No_X","CAM_DIR","CAM_DIR_x","HELP0","HELP1","HELP2","HELP3","HELP4","HELP5","HELP6"};
	class TOP_BORDER: TOP_BORDER{};
	class BOTTOM_BORDER: BOTTOM_BORDER{};
	class LEFT_BORDER: LEFT_BORDER{};
	class RIGHT_BORDER: RIGHT_BORDER{};
	class CAM_BG: CAM_BG{};
	class CAM_HEIGHT: CAM_HEIGHT{};
	class CAM_ALT: CAM_ALT{};
	class CAM_No: CAM_No{};
	class CAM_NO_x: CAM_NO_x{};
	class CAM_TIME_REMAIN: CAM_TIME_REMAIN{};
	class CAM_TIME: CAM_TIME{};
	class CAM_ZOOM: CAM_ZOOM{};
	class ZOOM_X: ZOOM_X{};
	class CAM_POS: CAM_POS{};
	class CAM_POS_X: CAM_POS_X{};
	class CAM_DIR: CAM_DIR{};
	class CAM_DIR_x: CAM_DIR_x{};
	class HELP0
	{
		idc = -1;
		type = 0;
		style = "0x00";
		x = "SafeZoneX+ (SafeZoneW- 0.3)";
		y = "SafeZoneY+ 0.03";
		w = 0.4;
		h = 0.03;
		font = "Zeppelin32";
		sizeEx = 0.022;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,1};
		text = "$STR_ACE_HUNTIR_HELP_EXIT";
		blinkingPeriod = 0;
	};
	class HELP1: HELP0
	{
		y = "SafeZoneY+ 0.06";
		text = "$STR_ACE_HUNTIR_HELP_ZOOM";
	};
	class HELP2: HELP0
	{
		y = "SafeZoneY+ 0.09";
		text = "$STR_ACE_HUNTIR_HELP_CAM";
	};
	class HELP3: HELP0
	{
		y = "SafeZoneY+ 0.12";
		text = "$STR_ACE_HUNTIR_HELP_ROT";
	};
	class HELP4: HELP0
	{
		y = "SafeZoneY+ 0.15";
		text = "$STR_ACE_HUNTIR_HELP_ELV";
	};
	class HELP5: HELP0
	{
		y = "SafeZoneY+ 0.18";
		text = "$STR_ACE_HUNTIR_HELP_MOD";
	};
	class HELP6: HELP0
	{
		y = "SafeZoneY+ 0.21";
		text = "$STR_ACE_HUNTIR_HELP_RES";
	};
};
class RscTitles
{
	class ace_huntir_cam_rose
	{
		idd = -1;
		movingEnable = "true";
		fadein = 0;
		fadeout = 1;
		duration = 1e+011;
		name = "ace_huntir_cam_rose";
		onLoad = "uiNamespace setVariable ['ace_huntir_cam_rose', _this select 0]";
		class controls
		{
			class CHAR_N
			{
				type = 0;
				idc = 64432;
				style = 0;
				x = 0.497;
				y = 0.297;
				w = 0.2;
				h = 0.2;
				font = "Zeppelin32";
				sizeEx = 0.02;
				colorText[] = {1,1,1,1};
				colorBackground[] = {0,0,0,0};
				text = "N";
			};
			class CHAR_E: CHAR_N
			{
				idc = 64433;
				x = 0.697;
				y = 0.497;
				text = "E";
			};
			class CHAR_S: CHAR_N
			{
				idc = 64434;
				x = 0.497;
				y = 0.697;
				text = "S";
			};
			class CHAR_W: CHAR_N
			{
				idc = 64435;
				x = 0.297;
				y = 0.497;
				text = "W";
			};
		};
	};
};
//};
