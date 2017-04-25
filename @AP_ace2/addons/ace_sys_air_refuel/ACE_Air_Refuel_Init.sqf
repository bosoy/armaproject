/* ace_sys_air_refuel | (c) 2008, 2009 by rocko */

/* Module version
 Creates a tanker at the position of the module.
 Direction of the module logic determines the initial heading of the tanker.
 Tanker will fly straight forward into given direction for about 10 km. It will then turn around
 and fly in the opposite direction.

 This allows to have an AI controlled tanker flying autonomously over the map.

 TODO:
 - Indicate flight route with markers?
 - Get feedback
*/

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

_logic = _this select 0;
sleep (random 4);
// Limit usage to 4 modules at once
if (isNil QGVAR(Modules)) then {
	GVAR(Modules) = [_logic]; // This module is 1 if NIL!
} else {
	GVAR(Modules) set [(count GVAR(Modules)),_logic];
};
if ((count GVAR(Modules)) > 4) exitWith { _logic globalChat "Too many Air Refueling Modules active. Maximum is four."; };

// Check distance between each modules
_nearestModules = (position _logic) nearEntities ["ACE_AirRefuel_Logic", 800];
if ((count _nearestModules) > 1) exitWith { _logic globalChat "Two Air Refueling Modules are placed too close to each other. Increase distance. Minimum distance is 800 meters."; };

sleep 10 + (random 10);

// Parameter
_startPos = getPosATL _logic;
_startDir = getDir _logic;
_startHeight = 1000;
_km = 10;
_distance = (_km * 1000);

// Parameter: HEIGHT
_defaultHeight = 1000;
#define __minHeight 400
#define __maxHeight 2000
_height = _logic getVariable ["HEIGHT", _defaultHeight];
if ((typeName _height) != "SCALAR") then { _height = _defaultHeight; };
if (_height > __maxHeight) then { _height = __maxHeight; };
if (_height < __minHeight) then { _height = __minHeight; };
_defaultHeight = _height;
TRACE_1("",_defaultHeight);

// Parameter: TANKER
// TODO: Enable once more tankers available
_defaultTanker = "ACE_HC130_N"; // DEFAULT: HC-130
//_tanker = _logic getVariable "TANKER";
//if (isNil "_tanker") then { _tanker = _defaultTanker; };
//if (getNumber(configFile >> "CfgVehicles" >> (typeOf _tanker) >> "ACE_isTanker") != 1) exitWith {};	// ABORT
TRACE_1("",_defaultTanker);

// Parameter: SIDE - Side parameter depends on the type of tanker unit
_defaultSide = getNumber(configFile >> "CfgVehicles" >> (_defaultTanker) >> "side");
if (_defaultSide in [0,east]) then { _defaultSide = east; };
if (_defaultSide in [1,west]) then { _defaultSide = west; };
TRACE_1("",_defaultSide);

// Parameter: FUEL
_defaultFuel = true;

// Spawn Tanker
_spawn = [[(_startPos select 0), (_startPos select 1), _startHeight], _startDir, _defaultTanker, _defaultSide] call BIS_fnc_spawnVehicle; // Thanks BIS!
_v = _spawn select 0;
_c = _spawn select 1;
_g = _spawn select 2;
TRACE_4("",_spawn,_v,_c,_g);

// Parameter: Respawn
_defaultRespawn = 0;
_respawn = _logic getVariable ["RESPAWN", _defaultRespawn];
switch (typeName _respawn) do {
	case "BOOL": { if (_respawn) then { _respawn = 1; } else { _respawn = 0; }; };
	case "SCALAR": { if (_respawn == 1) then { _respawn = 1; } else { _respawn = 0; }; };
	default { _respawn = _defaultRespawn; };
};
if (_respawn == 1) then {
	_v setVariable ["ACE_REFUELING_LOGIC", _logic, true];
	_v addEventhandler ["killed", QUOTE([(_this select 0) getVariable 'ACE_REFUELING_LOGIC'] spawn COMPILE_FILE(ACE_Air_Refuel_Init))];
};
TRACE_1("",_defaultRespawn);

// Delete initial waypoints
deleteWaypoint [_g,0];

_movePos = [(_startPos select 0) + ((sin _startDir) * _distance), (_startPos select 1) + ((cos _startDir) * _distance), _defaultHeight];
_cyclePos = [(_movePos select 0) + ((sin _startDir) * -(_distance)), (_movePos select 1) + ((cos _startDir) * -(_distance)), _defaultHeight];

#define __pos [_movePos,_cyclePos,_movePos]

for "_x" from 0 to 2 do {
	_wp = _g addWaypoint [(__pos select _x), 0];
	_wp setWaypointCompletionRadius 300;
	_wp setWaypointSpeed "LIMITED";
	_wp setWaypointBehaviour "SAFE";
	if (_x<2) then { _wp setWaypointType "MOVE"; } else { _wp setWaypointType "CYCLE"; };
	if (_defaultFuel) then { _wp setWaypointStatements ["true", "this setFuel 1;"]; };

	// DEBUG
	#ifdef DEBUG_MODE_FULL
		_marker = createMarker [(format["AirRefuel%1",_x]), (__pos select _x)];
		_marker setMarkerShape "ICON";
		format["AirRefuel%1",_x] setMarkerType "DOT";
		format["AirRefuel%1",_x] setMarkerText (format["%1   %2    %3",_x,(__pos select _x), (waypointType _wp)]);
	#endif
};

// Force flying in correct height
_v flyInHeight _defaultHeight;
_v setSkill 1;

// Bimmel Bommel
[_v] execFSM "\x\ace\addons\sys_air_refuel\fnc_release_hose.fsm";
