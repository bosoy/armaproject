//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: (AEF)Wolffy.au [2CAV]/(AEF)Odin [2CAV]
// Modified by: (AEF)Odin 2010/01/04
// Created: 20090819
// Contact: http://creobellum.org
// Purpose: Create function to randomly spawn OPFOR groups
// Parameter: position to spawn group
// Parameter: type = Infantry/Motorized/Mechanized/Armored/Air
// Parameter: (optional)single side e.g. east
//   OR	single faction = USMC,RU,INS,GUE,etc e.g. "INS"
//   OR	multiple factions = USMC,RU,INS,GUE,etc e.g. ["RU","INS"]
///////////////////////////////////////////////////////////////////
if(!isServer) exitWith{};
private["_pos","_type","_fac","_facs","_sidex","_side","_grpx","_grps","_grp","_radius"];

_pos = _this select 0;
_type = _this select 1;
_fac = nil;
// setup default param
if (count _this > 2) then { _fac = _this select 2; };
if (isNil "_fac") then { _fac = east; };
//hint str _fac;

// init BIS funcs
waitUntil {!isNil "bis_fnc_init"};

_facs = [];
_side = nil;
// get all factions
_allfacs = [] call BIS_fnc_getFactions;
//hint str _allfacs;
// if default or selection by side
if(typeName _fac == "ANY" || typeName _fac == "SIDE") then {
	if(typeName _fac == "SIDE") then {
		_side = _fac;
		_fac = nil;
	};
	switch(_side) do {
		case east: {
			_sidex = 0;
		};
		case west: {
			_sidex = 1;
		};
		case resistance: {
			_sidex = 2;
		};
		case civilian: {
			_sidex = 3;
		};
	};

	{
		_fx = getNumber(configFile >> "CfgFactionClasses" >> _x >> "side");
		if (_fx == _sidex) then {
			_facs = _facs + [_x];
		};
	} forEach _allfacs;
};
//hint str _facs;
// if single faction
if(typeName _fac == "STRING") then {
	_facs = [_fac];
//	_fac = nil;
};

// if multiple factions
if(typeName _fac == "ARRAY") then {
	_facs = _fac;
	_fac = nil;
};

if(isNil "_fac" && !isNil "_side") then {
	_s = switch(_side) do {
		case resistance: {"Guerrila";};
		case civilian: {"Civilian";};
		default {str _side;};
	};
//hint str _s;
	// Confirm there are units for this faction in this type
	_facx = [];
	{
		_grpx = count(configFile >> "CfgGroups" >> _s >> _x >> _type);
		for "_y" from 1 to _grpx - 1 do {
			if (!(_x in _facx)) then {
				_facx = _facx + [_x];
			};
		};
	} forEach _facs;
	_facs = _facx;
};
//hint str _facs;
// pick random faction and validate
_fac = _facs select floor(random count _facs);
//if(!(_fac in _allfacs)) exitWith{player GlobalChat format["crB_randomGroup - ""%1"" not valid - %2", _fac, _allfacs];};

if(isNil "_side") then {
	_sidex = getNumber(configFile >> "CfgFactionClasses" >> _fac >> "side");
	_side = nil;
	switch(_sidex) do {
		case 0: {
			_side = east;
		};
		case 1: {
			_side = west;
		};
		case 2: {
			_side = resistance;
		};
		case 3: {
			_side = civilian;
		};
	};
};

//player globalChat format["Side %1 %2 Fctns: %3 This %4 Type %5", _side, _sidex, _facs, _fac, _type];

_grps = [];
	_s = switch(_side) do {
		case resistance: {"Guerrila";};
		case civilian: {"Civilian";};
		default {str _side;};
	};
//hint str _s;
_grpx = count(configFile >> "CfgGroups" >> _s >> _fac >> _type);
for "_y" from 1 to _grpx - 1 do {
	_grps = _grps + [(configFile >> "CfgGroups" >> _s >> _fac >> _type) select _y];
};
//hint str _grps;
_grp = _grps select floor(random count _grps);

//hint format["%1 %2 %3", _pos, _side, _grp];
_spawnGrp = [_pos, _side, _grp] call BIS_fnc_spawnGroup;

if(_side == civilian) then {
	[_spawnGrp, _pos] spawn {
		_spawnGrp = _this select 0;
		_pos = _this select 1;
		while{true} do {
			_wp = _spawnGrp addWaypoint [_pos, 0];
			_wp setWaypointType "DISMISS";
			_wp setWaypointBehaviour "SAFE";
			sleep 300;
		};
	};
};

//player globalChat format["type: %1 fac: %2", _type, _fac];
_spawnGrp;
