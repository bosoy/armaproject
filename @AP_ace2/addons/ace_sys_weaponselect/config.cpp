////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:08:45 2013 : Created on Mon Oct 14 23:08:45 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_weaponselect : config.bin{
class CfgPatches
{
	class ace_sys_weaponselect
	{
		units[] = {};
		weapons[] = {"ace_safe"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_c_weapon"};
		version = "1.14.0.597";
		author[] = {"q1184","rocko"};
		class ACE_Options
		{
			group = "WEP";
			title = " ";
		};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_weaponselect
		{
			list[] = {"ace_sys_weaponselect"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_weaponselect
	{
		clientInit = "call ('\x\ace\addons\sys_weaponselect\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_weaponselect
	{
		clientInit = "call ('\x\ace\addons\sys_weaponselect\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_GetOut_EventHandlers
{
	class All
	{
		class ace_sys_weaponselect
		{
			clientGetOut = "if (player == (_this select 2)) then {_this call ace_sys_weaponselect_fnc_clientGetOut}";
		};
	};
};
class cfgWeapons
{
	class GrenadeLauncher;
	class PistolCore;
	class Pistol: PistolCore
	{
		ace_firemode_sound = "pla";
	};
	class RifleCore;
	class Rifle: RifleCore
	{
		ace_firemode_sound = "pla";
		class M203Muzzle: GrenadeLauncher
		{
			ace_firemode_sound = "met";
		};
	};
	class AK_BASE: Rifle
	{
		ace_firemode_sound = "met";
	};
	class SVD: Rifle
	{
		ace_firemode_sound = "met";
	};
	class VSS_vintorez: Rifle
	{
		ace_firemode_sound = "met";
	};
	class Sa58P_EP1: Rifle
	{
		ace_firemode_sound = "met";
	};
	class UK59_ACR: Rifle
	{
		ace_firemode_sound = "met";
	};
	class LauncherCore;
	class Launcher: LauncherCore
	{
		ace_firemode_sound = "met";
	};
	class MP5SD;
	class MP5A5: MP5SD{};
	class Evo_ACR: MP5A5{};
	class Evo_mrad_ACR: Evo_ACR
	{
		ace_gunlight_classes[] = {"Evo_mrad_ACR","ACE_EVO3_CCO_F"};
	};
	class ACE_EVO3_CCO_F: Evo_mrad_ACR
	{
		class FlashLight
		{
			color[] = {0.9,0.9,0.7,0.9};
			ambient[] = {0.1,0.1,0.1,1.0};
			position = "flash dir";
			direction = "flash";
			angle = 20;
			scale[] = {0.9,0.9,0.4};
			brightness = 0.09;
		};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 0;
		class Armory
		{
			disabled = 1;
		};
	};
	class evo_sd_ACR: MP5SD
	{
		ace_gunlight_classes[] = {"evo_sd_ACR","ACE_EVO3_SD_CCO_L"};
	};
	class ACE_EVO3_SD_CCO_L: evo_sd_ACR
	{
		class FlashLight{};
		irLaserPos = "laser pos";
		irLaserEnd = "laser dir";
		irDistance = 100;
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgSounds
{
	class ace_switch_met_1
	{
		name = "ace_switch_met_1";
		sound[] = {"\x\ace\addons\sys_weaponselect\sound\firemodeswitch_met1.wav",5,1};
		titles[] = {};
	};
	class ace_switch_met_2
	{
		name = "ace_switch_met_2";
		sound[] = {"\x\ace\addons\sys_weaponselect\sound\firemodeswitch_met2.wav",5,1};
		titles[] = {};
	};
	class ace_switch_pla_1
	{
		name = "ace_switch_pla_1";
		sound[] = {"\x\ace\addons\sys_weaponselect\sound\firemodeswitch_pla1.wav",5,1};
		titles[] = {};
	};
	class ace_switch_pla_2
	{
		name = "ace_switch_pla_2";
		sound[] = {"\x\ace\addons\sys_weaponselect\sound\firemodeswitch_pla2.wav",5,1};
		titles[] = {};
	};
};
//};
