#include "script_component.hpp"

/*
	Six - Battle Center by Sickboy (sb_at_dev-heaven.net)
*/
PREP(menuAI);
PREP(menuBI);
PREP(menu);

if (isNil "ace_sys_menu_CUSTOM") then { ace_sys_menu_CUSTOM = [] };

ace_sys_menu_CUSTOM set [count ace_sys_menu_custom, {
		_mainItems = _mainItems + [[ ["Item", "Battle Center Menu >"], ["Action", QUOTE([] spawn COMPILE_FILE(menu_bc))] ]];
	}
];
