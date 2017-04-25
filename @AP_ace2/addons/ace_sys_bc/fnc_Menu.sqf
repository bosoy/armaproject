#include "script_component.hpp"
switch (_this select 0) do
{
	case 11:
	{
		SETVAR ["training", _this select 1, true];
		if (_this select 1) then {
			ace_sys_weapons_lock set [0, false];
			hint "Training Mode Enabled!"
		} else {
			ace_sys_weapons_lock set [0, true];
			hint "Training Mode Disabled!"
		};
		publicVariable "ace_sys_weapons_lock";
	};

	case 13:
	{
		hint "BC: Click on the Map to move the Zone Location";
		[1] call ace_sys_menu_fnc_showMap;
		onMapSingleClick "_pos set [2, 0];ace_dummy = [14,_pos] spawn ace_sys_bc_fnc_menu;onMapSingleClick ''";
	};

	case 14:
	{
		closeDialog 0;
		GVAR(zone_pos) = _this select 1;
		if (count GVAR(zone_selected) > 0) then { [GVAR(zone_selected), GVAR(zone_pos)] call FUNC(moveZone) };
		hint format["BC: Zone Position set to: %1", GVAR(zone_pos)];
	};

	case 15:
	{
		GVAR(zone_size) set [0, _this select 1];
		if (count GVAR(zone_selected) > 0) then { [GVAR(zone_selected), GVAR(zone_size)] call FUNC(resizeZone) };
		hint format["BC: Zone X-size set to: %1m", GVAR(zone_size)];
	};

	case 16:
	{
		GVAR(zone_size) set [1, _this select 1];
		if (count GVAR(zone_selected) > 0) then { [GVAR(zone_selected), GVAR(zone_size)] call FUNC(resizeZone) };
		hint format["BC: Zone Y-size set to: %1m", GVAR(zone_size)];
	};

	case 21:
	{
		hint "BC: Click on the map to move the Player Start Location";
		[1] call ace_sys_menu_fnc_showMap;
		onMapSingleClick "_pos set [2, 0];ace_dummy = [22,_pos] spawn ace_sys_bc_fnc_menu;onMapSingleClick ''";
	};

	case 22:
	{
		GVAR(startPos) set [GVAR(sides_ar) find (GETVAR(_side)), _this select 1];
		publicVariable QUOTE(GVAR(startPos));
		closeDialog 0;
		hint format["BC: Player Position set to: %1",(_this select 1)];
	};

	case 23: {
		GVAR(spawnCrate) = [true,getPos player,getPosASL player];
		publicVariable QUOTE(GVAR(spawnCrate));
		GVAR(spawnCrate) spawn FUNC(spawnCrate);
		hint "Spawn Crate Enabled";
	};

	case 44:
	{
			if (GVAR(crates_disabled)) then {
				GVAR(crates_disabled) = false;
				hint "Enabled Weapon Boxes";
			} else {
				GVAR(crates_disabled) = true;
				hint "Disabled Weapon Boxes";
			};
			publicVariable QUOTE(GVAR(crates_disabled));
	};

	case 51:
	{
		_ar = _this select 1;
		_bla = []; { PUSH(_bla,_x) } forEach GVAR(zone_pos); _ar set [0, _bla];
		_bla = []; { PUSH(_bla,_x) } forEach GVAR(zone_size); _ar set [2, _bla];
		_bla = []; { PUSH(_bla,_x) } forEach (GVAR(AI) select 1); _ar set [5, [GVAR(AI) select 0, _bla]];
		_ar call FUNC(addZone);
		hint format["Zone added: %1", _ar];
	};

	case 52:
	{
		copyToClipboard format['{_x call FUNC(addZone)} forEach %1;', GVAR(zones)];
		hint format["%1 Zones Saved to Clipboard. Execute in a console, RTE command, etc to load.", count GVAR(zones)];
	};

	case 53:
	{
		hint "Importing... See arma2.rpt for errors, or run game with -showScriptErrors";
		call compile copyFromClipboard;
	};

	case 55:
	{
		if (_this select 1 == "") then
		{
			GVAR(zone_selected) = [];
		} else {
			PUSH(GVAR(zone_selected),_this select 1);
		};
		hint ("Zone selection set to: " + str(GVAR(zone_selected)));
	};

	case 60:
	{
		GVAR(commander) = true;
		SETVAR ["modify", true, true];
		[QUOTE(GVAR(mod_handler)), [player] call FUNC(getName)] call CBA_fnc_globalEvent;
		[] spawn COMPILE_FILE(menu_bc);
	};

	case 70:
	{
		_ai = _this select 1;
		_a = [GVAR(ai_hash), _ai] call CBA_fnc_hashGet;
		GVAR(ai) = [_ai, []];
		hint ("Selected AI: " + _ai + ". Available Options: " + str(_a select 0));
		[] spawn COMPILE_FILE(menu_bc);
	};

	case 71:
	{
		_option = _this select 1;
		_options = GVAR(ai) select 1;
		if (_option in _options) then
		{
			_options = _options - [_option];
			GVAR(ai) set [1, _options];
			hint ("Disabled: " + _option + ". Current Options: " + str(_options));
		} else {
			PUSH(_options,_option);
			hint ("Enabled: " + _option + ". Current Options: " + str(_options));
		};
	};

	case 87:
	{
		if (isServer) then
		{
			hint "Not possible on server, please Submit and Start instead";
		} else {
			hint ("BC: Setup Submitted: " + str(count GVAR(zones)) + " Zones, Local zones cleared");
			onMapSingleClick "";
			if (count GVAR(zones) > 0) then { call FUNC(submit) };
		};
	};

	case 88:
	{
		hint ("BC: Setup Submitted: " + str(count GVAR(zones)) + " Zones, Starting Mission...");
		onMapSingleClick "";
		if (count GVAR(zones) > 0) then { call FUNC(submit) };
		sleep 3;
		SETVAR ["start", true, true];
	};

	case 89:
	{
		hint "BC: Queue Cleared!";
		GVAR(zones) = [];
	};
};
