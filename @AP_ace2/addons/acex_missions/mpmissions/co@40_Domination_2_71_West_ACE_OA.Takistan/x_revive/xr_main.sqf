// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_revive\xr_main.sqf"
#include "xr_macros.sqf"

#define __shots ["shotBullet","shotShell","shotRocket","shotMissile","shotTimeBomb","shotMine"]
#define __plsd1 player setDamage 1
#define __addmx _p addMagazine _x
#define __addwx _p addWeapon _x

if (isNil QGVARXR(with_marker)) then {
	GVARXR(with_marker) = true;
};

#define __unc #UNCONSCIOUS

[0, QGVARXR(wn), FUNCXR(handlenet)] call d_fnc_NetAddEvent;
[0, QGVARXR(setCap), {(_this select 0) setCaptive (_this select 1)}] call d_fnc_NetAddEvent;
[0, QGVARXR(a1), {_this switchMove "ainjpfalmstpsnonwrfldnon_carried_up"}] call d_fnc_NetAddEvent;
[0, QGVARXR(a2), {_this switchMove "acinpknlmstpsraswrfldnon_acinpercmrunsraswrfldnon"}] call d_fnc_NetAddEvent;
[0, QGVARXR(a3), {_this switchMove "ainjppnemstpsnonwrfldb_still"}] call d_fnc_NetAddEvent;
[0, QGVARXR(a4), {_this switchMove "AidlPpneMstpSnonWnonDnon_SleepA_death"}] call d_fnc_NetAddEvent;
[0, QGVARXR(a55), {_this switchMove "adthppnemstpsraswrfldnon_1"}] call d_fnc_NetAddEvent;
[0, QGVARXR(dir), {_this setDir 180}] call d_fnc_NetAddEvent;
if (!isDedicated) then {
	FUNCXR(cpr) = {
		__pSetVar [QGVARXR(unconendtime), __pGetVar(GVARXR(unconendtime)) + GVARXR(cpr_time_add)];
	};
	[QGVARXR(m_msg), {
		if (isPlayer (_this select 0) && {(_this select 0) != (_this select 1)}) then {
			(format [(localize "STR_DOM_MISSIONSTRING_911"), name (_this select 0), name (_this select 1)]) call d_fnc_GlobalChat;
		} else {
			(format [(localize "STR_DOM_MISSIONSTRING_912"), name (_this select 1)]) call d_fnc_GlobalChat;
		};
	}] call d_fnc_NetAddEventToClients;
	[QGVARXR(cpr), FUNCXR(cpr)] call d_fnc_NetAddEventSTO;
};

[QGVARXR(addpoint), {
	private ["_killer", "_killed", "_par", "_par1", "_namep", "_namek", "_killedfriendly"];
	PARAMS_2(_killer,_killed);
	_killer addScore 1;
	#ifdef __TT__
	_par1 = d_player_store getVariable (getPlayerUID _killed);
	_namep = if (isNil "_par1") then {"Unknown"} else {_par1 select 6};
	_par = d_player_store getVariable (getPlayerUID _killer);
	_namek = if (isNil "_par") then {"Unknown"} else {_par select 6};
	_sidegrpk = side (group _killer);
	switch (_sidegrpk) do {
		case west: {
			d_points_west = d_points_west + (d_tt_points select 8);
			["d_u_k", [_namek, _namep, "WEST"]] call d_fnc_NetCallEvent;
		};
		case east: {
			d_points_east = d_points_east + (d_tt_points select 8);
			["d_u_k", [_namek, _namep, "EAST"]] call d_fnc_NetCallEvent;
		};
	};
	if (d_domdatabase) then {
		_par set [20, (_par select 20) + 1];
	};
	#else
	if (d_domdatabase) then {
		_par1 set [29, (_par1 select 29) + 1];
	};
	[QGVARXR(m_msg), [_killer, _killed]] call d_fnc_NetCallEventToClients;
	#endif
}] call d_fnc_NetAddEventCTS;
[1, QGVARXR(subpoint), {
	(_this select 0) addScore (d_sub_tk_points * -1);
	if (d_domdatabase) then {
		(_this select 0) call d_fnc_PAddTeamKillPoints;
	};
}] call d_fnc_NetAddEvent;

if (d_sub_kill_points != 0) then {
	if (d_sub_kill_points > 0) then {d_sub_kill_points = d_sub_kill_points * -1};
	[QGVARXR(add_sub_kill), {_this addScore d_sub_kill_points}] call d_fnc_NetAddEventCTS;
};

[QGVARXR(unconmsg), {
	(format [(localize "STR_DOM_MISSIONSTRING_912"), name _this]) call d_fnc_GlobalChat;
}] call d_fnc_NetAddEventToClients;
[2, QGVARXR(subpoint), {
	if (isPlayer (_this select 0)) then {
		(format [(localize "STR_DOM_MISSIONSTRING_911"), name (_this select 0), name (_this select 1)]) call d_fnc_GlobalChat;
	} else {
		(format [(localize "STR_DOM_MISSIONSTRING_912"), name (_this select 1)]) call d_fnc_GlobalChat;
	};
}] call d_fnc_NetAddEvent;
[QGVARXR(msg), {
	if ((_this select 2) == side (group player) && (_this select 1) != GVARXR(name_player)) then {
		GVARXR(msg_logic) globalChat format [(localize "STR_DOM_MISSIONSTRING_913"), _this select 1, _this select 0];
	};
	if ((_this select 1) == GVARXR(name_player)) then {
		_this spawn {
			sleep 2.5;
			GVARXR(msg_logic) globalChat (format [(localize "STR_DOM_MISSIONSTRING_914"), _this select 0]);
		};
	};
}] call d_fnc_NetAddEventToClients;
[0, QGVARXR(swmnon), {_this switchMove ""}] call d_fnc_NetAddEvent;
[0, QGVARXR(wn2), {if (local (_this select 0)) then {_this call FUNCXR(handlenet)}}] call d_fnc_NetAddEvent;
#ifdef __TT__
[QGVARXR(addActions), {if (player != (_this select 0) && {(_this select 1) == side (group player)}) then {(_this select 0) call FUNCXR(addActions)}}] call d_fnc_NetAddEventToClients; // TODO, what if more than one side is friendly
#else
[QGVARXR(addActions), {if (player != _this) then {_this call FUNCXR(addActions)}}] call d_fnc_NetAddEventToClients;
#endif
[QGVARXR(removeActions), {if (player != _this) then {_this call FUNCXR(removeActions)}}] call d_fnc_NetAddEventToClients;
[0, QGVARXR(hpl), {_this hideobject true}] call d_fnc_NetAddEvent;
[QGVARXR(grpl), {(_this select 0) selectLeader (_this select 1)}] call d_fnc_NetAddEventSTO;
[2, QGVARXR(delml), {if (str(markerPos _this) != "[0,0,0]") then {deleteMarkerLocal _this}}] call d_fnc_NetAddEvent;
[0, QGVARXR(setgid), {(_this select 0) setGroupid [_this select 1]}] call d_fnc_NetAddEvent;

if (!isDedicated) then {
	[QGVARXR(doHandleHeal), FUNCXR(dohandleheal)] call d_fnc_NetAddEventSTO;
};

if (GVARXR(withSounds)) then {
	[QGVARXR(say3d), {(_this select 0) say3D (_this select 1)}] call d_fnc_NetAddEventToClients;
};

if (GVARXR(with_marker)) then {
	//check markers
	[0, QGVARXR(umarker), {_this call FUNCXR(addmarker)}] call d_fnc_NetAddEvent;
	if (isServer) then {
		GVARXR(uncon_m_units) = [];
	};
	FUNCXR(addmarker) = {
		private ["_pos", "_name", "_unitstr", "_mname"];
		if (!alive _this) exitWith {};
		_unitstr = str _this;
		if (isServer) then {
			GVARXR(uncon_m_units) set [count GVARXR(uncon_m_units), _unitstr];
		};
		if (isDedicated) exitWith {};
		_pos = getPosASL _this;
		_name = name _this;
		_mname = _unitstr + __xrdead;
		if (str(markerPos _mname) != "[0,0,0]") then {
			deleteMarkerLocal _mname;
		};		
		if (side (group _this) == GVARXR(side_pl)) then {
			[_mname, _pos, "ICON", "ColorBlue", [0.4,0.4], format [(localize "STR_DOM_MISSIONSTRING_910"), _name], 0, "Flag1"] call FUNCXR(CreateMarkerLocal);
		};
	};
	FUNCXR(movemarker) = {
		if (!alive _this) exitWith {};
		_unitstr = str _this;
		_mname = _unitstr + __xrdead;
		if (str(markerPos _mname) != "[0,0,0]") then {
			_pos = getPosASL _this;
			_mname setMarkerPosLocal _pos;
		};
	};
	
	[2, QGVARXR(movemarker), FUNCXR(movemarker)] call d_fnc_NetAddEvent;
};

if (isDedicated) exitWith {};

if (isNil QGVARXR(respawn_available_after)) then {GVARXR(respawn_available_after) = 150};
if (isNil QGVARXR(near_player_dist)) then {GVARXR(near_player_dist) = 250};
if (isNil QGVARXR(lifetime)) then {GVARXR(lifetime) = 300};
if (isNil QGVARXR(can_revive)) then {GVARXR(can_revive) = []};
if (isNil QGVARXR(withweaponrespawn)) then {GVARXR(withweaponrespawn) = true};

if (isNil QGVARXR(respawn_markers)) then {GVARXR(respawn_markers) = ["base"]};

GVARXR(use_dom_opendlg) = false;

GVARXR(dropAction) = -3333;
if (isNil QGVARXR(phd_invulnerable)) then {GVARXR(phd_invulnerable) = false};

GVARXR(respawn_delay) = getNumber(missionConfigFile >> "respawndelay");

FUNCXR(blurr) = {
	GVARXR(blurr) ppEffectEnable true;
	GVARXR(blurr) ppEffectAdjust [1];
	GVARXR(blurr) ppEffectCommit 1;
	sleep 1;
	GVARXR(blurr) ppEffectAdjust [0];
	GVARXR(blurr) ppEffectCommit 1;
	sleep 1;
	GVARXR(blurr) ppEffectEnable false;
};

FUNCXR(GetSlope) = {
	private ["_pos", "_rad", "_centrH", "_height"];
	PARAMS_2(_pos,_rad);
	GVARXR(slopeObj) setPos _pos;
	_centrH = getPosASL GVARXR(slopeObj) select 2;
	_height = 0;
	for "_dir" from 0 to 315 step 45 do {
		GVARXR(slopeObj) setPos [(_pos select 0) + ((sin _dir) * _rad), (_pos select 1) + ((cos _dir) * _rad),0];
		_height = _height + abs (_centrH - (getPosASL GVARXR(slopeObj) select 2));
	};
	_height / 8
};

FUNCXR(DoSlope) = {
	private ["_pos", "_sl", "_unit", "_rad", "_found", "_cx", "_cy", "_x1", "_y1"];
	PARAMS_3(_pos,_sl,_unit);
	_rad = 0;_found = false;
	while {_sl >= 0.78} do {
		_cx = _pos select 0;_cy = _pos select 1;
		_rad = _rad + 10;
		for "_ang" from 0 to 345 step 15 do {
			_x1 = _cx - (_rad * sin _ang);
			_y1 = _cy - (_rad * cos _ang);
			_sl = [[_x1, _y1, 0], 1] call FUNCXR(GetSlope);
			if (_sl < 0.78) exitWith {
				_pos = [_x1, _y1, 0];
				_found = true;		
			};
		};
		if (_found) exitWith {};
	};
	if (_found) then {_unit setPos [_pos select 0, _pos select 1, _unit distance _pos]};
};

