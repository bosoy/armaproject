// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_setupplayer.sqf"
#include "x_setup.sqf"
private ["_p", "_pos", "_type", "_weapp", "_magp", "_res", "_taskstr", "_color", "_counterxx", "_text", "_mcol", "_s", "_trigger", "_types", "_action", "_ar", "_tactionar", "_primw", "_muzzles"];

diag_log [diag_frameno, diag_ticktime, time, "Executing Dom x_setupplayer.sqf"];

GVAR(still_in_intro) = true;

if !(__TTVer) then {
	_shield = GVAR(ProtectionZone) createVehicleLocal (position GVAR(FLAG_BASE));
	_shield setDir -211;
	_shield setPos (position GVAR(FLAG_BASE));
	_shield setObjectTexture [0,"#(argb,8,8,3)color(0,0,0,0,ca)"];
	if (GVAR(ShowBaseSafeZone) == 0) then {
		_shield = GVAR(ProtectionZone) createVehicleLocal (position GVAR(FLAG_BASE));
		_shield setDir -211;
		_shield setPos [getPosASL GVAR(FLAG_BASE) select 0, getPosASL GVAR(FLAG_BASE) select 1, -28.48];
		_shield setObjectTexture [0,"#(argb,8,8,3)color(0,0,0,0.7,ca)"];
	};
};

GVAR(current_defend_target) = "";
GVAR(current_defend_idx) = -1;
GVAR(current_attack_target) = "";
GVAR(current_attack_idx) = -1;

__ccppfln(x_client\x_f\x_perframe.sqf);

GVAR(name_pl) = name player;
GVAR(player_faction) = faction player;

GVAR(misc_store) = GVAR(HeliHEmpty) createVehicleLocal [0,0,0];

FUNC(GreyText) = {"<t color='#f0bfbfbf'>" + _this + "</t>"};
FUNC(RedText) = {"<t color='#f0ff0000'>" + _this + "</t>"};
FUNC(BlueText) = {"<t color='#f07f7f00'>" + _this + "</t>"}; //olive

#ifdef __ACE__
if (GVAR(WoundsRevTime) != -1) then {ace_wounds_prevtime = GVAR(WoundsRevTime)};
#endif

__pSetVar ["BIS_noCoreConversations", true];

/* for "_i" from 1 to 21 do {
	_mrkr = format ["mt%1", _i];
	_str = "[" + str (markerPos _mrkr) + "," + toString [34] + markerText _mrkr + toString [34] + ",300]";
	if (_i < 21) then {_str = _str + ","};
	_str = _str + " // " + str (_i - 1);
	diag_log _str;
}; */

_p = player;
__pSetVar [QGVAR(alivetimestart), time];
_pos = position _p;
_type = typeOf _p;
GVAR(string_player) = str(player);
GVAR(player_side) = playerSide;
GVAR(player_str_group) = str(group player);
if (GVAR(player_str_group) != "") then {
	_ar = toArray GVAR(player_str_group);
	_ar set [0,-99]; _ar set [1,-99];
	_ar = _ar - [-99];
	GVAR(player_str_group) = toString _ar;
};
// no idea if the following really works and it should never happen!
if (isNull (group player)) then {
	_gside = if ((faction player) in ["USMC","CDF","BIS_US","BIS_CZ","BIS_GER","BIS_BAF","ACE_USAF","ACE_USNAVY"]) then {west} else {east};
	_grpp = createGroup west;
	[player] joinSilent _grpp;
};
if (side (group player) != GVAR(player_side)) then {
	GVAR(player_side) = side (group player);
};

if (GVAR(WithRevive) == 1) then {
	__pSetVar ["xr_pluncon", false];
	
	#ifdef __ACE__
	if (GVAR(WithWounds) == 1) then {
	#endif
	
	#define __shots ["shotBullet","shotShell","shotRocket","shotMissile","shotTimeBomb","shotMine"]
	xr_bscreens = ["xr_ScreenBlood1", "xr_ScreenBlood2","xr_ScreenBlood3"];
	xr_blurr = ppEffectCreate ["dynamicBlur", -12521];
	FUNC(blurr) = {
		xr_blurr ppEffectEnable true;
		xr_blurr ppEffectAdjust [1];
		xr_blurr ppEffectCommit 1;
		sleep 1;
		xr_blurr ppEffectAdjust [0];
		xr_blurr ppEffectCommit 1;
		sleep 1;
		xr_blurr ppEffectEnable false;
	};
	FUNC(playerHD) = {
		private ["_unit", "_part", "_dam", "_injurer", "_ammo", "_ddexit"];
		PARAMS_5(_unit,_part,_dam,_injurer,_ammo);
		if (!alive _unit) exitWith {_dam};
		if (xr_phd_invulnerable) exitWith {0};
		if (GV(_unit,xr_pluncon)) exitWith {0};
		_ddexit = false;
		if (GVAR(no_teamkill) == 0) then {
			if (_part == "" && {_dam >= 0.5}) then {
				if (isPlayer _injurer) then {
					if (_injurer != _unit && {side (group _injurer) == side (group _unit) && getText (configFile >> "CfgAmmo" >> _ammo >> "simulation") in __shots}) then {
						hint format [(localize "STR_DOM_MISSIONSTRING_497"), name _injurer];
						[QGVAR(unit_tkr), [_unit,_injurer]] call FUNC(NetCallEventCTS);
						if (d_domdatabase) then {
							[QGVAR(ptkkg), _injurer] call FUNC(NetCallEventCTS);
						};
						_ddexit = true;
					};
				};
			};
		};
		if (_ddexit) exitWith {0};
		_dam = _dam * 0.8;
		if (_dam > 0.15 && _part == "") then {
			if (vehicle _unit == _unit) then {
				if (getText (configFile >> "CfgAmmo" >> _ammo >> "simulation") in __shots) then {
					if (!surfaceIsWater (getPosASL _unit)) then {39672 cutRsc ["xr_ScreenDirt","PLAIN"]};
				};
			};
		};
		0 spawn FUNC(blurr);
		39671 cutRsc[xr_bscreens select (floor (random 3)),"PLAIN"];
		_dam
	};
	player removeAllEventHandlers "handleDamage";
	player addEventHandler ["handleDamage", FUNC(playerHD)];
	
	#ifdef __ACE__
	};
	#endif
};

if (GVAR(with_ranked)) then {GVAR(sm_p_pos) = nil};

#ifdef __TT__
GVAR(own_side) = if (GVAR(player_side) == east) then {"EAST"} else {"WEST"};
GVAR(side_player_str) = switch (GVAR(player_side)) do {
	case west: {"west"};
	case east: {"east"};
};
GVAR(own_side_trigger) = if (GVAR(player_side) == east) then {"EAST"} else {"WEST"};

GVAR(side_player) = GVAR(player_side);

GVAR(rep_truck) = if (GVAR(own_side) == "WEST") then {GVAR(rep_truck_west)} else {GVAR(rep_truck_east)};

GVAR(create_bike) = switch (true) do {
	case (__OAVer): {if (GVAR(own_side) == "EAST") then {["Old_bike_TK_INS_EP1","Old_bike_TK_INS_EP1"]} else {["ATV_US_EP1","M1030"]}};
	case (__COVer): {if (GVAR(own_side) == "EAST") then {["MMT_Civ","TT650_Civ"]} else {["MMT_USMC","M1030"]}};
};

if (GVAR(with_mgnest)) then {
	GVAR(mg_nest) = switch (true) do {
		case (__OAVer): {if (GVAR(own_side) == "EAST") then {"WarfareBMGNest_PK_TK_EP1"} else {"WarfareBMGNest_M240_US_EP1"}};
		case (__COVer): {if (GVAR(own_side) == "EAST") then {"RU_WarfareBMGNest_PK"} else {"USMC_WarfareBMGNest_M240"}};
	};
};
#endif

#ifndef __TT__
GVAR(name_flag_base) = GVAR(FLAG_BASE);
#else
GVAR(name_flag_base) = switch (GVAR(player_side)) do {
	case west: {GVAR(WFLAG_BASE)};
	case east: {GVAR(EFLAG_BASE)};
};
#endif

#ifdef __CO__
GVAR(the_box) = switch (GVAR(own_side)) do {
	case "GUER": {"LocalBasicAmmunitionBox"};
	case "EAST": {"RUBasicAmmunitionBox"};
	case "WEST": {"USBasicWeaponsBox"};
};
GVAR(the_base_box) = switch (GVAR(own_side)) do {
	case "GUER": {"GuerillaCacheBox"};
	case "EAST": {"RUSpecialWeaponsBox"};
	case "WEST": {"USSpecialWeaponsBox"};
};
#endif
#ifdef __OA__
GVAR(the_box) = switch (GVAR(own_side)) do {
	case "GUER": {"LocalBasicAmmunitionBox"};
	case "EAST": {"TKBasicWeapons_EP1"};
	case "WEST": {"USBasicWeapons_EP1"};
};
GVAR(the_base_box) = switch (GVAR(own_side)) do {
	case "GUER": {"GuerillaCacheBox"};
	case "EAST": {"TKSpecialWeapons_EP1"};
	case "WEST": {"USSpecialWeapons_EP1"};
};
#endif

GVAR(flag_vec) = objNull;

__ccppfln(x_client\x_f\x_playerfuncs.sqf);

if (!isServer) then {execVM "x_bikb\kbinit.sqf"};

if (!X_SPE) then {
#ifndef __TT__
	GVAR(X_DropZone) = __XJIPGetVar(X_DropZone);
#endif
	GVAR(AriTarget) = __XJIPGetVar(GVAR(AriTarget));
	GVAR(AriTarget2) = __XJIPGetVar(GVAR(AriTarget2));
};

[QGVAR(dummy_marker), [0,0,0],"ICON","ColorBlack",[1,1],"",0,"Empty"] call FUNC(CreateMarkerLocal);
[QGVAR(arti_target2), [0,0,0],"ICON","ColorBlue",[1,1],(localize "STR_DOM_MISSIONSTRING_498"),0,"mil_destroy"] call FUNC(CreateMarkerLocal);
QGVAR(arti_target2) setMarkerPosLocal getPosASL GVAR(AriTarget2);
[QGVAR(arti_target), [0,0,0],"ICON","ColorBlue",[1,1],(localize "STR_DOM_MISSIONSTRING_499"),0,"mil_destroy"] call FUNC(CreateMarkerLocal);
QGVAR(arti_target) setMarkerPosLocal getPosASL GVAR(AriTarget);
#ifndef __TT__
[QGVAR(drop_zone), [0,0,0],"ICON","ColorBlue",[1,1],(localize "STR_DOM_MISSIONSTRING_500"),0,"mil_dot"] call FUNC(CreateMarkerLocal);
QGVAR(drop_zone) setMarkerPosLocal getPosASL GVAR(X_DropZone);
#endif

if (__XJIPGetVar(GVAR(the_end))) exitWith {
	endMission "END1";
	forceEnd;
};

