////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Nov 18 19:11:39 2011 : Created on Fri Nov 18 19:11:39 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_sm_c_sound_wep_launcher : config.bin{
class CfgPatches
{
	class acex_sm_c_sound_wep_launcher
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"acex_sm_main","CAWeapons","CAWeapons2_RPG18","acex_sm_s_wep_launcher"};
		version = "1.12.0.99";
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class Launcher;
	class M136: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\at4_fire",2.778,1,2700};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_launcher\at4_arm",0.000316228,1,20};
	};
	class Javelin: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\javelin_fire",2.778,1,2800};
	};
	class Stinger: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\stinger_fire",2.778,1,2800};
	};
	class RPG7V: Launcher
	{
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_launcher\rpg7_reload",0.000316228,1,20};
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\rpg7_fire",2.778,1,2000};
	};
	class RPG18: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\rpg22_fire",2.778,0.9,2000};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_launcher\rpg_arm",0.000316228,1,20};
	};
	class Strela: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\stinger_fire",2.778,1,2800};
	};
	class Igla: Strela
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\stinger_fire",2.778,1,2800};
	};
	class MetisLauncher: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\dragon_fire",2.778,0.85,2800};
	};
	class GrenadeLauncher_EP1;
	class M32_EP1: GrenadeLauncher_EP1
	{
		begin1[] = {"x\acex_sm\addons\s_wep_launcher\m32_fire.wss",1,1,200};
		soundBegin[] = {"begin1",1};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_launcher\m32_reload.wss",0.0316228,1,20};
	};
	class M79_EP1: GrenadeLauncher_EP1
	{
		begin1[] = {"x\acex_sm\addons\s_wep_launcher\m79_fire.wss",1,1,200};
		soundBegin[] = {"begin1",1};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_launcher\m79_reload.wss",0.0316228,1,20};
	};
	class Mk13_EP1: GrenadeLauncher_EP1
	{
		begin1[] = {"x\acex_sm\addons\s_wep_launcher\m203_fire.wss",1,0.9,200};
		soundBegin[] = {"begin1",1};
		reloadMagazineSound[] = {"x\acex_sm\addons\s_wep_launcher\m203_reload.wss",0.0316228,1,20};
	};
	class M47Launcher_EP1: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\dragon_fire",2.778,1,2800};
	};
	class MAAWS: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\cg_fire",2.778,1,2700};
	};
	class BAF_NLAW_Launcher: Launcher
	{
		Sound[] = {"x\acex_sm\addons\s_wep_launcher\nlaw_fire",2.778,1,2700};
	};
};
//};
