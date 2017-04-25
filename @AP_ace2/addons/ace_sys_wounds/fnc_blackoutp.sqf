//#define DEBUG_MODE_FULL
#include "script_component.hpp"
#define _state_blackingOut 801

private ["_knockout", "_dialog", "_grpunit", "_isLeader", "_uncontime", "_normtime", "_awaketime", "_bleed", "_pain", "_endtime", "_doex", "_uconl", "_carrier", "_grp"];

 _bout = player getVariable ["ace_w_bout", false];
 if (isNil "_bout") then {_bout = false};
 TRACE_1("",_bout);
if (_bout) exitWith {};

player setVariable ["ace_w_bout",true];
player setVariable ["ace_w_wakeup",1];
//player setVariable ["BIS_IS_inAgony",true];
enableRadio false;
//player setUnconscious true;
PARAMS_1(_knockout);
_dialog = false;
_grp = group player;
_isLeader = (player == leader _grp);
if (_isLeader) then {
	_newl = objNull;
	{
		private "_isu";
		_isu = _x call FUNC(isUncon);
		if (!_isu && {_x != player} && {alive _x}) exitWith {_newl = _x}
	} forEach units _grp;
	if (!isNull _newl) then {
		[QGVAR(selLeader), [_grp, _newl]] call CBA_fnc_globalEvent;
		{if (alive _x && {_x != player}) then {_x doFollow _newl}} forEach units _grp;
	};
};
GVAR(specton) = false;
// Drop out of static weapons 
if ((vehicle player) isKindOf "StaticWeapon") then {
	TRACE_1("vehicle player StaticWeapon ejectomg",vehicle player);
	player action ["eject", vehicle player];
};
// Fall down from ladders
if (animationState player in ["ladderriflestatic","laddercivilstatic"]) then {
	TRACE_1("Fsll down ladder",player);
	player action ["ladderOff", (nearestBuilding player)];
};
// Release all attachto stuff
if (player getVariable ["ace_sys_cargo_dragging",false]) then {
	TRACE_1("Cargo dragging",player);
	_dragged_object = player getVariable ["ace_sys_cargo_dragged_object",objNull];
	if (!isNull _dragged_object) then {
		detach _dragged_object;
	};
};

