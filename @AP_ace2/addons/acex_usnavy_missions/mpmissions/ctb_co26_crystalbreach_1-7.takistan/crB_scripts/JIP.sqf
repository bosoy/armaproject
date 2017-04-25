//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090916
// Modified: 20100818
// Contact: http://creobellum.org
// Purpose: Setup client side objects and markers
///////////////////////////////////////////////////////////////////
if (isDedicated) exitWith{};

waitUntil{!isNull player};
waitUntil{local player};
waitUntil{!isNil "tasksPublicVariable"};

[] call compile preprocessFileLineNumbers "crB_scripts\JIPMarkers.sqf";
[] call compile preprocessFileLineNumbers "crB_scripts\JIPBriefing.sqf";
0 = [player] execVM "crB_scripts\PlayerInit.sqf";
