/* ace_sys_helidust | (c) 2008, 2009 by rocko */

#include "script_component.hpp"

LOG(MSG_INIT);

ADDON = false;

PREP(rocko_engine);
PREP(rocko_dust);
PREP(rocko_tailrotor);
PREP(rocko_manshred);

[QGVAR(engineon), {(_this select 0) setVariable [QGVAR(enginestate),false];if (!isDedicated) then {_this spawn FUNC(rocko_dust)}}] call CBA_fnc_addEventHandler;
[QGVAR(engineoff), {_this setVariable [QGVAR(enginestate),false]}] call CBA_fnc_addEventHandler;

[QGVAR(dodam), {
	if (isPlayer (_this select 0)) then {
		playSound "ACE_TailRotorShredding"
	};
	if (isNil "ace_sys_wounds_enabled") then {
		(_this select 0) setDamage (_this select 1);
	} else {
		[_this select 0, "", _this select 1, objNull, ""] call ace_sys_wounds_fnc_hd;
	};
}] call ACE_fnc_addReceiverOnlyEventhandler;

ADDON = true;
