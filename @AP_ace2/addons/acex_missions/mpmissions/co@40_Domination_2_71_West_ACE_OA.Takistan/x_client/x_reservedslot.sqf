// by Xeno
#define THIS_FILE "x_reservedslot.sqf"
#include "x_setup.sqf"

sleep 1;

if (serverCommandAvailable "#shutdown") exitWith {};

for "_i" from 1 to 3 do {
	hint (localize "STR_DOM_MISSIONSTRING_335");
	sleep 5;
};

if (serverCommandAvailable "#shutdown") exitWith {
	hint format [(localize "STR_DOM_MISSIONSTRING_336"), GVAR(name_pl)];
};

hint (localize "STR_DOM_MISSIONSTRING_337");

sleep 5;

if (serverCommandAvailable "#shutdown") exitWith {
	hint format [(localize "STR_DOM_MISSIONSTRING_336"), GVAR(name_pl)];
};

hint (localize "STR_DOM_MISSIONSTRING_338");
sleep 1;
[QGVAR(p_f_b_k), [player, GVAR(name_pl),2]] call FUNC(NetCallEventCTS);