[QGVAR(the_end), {
	if (_this == 0) then {
		if (isNil QGVAR(end_cam_running)) then {
			execVM "x_client\x_endcam.sqf";
		};
	} else {
		endMission "END1";
		forceEnd;
	};
}] call FUNC(NetAddEventToClients);
[QGVAR(recaptured), FUNC(RecapturedUpdate)] call FUNC(NetAddEventToClients);
[QGVAR(doarti), {if (alive player && {(player distance _this < 50)}) then {(localize "STR_DOM_MISSIONSTRING_501") call FUNC(HQChat)}}] call FUNC(NetAddEventToClients);
[2, QGVAR(m_box), FUNC(create_boxNet)] call FUNC(NetAddEvent);
[2, QGVAR(r_box), {_nobjs = nearestObjects [_this, [GVAR(the_box)], 10];if (count _nobjs > 0) then {_box = _nobjs select 0;deleteVehicle _box}}] call FUNC(NetAddEvent);
[QGVAR(air_box), {_box = GVAR(the_box) createVehicleLocal _this;_box setPos [_this select 0,_this select 1,0];player reveal _box;[_box] call FUNC(weaponcargo);_box addEventHandler ["killed",{deleteVehicle (_this select 0)}]}] call FUNC(NetAddEventToClients);
[QGVAR(sm_res_client), {playSound "Notebook";GVAR(side_mission_winner) = _this select 0;if (GVAR(with_ranked)) then {GVAR(sm_running) = false}; (_this select 1) execVM "x_missions\x_sidemissionwinner.sqf"}] call FUNC(NetAddEventToClients);
[QGVAR(target_clear), {playSound "fanfare";_this execVM "x_client\x_target_clear_client.sqf"}] call FUNC(NetAddEventToClients);
[QGVAR(update_target), {execVM "x_client\x_createnexttargetclient.sqf"}] call FUNC(NetAddEventToClients);
[QGVAR(up_m), {[true] spawn FUNC(getsidemissionclient)}] call FUNC(NetAddEventToClients);
[QGVAR(unit_tk), {
	if (GVAR(sub_tk_points) != 0) then {
		[format [(localize "STR_DOM_MISSIONSTRING_502"), _this select 0, _this select 1, GVAR(sub_tk_points)], "GLOBAL"] call FUNC(HintChatMsg);
	} else {
		[format [(localize "STR_DOM_MISSIONSTRING_503"), _this select 0, _this select 1], "GLOBAL"] call FUNC(HintChatMsg);
	};
}] call FUNC(NetAddEventToClients);
[QGVAR(unit_tk2), {
	if (GVAR(sub_tk_points) != 0) then {
		[format [(localize "STR_DOM_MISSIONSTRING_504"), _this select 0, _this select 1, GVAR(sub_tk_points)], "GLOBAL"] call FUNC(HintChatMsg);
	} else {
		[format [(localize "STR_DOM_MISSIONSTRING_505"), _this select 0, _this select 1], "GLOBAL"] call FUNC(HintChatMsg);
	};
}] call FUNC(NetAddEventToClients);
[QGVAR(ataxi), FUNC(ataxiNet)] call FUNC(NetAddEventSTO);
[QGVAR(ai_kill), {if ((_this select 0) in (units (group player))) then {if (player == leader (group player)) then {[QGVAR(pas), [player, _this select 1 ]] call FUNC(NetCallEventCTS)}}}] call FUNC(NetAddEventToClients);
[QGVAR(p_ar), {
#ifdef __DEBUG__
	_uidp = getPlayerUID player;
	_suid = _this select 2;
	__TRACE_2("p_ar","_uidp","_suid");
#endif
	_this call FUNC(player_stuff);
}] call FUNC(NetAddEventSTO);
[QGVAR(sm_p_pos), {GVAR(sm_p_pos) = _this}] call FUNC(NetAddEventToClients);
[QGVAR(mt_winner), {GVAR(mt_winner) = _this}] call FUNC(NetAddEventToClients);
[QGVAR(n_v), FUNC(initvec)] call FUNC(NetAddEventToClients);
[QGVAR(m_l_o), FUNC(LightObj)] call FUNC(NetAddEventToClients);
[QGVAR(dpicm), {_pod = "ARTY_SADARM_BURST" createVehicleLocal _this;_pod setPos _this}] call FUNC(NetAddEventToClients);
[QGVAR(artyt), {_this spawn FUNC(ArtyShellTrail)}] call FUNC(NetAddEventToClients);
[2, QGVAR(mhqdepl), {if (local (_this select 0)) then {(_this select 0) lock (_this select 1)};_this call FUNC(mhqdeplNet)}] call FUNC(NetAddEvent);
[QGVAR(w_n), {[format [(localize "STR_DOM_MISSIONSTRING_506"), _this select 0, _this select 1], "GLOBAL"] call FUNC(HintChatMsg)}] call FUNC(NetAddEventToClients);
[QGVAR(tk_an), {
	[format [(localize "STR_DOM_MISSIONSTRING_507"), _this select 0, _this select 1], "GLOBAL"] call FUNC(HintChatMsg);
	if (serverCommandAvailable "#shutdown") then {serverCommand ("#kick " + (_this select 0))};
}] call FUNC(NetAddEventToClients);
[2, QGVAR(say2), {if (alive player && {(player distance (_this select 0) < (_this select 2))}) then {(_this select 0) say3D (_this select 1)}}] call FUNC(NetAddEvent);
[QGVAR(em), {endMission "LOSER"}] call FUNC(NetAddEventSTO);
[QGVAR(ps_an), {
	switch (_this select 1) do {
		case 0: {[format [(localize "STR_DOM_MISSIONSTRING_508"), _this select 0], "GLOBAL"] call FUNC(HintChatMsg)};
		case 1: {[format [(localize "STR_DOM_MISSIONSTRING_509"), _this select 0], "GLOBAL"] call FUNC(HintChatMsg)};
	};
	if (serverCommandAvailable "#shutdown") then {serverCommand ("#kick " + (_this select 0))};
}] call FUNC(NetAddEventToClients);
[QGVAR(s_p_inf), {GVAR(u_r_inf) = _this}] call FUNC(NetAddEventSTO);
[QGVAR(w_ma), {deleteMarkerLocal _this}] call FUNC(NetAddEventToClients);
[2, QGVAR(p_o_a), {
	private "_ar";_ar = _this select 1;
#ifdef __TT__
	if (GVAR(player_side) == (_ar select 3)) then {
#endif
	if ((_ar select 0) isKindOf "Mash") then {
		[_ar select 1, getPosASL (_ar select 0),"ICON","ColorBlue",[0.5,0.5],format [(localize "STR_DOM_MISSIONSTRING_510"), _ar select 2],0,"mil_dot"] call FUNC(CreateMarkerLocal);
	} else {
		if ((_ar select 0) isKindOf "Base_WarfareBVehicleServicePoint") then {
			[_ar select 1, getPosASL (_ar select 0),"ICON","ColorBlue",[0.5,0.5],format [(localize "STR_DOM_MISSIONSTRING_511"), _ar select 2],0,"mil_dot"] call FUNC(CreateMarkerLocal);
		} else {
			[_ar select 1, getPosASL (_ar select 0),"ICON","ColorBlue",[0.5,0.5],format [(localize "STR_DOM_MISSIONSTRING_512"), _ar select 2],0,"mil_dot"] call FUNC(CreateMarkerLocal);
		};
	};
#ifdef __TT__
	};
#endif
}] call FUNC(NetAddEvent);
if (GVAR(with_ranked)) then {
	[QGVAR(pho), {(format [(localize "STR_DOM_MISSIONSTRING_288"), GVAR(ranked_a) select 17]) call FUNC(HQChat)}] call FUNC(NetAddEventSTO);
};
#ifdef __ACE__
[QGVAR(haha), FUNC(DHaha)] call FUNC(NetAddEventSTO);
#endif
[2, QGVAR(p_o_r), {deleteMarkerLocal (_this select 1)}] call FUNC(NetAddEvent);
if (GVAR(engineerfull) == 0 || GVAR(with_ai) || GVAR(with_ai_features) == 0) then {
	[QGVAR(farp_e), {if (GVAR(eng_can_repfuel)) then {_this addAction [(localize "STR_DOM_MISSIONSTRING_513") call FUNC(BlueText), "x_client\x_restoreeng.sqf"]}}] call FUNC(NetAddEventToClients);
};
[QGVAR(p_o_an), {_this call FUNC(PlacedObjAn)}] call FUNC(NetAddEventToClients);
#ifdef __TT__
if (GVAR(WithRevive) == 0) then {
	[QGVAR(u_k), {format [(localize "STR_DOM_MISSIONSTRING_514"), _this select 0, _this select 1, _this select 2, GVAR(tt_points) select 8] call FUNC(GlobalChat)}] call FUNC(NetAddEventToClients);
} else {
	[QGVAR(u_k), {format [(localize "STR_DOM_MISSIONSTRING_515"), _this select 0, _this select 1, _this select 2, GVAR(tt_points) select 8] call FUNC(GlobalChat)}] call FUNC(NetAddEventToClients);
};
[QGVAR(vec_killer), {format [(localize "STR_DOM_MISSIONSTRING_516"), _this select 0, _this select 1, _this select 2, GVAR(tt_points) select 7] call FUNC(GlobalChat)}] call FUNC(NetAddEventToClients);
[QGVAR(r_mark), {if (GVAR(player_side) != (_this select 1)) then {_this spawn {waitUntil {((markerPos (_this select 0)) select 0) != 0};deleteMarkerLocal (_this select 0)}}}] call FUNC(NetAddEventToClients);
[QGVAR(attention), {_this call FUNC(dattention)}] call FUNC(NetAddEventToClients);
[QGVAR(w_m_c), {
	if (!isNil {_this select 3} && {!isNil QGVAR(player_side)}) then {
		if (GVAR(player_side) == _this select 3) then {
			[_this select 0, _this select 1,"ICON","ColorBlue",[1,1],format [(localize "STR_DOM_MISSIONSTRING_517"), _this select 2],0,"mil_triangle"] call FUNC(CreateMarkerLocal)
		}
	}
}] call FUNC(NetAddEventToClients);
#else
[QGVAR(dropansw), FUNC(dropansw)] call FUNC(NetAddEventSTO);
[QGVAR(n_jf), {if (GVAR(WithJumpFlags) == 1) then {_this execVM "x_client\x_newflagclient.sqf"}}] call FUNC(NetAddEventToClients);
[QGVAR(jet_sf), FUNC(jet_service_facNet)] call FUNC(NetAddEventToClients);
[QGVAR(chop_sf), FUNC(chopper_service_facNet)] call FUNC(NetAddEventToClients);
[QGVAR(wreck_rf), FUNC(wreck_repair_facNet)] call FUNC(NetAddEventToClients);
[QGVAR(s_b_client), {__XJIPGetVar(GVAR(searchbody)) setVariable [QGVAR(search_id), __XJIPGetVar(GVAR(searchbody)) addAction [(localize "STR_DOM_MISSIONSTRING_518"), "x_client\x_searchbody.sqf"]]}] call FUNC(NetAddEventToClients);
[QGVAR(rem_sb_id), {if (!isNil {__XJIPGetVar(GVAR(searchbody)) getVariable QGVAR(search_id)}) then {__XJIPGetVar(GVAR(searchbody)) removeAction (__XJIPGetVar(GVAR(searchbody)) getVariable QGVAR(search_id))}}] call FUNC(NetAddEventToClients);
[QGVAR(intel_upd), FUNC(intel_updNet)] call FUNC(NetAddEventToClients);
[QGVAR(w_m_c), {[_this select 0, _this select 1,"ICON","ColorBlue",[1,1],format [(localize "STR_DOM_MISSIONSTRING_517"), _this select 2],0,"mil_triangle"] call FUNC(CreateMarkerLocal)}] call FUNC(NetAddEventToClients);
#endif
[QGVAR(smsg), {(localize "STR_DOM_MISSIONSTRING_519") call FUNC(HQChat)}] call FUNC(NetAddEventToClients);

[QGVAR(mqhtn), {[format [(localize "STR_DOM_MISSIONSTRING_520"), GVAR(MHQDisableNearMT), _this], "HQ"] call FUNC(HintChatMsg)}] call FUNC(NetAddEventToClients);

[QGVAR(ccso), {playSound "Ui_cc"}] call FUNC(NetAddEventToClients);

[QGVAR(grpswmsg), {((_this select 1) + " " + localize "STR_DOM_MISSIONSTRING_1432") call FUNC(GlobalChat)}] call FUNC(NetAddEventSTO);
[QGVAR(grpswmsgn), {((_this select 1) + " " + localize "STR_DOM_MISSIONSTRING_1433") call FUNC(GlobalChat)}] call FUNC(NetAddEventSTO);

