#include "script_component.hpp"

waitUntil { sleep 0.15; (time > 0) && (alive player) };

if (isNil QGVAR(enabled)) exitWith {};

#define HASMAP (_player hasWeapon "ACE_Map")
#define HASGPS ((_player hasWeapon "ItemGPS") || { _player hasWeapon "ACE_DAGR" })
#define ISHALO ((_veh == _player) && (((velocity _player) select 2) < -20))
#define ENABLEDGPS ((getNumber (configFile >> "CfgVehicles" >> (typeOf _veh) >> "EnableGPS")) == 1)
#define TOINT(VAR1) (if (VAR1) then { 1 } else { 0 })

_fnc_inVehicle = {
	if ((_player != _veh) && { ENABLEDGPS }) then {
		if (_player == (driver _veh) || { _player == (gunner _veh) } || { _player == (commander _veh) }) then { true } else { false }
	} else { false }
};

_canSeeMap = 0;
_hasGPS = 0;

_canSeeMap_old = -1;
_hasGPS_old = -1;

while { true } do {
	private ["_player", "_veh", "_canSeeMap", "_hasGPS"];
	_player = player;
	_veh = vehicle player;
	_canSeeMap = TOINT(HASMAP);
	_hasGPS = TOINT(HASGPS);
	_inVehicle = call _fnc_inVehicle;
	
	if (_canSeeMap == 1) then {
		if (ISHALO) then {
			_canSeeMap = 0
		};
	} else {
		if (_inVehicle) then {
			_canSeeMap = 1
		};
	};
	
	if (_canSeeMap_old != _canSeeMap) then {
		showMap (_canSeeMap == 1);
		_canSeeMap_old = _canSeeMap;
	};

	if ((_hasGPS == 1) || _inVehicle) then {
		_hasGPS = 1
	} else {
		_hasGPS = 0
	};
	
	if (_hasGPS_old != _hasGPS) then {
		showGPS (_hasGPS == 1);
		_hasGPS_old = _hasGPS;
	};
	if (_player hasWeapon "ItemMap") then {_player removeWeapon "ItemMap"};
	if (!alive player) then {
		waitUntil { sleep 0.1; alive player };
		if (_player hasWeapon "ItemMap") then {_player removeWeapon "ItemMap"};
	};
	sleep 0.512;
};