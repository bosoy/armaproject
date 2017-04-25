////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Mon Oct 14 23:08:19 2013 : Created on Mon Oct 14 23:08:19 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_sight_adjustment_at : config.bin{
class CfgPatches
{
	class ace_sys_sight_adjustment_at
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","Extended_EventHandlers","ace_main","ace_c_weapon","ace_sys_rocket_ballistics"};
		version = "1.14.0.597";
	};
};
class CfgWeapons
{
	class Launcher;
	class RPG7V: Launcher
	{
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_minrange = 200;
		ace_sa_maxrange = 500;
		ace_sa_steprange = 100;
		ace_sa_table_elev[] = {{0,0},{200,27},{300,33.8},{400,40.4},{500,50.6}};
	};
	class ACE_RPG7V_PGO7: RPG7V
	{
		ace_sa_enabled = 1;
	};
	class RPG18: Launcher
	{
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_minrange = 50;
		ace_sa_maxrange = 250;
		ace_sa_steprange = 100;
		ace_sa_table_elev[] = {{0,0},{50,13.6},{150,40.2},{250,69.5}};
	};
	class M136: Launcher
	{
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 500;
		ace_sa_steprange = 50;
		ace_sa_table_elev[] = {{0,0},{100,5.9},{150,9.3},{200,11.6},{250,14.9},{300,20},{350,23.9},{400,27.4},{450,31.4},{500,35.9}};
	};
	class SMAW: Launcher
	{
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 500;
		ace_sa_steprange = 50;
		ace_sa_table_elev[] = {{0,0},{100,4.5},{150,7.1},{200,9.7},{250,12.4},{300,15.2},{350,18.2},{400,21.2},{450,24.3},{500,27.5}};
	};
	class MAAWS: Launcher
	{
		ace_sa_enabled = 1;
		ace_sa_defaultelevation = 0;
		ace_sa_minrange = 100;
		ace_sa_maxrange = 1200;
		ace_sa_steprange = 100;
		ace_sa_table_elev[] = {{0,0},{100,4.5},{150,7.1},{200,9.7},{250,12.4},{300,15.2},{350,18.2},{400,21.2},{450,24.3},{500,27.5}};
	};
};
class cfgMagazines
{
	class CA_LauncherMagazine;
	class PG7V: CA_LauncherMagazine
	{
		ace_sa_table_elev[] = {{0,0},{100,18.3},{200,26.4},{300,33.3},{400,41.05},{500,50.7},{600,62.7},{700,78.05}};
	};
	class ACE_PG7VM: PG7V
	{
		ace_sa_table_elev[] = {{0,0},{100,18.3},{200,26.4},{300,33.3},{400,41.05},{500,50.7},{600,62.7},{700,78.05}};
	};
	class PG7VL: PG7V
	{
		ace_sa_table_elev[] = {{0,0},{100,24.25},{200,36.2},{300,50.1},{400,66.75},{500,86.3},{600,111.75}};
	};
	class PG7VR: PG7V
	{
		ace_sa_table_elev[] = {{0,0},{50,30},{100,55.2},{150,79.1},{200,106.2},{250,136},{300,171},{350,212.9}};
	};
	class ACE_TBG7V: PG7VR
	{
		ace_sa_table_elev[] = {{0,0},{50,30},{100,55.2},{150,79.1},{200,106.2},{250,136},{300,171},{350,212.9}};
	};
	class OG7: CA_LauncherMagazine
	{
		ace_sa_table_elev[] = {{0,0},{100,24.15},{200,50},{300,76.3},{400,102.4},{500,130.9},{600,158.8}};
	};
	class MAAWS_HEDP: CA_LauncherMagazine
	{
		ace_sa_table_elev[] = {{0,0},{100,9},{200,18.4},{300,28.7},{400,38.5},{500,49},{600,60.4},{700,70.9},{800,82.3},{900,94.05}};
	};
	class ACE_MAAWS_HE: MAAWS_HEDP
	{
		ace_sa_table_elev[] = {{0,0},{100,8.6},{200,17.35},{300,26.25},{400,35.9},{500,45.1},{600,55.05},{700,65.1},{800,75.8},{900,86.4},{1000,97.3},{1100,109.05},{1200,120.75}};
	};
	class MAAWS_HEAT: MAAWS_HEDP
	{
		ace_sa_table_elev[] = {{0,0},{100,6.05},{200,10.7},{300,15.6},{400,19.55},{500,24.5},{600,29.6},{700,35.2},{800,41},{900,47.75}};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_sys_sight_adjustment_at
	{
		clientInit = "call ('\x\ace\addons\sys_sight_adjustment_at\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
//};
