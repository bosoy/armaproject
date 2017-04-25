// by Xeno

if (!isServer) exitWith{};

_vehicle = _this select 0;
_position = _this select 1;
_enterer = _this select 2;

_enterer_name = typeOf _enterer;

switch (_position) do {
	case "driver": {
		if (_enterer_name != "RU_Soldier_Pilot") then {
			driver _vehicle action["Eject",_vehicle];
		};
	};
	case "gunner": {
		if (_enterer_name != "RU_Soldier_Pilot") then {
			_enterer action["Eject",_vehicle];
		};
	};
};

if (true) exitWith {};