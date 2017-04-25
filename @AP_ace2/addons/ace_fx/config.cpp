////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 4.88
//Sun Sep 13 16:37:11 2015 : Source 'file' date Sun Sep 13 16:37:11 2015
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class F:/cfg/ace/αδ58/ace_fx/config.bin{
class CfgPatches
{
	class ace_fx
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"Extended_EventHandlers","ace_main"};
		version = "1.14.0.597";
		author[] = {"Rocko"};
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_fx
	{
		init = "call ('\x\ace\addons\fx\XEH_preInit.sqf' call SLX_XEH_COMPILE)";
		clientInit = "call ('\x\ace\addons\fx\XEH_preClientInit.sqf' call SLX_XEH_COMPILE)";
	};
};
class CfgSounds
{
	class ACE_Ring_Backblast
	{
		name = "";
		sound[] = {"\x\ace\addons\fx\sound\backblast_ring.ogg",1,1};
		titles[] = {};
		ace_fx_sound_length = 26;
	};
	class ACE_Ring_Flashbang: ACE_Ring_Backblast
	{
		sound[] = {"\x\ace\addons\fx\sound\flashbang_ring.ogg",1,1};
		ace_fx_sound_length = 20;
	};
	class ACE_Ring_Muzzleblast1: ACE_Ring_Backblast
	{
		sound[] = {"\x\ace\addons\fx\sound\muzzleblast_ring1.ogg","db+10",1};
		ace_fx_sound_length = 29;
	};
	class ACE_Ring_Muzzleblast2: ACE_Ring_Backblast
	{
		sound[] = {"\x\ace\addons\fx\sound\muzzleblast_ring2.ogg","db+4",1};
		ace_fx_sound_length = 10;
	};
	class ACE_Cough_1
	{
		name = "";
		sound[] = {"\x\ace\addons\fx\sound\coughing\cough1.ogg","db-20",1};
		titles[] = {};
	};
	class ACE_Cough_2: ACE_Cough_1
	{
		sound[] = {"\x\ace\addons\fx\sound\coughing\cough2.ogg","db-20",1};
	};
	class ACE_Cough_3: ACE_Cough_1
	{
		sound[] = {"\x\ace\addons\fx\sound\coughing\cough3.ogg","db-20",1};
	};
	class ACE_Cough_4: ACE_Cough_1
	{
		sound[] = {"\x\ace\addons\fx\sound\coughing\cough4.ogg","db-20",1};
	};
	class ACE_Cough_5: ACE_Cough_1
	{
		sound[] = {"\x\ace\addons\fx\sound\coughing\cough5.ogg","db-20",1};
	};
	class ACE_Cough_H1: ACE_Cough_1
	{
		sound[] = {"\x\ace\addons\fx\sound\coughing\heavycough1.ogg","db-20",1};
	};
	class ACE_Cough_H2: ACE_Cough_1
	{
		sound[] = {"\x\ace\addons\fx\sound\coughing\heavycough2.ogg","db-20",1};
	};
};
//};