GVAR(mapunc_keyDownEHId) = -9999;
if (isNil QGVAR(withSpect) || {(player getVariable "ace_w_state") != 802}) then {
	// Add "M" key down eventhandler (map)
	TRACE_1("Add M key evemthandler",player);
	GVAR(mapunc_keyDownEHId) = (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call ace_sys_wounds_fnc_mapunckeydown"];
};
[QGVAR(cap), [player,true]] call CBA_fnc_globalEvent;
if (isNil QGVAR(withSpect) || {((player getVariable "ace_w_state") != 802)}) then {
	TRACE_1("Creating resource for state 802",player);
	if (vehicle player == player) then {
		10002 cutRsc["ACE_Wound_Unconscious1","PLAIN"]; // Half vision
	} else {
		createDialog "ACE_Wound_Unconscious_Rare"; // Half vision DLG
		_dialog = true;
	};
};

if (!isNil "ace_wounds_prevtime") then {
	TRACE_1("ace_wounds_prevtime enabled",player);
	player setVariable ["ace_w_cardiactime", 0];
	if (ace_wounds_prevtime > 0) then {
		TRACE_1("ace_wounds_prevtime > 0",player);
		if (isNil "ace_wounds_no_prevtime") then {
			ace_wounds_no_prevtime = false;
		};
		if (isNil QGVAR(withSpect)) then {
			if (ace_wounds_no_prevtime) exitWith {};
			if (player getVariable "ace_w_state" <= _state_blackingOut) exitWith {
				TRACE_1("state <= _state_blackingOut",player);
			};
			sleep 2;

			[] spawn {
				10005 cutRsc ["ACE_Wound_Revivetime", "PLAIN"];
				while {(player call FUNC(isUncon)) && {alive player}} do {
					// Check if player is Unconscious in a MEDEVAC vehicle 
					// Check only for Cargo Seats
					_evacTime = player getVariable ["ace_w_evactime",0];
					if (vehicle player != player && {player in assignedCargo (vehicle player)} && {getNumber(configFile >> "CfgVehicles" >> typeOf (vehicle player) >> "attendant") == 1}) then {
						_newEvacTime = _evacTime + 1;
						player setVariable ["ace_w_evactime",_newEvacTime];
						((uiNamespace getVariable "ACE_Wound_Revivetime") displayCtrl 1234567) ctrlSetText ""; // If player is evacuated show no timer
						((uiNamespace getVariable "ACE_Wound_Revivetime") displayCtrl 1234567) ctrlCommit 0;						
						sleep 1;
					} else {
						_time_left = round ((player getVariable "ace_w_revive") - time + _evacTime + (player getVariable "ace_w_cardiactime"));
						if (!isNil "ace_wounds_prevtimeshow" && {ace_wounds_prevtimeshow}) then { // Show revive time, if enabled
							// Arcade shit
							((uiNamespace getVariable "ACE_Wound_Revivetime") displayCtrl 1234567) ctrlSetText format [localize "STR_ACE_WOUNDS_LIFETIME", _time_left];
							((uiNamespace getVariable "ACE_Wound_Revivetime") displayCtrl 1234567) ctrlCommit 0;						
						} else {
							// Immersive shit
							((uiNamespace getVariable "ACE_Wound_Revivetime") displayCtrl 1234567) ctrlSetText "";
							((uiNamespace getVariable "ACE_Wound_Revivetime") displayCtrl 1234567) ctrlCommit 0;
						};
						sleep 1;
					};
				};
				10005 cutRsc["Default","PLAIN"];
			};
		} else {
			[] spawn {
				if ((player getVariable "ace_w_state") != 802) then {
					waitUntil {((player getVariable "ace_w_state") == 802) || {!(player call FUNC(isUncon))} || {!alive player}};
				};
				if (alive player && {(player call FUNC(isUncon))} && {((player getVariable "ace_w_state") == 802)}) then {
					if (GVAR(mapunc_keyDownEHId) != -9999) then {
						(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(mapunc_keyDownEHId)];
						GVAR(mapunc_keyDownEHId) = -9999;
					};
					if (isNil "ace_sys_spectator_ShownSides") then {ace_sys_spectator_ShownSides = [playerSide]};
					if (isNil "ace_sys_spectator_maxDistance") then {ace_sys_spectator_maxDistance = 10};
					if (isNil "ace_sys_spectator_CheckDist") then {ace_sys_spectator_CheckDist = 250};
					if (isNil "ace_sys_spectator_CheckUncon") then {ace_sys_spectator_CheckUncon = true};
					if (isNil "ace_sys_spectator_RemoveDeadFilter") then {ace_sys_spectator_RemoveDeadFilter = true};
					ace_sys_spectator_no_butterfly_mode = true;
					if (isNil "ace_sys_spectator_playable_only") then {ace_sys_spectator_playable_only = true};
					titleText ["", "BLACK OUT", 3];
					GVAR(specton) = true;
					[] spawn {
						sleep 4;
						10002 cutRsc ["Default","PLAIN"];
						10004 cutRsc ["Default","PLAIN"];
						if (dialog) then {closeDialog 0};
						0.5 fadeSound 1;
						call ace_sys_spectator_fnc_startSpectator;
						titleText ["", "BLACK IN", 1];
					};
				};
			};
		};
	};
};

_normtime = true;
if (!isNil "ace_wounds_prevtime") then {
	if (ace_wounds_prevtime > 0) then {_normtime = false};
};

if (_knockout) then {_normtime = false};
TRACE_1("",_normtime);

while {(player call FUNC(isUncon)) && {alive player}} do {
	_uncontime = 3; _awaketime = 6;
	if (_normtime) then {
		_uncontime = 3;
		_awaketime = 6;
		_bleed = player getVariable "ace_w_bleed";
		_pain = player getVariable "ace_w_pain";
		
		TRACE_2("",_bleed,_pain);

		if (_bleed > 0.3 || {_pain > 0.3}) then {
			_uncontime = _uncontime + (_bleed * 8) + (_pain * 8);
			if (_awaketime > 3) then {
				_awaketime = _awaketime - 0.1;
			};
		};
	} else {
		_uncontime = 5 + random 5;
		_awaketime = 5 + random 5;
	};
	TRACE_2("",_uncontime,_awaketime);
	if (isNil QGVAR(withSpect)) then {
		0.5 fadeSound 0;
		10004 cutRsc["ACE_Wound_Unconscious2","PLAIN"]; // No vision
	} else {
		if (!GVAR(specton) && {((player getVariable "ace_w_state") != 802)}) then {
			0.5 fadeSound 0;
			10004 cutRsc ["ACE_Wound_Unconscious2","PLAIN"]; // No vision
		};
	};
	if (!alive player || {!(player call FUNC(isUncon))}) exitWith {};
	if (vehicle player == player && {(player call FUNC(isUncon))} && {isNull (player getVariable ["ace_w_carry", objNull])}) then {
		if ((player call CBA_fnc_getUnitDeathAnim) != "") then {
			TRACE_1("playimg death anim 100, local, non vehicle",player);
			[player, 100] call FUNC(animator2);
		};
	};
	if (isNil QGVAR(withSpect)) then {
		if (_dialog) then {
			if (!dialog) then {createDialog "ACE_Wound_Unconscious_Rare";}; // Half vision DLG
		} else {
			if (vehicle player != player) then {
				10002 cutRsc ["Default","PLAIN"];
				createDialog "ACE_Wound_Unconscious_Rare"; // Half vision DLG
				_dialog = true;
			};
		};
	} else {
		if (!GVAR(specton) && {(player getVariable "ace_w_state") != 802}) then {
			if (_dialog) then {
				if (!dialog) then {createDialog "ACE_Wound_Unconscious_Rare";}; // Half vision DLG
			} else {
				if (vehicle player != player) then {
					10002 cutRsc ["Default","PLAIN"];
					createDialog "ACE_Wound_Unconscious_Rare"; // Half vision DLG
					_dialog = true;
				};
			};
		};
	};
	private "_vecp";
	_vecp = vehicle player;
	_endtime = time + _uncontime;
	TRACE_1("",_endtime);
	waitUntil {time >= _endtime || {!alive player} || {(_vecp != vehicle player)} || {(_dialog && !dialog)} || {!(player call FUNC(isUncon))}};
	TRACE_1("endtime reached",player);
	if (!alive player || {!(player call FUNC(isUncon))}) exitWith {};
	if (_dialog && {!dialog}) then {
		sleep 0.2;
	};
	if (vehicle player == player && {vehicle player != _vecp} && {(player call FUNC(isUncon))} && {isNull (player getVariable ["ace_w_carry", objNull])}) then {
		if ((player call CBA_fnc_getUnitDeathAnim) != "") then {
			TRACE_1("playimg death anim 100. iocal 2, non vehicle",player);
			[player, 100] call FUNC(animator2);
		};
	};
	if (vehicle player != player) then {
		_vecx = vehicle player;
		_alv = if (isNil {_vecx getVariable "ace_canmove"}) then {alive _vecx} else {_vecx call ace_v_alive};
		if (!_alv) then {
			TRACE_1("Ejecting player",player);
			player action ["eject", _vecx];
			waitUntil {vehicle player == player};
			if (player call FUNC(isUncon)) then {
				TRACE_1("Ejecting player animator2 100",player);
				[player, 100] call FUNC(animator2);
			};
		};
	};
	if (isNil QGVAR(withSpect)) then {
		if (_dialog) then {
			if (!dialog) then {createDialog "ACE_Wound_Unconscious_Rare";}; // Half vision DLG
		} else {
			if (vehicle player != player) then {
				10002 cutRsc["Default","PLAIN"];
				createDialog "ACE_Wound_Unconscious_Rare"; // Half vision DLG
				_dialog = true;
			};
		};

		0.5 fadeSound 0.01;
		10004 cutRsc["ACE_Wound_Unconscious3","PLAIN"]; // No vision
	} else {
		if (!GVAR(specton) && {(player getVariable "ace_w_state") != 802}) then {
			if (_dialog) then {
				if (!dialog) then {createDialog "ACE_Wound_Unconscious_Rare";}; // Half vision DLG
			} else {
				if (vehicle player != player) then {
					10002 cutRsc ["Default","PLAIN"];
					createDialog "ACE_Wound_Unconscious_Rare"; // Half vision DLG
					_dialog = true;
				};
			};
			0.5 fadeSound 0.01; 
			10004 cutRsc ["ACE_Wound_Unconscious3","PLAIN"]; // No vision
		};
	};
	_vecp = vehicle player;
	_endtime = time + _awaketime;
	TRACE_1("2",_endtime);
	waitUntil {time >= _endtime || {!alive player} || {(_vecp != vehicle player)} || {(_dialog && !dialog)} || {!(player call FUNC(isUncon))}};
	TRACE_1("endtime reached 2",player);
	if (!alive player || {!(player call FUNC(isUncon))}) exitWith {};
	if (_dialog && {!dialog}) then {
		sleep 0.2;
	};
	if (vehicle player == player && {vehicle player != _vecp} && {(player call FUNC(isUncon))} && {isNull (player getVariable ["ace_w_carry", objNull])}) then {
		if ((player call CBA_fnc_getUnitDeathAnim) != "") then {
			TRACE_1("playing death anim 100. iocal 3, non vehicle",player);
			[player, 100] call FUNC(animator2);
		};
	};
	if (vehicle player != player) then {
		_vecx = vehicle player;
		_alv = if (isNil {_vecx getVariable "ace_canmove"}) then {alive _vecx} else {_vecx call ace_v_alive};
		if (!_alv) then {
			TRACE_1("Ejecting player 2",player);
			player action ["eject", _vecx];
			waitUntil {vehicle player == player};
			if (player call FUNC(isUncon)) then {
				TRACE_1("Ejecting player animator2 100 2",player);
				[player, 100] call FUNC(animator2);
			};
		};
	};

	_doex = false;
	if ((player getVariable "ace_w_state") <= _state_blackingOut) then {
		_uconl = player getVariable "ace_w_unconlen";
		if (_uconl != -1 && {time > _uconl}) then {_doex = true};
	};
	TRACE_1("",_doex);
	if (_doex) exitWith {};
	if (isNil QGVAR(withSpect)) then {
		if (_dialog) then {
			if (!dialog) then {createDialog "ACE_Wound_Unconscious_Rare";}; // Half vision DLG
		} else {
			if (vehicle player != player) then {
				10002 cutRsc["Default","PLAIN"];
				createDialog "ACE_Wound_Unconscious_Rare"; // Half vision DLG
				_dialog = true;
			};
		};
	} else {
		if (!GVAR(specton) && {(player getVariable "ace_w_state") != 802}) then {
			if (_dialog) then {
				if (!dialog) then {createDialog "ACE_Wound_Unconscious_Rare";}; // Half vision DLG
			} else {
				if (vehicle player != player) then {
					10002 cutRsc ["Default","PLAIN"];
					createDialog "ACE_Wound_Unconscious_Rare"; // Half vision DLG
					_dialog = true;
				};
			};
		};
	};
	TRACE_1("loop end",player);
};
TRACE_1("loop exit",player);

if (vehicle player != player) then {
	_vecx = vehicle player;
	_alv = if (isNil {_vecx getVariable "ace_canmove"}) then {alive _vecx} else {_vecx call ace_v_alive};
	if (!_alv) then {
		TRACE_1("Ejecting player 3",player);
		player action ["eject", _vecx];
		waitUntil {vehicle player == player};
		if (player call FUNC(isUncon)) then {
			TRACE_1("Ejecting player animator2 100 3",player);
			[player, 100] call FUNC(animator2);
		};
	};
};

if (alive player) then {
	if (!isNull (player getVariable "ace_w_carry")) then {
		TRACE_1("Somebody is carrying the player",player);
		waitUntil {_carrier = player getVariable "ace_w_carry";(isNull _carrier || {!alive _carrier})};
		TRACE_1("Carrying over",player);
		player setVariable ["ace_w_carry", objNull, true];
		sleep 1;
	};
	if (vehicle player == player) then {
		_sec = currentWeapon player;
		if (_sec != "" && {_sec != " "}) then {
			if (getNumber (configFile >> "CfgWeapons" >> _sec >> "type") == 4) then {
				TRACE_1("Headbugfix",player);
				_iswater = surfaceIsWater getPosASL player;
				_ppos = if (_iswater) then {getPosASL player} else {getPosATL player};
				_pdir = direction player;
				_ACE_HeadbugFix = "ACE_Headbug_Fix" createVehicleLocal _ppos;
				if (_iswater) then {_ACE_HeadbugFix setPosASL _ppos} else {_ACE_HeadbugFix setPosATL _ppos};
				_ACE_HeadbugFix setDir _pdir;
				player moveInDriver _ACE_HeadbugFix;
				waitUntil {vehicle player != player};
				unassignVehicle player;
				player action ["Eject", vehicle player];
				waitUntil {vehicle player == player};
				if (_iswater) then {player setposASL _ppos} else {player setposATL _ppos};
				player setDir _pdir;
				deleteVehicle _ACE_HeadbugFix;
			};
		};

		[player, 102] call FUNC(animator);
		TRACE_1("heal anim 102",player);
	};
	player setVariable ["ace_w_wakeup", 0];
	TRACE_1("heal anim 102 done",player);

	if (!isNil "ace_sys_wounds_enabled") then {
		player setVariable ["ace_w_unconlen",-1];
		if ((player getVariable "ace_w_state") <= _state_blackingOut) then {
			TRACE_1("Setting uncon variable player to false",player);
			player setVariable [QGVAR(uncon),false,true];
			player setVariable ["ace_w_nextuncon", time + (60 + random 60)]; // add bleeding and pain
		};
	} else {
		player setVariable [QGVAR(uncon),false];
	};

	//player setVariable ["BIS_IS_inAgony",false];
	//player setUnconscious false;
};

if (!isNil QGVAR(withSpect) && {GVAR(specton)}) then {
	//if (GVAR(SPECTATINGON)) then {
		ace_sys_spectator_exit_spectator = true;
		titleText ["", "BLACK IN", 3];
	//};
};
enableRadio true;
if (!GVAR(specton)) then {
	10004 cutRsc ["ACE_Wound_Unconscious3","PLAIN"]; // No vision
	if (!_dialog) then {
		10002 cutRsc ["Default","PLAIN"];
	} else {
		closeDialog 0;
	};
};
// Remove "M" key down eventhandler
if (GVAR(mapunc_keyDownEHId) != -9999) then {
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", GVAR(mapunc_keyDownEHId)];
};
0.5 fadeSound 1;
[QGVAR(cap), [player,false]] call CBA_fnc_globalEvent;
if (rating player < 0) then {
	player addRating abs(rating player);
};

if (alive player) then {
	if (_isLeader) then {
		[QGVAR(selLeader), [_grp, player]] call CBA_fnc_globalEvent;
		{if (_x != player) then {_x doFollow player}} forEach units _grp;
	};
};
player setVariable ["ace_w_bout",false];

TRACE_1("blackout player done",player);