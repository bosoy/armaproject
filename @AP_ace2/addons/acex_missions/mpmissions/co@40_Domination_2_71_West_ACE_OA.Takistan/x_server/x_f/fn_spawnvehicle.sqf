#define THIS_FILE "fn_spawnvehicle.sqf"
#include "x_setup.sqf"
/*
	File: spawnVehicle.sqf
	Author: Joris-Jan van 't Land

	Description:
	Function to spawn a certain vehicle type with all crew (including turrets).
	The vehicle can either become part of an existing group or create a new group.

	Parameter(s):
	_this select 0: desired position (Array).
	_this select 1: desired azimuth (Number).
	_this select 2: type of the vehicle (String).
	_this select 3: side or existing group (Side or Group).

	Returns:
	Array:
	0: new vehicle (Object).
	1: all crew (Array of Objects).
	2: vehicle's group (Group).
*/

private ["_posv1", "_azi", "_typev1", "_param4", "_grp", "_side", "_newGrp"];
PARAMS_4(_posv1,_azi,_typev1,_param4);

if ((typeName _param4) == (typeName sideEnemy)) then {
	_side = _param4;
	_grp = [_side] call FUNC(creategroup);
	_newGrp = true;
} else {
	_grp = _param4;
	_side = side _grp;
	_newGrp = false;
};

private ["_sim", "_veh", "_crew"];
_sim = getText(configFile >> "CfgVehicles" >> _typev1 >> "simulation");

if (_sim in ["airplane", "helicopter"]) then {
	if ((count _posv1) == 2) then {_posv1 set [count _posv1, 200]};

	_veh = createVehicle [_typev1, _posv1, [], 0, "FLY"];

	_veh setVelocity [50 * (sin _azi), 50 * (cos _azi), 0];
} else {
	_veh = createVehicle [_typev1, _posv1, [], 0, "NONE"];
	_svec = sizeOf _typev1;
	_isFlat = (position _veh) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _veh];
	if (count _isFlat > 1) then {
		_posv1 = _isFlat;
		_posv1 set [2, 0];
	};
	if (random 100 > 50) then {_veh allowcrewinimmobile true};
};

_veh setDir _azi;
_veh setPos _posv1;

_grp addVehicle _veh;
_crew = [_veh, _grp] call FUNC(spawnCrew);

if (_newGrp) then {_grp selectLeader (commander _veh)};

[_veh, _crew, _grp]