// by Xeno
#define THIS_FILE "x_clientfuncs.sqf"
#include "x_setup.sqf"

// setup global chat logic
if (isNil QGVAR(global_chat_logic)) then {
	GVAR(global_chat_logic) = "Logic" createVehicleLocal [0,0,0];
	GVAR(global_chat_logic) enableSimulation false;
};

// display a text message over a global logic chat
// parameters: text (without brackets)
// example: "Hello World!" call FUNC(GlobalChat);
FUNC(GlobalChat) = {GVAR(global_chat_logic) globalChat _this};

// display a text message over side chat
// parameters: unit, text
// example: [player,"Hello World!"] call FUNC(SideChat);
FUNC(SideChat) = {(_this select 0) sideChat (_this select 1)};

FUNC(KBSideChat) = {player kbTell [GVAR(kb_logic1),"PL" + str(player),"Dummy",["1","",_this,[]],true]};

// display a text message over group chat
// parameters: unit, text
// example: [player,"Hello World!"] call FUNC(GroupChat);
FUNC(GroupChat) = {(_this select 0) groupChat (_this select 1)};

// display a text message over vehicle chat
// parameters: vehicle, text
// example: [vehicle player,"Hello World!"] call FUNC(VehicleChat);
FUNC(VehicleChat) = {(_this select 0) vehicleChat (_this select 1)};

// display a text message over HQ sidechat (CROSSROAD)
// parameters: text
// example: "Hello World!" call FUNC(HQChat);
FUNC(HQChat) = {[playerSide, "HQ"] sideChat _this};

// removes linebreaks from strings (\n or \N)
// parameters: text
// example: "My nice text\n\nHello World" call FUNC(RemoveLineBreak);
FUNC(RemoveLineBreak) = {
	private ["_msg", "_msg_chat_a", "_i", "_c"];
	_msg = _this;
	_msg_chat_a = toArray (_msg);
	for "_i" from 0 to (count _msg_chat_a - 2) do {
		_c = _msg_chat_a select _i;
		if (_c == 92) then {
			if ((_msg_chat_a select (_i + 1)) in [78,110]) then {
				_msg_chat_a set [_i, 32];
				__INC(_i);
				_msg_chat_a set [_i, -1];
			};
		};
	};
	_msg_chat_a = _msg_chat_a - [-1];
	toString (_msg_chat_a)
};

// displays a hint and a chat message, \n get removed for the chat text
// parameters: text (with \n for hints), type of chat ("HQ","SIDE","GLOBAL" or "GROUP")
// example: ["My nice text\n\nHello World", "HQ"] call FUNC(HintChatMsg);
FUNC(HintChatMsg) = {	
	private ["_msg", "_type_chat", "_msg_chat"];
	PARAMS_2(_msg,_type_chat);
	hintSilent _msg;
	_msg_chat = _msg call FUNC(RemoveLineBreak);
	
	_type_chat = toUpper _type_chat;
	switch (_type_chat) do {
		case "HQ": {_msg_chat call FUNC(HQChat)};
		case "SIDE": {[player,_msg_chat] call FUNC(SideChat)};
		case "GLOBAL": {_msg_chat call FUNC(GlobalChat)};
		case "GROUP": {[player,_msg_chat] call FUNC(GroupChat)};
	};
};

// handles messages  transfered over the network
FUNC(HandleMessage) = {
	private ["_msg","_receiver_type","_receiver","_type"];
	PARAMS_4(_msg,_receiver_type,_receiver,_type);
	 //_receiver_type:  "unit", "grp", "all","vec"
	 //_receiver: only needed for "unit", "grp", "vec", otherwise objNull
	 //_type: "global", "vehicle", "side", "group", "hint", "hq"
	switch (_type) do {
		case "global": {
			switch (_receiver_type) do {
				case "unit": {if (!isNull _receiver) then {if (player == _receiver) then {_msg call FUNC(GlobalChat)}}};
				case "grp": {if (!isNull _receiver) then {if (player in units _receiver) then {_msg call FUNC(GlobalChat)}}};
				case "all": {_msg call FUNC(GlobalChat)};
				case "vec": {if (!isNull _receiver) then {if (player in crew _receiver) then {_msg call FUNC(GlobalChat)}}};
			};
		};
		case "vehicle": {
			switch (_receiver_type) do {
				case "unit": {if (!isNull _receiver) then {if (player == crew _receiver) then {[_receiver,_msg] call FUNC(VehicleChat)}}};
				case "grp": {if (!isNull _receiver) then {if (player in crew _receiver) then {[_receiver,_msg] call FUNC(VehicleChat)}}};
				case "vec": {if (!isNull _receiver) then {if (player in crew _receiver) then {[_receiver,_msg] call FUNC(VehicleChat)}}};
			};
		};
		case "side": {
			switch (_receiver_type) do {
				case "unit": {if (!isNull _receiver) then {if (player == _receiver) then {[player,_msg] call FUNC(SideChat)}}};
				case "grp": {if (!isNull _receiver) then {if (player in units _receiver) then {[player,_msg] call FUNC(SideChat)}}};
				case "all": {[player,_msg] call FUNC(SideChat)};
				case "vec": {if (!isNull _receiver) then {if (player in crew _receiver) then {[player,_msg] call FUNC(SideChat)}}};
			};
		};
		case "group": {
			switch (_receiver_type) do {
				case "unit": {if (!isNull _receiver) then {if (player == _receiver) then {[player,_msg] call FUNC(GroupChat)}}};
				case "grp": {if (!isNull _receiver) then {if (player in units _receiver) then {[player,_msg] call FUNC(GroupChat)}}};
				case "all": {[player,_msg] call FUNC(GroupChat)};
				case "vec": {if (!isNull _receiver) then {if (player in crew _receiver) then {[player,_msg] call FUNC(GroupChat)}}};
			};
		};
		case "hint": {
			switch (_receiver_type) do {
				case "unit": {if (!isNull _receiver) then {if (player == _receiver) then {hintSilent _msg}}};
				case "grp": {if (!isNull _receiver) then {if (player in units _receiver) then {hintSilent _msg}}};
				case "all": {hintSilent _msg};
				case "vec": {if (!isNull _receiver) then {if (player in crew _receiver) then {hintSilent _msg}}};
			};
		};
		case "hq": {
			switch (_receiver_type) do {
				case "unit": {if (!isNull _receiver) then {if (player == _receiver) then {_msg call FUNC(HQChat)}}};
				case "grp": {if (!isNull _receiver) then {if (player in units _receiver) then {_msg call FUNC(HQChat)}}};
				case "all": {_msg call FUNC(HQChat)};
				case "vec": {if (!isNull _receiver) then {if (player in crew _receiver) then {_msg call FUNC(HQChat)}}};
			};
		};
	};
};