GVARXR(msg_logic) = "Logic" createVehicleLocal [0,0,0];
FUNCXR(dorevive) = {
	__TRACE("dorevive start");
	private ["_ma", "_endtime"];
	__pSetVar [QGVARXR(pisinaction), true];
	__pSetVar [QGVARXR(stop_revive), false];
	_ma = "ainvpknlmstpslaywrfldnon_medic";
	player playMove _ma;
	_endtime = time + 12;
	// TODO: cancel revive does not work, the animation won't stop. damn. switchmove "" is a nada :(
	//_cancelrevaction = player addAction ["<t color='#FF0000'>Cancel Revive</t>", "x_revive\xr_cancelrevive.sqf", [], -1];
	waitUntil {animationState player == _ma || !alive player || time > _endtime};
	waitUntil {animationState player != _ma || !alive player || __pGetVar(GVARXR(stop_revive)) || time > _endtime};
	//player removeAction _cancelrevaction;
	__pSetVar [QGVARXR(pisinaction), false];
	if (__pGetVar(GVARXR(stop_revive))) exitWith {
		[QGVARXR(swmnon), player] call d_fnc_NetCallEvent;
	};
	if (time > _endtime) exitWith {};
	if (alive player) then {
		if (alive __pGetVar(GVARXR(cursorTarget))) then {
			if (GVARXR(pl_can_revive)) then {
				if (GVARXR(help_bonus) > 0 && GVARXR(max_lives) != -1) then {
					if (!d_with_ranked) then {
						hintSilent format [(localize "STR_DOM_MISSIONSTRING_915"), GVARXR(help_bonus)];
					} else {
						hintSilent format [(localize "STR_DOM_MISSIONSTRING_916"), GVARXR(help_bonus), d_ranked_a select 21];
						["d_pas", [player, d_ranked_a select 21]] call d_fnc_NetCallEventCTS;
					};
					_lives = __pGetVar(GVARXR(lives));
					_lives = _lives + GVARXR(help_bonus);
					__TRACE_1("dorevive","_lives");
					__pSetVar [QGVARXR(lives), _lives];
					["d_crl", [getPlayerUID player, _lives]] call d_fnc_NetCallEventCTS;
				};
				__pGetVar(GVARXR(cursorTarget)) setVariable [QGVARXR(pluncon),false,true];
				if (GVARXR(revivemsg)) then {
					[QGVARXR(msg), [GVARXR(name_player), name __pGetVar(GVARXR(cursorTarget)), side (group player)]] call d_fnc_NetCallEventToClients;
					GVARXR(msg_logic) globalChat format [(localize "STR_DOM_MISSIONSTRING_914a"), name __pGetVar(GVARXR(cursorTarget))];
				};
			} else {
				[QGVARXR(cpr), [__pGetVar(GVARXR(cursorTarget))]] call d_fnc_NetCallEventSTO;
			};
		};
	};
	__TRACE("dorevive end");
};

FUNCXR(KHUncKeyESC) = {
	__TRACE("KHUncKeyESC ESC pressed");
	disableSerialization;
	createDialog QGVARXR(UnconDlg);
	(__uiGetVar(GVARXR(UnconDlg)) displayCtrl 1000) ctrlShow false;
	(__uiGetVar(GVARXR(UnconDlg)) displayCtrl 1001) ctrlShow false;
};

FUNCXR(KeyboardHandlerKeyDown) = {
	private ["_key", "_unc"];
	_key = _this select 1;
	_unc = __pGetVar(GVARXR(pluncon));
	if (_unc && _key == 1) then {
		if !(GVARXR(followcam)) then {
			0 spawn FUNCXR(KHUncKeyESC);
		};
	};
	false
};

FUNCXR(respawneh) = {
	private ["_old", "_d_pos"];
	_old = _this select 1;
	__TRACE_1("respawneh","_old");
	if (!isNull _old) then {
		deleteVehicle _old;
	};
	if (GVARXR(withweaponrespawn)) then {
		call FUNCXR(WeapRespawn2);
	};
	_d_pos = __pGetVar(GVARXR(death_pos));
	__TRACE_1("respawneh","_d_pos");
	if (count _d_pos > 0) then {
		player setDir (_d_pos select 1);
		player setPos (_d_pos select 0);
		
		if (!__pGetVar(GVARXR(isdead))) then {
			player playActionNow "Die";
			[1] spawn FUNCXR(uncon);
			if (GVARXR(with_marker)) then {
				[QGVARXR(umarker), player] call d_fnc_NetCallEvent;
			};
		};
		__pSetVar [QGVARXR(death_pos), []];
	} else {	
		if (__pGetVar(GVARXR(pluncon))) then {
			__pSetVar [QGVARXR(pluncon), false, true];
		};
	};
	__pSetVar [QGVARXR(pisinaction), false];
	__pSetVar [QGVARXR(is_dragging), false];
	__pSetVar [QGVARXR(dragged), false, true];
	__pSetVar [QGVARXR(busyt), -1, true];
};

FUNCXR(CheckRespawn) = {
	private ["_pos","_dir"];
	_pos = position player;
	_pos set [2, player distance _pos];
	_dir = direction player;
	__TRACE_2("CheckRespawn","_pos","_dir");
	__pSetVar [QGVARXR(death_pos), [_pos, _dir]];
};

FUNCXR(WeapRespawn1) = {
	private ["_body", "_oabackpackmags", "_oabackpackweaps", "_ubp", "_ubackp", "_weapons", "_magazines"];
	_body = player;
	#ifdef __OAXR__
	_oabackpackmags = [[],[]];
	_oabackpackweaps = [[],[]];
	__pSetVar [QGVARXR(oabackpackmags), _oabackpackmags];
	__pSetVar [QGVARXR(oabackpackweaps), _oabackpackweaps];
	_ubp = unitBackpack _body;
	_ubackp = if (!isNull _ubp) then {typeOf _ubp} else {""};
	__pSetVar [QGVARXR(ubp), _ubackp];
	if (_ubackp != "") then {
		_oabackpackmags = getMagazineCargo _ubp;
		_oabackpackweaps = getWeaponCargo _ubp;
		__pSetVar [QGVARXR(oabackpackmags), _oabackpackmags];
		__pSetVar [QGVARXR(oabackpackweaps), _oabackpackweaps];
	};
	#endif
	_weapons = weapons _body;
	_magazines = magazines _body;
	__pSetVar [QGVARXR(weapons), _weapons];
	__pSetVar [QGVARXR(magazines), _magazines];
	if (GVARXR(dead_removeweapon)) then {
		if (primaryWeapon _body != "") then {
			_body removeWeapon (primaryWeapon _body);
		};
		if (secondaryWeapon _body != "") then {
			_body removeWeapon (secondaryWeapon _body);
		};
	};
};

FUNCXR(WeapRespawn2) = {
	_p = player;
	removeAllItems _p;
	removeAllWeapons _p;
	{__addmx} forEach __pGetVar(GVARXR(magazines));
	{__addwx} forEach __pGetVar(GVARXR(weapons));
	_primw = primaryWeapon _p;
	if (_primw != "") then {
		_p selectWeapon _primw;
		_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
		_p selectWeapon (_muzzles select 0);
	};
	#ifdef __OAXR__
	if (!isNull (unitBackpack _p)) then {removeBackpack _p};
	if (__pGetVar(GVARXR(ubp)) != "") then {
		_p addBackpack __pGetVar(GVARXR(ubp));
		_bp = unitBackpack _p;
		clearMagazineCargo _bp;
		clearWeaponCargo _bp;
		if (count (__pGetVar(GVARXR(oabackpackmags)) select 0) > 0) then {
			_mags = __pGetVar(GVARXR(oabackpackmags)) select 0;
			_mcount = __pGetVar(GVARXR(oabackpackmags)) select 1;
			{_bp addMagazineCargo [_x, _mcount select _forEachIndex]} forEach _mags;
		};
		if (count (__pGetVar(GVARXR(oabackpackweaps)) select 0) > 0) then {
			_weaps = __pGetVar(GVARXR(oabackpackweaps)) select 0;
			_mcount = __pGetVar(GVARXR(oabackpackweaps)) select 1;
			{_bp addWeaponCargo [_x, _mcount select _forEachIndex]} forEach _weaps;
		};
	};
	#endif
};

FUNCXR(MapClickRespawn) = {
	private ["_respawn_pos","_etime", "_mhq", "_mhqobj"];
	_respawn_pos = _this;
	__TRACE_1("MapClickRespawn","_respawn_pos");
	__pSetVar [QGVARXR(pluncon), false, true];
	[QGVARXR(setCap), [player, false]] call d_fnc_NetCallEvent;
	__pSetVar [QGVARXR(u_state), 200];
	titleText [(localize "STR_DOM_MISSIONSTRING_917"),"BLACK OUT", 1];
	[QGVARXR(wn), [player,105]] call d_fnc_NetCallEvent;
	__plsd1;
	__TRACE("MapClickRespawn player setDamage 1");
	GVARXR(stopspect) = true;
	sleep 0.5;
	_etime = time + __pGetVar(GVARXR(presptime)) - 1.3;
	__TRACE_1("MapClickRespawn","_etime");
	waitUntil {sleep 0.121;time >= _etime};
	
	_nos = _respawn_pos nearEntities ["All", 20];
	__TRACE_1("MapClickRespawn","_nos");
	_mhqobj = objNull;
	{
		if (_x getVariable ["d_vec_type", ""] == "MHQ") exitWith {
			_mhqobj = _x;
		};
	} forEach _nos;
	__TRACE_1("MapClickRespawn","_mhqobj");
	waitUntil {sleep 0.223;alive player};
	[QGVARXR(wn), [player,105]] call d_fnc_NetCallEvent;
	if (!isNull _mhqobj) then {
		_newppos = _mhqobj modelToWorld [0,-6,0];
		player setPosATL [_newppos select 0, _newppos select 1, 0];
		player setDir (direction _mhqobj);
		_nobs = switch (true) do {
			case ("OA" in d_version): {nearestObjects [player, [d_the_box,"M1133_MEV_EP1","BMP2_HQ_TK_EP1"], 30]};
			case ("CO" in d_version): {nearestObjects [player, [d_the_box,"LAV25_HQ","BTR90_HQ"], 30]};
		};
		{player reveal _x} forEach _nobs;
	} else {
		if (isNil "d_with_carrier") then {
			player setpos _respawn_pos;
		} else {
			if (surfaceIsWater _respawn_pos) then {
				player setPosASL [markerpos "base_spawn_1" select 0, markerpos "base_spawn_1" select 1, 16.20];
			} else {
				player setpos _respawn_pos;
			};
		};
	};
	titleText [(localize "STR_DOM_MISSIONSTRING_918"),"BLACK IN", 6];
	if (GVARXR(max_lives) != -1) then {
		sleep 3;
		if (__pGetVar(GVARXR(lives)) > -1) then {
			hintSilent format [(localize "STR_DOM_MISSIONSTRING_919"), __pGetVar(GVARXR(lives))];
		};
	};
	__TRACE("MapClickRespawn done");
};

FUNCXR(joingr) = {
	//if (!isNull GVARXR(pl_group)) then {
	//	[player] joinSilent GVARXR(pl_group);
	//} else {
	//	private ["_newg"];
	//	_newg = createGroup GVARXR(side_pl);
	//	[player] joinSilent _newg;
	//	if (d_player_str_group != "") then {
	//		[QGVARXR(setgid), [player, d_player_str_group]] call d_fnc_NetCallEvent;
	//	};
	//};
	__TRACE("joingr");
	if (__pGetVar(GVARXR(isleader))) then {
		[QGVARXR(grpl), [GVARXR(pl_group), player]] call d_fnc_NetCallEventSTO;
	};
	__pSetVar [QGVARXR(isleader), false];
};

