#include "\x\ace\addons\sys_explosives\script_component.hpp"

_mine = (_this select 3) select 0;
_max = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(tripwire_length));

if ((player distance GVAR(tripwire_point_a)) > (_max + 0.2)) then {
	format["%1. Max. %2 m",localize "STR_HINT_ACE_SYS_EXPLOSIVES_TOOFAR",_max] spawn ACE_fnc_visual;
	sleep 3;
} else {
	[true,_mine] spawn FUNC(createStake);
};
