// by Xeno
// #define __DEBUG__
#define THIS_FILE "x_revive\xr_init.sqf"

#include "xr_macros.sqf"

if (!isNil QGVARXR(INIT)) exitWith {};
GVARXR(INIT) = false;

#define __unc #UNCONSCIOUS

#define __waitpl 0 spawn {waitUntil {!isNull player};GVARXR(INIT) = true}
if (!isDedicated) then {
	if (isNull player) then {
		__waitpl;
	} else {
		GVARXR(INIT) = true;
	};
};

if (GVARXR(with_marker)) then {
	//check markers
	if (isServer) then {
		0 spawn {
			private ["_mname", "_unit"];
			waitUntil {!isNil QGVARXR(uncon_m_units)};
			waitUntil {count GVARXR(uncon_m_units) > 0};
			while {true} do {
				{
					_mname = _x + __xrdead;
					_unit = __getMNsVar2(_x);
					if (isNull _unit) then {
						[QGVARXR(delml), _mname] call d_fnc_NetCallEvent;
						GVARXR(uncon_m_units) set [_forEachIndex, -1];
					} else {
						if !__GV(_unit,GVARXR(pluncon)) then {
							GVARXR(uncon_m_units) set [_forEachIndex, -1];
						};
					};
					sleep 0.01;
				} forEach GVARXR(uncon_m_units);
				GVARXR(uncon_m_units) = GVARXR(uncon_m_units) - [-1];
				sleep 0.542;
			};
		};
	};
};

if (isDedicated) exitWith {};

waitUntil {GVARXR(INIT)};
waitUntil {player == player};

__pSetVar [QGVARXR(lives), GVARXR(max_lives)];
__pSetVar [QGVARXR(num_death), 0];

__pSetVar [QGVARXR(is_dragging), false];

// 100 = died after live time over ,   1 = uncon, 0 = normal state
// 200 = map respawn
__pSetVar [QGVARXR(u_state), 0];

__pSetVar [QGVARXR(presptime), -1];

__pSetVar [QGVARXR(busyt), -1, true];

/*if (GVARXR(respawn_delay) <= 3) then {
	hint "Attention! Respawn delay in description.ext is too low or missing !!!!!!!!!!!!!!!";
};*/

#define __shots ["shotBullet","shotShell","shotRocket","shotMissile","shotTimeBomb","shotMine"]
#define __plsd1 player setDamage 1
#define __addmx _p addMagazine _x
#define __addwx _p addWeapon _x

GVARXR(slopeObj) = "Logic" createVehicleLocal [0,0,0];

__pSetVar [QGVARXR(pluncon), false, true];

GVARXR(blurr) = ppEffectCreate ["dynamicBlur", -12521];

GVARXR(pl_group) = group player;
GVARXR(side_pl) = if (!isNull GVARXR(pl_group)) then {side GVARXR(pl_group)} else {playerSide};

GVARXR(strpl) = str player;
GVARXR(strpldead) = GVARXR(strpl) + "_xr_dead";

__pSetVar [QGVARXR(pisinaction), false];
__pSetVar [QGVARXR(death_pos), []];
__pSetVar [QGVARXR(dragged), false, true];

__pSetVar [QGVARXR(isdead), false];

FUNCXR(resetVals) = {{__pSetVar [_x, 0]} forEach [QGVARXR(head_hit), QGVARXR(body), QGVARXR(legs), QGVARXR(hands), QGVARXR(overall)]};

