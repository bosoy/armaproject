// Included from menu_bc.sqf
#include "script_component.hpp"

// GVAR(DAC_Settings) = [[1,0,0],[3,3,20,6],[3,3,20,6],[3,3,20,6],[2,2,50,0,100,10],[0,0,0,0,1]];
//                         0          1        2          3            4               5

// Menu entries
#define DAC_AMOUNT [[1, "1"], [2, "2"], [3, "3"], [4, "4"], [5, "5"], [10, "10"]]
#define DAC_SIDES [[0, "East"], [1, "West"], [2, "Guerilla"], [3, "Civilian"]]
#define DAC_WAYPOINTS [[2, "2"], [3, "3"], [4, "4"], [5, "5"], [10, "10"], [20, "20"]]
#define DAC_TOTALWAYPOINTS [[10, "10"], [20, "20"], [30, "30"], [40, "40"], [50, "50"], [75, "75"], [100, "100"], [200, "200"]]
// These seem to not function properly yet
#define DAC_WAYPOINTCONFIGS [[0, "0"], [1, "1"], [2, "2"], [3, "3"], [4, "4"]]
#define DAC_UNIT_CONFIGS [ \
   [ [1000, "Russian Army"], [1001, "Takistani Army"], [1002, "Chedaki Insurgents"], [1003, "Takistani Militia"] ], \
   [ [1100, "US Army - Desert Camo"], [1101, "USMC - Woodland Camo"], [1102, "German KSK - Desert Camo"], [1103, "US Army - Delta Force"], [1104, "CDF"] ], \
   [ [1200, "NAPA Guerillas"], [1201, "Czech Army - Desert Camo"], [1202, "UN"] ], \
   [ [1300, "Civilians - Cherno Russia"], [1301, "Civilians - Takistan"] ] ]


_dac_sizes = []; _i = 1;
{ _dac_sizes set [count _dac_sizes, [_i, format["%1-%2",_x select 0,_x select 1]]]; ADD(_i,1) } forEach DAC_AI_Count_Level;


// Functions
_amount = {
	_title = "Amount of Groups"; _short = format["DAC_%1_Amount", _this]; _sItems = [];
	[_mItems, _title, _short] call FUNC(addSubMenu);
	{ [_sItems, _x select 1, format["[11, [%1,%2]] call %3", _x select 0, _this, QUOTE(FUNC(menu_dac))], "noclose"] call FUNC(addAction); } forEach DAC_AMOUNT;
	[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);
};

_sizes = {
	_title = "Size of Group"; _short = format["DAC_%1_Sizes", _this]; _sItems = [];
	[_mItems, _title, _short] call FUNC(addSubMenu);
	{ [_sItems, _x select 1, format["[11, [%1,%2]] call %3", _x select 0, _this, QUOTE(FUNC(menu_dac))], "noclose"] call FUNC(addAction); } forEach _dac_sizes;
	[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);
};

_waypoints = {
	_title = "Waypoints per Group"; _short = format["DAC_%1_WPs", _this]; _sItems = [];
	[_mItems, _title, _short] call FUNC(addSubMenu);
	{ [_sItems, _x select 1, format["[11, [%1,%2]] call %3", _x select 0, _this, QUOTE(FUNC(menu_dac))], "noclose"] call FUNC(addAction); } forEach DAC_WAYPOINTS;
	[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);
};

// TODO: Perhaps these should be auto calced ? (groups*waypointspergroup+1)
_totalWaypoints = {
	_title = "Total Waypoints"; _short = format["DAC_%1_WPs", _this]; _sItems = [];
	[_mItems, _title, _short] call FUNC(addSubMenu);
	{ [_sItems, _x select 1, format["[11, [%1,%2]] call %3", _x select 0, _this, QUOTE(FUNC(menu_dac))], "noclose"] call FUNC(addAction); } forEach DAC_TOTALWAYPOINTS;
	[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);
};


_def = {
	[_mainItems, _mTitle, _mShort] call FUNC(addSubMenu);
	_ar = GVAR(DAC_Settings) select _this;
	if (count _ar > 0) then {
		if (count _ar > 1) then {
			// Groups #
			[0, _this] call _amount;
			// Size of groups 1..4 (from dac configs)
			[1, _this] call _sizes;
			// Total Waypoints #
			[2, _this] call _totalWaypoints;
			// Waypoints per group #
			[3, _this] call _waypoints;
		} else {
			// Total Waypoints #
			[0, _this] call _totalWaypoints;
		};
	};
	// Turn On/Off
	[_mItems, "-"] call FUNC(addHeader);
	[_mItems, "Switch Off/On", format["[10, %2] call %1", QUOTE(FUNC(menu_dac)), _this]] call FUNC(addAction);
	[_mItems, "Switch between WaypointsOnly/Full", format["[13, %2] call %1", QUOTE(FUNC(menu_dac)), _this]] call FUNC(addAction);
};


// Menu

_mTitle = "DAC Infantry >"; _mShort = "DAC_infantry"; _mItems = [];
DACINF call _def;
[_menuStructureArray, _mTitle, _mShort, _mItems] call FUNC(addMenu);

_mTitle = "DAC Vehicles >"; _mShort = "DAC_vehicles"; _mItems = [];
DACVEH call _def;
[_menuStructureArray, _mTitle, _mShort, _mItems] call FUNC(addMenu);

