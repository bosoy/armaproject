//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

disableSerialization;

PARAMS_2(_unit,_display);
DEFAULT_PARAM(2,_sleep,true);

//Weight
#define REQ_DELAY 0.5

if (_sleep) then { sleep REQ_DELAY };

_wgt = _unit call FUNC(GearWeight);
_wgtCtrl = _display displayctrl ACE_TOTAL_WEIGHT_IDC;
if (_wgt < 0) then {
	_wgtCtrl ctrlSetText "";
} else {
	_wgtCtrl ctrlSetText format[
		"%1 %2 %3",
		localize "STR_ACE_SYS_RUCK_WEIGHT",
		[_wgt, 1, 0, true] call CBA_fnc_formatNumber,
		localize "STR_ACE_SYS_RUCK_KILOGRAM"
	];
};

//IFAK
if (!isNil "ace_sys_wounds_enabled") then { [_unit,_display] call FUNC(uiIFAKupdate); };
