// by Xeno
disableSerialization;

private ["_ok","_XD_display","_ctrl"];

if (!(local player)) exitWith {};

_ok = createDialog "XD_StatusDialog";

_XD_display = findDisplay 11001;

_ctrl = _XD_display displayCtrl 1000;

_rarray = [900, 1000, 1200, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 10000];

_vdindex = -1;

for "_i" from 0 to (count _rarray - 1) do {
	call compile format ["_index = _ctrl lbAdd ""%1"";if (d_viewdistance == %1) then {_vdindex = _index};",_rarray select _i];
};

_ctrl lbSetCurSel _vdindex;

if (d_disable_viewdistance) then {
	_ctrl ctrlEnable false;
	_ctrl = _XD_display displayCtrl 1999;
	_ctrl ctrlSetText "Viewdistance";
	_ctrl = _XD_display displayCtrl 1997;
	_ctrl ctrlSetText "";
};

_ctrl = _XD_display displayCtrl 1001;
_rarray = ["No Gras", "Medium Gras", "Full Gras"];

_glindex = -1;

for "_i" from 0 to (count _rarray - 1) do {
	call compile format ["_index = _ctrl lbAdd ""%1"";if (d_graslayer_index == _index) then {_glindex = _index};",_rarray select _i];
};

_ctrl lbSetCurSel _glindex;
if (d_disable_graslayer) then {
	_ctrl ctrlEnable false;
	_ctrl = _XD_display displayCtrl 1998;
	_ctrl ctrlSetText "Gras Layer";
	_ctrl = _XD_display displayCtrl 1996;
	_ctrl ctrlSetText "";
};

_ctrl = _XD_display displayCtrl 1002;
_rarray = ["Off", "On"];
for "_i" from 0 to (count _rarray - 1) do {
	call compile format ["_index = _ctrl lbAdd ""%1"";",_rarray select _i];
};
_ctrl lbSetCurSel d_show_player_namesx;

_ctrl = _XD_display displayCtrl 1005;
_units = if (!ismultiplayer) then {switchableunits} else {playableunits};
d_namep_rarray = [x_player_name];
{
	if (name _x != x_player_name) then {
		d_namep_rarray set [count d_namep_rarray, name _x];
	};
} foreach _units;
for "_i" from 0 to (count d_namep_rarray - 1) do {
	call compile format ["_index = _ctrl lbAdd ""%1"";",d_namep_rarray select _i];
};
_ctrl lbSetCurSel 0;

if (count x_pm_add_ar > 0) then {
	for "_i" from (count x_pm_add_ar - 1) to 0 step - 1 do {
		x_pm_received_ar = [x_pm_received_ar, [(x_pm_add_ar select _i)], 0] call BIS_fnc_arrayInsert;
	};
	x_pm_add_ar = [];
};

if (count x_pm_received_ar > 50) then {
	for "_i" from 50 to (count x_pm_received_ar - 1) do {
		x_pm_received_ar set [_i, -1];
	};
	x_pm_received_ar = x_pm_received_ar - [-1];
};

_ctrl = _XD_display displayCtrl 1030;
for "_i" from 0 to (count x_pm_received_ar - 1) do {
	_ele = x_pm_received_ar select _i;
	_hour = (_ele select 2) select 3;
	_minute = (_ele select 2) select 4;
	_strhour = if (_hour < 10) then {
		"0" + str(_hour)
	} else {
		str(_hour);
	};
	_strmin = if (_minute < 10) then {
		"0" + str(_minute)
	} else {
		str(_minute);
	};
	call compile format ["_index = _ctrl lbAdd ""%1, %3:%4: %2"";", _ele select 0, _ele select 1, _strhour, _strmin];
};
_ctrl lbSetCurSel 0;

if (count x_pm_send_ar > 50) then {
	for "_i" from 50 to (count x_pm_send_ar - 1) do {
		x_pm_send_ar set [_i, -1];
	};
	x_pm_send_ar = x_pm_send_ar - [-1];
};

_ctrl = _XD_display displayCtrl 1031;
for "_i" from 0 to (count x_pm_send_ar - 1) do {
	_ele = x_pm_send_ar select _i;
	_hour = (_ele select 2) select 3;
	_minute = (_ele select 2) select 4;
	_strhour = if (_hour < 10) then {
		"0" + str(_hour)
	} else {
		str(_hour);
	};
	_strmin = if (_minute < 10) then {
		"0" + str(_minute)
	} else {
		str(_minute);
	};
	call compile format ["_index = _ctrl lbAdd ""%1, %3:%4: %2"";", _ele select 0, _ele select 1, _strhour, _strmin];
};
_ctrl lbSetCurSel 0;

if (true) exitWith {};
