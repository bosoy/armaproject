//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;

LOG(MSG_INIT);

// M86 PDM shot registration
["shotM86PDM", COMPILE_FILE(fnc_fired)] call ACE_fnc_registerSimulation;

PREP(fired_M86PDM);

// Events
if (isServer) then {
	[QGVAR(fired), {_this spawn FUNC(fired_M86PDM)}] call ACE_fnc_addClientToServerEventhandler; // Mine and Trigger creation by server
};
[QGVAR(trip), {_this spawn FUNC(detonate_M49)}] call CBA_fnc_addEventHandler;

// Array for mine ID's | Current number of mines: 21
// Sorting order: 0:M16A1, 1:DM31, 2:OSM4, 3:POMZ, 4:IED, 5:M18A1, 6:MON50, 7:Tripflare, 8:SLAM, 9:C4, 10:Pipebomb, 11: Mine, 12: MineE, 13: DM12, 14: PMN-1, 15: PMN-2, 16: PMN-3, 17: PPM-2, 18: DM16, 19: DM31 AT, 20: DM12B1, 21: DM21 AT
GVAR(mine_ID) = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
GVAR(tripwire_lock) = false;
GVAR(items) = [];
GVAR(ied_phonenumbers) = [];

// PREP
//PREP(exec);

PREP(fired);
PREP(fired_M86PDM);
PREP(handleDamage);

// PREP Actions
PREP(action_submerge);
PREP(action_place_mine);
PREP(action_place_ied);
PREP(action_cutwire);
PREP(action_hidestake);
PREP(action_defuse);
PREP(action_call_ied);
PREP(action_fuse);

// PREP Detonations
PREP(detonate_M18);
PREP(detonate_MON50);
PREP(detonate_POMZ);
PREP(detonate_PMN);
PREP(detonate_M49);
PREP(detonate_M16);
PREP(detonate_M86);
PREP(detonate_SATCHEL);
PREP(detonate_C4);
PREP(detonate_MINE);
PREP(detonate_IED);
PREP(detonate_M2_side);
PREP(detonate_M2_bottom);
PREP(detonate_M2_command);
//PREP(detonate_M2_timer);
PREP(detonate_DM12);

// Fragments and Detonation
PREP(spawnpellets_60);
PREP(spawnpellets_360);

// Debug
FUNC(Debug_Trigger) = {
	PARAMS_1(_mine);
	private ["_trigger","_triggerPos","_triggerArea","_triggerForm","_triggerDir","_PS","_marker"];
	_trigger = _mine call FUNC(get_trigger);
	_triggerPos = getPos _trigger;
	_triggerArea = triggerArea _trigger;
	_triggerForm = if (_triggerArea select 3) then { "RECTANGLE" } else { "ELLIPSE" };
	_triggerDir = _triggerArea select 2;
	TRACE_4("DEBUG",_trigger,_triggerPos,_triggerArea,_triggerForm);
	switch (_triggerForm) do {
		case "ELLIPSE": {
			TRACE_1("Creating ELLIPSE","");
			_PS = "#particlesource" createVehicleLocal _triggerPos;
			_PS setParticleCircle [0.5*(_triggerArea select 0), [0, 0, 0]];
			_PS setParticleRandom [0, [0, 0, 0], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];
			_PS setParticleParams [["\Ca\Data\ParticleEffects\Universal\Universal", 16, 13, 3, 0], "", "Billboard", 1, 3.0141, [0, 0, 1.5], [0, 0, 0], 1, 1.275, 1, 0, [.1, .1], [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]], [1], 1, 0, "", "", _trigger];
			_PS setDropInterval 0.5;
		};
		case "RECTANGLE": {
			TRACE_1("Creating RECTANGLE","");
		};			
	};
	_marker = createMarker [str(_trigger), _triggerPos];
	_marker setMarkerColor "ColorRed";
	_marker setMarkerShape _triggerForm;
	_marker setMarkerBrush "Solid";
	_marker setMarkerSize [(_triggerArea select 0),(_triggerArea select 1)];
	_marker setMarkerDir _triggerDir;
	_marker setMarkerText str(_mine);	
};

