#include "script_component.hpp"

private ["_radius", "_disp", "_width", "_height", "_dir", "_x1", "_y1", "_y", "_correctit_fnc"];

1234 cutRsc ["ace_huntir_cam_rose","PLAIN"];

disableSerialization;

_center_x = 0.7;
_center_y = 0.65;
_radius = 0.05;
_x_offset = 0.003;
_y_offset = 0.003;

#define _disp (uiNamespace getVariable "ace_huntir_cam_rose")
_char_n = _disp displayCtrl 64432;
_char_e = _disp displayCtrl 64433;
_char_s = _disp displayCtrl 64434;
_char_w = _disp displayCtrl 64435;
_width = 0.1;
_height = 0.1;

_correctit_fnc = {
	_pos = _this select 0;
	_dir = _this select 1;
	if (_dir >= 270 || {_dir <= 90}) then {
		_pos set [1, (_pos select 1) + _y_offset]
	};
	if (_dir >= 0 && {_dir <= 180}) then {
		_pos set [0, (_pos select 0) - _x_offset]
	};
	if (_dir >= 90 && {_dir <= 270}) then {
		_pos set [1, (_pos select 1) - _y_offset]
	};
	if (_dir >= 180 && {_dir <= 360}) then {
		_pos set [0, (_pos select 0) + _x_offset]
	};
	_pos
};

while {!(GVAR(stop))} do {
	_dir = getDir GVAR(cam); //direction player;
	_x1 = _center_x - (_radius * sin _dir);
	_y1 = _center_y - (_radius * cos _dir);
	_pos = [[_x1, _y1], _dir] call _correctit_fnc;
	_char_n ctrlSetPosition [_pos select 0, _pos select 1, _width, _height];
	_char_n ctrlCommit 0;

	_x1 = _center_x - (_radius * sin (_dir + 90));
	_y1 = _center_y - (_radius * cos (_dir + 90));
	_pos = [[_x1, _y1], _dir] call _correctit_fnc;
	_char_w ctrlSetPosition [_pos select 0, _pos select 1, _width, _height];
	_char_w ctrlCommit 0;

	_x1 = _center_x - (_radius * sin (_dir + 180));
	_y1 = _center_y - (_radius * cos (_dir + 180));
	_pos = [[_x1, _y1], _dir] call _correctit_fnc;
	_char_s ctrlSetPosition [_pos select 0, _pos select 1, _width, _height];
	_char_s ctrlCommit 0;

	_x1 = _center_x - (_radius * sin (_dir + 270));
	_y1 = _center_y - (_radius * cos (_dir + 270));
	_pos = [[_x1, _y1], _dir] call _correctit_fnc;
	_char_e ctrlSetPosition [_pos select 0, _pos select 1, _width, _height];
	_char_e ctrlCommit 0;

	sleep 0.01;
};

1234 cutRsc ["Default","PLAIN"];