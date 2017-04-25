////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:39:39 2012 : Created on Fri Nov 09 22:39:39 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_veh_air_wep : config.bin{
class CfgPatches
{
	class acex_ru_veh_air_wep
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAAir","CAWeapons","CA_Anims","CAData","acex_ru_main","ace_c_vehicle","ace_c_vehicle","Extended_EventHandlers","ace_sys_easa"};
		version = "1.14.0.76";
	};
};
class CfgAmmo
{
	class MissileBase;
	class BombCore;
	class LaserBombCore;
	class ACE_R_Empty_Dummy: MissileBase
	{
		proxyShape = "\ca\weapons\empty";
	};
	class ACE_R_S8T: MissileBase
	{
		proxyShape = "\ca\air\s8_launcher_aircraft";
	};
	class ACE_R_S8T_2: MissileBase
	{
		proxyShape = "\ca\weapons\empty";
	};
	class ACE_R_UB16: MissileBase
	{
		proxyShape = "\CA\air_e\ub16.p3d";
	};
	class ACE_R_UB32: MissileBase
	{
		proxyShape = "\CA\air_e\ub32.p3d";
	};
	class M_R73_AA;
	class ACE_M_R73_AA: M_R73_AA{};
	class ACE_M_R27_AA: M_R73_AA
	{
		model = "\x\acex_ru\addons\m_veh_air_wep\alamoA";
		proxyShape = "\x\acex_ru\addons\m_veh_air_wep\alamoA";
	};
	class M_Ch29_AT;
	class ACE_M_Kh29_AT: M_Ch29_AT
	{
		model = "\x\acex_ru\addons\m_veh_air_wep\Kh29";
		proxyShape = "\x\acex_ru\addons\m_veh_air_wep\Kh29";
	};
	class ACE_M_Kh25_AT: MissileBase
	{
		model = "\x\acex_ru\addons\m_veh_air_wep\KH-25ML";
		proxyShape = "\x\acex_ru\addons\m_veh_air_wep\KH-25ML";
	};
	class Bo_FAB_250;
	class ACE_Bo_FAB_250: Bo_FAB_250{};
	class R_S8T_AT;
	class ACE_R_S8T_AT: R_S8T_AT{};
	class ACE_Bo_FAB500: Bo_FAB_250{};
	class ACE_Bo_FAB500M62: ACE_Bo_FAB500
	{
		model = "\x\acex_ru\addons\m_veh_air_wep\FAB500M62HE";
		proxyShape = "\x\acex_ru\addons\m_veh_air_wep\FAB500M62HE";
	};
	class Bo_GBU12_LGB;
	class ACE_Bo_KAB500KR_CGB: Bo_GBU12_LGB
	{
		model = "\x\acex_ru\addons\m_veh_air_wep\KAB500KR";
		proxyShape = "\x\acex_ru\addons\m_veh_air_wep\KAB500KR";
	};
	class ACE_Bo_KAB500L_LGB: ACE_Bo_KAB500KR_CGB
	{
		model = "\x\acex_ru\addons\m_veh_air_wep\KAB-500L";
		proxyShape = "\x\acex_ru\addons\m_veh_air_wep\KAB-500L";
	};
};
//};
