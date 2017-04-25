/* ----------------------------------------------------------------------------
Function: ACE_fnc_setProperty

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
 SetProperty.sqf version 1.15
 By Fragorl, adapted for WGL5

 This function is part of the global variable management system. It is used to set user-defined properties, or create them
 No initialisation is required, simply call this function, or GetProperty.sqf, once, and all arrays will be initialised
 This function is complemented by GetProperty, which retrieves the properties

 CHANGES TO v1.1
 - The user can now specify their own array in which to store all of the variables (optional 4th parameter).
 - The default array is now named 'ACE_props' instead of 'Properties', in accordance with Ofpec tag rules.
 - The user may specify an object OR a string as the first paramemter, instead of just an object.

 CHANGES TO v1.15
 - The initial check for setting up the arrays no longer uses the 'format' command on the array itself.
   This was causing crashes when the array was getting large.

 Thanks to General Barron, HateR_Kint and UNN for their input to these funcs.

 operands: ["propertyclass"/object, "propertyName", value]
 or:        ["propertyclass"/object, "propertyName", value, "propertyArrayName"]

 Note that propertyArrayName is a string. It is the name of the array where all the values are stored
 Using the 3-argument version will use the default arrayname, 'ACE_props'
}; */

private["_check", "_init", "_myo", "_myps", "_myval", "_userPA", "_foundO", "_foundP", "_ci", "_cj", "_i", "_j", "_objP", "_p"];

_check = { _t = true;if (count(_this select 0)>= 0) then { _t = false };!_t };

if (count _this == 3) then {
	_init = false;
	if ([ACE_props] call _check) then {
		_userPA = ACE_props;
		_init = true;
	};
	if (!_init) then {
		_userPA = [];
		ACE_props = _userPA;
	};
} else {
	_init = false;
	if (count _this == 4) then {
		call compile format["_userPA = %1", _this select 3];
		if ([_userPA] call _check) then {
			call compile format["_userPA = %1", _this select 3];
			_init = true;
		};
		if (!_init) then {
			_userPA = [];
			call compile format["%1 = _userPA", _this select 3];
		};
	};
};

PARAMS_3(_myo,_myps,_myval);

//comment { whether we can find the "propertyclass"/object the user has supplied us in the arguments or not };
_foundO = false;
//comment { whether we can find the "propertyName" the user has supplied us in the arguments or not };
_foundP = false;

_i = 0;
_ci = count _userPA;
//comment { This loop checks to see if the object or string already has _userPA defined };
while { _i < _ci && !_foundO } do {
	if (((_userPA select _i)select 0) == _myo) then {
		//comment { leaving us with just [["prop1", value], ["prop2", value]] };
		_objP = (_userPA select _i)-[_myo];
		_j = 0;
		_cj = count _objP;
		//comment { This loop checks to see if the propery already exists };
		while { _j < _cj && !_foundP } do {
			//comment { giving us ["prop1", value] the first time, and so on };
			_p = _objP select _j;
			if ((_p select 0) == _myps) then {
				_p set[1, _myval];
				//comment { j = 0 is the first property of _objP, which excludes the object's name };
				_objP set[_j,_p];
				_foundP = true;
			};
			_j = _j+1;
		};
		//comment { This statement adds the property, if it is not found };
		if (!_foundP) then {
			//comment { The property does not exist yet - create it };
			_p = [_myps,_myval];
			//comment { adding a new property: [object, ["prop1", value], ["prop2", value]] append [["newprop", data]] };
			PUSH(_objP,_p);
		};
		//comment { Reintroduce myo and save our changes };
		_userPA set[_i, [_myo]+_objP];
		_foundO = true;
	};
	_i = _i+1;
};
if (!_foundO) then {
	/*comment { This statement adds the string/object to the _userPA list and adds our property.
	This object has no listings under _userPA yet. Instantiate it and add it's new property };*/
	_userPA set[count _userPA , [_myo, [_myps,_myval]]];
};
