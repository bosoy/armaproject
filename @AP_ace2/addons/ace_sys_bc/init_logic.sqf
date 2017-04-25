#include "script_component.hpp"
#define DEFAULT_SIDES East, West, Resistance, Civilian

ADDON = _this;

LOG(MSG_INIT);

SETVAR ["_state", 0]; // SIX_BC_VALUE

if (isServer) then {
		SETVAR ["ready", false, true];
		SETVAR ["modify", false, true];
		SETVAR ["custom", false, true];
		SETVAR ["training", false, true];
		SETVAR ["start", false, true];
};

if (isNil "ACE_NOSPECT") then { ACE_NOSPECT = false };

// TODO: Move into logic space
GVAR(zones) = [];

GVAR(ai_hash) = [[], ""] call CBA_fnc_hashCreate;
[GVAR(ai_hash), "UPSMON", [["RANDOM", "NOMOVE", "NOFOLLOW", "NOWAIT", "REINFORCEMENT"], { PARAMS_3(_grp,_marker,_options); _ar = [leader _grp, _marker, "SHOWMARKER"]; { PUSH(_ar,_x) } forEach _options; _ar spawn FUNC(upsMON)}]] call CBA_fnc_hashSet;
[GVAR(ai_hash), "UPS", [["RANDOM", "NOMOVE", "NOFOLLOW", "NOWAIT"], { PARAMS_3(_grp,_marker,_options); _ar = [leader _grp, _marker, "SHOWMARKER"]; { PUSH(_ar,_x) } forEach _options; _ar spawn FUNC(ups)}]] call CBA_fnc_hashSet;

GVAR(AI) = ["DAC", ["RANDOM", "REINFORCEMENT"]];

GVAR(start_markers) = ["respawn_east", "respawn_west", "respawn_guerrila", "respawn_civilian"];

GVAR(sides) = [[], civilian] call CBA_fnc_hashCreate;
{[GVAR(sides), _x, call compile _x] call CBA_fnc_hashSet} forEach ["East", "West", "Civilian"];
_i = 0; {[GVAR(sides), _i, call compile _x] call CBA_fnc_hashSet; ADD(_i,1)} forEach ["East", "West", "Civilian"];
[GVAR(sides), "Guerrila", resistance] call CBA_fnc_hashSet;
[GVAR(sides), "PLAgrps", resistance] call CBA_fnc_hashSet;

GVAR(sides_ar) = [DEFAULT_SIDES, sideLogic, sideEnemy];
GVAR(sides_enemies) = [[1, 2], [0, 2], [0,1], [3]];

// TODO: Set in faction configs instead ?
GVAR(sides_colors) = [[], "ColorWhite"] call CBA_fnc_hashCreate;
[GVAR(sides_colors), "East", "ColorRed"] call CBA_fnc_hashSet;
[GVAR(sides_colors), "West", "ColorBlue"] call CBA_fnc_hashSet;
[GVAR(sides_colors), "Guerrila", "ColorOrange"] call CBA_fnc_hashSet;

GVAR(sides_ammoboxes) = [[], "USBasicAmmunitionBox_EP1"] call CBA_fnc_hashCreate;
[GVAR(sides_ammoboxes), east, "TKBasicAmmunitionBox_EP1"] call CBA_fnc_hashSet;
[GVAR(sides_ammoboxes), resistance, "UNBasicAmmunitionBox_EP1"] call CBA_fnc_hashSet;

GVAR(sides_weaponboxes) = [[], "USBasicWeapons_EP1"] call CBA_fnc_hashCreate;
[GVAR(sides_weaponboxes), east, "TKBasicWeapons_EP1"] call CBA_fnc_hashSet;
[GVAR(sides_weaponboxes), resistance, "UNBasicWeapons_EP1"] call CBA_fnc_hashSet;

if (isNil QUOTE(GVAR(commanders))) then { GVAR(commanders) = [] };
if (isNil QUOTE(GVAR(commander))) then { GVAR(commander) = false };

