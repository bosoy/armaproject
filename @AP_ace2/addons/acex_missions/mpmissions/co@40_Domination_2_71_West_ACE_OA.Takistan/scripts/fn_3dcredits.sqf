//Author: Karel Moricky
#define THIS_FILE "fn_3dcredits.sqf"
#include "x_setup.sqf"
disableserialization;

private ["_text","_pos","_display","_control","_w","_h","_minsDis","_dis","_alpha","_pos2D"];
PARAMS_2(_text,_pos);
_minDis = if (count _this > 2) then {_this select 2} else {20};
_fadeDis = if (count _this > 3) then {_this select 3} else {1.5};
if (isNil QGVAR(BIS_fnc_3dCredits_n)) then {GVAR(BIS_fnc_3dCredits_n) = 2733};

__TRACE_3("","_text","_pos","_minDis");
__TRACE_2("","_fadeDis","d_BIS_fnc_3dCredits_n");

if (typename _pos == typename objnull) then {_pos = position _pos};
if (typename _pos == typename "") then {_pos = markerpos _pos};

GVAR(BIS_fnc_3dCredits_n) cutrsc [QGVAR(rscDynamicText), "plain"];
__INC(GVAR(BIS_fnc_3dCredits_n));

_control = __uiGetVar(GVAR(BIS_dynamicText)) displayctrl 9999;

_control ctrlsetfade 1;
_control ctrlcommit 0;
_control ctrlsetstructuredtext parsetext _text;
_control ctrlcommit 0;

_w = safezoneW;//0.5;
_h = safezoneH;//0.3;

while {true} do {
	_dis = player distance _pos;
	_alpha = abs ((_dis / _minDis) - _fadeDis);
	if (_alpha <= 1) then {
		_pos2D = worldtoscreen _pos;
		if (count _pos2D > 0) then {
			_control ctrlsetposition [(_pos2D select 0) - _w / 2, (_pos2D select 1) - _h / 2, _w, _h];
			_control ctrlsetstructuredtext parsetext _text;
			_control ctrlsetfade (_alpha^3);
			_control ctrlcommit 0.01;
		} else {
			_control ctrlsetfade 1;
			_control ctrlcommit 0.1;
		};
	} else {
		_control ctrlsetfade 1;
		_control ctrlcommit 0.1;
		sleep 0.1;
	};
	sleep 0.01;
};