#define __ucdlg1022 (__uiGetVar(GVARXR(UnconDlg)) displayCtrl 1022)
#define __spectdlg1022 (__uiGetVar(GVARXR(SpectDlg)) displayCtrl 1022)

FUNCXR(OnMapSingleClickResp) = {
	private ["_pos", "_ma", "_dist", "_mcol", "_mes", "_nearest", "_distnearest"];
	if (!GVARXR(respawn_available)) exitWith {};
	if (!GVARXR(followcam)) then {
		__ucdlg1022 ctrlSetText "";
		__ucdlg1022 ctrlSetTextColor [1,0,0,1];
		__ucdlg1022 ctrlCommit 0;
	} else {
		__spectdlg1022 ctrlSetText "";
		__spectdlg1022 ctrlSetTextColor [1,0,0,1];
		__spectdlg1022 ctrlCommit 0;
	};
	_pos = _this;
	_nearest = [];
	_distnearest = 1000000000;
	{
		_ma = _x select 1;
		_dist = _pos distance markerPos _ma;
		if (_dist < 30) then {
			if (_dist < _distnearest) then {
				_distnearest = _dist;
				_nearest = _x;
			};
		};
	} forEach GVARXR(respmarkerar);
	
	__TRACE_2("OnMapSingleClickResp","_pos","_nearest");
	
	if (count _nearest == 0) exitWith {};

	_ma = _nearest select 1;
	_dist = _pos distance markerPos _ma;
	__TRACE_2("OnMapSingleClickResp","_ma","_dist");
	_mcol = markerColor _ma;
	__TRACE_2("OnMapSingleClickResp","_dist","_mcol");
	if (_dist < 30 && toUpper _mcol == "COLORGREEN") exitWith {
		_pos = markerPos _ma;
		_pos = markerPos _ma;
		__TRACE_1("OnMapSingleClickResp","_pos");
		GVARXR(stopspect) = true;
		closeDialog 0;
		_pos spawn FUNCXR(MapClickRespawn);
	};
	_mes = if (_dist < 30) then {_nearest select 3} else {""};
	__TRACE_1("OnMapSingleClickResp","_mes");
	if (_mes != "") then {
		if (!GVARXR(followcam)) then {
			__ucdlg1022 ctrlSetText _mes;
			__ucdlg1022 ctrlSetTextColor [1,0,0,1];
			__ucdlg1022 ctrlCommit 0;
		} else {
			__spectdlg1022 ctrlSetText _mes;
			__spectdlg1022 ctrlSetTextColor [1,0,0,1];
			__spectdlg1022 ctrlCommit 0;
		};
	};
};

FUNCXR(MapClickRespawn2) = {
	private ["_ma", "_dist", "_mcol", "_mes", "_nearest", "_distnearest"];
	if (!GVARXR(followcam)) then {
		__ucdlg1022 ctrlSetText "";
		__ucdlg1022 ctrlSetTextColor [1,0,0,1];
		__ucdlg1022 ctrlCommit 0;
	} else {
		__spectdlg1022 ctrlSetText "";
		__spectdlg1022 ctrlSetTextColor [1,0,0,1];
		__spectdlg1022 ctrlCommit 0;
	};
	_respawn_pos = _this;
	_nearest = [];
	_distnearest = 1000000000;
	{
		_ma = _x select 1;
		_dist = _respawn_pos distance markerPos _ma;
		if (_dist < 30) then {
			if (_dist < _distnearest) then {
				_distnearest = _dist;
				_nearest = _x;
			};
		};
	} forEach GVARXR(respmarkerar);
	
	if (count _nearest == 0) exitWith {};
	
	_ma = _nearest select 1;
	_dist = _respawn_pos distance markerPos _ma;
	_mcol = markerColor _ma;
	if (_dist < 30 && {toUpper _mcol == "COLORGREEN"}) exitWith {
		_respawn_pos = markerPos _ma;
		closeDialog 0;
		GVARXR(stopspect) = true;
		_respawn_pos spawn FUNCXR(MapClickRespawn);
		//player setPos _respawn_pos; // TODO: Check for vehicle at resp pos and put player behind it
		titleText [(localize "STR_DOM_MISSIONSTRING_918"),"BLACK IN", 5];
		if (__pGetVar(GVARXR(isleader))) then {
			[QGVARXR(grpl), [group player, player]] call d_fnc_NetCallEventSTO;
		};
	};
	_mes = if (_dist < 30) then {_nearest select 3} else {""};
	if (_mes != "") then {
		if (!GVARXR(followcam)) then {
			__ucdlg1022 ctrlSetText _mes;
			__ucdlg1022 ctrlSetTextColor [1,0,0,1];
			__ucdlg1022 ctrlCommit 0;
		} else {
			__spectdlg1022 ctrlSetText _mes;
			__spectdlg1022 ctrlSetTextColor [1,0,0,1];
			__spectdlg1022 ctrlCommit 0;
		};
	};
};

FUNCXR(OnMapSingleClickResp2) = {
	private ["_pos", "_ma", "_dist", "_mcol", "_mes", "_nearest", "_distnearest"];
	if (!GVARXR(followcam)) then {
		__ucdlg1022 ctrlSetText "";
		__ucdlg1022 ctrlSetTextColor [1,0,0,1];
		__ucdlg1022 ctrlCommit 0;
	} else {
		__spectdlg1022 ctrlSetText "";
		__spectdlg1022 ctrlSetTextColor [1,0,0,1];
		__spectdlg1022 ctrlCommit 0;
	};
	_pos = _this;
	_nearest = [];
	_distnearest = 1000000000;
	{
		_ma = _x select 1;
		_dist = _pos distance markerPos _ma;
		if (_dist < 30) then {
			if (_dist < _distnearest) then {
				_distnearest = _dist;
				_nearest = _x;
			};
		};
	} forEach GVARXR(respmarkerar);
	
	if (count _nearest == 0) exitWith {};
	
	_ma = _nearest select 1;
	_dist = _pos distance markerPos _ma;
	_mcol = markerColor _ma;
	if (_dist < 30 && {toUpper _mcol == "COLORGREEN"}) exitWith {
		GVARXR(pl_has_pos_changed) = true;
		_pos = markerPos _ma;
		GVARXR(stopspect) = true;
		closeDialog 0;
		_pos spawn FUNCXR(MapClickRespawn2);
	};
	_mes = if (_dist < 30) then {_nearest select 3} else {""};
	if (_mes != "") then {
		if (!GVARXR(followcam)) then {
			__ucdlg1022 ctrlSetText _mes;
			__ucdlg1022 ctrlSetTextColor [1,0,0,1];
			__ucdlg1022 ctrlCommit 0;
		} else {
			__spectdlg1022 ctrlSetText _mes;
			__spectdlg1022 ctrlSetTextColor [1,0,0,1];
			__spectdlg1022 ctrlCommit 0;
		};
	};
};

FUNCXR(resp_dlg_helper) = {
	__TRACE("resp_dlg_helper start");
	while {true} do {
		waitUntil {!dialog};
		if (GVARXR(pl_has_pos_changed)) exitWith {};
		if (!GVARXR(no_respawn_dialog)) then {
			createDialog QGVARXR(RespDlg);
		};
	};
	if (GVARXR(max_lives) != -1) then {
		if (__pGetVar(GVARXR(lives)) > -1) then {
			hintSilent format [(localize "STR_DOM_MISSIONSTRING_919"), __pGetVar(GVARXR(lives))];
		};
	};
	__TRACE("resp_dlg_helper end");
};

FUNCXR(waterfix) = {
	private ["_helpero", "_weaps", "_mags", "_radius", "_endpos", "_markerpos", "_angle", "_x1", "_y1", "_p", "_center_x", "_center_y"];
	titleText ["","BLACK OUT", 1];
	titleCut [(localize "STR_DOM_MISSIONSTRING_920"), "PLAIN"];
	_helpero = d_HeliHEmpty createVehicleLocal (getPosASL player);
	_weaps = weapons player;
	_mags = magazines player;
	removeAllWeapons player;
	_radius = 20;
	_endpos = getPosASL _helpero;
	_markerpos = markerPos QGVARXR(center);
	while {surfaceIsWater _endpos} do {
		_endpos = getPosASL _helpero;
		_center_x = _endpos select 0;
		_center_y = _endpos select 1;
		_angle = [_endpos, _markerpos] call FUNCXR(DirTo);
		_angle = _angle + 180;
		_x1 = _center_x - (_radius * sin _angle);
		_y1 = _center_y - (_radius * cos _angle);
		_endpos = [_x1, _y1, 0];
		_helpero setPos _endpos;
		sleep 0.01;
	};
	_p = player;
	_p setPos _endpos;
	removeAllItems _p;
	removeAllWeapons _p;
	{__addmx} forEach _mags;
	{__addwx} forEach _weaps;
	titleText ["","BLACK IN", 1];
	titleCut [" ", "PLAIN"];
	deleteVehicle _helpero;
};

FUNCXR(targetsslbchange) = {
	private ["_sel", "_ctrl", "_selIdx", "_data", "_unit"];
	disableSerialization;
	_sel = _this;
	_ctrl = _sel select 0;
	_selIdx = _sel select 1;
	if (_selIdx == -1) exitWith {};
	_data = lbData [1000, _selIdx];
	if (_data == GVARXR(spectcamtargetstr)) exitWith {};
	_unit = __getMNsVar2(_data);
	if (isNull _unit) exitWith {};
	GVARXR(spectcamtargetstr) = _data;
	_posunit = position _unit;
	_posunit set [2, 2];
	GVARXR(spectcamtarget) = _unit;
	GVARXR(spectcam) camSetTarget GVARXR(spectcamtarget);
	GVARXR(spectcam) camSetPos _posunit;
	GVARXR(spectcam) cameraEffect ["INTERNAL", "Back"];
	GVARXR(spectcam) camCommit 0;
	ctrlSetText [1010, lbText [1000, _selIdx]];
};

FUNCXR(MouseDownClickedLoop) = {
	__TRACE("MouseDownClickedLoop on");
	GVARXR(mousecheckon) = true;
	while {GVARXR(MouseButtons) select 1 || GVARXR(MouseButtons) select 0} do {
		switch (true) do {
			case (!(GVARXR(MouseButtons) select 0) && (GVARXR(MouseButtons) select 1)): {
				GVARXR(fangle) = GVARXR(fangle) - ((GVARXR(mouseDeltaPos) select 0) * 360);
				GVARXR(fangleY) = GVARXR(fangleY) + ((GVARXR(mouseDeltaPos) select 1) * 180);
				switch (true) do {
					case (GVARXR(fangleY) > 89): {GVARXR(fangleY) = 89};
					case (GVARXR(fangleY) < -89): {GVARXR(fangleY) = -89};
				};
				//__TRACE_2("MouseDownClickedLoop","xr_fangle","xr_fangleY");
			};
			case ((GVARXR(MouseButtons) select 0) && !(GVARXR(MouseButtons) select 1)): {
				GVARXR(sdistance) = GVARXR(sdistance) - ((GVARXR(mouseDeltaPos) select 1) * 10);
				switch (true) do {
					case (GVARXR(sdistance) > GVARXR(maxDistance)): {GVARXR(sdistance) = GVARXR(maxDistance)};
					case (GVARXR(sdistance) < -GVARXR(maxDistance)): {GVARXR(sdistance) = -GVARXR(maxDistance)};
				};
				if (GVARXR(sdistance) < -0.6) then {GVARXR(sdistance) = -0.6};
				//__TRACE_1("MouseDownClickedLoop","xr_sdistance");
			};
			case ((GVARXR(MouseButtons) select 0) && (GVARXR(MouseButtons) select 1)): {
				GVARXR(szoom) = GVARXR(szoom) - ((GVARXR(mouseDeltaPos) select 1) * 3);
				switch (true) do {
					case (GVARXR(szoom) > 2): {GVARXR(szoom) = 2};
					case (GVARXR(szoom) < 0.05): {GVARXR(szoom) = 0.05};
				};
				//__TRACE_1("MouseDownClickedLoop","xr_szoom");
			};
		};
		sleep 0.0034;
	};
	GVARXR(mousecheckon) = false;
	__TRACE("MouseDownClickedLoop off");
};

