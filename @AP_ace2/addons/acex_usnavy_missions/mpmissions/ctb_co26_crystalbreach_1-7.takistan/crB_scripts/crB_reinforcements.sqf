//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Created by: Wolffy.au
// Modified by: (AEF)Odin 2010/01/04
// Version: 20081110 - Initial release
// Modified: 20091028 - Changed for ARMA2
// Modified: 20091120 - Added random squads and land/air transport vehicles
// Contact: http://creobellum.org
// Usage: call{[pos spawn, pos dest, pos getout, total reinforcements, watermark, radius, timecheck, faction] execVM "crb_scripts\crb_reinforcements.sqf";};
// Purpose: Spawn and deploy reinforcements
///////////////////////////////////////////////////////////////////
_debug = false;

if (!isServer) exitwith {};
private["_pos","_type","_fac","_facs","_sidex","_side","_grpx","_grps","_grp","_radius"];
// where do units and vehicles spawn
_crb_startpos = _this select 0;
// where will they travel too
_crb_destpos = _this select 1;
// where will they dismount/eject their vehicle
_crb_dismntpos = _this select 2;
// whats the total number of units you want to create?
_crb_total_enemy = _this select 3;
// whats the maximum number of units it want active at anytime?
_crb_watermark_enemy = _this select 4;
// radius to check for reinforcement numbers
_crb_reinperim = _this select 5;
// time between checking watermark
_crb_timechk = _this select 6;
// faction
_fac = nil;
if(count _this > 7) then {
	_fac = _this select 7;
};
if (isNil "_fac") then { _fac = east; };

sleep _crb_timechk;

_crb_reinforcements = 0;

waitUntil {!isNil "bis_fnc_init"};

_facs = [];
_side = nil;
_sidex = nil;
// get all factions
_allfacs = [] call BIS_fnc_getFactions;
//hintC str _allfacs;

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
//hintC str _facs;
// if single faction
if(typeName _fac == "STRING") then {
	_facs = [_fac];
	_fac = nil;
};

