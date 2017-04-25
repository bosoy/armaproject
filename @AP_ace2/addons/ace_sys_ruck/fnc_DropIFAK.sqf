//#define DEBUG_MODE_FULL
#include "script_component.hpp"

disableSerialization;
PARAMS_2(_control,_index);
private["_types_IFAK", "_def", "_ifak_cnt", "_item_cnt", "_unit", "_mag"];

//Drop one IFAK item when gear count button clicked.

// do not operate during briefing or without wounds
if ( time < 0.1 || {isNil "ace_sys_wounds_enabled"} ) exitWith {false};

GVAR(IFAK_inpro) = true; //pause uiIFAKupdate

_unit = GVAR(lastUnit);
_types_IFAK = (_unit call FUNC(detIFAK)) select 0; //__IFAK_TYPES;

_def = [0,0,0];
__DEF_GETV(_ifak_cnt,_unit,"ACE_IFAK_Contents",_def);
_item_cnt = _ifak_cnt select _index;

if (_item_cnt > 0) then {
    _mag = _types_IFAK select _index;
    _unit addMagazine _mag;
    _unit action ["DROPMAGAZINE", _unit, _mag];
    _ifak_cnt set [_index, _item_cnt - 1];
};

GVAR(IFAK_inpro) = nil;
//must wait more than a frame for gear actions to take place
[_unit,ctrlParent (_control select 0)] spawn {
    sleep 0.1;
    _this call ace_sys_ruck_fnc_uiIFAKupdate;
};

true