FUNCXR(DlgEvents) = {
	private "_param";
	_param = _this select 1;
	switch (_this select 0) do {
		case "MouseMoving": {
			GVARXR(MouseCoord) = [_param select 1, _param select 2];
		};
		case "MouseButtonDown": {
			__TRACE_1("DlgEvents MouseButtonDown","_param");
			GVARXR(MouseButtons) set [_param select 1, true];
			if (!GVARXR(mousecheckon)) then {
				0 spawn FUNCXR(MouseDownClickedLoop);
			};
		};
		case "MouseButtonUp": {
			GVARXR(MouseButtons) set[_param select 1, false];
		};
		case "MouseZChanged": {
			GVARXR(MouseScroll) = GVARXR(MouseScroll) + (_param select 1);
		};
	};
};

FUNCXR(spectating) = {
	__TRACE("spectating start");
	private ["_withresp", "_disp", "_pllist", "_plnamelist", "_u", "_uc", "_add", "_idx", "_forEachIndex", "_campos", "_updatelb", "_timer", "_h", "_fangle", "_fangleY", "_sdistance", "_setidx", "_bb", "_foo", "_hstr", "_vpmtw", "_cxpos", "_cypos", "_czpos", "_gjp", "_lsdist", "_l", "_d", "_z", "_co","_l", "_player_has_no_lifes", "_plposm", "_nposvis"];
	GVARXR(MouseCoord) = [0.5,0.5];
	GVARXR(MouseScroll) = 0;
	GVARXR(MouseButtons) = [false,false];
	GVARXR(mouseDeltaPos) = [0,0];
	GVARXR(mouseLastX) = 0.5;
	GVARXR(mouseLastY) = 0.5;
	GVARXR(maxDistance) = 50;
	GVARXR(sdistance) = 1;
	GVARXR(szoom) = 0.976;
	GVARXR(fangle) = 0;
	GVARXR(fangleY) = 15;
	GVARXR(mousecheckon) = false;
	disableSerialization;
	if (!isNil QGVARXR(stopspect)) then {
		if (!GVARXR(stopspect)) then  {
			waitUntil {sleep 0.112;GVARXR(stopspect)};
			sleep 0.2;
		};
	};
	GVARXR(stopspect) = false;
	enableRadio false;
	PARAMS_1(_withresp);
	__TRACE_1("spectating","_withresp");
	if (_withresp) then {
		titleText [(localize "STR_DOM_MISSIONSTRING_921"),"BLACK OUT", 1];
		sleep 5;
		titleText ["","BLACK IN", 1];
	};
	_player_has_no_lifes = __pGetVar(GVARXR(lives)) == -1;
	__TRACE_1("spectating","_player_has_no_lifes");
	GVARXR(camnvgon) = false;
	createDialog QGVARXR(SpectDlg);
	_disp = __uiGetVar(GVARXR(SpectDlg));
	#define __dspctrl(ctrlid) (_disp displayCtrl ctrlid)
	__dspctrl(1000) ctrlShow false;
	__dspctrl(1001) ctrlShow false;
	#define __spectdlg1006e (__uiGetVar(GVARXR(SpectDlg)) displayCtrl 1006)
	if (!_withresp) then {
		__dspctrl(1020) ctrlShow false;
		__dspctrl(1021) ctrlShow false;
		__dspctrl(1005) ctrlShow false;
		__dspctrl(1006) ctrlShow false;
	} else {
		if (GVARXR(respawn_available)) then {
			__spectdlg1006e ctrlSetText (localize "STR_DOM_MISSIONSTRING_922");
			__spectdlg1006e ctrlSetTextColor [1,1,0,1];
			__spectdlg1006e ctrlCommit 0;
		};
	};
	
	_pllist = if (!_player_has_no_lifes) then {[str player]} else {[]};
	__TRACE_1("spectating","_pllist");
	_plnamelist = if (!_player_has_no_lifes) then {[GVARXR(name_player)]} else {[]};
	__TRACE_1("spectating","_plnamelist");
	_helperls = [];
	if (!_player_has_no_lifes) then {
		{
			_u = __getMNsVar2(_x);
			if (!isNil "_u") then {
				if (!isNull _u && alive _u && {side (group _u) == GVARXR(side_pl) && _u != player}) then {
					_uc = __GV(_u,GVARXR(pluncon));
					if (isNil "_uc") then {_uc = false};
					if (!_uc) then {
						_add = true;
						_distup = -1;
						if (_withresp) then {
							_distup = _u distance player;
							if (_distup > GVARXR(near_player_dist)) then {
								_add = false;
							};
						};
						if (_add) then {
							_helperls set [count _helperls, [_distup, str _u, name _u]];
						};
					};
				};
			};
		} forEach GVARXR(player_entities);
	} else {
		_sfm = markerPos QGVARXR(playerparkmarker);
		_sfm set [2,0];
		{
			_u = __getMNsVar2(_x);
			if (!isNil "_u") then {
				if (!isNull _u && alive _u && {side (group _u) == GVARXR(side_pl) && _u != player}) then {
					_distup = _u distance _sfm;
					if (_distup > 100) then {
						_helperls set [count _helperls, [_distup, str _u, name _u]];
					};
				};
			};
		} forEach GVARXR(player_entities);
	};
	if (count _helperls > 0) then {
		_helperls = [_helperls, 0] call d_fnc_SortAR;
		{
			_pllist set [count _pllist, _x select 1];
			_plnamelist set [count _plnamelist, _x select 2];
		} forEach _helperls;
	};
	_helperls = nil;
	_helperls = [];
	
	lbClear (__uiGetVar(GVARXR(SpectDlg)) displayCtrl 1000);
	{
		_idx = lbAdd [1000, _plnamelist select _forEachIndex];
		lbSetData [1000, _idx, _x];
	} forEach _pllist;
	showcinemaborder false;
	if (!_player_has_no_lifes) then {
		_vkegs = vehicle player;
		_nposvis = ASLToATL (visiblePositionASL _vkegs);
		_campos = [(_nposvis select 0) - 1 + random 2, (_nposvis select 1) - 1 + random 2, 2];
		GVARXR(spectcam) = "camera" camCreate _campos;
		GVARXR(spectcamtarget) = player;
		GVARXR(spectcamtargetstr) = str player;
		GVARXR(spectcam) cameraEffect ["INTERNAL", "Back"];
		GVARXR(spectcamrelpos) = [-2, -2, 2];
		GVARXR(spectcam) camCommit 0;
		__dspctrl(1010) ctrlSetText GVARXR(name_player);
	} else {
		_sfm = markerPos QGVARXR(playerparkmarker);
		_visobj = objNull;
		_exitit = false;
		{
			_u = __getMNsVar2(_x);
			if (!isNull _u && alive _u && {side (group _u) == GVARXR(side_pl) && _u != player}) then {
				if (_u distance _sfm > 100) then {
					_visobj = _u;
					_exitit = true;
				};
			};
			if (_exitit) exitWith {};
		} forEach GVARXR(player_entities);
		if (isNull _visobj) then {_visobj = player};
		_vkegs = vehicle _visobj;
		_nposvis = ASLToATL (visiblePositionASL _vkegs);
		_campos = [(_nposvis select 0) - 1 + random 2, (_nposvis select 1) - 1 + random 2, 2];
		GVARXR(spectcam) = "camera" camCreate _campos;
		GVARXR(spectcamtarget) = _visobj;
		GVARXR(spectcamtargetstr) = str _visobj;
		GVARXR(spectcam) cameraEffect ["INTERNAL", "Back"];
		GVARXR(spectcamrelpos) = [-2, -2, 2];
		GVARXR(spectcam) camCommit 0;
		__dspctrl(1010) ctrlSetText (name _visobj);
	};
	_updatelb = true;
	_timer = time + 10;
	_h = 2;
	_plposm = getPosASL player;
	__TRACE("spectating main loop starts");
	while {!GVARXR(stopspect)} do {
		_fangle = GVARXR(fangle);
		_fangleY = GVARXR(fangleY);
		GVARXR(mouseDeltaPos) set [0, GVARXR(mouseLastX) - (GVARXR(MouseCoord) select 0)];
		GVARXR(mouseDeltaPos) set [1, GVARXR(mouseLastY) - (GVARXR(MouseCoord) select 1)];
		GVARXR(mouseLastX) = GVARXR(MouseCoord) select 0;
		GVARXR(mouseLastY) = GVARXR(MouseCoord) select 1;
		if (GVARXR(MouseScroll) != 0) then {
			GVARXR(sdistance) = GVARXR(sdistance) - (GVARXR(MouseScroll) * 0.11);
			GVARXR(MouseScroll) = GVARXR(MouseScroll) * 0.75;
			switch (true) do {
				case (GVARXR(sdistance) > GVARXR(maxDistance)): {GVARXR(sdistance) = GVARXR(maxDistance)};
				case (GVARXR(sdistance) < -GVARXR(maxDistance)): {GVARXR(sdistance) = -GVARXR(maxDistance)};
			};
			if (GVARXR(sdistance) < -0.6) then {GVARXR(sdistance) = -0.6};
		};
		_sdistance = GVARXR(sdistance);

		if (time > _timer) then {
			if (!_player_has_no_lifes) then {
				_pllist = if (_withresp) then {[str player]} else {[]};
				_plnamelist = if (_withresp) then {[GVARXR(name_player)]} else {[]};
			} else {
				_pllist = [];
				_plnamelist = [];
			};
			_helperls = [];
			if (!_player_has_no_lifes) then {
				{
					_u = __getMNsVar2(_x);
					if (!isNil "_u") then {
						if (!isNull _u && alive _u && {side (group _u) == GVARXR(side_pl) && _u != player}) then {
							_uc = __GV(_u,GVARXR(pluncon));
							if (isNil "_uc") then {_uc = false};
							if (!_uc) then {
								_add = true;
								_distup = -1;
								if (_withresp) then {
									_distup = _u distance player;
									if (_distup > GVARXR(near_player_dist)) then {
										_add = false;
									};
								};
								if (_add) then {
									_helperls set [count _helperls, [_distup, str _u, name _u]];
								};
							};
						};
					};
				} forEach GVARXR(player_entities);
			} else {
				_sfm = markerPos QGVARXR(playerparkmarker);
				_sfms set [2,0];
				{
					_u = __getMNsVar2(_x);
					if (!isNil "_u") then {
						if (!isNull _u && alive _u && {side (group _u) == GVARXR(side_pl) && _u != player}) then {
							_distup = _u distance _sfm;
							if (_distup > 100) then {
								_helperls set [count _helperls, [_distup, str _u, name _u]];
							};
						};
					};
				} forEach GVARXR(player_entities);
			};
			if (count _helperls > 0) then {
				_helperls = [_helperls, 0] call d_fnc_SortAR;
				{
					_pllist set [count _pllist, _x select 1];
					_plnamelist set [count _plnamelist, _x select 2];
				} forEach _helperls;
			};
			_updatelb = true;
			_timer = time + 10;
			_helperls = nil;
		};
		if (_updatelb) then {
			if (!isNil {__uiGetVar(GVARXR(SpectDlg))}) then {
				if (ctrlShown (__uiGetVar(GVARXR(SpectDlg)) displayCtrl 1000)) then {
					__TRACE_1("spectating","_updatelb");
					_updatelb = false;
					lbClear (__uiGetVar(GVARXR(SpectDlg)) displayCtrl 1000);
					_setidx = -1;
					{
						_idx = lbAdd [1000, _plnamelist select _forEachIndex];
						lbSetData [1000, _idx, _x];
						if (GVARXR(spectcamtargetstr) == _x) then {_setidx = _forEachIndex};
					} forEach _pllist;
					if (_setidx != -1) then {lbSetCurSel [1000, _setidx]};
				};
			};
		};
		// user pressed ESC
		__TRACE("before spectating ctrl check");
		_spectdisp = __uiGetVar(GVARXR(SpectDlg));
		if ((isNil "_spectdisp" || !ctrlShown (_spectdisp displayCtrl 1002)) && !GVARXR(stopspect)) then {
			__TRACE("spectating ctrl not shown anymore");
			titleText ["","BLACK OUT", 1];
			sleep 3;
			if (!alive player) then {
				__TRACE("spectating player not alive");
				waitUntil {sleep 0.321;alive player};
				sleep 0.1;
			};
			__TRACE("spectating creating new dialog");
			createDialog QGVARXR(SpectDlg);
			_disp = __uiGetVar(GVARXR(SpectDlg));
			#define __dspctrl(ctrlid) (_disp displayCtrl ctrlid)
			__dspctrl(1000) ctrlShow false;
			__dspctrl(1001) ctrlShow false;
			if (GVARXR(respawn_available)) then {
				__spectdlg1006e ctrlSetText (localize "STR_DOM_MISSIONSTRING_922");
				__spectdlg1006e ctrlSetTextColor [1,1,0,1];
				__spectdlg1006e ctrlCommit 0;
			};
			if (!_player_has_no_lifes) then {
				GVARXR(spectcamtarget) = player;
				GVARXR(spectcamtargetstr) = str player;
				GVARXR(spectcam) cameraEffect ["INTERNAL", "Back"];
				GVARXR(spectcamrelpos) = [-2, -2, 2];
				GVARXR(spectcam) camCommit 0;
				__dspctrl(1010) ctrlSetText GVARXR(name_player);
			} else {
				_sfm = markerPos QGVARXR(playerparkmarker);
				_visobj = objNull;
				_exitit = false;
				{
					if (!isNull _u && alive _u && side (group _u) == GVARXR(side_pl) && _u != player) then {
						if (_u distance _sfm > 100) then {
							_visobj = _u;
							_exitit = true;
						};
					};
					if (_exitit) exitWith {};
				} forEach GVARXR(player_entities);
				if (isNull _visobj) then {_visobj = player};
				_vkegs = vehicle _visobj;
				_nposvis = ASLToATL (visiblePositionASL _vkegs);
				_campos = [(_nposvis select 0) - 1 + random 2, (_nposvis select 1) - 1 + random 2, 2];
				GVARXR(spectcam) = "camera" camCreate _campos;
				GVARXR(spectcamtarget) = _visobj;
				GVARXR(spectcamtargetstr) = str _visobj;
				GVARXR(spectcam) cameraEffect ["INTERNAL", "Back"];
				GVARXR(spectcamrelpos) = [-2, -2, 2];
				GVARXR(spectcam) camCommit 0;
				__dspctrl(1010) ctrlSetText (name _visobj);
			};
			_timer = -1;
			titleText ["","BLACK IN", 1];
			__TRACE("spectating blacking in after dialog create");
		};
		if (isNull GVARXR(spectcamtarget)) then { // player disconnect !?!
			_vkegs = vehicle player;
			_nposvis = ASLToATL (visiblePositionASL _vkegs);
			_campos = [(_nposvis select 0) - 1 + random 2, (_nposvis select 1) - 1 + random 2, 2];
			GVARXR(spectcamtarget) = player;
			GVARXR(spectcamtargetstr) = str player;
			GVARXR(spectcam) cameraEffect ["INTERNAL", "Back"];
			GVARXR(spectcamrelpos) = [-2, -2, 2];
			GVARXR(spectcam) camCommit 0;
			__dspctrl(1010) ctrlSetText GVARXR(name_player);
		};
		
		_bb = boundingBox vehicle GVARXR(spectcamtarget);
		_foo = ((_bb select 1) select 2) - ((_bb select 0) select 2);
		_l = ((_bb select 1) select 1) - ((_bb select 0) select 1);
		_hstr = 0.15;
		_h = (_foo * _hstr) + (_h * (1 - _hstr));
		
		_vkegs = vehicle GVARXR(spectcamtarget);
		_vpmtw = ASLToATL (visiblePositionASL _vkegs);
		_cxpos = _vpmtw select 0;
		_cypos = _vpmtw select 1;
		_czpos = _vpmtw select 2;

		_gjp = [_cxpos, _cypos, _czpos + (_h * 0.6)];
		GVARXR(spectcam) camSetTarget _gjp;
		GVARXR(spectcam) camSetFov GVARXR(szoom);
		
		_lsdist = _l * (0.3 max _sdistance);
		_d = -_lsdist;
		_z = sin _fangleY * _lsdist;
		_co = cos _fangleY;
		GVARXR(spectcam) camSetRelPos [(sin _fangle * _d) * _co, (cos _fangle * _d) * _co, _z];
		GVARXR(spectcam) camCommit 0;
		
		// adjust marker if uncon player gets moved. Can happen when he gets dragged/carried or when a shilka hits him (flying miles away)
		if (alive player) then {
			_newplposm = getPosASL player;
			if (_newplposm distance _plposm > 5) then {
				_plposm = _newplposm;
				[QGVARXR(movemarker), player] call d_fnc_NetCallEvent;
			};
		};

		sleep 0.0034;
	};
	closeDialog 0;
	player switchCamera "INTERNAL";
	GVARXR(spectcam) CameraEffect ["Terminate", "Back"];
	camDestroy GVARXR(spectcam);
	enableRadio true;
	__TRACE("spectating end");
};