call FUNCXR(resetVals);
FUNCXR(killedEH) = {
	__TRACE("killedEH start");
	if (__pGetVar(GVARXR(isdead))) exitWith {
		call FUNCXR(CheckRespawn);
		__pSetVar [QGVARXR(presptime), 4];
		setPlayerRespawnTime 4;
		__TRACE("killedEH respawn time 4");
	};
	private "_u_state";
	_u_state = __pGetVar(GVARXR(u_state));
	__TRACE_1("killedEH","_u_state");
	if (_u_state > 0) then {
		__pSetVar [QGVARXR(presptime), 4];
		setPlayerRespawnTime 4;
		if (_u_state in [100, 200]) then {
			GVARXR(stopspect) = true;
			private "_pdx";
			_pdx = __pGetVar(GVARXR(num_death));
			__INC(_pdx);
			__TRACE_1("killedEH","_pdx");
			__pSetVar [QGVARXR(num_death), _pdx];
			call FUNCXR(resetVals);
			__pSetVar [QGVARXR(u_state), 0];
		} else {
			if (_u_state == 1) then {
				call FUNCXR(CheckRespawn);
			};
		};
	} else {
		_exitit = false;
		if (GVARXR(max_lives) != -1) then {
			private "_lives";
			_lives = __pGetVar(GVARXR(lives));
			_lives = (_lives - 2) max -1;
			__TRACE_1("killedEH","_lives");
			__pSetVar [QGVARXR(lives), _lives];
			["d_crl", [getPlayerUID player, _lives]] call d_fnc_NetCallEventCTS;
			if (_lives == -1) then {
				call FUNCXR(CheckRespawn);
				__pSetVar [QGVARXR(presptime), 4];
				setPlayerRespawnTime 4;
				GVARXR(phd_invulnerable) = true;
				[true] spawn FUNCXR(park_player);
				_exitit = true;
				__pSetVar [QGVARXR(u_state), 0];
			};
		};
		__TRACE_1("killedEH","_exitit");
		if (_exitit) exitWith {};
		GVARXR(use_dom_opendlg) = true;
		__pSetVar [QGVARXR(presptime), 180];
		setPlayerRespawnTime 180; // punish players that simply do a respawn
		if (GVARXR(max_lives) != -1) then {
			titleText [(localize "STR_DOM_MISSIONSTRING_907"),"PLAIN", 1];
		} else {
			titleText [(localize "STR_DOM_MISSIONSTRING_908"),"PLAIN", 1];
		};
	};
	if (GVARXR(withweaponrespawn)) then {
		call FUNCXR(WeapRespawn1)
	};
};
player addEventHandler ["killed", FUNCXR(killedEH)];

player addEventHandler ["respawn", FUNCXR(respawneh)];

GVARXR(name_player) = name player;

player setVariable [QGVARXR(cutofftime), -1];
call FUNCXR(resetVals);
player removeAllEventHandlers QUOTE(handleDamage);
player addEventHandler [QUOTE(handleDamage), FUNCXR(ClientHD)];

__pSetVar [QGVARXR(healcutoff), -1];
player addEventHandler ["AnimDone", {if (alive (_this select 0)) then {if (damage (_this select 0) > 0 && {!((_this select 0) getVariable QGVARXR(pluncon))}) then {(_this select 1) call FUNCXR(healanim)}}}];

if (isNil "d_WithWounds") then {
	player addEventHandler ["handleHeal", FUNCXR(HandleHeal)];
} else {
	if (d_WithWounds == 1) then {
		player addEventHandler ["handleHeal", FUNCXR(HandleHeal)];
	};
};

if (count GVARXR(can_revive) == 0) then {
	GVARXR(pl_can_revive) = true;
} else {
	{
		GVARXR(can_revive) set [_forEachIndex, toUpper GVARXR(can_revive)];
	} forEach GVARXR(can_revive);
	GVARXR(pl_can_revive) = (toUpper(str player) in GVARXR(can_revive));
};

if (GVARXR(with_marker)) then {
	{
		_unit = __getMNsVar2(_x);
		if (!isNil "_unit") then {
			if (alive _unit && __GV(_unit,GVARXR(pluncon))) then {
				if (_unit distance (markerPos QGVARXR(playerparkmarker))> 100) then {
					if (side (group _unit) == GVARXR(side_pl)) then {
						[(_x + __xrdead), getPosASL _unit, "ICON", "ColorBlue", [0.4,0.4], format [(localize "STR_DOM_MISSIONSTRING_910"), name _unit],0,"Flag1"] call FUNCXR(CreateMarkerLocal);
					};
				};
			};
		};
	} forEach GVARXR(player_entities);
};

{
	_unit = __getMNsVar2(_x);
	if (!isNil "_unit") then {
		if (alive _unit && __GV(_unit,GVARXR(pluncon))) then {
#ifdef __TT__
			if (side (group _unit) == GVARXR(side_pl)) then {
#endif
				_unit call FUNCXR(addActions);
#ifdef __TT__
			};
#endif
		} else {
			_unit setVariable [QGVARXR(ReviveAction), -9999];
			_unit setVariable [QGVARXR(DragAction), -9999];
		};
	};
} forEach GVARXR(player_entities);

waitUntil {!isNull (findDisplay 46)};
__pSetVar [QGVARXR(display_key_handler), (findDisplay 46) displayAddEventHandler ["KeyDown", format ["_this call %1_fnc_KeyboardHandlerKeyDown", __COMPXRstr]]];
