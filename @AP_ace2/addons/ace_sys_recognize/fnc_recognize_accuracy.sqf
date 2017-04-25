// Return most specific displayName below player's knowledge
// Function by zGuba

#include "script_component.hpp"

PARAMS_2(_target,_knowledge);

private ["_class","_abort","_displayName","_displayNameShort"];

#define __ACCURACY getNumber (_class >> "accuracy")

_class = (configFile >> "CfgVehicles" >> typeOf _target);
_abort = false;
while {!_abort && {__ACCURACY > _knowledge}} do {
	_class = inheritsFrom _class; // TODO: if null return Default and no recognition
};

_displayName = getText (_class >> "displayName");
_displayNameShort = getText (_class >> "displayNameShort");

if (_displayNameShort != "") then {
	_displayName = _displayNameShort;
};

_displayName;