// Prepare Functions & Scripts
FUNC(startpos) = { private ["_index"]; _index = GVAR(sides_ar) find _this; GVAR(startpos) select _index }; // TODO: Change to Hash
[] spawn COMPILE_FILE(init_UPSMON);
FUNC(upsZone) = {
	private ["_cfg", "_grp", "_marker"];
	PARAMS_6(_position,_side,_size,_cfgGroups,_zoneName,_ai);
	_marker = [_zoneName, _position, _size, ([GVAR(sides_colors), _side] call CBA_fnc_hashGet)] call FUNC(marker);
	_cfg = configFile >> "CfgGroups" >> _side;
	{ _cfg = _cfg >> _x } forEach _cfgGroups;

	_grp = [_position, [GVAR(sides), _side] call CBA_fnc_hashGet, _cfg] call BIS_fnc_spawnGroup;
	if !(isNull _grp) then {
		_a = [GVAR(ai_hash), _ai select 0] call CBA_fnc_hashGet;
		[_grp, _marker, _ai select 1] call (_a select 1);
	};

	_grp;
};
[] call COMPILE_FILE(init_dac);

if (isServer) then {
	// TODO: Also on client, or leave up to RTE, etc?
	{ [_x] call CBA_fnc_createCenter } forEach [DEFAULT_SIDES];
	Resistance setFriend [East, 0];
	East setFriend [Resistance, 0];
	West setFriend [East, 0];
	East setFriend [West, 0];
	// Setup menu options
	//ace_sys_menu setVariable ["config_weapons", true, true];
	//ace_sys_menu setVariable ["config_group", true, true];
	//ace_sys_menu setVariable ["config_character", true, true];
	//ace_sys_menu setVariable ["config_teamstatus", true, true];

	GVAR(hash) = [[], -1] call CBA_fnc_hashCreate;
	GVAR(zones_built) = [];

	PREP(handler);
	PREP(spawnZone);

	FUNC(marker) = {
		PARAMS_4(_marker,_position,_size,_color);
		createMarkerLocal [_marker, _position];
		_marker setMarkerShapeLocal "RECTANGLE";
		_marker setMarkerBrushLocal "BORDER";
		_marker setMarkerSizeLocal _size;
		_marker setMarkerColorLocal _color;

		_marker;
	};

	// TODO: Handle better
	FUNC(handler_move) = {
		PARAMS_2(_zones,_position);
		{
			private ["_z"]; // "_marker2",
			_z = _x;
			{
				if (_x select 4 == _z) exitWith {
					_x set [0, _position];
					switch ((_x select 5) select 0) do {
						case "DAC": {
							[(call compile _z), _position, [], 0, 0, 0] call DAC_fChangeZone;
						};
						default {
							_z setMarkerPosLocal _position;
						};
					};
				}
			} forEach GVAR(zones_built);
		} forEach _zones;
	};

	FUNC(handler_resize) = {
		PARAMS_2(_zones,_size);
		{
			_z = _x;
			{
				if (_x select 4 == _z) exitWith {
					_x set [2, _size];
					switch ((_x select 5) select 0) do {
						case "DAC": {
							[(call compile _z), [], _size + [0], 0, 0, 0] call DAC_fChangeZone;
						};
						default {
							_z setMarkerSizeLocal _size;
						};
					};
				}
			} forEach GVAR(zones_built);
		} forEach _zones;
	};

	FUNC(modhandler) = { if !(_this in GVAR(commanders)) then { PUSH(GVAR(commanders),_this); publicVariable QUOTE(GVAR(commanders)) } };

	[QUOTE(GVAR(mod_handler)), {_this call FUNC(modhandler)}] call CBA_fnc_addEventHandler;
	[QUOTE(GVAR(handler)), {_this call FUNC(handler)}] call CBA_fnc_addEventHandler;
	[QUOTE(GVAR(handler_move)), {_this call FUNC(handler_move)}] call CBA_fnc_addEventHandler;
	[QUOTE(GVAR(handler_resize)), {_this call FUNC(handler_resize)}] call CBA_fnc_addEventHandler;
} else {
	waitUntil {SLX_XEH_MACHINE select 5};
};

