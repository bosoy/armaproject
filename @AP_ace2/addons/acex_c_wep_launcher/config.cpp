////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:48:52 2013 : Created on Sat Apr 06 11:48:52 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_wep_launcher : config.bin{
class CfgPatches
{
	class acex_wep_launcher
	{
		units[] = {"ACE_RPG27Used_Tube","ACE_RPG22Used_Tube","ACE_M72A2_Used_Tube","ACE_RPOM_Used_Tube"};
		weapons[] = {"ACE_M72A2","ACE_M72","ACE_RPG29","ACE_RPG22","ACE_RPG22Used","ACE_RPG27","ACE_RPG27Used","ACE_RPOM","ACE_RPOM_used"};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAWeapons","CAWeapons_E_GrenadeLauncher","ace_c_weapon","acex_m_wep_launcher","acex_t_wep_launcher","acex_s_wep_launcher","ace_sys_disposal"};
		version = "1.14.0.371";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class acex_wep_launcher
		{
			list[] = {"acex_wep_launcher"};
		};
	};
};
class CfgAmmo
{
	class R_M136_AT;
	class ACE_R_M72_AT: R_M136_AT
	{
		hit = 300;
		ace_hit = 300;
		indirectHit = 20;
		indirectHitRange = 2.7;
		cost = 4000;
		maxSpeed = 96;
		sideAirFriction = 0.05;
		ACE_AT_FX = "ACE_BB_BACK_RPG";
	};
	class R_PG7V_AT;
	class R_PG7VR_AT;
	class ACE_R_TBG7V_AT;
	class ACE_Rocket_RPG22: R_PG7V_AT
	{
		hit = 400;
		ace_hit = 400;
		indirecthit = 20;
		indirectHitRange = 2.7;
		timeToLive = 5;
		sideAirFriction = 0.05;
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
		maxspeed = 84;
		irlock = 1;
	};
	class ACE_Rocket_RPG27: ACE_Rocket_RPG22
	{
		hit = 720;
		ace_hit = 650;
		ace_tandemheat = 1;
		indirecthit = 25;
		indirectHitRange = 3;
		maxspeed = 76;
	};
	class ACE_Rocket_RSHG1: ACE_Rocket_RPG27
	{
		model = "\x\acex\addons\m_wep_launcher\RPO_ROCKET";
		hit = 190;
		ace_hit = 80;
		indirecthit = 90;
		indirectHitRange = 5;
		sideAirFriction = 0.006;
		timetolive = 10;
		maxspeed = 76;
		ace_thermobaric = 1;
		ace_tandemheat = 0;
		ace_heat = 0;
		irlock = 0;
		craterEffects = "ACE_FAE_Crater";
		explosionEffects = "ACE_FAE_Explosion";
		soundDefault1[] = {"x\ace\addons\c_weapon\data\sound\fae_hit1.wss",44.6684,1,4000};
		soundDefault2[] = {"x\ace\addons\c_weapon\data\sound\fae_hit2.wss",44.6684,1,4000};
		soundDefault3[] = {"x\ace\addons\c_weapon\data\sound\fae_hit3.wss",44.6684,1,4000};
		soundMetal1[] = {"x\ace\addons\c_weapon\data\sound\fae_hit1.wss",44.6684,1,4000};
		soundMetal2[] = {"x\ace\addons\c_weapon\data\sound\fae_hit2.wss",44.6684,1,4000};
		soundMetal3[] = {"x\ace\addons\c_weapon\data\sound\fae_hit3.wss",44.6684,1,4000};
		hitGroundSoft[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGroundHard[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMan[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitArmor[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitIron[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitBuilding[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitFoliage[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitWood[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlass[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlassArmored[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitConcrete[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitRubber[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitPlastic[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitDefault[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMetal[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitMetalplate[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
	};
	class ACE_Rocket_RMG: ACE_Rocket_RSHG1
	{
		ace_hit = 500;
		hit = 500;
		indirecthit = 70;
		indirectHitRange = 5;
		ace_thermobaric = 1;
		ace_tandemheat = 0;
		ace_heat = 1;
	};
	class ACE_R_RPOM: ACE_Rocket_RPG22
	{
		model = "\x\acex\addons\m_wep_launcher\RPO_ROCKET";
		hit = 230;
		ace_hit = 95;
		indirecthit = 130;
		indirectHitRange = 7;
		sideAirFriction = 0.006;
		timetolive = 10;
		maxspeed = 76;
		ace_thermobaric = 1;
		ace_heat = 0;
		irlock = 0;
		craterEffects = "ACE_FAE_Crater";
		explosionEffects = "ACE_FAE_Explosion";
		soundDefault1[] = {"x\ace\addons\c_weapon\data\sound\fae_hit1.wss",44.6684,1,4000};
		soundDefault2[] = {"x\ace\addons\c_weapon\data\sound\fae_hit2.wss",44.6684,1,4000};
		soundDefault3[] = {"x\ace\addons\c_weapon\data\sound\fae_hit3.wss",44.6684,1,4000};
		soundMetal1[] = {"x\ace\addons\c_weapon\data\sound\fae_hit1.wss",44.6684,1,4000};
		soundMetal2[] = {"x\ace\addons\c_weapon\data\sound\fae_hit2.wss",44.6684,1,4000};
		soundMetal3[] = {"x\ace\addons\c_weapon\data\sound\fae_hit3.wss",44.6684,1,4000};
		hitGroundSoft[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGroundHard[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMan[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitArmor[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitIron[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitBuilding[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitFoliage[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitWood[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlass[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitGlassArmored[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitConcrete[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitRubber[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitPlastic[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitDefault[] = {"soundDefault1",0.33,"soundDefault2",0.33,"soundDefault3",0.33};
		hitMetal[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
		hitMetalplate[] = {"soundMetal1",0.33,"soundMetal2",0.33,"soundMetal3",0.33};
	};
	class ACE_Rocket_PG29: R_PG7VR_AT
	{
		model = "\x\acex\addons\m_wep_launcher\PG_29V";
		timeToLive = 5;
		sideAirFriction = 0.2;
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
		maxspeed = 150;
	};
	class ACE_Rocket_TBG29: ACE_R_TBG7V_AT
	{
		model = "\x\acex\addons\m_wep_launcher\TBG_29V";
		timeToLive = 5;
		sideAirFriction = 0.2;
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
		maxspeed = 150;
		ace_thermobaric = 1;
	};
};
class CfgMagazines
{
	class M136;
	class ACE_M72A2: M136
	{
		displayName = "$STR_MDN_ACE_M72A2";
		ammo = "ACE_R_M72_AT";
		modelSpecial = "\x\acex\addons\m_wep_launcher\m72a2_armed.p3d";
		initSpeed = 150;
	};
	class ACE_M72: ACE_M72A2{};
	class ACE_M72A2_Used: ACE_M72A2
	{
		scope = 1;
		count = 0;
		displayName = "$STR_WDN_ACE_M72A2USED";
		modelSpecial = "\x\acex\addons\m_wep_launcher\m72a2_used.p3d";
	};
	class RPG18;
	class PG7VR;
	class ACE_RPG29_PG29: PG7VR
	{
		displayName = "$STR_MDN_ACE_PG29";
		displayNameShort = "$STR_MDNS_ACE_PG29";
		ace_weight = 6.1;
		ammo = "ACE_Rocket_PG29";
		initspeed = 255;
		model = "\x\acex\addons\m_wep_launcher\PG_29V";
		modelSpecial = "\x\acex\addons\m_wep_launcher\RPG_29V";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_PG29";
	};
	class ACE_RPG29_TBG29: ACE_RPG29_PG29
	{
		displayName = "$STR_MDN_ACE_TBG29";
		displayNameShort = "$STR_MDNS_ACE_TBG29";
		ammo = "ACE_Rocket_TBG29";
		model = "\x\acex\addons\m_wep_launcher\TBG_29V";
		modelSpecial = "\x\acex\addons\m_wep_launcher\RPG_29V";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_TBG29";
	};
	class ACE_RPG22: RPG18
	{
		displayName = "$STR_WDN_ACE_RPG22";
		ACE_Weight = 0;
		ammo = "ACE_Rocket_RPG22";
		initSpeed = 133;
		picture = "\ca\weapons\data\clear_empty.paa";
		model = "\ca\weapons\empty";
		modelSpecial = "\x\acex\addons\m_wep_launcher\RHS_RPG22";
		ace_disposable = 1;
		type = 256;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RPG22Used: ACE_RPG22
	{
		displayName = "$STR_WDN_ACE_RPG22USED";
		scope = 1;
		count = 0;
		modelSpecial = "\x\acex\addons\m_wep_launcher\RHS_RPG22clean";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RPG27: RPG18
	{
		displayName = "$STR_WDN_ACE_RPG27";
		ACE_Weight = 0;
		ammo = "ACE_Rocket_RPG27";
		initSpeed = 120;
		picture = "\ca\weapons\data\clear_empty.paa";
		model = "\ca\weapons\empty";
		modelSpecial = "\x\acex\addons\m_wep_launcher\RHS_RPG27";
		ace_disposable = 1;
		type = 256;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RPG27Used: ACE_RPG27
	{
		displayName = "$STR_WDN_ACE_RPG27USED";
		scope = 1;
		count = 0;
		modelSpecial = "\x\acex\addons\m_wep_launcher\RHS_RPG27clean";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RSHG1: ACE_RPG27
	{
		displayName = "$STR_WDN_ACE_RSHG1";
		ammo = "ACE_Rocket_RSHG1";
	};
	class ACE_RSHG1_Used: ACE_RSHG1
	{
		displayName = "$STR_WDN_ACE_RSHG1_Used";
		scope = 1;
		count = 0;
		modelSpecial = "\x\acex\addons\m_wep_launcher\RHS_RPG27clean";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RMG: ACE_RPG27
	{
		displayName = "$STR_WDN_ACE_RMG";
		ammo = "ACE_Rocket_RMG";
	};
	class ACE_RMG_Used: ACE_RMG
	{
		displayName = "$STR_WDN_ACE_RMG_Used";
		scope = 1;
		count = 0;
		modelSpecial = "\x\acex\addons\m_wep_launcher\RHS_RPG27clean";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RPO_M: RPG18
	{
		ACE_Weight = 0;
		ammo = "ACE_R_RPOM";
		displayName = "$STR_WDN_ACE_RPOM";
		initSpeed = 180;
		type = 256;
		picture = "\ca\weapons\data\clear_empty.paa";
		model = "\ca\weapons\empty";
		modelSpecial = "\x\acex\addons\m_wep_launcher\RPO_M";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_RPOM";
	};
	class ACE_RPO_M_Used: ACE_RPO_M
	{
		scope = 1;
		ACE_Weight = 0;
		count = 0;
		displayName = "$STR_WDN_ACE_RPOMUSED";
		picture = "\ca\weapons\data\clear_empty.paa";
		model = "\ca\weapons\empty";
		modelSpecial = "\x\acex\addons\m_wep_launcher\RPO_M";
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_RPOM";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class M136;
	class ACE_M72A2: M136
	{
		displayName = "M72A2";
		sound[] = {"\x\acex\addons\s_wep_launcher\M72_Fire.wss",16.5,1,2500};
		model = "\x\acex\addons\m_wep_launcher\m72a2_safe.p3d";
		modelOptics = "-";
		picture = "\x\acex\addons\c_wep_launcher\i\w_m72a2_ca.paa";
		minRange = 10;
		minRangeProbab = 0.3;
		midRange = 100;
		midRangeProbab = 0.7;
		maxRange = 250;
		maxRangeProbab = 0.1;
		magazines[] = {"ACE_M72A2"};
		ace_weight = 2.3;
		dexterity = "(0.5 + 3.75/(2.3 + 0.001) + 0/10)";
		ace_disposable = 1;
		ace_disposable_used = "ACE_M72A2_Used";
		ace_disposable_model = "ACE_M72A2_Used_Tube";
		ace_sa_enabled = 0;
	};
	class ACE_M72: ACE_M72A2
	{
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_M72A2_Used: ACE_M72
	{
		scope = 1;
		ace_weight = 0.5;
		dexterity = "(0.5 + 3.75/(0.5 + 0.001) + 0/10)";
		ace_disposable = 0;
		ace_isusedweapon = 1;
		displayName = "$STR_WDN_ACE_M72A2USED";
		model = "\x\acex\addons\m_wep_launcher\m72a2_used.p3d";
		magazines[] = {"ACE_M72A2_Used"};
		class Armory
		{
			disabled = 1;
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class RPG7V;
	class ACE_RPG29: RPG7V
	{
		scope = 2;
		ace_weight = 12.07;
		dexterity = "(0.5 + 3.75/(11.5+ 0.57+ 6.1 + 0.001) + -3/10)";
		ACE_Size = 9000;
		ACE_NoPack = 1;
		displayName = "$STR_WDN_ACE_RPG29";
		picture = "\x\acex\addons\c_wep_launcher\i\w_rpg29_ca.paa";
		magazines[] = {"ACE_RPG29_PG29","ACE_RPG29_TBG29"};
		sound[] = {"\x\acex\addons\s_wep_launcher\rpg29_fire.wss",10,1,2400};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_launcher\rpg29_reload.wss",0.000316228,1,20};
		model = "\x\acex\addons\m_wep_launcher\RPG_29V_launcher";
		modelOptics = "\x\acex\addons\m_wep_launcher\ACE_optics_PGO29";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\igla.rtm"};
		opticsZoomMin = 0.128;
		opticsZoomMax = 0.128;
		opticsZoomInit = 0.128;
		minRange = 12;
		minRangeProbab = 0.4;
		midRange = 250;
		midRangeProbab = 0.7;
		maxRange = 500;
		maxRangeProbab = 0.2;
		ace_sa_enabled = 0;
		ace_at_zero = 24.5;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RPG22: RPG7V
	{
		scope = 2;
		displayName = "$STR_WDN_ACE_RPG22";
		ace_weight = 2.8;
		dexterity = "(0.5 + 3.75/(2.8 + 0.001) + 0/10)";
		model = "\x\acex\addons\m_wep_launcher\RHS_RPG22";
		sound[] = {"\x\acex\addons\s_wep_launcher\rpg22_fire.wss",10,1,2000};
		reloadMagazineSound[] = {"\x\acex\addons\s_wep_launcher\rpg_arm.wss",0.000316228,1,20};
		picture = "\x\acex\addons\c_wep_launcher\i\w_rpg22_ca.paa";
		magazines[] = {"ACE_RPG22"};
		handAnim[] = {};
		minRange = 12;
		minRangeProbab = 0.3;
		midRange = 160;
		midRangeProbab = 0.7;
		maxRange = 250;
		maxRangeProbab = 0.1;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
		ace_disposable = 1;
		ace_disposable_used = "ACE_RPG22Used";
		ace_disposable_model = "ACE_RPG22Used_Tube";
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_minrange = 50;
		ace_sa_maxrange = 250;
		ace_sa_steprange = 100;
		ace_sa_table_elev[] = {{0,0},{50,13.6},{150,40.2},{250,69.5}};
	};
	class ACE_RPG22Used: ACE_RPG22
	{
		scope = 1;
		ace_weight = 1.6;
		dexterity = "(0.5 + 3.75/(1.6 + 0.001) + 0/10)";
		displayName = "$STR_WDN_ACE_RPG22USED";
		model = "\x\acex\addons\m_wep_launcher\RHS_RPG22clean";
		magazines[] = {"ACE_RPG22Used"};
		ace_disposable = 0;
		ace_isusedweapon = 1;
		class Armory
		{
			disabled = 1;
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RPG27: ACE_RPG22
	{
		ace_weight = 8.3;
		dexterity = "(0.5 + 3.75/(8.3 + 0.001) + 0/10)";
		ACE_sys_weapons_Side[] = {"CDF","RU","BIS_TK"};
		displayName = "$STR_WDN_ACE_RPG27";
		model = "\x\acex\addons\m_wep_launcher\RHS_RPG27";
		picture = "\x\acex\addons\c_wep_launcher\i\w_rpg27_ca.paa";
		magazines[] = {"ACE_RPG27"};
		minRange = 12;
		minRangeProbab = 0.3;
		midRange = 170;
		midRangeProbab = 0.7;
		maxRange = 260;
		maxRangeProbab = 0.1;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
		ace_disposable = 1;
		ace_disposable_used = "ACE_RPG27Used";
		ace_disposable_model = "ACE_RPG27Used_Tube";
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = -1.0;
		ace_sa_minrange = 50;
		ace_sa_maxrange = 200;
		ace_sa_steprange = 50;
		ace_sa_table_elev[] = {{0,0},{50,15.2},{100,33.6},{150,51.2},{200,67.2}};
		handAnim[] = {"OFP2_ManSkeleton","\x\acex\addons\c_wep_launcher\anim\ace_rpg27.rtm"};
	};
	class ACE_RPG27Used: ACE_RPG27
	{
		scope = 1;
		ace_weight = 3.8;
		dexterity = "(0.5 + 3.75/(3.8 + 0.001) + 0/10)";
		displayName = "$STR_WDN_ACE_RPG27USED";
		model = "\x\acex\addons\m_wep_launcher\RHS_RPG27clean";
		magazines[] = {"ACE_RPG27Used"};
		ace_disposable = 0;
		ace_isusedweapon = 1;
		class Armory
		{
			disabled = 1;
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_UG";
	};
	class ACE_RPOM: ACE_RPG22
	{
		ACE_sys_weapons_Side[] = {"RU","BIS_TK"};
		ace_weight = 8.8;
		dexterity = "(0.5 + 3.75/(8.8 + 0.001) + 0/10)";
		displayName = "$STR_WDN_ACE_RPOM";
		model = "\x\acex\addons\m_wep_launcher\RPO_M";
		picture = "\x\acex\addons\c_wep_launcher\i\w_rpo_i_ca.paa";
		modelOptics = "\x\acex\addons\m_wep_launcher\ACE_optics_RPO_M";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\data\Anim\Strela.rtm"};
		opticsZoomMin = 0.128;
		opticsZoomMax = 0.128;
		opticsZoomInit = 0.128;
		ace_sa_enabled = 0;
		ace_at_zero = 75.2;
		visionMode[] = {"Normal"};
		magazines[] = {"ACE_RPO_M"};
		minRange = 12;
		minRangeProbab = 0.3;
		midRange = 270;
		midRangeProbab = 0.7;
		maxRange = 400;
		maxRangeProbab = 0.1;
		class Library
		{
			libTextDesc = "";
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_FAE";
		ace_disposable = 1;
		ace_disposable_used = "ACE_RPOM_Used";
		ace_disposable_model = "ACE_RPOM_Used_Tube";
	};
	class ACE_RPOM_Used: ACE_RPOM
	{
		scope = 1;
		model = "\x\acex\addons\m_wep_launcher\RPO_M_fired";
		ace_weight = 2.1;
		dexterity = "(0.5 + 3.75/(2.1 + 0.001) + 0/10)";
		displayName = "$STR_WDN_ACE_RPOMUSED";
		magazines[] = {"ACE_RPO_M_Used"};
		ace_disposable = 0;
		ace_isusedweapon = 1;
		class Armory
		{
			disabled = 1;
		};
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_FAE";
	};
	class ACE_RSHG1: ACE_RPG27
	{
		displayName = "$STR_WDN_ACE_RSHG1";
		magazines[] = {"ACE_RSHG1"};
		ace_disposable_used = "ACE_RSHG1_Used";
		ace_disposable_model = "ACE_RSHG1_Used_Tube";
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_FAE";
	};
	class ACE_RSHG1_Used: ACE_RSHG1
	{
		scope = 1;
		displayName = "$STR_WDN_ACE_RSHG1_Used";
		magazines[] = {"ACE_RSHG1_Used"};
		ace_disposable = 0;
		ace_isusedweapon = 1;
		class Armory
		{
			disabled = 1;
		};
	};
	class ACE_RMG: ACE_RSHG1
	{
		displayName = "$STR_WDN_ACE_RMG";
		magazines[] = {"ACE_RMG"};
		ace_disposable_used = "ACE_RMG_Used";
		ace_disposable_model = "ACE_RMG_Used_Tube";
		descriptionShort = "$STR_DSS_ACE_LAUNCHER_FAE";
		ace_weight = 8.5;
		dexterity = "(0.5 + 3.75/(8.5 + 0.001) + 0/10)";
	};
	class ACE_RMG_Used: ACE_RMG
	{
		scope = 1;
		displayName = "$STR_WDN_ACE_RMG_Used";
		magazines[] = {"ACE_RMG_Used"};
		ace_disposable = 0;
		ace_isusedweapon = 1;
		class Armory
		{
			disabled = 1;
		};
	};
};
class CfgVehicles
{
	class ACE_UsedTubes;
	class ACE_RPG27Used_Tube: ACE_UsedTubes
	{
		model = "\x\acex\addons\m_wep_launcher\rpg27_used_vehicle.p3d";
	};
	class ACE_RPG22Used_Tube: ACE_RPG27Used_Tube
	{
		model = "\x\acex\addons\m_wep_launcher\rpg22_used_vehicle.p3d";
	};
	class ACE_M72A2_Used_Tube: ACE_UsedTubes
	{
		model = "\x\acex\addons\m_wep_launcher\m72a2_used_vehicle.p3d";
	};
	class ACE_RPOM_Used_Tube: ACE_UsedTubes
	{
		model = "\x\acex\addons\m_wep_launcher\RPO_M_used_vehicle.p3d";
	};
	class ACE_RSHG1_Used_Tube: ACE_RPG27Used_Tube{};
	class ACE_RMG_Used_Tube: ACE_RSHG1_Used_Tube{};
};
//};
