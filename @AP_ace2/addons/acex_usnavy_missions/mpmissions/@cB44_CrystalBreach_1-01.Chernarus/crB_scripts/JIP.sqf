//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]
// Created: 20090916
// Contact: http://creobellum.org
// Purpose: Setup client side objects and markers
///////////////////////////////////////////////////////////////////
waitUntil{!isNull player};
_unit = _this select 0;

waitUntil{!isNil "tasksPublicVariable"};

_nulm = [] execVM "crb_scripts\JIPMarkers.sqf";
waitUntil{scriptDone _nulm;};

_nulb = [] execVM "crb_scripts\JIPBriefing.sqf";
waitUntil{scriptDone _nulb;};

call {[player] execVM "crb_scripts\PlayerInit.sqf"};