if (isNil QUOTE(GVAR(crates_disabled))) then { GVAR(crates_disabled) = false };
if (isNil QUOTE(GVAR(TRAINING))) then { GVAR(TRAINING) = false };
if (isNil QUOTE(GVAR(SUPPORT))) then { GVAR(SUPPORT) = [[time, 5], [time, 5]] }; // TODO: Not Side sensitive!
if (isNil QUOTE(GVAR(startpos))) then { GVAR(startpos) = call compile format["%1", GVAR(default_startpos)] }; // copy array
if (isNil "ace_nodisablerespawn") then { ace_nodisablerespawn = false };
if (isNil QUOTE(GVAR(spawnCrate))) then { GVAR(spawnCrate) = [] };

if (SLX_XEH_MACHINE select 0) then {
	SETVAR ["_side", side player];

	// Make players captive to make sure they don't get attacked before we're ready
	player setCaptive true;

	GVAR(spawnCrate_done) = false;

	GVAR(ENEMY_SIDE) = 0;
	_id = GVAR(sides_ar) find GETVAR(_side);
	if (_id > -1) then {
		_enemies = GVAR(sides_enemies) select _id;
		GVAR(ENEMY_SIDE) = _enemies select 0;
	};

	// RespawnType: Base
	[] spawn COMPILE_FILE(player_disableRespawn);

	GVAR(id) = 0; GVAR(zones_mine) = []; GVAR(zone_selected) = [];
	GVAR(zone_size) = [250, 250]; GVAR(zone_pos) = [0,0,0];
	if (isNil QUOTE(GVAR(hash))) then {
		GVAR(hash) = [[], 0] call CBA_fnc_hashCreate;
	} else {
		_v = [GVAR(hash), [player] call FUNC(getName)] call CBA_fnc_hashGet;
		if (_v > 0) then { GVAR(id) = _v };
	};

	FUNC(spawnCrate) = {
		if (GVAR(spawnCrate_done)) exitWith {}; // Already done
		GVAR(spawnCrate_done) = true;
		PARAMS_3(_enabled,_pos,_posASL);

		_crate = ([GVAR(sides_weaponboxes), GETVAR(_side)] call CBA_fnc_hashGet) createVehicleLocal _pos;
		_crate setPosASL _posASL;
		player reveal _crate;

		// TODO: Fix Lame
		_crate spawn {
			sleep 1; sleep 1; sleep 1;
			[player] call FUNC(handleWeapons);
			_act = player addAction ["Open Gear Menu", QUOTE(PATHTO_F(fnc_openBox)), _this];

			while {! (GETVAR(ready)) } do {
				sleep 1;
				if !(alive player) then {
					player removeAction _act;
					waitUntil {alive player};
					sleep 1; sleep 1; sleep 1;
					player reveal _crate;
					_act = player addAction ["Open Gear Menu", QUOTE(PATHTO_F(fnc_openBox)), _this];
				};
			};
			player removeAction _act;
		};

		clearMagazineCargo _crate; clearWeaponCargo _crate;

		_ar = [player] call ace_fnc_enum;
		_weapons = []; {
			{ PUSH(_weapons,_x select 0) } forEach _x;
		} forEach (_ar select 0);
		{ _crate addWeaponCargo [_x, 5] } forEach _weapons;

		_ar = [_weapons + ["Throw", "Put"]] call ace_fnc_enumMagazines;
		_magazines = []; {
			{ PUSH(_magazines,_x select 0) } forEach _x;
		} forEach (_ar select 0);
		{ _crate addMagazineCargo [_x, 15] } forEach _magazines;
	};

	FUNC(moveZone) = {
		PARAMS_2(_zones,_position);
		[QUOTE(GVAR(handler_move)), _this] call CBA_fnc_globalEvent;
		{
			_z = _x;
			_marker = format['%1_l', _z];
			_marker2 = format['%1_l2', _marker];
			_marker setMarkerPosLocal _position;
			_marker2 setMarkerPosLocal _position;
			{ if (_x select 4 == _z) exitWith { _x set [0, _position] } } forEach GVAR(zones_mine);
		} forEach _zones;
	};

	FUNC(resizeZone) = {
		PARAMS_2(_zones,_size);
		[QUOTE(GVAR(handler_resize)), _this] call CBA_fnc_globalEvent;
		{
			_z = _x;
			_marker = format['%1_l', _z];
			_marker setMarkerSizeLocal _size;
			{ if (_x select 4 == _z) exitWith { _x set [2, _size] } } forEach GVAR(zones_mine);
		} forEach _zones;
	};

	FUNC(addZone) = {
		_name = [player] call FUNC(getName);
		_this set [4, _name + "_" + str(GVAR(id))];
		ADD(GVAR(id),1);
		PUSH(GVAR(zones),_this);
		if (isServer) then { if !(_name in GVAR(commanders)) then { PUSH(GVAR(commanders),_name) } };
	};

	FUNC(submit) = {
		// Create markers of zones owned by player
		{ // TODO: Allow to turn these off and on.
			private ["_marker", "_marker2"];
			_marker = format["%1_l", _x select 4];
			_marker2 = format['%1_l2', _marker];
			createMarkerLocal [_marker, _x select 0];
			createMarkerLocal [_marker2, _x select 0];
			_marker setMarkerShapeLocal "RECTANGLE";
			_marker setMarkerBrushLocal "BORDER";
			_marker2 setMarkerShapeLocal "ICON";
			_marker2 setMarkerTypeLocal "DOT";
			_marker setMarkerSizeLocal (_x select 2);
			_marker setMarkerColorLocal ([GVAR(sides_colors), _x select 1] call CBA_fnc_hashGet);
			_marker2 setMarkerTextLocal _marker;
			_marker2 setMarkerColorLocal ([GVAR(sides_colors), _x select 1] call CBA_fnc_hashGet);
		} forEach GVAR(zones);

		{ PUSH(GVAR(zones_mine),_x) } forEach GVAR(zones);
		if (isServer) then {
			if (GETVAR(start)) then	{ [] spawn { { _x call FUNC(spawnZone) } forEach GVAR(zones); GVAR(zones) = [] } };
		} else {
			[QUOTE(GVAR(handler)), [[player] call FUNC(getName), GVAR(id), GVAR(zones)]] call CBA_fnc_globalEvent;
			GVAR(zones) = [];
		};
	};

	// TODO: Export to sys_menu
	FUNC(addSubMenu) = {
		private ["_item"];
		PARAMS_3(_menu,_title,_short);
		_item = [ ["Item", _title], ["SubMenu", _short] ];
		_menu set [count _menu, _item];
		if ("break" in _this) then { _menu set [count _menu, [ ["Item", "-"] ]] };
		_short;
	};

	FUNC(addMenu) = {
		private ["_item"];
		PARAMS_4(_menu,_title,_short,_items);
		_item = [_short, [["Caption", _title], ["Items", _items]]];
		_menu set [count _menu, _item];
		_short;
	};

	FUNC(addAction) = {
		private ["_item"];
		PARAMS_3(_menu,_title,_action);
		_item = [ ["Item", _title], ["Action", _action] ];
		if ("noclose" in _this) then { _item set [count _item, ["Close", false]] };
		_menu set [count _menu, _item];
		true;
	};

	FUNC(addHeader) = {
		PARAMS_2(_menu,_title);
		_menu set [count _menu, [ ["Item", _title], ["Close", false] ]];
		_short;
	};

	QUOTE(GVAR(startPos)) addPublicVariableEventHandler {
		PARAMS_2(_var,_val);
		{ _x setMarkerPosLocal (GETVAR(_side) call FUNC(startpos)) } forEach GVAR(start_markers); // Set markers to base location
	};

	// Incase JIP
	if (count GVAR(spawnCrate) > 0) then {
		GVAR(spawnCrate) spawn FUNC(spawnCrate);
	};

	QUOTE(GVAR(spawnCrate)) addPublicVariableEventHandler {
		_data = _this select 1;
		if (_data select 0) then { _data spawn FUNC(spawnCrate) };
	};

	[] spawn {
		// Marker tracking of local zone queue
		_markers = [];
		while {true} do {
			_i = 0;
			{
				private ["_marker", "_marker2"];
				_marker = format['GVAR(mark)_%1', _i];
				_marker2 = format['%1_2', _marker];
				if (count _markers == _i) then {
					createMarkerLocal [_marker, _x select 0];
					createMarkerLocal [_marker2, _x select 0];
					_marker setMarkerShapeLocal "RECTANGLE";
					_marker setMarkerBrushLocal "BORDER";
					_marker2 setMarkerShapeLocal "ICON";
					_marker2 setMarkerTypeLocal "DOT";
					PUSH(_markers,_marker);
				};
				_marker setMarkerSizeLocal (_x select 2);
				_marker setMarkerColorLocal ([GVAR(sides_colors), _x select 1] call CBA_fnc_hashGet);
				_marker2 setMarkerTextLocal _marker;
				_marker2 setMarkerColorLocal ([GVAR(sides_colors), _x select 1] call CBA_fnc_hashGet);
				ADD(_i,1);
			} forEach GVAR(zones);
			if (count _markers > count GVAR(zones)) then {
				for "_i" from (count GVAR(zones)) to (count _markers - 1) do {
					private ["_marker", "_marker2"];
					_marker = _markers select _i;
					_marker2 = format['%1_2', _marker];
					deleteMarkerLocal _marker; deleteMarkerLocal _marker2;
				};
				_markers reSize (count GVAR(zones));
			};
			sleep 2;
			if (GETVAR(start) && ! GVAR(commander)) exitWith {};
		};
		{
			_marker2 = format['%1_2', _x];
			deleteMarkerLocal _x; deleteMarkerLocal _marker2;
		} forEach _markers;
	};

	[] spawn COMPILE_FILE(init_menu);
};

