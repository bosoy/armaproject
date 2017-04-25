/*
File:			otfgfx_scripts.sqf
Version:		1.00
Author:		Deadfast
Description:	On-the-fly GFX Changer, main and the only script :)

Parameters:
	[
		default view distance (0 - ?),
		min view distance (0 - ?),
		max view distance (0 - ?),
		default terrain detail (1 - 5),
		min terrain detail (1 - 5),
		max terrain detail (1 - 5)
	] (all real numbers)

	All parameters are optional, if not specified otherwise default values will be used
		- Default values:
			Default VD: 1,200m
			Min VD: 500m
			Max VD: 10,000m
			Default TD: 2
			Min TD: 1
			Max TD: 5

IMPORTANT!
	* execVM ""otfgfx\otfgfx_scripts.sqf"";
		- this cannot be used, if you wish to keep the defaults simply pass on an empty array as the parameter:
				[] execVM ""otfgfx\otfgfx_scripts.sqf"";

Examples:
	* [1500, 1000, 3000, 3, 2, 5] execVM ""otfgfx\otfgfx_scripts.sqf"";

	* [1500, 1000, 3000] execVM ""otfgfx\otfgfx_scripts.sqf"";

	* [] execVM ""otfgfx\otfgfx_scripts.sqf"";


>TIP<: To open the settings dialog use:
		* [] call DFS_otfgfx_openSettings;
*/

//Default values:
DFS_otfgfx_vd_def = 2000;
DFS_otfgfx_vd_min = 500;
DFS_otfgfx_vd_max = 10000;

DFS_otfgfx_td_def = 1;
DFS_otfgfx_td_min = 1;
DFS_otfgfx_td_max = 5;

//Based on the number of parameters we're going to update the default values:
switch (count _this) do
{
	case 1:
	{
		DFS_otfgfx_vd_def = _this select 0;
	};
	case 1:
	{
		DFS_otfgfx_vd_def = _this select 0;
		DFS_otfgfx_vd_min = _this select 1;
	};
	case 3:
	{
		DFS_otfgfx_vd_def = _this select 0;
		DFS_otfgfx_vd_min = _this select 1;
		DFS_otfgfx_vd_max = _this select 2;
	};
	case 4:
	{
		DFS_otfgfx_vd_def = _this select 0;
		DFS_otfgfx_vd_min = _this select 1;
		DFS_otfgfx_vd_max = _this select 2;

		DFS_otfgfx_td_def = _this select 3;
	};
	case 5:
	{
		DFS_otfgfx_vd_def = _this select 0;
		DFS_otfgfx_vd_min = _this select 1;
		DFS_otfgfx_vd_max = _this select 2;

		DFS_otfgfx_td_def = _this select 3;
		DFS_otfgfx_td_min = _this select 4;
	};
	case 6:
	{
		DFS_otfgfx_vd_def = _this select 0;
		DFS_otfgfx_vd_min = _this select 1;
		DFS_otfgfx_vd_max = _this select 2;

		DFS_otfgfx_td_def = _this select 3;
		DFS_otfgfx_td_min = _this select 4;
		DFS_otfgfx_td_max = _this select 5;
	};
};

DFS_otfgfx_tgDetails = [50, 25, 12.5, 6.25, 3.125]; //Array with terrain grid resolutions
DFS_otfgfx_vd_cur = DFS_otfgfx_vd_def; //Declare the current VD and TD as whatever the default values are
DFS_otfgfx_td_cur = DFS_otfgfx_td_def;


setViewDistance DFS_otfgfx_vd_def; //Set the game to the default VD
setTerrainGrid (DFS_otfgfx_tgDetails select (DFS_otfgfx_td_def - 1)); //Look up the default TD in the terrain grid array and make the game use it


//Function to open the settings dialog:
DFS_otfgfx_openSettings =
{
	if (!createDialog "dfs_otfgfx_optionsDlg") exitWith //Create the dialog, if error interrupt the function
	{
		hint "Settings\n----------------------------------------\n\nError in >DFS_otfgfx_openSettings<, cannot create >dfs_otfgfx_optionsDlg< dialog!";
	};

	sliderSetRange [12, DFS_otfgfx_vd_min, DFS_otfgfx_vd_max]; //Change the slider range
	sliderSetSpeed [12, 10, 10]; //Change the speed (how many "jumps" the arrows do)
	sliderSetPosition [12, DFS_otfgfx_vd_cur]; //Set the slider position

	sliderSetRange [22, DFS_otfgfx_td_min, DFS_otfgfx_td_max];
	sliderSetSpeed [22, 1, 1];
	sliderSetPosition [22, DFS_otfgfx_td_cur];

	((findDisplay 46212) displayCtrl 11) ctrlSetStructuredText parseText format["%1/%2 m", sliderPosition 12, DFS_otfgfx_vd_max];
	((findDisplay 46212) displayCtrl 21) ctrlSetStructuredText parseText format["%1/%2", sliderPosition 22, DFS_otfgfx_td_max];
};

//UI EventHandler for slider position change (onSliderPosChanged):
DFS_otfgfx_sliderChange =
{
	//By default the dragging the slider gets us into negative values, let's prevent it:
	sliderSetPosition [12, round (sliderPosition 12)];
	sliderSetPosition [22, round (sliderPosition 22)];

	//Update the displayed texts:
	((findDisplay 46212) displayCtrl 11) ctrlSetStructuredText parseText format["%1/%2 m", sliderPosition 12, DFS_otfgfx_vd_max];
	((findDisplay 46212) displayCtrl 21) ctrlSetStructuredText parseText format["%1/%2", sliderPosition 22, DFS_otfgfx_td_max];
};

//Function executed on pressing the Commit! button:
DFS_otfgfx_commit =
{
	private ["_td", "_vd"];

	hintSilent parseText "<t size='1.4' color='#ffcc00' align='center'>Loading...</t>";
	sleep 0.01;

	_vd = _this select 0;
	_td = _this select 1;

	DFS_otfgfx_vd_cur = _vd; //Update the  current VD and TD
	DFS_otfgfx_td_cur = _td;

	setViewDistance _vd; //Make the game use the selected VD
	setTerrainGrid (DFS_otfgfx_tgDetails select (_td - 1)); //Look up the terrain grid in the array and make the game use it

	//A bit of a funky hint:
	hint parseText format ["<t font='Zeppelin33'><t size='1.4' color='#ffcc00' align='center'>Graphic settings updated!</t><br/><br/>View distance:</t> %1 m<br/><t font='Zeppelin33'>Terrain detail:</t> level %2", _vd, _td]
};
