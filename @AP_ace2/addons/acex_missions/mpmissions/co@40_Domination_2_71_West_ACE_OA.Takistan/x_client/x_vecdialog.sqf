// by Xeno
#define THIS_FILE "x_vecdialog.sqf"
#include "x_setup.sqf"

#define __control(numcontrol) (_XD_display displayCtrl numcontrol)
private ["_vec", "_caller", "_ok", "_hasbox", "_ttyp", "_canloadunloadbox", "_vtype", "_pic", "_index", "_control", "_pos", "_depl"];
if (!X_Client) exitWith {};

disableSerialization;

PARAMS_2(_vec,_caller);

if (!alive _vec) exitWith {};
#ifdef __ACE__
if (!(if (!isNil {GV(_vec,ace_canmove)}) then {_vec call ace_v_alive} else {true})) exitWith {
	(localize "STR_DOM_MISSIONSTRING_211") call FUNC(GlobalChat)
};
#endif

GVAR(curvec_dialog) = _vec;

createDialog "XD_VecDialog";

_XD_display = __uiGetVar(X_VEC_DIALOG);

if (getText (configFile >> "CfgVehicles" >> typeOf _vec >> "picture") != "picturestaticobject") then {
	__control(44444) ctrlSetText getText (configFile >> "CfgVehicles" >> typeOf _vec >> "picture");
} else {
	__control(44444) ctrlSetText "";
};

_vec_name = GV(_vec,GVAR(vec_name));
if (isNil "_vec_name") then {
	_vec_name = (localize "STR_DOM_MISSIONSTRING_11");
} else {
	if (_vec_name == "") then {_vec_name = (localize "STR_DOM_MISSIONSTRING_11")};
};

__control(44446) ctrlSetText getText (configFile >> "CfgVehicles" >> GVAR(the_box) >> "icon");
__control(44445) ctrlSetText _vec_name;

_hasbox = GV(_vec,GVAR(ammobox));
if (isNil "_hasbox") then {_hasbox = false};
if (isNil QGVAR(xxvllist)) then {GVAR(xxvllist) = []};
_ttyp = toUpper (typeOf _vec);
if (count GVAR(xxvllist) == 0) then {
	{GVAR(xxvllist) set [count GVAR(xxvllist), toUpper _x]} forEach GVAR(check_ammo_load_vecs);
};

_canloadunloadbox = _ttyp in GVAR(xxvllist);
if (_canloadunloadbox) then {
	if (_hasbox) then {
		__control(44447) ctrlSetText __UI_Path(objective_complete_ca.paa);
		__control(44452) ctrlEnable false;
	} else {
		__control(44447) ctrlSetText __UI_Path(objective_incomplete_ca.paa);
		__control(44448) ctrlEnable false;
	};
} else {
	__control(44452) ctrlEnable false;
	__control(44448) ctrlEnable false;
};

_move_controls = false;

if (_caller != driver _vec) then {
	_ctrl_but_load ctrlEnable false;
	_ctrl_but_drop ctrlEnable false;

	_vtype = GV(_vec,GVAR(vec_type));
	if (!isNil "_vtype") then {
		if (_vtype == "MHQ") then {
			if (!(_caller in _vec)) then {
				lbClear 44449;
				{
					_pic = getText(configFile >> "cfgVehicles" >> _x >> "picture");
					_index = __control(44449) lbAdd ([_x,0] call FUNC(GetDisplayName));
					__control(44449) lbSetPicture [_index, _pic];
					__control(44449) lbSetColor [_index, [1, 1, 0, 0.5]];
				} forEach GVAR(create_bike);

				__control(44449) lbSetCurSel 0;
			} else {
				_move_controls = true;
			};
		};
	};
} else {
	_move_controls = true;
};

_vtype = GV(_vec,GVAR(choppertype));
if (!isNil "_vtype") then {_move_controls = true};

if (GVAR(WithMHQTeleport) == 1) then {
	__control(44453) ctrlShow false;
};

if (_move_controls) then {
	__control(44453) ctrlShow false;
	__control(44449) ctrlShow false;
	__control(44451) ctrlShow false;
	__control(44450) ctrlShow false;
	__control(44459) ctrlShow false;
	__control(44462) ctrlShow false;
	_control = _XD_display displayCtrl 44454;
	_pos = ctrlPosition _control;
	_pos = [(_pos select 0) + 0.17, _pos select 1,_pos select 2,_pos select 3];
	_control ctrlSetPosition _pos;
	_control ctrlCommit 0;
	_control = _XD_display displayCtrl 44446;
	_pos = ctrlPosition _control;
	_pos = [(_pos select 0) + 0.17, _pos select 1,_pos select 2,_pos select 3];
	_control ctrlSetPosition _pos;
	_control ctrlCommit 0;
	_control = _XD_display displayCtrl 44447;
	_pos = ctrlPosition _control;
	_pos = [(_pos select 0) + 0.17, _pos select 1,_pos select 2,_pos select 3];
	_control ctrlSetPosition _pos;
	_control ctrlCommit 0;
	_control = _XD_display displayCtrl 44448;
	_pos = ctrlPosition _control;
	_pos = [(_pos select 0) + 0.17, _pos select 1,_pos select 2,_pos select 3];
	_control ctrlSetPosition _pos;
	_control ctrlCommit 0;
	_control = _XD_display displayCtrl 44452;
	_pos = ctrlPosition _control;
	_pos = [(_pos select 0) + 0.17, _pos select 1,_pos select 2,_pos select 3];
	_control ctrlSetPosition _pos;
	_control ctrlCommit 0;
} else {
	_depl = GV(_vec,GVAR(MHQ_Deployed));
	if (isNil "_depl") then {_depl = false};
	if (_depl) then {
		__control(44462) ctrlSetText (localize "STR_DOM_MISSIONSTRING_610");
		if (_hasbox) then {
			__control(44448) ctrlEnable true;
			__control(44452) ctrlEnable false;
		} else {
			__control(44448) ctrlEnable false;
			__control(44452) ctrlEnable true;
		};
	} else {
		__control(44453) ctrlEnable false;
		__control(44459) ctrlEnable false;
		__control(44451) ctrlEnable false;
		__control(44449) ctrlEnable false;
	};
};

waitUntil {!dialog || !alive player};

if (!alive player) then {closeDialog 0};