// Functions for editor placed mines
FUNC(store_trigger) = {
	/* (c) by rocko */
	PARAMS_2(_mine,_trigger);
	_mine setVariable [QGVAR(trigger),_trigger,true];
	TRACE_2("FUNC_store_trigger",_mine,(_mine getVariable QGVAR(trigger)));
};

FUNC(get_trigger) = {
	/* (c) by rocko */
	PARAMS_1(_mine);
	_trigger = _mine getVariable [QGVAR(trigger),objNull];
	TRACE_1("FUNC_get_trigger",_trigger);
	_trigger
};

FUNC(has_trigger) = {
	PARAMS_1(_mine);
	_trigger = [_mine] call FUNC(get_trigger);
	TRACE_1("FUNC_has_trigger",(!isnull _trigger));
	(!isnull _trigger)
};

FUNC(delete_trigger) = {
	/* (c) by rocko */
	PARAMS_1(_mine);
	_trigger = [_mine] call FUNC(get_trigger);
	if (!isNull _trigger) then {
		deleteVehicle _trigger;
	};
	TRACE_1("FUNC_delete_trigger","");
};

FUNC(createMine) = {
	/* (c) by rocko */
	private ["_pos", "_mine", "_minetype","_z","_offset"];
	_pos = player modelToWorld [0,0,0];
	_offset = if ((player call CBA_fnc_getUnitAnim select 0) == "prone") then { 1 } else {0.5};
	
	_pos set [0, (_pos select 0) + (sin (direction player) * _offset)];
	_pos set [1, (_pos select 1) + (cos (direction player) * _offset)];
	_z = [player] call CBA_fnc_realHeight;
	_pos set [2,_z];
	_minetype = _this;
	_mine = _minetype createVehicle _pos;
	player reveal _mine;
	_mine setDir (direction player);
	_mine setPos _pos;
	_mine call FUNC(set_id);
	[_mine,true,0] call FUNC(set_ready);
	
	TRACE_2("Create mine",_minetype,(isOnRoad player));
};

FUNC(removeMine) = {
	PARAMS_1(_mine);
	if (!isnil "pzn_delete_mine") then {_mine call pzn_delete_mine};deletevehicle _mine;
	TRACE_1("FUNC_remove_mine");
};

FUNC(store_mine) = {
	/* (c) by rocko */
	PARAMS_2(_mine,_trigger);
	_trigger setVariable [QGVAR(mine),_mine,true];
	TRACE_2("FUNC_store_mine",_mine,(_trigger getVariable QGVAR(mine)));
};

FUNC(get_mine) = {
	/* (c) by rocko */
	PARAMS_1(_trigger);
	_mine = _trigger getVariable [QGVAR(mine),objNull];
	TRACE_1("FUNC_get_mine",_mine);
	_mine
};

FUNC(bury_mine) = {
	PARAMS_1(_mine);
	private "_cBB";
	_cBB = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "bury") in [1,2];
	if (_cBB) then {
		_depth = ((_mine selectionPosition "depth_max") select 2) - ((_mine selectionPosition "depth") select 2);
		_level = _mine getVariable [QGVAR(level),0];
		_mine setVariable [QGVAR(level),(_level - 3),true];
		_pos = getPos _mine;
		_pos set [2, ((_pos select 2) - _depth)];
		_mine setPos _pos;
	};
};

FUNC(set_disabled) = {
	/* (c) by rocko */
	PARAMS_1(_mine);
	_mine setVariable [QGVAR(disabled),true,true];
};

FUNC(check_disabled) = {
	/* (c) by rocko */
	PARAMS_1(_mine);
	_r = _mine getVariable [QGVAR(disabled),false];
	TRACE_2("FUNC_check_disabled",_this,_r);
	_r
};

FUNC(disabled) = {
	/* (c) by rocko */
	PARAMS_1(_mine);
	_mine call FUNC(set_disabled);
	[_mine] call FUNC(delete_trigger);
	TRACE_1("FUNC_disabled",_mine);
};

