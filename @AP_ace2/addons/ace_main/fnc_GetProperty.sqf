/* ----------------------------------------------------------------------------
Function: ACE_fnc_getProperty

Description:
	Func

Parameters:
	-

Returns:
		nil

Examples:
	(begin example)
		-
	(end)

Author:
	(c) Rocko 2009
---------------------------------------------------------------------------- */
#include "script_component.hpp"
/* comment {
 GetProperty.sqf version 1.15
 By Fragorl, adapted for WGL5

 This function is part of the global variable management system. It is used to retrieve user-defined proproperties.
 No initialisation is required, simply call this function, or SetProperty.sqf, once, and all arrays will be initialised
 This function is complemented by SetProperty, which creates and changes user-defined proproperties

 Syntax: ["propertyclass"/object, "propertyName"] call GetProperty
 or:     ["propertyclass"/object, "propertyName", "propertyArrayName"] call GetProperty
}; */
private["_check", "_init", "_myo", "_myps", "_userPA", "_foundO", "_foundP", "_ci", "_cj", "_i", "_j", "_objP", "_p", "_r"];

_check = { _t = true;if (count(_this select 0)>= 0) then { _t = false };!_t };

if (count _this == 2) then {
	_init = false;
	if ( [ACE_props] call _check ) then {
		_userPA = ACE_props;
		_init = true;
	};
	if (!_init) then {
		_userPA = [];
		ACE_props = _userPA;
	};
} else {
	_init = false;
	if (count _this == 3) then {
		call compile format ["_userPA = %1", _this select 2];
		if ( [_userPA] call _check ) then {
			call compile format["_userPA = %1",(_this select 2)];
			_init = true;
		};
		if (!_init) then {
			_userPA = [];
			call compile format["%1 = _userPA",(_this select 2)];
		};
	};
};

PARAMS_1(_myo);
_myps = _this select 1; //comment { The name of the property };

//comment { whether we can find the "propertyclass"/object the user has supplied us in the arguments or not };
_foundO = false;
//comment { whether we can find the "propertyName" the user has supplied us in the arguments or not };
_foundP = false;

_i = 0;
_ci = count _userPA;
while { !_foundO && {_i < _ci} } do {
	if ((_userPA select _i)select 0 == _myo) then {
		//comment { Giving us just the proproperties not the name: [["prop1", value], ["prop2", value]] };
		_objP = (_userPA select _i)-[_myo];
		_j = 0;
		_cj = count _objP;
		while { !_foundP && {_j < _cj} } do {
			//comment { Giving us ["prop1", value] the first time };
			_p = _objP select _j;
			if ((_p select 0) == _myps) then {
				_r = (_p select 1);
				_foundP = true;
			};
			_j = _j+1;
		};
		_foundO = true;
	};
	_i = _i+1;
};
if (!_foundP||{!_foundO}) then { _r = objNull; };
_r
