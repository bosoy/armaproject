////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Sat Apr 06 11:44:16 2013 : Created on Sat Apr 06 11:44:16 2013
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class ace_sys_attachments : config.bin{
class CfgPatches
{
	class ace_sys_attachments
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {"CAWeapons","CAWeapons2","ace_main","ace_sys_interaction"};
		version = "1.14.0.590";
		author[] = {"Sickboy"};
	};
};
class CfgSettings
{
	class ace
	{
		class sys_attachments
		{
			class Weapons
			{
				class Default
				{
					ACE_ATTACH_AVAILABLE[] = {};
				};
			};
		};
	};
};
class CfgWeapons
{
	class Rifle;
};
//};
