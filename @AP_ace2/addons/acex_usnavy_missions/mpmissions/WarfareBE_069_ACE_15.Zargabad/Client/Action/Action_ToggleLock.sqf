Private ["_lock","_vehicle"];

_vehicle = _this select 0;

_lock = if (_vehicle call CBA_fnc_locked) then {false} else {true};

[_vehicle,_lock] Call CLTFNCSetVehicleLock;