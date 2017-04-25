/* ace_sys_interaction (.pbo) | (c) 2009 by rocko */
//#define DEBUG_MODE_FULL
#include "script_component.hpp"

with uiNamespace do { ACE_Interaction_Menu = _this select 0 };

	TRACE_1("",(GVAR(targets) select 1));
switch (toUpper (GVAR(targets) select 1)) do {
	case "MAN": {
		GVAR(targets) spawn FUNC(menu_man); TRACE_1("MAN menu","");
	};
	case "STATIC": {
		GVAR(targets) spawn FUNC(menu_static); TRACE_1("STATIC menu","");
	};
	case "SANDBAG": {
		GVAR(targets) spawn FUNC(menu_sandbag); TRACE_1("SANDBAG menu","");
	};
};

false



