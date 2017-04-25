////////////////////////////////////////////////////////////////////
//DeRap: Produced from mikero's Dos Tools Dll version 5.24
//Produced on Fri Oct 21 13:55:07 2011 : Created on Fri Oct 21 13:55:07 2011
//http://dev-heaven.net/projects/list_files/mikero-pbodll
////////////////////////////////////////////////////////////////////

#define _ARMA_

//Class acex_ru_c_ui : config.bin{
class CfgPatches
{
	class acex_ru_c_ui
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.54;
		requiredAddons[] = {"ace_c_ui","Utes","Chernarus"};
	};
};
class CfgWorlds
{
	class DefaultWorld;
	class CAWorld: DefaultWorld
	{
		class Grid{};
	};
	class Chernarus: CAWorld
	{
		class Grid: Grid
		{
			offsetY = 15360;
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.075;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
	class utes: CAWorld
	{
		class Grid: Grid
		{
			offsetY = 5120;
			class Zoom1
			{
				zoomMax = 0.0001;
				format = "XY";
				formatX = "0000";
				formatY = "0000";
				stepX = 10;
				stepY = -10;
			};
			class Zoom2
			{
				zoomMax = 0.3;
				format = "XY";
				formatX = "000";
				formatY = "000";
				stepX = 100;
				stepY = -100;
			};
			class Zoom3
			{
				zoomMax = 1;
				format = "XY";
				formatX = "00";
				formatY = "00";
				stepX = 1000;
				stepY = -1000;
			};
		};
	};
};
//};