FUNCXR(addActions) = {
	private ["_unit", "_hasaction"];
	_unit = _this;
	_hasaction = __GV(_unit,GVARXR(ReviveAction));
	if (isNil "_hasaction") then {_hasaction = -9999};
	if (_hasaction == -9999) then {
		_reviveorcprs = if (GVARXR(pl_can_revive)) then {(localize "STR_DOM_MISSIONSTRING_923")} else {(localize "STR_DOM_MISSIONSTRING_924")};
		_reviveorcpr = "<t color='#FF0000'>" + _reviveorcprs + " " + name _unit + "</t>";
		_unit setVariable [QGVARXR(ReviveAction), _unit addAction [_reviveorcpr, "x_revive\xr_dorevive.sqf", [], -1, false, false, "", "(_this distance _target <= 3) && (_target getVariable 'xr_pluncon') && !(_this getVariable 'xr_pisinaction') && time > (_target getVariable 'xr_busyt') && !(_target getVariable 'xr_dragged')"]];
		_unit setVariable [QGVARXR(DragAction), _unit addAction [format ["<t color='#FF0000'>Drag %1</t>", name _unit], "x_revive\xr_dodrag.sqf", [], -1, false, false, "", "(_this distance _target <= 3) && (_target getVariable 'xr_pluncon') && !(_this getVariable 'xr_pisinaction') && time > (_target getVariable 'xr_busyt') && !(_target getVariable 'xr_dragged')"]];
	};
};

FUNCXR(removeActions) = {
	private ["_unit", "_hasaction"];
	_unit = _this;
	_hasaction = __GV(_unit,GVARXR(ReviveAction));
	if (isNil "_hasaction") then {_hasaction = -9999};
	if (_hasaction != -9999) then {
		_unit removeAction _hasaction;
	};
	_unit setVariable [QGVARXR(ReviveAction), -9999];
	_hasaction = __GV(_unit,GVARXR(DragAction));
	if (isNil "_hasaction") then {_hasaction = -9999};
	if (_hasaction != -9999) then {
		_unit removeAction _hasaction;
	};
	_unit setVariable [QGVARXR(DragAction), -9999];
};

FUNCXR(respawn_markers) = {
	private ["_newm", "_xrm"];
	GVARXR(respavailablemarker) = true;
	GVARXR(respmarkerar) = [];
	GVARXR(respmarkerar2) = [];
	{
		if (str(markerPos _x) != "[0,0,0]") then {
			_newm = createMarkerLocal [_x + "_xrm", markerPos _x];
			_newm setMarkerShapeLocal "ICON";
			_newm setMarkerTypeLocal "selector_selectedMission";
			_newm setMarkerColorLocal "ColorGreen";
			_newm setMarkerDirLocal 20;
			GVARXR(respmarkerar) set [count GVARXR(respmarkerar), [_x, _newm, 0.015, ""]];
			
			_newm = createMarkerLocal [_x + "_xrm2", markerPos _x];
			_newm setMarkerShapeLocal "ICON";
			_newm setMarkerTypeLocal "Select";
			_newm setMarkerColorLocal "ColorYellow";
			_newm setMarkerDirLocal 20;
			GVARXR(respmarkerar2) set [count GVARXR(respmarkerar2), [_x, _newm]];
		};
	} forEach GVARXR(respawn_markers);
};

FUNCXR(deleteRespMarkers) = {
	{
		_mar = _x select 1;
		deleteMarkerLocal _mar;
	} forEach GVARXR(respmarkerar);
	{
		_mar = _x select 1;
		deleteMarkerLocal _mar;
	} forEach GVARXR(respmarkerar2);
	GVARXR(respmarkerar) = [];
	GVARXR(respmarkerar2) = [];
};

FUNCXR(mobRespAvailable) = {
	private ["_num", "_mrrname", "_mrinair", "_mrnumstr", "_mrtext", "_mrvec", "_depl", "_enear"];
	PARAMS_1(_num);

	if !("TT" in d_version) then {
		_mrrname = format ["MRR%1", _num];
		_mrinair = format ["mr%1_in_air", _num];
	} else {
		_mrrname = if (d_player_side == west) then {
			_mrinair = format ["mr%1_in_air", _num];
			format ["MRR%1", _num]
		} else {
			_mrinair = format ["mrr%1_in_air", _num];
			format ["MRRR%1", _num]
		};
	};
	
	_mrnumstr = switch (_num) do {
		case 1: {"one"};
		case 2: {"two"};
		case 3: {"three"};
		case 4: {"four"};
		case 5: {"five"};
		case 6: {"six"};
	};
	
	_mr_available = true;
	_mrtext = "";
	_mrvec = missionNamespace getVariable _mrrname;
	if (isNil "_mrvec") exitWith {
		[false, ""]
	};
	if (isNull _mrvec) exitWith {
		[false, ""]
	};
	
	switch (true) do {
		case (X_JIPH getVariable _mrinair): {
			_mrtext = format [(localize "STR_DOM_MISSIONSTRING_925"), _mrnumstr];
			_mr_available = false;
		};
		case (speed _mrvec > 4): {
			_mrtext = format [(localize "STR_DOM_MISSIONSTRING_926"), _mrnumstr];
			_mr_available = false;
		};
		case (surfaceIsWater [(position _mrvec) select 0,(position _mrvec) select 1]): {
			_mrtext = format [(localize "STR_DOM_MISSIONSTRING_927"), _mrnumstr];
			_mr_available = false;
		};
		case (!(if (!isNil {__GV(_mrvec,ace_canmove)}) then {_mrvec call ace_v_alive} else {alive _mrvec})): {
			_mrtext = format [(localize "STR_DOM_MISSIONSTRING_928"), _mrnumstr];
			_mr_available = false;
		};
		default {
			_depl = __GV(_mrvec,d_MHQ_Deployed);
			if (isNil "_depl") then {_depl = false};
			if (!_depl) then {
				_mrtext = format [(localize "STR_DOM_MISSIONSTRING_929"), _mrnumstr];
				_mr_available = false;
			} else {
				_enear = __GV(_mrvec,d_enemy_near);
				if (!isNil "_enear") then {
					if (_enear) then {
						_mrtext = format [(localize "STR_DOM_MISSIONSTRING_930"), _mrnumstr];
						_mr_available = false;
					};
				};
			};
		};
	};
	[_mr_available, _mrtext]
};

