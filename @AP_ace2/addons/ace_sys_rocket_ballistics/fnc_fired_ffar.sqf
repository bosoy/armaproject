#include "script_component.hpp"
//	This script makes rockets turn into the trajectory
//	as opposed to them keeping the initial facing/pitch during the whole flight.
//	On each iteration the new direction is calculated based on current speed vector.

//	This version handles FFARs

private ["_bullet"];

_bullet = _this select 6; // uses BIS Fired EH

[_this, _bullet,1] spawn FUNC(dispersion);
//[_this,_bullet,1] execFSM "\x\ace\addons\sys_rocket_ballistics\fnc_dispersion.fsm";

//find and set proper vectorup continuosly
[_bullet, 0.07, 0.3] spawn FUNC(turnrocket);
//[_bullet, 0.07, 0.] execFSM "\x\ace\addons\sys_rocket_ballistics\fnc_turnrocket.fsm";
