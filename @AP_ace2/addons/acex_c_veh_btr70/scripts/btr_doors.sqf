// Script by zGuba A.D. 2011
// Open door at get in and out

private ["_vehicle","_position","_unit","_door"];

_vehicle = _this select 0;
_position = _this select 1;
_unit = _this select 2;

if !(local _vehicle) exitWith {};
if !(alive _vehicle) exitWith {};
if (isNull _unit) exitWith {};
if !(_position == "cargo") exitWith {};

_door = if (surfaceIsWater [getposASL _vehicle select 0, getposASL _vehicle select 1]) then {
	if ((_vehicle worldToModel (getPosATL _unit)) select 0 > 0) then {"t_door_1"} else {"t_door_2"};
} else {
	if ((_vehicle worldToModel (getPosATL _unit)) select 0 > 0) then {"r_door"} else {"l_door"};
};

if (_vehicle animationPhase _door < 1) then {
	_vehicle animate [_door, 0.99];
};

if (isNil {_vehicle getVariable _door}) then {
	[_vehicle, _unit, _door] spawn {
		_vehicle = _this select 0;
		_unit = _this select 1;
		_door = _this select 2;
		_vehicle setVariable [_door, [time + 1.5, _unit]];
		waitUntil {sleep 0.3; time > (_vehicle getVariable _door) select 0 || isNil {_vehicle getVariable _door}};
		if (alive _vehicle && (count crew _vehicle > 0 || ((_vehicle getVariable _door) select 1) distance _vehicle < 4)) then {
			if (_vehicle animationPhase _door < 1) then {
				_vehicle animate [_door, 0];
			};
		};
		_vehicle setVariable [_door, nil];
	};
} else {
	_vehicle setVariable [_door, [time + 1.5,_unit]];
};
