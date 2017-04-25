//Secondary explosions
//By Maddmatt for ACE
#include "script_component.hpp"
private ["_t","_b","_effect2pos"];

PARAMS_2(_veh,_int);

//First we deal with fuel explosions

_t = time;
[QGVAR(Burn), [_veh,_int,_t]] call CBA_fnc_globalEvent;

if (sizeOf (typeOf _veh) > 5) then {
	//Big fuel explosion possible if enough fuel.
	switch (true) do {
		case (_int > 7.5): {_veh spawn FUNC(fuelexpbig)};
		case (_int > 5): {_veh spawn FUNC(fuelexpsmall)};
	};
	//Possible initial small explosion
	if ((random _int) > 3) then {
		_effect2pos = _veh selectionposition "destructionEffect2";
		_b = "SmallSecondary" createvehicle (_veh modelToWorld _effect2pos);
	};
} else {
	//Small vehicle, small explosion.
	if (_int > 3) then {
		_veh spawn FUNC(fuelexpspark);
	};
	//Possible initial secondary
	if ((random _int) > 5) then {
		_effect2pos = _veh selectionposition "destructionEffect2";
		_b = "ace_fuelexpsmall" createvehicle (_veh modelToWorld _effect2pos);
	};
};

//Create small fuel explosions
[_veh, _int] spawn FUNC(fuelexpmain)

//TODO: Ammo explosions
// wut ?
