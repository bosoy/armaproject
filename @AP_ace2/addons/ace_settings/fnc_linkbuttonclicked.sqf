#include "script_component.hpp"
private ["_disp", "_base", "_control", "_txt", "_hasalt", "_usecol", "_hasctrl", "_hasshift", "_class", "_feature"];

#define CTRL(A) (_disp displayCtrl A)

disableSerialization;

// Hide key settings
CTRL(1002) ctrlShow false; 

if (uiNamespace getVariable QGVAR(KeyChangeDo)) exitWith {};

uiNamespace setVariable [QGVAR(KeyChangeDo), true];

_disp = uiNamespace getVariable "ACE_SETTINGS_DIALOG";

_base = _this - 2500;

#define KEYCAPTION_IDC_KEYCONFIG 1500
#define KEYFEATURE_IDC_KEYCONFIG 2000
#define KEYTEXTBOX_IDC_KEYCONFIG 2500
#define KEYTALT_IDC_KEYCONFIG 3000
#define KEYTCTRL_IDC_KEYCONFIG 3500
#define KEYTSHIFT_IDC_KEYCONFIG 4000

_control = CTRL(1002);
_control ctrlSetPosition [0.329816, 0.28, 0.630743, 0.75];
_control ctrlCommit 0;

_control = CTRL(6000);
_control ctrlShow true;
_control ctrlCommit 0;

_control = _disp displayCtrl (KEYTALT_IDC_KEYCONFIG + _base);
_txt = ctrlText _control;
_hasalt = 0;
_image = "";
if (_txt == "") then {
	_usecol = [1,1,1,0.3];
} else {
	_usecol = [1,1,1,1];
	_hasalt = 1;
};
_control ctrlSetTextColor _usecol;
_control = CTRL(7007);
_control ctrlSetTextColor _usecol;
_control ctrlCommit 0;

_control = _disp displayCtrl (KEYTCTRL_IDC_KEYCONFIG + _base);
_txt = ctrlText _control;
_hasctrl = 0;
if (_txt == "") then {
	_usecol = [1,1,1,0.3];
} else {
	_usecol = [1,1,1,1];
	_hasctrl = 1;
};
_control = CTRL(7006);
_control ctrlSetTextColor _usecol;
_control ctrlCommit 0;

_control = _disp displayCtrl (KEYTSHIFT_IDC_KEYCONFIG + _base);
_txt = ctrlText _control;
_hasshift = 0;
if (_txt == "") then {
	_usecol = [1,1,1,0.3];
} else {
	_usecol = [1,1,1,1];
	_hasshift = 1;
};
_control = CTRL(7005);
_control ctrlSetTextColor _usecol;
_control ctrlCommit 0;

_control = _disp displayCtrl (KEYTEXTBOX_IDC_KEYCONFIG + _base);
_txt = ctrlText _control;
_control = CTRL(6002);
_control ctrlSetText _txt;

uiNamespace setVariable [QGVAR(cur_one_key_ctrl), [_base, _hasshift, _hasctrl, _hasalt, (uiNamespace getVariable QGVAR(key_save)) select _base]];

_control = _disp displayCtrl (KEYCAPTION_IDC_KEYCONFIG + _base);
_class = ctrlText _control;

_control = _disp displayCtrl (KEYFEATURE_IDC_KEYCONFIG + _base);
_feature = ctrlText _control;

_control = CTRL(6001);
_control ctrlSetText (OPTION_CHANGE + _class + ", " + _feature);

CTRL(22123) ctrlEnable false;
CTRL(22124) ctrlEnable false;
