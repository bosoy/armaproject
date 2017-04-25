if (!isServer) exitWith{};

nul0 = ["loc_citycenter",1800] execVM "OBJ_antiair1.sqf";
nul0 = ["loc_citycenter",1800] execVM "OBJ_antiair2.sqf";
nul0 = ["loc_citycenter",1800] execVM "OBJ_antiair3.sqf";
nul0 = ["loc_citycenter",1800] execVM "OBJ_antiair4.sqf";
nul0 = ["loc_citycenter",1800] execVM "OBJ_supplies.sqf";
nul0 = ["loc_citycenter",1800] execVM "OBJ_officer.sqf";
nul0 = ["loc_citycenter",1800] execVM "OBJ_radiotower.sqf";
nul0 = [] execVM "OBJ_airport.sqf";

// Debug
if (!isMultiplayer) then {
  sleep 1;
  player globalChat "INIT_OBJ COMPLETED";
  sleep 1;
};

if (true) exitWith {};