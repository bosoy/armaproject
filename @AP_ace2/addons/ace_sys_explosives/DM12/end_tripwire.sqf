#include "\x\ace\addons\sys_explosives\script_component.hpp"

_mine = (_this select 3) select 0;
_max = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(tripwire_length));

if (player distance (_mine getVariable QGVAR(tw_start)) > (_max + 0.2)) then {
	format["%1. Max. %2 m",localize "STR_HINT_ACE_SYS_EXPLOSIVES_TOOFAR",_max] spawn ACE_fnc_visual;
	sleep 3;
} else {
	call FUNC(anim);
	_tripwire_point_b = [(getPos player) select 0,(getPos player) select 1,([player] call CBA_fnc_realHeight)];
	_mine setVariable [QGVAR(tw_end),_tripwire_point_b,true];
	GVAR(waiting_for_tripwire) = false;
};
