#include "script_component.hpp"

// #define BLOOD_DROPS ["ACE_Blooddrop_1", "ACE_Blooddrop_2"]
// #define BLOOD_SPLATS ["ACE_Bloodsplat_1", "ACE_Bloodsplat_2"]
// (BLOOD_DROPS call ACE_fnc_selectrandom)
#define MAXIMUM_DROPS 4
// How much apart should the drops be
#define VALUE 0.20
// How far must the first blooddrop appear?
#define OFFSET 0.25

PARAMS_3(_unit,_dir,_damage);

private ["_pos", "_bloodPos", "_x", "_y", "_value", "_offSet", "_sinDir", "_cosDir", "_sin", "_cos"];

// TODO: Do all calcs on sender's end?
_pos = getPosATL _unit;
_value = VALUE * _damage;
_offSet = OFFSET + _value;
_sinDir = sin _dir;
_cosDir = cos _dir;

_x = _pos select 0; _y = _pos select 1;
_bloodPos = [_x + (_sinDir * _offSet), _y + (_cosDir * _offSet), 0];
["ACE_Blooddrop_2", _bloodPos, _dir] call FUNC(spawnBlood);

_c = ceil (MAXIMUM_DROPS * _damage);
if (_c > 1) then {
	_sin = _sinDir * _value;
	_cos = _cosDir * _value;

	// Start from 2, as blooddrop 1 we already did
	for "_i" from 2 to _c do {
		_x = _bloodPos select 0; _y = _bloodPos select 1;
		_bloodPos = [_x + _sin, _y + _cos, 0];
		["ACE_Blooddrop_1", _bloodPos, _dir] call FUNC(spawnBlood);
	};
};

[QGVAR(bleeding), [_unit]] call CBA_fnc_localEvent;
