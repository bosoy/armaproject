#include "script_component.hpp"

PARAMS_1(_weap);

switch ([_weap] call FUNC(getType)) do {
	case 1: {
		_type = "RIFLE";
	};
	case 2: {
		_type = "PISTOL";
	};
	case 3: {
		_type = "SNIPER";
	};
	case 4: {
		_type = "LAUNCHER";
	};
	case 5: {
		_type = "MG";
	};
	case 6: {
		_type = "AR";
	};
	case 4094: {
		_type = "RUCK";
	};
	case 4095: {
		_type = "ITEM";
	};
	case 4096: {
		_type = "EQUIP";
	};
	// Official Item type
	case 131072: {
		_type = "ITEM";
	};
};
_type;
