//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __chance 10 //10% you won't unjam on first try

if (GVAR(unjamming)) exitwith {};

PARAMS_3(_unit,_muzzle,_delay);

if (currentMuzzle player != _muzzle) exitwith {GVAR(unjamming) = false};
GVAR(unjamming) = true;

player playActionNow "reloadMagazine";
playSound QGVAR(unjam);	// a bit too quiet if you ask me

sleep _delay;

if (__chance < random 100) then {
	_unit setVariable [QGVAR(unjammed),_muzzle];
} else {
	_unit setVariable [QGVAR(jammed),nil,true];
};

GVAR(unjamming) = false;
