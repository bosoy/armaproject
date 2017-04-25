Private ['_configScripts','_location','_locationName','_params','_range','_script','_total'];

_location = _this Select 0;
_locationName = _this Select 1;
_configScripts = _this Select 2;

if (isNull _location) exitWith {};

waitUntil {townModeSet};
if ((str _location) in TownTemplate) exitWith {
	diag_log Format ["[WFBE (INIT)][frameno:%3 | ticktime:%4] Config_Town: Removing town %1 (%2) since the town is removed in the towns templates.",_location,_locationName,diag_frameno,diag_tickTime];
	if (isServer) then {deleteVehicle _location};
};

_range = 600;
if (Count _this > 4) then {_range = _this Select 4};

_total = Count _configScripts;
_script = _configScripts Select (Random (_total - 1));
_params = [_location,_locationName];
if (Count _this > 4) then {_params = _params + [_range]};

waitUntil{initJIP && commonInitComplete};

_params ExecVM Format["Server\Config\Config_%1.sqf",_script];