#define THIS_FILE "animateLetters.sqf"
#include "x_setup.sqf"
private ["_chars","_mode","_display","_idcPool","_Slot","_ctrl"];

disableSerialization;

PARAMS_1(_chars);
_mode = "";
_display = __uiGetVar(X_ANIM_LETTERS);
_Slot = 0;

switch (_this select 1) do  {
	case 0: {_mode = "IntroAnim\animateLetter.sqf";_Slot = 0};
	case 1: {_mode = "IntroAnim\animateLetter1.sqf";_Slot = 30};
	case 2: {_mode = "IntroAnim\animateLetter2.sqf";_Slot = 60};
	case 3: {_mode = "IntroAnim\animateLetter.sqf";_Slot = 90};
	case 4: {_mode = "IntroAnim\animateLetter1.sqf";_Slot = 120};
	case 5: {_mode = "IntroAnim\animateLetter2.sqf";_Slot = 150};
	case 6: {_mode = "IntroAnim\animateLetter1.sqf";_Slot = 180};
	default {};
};
private "_idcPool";
_idcPool = 5000;
GVAR(animL_controls) = [];
for "_i" from _Slot to (_Slot + 30) do {
	_ctrl = _display displayCtrl (_idcPool + _i);
	GVAR(animL_controls) set [count GVAR(animL_controls), _ctrl];
	waituntil{ctrlCommitted _ctrl};
};
for "_i" from 0 to 29 do {
	sleep 0.06;
	_ctrl = GVAR(animL_controls) select 0;
	if !(isNil "_ctrl") then {[_ctrl, _chars select _i, _i, _Slot] execVM _mode};
	sleep 0.06;
};
__INC(GVAR(animL_i));
true