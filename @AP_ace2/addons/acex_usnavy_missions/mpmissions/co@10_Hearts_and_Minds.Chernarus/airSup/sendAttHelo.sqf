_man = _this select 1;
_id = _this select 2;

_man removeAction asf1;
_man removeAction asf2;
_man removeAction asf5;

ASHEL = ASHEL + 1;

if (ASHEL == ASnumHEL) then {
	as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
	[West,"HQ"] sideChat localize "STR_NOMORE";
	playSound "beep";
	playSound "radionoise2";
	kill5 = true;
};
if(kill5)exitwith{helo = false;};

[West,"HQ"] sideChat localize "STR_MAPSEL";
_asloc = createMarkerLocal ["asloc", [0,0,0]];
_asloc setMarkerShapeLocal "ICON";
"asloc" setMarkerTypeLocal "hd_destroy";
onMapSingleClick "'asloc' setMarkerPosLocal _pos,ASclick = true";
waitUntil {ASclick};
onMapSingleClick "";
ASclick = false;

_asloc = getMarkerPos "asloc";
_spwn = getPos ASpad;
_spwndir = getDir ASpad;
_grp1 = creategroup side _man;
_grp2 = creategroup side _man;

IPheloAS = true;

_marker = createMarkerLocal ["aircraftmarker1", position ASpad];
_marker setMarkerShapeLocal "ICON";
"aircraftmarker1" setMarkerTypeLocal "b_air";
_marker = createMarkerLocal ["aircraftmarker2", position ASpad];
_marker setMarkerShapeLocal "ICON";
"aircraftmarker2" setMarkerTypeLocal "b_air";

_spwn1 = [(_spwn select 0) - 30,(_spwn select 1) + 30,_spwn select 2];
_spwn2 = [(_spwn select 0) + 30,(_spwn select 1) - 30,_spwn select 2];

_AShelo1 = createVehicle [airSupROT, _spwn1, [], 0, "FLY"];
_AShelo1 setdir _spwndir;
_AShelo2 = createVehicle [airSupROT, _spwn2, [], 0, "FLY"];
_AShelo2 setdir _spwndir;

_pilot1 = _grp1 createUnit [airSupPIL, _spwn, [], 0, "FORM"];
_pilot2 = _grp1 createUnit [airSupPIL, _spwn, [], 0, "FORM"];
_pilot1 moveindriver _AShelo1;
_pilot2 moveingunner _AShelo1;
_pilot3 = _grp2 createUnit [airSupPIL, _spwn, [], 0, "FORM"];
_pilot4 = _grp2 createUnit [airSupPIL, _spwn, [], 0, "FORM"];
_pilot3 moveindriver _AShelo2;
_pilot4 moveingunner _AShelo2;

[_AShelo1,_AShelo2] spawn {
	_AShelo1 = _this select 0;
	_AShelo2 = _this select 1;	
	while{IPheloAS} do {
		"aircraftmarker1" setMarkerPosLocal getPos _AShelo1;
		"aircraftmarker2" setMarkerPosLocal getPos _AShelo2;
		sleep 1;
	};
	if(true)exitWith{deletemarker "aircraftmarker1";deletemarker "aircraftmarker2";};
};

[_AShelo1,_AShelo2] spawn {	
	_AShelo1 = _this select 0;
	_AShelo2 = _this select 1;
	while{IPheloAS} do {
		if(getPosATL _AShelo1 select 2 <= 1)then{_AShelo1 setdamage 1;};
		if(getPosATL _AShelo2 select 2 <= 1)then{_AShelo2 setdamage 1;};
	};
	if(true)exitWith{};
};

[West,"HQ"] sideChat localize "STR_HELOINC";
playSound "beep";
playSound "radionoise2";

g1wp1=_grp1 addWaypoint [_asloc, 75];
g1wp1 setWaypointBehaviour "COMBAT";
g1wp1 setWaypointStatements  ["true",""];
g1wp1 setWaypointType "SAD";
g1wp1 setWaypointTimeout [30, 30, 30];
g1wp2=_grp1 addWaypoint [_spwn, 0];
g1wp2 setWaypointType "MOVE";
g1wp2 setWaypointStatements ["true", "IPheloAS = false;"];
g2wp1=_grp2 addWaypoint [_asloc, 75];
g2wp1 setWaypointBehaviour "COMBAT";
g2wp1 setWaypointStatements  ["true",""];
g2wp1 setWaypointType "SAD";
g2wp1 setWaypointTimeout [30, 30, 30];
g2wp2=_grp2 addWaypoint [_spwn, 0];
g2wp2 setWaypointType "MOVE";
g2wp2 setWaypointStatements ["true", "IPheloAS = false;"];

[_pilot2,_pilot4,_grp1,_grp2] spawn {	
	_pilot2 = _this select 0;
	_pilot4 = _this select 1;
	_grp1 = _this select 2;
	_grp2 = _this select 3;
	while{IPheloAS} do {
		if(!alive _pilot2)then{_grp1 setCurrentWaypoint g1wp2};
		if(!alive _pilot4)then{_grp2 setCurrentWaypoint g2wp2};
	};
	if(true)exitWith{};
};

waitUntil{(!IPheloAS) or ((!alive _AShelo1) and (!alive _AShelo2))};
if(!IPheloAS)then{[West,"HQ"] sideChat localize "STR_HELODON"; playSound "beep"; playSound "radionoise2";}else{[West,"HQ"] sideChat localize "STR_HELODIE"; playSound "beep"; playSound "radionoise2";};
if((!IPheloAS) and (alive _AShelo1))then{deleteVehicle _AShelo1;};
if((!IPheloAS) and (alive _AShelo2))then{deleteVehicle _AShelo2;};

IPheloAS = false;
if(alive _pilot1)then{deleteVehicle _pilot1};
if(alive _pilot2)then{deleteVehicle _pilot2};
if(alive _pilot3)then{deleteVehicle _pilot3};
if(alive _pilot4)then{deleteVehicle _pilot4};
deleteMarkerLocal "asloc";

if(true)exitwith{as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];};