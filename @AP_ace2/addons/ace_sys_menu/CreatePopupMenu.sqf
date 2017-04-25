#include "script_component.hpp"

// Desc: A sample menu array structure definition, for use by PopupMenu.sqf.
// Concept By: Dr Eyeball
// Version: 1.1 (May 2007)
//-----------------------------------------------------------------------------
// Notes: Avoid using "format" command inside a caption, Item or Action string, since PopUpMenu will call SIX_PUM3_ReplaceCommonParams for parameter substitution.
//-----------------------------------------------------------------------------
private ["_action", "_callsignList_MenuArray", "_group", "_groupList_MenuArray", "_i", "_items", "_mainItems", "_MenuStructureArray", "_rf", "_no"];

/*
	// TODO: Alternative implementation through Macros
	#define MENU_MENU(menu,caption,items) [menu, [ ["Caption", caption], ["Items", items] ] ]
	#define MENU_SUB(item,submenu) [ ["Item", item], ["SubMenu", submenu] ]
	#define MENU_ACTION(item,action) [ ["Item", item], ["Action", action] ]

	_item = "Test";
	_action = "[1,2,3] spawn test";
	MENU_ACTION(_item,_action);

	_item = "Test2";
	_subMenu = "Test2b";
	MENU_SUB(_item,_subMenu);

	_menu = "Test3";
	_caption = "Test3 menu";
	_items = [ MENU_SUB(_item,_subMenu), MENU_ACTION(_item,_action) ];
	MENU_MENU(_menu,_caption,_items);
*/

// TODO: Allow optional parameters, like ["Close", false]
// TODO: Globalize functions and use them across all menu operations
_fnc_createActionMenu = {
	PARAMS_2(_item,_action);
	[
		["Item", _item],
		["Action", _action]
	];
};

_fnc_createSubMenu = {
	PARAMS_2(_item,_subMenu);
	[
		["Item", _item],
		["SubMenu", _subMenu]
	];
};

_fnc_createMenu = {
	PARAMS_3(_menu,_caption,_items);
	[_menu,
		[
			["Caption", _caption],
			["Items", _items]
		]
	];
};

_rf = serverCommandAvailable "#kick"; if !(isNil "ace_referee") then { if (ace_referee) then { _rf = true } };
_mainItems = []; _MenuStructureArray = [];
_group = group player;

