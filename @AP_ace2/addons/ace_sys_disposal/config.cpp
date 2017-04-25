////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Jun 08 13:06:12 2013 : Created on Sat Jun 08 13:06:12 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_disposal : config.bin{
class CfgPatches
{
	class ace_sys_disposal
	{
		units[] = {"ACE_M136_Used_Tube","ACE_RPG18_Used_Tube","ACE_Javelin_Used_Tube"};
		weapons[] = {"ACE_M136_Used","ACE_RPG18_Used","ACE_Javelin_Used","ACE_Javelin_CLU"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","CAWheeled","CATracked","CAWeapons","CAWeapons2","CAWeapons2_RPG18","CAWeapons_E_M136","CAWeapons_E_RPG18","ace_sys_stamina","ace_main"};
		version = "1.14.0.593";
		author[] = {"Inkompetent","zGuba"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_disposal
		{
			list[] = {"ace_sys_disposal"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_disposal
	{
		Init = "call ('\x\ace\addons\sys_disposal\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_disposal
	{
		init = "call ('\x\ace\addons\sys_disposal\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		ace_sys_disposal = "if (local (_this select 0)) then {if (getNumber (configFile >> 'CfgWeapons' >> (_this select 1) >> 'ace_disposable') == 1) then {_this spawn ace_sys_disposal_fnc_fired}}";
	};
};
class Extended_AnimStateChanged_EventHandlers
{
	class CAManBase
	{
		class ace_sys_disposal
		{
			clientAnimStateChanged = "if (player == (_this select 0) && {((_this select 1) == 'ace_launcherkneel_launcherprone')}) then {_this spawn ace_sys_disposal_fnc_launcher_prone}";
		};
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class ace_sys_disposal
		{
			init = "if (local (_this select 0)) then {if (secondaryWeapon (_this select 0) != '') then {_this call ace_sys_disposal_fnc_partcheck}}";
		};
	};
};
class CfgMagazines
{
	class CA_LauncherMagazine;
	class M136: CA_LauncherMagazine
	{
		ace_weight = 0;
		ace_disposable = 1;
		displayName = "M136 AT-4";
		model = "\ca\weapons\empty";
		modelSpecial = "\x\ace\addons\sys_disposal\ace_m136_armed.p3d";
		picture = "\CA\weapons\data\clear_empty.paa";
		type = 256;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M136_Used: M136
	{
		scope = 1;
		count = 0;
		displayName = "$STR_ACE_WDN_ACE_M136_USED";
		modelSpecial = "\x\ace\addons\sys_disposal\ace_m136_used.p3d";
	};
	class ACE_M136_CSRS: M136
	{
		displayName = "M136 AT4 CS/RS";
		ammo = "ACE_R_M136_CSRS";
	};
	class ACE_M136_CSRS_Used: ACE_M136_Used{};
	class ACE_M136_CSHP: M136
	{
		displayName = "M136 AT4 CS/HP";
		ammo = "ACE_R_M136_CSHP";
	};
	class ACE_M136_CSHP_Used: ACE_M136_Used{};
	class RPG18: CA_LauncherMagazine
	{
		ace_weight = 0;
		ace_disposable = 1;
		displayName = "$STR_ACE_WDN_RPG18";
		model = "\ca\weapons\empty";
		picture = "\CA\weapons\data\clear_empty.paa";
		type = 256;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_RPG18_Used: RPG18
	{
		scope = 1;
		count = 0;
		displayName = "$STR_ACE_WDN_ACE_RPG18_USED";
	};
	class NLAW: CA_LauncherMagazine
	{
		ace_weight = 0;
		ace_disposable = 1;
		model = "\ca\weapons\empty";
		picture = "\CA\weapons\data\clear_empty.paa";
		type = 256;
		displayName = "NLAW";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_NLAW_Used: NLAW
	{
		scope = 1;
		count = 0;
		displayName = "$STR_ACE_WDN_ACE_NLAW_USED";
	};
	class Javelin: CA_LauncherMagazine
	{
		ace_weight = 0;
		ace_disposable = 1;
		displayName = "M98A1 CLU";
		model = "\ca\weapons\empty";
		picture = "\CA\weapons\data\clear_empty.paa";
		type = 256;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Javelin_Used: Javelin
	{
		scope = 1;
		count = 0;
		displayName = "$STR_ACE_WDN_ACE_JAVELIN_USED";
	};
};
class CfgVehicles
{
	class Thing;
	class ACE_UsedTubes: Thing
	{
		scope = 1;
		side = 4;
		model = "\x\ace\addons\sys_disposal\ace_m136_used_vehicle.p3d";
		icon = "";
		camouflage = 0.1;
		destrType = "DestructNo";
		mapSize = 0;
		accuracy = 0;
		armor = 5;
		typicalCargo[] = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		class DestructionEffects{};
		weight = 1000;
		gravityFactor = 1.2;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_M136_Used_Tube: ACE_UsedTubes
	{
		model = "\x\ace\addons\sys_disposal\ace_m136_used_vehicle.p3d";
	};
	class ACE_RPG18_Used_Tube: ACE_UsedTubes
	{
		model = "\x\ace\addons\sys_disposal\ace_rpg18_used_vehicle.p3d";
	};
	class ACE_NLAW_Used_Tube: ACE_UsedTubes
	{
		model = "\x\ace\addons\sys_disposal\ace_nlaw_used_vehicle.p3d";
	};
	class ACE_Javelin_Used_Tube: ACE_UsedTubes
	{
		model = "\x\ace\addons\sys_disposal\ace_javelin_used_vehicle.p3d";
	};
	class US_Backpack_EP1;
	class US_Backpack_AT_EP1: US_Backpack_EP1
	{
		transportMaxWeapons = 2;
		class TransportMagazines
		{
			class _xx_Javelin
			{
				magazine = "Javelin";
				count = 0;
			};
		};
		class TransportWeapons
		{
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 1;
			};
			class _xx_ACE_Javelin_Direct
			{
				weapon = "ACE_Javelin_Direct";
				count = 1;
			};
		};
	};
	class ReammoBox;
	class USBasicAmmunitionBox: ReammoBox{};
	class USLaunchersBox: USBasicAmmunitionBox
	{
		class TransportMagazines
		{
			class _xx_Javelin
			{
				magazine = "Javelin";
				count = 0;
			};
		};
		class TransportWeapons
		{
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 2;
			};
			class _xx_ACE_Javelin_CLU
			{
				weapon = "ACE_Javelin_CLU";
				count = 1;
			};
		};
	};
	class ReammoBox_EP1;
	class USLaunchers_EP1: ReammoBox_EP1
	{
		class TransportMagazines
		{
			class _xx_Javelin
			{
				magazine = "Javelin";
				count = 0;
			};
		};
		class TransportWeapons
		{
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 5;
			};
			class _xx_ACE_Javelin_CLU
			{
				weapon = "ACE_Javelin_CLU";
				count = 1;
			};
		};
	};
	class Bag_Base_BAF;
	class BAF_AssaultPack_HATAmmo: Bag_Base_BAF
	{
		transportMaxWeapons = 2;
		class TransportMagazines
		{
			class _xx_Javelin
			{
				magazine = "Javelin";
				count = 0;
			};
		};
		class TransportWeapons
		{
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 1;
			};
			class _xx_ACE_Javelin_Direct
			{
				weapon = "ACE_Javelin_Direct";
				count = 1;
			};
		};
	};
	class BAF_BasicAmmunitionBox: ReammoBox_EP1
	{
		class TransportMagazines
		{
			class _xx_Javelin
			{
				magazine = "Javelin";
				count = 0;
			};
		};
		class TransportWeapons
		{
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 30;
			};
		};
	};
	class BAF_Launchers: ReammoBox_EP1
	{
		class TransportMagazines
		{
			class _xx_Javelin
			{
				magazine = "Javelin";
				count = 0;
			};
		};
		class TransportWeapons
		{
			class _xx_Javelin
			{
				weapon = "Javelin";
				count = 5;
			};
			class _xx_ACE_Javelin_CLU
			{
				weapon = "ACE_Javelin_CLU";
				count = 1;
			};
		};
	};
};
class CfgWeapons
{
	class LauncherCore;
	class Launcher: LauncherCore
	{
		ace_disposable = 0;
	};
	class M136: Launcher
	{
		ace_weight = 6.7;
		dexterity = "(0.5 + 3.75/(6.7 + 0.001) + 0/10)";
		ace_disposable = 1;
		ace_disposable_used = "ACE_M136_Used";
		ace_disposable_model = "ACE_M136_Used_Tube";
		displayName = "M136 AT4";
		model = "\x\ace\addons\sys_disposal\ace_m136_safe.p3d";
	};
	class ACE_M136_CSRS: M136
	{
		ace_weight = 7.5;
		dexterity = "(0.5 + 3.75/(7.5 + 0.001) + 0/10)";
		displayName = "M136 AT4 CS/RS";
		magazines[] = {"ACE_M136_CSRS"};
	};
	class ACE_M136_Used: M136
	{
		scope = 1;
		ace_weight = 4.9;
		dexterity = "(0.5 + 3.75/(4.9 + 0.001) + 0/10)";
		ace_disposable = 0;
		ace_isusedweapon = 1;
		magazines[] = {"ACE_M136_Used"};
		displayName = "$STR_ACE_WDN_ACE_M136_USED";
		model = "\x\ace\addons\sys_disposal\ace_m136_used.p3d";
		class Armory
		{
			disabled = 1;
		};
	};
	class RPG18: Launcher
	{
		ace_weight = 2.6;
		dexterity = "(0.5 + 3.75/(2.6 + 0.001) + 0/10)";
		ace_disposable = 1;
		ace_disposable_used = "ACE_RPG18_Used";
		ace_disposable_model = "ACE_RPG18_Used_Tube";
		displayName = "$STR_ACE_WDN_RPG18";
	};
	class ACE_RPG18_Used: RPG18
	{
		scope = 1;
		ace_weight = 1.4;
		dexterity = "(0.5 + 3.75/(1.4 + 0.001) + 0/10)";
		ace_disposable = 0;
		ace_isusedweapon = 1;
		magazines[] = {"ACE_RPG18_Used"};
		displayName = "$STR_ACE_WDN_ACE_RPG18_USED";
		model = "\ca\weapons2\rpg18\rpg18_loaded";
		class Armory
		{
			disabled = 1;
		};
	};
	class BAF_NLAW_Launcher: Launcher
	{
		ace_weight = 12.5;
		dexterity = "(0.5 + 3.75/(12.5 + 0.001) + -3/10)";
		ace_disposable = 1;
		ace_disposable_used = "ACE_NLAW_Used";
		ace_disposable_model = "ACE_NLAW_Used_Tube";
		model = "\ca\weapons_BAF\nlaw_loaded_BAF";
	};
	class ACE_NLAW_Used: BAF_NLAW_Launcher
	{
		scope = 1;
		ace_weight = 2.5;
		dexterity = "(0.5 + 3.75/(2.5 + 0.001) + -3/10)";
		ace_disposable = 0;
		ace_isusedweapon = 1;
		magazines[] = {"ACE_NLAW_Used"};
		displayName = "$STR_ACE_WDN_ACE_NLAW_USED";
		model = "\ca\weapons_BAF\nlaw_BAF";
		class Armory
		{
			disabled = 1;
		};
	};
	class Javelin: Launcher
	{
		ace_weight = 15.5;
		dexterity = "(0.5 + 3.75/(4.1+ 11.4+ 6.4 + 0.001) + -3/10)";
		ace_disposable = 1;
		ace_disposable_needpart = 1;
		ace_disposable_neededpart = "ACE_Javelin_CLU";
		ace_disposable_used = "ACE_Javelin_Used";
		ace_disposable_model = "ACE_Javelin_Used_Tube";
	};
	class ACE_Javelin_Used: Javelin
	{
		scope = 1;
		ace_weight = 4.1;
		dexterity = "(0.5 + 3.75/(4.1 + 0.001) + -3/10)";
		ace_disposable = 0;
		ace_isusedweapon = 1;
		magazines[] = {"ACE_Javelin_Used"};
		model = "\x\ace\addons\sys_disposal\ace_javelin_used.p3d";
		displayName = "$STR_ACE_WDN_ACE_JAVELIN_USED";
		weaponInfoType = "ACE_RscWeaponInfoJavelin_CLU";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Javelin_CLU: Javelin
	{
		ace_weight = 6.4;
		dexterity = "(0.5 + 3.75/(6.4 + 0.001) + -3/10)";
		displayName = "FGM-148 CLU";
		model = "\x\ace\addons\sys_disposal\ace_javelin_clu.p3d";
		picture = "\x\ace\addons\sys_disposal\data\equip\clu_ca.paa";
		weaponInfoType = "ACE_RscWeaponInfoJavelin_CLU";
		reloadaction = "";
		showSwitchAction = 1;
		useAsBinocular = 1;
		uipicture = "";
		descriptionshort = "M98A1 Command Launch Unit";
		ace_disposable = 0;
		magazines[] = {};
		type = 4096;
	};
};
class RscControlsGroup;
class RscPicture;
class RscLine;
class RscInGameUI
{
	class ACE_RscWeaponInfoJavelin_CLU
	{
		idd = 300;
		controls[] = {"CA_javelin_elements_group"};
		class CA_javelin_elements_group: RscControlsGroup
		{
			x = "SafezoneX";
			y = "SafezoneY";
			w = "SafezoneW";
			h = "SafezoneH";
			idc = 170;
			class VScrollbar
			{
				autoScrollSpeed = -1;
				autoScrollDelay = 5;
				autoScrollRewind = 0;
				color[] = {1,1,1,0};
				width = 0.001;
			};
			class HScrollbar
			{
				color[] = {1,1,1,0};
				height = 0.001;
			};
			class Controls
			{
				class CA_Javelin_Day_mode_off: RscPicture
				{
					idc = 1001;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.03/4)*3*SafezoneH - SafezoneX";
					y = "SafezoneY+SafezoneH*0.031 - SafezoneY";
					w = "0.1045752* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
					h = "SafezoneH*0.1045752";
					colorText[] = {0.2941,0.2941,0.2941,1};
					text = "\ca\ui\data\igui_javelin_day_co.paa";
				};
				class CA_Javelin_Day_mode: CA_Javelin_Day_mode_off
				{
					idc = 160;
					colorText[] = {0.2941,0.8745,0.2157,1};
				};
				class CA_Javelin_WFOV_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1004;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.307/4)*3*SafezoneH - SafezoneX";
					text = "\ca\ui\data\igui_javelin_wfov_co.paa";
				};
				class CA_Javelin_WFOV_mode_group: RscControlsGroup
				{
					x = "SafezoneX";
					y = "SafezoneY";
					w = "SafezoneW";
					h = "SafezoneH";
					idc = 163;
					class VScrollbar
					{
						autoScrollSpeed = -1;
						autoScrollDelay = 5;
						autoScrollRewind = 0;
						color[] = {1,1,1,0};
						width = 0.001;
					};
					class HScrollbar
					{
						color[] = {1,1,1,0};
						height = 0.001;
					};
					class Controls
					{
						class CA_Javelin_WFOV_mode: CA_Javelin_WFOV_mode_off
						{
							idc = -1;
							y = "0.031*SafeZoneH - SafezoneY";
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.307/4)*3*SafezoneH - SafezoneX";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaL: RscLine
						{
							x = "0.4899*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaR: RscLine
						{
							x = "0.5109*SafezoneW- SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketL: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.293/4)*3*SafezoneH - SafezoneX";
							y = "0.4677*SafezoneH - SafezoneY";
							w = 0;
							h = "0.0646*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketR: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.70/4)*3*SafezoneH - SafezoneX";
							y = "0.4677*SafezoneH - SafezoneY";
							w = 0;
							h = "0.0646*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketT: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.467/4)*3*SafezoneH - SafezoneX";
							y = "0.3535*SafezoneH - SafezoneY";
							w = "0.065* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = 0;
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class BracketB: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.467/4)*3*SafezoneH - SafezoneX";
							y = "0.6465*SafezoneH - SafezoneY";
							w = "0.065* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = 0;
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
					};
				};
				class CA_Javelin_NFOV_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1003;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.586/4)*3*SafezoneH - SafezoneX";
					text = "\ca\ui\data\igui_javelin_nfov_co.paa";
				};
				class CA_Javelin_NFOV_mode_group: RscControlsGroup
				{
					x = "SafezoneX";
					y = "SafezoneY";
					w = "SafezoneW-SafezoneX";
					h = "SafezoneH-SafezoneY";
					idc = 162;
					class VScrollbar
					{
						autoScrollSpeed = -1;
						autoScrollDelay = 5;
						autoScrollRewind = 0;
						color[] = {1,1,1,0};
						width = 0.001;
					};
					class HScrollbar
					{
						color[] = {1,1,1,0};
						height = 0.001;
					};
					class Controls
					{
						class CA_Javelin_NFOV_mode: CA_Javelin_NFOV_mode_off
						{
							idc = -1;
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.586/4)*3*SafezoneH - SafezoneX";
							y = "0.031*SafeZoneH - SafezoneY";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaL: RscLine
						{
							x = "0.4788*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class StadiaR: RscLine
						{
							x = "0.5212*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.049*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineHL: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.01/4)*3*SafezoneH - SafezoneX";
							y = "SafezoneH*0.5 - SafezoneY";
							w = "0.29* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = "SafezoneH*0.0";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineHR: RscLine
						{
							x = "((SafezoneW -SafezoneH*3/4)/2)+ (0.695/4)*3*SafezoneH - SafezoneX";
							y = "SafezoneH*0.5 - SafezoneY";
							w = "0.29* (((SafezoneW*3)/4)/SafezoneW)/(1/SafezoneH)";
							h = "SafezoneH*0.0";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineVT: RscLine
						{
							x = "0.5*SafezoneW - SafezoneX";
							y = "0.171*SafezoneH - SafezoneY";
							w = 0;
							h = "0.1825*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
						class LineVB: RscLine
						{
							x = "0.5*SafezoneW - SafezoneX";
							y = "0.6465*SafezoneH - SafezoneY";
							w = 0;
							h = "0.1895*SafezoneH";
							colorText[] = {0.2941,0.8745,0.2157,1};
						};
					};
				};
				class CA_Javelin_SEEK_off: CA_Javelin_Day_mode_off
				{
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (0.863/4)*3*SafezoneH - SafezoneX";
					text = "\ca\ui\data\igui_javelin_seek_co.paa";
				};
				class CA_Javelin_SEEK: CA_Javelin_SEEK_off
				{
					idc = 166;
					colorText[] = {0.2941,0.8745,0.2157,1};
				};
				class CA_Javelin_Missle_off: CA_Javelin_Day_mode_off
				{
					idc = 1032;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (-0.134/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.208*SafezoneH) - SafezoneY";
					colorText[] = {0.9255,0.5216,0.1216,1};
					text = "\ca\ui\data\igui_javelin_missle_co.paa";
				};
				class CA_Javelin_Missle: CA_Javelin_Missle_off
				{
					idc = 167;
					colorText[] = {0.9255,0.5216,0.1216,1};
				};
				class CA_Javelin_CLU_off: CA_Javelin_Missle_off
				{
					idc = 1027;
					y = "(SafezoneY + 0.436*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_clu_co.paa";
					colorText[] = {0.2941,0.2941,0.2941,1};
				};
				class CA_Javelin_HangFire_off: CA_Javelin_Missle_off
				{
					idc = 1028;
					y = "(SafezoneY + 0.669*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_hangfire_co.paa";
					colorText[] = {0.2941,0.2941,0.2941,1};
				};
				class CA_Javelin_TOP_off: CA_Javelin_Day_mode_off
				{
					idc = 1006;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.208*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_top_co.paa";
					colorText[] = {0.2941,0.2941,0.2941,1};
				};
				class CA_Javelin_DIR: CA_Javelin_Day_mode
				{
					idc = 1007;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.436*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_dir_co.paa";
					colorText[] = {0.2941,0.2941,0.2941,1};
				};
				class CA_Javelin_FLTR_mode_off: CA_Javelin_Day_mode_off
				{
					idc = 1002;
					x = "(SafezoneX+(SafezoneW -SafezoneH*3/4)/2)+ (1.023/4)*3*SafezoneH - SafezoneX";
					y = "(SafezoneY + 0.669*SafezoneH) - SafezoneY";
					text = "\ca\ui\data\igui_javelin_fltr_co.paa";
				};
				class CA_Javelin_FLTR_mode: CA_Javelin_FLTR_mode_off
				{
					idc = 161;
					colorText[] = {0.2941,0.8745,0.2157,1};
				};
			};
		};
	};
};
//};
