#include "script_component.hpp"

_mainItems = []; _MenuStructureArray = [];

[_mainItems, "Return to BC Menu", QUOTE([] spawn COMPILE_FILE(menu_bc))] call FUNC(addAction);

_side = configFile >> "CfgGroups" >> _this;

for "_j" from 0 to (count _side) - 1 do {
	_faction = _side select _j;
	if (isClass _faction) then {
		_title3 = format["%1 >", configName(_faction)]; _short3 = format["spawn_%1_%2", configName(_side), configName(_faction)]; _fitems = [];
		[_mainItems, _title3, _short3] call FUNC(addSubMenu);
		for "_k" from 0 to (count _faction) - 1 do {
			_type = _faction select _k;
			if (isClass _type) then {
				_title4 = format["%1 >", configName(_type)]; _short4 = format["spawn_%1_%2_%3", configName(_side), configName(_faction), configName(_type)]; _sitems = [];
				[_fItems, _title4, _short4] call FUNC(addSubMenu);
				for "_l" from 0 to (count _type) - 1 do {
					_squad = _type select _l;
					if (isClass _squad) then {
						_title5 = format["%1 >", configName(_squad)]; _short5 = format["spawn_%1_%2_%3_%4", configName(_side), configName(_faction), configName(_type), configName(_squad)];
						[_sitems, format["%1", getText(_squad >> "name")], format['[51, [%5, "%1", %6, ["%2", "%3", "%4"]]] spawn FUNC(menu)', configName(_side), configName(_faction), configName(_type), configName(_squad), 0, 0], "noclose"] call FUNC(addAction);
					};
				};
				[_menuStructureArray, _title4, _short4, _sitems] call FUNC(addMenu);
			};
		};
		[_menuStructureArray, _title3, _short3, _fitems] call FUNC(addMenu);
	};
};

[_MenuStructureArray, "Spawn >", "MainMenu", _mainitems] call FUNC(addMenu);

//-----------------------------------------------------------------------------
// Create Menu
//["CreatePopupMenu.sqf", _MenuStructureArray] call fn_DebugAppend; // debug
_MenuStructureArray spawn COMPILE_FILE2(PATHTO_SYS(PREFIX,sys_menu,PopupMenu));
//-----------------------------------------------------------------------------
