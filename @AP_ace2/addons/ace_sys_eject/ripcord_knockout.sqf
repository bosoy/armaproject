#include "script_component.hpp"
#define __UncTime (10 + random 50)

_jumper = _this;

cutText ["You've been knocked out from excess G-forces.", "BLACK OUT"];

_endtime = diag_tickTime + __UncTime;

waitUntil {(vehicle _jumper == _jumper) || {(diag_tickTime > _endtime)}};

sleep 2;

CutText ["You've been knocked out from excess G-forces.", "BLACK IN"];
_jumper setVariable [QGVAR(Chute_Unconc), false];

// May implement later: player gets damaged - this is old ACE1 code, and function calls would need to be updated to ACE2.
/*
if (vehicle _jumper != _jumper) then {  // player still in parachute -> has regained conciousness but must be injured.
	waitUntil {vehicle _jumper == _jumper};

	if (isNil "ace_sys_wounds_enabled") then {
		_jumper setDamage ((Damage _jumper) + 0.25);
	} else {
		[_jumper,"",0.25,objNull,""] call ace_sys_wounds_fnc_hd;
	};
}
else { //  player has landed but still hasn't regained conciousness -> Transfer them over to the ACE wounded unconciousness system.
	sleep 0.25;
	if (!isNil "ace_sys_wounds_enabled") then {
		[_jumper,"",0.55,objNull,""] call ace_sys_wounds_fnc_hd;
	};
};
*/