// ID functions
FUNC(make_id) = {
	/* (c) by rocko */
	private ["_index", "_mine_index"];
	_index = getNumber(configFile >> "CfgVehicles" >> typeOf _this >> "ACE" >> "ACE_EXPLOSIVES" >> "index");
	_mine_index = GVAR(mine_ID) select _index;
	GVAR(mine_ID) set [_index, _mine_index + 1];
	TRACE_3("FUNC_make_id",(GVAR(mine_ID) select _index),_index,_mine_index);
	(GVAR(mine_ID) select _index)
};

FUNC(reset_id) = {
	/* (c) by rocko */
	private "_new_id";
	_new_id = _this call FUNC(make_id);
	[_this,_new_id] call FUNC(store_id);
	TRACE_2("FUNC_reset_id",_this,_new_id);
};

FUNC(check_duplicate_id) = {
	/* (c) by rocko */
	PARAMS_1(_mine);
	private ["_index", "_mine_index","_duplicate"];
	_index = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "index");
	_mine_index = GVAR(mine_ID) select _index;
	_duplicate = if (_mine_index ==  _mine getVariable QGVAR(id)) then { true } else { false };
	TRACE_4("FUNC_check_duplicate_id",_mine,_index,_mine_index,_duplicate);
	_duplicate
};

FUNC(store_id) = {
	/* (c) by rocko */
	PARAMS_2(_mine,_id);
	_mine setVariable [QGVAR(id),_id,false];
	TRACE_2("FUNC_store_id",_mine,_id);
};

FUNC(show_id) = {
	/* (c) by rocko */
	TRACE_1("FUNC_show_id","");
	private "_name";
	_name = getText(configFile >> "CfgVehicles" >> typeOf _this >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(name));
	hintSilent format ["%1 #%2", _name,(_this getVariable QGVAR(id))];
};

FUNC(get_id) = {
	/* (c) by rocko */
	TRACE_1("FUNC_get_id",_this);
	private "_id";
	_id = _this getVariable QGVAR(id);
	_id
};

FUNC(set_id) = {
	/* (c) by rocko */
	TRACE_1("FUNC_set_id",_this);
	[_this,(_this call FUNC(make_id))] call FUNC(store_id);
	_this call FUNC(show_id);
};

FUNC(set_ready) = {
	/* (c) by rocko */
	TRACE_1("FUNC_set_ready",_this);
	PARAMS_2(_mine,_state);
	private "_initPhase";
	_initPhase = (count _this > 2); // Check if mine has just been placed
	_mine setVariable [QGVAR(canInteract),_state,true];
	_mine enableSimulation false; // TEST
	_canAnimate = (getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "animated") == 1);
	_unarmedPhase = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "AnimationSources" >> "arming" >> "initPhase"); // Read from config initally...
	if (_canAnimate) then {
		_currentPhase = _mine animationPhase "arming";
		switch (_state) do {
			// Mine is not armed!
			case true: {
				if (!_initPhase) then { // Mine disarmed ... then animate back to unarmedPhase
					_mine animate ["arming",_unarmedPhase];
				};
			};
			// Mine is armed!!!
			case false: {
				_newPhase = if (_unarmedPhase == 0) then { 1 } else { 0 };
				_mine animate ["arming",_newPhase];
			};
		};
	};
};

// Sight functions
FUNC(sight_addkey) = {
	/* (c) by rocko */
	GVAR(key_dn) = (findDisplay 46) displayAddEventHandler["KeyDown", '["KeyDown", _this] call FUNC(sight_event)'];
	GVAR(key_up) = (findDisplay 46) displayAddEventHandler["KeyUp", '["KeyUp", _this] call FUNC(sight_event)'];
};

FUNC(sight_remkey) = {
	/* (c) by rocko */
	(findDisplay 46) displayRemoveEventhandler ["KeyDown", GVAR(key_dn)];
	(findDisplay 46) displayRemoveEventhandler ["KeyUp", GVAR(key_up)];
};

