////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:43:25 2013 : Created on Sat Apr 06 11:43:25 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_air_rwr : config.bin{
class CfgPatches
{
	class ace_sys_air_rwr
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_sys_vehicle"};
		version = "1.14.0.590";
		author[] = {"Reezo","rocko","Xeno"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_air_rwr
		{
			list[] = {"ace_sys_air_rwr"};
		};
	};
};
class CfgSettings
{
	class ace
	{
		class sys_air_rwr
		{
			class ACE_Default
			{
				ace_sys_air_rwr_type = 1;
				ace_sys_air_rwr_skin = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_default.paa";
				ace_sys_air_rwr_detectMissile = 1;
				ace_sys_air_rwr_alphanumeric = 1;
			};
			class ACE_ANALR69: ACE_Default
			{
				ace_sys_air_rwr_skin = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_analr69.paa";
			};
			class ACE_ANALR67: ACE_Default
			{
				ace_sys_air_rwr_skin = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_analr67.paa";
			};
			class ACE_ANALR56: ACE_Default
			{
				ace_sys_air_rwr_skin = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_analr56.paa";
			};
			class ACE_ANPR391: ACE_Default
			{
				ace_sys_air_rwr_skin = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_anapr39.paa";
				ace_sys_air_rwr_detectMissile = 0;
				ace_sys_air_rwr_alphanumeric = 0;
			};
			class ACE_ANPR39A1: ACE_Default
			{
				ace_sys_air_rwr_skin = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_anapr39.paa";
			};
			class ACE_ANPR39A2: ACE_Default
			{
				ace_sys_air_rwr_skin = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_anapr39.paa";
			};
			class ACE_SPO15
			{
				ace_sys_air_rwr_type = 0;
				ace_sys_air_rwr_detectMissile = 1;
				ace_sys_air_rwr_alphanumeric = 0;
			};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_air_rwr
	{
		clientinit = "call ('\x\ace\addons\sys_air_rwr\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_GetIn_EventHandlers
{
	class Air
	{
		class ace_sys_air_rwr
		{
			clientGetIn = "if (player == _this select 2) then {_this call ace_sys_air_rwr_fnc_getIn}";
			exclude[] = {"BIS_Steerable_Parachute"};
		};
	};
	class Tank
	{
		class ace_sys_air_rwr
		{
			clientGetIn = "if (player == _this select 2) then {_this call ace_sys_air_rwr_fnc_getIn}";
		};
	};
	class Car
	{
		class ace_sys_air_rwr
		{
			clientGetIn = "if (player == _this select 2) then {_this call ace_sys_air_rwr_fnc_getIn}";
		};
	};
};
class Extended_InitPost_EventHandlers
{
	class Air
	{
		class ace_sys_air_rwr
		{
			clientInit = "_this call ace_sys_air_rwr_fnc_init";
			exclude[] = {"BIS_Steerable_Parachute"};
		};
	};
	class Tank
	{
		class ace_sys_air_rwr
		{
			clientInit = "_this call ace_sys_air_rwr_fnc_init";
		};
	};
	class Car
	{
		class ace_sys_air_rwr
		{
			clientInit = "_this call ace_sys_air_rwr_fnc_init";
		};
	};
};
class CfgVehicles
{
	class Air;
	class Plane: Air
	{
		ace_sys_air_rwr_type = "ACE_Default";
	};
	class Helicopter: Air
	{
		ace_sys_air_rwr_type = "ACE_Default";
	};
	class Su34: Plane
	{
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_34.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class Su25_base: Plane
	{
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_25.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class Su39: Su25_base
	{
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_39.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class Kamov_Base: Helicopter
	{
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_ka.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class Mi24_Base: Helicopter
	{
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_mi.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class A10: Plane
	{
		ace_sys_air_rwr_type = "ACE_ANALR69";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_10.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class AV8B2: Plane
	{
		ace_sys_air_rwr_type = "ACE_ANALR67";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_av.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class C130J: Plane
	{
		ace_sys_air_rwr_type = "ACE_ANALR56";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_13.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class F35_base: Plane
	{
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_35.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class AH1_Base: Helicopter
	{
		ace_sys_air_rwr_type = "ACE_ANPR39A2";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_1z.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class AH64_base_EP1: Helicopter
	{
		ace_sys_air_rwr_type = "ACE_ANPR39A1";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_ah.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class L39_base: Plane
	{
		ace_sys_air_rwr_type = "ACE_SPO15";
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_l3.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class Tank;
	class 2S6M_Tunguska: Tank
	{
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_s6.paa";
		ace_sys_air_rwr_threat_img_spo = 3;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class ZSU_Base: Tank
	{
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_23.paa";
		ace_sys_air_rwr_threat_img_spo = 3;
		ace_sys_air_rwr_detectable = 1;
		ace_sys_air_rwr_hasrwr = 1;
		ace_sys_air_rwr_range = 3600;
	};
	class WarfareBBaseStructure;
	class BASE_WarfareBAntiAirRadar: WarfareBBaseStructure
	{
		ace_sys_air_rwr_detectable = 1;
	};
	class UAV;
	class MQ9PredatorB: UAV
	{
		ace_sys_air_rwr_threat_img = "\x\ace\addons\sys_air_rwr\data\rsc\threat_mq.paa";
		ace_sys_air_rwr_threat_img_spo = 0;
		ace_sys_air_rwr_detectable = 0;
	};
};
class ACE_RWR_RscPicture
{
	type = 0;
	idc = -1;
	style = 48;
	x = 0.1;
	y = 0.1;
	w = 0.4;
	h = 0.2;
	sizeEx = 0.023;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	font = "Zeppelin32";
	text = "";
};
class ACE_RWR_SPOMainThreat: ACE_RWR_RscPicture
{
	w = "(0.0143255*0.75) * SafeZoneW";
	h = "(0.0275089*0.75) * SafeZoneH";
	text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_primary_dir_act.paa";
};
class ACE_RWR_SPOSecondaryThreat: ACE_RWR_SPOMainThreat
{
	w = "(0.0143255*1) * SafeZoneW";
	h = "(0.0275089*1) * SafeZoneH";
	text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_secondary_dir_act.paa";
};
class ACE_RWR_SPOPrimaryThreatType: ACE_RWR_RscPicture
{
	w = "0.011991 * SafeZoneW";
	h = "0.0115254 * SafeZoneH";
	text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_act.paa";
};
class ACE_RWR_SPOSecondaryThreatType: ACE_RWR_SPOPrimaryThreatType{};
class RscTitles
{
	class ACE_RWR_US
	{
		idd = -1;
		duration = 1e+011;
		name = "ACE_RWR_US";
		onLoad = "uiNamespace setVariable ['ACE_RWR_US', _this select 0]";
		class controlsBackground
		{
			class BackGround: ACE_RWR_RscPicture
			{
				idc = 21999;
				x = "SafeZoneX + SafeZoneW - 0.01 - 0.22";
				y = "SafeZoneY + SafeZoneH - 0.01 - 0.2934";
				w = 0.22;
				h = 0.2934;
				colorBackground[] = {0,0,0,0};
				text = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_default.paa";
			};
		};
		class controls
		{
			class SR5RWR_display: ACE_RWR_RscPicture
			{
				idc = -1;
				colorText[] = {0.75,0.75,0.75,1};
				colorBackground[] = {0,0,0,0};
				font = "Bitstream";
				text = "";
				sizeEx = 0.018;
				x = "SafeZoneX + SafeZoneW - 0.01 - 0.22";
				y = "SafeZoneY + SafeZoneH - 0.01 - 0.2934";
				w = 0.022;
				h = 0.02934;
			};
			class SR5RWR_Threat01: SR5RWR_display
			{
				idc = "22000+ 0";
			};
			class SR5RWR_Threat02: SR5RWR_display
			{
				idc = "22000+ 1";
			};
			class SR5RWR_Threat03: SR5RWR_display
			{
				idc = "22000+ 2";
			};
			class SR5RWR_Threat04: SR5RWR_display
			{
				idc = "22000+ 3";
			};
			class SR5RWR_Threat05: SR5RWR_display
			{
				idc = "22000+ 4";
			};
			class SR5RWR_Threat06: SR5RWR_display
			{
				idc = "22000+ 5";
			};
			class SR5RWR_Threat07: SR5RWR_display
			{
				idc = "22000+ 6";
			};
			class SR5RWR_Threat08: SR5RWR_display
			{
				idc = "22000+ 7";
			};
			class SR5RWR_Threat09: SR5RWR_display
			{
				idc = "22000+ 8";
			};
			class SR5RWR_Threat10: SR5RWR_display
			{
				idc = "22000+ 9";
			};
			class SR5RWR_Threat11: SR5RWR_display
			{
				idc = "22000+ 10";
			};
			class SR5RWR_Threat12: SR5RWR_display
			{
				idc = "22000+ 11";
			};
			class SR5RWR_Threat13: SR5RWR_display
			{
				idc = "22000+ 12";
			};
			class SR5RWR_Threat14: SR5RWR_display
			{
				idc = "22000+ 13";
			};
			class SR5RWR_Threat15: SR5RWR_display
			{
				idc = "22000+ 14";
			};
			class SR5RWR_Threat16: SR5RWR_display
			{
				idc = "22000+ 15";
			};
			class SR5RWR_ThreatNew01: SR5RWR_display
			{
				idc = "22020+ 0";
			};
			class SR5RWR_ThreatNew02: SR5RWR_display
			{
				idc = "22020+ 1";
			};
			class SR5RWR_ThreatNew03: SR5RWR_display
			{
				idc = "22020+ 2";
			};
			class SR5RWR_ThreatNew04: SR5RWR_display
			{
				idc = "22020+ 3";
			};
			class SR5RWR_ThreatNew05: SR5RWR_display
			{
				idc = "22020+ 4";
			};
			class SR5RWR_ThreatNew06: SR5RWR_display
			{
				idc = "22020+ 5";
			};
			class SR5RWR_ThreatNew07: SR5RWR_display
			{
				idc = "22020+ 6";
			};
			class SR5RWR_ThreatNew08: SR5RWR_display
			{
				idc = "22020+ 7";
			};
			class SR5RWR_ThreatNew09: SR5RWR_display
			{
				idc = "22020+ 8";
			};
			class SR5RWR_ThreatNew10: SR5RWR_display
			{
				idc = "22020+ 9";
			};
			class SR5RWR_ThreatNew11: SR5RWR_display
			{
				idc = "22020+ 10";
			};
			class SR5RWR_ThreatNew12: SR5RWR_display
			{
				idc = "22020+ 11";
			};
			class SR5RWR_ThreatNew13: SR5RWR_display
			{
				idc = "22020+ 12";
			};
			class SR5RWR_ThreatNew14: SR5RWR_display
			{
				idc = "22020+ 13";
			};
			class SR5RWR_ThreatNew15: SR5RWR_display
			{
				idc = "22020+ 14";
			};
			class SR5RWR_ThreatNew16: SR5RWR_display
			{
				idc = "22020+ 15";
			};
			class SR5RWR_ThreatGround01: SR5RWR_display
			{
				idc = "22040+ 0";
			};
			class SR5RWR_ThreatGround02: SR5RWR_display
			{
				idc = "22040+ 1";
			};
			class SR5RWR_ThreatGround03: SR5RWR_display
			{
				idc = "22040+ 2";
			};
			class SR5RWR_ThreatGround04: SR5RWR_display
			{
				idc = "22040+ 3";
			};
			class SR5RWR_ThreatGround05: SR5RWR_display
			{
				idc = "22040+ 4";
			};
			class SR5RWR_ThreatGround06: SR5RWR_display
			{
				idc = "22040+ 5";
			};
			class SR5RWR_ThreatGround07: SR5RWR_display
			{
				idc = "22040+ 6";
			};
			class SR5RWR_ThreatGround08: SR5RWR_display
			{
				idc = "22040+ 7";
			};
			class SR5RWR_ThreatGround09: SR5RWR_display
			{
				idc = "22040+ 8";
			};
			class SR5RWR_ThreatGround10: SR5RWR_display
			{
				idc = "22040+ 9";
			};
			class SR5RWR_ThreatGround11: SR5RWR_display
			{
				idc = "22040+ 10";
			};
			class SR5RWR_ThreatGround12: SR5RWR_display
			{
				idc = "22040+ 11";
			};
			class SR5RWR_ThreatGround13: SR5RWR_display
			{
				idc = "22040+ 12";
			};
			class SR5RWR_ThreatGround14: SR5RWR_display
			{
				idc = "22040+ 13";
			};
			class SR5RWR_ThreatGround15: SR5RWR_display
			{
				idc = "22040+ 14";
			};
			class SR5RWR_ThreatGround16: SR5RWR_display
			{
				idc = "22040+ 15";
			};
			class SR5RWR_ThreatAir01: SR5RWR_display
			{
				idc = "22060+ 0";
			};
			class SR5RWR_ThreatAir02: SR5RWR_display
			{
				idc = "22060+ 1";
			};
			class SR5RWR_ThreatAir03: SR5RWR_display
			{
				idc = "22060+ 2";
			};
			class SR5RWR_ThreatAir04: SR5RWR_display
			{
				idc = "22060+ 3";
			};
			class SR5RWR_ThreatAir05: SR5RWR_display
			{
				idc = "22060+ 4";
			};
			class SR5RWR_ThreatAir06: SR5RWR_display
			{
				idc = "22060+ 5";
			};
			class SR5RWR_ThreatAir07: SR5RWR_display
			{
				idc = "22060+ 6";
			};
			class SR5RWR_ThreatAir08: SR5RWR_display
			{
				idc = "22060+ 7";
			};
			class SR5RWR_ThreatAir09: SR5RWR_display
			{
				idc = "22060+ 8";
			};
			class SR5RWR_ThreatAir10: SR5RWR_display
			{
				idc = "22060+ 9";
			};
			class SR5RWR_ThreatAir11: SR5RWR_display
			{
				idc = "22060+ 10";
			};
			class SR5RWR_ThreatAir12: SR5RWR_display
			{
				idc = "22060+ 11";
			};
			class SR5RWR_ThreatAir13: SR5RWR_display
			{
				idc = "22060+ 12";
			};
			class SR5RWR_ThreatAir14: SR5RWR_display
			{
				idc = "22060+ 13";
			};
			class SR5RWR_ThreatAir15: SR5RWR_display
			{
				idc = "22060+ 14";
			};
			class SR5RWR_ThreatAir16: SR5RWR_display
			{
				idc = "22060+ 15";
			};
			class SR5RWR_ThreatLaunch01: SR5RWR_display
			{
				idc = "22080+ 0";
			};
			class SR5RWR_ThreatLaunch02: SR5RWR_display
			{
				idc = "22080+ 1";
			};
			class SR5RWR_ThreatLaunch03: SR5RWR_display
			{
				idc = "22080+ 2";
			};
			class SR5RWR_ThreatLaunch04: SR5RWR_display
			{
				idc = "22080+ 3";
			};
			class SR5RWR_ThreatLaunch05: SR5RWR_display
			{
				idc = "22080+ 4";
			};
			class SR5RWR_ThreatLaunch06: SR5RWR_display
			{
				idc = "22080+ 5";
			};
			class SR5RWR_ThreatLaunch07: SR5RWR_display
			{
				idc = "22080+ 6";
			};
			class SR5RWR_ThreatLaunch08: SR5RWR_display
			{
				idc = "22080+ 7";
			};
			class SR5RWR_ThreatLaunch09: SR5RWR_display
			{
				idc = "22080+ 8";
			};
			class SR5RWR_ThreatLaunch10: SR5RWR_display
			{
				idc = "22080+ 9";
			};
			class SR5RWR_ThreatLaunch11: SR5RWR_display
			{
				idc = "22080+ 10";
			};
			class SR5RWR_ThreatLaunch12: SR5RWR_display
			{
				idc = "22080+ 11";
			};
			class SR5RWR_ThreatLaunch13: SR5RWR_display
			{
				idc = "22080+ 12";
			};
			class SR5RWR_ThreatLaunch14: SR5RWR_display
			{
				idc = "22080+ 13";
			};
			class SR5RWR_ThreatLaunch15: SR5RWR_display
			{
				idc = "22080+ 14";
			};
			class SR5RWR_ThreatLaunch16: SR5RWR_display
			{
				idc = "22080+ 15";
			};
		};
	};
	class ACE_RWR_RU
	{
		idd = -1;
		duration = 1e+011;
		name = "ACE_RWR_RU";
		onLoad = "uiNamespace setVariable ['ACE_RWR_RU', _this select 0]";
		class controlsBackground
		{
			class BackGround: ACE_RWR_RscPicture
			{
				idc = 21999;
				x = "0.894564 * SafeZoneW + SafeZoneX";
				y = "0.671654 * SafeZoneH + SafeZoneY - 0.42";
				w = "0.100852 * SafeZoneW";
				h = "0.322844 * SafeZoneH";
				colorBackground[] = {0,0,0,0};
				text = "\x\ace\addons\sys_air_rwr\data\rsc\rwr_background\rwr_spo.paa";
			};
		};
		class controls
		{
			class ACE_RWR_SPO_10L: ACE_RWR_SPOMainThreat
			{
				idc = "22000+ 0";
				x = "0.92763 * SafeZoneW + SafeZoneX";
				y = "0.734265 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_10R: ACE_RWR_SPO_10L
			{
				idc = "22000+ 1";
				x = "0.949315 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_30L: ACE_RWR_SPOMainThreat
			{
				idc = "22000+ 2";
				x = "0.914935 * SafeZoneW + SafeZoneX";
				y = "0.745139 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_30R: ACE_RWR_SPO_30L
			{
				idc = "22000+ 3";
				x = "0.962538 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_50L: ACE_RWR_SPOMainThreat
			{
				idc = "22000+ 4";
				x = "0.906473 * SafeZoneW + SafeZoneX";
				y = "0.763919 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_50R: ACE_RWR_SPO_50L
			{
				idc = "22000+ 5";
				x = "0.97153 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_90L: ACE_RWR_SPOMainThreat
			{
				idc = "22000+ 6";
				x = "0.902771 * SafeZoneW + SafeZoneX";
				y = "0.785666 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_90R: ACE_RWR_SPO_90L
			{
				idc = "22000+ 7";
				x = "0.974702 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_90LB: ACE_RWR_SPOMainThreat
			{
				idc = "22000+ 28";
				x = "0.917051 * safezoneW + safezoneX";
				y = "0.845962 * safezoneH + safezoneY - 0.42";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_primary_dir_act90S.paa";
			};
			class ACE_RWR_SPO_90RB: ACE_RWR_SPO_90LB
			{
				idc = "22000+ 29";
				x = "0.96148 * safezoneW + safezoneX";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_primary_dir_act90B.paa";
			};
			class ACE_RWR_SPO_10LS: ACE_RWR_SPOSecondaryThreat
			{
				idc = "22000+ 8";
				x = "0.928688 * SafeZoneW + SafeZoneX";
				y = "0.745139 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_10RS: ACE_RWR_SPO_10LS
			{
				idc = "22000+ 9";
				x = "0.945612 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_30LS: ACE_RWR_SPOSecondaryThreat
			{
				idc = "22000+ 10";
				x = "0.918637 * SafeZoneW + SafeZoneX";
				y = "0.753046 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_30RS: ACE_RWR_SPO_30LS
			{
				idc = "22000+ 11";
				x = "0.956192 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_50LS: ACE_RWR_SPOSecondaryThreat
			{
				idc = "22000+ 12";
				x = "0.912291 * SafeZoneW + SafeZoneX";
				y = "0.766884 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_50RS: ACE_RWR_SPO_50LS
			{
				idc = "22000+ 13";
				x = "0.963068 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_90LS: ACE_RWR_SPOSecondaryThreat
			{
				idc = "22000+ 14";
				x = "0.909118 * SafeZoneW + SafeZoneX";
				y = "0.784677 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_90RS: ACE_RWR_SPO_90LS
			{
				idc = "22000+ 15";
				x = "0.965712 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_90LSB: ACE_RWR_SPOSecondaryThreat
			{
				idc = "22000+ 30";
				x = "0.920754 * safezoneW + safezoneX";
				y = "0.830147 * safezoneH + safezoneY - 0.42";
			};
			class ACE_RWR_SPO_90RSB: ACE_RWR_SPO_90LSB
			{
				idc = "22000+ 31";
				x = "0.953546 * safezoneW + safezoneX";
			};
			class ACE_RWR_SPO_PT1: ACE_RWR_SPOPrimaryThreatType
			{
				idc = "22000+ 16";
				x = "0.909646 * SafeZoneW + SafeZoneX";
				y = "0.869684 * SafeZoneH + SafeZoneY - 0.42";
			};
			class ACE_RWR_SPO_PT2: ACE_RWR_SPO_PT1
			{
				idc = "22000+ 17";
				x = "0.921811 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_PT3: ACE_RWR_SPO_PT1
			{
				idc = "22000+ 18";
				x = "0.933976 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_PT4: ACE_RWR_SPO_PT1
			{
				idc = "22000+ 19";
				x = "0.945612 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_PT5: ACE_RWR_SPO_PT1
			{
				idc = "22000+ 20";
				x = "0.958307 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_PT6: ACE_RWR_SPO_PT1
			{
				idc = "22000+ 21";
				x = "0.970472 * SafeZoneW + SafeZoneX";
			};
			class ACE_RWR_SPO_ST1: ACE_RWR_SPOSecondaryThreatType
			{
				idc = "22000+ 22";
				x = "0.909646 * SafeZoneW + SafeZoneX";
				y = "0.878581 * SafeZoneH + SafeZoneY - 0.42";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_n.paa";
			};
			class ACE_RWR_SPO_ST2: ACE_RWR_SPO_ST1
			{
				idc = "22000+ 23";
				x = "0.921811 * SafeZoneW + SafeZoneX";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_3.paa";
			};
			class ACE_RWR_SPO_ST3: ACE_RWR_SPO_ST1
			{
				idc = "22000+ 24";
				x = "0.933976 * SafeZoneW + SafeZoneX";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_x.paa";
			};
			class ACE_RWR_SPO_ST4: ACE_RWR_SPO_ST1
			{
				idc = "22000+ 25";
				x = "0.945612 * SafeZoneW + SafeZoneX";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_h.paa";
			};
			class ACE_RWR_SPO_ST5: ACE_RWR_SPO_ST1
			{
				idc = "22000+ 26";
				x = "0.958307 * SafeZoneW + SafeZoneX";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_f.paa";
			};
			class ACE_RWR_SPO_ST6: ACE_RWR_SPO_ST1
			{
				idc = "22000+ 27";
				x = "0.970472 * SafeZoneW + SafeZoneX";
				text = "\x\ace\addons\sys_air_rwr\data\rsc\threat_c.paa";
			};
			class ACE_RWR_SPO_SignalStrength: ACE_RWR_RscPicture
			{
				idc = "22000+ 32";
				text = "";
				x = "0.919168 * safezoneW + safezoneX";
				y = "0.76293 * safezoneH + safezoneY - 0.42";
				w = "0.0504129 * safezoneW";
				h = "0.0809278 * safezoneH";
			};
			class ACE_RWR_SPO_Launch: ACE_RWR_RscPicture
			{
				idc = "22000+ 33";
				text = "";
				x = "0.891662 * safezoneW + safezoneX";
				y = "0.676935 * safezoneH + safezoneY - 0.42";
				w = "0.10595 * safezoneW";
				h = "0.308274 * safezoneH";
			};
		};
	};
};
class CfgSounds
{
	class ACE_SR5RWR_tunguska
	{
		name = "ACE_SR5RWR_tunguska";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\2S6.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_shilka
	{
		name = "ACE_SR5RWR_shilka";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\gundish.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_sa9
	{
		name = "ACE_SR5RWR_sa9";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\sa9.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_generic
	{
		name = "ACE_SR5RWR_generic";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\tinshield.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_blufor
	{
		name = "ACE_SR5RWR_blufor";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\TPS63.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_opfor
	{
		name = "ACE_SR5RWR_opfor";
		sound[] = {"\x\ace\addons\sys_air_rwr\sounds\longtrak.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_amraam
	{
		name = "ACE_SR5RWR_amraam";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\amraam.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_lock
	{
		name = "ACE_SR5RWR_lock";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\TwsLock.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_launch
	{
		name = "ACE_SR5RWR_launch";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\TwsLnch.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_launchIR
	{
		name = "ACE_SR5RWR_launchIR";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\TwsLncIR.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SR5RWR_air
	{
		name = "ACE_SR5RWR_air";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\MIG25.ogg","db+6",1.0};
		titles[] = {};
	};
	class ACE_SPO15_TRACK
	{
		name = "ACE_SPO15_TRACK";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\SPOTrack.ogg",0.0030957,1.0};
		titles[] = {};
	};
	class ACE_SPO15_IR
	{
		name = "ACE_SPO15_IR";
		sound[] = {"\x\ace\addons\sys_air_rwr\sound\SPOIR.ogg",0.0030957,1.0};
		titles[] = {};
	};
};
//};
