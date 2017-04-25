////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:35:16 2011 : Created on Fri Oct 21 13:35:16 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_c_static : config.bin{
class CfgPatches
{
	class acex_static
	{
		units[] = {"ACE_Fort_EnvelopeSmall_dirt"};
		weapons[] = {};
		requiredVersion = 1.56;
		requiredAddons[] = {"CAMisc3"};
		author[] = {"Sandiford"};
	};
};
class CfgVehicles
{
	class Fort_EnvelopeSmall;
	class ACE_Fort_EnvelopeSmall_dirt: Fort_EnvelopeSmall
	{
		scope = 2;
		model = "\x\acex\addons\m_static\Fort_EnvelopeSmallDirt.p3d";
		displayName = "$STR_DN_ENVELOPESMALL";
	};
};
//};
