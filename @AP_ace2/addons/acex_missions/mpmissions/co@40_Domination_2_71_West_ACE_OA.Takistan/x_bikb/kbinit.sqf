// by Xeno
#define THIS_FILE "kbinit.sqf"
#include "x_setup.sqf"
private ["_grpen", "_grpru", "_kbscript"];

if (isServer) then {
	waitUntil {!isNil QUOTE(FUNC(creategroup))};
	_grpen = [west] call FUNC(creategroup);
	GVAR(hq_logic_en1) = _grpen createUnit ["Logic",[0,0,333],[],0,"NONE"];
	[GVAR(hq_logic_en1)] joinSilent _grpen;
	GVAR(hq_logic_en1) enableSimulation false;
	[QGVAR(hq_logic_en1), GVAR(hq_logic_en1)] call FUNC(NetSetJIP);
	_grpen = [west] call FUNC(creategroup);
	GVAR(hq_logic_en2) = _grpen createUnit ["Logic",[0,0,334],[],0,"NONE"];
	[GVAR(hq_logic_en2)] joinSilent _grpen;
	GVAR(hq_logic_en2) enableSimulation false;
	[QGVAR(hq_logic_en2), GVAR(hq_logic_en2)] call FUNC(NetSetJIP);

	_grpru = [east] call FUNC(creategroup);
	GVAR(hq_logic_ru1) = _grpru createUnit ["Logic",[0,0,335],[],0,"NONE"];
	[GVAR(hq_logic_ru1)] joinSilent _grpru;
	GVAR(hq_logic_ru1) enableSimulation false;
	[QGVAR(hq_logic_ru1), GVAR(hq_logic_ru1)] call FUNC(NetSetJIP);
	_grpru = [east] call FUNC(creategroup);
	GVAR(hq_logic_ru2) = _grpru createUnit ["Logic",[0,0,336],[],0,"NONE"];
	[GVAR(hq_logic_ru2)] joinSilent _grpru;
	GVAR(hq_logic_ru2) enableSimulation false;
	[QGVAR(hq_logic_ru2), GVAR(hq_logic_ru2)] call FUNC(NetSetJIP);
} else {
	waitUntil {!isNil {__XJIPGetVar(GVAR(hq_logic_ru2))}};
	GVAR(hq_logic_en1) = __XJIPGetVar(GVAR(hq_logic_en1));
	GVAR(hq_logic_en2) = __XJIPGetVar(GVAR(hq_logic_en2));
	GVAR(hq_logic_ru1) = __XJIPGetVar(GVAR(hq_logic_ru1));
	GVAR(hq_logic_ru2) = __XJIPGetVar(GVAR(hq_logic_ru2));
};

#ifdef __OA__
_kbscript = "x_bikb\domkboa.bikb";
#endif
#ifdef __CO__
_kbscript = "x_bikb\domkb.bikb";
#endif

GVAR(hq_logic_ru1) kbAddTopic["HQ_E",_kbscript];
GVAR(hq_logic_ru1) kbAddTopic["HQ_ART_E",_kbscript];
GVAR(hq_logic_ru1) setIdentity "DHQ_RU1";
GVAR(hq_logic_ru1) setRank "COLONEL";
GVAR(hq_logic_ru1) setGroupId ["HQ"];

GVAR(hq_logic_ru2) kbAddTopic["HQ_E",_kbscript];
GVAR(hq_logic_ru2) setIdentity "DHQ_RU2";
GVAR(hq_logic_ru2) setRank "COLONEL";
GVAR(hq_logic_ru2) setGroupId ["HQ1"];

GVAR(hq_logic_en1) kbAddTopic["HQ_W",_kbscript];
GVAR(hq_logic_en1) kbAddTopic["HQ_ART_W",_kbscript];
GVAR(hq_logic_en1) setIdentity "DHQ_EN1";
GVAR(hq_logic_en1) setRank "COLONEL";
GVAR(hq_logic_en1) setGroupId ["Crossroad"];

GVAR(hq_logic_en2) kbAddTopic["HQ_W",_kbscript];
GVAR(hq_logic_en2) setIdentity "DHQ_EN2";
GVAR(hq_logic_en2) setRank "COLONEL";
GVAR(hq_logic_en2) setGroupId ["Crossroad1"];

#ifndef __TT__
GVAR(kb_logic1) = switch (GVAR(enemy_side)) do {
	case "EAST": {GVAR(hq_logic_en1)};
	case "WEST": {GVAR(hq_logic_ru1)};
};
GVAR(kb_logic2) = switch (GVAR(enemy_side)) do {
	case "EAST": {GVAR(hq_logic_en2)};
	case "WEST": {GVAR(hq_logic_ru2)};
};
GVAR(kb_topic_side) = switch (GVAR(enemy_side)) do {
	case "EAST": {"HQ_W"};
	case "WEST": {"HQ_E"};
};
GVAR(kb_topic_side_arti) = switch (GVAR(enemy_side)) do {
	case "EAST": {"HQ_ART_W"};
	case "WEST": {"HQ_ART_E"};
};
#endif

if (!isDedicated) then {
	waitUntil {sleep 0.121;X_INIT};
	sleep 1;
	if (isMultiplayer) then {
		waitUntil {sleep 0.220;!isNil QGVAR(still_in_intro)};
		waitUntil {sleep 0.220;!GVAR(still_in_intro)};
	};
	switch (playerSide) do {
		case west: {player kbAddTopic["HQ_W",_kbscript]};
		case east: {player kbAddTopic["HQ_E",_kbscript]};
	};
	_strp = str(player);
	player kbAddTopic["PL" + _strp,_kbscript];
	#ifndef __TT__
	GVAR(kb_logic1) kbAddTopic["PL" + str(player),_kbscript];
	#else
	_ll = switch (playerSide) do {
		case west: {GVAR(hq_logic_en1)};
		case east: {GVAR(hq_logic_ru1)};
	};
	_ll kbAddTopic["PL" + _strp,_kbscript];
	#endif
	if (!GVAR(with_ai) && GVAR(with_ai_features) != 0) then {
		if (_strp in GVAR(can_use_artillery)) then {
			switch (playerSide) do {
				case west: {player kbAddTopic["HQ_ART_W",_kbscript]};
				case east: {player kbAddTopic["HQ_ART_E",_kbscript]};
			};
		};
	} else {
		switch (playerSide) do {
			case west: {player kbAddTopic["HQ_ART_W",_kbscript]};
			case east: {player kbAddTopic["HQ_ART_E",_kbscript]};
		};
	};
};
