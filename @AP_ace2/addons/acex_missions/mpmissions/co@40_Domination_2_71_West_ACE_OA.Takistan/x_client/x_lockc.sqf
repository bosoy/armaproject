// by Xeno
#define THIS_FILE "x_lockc.sqf"
#include "x_setup.sqf"
private ["_vec", "_arg","_id"];

PARAMS_1(_vec);
_id = _this select 2;
_arg = _this select 3;

if (vehicle player != player) exitWith {
	(localize "STR_DOM_MISSIONSTRING_274") call FUNC(GlobalChat)
};

if ((_vec call d_fnc_isVecLocked) && _arg == 0) exitWith {(localize "STR_DOM_MISSIONSTRING_275") call FUNC(GlobalChat)};

if (!(_vec call d_fnc_isVecLocked) && _arg == 1) exitWith {(localize "STR_DOM_MISSIONSTRING_276") call FUNC(GlobalChat)};

_dexit = false;
_depl = GV(_vec,GVAR(MHQ_Deployed));
if (!isNil "_depl") then {
	if (_depl && _arg == 1) then {
		(localize "STR_DOM_MISSIONSTRING_277") call FUNC(GlobalChat);
		_dexit = true;
	};
};
if (_dexit) exitWith {};

if (_arg == 0 && count (crew _vec) > 0) then {{_x action ["Eject", vehicle _x]} forEach ((crew _vec) - [player])};

switch (_arg) do {
	case 0: {[QGVAR(l_v), [_vec, true]] call FUNC(NetCallEventCTS); (localize "STR_DOM_MISSIONSTRING_278") call FUNC(GlobalChat)};
	case 1: {[QGVAR(l_v), [_vec, false]] call FUNC(NetCallEventCTS); (localize "STR_DOM_MISSIONSTRING_279") call FUNC(GlobalChat)};
};

GVAR(adm_currentvec) = objNull;
_vec removeAction _id;
GVAR(admin_idd) =  -9999;
