//fnc_drawDashedLine.sqf
#include "script_component.hpp"
_canvas = _this select 0;
_startPos = _this select 1;
_endPos = _this select 2;
_dashLength = _this select 3;

_p1 = _startPos;
_exit = false;
_vecTo = [_startPos, _endPos] call ACE_fnc_vectorFromXToY;
_distVec = [
			(_vecTo select 0)*_dashLength,
			(_vecTo select 1)*_dashLength
		];
_drawDash = true;
while {!_exit} do {
	_p2 = [
			(_p1 select 0)+(_distVec select 0),
			(_p1 select 1)+(_distVec select 1)
		];
	if(_p1 distance _endPos < _p1 distance _p2) then {
		_p2 = _endPos;
		_exit = true;
	};
	if(_drawDash) then {
		_canvas drawLine [_p1, _p2, HUDCOLOR];
		_drawDash = false;
	} else {
		_drawDash = true;
	};
	_p1 = _p2;
};