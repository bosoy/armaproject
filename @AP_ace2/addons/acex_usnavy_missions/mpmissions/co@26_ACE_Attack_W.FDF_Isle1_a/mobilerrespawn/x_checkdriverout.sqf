private ["_vehicle","_position","_enterer"];

_vehicle = _this select 0;
_position = _this select 1;
_enterer = _this select 2;

if (_position == "driver") then {
	if (_enterer == player && local player) then {
		if (vec2_id != -1000) then {
			_vehicle removeAction vec2_id;
			vec2_id = -1000;
		};
	};
};
