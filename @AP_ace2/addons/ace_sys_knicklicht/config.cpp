////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:45:41 2013 : Created on Sat Apr 06 11:45:41 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_knicklicht : config.bin{
class CfgPatches
{
	class ace_sys_knicklicht
	{
		units[] = {"ACE_Knicklicht_Object_Base","ACE_Knicklicht_Object_R","ACE_Knicklicht_Object_R_I","ACE_Knicklicht_Object_G","ACE_Knicklicht_Object_G_I","ACE_Knicklicht_Object_W","ACE_Knicklicht_Object_W_I","ACE_Knicklicht_Object_Y","ACE_Knicklicht_Object_Y_I","ACE_Knicklicht_Object_B","ACE_Knicklicht_Object_B_I","ACE_KnicklichtBox"};
		weapons[] = {"ACE_Knicklicht_Proxy"};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","ace_main","ace_sys_interaction"};
		version = "1.14.0.590";
		author[] = {"Rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_knicklicht
		{
			list[] = {"ace_sys_knicklicht"};
		};
	};
};
class CfgAmmo
{
	class GrenadeHand;
	class ACE_Knicklicht_Base: GrenadeHand
	{
		fuseDistance = 0;
		whistleDist = 0;
		whistleOnFire = 0;
		displayName = "$STR_WDN_ACE_KNICKLICHT";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0.1;
		explosiontime = 10;
		typicalSpeed = 25;
		deflecting = 0;
		visibleFire = 0;
		audibleFire = 0;
		visibleFireTime = 0;
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		soundHit[] = {"",15.8489,1};
		ACE_Simulation = "shotKnicklicht";
	};
	class ACE_Knicklicht_R: ACE_Knicklicht_Base
	{
		displayName = "$STR_MDN_ACE_KNICKLICHT_ROT";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		ACE_Knicklicht_Farbe = "R";
	};
	class ACE_Knicklicht_W: ACE_Knicklicht_Base
	{
		displayName = "$STR_MDN_ACE_KNICKLICHT_WEISS";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		ACE_Knicklicht_Farbe = "W";
	};
	class ACE_Knicklicht_G: ACE_Knicklicht_Base
	{
		displayName = "$STR_MDN_ACE_KNICKLICHT_GRUN";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		ACE_Knicklicht_Farbe = "G";
	};
	class ACE_Knicklicht_B: ACE_Knicklicht_Base
	{
		displayName = "$STR_MDN_ACE_KNICKLICHT_BLAU";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		ACE_Knicklicht_Farbe = "B";
	};
	class ACE_Knicklicht_Y: ACE_Knicklicht_Base
	{
		displayName = "$STR_MDN_ACE_KNICKLICHT_GELB";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		ACE_Knicklicht_Farbe = "Y";
	};
	class ACE_Knicklicht_IR: ACE_Knicklicht_Base
	{
		displayName = "STR_MDN_ACE_KNICKLICHT_IR";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		ACE_Knicklicht_Farbe = "IR";
	};
};
class CfgMagazines
{
	class HandGrenade_Stone;
	class ACE_Knicklicht_R: HandGrenade_Stone
	{
		type = 16;
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_magazin.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_ROT";
		displayNameShort = "$STR_ACE_MDNS_RED";
		ammo = "ACE_Knicklicht_R";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_KNICKLICHT_ROT";
		ACE_Weight = 0.01;
		ACE_Size = 10;
	};
	class ACE_Knicklicht_G: ACE_Knicklicht_R
	{
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_GRUN";
		displayNameShort = "$STR_ACE_MDNS_GREEN";
		ammo = "ACE_Knicklicht_G";
		descriptionShort = "$STR_DSS_ACE_KNICKLICHT_GRUN";
	};
	class ACE_Knicklicht_W: ACE_Knicklicht_R
	{
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_WEISS";
		displayNameShort = "$STR_ACE_MDNS_WHITE";
		ammo = "ACE_Knicklicht_W";
		descriptionShort = "$STR_DSS_ACE_KNICKLICHT_WEISS";
	};
	class ACE_Knicklicht_Y: ACE_Knicklicht_R
	{
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_GELB";
		displayNameShort = "$STR_ACE_MDNS_YELLOW";
		ammo = "ACE_Knicklicht_Y";
		descriptionShort = "$STR_DSS_ACE_KNICKLICHT_GELB";
	};
	class ACE_Knicklicht_B: ACE_Knicklicht_R
	{
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_BLAU";
		displayNameShort = "$STR_ACE_MDNS_BLUE";
		ammo = "ACE_Knicklicht_B";
		descriptionShort = "$STR_DSS_ACE_KNICKLICHT_BLAU";
	};
	class ACE_Knicklicht_IR: ACE_Knicklicht_R
	{
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_IR";
		displayNameShort = "IR";
		ammo = "ACE_Knicklicht_IR";
		descriptionShort = "$STR_DSS_ACE_KNICKLICHT_IR";
	};
	class ACE_Knicklicht_R_Used: ACE_Knicklicht_R
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_magazin_leucht_r.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_used_rot_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_ROT_USED";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Knicklicht_G_Used: ACE_Knicklicht_G
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_magazin_leucht_g.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_used_grun_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_GRUN_USED";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Knicklicht_W_Used: ACE_Knicklicht_W
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_magazin_leucht_w.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_used_weiss_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_WEISS_USED";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Knicklicht_Y_Used: ACE_Knicklicht_Y
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_magazin_leucht_y.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_used_gelb_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_GELB_USED";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Knicklicht_B_Used: ACE_Knicklicht_B
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_magazin_leucht_b.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_used_blau_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_BLAU_USED";
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_Knicklicht_IR_Used: ACE_Knicklicht_IR
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_magazin_leucht_ir.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_used_ir_ca.paa";
		displayName = "$STR_MDN_ACE_KNICKLICHT_IR_USED";
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgWeapons
{
	class GrenadeLauncher;
	class Throw: GrenadeLauncher
	{
		class ThrowMuzzle;
		class ACE_KnicklichtMuzzle: ThrowMuzzle
		{
			sound[] = {"\x\ace\addons\sys_knicklicht\sound\knickknack.ogg",1,1};
			displayName = "$STR_WDN_ACE_KNICKLICHT";
			magazines[] = {"ACE_Knicklicht_R","ACE_Knicklicht_W","ACE_Knicklicht_G","ACE_Knicklicht_Y","ACE_Knicklicht_B","ACE_Knicklicht_IR"};
		};
		class ACE_Knicklicht_UsedMuzzle: ACE_KnicklichtMuzzle
		{
			sound[] = {"",1,1};
			displayName = "$STR_WDN_ACE_KNICKLICHT_USED";
			magazines[] = {"ACE_Knicklicht_R_Used","ACE_Knicklicht_W_Used","ACE_Knicklicht_G_Used","ACE_Knicklicht_Y_Used","ACE_Knicklicht_B_Used","ACE_Knicklicht_IR_Used"};
		};
	};
	class M9;
	class ACE_Knicklicht_Proxy: M9
	{
		displayName = "$STR_WDN_ACE_KNICKLICHT";
		scope = 2;
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_proxy.p3d";
		picture = "\x\ace\addons\sys_knicklicht\data\equip\m_knicklicht_used_weiss_ca.paa";
		begin1[] = {"",0,0,0};
		soundBegin[] = {"begin1",1};
		drySound[] = {"",0,0,0};
		reloadMagazineSound[] = {"",0,0,0};
		magazines[] = {};
		class Library
		{
			libTextDesc = "Und es ward hell ... und rocko sah das es gut war. Und er nannte es Licht.";
		};
		descriptionShort = "";
		ACE_isKnicklicht = 1;
		enableAttack = 0;
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgVehicles
{
	class NonStrategic;
	class RoadBarrier_light: NonStrategic
	{
		class ACE;
	};
	class ACE_Knicklicht_Object_Base: RoadBarrier_light
	{
		armor = 1;
		scope = 1;
		mapsize = 0;
		displayName = "$STR_WDN_ACE_KNICKLICHT";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht.p3d";
		hiddenSelections[] = {"color"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_knicklicht\data\weiss_ca.paa"};
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
		class ACE: ACE
		{
			class ACE_KNICKLICHT
			{
				magazine = "";
			};
		};
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_Knicklicht_Object_R: ACE_Knicklicht_Object_Base
	{
		hiddenSelections[] = {"color"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_knicklicht\data\rot_ca.paa"};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "licht";
				color[] = {1,0.1,0.1,1};
				ambient[] = {0.1,0.01,0.01,0.05};
				brightness = 0.0028;
				blinking = "false";
			};
		};
		class ACE: ACE
		{
			class ACE_KNICKLICHT: ACE_KNICKLICHT
			{
				magazine = "ACE_Knicklicht_R_USED";
			};
		};
	};
	class ACE_Knicklicht_Object_R_I: ACE_Knicklicht_Object_R
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_i.p3d";
	};
	class ACE_Knicklicht_Object_G: ACE_Knicklicht_Object_Base
	{
		hiddenSelections[] = {"color"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_knicklicht\data\grun_ca.paa"};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "licht";
				color[] = {0.1,1,0.1,1};
				ambient[] = {0.01,0.1,0.01,0.05};
				brightness = 0.0028;
				blinking = "false";
			};
		};
		class ACE: ACE
		{
			class ACE_KNICKLICHT: ACE_KNICKLICHT
			{
				magazine = "ACE_Knicklicht_G_USED";
			};
		};
	};
	class ACE_Knicklicht_Object_G_I: ACE_Knicklicht_Object_G
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_i.p3d";
	};
	class ACE_Knicklicht_Object_W: ACE_Knicklicht_Object_Base
	{
		hiddenSelections[] = {"color"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_knicklicht\data\weiss_ca.paa"};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "licht";
				color[] = {1,1,1,1};
				ambient[] = {0.1,0.1,0.1,0.05};
				brightness = 0.0028;
				blinking = "false";
			};
		};
		class ACE: ACE
		{
			class ACE_KNICKLICHT: ACE_KNICKLICHT
			{
				magazine = "ACE_Knicklicht_W_USED";
			};
		};
	};
	class ACE_Knicklicht_Object_W_I: ACE_Knicklicht_Object_W
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_i.p3d";
	};
	class ACE_Knicklicht_Object_Y: ACE_Knicklicht_Object_Base
	{
		hiddenSelections[] = {"color"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_knicklicht\data\gelb_ca.paa"};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "licht";
				color[] = {1,1,0,1};
				ambient[] = {0.1,0.1,0.01,0.05};
				brightness = 0.0028;
				blinking = "false";
			};
		};
		class ACE: ACE
		{
			class ACE_KNICKLICHT: ACE_KNICKLICHT
			{
				magazine = "ACE_Knicklicht_Y_USED";
			};
		};
	};
	class ACE_Knicklicht_Object_Y_I: ACE_Knicklicht_Object_Y
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_i.p3d";
	};
	class ACE_Knicklicht_Object_B: ACE_Knicklicht_Object_Base
	{
		hiddenSelections[] = {"color"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_knicklicht\data\blau_ca.paa"};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "licht";
				color[] = {0,0,1,1};
				ambient[] = {0.01,0.01,0.1,0.05};
				brightness = 0.0028;
				blinking = "false";
			};
		};
		class ACE: ACE
		{
			class ACE_KNICKLICHT: ACE_KNICKLICHT
			{
				magazine = "ACE_Knicklicht_B_USED";
			};
		};
	};
	class ACE_Knicklicht_Object_B_I: ACE_Knicklicht_Object_B
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_i.p3d";
	};
	class ACE_Knicklicht_Object_IR: ACE_Knicklicht_Object_Base
	{
		hiddenSelections[] = {"color"};
		hiddenSelectionsTextures[] = {"x\ace\addons\sys_knicklicht\data\ir_ca.paa"};
		class MarkerLights
		{
			class RedBlinking
			{
				name = "licht";
				color[] = {0,0,0,1};
				ambient[] = {0.1,0.1,0.1,1};
				brightness = 0.01;
				blinking = "false";
				onlyInNvg = 1;
			};
		};
		class ACE: ACE
		{
			class ACE_KNICKLICHT: ACE_KNICKLICHT
			{
				magazine = "ACE_Knicklicht_IR_USED";
			};
		};
	};
	class ACE_Knicklicht_Object_IR_I: ACE_Knicklicht_Object_IR
	{
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_i.p3d";
	};
	class USBasicAmmunitionBox_EP1;
	class ACE_KnicklichtBox: USBasicAmmunitionBox_EP1
	{
		displayName = "$STR_ACE_VDN_ACE_KNICKLICHT_BOX";
		model = "\x\ace\addons\sys_knicklicht\rocko_knicklicht_box.p3d";
		vehicleClass = "ACE_Ammunition";
		class TransportWeapons{};
		class TransportMagazines
		{
			class _xx_ACE_Knicklicht_R
			{
				magazine = "ACE_Knicklicht_R";
				count = 20;
			};
			class _xx_ACE_Knicklicht_G
			{
				magazine = "ACE_Knicklicht_G";
				count = 20;
			};
			class _xx_ACE_Knicklicht_W
			{
				magazine = "ACE_Knicklicht_W";
				count = 20;
			};
			class _xx_ACE_Knicklicht_Y
			{
				magazine = "ACE_Knicklicht_Y";
				count = 20;
			};
			class _xx_ACE_Knicklicht_B
			{
				magazine = "ACE_Knicklicht_B";
				count = 20;
			};
			class _xx_ACE_Knicklicht_IR
			{
				magazine = "ACE_Knicklicht_IR";
				count = 20;
			};
		};
	};
};
class CfgSounds
{
	class ACE_knick_knack
	{
		name = "ACE_knick_knack";
		sound[] = {"\x\ace\addons\sys_knicklicht\sound\knickknack.ogg",2,1};
		titles[] = {};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_knicklicht
	{
		init = "call ('\x\ace\addons\sys_knicklicht\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\sys_knicklicht\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_knicklicht
	{
		clientInit = "call ('\x\ace\addons\sys_knicklicht\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Killed_EventHandlers
{
	class CAManBase
	{
		ace_sys_knicklicht = "_this call ace_sys_knicklicht_fnc_killed";
	};
};
//};
