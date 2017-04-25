#include "script_component.hpp"

private ["_chars", "_mode", "_display", "_line"];

PARAMS_2(_chars,_line);

_mode = "";

disableSerialization;

_display = (uiNamespace getVariable "ACE_ANIM_LETTERS");
_Slot = 0;

switch (_line) do  {
	case 0: {_mode = QUOTE(PATHTO(animateLetter));_Slot = 0;};
	case 1: {_mode = QUOTE(PATHTO(animateLetter1));_Slot = 30;};
	case 2: {_mode = QUOTE(PATHTO(animateLetter2));_Slot = 60;};
	case 3: {_mode = QUOTE(PATHTO(animateLetter));_Slot = 90;};
	case 4: {_mode = QUOTE(PATHTO(animateLetter1));_Slot = 120;};
	case 5: {_mode = QUOTE(PATHTO(animateLetter2));_Slot = 150;};
	case 6: {_mode = QUOTE(PATHTO(animateLetter1));_Slot = 180;};
	default {};
};

//Set up a pool of controls to use.
private ["_idcPool", "_sizePool"];
_idcPool = 5000;
_sizePool = 210;
GVAR(anim_controls) = [];

for "_i" from _Slot to (_Slot + 30) do  {
	_ctrl = _display displayCtrl (_idcPool + _i);
	GVAR(anim_controls) set [count GVAR(anim_controls), _ctrl];
	waituntil{ctrlCommitted _ctrl};
};

//Parse the array of characters.
for "_i" from 0 to 29 do {
	sleep 0.06;
	_ctrl = GVAR(anim_controls) select 0;

	//Send character to the animation engine.
	if !(isNil "_ctrl") then  {
		[_ctrl, (_chars select _i), _i, _Slot] spawn COMPILE_FILE2_SYS(_mode);
	};
	sleep 0.06;
};
i = i + 1;
