/* ----------------------------------------------------------------------------
Function: ACE_fnc_track

Description:
	Tracks an object with markers and particles

Parameters:
	_unit - Unit or Vehicle to attach to [Object]

Returns:
	nil

Examples:
	(begin example)
	(end)

Author:
	(c) Sickboy 2010
---------------------------------------------------------------------------- */
// #define DEBUG_MODE_FULL
#include "script_component.hpp";

#define MAXFIFO 20
#define DEFAULT_WAIT 0.3
#define VEHICLE_WAIT 5

private ["_objects", "_particles", "_groundMarker", "_markers", "_isVehicle", "_color", "_color1", "_color2", "_wait", "_waitUntil", "_p", "_o"];
PARAMS_1(_object);
DEFAULT_PARAM(2,_pos,getPosASL _object);

_objects = []; _particles = []; _markers = [];
_isVehicle = _object isKindOf "All";
// TODO: Read color properties from config?
_color = if (_isVehicle) then { [[[RGB_BLUE], "ColorBlue"], [[RGB_GREEN], "ColorGreen"]] } else { [[[RGB_RED], "ColorRed"], [[RGB_YELLOW], "ColorYellow"]] };
_color1 = _color select 0;
_color2 = _color select 1;

_wait = DEFAULT_WAIT;
if (_isVehicle) then { if !(_object isKindOf "Logic" || {_object isKindOf "LaserTarget"}) then { _wait = VEHICLE_WAIT } } else { _groundMarker = "HeliH" createVehicleLocal _pos };

_tracker = "ACE_LogicDummy" createVehicleLocal _pos;
_particle = [_tracker, _color1 select 0] call ACE_fnc_particle;

ADD(GVAR(marker_debug),1);
_marker = createMarkerLocal [format["ace_debug_mrk2_%1", GVAR(marker_debug)], _pos];
_marker setMarkerShapeLocal "ICON";
_marker setMarkerTypeLocal "DOT";
_marker setMarkerColorLocal (_color1 select 1);
_marker setMarkerTextLocal format["%1", _object];

_waitUntil = time + _wait;
while {alive _object} do {
	_pos = getPosASL _object;
	if ((_pos select 0) != 0 && {(_pos select 1) != 0} && {(_pos select 2) != 0}) then {
		_marker setMarkerPosLocal _pos;
		_tracker setPosASL _pos;
		if !(_isVehicle) then { _groundMarker setPosASL _pos };
		if (time > _waitUntil) then {
			// if (vehicle _object != _object) exitWith {}; // exit time condition scope
			_o = "ACE_LogicDummy" createVehicleLocal _pos;
			_o setPosASL _pos;
			PUSH(_objects,_o);
			_p = [_o, _color2 select 0] call ACE_fnc_particle;
			PUSH(_particles,_p);
			ADD(GVAR(marker_debug),1);
			_m = createMarkerLocal [format["ace_debug_mrk2_%1", GVAR(marker_debug)], _pos];
			_m setMarkerShapeLocal "ICON";
			_m setMarkerTypeLocal "DOT";
			_m setMarkerColorLocal (_color2 select 1);
			//_marker setMarkerTextLocal format["%1", _object];
			PUSH(_markers,_m);
			if (count _markers > MAXFIFO) then {
				_m = _markers select 0;
				_markers = _markers - [_m];
				deleteMarkerLocal _m;
				_m = _particles select 0;
				_particles = _particles - [_m];
				deleteVehicle _m;
				_m = _objects select 0;
				_objects = _objects - [_m];
				deleteVehicle _m;
			};
			_waitUntil = time + _wait;
		};
	};
	sleep 0.001;
};

sleep 10;

{ deleteVehicle _x } forEach _particles;
{ deleteVehicle _x } forEach _objects;
{ deleteMarkerLocal _x } forEach _markers;

if !(_isVehicle) then { deleteVehicle _groundMarker };
deleteVehicle _particle;
deleteVehicle _tracker;
deleteMarkerLocal _marker;
