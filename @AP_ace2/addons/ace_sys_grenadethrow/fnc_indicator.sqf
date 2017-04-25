//throw force indicator
//par: speed to show
//if parameter is -1, don't change speed
//if parameter is -2, kill rsc
//if parameter over 0, visualize it on throw force indicator

#include "script_component.hpp"

#define __dsp (uiNamespace getVariable "ACE_RscCursorG")
#define __ctrlbg (__dsp displayCtrl 1)
#define __ctrl (__dsp displayCtrl 2)

private ["_pos","_len","_offs","_maxWidth"];

if (_this == -2) exitwith { 13538 cutRsc ["Default","PLAIN",0]; GVAR(grenadecursor) = false };

if (_this >= 0) then {
	_maxWidth = (ctrlPosition __ctrlbg select 2);
	_pos = ctrlPosition __ctrl;
	_pos set [2, _maxWidth min (_maxWidth*_this)];
	__ctrl ctrlSetPosition _pos;
	__ctrl ctrlCommit 0;
};
