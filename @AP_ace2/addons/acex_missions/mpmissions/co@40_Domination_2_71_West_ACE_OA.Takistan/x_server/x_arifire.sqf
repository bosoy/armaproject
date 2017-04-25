// by Xeno
#define THIS_FILE "x_arifire.sqf"
#include "x_setup.sqf"
private ["_height", "_type", "_radius", "_arix", "_ariy", "_ang", "_posf", "_posb", "_posl", "_posr", "_series", "_x1", "_y1", "_angle", "_strenght", "_i", "_j", "_nos", "_shell", "_xo", "_pos", "_pod", "_obj", "_center_x", "_center_y", "_wp_array", "_ari_target","_ari_avail","_side_arti", "_num_arti", "_aristr", "_topicside", "_topicside2", "_logic"];
if (!isServer) exitWith {};

PARAMS_6(_ari_type,_ari_salvos,_arti_operator,_ari_target,_ari_avail,_num_arti);
_side_arti = side (group _arti_operator);

if !(X_JIPH getVariable _ari_avail) exitWith {};

[_ari_avail,false] call FUNC(NetSetJIP);

sleep 9.123;
#ifndef __TT__
_aristr = switch (_num_arti) do {
	case 1: {(localize "STR_DOM_MISSIONSTRING_934")};
	case 2: {(localize "STR_DOM_MISSIONSTRING_935")};
};
GVAR(kb_logic1) kbTell [_arti_operator,GVAR(kb_topic_side_arti),"ArtilleryRoger",["1","",_aristr,[]],true];
#else
_topicside = switch (_num_arti) do {
	case 1: {"HQ_ART_W"};
	case 2: {"HQ_ART_E"};
};
_topicside2 = switch (_num_arti) do {
	case 1: {"HQ_W"};
	case 2: {"HQ_E"};
};
_logic = switch (_num_arti) do {
	case 1: {GVAR(hq_logic_en1)};
	case 2: {GVAR(hq_logic_ru1)};
};
_logic kbTell [_arti_operator,_topicside,"ArtilleryRoger",["1","",(localize "STR_DOM_MISSIONSTRING_936"),[]],true];
#endif
sleep 1;
#ifndef __TT__
_aristr = switch (_num_arti) do {
	case 1: {(localize "STR_DOM_MISSIONSTRING_937")};
	case 2: {(localize "STR_DOM_MISSIONSTRING_938")};
};
["ArtilleryUnAvailable", _aristr] call FUNC(KBSendMsgAll);
#else
switch (true) do {
	case (__OAVer): {[_topicside2,"ArtilleryUnAvailable", (localize "STR_DOM_MISSIONSTRING_939"), ["BeAdvisedArtilleryIsUnavailableAtThisTimeOut"]] call FUNC(KBSendMsgAll)};
	case (__COVer): {[_topicside2,"ArtilleryUnAvailable", (localize "STR_DOM_MISSIONSTRING_939")] call FUNC(KBSendMsgAll)};
};
#endif
sleep 8.54;
#ifndef __TT__
GVAR(kb_logic1) kbTell [_arti_operator,GVAR(kb_topic_side_arti),"ArtilleryExecute",["1","",_aristr,[]],["2","",_ari_type,[]],["3","",str(_ari_salvos),[]],true];
#else
_logic kbTell [_arti_operator,_topicside,"ArtilleryExecute",["1","",(localize "STR_DOM_MISSIONSTRING_939"),[]],["2","",_ari_type,[]],["3","",str(_ari_salvos),[]],true];
#endif

_height = 0;
_type = "";
_radius = 30;
_number_shells = 1;

switch (_ari_type) do {
	case "flare": {
		_number_shells = 18;
        _height = 350;
		_type = if (_side_arti == west) then {GVAR(ArtyShellsWest) select 0} else {GVAR(ArtyShellsEast) select 0};
        _radius = 300;
        _arix = getPosASL _ari_target select 0;
        _ariy = getPosASL _ari_target select 1;
		_ang = (_arix - (getPosASL _arti_operator select 0)) atan2 (_ariy - (getPosASL _arti_operator select 1));
        if (abs _ang != _ang) then {angle = _ang + 360};
		_sina = sin _ang; _cosa = cos _ang;
        _posf = [_arix + _radius * _sina, _ariy + _radius * _cosa];
        _posb = [_arix - _radius * _sina, _ariy - _radius * _cosa];
        _posl = [_arix + _radius * sin (_ang - 90), _ariy + _radius * cos (_ang - 90)];
        _posr = [_arix + _radius * sin (_ang + 90), _ariy + _radius * cos (_ang + 90)];
	};
	case "he": {
		_number_shells = 6;
		_height = 150;
		_type = if (_side_arti == west) then {GVAR(ArtyShellsWest) select 1} else {GVAR(ArtyShellsEast) select 1};
	};
	case "smoke": {
		_number_shells = 1;
		_height = 1;
		_type = if (_side_arti == west) then {GVAR(ArtyShellsWest) select 2} else {GVAR(ArtyShellsEast) select 2};
	};
	case "dpicm": {
		_number_shells = 40;
		_height = 150;
		_type = if (_side_arti == west) then {GVAR(ArtyShellsWest) select 3} else {GVAR(ArtyShellsEast) select 3};
		_radius = 100;
	};
	case "sadarm": {
		_number_shells = 1;
		_height = 165;
		_type = if (_side_arti == west) then {GVAR(ArtyShellsWest) select 4} else {GVAR(ArtyShellsEast) select 4};
	};
};

