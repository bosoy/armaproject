// find and setvar solution for each ammo type for given range

#include "script_component.hpp"

#define __vehcfg configFile >> "cfgVehicles" >> typeof _veh
#define __magcfg configFile >> "cfgMagazines" >> _c

private ["_rd","_offset","_currange","_ammo","_fired","_c","_flighttime","_elev","_maxrng","_minrng","_lead"];
PARAMS_5(_veh,_range,_magz,_wpn,_ignorelead);

_fired = []; //format: ["ammo1",[lead1,elev1],"ammo2",[lead2,elev2],...]

// optics offset correction
_offset = _veh getvariable "ace_tankfcs_boreoffseth";
_rd = _offset atan2 _range;
_veh setvariable ["ace_tankfcs_boreoffsetangleh",_rd];

//_offsetV = _veh getvariable "ace_tankfcs_boreoffsetv";
//_rd1 = _offsetV atan2 _range;

for "_i" from 0 to (count _magz) - 2 step 2 do {
	_c = _magz select _i;
	_ammo = getText(__magcfg >> "ammo");
	if !(_ammo in _fired) then {
		_maxrng = _magz select (_i + 1);
		_currange = _maxrng min _range;
		_elev = [_c,_currange] call FUNC(elev);
		_flighttime = _elev select 1;
		_elev = _elev select 0;
		_lead = if (_ignorelead) then {0} else {[_veh,_wpn,_currange,_flighttime] call FUNC(lead)};
		_fired set [count _fired,_ammo];
		_fired set [count _fired,[_lead + _rd,_elev]];
	};
};

_veh setvariable ["ace_tankfcs_fired",_fired,true];
