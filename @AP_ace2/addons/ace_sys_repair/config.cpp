////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:07:41 2013 : Created on Mon Oct 14 23:07:41 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_repair : config.bin{
class CfgPatches
{
	class ace_sys_repair
	{
		units[] = {"ACE_repairTest","ACE_JerryCan_15"};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","CAData","CAWeapons","CAWeapons2","CACharacters","CATracked","CAWheeled","CAWheeled3","CAAir","CAAir3","CAA10","ace_sys_interaction","ace_sys_cargo"};
		version = "1.14.0.597";
		author[] = {"Sickboy"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_repair
		{
			list[] = {"ace_sys_repair"};
		};
	};
};
class CfgVehicleClasses
{
	class ace_sys_repair
	{
		displayName = "$STR_ACE_VC_REPAIR";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_repair
	{
		init = "call ('\x\ace\addons\sys_repair\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_repair
	{
		clientInit = "call ('\x\ace\addons\sys_repair\XEH_postInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_InitPost_EventHandlers
{
	class Car
	{
		class ace_sys_repair
		{
			exclude[] = {"ACE_JerryCan","FoldChair_with_Cargo"};
			init = "_this spawn ace_sys_repair_fnc_init";
		};
	};
	class Truck
	{
		class ace_sys_repair
		{
			init = "_this spawn ace_sys_repair_fnc_init";
		};
	};
	class Tank
	{
		class ace_sys_repair
		{
			init = "_this spawn ace_sys_repair_fnc_init";
		};
	};
};
class CfgMagazines
{
	class CA_Magazine;
	class VehicleMagazine: CA_Magazine
	{
		ace_sys_repair_time = 10;
	};
};
class CfgVehicles
{
	class All;
	class AllVehicles: All
	{
		ace_sys_repair_time = 600;
		ace_sys_repair_threshold_refuel = 1;
		ace_sys_repair_threshold = 0.8;
		ace_sys_repair_refuel = 0;
		ace_sys_repair_repair = 0;
		ace_sys_repair_rearm = 0;
		ace_sys_repair_spare_tyres = 0;
	};
	class ACE_Logic;
	class ace_sys_repair_full: ACE_Logic
	{
		displayName = "$STR_ACE_REPAIR_LOGIC_FULL";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then { ace_sys_repair_full = true; publicVariable 'ace_sys_repair_full' }";
		};
	};
	class ace_sys_repair_tyres: ACE_Logic
	{
		displayName = "$STR_ACE_REPAIR_LOGIC_TYRES";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then { ace_sys_repair_default_tyres= true; publicVariable 'ace_sys_repair_default_tyres' }";
		};
	};
	class Ship: AllVehicles{};
	class Land: AllVehicles{};
	class Man: Land{};
	class LandVehicle: Land{};
	class Car: LandVehicle
	{
		ace_sys_repair_spare_tyres = 1;
		ace_sys_repair_tyre_type = "ACE_Spare_Tyre";
		class Turrets
		{
			class MainTurret;
		};
	};
	class HMMWV_Base: Car
	{
		ace_sys_repair_tyre_type = "ACE_Spare_Tyre_HD";
	};
	class Truck: Car
	{
		ace_sys_repair_tyre_type = "ACE_Spare_Tyre_HD";
	};
	class Wheeled_APC: Car
	{
		ace_sys_repair_tyre_type = "ACE_Spare_Tyre_HDAPC";
	};
	class StrykerBase_EP1: Wheeled_APC
	{
		ace_sys_repair_jerrycan_count = 2;
	};
	class Motorcycle: Landvehicle{};
	class Tank: LandVehicle
	{
		ace_sys_repair_time = 900;
	};
	class StaticWeapon: LandVehicle{};
	class StaticCannon;
	class M119: StaticCannon{};
	class D30: StaticWeapon{};
	class Air: AllVehicles
	{
		ace_sys_repair_time = 1200;
	};
	class Helicopter: Air
	{
		ace_sys_repair_time = 900;
	};
	class ParachuteBase: Helicopter{};
	class Plane: Air{};
	class MTVR;
	class MtvrReammo: MTVR
	{
		transportAmmo = 0.1;
		supplyRadius = 0;
	};
	class MtvrRefuel: MTVR
	{
		transportFuel = 0.1;
		supplyRadius = 0;
	};
	class MtvrRepair: MTVR
	{
		transportRepair = 0.1;
		supplyRadius = 0;
	};
	class MtvrRepair_base;
	class MtvrRepair_DES_EP1: MtvrRepair_base
	{
		transportRepair = 0.1;
		supplyRadius = 0;
	};
	class MtvrRefuel_base;
	class MtvrRefuel_DES_EP1: MtvrRefuel_base
	{
		transportFuel = 0.1;
		supplyRadius = 0;
	};
	class MtvrReammo_base;
	class MtvrReammo_DES_EP1: MtvrReammo_base
	{
		transportAmmo = 0.1;
		supplyRadius = 0;
	};
	class Kamaz_Base;
	class KamazReammo: Kamaz_Base
	{
		transportAmmo = 0.1;
		supplyRadius = 0;
	};
	class KamazRepair: Kamaz_Base
	{
		transportRepair = 0.1;
		supplyRadius = 0;
	};
	class KamazRefuel: Kamaz_Base
	{
		transportFuel = 0.1;
		supplyRadius = 0;
	};
	class Ural_Base;
	class UralReammo_Base: Ural_Base
	{
		transportAmmo = 0.1;
		supplyRadius = 0;
	};
	class UralRefuel_Base: Ural_Base
	{
		transportFuel = 0.1;
		supplyRadius = 0;
	};
	class UralRepair_Base: Ural_Base
	{
		transportRepair = 0.1;
		supplyRadius = 0;
	};
	class UralRepair_TK_EP1: UralRepair_Base
	{
		transportRepair = 0.1;
		supplyRadius = 0;
	};
	class UralReammo_TK_EP1: UralReammo_Base
	{
		transportAmmo = 0.1;
		supplyRadius = 0;
	};
	class UralRefuel_TK_EP1: UralRefuel_Base
	{
		transportFuel = 0.1;
		supplyRadius = 0;
	};
	class V3S_Base_EP1;
	class V3S_Reammo_TK_GUE_EP1: V3S_Base_EP1
	{
		transportAmmo = 0.1;
		supplyRadius = 0;
	};
	class V3S_Repair_TK_GUE_EP1: V3S_Base_EP1
	{
		transportRepair = 0.1;
		supplyRadius = 0;
	};
	class V3S_Refuel_TK_GUE_EP1: V3S_Base_EP1
	{
		transportFuel = 0.1;
		supplyRadius = 0;
	};
	class ACE_MTVRRepair_DES_EP1: MTVRRepair_DES_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_repair
			{
				displayName = "$STR_ACE_UA_REPAIR";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_MTVRReammo_DES_EP1: MTVRReammo_DES_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_rearm
			{
				displayName = "$STR_ACE_UA_REARM";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_MTVRRefuel_DES_EP1: MTVRRefuel_DES_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_refuel
			{
				displayName = "$STR_ACE_UA_REFUEL";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_UralRepair_TK_EP1: UralRepair_TK_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_repair
			{
				displayName = "$STR_ACE_UA_REPAIR";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_UralReammo_TK_EP1: UralReammo_TK_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_rearm
			{
				displayName = "$STR_ACE_UA_REARM";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_UralRefuel_TK_EP1: UralRefuel_TK_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_refuel
			{
				displayName = "$STR_ACE_UA_REFUEL";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_V3S_Repair_TK_GUE_EP1: V3S_Repair_TK_GUE_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_repair
			{
				displayName = "$STR_ACE_UA_REPAIR";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_V3S_Reammo_TK_GUE_EP1: V3S_Reammo_TK_GUE_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_rearm
			{
				displayName = "$STR_ACE_UA_REARM";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ACE_V3S_Refuel_TK_GUE_EP1: V3S_Refuel_TK_GUE_EP1
	{
		scope = 1;
		vehicleClass = "ace_sys_repair";
		transportFuel = 0;
		transportAmmo = 0;
		transportRepair = 0;
		class UserActions
		{
			class ace_sys_repair_refuel
			{
				displayName = "$STR_ACE_UA_REFUEL";
				position = "doplnovani";
				radius = 15;
				condition = "alive this";
				onlyForPlayer = 1;
				statement = "";
			};
		};
	};
	class ReammoBox;
	class ACE_Tyre_Object: ReammoBox
	{
		scope = 1;
		vehicleClass = "ACE_Objects";
		model = "\x\ace\addons\sys_repair\ace_spare_tyre.p3d";
		icon = "\Ca\Structures\Misc\Armory\Pneu\Data\icon\pneu_icon_ca.paa";
		accuracy = 0.2;
		mapSize = 0.2;
		class DestructionEffects{};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ACE_Spare_Tyre: ACE_Tyre_Object
	{
		scope = 2;
		displayName = "$STR_DN_ACE_SPARE_TYRE";
		ACE_Weight = 5;
	};
	class ACE_Spare_Tyre_HD: ACE_Spare_Tyre
	{
		model = "\x\ace\addons\sys_repair\ace_spare_tyre_hd.p3d";
		displayName = "Heavy Duty Tire";
		ACE_Weight = 25;
	};
	class ACE_Spare_Tyre_HDAPC: ACE_Spare_Tyre_HD
	{
		model = "\x\ace\addons\sys_repair\ace_spare_tyre_hdapc.p3d";
		displayName = "Heavy Duty Tire (APC)";
		ACE_Weight = 25;
	};
	class ACE_JerryCan: Car
	{
		displayName = "$STR_DN_ACE_JERRYCAN_DUMMY";
		vehicleClass = "ACE_Objects";
		model = "\x\ace\addons\sys_repair\ace_jerrycan.p3d";
		picture = "\x\ace\addons\sys_repair\data\picture\ace_ico_jerrycan_ca.paa";
		icon = "\x\ace\addons\sys_repair\data\icon\ico_ace_jc_ca.paa";
		mapSize = 0.25;
		fuelCapacity = 20;
		hasDriver = 0;
		hasGunner = 0;
		hasCommander = 0;
		audible = 0;
		canfloat = 1;
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "true";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
		ACE_Weight = 20;
		class Turrets{};
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		transportMaxBackpacks = 0;
		class TransportMagazines{};
		class TransportWeapons{};
		class TransportBackpacks{};
		class DestructionEffects
		{
			class Light1
			{
				simulation = "light";
				type = "ObjectDestructionLight";
				position = "destructionEffect1";
				intensity = 0.001;
				interval = 1;
				lifeTime = 3;
			};
			class Smoke1
			{
				simulation = "particles";
				type = "ObjectDestructionSmoke";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3.5;
			};
			class Fire1
			{
				simulation = "particles";
				type = "ObjectDestructionFire1";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3;
			};
			class Sparks1
			{
				simulation = "particles";
				type = "ObjectDestructionSparks";
				position = "destructionEffect1";
				intensity = 0;
				interval = 1;
				lifeTime = 0;
			};
			class Sound
			{
				simulation = "sound";
				position = "destructionEffect1";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
				type = "Fire";
			};
			class Light2
			{
				simulation = "light";
				type = "ObjectDestructionLight";
				position = "destructionEffect2";
				intensity = 0.001;
				interval = 1;
				lifeTime = 3;
			};
			class Fire2
			{
				simulation = "particles";
				type = "ObjectDestructionFire2";
				position = "destructionEffect2";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3;
			};
			class Smoke1_2
			{
				simulation = "particles";
				type = "ObjectDestructionSmoke1_2";
				position = "destructionEffect2";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3.5;
			};
		};
	};
	class ACE_JerryCan_15: ACE_JerryCan
	{
		scope = 2;
	};
	class ACE_JerryCan_5: ACE_JerryCan_15
	{
		displayName = "$STR_ACE_DN_JERRYCAN5";
		fuelCapacity = 5;
		ACE_Weight = 5;
	};
};
class CfgActions
{
	class None;
	class RepairVehicle: None
	{
		show = 0;
		shortcut = "";
	};
};
class ACE_DYNAMIC_RELOAD
{
	idd = 66361;
	name = "ACE_DYNAMIC_RELOAD";
	movingEnable = "false";
	onLoad = "uiNamespace setVariable ['ACE_Dynamic_Reload', _this select 0];call ace_sys_repair_fnc_onload";
	controlsBackground[] = {"ACE_DLOAD_background_veh","ACE_DLOAD_background_ammo"};
	class ACE_DLOAD_background_veh
	{
		idc = -1;
		type = 0;
		style = 48;
		x = 0.1;
		w = 0.9;
		y = 0.1;
		h = "1/2";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "\ca\ui\data\ui_gameoptions_background_ca.paa";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};
	class ACE_DLOAD_background_ammo
	{
		idc = -1;
		type = 0;
		style = 48;
		x = 0.1;
		w = 0.9;
		y = "1/2+0.01";
		h = "1/2";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "\ca\ui\data\ui_gameoptions_background_ca.paa";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};
	objects[] = {};
	controls[] = {"ACE_DLOAD_vehicle_shortcut","ACE_DLOAD_vehicle_list_desc","ACE_DLOAD_turret_list_desc","ACE_DLOAD_weapon_list_desc","ACE_DLOAD_vehicle_list","ACE_DLOAD_turret_list","ACE_DLOAD_weapon_list","ACE_DLOAD_capacity","ACE_DLOAD_default_loadout_desc","ACE_DLOAD_default_loadout","ACE_DLOAD_compatible_magazines_desc","ACE_DLOAD_current_magazines_desc","ACE_DLOAD_ammo_info_desc","ACE_DLOAD_compatible_magazines","ACE_DLOAD_current_magazines","ACE_DLOAD_ammo_info","ACE_DLOAD_restore_btn","ACE_DLOAD_load_btn","ACE_DLOAD_unload_btn","ACE_DLOAD_close_btn"};
	class ACE_DLOAD_text
	{
		idc = -1;
		type = 0;
		style = 0;
		x = 0.0;
		w = 0.3;
		y = 0.0;
		h = 0.03;
		sizeEx = 0.023;
		colorBackground[] = {0.5,0.5,0.5,0};
		colorText[] = {0.85,0.85,0.85,1};
		font = "Zeppelin32";
		text = "";
	};
	class ACE_DLOAD_image
	{
		idc = -1;
		type = 0;
		style = 48;
		x = 0.25;
		w = 0.1;
		y = 0.1;
		h = 0.1;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};
	class ACE_DLOAD_btn
	{
		idc = -1;
		type = 16;
		style = 0;
		text = "";
		action = "";
		x = 0;
		y = 0;
		w = 0.23;
		h = 0.11;
		size = 0.03921;
		sizeEx = 0.03921;
		color[] = {0.543,0.5742,0.4102,1.0};
		color2[] = {0.95,0.95,0.95,1};
		colorBackground[] = {1,1,1,1};
		colorbackground2[] = {1,1,1,0.4};
		colorDisabled[] = {1,1,1,0.25};
		periodFocus = 1.2;
		periodOver = 0.8;
		class HitZone
		{
			left = 0.004;
			top = 0.029;
			right = 0.004;
			bottom = 0.029;
		};
		class ShortcutPos
		{
			left = 0.0145;
			top = 0.026;
			w = 0.0392157;
			h = 0.0522876;
		};
		class TextPos
		{
			left = 0.05;
			top = 0.034;
			right = 0.005;
			bottom = 0.005;
		};
		textureNoShortcut = "";
		animTextureNormal = "\ca\ui\data\ui_button_normal_ca.paa";
		animTextureDisabled = "\ca\ui\data\ui_button_disabled_ca.paa";
		animTextureOver = "\ca\ui\data\ui_button_over_ca.paa";
		animTextureFocused = "\ca\ui\data\ui_button_focus_ca.paa";
		animTexturePressed = "\ca\ui\data\ui_button_down_ca.paa";
		animTextureDefault = "\ca\ui\data\ui_button_default_ca.paa";
		period = 0.4;
		font = "Zeppelin32";
		soundEnter[] = {"\ca\ui\data\sound\mouse2",0.09,1};
		soundPush[] = {"\ca\ui\data\sound\new1",0.09,1};
		soundClick[] = {"\ca\ui\data\sound\mouse3",0.07,1};
		soundEscape[] = {"\ca\ui\data\sound\mouse1",0.09,1};
		class Attributes
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
		class AttributesImage
		{
			font = "Zeppelin32";
			color = "#E5E5E5";
			align = "left";
			shadow = "true";
		};
	};
	class ACE_DLOAD_list
	{
		type = 5;
		style = 0;
		idc = -1;
		text = "";
		w = 0.275;
		h = 0.04;
		x = "0.1 + 0.03 + 0.2*1";
		y = "0.1 + 0.01 + 0.05";
		colorSelect[] = {1,1,1,1};
		colorText[] = {1,1,1,1};
		colorBackground[] = {0.8,0.8,0.8,1};
		colorSelectBackground[] = {0.4,0.43,0.28,0.5};
		colorScrollbar[] = {0.2,0.2,0.2,1};
		arrowEmpty = "\ca\ui\data\ui_arrow_combo_ca.paa";
		arrowFull = "\ca\ui\data\ui_arrow_combo_active_ca.paa";
		wholeHeight = 0.45;
		rowHeight = 0.04;
		color[] = {0.3,0.32,0.21,1};
		colorActive[] = {0,0,0,1};
		colorDisabled[] = {0,0,0,0.3};
		font = "Zeppelin32";
		sizeEx = 0.023;
		soundSelect[] = {"",0.1,1};
		soundExpand[] = {"",0.1,1};
		soundCollapse[] = {"",0.1,1};
		maxHistoryDelay = 1;
		autoScrollSpeed = -1;
		autoScrollDelay = 5;
		autoScrollRewind = 0;
		class ScrollBar
		{
			color[] = {0.3,0.32,0.21,0.6};
			colorActive[] = {0.3,0.32,0.21,1};
			colorDisabled[] = {0.3,0.32,0.21,0.3};
			thumb = "\ca\ui\data\ui_scrollbar_thumb_ca.paa";
			arrowFull = "\ca\ui\data\ui_arrow_top_active_ca.paa";
			arrowEmpty = "\ca\ui\data\ui_arrow_top_ca.paa";
			border = "\ca\ui\data\ui_border_scroll_ca.paa";
		};
	};
	class ACE_DLOAD_pict
	{
		idc = -1;
		type = 0;
		style = 48;
		x = 0.25;
		w = 0.5;
		y = 0.1;
		h = 0.8;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "\ca\ui\data\ui_gameoptions_background_ca.paa";
		font = "Zeppelin32";
		sizeEx = 0.032;
	};
	class ACE_DLOAD_vehicle_list_desc: ACE_DLOAD_text
	{
		x = "0.1 + 0.03 + 0.2";
		w = "0.2 - 0.03";
		y = "0.1 + 0.01";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_VLD";
	};
	class ACE_DLOAD_turret_list_desc: ACE_DLOAD_text
	{
		x = "0.1 + 0.03 + 0.2*2";
		w = "0.2 - 0.03";
		y = "0.1 + 0.01";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_TLD";
	};
	class ACE_DLOAD_weapon_list_desc: ACE_DLOAD_text
	{
		x = "0.1 + 0.03 + 0.2*3";
		w = "0.2 - 0.03";
		y = "0.1 + 0.01";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_WLD";
	};
	class ACE_DLOAD_capacity: ACE_DLOAD_text
	{
		idc = "(66361 + 5)";
		x = "0.1 + 0.03 + 0.2*3";
		w = "0.2 - 0.03";
		y = "1/2 - 0.04";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_CAP";
	};
	class ACE_DLOAD_default_loadout_desc: ACE_DLOAD_text
	{
		x = "0.1 + 0.03";
		w = "0.2 - 0.03";
		y = "1/2 + 0.01*2";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_DEFAULT";
	};
	class ACE_DLOAD_compatible_magazines_desc: ACE_DLOAD_text
	{
		x = "0.1 + 0.03 + 0.2*1";
		w = "0.2 - 0.03";
		y = "1/2 + 0.01*2";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_COMPMAG";
	};
	class ACE_DLOAD_current_magazines_desc: ACE_DLOAD_text
	{
		x = "0.1 + 0.03 + 0.2*2";
		w = "0.2 - 0.03";
		y = "1/2 + 0.01*2";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_CURMAG";
	};
	class ACE_DLOAD_ammo_info_desc: ACE_DLOAD_text
	{
		x = "0.1 + 0.03 + 0.2*3";
		w = "0.2 - 0.03";
		y = "1/2 + 0.01*2";
		h = 0.04;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "$STR_ACE_REP_DL_INFO";
	};
	class ACE_DLOAD_ammo_info: ACE_DLOAD_text
	{
		idc = "(66361 + 9)";
		type = 13;
		size = 0.023;
		x = "0.1 + 0.03 + 0.2*3";
		w = "0.2 - 0.03";
		y = "1/2 + 0.01*2 + 0.05";
		h = "1/2 - 0.06 - (0.1 + 0.01 + 0.05)";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "";
	};
	class ACE_DLOAD_vehicle_shortcut: ACE_DLOAD_image
	{
		idc = "(66361 + 1)";
		x = "0.1 + 0.03";
		w = "0.2 - 0.03";
		y = "0.1 + 0.01 + 0.05";
		h = 0.24;
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		text = "\ca\ui\data\ui_action_getingunner_ca.paa";
	};
	class ACE_DLOAD_vehicle_list: ACE_DLOAD_list
	{
		idc = "(66361 + 2)";
		x = "0.1 + 0.03 + 0.2*1";
		w = "0.2 - 0.01";
		y = "0.1 + 0.01 + 0.05";
		h = "1/2 - 0.06 - (0.1 + 0.01 + 0.05)";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		onLBSelChanged = "[_this] call ace_sys_repair_fnc_fill_turret_list;";
		onLBDblClick = "[_this] call ace_sys_repair_fnc_fill_turret_list;";
	};
	class ACE_DLOAD_turret_list: ACE_DLOAD_list
	{
		idc = "(66361 + 3)";
		x = "0.1 + 0.03 + 0.2*2";
		w = "0.2 - 0.01";
		y = "0.1 + 0.01 + 0.05";
		h = "1/2 - 0.06 - (0.1 + 0.01 + 0.05)";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		onLBSelChanged = "[_this] call ace_sys_repair_fnc_fill_weapon_list;";
		onLBDblClick = "[_this] call ace_sys_repair_fnc_fill_weapon_list;";
	};
	class ACE_DLOAD_weapon_list: ACE_DLOAD_list
	{
		idc = "(66361 + 4)";
		x = "0.1 + 0.03 + 0.2*3";
		w = "0.2 - 0.01";
		y = "0.1 + 0.01 + 0.05";
		h = "1/2 - 0.06 - (0.1 + 0.01 + 0.05)";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		onLBSelChanged = "[_this] call ace_sys_repair_fnc_fill_compatible_magazines_list;[_this] call ace_sys_repair_fnc_fill_current_magazines_list;";
		onLBDblClick = "[_this] call ace_sys_repair_fnc_fill_compatible_magazines_list;[_this] call ace_sys_repair_fnc_fill_current_magazines_list;";
	};
	class ACE_DLOAD_default_loadout: ACE_DLOAD_list
	{
		idc = "(66361 + 6)";
		x = "0.1 + 0.03";
		w = "0.2 - 0.01";
		y = "1/2 + 0.01*2 + 0.05";
		h = "1/2 - 0.06 - (0.1 + 0.01 + 0.05)";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		onLBSelChanged = "[_this] call ace_sys_repair_fnc_ammo_info;";
	};
	class ACE_DLOAD_compatible_magazines: ACE_DLOAD_list
	{
		idc = "(66361 + 7)";
		x = "0.1 + 0.03 + 0.2*1";
		w = "0.2 - 0.01";
		y = "1/2 + 0.01*2 + 0.05";
		h = "1/2 - 0.06 - (0.1 + 0.01 + 0.05)";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		onLBSelChanged = "[_this] call ace_sys_repair_fnc_ammo_info;";
	};
	class ACE_DLOAD_current_magazines: ACE_DLOAD_list
	{
		idc = "(66361 + 8)";
		x = "0.1 + 0.03 + 0.2*2";
		w = "0.2 - 0.01";
		y = "1/2 + 0.01*2 + 0.05";
		h = "1/2 - 0.06 - (0.1 + 0.01 + 0.05)";
		colorText[] = {1,1,1,1};
		colorBackground[] = {0,0,0,0};
		onLBSelChanged = "[_this] call ace_sys_repair_fnc_ammo_info;";
	};
	class ACE_DLOAD_restore_btn: ACE_DLOAD_btn
	{
		idc = "(66361 + 10)";
		x = "0.1 + 0.03";
		w = 0.16;
		y = "1 - 0.16";
		text = "$STR_ACE_REP_DL_BTNR";
		action = "call ace_sys_repair_fnc_restore_loadout;";
	};
	class ACE_DLOAD_load_btn: ACE_DLOAD_btn
	{
		idc = "(66361 + 11)";
		x = "0.1 + 0.03 + 0.2*1";
		w = 0.16;
		y = "1 - 0.16";
		text = "$STR_ACE_REP_DL_BTNL";
		action = "call ace_sys_repair_fnc_add_magazine;";
	};
	class ACE_DLOAD_unload_btn: ACE_DLOAD_btn
	{
		idc = "(66361 + 12)";
		x = "0.1 + 0.03 + 0.2*2";
		w = 0.16;
		y = "1 - 0.16";
		text = "$STR_ACE_REP_DL_BTNU";
		action = "call ace_sys_repair_fnc_remove_magazine";
	};
	class ACE_DLOAD_close_btn: ACE_DLOAD_btn
	{
		x = "0.1 + 0.03 + 0.2*3";
		w = 0.16;
		y = "1 - 0.16";
		text = "$STR_ACE_REP_DL_BTNC";
		action = "closeDialog 0;";
	};
};
//};
