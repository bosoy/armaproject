////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Tue Oct 19 13:41:22 2010 : Created on Tue Oct 19 13:41:22 2010
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class dac_source : config.bin{
class CfgPatches
{
	class DAC_Source
	{
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {};
		requiredVersion = 1.0;
	};
};
class CfgVehicleClasses
{
	class DAC_Source
	{
		displayName = "DAC";
	};
};
class CfgVehicles
{
	class Logic;
	class DAC_Source_Intern: Logic
	{
		displayName = "DAC_Intern";
		vehicleClass = "DAC_Source";
		class EventHandlers
		{
			Init = "_this execVM ""\DAC_Source\Init_Intern.sqf"" ";
		};
	};
	class DAC_Source_Extern: Logic
	{
		displayName = "DAC_Extern";
		vehicleClass = "DAC_Source";
		class EventHandlers
		{
			Init = "_this execVM ""\DAC_Source\Init_Extern.sqf"" ";
		};
	};
};
//};
