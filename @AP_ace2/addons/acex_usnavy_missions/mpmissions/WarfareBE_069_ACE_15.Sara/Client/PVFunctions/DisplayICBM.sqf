Private ["_cruise","_obj"];

_obj = _this select 0;
_cruise = _this select 1;
waitUntil {!alive _cruise || isNull _cruise};
[_obj] Spawn Nuke;