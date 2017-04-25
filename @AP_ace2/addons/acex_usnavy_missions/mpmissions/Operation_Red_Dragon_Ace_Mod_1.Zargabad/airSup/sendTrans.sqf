_man = _this select 1;
_id = _this select 2;

_man removeAction asf1;
_man removeAction asf2;
_man removeAction asf5;

if (ASHEL == ASnumHEL) then {
	as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
	_man groupChat localize "STR_NOMORE";
	kill8 = true;
};
if(kill8)exitwith{trans = false;};

ASTRN = ASTRN + 1;

// from here

_man groupChat localize "STR_MAPPIK";
_asloc = createMarkerLocal ["asloc", [0,0,0]];
_asloc setMarkerShapeLocal "ICON";
_asloc setMarkerColorLocal "ColorGreen";
"asloc" setMarkerTypeLocal "hd_pickup";
onMapSingleClick "'asloc' setMarkerPosLocal _pos,ASclick = true";
waitUntil {ASclick};
onMapSingleClick "";
ASclick = false;

// to here

_man groupChat localize "STR_MAPDRO";
_asloc2 = createMarkerLocal ["asloc2", [0,0,0]];
_asloc2 setMarkerShapeLocal "ICON";
_asloc2 setMarkerColorLocal "ColorGreen";
"asloc2" setMarkerTypeLocal "hd_end";
onMapSingleClick "'asloc2' setMarkerPosLocal _pos,ASclick = true";
waitUntil {ASclick};
onMapSingleClick "";
ASclick = false;

_asloc = getMarkerPos "asloc";
_asloc2 = getMarkerPos "asloc2";

_spwn = getPos ASpad;
_spwndir = getDir ASpad;
_grp1 = creategroup side _man;

IPheloAS = true;

_marker = createMarkerLocal ["aircraftmarker1", position ASpad];
_marker setMarkerShapeLocal "ICON";
"aircraftmarker1" setMarkerTypeLocal "b_air";

_spwn1 = [(_spwn select 0) - 30,(_spwn select 1) + 30,_spwn select 2];

_AShelo1 = createVehicle [airSupTRN, _spwn1, [], 0, "FLY"];
_AShelo1 setdir _spwndir;

_pilot1 = _grp1 createUnit [airSupPIL, _spwn, [], 0, "FORM"];
_pilot2 = _grp1 createUnit [airSupPIL, _spwn, [], 0, "FORM"];

_pilot1 moveindriver _AShelo1;
_pilot2 moveincargo _AShelo1;

_lz1 = "HeliHEmpty" createVehicle _asloc;
_lz2 = "HeliHEmpty" createVehicle _asloc2;

[_AShelo1] spawn {
	_AShelo1 = _this select 0;
	while{IPheloAS} do {
		"aircraftmarker1" setMarkerPosLocal getPos _AShelo1;
		sleep 1;
	};
	if(true)exitWith{deletemarker "aircraftmarker1";};
};

[_AShelo1] spawn {
	_AShelo1 = _this select 0;
	while{IPheloAS} do {
		if !(isEngineOn _AShelo1)then{_AShelo1 setdamage 1;};
	};
	if(true)exitWith{};
};

[_AShelo1] spawn {
	_AShelo1 = _this select 0;
	while{true} do {
		if (!alive _AShelo1) then {IPheloAS = false}
	};
	if(true)exitWith{};
};

_man groupChat localize "STR_TRANINC";

landed = false;
takeoff = false;

g1wp1=_grp1 addWaypoint [_asloc, 75];
g1wp1 setWaypointBehaviour "COMBAT";
g1wp1 setWaypointType "LOAD";
[_grp1, 1] setWaypointStatements ["true", "landed = true"];
_AShelo1 addAction [localize "STR_GTGPIL","airSup\takeOff.sqf"];
waituntil {(!IPheloAS) or (landed)};
_AShelo1 land "get in";
waituntil {(!IPheloAS) or (!alive _man) or (takeoff)};

landed = false;

g1wp2=_grp1 addWaypoint [_asloc2, 75];
g1wp2 setWaypointBehaviour "COMBAT";
g1wp2 setWaypointType "LOAD";
[_grp1, 2] setWaypointStatements ["true", "landed = true"];
waituntil {(!IPheloAS) or landed};
_AShelo1 land "get out";
waituntil {(!IPheloAS) or (0 >= count ((crew _AShelo1)-[_pilot1,_pilot2]))};

g1wp3=_grp1 addWaypoint [_spwn, 0];
g1wp3 setWaypointType "MOVE";
g1wp3 setWaypointStatements ["true", "IPheloAS = false;"];

waitUntil{(!IPheloAS) or (!alive _AShelo1)};
if(!IPheloAS)then{_man groupChat localize "STR_HELODON";}else{_man groupChat localize "STR_HELODIE";};
if(alive _AShelo1)then{deleteVehicle _AShelo1;};

IPheloAS = false;
if(alive _pilot1)then{deleteVehicle _pilot1};
if(alive _pilot2)then{deleteVehicle _pilot2};
deleteMarkerLocal "asloc";
deleteMarkerLocal "asloc2";
deleteVehicle _lz1;
deleteVehicle _lz2;

landed = false;

if(true)exitwith{as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];};