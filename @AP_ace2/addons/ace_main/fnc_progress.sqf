#include "script_component.hpp"

private ["_endtime", "_curtime", "_text", "_maxWidth", "_position","_len","_offs"];

#define __disp (uiNameSpace getVariable "ACE_Rsc_Progressbar")
#define __bgrdCtrl (__disp displayCtrl 1)
#define __control (__disp displayCtrl 2)
#define __text (__disp displayCtrl 3)

PARAMS_4(_endtime,_curtime,_text,_len); // 37
_offs = 0.01 + ((0.1805 - ((round (_len / 2)) * 0.00976)) max 0);
__text ctrlSetPosition [SafeZoneX + _offs, SafeZoneY + 0.045, 0.361, 0.045];
__text ctrlSetText _text;
__text ctrlCommit 0;
_maxWidth = (ctrlPosition __bgrdCtrl select 2) - 0.021;
_position = ctrlPosition __control;
_position set [2, _maxWidth min (_maxWidth * ((_curtime + 1) / _endtime))];
__control ctrlSetPosition _position;
__control ctrlCommit 1;