FUNCXR(animateRespMarkers) = {
	private ["_origmarker", "_respm", "_size", "_msize"];
	{
		_origmarker = _x select 0;
		_respm = _x select 1;
		_size = _x select 2;
		_respm setMarkerPosLocal (markerPos _origmarker);
		_respm setMarkerDirLocal ((markerDir _respm) + 2);
		_msize = (markerSize _respm) select 0;
		_msize = _msize + _size;
		if (_msize >= 1.7) then {
			_x set [2, -0.015];
		} else {
			if (_msize <= 1) then {
				_x set [2, 0.015];
			};
		};
		_respm setMarkerSizeLocal [_msize, _msize];
		if (_forEachIndex > 0) then {
			_isavailable = [_forEachIndex] call FUNCXR(mobRespAvailable);
			_respm setMarkerColorLocal (if !(_isavailable select 0) then {
				"ColorRed"
			} else {
				"ColorGreen"
			});
			_x set [3, _isavailable select 1];
		};
		_sel = GVARXR(respmarkerar2) select _forEachIndex;
		_respm = _sel select 1;
		_respm setMarkerPosLocal (markerPos _origmarker);
	} forEach GVARXR(respmarkerar);
};

FUNCXR(park_player) = {
	private "_dosleep";
	PARAMS_1(_dosleep);
	__TRACE_1("park_player","_dosleep");
	__pSetVar [QGVARXR(isdead), true];
	GVARXR(phd_invulnerable) = true;
	titleText [(localize "STR_DOM_MISSIONSTRING_931"),"BLACK OUT", 1];
	if (_dosleep) then {
		sleep 5;
		waitUntil {sleep 0.312;alive player};
	};
	player setPos (markerPos QGVARXR(playerparkmarker));
	[QGVARXR(hpl), player] call d_fnc_NetCallEvent;
	[false] spawn FUNCXR(spectating);
	titleText [(localize "STR_DOM_MISSIONSTRING_931"),"BLACK IN", 1];
};

FUNCXR(uncon) = {
	private ["_pisdead", "_lives", "_disp", "_curtime", "_ott", "_respawn", "_tt", "_etime", "_dcounter", "_typer", "_remactions", "_curanim", "_nextcrytime"];
	PARAMS_1(_typer);
	__TRACE_1("uncon","_typer");
	disableSerialization;
	enableRadio false;
	#ifdef __TT__
	[QGVARXR(addActions), [player, side (group player)]] call d_fnc_NetCallEventToClients;
	#else
	[QGVARXR(addActions), player] call d_fnc_NetCallEventToClients;
	#endif
	[QGVARXR(setCap), [player,true]] call d_fnc_NetCallEvent;
	
	GVARXR(respavailablemarker) = false;
	
	_pisdead = false;
	if (_typer == 0) then {
		if (GVARXR(max_lives) != -1) then {
			_lives = __pGetVar(GVARXR(lives));
			if (_lives > -1) then {
				__DEC(_lives);
				__pSetVar [QGVARXR(lives), _lives];
				["d_crl", [getPlayerUID player, _lives]] call d_fnc_NetCallEventCTS;
			};
			if (_lives == -1) then {
				_pisdead = true;
			};
		};
	};
	if (_pisdead) exitWith {
		GVARXR(phd_invulnerable) = true;
		[true] spawn FUNCXR(park_player);
		false
	};
	#define __dspctrl(ctrlid) (_disp displayCtrl ctrlid)
	closeDialog 0;
	GVARXR(respawn_available) = false;
	_curtime = time;
	__pSetVar [QGVARXR(unconendtime), _curtime + GVARXR(lifetime)];
	_ott = -1;
	_respawn = if (GVARXR(respawn_available_after) != -1) then {
		_curtime + GVARXR(respawn_available_after)
	} else {
		GVARXR(respawn_available) = true; -1
	};
	
	__TRACE_2("uncon","_curtime","_respawn");
	
	if !(GVARXR(followcam)) then {
		createDialog QGVARXR(UnconDlg);
		_disp = __uiGetVar(GVARXR(UnconDlg));
		__dspctrl(1000) ctrlShow false;
		__dspctrl(1001) ctrlShow false;
	} else {
		[true] spawn FUNCXR(spectating);
	};
	
	#define __ucdlg1005 (__uiGetVar(GVARXR(UnconDlg)) displayCtrl 1005)
	#define __ucdlg1006 (__uiGetVar(GVARXR(UnconDlg)) displayCtrl 1006)
	#define __spectdlg1005 (__uiGetVar(GVARXR(SpectDlg)) displayCtrl 1005)
	#define __spectdlg1006 (__uiGetVar(GVARXR(SpectDlg)) displayCtrl 1006)
	if (_respawn == -1) then {
		if (!GVARXR(followcam)) then {
			__ucdlg1006 ctrlSetText (localize "STR_DOM_MISSIONSTRING_922");
			__ucdlg1006 ctrlSetTextColor [1,1,0,1];
			__ucdlg1006 ctrlCommit 0;
		};
		if (!GVARXR(respavailablemarker)) then {
			call FUNCXR(respawn_markers);
		};
	};
	_pl_died = false;
	_dcounter = 0;
	__TRACE("uncon starting main loop");
	_remactions = false;
	_nextcrytime = time + 10 + (random 15);
	while {alive player && __pGetVar(GVARXR(pluncon))} do {
		if (d_ace_enabled) then {
			if ([player] call ACE_fnc_isBurning) then {
				["ace_sys_wounds_burnoff", player] call CBA_fnc_globalEvent;
			};
		};
		if (GVARXR(withSounds)) then {
			if (time >= _nextcrytime) then {
				_nus3 = (floor (random 20)) + 11;
				[QGVARXR(say3d), [player, "Hit" + str(_nus3)]] call d_fnc_NetCallEventToClients;
				_nextcrytime = time + 10 + (random 15);
			};
		};
		_tt = round (__pGetVar(GVARXR(unconendtime)) - time);
		if (_tt != _ott) then {
			if (!GVARXR(followcam)) then {
				__ucdlg1005 ctrlSetText str _tt;
			} else {
				__spectdlg1005 ctrlSetText str _tt;
			};
			_ott = _tt;
		};
		if (GVARXR(near_player_dist_respawn) && {!GVARXR(respawn_available) && _dcounter > 10}) then {
			_nearunit = objNull;
			{
				scopeName "xr_loop1";
				_xm = __getMNsVar2(_x);
				if (_x != GVARXR(strpl) && {!isNull _xm && !__GV(_xm,GVARXR(pluncon))}) then {
					if (_xm distance player < GVARXR(near_player_dist)) then {
						_nearunit = _xm;
						breakOut "xr_loop1";
					};
				};
			} forEach GVARXR(player_entities);
			if (isNull _nearunit) then {
				GVARXR(respawn_available) = true;
				if (!GVARXR(respavailablemarker)) then {
					call FUNCXR(respawn_markers);
				};
				if (!GVARXR(followcam)) then {
					__ucdlg1006 ctrlSetText (localize "STR_DOM_MISSIONSTRING_922");
					__ucdlg1006 ctrlSetTextColor [1,1,0,1];
					__ucdlg1006 ctrlCommit 0;
				} else {
					__spectdlg1006 ctrlSetText (localize "STR_DOM_MISSIONSTRING_922");
					__spectdlg1006 ctrlSetTextColor [1,1,0,1];
					__spectdlg1006 ctrlCommit 0;
				};
			};
			_dcounter = 0;
		} else {
			__INC(_dcounter);
			if (_dcounter > 1000) then {_dcounter = 0};
		};
		if (_respawn != -1 && {!GVARXR(respawn_available)}) then {
			if (time >= _respawn) then {
				if (!GVARXR(followcam)) then {
					__ucdlg1006 ctrlSetText (localize "STR_DOM_MISSIONSTRING_922");
					__ucdlg1006 ctrlSetTextColor [1,1,0,1];
					__ucdlg1006 ctrlCommit 0;
				} else {
					__spectdlg1006 ctrlSetText (localize "STR_DOM_MISSIONSTRING_922");
					__spectdlg1006 ctrlSetTextColor [1,1,0,1];
					__spectdlg1006 ctrlCommit 0;
				};
				GVARXR(respawn_available) = true;
				if (!GVARXR(respavailablemarker)) then {
					call FUNCXR(respawn_markers);
				};
			};
		};
		if (_tt <= 0) exitWith {
			__TRACE("uncon _tt < =0, exit");
			closeDialog 0;
			GVARXR(stopspect) = true;
			__pSetVar [QGVARXR(isleader),leader (group player) == player];
			if (GVARXR(with_marker)) then {
				[QGVARXR(delml), GVARXR(strpldead)] call d_fnc_NetCallEvent;
			};
			[QGVARXR(removeActions), player] call d_fnc_NetCallEventToClients;
			_remactions = true;
			__pSetVar [QGVARXR(pluncon), false, true];
			GVARXR(use_dom_opendlg) = true;
			__pSetVar [QGVARXR(u_state), 100];
			[QGVARXR(wn), [player,102]] call d_fnc_NetCallEvent;
			__plsd1;
			__TRACE("uncon player setDamage 1");
			titleText [(localize "STR_DOM_MISSIONSTRING_932"),"BLACK OUT", 1];
			sleep 0.5;
			_etime = time + __pGetVar(GVARXR(presptime)) - 1.3;
			__TRACE_1("uncon","_etime");
			waitUntil {sleep 0.112;time >= _etime};
			titleText ["","BLACK IN", 2];
			waitUntil {sleep 0.112;alive player};
			[QGVARXR(wn), [player,105]] call d_fnc_NetCallEvent;
			GVARXR(pl_has_pos_changed) = false;
			if (GVARXR(max_lives) != -1) then {
				hintSilent format [(localize "STR_DOM_MISSIONSTRING_933"), __pGetVar(GVARXR(lives))];
			};
			// deactivated for now
			//if (!GVARXR(no_respawn_dialog)) then {
			//	createDialog QGVARXR(RespDlg);
			//};
			//0 spawn FUNCXR(resp_dlg_helper);
			_pl_died = true;
		};
		if (GVARXR(respavailablemarker)) then {
			call FUNCXR(animateRespMarkers);
		};
		sleep 0.02;
	};
	__TRACE("uncon main loop end");
	if (GVARXR(respavailablemarker)) then {
		call FUNCXR(deleteRespMarkers);
	};
	if (!_remactions) then {
		[QGVARXR(removeActions), player] call d_fnc_NetCallEventToClients;
	};
	if (GVARXR(with_marker) && !_pl_died) then {
		[QGVARXR(delml), GVARXR(strpldead)] call d_fnc_NetCallEvent;
	};
	[QGVARXR(setCap), [player,false]] call d_fnc_NetCallEvent;
	enableRadio true;
	if (alive player && {!_pl_died}) then {
		__TRACE("uncon player alive and lives left");
		titleText ["","BLACK OUT", 1];
		closeDialog 0;
		[QGVARXR(wn), [player,102]] call d_fnc_NetCallEvent;
		player setDamage 0;
		call FUNCXR(resetVals);
		if (rating player < 0) then {
			player addRating abs(rating player);
		};
		if (!GVARXR(stopspect)) then {GVARXR(stopspect) = true};
		__pSetVar [QGVARXR(u_state), 0];
		titleText ["","BLACK IN", 6];
		if (GVARXR(max_lives) != -1) then {
			hintSilent format [(localize "STR_DOM_MISSIONSTRING_933"), __pGetVar(GVARXR(lives))];
		};
	};
	call FUNCXR(joingr);
	__TRACE("uncon end");
	if (d_WithAcre) then {
		[false] call acre_api_fnc_setSpectator;
	};
};

