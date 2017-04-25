////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:33:34 2012 : Created on Fri Nov 09 22:33:34 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_grenades : config.bin{
class CfgPatches
{
	class ace_sys_grenades
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_c_weapon","ace_main"};
		version = "1.14.0.581";
	};
};
class CfgAddons
{
	class PreloadAddons
	{
		class ace_sys_grenades
		{
			list[] = {"ace_sys_grenades"};
		};
	};
};
class CfgAmmo
{
	class GrenadeBase;
	class G_40mm_HE: GrenadeBase
	{
		ACE_GRENADE_TYPE = "GP25";
	};
	class ACE_G40mm_HE_VOG25P: G_40mm_HE
	{
		ACE_GRENADE_TYPE = "GP25";
	};
	class ACE_G_40mm_HEDP: G_40mm_HE
	{
		ACE_GRENADE_TYPE = "M203";
	};
	class ACE_G_40mm_HE: ACE_G_40mm_HEDP
	{
		ACE_GRENADE_TYPE = "M203";
	};
	class ACE_G_40mm_Practice: ACE_G_40mm_HE
	{
		ACE_GRENADE_TYPE = "NONE";
	};
	class SmokeShell;
	class G_40mm_Smoke: SmokeShell
	{
		ACE_GRENADE_TYPE = "NONE";
	};
	class ACE_Grenade_40mm_Dummy: G_40mm_HE
	{
		typicalspeed = 76;
		soundHit[] = {"",1,1};
		soundFly[] = {"",1,1};
		CraterEffects = "";
		explosionEffects = "";
		model = "\ca\Weapons\granat";
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		explosive = 0.01;
		explosionTime = 19;
		deflecting = 0;
	};
	class ACE_Grenade_M433_Dummy: ACE_Grenade_40mm_Dummy
	{
		model = "\x\ace\addons\m_wep_magazines\ace_m433_armed.p3d";
	};
	class ACE_Grenade_VOG25_Dummy: ACE_Grenade_40mm_Dummy
	{
		model = "\x\ace\addons\m_wep_magazines\ace_vog25_armed.p3d";
	};
	class ACE_Grenade_VOG25P_Dummy: ACE_Grenade_40mm_Dummy
	{
		model = "\x\ace\addons\m_wep_magazines\ace_vog25p_armed.p3d";
	};
	class ACE_Grenade_40mm_SelfDestr: ACE_G40mm_HE_VOG25P
	{
		fusedistance = 0;
		explosionTime = 0.07;
	};
};
//};