//-----------------------------------------------------------------------------
// Group Commands Menu
if (GETVAR(config_group)) then {
	///////////////
	// TODO: If player and grouplist are set in global variables, then the objects can be added to those arrays instead of using GVAR(PL) and GVAR(GR)
	////////////////

	//-----------------------------------------------------------------------------
	// Player Group list
	GVAR(GR) = []; if (isNil QUOTE(GVAR(teleported))) then { GVAR(teleported) = false };
	_groupList_MenuArray = []; _teleportList_MenuArray = [];
	_i = 0; _leaders = []; _players = [] call CBA_fnc_players;
	private ["_config"];
	_config = ADDON getVariable "config_groups_commands";
	if (isNil "_config") then { _config = false };


	if (_config) then { _mainItems = _mainItems + [["Group Commands (CAUTION!) >", "Groups"] call _fnc_createSubMenu] };
	if !(GVAR(teleported)) then {
		_mainItems = _mainItems + [["Teleport (CAUTION!) >", "Teleport"] call _fnc_createSubMenu];
	};
 {
		if (_x == leader _x && side _x == side player) then {
			PUSH(_leaders,_x);
		};
	} forEach _players;
 {
		_grp = group _x;
		_no = false;
		if !(isNil "ace_main_dummyGroup") then { if (_grp == ace_main_dummyGroup) then { _no = true } };

		if (_grp != _group && str(_grp) != "<NULL-group>" && !_no) then {
			GVAR(GR) set [_i, _grp];
			_action = format["player setRank 'CORPORAL'; [player] join (ace_sys_menu_GR select %1)", _i];
			_groupList_MenuArray set [_i, [(str(_grp)+", Leader: "+name(leader _grp)), _action] call _fnc_createActionMenu];

			_action = format["player setPos (getPos leader (ace_sys_menu_GR select %1)); " + QUOTE(GVAR(teleported) = true), _i];
			_teleportList_MenuArray set [_i, [(str(_grp)+", Leader: "+name(leader _grp)), _action] call _fnc_createActionMenu];
			_i = _i + 1;
		};
	} forEach _leaders;

	_items =
	[
		[ ["Item", "Join a group >"], ["SubMenu", "GroupList"], ["UserList", true] ],
		[ ["Item", "Become a new group"], ["Action", "player setRank 'LIEUTENANT'; [player] join grpNull"]	]
	];

	//-----------------------------------------------------------------------------
	// Groupsmenu structure
	_MenuStructureArray = _MenuStructureArray+
	[
		["Groups", "Groups", _items] call _fnc_createMenu,
		["GroupList", "GroupList", _groupList_MenuArray] call _fnc_createMenu,
		["Teleport", "Teleport", _teleportList_MenuArray] call _fnc_createMenu
	];


	//-----------------------------------------------------------------------------
	// Callsignlist IF groupleader
	if (player == leader _group) then {
		private ["_squads", "_designations", "_subItems", "_action", "_j", "_i", "_squad"];
		if (_config) then { _mainItems = _mainItems + [[ ["Item", "Group Callsigns >"], ["SubMenu", "Callsigns"] ]] };

		// Sort the squads and designations into arrays
		_squads = [];
		_designations = []; {
			_squads = _squads + [_x select 0];
			_designations = _designations + [_x select 1];
		} forEach SIX_Army;

		// Build the Squads + Subgroup menus
		_i = 0; _items = []; {
			_squad = _x;
			// Build Subgroup items
			_subItems = [];
			_j = 0; {
				_action = format["[group player,%1] call CBA_fnc_setGroupCS", [_i,_j]];
				_subItems = _subItems + [ [(_squad + " " + _x), _action] call _fnc_createActionMenu ];
				_j = _j + 1;
			} forEach (_designations select _i);

			// Build Squad Menu
			_MenuStructureArray = _MenuStructureArray + [ [_x, _x, _subItems] call _fnc_createMenu ];

			// Add Squad Menu to Squads Menu
			_items = _items + [ [["Item", _x], ["SubMenu", _x]] ];
			_i = _i + 1;
		} forEach _squads;

		_MenuStructureArray = _MenuStructureArray +	[ ["Callsigns", "Callsigns", _items] call _fnc_createMenu ];
	};
};

//-----------------------------------------------------------------------------
// Options
if (GETVAR(config_laser)) then {
	_mainItems = _mainItems + [[ ["Item", "Options >"], ["SubMenu", QUOTE(GVAR(options))] ]];
	_MenuStructureArray = _MenuStructureArray +	[ [QUOTE(GVAR(options)), "Options >", [ [ ["Item", "dis/enable Laser Marker Tracking >"], ["Action", QUOTE([0] spawn GVAR(Process))] ] ]] call _fnc_createMenu ];
};

//-----------------------------------------------------------------------------
// Line
_mainItems = _mainItems + [[ ["Item", "-"] ]];
if (count GVAR(CUSTOM) > 0) then {
	_items = [];
	{ call _x } forEach GVAR(CUSTOM);
	_mainItems = _mainItems + [[ ["Item", "-"] ]];
};

// _mainItems = _mainItems + [[ ["Item", "Open SPON Map"], ["Action", "closedialog 0; [true] call SPON_Map_show;"], ["Close", false] ]];