#ifdef __TOH__
[2, QGVAR(setVideoPIPTar), FUNC(setVideoPipTarget)] call FUNC(NetAddEvent);
#endif

if (GVAR(domdatabase)) then {
	[QGVAR(sendps), FUNC(CreatePStatsDialog)] call FUNC(NetAddEventSTO);
};

if (GVAR(dom4)) then {
	[2, QGVAR(u_old_m), {
		private ["_mname", "_mcolor"];
		_mname = format [QGVAR(target_%1), _this select 0];
		_mcolor = switch (_this select 1) do {
			case "west": {"ColorBlueFaded25"};
			case "east": {"ColorRedFaded25"};
		};
		_mname setMarkerColorLocal _mcolor;
		_curtars = __XJIPGetVar(GVAR(current_targets));
		_mname = format [QGVAR(target_%1), _curtars select 0];
		_mname setMarkerColorLocal "ColorRedFaded75";
		_mname = format [QGVAR(target_%1), _curtars select 1];
		_mname setMarkerColorLocal "ColorBlueFaded75";
	}] call FUNC(NetAddEvent);
};

0 spawn {
	sleep 1 + random 3;
	if (isMultiplayer) then {
		[QGVAR(p_a), player] call FUNC(NetCallEventCTS);// ask the server for the client score, etc
		waitUntil {!GVAR(still_in_intro)};
		xr_phd_invulnerable = false;
		__pSetVar ["ace_w_allow_dam", nil];
		sleep 2;
		__pSetVar [QGVAR(player_old_rank), "PRIVATE"];
		["player_rank", {call FUNC(PlayerRank)},5.01] call FUNC(addPerFrame);
	} else {
		GVAR(player_autokick_time) = GVAR(AutoKickTime);
		xr_phd_invulnerable = false;
		__pSetVar ["ace_w_allow_dam", nil];
		0 spawn {
			sleep 20;
			if (GVAR(still_in_intro)) then {
				GVAR(still_in_intro) = false;
			};
		};
	};
};

["init_vecs", {{_x call FUNC(initvec)} forEach vehicles;["init_vecs"] call FUNC(removePerFrame)},0] call FUNC(addPerFrame);

if (GVAR(with_ranked)) then {
	// basic rifle at start
	_weapp = "";
	_magp = "";
	switch (GVAR(own_side)) do {
		case "WEST": {
#ifdef __CO__
			_weapp = "M16A4";
#endif
#ifdef __OA__
			_weapp = "M16A2";
#endif
			_magp = "30Rnd_556x45_Stanag";
		};
		case "EAST": {
			_weapp = "AK_74";
			_magp = "30Rnd_545x39_AK";
		};
		case "GUER": {
			_weapp = "M16A4";
			_magp = "30Rnd_556x45_Stanag";
		};
	};
	removeAllWeapons _p;
	for "_i" from 1 to 6 do {_p addMagazine _magp};
	_p addWeapon _weapp;
};

#define __tctn _target_array = GVAR(target_names) select _res;\
_current_target_pos = _target_array select 0;\
_target_name = _target_array select 1;\
_target_radius = _target_array select 2
_taskstr = "d_task%2 = player createSimpleTask ['obj%2'];d_task%2 setSimpleTaskDescription ['" + localize "STR_DOM_MISSIONSTRING_202" + "','" + localize "STR_DOM_MISSIONSTRING_203" + "','" + localize "STR_DOM_MISSIONSTRING_203" + "'];d_task%2 settaskstate _objstatus;d_task%2 setSimpleTaskDestination _current_target_pos;";
#define __tmarker [_target_name, _current_target_pos,#ELLIPSE,_color,[_target_radius,_target_radius]] call FUNC(CreateMarkerLocal)
if (GVAR(MissionType) != 2) then {
#ifndef __TT__
	if (count __XJIPGetVar(resolved_targets) > 0) then {
		for "_i" from 0 to (count __XJIPGetVar(resolved_targets) - 1) do {
			if (isNil {__XJIPGetVar(resolved_targets)}) exitWith {};
			if (_i >= count __XJIPGetVar(resolved_targets)) exitWith {};
			_res = __XJIPGetVar(resolved_targets) select _i;
			if (!isNil "_res") then {
				if (_res >= 0) then {
					__tctn;
					_mname = format [QGVAR(target_%1), _res];
					_no = __getMNsVar2(_mname);
					_color = "ColorGreen";
					_objstatus = "Succeeded";
					if (!isNull _no) then {
						_isrec = GV(_no,GVAR(recaptured));
						if (!isNil "_isrec") then {
							_objstatus = "Failed";
							_color = "ColorRed";
							[_target_name, _current_target_pos,"ELLIPSE",_color,[_target_radius,_target_radius],"",0,"Marker","FDiagonal"] call FUNC(CreateMarkerLocal);
						} else {
							__tmarker;
						};
					} else {
						__tmarker;
					};

					call compile format [_taskstr,_target_name,_res + 2];
				};
			};
		};
	};
#else
	if (count __XJIPGetVar(resolved_targets) > 0) then {
		for "_i" from 0 to (count __XJIPGetVar(resolved_targets) - 1) do {
			if (isNil {__XJIPGetVar(resolved_targets)}) exitWith {};
			if (_i == count __XJIPGetVar(resolved_targets)) exitWith {};
			_xres = __XJIPGetVar(resolved_targets) select _i;
			_res = _xres select 0;
			_winner = _xres select 1;
			__tctn;
			_color = switch (_winner) do {
				case 1: {"ColorBlue"};
				case 2: {"ColorRed"};
				case 3: {"ColorGreen"};
			};
			__tmarker;
			call compile format [_taskstr,_target_name,_res + 2];
		};
	};
#endif

	GVAR(current_seize) = "";
	if (__XJIPGetVar(GVAR(current_target_index)) != -1 && !__XJIPGetVar(target_clear)) then {
		__TargetInfo;
		_current_target_pos = _target_array2 select 0;
		GVAR(current_seize) = _current_target_name;
		_target_radius = _target_array2 select 2;	
	#ifndef __TT__
		_color = "ColorRed";
	#else
		_color = "ColorYellow";
	#endif
		[_current_target_name, _current_target_pos,"ELLIPSE",_color,[_target_radius,_target_radius]] call FUNC(CreateMarkerLocal);
		QGVAR(dummy_marker) setMarkerPosLocal _current_target_pos;
		_objstatus = "Created";
		call compile format [(_taskstr + "d_current_task = d_task%2;"), _current_target_name, __XJIPGetVar(GVAR(current_target_index)) + 2];
	};
};

{
	if (typeName _x == "ARRAY") then {
#ifdef __TT__
		if (GVAR(player_side) == (_x select 3)) then {
#endif
		[_x select 0, _x select 1,"ICON","ColorBlue",[1,1],format [(localize "STR_DOM_MISSIONSTRING_517"), _x select 2],0,"mil_triangle"] call FUNC(CreateMarkerLocal);
#ifdef __TT__
		};
#endif
	};
} forEach __XJIPGetVar(GVAR(wreck_marker));

if (GVAR(MissionType) != 2) then {
	_counterxx = 0;
	{
		_pos = position _x;
		[format [QGVAR(paraflag%1), _counterxx], _pos,"ICON","ColorYellow",[0.5,0.5],"Parajump",0,"mil_flag"] call FUNC(CreateMarkerLocal);
		
		__INC(_counterxx);
		if (GVAR(jumpflag_vec) == "") then {
			_x addaction [(localize "STR_DOM_MISSIONSTRING_296") call FUNC(BlueText),"AAHALO\x_paraj.sqf"];
		} else {
			_text = format [(localize "STR_DOM_MISSIONSTRING_297"), [GVAR(jumpflag_vec),0] call FUNC(GetDisplayName)];
			_x addAction [_text call FUNC(BlueText),"x_client\x_bike.sqf",[GVAR(jumpflag_vec),1]];
		};
#ifdef __ACE__
		if (GVAR(jumpflag_vec) == "") then {
			_box = "ACE_RuckBox" createVehicleLocal _pos;
			clearMagazineCargo _box;
			clearWeaponCargo _box;
			_box addweaponcargo ["ACE_ParachutePack",10];
			_box allowDamage false;
		};
#endif
	} forEach __XJIPGetVar(jump_flags);
};

