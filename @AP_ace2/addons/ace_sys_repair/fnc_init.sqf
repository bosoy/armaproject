//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define __cfg configFile >> "CfgVehicles" >> typeOf _veh

#define __aJC for "_i" from 1 to _count_can do { \
_type = if (getnumber(configFile >> "CfgVehicles" >> typeOf _veh >> "side") == 3) then { "ACE_JerryCan_5" } else { "ACE_JerryCan_15" }; \
_can = createVehicle [_type,[0,0,0],[],0,"NONE"]; \
[[_can], _veh, true] call ACE_fnc_loadCargo; \
sleep 1; \
}

PARAMS_1(_veh);

_count_can = if (isNumber(configFile >> "CfgVehicles" >> typeOf _veh >> QGVAR(jerrycan_count))) then {
	getNumber(configFile >> "CfgVehicles" >> typeOf _veh >> QGVAR(jerrycan_count))
} else {
	1
};

if (!isDedicated) then {
	if (getNumber(__cfg >> QGVAR(repair)) == 1) then { _act = _veh addAction [localize "STR_CFG_CUTSCENES_REPAIR", QPATHTO_F(fnc_action), "repair"] };
	if (getNumber(__cfg >> QGVAR(rearm)) == 1) then { _act = _veh addAction [localize "STR_CFG_CUTSCENES_REARM", QPATHTO_F(fnc_action), "rearm"] };
	if (getNumber(__cfg >> QGVAR(refuel)) == 1) then { _act = _veh addAction [localize "STR_CFG_CUTSCENES_REFUEL", QPATHTO_F(fnc_action), "refuel"] };
};

if (local _veh) then {
	if (_veh isKindOf "Car") then {
		if ([_veh] call ACE_fnc_canLoadCargo) then {
			//_offset = if (surfaceIsWater (getPos _veh)) then { [0,(sizeOf (typeof _veh)) / 2,-(getPosATL _veh select 2)] } else { [0,(sizeOf (typeof _veh)) / 2,0] }; //unload by default behind the vehicle
			if (getnumber(configFile >> "CfgVehicles" >> typeOf _veh >> "side") == 3) then {
				if (random 100 > 50) then { __aJC; };
			} else {
				__aJC;
			};
			if (!isnil QGVAR(default_tyres)) then {
				_n = (getNumber(__cfg >> QGVAR(spare_tyres))) - 1;
				for "_i" from 0 to _n do {
					private "_tyre";
					_type = getText(configFile >> "CfgVehicles" >> typeOf _veh >> QGVAR(tyre_type));
					_tyre = createvehicle [_type,[0,0,0],[],0,"NONE"];
					[[_tyre], _veh] call ACE_fnc_loadCargo;
				};
			};
		};
	};
};
