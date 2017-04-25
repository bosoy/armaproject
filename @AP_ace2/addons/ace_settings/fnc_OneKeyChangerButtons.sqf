#include "script_component.hpp"
private ["_disp", "_doexit", "_control", "_col"];

disableSerialization;

#define CTRL(A) (_disp displayCtrl A)

_disp = uiNamespace getVariable "ACE_SETTINGS_DIALOG";

#define KEYCAPTION_IDC_KEYCONFIG 1500
#define KEYFEATURE_IDC_KEYCONFIG 2000
#define KEYTEXTBOX_IDC_KEYCONFIG 2500
#define KEYTALT_IDC_KEYCONFIG 3000
#define KEYTCTRL_IDC_KEYCONFIG 3500
#define KEYTSHIFT_IDC_KEYCONFIG 4000

_doexit = false;
switch (_this) do {
	case 0: {
		CTRL(22123) ctrlEnable true;
		CTRL(22124) ctrlEnable true;
		_doexit = true; // discard button
	};
	case 1: {
		if ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 4 != -1) then {
			_control = _disp displayCtrl (KEYTEXTBOX_IDC_KEYCONFIG + ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 0));
			_control ctrlSetText (call compile format ["%1", keyName ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 4)]);
			_control ctrlCommit 0;
			_ks = uiNamespace getVariable QGVAR(key_save);
			_ks set [(uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 0, (uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 4];
			_control = _disp displayCtrl (KEYTSHIFT_IDC_KEYCONFIG + ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 0));
			private ["_col", "_txt"];
			if ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 1 == 0) then {
				_col = [1,0,0,0.2];
				_txt = "";
			} else {
				_col = [0.8784,0.8471,0.651,1];
				_txt = QPATHTO_T(data\shift_ca.paa)
			};
			_control ctrlSetTextColor _col;
			_control ctrlSetText _txt;
			_control ctrlCommit 0;
			_control = _disp displayCtrl (KEYTCTRL_IDC_KEYCONFIG + ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 0));
			if ((uiNamespace getVariable QGVAR(cur_one_key_ctrl) select 2) == 0) then {
				_col = [1,0,0,0.2];
				_txt = "";
			} else {
				_col = [0.8784,0.8471,0.651,1];
				_txt = QPATHTO_T(data\ctrl_ca.paa)
			};
			_control ctrlSetTextColor _col;
			_control ctrlSetText _txt;
			_control ctrlCommit 0;
			_control = _disp displayCtrl (KEYTALT_IDC_KEYCONFIG + ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 0));
			if ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 3 == 0) then {
				_col = [1,0,0,0.2];
				_txt = "";
			} else {
				_col = [0.8784,0.8471,0.651,1];
				_txt = QPATHTO_T(data\alt_ca.paa)
			};
			_control ctrlSetTextColor _col;
			_control ctrlSetText _txt;
			_control ctrlCommit 0;
		};
		CTRL(22123) ctrlEnable true;
		CTRL(22124) ctrlEnable true;
		_doexit = true; // accept button
	};
	case 2: {
		_control = CTRL(6005);
		_col = [];
		_image = "";
		if ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 1 == 0) then {
			_col = [1,1,1,1];
			_cokc = uiNamespace getVariable QGVAR(cur_one_key_ctrl);
			_cokc set [1, 1];
		} else {
			_col = [1,1,1,0.3];
			_cokc = uiNamespace getVariable QGVAR(cur_one_key_ctrl);
			_cokc set [1, 0];
		};
		_control = CTRL(7005);
		_control ctrlSetTextColor _col;
	};
	case 3: {
		_control = CTRL(6006);
		_col = [];
		_image = "";
		if ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 2 == 0) then {
			_col = [1,1,1,1];
			_cokc = uiNamespace getVariable QGVAR(cur_one_key_ctrl);
			_cokc set [2, 1];
		} else {
			_col = [1,1,1,0.3];
			_cokc = uiNamespace getVariable QGVAR(cur_one_key_ctrl);
			_cokc set [2, 0];
		};
		_control = CTRL(7006);
		_control ctrlSetTextColor _col;
	};
	case 4: {
		_control = CTRL(6007);
		_col = [];
		_image = "";
		if ((uiNamespace getVariable QGVAR(cur_one_key_ctrl)) select 3 == 0) then {
			_col = [1,1,1,1];;
			_cokc = uiNamespace getVariable QGVAR(cur_one_key_ctrl);
			_cokc set [3, 1];
		} else {
			_col = [1,1,1,0.3];
			_cokc = uiNamespace getVariable QGVAR(cur_one_key_ctrl);
			_cokc set [3, 0];
		};
		_control = CTRL(7007);
		_control ctrlSetTextColor _col;
	};
};

// Show key settings again
CTRL(1002) ctrlShow true; 

if (_doexit) exitWith {
	uiNamespace setVariable [QGVAR(KeyChangeDo), false];

	_control = CTRL(6000);
	_control ctrlShow false;
	_control ctrlCommit 0;

	_control = CTRL(1002);
	_control ctrlSetPosition [0.329816, -0.0450946, 0.630743, 1.07667];
	_control ctrlCommit 0;
};
