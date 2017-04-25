////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:35:13 2012 : Created on Fri Nov 09 22:35:13 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_targets : config.bin{
class CfgPatches
{
	class ace_sys_targets
	{
		units[] = {"ACE_Target_Invisible","ACE_Target_EInf","ACE_Target_WInf","ACE_Target_RInf","ACE_Target_CInf","ACE_Target_ELT","ACE_Target_WLT","ACE_Target_RLT","ACE_Target_CLT","ACE_Target_EArm","ACE_Target_WArm","ACE_Target_RArm","ACE_Target_CArm","ACE_Target_EHvy","ACE_Target_WHvy","ACE_Target_RHvy","ACE_Target_CHvy"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAMisc","CAMisc3"};
		version = "1.14.0.581";
		author[] = {"Rocko"};
	};
	class ace_sys_popup
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main"};
	};
	class ace_sys_invisible_targets
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main"};
	};
};
class CfgVehicleClasses
{
	class ACE_INVISIBLE_TARGETS
	{
		displayName = "$STR_ACE_INV_TARGETS";
	};
};
class CfgVehicles
{
	class TargetBase;
	class ACE_TargetBase: TargetBase
	{
		scope = 1;
		model = "\x\ace\addons\sys_targets\ace_target_popup.p3d";
		icon = "\Ca\misc\data\icons\i_terc_CA.paa";
		mapSize = 2;
		displayName = "xkjhkjlsjkd";
		accuracy = 1000;
		destrType = "DestructEngine";
		class AnimationSources
		{
			class terc
			{
				animPeriod = 1;
			};
		};
		class EventHandlers
		{
			hit = "[(_this select 0)] execVM ""ca\misc\scripts\PopUpTarget.sqf""";
		};
		class DestructionEffects{};
		hiddenSelections[] = {"__TEXTURE_ACE","__TEXTURE_DEFAULT"};
	};
	class ACE_Hostage_Target_1: ACE_TargetBase
	{
		scope = 2;
		displayName = "Hostage 1";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\blackhos_co.paa"};
	};
	class ACE_Hostage_Target_2: ACE_Hostage_Target_1
	{
		displayName = "Hostage 2";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\brownhos_co.paa"};
	};
	class ACE_Hostage_Target_3: ACE_Hostage_Target_1
	{
		displayName = "Hostage 3";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\greenhos_co.paa"};
	};
	class ACE_Hostage_Target_4: ACE_Hostage_Target_1
	{
		displayName = "Hostage 4";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\redhos_co.paa"};
	};
	class ACE_Hostage_Target_5: ACE_Hostage_Target_1
	{
		displayName = "Hostage 5";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\tanhos_co.paa"};
	};
	class ACE_Hostage_Target_6: ACE_Hostage_Target_1
	{
		displayName = "Hostage 6";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\whitehos_co.paa"};
	};
	class ACE_Box_Target_1: ACE_TargetBase
	{
		scope = 2;
		displayName = "Popup 1";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\greenfacumc_co.paa"};
	};
	class ACE_Box_Target_2: ACE_Box_Target_1
	{
		displayName = "Popup 2";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\brownfacumc_co.paa"};
	};
	class ACE_Box_Target_3: ACE_Box_Target_1
	{
		displayName = "Popup 3";
		hiddenSelectionsTextures[] = {"\x\ace\addons\sys_targets\data\facumc_co.paa"};
	};
	class ACE_Box_Target_1_Small: ACE_Box_Target_1
	{
		displayName = "Popup 1 Small";
		model = "\x\ace\addons\sys_targets\ace_target_popup_small.p3d";
	};
	class ACE_Box_Target_2_Small: ACE_Box_Target_2
	{
		displayName = "Popup 2 Small";
		model = "\x\ace\addons\sys_targets\ace_target_popup_small.p3d";
	};
	class ACE_Box_Target_3_Small: ACE_Box_Target_3
	{
		displayName = "Popup 3 Small";
		model = "\x\ace\addons\sys_targets\ace_target_popup_small.p3d";
	};
	class ACE_Tac_Target_1: ACE_TargetBase
	{
		scope = 2;
		displayName = "Tactical 1";
		hiddenSelectionsTextures[] = {"","\x\ace\addons\sys_targets\data\ace_tac_1_ca.paa"};
	};
	class ACE_Tac_Target_2: ACE_Tac_Target_1
	{
		displayName = "Tactical 2";
		hiddenSelectionsTextures[] = {"","\x\ace\addons\sys_targets\data\ace_tac_2_ca.paa"};
	};
	class ACE_Tac_Target_3: ACE_Tac_Target_1
	{
		displayName = "Tactical 3";
		hiddenSelectionsTextures[] = {"","\x\ace\addons\sys_targets\data\ace_tac_3_ca.paa"};
	};
	class ACE_Target_Invisible: TargetBase
	{
		Audible = 10;
		camouflage = 10;
		cost = 100000000;
		destrType = 0;
		icon = "\ca\data\data\Unknown_object";
		mapSize = 0.2;
		model = "\x\ace\addons\sys_targets\ace_target.p3d";
		vehicleClass = "ACE_INVISIBLE_TARGETS";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_Target_EInf: ACE_Target_Invisible
	{
		side = 0;
		scope = 2;
		displayName = "$STR_ACE_INV_TARGET_EINF";
		threat[] = {1,1,1};
	};
	class ACE_Target_WInf: ACE_Target_EInf
	{
		side = 1;
		displayName = "$STR_ACE_INV_TARGET_WINF";
	};
	class ACE_Target_RInf: ACE_Target_EInf
	{
		side = 2;
		displayName = "$STR_ACE_INV_TARGET_RINF";
	};
	class ACE_Target_CInf: ACE_Target_EInf
	{
		side = 3;
		displayName = "$STR_ACE_INV_TARGET_CINF";
	};
	class ACE_Target_ELT: ACE_Target_EInf
	{
		side = 0;
		displayName = "$STR_ACE_INV_TARGET_ELAS";
		lasertarget = 1;
	};
	class ACE_Target_WLT: ACE_Target_ELT
	{
		side = 1;
		displayName = "$STR_ACE_INV_TARGET_WLAS";
	};
	class ACE_Target_RLT: ACE_Target_ELT
	{
		side = 2;
		displayName = "$STR_ACE_INV_TARGET_RLAS";
	};
	class ACE_Target_CLT: ACE_Target_ELT
	{
		side = 3;
		displayName = "$STR_ACE_INV_TARGET_CLAS";
	};
	class ACE_Target_EArm: ACE_Target_EInf
	{
		side = 0;
		displayName = "$STR_ACE_INV_TARGET_EARM";
		armor = 500;
		irTarget = 1;
	};
	class ACE_Target_WArm: ACE_Target_EArm
	{
		side = 1;
		displayName = "$STR_ACE_INV_TARGET_WARM";
	};
	class ACE_Target_RArm: ACE_Target_EArm
	{
		side = 2;
		displayName = "$STR_ACE_INV_TARGET_RARM";
	};
	class ACE_Target_CArm: ACE_Target_EArm
	{
		side = 3;
		displayName = "$STR_ACE_INV_TARGET_CARM";
	};
	class ACE_Target_EHvy: ACE_Target_EInf
	{
		side = 0;
		displayName = "$STR_ACE_INV_TARGET_EARMH";
		threat[] = {1,1,1};
		armor = 1500;
	};
	class ACE_Target_WHvy: ACE_Target_EHvy
	{
		side = 1;
		displayName = "$STR_ACE_INV_TARGET_WARMH";
	};
	class ACE_Target_RHvy: ACE_Target_EHvy
	{
		side = 2;
		displayName = "$STR_ACE_INV_TARGET_RARMH";
	};
	class ACE_Target_CHvy: ACE_Target_EHvy
	{
		side = 3;
		displayName = "$STR_ACE_INV_TARGET_CARMH";
	};
};
//};
