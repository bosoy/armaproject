#include "script_component.hpp"
private ["_trg", "_list"];
_trg = createTrigger["EmptyDetector", getArray(configFile >> "CfgWorlds" >> worldName >> "CenterPosition")];
_trg setTriggerArea[50000, 50000, 0, false];
_trg setTriggerActivation["ANY", "PRESENT", true];

waitUntil { _list = list _trg; !(isNil "_list") };
_ar1 = []; _ar2 = [];
{
	if (_x isKindOf "LaserTarget") then {
		if (local _x) then { PUSH(_ar1,_x) } else { PUSH(_ar2,_x) };
	};
} forEach (list _trg);
deleteVehicle _trg;
if !(isNull ace_laser_object) then {
	if !(ace_laser_object in _ar1) then { PUSH(_ar1,ace_laser_object) };
};

[_ar1, _ar2];