_mTitle = "DAC Tanks >"; _mShort = "DAC_tanks"; _mItems = [];
DACTNK call _def;
[_menuStructureArray, _mTitle, _mShort, _mItems] call FUNC(addMenu);


_ar = GVAR(DAC_Settings) select DACAIR;
if (count _ar > 0) then {
	if (count (GVAR(DAC_Settings) select DACAIR) > 3) then {
		_mTitle = "DAC Camps >"; _mShort = "DAC_air"; _mItems = [];
		[_mainItems, _mTitle, _mShort] call FUNC(addSubMenu);
		// -- Camps
		// Camps #
		[0, DACAIR] call _amount;
		// Size of groups 1..4 (from dac configs)
		[1, DACAIR] call _sizes;
		// Radius #
		// Vehicles and/or Infantry: 0 (both)
		// Respawns #
	} else {
		_mTitle = "DAC Air >"; _mShort = "DAC_air"; _mItems = [];
		[_mainItems, _mTitle, _mShort] call FUNC(addSubMenu);
		if (count _ar > 1) then {
			// -- Air
			// Groups #
			[0, DACAIR] call _amount;
			// Size of groups 1..4 (from dac configs)
			[1, DACAIR] call _sizes;
			// Waypoints per group #
			[2, DACAIR] call _waypoints;
		} else {
			// Total Waypoints #
			[0, DACAIR] call _totalWaypoints;
		};
	};
	[_mItems, "-"] call FUNC(addHeader);
	[_mItems, "Switch Between Camp/Air", format["[5] call %1", QUOTE(FUNC(menu_dac))]] call FUNC(addAction);
	if (count (GVAR(DAC_Settings) select DACAIR) < 4) then { [_mItems, "Switch between WaypointsOnly/Full", format["[13, %2] call %1", QUOTE(FUNC(menu_dac)), DACAIR]] call FUNC(addAction) };
} else {
	_mTitle = "DAC Air/Camps >"; _mShort = "DAC_air"; _mItems = [];
	[_mainItems, _mTitle, _mShort] call FUNC(addSubMenu);
	[_mItems, "-"] call FUNC(addHeader);
};
[_mItems, "Switch Off/On", format["[10, %2] call %1", QUOTE(FUNC(menu_dac)), DACAIR]] call FUNC(addAction);
[_menuStructureArray, _mTitle, _mShort, _mItems] call FUNC(addMenu);


_mTitle = "DAC Side >"; _mShort = "DAC_side"; _mItems = [];
[_mainItems, _mTitle, _mShort] call FUNC(addSubMenu);
// Side # - 0 east etc - at this time, also changes UnitConfig,BehavConfig and CampConfig
_title = "Side"; _short = "DAC_side_side"; _sItems = [];
[_mItems, _title, _short] call FUNC(addSubMenu);
{ [_sItems, _x select 1, format["[21, %1] call %2", _x select 0, QUOTE(FUNC(menu_dac))]] call FUNC(addAction); } forEach DAC_SIDES;
[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);


// UnitConfiguration # - 0 east etc (corresponds to DAC_UnitsConfig)
_title = "Select Faction"; _short = "DAC_side_unitconfig"; _sItems = [];
[_mItems, _title, _short] call FUNC(addSubMenu);
{ [_sItems, _x select 1, format["[22, %1] call %2", _x select 0, QUOTE(FUNC(menu_dac))], "noclose"] call FUNC(addAction); } forEach (DAC_UNIT_CONFIGS select GVAR(DAC_SIDE));
[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);


// BehaviourConfiguration # - 0 east etc (corresponds to DAC_BehaviourConfig)
// Camp configuration # - 0 east etc (corresponds to DAC_CampConfig)
// Waypoint configuration # - 0 optional
_title = "Waypoint Config"; _short = "DAC_Side_WaypointConfig"; _sItems = [];
[_mItems, _title, _short] call FUNC(addSubMenu);
{ [_sItems, _x select 1, format["[11, [%1,%2]] call %3", _x select 0, [4, DACSIDE], QUOTE(FUNC(menu_dac))], "noclose"] call FUNC(addAction); } forEach DAC_WAYPOINTCONFIGS;
[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);

[_menuStructureArray, _mTitle, _mShort, _mItems] call FUNC(addMenu);


_mTitle = "DAC Settings >"; _mShort = "DAC_settings"; _mItems = [];
[_mainItems, _mTitle, _mShort, "break"] call FUNC(addSubMenu);
// DACGEN
_title = "Zone ID"; _short = "DAC_zoneid"; _sItems = [];
[_mItems, _title, _short] call FUNC(addSubMenu);
for "_i" from 1 to 15 do { [_sItems, "Set Zone ID to " + str(_i), format["[12,%1] call %2", _i, QUOTE(FUNC(menu_dac))], "noclose"] call FUNC(addAction); };
[_menuStructureArray, _title, _short, _sItems] call FUNC(addMenu);
// ZoneID - 0 // Needed for linking
// Status - 0 // activated. 1 is deactivated - activate later.
// Events - 0
[_menuStructureArray, _mTitle, _mShort, _mItems] call FUNC(addMenu);

[_mainItems, "Save DAC Zone", QUOTE([1] call FUNC(menu_dac))] call FUNC(addAction);
[_mainItems, "Show Zone Settings", QUOTE([0] call FUNC(menu_dac)), "noclose"] call FUNC(addAction);
[_mainItems, "-"] call FUNC(addHeader);
