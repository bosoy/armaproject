////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:47:11 2013 : Created on Sat Apr 06 11:47:11 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_wirecutter : config.bin{
class CfgPatches
{
	class ace_sys_wirecutter
	{
		units[] = {};
		weapons[] = {"ACE_WireCutter"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAWeapons","ace_sys_interaction"};
		version = "1.14.0.590";
		author[] = {"Rocko","Xeno"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_wirecutter
		{
			list[] = {"ace_sys_wirecutter"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_wirecutter
	{
		init = "call ('\x\ace\addons\sys_wirecutter\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_wirecutter\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Mode_SemiAuto;
class CfgWeapons
{
	class Rifle;
	class ACE_WireCutter: Rifle
	{
		scope = 2;
		displayName = "$STR_DN_ACE_WIRECUTTER";
		descriptionShort = "";
		model = "\x\ace\addons\sys_wirecutter\wirecutter.p3d";
		picture = "\x\ace\addons\sys_wirecutter\data\equip\w_wirecutter_ca.paa";
		magazines[] = {};
		modes[] = {"Single"};
		class Single: Mode_SemiAuto
		{
			displayName = "$STR_DN_ACE_WIRECUTTER";
			begin1[] = {"",1.77828,1,1000};
			soundBegin[] = {"begin1",1};
			reloadTime = 0.075;
			recoil = "recoil_single_primary_3outof10";
			recoilProne = "recoil_single_primary_prone_3outof10";
			dispersion = 0.001;
			minRange = 2;
			minRangeProbab = 0.3;
			midRange = 250;
			midRangeProbab = 0.7;
			maxRange = 400;
			maxRangeProbab = 0.05;
		};
		class M203Muzzle{};
		ACE_Weight = 1.3;
		ACE_Size = 4000;
	};
};
class CfgSounds
{
	class ace_wire_cut
	{
		name = "ace_wire_cut";
		sound[] = {"\x\ace\addons\sys_wirecutter\sound\wirecut.ogg","db",1};
		titles[] = {};
	};
};
//};