if (GVAR(MissionType) != 2) then {
	if (!__XJIPGetVar(GVAR(mt_radio_down))) then {
		if (__XJIPGetVar(mt_radio_pos) select 0 != 0) then {
			["main_target_radiotower", __XJIPGetVar(mt_radio_pos),"ICON","ColorBlack",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_521"),0,"mil_dot"] call FUNC(CreateMarkerLocal);
		};
	};
};

if (GVAR(MissionType) != 2) then {
	if (count __XJIPGetVar(GVAR(currentcamps)) > 0) then {
		{
			if (!isNull _x) then {
#ifndef __TT__
				_mcol = switch (GV(_x,GVAR(SIDE))) do {
					case "WEST": {if (GVAR(own_side) == "EAST") then {"ColorBlack"} else {"ColorBlue"}};
					case "EAST": {if (GVAR(own_side) == "WEST") then {"ColorBlack"} else {"ColorBlue"}};
				};
#else
				_mcol = switch (GV(_x,GVAR(SIDE))) do {
					case "WEST": {"ColorBlue"};
					case "EAST": {"ColorRed"};
					case "GUER": {"ColorBlack"};
				};
#endif
				[format[QGVAR(camp%1),GV(_x,GVAR(INDEX))], getPosASL _x,"ICON",_mcol,[0.5,0.5],"",0,"Strongpoint"] call FUNC(CreateMarkerLocal);
			};
		} forEach __XJIPGetVar(GVAR(currentcamps));
	};
};

if (__XJIPGetVar(all_sm_res)) then {GVAR(current_mission_text) = (localize "STR_DOM_MISSIONSTRING_522")} else {[false] spawn FUNC(getsidemissionclient)};

if (GVAR(without_nvg) == 1) then {
	#define __paddweap(xweap) if (!(_p hasWeapon #xweap)) then {_p addWeapon #xweap}
	__paddweap(NVGoggles);
} else {
	if (player hasWeapon "NVGoggles") then {player removeWeapon "NVGoggles"};
	execFSM "fsms\RemoveGoogles.fsm";
};
_weapop = weapons player;
if (!("Binocular_Vector" in _weapop) && !("Laserdesignator" in _weapop)) then {
	__paddweap(Binocular);
};
__paddweap(ItemGPS);

#ifndef __ACE__
if (sunOrMoon == 0) then {_p action ["NVGoggles",_p]};
#endif

__cppfln(FUNC(x_playerspawn),x_client\x_playerspawn.sqf);

GVAR(pl_killer) = objNull;
GVAR(pl_killer_t) = 0;
GVAR(dublicate_kill) = false;
if (GVAR(with_ai)) then {
	player addMPEventHandler ["MPKilled", {_this call FUNC(x_checkkill)}];
} else {
	__cppfln(FUNC(x_dlgopen),x_client\x_open.sqf);
	if !(__TTVer) then {
			player addMPEventHandler ["MPKilled", {_this call FUNC(x_checkkill)}];
	} else {
		if (GVAR(player_side) == west) then {
				player addMPEventHandler ["MPKilled", {_this call FUNC(x_checkkillwest)}];
		} else {
				player addMPEventHandler ["MPKilled", {_this call FUNC(x_checkkilleast)}];
		};
	};
};

xr_use_dom_opendlg = false;
FUNC(prespawned) = {
	if (GVAR(WithMHQTeleport) == 0) then {
		if (!isNil QUOTE(FUNC(x_dlgopen))) then {
			if (GVAR(WithRevive) == 0) then {
				//if (xr_max_lives == -1) then {
				//	call FUNC(x_dlgopen);
				//} else {
					if (__pGetVar(xr_lives) > -1) then {
						if (xr_use_dom_opendlg) then {
							call FUNC(x_dlgopen);
							xr_use_dom_opendlg = false;
						};
					};
				//};
			} else {
				call FUNC(x_dlgopen);
			};
		};
	};
	[1, _this] call FUNC(x_playerspawn);
};

player addEventHandler ["respawn", FUNC(prespawned)];

if (count __XJIPGetVar(GVAR(ammo_boxes)) > 0) then {
	private ["_box_pos", "_boxnew", "_boxscript"];
	{
		if (typeName _x == "ARRAY") then {
			_box_pos = _x select 0;
#ifndef __TT__
			if ((_x select 1) != "") then {[_x select 1, _box_pos,"ICON","ColorBlue",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_523"),0,GVAR(dropped_box_marker)] call FUNC(CreateMarkerLocal)};
#else
			if ((_x select 1) != "" && {GVAR(player_side) == (_x select 2)}) then {[_x select 1, _box_pos,"ICON","ColorBlue",[0.5,0.5],(localize "STR_DOM_MISSIONSTRING_523"),0,GVAR(dropped_box_marker)] call FUNC(CreateMarkerLocal)};
#endif
			_boxnew = GVAR(the_box) createVehicleLocal _box_pos;
			_boxnew setPos _box_pos;
			_boxnew addAction [(localize "STR_DOM_MISSIONSTRING_300") call FUNC(BlueText), "x_client\x_savelayout.sqf"];
			_boxnew addAction [(localize "STR_DOM_MISSIONSTRING_301") call FUNC(BlueText), "x_client\x_clearlayout.sqf"];
			[_boxnew] call FUNC(weaponcargo);
			_boxnew allowDamage false;
		};
	} forEach __XJIPGetVar(GVAR(ammo_boxes));
};

GVAR(player_can_call_drop) = 0;
GVAR(player_can_call_arti) = 0;
GVAR(player_can_build_trench) = false;
__pSetVar [QGVAR(isinaction), false];

__cppfln(FUNC(spawn_mash),x_client\x_mash.sqf);
__cppfln(FUNC(spawn_mgnest),x_client\x_mgnest.sqf);

__cppfln(FUNC(3DCredits),scripts\fn_3dcredits.sqf);
__cppfln(FUNC(DirIndicator),scripts\fn_dirindicator.sqf);
__cppfln(FUNC(Sandstorm),scripts\fn_sandstorm.sqf);

#ifndef __TT__
[(localize "STR_DOM_MISSIONSTRING_524") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_525") + "</t>", position GVAR(vecre_trigger), 30, 0] spawn FUNC(3DCredits);
[(localize "STR_DOM_MISSIONSTRING_526") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_527") + "</t>", position GVAR(jet_trigger), 30, 0] spawn FUNC(3DCredits);
[(localize "STR_DOM_MISSIONSTRING_528") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_529") + "</t>", position GVAR(chopper_trigger), 30, 0] spawn FUNC(3DCredits);
[(localize "STR_DOM_MISSIONSTRING_0") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_530") + "</t>", position GVAR(wreck_rep), 30, 0] spawn FUNC(3DCredits);
if (isNil QGVAR(with_carrier)) then {
	[(localize "STR_DOM_MISSIONSTRING_531") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_532") + "</t>", position GVAR(AMMOLOAD), 30, 0] spawn FUNC(3DCredits);
};
#else
if (GVAR(player_side) == west) then {
	[(localize "STR_DOM_MISSIONSTRING_524") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_525") + "</t>", position GVAR(vecre_trigger), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_526") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_527") + "</t>", position GVAR(jet_trigger), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_528") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_529") + "</t>", position GVAR(chopper_trigger), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_0") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_530") + "</t>", position GVAR(wreck_rep), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_531") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_532") + "</t>", position GVAR(AMMOLOAD), 30, 0] spawn FUNC(3DCredits);
} else {
	[(localize "STR_DOM_MISSIONSTRING_524") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_525") + "</t>", position GVAR(vecre_trigger2), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_526") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_527") + "</t>", position GVAR(jet_trigger2), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_528") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_529") + "</t>", position GVAR(chopper_triggerR), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_0") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_530") + "</t>", position GVAR(wreck_rep2), 30, 0] spawn FUNC(3DCredits);
	[(localize "STR_DOM_MISSIONSTRING_531") + "<br/><t size='0.6'>" + (localize "STR_DOM_MISSIONSTRING_532") + "</t>", position GVAR(AMMOLOAD2), 30, 0] spawn FUNC(3DCredits);
};
#endif

diag_log ["Internal D Version:",__DOM_NVER_STR2__];

__pSetVar [QGVAR(trench), objNull];
__pSetVar [QGVAR(trenchid), -9999];
if (GVAR(with_ai) || GVAR(with_ai_features) == 0) then {
	if (GVAR(with_ai)) then {
		execVM "x_client\x_recruitsetup.sqf";
		
		_grpp = group player;
		_leader = leader _grpp;
		if (!isPlayer _leader || {player == _leader}) then {
			{
				if (!isPlayer _x) then {
					if (vehicle _x == _x) then {
						deleteVehicle _x;
					} else {
						moveOut _x;
						_x spawn {
							waitUntil {sleep 0.331;vehicle _this == _this};
							deleteVehicle _this;
						};
					};
				};
			} forEach units _grpp;
		};
	};

	if !(__ACEVer) then {
		GVAR(player_can_call_arti) = 1;
		GVAR(player_can_call_drop) = 1;
	} else {
		[1] execVM "x_client\x_artiradiocheckold.sqf";
		execVM "x_client\x_dropradiocheckold.sqf";
	};
	GVAR(player_can_build_trench) = true;
	_p addRating 20000;
} else {
	if (GVAR(string_player) in GVAR(can_use_artillery)) then {
		if !(__ACEVer) then {
			if (GVAR(string_player) == "RESCUE") then {
				GVAR(player_can_call_arti) = 1;
			};
			if (GVAR(string_player) == "RESCUE2") then {
				GVAR(player_can_call_arti) = 2;
			};
		} else {
			GVAR(player_can_call_arti) = switch (GVAR(string_player)) do {
				case "RESCUE": {1};
				case "RESCUE2": {2};
				default {0};
			};
			if (GVAR(player_can_call_arti) == 0) exitWith {};
			[GVAR(player_can_call_arti)] execVM "x_client\x_artiradiocheckold.sqf";
		};
	} else {
		enableEngineArtillery false;
	};
	if (GVAR(string_player) in GVAR(can_call_drop_ar)) then {
		if (__ACEVer) then {
			execVM "x_client\x_dropradiocheckold.sqf";
		} else {
			GVAR(player_can_call_drop) = 1;
		};
	};
	if (GVAR(player_can_call_arti) == 0 && !(GVAR(string_player) in GVAR(is_engineer))) then {
		GVAR(player_can_build_trench) = true;
	};
};

_respawn_marker = "";
#define __dml_w deleteMarkerLocal #respawn_west
#define __dml_e deleteMarkerLocal #respawn_east
#define __dml_g deleteMarkerLocal #respawn_guerrila
switch (GVAR(own_side)) do {
	case "GUER": {
		_respawn_marker = "respawn_guerrila";
		__dml_w;
		__dml_e;
	};
	case "WEST": {
		_respawn_marker = "respawn_west";
		__dml_g;
		__dml_e;
	};
	case "EAST": {
		_respawn_marker = "respawn_east";
		__dml_w;
		__dml_g;
	};
};

#define __rmsmpl _respawn_marker setMarkerPosLocal
if (__TTVer) then {
	if (GVAR(player_side) == west) then {
		__rmsmpl markerPos "base_spawn_1";
	} else {
		__rmsmpl markerPos "base_spawn_2";
	};
} else {
	if (!isNil QGVAR(with_carrier)) then {
		"base_spawn_1" setMarkerPosLocal [markerPos "base_spawn_1" select 0, markerPos "base_spawn_1" select 1, 15.9];
		__rmsmpl [markerPos "base_spawn_1" select 0, markerPos "base_spawn_1" select 1, 15.9];
	} else {
		__rmsmpl markerPos "base_spawn_1";
	};
};
// if there ever will be a carrier version who knows... if (!isNil QGVAR(with_carrier)) then {"base_spawn_1" setMarkerPosLocal [markerPos "base_spawn_1" select 0, markerPos "base_spawn_1" select 1, 15.9]};

__pSetVar [QGVAR(pbp_id), -9999];
GVAR(backpack_helper) = [];
__pSetVar [QGVAR(custom_backpack), []];
__pSetVar [QGVAR(player_backpack), []];
if (GVAR(WithBackpack)) then {
	GVAR(prim_weap_player) = primaryWeapon _p;
	_s = format [(localize "STR_DOM_MISSIONSTRING_155"), [GVAR(prim_weap_player),1] call FUNC(GetDisplayName)];
	if (GVAR(prim_weap_player) != "" && GVAR(prim_weap_player) != " ") then {
		__pSetVar [QGVAR(pbp_id), _p addAction [_s call FUNC(GreyText), "x_client\x_backpack.sqf",[],-1,false]];
	};
	// No Weapon fix for backpack
	[_pos, [0, 0, 0, false], ["NONE", "PRESENT", true], ["primaryWeapon player != d_prim_weap_player && primaryWeapon player != ' ' && !dialog","call {d_prim_weap_player = primaryWeapon player;_id = player getVariable 'd_pbp_id';if (_id != -9999 && count (player getVariable 'd_player_backpack') == 0) then {player removeAction _id;player setVariable ['d_pbp_id', -9999]};if ((player getVariable 'd_pbp_id' == -9999) && count (player getVariable 'd_player_backpack') == 0 && d_prim_weap_player != '' && d_prim_weap_player != ' ') then {player setVariable ['d_pbp_id', player addAction [format [localize 'STR_DOM_MISSIONSTRING_155', [d_prim_weap_player,1] call d_fnc_GetDisplayName] call d_fnc_GreyText, 'x_client\x_backpack.sqf',[],-1,false]]}}",""]] call FUNC(CreateTrigger);
};

#ifndef __TT__
GVAR(base_trigger) = createTrigger["EmptyDetector" ,GVAR(base_array) select 0];
GVAR(base_trigger) setTriggerArea [GVAR(base_array) select 1, GVAR(base_array) select 2, GVAR(base_array) select 3, true];
#else
_dbase_a = if (GVAR(player_side) == west) then {GVAR(base_array) select 0} else {GVAR(base_array) select 1};
GVAR(base_trigger) = createTrigger["EmptyDetector" ,_dbase_a select 0];
GVAR(base_trigger) setTriggerArea [_dbase_a select 1, _dbase_a select 2, _dbase_a select 3, true];
#endif
GVAR(base_trigger) setTriggerActivation [GVAR(own_side_trigger), "PRESENT", true];
GVAR(base_trigger) setTriggerStatements["this", "", ""];

// special triggers for engineers, AI version, everybody can repair and flip vehicles
GVAR(eng_can_repfuel) = false;
if (GVAR(string_player) in GVAR(is_engineer) || GVAR(with_ai) || GVAR(with_ai_features) == 0) then {
	GVAR(eng_can_repfuel) = true;

	if (GVAR(engineerfull) == 0 || {GVAR(with_ai) || GVAR(with_ai_features) == 0}) then {
#ifndef __TT__
		GVAR(engineer_trigger) = createTrigger["EmptyDetector" ,GVAR(base_array) select 0];
		GVAR(engineer_trigger) setTriggerArea [GVAR(base_array) select 1, GVAR(base_array) select 2, GVAR(base_array) select 3, true];
#else
		_dbase_a = if (playerSide == west) then {GVAR(base_array) select 0} else {GVAR(base_array) select 1};
		GVAR(engineer_trigger) = createTrigger["EmptyDetector" ,_dbase_a select 0];
		GVAR(engineer_trigger) setTriggerArea [_dbase_a select 1, _dbase_a select 2, _dbase_a select 3, true];
#endif
		GVAR(engineer_trigger) setTriggerActivation [GVAR(own_side_trigger), "PRESENT", true];
		GVAR(engineer_trigger) setTriggerStatements["!d_eng_can_repfuel && player in thislist", "d_eng_can_repfuel = true;(localize 'STR_DOM_MISSIONSTRING_340') call d_fnc_GlobalChat", ""];
	};
	
	if (GVAR(with_ranked)) then {GVAR(last_base_repair) = -1};
	
	[_pos, [0, 0, 0, false], ["NONE", "PRESENT", true], ["call d_fnc_ffunc", "actionID1=player addAction [(localize 'STR_DOM_MISSIONSTRING_1408') call d_fnc_GreyText, 'scripts\unflipVehicle.sqf',[d_objectID1],-1,false];", "player removeAction actionID1"]] call FUNC(CreateTrigger);
	
	if (GVAR(engineerfull) == 0 || {GVAR(with_ai) || GVAR(with_ai_features) == 0}) then {
		_trigger = createTrigger["EmptyDetector" ,_pos];
		_trigger setTriggerArea [0, 0, 0, true];
		_trigger setTriggerActivation ["NONE", "PRESENT", true];
#ifndef __ENGINEER_OLD__
		_trigger setTriggerStatements["call d_fnc_sfunc", "d_actionID6 = player addAction ['Analyze Vehicle' call d_fnc_GreyText, 'x_client\x_repanalyze.sqf',[],-1,false];d_actionID2 = player addAction ['Repair/Refuel Vehicle' call d_fnc_GreyText, 'x_client\x_repengineer.sqf',[],-1,false]", "player removeAction d_actionID6;player removeAction d_actionID2"];
#else
		_trigger setTriggerStatements["call d_fnc_sfunc", "d_actionID2 = player addAction ['Repair/Refuel Vehicle' call d_fnc_GreyText, 'x_client\x_repengineer_old.sqf',[],-1,false]", "player removeAction d_actionID2"];
#endif
	};
	
	__pSetVar [QGVAR(is_engineer),true];
	__pSetVar [QGVAR(farp_pos), []];
	
	if (GVAR(engineerfull) == 0 || {GVAR(with_ai) || GVAR(with_ai_features) == 0}) then {
		{_x addAction [(localize "STR_DOM_MISSIONSTRING_513") call FUNC(BlueText), "x_client\x_restoreeng.sqf"]} forEach (__XJIPGetVar(GVAR(farps)));
	};
};

GVAR(there_are_enemies_atbase) = false;
GVAR(enemies_near_base) = false;
#ifndef __TT__
// Enemy at base
if (isNil QGVAR(with_carrier)) then {
	"enemy_base" setMarkerPosLocal (GVAR(base_array) select 0);
	"enemy_base" setMarkerDirLocal (GVAR(base_array) select 3);
	[GVAR(base_array) select 0, [GVAR(base_array) select 1, GVAR(base_array) select 2, GVAR(base_array) select 3, true], [GVAR(enemy_side), "PRESENT", true], ["'Man' countType thislist > 0 || 'Tank' countType thislist > 0 || 'Car' countType thislist > 0", "[0] call d_fnc_BaseEnemies;'enemy_base' setMarkerSizeLocal [d_base_array select 1,d_base_array select 2];d_there_are_enemies_atbase = true", "[1] call d_fnc_BaseEnemies;'enemy_base' setMarkerSizeLocal [0,0];d_there_are_enemies_atbase = false"]] call FUNC(CreateTrigger);
	[GVAR(base_array) select 0, [(GVAR(base_array) select 1) + 300, (GVAR(base_array) select 2) + 300, GVAR(base_array) select 3, true], [GVAR(enemy_side), "PRESENT", true], ["'Man' countType thislist > 0 || 'Tank' countType thislist > 0 || 'Car' countType thislist > 0", "hint (localize 'STR_DOM_MISSIONSTRING_1409');d_enemies_near_base = true", "d_enemies_near_base = false"]] call FUNC(CreateTrigger);
};
#endif

GVAR(player_can_build_mgnest) = false;
if (GVAR(with_mgnest)) then {
	if (GVAR(string_player) in GVAR(can_use_mgnests)) then {
		GVAR(player_can_build_mgnest) = true;
		__pSetVar [QGVAR(mgnest_pos), []];
	};
};

GVAR(player_is_medic) = false;
if (GVAR(string_player) in GVAR(is_medic)) then {
	if (GVAR(with_medtent)) then {
		GVAR(player_is_medic) = true;
		__pSetVar [QGVAR(medtent), []];
	};
};

// TODO: Remove those ?
if (!isNil QGVAR(action_menus_type)) then {
	if (count GVAR(action_menus_type) > 0) then {
		{
			_types = _x select 0;
			if (count _types > 0) then {
				if (_type in _types) then { 
					_action = _p addAction [(_x select 1) call FUNC(GreyText),_x select 2,[],-1,false];
					_x set [3, _action];
				};
			} else {
				_action = _p addAction [(_x select 1) call FUNC(GreyText),_x select 2,[],-1,false];
				_x set [3, _action];
			};
		} forEach GVAR(action_menus_type);
	};
};
if (!isNil QGVAR(action_menus_unit)) then {
	if (count GVAR(action_menus_unit) > 0) then {
		{
			_types = _x select 0;
			_ar = _x;
			if (count _types > 0) then {
				{
					private "_pc";
					_pc = __getMNsVar(_x);
					if (_p ==  _pc) exitWith { 
						_action = _p addAction [(_ar select 1) call FUNC(GreyText),_ar select 2,[],-1,false];
						_ar set [3, _action];
					};
				} forEach _types
			} else {
				_action = _p addAction [(_x select 1) call FUNC(GreyText),_x select 2,[],-1,false];
				_x set [3, _action];
			};
		} forEach GVAR(action_menus_unit);
	};
};

if (!isNil QGVAR(action_menus_vehicle)) then {
	if (count GVAR(action_menus_vehicle) > 0) then {execVM "x_client\x_vecmenus.sqf"};
};

#ifndef __TT__
if (isNil QGVAR(with_carrier) && GVAR(MissionType) != 2) then {
	if (GVAR(string_player) in GVAR(is_engineer) || {GVAR(with_ai) || GVAR(with_ai_features) == 0}) then {
		if (__XJIPGetVar(GVAR(jet_serviceH)) && {!__XJIPGetVar(GVAR(jet_s_reb))}) then {
			[0] spawn FUNC(XFacAction);
		};
		if (__XJIPGetVar(GVAR(chopper_serviceH)) && {!__XJIPGetVar(GVAR(chopper_s_reb))}) then {
			[1] spawn FUNC(XFacAction);
		};
		if (__XJIPGetVar(GVAR(wreck_repairH)) && {!__XJIPGetVar(GVAR(wreck_s_reb))}) then {
			[2] spawn FUNC(XFacAction);
		};
	};

#define __facset _pos = _element select 0;\
_dir = _element select 1;\
_fac = "Land_budova2_ruins" createVehicleLocal _pos;\
_fac setDir _dir
#define __facset2 _pos = _element select 0;\
_dir = _element select 1;\
_fac = "Land_vez_ruins" createVehicleLocal _pos;\
_fac setDir _dir
	if (__XJIPGetVar(GVAR(jet_serviceH)) && {!__XJIPGetVar(GVAR(jet_s_reb))}) then {
		_element = GVAR(aircraft_facs) select 0;
		switch (true) do {
			case (__COVer): {__facset};
			case (__OAVer): {__facset2};
		};
	};
	if (__XJIPGetVar(GVAR(chopper_serviceH)) && {!__XJIPGetVar(GVAR(chopper_s_reb))}) then {
		_element = GVAR(aircraft_facs) select 1;
		switch (true) do {
			case (__COVer): {__facset};
			case (__OAVer): {__facset2};
		};
	};
	if (__XJIPGetVar(GVAR(wreck_repairH)) && {!__XJIPGetVar(GVAR(wreck_s_reb))}) then {
		_element = GVAR(aircraft_facs) select 2;
		switch (true) do {
			case (__COVer): {__facset};
			case (__OAVer): {__facset2};
		};
	};
};
#endif

if (count GVAR(only_pilots_can_fly) > 0) then {
	if !(GVAR(string_player) in GVAR(only_pilots_can_fly)) then {
		execFSM "fsms\HandleAircraft.fsm";
	};
};

if (GVAR(WithJumpFlags) == 0) then {GVAR(ParaAtBase) = 1};

_tactionar = [(localize "STR_DOM_MISSIONSTRING_533") call FUNC(GreyText),"x_client\x_teleport.sqf"];
#ifndef __TT__
if (GVAR(WithMHQTeleport) == 0) then {
	GVAR(FLAG_BASE) addAction _tactionar;
};
if (GVAR(with_ai) || (GVAR(ParaAtBase) == 0)) then {
	GVAR(FLAG_BASE) addaction [(localize "STR_DOM_MISSIONSTRING_296") call FUNC(GreyText),"AAHALO\x_paraj.sqf"];
};
#else
if (GVAR(WithMHQTeleport) == 0) then {
	(if (GVAR(own_side) == "WEST") then {GVAR(WFLAG_BASE)} else {GVAR(EFLAG_BASE)}) addAction _tactionar;
};
#endif

if (GVAR(ParaAtBase) == 1) then {
	_s = QGVAR(Teleporter);
	_sn = (localize "STR_DOM_MISSIONSTRING_534");
#ifndef __TT__
	_s setMarkerTextLocal _sn;
#else
	if (GVAR(own_side) == "WEST") then {
		_s setMarkerTextLocal _sn;
	} else {
		QGVAR(teleporter_1) setMarkerTextLocal _sn;
	};
#endif
};

#ifdef __ACE__
if !(__TTVer) then {
	{
		_element = _x;
		_box = (_element select 0) createVehicleLocal (_element select 1);
		_box setDir (_element select 2);
		_box setPos (_element select 1);
		player reveal _box;
		[_box, _element select 1, _element select 2, _element select 0] spawn {
			private ["_box","_boxname","_pos","_dir"];
			PARAMS_4(_box,_pos,_dir,_boxname);
			while {true} do {
				sleep 1500 + random 500;
				if (!isNull _box) then {deleteVehicle _box};
				_box = _boxname createVehicleLocal _pos;
				_box setDir _dir;
				_box setPos _pos;
				player reveal _box;
			};
		};
	} forEach GVAR(ace_boxes);
} else {
	_element = GVAR(ace_boxes) select (switch (GVAR(player_side)) do {case east: {1};case west: {0};});
	_box = (_element select 0) createVehicleLocal (_element select 1);
	_box setDir (_element select 2);
	_box setPos (_element select 1);
	player reveal _box;
	[_box, _element select 1, _element select 2, _element select 0] spawn {
		private ["_box","_boxname","_pos","_dir"];
		PARAMS_4(_box,_pos,_dir,_boxname);
		while {true} do {
			sleep 1500 + random 500;
			if (!isNull _box) then {deleteVehicle _box};
			_box = _boxname createVehicleLocal _pos;
			_box setDir _dir;
			_box setPos _pos;
			player reveal _box;
		};
	};
};
GVAR(ace_boxes) = nil;
GVAR(pos_ace_boxes) = nil;
#endif

[GVAR(AMMOLOAD)] execFSM "fsms\AmmoLoad.fsm";
#ifdef __TT__
[GVAR(AMMOLOAD2)] execFSM "fsms\AmmoLoad.fsm";
#endif

if (!GVAR(with_ranked)) then {
	if (GVAR(AutoKickTime) > 0 && GVAR(MissionType) != 2) then {execFSM "fsms\AutoKick.fsm"};
} else {
	execVM "x_client\x_playerveccheck.sqf";
#ifndef __ACE__
	player addEventHandler ["handleHeal", FUNC(HandleHeal)];
#else
	if (GVAR(string_player) in GVAR(is_medic)) then {execVM "x_client\x_mediccheck.sqf"};
#endif
	execVM "x_client\x_playervectrans.sqf";
};

if (GVAR(with_ai) || {GVAR(with_ai_features) == 0}) then {
	GVAR(heli_taxi_available) = true;
	_trigger = createTrigger ["EmptyDetector", _pos];
	_trigger setTriggerText (localize "STR_DOM_MISSIONSTRING_535");
	_trigger setTriggerActivation ["HOTEL", "PRESENT", true];
	_trigger setTriggerStatements ["this", "0 = [] execVM 'x_client\x_airtaxi.sqf'",""];
};

GVAR(vec_end_time) = -1;

if (GVAR(WithRepStations) == 0) then {execFSM "fsms\RepStation.fsm"};

if (isMultiplayer) then {
	0 spawn {
		sleep (0.5 + random 2);
		[QGVAR(p_varn), [getPlayerUID player,GVAR(string_player),GVAR(player_side)]] call FUNC(NetCallEventCTS);
	};
};

#ifdef __TT__
	if (GVAR(player_side) == east) then {
		QGVAR(arti_target) setMarkerAlphaLocal 0;
		QGVAR(arti_target2) setMarkerTextLocal (localize "STR_DOM_MISSIONSTRING_536");
	} else {
		QGVAR(arti_target2) setMarkerAlphaLocal 0;
		QGVAR(arti_target) setMarkerTextLocal (localize "STR_DOM_MISSIONSTRING_536");
	};
#endif

#ifndef __TOH__
// brrr, sqs
[] exec "\ca\modules\Clouds\data\scripts\BIS_CloudSystem.sqs";
#endif

if (GVAR(LimitedWeapons)) then {
	GVAR(poss_weapons) = [];
	for "_i" from 0 to (count GVAR(limited_weapons_ar) - 2) do {
		_ar = GVAR(limited_weapons_ar) select _i;
		if (GVAR(string_player) in (_ar select 0)) exitWith {GVAR(poss_weapons) =+ _ar select 1};
	};
	if (count GVAR(poss_weapons) == 0) then {GVAR(poss_weapons) =+ (GVAR(limited_weapons_ar) select (count GVAR(limited_weapons_ar) - 1)) select 1};
	execFSM "fsms\LimitWeapons.fsm";
	GVAR(limited_weapons_ar) = nil;
};

execVM "x_msg\x_playernamehud.sqf";

if (GVAR(MissionType) != 2) then {
	execFSM "fsms\CampDialog.fsm";
};

if (GVAR(with_ai)) then {
	0 spawn {
		while {true} do {
			waitUntil {sleep 0.272;alive player};
			if (player != leader (group player) && !__pGetVar(xr_pluncon)) then {
				if (count GVAR(current_ai_units) > 0) then {
					GVAR(current_ai_units) = [];
					GVAR(current_ai_num) = 0;
				};
			};
			if (__pGetVar(xr_pluncon)) then {
				waitUntil {sleep 0.332;!__pGetVar(xr_pluncon) || !alive player};
			};
			sleep 1.212;
		};
	};
};

execFSM "fsms\IsAdmin.fsm";

_primw = primaryWeapon _p;
if (_primw != "") then {
	_p selectWeapon _primw;
	_muzzles = getArray(configFile >>"cfgWeapons" >> _primw >> "muzzles");
	_p selectWeapon (_muzzles select 0);
};

#ifndef __TT__
if (GVAR(MissionType) != 2) then {
	_sb = __XJIPGetVar(GVAR(searchbody));
	if (!isNull _sb) then {
		if (isNil {GV(_sb,GVAR(search_body))}) then {_sb setVariable [QGVAR(search_id), _sb addAction [(localize "STR_DOM_MISSIONSTRING_518"), "x_client\x_searchbody.sqf"]]};
	};
};
#endif

player addEventHandler ["fired", FUNC(ParaExploitHandler)];

#ifdef __ACE__
if ("ACE_Earplugs" in items player) then {
	__pSetVar [QGVAR(earwear), true];
} else {
	__pSetVar [QGVAR(earwear), false];
};
0 spawn {
	while {true} do {
		if (alive player) then {
			if (!__pGetVar(GVAR(earwear))) then {
				if ("ACE_Earplugs" in items player || __pGetVar(ACE_EarWear)) then {
					__pSetVar [QGVAR(earwear), true];
				};
			} else {
				if (__pGetVar(GVAR(earwear))) then {
					if (!("ACE_Earplugs" in items player) && !__pGetVar(ACE_EarWear)) then {
						__pSetVar [QGVAR(earwear), false];
					};
				};
			};
		};
		sleep 0.5;
	};
};
#endif

if (isNil QGVAR(with_carrier)) then {
	__pSetVar [QGVAR(p_f_b), 0];
	
	FUNC(KickPlayerBaseFired) = {
        private "_num";
        if !(serverCommandAvailable "#shutdown") then {
			if (player in (list GVAR(player_base_trig))) then {
				private "_ta";
				_ta = _this select 4;
				if (_ta isKindOf "TimeBombCore" || _ta == "ACE_PipebombExplosion") then {
					if (count _this > 6) then {
						deleteVehicle (_this select 6);
					};
					if (GVAR(kick_base_satchel) == 0) then {
						[QGVAR(p_f_b_k), [player, GVAR(name_pl),1]] call FUNC(NetCallEventCTS);
					} else {
						[QGVAR(p_bs), [player, GVAR(name_pl),1]] call FUNC(NetCallEventCTS);
					};
				} else {
					if (!GVAR(there_are_enemies_atbase) && {!GVAR(enemies_near_base)}) then {
						if !(getText(configFile >> "CfgAmmo" >> _ta >> "simulation") in ["shotSmoke", "shotIlluminating", "shotNVGMarker", "shotCM"]) then {
							_num = __pGetVar(GVAR(p_f_b));
							__INC(_num);
							__pSetVar [QGVAR(p_f_b), _num];
							if !(player in (list GVAR(player_base_trig2))) then {
								if (GVAR(player_kick_shootingbase) != 1000) then {
									if (_num >= GVAR(player_kick_shootingbase)) then {
										if (isNil {__pGetVar(GVAR(pfbk_announced))}) then {
											[QGVAR(p_f_b_k), [player, GVAR(name_pl),0]] call FUNC(NetCallEventCTS);
											__pSetVar [QGVAR(pfbk_announced), true];
										};
									} else {
										hint (localize "STR_DOM_MISSIONSTRING_537");
									};
								} else {
									if (_num >= GVAR(player_kick_shootingbase)) then {
										[QGVAR(p_bs), [player, GVAR(name_pl),0]] call FUNC(NetCallEventCTS);
									};
								};
							};
						};
					};
				};
			} else {
				__pSetVar [QGVAR(p_f_b), 0];
			};
		};
	};

#ifndef __TT__
	GVAR(player_base_trig) = createTrigger["EmptyDetector" ,GVAR(base_array) select 0];
	GVAR(player_base_trig) setTriggerArea [GVAR(base_array) select 1, GVAR(base_array) select 2, GVAR(base_array) select 3, true];
#else
	_dbase_a = if (GVAR(player_side) == west) then {GVAR(base_array) select 0} else {GVAR(base_array) select 1};
	GVAR(player_base_trig) = createTrigger["EmptyDetector" ,_dbase_a select 0];
	GVAR(player_base_trig) setTriggerArea [_dbase_a select 1, _dbase_a select 2, _dbase_a select 3, true];
#endif
	GVAR(player_base_trig) setTriggerActivation [GVAR(own_side_trigger), "PRESENT", true];
	GVAR(player_base_trig) setTriggerStatements["this", "", ""];

#ifndef __TT__
	GVAR(player_base_trig2) = createTrigger["EmptyDetector" ,position GVAR(FLAG_BASE)];
#else
	_dbase_a = if (GVAR(player_side) == west) then {position GVAR(WFLAG_BASE)} else {position GVAR(EFLAG_BASE)};
	GVAR(player_base_trig2) = createTrigger["EmptyDetector" ,_dbase_a];
#endif
	GVAR(player_base_trig2) setTriggerArea [25, 25, 0, false];
	GVAR(player_base_trig2) setTriggerActivation [GVAR(own_side_trigger), "PRESENT", true];
	GVAR(player_base_trig2) setTriggerStatements["this", "", ""];
	
	player addEventHandler ["fired", FUNC(KickPlayerBaseFired)];
};

if (GVAR(no_3rd_person) == 0) then {
	execFSM "fsms\3rdperson.fsm";
};

GVAR(msg_hud_array) = [];
FUNC(AddHudMsg) = {
	GVAR(msg_hud_array) set [count GVAR(msg_hud_array), _this];
};

GVAR(last_hud_msgs) = [];
FUNC(HudDispMsgEngine) = {
	while {true} do {
		waitUntil {count GVAR(msg_hud_array) > 0 && alive player && !GVAR(msg_hud_shown) && !__pGetVar(xr_pluncon)};
		[GVAR(msg_hud_array) select 0] spawn FUNC(HudDispMsg);
		GVAR(last_hud_msgs) set [count GVAR(last_hud_msgs), GVAR(msg_hud_array) select 0];
		if (count GVAR(last_hud_msgs) > 20) then {
			GVAR(last_hud_msgs) set [0,-1];
			GVAR(last_hud_msgs) = GVAR(last_hud_msgs) - [-1];
		};
		GVAR(msg_hud_array) set [0,-1];
		GVAR(msg_hud_array) = GVAR(msg_hud_array) - [-1];
	};
};

0 spawn FUNC(HudDispMsgEngine);

GVAR(msg_hud_shown) = false;
FUNC(HudDispMsg) = {
	// TODO: Length should depend on message size
	private ["_msg", "_hud", "_control", "_cpos", "_control2", "_cpos2", "_endtime"];
	PARAMS_1(_msg);
	if (GVAR(msg_hud_shown)) exitWith {};
	GVAR(msg_hud_shown) = true;
	disableSerialization;
	89643 cutRsc [QGVAR(message_hud),"PLAIN"];
	_hud = __uiGetVar(DMESSAGE_HUD);
	_control = _hud displayCtrl 1000;
	_cpos = ctrlPosition _control;
	_control ctrlSetPosition [_cpos select 0, SafeZoneY + SafeZoneH - 0.07, _cpos select 2, _cpos select 3];
	_control2 = _hud displayCtrl 1001;
	_control2 ctrlSetText _msg;
	_cpos2 = ctrlPosition _control2;
	_control2 ctrlSetPosition [_cpos2 select 0, SafeZoneY + SafeZoneH - 0.068, _cpos2 select 2, _cpos2 select 3];
	_control ctrlCommit 0.5;
	_control2 ctrlCommit 0.5;
	_endtime = time + 19;
	waitUntil {time > _endtime || !alive player || __pGetVar(xr_pluncon)};
	_control ctrlSetPosition _cpos;
	_control2 ctrlSetPosition _cpos2;
	_control ctrlCommit 0.5;
	_control2 ctrlCommit 0.5;
	GVAR(msg_hud_shown) = false;
};

__ccppfln(x_client\x_marker.sqf);

if (GVAR(vechud_on) == 0) then {execVM "x_client\x_vec_hud.sqf"};

if (GVAR(WithChopHud)) then {execVM "x_client\x_chop_hud.sqf"};

__ccppfln(x_client\x_playerammobox.sqf);

0 spawn {
	waitUntil {sleep 0.123;!isNil {__XJIPGetVar(GVAR(overcast))}};
	GVAR(lastovercast) = __XJIPGetVar(GVAR(overcast));
	0 setOvercast GVAR(lastovercast);
	if (GVAR(weather) == 0 && GVAR(FastTime) == 0) then {
		execFSM "fsms\WeatherClient.fsm";
		if (GVAR(WithWinterWeather) == 0) then {execVM "scripts\weather_winter.sqf"};
	} else {
		if (GVAR(FastTime) > 0) then {GVAR(weather) = 1};
	};
};

if (GVAR(without_vec_ti) == 0) then {
	0 spawn {
		while {true} do {
			waitUntil {sleep 0.412;alive player};
			waitUntil {sleep 0.512;vehicle player != player};
			(vehicle player) disableTIEquipment true;
			waitUntil {sleep 0.489;vehicle player == player};
		};
	};
};

#ifndef __ACE__
if (!isClass (configFile >> "CfgPatches" >> "ace_main")) then {
	GVAR(mag_check_open) = false;
	__pSetVar [QGVAR(lastgdfcheck), -1];
	FUNC(KeyDownGDF) = {
		private "_ret";
		_ret = false;
		if (_this select 1 == 34 && (_this select 2)) then {
			if (!alive player) exitWith {};
			if (__pGetVar(xr_pluncon)) exitWith {};
			if (time - __pGetVar(GVAR(lastgdfcheck)) < 1) exitWith {_ret = true};
			if (GVAR(mag_check_open)) exitWith {_ret = true};
			GVAR(mag_check_open) = true;
			135923 cutRsc ["d_RscGearFast","PLAIN DOWN"];
			__pSetVar [QGVAR(lastgdfcheck), time];
			_ret = true;
		};
		_ret
	};

	(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call d_fnc_KeyDownGDF"];
};

GVAR(rscCrewTextShownTimeEnd) = -1;
FUNC(MouseWheelRec) = {
	private ["_ct", "_role", "_rpic", "_t", "_ctrl", "_dospawn", "_crewok", "_sidepp"];
	if (!alive player || __pGetVar(xr_pluncon)) exitWith {false};
	_ct = if (vehicle player == player) then {
		cursorTarget
	} else {
		vehicle player
	};
	if (isNull _ct) exitWith {false};
	if (!alive _ct) exitWith {false};
	if (_ct distance player > 20) exitWith {false};
	if (!(_ct isKindOf "Car") && {!(_ct isKindOf "Tank") && !(_ct isKindOf "Air")}) exitWith {false};
	if (_ct isKindOf "ParachuteBase") exitWith {false};
	if (getNumber(configFile >> "CfgVehicles" >> typeOf _ct >> "isBicycle") == 1) exitWith {false};
	if ((_ct call FUNC(GetAliveCrew)) == 0) exitWith {false};
	// TODO: Whenever countFriendly will get fixed so that it works with vehicle crew arrays too then change again
	// if (player countFriendly (crew _ct) == 0) exitWith {false};
	_sidepp = side (group player);
	_crewok = false;
	{
		if (alive _x && _sidepp getFriend side (group _x) >= 0.6) exitWith {
			_crewok = true;
		};
	} forEach (crew _ct);
	if (!_crewok) exitWith {false};
	
	_ar_P = [];
	_ar_AI = [];

	{
		if (alive _x) then {
			if (isPlayer _x) then {
				_ar_P set [count _ar_P, _x];
			} else {
				_ar_AI set [count _ar_AI, _x];
			};
		};
		sideFriendly
	} foreach (crew _ct);

	_s_p = "";
	if (count _ar_P > 0) then {
		_s_p = "<t align='left'>";
		{
			_role = assignedVehicleRole _x;
			if (count _role > 0) then {
				private "_rpic";
				if (commander _ct == _x) then {
					_rpic = __UI_Path(i_commander_ca.paa);
				} else {
					if (driver _ct == _x) then {
						_rpic = __UI_Path(i_driver_ca.paa);
					} else {
						_rpic = switch (toUpper (_role select 0)) do {
							case "TURRET": {__UI_Path(i_gunner_ca.paa)};
							default {__UI_Path(i_cargo_ca.paa)};
						};
					};
				};
				_s_p = _s_p + "<img image='" + _rpic + "'/> " + (name _x) + "<br/>";
			};
		} foreach _ar_P;
		_s_p = _s_p + "</t>";
	};

	_s_ai = "";
	if (count _ar_AI > 0) then {
		_s_ai = "<t align='left'>";
		{
			_role = assignedVehicleRole _x;
			if (count _role > 0) then {
				private "_rpic";
				if (commander _ct == _x) then {
					_rpic = __UI_Path(i_commander_ca.paa);
				} else {
					if (driver _ct == _x) then {
						_rpic = __UI_Path(i_driver_ca.paa);
					} else {
						_rpic = switch (toUpper (_role select 0)) do {
							case "DRIVER": {__UI_Path(i_driver_ca.paa)};
							case "TURRET": {__UI_Path(i_gunner_ca.paa)};
							default {__UI_Path(i_cargo_ca.paa)};
						};
					};
				};
				_s_ai = _s_ai + "<img image='" + _rpic + "'/> " + (name _x) + " (AI)" + "<br/>";
			};
		} foreach _ar_AI;
		_s_ai = _s_ai + "</t>";
	};

	_t = "<t size='0.6'><t align='left'>" + (localize "STR_DOM_MISSIONSTRING_538") + " " + ([typeOf _ct, 0] call FUNC(GetDisplayName)) + ":</t>" + "<br/>" + _s_p + _s_ai + "</t>";
	121282 cutRsc [QGVAR(rscCrewText), "PLAIN"];
	_ctrl = __uiGetVar(GVAR(rscCrewText)) displayCtrl 9999;
	_ctrl ctrlSetStructuredText parseText _t;
	_ctrl ctrlCommit 0;
	_dospawn = GVAR(rscCrewTextShownTimeEnd) == -1;
	GVAR(rscCrewTextShownTimeEnd) = time + 5;
	if (_dospawn) then {
		0 spawn {
			private "_vecp";
			_vecp = vehicle player;
			waitUntil {sleep 0.221;time > GVAR(rscCrewTextShownTimeEnd) || !alive player || __pGetVar(xr_pluncon) || vehicle player != _vecp};
			121282 cutRsc ["Default", "PLAIN"];
			GVAR(rscCrewTextShownTimeEnd) = -1;
		};
	};
};

(findDisplay 46) displayAddEventHandler ["MouseZChanged", "_this call d_fnc_MouseWheelRec"];
#endif

if (GVAR(MHQDisableNearMT) != 0) then {
	0 spawn {
		private ["_vec", "_vt", "_ti"];
		while {true} do {
			waitUntil {sleep 0.226;alive player};
			waitUntil {sleep 0.226;vehicle player != player};
			_vec = vehicle player;
			_vt = GV(_vec,GVAR(vec_type));
			if (isNil "_vt") then {_vt = ""};
			if (_vt == "MHQ") then {
				while {_vec == vehicle player} do {
					if (fuel _vec != 0) then {
						_ti = __XJIPGetVar(GVAR(current_target_index));
						if (_ti != -1) then {
							_current_target_pos = (GVAR(target_names) select _ti) select 0;
							if (_vec distance _current_target_pos <= GVAR(MHQDisableNearMT)) then {
								_vec setVariable [QGVAR(vecfuelmhq), fuel _vec, true];
								_vec setFuel 0;
								[QGVAR(mqhtn), GV(_vec,GVAR(vec_name))] call FUNC(NetCallEventToClients);
								[format [(localize "STR_DOM_MISSIONSTRING_520"), GVAR(MHQDisableNearMT), _this], "HQ"] call FUNC(HintChatMsg);
							};
						};
					};
					sleep 0.531;
				};
			} else {
				waitUntil {sleep 0.226;vehicle player == player};
			};
		};
	};
};

#ifndef __ACE__
if (GVAR(WithRevive) == 0) then {
	__ccppfln(x_revive.sqf);
};
#else
if (GVAR(WithRevive) == 0 && GVAR(WithWounds) == 1) then {
	__ccppfln(x_revive.sqf);
};
#endif

if (GVAR(dom4)) then {
	private "_targets_list";
	_targets_list = __XJIPGetVar(GVAR(targets_list));
	_cur_targets = __XJIPGetVar(GVAR(current_targets));

	//diag_log "################### client ###################";
	//diag_log _targets_list;

	_curlinenum = 0;
	_curpos = [];
	_colfunc = {
		private "_dtar";
		_dtar = _this;
		if ((direction _dtar < 90) || {(direction _dtar > 270)}) then {
			if !(_x in [_cur_targets select 0,_cur_targets select 1]) then {
				"ColorRedFaded25"
			} else {
				"ColorRedFaded75"
			}
		} else {
			if !(_x in [_cur_targets select 0,_cur_targets select 1]) then {
				"ColorBlueFaded25"
			} else {
				"ColorBlueFaded75"
			}
		}
	};
	{
		_mname = format [QGVAR(target_%1), _x];
		_dtar = __getMNsVar2(_mname);
		_pos = getPosASL _dtar;
		_pos set [2,0];
			
		if (_x in [_cur_targets select 0,_cur_targets select 1]) then {
			_ctar = GV2(GVAR(targets_store),_mname);
			
			if ((direction _dtar < 90) || {(direction _dtar > 270)}) then {
				if (GVAR(side_player) == west) then {
					GVAR(current_attack_target) = _mname;
					GVAR(current_attack_idx) = _x;
					GVAR(current_attack_pos) = _pos;
					GVAR(current_attack_targetname) = _ctar select 0;
				} else {
					GVAR(current_defend_target) = _mname;
					GVAR(current_defend_idx) = _x;
					GVAR(current_defend_pos) = _pos;
					GVAR(current_defend_targetname) = _ctar select 0;
				};
			} else {
				if (GVAR(side_player) == west) then {
					GVAR(current_defend_target) = _mname;
					GVAR(current_defend_idx) = _x;
					GVAR(current_defend_pos) = _pos;
					GVAR(current_defend_targetname) = _ctar select 0;
				} else {
					GVAR(current_attack_target) = _mname;
					GVAR(current_attack_idx) = _x;
					GVAR(current_attack_pos) = _pos;
					GVAR(current_attack_targetname) = _ctar select 0;
				};
			};
		};
		
		[_mname, _pos, "ELLIPSE", _dtar call _colfunc,[300,300]] call FUNC(CreateMarkerLocal);
		if (count _curpos > 0) then {
			_curlinenum = [_curpos, _pos, _curlinenum] call FUNC(linemaker);
		};
		_curpos = _pos;
	} forEach _targets_list;

	GVAR(task10000) setTaskState "Succeeded";

	GVAR(task1) = player createSimpleTask ["obj1"];
	GVAR(task1) setSimpleTaskDescription [format ["Seize %1...", GVAR(current_attack_targetname)], format ["Main Target: Seize %1", GVAR(current_attack_targetname)],format ["Main Target: Seize %1", GVAR(current_attack_targetname)]];
	GVAR(task1) setTaskState "Created";
	GVAR(task1) setSimpleTaskDestination GVAR(current_attack_pos);

	GVAR(task2) = player createSimpleTask ["obj2"];
	GVAR(task2) setSimpleTaskDescription [format ["Defend %1...", GVAR(current_defend_targetname)], format ["Main Target: Defend %1", GVAR(current_defend_targetname)],format ["Main Target: Defend %1", GVAR(current_defend_targetname)]];
	GVAR(task2) setTaskState "Created";
	GVAR(task2) setSimpleTaskDestination GVAR(current_defend_pos);
};

__ccppfln(x_clientcustomcode.sqf);

if (isMultiplayer) then {execVM "x_client\x_intro.sqf"};

#ifdef __TOH__
GVAR(CurPIPVideoTarget) = objNull;

FUNC(setVideoPipTarget) = {
	if (GVAR(still_in_intro)) exitWith {};
	if (!isNil "KEGs_SPECTATINGON") exitWith {};
	private ["_poscam"];
	GVAR(CurPIPVideoTarget) = __XJIPGetVar(GVAR(CurPIPVideoTarget));
	if (!isNil QGVAR(PIP_screenCam)) then {
		detach GVAR(PIP_screenCam);
	};
	_poscam = (vehicle GVAR(CurPIPVideoTarget)) modelToWorld [0, -5, 2];
	if (isNil QGVAR(PIP_screenCam)) then {
		GVAR(PIP_screenCam) = "camera" camCreate _poscam;
		GVAR(PIP_screenCam) camPrepareFov 0.100;
		GVAR(PIP_screenCam) cameraEffect ["INTERNAL", "BACK", QGVAR(rendertarget0)];
		GVAR(video_wall1) setObjectTexture [0, "#(argb,256,256,1)r2t(d_rendertarget0,1.0)"];
		QGVAR(rendertarget0) setPiPEffect [0];
	} else {
		detach GVAR(PIP_screenCam);
		GVAR(PIP_screenCam) camSetPos _poscam;
	};
	GVAR(PIP_screenCam) camPrepareTarget (vehicle GVAR(CurPIPVideoTarget));
	GVAR(PIP_screenCam) camCommitPrepared 0;
	GVAR(PIP_screenCam) attachTo [vehicle GVAR(CurPIPVideoTarget), [0,-5,2]];
	GVAR(pipt_isinvec) = vehicle GVAR(CurPIPVideoTarget) != GVAR(CurPIPVideoTarget);
};

0 spawn {
	waitUntil {sleep 0.312;!GVAR(still_in_intro)};
	waitUntil {sleep 0.312; !isNil {__XJIPGetVar(GVAR(CurPIPVideoTarget))}};
	waitUntil {sleep 0.312; !isNull __XJIPGetVar(GVAR(CurPIPVideoTarget))};
	while {true} do {
		waitUntil {sleep 0.123;isNil "KEGs_SPECTATINGON"};
		if ((GVAR(pipt_isinvec) && (vehicle GVAR(CurPIPVideoTarget) == GVAR(CurPIPVideoTarget))) || (!GVAR(pipt_isinvec) && (vehicle GVAR(CurPIPVideoTarget) != GVAR(CurPIPVideoTarget)))) then {
			GVAR(pipt_isinvec) = !GVAR(pipt_isinvec);
			if (!isNil QGVAR(PIP_screenCam)) then {
				detach GVAR(PIP_screenCam);
			};
			GVAR(PIP_screenCam) camPrepareTarget (vehicle GVAR(CurPIPVideoTarget));
			GVAR(PIP_screenCam) camCommitPrepared 0;
			GVAR(PIP_screenCam) attachTo [vehicle GVAR(CurPIPVideoTarget), [0,-5,2]];
		};
		sleep 1.211;
	};
};

if (!isNil {__XJIPGetVar(GVAR(CurPIPVideoTarget))}) then {
	[] spawn {
		waitUntil {sleep 0.312;!GVAR(still_in_intro)};
		if (!isNull __XJIPGetVar(GVAR(CurPIPVideoTarget))) then {
			call FUNC(setVideoPipTarget);
		};
	}
};
#endif

GVAR(commandingMenuIniting) = false;
["dom_command_menu", {
	if (!isNil QGVAR(commandingMenuCode)) then {
		if (alive player && !GV(player,xr_pluncon)) then {
			if (commandingMenu == "") then {
				call GVAR(commandingMenuCode);
				GVAR(commandingMenuCode) = nil;
				GVAR(DomCommandingMenuBlocked) = false;
			};
		} else {
			GVAR(commandingMenuCode) = nil;
			GVAR(DomCommandingMenuBlocked) = false;
			GVAR(commandingMenuIniting) = false;
		};
	}
}, 0.1] call FUNC(addPerFrame);

FUNC(DomCommandingMenuExec) = {
	if (!alive player) exitWith {showCommandingMenu ""};
	if (GV(player,xr_pluncon)) exitWith {showCommandingMenu ""};
	if (__pGetVar(GVAR(isinaction))) exitWith {showCommandingMenu ""};
	GVAR(commandingMenuIniting) = true;
	showCommandingMenu "";
	switch (_this) do {
		case 0: {GVAR(commandingMenuCode) = {call compile preprocessFileLineNumbers "x_client\x_showstatus.sqf"}};
		case 1: {
			GVAR(commandingMenuCode) = {
				_artar = switch (GVAR(player_can_call_arti)) do {
					case 1: {[1, GVAR(AriTarget)]};
					case 2: {[2, GVAR(AriTarget2)]};
				};
				_artar execVM "x_client\x_artillery.sqf";
			};
		};
		case 2: {GVAR(commandingMenuCode) = {execVM "x_client\x_calldrop.sqf"}};
		case 3: {GVAR(commandingMenuCode) = {execVM "x_client\x_trench.sqf"}};
		case 4: {GVAR(commandingMenuCode) = {execVM "x_client\x_mgnest.sqf"}};
		case 5: {GVAR(commandingMenuCode) = {execVM "x_client\x_mash.sqf"}};
		case 6: {GVAR(commandingMenuCode) = {execVM "x_client\x_farp.sqf"}};
		case 7: {GVAR(commandingMenuCode) = {call compile preprocessFileLineNumbers "x_client\x_adminspectate.sqf"}};
	};
	GVAR(DomCommandingMenuBlocked) = false;
};

FUNC(CreateDomUserMenu) = {
	_start_key = 1;
	_fnc_inc_num = {
		__INC(_start_key);
		_start_key
	};
	
	GVAR(DomUserMenu) = [
		["Domination", false],
		[localize "STR_DOM_MISSIONSTRING_304", [call _fnc_inc_num], "", -5, [["expression", "0 call d_fnc_DomCommandingMenuExec"]], "1", "1"],
		["-", [0], "", -1, [["expression", ""]], "1", "1"]
	];
	
	#ifndef __ACE__
	if (GVAR(player_can_call_arti) > 0 && {!((vehicle player) isKindOf "BIS_Steerable_Parachute") && !((vehicle player) isKindOf "ParachuteBase")}) then {
		GVAR(DomUserMenu) set [count GVAR(DomUserMenu),
			[localize "STR_DOM_MISSIONSTRING_153", [call _fnc_inc_num], "", -5, [["expression", "1 call d_fnc_DomCommandingMenuExec"]], "1", "1"]
		];
	};
	
	GVAR(DomUserMenu) set [count GVAR(DomUserMenu), ["-", [0], "", -1, [["expression", ""]], "1", "1"]];
	
	if (GVAR(player_can_call_drop) > 0 && {!((vehicle player) isKindOf "BIS_Steerable_Parachute") && !((vehicle player) isKindOf "ParachuteBase")}) then {
		GVAR(DomUserMenu) set [count GVAR(DomUserMenu),
			[localize "STR_DOM_MISSIONSTRING_230", [call _fnc_inc_num], "", -5, [["expression", "2 call d_fnc_DomCommandingMenuExec"]], "1", "1"]
		];
	};
	#endif
	
	GVAR(DomUserMenu) set [count GVAR(DomUserMenu), ["-", [0], "", -1, [["expression", ""]], "1", "1"]];
	
	if (GVAR(player_can_build_trench) && {vehicle player == player && isNull __pGetVar(GVAR(trench))}) then {
		GVAR(DomUserMenu) set [count GVAR(DomUserMenu),
			[localize "STR_DOM_MISSIONSTRING_303", [call _fnc_inc_num], "", -5, [["expression", "3 call d_fnc_DomCommandingMenuExec"]], "1", "1"]
		];
	};
	
	GVAR(DomUserMenu) set [count GVAR(DomUserMenu), ["-", [0], "", -1, [["expression", ""]], "1", "1"]];
	
	if (GVAR(player_can_build_mgnest) && {vehicle player == player && count __pGetVar(GVAR(mgnest_pos)) == 0}) then {
		GVAR(DomUserMenu) set [count GVAR(DomUserMenu),
			[localize "STR_DOM_MISSIONSTRING_306", [call _fnc_inc_num], "", -5, [["expression", "4 call d_fnc_DomCommandingMenuExec"]], "1", "1"]
		];
	};
	
	if (GVAR(player_is_medic) && {vehicle player == player && count __pGetVar(GVAR(medtent)) == 0}) then {
		GVAR(DomUserMenu) set [count GVAR(DomUserMenu),
			[localize "STR_DOM_MISSIONSTRING_305", [call _fnc_inc_num], "", -5, [["expression", "5 call d_fnc_DomCommandingMenuExec"]], "1", "1"]
		];
	};
	
	if (GVAR(eng_can_repfuel) && {vehicle player == player && count __pGetVar(GVAR(farp_pos)) == 0}) then {
		GVAR(DomUserMenu) set [count GVAR(DomUserMenu),
			[localize "STR_DOM_MISSIONSTRING_307", [call _fnc_inc_num], "", -5, [["expression", "6 call d_fnc_DomCommandingMenuExec"]], "1", "1"]
		];
	};
	
	GVAR(DomUserMenu) set [count GVAR(DomUserMenu), ["-", [0], "", -1, [["expression", ""]], "1", "1"]];
	
	_hxhx = __pGetVar(GVAR(p_isadmin));
	if (isNil "_hxhx") then {_hxhx = false};
	if (_hxhx) then {
		GVAR(DomUserMenu) set [count GVAR(DomUserMenu),
			[localize "STR_DOM_MISSIONSTRING_1420", [call _fnc_inc_num], "", -5, [["expression", "7 call d_fnc_DomCommandingMenuExec"]], "1", "1"]
		];
	};
};

GVAR(DomCommandingMenuBlocked) = false;
FUNC(KeyDownCommandingMenu) = {
	private ["_type"];
	PARAMS_1(_type);
	if (dialog) exitWith {
		showCommandingMenu "";
	};
	if (_type == 0 && !GVAR(DomCommandingMenuBlocked) && !GVAR(commandingMenuIniting)) exitWith {
		GVAR(DomCommandingMenuBlocked) = true;
		if (commandingMenu != "#USER:d_DomUserMenu") then {
			call FUNC(CreateDomUserMenu);
			showCommandingMenu "#USER:d_DomUserMenu";
		};
	};
	if (_type == 1) then {
		GVAR(DomUserMenu) = [];
	};
	if (_type == 1 && GVAR(DomCommandingMenuBlocked) && !GVAR(commandingMenuIniting)) exitWith {
			GVAR(DomCommandingMenuBlocked) = false;
			if (commandingMenu == "#USER:d_DomUserMenu") then {
				showCommandingMenu "";
			};
		};
};

(findDisplay 46) displayAddEventHandler ["KeyDown", "if (_this select 1 in actionKeys 'TeamSwitch' && alive player && !(player getVariable 'xr_pluncon') && !(_this select 2) && !(_this select 3) && !(_this select 4)) then {[0, _this] call d_fnc_KeyDownCommandingMenu; true} else {false}"];
(findDisplay 46) displayAddEventHandler ["KeyUp", "if (_this select 1 in actionKeys 'TeamSwitch'&& !(_this select 2) && !(_this select 3) && !(_this select 4)) then {[1, _this] call d_fnc_KeyDownCommandingMenu; true} else {false}"];

if (isMultiplayer) then {
	execVM "x_client\x_respawnblock.sqf";
};

deleteVehicle GVAR(client_init_trig);

diag_log [diag_frameno, diag_ticktime, time, "Dom x_setupplayer.sqf processed"];