sleep 8 + (random 7);

if (_ari_type != "flare") then {
    _center_x = getPosASL _ari_target select 0;
    _center_y = getPosASL _ari_target select 1;
};

#ifndef __TT__
_arti_distance = GVAR(FLAG_BASE) distance [getPosASL _ari_target select 0,getPosASL _ari_target select 1,0];
#else
_flagb = switch (_num_arti) do {
	case 1: {GVAR(WFLAG_BASE)};
	case 2: {GVAR(EFLAG_BASE)};
};
_arti_distance = _flagb distance [getPosASL _ari_target select 0,getPosASL _ari_target select 1,0];
#endif
_travel_time = (_arti_distance / 500) + 5 + random 3;

_enemy_units = [];

for "_series" from 1 to _ari_salvos do {
	_wp_array = [];
	while {count _wp_array < _number_shells} do {
		if (_ari_type == "flare") then {
			{
				_x1 = (_x select 0) - 20 + random 40;
				_y1 = (_x select 1) - 20 + random 40;
				_wp_array set [count _wp_array, [_x1, _y1, _height + random 10]];
				sleep 0.0153;
			} forEach [_posf, _posb, _posl, _posr];
		} else {
			_angle = floor random 360;
			_x1 = _center_x - ((random _radius) * sin _angle);
			_y1 = _center_y - ((random _radius) * cos _angle);
			_wp_array set [count _wp_array, [_x1, _y1, (if (_ari_type == "he") then {_height + random 50} else {_height})]];
			sleep 0.0153;
		};
	};
#ifndef __TT__
	_kbstr = switch (_num_arti) do {
		case 1: {"ArtilleryFirstOTW"};
		case 2: {"ArtillerySecondOTW"};
	};
	GVAR(kb_logic1) kbTell [_arti_operator,GVAR(kb_topic_side_arti),_kbstr,["1","",str(_series),[]],true];
#else
	_logic kbTell [_arti_operator,_topicside,"ArtilleryOTW",["1","",str(_series),[]],true];
#endif
	
	sleep _travel_time;
	[QGVAR(say2), [_ari_target, "Ari", 800]] call FUNC(NetCallEvent);
#ifndef __TT__
	_kbstr = switch (_num_arti) do {
		case 1: {"ArtilleryFirstSplash"};
		case 2: {"ArtillerySecondSplash"};
	};
	GVAR(kb_logic1) kbTell [_arti_operator,GVAR(kb_topic_side_arti),_kbstr,["1","",str(_series),[]],true];
#else
	_logic kbTell [_arti_operator,_topicside,"ArtillerySplash",["1","",str(_series),[]],true];
#endif
	
	switch (_ari_type) do {
		case "flare": {
			sleep 1;
			for "_i" from 0 to (_number_shells-1) do {
				_mpp = [(_wp_array select _i) select 0, (_wp_array select _i) select 1, (_wp_array select _i) select 2];
				_shell = createVehicle [_type, _mpp, [], 0, "NONE"];
				_shell setPos _mpp;
				if (((_i+1) % 4 == 0) && (_i > 1)) then {sleep 18 + (ceil random 5)} else {sleep 0.5 + random 1.5};
			};
		};
		case "he": {
			_soldier_type = switch (GVAR(enemy_side)) do {
				case "EAST": {"SoldierEB"};
				case "WEST": {"SoldierWB"};
				case "GUER": {"SoldierGB"};
			};
			_nos = [getPosASL _ari_target select 0,getPosASL _ari_target select 1,0] nearEntities [_soldier_type, _radius];
			{if (!(_x in _enemy_units)) then {_enemy_units set [count _enemy_units, _x]}} forEach _nos;
			for "_i" from 0 to (_number_shells - 1) do {
				_mpp = _wp_array select _i;
				_shell = createVehicle [_type, _mpp, [], 0, "NONE"];
				_shell setPos _mpp;
				_shell setVelocity [0,0,-150];
				[QGVAR(artyt), [getPosASL _shell, _type]] call FUNC(NetCallEventToClients);
				sleep 0.923 + (random 2);
			};
		};
		case "smoke": {
			for "_i" from 0 to (_number_shells - 1) do {
				_mpp = _wp_array select _i;
				_shell = createVehicle [_type, _mpp, [], 0, "NONE"];
				_shell setPos _mpp;
				_shell setVelocity [0,0,-150];
				_xo = ceil random 10;
				sleep 0.923 + (_xo / 10);
			};
		};
		case "dpicm": {
			_soldier_type = switch (GVAR(enemy_side)) do {
				case "EAST": {"SoldierEB"};
				case "WEST": {"SoldierWB"};
				case "GUER": {"SoldierGB"};
			};
			_nos = [getPosASL _ari_target select 0,getPosASL _ari_target select 1,0] nearEntities [_soldier_type, _radius];
			{if (!(_x in _enemy_units)) then {_enemy_units set [count _enemy_units, _x]}} forEach _nos;
			_pos = [(getPosASL _ari_target) select 0, (getPosASL _ari_target) select 1, _height];
			[QGVAR(dpicm), _pos] call FUNC(NetCallEventToClients);
			sleep 0.5;
			for "_i" from 0 to (_number_shells - 1) do {
				_mpp = _wp_array select _i;
				_shell = createVehicle [_type, _mpp, [], 0, "NONE"];
				_shell setPos _mpp;
				_shell setVelocity [0,0,-80];
				_xo = ceil random 10;
				sleep 0.223 + (_xo / 10);
			};
			sleep 2.132;
		};
		case "sadarm": {
			for "_i" from 0 to (_number_shells - 1) do {
				_mpp = _wp_array select _i;
				_shell = createVehicle [_type, _mpp, [], 0, "NONE"];
				_shell setPos _mpp;
				[_shell] spawn BIS_ARTY_F_SadarmDeploy;
				sleep 0.923 + (random 2);
			};
		};
	};
	_wp_array = nil;

	if (_series < _ari_salvos) then {
#ifndef __TT__
		GVAR(kb_logic1) kbTell [_arti_operator,GVAR(kb_topic_side_arti),"ArtilleryReload",["1","",_aristr,[]],true];
#else
		_logic kbTell [_arti_operator,_topicside,"ArtilleryReload",["1","",(localize "STR_DOM_MISSIONSTRING_939"),[]],true];
#endif
		sleep (GVAR(arti_reload_time) + random 3);
	};
};

