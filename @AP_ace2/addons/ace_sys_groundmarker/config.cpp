////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:23 2013 : Created on Sat Apr 06 11:45:23 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_groundmarker : config.bin{
class CfgPatches
{
	class ace_sys_groundmarker
	{
		units[] = {"ACE_VS17PANEL","ACE_VS21APANEL","ACE_VS21BPANEL","ACE_VS21CPANEL","ACE_VS21MEDICPANEL"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_interaction"};
		version = "1.14.0.590";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_groundmarker
		{
			list[] = {"ace_sys_groundmarker"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_groundmarker
	{
		init = "call ('\x\ace\addons\sys_groundmarker\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_groundmarker\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgWeapons
{
	class Default;
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_groundmarker: ACE_Dummy_Utility
		{
			magazines[] = {"ACE_VS17PANEL_M","ACE_VS21APANEL_M","ACE_VS21BPANEL_M","ACE_VS21CPANEL_M","ACE_VS21MEDICPANEL_m"};
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class ACE_VS17PANEL_M: CA_Magazine
	{
		ACE_Weight = 0.115;
		ACE_Size = 10;
		scope = 2;
		value = 1;
		type = 256;
		ammo = "";
		displayName = "$STR_DN_ACE_VS17PANEL";
		picture = "\x\ace\addons\sys_groundmarker\data\equip\m_vs17_ca.paa";
		count = 1;
		initSpeed = 100;
	};
	class ACE_VS21APANEL_M: ACE_VS17Panel_M
	{
		displayName = "$STR_DN_ACE_VS21PANEL";
		descriptionShort = "Type A";
		picture = "\x\ace\addons\sys_groundmarker\data\equip\m_vs21a_ca.paa";
		ACE_Weight = 0.5;
		ACE_Size = 39;
	};
	class ACE_VS21BPANEL_M: ACE_VS21APanel_M
	{
		descriptionShort = "Type B";
		picture = "\x\ace\addons\sys_groundmarker\data\equip\m_vs21b_ca.paa";
	};
	class ACE_VS21CPANEL_M: ACE_VS21APanel_M
	{
		descriptionShort = "Type C";
		picture = "\x\ace\addons\sys_groundmarker\data\equip\m_vs21c_ca.paa";
	};
	class ACE_VS21MEDICPANEL_M: ACE_VS21APanel_M
	{
		descriptionShort = "Medical";
		picture = "\x\ace\addons\sys_groundmarker\data\equip\m_vs21med_ca.paa";
	};
};
class CfgVehicles
{
	class NonStrategic;
	class ACE_GroundMarker_Base: NonStrategic
	{
		scope = 1;
		displayName = "$STR_DN_ACE_VSPANEL_FAKE";
		animated = 1;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_VS17PANEL: ACE_GroundMarker_Base
	{
		model = "\x\ace\addons\sys_groundmarker\ace_vs17.p3d";
		class AnimationSources
		{
			class flip
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class rotate: flip{};
			class hide: flip{};
		};
		htMin = 1;
		htMax = 2;
		afMax = 0;
		mfMax = 200;
		mFact = 0;
		tBody = 0;
	};
	class ACE_VS21APANEL: ACE_VS17PANEL
	{
		model = "\x\ace\addons\sys_groundmarker\ace_vs21_a.p3d";
		class AnimationSources: AnimationSources
		{
			class flip: flip{};
			class rotate: rotate{};
			class hide: hide{};
			class camo: hide
			{
				initPhase = 0;
			};
		};
		htMin = 60;
		htMax = 1800;
		afMax = 0;
		mfMax = 0;
		mFact = 0;
		tBody = 8000;
	};
	class ACE_VS21BPANEL: ACE_VS21APANEL
	{
		model = "\x\ace\addons\sys_groundmarker\ace_vs21_b.p3d";
	};
	class ACE_VS21CPANEL: ACE_VS21APANEL
	{
		model = "\x\ace\addons\sys_groundmarker\ace_vs21_c.p3d";
	};
	class ACE_VS21MEDICPANEL: ACE_VS17PANEL
	{
		model = "\x\ace\addons\sys_groundmarker\ace_vs21_medic.p3d";
		class AnimationSources
		{
			class flip
			{
				source = "user";
				animPeriod = 0.01;
				initPhase = 0;
			};
			class hide: flip{};
		};
		htMin = 60;
		htMax = 1800;
		afMax = 0;
		mfMax = 0;
		mFact = 0;
		tBody = 8000;
	};
};
//};
