/* ace_sys_explosives | IED Phone | (c) 2012 by rocko */

#include "\x\ace\addons\sys_explosives\script_component.hpp"

// Give mobile phone, item itself is useless, but with the magic of numbers ...
if !("ACE_Cellphone" in (weapons player)) then {
	player addWeapon "ACE_Cellphone";
};

// There will be no preset IED's with a phone..
_mine = _this;

// Generate number
// TODO: Function to generate map specific mobile number
_ln = "0771";

/*
switch (worldName) do {
	case "Desert_E": { _ln = "0771" };
	// case "Takistan": { };
	// case "Zargabd":
	// case "Chernarus": { _ln = "995" };
};
*/

_fn = ["1","2","3","4","5","6","7","8","9"];
_rn = ["1","2","3","4","5","6","7","8","9","0"];
_random_fn = _fn call ACE_fnc_selectrandom;
_number = _ln + _random_fn;
for "_i" from 0 to 4 do {
	_tmp_random = _rn call ACE_fnc_selectrandom;
	_number = _number + _tmp_random;
};

// TODO: Make some sort of notepad where the number is stored, else expect people to fucking use pen and paper, lazy fuckers...
if (local player) then {
	hintSilent format ["%1",_number];
};

// Save number and mine into GLOBAL numbers array
_store = [_number,_mine];

GVAR(ied_phonenumbers) set [(count GVAR(ied_phonenumbers)),_store];
publicVariable QGVAR(ied_phonenumbers); // TODO: broadcast numbers, so its available from everywhere IN A BETTER WAY if possible

// TODO: Fraud call, if wrong number entered, player hears a tut tut until presses hang up on dialog or drops mobile 

[_mine,false] call FUNC(set_ready);