sleep 2;

_arti_operator addScore ({!alive _x} count _enemy_units);
_enemy_units = nil;
sleep 0.5;

#ifndef __TT__
GVAR(kb_logic1) kbTell [_arti_operator,GVAR(kb_topic_side_arti),"ArtilleryComplete",["1","",_aristr,[]],true];
#else
_logic kbTell [_arti_operator,_topicside,"ArtilleryComplete",["1","",(localize "STR_DOM_MISSIONSTRING_939"),[]],true];
#endif

#ifndef __TT__
[_ari_salvos, _ari_type, _ari_avail,_aristr] spawn {
#else
[_ari_salvos, _ari_type, _ari_avail,_aristr,_topicside2] spawn {
#endif
	private ["_ari_salvos", "_ari_type", "_ari_avail", "_topicside2"];
	PARAMS_4(_ari_salvos,_ari_type,_ari_avail,_aristr);
#ifdef __TT__
	_topicside2 = _this select 4;
#endif
	sleep (GVAR(arti_available_time) + ((_ari_salvos - 1) * 200)) + (random 60) + (if (GVAR(MissionType) != 2) then {if (_ari_type == "sadarm") then {180} else {0}} else {300});
	[_ari_avail,true] call FUNC(NetSetJIP);
#ifndef __TT__
	["ArtilleryAvailable", _aristr] call FUNC(KBSendMsgAll);
#else
	switch (true) do {
		case (__OAVer): {[_topicside2,"ArtilleryAvailable", (localize "STR_DOM_MISSIONSTRING_939"), ["ArtilleryAvailableTransmitTargetLocationOver"]] call FUNC(KBSendMsgAll)};
		case (__COVer): {[_topicside2,"ArtilleryAvailable", (localize "STR_DOM_MISSIONSTRING_939")] call FUNC(KBSendMsgAll)};
	};
#endif
};
