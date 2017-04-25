private ["_vehicle","_position","_enterer"];

_vehicle = _this select 0;
_position = _this select 1;
_enterer = _this select 2;

if (_position == "driver") then {
	if (_enterer == player && local player) then {
		vec2_id = _vehicle addAction ["Drop Ammocrate", "mobilerrespawn\x_dropammobox.sqf",[],-1,false];
	};
};