// if multiple factions
if(typeName _fac == "ARRAY") then {
	_facs = _fac;
	_fac = nil;
};
//hintC format["%1 %2", _fac, _side];
if(isNil "_fac" && !isNil "_side") then {
	_s = switch(_side) do {
		case resistance: {"Guerrila";};
		case civilian: {"Civilian";};
		default {str _side;};
	};
//hint str _s;
	// Confirm there are units for this faction in this type
	_type = "Infantry";
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
//hintC str _facs;
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

//hintC format["Side %1 %2 Fctns: %3 This %4 Type %5", _side, _sidex, _facs, _fac, _type];

_grps = [];
_allvehs = [];
_grpx = count(configFile >> "CfgVehicles");
for "_y" from 1 to _grpx - 1 do {
	_vehx = (configFile >> "CfgVehicles") select _y;
	_sx = getNumber(_vehx >> "transportSoldier");
	_fx = getText(_vehx >> "faction");
	_cx = configName _vehx;
//	hint str _fx;
	if (_fx == _fac && _sx > 2) then {
		_allvehs = _allvehs + [_cx];
	};
};

_vehclasses = [];
{
	if(_x isKindOf "Car") then {
		_vehclasses = _vehclasses + [_x];
	};
} forEach _allvehs;
_vehclasses = _vehclasses + ["AIR"];

_airclasses = [];
{
	if(_x isKindOf "Air") then {
		_airclasses = _airclasses + [_x];
	};
} forEach _allvehs;
//hintC str (_vehclasses + _airclasses);

// count active units
_crb_count_enemy = 0;
{
	if (_x isKindOf "Land" && side _x == _side && _crb_destpos distance _x < _crb_reinperim) then {
		_crb_count_enemy = _crb_count_enemy + 1;
	};
} forEach allUnits;

if (_debug) then {hint format["#current enemy: %1\n#reinforcements deployed: %2", _crb_count_enemy, _crb_reinforcements];};

// check if units are below watermark
while {_crb_count_enemy > _crb_watermark_enemy} do {
	sleep _crb_timechk;
	// count active units
	_crb_count_enemy = 0;
	{
		if (_x isKindOf "Land" && side _x == _side && _crb_destpos distance _x < _crb_reinperim) then {
			_crb_count_enemy = _crb_count_enemy + 1;
		};
	} forEach allUnits;
};

//////////////////////////////////////////////////////////////////////
// Create units
//////////////////////////////////////////////////////////////////////
_grps = [];
// create reinforcements until difference is made up
while{_crb_reinforcements < _crb_total_enemy} do {
	_grp = [[(_crb_startpos select 0) - 20, (_crb_startpos select 1)], "Infantry", _fac] call compile preprocessfile "crb_scripts\crb_randomGroup.sqf";
	_crb_reinforcements = _crb_reinforcements + (count units _grp);
	if (_debug) then {hint format["#current enemy: %1\n#reinforcements deployed: %2", _crb_count_enemy, _crb_reinforcements];};
	_grps = _grps + [_grp];
};
//waitUntil{false};

//////////////////////////////////////////////////////////////////////
// Select reinforcments side
//////////////////////////////////////////////////////////////////////
_offset = 0;
_crb_vehicle = objNull;

//////////////////////////////////////////////////////////////////////
// Create transport vehicles with enough cargo slots for infantry
// include "AIR" to help balance air and land transport
//////////////////////////////////////////////////////////////////////
{
	// position
	_vehpos = [(_crb_startpos select 0) + _offset, (_crb_startpos select 1)];
	_offset = _offset + 5;
	// class
	_crb_vehclass = _vehclasses select floor(random (count _vehclasses));
	if (_crb_vehclass == "AIR") then {
		_crb_vehclass = _airclasses select floor(random (count _airclasses));
	};
	// create vehicle with enough positions for group
	_crb_vehicle = _crb_vehclass createVehicle _vehpos;
	while{_crb_vehicle emptyPositions "cargo" < count units _x} do {
		deleteVehicle _crb_vehicle;
		_crb_vehicle = objNull;
		_crb_vehclass = _vehclasses select floor(random (count _vehclasses));
		_crb_vehicle = _crb_vehclass createVehicle _vehpos;
	};
	_cargo = _crb_vehicle emptyPositions "cargo";

	sleep 1;

	// spawn crew
	waitUntil {!isNil "bis_fnc_init"};
	_driver_grp = createGroup _side;
	[_crb_vehicle, _driver_grp] call BIS_fnc_spawnCrew;

	// move units into cargo positions
	{
		private["_x"];
		_x assignAsCargo _crb_vehicle;
		_x moveInCargo _crb_vehicle;
	} forEach units _x;

	_driver_grp setCombatMode "GREEN";
	_driver_grp setSpeedMode "FULL";
//	_driver_grp setBehaviour "SAFE";

	// disable aircraft from engaging and ensure they are rise vertically before moving.
	if (_crb_vehicle iskindof "Air") then {
		_driver_grp setSpeedMode "NORMAL";
		_crb_vehicle disableAI "AUTOTARGET";
		_crb_vehicle move position _crb_vehicle;
		_crb_vehicle flyInHeight 50;
		sleep 22;
	};

	if (_debug) then {hint "Moving out";};
	// set transport group behaviour and move to dismount position
	_driver_grp move _crb_dismntpos;
	[_crb_vehicle, _crb_startpos, _crb_dismntpos, _x, _cargo, _crb_destpos] spawn {
		_crb_vehicle = _this select 0;
		_crb_startpos = _this select 1;
		_crb_dismntpos = _this select 2;
		_x = _this select 3;
		_cargo = _this select 4;
		_crb_destpos = _this select 5;

		_driver_grp = group driver _crb_vehicle;

		waitUntil{leader _driver_grp distance _crb_dismntpos < 20 || (leader _driver_grp distance _crb_dismntpos < 160 && _crb_vehicle iskindof "Air")};

		_landStart = "HeliHEmpty" createVehicle _crb_dismntpos;
		if (_crb_vehicle iskindof "Air") then {
			_crb_vehicle land "GET OUT";
			waitUntil {(position _crb_vehicle) select 2 < 3};
		};

		if (_debug) then {hint "Arrived";};

		// wait until all units have dismounted and send to defend
		{
			private["_x"];
			unassignVehicle _x;
			_x action ["Get out", vehicle _x];
		} forEach units _x;
		waitUntil{_crb_vehicle emptyPositions "cargo" == _cargo};
//		if (_debug) then {hint "All troops dismounted";};
		deleteVehicle _landStart;
		_landStart = objNull;

		_x move _crb_destpos;

	//////////////////////////////////////////////////////////////////////
	// Spawn Transport process
	// At this point the transport group run in their own process until
	// they return to base
	//////////////////////////////////////////////////////////////////////
		[_crb_vehicle, _crb_startpos] spawn {
			_crb_vehicle = _this select 0;
			_crb_startpos = _this select 1;
			_driver_grp = group driver _crb_vehicle;
	//waitUntil{false};
				// Originally from Myke's cep_move.sqf
			if (_crb_vehicle iskindof "Air") then {
				_crb_vehicle move position _crb_vehicle;
				_crb_vehicle flyInHeight 70;
				sleep 5;
			};

			_driver_grp move _crb_startpos;

			waitUntil{leader _driver_grp distance _crb_startpos < 20 || (leader _driver_grp distance _crb_startpos < 160 && _crb_vehicle iskindof "Air")};

			if (_crb_vehicle iskindof "Air") then {
				_landEnd = "HeliHEmpty" createVehicle _crb_startpos;
				_crb_vehicle land "LAND";
				waitUntil{(position _crb_vehicle) select 2 <= 5};
				_crb_vehicle engineOn false;
				deleteVehicle _landEnd;
				_landEnd = objNull;
			};
	//waitUntil{false};
			{
				private["_x"];
				unassignVehicle _x;
				deleteVehicle _x;
				_x = objNull;
			} forEach units _crb_vehicle;
			deleteVehicle _crb_vehicle;
			_crb_vehicle = objNull;
		};

		waitUntil{leader _x distance _crb_destpos < 5};
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
		} else {
			call {[_x, position leader _x] execVM "scripts\BIN_taskDefend.sqf"};
		};
	};

} forEach _grps;
if (_debug) then {hint "End reinforcements";};
forceEnd;
