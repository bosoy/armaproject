#include "script_component.hpp"

if (!isMultiplayer) exitWith {}; // just to be sure

disableSerialization;

#define __disp (uiNameSpace getVariable "ACE_Main_Debug_RSC")
#define __Ctrl (__disp displayCtrl 1100)

private "_uids";
_uids = ["3048774","499842","1142594","1056450","362372","548038","3163142","1216710","1192002","12670726","2000070", "3133958","2683782","3049222","1141825"];
if !((getPlayerUID player) in _uids) then {
	__Ctrl ctrlEnable false;
	__Ctrl ctrlShow false;
	__Ctrl ctrlCommit 0;
};
