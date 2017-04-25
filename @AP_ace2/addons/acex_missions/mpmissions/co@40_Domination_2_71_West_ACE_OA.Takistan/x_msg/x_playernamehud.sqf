// by Xeno
#define THIS_FILE "x_playernamehud.sqf"
#include "x_setup.sqf"
private "_xctrl";
if (!local player) exitwith {};

#define IDCPLAYER 5200

disableSerialization;

x_pm_received_ar = [];
x_pm_send_ar = [];
x_pm_add_ar = [];
x_player_name = name player;
x_pm_send_ar_update = false;

FUNC(XSendMsgSysMsg) = {
	private "_xctrl";
	disableSerialization;
	_xx_display = __uiGetVar(XD_MsgDialog);
	_xctrl = _xx_display displayCtrl 1010;
	if (ctrlText (_xx_display displayCtrl 1201) != "") then {
		if (x_player_name != ctrlText _xctrl) then {
			["x_msg_net", [ctrlText _xctrl,x_player_name,ctrlText (_xx_display displayCtrl 1201)]] call FUNC(NetCallEvent);
			(format [(localize "STR_DOM_MISSIONSTRING_879"), ctrlText _xctrl]) call FUNC(GlobalChat);
		} else {
			(localize "STR_DOM_MISSIONSTRING_880") call FUNC(GlobalChat);
		};
		_one_ele = [ctrlText _xctrl, ctrlText (_xx_display displayCtrl 1201), date];
		x_pm_send_ar = [x_pm_send_ar, [_one_ele], 0] call FUNC(arrayInsert);
		x_pm_send_ar_update = true;
	} else {
		(localize "STR_DOM_MISSIONSTRING_881") call FUNC(GlobalChat)
	};
};

[2, "x_msg_net", {if (x_player_name == _this select 0) then {x_pm_add_ar set [count x_pm_add_ar, [_this select 1, _this select 2, date]];playSound "IncomingChallenge2";(format [(localize "STR_DOM_MISSIONSTRING_882"), _this select 1] + (_this select 2)) call FUNC(AddHudMsg)}}] call FUNC(NetAddEvent);

