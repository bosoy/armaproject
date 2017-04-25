class CfgPatches
{
	class ace_sys_wounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAMisc3","CAWheeled","CATracked","CATracked2","CAWheeled2","CAWheeled3","CATracked_E","CAWheeled_E","CAWheeled2_HMMWV_Ambulance","CATracked_E_M113","CAMisc_E","Warfare2","WarfareBuildings","Warfare2_E","ace_main","ace_sys_interaction","ace_c_vehicle","ace_sys_ruck"};
		version = "1.14.0.597";
		author[] = {"Xeno","Sickboy","rocko"};
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_wounds
		{
			list[] = {"ace_sys_wounds"};
		};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_wounds
	{
		init = "call ('\x\ace\addons\sys_wounds\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientinit = "call ('\x\ace\addons\sys_wounds\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_PostInit_EventHandlers
{
	class ace_sys_wounds
	{
		clientInit = "call ('\x\ace\addons\sys_wounds\XEH_postClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class Extended_Init_EventHandlers
{
	class ACE_Stretcher
	{
		class ace_sys_wounds
		{
			serverInit = "_this call ace_sys_wounds_fnc_stretchers";
			clientInit = "_this call ace_sys_wounds_fnc_stretcher";
		};
	};
};
class Extended_GetIn_EventHandlers
{
	class ACE_Stretcher
	{
		class ace_sys_wounds
		{
			GetIn = "_this spawn ace_sys_wounds_fnc_stretcher_fix";
		};
	};
};
class Extended_GetOut_EventHandlers
{
	class Tank
	{
		class ace_sys_wounds
		{
			getout = "_this call ace_sys_wounds_fnc_getout";
		};
	};
	class Wheeled_APC
	{
		class ace_sys_wounds
		{
			getout = "_this call ace_sys_wounds_fnc_getout";
		};
	};
};
class Extended_Respawn_EventHandlers
{
	class CAManBase
	{
		class ace_sys_wounds
		{
			respawn = "_this call ace_sys_wounds_fnc_onRespawn";
		};
	};
};
class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class ace_sys_wounds
		{
			init = "_this call ace_sys_wounds_fnc_addEH";
		};
	};
	class MASH
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class BMP2_Ambul_CDF
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class BMP2_Ambul_INS
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class GAZ_Vodnik_MedEvac
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class HMMWV_Ambulance
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class HMMWV_Ambulance_base
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class M113Ambul_Base
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class S1203_ambulance_EP1
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class Mi17_medevac_RU
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class Mi17_medevac_CDF
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class Mi17_medevac_Ins
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
	class MH60S
	{
		class ace_sys_wounds
		{
			serverinit = "_this execFSM 'x\ace\addons\sys_wounds\aivec.fsm'";
		};
	};
};
class cfgAmmo
{
	class Default;
	class BulletCore;
	class BulletBase: BulletCore
	{
		ace_mass = 0.4;
		ace_caliber = 6;
		ace_penetrationMultiplier = 1.2;
	};
	class B_9x18_Ball: BulletBase
	{
		ace_mass = 0.61;
		ace_caliber = 9;
		ace_penetrationMultiplier = 0.75;
	};
	class B_9x19_Ball: B_9x18_Ball
	{
		ace_mass = 0.8;
	};
	class B_9x19_SD: B_9x19_Ball
	{
		ace_mass = 0.95;
	};
	class B_45ACP_Ball: BulletBase
	{
		ace_mass = 1.49;
		ace_caliber = 11.43;
		ace_penetrationMultiplier = 0.75;
	};
	class B_765x17_Ball: BulletBase
	{
		ace_mass = 0.46;
		ace_caliber = 7.8;
		ace_penetrationMultiplier = 0.75;
	};
	class ACE_Bullet_762x25_B: B_9x19_Ball
	{
		ace_mass = 0.55;
		ace_caliber = 7.8;
		ace_penetrationMultiplier = 0.75;
	};
	class B_545x39_Ball: BulletBase
	{
		ace_mass = 0.343;
		ace_caliber = 5.45;
	};
	class ACE_B_545x39_T: B_545x39_Ball
	{
		ace_mass = 0.324;
	};
	class B_545x39_SD: BulletBase
	{
		ace_mass = 0.52;
		ace_caliber = 5.45;
	};
	class ACE_B_545x39_EP: B_545x39_Ball
	{
		ace_mass = 0.362;
	};
	class ACE_B_545x39_AP: B_545x39_Ball
	{
		ace_mass = 0.368;
	};
	class B_556x45_Ball: BulletBase
	{
		ace_mass = 0.402;
		ace_caliber = 5.56;
		ace_penetrationMultiplier = 1.1;
	};
	class ACE_B_556x45_T: B_556x45_Ball
	{
		ace_mass = 0.4;
		ace_penetrationMultiplier = 1;
	};
	class ACE_B_556x45_SB: B_556x45_Ball
	{
		ace_mass = 0.499;
		ace_penetrationMultiplier = 1;
	};
	class B_556x45_SD: BulletBase
	{
		ace_mass = 0.57;
		ace_caliber = 5.56;
		ace_penetrationMultiplier = 1;
	};
	class ACE_B_556x45_EP: B_556x45_Ball
	{
		ace_mass = 0.402;
		ace_penetrationMultiplier = 1.3;
	};
	class ACE_B_556x45_AP: B_556x45_Ball
	{
		ace_mass = 0.37;
		ace_penetrationMultiplier = 1.4;
	};
	class ACE_B_556x45_DM31: ACE_B_556x45_AP
	{
		ace_mass = 0.4;
		ace_penetrationMultiplier = 1.4;
	};
	class B_9x39_SP5: BulletBase
	{
		ace_mass = 1.68;
		ace_caliber = 9;
		ace_penetrationMultiplier = "(1+ 1.2)/2";
	};
	class ACE_B_9x39_SP6: B_9x39_SP5
	{
		ace_mass = 1.6;
		ace_penetrationMultiplier = 1.2;
	};
	class B_762x39_Ball: BulletBase
	{
		ace_mass = 0.79;
		ace_caliber = 7.62;
	};
	class ACE_B_762x39_T: B_762x39_Ball
	{
		ace_mass = 0.79;
	};
	class ACE_B_762x39_SD: B_762x39_Ball
	{
		ace_mass = 1.255;
	};
	class B_762x51_Ball: BulletBase
	{
		ace_mass = 0.972;
		ace_caliber = 7.62;
		ace_penetrationMultiplier = 1;
	};
	class ACE_B_762x51_T: B_762x51_Ball
	{
		ace_mass = 0.972;
	};
	class B_762x51_noTracer: B_762x51_Ball
	{
		ace_mass = 1.134;
	};
	class B_762x54_Ball: BulletBase
	{
		ace_mass = 0.96;
		ace_caliber = 7.62;
		ace_penetrationMultiplier = 1;
	};
	class ACE_B_762x54_T: B_762x54_Ball
	{
		ace_mass = 0.96;
	};
	class B_762x54_noTracer: B_762x54_Ball
	{
		ace_mass = 0.96;
	};
	class B_77x56_Ball: BulletBase
	{
		ace_mass = 0.96;
		ace_caliber = 7.7;
		ace_penetrationMultiplier = 1;
	};
	class B_303_Ball: BulletBase
	{
		ace_mass = 0.96;
		ace_caliber = 7.7;
		ace_penetrationMultiplier = 1;
	};
	class B_86x70_Ball_noTracer: BulletBase
	{
		ace_mass = 0.9;
		ace_caliber = 7.62;
	};
	class ACE_B_86x70_SB: B_762x51_noTracer
	{
		ace_mass = 0.9;
		ace_caliber = 7.62;
	};
	class ACE_B_46x30_B: B_9x19_Ball
	{
		ace_mass = 0.2;
		ace_caliber = 4.6;
		ace_penetrationMultiplier = 1.2;
	};
	class ACE_B_46x30_SD: ACE_B_46x30_B
	{
		ace_mass = 0.421;
		ace_penetrationMultiplier = 1;
	};
	class ACE_B_57x28_B: B_9x19_Ball
	{
		ace_mass = 0.2;
		ace_caliber = 5.7;
		ace_penetrationMultiplier = 1.2;
	};
	class ACE_B_6x35_B: B_556x45_Ball
	{
		ace_mass = 0.42;
		ace_caliber = 6;
	};
	class Ace_ATDebris: BulletBase
	{
		ace_w_explosive = 1;
		ace_penetrationMultiplier = 0.1;
	};
	class B_12Gauge_74Slug: BulletBase
	{
		ace_mass = 2.8;
		ace_caliber = 18.5;
		ace_penetrationMultiplier = 0.75;
	};
	class B_12Gauge_Pellets: BulletBase
	{
		ace_mass = 0.349;
		ace_caliber = 9.24;
		ace_penetrationMultiplier = 0.75;
	};
	class ACE_Slug_12_1: BulletBase
	{
		ace_mass = 2.8;
		ace_caliber = 18.5;
		ace_penetrationMultiplier = 0.75;
	};
	class ACE_Pellet_Buck_00: BulletBase
	{
		ace_mass = 0.349;
		ace_caliber = 9.24;
		ace_penetrationMultiplier = 0.75;
	};
	class B_127x99_Ball: BulletBase
	{
		ace_mass = 4.034;
		ace_caliber = 12.7;
	};
	class ACE_B_127x99_T: B_127x99_Ball
	{
		ace_mass = 4.0;
		ace_caliber = 12.7;
	};
	class B_127x99_Ball_noTracer: B_127x99_Ball
	{
		ace_mass = 4.348;
	};
	class B_127x107_Ball: BulletBase
	{
		ace_mass = 4.82;
		ace_caliber = 12.7;
	};
	class ACE_B_127x108_T: B_127x107_Ball
	{
		ace_mass = 4.5;
	};
	class B_127x108_Ball: BulletBase
	{
		ace_mass = 4.82;
		ace_caliber = 12.7;
	};
	class B_127x108_APHE: BulletBase
	{
		ace_mass = 4.82;
		ace_caliber = 12.7;
	};
	class B_145x115_AP: BulletBase
	{
		ace_mass = 6.3;
		ace_caliber = 14.5;
	};
	class B_20mm_AA: BulletBase
	{
		ace_mass = 10;
		ace_caliber = 20;
	};
	class B_20mm_AP: BulletBase
	{
		ace_mass = 10;
		ace_caliber = 20;
	};
	class B_23mm_AA: BulletBase
	{
		ace_mass = 15;
		ace_caliber = 23;
	};
	class B_23mm_APHE: BulletBase
	{
		ace_mass = 15;
		ace_caliber = 23;
	};
	class B_25mm_HE: BulletBase
	{
		ace_mass = 18.5;
		ace_caliber = 25;
	};
	class B_25mm_APDS: BulletBase
	{
		ace_mass = 9.8;
		ace_caliber = 25;
	};
	class B_30mmA10_AP: BulletBase
	{
		ace_mass = 30;
		ace_caliber = 30;
	};
	class B_30mm_AP: BulletBase
	{
		ace_mass = 40;
		ace_caliber = 30;
	};
	class B_30mm_HE: BulletBase
	{
		ace_mass = 39;
		ace_caliber = 30;
	};
	class B_30mm_AA: BulletBase
	{
		ace_mass = 30;
		ace_caliber = 30;
	};
	class Sh_40_HE: BulletBase
	{
		ace_mass = 50;
		ace_caliber = 40;
	};
	class Sh_40_SABOT: Sh_40_HE
	{
		ace_mass = 35;
	};
	class GrenadeCore;
	class GrenadeBase: GrenadeCore
	{
		ace_mass = 2;
		ace_caliber = 30;
		ace_frag_vel = 110;
		ace_penetrationMultiplier = 1;
	};
	class Grenade: Default
	{
		ace_mass = 2;
		ace_caliber = 30;
		ace_frag_vel = 110;
		ace_penetrationMultiplier = 1;
	};
	class GrenadeHand;
	class GrenadeHand_stone: GrenadeHand
	{
		ace_mass = 3;
		ace_caliber = 60;
		ace_penetrationmultiplier = 0.2;
	};
	class TimeBombCore;
	class TimeBomb: TimeBombCore
	{
		ace_mass = 8;
		ace_caliber = 100;
		ace_frag_vel = 130;
		ace_penetrationMultiplier = 1;
	};
	class BombCore: Default
	{
		ace_mass = 50;
		ace_caliber = 100;
		ace_frag_vel = 300;
		ace_penetrationMultiplier = 1;
	};
	class RocketCore;
	class RocketBase: RocketCore
	{
		ace_mass = 8;
		ace_caliber = 70;
		ace_frag_vel = 80;
		ace_penetrationMultiplier = 1;
	};
	class R_SMAW_HEDP: RocketBase
	{
		ace_frag_vel = 160;
	};
	class R_SMAW_HEAA: R_SMAW_HEDP
	{
		ace_frag_vel = 60;
	};
	class MissileCore;
	class MissileBase: MissileCore
	{
		ace_mass = 8;
		ace_frag_vel = 130;
		ace_penetrationMultiplier = 1;
	};
	class ShellCore;
	class ShellBase: ShellCore
	{
		ace_mass = 10;
		ace_caliber = 100;
		ace_penetrationMultiplier = 1.2;
	};
};
class CfgMagazines
{
	class Default;
	class CA_Magazine: Default
	{
		class ACE;
	};
	class ACE_Bandage: CA_Magazine
	{
		ACE_Weight = 0.1;
		ACE_Size = 100;
		scope = 2;
		value = 1;
		type = 16;
		ammo = "ACE_DummyAmmo";
		displayName = "$STR_ACE_ITEM_BANDAGE";
		picture = "\x\ace\addons\sys_wounds\data\equip\m_bandage_ca.paa";
		useActionTitle = "Apply Bandage";
		model = "\x\ace\addons\sys_wounds\ace_bandage.p3d";
		count = 1;
		initSpeed = 100;
		reloadAction = "";
		class ACE: ACE
		{
			class ACE_WOUNDS
			{
				useTime = 1;
				bloodRemove = 0.15;
				bloodStop = 15;
				painStop = 0;
				usedMagazine = "ACE_WoundingLitter_Bandage";
			};
		};
	};
	class ACE_LargeBandage: ACE_Bandage
	{
		ACE_Weight = 0.128;
		ACE_Size = 387;
		displayName = "$STR_ACE_ITEM_LARGEBANDAGE";
		model = "\x\ace\addons\sys_wounds\ace_traumabandage.p3d";
		picture = "\x\ace\addons\sys_wounds\data\equip\m_traumabandage_ca.paa";
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				bloodRemove = 0.35;
				bloodStop = 50;
				usedMagazine = "ACE_WoundingLitter_Traumabandage";
			};
		};
	};
	class ACE_Tourniquet: ACE_LargeBandage
	{
		displayName = "$STR_ACE_ITEM_TOURNIQUET";
		picture = "\x\ace\addons\sys_wounds\data\equip\m_cat_ca.paa";
		ACE_Weight = 0.059;
		ACE_Size = 245.8;
		class Armory
		{
			disabled = 1;
		};
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				bloodRemove = 0;
				bloodStop = 80;
				usedMagazine = "ACE_ACE_WoundingLitterTourniquet";
			};
		};
	};
	class ACE_Morphine: ACE_Bandage
	{
		displayName = "$STR_ACE_ITEM_MORPHINE";
		picture = "\x\ace\addons\sys_wounds\data\equip\m_morphine_ca.paa";
		model = "\x\ace\addons\sys_wounds\ace_morphine.p3d";
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				useTime = 1;
				bloodStop = 0;
				painStop = 0.7;
				usedMagazine = "ACE_WoundingLitter_Morphine";
			};
		};
	};
	class ACE_Epinephrine: ACE_Morphine
	{
		displayName = "$STR_ACE_ITEM_EPINEPHRINE";
		picture = "\x\ace\addons\sys_wounds\data\equip\m_epi_ca.paa";
		model = "\x\ace\addons\sys_wounds\ace_epi.p3d";
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				bloodStop = 0;
				painStop = 0.1;
				usedMagazine = "ACE_WoundingLitter_Epinephrine";
			};
		};
	};
	class ACE_Splint: ACE_Bandage
	{
		ACE_Weight = 1;
		displayName = "$STR_ACE_ITEM_SPLINT";
		type = "3*256";
		class Armory
		{
			disabled = 1;
		};
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				useTime = 60;
				bloodStop = 0;
				painStop = 0;
				usedMagazine = "";
			};
		};
	};
	class ACE_IV: ACE_Bandage
	{
		ACE_Weight = 3;
		displayName = "$STR_ACE_ITEM_IV";
		type = "2*256";
		class Armory
		{
			disabled = 1;
		};
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				useTime = 15;
				bloodStop = 0;
				painStop = 0;
				usedMagazine = "";
			};
		};
	};
	class ACE_Plasma: ACE_IV
	{
		displayName = "$STR_ACE_ITEM_PLASMA";
		class Armory
		{
			disabled = 1;
		};
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				useTime = 15;
				bloodStop = 0;
				painStop = 0;
				usedMagazine = "";
			};
		};
	};
	class ACE_Medkit: ACE_LargeBandage
	{
		ACE_Weight = 0.8;
		displayName = "Medkit";
		picture = "\x\ace\addons\sys_wounds\data\equip\m_medkit_ca.paa";
		model = "\x\ace\addons\sys_wounds\ace_medkit.p3d";
		class Armory
		{
			disabled = 0;
		};
		class ACE: ACE
		{
			class ACE_WOUNDS: ACE_WOUNDS
			{
				useTime = 15;
				bloodStop = 0;
				painStop = 0.8;
				usedMagazine = "ACE_ACE_WoundingLitterMedkit";
			};
		};
	};
	class ACE_Bodybag: CA_Magazine
	{
		ACE_Weight = 4;
		ACE_Size = 20;
		scope = 2;
		value = 1;
		type = 16;
		ammo = "ACE_DummyAmmo";
		displayName = "$STR_ACE_ITEM_BODYBAG";
		picture = "\x\ace\addons\sys_wounds\data\equip\m_bodybag_ca.paa";
		count = 1;
		initSpeed = 100;
		reloadAction = "";
	};
};
class CfgWeapons
{
	class Default;
	class Put: Default
	{
		class ACE_Dummy_Utility;
		class ace_sys_wounds: ACE_Dummy_Utility
		{
			class Armory
			{
				disabled = 1;
			};
			magazines[] = {"ACE_Bandage","ACE_Medkit","ACE_Morphine","ACE_Bodybag","ACE_Epinephrine","ACE_LargeBandage","ACE_Tourniquet","ACE_Splint","ACE_IV","ACE_Plasma"};
		};
	};
	class Launcher;
	class ACE_Stretcher: Launcher
	{
		ACE_Size = 20001;
		ACE_Weight = 5;
		ACE_NoPack = 1;
		scope = 2;
		displayName = "$STR_DN_ACE_STRETCHER";
		nameSound = "weapon";
		picture = "\x\ace\addons\sys_wounds\data\equip\w_ace_stretcher_ca.paa";
		simulation = "ProxyWeapon";
		modelOptics = "";
		model = "\x\ace\addons\sys_wounds\ace_stretcher_fold.p3d";
		autoReload = 1;
		backgroundReload = 0;
		magazineReloadTime = 0;
		reloadSound[] = {1,1};
		reloadMagazineSound[] = {1,1};
		reloadTime = 0;
		canLock = 0;
		enableAttack = 0;
		valueWeapon = 20;
		optics = 0;
		uiPicture = "";
		ffMagnitude = 0;
		ffFrequency = 0;
		ffCount = 0;
		primary = 1;
		showEmpty = 0;
		dispersion = 0.0009;
		minRange = 0.1;
		minRangeProbab = 0.1;
		midRange = 1;
		midRangeProbab = 0.1;
		maxRange = 2;
		maxRangeProbab = 0.1;
		magazines[] = {};
		class Library
		{
			libTextDesc = "";
		};
	};
};
class CfgVehicleClasses
{
	class ACE_VC_CIV_OBJECTS
	{
		displayName = "ACE - Objects";
	};
	class ACE_VC_LOGIC
	{
		displayName = "ACE - Logic";
	};
};
class CfgVehicles
{
	class ACE_Logic;
	class ACE_Wounds_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_WOUNDS_ENABLE";
		icon = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_ca.paa";
		picture = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_wounds_enabled = true;publicVariable 'ace_sys_wounds_enabled'};";
		};
	};
	class ACE_Wounds_MedicsOnly_Logic: ACE_Logic
	{
		displayName = "$STR_ACE_WOUNDS_MEDICS_ONLY";
		icon = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_mo_ca.paa";
		picture = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_mo_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_wounds_medics_only = true;publicVariable 'ace_sys_wounds_medics_only'};";
		};
	};
	class ACE_Wounds_EveryoneMedic: ACE_Logic
	{
		displayName = "$STR_ACE_WOUNDS_ALL_MEDICS";
		icon = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_ca.paa";
		picture = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_wounds_all_medics = true;publicVariable 'ace_sys_wounds_all_medics'};";
		};
	};
	class ACE_Wounds_FullHeal: ACE_Logic
	{
		displayName = "$STR_ACE_WOUNDS_FULL_HEAL";
		icon = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_ca.paa";
		picture = "\x\ace\addons\sys_wounds\data\icon\icon_sys_wounds_ca.paa";
		vehicleClass = "Modules";
		class Eventhandlers
		{
			init = "if (isServer) then {ace_sys_wounds_leftdam = 0;publicVariable 'ace_sys_wounds_leftdam'};";
		};
	};
	class Bicycle;
	class ACE_Stretcher: Bicycle
	{
		scope = 1;
		displayName = "$STR_DN_ACE_STRETCHER";
		displayNameShort = "$STR_DN_ACE_STRETCHER";
		model = "\x\ace\addons\sys_wounds\ace_stretcher.p3d";
		vehicleClass = "Car";
		armor = 5;
		weapons[] = {};
		magazines[] = {};
		wheelCircumference = 1;
		rarityUrban = -1;
		class DestructionEffects{};
		class Library
		{
			libTextDesc = "";
		};
		picture = "\x\ace\addons\sys_wounds\data\picture\picture_ace_stretcher_ca.paa";
		Icon = "";
		mapSize = 1;
		maxSpeed = 0;
		ejectDeadCargo = 0;
		extCameraPosition[] = {0,0,-3};
		class HitPoints
		{
			class HitRGlass
			{
				armor = 0.3;
				material = -1;
				name = "sklo predni P";
				passThrough = 0;
			};
			class HitLGlass
			{
				armor = 0.3;
				material = -1;
				name = "sklo predni L";
				passThrough = 0;
			};
			class HitBody
			{
				armor = 1;
				material = 51;
				name = "karoserie";
				visual = "";
				passThrough = 1;
			};
			class HitFuel
			{
				armor = 0.3;
				material = 51;
				name = "palivo";
				passThrough = 0;
			};
			class HitFWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_1_damper";
				visual = "wheel_1";
				passThrough = 0;
			};
			class HitBWheel
			{
				armor = 1;
				material = -1;
				name = "wheel_2_damper";
				visual = "wheel_2";
				passThrough = 0;
			};
			class HitEngine
			{
				armor = 0.4;
				material = -1;
				name = "motor";
				visual = "";
				passThrough = 0;
			};
		};
		threat[] = {0,0,0};
		secondaryExplosion = 0;
		leftDustEffect = "NoDust";
		rightDustEffect = "NoDust";
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		class Reflectors{};
		driverAction = "MMT_Driver";
		driverInAction = "MMT_Driver";
		transportSoldier = 1;
		typicalCargo[] = {"USMC_Soldier"};
		cargoAction[] = {"BMP2_Cargo04"};
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		cargoGetInAction[] = {"GetInLow"};
		cargoGetOutAction[] = {"GetOutLow"};
		animated = 1;
		hadsDriver = 0;
		driverCompartments = 0;
		cargoCompartments[] = {1};
		memoryPointsGetInDriver = "pos driver1";
		memoryPointsGetInDriverDir = "pos driver1 dir";
		memoryPointsGetInCargo = "pos cargo";
		memoryPointsGetInCargoDir = "pos cargo dir";
		class AnimationSources
		{
			class user1
			{
				source = "user";
				animPeriod = "0.05";
				initPhase = "0";
			};
			class user2: user1{};
		};
		ACE_canBeLoad = "true";
		ACE_canBeCargo = "false";
	};
	class ACE_Headbug_Fix: Bicycle
	{
		scope = 1;
		side = 3;
		model = "\x\ace\addons\sys_wounds\ACE_HeadBanger.p3d";
		displayName = " ";
		soundEngine[] = {"",20,0.875};
		soundEnviron[] = {"",25,0.925};
		isBicycle = 1;
		class EventHandlers{};
		SLX_XEH_DISABLED = 1;
	};
	class ReammoBox;
	class ACE_BandageBox: ReammoBox
	{
		displayName = "$STR_DN_ACE_BANDAGEBOX";
		vehicleClass = "ACE_Ammunition";
		class TransportMagazines
		{
			class _xx_ACE_Bandage
			{
				magazine = "ACE_Bandage";
				count = 30;
			};
			class _xx_ACE_LargeBandage
			{
				magazine = "ACE_LargeBandage";
				count = 15;
			};
			class _xx_ACE_Tourniquet
			{
				magazine = "ACE_Tourniquet";
				count = 30;
			};
			class _xx_ACE_Morphine
			{
				magazine = "ACE_Morphine";
				count = 30;
			};
			class _xx_ACE_Epinephrine
			{
				magazine = "ACE_Epinephrine";
				count = 30;
			};
			class _xx_ACE_Medkit
			{
				magazine = "ACE_Medkit";
				count = 15;
			};
		};
		ACE_Weight = 5;
	};
	class ACE_BandageBoxWest: ACE_BandageBox
	{
		scope = 2;
		accuracy = 1000;
		displayName = "$STR_DN_ACE_BANDAGEBOX";
		model = "\x\ace\addons\sys_wounds\ace_medcrate.p3d";
	};
	class ACE_BandageBoxEast: ACE_BandageBoxWest
	{
		scope = 1;
		displayName = "$STR_DN_ACE_BANDAGEBOX";
		model = "\x\ace\addons\sys_wounds\ace_medcrate_r.p3d";
	};
	class Thing;
	class ACE_WoundingLitterBase: Thing
	{
		scope = 1;
		displayName = " ";
		destrType = "DestructNo";
		model = "\x\ace\addons\sys_wounds\ace_traumabandage_used.p3d";
		ACE_canBeLoad = "false";
		ACE_canBeCargo = "false";
		ACE_canGear = "false";
		ACE_canLoadFront = "false";
	};
	class ACE_WoundingLitter_Traumabandage: ACE_WoundingLitterBase
	{
		model = "\x\ace\addons\sys_wounds\ace_traumabandage_used.p3d";
	};
	class ACE_WoundingLitter_Bandage: ACE_WoundingLitter_Traumabandage{};
	class ACE_WoundingLitter_Morphine: ACE_WoundingLitterBase
	{
		model = "\x\ace\addons\sys_wounds\ace_morphine_used.p3d";
	};
	class ACE_WoundingLitter_Epinephrine: ACE_WoundingLitterBase
	{
		model = "\x\ace\addons\sys_wounds\ace_epi_used.p3d";
	};
	class ACE_ACE_WoundingLitterMedkit: ACE_WoundingLitterBase
	{
		model = "\x\ace\addons\sys_wounds\ace_medkit_used.p3d";
	};
	class ACE_ACE_WoundingLitterTourniquet: ACE_WoundingLitterBase
	{
		model = "\x\ace\addons\sys_wounds\ace_littergeneric_bandages3.p3d";
	};
	class BMP2_Base;
	class BMP2_Ambul_Base: BMP2_Base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.25;
	};
	class Mi17_base;
	class Mi17_medevac_base: Mi17_base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.25;
	};
	class Camp_base;
	class MASH: Camp_base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0;
	};
	class HMMWV_Base;
	class HMMWV_Ambulance: HMMWV_Base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.5;
	};
	class HMMWV_Ambulance_base;
	class HMMWV_Ambulance_DES_EP1: HMMWV_Ambulance_base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.5;
	};
	class HMMWV_Ambulance_CZ_DES_EP1: HMMWV_Ambulance_base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.5;
	};
	class S1203_TK_CIV_EP1;
	class S1203_ambulance_EP1: S1203_TK_CIV_EP1
	{
		ACE_W_HEAL = 1;
	};
	class StrykerBase_EP1;
	class M1133_MEV_EP1: StrykerBase_EP1
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.25;
	};
	class BASE_WarfareBFieldhHospital: Camp_base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0;
	};
	class UH60M_US_base_EP1;
	class UH60M_MEV_EP1: UH60M_US_base_EP1
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.25;
	};
	class M113_Base;
	class M113Ambul_Base: M113_Base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.25;
	};
	class UH60_Base;
	class MH60S: UH60_Base
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.25;
	};
	class GAZ_Vodnik;
	class GAZ_Vodnik_MedEvac: GAZ_Vodnik
	{
		ACE_W_HEAL = 1;
		ACE_W_HEAL_LEFTDAM_REST = 0.25;
	};
};
class CfgActions
{
	class None;
	class Heal: None
	{
		show = 0;
		shortcut = "";
	};
	class HealSoldier: None
	{
		show = 0;
		shortcut = "";
	};
};
class CfgSounds
{
	class ACE_Injector
	{
		name = "ACE_Injector";
		sound[] = {"\x\ace\addons\sys_wounds\sound\Inject.ogg","db-5",1};
		titles[] = {};
	};
	class ACE_Suffering1
	{
		name = "ACE Suffering 1";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering01.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering2
	{
		name = "ACE Suffering 2";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering02.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering3
	{
		name = "ACE Suffering 3";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering03.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering4
	{
		name = "ACE Suffering 4";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering04.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering5
	{
		name = "ACE Suffering 5";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering05.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering6
	{
		name = "ACE Suffering 6";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering06.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering7
	{
		name = "ACE Suffering 7";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering07.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering8
	{
		name = "ACE Suffering 8";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering08.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering9
	{
		name = "ACE Suffering 9";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering09.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering10
	{
		name = "ACE Suffering 10";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering10.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering11
	{
		name = "ACE Suffering 11";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering11.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering12
	{
		name = "ACE Suffering 12";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering12.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering13
	{
		name = "ACE Suffering 13";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering13.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering14
	{
		name = "ACE Suffering 14";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering14.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering15
	{
		name = "ACE Suffering 15";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering15.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Suffering16
	{
		name = "ACE Suffering 16";
		sound[] = {"\x\ace\addons\sys_wounds\sound\suffering16.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream1
	{
		name = "ACE Brutal Scream 1";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit1.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream2
	{
		name = "ACE Brutal Scream 2";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit2.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream3
	{
		name = "ACE Brutal Scream 3";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit3.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream4
	{
		name = "ACE Brutal Scream 4";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit4.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream5
	{
		name = "ACE Brutal Scream 5";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit5.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream6
	{
		name = "ACE Brutal Scream 6";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit6.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream7
	{
		name = "ACE Brutal Scream 7";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit7.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream8
	{
		name = "ACE Brutal Scream 8";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit8.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream9
	{
		name = "ACE Brutal Scream 9";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit9.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream10
	{
		name = "ACE Brutal Scream 10";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit10.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream11
	{
		name = "ACE Brutal Scream 11";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit11.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream12
	{
		name = "ACE Brutal Scream 12";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit12.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream13
	{
		name = "ACE Brutal Scream 13";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit13.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream14
	{
		name = "ACE Brutal Scream 14";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit14.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_BrutalScream15
	{
		name = "ACE Brutal Scream 15";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit15.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream1
	{
		name = "ACE Scream 1";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit001.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream2
	{
		name = "ACE Scream 2";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit002.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream3
	{
		name = "ACE Scream 3";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit003.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream4
	{
		name = "ACE Scream 4";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit004.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream5
	{
		name = "ACE Scream 5";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit005.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream6
	{
		name = "ACE Scream 6";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit006.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream7
	{
		name = "ACE Scream 7";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit007.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream8
	{
		name = "ACE Scream 8";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit008.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream9
	{
		name = "ACE Scream 9";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit009.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream10
	{
		name = "ACE Scream 10";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit010.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream11
	{
		name = "ACE Scream 11";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit011.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream12
	{
		name = "ACE Scream 12";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit012.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream13
	{
		name = "ACE Scream 13";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit013.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream14
	{
		name = "ACE Scream 14";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit014.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream15
	{
		name = "ACE Scream 15";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit015.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream16
	{
		name = "ACE Scream 16";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit016.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream17
	{
		name = "ACE Scream 17";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit017.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream18
	{
		name = "ACE Scream 18";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit018.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream19
	{
		name = "ACE Scream 19";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit019.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream20
	{
		name = "ACE Scream 20";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit020.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream21
	{
		name = "ACE Scream 21";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit021.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream22
	{
		name = "ACE Scream 22";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit022.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream23
	{
		name = "ACE Scream 23";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit023.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream24
	{
		name = "ACE Scream 24";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit024.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream25
	{
		name = "ACE Scream 25";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit025.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream26
	{
		name = "ACE Scream 26";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit026.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream27
	{
		name = "ACE Scream 27";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit027.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream28
	{
		name = "ACE Scream 28";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit028.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream29
	{
		name = "ACE Scream 29";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit029.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream30
	{
		name = "ACE Scream 30";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit030.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream31
	{
		name = "ACE Scream 31";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit031.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream32
	{
		name = "ACE Scream 32";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit032.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream33
	{
		name = "ACE Scream 33";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit033.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream34
	{
		name = "ACE Scream 34";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit034.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream35
	{
		name = "ACE Scream 35";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit035.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream36
	{
		name = "ACE Scream 36";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit036.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream37
	{
		name = "ACE Scream 37";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit037.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream38
	{
		name = "ACE Scream 38";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit038.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream39
	{
		name = "ACE Scream 39";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit039.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream40
	{
		name = "ACE Scream 40";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit040.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream41
	{
		name = "ACE Scream 41";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit041.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream42
	{
		name = "ACE Scream 42";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit042.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream43
	{
		name = "ACE Scream 43";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit043.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream44
	{
		name = "ACE Scream 44";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit044.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream45
	{
		name = "ACE Scream 45";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit045.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream46
	{
		name = "ACE Scream 46";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit046.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream47
	{
		name = "ACE Scream 47";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit047.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream48
	{
		name = "ACE Scream 48";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit048.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream49
	{
		name = "ACE Scream 49";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit049.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream50
	{
		name = "ACE Scream 50";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit050.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream51
	{
		name = "ACE Scream 51";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit051.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream52
	{
		name = "ACE Scream 52";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit052.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream53
	{
		name = "ACE Scream 53";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit053.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream54
	{
		name = "ACE Scream 54";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit054.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream55
	{
		name = "ACE Scream 55";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit055.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream56
	{
		name = "ACE Scream 56";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit056.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream57
	{
		name = "ACE Scream 57";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit057.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream58
	{
		name = "ACE Scream 58";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit058.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream59
	{
		name = "ACE Scream 59";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit059.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream60
	{
		name = "ACE Scream 60";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit060.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream61
	{
		name = "ACE Scream 61";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit061.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream62
	{
		name = "ACE Scream 62";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit062.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream63
	{
		name = "ACE Scream 63";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit063.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream64
	{
		name = "ACE Scream 64";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit064.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream65
	{
		name = "ACE Scream 65";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit065.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream66
	{
		name = "ACE Scream 66";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit066.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream67
	{
		name = "ACE Scream 67";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit067.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream68
	{
		name = "ACE Scream 68";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit068.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream69
	{
		name = "ACE Scream 69";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit069.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream70
	{
		name = "ACE Scream 70";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit070.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream71
	{
		name = "ACE Scream 71";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit071.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream72
	{
		name = "ACE Scream 72";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit072.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream73
	{
		name = "ACE Scream 73";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit073.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream74
	{
		name = "ACE Scream 74";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit074.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream75
	{
		name = "ACE Scream 75";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit075.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream76
	{
		name = "ACE Scream 76";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit076.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream77
	{
		name = "ACE Scream 77";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit077.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream78
	{
		name = "ACE Scream 78";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit078.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream79
	{
		name = "ACE Scream 79";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit079.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream80
	{
		name = "ACE Scream 80";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit080.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream81
	{
		name = "ACE Scream 81";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit081.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream82
	{
		name = "ACE Scream 82";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit082.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream83
	{
		name = "ACE Scream 83";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit083.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream84
	{
		name = "ACE Scream 84";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit084.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream85
	{
		name = "ACE Scream 85";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit085.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream86
	{
		name = "ACE Scream 86";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit086.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream87
	{
		name = "ACE Scream 87";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit087.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream88
	{
		name = "ACE Scream 88";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit088.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream89
	{
		name = "ACE Scream 89";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit089.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream90
	{
		name = "ACE Scream 90";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit090.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream91
	{
		name = "ACE Scream 91";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit091.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream92
	{
		name = "ACE Scream 92";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit092.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream93
	{
		name = "ACE Scream 93";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit093.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream94
	{
		name = "ACE Scream 94";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit094.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream95
	{
		name = "ACE Scream 95";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit095.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream96
	{
		name = "ACE Scream 96";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit096.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream97
	{
		name = "ACE Scream 97";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit097.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream98
	{
		name = "ACE Scream 98";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit098.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream99
	{
		name = "ACE Scream 99";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit099.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream100
	{
		name = "ACE Scream 100";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit100.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream101
	{
		name = "ACE Scream 101";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit101.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream102
	{
		name = "ACE Scream 102";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit102.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream103
	{
		name = "ACE Scream 103";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit103.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream104
	{
		name = "ACE Scream 104";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit104.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream105
	{
		name = "ACE Scream 105";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit105.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream106
	{
		name = "ACE Scream 106";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit106.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream107
	{
		name = "ACE Scream 107";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit107.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream108
	{
		name = "ACE Scream 108";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit108.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream109
	{
		name = "ACE Scream 109";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit109.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream110
	{
		name = "ACE Scream 110";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit110.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream111
	{
		name = "ACE Scream 111";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit111.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream112
	{
		name = "ACE Scream 112";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit112.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream113
	{
		name = "ACE Scream 113";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit113.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream114
	{
		name = "ACE Scream 114";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit114.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream115
	{
		name = "ACE Scream 115";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit115.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream116
	{
		name = "ACE Scream 116";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit116.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream117
	{
		name = "ACE Scream 117";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit117.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream118
	{
		name = "ACE Scream 118";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit118.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream119
	{
		name = "ACE Scream 119";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit119.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream120
	{
		name = "ACE Scream 120";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit120.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream121
	{
		name = "ACE Scream 121";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit121.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream122
	{
		name = "ACE Scream 122";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit122.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream123
	{
		name = "ACE Scream 123";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit123.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream124
	{
		name = "ACE Scream 124";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit124.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream125
	{
		name = "ACE Scream 125";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit125.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream126
	{
		name = "ACE Scream 126";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit126.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream127
	{
		name = "ACE Scream 127";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit127.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream128
	{
		name = "ACE Scream 128";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit128.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream129
	{
		name = "ACE Scream 129";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit129.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream130
	{
		name = "ACE Scream 130";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit130.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream131
	{
		name = "ACE Scream 131";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit131.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream132
	{
		name = "ACE Scream 132";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit132.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream133
	{
		name = "ACE Scream 133";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit133.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream134
	{
		name = "ACE Scream 134";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit134.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream135
	{
		name = "ACE Scream 135";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit135.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream136
	{
		name = "ACE Scream 136";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit136.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream137
	{
		name = "ACE Scream 137";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit137.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream138
	{
		name = "ACE Scream 138";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit138.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream139
	{
		name = "ACE Scream 139";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit139.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream140
	{
		name = "ACE Scream 140";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit140.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream141
	{
		name = "ACE Scream 141";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit141.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream142
	{
		name = "ACE Scream 142";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit142.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream143
	{
		name = "ACE Scream 143";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit143.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream144
	{
		name = "ACE Scream 144";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit144.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream145
	{
		name = "ACE Scream 145";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit145.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream146
	{
		name = "ACE Scream 146";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit146.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream147
	{
		name = "ACE Scream 147";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit147.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream148
	{
		name = "ACE Scream 148";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit148.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream149
	{
		name = "ACE Scream 149";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit149.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream150
	{
		name = "ACE Scream 150";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit150.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream151
	{
		name = "ACE Scream 151";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit151.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream152
	{
		name = "ACE Scream 152";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit152.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream153
	{
		name = "ACE Scream 153";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit153.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream154
	{
		name = "ACE Scream 154";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit154.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream155
	{
		name = "ACE Scream 155";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit155.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream156
	{
		name = "ACE Scream 156";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit156.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream157
	{
		name = "ACE Scream 157";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit157.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream158
	{
		name = "ACE Scream 158";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit158.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream159
	{
		name = "ACE Scream 159";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit159.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream160
	{
		name = "ACE Scream 160";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit160.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream161
	{
		name = "ACE Scream 161";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit161.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream162
	{
		name = "ACE Scream 162";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit162.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream163
	{
		name = "ACE Scream 163";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit163.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream164
	{
		name = "ACE Scream 164";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit164.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream165
	{
		name = "ACE Scream 165";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit165.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream166
	{
		name = "ACE Scream 166";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit166.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream167
	{
		name = "ACE Scream 167";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit167.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream168
	{
		name = "ACE Scream 168";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit168.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream169
	{
		name = "ACE Scream 169";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit169.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream170
	{
		name = "ACE Scream 170";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit170.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream171
	{
		name = "ACE Scream 171";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit171.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream172
	{
		name = "ACE Scream 172";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit172.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream173
	{
		name = "ACE Scream 173";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit173.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream174
	{
		name = "ACE Scream 174";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit174.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream175
	{
		name = "ACE Scream 175";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit175.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream176
	{
		name = "ACE Scream 176";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit176.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream177
	{
		name = "ACE Scream 177";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit177.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream178
	{
		name = "ACE Scream 178";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit178.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream179
	{
		name = "ACE Scream 179";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit179.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream180
	{
		name = "ACE Scream 180";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit180.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream181
	{
		name = "ACE Scream 181";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit181.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream182
	{
		name = "ACE Scream 182";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit182.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream183
	{
		name = "ACE Scream 183";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit183.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream184
	{
		name = "ACE Scream 184";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit184.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream185
	{
		name = "ACE Scream 185";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit185.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream186
	{
		name = "ACE Scream 186";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit186.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream187
	{
		name = "ACE Scream 187";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit187.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream188
	{
		name = "ACE Scream 188";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit188.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream189
	{
		name = "ACE Scream 189";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit189.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream190
	{
		name = "ACE Scream 190";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit190.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream191
	{
		name = "ACE Scream 191";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit191.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream192
	{
		name = "ACE Scream 192";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit192.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream193
	{
		name = "ACE Scream 193";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit193.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream194
	{
		name = "ACE Scream 194";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit194.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream195
	{
		name = "ACE Scream 195";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit195.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream196
	{
		name = "ACE Scream 196";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit196.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream197
	{
		name = "ACE Scream 197";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit197.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream198
	{
		name = "ACE Scream 198";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit198.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream199
	{
		name = "ACE Scream 199";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit199.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream200
	{
		name = "ACE Scream 200";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit200.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream201
	{
		name = "ACE Scream 201";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit201.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream202
	{
		name = "ACE Scream 202";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit202.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream203
	{
		name = "ACE Scream 203";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit203.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream204
	{
		name = "ACE Scream 204";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit204.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream205
	{
		name = "ACE Scream 205";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit205.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream206
	{
		name = "ACE Scream 206";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit206.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream207
	{
		name = "ACE Scream 207";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit207.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream208
	{
		name = "ACE Scream 208";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit208.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream209
	{
		name = "ACE Scream 209";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit209.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream210
	{
		name = "ACE Scream 210";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit210.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream211
	{
		name = "ACE Scream 211";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit211.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream212
	{
		name = "ACE Scream 212";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit212.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream213
	{
		name = "ACE Scream 213";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit213.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream214
	{
		name = "ACE Scream 214";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit214.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream215
	{
		name = "ACE Scream 215";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit215.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream216
	{
		name = "ACE Scream 216";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit216.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream217
	{
		name = "ACE Scream 217";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit217.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream218
	{
		name = "ACE Scream 218";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit218.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream219
	{
		name = "ACE Scream 219";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit219.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream220
	{
		name = "ACE Scream 220";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit220.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream221
	{
		name = "ACE Scream 221";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit221.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream222
	{
		name = "ACE Scream 222";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit222.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream223
	{
		name = "ACE Scream 223";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit223.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream224
	{
		name = "ACE Scream 224";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit224.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream225
	{
		name = "ACE Scream 225";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit225.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream226
	{
		name = "ACE Scream 226";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit226.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream227
	{
		name = "ACE Scream 227";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit227.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream228
	{
		name = "ACE Scream 228";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit228.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream229
	{
		name = "ACE Scream 229";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit229.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream230
	{
		name = "ACE Scream 230";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit230.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream231
	{
		name = "ACE Scream 231";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit231.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream232
	{
		name = "ACE Scream 232";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit232.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream233
	{
		name = "ACE Scream 233";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit233.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream234
	{
		name = "ACE Scream 234";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit234.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream235
	{
		name = "ACE Scream 235";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit235.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream236
	{
		name = "ACE Scream 236";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit236.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream237
	{
		name = "ACE Scream 237";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit237.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream238
	{
		name = "ACE Scream 238";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit238.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream239
	{
		name = "ACE Scream 239";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit239.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream240
	{
		name = "ACE Scream 240";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit240.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream241
	{
		name = "ACE Scream 241";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit241.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream242
	{
		name = "ACE Scream 242";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit242.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream243
	{
		name = "ACE Scream 243";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit243.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream244
	{
		name = "ACE Scream 244";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit244.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream245
	{
		name = "ACE Scream 245";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit245.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream246
	{
		name = "ACE Scream 246";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit246.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream247
	{
		name = "ACE Scream 247";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit247.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream248
	{
		name = "ACE Scream 248";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit248.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream249
	{
		name = "ACE Scream 249";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit249.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream250
	{
		name = "ACE Scream 250";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit250.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream251
	{
		name = "ACE Scream 251";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit251.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream252
	{
		name = "ACE Scream 252";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit252.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream253
	{
		name = "ACE Scream 253";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit253.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream254
	{
		name = "ACE Scream 254";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit254.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream255
	{
		name = "ACE Scream 255";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit255.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream256
	{
		name = "ACE Scream 256";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit256.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream257
	{
		name = "ACE Scream 257";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit257.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream258
	{
		name = "ACE Scream 258";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit258.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream259
	{
		name = "ACE Scream 259";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit259.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream260
	{
		name = "ACE Scream 260";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit260.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream261
	{
		name = "ACE Scream 261";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit261.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream262
	{
		name = "ACE Scream 262";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit262.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream263
	{
		name = "ACE Scream 263";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit263.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream264
	{
		name = "ACE Scream 264";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit264.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream265
	{
		name = "ACE Scream 265";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit265.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream266
	{
		name = "ACE Scream 266";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit266.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream267
	{
		name = "ACE Scream 267";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit267.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream268
	{
		name = "ACE Scream 268";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit268.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream269
	{
		name = "ACE Scream 269";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit269.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream270
	{
		name = "ACE Scream 270";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit270.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream271
	{
		name = "ACE Scream 271";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit271.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream272
	{
		name = "ACE Scream 272";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit272.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream273
	{
		name = "ACE Scream 273";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit273.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream274
	{
		name = "ACE Scream 274";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit274.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream275
	{
		name = "ACE Scream 275";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit275.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream276
	{
		name = "ACE Scream 276";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit276.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream277
	{
		name = "ACE Scream 277";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit277.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream278
	{
		name = "ACE Scream 278";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit278.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream279
	{
		name = "ACE Scream 279";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit279.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream280
	{
		name = "ACE Scream 280";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit280.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream281
	{
		name = "ACE Scream 281";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit281.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream282
	{
		name = "ACE Scream 282";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit282.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream283
	{
		name = "ACE Scream 283";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit283.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream284
	{
		name = "ACE Scream 284";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit284.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream285
	{
		name = "ACE Scream 285";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit285.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream286
	{
		name = "ACE Scream 286";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit286.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream287
	{
		name = "ACE Scream 287";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit287.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream288
	{
		name = "ACE Scream 288";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit288.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream289
	{
		name = "ACE Scream 289";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit289.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream290
	{
		name = "ACE Scream 290";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit290.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream291
	{
		name = "ACE Scream 291";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit291.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream292
	{
		name = "ACE Scream 292";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit292.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream293
	{
		name = "ACE Scream 293";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit293.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream294
	{
		name = "ACE Scream 294";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit294.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream295
	{
		name = "ACE Scream 295";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit295.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream296
	{
		name = "ACE Scream 296";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit296.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream297
	{
		name = "ACE Scream 297";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit297.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream298
	{
		name = "ACE Scream 298";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit298.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream299
	{
		name = "ACE Scream 299";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit299.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream300
	{
		name = "ACE Scream 300";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit300.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream301
	{
		name = "ACE Scream 301";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit301.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream302
	{
		name = "ACE Scream 302";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit302.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream303
	{
		name = "ACE Scream 303";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit303.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream304
	{
		name = "ACE Scream 304";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit304.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream305
	{
		name = "ACE Scream 305";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit305.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream306
	{
		name = "ACE Scream 306";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit306.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream307
	{
		name = "ACE Scream 307";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit307.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream308
	{
		name = "ACE Scream 308";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit308.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream309
	{
		name = "ACE Scream 309";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit309.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream310
	{
		name = "ACE Scream 310";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit310.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream311
	{
		name = "ACE Scream 311";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit311.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream312
	{
		name = "ACE Scream 312";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit312.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream313
	{
		name = "ACE Scream 313";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit313.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream314
	{
		name = "ACE Scream 314";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit314.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream315
	{
		name = "ACE Scream 315";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit315.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream316
	{
		name = "ACE Scream 316";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit316.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream317
	{
		name = "ACE Scream 317";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit317.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream318
	{
		name = "ACE Scream 318";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit318.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream319
	{
		name = "ACE Scream 319";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit319.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream320
	{
		name = "ACE Scream 320";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit320.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream321
	{
		name = "ACE Scream 321";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit321.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream322
	{
		name = "ACE Scream 322";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit322.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream323
	{
		name = "ACE Scream 323";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit323.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream324
	{
		name = "ACE Scream 324";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit324.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream325
	{
		name = "ACE Scream 325";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit325.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream326
	{
		name = "ACE Scream 326";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit326.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream327
	{
		name = "ACE Scream 327";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit327.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream328
	{
		name = "ACE Scream 328";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit328.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream329
	{
		name = "ACE Scream 329";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit329.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream330
	{
		name = "ACE Scream 330";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit330.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream331
	{
		name = "ACE Scream 331";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit331.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream332
	{
		name = "ACE Scream 332";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit332.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_Scream333
	{
		name = "ACE Scream 333";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams\hit333.ogg","db-35",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream1
	{
		name = "ACE VD Brutal Scream 1";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit1.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream2
	{
		name = "ACE VD Brutal Scream 2";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit2.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream3
	{
		name = "ACE VD Brutal Scream 3";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit3.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream4
	{
		name = "ACE VD Brutal Scream 4";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit4.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream5
	{
		name = "ACE VD Brutal Scream 5";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit5.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream6
	{
		name = "ACE VD Brutal Scream 6";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit6.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream7
	{
		name = "ACE VD Brutal Scream 7";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit7.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream8
	{
		name = "ACE VD Brutal Scream 8";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit8.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream9
	{
		name = "ACE VD Brutal Scream 9";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit9.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream10
	{
		name = "ACE VD Brutal Scream 10";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit10.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream11
	{
		name = "ACE VD Brutal Scream 11";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit11.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream12
	{
		name = "ACE VD Brutal Scream 12";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit12.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream13
	{
		name = "ACE VD Brutal Scream 13";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit13.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream14
	{
		name = "ACE VD Brutal Scream 14";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit14.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_VDBrutalScream15
	{
		name = "ACE VD Brutal Scream 15";
		sound[] = {"\x\ace\addons\sys_wounds\sound\screams_brutal\hit15.ogg","db-15",1};
		titles[] = {};
	};
	class ACE_Drattle1
	{
		name = "ACE Death Rattle 1";
		sound[] = {"\x\ace\addons\sys_wounds\sound\rattle\ace_drattle1","db-45",1};
		titles[] = {};
	};
	class ACE_Drattle2: ACE_Drattle1
	{
		sound[] = {"\x\ace\addons\sys_wounds\sound\rattle\ace_drattle2","db-45",1};
	};
	class ACE_Drattle3: ACE_Drattle1
	{
		sound[] = {"\x\ace\addons\sys_wounds\sound\rattle\ace_drattle3","db-45",1};
	};
	class ACE_Drattle4: ACE_Drattle1
	{
		sound[] = {"\x\ace\addons\sys_wounds\sound\rattle\ace_drattle4","db-45",1};
	};
	class ACE_Drattle5: ACE_Drattle1
	{
		sound[] = {"\x\ace\addons\sys_wounds\sound\rattle\ace_drattle5","db-45",1};
	};
	class ACE_BurningElectric
	{
		name = "ACE Burning Electric";
		sound[] = {"\x\ace\addons\sys_wounds\sound\burning_electric.ogg","db-5",1};
		titles[] = {};
	};
	class ACE_Burning
	{
		name = "ACE Burning";
		sound[] = {"\x\ace\addons\sys_wounds\sound\burning1.ogg","db-5",1};
		titles[] = {};
	};
};
class RscTitles
{
	class ACE_Wound_Revivetime
	{
		idd = 585306;
		movingEnable = "true";
		fadein = 0;
		fadeout = 0;
		duration = 1e+011;
		name = "ACE_Wound_Revivetime";
		controls[] = {"ACE_Wound_TextStr"};
		onload = "with uiNamespace do {ACE_Wound_Revivetime = _this select 0}";
		class ACE_Wound_TextStr
		{
			type = 0;
			idc = 1234567;
			style = 0;
			x = 0.45;
			y = 0.725;
			w = 0.2;
			h = 0.2;
			font = "Zeppelin32";
			sizeEx = 0.023;
			colorText[] = {1.0,1.0,1.0,0.9};
			colorBackground[] = {0,0,0,0.0};
			text = "";
		};
	};
	class ACE_Wound_Bleeding1
	{
		idd = 585301;
		movingEnable = 0;
		duration = 0.1;
		fadein = 0.4;
		fadeout = 0.5;
		name = "ACE_Wound_Bleeding1";
		class controls
		{
			class ACE_Wound_Bleeding_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.6};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_bleeding1.paa";
			};
		};
	};
	class ACE_Wound_Bleeding2
	{
		idd = 585302;
		movingEnable = 0;
		duration = 0.1;
		fadein = 0.3;
		fadeout = 0.6;
		name = "ACE_Wound_Bleeding2";
		class controls
		{
			class ACE_Wound_Bleeding_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.8};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_bleeding1.paa";
			};
		};
	};
	class ACE_Wound_Bleeding3
	{
		idd = 585303;
		movingEnable = 0;
		duration = 0.1;
		fadein = 0.2;
		fadeout = 0.7;
		name = "ACE_Wound_Bleeding3";
		class controls
		{
			class ACE_Wound_Bleeding_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.9};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_bleeding2.paa";
			};
		};
	};
	class ACE_Wound_Bleeding4
	{
		idd = 585304;
		movingEnable = 0;
		duration = 0.1;
		fadein = 0.18;
		fadeout = 0.72;
		name = "ACE_Wound_Bleeding4";
		class controls
		{
			class ACE_Wound_Bleeding_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.9};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_bleeding3.paa";
			};
		};
	};
	class ACE_Wound_Bleeding5
	{
		idd = 585305;
		movingEnable = 0;
		duration = 0.1;
		fadein = 0.15;
		fadeout = 0.75;
		name = "ACE_Wound_Bleeding5";
		class controls
		{
			class ACE_Wound_Bleeding_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.9};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_bleeding3.paa";
			};
		};
	};
	class ACE_Wound_Unconscious1
	{
		idd = 585311;
		movingEnable = 0;
		duration = 1e+011;
		fadein = 0;
		fadeout = 1.5;
		name = "ACE_Wound_Unconscious1";
		class controls
		{
			class ACE_Wound_Unconscious_BG
			{
				idc = 1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_unc1.paa";
			};
		};
	};
	class ACE_Wound_Unconscious2
	{
		idd = 585312;
		movingEnable = 0;
		duration = 1e+011;
		fadein = 1.5;
		fadeout = 0;
		name = "ACE_Wound_Unconscious2";
		class controls
		{
			class ACE_Wound_Unconscious_BG
			{
				idc = 1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_unc2.paa";
			};
		};
	};
	class ACE_Wound_Unconscious3
	{
		idd = 585313;
		movingEnable = 0;
		duration = 2;
		fadein = 0;
		fadeout = 1.5;
		name = "ACE_Wound_Unconscious3";
		class controls
		{
			class ACE_Wound_Unconscious_BG
			{
				idc = 1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_unc2.paa";
			};
		};
	};
	class ACE_Wound_UnconsciousNothing
	{
		idd = -1;
		movingEnable = 0;
		duration = 1;
		fadein = 0;
		fadeout = 1.5;
		name = "ACE_Wound_UnconsciousNothing";
		class controls
		{
			class ACE_Wound_Unconscious_BG2
			{
				idc = 2;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {1,1,1,1};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_unc1.paa";
			};
		};
	};
	class ACE_Wound_Pain
	{
		idd = 585321;
		movingEnable = 0;
		duration = 0.1;
		fadein = 0.4;
		fadeout = 0.5;
		name = "ACE_Wound_Pain";
		class controls
		{
			class ACE_Wound_Bleeding_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.65};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\i_pain.paa";
			};
		};
	};
	class ACE_Wound_ScreenDirt
	{
		idd = -1;
		movingEnable = 0;
		duration = 5;
		fadein = 0.01;
		fadeout = 5;
		name = "ACE_Wound_ScreenDirt";
		class controls
		{
			class ACE_Wound_ScreenDirt_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.8};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\screen_dirt_ca.paa";
			};
		};
	};
	class ACE_Wound_ScreenBlood1
	{
		idd = -1;
		movingEnable = 0;
		duration = 2;
		fadein = 0.1;
		fadeout = 5;
		name = "ACE_Wound_ScreenBlood1";
		class controls
		{
			class ACE_Wound_ScreenBlood_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.8};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\screen_blood_1_ca.paa";
			};
		};
	};
	class ACE_Wound_ScreenBlood2
	{
		idd = -1;
		movingEnable = 0;
		duration = 2;
		fadein = 0.1;
		fadeout = 5;
		name = "ACE_Wound_ScreenBlood2";
		class controls
		{
			class ACE_Wound_ScreenBlood_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.8};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\screen_blood_2_ca.paa";
			};
		};
	};
	class ACE_Wound_ScreenBlood3
	{
		idd = -1;
		movingEnable = 0;
		duration = 2;
		fadein = 0.1;
		fadeout = 5;
		name = "ACE_Wound_ScreenBlood3";
		class controls
		{
			class ACE_Wound_ScreenBlood_BG
			{
				idc = -1;
				type = 0;
				style = 48;
				colorBackground[] = {0,0,0,0};
				colorText[] = {0.9,0.9,0.9,0.8};
				font = "Bitstream";
				sizeEx = 0.023;
				x = "safeZoneXAbs";
				y = "SafeZoneY";
				w = "safeZoneWAbs + 0.05";
				h = "SafeZoneH + 0.05";
				text = "\x\ace\addons\sys_wounds\data\rsc\screen_blood_3_ca.paa";
			};
		};
	};
};
class ACE_Wound_Unconscious_Rare
{
	name = "ACE_Wound_Unconscious_Rare";
	idd = -1;
	movingEnable = 1;
	controlsBackground[] = {"Background"};
	objects[] = {};
	controls[] = {};
	onLoad = "with uiNamespace do {ACE_Wound_Unconscious_Rare = _this select 0}";
	class Background
	{
		colorBackground[] = {0,0,0,0};
		type = 0;
		colorText[] = {1,1,1,1};
		sizeEx = 0.04;
		style = 48;
		font = "BitStream";
		idc = -1;
		x = "safeZoneXAbs";
		y = "SafeZoneY";
		w = "safeZoneWAbs + 0.05";
		h = "SafeZoneH + 0.05";
		text = "\x\ace\addons\sys_wounds\data\rsc\i_unc1.paa";
	};
};
class ACE_Wound_Unconscious_Full: ACE_Wound_Unconscious_Rare
{
	name = "ACE_Wound_Unconscious_Full";
	onLoad = "with uiNamespace do {ACE_Wound_Unconscious_Full = _this select 0}";
	class Background: Background
	{
		text = "\x\ace\addons\sys_wounds\data\rsc\i_unc2.paa";
	};
};