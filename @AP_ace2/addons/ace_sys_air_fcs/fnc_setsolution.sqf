// Tank FCS by q1184
// find and setvar solution for each ammo type for given range

// #define DEBUG_MODE_FULL
#include "script_component.hpp"
//#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __magcfg configFile >> "cfgMagazines" >> _x

private ["_currange","_ammo","_fired","_c","_flighttime","_elev","_maxrng","_minrng","_lead"];
PARAMS_5(_veh,_range,_magz,_wpn,_ignorelead);

_fired = []; //format: ["ammo1",[lead1,elev1],"ammo2",[lead2,elev2],...]
{
	_ammo = getText(__magcfg >> "ammo");
	if !(_ammo in _fired) then {
		_maxrng =  getNumber(__magcfg >> "ace_air_fcs_maxrange");
		if (_maxrng > 0) then {
			_currange = _maxrng min _range;
			_elev = [_x,_currange] call FUNC(elev);
			_flighttime = _elev select 1;
			_elev = _elev select 0;
			_lead = if (_ignorelead) then {0} else {[_veh,_wpn,_currange,_flighttime] call FUNC(lead)};
			_fired set [count _fired,_ammo];
			_fired set [count _fired,[_lead,_elev]];
		};
	};
} forEach _magz;

_veh setVariable [QGVAR(fired),_fired];
