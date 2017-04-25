////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:32:25 2012 : Created on Fri Nov 09 22:32:25 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_cartridges : config.bin{
class CfgPatches
{
	class ace_sys_cartridges
	{
		units[] = {"rocko_556","rocko_762","rocko_9","rocko_25x","rocko_127","rocko_145"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main","ace_settings","ace_c_weapon"};
		version = "1.14.0.581";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_cartridges
		{
			list[] = {"ace_sys_cartridges"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_cartridges
	{
		clientInit = "call ('\x\ace\addons\sys_cartridges\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_FiredBIS_EventHandlers
{
	class CAManBase
	{
		class ace_sys_cartridges
		{
			clientFiredBis = "if (ace_sys_cartridges_enabled) then { _this call ace_sys_cartridges_fnc_fired }";
		};
	};
};
class CfgVehicles
{
	class NonStrategic;
	class ThingEffect;
	class FxCartridge_Big: ThingEffect
	{
		model = "\x\ace\addons\sys_cartridges\ShellCasing_Big.p3d";
		displayName = "Brass Big";
		airRotation = "0.2";
		htMin = 30;
		htMax = 60;
		afMax = 400;
		mfMax = 200;
		mFact = 0;
		tBody = 200;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class FxCartridge_Shotgun: FxCartridge_Big
	{
		model = "\x\ace\addons\sys_cartridges\ShellCasing_Shotgun.p3d";
		displayName = "Buckshot";
		airRotation = "0.5";
	};
	class FxCartridge_DrumRevolver: FxCartridge_Big
	{
		model = "\x\ace\addons\sys_cartridges\ShellCasing_Revolver.p3d";
		displayName = "";
		airRotation = "0.5";
	};
	class FxCartridge_556_stay: NonStrategic
	{
		model = "\x\ace\addons\sys_cartridges\rocko_556.p3d";
		icon = "";
		displayName = "";
		nameSound = "";
		destrType = "DestructNo";
		mapSize = 0;
		accuracy = 0;
		armor = 5;
		scope = 1;
		typicalCargo[] = {};
		transportAmmo = 0;
		transportRepair = 0;
		transportFuel = 0;
		htMin = 30;
		htMax = 60;
		afMax = 400;
		mfMax = 200;
		mFact = 0;
		tBody = 200;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class FxCartridge_762_stay: FxCartridge_556_stay
	{
		model = "\x\ace\addons\sys_cartridges\rocko_762.p3d";
	};
	class FxCartridge_9mm_stay: FxCartridge_556_stay
	{
		model = "\x\ace\addons\sys_cartridges\rocko_9.p3d";
	};
	class FxCartridge_Small_stay: FxCartridge_9mm_stay{};
	class FxCartridge_Big_stay: FxCartridge_556_stay
	{
		model = "\x\ace\addons\sys_cartridges\rocko_127.p3d";
	};
	class FxCartridge_127_stay: FxCartridge_Big_stay{};
	class FxCartridge_Shotgun_stay: FxCartridge_556_stay
	{
		model = "\x\ace\addons\sys_cartridges\rocko_sg.p3d";
	};
	class FxCartridge_slug_stay: FxCartridge_Shotgun_stay{};
};
class CfgAmmo
{
	class BulletBase;
	class B_127x99_Ball: BulletBase
	{
		cartridge = "FxCartridge_Big";
	};
	class B_127x107_Ball: BulletBase
	{
		cartridge = "FxCartridge_Big";
	};
	class B_127x108_Ball: BulletBase
	{
		cartridge = "FxCartridge_Big";
	};
	class B_127x108_APHE: BulletBase
	{
		cartridge = "FxCartridge_Big";
	};
	class B_145x115_AP: BulletBase
	{
		cartridge = "FxCartridge_Big";
	};
};
//};
