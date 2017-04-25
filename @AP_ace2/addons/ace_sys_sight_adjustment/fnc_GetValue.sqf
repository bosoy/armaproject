#include "script_component.hpp"
// gets a value from 2 configs: first from the first one, then overrides it with the one from the second config if it exists there
// example of call: [_mywcfg,_myvehcfg,"My_c_value",0] call fGetValueFrom2Configs

private ["_type","_res"];

PARAMS_4(_wcfg,_turcfg,_value,_default);

_res = _default;
_type = typeName _default;

switch (_type) do {
	case "SCALAR": {
		if (isNumber (_wcfg >> _value)) then {
			_res = getNumber (_wcfg >> _value);
		};
		if (isNumber (_turcfg >> _value)) then {
			_res = getNumber (_turcfg >> _value);
		};
	};
	case "STRING": {
		if (isText (_wcfg >> _value)) then {
			_res = getText (_wcfg >> _value);
		};
		if (isText (_turcfg >> _value)) then {
			_res = getText (_turcfg >> _value);
		};
	};
	case "ARRAY": {
		if (isArray (_wcfg >> _value)) then {
			_res = getArray (_wcfg >> _value);
		};
		if (isArray (_turcfg >> _value)) then {
			_res = getArray (_turcfg >> _value);
		};
	};

	default { hint format ["ace_sys_sight_adjustment error: unsupported data type %1 value %2", _type, _value] };
};

_res