FUNC(FixHeadBug) = {
	private ["_dir","_pos","_vehicle", "_posasl"];
	_unit = _this;
	if (vehicle _unit != _unit) exitWith {hintSilent (localize "STR_DOM_MISSIONSTRING_632")};
	titleCut [(localize "STR_DOM_MISSIONSTRING_633"),"black faded", 0];
	_pos = position _unit;
	_dist = _pos distance _unit;
	__TRACE_1("Fixheadbug","_dist");
	if (surfaceIsWater _pos) then {_posasl = getPosASL _unit};
	_dir = direction _unit;
	_vehicle = GVAR(headbug_vehicle) createVehicleLocal _pos;
	if (surfaceIsWater _pos) then {_vehicle setPosASL _posasl};
	_unit moveincargo _vehicle;
	waitUntil {vehicle _unit != _unit};
	unassignVehicle _unit;
	_unit action ["Eject",vehicle _unit];
	waitUntil {vehicle _unit == _unit};
	deleteVehicle _vehicle;
	[QGVAR(eswm), player] call FUNC(NetCallEvent);
	_pos set [2,_dist];
	if (surfaceIsWater _pos) then {_unit setPosASL _posasl} else {_unit setPos _pos};
	_unit setDir _dir;
	titleCut["", "BLACK IN", 2];
};

FUNC(TaskHint) = {
	private ["_task", "_status", "_params"];
	if (count _this < 2) exitWith {};
	PARAMS_2(_task,_status);
	_params = switch (true) do {
		case (_status == "created"): {[localize "str_taskNew", [1,1,1,1], "taskNew"]};
		case ((_status == "current") || (_status == "assigned")): {[localize "str_taskSetCurrent", [1,1,1,1], "taskCurrent"]};
		case (_status == "succeeded"): {[localize "str_taskAccomplished", [0.600000,0.839215,0.466666,1.000000], "taskDone"]};
		case (_status == "failed"): {[localize "str_taskFailed", [0.972549,0.121568,0.000000,1.000000], "taskFailed"]};
		case (_status == "canceled"): {[localize "str_taskCancelled", [0.750000,0.750000,0.750000,1.000000], "taskFailed"]};
	};

	taskHint [format [(_params select 0) + "\n%1", (taskDescription _task) select 1], _params select 1, _params select 2];
};

FUNC(GetRanJumpPoint) = {
	private ["_center", "_radius", "_angle", "_r", "_x1", "_y1"];
	PARAMS_2(_center,_radius);
	_center_x = _center select 0;_center_y = _center select 1;
	_angle = floor (random 360);
	_r = random _radius;
	if (_r < 50) then {_r = 50};
	_x1 = _center_x - ((random _r) * sin _angle);
	_r = random _radius;
	if (_r < 50) then {_r = 50};
	_y1 = _center_y - ((random _r) * cos _angle);
	[_x1, _y1, 0]
};

FUNC(HandleHeal) = {
	private ["_healed", "_healer"];
	PARAMS_2(_healed,_healer);
	if (alive _healed && alive _healer) then {
		if (_healed != _healer) then {
			_healer spawn {
				private "_healer";
				_healer = _this;
				sleep 3;
				[QGVAR(pas), [_healer, GVAR(ranked_a) select 17]] call FUNC(NetCallEventCTS);
				[QGVAR(pho), [_healer]] call FUNC(NetCallEventSTO);
			};
		};
	};
	false
};