////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:46:06 2013 : Created on Sat Apr 06 11:46:06 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_overheating : config.bin{
class CfgPatches
{
	class ace_sys_overheating
	{
		units[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"ace_main","ace_sys_interaction","ace_c_vehicle","ace_c_weapon"};
		version = "1.14.0.590";
		author[] = {"q1184","rocko"};
		class ACE_Options
		{
			group = "WEP";
			title = " ";
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_overheating
	{
		clientInit = "call ('\x\ace\addons\sys_overheating\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
		Init = "call ('\x\ace\addons\sys_overheating\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Respawn_EventHandlers
{
	class CAManBase
	{
		class ace_sys_overheating
		{
			clientRespawn = "if (player == (_this select 0)) then { _this call ace_sys_overheating_fnc_respawn}";
		};
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class ace_sys_overheating
		{
			clientFiredBisPlayer = "if ((_this select 6) isKindOf 'bulletBase') then {_this call ace_sys_overheating_fnc_fired }";
		};
	};
	class StaticWeapon
	{
		class ace_sys_overheating
		{
			firedBIS = "if (local (gunner (_this select 0)) && {(_this select 6) isKindOf 'bulletBase'}) then {_this call ace_sys_overheating_fnc_fired_static }";
		};
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class ace_sys_overheating
		{
			init = "if (local (_this select 0)) then {if (getNumber(configFile >> 'CfgWeapons' >> currentWeapon (_this select 0) >> 'ace_sys_weapons_type') in [5,6]) then {_this call ace_sys_overheating_fnc_partcheck}}";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class StaticWeapon
	{
		class ace_sys_overheating
		{
			clientGetIn = "_this call ace_sys_overheating_fnc_getIn";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class StaticWeapon
	{
		class ace_sys_overheating
		{
			clientGetOut = "_this call ace_sys_overheating_fnc_getOut";
		};
	};
};
class CfgWeapons
{
	class Riflecore;
	class Rifle: Riflecore
	{
		ace_jam[] = {5,0,0.428};
	};
	class M16_base: Rifle
	{
		ace_jam[] = {41,1,0.81};
	};
	class M4A1: M16_base
	{
		ace_jam[] = {25,1,0.59};
	};
	class Saiga12K: Rifle
	{
		ace_jam[] = {0,0,0.665};
	};
	class M1014: Rifle
	{
		ace_jam[] = {0,0,0.665};
	};
	class GrenadeLauncher_EP1;
	class M79_EP1: GrenadeLauncher_EP1
	{
		ace_jam[] = {0,0,0.665};
	};
	class M249: Rifle
	{
		ace_jam[] = {30,0,0.74};
	};
	class M240: Rifle
	{
		ace_jam[] = {20,0,0.67};
	};
	class PK: Rifle
	{
		ace_jam[] = {20,0,0.67};
	};
	class G36C: Rifle
	{
		ace_jam[] = {5,0,0.36};
	};
	class G36a: Rifle
	{
		ace_jam[] = {5,0,0.77};
	};
	class G36K: G36A
	{
		ace_jam[] = {5,0,0.51};
	};
	class MG36: G36C
	{
		ace_jam[] = {5,0,0.77};
	};
	class AK_74;
	class RPK_74: AK_74
	{
		ace_jam[] = {5,0,0.71};
	};
	class M60A4_EP1: Rifle
	{
		ace_jam[] = {10,0,0.665};
	};
	class BAF_L110A1_Aim: Rifle
	{
		ace_jam[] = {10,0,0.67};
	};
	class m8_base: Rifle
	{
		ace_jam[] = {5,0,0.816};
	};
	class m107: Rifle
	{
		ace_jam[] = {5,1,0.55};
	};
	class M24: Rifle
	{
		ace_jam[] = {0,0,0.428};
	};
	class huntingrifle: M24
	{
		ace_jam[] = {0,0,0.428};
	};
	class MP5SD: Rifle
	{
		ace_jam[] = {20,1,0.271};
	};
	class MP5A5: MP5SD
	{
		ace_jam[] = {20,1,0.418};
	};
	class AK_BASE: Rifle
	{
		ace_jam[] = {20,1,0.498};
	};
	class AKS_BASE: AK_BASE
	{
		ace_jam[] = {20,1,0.498};
	};
	class bizon: Rifle
	{
		ace_jam[] = {20,1,0.423};
	};
	class ksvk: Rifle
	{
		ace_jam[] = {0,0,0.74};
	};
	class VSS_vintorez: Rifle
	{
		ace_jam[] = {10,1,0.37};
	};
	class UK59_ACR: Rifle
	{
		ace_jam[] = {20,0,0.67};
	};
	class CZ805_A1_ACR: Rifle
	{
		ace_jam[] = {5,0,0.51};
	};
	class CZ805_A2_ACR: CZ805_A1_ACR
	{
		ace_jam[] = {5,0,0.36};
	};
	class MGun;
	class MK19: MGun
	{
		ace_jam[] = {40,0,0.49};
	};
	class AGS30: MGun
	{
		ace_jam[] = {30,1,1.36};
	};
	class BAF_static_GMG: MGun
	{
		ace_jam[] = {20,1,1.36};
	};
	class BAF_L7A2: MGun
	{
		ace_jam[] = {20,0,0.67};
	};
	class M2: MGun
	{
		ace_jam[] = {40,1,0.84};
	};
	class DSHKM: MGun
	{
		ace_jam[] = {40,1,1.36};
	};
	class KORD: MGun
	{
		ace_jam[] = {30,1,1.36};
	};
	class M240_veh: MGun
	{
		ace_jam[] = {20,0,0.67};
	};
	class M134: MGun
	{
		ace_jam[] = {0,0,0.67};
	};
	class PKT: MGun
	{
		ace_jam[] = {20,0,0.67};
	};
	class ACE_Item;
	class ACE_SpareBarrel: ACE_Item
	{
		scope = 2;
		displayName = "$STR_ACE_SWAPBARRELBAG";
		picture = "\x\ace\addons\sys_overheating\data\equip\w_ace_sparebarrelbag_ca.paa";
		model = "\x\ace\addons\sys_overheating\ace_sparebarrelbag";
		ACE_Weight = 6;
		ACE_Size = 2000;
	};
};
class CfgMovesBasic
{
	class Default;
	class ManActions;
	class Actions
	{
		class NoActions;
		class RifleBaseLowStandActions;
		class RifleBaseStandActions;
		class RifleLowStandActions: RifleBaseLowStandActions
		{
			putDown = "AmovPercMstpSlowWrflDnon";
			takeFlag = "AmovPercMstpSlowWrflDnon";
			Gear = "AmovPercMstpSlowWrflDnon";
		};
		class RifleStandTakeActions: RifleBaseLowStandActions
		{
			stop = "AmovPercMstpSlowWrflDnon";
			StopRelaxed = "AmovPercMstpSlowWrflDnon";
			default = "AmovPercMstpSlowWrflDnon";
			Gear = "AmovPercMstpSlowWrflDnon";
		};
		class RifleStandActions: RifleBaseStandActions
		{
			putDown = "AmovPercMstpSrasWrflDnon";
			takeFlag = "AmovPercMstpSrasWrflDnon";
			Gear = "AmovPercMstpSlowWrflDnon";
		};
		class RifleKneelActions: RifleBaseStandActions
		{
			putDown = "AmovPknlMstpSrasWrflDnon";
			takeFlag = "AmovPknlMstpSrasWrflDnon";
			Gear = "AmovPknlMstpSrasWrflDnon";
		};
		class RifleKneelTakeActions: RifleKneelActions
		{
			stop = "AmovPknlMstpSrasWrflDnon";
			StopRelaxed = "AmovPknlMstpSrasWrflDnon";
			default = "AmovPknlMstpSrasWrflDnon";
			Gear = "AmovPknlMstpSrasWrflDnon";
		};
	};
};
class CfgSounds
{
	class ace_sys_overheating_unjam
	{
		name = "ace_sys_overheating_unjam";
		sound[] = {"ca\sounds\weapons\rifles\reload-m16-3",0.1,1,20};
		titles[] = {};
	};
};
//};
