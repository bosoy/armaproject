// by Xeno
#define THIS_FILE "x_rebuildsupport.sqf"
#include "x_setup.sqf"
private ["_id", "_facindex", "_no", "_exitit"];

_id = _this select 2;
_facindex = _this select 3;

_exitit = false;
if (GVAR(with_ranked)) then {
	if (score player < (GVAR(ranked_a) select 13)) then {
		(format [(localize "STR_DOM_MISSIONSTRING_309"), score player, GVAR(ranked_a) select 13]) call FUNC(HQChat);
		_exitit = true;
	};
};
if (_exitit) exitWith {};

if (GVAR(with_ranked)) then {[QGVAR(pas), [player, (GVAR(ranked_a) select 13) * -1]] call FUNC(NetCallEventCTS)};

player removeAction _id;

[QGVAR(del_ruin), (GVAR(aircraft_facs) select _facindex) select 0] call FUNC(NetCallEvent);
sleep 1.021;

(localize "STR_DOM_MISSIONSTRING_310") call FUNC(HQChat);

[QGVAR(f_ru_i), _facindex] call FUNC(NetCallEventCTS);