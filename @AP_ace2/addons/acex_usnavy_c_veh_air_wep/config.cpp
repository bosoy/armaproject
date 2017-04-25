////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 09 22:40:19 2012 : Created on Fri Nov 09 22:40:19 2012
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_usnavy_c_veh_air_wep : config.bin{
class CfgPatches
{
	class acex_usnavy_veh_air_wep
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"CAAir","CAWeapons","CA_Anims","CAData","acex_usnavy_main","ace_c_vehicle","ace_c_vehicle","Extended_EventHandlers","ace_sys_easa"};
		version = "1.14.0.77";
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
	class ACE_R_MK82Rack: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\mk82_rack";
	};
	class ACE_R_AGM65Rack: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\agm65_rack";
	};
	class ACE_R_AIM9Rail: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\AIM9Rail";
	};
	class ACE_R_HellfirePod: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\HellfirePod";
	};
	class ACE_R_LAU61: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\LAU61";
	};
	class ACE_R_LAU68: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\LAU68";
	};
	class ACE_R_TOW2: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\ROCKO_TOW_2Launcher";
	};
	class ACE_R_TOW4: MissileBase
	{
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\ROCKO_TOW_4Launcher";
	};
	class M_Sidewinder_AA;
	class ACE_M_Sidewinder_AA: M_Sidewinder_AA{};
	class M_Maverick_AT;
	class ACE_M_Maverick_AT: M_Maverick_AT{};
	class Bo_GBU12_LGB;
	class ACE_Bo_GBU12_LGB: Bo_GBU12_LGB{};
	class Bo_Mk82;
	class ACE_Bo_Mk82: Bo_Mk82
	{
		model = "\x\acex_usnavy\addons\m_veh_air_wep\mk82";
		proxyShape = "\x\acex_usnavy\addons\m_veh_air_wep\mk82";
	};
};
//};
