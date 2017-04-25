#define THIS_FILE "animateLetter.sqf"
#include "x_setup.sqf"
private ["_ctrl", "_char", "_pos", "_Slot"];

disableSerialization;

PARAMS_4(_ctrl,_char,_pos,_Slot);

GVAR(animL_controls) = GVAR(animL_controls) - [_ctrl];
_ctrl ctrlSetTextColor GVAR(intro_color);
_ctrl ctrlSetText _char;
_ctrl ctrlSetPosition [-0.1, 0.3];
_ctrl ctrlSetFade 0;
_ctrl ctrlSetScale 0.2;
_ctrl ctrlCommit 0;
_ctrl ctrlSetPosition [(_pos * 0.03) + 0.1,0.05 + _Slot / 400];
_ctrl ctrlCommit 0.5;
_ctrl ctrlSetScale 4;
_ctrl ctrlCommit 0.25;
sleep 0.25;
_ctrl ctrlSetScale 1;
_ctrl ctrlCommit 0.25;
sleep 14.75;
_ctrl ctrlSetFade 1;
_ctrl ctrlCommit 1;
sleep 2;
GVAR(animL_controls) set [count GVAR(animL_controls), _ctrl];

true