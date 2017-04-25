// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_serverOPD.sqf"
#include "x_setup.sqf"
if (!isServer) exitWith{};
private ["_name", "_uid", "_pa", "_oldwtime", "_connecttime", "_newwtime"];
PARAMS_2(_name,_uid);

__TRACE_2("","_name","_uid")

if (_name == "__SERVER__") exitWith {};

_pa = GV2(GVAR(player_store),_uid);
if (!isNil "_pa") then {
	__TRACE_1("player store before change","_pa")
	_oldwtime = _pa select 0;
	_connecttime = _pa select 1;
	_newwtime = time - _connecttime;
	if (_newwtime >= _oldwtime) then {
		_newwtime = 0;
	} else {
		_newwtime = _oldwtime - _newwtime;
	};
	_pa set [0, _newwtime];
	_pa set [9, time];
	
	_pl = objNull;
	//{if (getPlayerUID _x == _uid) exitWith {_pl = _x}} forEach playableUnits;
	{
		_un = __getMNsVar2(_x);
		if (!isNil "_un" && {!isNull _un && getPlayerUID _un == _uid}) exitWith {_pl = _un};
	} forEach GVAR(player_entities);
	
	if (!isNull _pl) then {
		_pa set [10, weapons _pl];
		_pa set [11, magazines _pl];
		_pa set [12, position _pl];
		_pa set [13, vehicle _pl == _pl];
	} else {
		_pa set [10, []];
		_pa set [11, []];
		_pa set [12, []];
		_pa set [13, true];
	};
	
	if (GVAR(domdatabase)) then {
		_pa set [15, (_pa select 15) + (time - _connecttime)];
		private ["_score", "_diffscore"];
		_score = if (!isNull _pl) then {score _pl} else {0};
		_diffscore = if (_score > 0) then {_score - (_pa select 18)} else {0};
		_pa set [18, _score];
		#ifdef __DEBUG__ 
		_strdb = "DomDatabase ['Write','" + _uid +
		"','" + (_pa select 6) +
		"'," + str(round((_pa select 14) + _diffscore)) +
		", " + str(round(_pa select 15)) +
		", " + str(round(_pa select 16)) + // teamkills total
		", " + str(round(_pa select 17)) +
		", " + str(round(_pa select 19)) + // AI kills
		", " + str(round(_pa select 20)) + // Human kills
		", " + str(round(_pa select 21)) + // vehicle type car kills
		", " + str(round(_pa select 22)) + // vehicle type APC kills
		", " + str(round(_pa select 23)) + // vehicle type tank kills
		", " + str(round(_pa select 24)) + // vehicle type plane kills
		", " + str(round(_pa select 25)) + // vehicle type chopper kills
		", " + str(round(_pa select 26)) + // radio tower kills
		", " + str(round(_pa select 27)) + // main target objects kills
		", " + str(round(_pa select 28)) + // side missions resolved
		", " + str(round(_pa select 29)) + // deaths/uncons
		"]";
		__TRACE_1("","_strdb")
		#endif
		_res = "Arma2Net.Unmanaged" callExtension ("DomDatabase ['Write','" + _uid +
		"','" + (_pa select 6) + //  name player
		"'," + str(round((_pa select 14) + _diffscore)) + // total score player
		", " + str(round(_pa select 15)) + // total time played on the server
		", " + str(round(_pa select 16)) + // teamkills total
		", " + str(round(_pa select 17)) + // total number played on the server
		", " + str(round(_pa select 19)) + // AI kills
		", " + str(round(_pa select 20)) + // Human kills
		", " + str(round(_pa select 21)) + // vehicle type car kills
		", " + str(round(_pa select 22)) + // vehicle type APC kills
		", " + str(round(_pa select 23)) + // vehicle type tank kills
		", " + str(round(_pa select 24)) + // vehicle type plane kills
		", " + str(round(_pa select 25)) + // vehicle type chopper kills
		", " + str(round(_pa select 26)) + // radio tower kills
		", " + str(round(_pa select 27)) + // main target objects kills
		", " + str(round(_pa select 28)) + // side missions resolved
		", " + str(round(_pa select 29)) + // deaths/uncons
		"]");
		// teamkill number not saved for now
		__TRACE_1("","_res")
	};
	
	(_pa select 4) call FUNC(markercheck);
	__TRACE_1("player store after change","_pa")
};