FUNC(sight_rotate) = {
	/* (c) by rocko */
	PARAMS_3(_mine,_direction,_pos);
	
	//_z = [player] call CBA_fnc_realHeight; //account for placement above ground
	//_pos set [2, _z];

	_rotation = 0;
	_pitch = 0;
	
	private ["_rotation", "_pitch"];
	
	if (_direction == "R") then { _rotation = 1 };
	if (_direction == "L") then { _rotation = -1 };
	if (_direction == "UP") then { _pitch = -0.2; };
	if (_direction == "DN") then { _pitch = 0.2; };

	_old_dir = direction _mine;
	_old_pitch = _mine getVariable ["pitch",0];

	_new_dir = _old_dir + _rotation;
	_new_pitch = _old_pitch + _pitch;
	_mine setVariable ["pitch",_new_pitch];
	if (_new_pitch >= 90) then { _new_pitch = 89.999 };
	if (_new_pitch <= -90) then { _new_pitch = -89.999 };

	_mine setDir _new_dir;
	//_mine setPos _pos;
	_mine setVectorUp [((sin _new_dir)*(sin _new_pitch)),((cos _new_dir)*(sin _new_pitch)),(cos _new_pitch)];
};

FUNC(sight_event) = {
	/* (c) by rocko */
	PARAMS_2(_event,_parameters);

	if (GVAR(presstime) == time) exitwith {false};
	GVAR(presstime) = time;

	switch(_event) do {
		case "KeyDown": {
			_key = _parameters select 1;
			switch(_key) do {
				case 32: { GVAR(sight_right) = true; };
				case 30: { GVAR(sight_left) = true; };
				case 17: { GVAR(sight_up) = true; };
				case 31: { GVAR(sight_dn) = true; };
				case 49: { GVAR(sight_nvg) = !GVAR(sight_nvg); };
				case 1:  { GVAR(peep_sight) = false; };
			};
		};
		case "KeyUp": {
			_key = _parameters select 1;
			switch(_key) do {
				case 32: { GVAR(sight_right) = false; };
				case 30: { GVAR(sight_left) = false; };
				case 31: { GVAR(sight_dn) = false; };
				case 17: { GVAR(sight_up) = false; };
				case 1:  { GVAR(peep_sight) = false; };
			};
		};
	};
	!(GVAR(peep_sight))
};

FUNC(sight_add_pitch) = {
	/* (c) by rocko */
	_pitch = _this getVariable "pitch";
	_this setVariable ["pitch",_pitch,true];
};

// Placement functions
FUNC(anim) = {
	/* (c) by rocko */
	private "_anim";
	if ((player call CBA_fnc_getUnitAnim) select 0 == "stand") then {
		if (currentWeapon player != "") then {
			player playMove "AmovPercMstpSrasWrflDnon_diary";
		};
	};
	playSound "PlaceMine";
};

FUNC(createStake) = {
	/* (c) by rocko */
	private "_stake";
	PARAMS_2(_make_stake,_mine);
	GVAR(tripwire_point_b) = [(getPos player) select 0,(getPos player) select 1,([player] call CBA_fnc_realHeight)];
	if (_make_stake) then {
		_stake = "ACE_Stake" createVehicle GVAR(tripwire_point_b);
		_stake setVariable ["mine",_mine,true];
		_stake setPos [GVAR(tripwire_point_b) select 0, GVAR(tripwire_point_b) select 1, 0];
	};
	call FUNC(anim);
	sleep 2;
	localize "STR_HINT_ACE_SYS_EXPLOSIVES_ARMED5SEC" spawn ACE_fnc_visual;
	sleep 3;
	GVAR(waiting_for_tripwire) = false;
};

FUNC(removeMagazine) = {
	/* (c) by rocko */
	_magazine = getText(configFile >> "CfgVehicles" >> _this >> "ACE" >> "ACE_EXPLOSIVES" >> "mine_magazine");
	if (_magazine in (magazines player)) then { player removeMagazine _magazine; };
	TRACE_1("FUNC_removeMagazine",_magazine);
};

// Clacker functions
FUNC(showClackerResetHint) = {
	PARAMS_2(_dn,_id);
	format[localize "STR_HINT_ACE_SYS_EXPLOSIVES_CLACKER_RESET",_dn,_id] spawn ACE_fnc_visual;
};

FUNC(createClackerList) = {
	/* (c) by rocko */
	TRACE_1("FUNC_createClackerList",_this);
	private ["_list", "_mine"];
	// TODO: Self-Interaction menu entry to manually drop all clackers for someone else?
	_mine = _this;
	_list = player getVariable [QGVAR(list),[]];
	if (_mine in _list) exitWith {};
	_list set [count _list, _mine];
	player setVariable [QGVAR(list),_list];
};