if (isNil "d_blockspacebarscanning") then {GVAR(blockspacebarscanning) = 1};
if (GVAR(BlockSpacebarScanning) == 0) then {
	X_KeyboardHandlerKeyDown = {((_this select 1) == 57)};
	waitUntil {sleep 0.412;!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call X_KeyboardHandlerKeyDown"];
};

74193 cutrsc["PlayerNameHud","PLAIN"];

if (GVAR(show_playernames) == 0) exitWith {
	x_show_pname_hud = false;
	GVAR(show_player_namesx) = 0;
};

x_show_pname_hud = (GVAR(playernames_state) > 0);

GVAR(show_player_namesx) = GVAR(playernames_state);

GVAR(dist_pname_hud) = 100;

sleep 10;

#ifndef __TT__
waitUntil {sleep 0.232;!isNil QGVAR(player_entities)};
GVAR(phud_units) = GVAR(player_entities);
waitUntil {sleep 0.232;!isNil {GVAR(misc_store) getVariable (GVAR(player_entities) select ((count GVAR(player_entities)) - 1))}};
#else
waitUntil {sleep 0.232;!isNil QGVAR(entities_tt)};
GVAR(phud_units) = GVAR(entities_tt);
waitUntil {sleep 0.232;!isNil {GVAR(misc_store) getVariable (GVAR(entities_tt) select ((count GVAR(entities_tt)) - 1))}};
#endif
waitUntil {sleep 0.232;!isNil {GV(player,xr_pluncon)}};
waitUntil {sleep 0.232;!GVAR(still_in_intro)};

GVAR(phud_deleted) = false;
GVAR(pnhudgroupcolor) = [0.7,0.7,0,0.6];
GVAR(pnhudothercolor) = [0.72,0.72,0.72,0.6];
GVAR(pnhuddeadcolor) = [0,0,0,0];
FUNC(player_name_huddo) = {
	private ["_u", "_ua", "_index", "_control", "_ali", "_targetPos", "_position", "_vehu", "_tex", "_col", "_o", "_distu", "_do_del_u", "_pheight", "_eyepos_u"];
	disableSerialization;
	if (x_show_pname_hud && !visibleMap) then {
		GVAR(phud_deleted) = false;
		_pheight = switch (player call FUNC(getUnitStance)) do {
			case "prone": {0.2};
			case "kneel": {0.9};
			case "stand": {1.7};
			default {0.9};
		};
		{
			_u = __getMNsVar2(_x);
			if (!isNil "_u" && {!isNull _u}) then {
				_distu = (positionCameraToWorld [0,0,0]) distance _u;
				_do_del_u = false;
				if (_u != player && _distu <= GVAR(dist_pname_hud) && {alive player && alive _u}) then {
					_epp = eyePos player;
					_epu = eyePos _u;
					if (terrainIntersectASL [_epp, _epu]) exitWith {
						_do_del_u = true;
					};
					if (lineIntersects [_epp, _epu]) exitWith {
						_do_del_u = true;
					};
					_ua = GV2(GVAR(misc_store),_x);
					_index = _ua select 0;
					_control = __uiGetVar(X_PHUD) displayCtrl (IDCPLAYER + _index);
					if (isNil "_control") exitWith {};
					_ali = alive _u;
					_vehu = vehicle _u;
					
					_targetPos = ASLToATL (visiblePositionASL _u);
					_targetPos set [2 , (_targetPos select 2) + (if (_ali) then {2} else {1})];
					_position = worldToScreen _targetPos;

					if (count _position != 0 && {(_vehu == _u || (_vehu != _u && _u == driver _vehu))}) then {
						_control ctrlShow true;
						_control ctrlSetPosition _position;
						private "_tex";
						
						if (_distu <= 50) then {
							_tex = switch (GVAR(show_player_namesx)) do {
								case 1: {
									if (_ali) then {
										private "_unc";
										_unc = GV(_u,xr_pluncon);
										if (isNil "_unc") then {_unc = false};
										if (_unc) then {(localize "STR_DOM_MISSIONSTRING_883")} else {(name _u) + (if (getNumber (configFile >> "CfgVehicles" >> typeOf _u >> "attendant") == 1) then {(localize "STR_DOM_MISSIONSTRING_884")} else {""})}
									} else {(localize "STR_DOM_MISSIONSTRING_885")}
								};
								case 2: {_ua select 1};
								case 3: {str(9 - round(9 * damage _u))};
								default {(localize "STR_DOM_MISSIONSTRING_886")};
							};
							if (isNil "_tex") then {_tex = (localize "STR_DOM_MISSIONSTRING_886")};
							_scale = if (_distu == 0) then {
								1.2
							} else {
								(1.2 - ((_distu / 50) * .65)) max 0.6;
							};
							_control ctrlSetScale _scale;
						} else {
							_tex = "*";
							_control ctrlSetScale 0.4;
						};

						_control ctrlSetText _tex;
						_col = if (!_ali) then {
							GVAR(pnhuddeadcolor)
						} else {
							if (group _u == group player) then {GVAR(pnhudgroupcolor)} else {GVAR(pnhudothercolor)}
						};
						_control ctrlSetTextColor _col;
					} else {
						_control ctrlShow false;
					};
					_control ctrlCommit 0;
				} else {
					_do_del_u = true;
				};
				if (_do_del_u) then {
					_ua = GV2(GVAR(misc_store),_x);
					if (!isNil "_ua") then {
						_index = _ua select 0;
						_control = __uiGetVar(X_PHUD) displayCtrl (IDCPLAYER + _index);
						if (isNil "_control") exitWith {};
						_control ctrlShow false;
						_control ctrlCommit 0;
					};
				};
			} else {
				_ua = GV2(GVAR(misc_store),_x);
				if (!isNil "_ua") then {
					_index = _ua select 0;
					_control = __uiGetVar(X_PHUD) displayCtrl (IDCPLAYER + _index);
					if (isNil "_control") exitWith {};
					_control ctrlShow false;
					_control ctrlCommit 0;
				};
			};
		} foreach GVAR(phud_units);
	} else {
		if (!GVAR(phud_deleted)) then {
			GVAR(phud_deleted) = true;
			for "_o" from 5200 to 5239 do {
				_control = __uiGetVar(X_PHUD) displayCtrl _o;
				_control ctrlShow false;
				_control ctrlCommit 0;
			};
		};
	};
};

["player_hud", {call FUNC(player_name_huddo)},0] call FUNC(addPerFrame);