// by Xeno
#define THIS_FILE "x_vehirespawn.sqf"
#include "x_setup.sqf"
private ["_delay","_disabled","_moved","_newveh","_startdir","_startpos","_type","_vehicle","_fuelleft"];
if (!isServer) exitWith{};

PARAMS_2(_vehicle,_delay);
_moved = false;
_startpos = position _vehicle;
_startdir = getDir _vehicle;
_type = typeOf _vehicle;

_vehicle setVariable [QGVAR(vec_islocked), (_vehicle call d_fnc_isVecLocked)];

_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(fuelCheck)}}];

while {true} do {
	sleep (_delay + random 15);
	
	_empty = _vehicle call FUNC(GetVehicleEmpty);
	
	if (_empty) then {
		_moved = (_vehicle distance _startpos > 5);
		
		_disabled = (damage _vehicle > 0);
		
		if ((_disabled && _empty) || (_moved && _empty) || (_empty && !(alive _vehicle))) then {
			_isitlocked = _vehicle getVariable QGVAR(vec_islocked);
			_fuelleft = GV(_vehicle,GVAR(fuel));
			if (isNil "_fuelleft") then {_fuelleft = 1};
			deletevehicle _vehicle;
			_vehicle = objNull;
			sleep 0.5;
			_vehicle = createVehicle [_type, _startpos, [], 0, "NONE"];
			_vehicle setdir _startdir;
			_vehicle setpos _startpos;
			_vehicle setVariable [QGVAR(vec_islocked), _isitlocked];
			if (_isitlocked) then {_vehicle lock true};
			_vehicle setFuel _fuelleft;
			_vehicle addMPEventhandler ["MPKilled", {if (isServer) then {_this call FUNC(fuelCheck)}}];
		};
	};
};
