// #define DEBUG_MODE_FULL
#include "script_component.hpp"

private["_type", "_threshold", "_fuel", "_repairTime", "_endTime", "_complete", "_i", "_step"];
PARAMS_2(_veh,_repairVeh);

// TODO: Handle repairs differently based on used damage systems (Hitpoints, vs Armor Damage simulation etc)
// TODO: Handle repair veh type, can also be building, maybe some repairs should only be allowed at the building. One should be able to tow the vehicle to the building though..
_type = typeOf _veh;
_displayName = getText(configFile >> "CfgVehicles" >> _type >> "displayName");
_threshold = 1 - getNumber(configFile >> "CfgVehicles" >> _type >> QGVAR(threshold_refuel));
_fuel = fuel _veh;
TRACE_2("",_threshold,_fuel);
if (_fuel < _threshold) exitWith { hint format["Vehicle is too far Dry! < %1 (%2)", _threshold, _veh] };

// TODO: Verify Engine status (Armor damage simulation system)

_complete = false;
_repairTime = (getNumber(configFile >> "CfgVehicles" >> _type >> QGVAR(time)) * 0.5) * (1 - _fuel); // Fuel: 50% of Repair... for now
_repairTime = ceil _repairTime;
if (_repairTime == 0) exitWith { hint format[localize "STR_ACE_REFUEL_NO", _displayName]; };
if (_veh getVariable [QGVAR(refuel_busy), false] && {(_veh getVariable [QGVAR(refuel_busyState), 0]) >= time}) exitWith { hint "Busy already..." };
[QGVAR(setBusyRef), [_veh, _repairTime]] call CBA_fnc_globalEvent;

hint format[localize "STR_ACE_REFUEL_TIME", _repairTime, _displayName];
[_repairTime, [localize "STR_CFG_CUTSCENES_REFUEL"], false, false] spawn ace_progressbar;
_endTime = time + _repairTime;

_step = (1 - _fuel) / _repairTime;

_i = 0;
while {alive _repairVeh && {alive _veh} && {_veh distance _repairVeh < 15}} do {
	if (time > _endTime) exitWith { _complete = true };
	ADD(_i,1);
	sleep 1;
};

if (_complete) then {
	TRACE_1("setFuel 1",_veh);
	[QGVAR(refuel), [_veh, 1]] call CBA_fnc_globalEvent;
	hint (localize "STR_ACE_REFUEL_SUCCESS");
} else {
	[QGVAR(refuel), [_veh, (_fuel + (_step * _i) min 1)]] call CBA_fnc_globalEvent; // Still not entirely doing it in steps realtime, due to possible network implications
	hint (localize "STR_ACE_REFUEL_NOSUCCESS_TOOFAR");
};

[QGVAR(unsetBusyRef), _veh] call CBA_fnc_globalEvent;
