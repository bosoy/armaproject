/* ace_sys_wounds(.pbo) */

// _this (c) by Xeno

//#define DEBUG_MODE_FULL
#include "script_component.hpp"

#define __dsp (uiNameSpace getVariable "ACE_DogTag")

PARAMS_3(_receiver,_sender,_state);

if (!alive _receiver) exitWith {};

if ((_receiver distance _sender) > 4) exitWith { (localize "STR_ACE_DOG1") spawn ace_fnc_visual; };
if ((_receiver call CBA_fnc_getUnitAnim) select 0 == "stand") exitWith { (localize "STR_ACE_DOG3") spawn ace_fnc_visual; };

sleep 1 + (random 3);
if (!alive _receiver) exitWith {};

if ((_state select 0) == 0) then {
	TRACE_2("Valid dogtag", _receiver,_state);
	[QGVAR(removeDogtag), _sender] call ACE_fnc_receiverOnlyEvent;
	135966 cutRsc["ACE_DogTag", "PLAIN"];
	(__dsp displayCtrl 666) ctrlSetText (format["%1", _state select 1]);
	hintSilent format [localize "STR_ACE_DOGTAKENX", _state select 1];
	player addMagazine "ACE_DogTag";
} else {
	TRACE_2("Invalid dogtag", _receiver,_state);
	hintSilent (localize "STR_ACE_DOGTAGSOELSE");
};

false
