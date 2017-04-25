// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_serverOPC.sqf"
#include "x_setup.sqf"
if (!isServer) exitWith{};
private ["_name", "_uid", "_p", "_lt"];
PARAMS_2(_name,_uid);

__TRACE_2("","_uid","_name")

if (_name == "__SERVER__") exitWith {};

_p = GV2(GVAR(player_store),_uid);
if (isNil "_p") then {
	_p = [GVAR(AutoKickTime), time, _uid, 0, "", sideUnknown, _name, 0, xr_max_lives, time, [], [], [], true];
	GVAR(player_store) setVariable [_uid, _p];
	__TRACE_2("Player not found","_uid","_name")
	if (GVAR(domdatabase)) then {
		_p set [count _p, 0];
		_p set [count _p, 0];
		_p set [count _p, 0];
		_p set [count _p, 0];
		_p set [count _p, 0]; // score currently, idx 18
		_p set [count _p, 0]; // AI kills, idx 19
		_p set [count _p, 0]; // human kills (TT version only), idx 20
		_p set [count _p, 0]; // vehicle type car kills, idx 21
		_p set [count _p, 0]; // vehicle type APC kills, idx 22
		_p set [count _p, 0]; // vehicle type tank kills, idx 23
		_p set [count _p, 0]; // vehicle type plane kills, idx 24
		_p set [count _p, 0]; // vehicle type chopper kills, idx 25
		_p set [count _p, 0]; // radio tower kills, idx 26
		_p set [count _p, 0]; // main target objects kills, idx 27
		_p set [count _p, 0]; // side missions resolved, idx 28 !?!
		_p set [count _p, 0]; // deaths/uncons, idx 29 !?!
		_res = "Arma2Net.Unmanaged" callExtension ("DomDatabase ['Read', '" + _uid + "','" + _name + "']");
		_res = call compile _res;
		__TRACE_1("non existing UID","_res")
		if (_res select 0 != "Error") then {
			if (_res select 0 != "Newplayer") then {
				_p set [14, _res select 2]; // total score, _idx 14
				_p set [15, _res select 3]; // total time played on the server, _idx 15
				_p set [16, _res select 4]; // teamkills total, _idx 16, not used yet
				_p set [17, _res select 5]; // total number played on the server, _idx 17
				_p set [19, _res select 6]; // AI kills, idx 19
				_p set [20, _res select 7]; // Human kills, idx 20, only in TT version
				_p set [21, _res select 8]; // vehicle type car kills, idx 21
				_p set [22, _res select 9]; // vehicle type APC kills, idx 22
				_p set [23, _res select 10]; // vehicle type tank kills, idx 23
				_p set [24, _res select 11]; // vehicle type plane kills, idx 24
				_p set [25, _res select 12]; // vehicle type chopper kills, idx 25
				_p set [26, _res select 13]; // radio tower kills, idx 26
				_p set [27, _res select 14]; // main target objects kills, idx 27
				_p set [28, _res select 15]; // side missions resolved, idx 28
				_p set [29, _res select 16]; // deaths/uncons, idx 29 !?!
				__TRACE_1("after db query","_p")
			};
		};
	};
} else {
	__TRACE_1("player store before change","_p")
	_pna = _p select 6;
	if (_name != _pna) then {
		[QGVAR(w_n), [_name, _pna]] call FUNC(NetCallEventToClients);
		diag_log (format [localize "STR_DOM_MISSIONSTRING_942", _name, _pna, _uid]);
	};
	_lt = _p select 9;
	if (time - _lt > 600) then {
		_p set [8, xr_max_lives];
	};
	_p set [1, time];
	_p set [6, _name];
	__TRACE_1("player store after change","_p")
	if (GVAR(domdatabase)) then {
		_res = "Arma2Net.Unmanaged" callExtension ("DomDatabase ['Read', '" + _uid + "','" + _name + "']");
		_res = call compile _res;
		__TRACE_1("existing UID","_res")
		if (_res select 0 != "Error") then {
			if (_res select 0 != "Newplayer") then {
				_p set [14, _res select 2];
				_p set [15, _res select 3];
				_p set [16, _res select 4];
				_p set [17, _res select 5];
				_p set [19, _res select 6]; // AI kills, idx 19
				_p set [20, _res select 7]; // Human kills, idx 20, only in TT version
				_p set [21, _res select 8]; // vehicle type car kills, idx 21
				_p set [22, _res select 9]; // vehicle type APC kills, idx 22
				_p set [23, _res select 10]; // vehicle type tank kills, idx 23
				_p set [24, _res select 11]; // vehicle type plane kills, idx 24
				_p set [25, _res select 12]; // vehicle type chopper kills, idx 25
				_p set [26, _res select 13]; // radio tower kills, idx 26
				_p set [27, _res select 14]; // main target objects kills, idx 27
				_p set [28, _res select 15]; // side missions resolved, idx 28
				__TRACE_1("after db query","_p")
			};
		};
		_p set [17, (_p select 17) + 1]; // inc times played
	};
};
