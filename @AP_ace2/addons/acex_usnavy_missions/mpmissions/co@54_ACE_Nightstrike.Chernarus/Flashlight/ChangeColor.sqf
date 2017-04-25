_Col = _this select 0;
private ["_color","_colText","_idc"];

disableSerialization;

switch (_Col) do {
	case "White": {
		_color = ["White",[1,1,1]];
		_colText = [1,1,1,1];
		_idc = 184;
	};
	case "Red": {
		_color = ["Red",[1,0.05,0.05]];
		_colText = [1,0.25,0.25,1];
		_idc = 185;
	};
	case "Yellow": {
		_color = ["Yellow",[1,1,0.05]];
		_colText = [1,1,0.25,1];
		_idc = 186;
	};
	case "Green": {
		_color = ["Green",[0.05,1,0.05]];
		_colText = [0.25,1,0.25,1];
		_idc = 187;
	};
	case "Blue": {
		_color = ["Blue",[0.05,0.05,1]];
		_colText = [0.25,0.25,1,1];
		_idc = 188;
	};
};

HOMJ_FlashColor = _color;
_XD_display = uiNamespace getVariable "FlashLightDialog";
{
	(_XD_display displayCtrl _x) ctrlSetTextColor _colText;
	(_XD_display displayCtrl _x) ctrlCommit 0;
} foreach [176,177,178,179,180,181,182]; // CHANGE SIGNAL-CODE NAME COLORS

{
	if (_x == _idc) then {(_XD_display displayCtrl _x) ctrlSetTextColor (_colText);} else {(_XD_display displayCtrl _x) ctrlSetTextColor [0.25,0.25,0.25,1];};
	(_XD_display displayCtrl _x) ctrlCommit 0;
} foreach [184,185,186,187,188]; // CHANGE COLOR-SELECTOR TEXT COLORS