FUNCXR(veckick) = {
	waitUntil {sleep 0.121;vehicle player == player};
	if (__pGetVar(GVARXR(pluncon))) then {
		__TRACE("FUNCXR(veckick) Die");
		player playActionNow "Die";
	};
};

FUNCXR(isInVec) = {
	private ["_isInVec", "_shandle"];
	PARAMS_1(_isInVec);
	__TRACE_1("isInVec","_isInVec");
	if (_isInVec) then {
		_shandle = 0 spawn FUNCXR(veckick);
		waitUntil {sleep 0.112;scriptDone _shandle};
		__TRACE("isInVec first handle done");
	};
	if (surfaceIsWater (getPosASL player)) then {
		_shandle = 0 spawn FUNCXR(waterfix);
		waitUntil {sleep 0.112;scriptDone _shandle};
		__TRACE("isInVec second handle done");
	};
	0 spawn {
		private ["_pos", "_slope"];
		waitUntil {sleep 0.121;str(velocity player) == "[0,0,0]"};
		_pos = position player;
		_slope = [_pos, 1] call FUNCXR(GetSlope);
		__TRACE_2("isInVec","_pos","_slope");
		if (_slope >= 0.78) then {[_pos, _slope, player] call FUNCXR(DoSlope)};
		if (!__pGetVar(GVARXR(isdead))) then {
			if (GVARXR(with_marker)) then {
				[QGVARXR(umarker), player] call d_fnc_NetCallEvent;
			};
		};
	};
	[0] spawn FUNCXR(uncon);
};

GVARXR(bscreens) = [QGVARXR(ScreenBlood1),QGVARXR(ScreenBlood2),QGVARXR(ScreenBlood3)];
FUNCXR(ClientHD) = {
	private ["_unit", "_part", "_dam", "_injurer", "_ammo", "_ret", "_newpd", "_nd", "_ndoad", "_isbh", "_vecdead", "_vec", "_oad", "_pd", "_isInVec", "_ddexit"];
	PARAMS_5(_unit,_part,_dam,_injurer,_ammo);
	if (!alive _unit) exitWith {_dam};
	if (GVARXR(phd_invulnerable)) exitWith {0};
	if __GV(_unit,GVARXR(pluncon)) exitWith {0};
	_ddexit = false;
	if (d_no_teamkill == 0) then {
		if (_dam >= 0.5) then {
			if (isPlayer _injurer) then {
				if (_injurer != _unit && {side (group _injurer) == side (group _unit) && getText (configFile >> "CfgAmmo" >> _ammo >> "simulation") in __shots}) then {
					if (_part == "") then {
						hint format [(localize "STR_DOM_MISSIONSTRING_497"), name _injurer];
						["d_unit_tkr", [_unit,_injurer]] call d_fnc_NetCallEventCTS;
					};
					_ddexit = true;
				};
			};
		};
	};
	if (_ddexit) exitWith {0};
	_ret = 0;
	_newpd = 0;
	_nd = 0;
	_ndoad = 0;
	_isbh = 1;
	_vecdead = false;
	_leave_now = false;
	__TRACE_2("ClientHD _dam in","_dam","_part");
	_dam = _dam * 0.85;
	if (_part == "") then {
		_isbh = 0;
		_vec = vehicle _unit;
		_difd = _dam - __GV(_unit,GVARXR(overall));
		if (_vec == _unit) then {
			_ndoad = (_difd * 0.8) min 0.89;
			_oad = (__GV(_unit,GVARXR(overall)) + _ndoad) min 0.89;
			_unit setVariable [QGVARXR(overall), _oad];
			_unit setDamage _oad;
			__TRACE_3("ClientHD setDamage","_oad","_ndoad","_difd");
		} else {
			if (!alive _vec) then {
				__TRACE_1("ClientHD vehicle not alive","_vec");
				_vecdead = true;
				_unit setDamage 0.89;
			} else {
				__TRACE_1("ClientHD vehicle IS alive","_vec");
				if (_difd > 0.15) then {
					if (time >= __GV(_unit,GVARXR(cutofftime))) then {
						_ndoad = _difd;
						_unit setVariable [QGVARXR(cutofftime), time + 1];
						_pd = (__GV(_unit,GVARXR(overall)) + _difd) min 0.89;
						_unit setVariable [QGVARXR(overall), _pd];
						_unit setDamage _pd;
						if (_pd >= 0.89) exitWith {
							_vecdead = true;
						};
						_pd = (__GV(_unit,GVARXR(head_hit)) + _difd) min 0.89;
						_unit setVariable [QGVARXR(head_hit), _pd];
						_pd = (__GV(_unit,GVARXR(body)) + _difd) min 0.89;
						_unit setVariable [QGVARXR(body), _pd];
						_pd = (__GV(_unit,GVARXR(hands)) + _difd) min 15;
						_unit setVariable [QGVARXR(hands), _pd];
						_pd = (__GV(_unit,GVARXR(legs)) + _difd) min 15;
						_unit setVariable [QGVARXR(legs), _pd];
					} else {
						_leave_now = true;
					};
				};
			};
		};
	} else {
		#define __unitcfg configFile >> "cfgVehicles" >> typeOf _unit
		switch (_part) do {
			case "head_hit": {
				_armor = getNumber (__unitcfg >> "hitpoints" >> "HitHead" >> "armor");
				_nd = (_dam * (0.6 + (1 - _armor))) min 0.89;
				_newpd = (__GV(_unit,GVARXR(head_hit)) + _nd) min 0.89;
				__TRACE_2("ClientHD head_hit","_newpd","_nd");
				_unit setVariable [QGVARXR(head_hit), _newpd];
			};
			case "body": {
				_armor = getNumber (__unitcfg >> "hitpoints" >> "HitBody" >> "armor");
				_passt = getNumber (__unitcfg >> "hitpoints" >> "HitBody" >> "passThrough");
				__TRACE_2("ClientHD body","_armor","_passt");
				_nd = if (_passt < 1 && _armor == 1) then {
					(_dam * 0.5) min 0.89
				} else {
					(_dam * (0.6 + (1 - _armor))) min 0.89
				};
				_newpd = (__GV(_unit,GVARXR(body)) + _nd) min 0.89;
				__TRACE_2("ClientHD body","_newpd","_nd");
				_unit setVariable [QGVARXR(body), _newpd];
			};
			case "hands": {
				_nd = _dam min 15;_isbh = 2;
				_newpd = (__GV(_unit,GVARXR(hands)) + _nd) min 15;
				__TRACE_2("ClientHD hands","_newpd","_nd");
				_unit setVariable [QGVARXR(hands), _newpd];
			};
			case "legs": {
				_nd = _dam min 15;_isbh = 2;
				_newpd = (__GV(_unit,GVARXR(legs)) + _nd) min 15;
				__TRACE_2("ClientHD legs","_newpd","_nd");
				_unit setVariable [QGVARXR(legs), _newpd];
			};
		};
	};
	if (_leave_now) exitWith {0};
	_ret = _newpd;
	__TRACE_1("ClientHD _dam out","_ret");
	if (_ndoad >= 0.1) then {
		if (vehicle _unit == _unit) then {
			if (getText (configFile >> "CfgAmmo" >> _ammo >> "simulation") in __shots) then {
				if (!surfaceIsWater (getPosASL _unit)) then {39672 cutRsc[QGVARXR(ScreenDirt),"PLAIN"]};
			};
		};
		0 spawn FUNCXR(blurr);
		39671 cutRsc[(GVARXR(bscreens) select (floor (random 3))),"PLAIN"];
	};
	if (_isbh != 0 || {_vecdead}) then {
		if ((_isbh == 1 && _ret >= 0.89) || {(_isbh == 2 && _ret >= 15) || _vecdead}) then {
			__pSetVar [QGVARXR(u_state), 1];
			__pSetVar [QGVARXR(pluncon), true, true];
			__pSetVar [QGVARXR(isleader),leader (group player) == player];
			GVARXR(pl_group) = group player;
			_sideplg = side GVARXR(pl_group);
			
			//[player] joinSilent grpNull;
			if (isPlayer _injurer && _injurer != player) then {
				if (side (group _injurer) != _sideplg) then {
					[QGVARXR(addpoint), [_injurer, _unit]] call d_fnc_NetCallEventCTS;
				} else {
					[QGVARXR(subpoint), [_injurer, _unit]] call d_fnc_NetCallEvent;
				};
			} else {
				[QGVARXR(unconmsg), _unit] call d_fnc_NetCallEventToClients;
			};
			if (d_sub_kill_points != 0) then {
				[QGVARXR(add_sub_kill), player] call d_fnc_NetCallEventCTS;
			};
			if (animationState player == "HaloFreeFall_non") then {
				__TRACE("FUNCXR(ClientHD) HaloFreeFall_non anim");
				[QGVARXR(a55), player] call d_fnc_NetCallEvent;
			};
			_isInVec = false;
			if (vehicle player == player) then {
				__TRACE("FUNCXR(ClientHD) Die");
				player playActionNow "Die";
			} else {
				_isInVec = true;
				moveOut player;
			};
			if (d_WithAcre) then {
				[true] call acre_api_fnc_setSpectator;
			};
			if (d_ace_enabled) then {
				if ([player] call ACE_fnc_isBurning) then {
					["ace_sys_wounds_burnoff", player] call CBA_fnc_globalEvent;
				};
			};
			[_isInVec] spawn FUNCXR(isInVec);
			if (commandingMenu != "") then {
				showCommandingMenu "";
			};
		};
	};
	_ret
};

FUNCXR(makeUncon) = {
	player setVariable [QGVARXR(overall), 0.89];
	player setDamage 0.89;
	if (animationState player == "HaloFreeFall_non") then {
		[QGVARXR(swmnon), player] call d_fnc_NetCallEvent;
		__TRACE("FUNCXR(makeUncon) Die");
		player playActionNow "Die";
	};
	[player, "body", 5, player, ""] call FUNCXR(ClientHD);
};

FUNCXR(dragkeydown) = {
	#include "\ca\editor\Data\Scripts\dikCodes.h"
	private["_handled", "_ctrl", "_dikCode", "_shift", "_alt"];
	PARAMS_5(_du,_dikCode,_shift,_ctrl,_alt);
	if (!_shift && {!_ctrl && !_alt}) then {
		(_dikCode in ([DIK_C] + (actionKeys "NetworkStats") + (actionKeys "Crouch") + (actionKeys "Stand")))
	}
};

