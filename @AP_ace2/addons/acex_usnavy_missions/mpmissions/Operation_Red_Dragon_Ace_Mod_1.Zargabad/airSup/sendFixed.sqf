_man = _this select 1;
_arg = _this select 3;
_type = _arg select 0;

_man removeaction asf1;
_man removeaction asf2;
_man removeaction asf3;
_man removeaction asf4;
_man removeaction asf5;
_man removeaction asf6;
_man removeaction asf7;

if(_type == "exit")exitwith{as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"]};

switch (_type) do {
	case "jdam": {
		if (ASJDA == ASnumJDA) then {
			as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
			_man groupChat localize "STR_NOMORE";
			kill1 = true;
		};
	};
	case "lgb": {
		if (ASLGB == ASnumLGB) then {
			as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
			_man groupChat localize "STR_NOMORE";
			kill2 = true;
		};
	};
	case "cbuAP": {
		if (ASCAP == ASnumCAP) then {
			as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
			_man groupChat localize "STR_NOMORE";
			kill3 = true;
		};
	};
	case "cbuAT": {
		if (ASCAT == ASnumCAT) then {
			as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
			_man groupChat localize "STR_NOMORE";
			kill4 = true;
		};
	};
	case "cbumine": {
		if (ASCBM == ASnumCBM) then {
			as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
			_man groupChat localize "STR_NOMORE";
			kill7 = true;
		};
	};
	case "cas": {
		if (ASCAS == ASnumCAS) then {
			as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"];
			_man groupChat localize "STR_NOMORE";
			kill6 = true;
		};
	};
};

if(kill1)exitwith{jdam = false};
if(kill2)exitwith{lgb = false};
if(kill3)exitwith{cbuap = false};
if(kill4)exitwith{cbuat = false};
if(kill6)exitwith{cas = false};
if(kill7)exitwith{cbumine = false};

_man groupChat localize "STR_MAPSEL";
_asloc = createMarkerLocal ["asloc", [0,0,0]];
_asloc setMarkerShapeLocal "ICON";
"asloc" setMarkerTypeLocal "hd_destroy";
onMapSingleClick "'asloc' setMarkerPosLocal _pos,ASclick = true";
waitUntil {ASclick};
onMapSingleClick "";
ASclick = false;

IPfixedAS = true;
_grp = createGroup side _man;
_spwn = getPos ASpad;
_spwndir = getDir ASpad;

_marker = createMarkerLocal ["aircraftmarker", position ASpad];
_marker setMarkerShapeLocal "ICON";
"aircraftmarker" setMarkerTypeLocal "b_plane";
_asloc = getMarkerPos "asloc";
if (side _man == EAST) then {
	"aircraftmarker" setMarkerColorLocal "ColorRed";
};

if (_type == "cas") then {
	airSupPlane = airSupFXDCAS;
}
else
{
	airSupPlane = airSupFXD;
};

_plane = createVehicle [airSupPlane, _spwn, [], 0, "FLY"];
_plane setpos [_spwn select 0,_spwn select 1,(_spwn select 2)+200];
_plane setdir _spwndir;
_plane setVelocity [sin(_spwndir)*200,cos(_spwndir)*200,0];
_pilot = _grp createUnit [airSupPIL, _spwn, [], 0, "FORM"];
_pilot moveinDriver _plane;
_plane flyInheight 200;

if (!(_type == "cas")) then {
	{_plane removemagazine _x;} forEach magazines _plane;
};

[_plane] spawn {
	_plane = _this select 0;
	while{IPfixedAS} do {
		"aircraftmarker" setMarkerPosLocal getPos _plane;
		sleep 1;
	};
	if(true)exitWith{deletemarker "aircraftmarker"};
};

fwp1=_grp addWaypoint [_asloc, 0];
fwp1 setWaypointStatements ["true", ""];
fwp1 setWaypointType "MOVE";
fwp1 setWaypointSpeed "NORMAL";
fwp1 setWaypointCombatMode "BLUE";
fwp1 setWaypointCompletionRadius 30;
_grp setcurrentWaypoint fwp1;
fwp2=_grp addWaypoint [_spwn, 0];
fwp2 setWaypointType "MOVE";
fwp2 setWaypointStatements ["true", "IPfixedAS = false;"];
fwp2 setWaypointSpeed "NORMAL";
fwp2 setWaypointCombatMode "BLUE";
fwp2 setWaypointCompletionRadius 50;


_lockobj = "HeliHEmpty" createVehicle _asloc;
_lock = getPosASL _lockobj select 2;
deleteVehicle _lockobj;

nofricgrav =
{
	_b = _this select 0;
	_vx = _this select 1;
	_vy = _this select 2;
	_vz = 0;
	while {!isNull _b} do {
		_b setVelocity [_vx,_vy,_vz];
		_vz = _vz - 9.8*0.3;
		sleep 0.27;
	};
	if(true)exitWith{};
};

switch (_type) do
{
	case "jdam":{
		ASJDA = ASJDA + 1;
		_man groupChat localize "STR_FIXDJDA";
		while {true} do {
			if (((((getPos _plane select 0) - (_asloc select 0))^2+((getPos _plane select 1) - (_asloc select 1))^2)^0.5) <= 500)exitwith{};
			if(!alive _plane)exitwith{};
			sleep 0.5;
		};
		if (alive _plane) then {
			_b1 = "Bo_Mk82" createvehicle [getPos _plane select 0,getPos _plane select 1,(getPos _plane select 2)-10];
			_b1 setDir ((_asloc select 0)-(getPos _b1 select 0)) atan2 ((_asloc select 1)-(getPos _b1 select 1));
			_bombfall = sqrt(((getPosASL _b1 select 2)-_lock)/4.9);
			_bombvelx = ((_asloc select 0)-(getPos _b1 select 0))/_bombfall;
			_bombvely = ((_asloc select 1)-(getPos _b1 select 1))/_bombfall;
			[_b1,_bombvelx,_bombvely] spawn nofricgrav;
		};
	};
	case "lgb":{
		ASLGB = ASLGB + 1;
		_man groupChat localize "STR_FIXDLGB";
		fwp1 setWaypointCombatMode "RED";
		fwp2 setWaypointCombatMode "RED";
		_plane addWeapon "BombLauncherF35";
		_plane addMagazine "2Rnd_GBU12";
	};
	case "cbuAP":{
		_man groupChat localize "STR_FIXDCAP";
		while {true} do {
			if (((((getPos _plane select 0) - (_asloc select 0))^2+((getPos _plane select 1) - (_asloc select 1))^2)^0.5) <= 500)exitwith{};
			if(!alive _plane)exitwith{};
			sleep 0.5;
		};
		if (alive _plane) then {
			_cbu = "Bo_Mk82" createvehicle [getPos _plane select 0,getPos _plane select 1,(getPos _plane select 2)-10];
			_cbu setDir ((_asloc select 0)-(getPos _cbu select 0)) atan2 ((_asloc select 1)-(getPos _cbu select 1));
			_bombfall = sqrt((((getPosASL _cbu select 2)-60)-_lock)/4.9);
			_bombvelx = ((_asloc select 0)-(getPos _cbu select 0))/_bombfall;
			_bombvely = ((_asloc select 1)-(getPos _cbu select 1))/_bombfall;
			[_cbu,_bombvelx,_bombvely] spawn nofricgrav;
			waitUntil{getPos _cbu select 2 <= 60};
			_charge = "Arty_Sadarm_Burst" createvehicle getPos _cbu;
			deleteVehicle _cbu;
			_FLAR1 = "f_40MM_GREEN" createvehicle getpos _cbu;
			_FLAR1 setVelocity [0,5,0];
			for [{_n = 0},{_n <= 25},{_n = _n+1}] do {
				_blets1 = "g_30mm_he" createvehicle getPos _cbu;
				_blets1 setVelocity [(random 15),(random 15),-(random 15)];
			};
			for [{_n = 0},{_n <= 25},{_n = _n+1}] do {
				_blets2 = "g_30mm_he" createvehicle getPos _cbu;
				_blets2 setVelocity [-(random 15),(random 15),-(random 15)];
			};
			for [{_n = 0},{_n <= 25},{_n = _n+1}] do {
				_blets3 = "g_30mm_he" createvehicle getPos _cbu;
				_blets3 setVelocity [(random 15),-(random 15),-(random 15)];
			};
			for [{_n = 0},{_n <= 25},{_n = _n+1}] do {
				_blets4 = "g_30mm_he" createvehicle getPos _cbu;
				_blets4 setVelocity [-(random 15),-(random 15),-(random 15)];
			};
		};
		ASCAP = ASCAP + 1;
	};
	case "cbuAT":{
		ASCAT = ASCAT + 1;
		_man groupChat localize "STR_FIXDCAT";
		while {true} do {
			if (((((getPos _plane select 0) - (_asloc select 0))^2+((getPos _plane select 1) - (_asloc select 1))^2)^0.5) <= 500)exitwith{};
			if(!alive _plane)exitwith{};
			sleep 0.5;
		};
		if (alive _plane) then {
			_cbu = "Bo_Mk82" createvehicle [getPos _plane select 0,getPos _plane select 1,(getPos _plane select 2)-10];
			_cbu setDir ((_asloc select 0)-(getPos _cbu select 0)) atan2 ((_asloc select 1)-(getPos _cbu select 1));
			_bombfall = sqrt((((getPosASL _cbu select 2)-60)-_lock)/4.9);
			_bombvelx = ((_asloc select 0)-(getPos _cbu select 0))/_bombfall;
			_bombvely = ((_asloc select 1)-(getPos _cbu select 1))/_bombfall;
			[_cbu,_bombvelx,_bombvely] spawn nofricgrav;
			waitUntil{getPos _cbu select 2 <= 60};
			_pos = getPos _cbu;
			_charge = "Arty_Sadarm_Burst" createvehicle _pos;
			deleteVehicle _cbu;
			_tar = nearestObjects [_pos,["Car","Tank"],150];
			_FLAR1 = "f_40MM_GREEN" createvehicle _pos;
			_FLAR1 setVelocity [0,5,0];
			_tarpos = [];
			{_tarpos = _tarpos + [getPos _x]} forEach _tar;
			while{count _tarpos <= 5} do {
				_tarpos = _tarpos + [[(_pos select 0)-75+(random 150),(_pos select 1)-75+(random 150),(_pos select 2)-70]];
			};
			for [{_n = 0},{_n <= 5},{_n = _n+1}] do {
				_ntar = _tarpos select _n;
				_blets = "ARTY_SADARM_PROJO" createvehicle _ntar;
				sleep 0.5;
			};
		};
	};
	case "cbumine":{
		ASCBM = ASCBM + 1;
		_man groupChat localize "STR_FIXDCBM";
		while {true} do {
			if (((((getPos _plane select 0) - (_asloc select 0))^2+((getPos _plane select 1) - (_asloc select 1))^2)^0.5) <= 500)exitwith{};
			if(!alive _plane)exitwith{};
			sleep 0.5;
		};
		if (alive _plane) then {
			_cbu = "Bo_Mk82" createvehicle [getPos _plane select 0,getPos _plane select 1,(getPos _plane select 2)-10];
			_cbu setDir ((_asloc select 0)-(getPos _cbu select 0)) atan2 ((_asloc select 1)-(getPos _cbu select 1));
			_bombfall = sqrt((((getPosASL _cbu select 2)-60)-_lock)/4.9);
			_bombvelx = ((_asloc select 0)-(getPos _cbu select 0))/_bombfall;
			_bombvely = ((_asloc select 1)-(getPos _cbu select 1))/_bombfall;
			[_cbu,_bombvelx,_bombvely] spawn nofricgrav;
			waitUntil{getPos _cbu select 2 <= 60};
			_pos = getPos _cbu;
			_charge = "Arty_Sadarm_Burst" createvehicle _pos;
			deleteVehicle _cbu;
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets1 = "B_556x45_Ball" createvehicle _pos;
				_blets1 setVelocity [(random 15),(random 15),-(random 15)];
			};
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets2 = "B_556x45_Ball" createvehicle _pos;
				_blets2 setVelocity [-(random 15),(random 15),-(random 15)];
			};
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets3 = "B_556x45_Ball" createvehicle _pos;
				_blets3 setVelocity [(random 15),-(random 15),-(random 15)];
			};
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets4 = "B_556x45_Ball" createvehicle _pos;
				_blets4 setVelocity [-(random 15),-(random 15),-(random 15)];
			};
			sleep 2;
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets1 = "Mine" createvehicle [(_pos select 0)-50+(random 100),(_pos select 1)-50+(random 100),0];
			};
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets2 = "Mine" createvehicle [(_pos select 0)-50+(random 100),(_pos select 1)-50+(random 100),0];
			};
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets3 = "Mine" createvehicle [(_pos select 0)-50+(random 100),(_pos select 1)-50+(random 100),0];
			};
			for [{_n = 0},{_n <= 10},{_n = _n+1}] do {
				_blets4 = "Mine" createvehicle [(_pos select 0)-50+(random 100),(_pos select 1)-50+(random 100),0];
			};
		};
	};
	case "cas":{
		ASCAS = ASCAS + 1;
		_man groupChat localize "STR_FIXDCAS";
		fwp1 setWaypointCombatMode "RED";
		fwp1 setWaypointType "SAD";
		while {true} do {
			if (((((getPos _plane select 0) - (_asloc select 0))^2+((getPos _plane select 1) - (_asloc select 1))^2)^0.5) <= 100)exitwith{};
			if(!alive _plane)exitwith{};
			sleep 0.5;
		};
		[_grp,_plane,_pilot] spawn {
			_grp = _this select 0;
			_plane = _this select 1;
			_pilot = _this select 2;
			sleep 220;
			if(!alive _plane)exitwith{};
			{_plane removemagazine _x;} forEach magazines _plane;
			removeAllweapons _plane;
			_pilot dowatch objnull;
			_grp setcurrentWaypoint fwp2;
			if(true)exitwith{};
		};
	};
};

waitUntil{(!IPfixedAS) or (!alive _plane)};
if(!IPfixedAS)then{_man groupChat localize "STR_FIXDDON";}else{_man groupChat localize "STR_FIXDDIE";};
IPfixedAS = false;
if(alive _pilot)then{deleteVehicle _pilot};
deleteMarkerLocal "asloc";
deleteWaypoint fwp1;
deleteWaypoint fwp2;

if(true)exitWith{as0 = _man addAction [localize "STR_MENUASM","airSup\addMenu.sqf",[], 5, false, false, "", "_target == player"]};