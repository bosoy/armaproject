#define DEBUG_MODE_FULL
#include "script_component.hpp"

PUSH(GVAR(zones_built),_this);

switch ((_this select 5) select 0) do {
	case "DAC": {
		_this call FUNC(dacZone);
	};

	default { // "UPS", "UPSMON"
		_this call FUNC(upsZone);
	};
};
