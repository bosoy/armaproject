//#define DEBUG_MODE_FULL
#include "script_component.hpp"

if (GVAR(airportevents)) exitWith { false };

switch (GVAR(ils)) do {
	case false: {
		TRACE_1("activated","");
		if !(visibleMap) then {
			[vehicle player] spawn COMPILE_FILE(ofpec_open_airfieldselector);
		};
	};
	case true: {
		TRACE_1("deactivated","");
		GVAR(ils) = false;
		playSound "ofpec_clear";
	};
};
false