SETVAR ["_state", 1];

waitUntil { GETVAR(modify) || time > 45 };
if (GETVAR(modify)) then { waitUntil { GETVAR(start) } };

SETVAR ["_state", 2];
// DAC/AI stuff

SETVAR ["_state", 4];
// Runs after DAC has sucessfully Initialized on server and client

if (isServer) then {
	// TODO: Change to object var?
	publicVariable QUOTE(GVAR(startpos));
	publicVariable QUOTE(GVAR(commanders));

	// Spawn the zones
	{ _x call FUNC(spawnZone) } forEach GVAR(zones);
	GVAR(zones_mine) = [];  // TEMP
	{ PUSH(GVAR(zones_mine),_x) } forEach GVAR(zones); // TEMP
	GVAR(zones) = [];

	if !(isNil QUOTE(GVAR(DAC_INIT))) then { waitUntil {!(isNil "DAC_Basic_Value")}; waitUntil {DAC_Basic_Value > 0} };
	SETVAR ["ready", true, true];
};

SETVAR ["_state", 5];
waitUntil { GETVAR(ready) };

SETVAR ["_state", 6];
if (SLX_XEH_MACHINE select 0) then {
	// Put players on right camp position
	sleep 3;
	player setCaptive false;
	_pos = (GETVAR(_side)) call FUNC(startpos);
	["Preloading Camera... " + str(_pos), QUOTE(ADDON)] call CBA_fnc_debug;

	if !(GVAR(crates_disabled)) then {
		_crate = ([GVAR(sides_weaponboxes), GETVAR(_side)] call CBA_fnc_hashGet) createVehicleLocal _pos;
		clearMagazineCargo _crate; clearWeaponCargo _crate;
		_ar = [player] call ace_fnc_enum;
		_weapons = [];
		{ { PUSH(_weapons,_x select 0) } forEach _x } forEach (_ar select 0);
		{ _crate addWeaponCargo [_x, 5] } forEach _weapons;

		_ar = [_weapons + ["Throw", "Put"]] call ace_fnc_enumMagazines;
		_magazines = [];
		{ { PUSH(_magazines,_x select 0) } forEach _x } forEach (_ar select 0);
		{ _crate addMagazineCargo [_x, 15] } forEach _magazines;
	};

	waitUntil { preloadCamera _pos };
	(vehicle player) setVelocity [0, 0, 0];
	player setPos [(_pos select 0) - (random 3), (_pos select 1) + (random 3), 0];
	["Battle Center is Successfully Initialized", QUOTE(ADDON)] call CBA_fnc_debug;

	createMarkerLocal [QUOTE(GVAR(start)), _pos];
	QUOTE(GVAR(start)) setMarkerShapeLocal "ICON";
	QUOTE(GVAR(start)) setMarkerTypeLocal "Flag1";
	QUOTE(GVAR(start)) setMarkerColorLocal "ColorBlack";
	QUOTE(GVAR(start)) setMarkerTextLocal "HQ";
};
