//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "script_dialog_defines.hpp"

disableSerialization;
private ["_vol", "_volCtrl", "_rcontrol", "_drkbtn", "_rCont", "_unpkbtn", "_cursel", "_unpackable", "_txt"];
private ["_scope", "_ctrl_txt", "_ctrl_pic", "_scope_ltr", "_scope_name", "_scope_name", "_r_in_use", "_cnxbtn"];

PARAMS_2(_unit,_display);

_vol = _unit call FUNC(RuckInventorySize);
_volCtrl = _display displayctrl ACE_TOTAL_VOLUME_IDC;
if (_vol < 0) then {
	if (_vol < -1) then {
		_volCtrl ctrlSetText localize "STR_ACE_SYS_RUCK_TOOFULL";
		GVAR(oversize) = abs(_vol) / 100; //weight penalty
	} else {
		_volCtrl ctrlSetText localize "STR_ACE_SYS_RUCK_NORUCK";
		GVAR(oversize) = 0;
	};
} else {
	GVAR(oversize) = 0;
	_volCtrl ctrlSetText format[
		"%1 %2 %3",
		[_vol, 1, 0, true] call CBA_fnc_formatNumber,
		localize "STR_ACE_SYS_RUCK_CUBICCENTIMETERS",
		localize "STR_ACE_SYS_RUCK_FREESPACE"
	];
};

[_unit, _display] call FUNC(uiUpdateRuckDisplay);
_rcontrol = _display displayctrl ACE_RUCK_ITEMS_IDC;
_drkbtn = _display displayCtrl ACE_BUTTON_DRUCK_IDC;
_r_in_use = _display displayctrl ACE_RLOCK_INUSE_IDC;
_cnxpic = _display displayctrl ACE_RLOCK_CNX_PIC_IDC;
_cnxbtn = _display displayctrl ACE_RLOCK_CNX_BTN_IDC;

if (_unit call FUNC(HasRuck)) then {
    _r_in_use ctrlSetText "";
    _rcontrol ctrlEnable true;
	_rcontrol ctrlShow true;

    _cnxpic ctrlEnable false;
    _cnxpic ctrlShow false;
    _cnxbtn ctrlEnable false;
    _cnxbtn ctrlShow false;
} else {
    if ( [_unit] call FUNC(RuckBusy) ) then {
        _cnxpic ctrlEnable true;
        _cnxpic ctrlShow true;
        _cnxbtn ctrlEnable true;
        _cnxbtn ctrlShow true;
        _cnxbtn ctrlSetTooltip localize "STR_DN_ACE_RUCK_CANCEL";

        _r_in_use ctrlSetText format["%1 %2",
            localize "STR_DN_ACE_RUCK_IN_USE",
            _unit getVariable "ACE_Ruck_Lock"
            ];
    } else {
        _cnxpic ctrlEnable false;
        _cnxpic ctrlShow false;
        _cnxbtn ctrlEnable false;
        _cnxbtn ctrlShow false;

        _r_in_use ctrlSetText "";
        _rcontrol ctrlEnable false;
        _rcontrol ctrlShow false;
    };
    _drkbtn ctrlShow false;
};

_rCont = _display displayCtrl ACE_RUCK_CONTENTS_IDC;
_unpkbtn = _display displayCtrl ACE_BUTTON_UNPACK_IDC;
_cursel = lbCurSel _rCont;
_unpackable = false;
_txt = _rCont lnbText [_cursel, 0];
if (!isNil "_txt") then {
	if (_txt != "") then {_unpackable = true};
};
_unpkbtn ctrlEnable _unpackable;

//Ruck Lock
_ctrl_btn = _display displayCtrl ACE_RLOCK_BTN_IDC;
_ctrl_txt = _display displayCtrl ACE_RLOCK_TXT_IDC;
_ctrl_pic = _display displayCtrl ACE_RLOCK_PIC_IDC;

_scope = _unit getVariable ["ACE_Ruck_Lock_Scope", "Team"];

if (_scope == "") then {
    _ctrl_pic ctrlSetText "\ca\ui\data\lock_on_ca.paa";

    _scope_ltr = "";

    _ctrl_btn ctrlSetTooltip (localize "STR_DN_ACE_RUCK_LOCKED");

} else {
    _ctrl_pic ctrlSetText "\ca\ui\data\lock_off_ca.paa";

    _scope_ltr = localize ("STR_DN_ACE_RUCK_" + toUpper(_scope) + "_LTR");

    _scope_name = localize ("STR_DN_ACE_RUCK_" + toUpper(_scope));
    _ctrl_btn ctrlSetTooltip _scope_name;

};
_ctrl_txt ctrlSetText _scope_ltr;