// TODO: Remove from Clacker List (maybe already handled in "isNull _mine" checks?)

FUNC(createClackerObject) = {
	/* (c) by rocko */
	TRACE_1("FUNC_createClackerObject",_this);
	private ["_list", "_clacker", "_unit", "_clackerType"];
	_unit = _this;
	_list = _unit getVariable [QGVAR(list),[]];
	if (count _list < 1) exitWith { TRACE_1("Exit",count _list); };
	// El stupido factions
	_fac = faction _unit;
	_usclacker = ["USMC","INS","GUE","CIV","BIS_US","BIS_UN","BIS_TK_CIV","BIS_CIV_special","BIS_BAF","PMC_BAF"];
	_gerclacker = ["BIS_GER"];
	_ruclacker = ["CDF","RU","CIV_RU","BIS_CZ","BIS_TK","BIS_TK_INS","BIS_TK_GUE"];
	
	switch (true) do {
		case (_fac in _usclacker): { _clackerType = "ACE_Clacker" };
		case (_fac in _gerclacker): { _clackerType = "ACE_Zundmaschine" };
		case (_fac in _ruclacker): { _clackerType = "ACE_Clacker" };
		case (!(_fac in _usclacker) && !(_fac in _ruclacker) && !(_fac in _gerclacker)): { _clackerType = "ACE_Zundmaschine" };
	};
	
	_clacker = _clackerType createVehicle getpos _unit; // TODO: Create Model // Creating interaction menu on dead units will not work, maybe in A3 (needs to be obvious model)
	_clacker setPos getPos _unit; // TODO: Refine pos
	_clacker setVariable [QGVAR(list),_list,true];
};

FUNC(action_clacker) = {
	/* (c) by rocko */
	TRACE_1("FUNC_action_clacker",_this);
	private "_list";
	_list = _this getVariable [QGVAR(list),[]];
	{
		private ["_mine","_x","_script"];
		_mine = _x;
		if !(isNull _mine) then {
			if ([_mine] call FUNC(check_duplicate_id)) then {
				_mine call FUNC(reset_id);
			};
			_script = format["\x\ace\addons\sys_explosives\%1\attach_clacker.sqf", (getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "mine_type"))];
			_mine execVM _script; //TODO: Compile stuff	
		};
	} foreach _list;
	deleteVehicle _this;
};

FUNC(killed) = {
	/* (c) by rocko */
	TRACE_1("FUNC_killed",_this);
	PARAMS_1(_unit);
	_unit call FUNC(createClackerObject);
};

// Action functions

FUNC(attach_Clacker) = {

};
/*FUNC(safety_off) = {
	private ["_dn","_mine_type"];
	PARAMS_2(_mine,_id);
	_dn = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "name");
	_mine_type = getText(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> "mine_type");
	_detonation = format ["ace_sys_explosives_fnc_detonate_%1",_mine_type];
	if (!(missionNamespace getVariable (format ["SOA_%2_LOCK_%1", _id,_mine_type]))) then {
		missionNamespace setVariable [format ["SOA_%2_LOCK_%1", _id,_mine_type], true];
		_A_S = format [localize "STR_ACE_SYS_EXPLOSIVES_TOUCHOFF",_dn,_id];
		_A_ID = player addAction [_A_S, (__DIR + "\fnc_detonate_M18.sqf"), _mine, 80];
		// Experimental
		//_A_ID = player addAction [_A_S, "\x\ace\addons\sys_explosives\fnc_exec.sqf", [_mine,_detonation], 80];
		player removeAction (_this select 2);
		sleep 30;
		player removeAction _A_ID;
		missionNamespace setVariable [format ["SOA_%2_LOCK_%1", _id,_mine_type], false];
		if (!isNull _mine) then {
			[_dn,_id] call FUNC(showClackerResetHint);
			_mine spawn COMPILE_FILE2_SYS(PATH+"attach_clacker.sqf");
		};
	};
};
*/
FUNC(attach_Tripwire) = {

};

FUNC(getExplosion) = {

};



ADDON = true;
