// by Xeno
disableSerialization;

private ["_ok","_XD_display","_ctrl"];

if (!(local player)) exitWith {};

_ok = createDialog "XD_StatusDialog";

_XD_display = findDisplay 11001;

if (count x_show_player_marker == 0) then {
	_ctrl = _XD_display displayCtrl 11008;
	_ctrl ctrlEnable false;
} else {
	_ctrl = _XD_display displayCtrl 11008;
	if (x_show_p_marker) then {_ctrl ctrlSetText "Hide Player Marker";} else {_ctrl ctrlSetText "Show Player Marker";};
};

if (!(isNil "x_no_viewdistance_change")) then {
	if (x_no_viewdistance_change) then {
		_ctrl = _XD_display displayCtrl 11006;
		_ctrl ctrlEnable false;
	};
};

if (!(isNil "x_no_graslayer_change")) then {
	if (x_no_graslayer_change) then {
		_ctrl = _XD_display displayCtrl 11007;
		_ctrl ctrlEnable false;
	};
};

if (true) exitWith {};