//-----------------------------------------------------------------------------
// Configuration Menu
if (GETVAR(config_config)) then {
	_mainItems = _mainItems + [[ ["Item", "Configuration >"], ["SubMenu", "Configuration"] ]];

	_viewdistanceItems = []; {
		_item = [ ["Item", format["%1m", _x]], ["Action", format["[%1] call ace_sys_menu_fnc_viewDistance", _x]], ["Close", false] ];
		PUSH(_viewdistanceItems,_item);
	} forEach [1200, 1500, 2100, 2500, 3100, 3800, 4200, 5000, 7800, 10000];


	// TODO: Functionalize
	_terrainDetailItems =
	[
		[ ["Item", "Low - smoothest, least lag"],
			["Action", "setTerrainGrid 50; hint 'Terrain Detail set to Low'"],
			["Close", false]
		],
		[ ["Item", "Medium - default in multiplayer"],
			["Action", "setTerrainGrid 25; hint 'Terrain Detail set to Medium'"],
			["Close", false]
		],
		[ ["Item", "High - default in singleplayer"],
			["Action", "setTerrainGrid 12.5; hint 'Terrain Detail set to High'"],
			["Close", false]
		],
		[ ["Item", "Very High"],
			["Action", "setTerrainGrid 6.25; hint 'Terrain Detail set to Very High'"],
			["Close", false]
		],
		[ ["Item", "Ultra High - bumpiest, highest lag"],
			["Action", "setTerrainGrid 3.125; hint 'Terrain Detail set to Ultra High'"],
			["Close", false]
		]
	];

	_viewdistanceItems = _viewdistanceItems +
	[
		[ ["Item", "Increase by 100m"], ["Action", "[100, 'up'] call ace_sys_menu_fnc_viewDistance"], ["Close", false] ],
		[ ["Item", "Decrease by 100m"], ["Action", "[100, 'dn'] call ace_sys_menu_fnc_viewDistance"], ["Close", false] ],
		[ ["Item", "Increase by 500m"], ["Action", "[500, 'up'] call ace_sys_menu_fnc_viewDistance"], ["Close", false] ],
		[ ["Item", "Decrease by 500m"], ["Action", "[500, 'dn'] call ace_sys_menu_fnc_viewDistance"], ["Close", false] ]
	];

	_MenuStructureArray = _MenuStructureArray+
	[
		[
			"Configuration",
			"Configuration",
			[
				["Set View Distance >", "ViewDistance"] call _fnc_createSubMenu,
				["Set Terrain Detail >", "TerrainDetail"] call _fnc_createSubMenu
			]
		] call _fnc_createMenu,
		["ViewDistance", "View Distance", _viewdistanceItems] call _fnc_createMenu,
		["TerrainDetail", "Terrain Detail", _terrainDetailItems] call _fnc_createMenu
	];
};

if (ACE_DEBUG_MISS) then {
	_mainItems = _mainItems + [[ ["Item", "Debug >"], ["SubMenu", "Debug"] ]];
	_MenuStructureArray = _MenuStructureArray+
	[
		["Debug", "Debug", [ [ ["Item", "TroopMon"], ["Action", "nul = [] execVM '\CHN_TroopMon\scripts\MonInit.sqf'"] ] ]] call _fnc_createMenu
	];
};

//-----------------------------------------------------------------------------
// Admin Commands Menu
_MenuStructureArray = _MenuStructureArray + (call FUNC(admins));

if (_rf) then {
	SIX_WCRATEPOS = getPos player;
	_mainItems = _mainItems + [["Admin Commands >", "Admin"] call _fnc_createSubMenu];
};


//-----------------------------------------------------------------------------
// Close Menu
_mainItems = _mainItems + [[ ["Item", "Close Menu"], ["Close", true], ["Default", true] ]];

//-----------------------------------------------------------------------------
// Main Menu
_MenuStructureArray = _MenuStructureArray+
[
	["MainMenu", "Six Menu", _mainItems] call _fnc_createMenu
];

// [format["%1", _MenuStructureArray]] call CBA_fnc_debug;

//-----------------------------------------------------------------------------
// Create Menu
//["CreatePopupMenu.sqf", _MenuStructureArray] call fn_DebugAppend; // debug
_MenuStructureArray spawn COMPILE_FILE(PopupMenu);
//-----------------------------------------------------------------------------