FUNCXR(drag) = {
	private ["_dragee", "_unit", "_found_anim", "_sdone", "_isdragging"];
	_dragee = __pGetVar(GVARXR(cursorTarget));

	_isdragging = __pGetVar(GVARXR(is_dragging));
	if (isNil "_isdragging") then {_isdragging = false};
	if (_isdragging) exitWith {};

	if (isNull _dragee) exitWith {};
	if (!alive player) exitWith {};
	
	__pSetVar [QGVARXR(pisinaction), true];
	__pSetVar [QGVARXR(is_dragging), true];

	_anim = player call FUNCXR(getUnitStance);
	if (_anim == "prone") exitWith {
		[_dragee] spawn FUNCXR(dragprone);
	};

	_unit = player;
	private "_name_dragee";
	_name_dragee = (localize "STR_DOM_MISSIONSTRING_906");
	if (alive _dragee) then {if (name _dragee != (localize "STR_DOM_MISSIONSTRING_906")) then {_name_dragee = name _dragee}};
	 
	GVARXR(drag_keyDownEHId) = (findDisplay 46) displayAddEventHandler ["KeyDown", format ["_this call %1_fnc_dragkeydown", __COMPXRstr]];
	_dragee setVariable [QGVARXR(dragged), true, true];

	_unit playMove "acinpknlmstpsraswrfldnon";
	sleep 2;

	[QGVARXR(a3), _dragee] call d_fnc_NetCallEvent;

	_dragee attachto [_unit,[0.1, 1.01, 0]];
	
	sleep 0.02;
	[QGVARXR(dir), _dragee] call d_fnc_NetCallEvent;
	GVARXR(drag) = true;

	if (GVARXR(dropAction) != -3333) then {__PRA(GVARXR(dropAction));GVARXR(dropAction) = -3333};
	GVARXR(dropAction) = player addAction [format["<t color='#FF0000'>Drop %1</t>",_name_dragee], "x_revive\drop_body.sqf", [_dragee, 0], 0, false, true];
	GVARXR(carryAction) = player addAction [format["<t color='#FF0000'>Carry %1</t>",_name_dragee], "x_revive\carry.sqf", _dragee, 0, false, true];
	sleep 1;

	_found_anim = false;
	
	_animsd = ["acinpknlmstpsraswrfldnon","acinpknlmwlksraswrfldb"];

	while {GVARXR(drag)} do {
		if (!_found_anim) then {
			if (animationState player in _animsd) then {
				_found_anim = true;
			};
		};
		if (!alive _dragee || !__GV(_dragee,GVARXR(pluncon))) exitWith {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			if (GVARXR(carryAction) != -3333) then {
				__PRA(GVARXR(carryAction));
				GVARXR(carryAction) = -3333;
			};
			detach _dragee;
			sleep 0.5;
			if ((alive _dragee && __GV(_dragee,GVARXR(pluncon))) || {!alive _dragee}) then {
				[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
			} else {
				[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
			};
			[QGVARXR(swmnon), _unit] call d_fnc_NetCallEvent;
			sleep 1;
			GVARXR(drag) = false;
		};
		
		if (_found_anim && {!((animationState _unit) in _animsd)}) exitWith {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			if (GVARXR(carryAction) != -3333) then {
				__PRA(GVARXR(carryAction));
				GVARXR(carryAction) = -3333;
			};
			detach _dragee;
			sleep 0.5;
			if ((alive _dragee && __GV(_dragee,GVARXR(pluncon))) || {!alive _dragee}) then {
				[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
			} else {
				[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
			};
			[QGVARXR(swmnon), _unit] call d_fnc_NetCallEvent;
			sleep 1;
			GVARXR(drag) = false;
		};

		if (!alive _unit) exitWith {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			if (GVARXR(carryAction) != -3333) then {
				__PRA(GVARXR(carryAction));
				GVARXR(carryAction) = -3333;
			};
			detach _unit;
			if ((alive _dragee && __GV(_dragee,GVARXR(pluncon))) || {!alive _dragee}) then {
				[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
			} else {
				[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
			};
			[QGVARXR(swmnon), _unit] call d_fnc_NetCallEvent;
			sleep 1;
			GVARXR(drag) = false;
		};
		
		if (isNull _dragee) then {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			if (GVARXR(carryAction) != -3333) then {
				__PRA(GVARXR(carryAction));
				GVARXR(carryAction) = -3333;
			};
			detach _unit;
			[QGVARXR(swmnon), _unit] call d_fnc_NetCallEvent;
			sleep 1;
			GVARXR(drag) = false;
		};
		sleep 0.1;
	};

	__pSetVar [QGVARXR(pisinaction), false];
	__pSetVar [QGVARXR(is_dragging), false];
	_dragee setVariable [QGVARXR(dragged), false, true];

	(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVARXR(drag_keyDownEHId)];

	if (GVARXR(carryAction) != -3333) then {
		__PRA(GVARXR(carryAction));
		GVARXR(carryAction) = -3333;
	};
};

FUNCXR(dragkeydownprone) = {
	if ((_this select 1) in (actionKeys "moveForward" + actionKeys "moveFastForward")) exitWith {true};
	false
};

FUNCXR(dragprone) = {
	private ["_dragee", "_unit", "_pullanims"];
	_dragee = __pGetVar(GVARXR(cursorTarget));

	if (isNull _dragee) exitWith {};
	if (!alive player) exitWith {};
	
	__pSetVar [QGVARXR(pisinaction), true];
	__pSetVar [QGVARXR(is_dragging), true];

	_unit = player;
	private "_name_dragee";
	_name_dragee = (localize "STR_DOM_MISSIONSTRING_906");
	if (alive _dragee) then {if (name _dragee != (localize "STR_DOM_MISSIONSTRING_906")) then {_name_dragee = name _dragee}};
	
	_dragee setVariable [QGVARXR(dragged), true, true];
	 
	sleep 2;

	[QGVARXR(a4), _dragee] call d_fnc_NetCallEvent;

	_dragee attachto [_unit, [0, 2, 0]];
	sleep 0.02;
	[QGVARXR(dir), _dragee] call d_fnc_NetCallEvent;
	GVARXR(drag) = true;

	if (GVARXR(dropAction) != -3333) then {__PRA(GVARXR(dropAction));GVARXR(dropAction) = -3333};
	GVARXR(dropAction) = player addAction [format["<t color='#FF0000'>Drop %1</t>",_name_dragee], "x_revive\drop_body.sqf", [_dragee, 1], 0, false, true];
	GVARXR(dragprone_keyDownEHId) = (findDisplay 46) displayAddEventHandler ["KeyDown", format ["_this call %1_fnc_dragkeydownprone", __COMPXRstr]];
	sleep 0.5;

	_found_anim = false;

	_pullanims = ["amovppnemstpsraswrfldnon","amovppnemrunslowwrfldf","amovppnemsprslowwrfldfl","amovppnemsprslowwrfldfr","amovppnemrunslowwrfldb","amovppnemsprslowwrfldbl","amovppnemsprslowwrfldr","amovppnemstpsraswrfldnon_turnl","amovppnemstpsraswrfldnon_turnr","amovppnemrunslowwrfldl","amovppnemrunslowwrfldr","amovppnemsprslowwrfldb","amovppnemrunslowwrfldbl","amovppnemsprslowwrfldl","amovppnemsprslowwrfldbr"];

	while {GVARXR(drag)} do {
		if (!_found_anim) then {
			if (animationState player in _pullanims) then {
				_found_anim = true;
			};
		};
		if (!alive _dragee || {!__GV(_dragee,GVARXR(pluncon))}) exitWith {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			detach _dragee;
			sleep 0.5;
			if ((alive _dragee && __GV(_dragee,GVARXR(pluncon))) || {!alive _dragee}) then {
				[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
			} else {
				[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
			};
			sleep 1;
			GVARXR(drag) = false;
		};
		
		if (_found_anim && {!((animationState _unit) in _pullanims)}) exitWith {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			detach _dragee;
			sleep 0.5;
			if ((alive _dragee && __GV(_dragee,GVARXR(pluncon))) || {!alive _dragee}) then {
				[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
			} else {
				[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
			};
			sleep 1;
			GVARXR(drag) = false;
		};

		if (!alive _unit) exitWith {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			detach _unit;
			if ((alive _dragee && __GV(_dragee, GVARXR(pluncon))) || {!alive _dragee}) then {
				[QGVARXR(wn), [_dragee,101]] call d_fnc_NetCallEvent;
			} else {
				[QGVARXR(wn), [_dragee,102]] call d_fnc_NetCallEvent;
			};
			sleep 1;
			GVARXR(drag) = false;
		};
		
		if (isNull _dragee) then {
			__PRA(GVARXR(dropAction));
			GVARXR(dropAction) = -3333;
			detach _unit;
			sleep 1;
			GVARXR(drag) = false;
		};
		
		sleep 0.1;
	};

	__pSetVar [QGVARXR(pisinaction), false];
	__pSetVar [QGVARXR(is_dragging), false];
	_dragee setVariable [QGVARXR(dragged), false, true];

	(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVARXR(dragprone_keyDownEHId)];

	if (GVARXR(dropAction) != -3333) then {
		__PRA(GVARXR(dropAction));
		GVARXR(dropAction) = -3333;
	};
};

FUNCXR(pllbupdater) = {
	disableSerialization;
	#define __lbctrl (__uiGetVar(GVARXR(UnconDlg)) displayCtrl 1000)
	while {GVARXR(lb_u_updater)} do {
		if (!isNil {__uiGetVar(GVARXR(UnconDlg))}) then {
			if (ctrlShown __lbctrl) then {
				lbClear __lbctrl;
				{
					_u = __getMNsVar2(_x);
					if (!isNull _u && alive _u && {side (group _u) == side (group player) && _u != player}) then {
						if (_u distance player <= GVARXR(near_player_dist)) then {
							_hxhx = __GV(_u,GVARXR(pluncon));
							if (isNil "_hxhx") then {_hxhx = false};
							if (!_hxhx) then {
								__lbctrl lbAdd (name _u);
							};
						};
					};
				} forEach GVARXR(player_entities);
			};
		};
		if (!GVARXR(lb_u_updater)) exitWith {};
		sleep 0.5;
	};
};

FUNCXR(healanim) = {
	if (_this in ["ainvpknlmstpslaywrfldnon_healed", "ainvpknlmstpslaywrfldnon_healed2", "amovppnemstpsraswrfldnon_healed"]) then {
		if (time >= __pGetVar(GVARXR(healcutoff))) then {
			__pSetVar [QGVARXR(healcutoff), time + 1];
			call FUNCXR(resetVals);
		};
	};
};

if (GVARXR(selfheals) > 0) then {
	0 spawn {
		private "_id";
		while {true} do {
			__pSetVar [QGVARXR(numheals), GVARXR(selfheals)];
			waitUntil {sleep 0.332;alive player};
			_id = player addAction ["<t color='#FF0000'>Self Heal</t>", "x_revive\xr_selfheal.sqf", [], -1, false, false, "", "alive _target &&  !(_target getVariable 'xr_pluncon') && !(_target getVariable 'xr_pisinaction') && (damage _target >= (xr_selfheals_minmaxdam select 0)) && (damage _target <= (xr_selfheals_minmaxdam select 1)) && (_target getVariable 'xr_numheals') > 0"];
			waitUntil {sleep 0.231;!alive player};
			player removeAction _id;
		};
	};
};
