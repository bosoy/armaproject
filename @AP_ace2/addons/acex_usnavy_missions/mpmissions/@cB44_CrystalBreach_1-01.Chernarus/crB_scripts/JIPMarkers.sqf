//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090916
// Contact: http://creobellum.org
// Purpose: Setup client side markers
///////////////////////////////////////////////////////////////////

if(isDedicated) exitWith{};

call{["Mines","Mines_1","Mines_2","Mines_3","Mines_4"] execVM "crb_scripts\crB_MineFields.sqf";};

waitUntil{typeName erb_array == "ARRAY"};
{
	_mkRB = createMarkerLocal [str _x, position _x];
	_mkRB setMarkerTextLocal "Roadblock";
	_mkRB setMarkerTypeLocal "Strongpoint";
	_mkRB setMarkerColorLocal "ColorRed";
} forEach erb_array;
