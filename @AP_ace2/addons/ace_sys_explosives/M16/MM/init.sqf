/* rocko */
//#define DEBUG_MODE_FULL
#include "\x\ace\addons\sys_explosives\script_component.hpp"

_mine = _this select 0;
[_mine,false] call FUNC(set_ready);
[_mine] call FUNC(bury_mine); // Q&D blabla automate

_dir = _mine getVariable [QUOTE(direction),(direction _mine)];

_length = _mine getVariable [QUOTE(length),0];
_length_compare = getNumber(configFile >> "CfgVehicles" >> typeOf _mine >> "ACE" >> "ACE_EXPLOSIVES" >> QUOTE(tripwire_length));
if (isNil "_length") then {
	_length = _length_compare; // Not setup, max length
};
if (_length > _length_compare) then { _length = _length_compare; }; // Length given but too long ;)

_pos = getPos _mine;
_z = [_mine] call CBA_fnc_realHeight;
_real_pos = [_pos select 0, _pos select 1, _z];
_x1 = _real_pos select 0;
_x2 = _x1 + ((sin _dir)*_length);
_y1 = _real_pos select 1;
_y2 = _y1 + ((cos _dir)*_length);
_midpoint = [((_x1 + _x2) / 2), ((_y1 + _y2) / 2), _z];
_length = _length * 0.5;
if (_dir < 0) then { _dir = 360 + _dir; };

if (_length != 0) then {
	_stake = "ACE_Stake" createVehicle [_x2,_y2,0]; _stake setVariable ["mine",_mine,true];
	_stake setPos [_x2,_y2,0];
};

_trigger = createTrigger ["EmptyDetector", _midpoint];
if (_length == 0) then {
	_trigger setTriggerArea [__WIDTH, __LENGTH, _dir, false];
} else {
	_trigger setTriggerArea [__WIDTH_TRIPWIRE, _length, _dir, true];
};
_trigger setTriggerActivation ["ANY", "PRESENT", false];
_trigger setTriggerStatements [
	format["({ _x isKindOf 'Land' && {abs((getposatl _x select 2) - %1)<0.4} } count thisList) > 0", _z],
	"[thisTrigger,thisList] spawn ace_sys_explosives_fnc_detonate_M16", ""
];

// Func to store trigger
[_mine,_trigger] call FUNC(store_trigger);
[_mine,_trigger] call FUNC(store_mine);
