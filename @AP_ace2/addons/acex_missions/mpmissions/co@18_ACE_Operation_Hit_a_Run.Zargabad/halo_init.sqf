/////////////////////////HALO////////////////////////////////
if (isDedicated) exitWith {}; 
CYBP_setVel = [];
CYBP_animHalo = [];
"CYBP_setVel" addPublicVariableEventHandler {(_this select 1) execVM "CYBP\HALO-C130\PVEHsetVel.sqf"};
"CYBP_animHalo" addPublicVariableEventHandler {(_this select 1) execVM "CYBP\HALO\PVEHanimHalo.sqf"};

[c130f, c130r] execVM "CYBP\HALO-C130\C130fly.sqf";

if (isnil "bis_fnc_init") then {createcenter sidelogic; _grp = creategroup sidelogic; _logicFnc = _grp createunit ["FunctionsManager",position player,[],0,"none"];};
WaitUntil{!(isNil "bis_fnc_init")};
BIS_fnc_halo = compile preprocessFile "CYBP\HALO\fn_halo.sqf";	// override BIS function

waitUntil {!(isNull player)};
sleep 1;
if (time > 300) exitWith {};
[player, c130f] execVM "CYBP\HALO-C130\HALO-Jump.sqf";
/////////////////////////////////////////////////////////