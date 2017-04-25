#include "script_component.hpp"
private ["_i", "_effect2pos", "_b", "_secondarytype", "_pause"];
PARAMS_2(_v2,_int2);

if (sizeOf (typeOf _v2) < 5) then {
	_secondaryType = "ace_fuelexpspark";
	_pause = 15;
	_i = 0.75 + random 1;
} else {
	_secondaryType = "SmallSecondary";
	_pause = 90;
	_i = 1.5 + random 2;
};

while {_int2 > 0} do {
	_int2 = _int2 - _i;
	sleep ((random _pause) + 1);
	if (alive _v2 || {(getposASL _v2 select 2) < -2.5} || {isnull _v2}) exitwith {};
	_effect2pos = _v2 selectionposition "destructionEffect2";
	_b = _secondarytype createvehicle (_v2 modelToWorld _effect2pos);
};
