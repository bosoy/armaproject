#include "script_component.hpp"

PARAMS_1(_ejector);

waitUntil { ((animationState player) != "para_pilot") };

if !(surfaceIsWater (getpos _ejector)) exitWith {};
private ["_lb","_pos"];
_lb = "ACE_Lifeboat_US" createVehicle getposASL _ejector;
_pos = getposASL _ejector;
_pos set [0, ((_pos select 0) + 2)];
_pos set [1, ((_pos select 1) + 2)];
_pos set [2, 0];
_lb setPos _pos;

if !(isPlayer _ejector) then {
	_ejector moveInDriver _lb;
};
