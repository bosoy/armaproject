Private ["_amount","_vehicle"];
_vehicle = _this select 0;

if (isNull _vehicle) exitWith {};
waitUntil {commonInitComplete};
sleep 2;
_amount = if (_vehicle isKindOf "Plane") then {'WFBE_COUNTERMEASUREPLANES' Call GetNamespace} else {'WFBE_COUNTERMEASURECHOPPERS' Call GetNamespace};
_vehicle setVariable ["FlareCount", _amount];
_vehicle setVariable ["FlareActive", false];
