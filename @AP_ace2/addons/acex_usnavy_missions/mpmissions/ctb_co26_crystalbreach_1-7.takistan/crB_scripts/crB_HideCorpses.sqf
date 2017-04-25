//////////////////////////////////////////////////////////////////
// Function file for Armed Assault
// Inspired by:  Mr Murray Gravedigger
// Created: 20090930
// Contact: http://creobellum.org
// Purpose: Hide corpses
///////////////////////////////////////////////////////////////////
if (!isServer) exitWith{};
_maxcorpses = _this select 0;
_timeuntilhide = _this select 1;
_Dead = [];
_Man = [];
_P = nil;

waitUntil{typeName allUnits == "ARRAY"};

while {true} do {
	_cMan = allUnits;
	_Man = _Man - _cMan;
	_Man = _Man + _cMan;

	{
		if(!alive _x) then{_Dead = _Dead + [_x];};
	} forEach _Man;
	_Man = _Man - _Dead;
	if(count _Dead > _maxcorpses) then{_P = _Dead select 0; _Dead = _Dead - [_P];};
	_hidetime = _timeuntilhide;
	if(_P isKindOf "Car") then{_hidetime = _timeuntilhide * 10;};
	sleep _hidetime;
	hideBody _P;
	deleteVehicle _P;
	_P = objNull;
};