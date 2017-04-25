// by Xeno and Carl Gustaffa
#define THIS_FILE "x_searchbody.sqf"
#include "x_setup.sqf"

if (isNull __XJIPGetVar(GVAR(searchbody))) exitWith {};

PARAMS_1(_body);

if (alive _body) exitWith {(localize "STR_DOM_MISSIONSTRING_343") call FUNC(GlobalChat)};
if (player distance _body > 3) exitWith {(localize "STR_DOM_MISSIONSTRING_344") call FUNC(GlobalChat)};

(localize "STR_DOM_MISSIONSTRING_345") call FUNC(GlobalChat);
player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
if (!alive player) exitWith {(localize "STR_DOM_MISSIONSTRING_346") call FUNC(GlobalChat)};

if (isNull __XJIPGetVar(GVAR(searchbody))) exitWith {(localize "STR_DOM_MISSIONSTRING_347") call FUNC(GlobalChat)};

[QGVAR(rem_sb_id)] call FUNC(NetCallEventToClients);
sleep 0.1;
[QGVAR(searchbody),objNull] call FUNC(NetSetJIP);

_intelar = __XJIPGetVar(GVAR(searchintel));
_intelnum = _intelar call FUNC(RandomFloorArray);

if (random 1 < 0.8) then {
	if ((_intelar select _intelnum) != 1) then {
		switch (_intelnum) do {
			case 0: {
				(localize "STR_DOM_MISSIONSTRING_348") call FUNC(GlobalChat);
				sleep 2;
				_intelar set [0, 1];
				[QGVAR(searchintel),_intelar] call FUNC(NetSetJIP);
				[QGVAR(intel_upd), [0, GVAR(name_pl)]] call FUNC(NetCallEventToClients);
			};
			case 1: {
				(localize "STR_DOM_MISSIONSTRING_349") call FUNC(GlobalChat);
				sleep 2;
				_intelar set [1, 1];
				[QGVAR(searchintel),_intelar] call FUNC(NetSetJIP);
				[QGVAR(intel_upd), [1, GVAR(name_pl)]] call FUNC(NetCallEventToClients);
			};
			case 2: {
				(localize "STR_DOM_MISSIONSTRING_350") call FUNC(GlobalChat);
				sleep 2;
				_intelar set [2, 1];
				[QGVAR(searchintel),_intelar] call FUNC(NetSetJIP);
				[QGVAR(intel_upd), [2, GVAR(name_pl)]] call FUNC(NetCallEventToClients);
			};
			case 3: {
				(localize "STR_DOM_MISSIONSTRING_351") call FUNC(GlobalChat);
				sleep 2;
				_intelar set [3, 1];
				[QGVAR(searchintel),_intelar] call FUNC(NetSetJIP);
				[QGVAR(intel_upd), [3, GVAR(name_pl)]] call FUNC(NetCallEventToClients);
			};
			case 4: {
				(localize "STR_DOM_MISSIONSTRING_352") call FUNC(GlobalChat);
				sleep 2;
				_intelar set [4, 1];
				[QGVAR(searchintel),_intelar] call FUNC(NetSetJIP);
				[QGVAR(intel_upd), [4, GVAR(name_pl)]] call FUNC(NetCallEventToClients);
			};
			case 5: {
				(localize "STR_DOM_MISSIONSTRING_353") call FUNC(GlobalChat);
				sleep 2;
				_intelar set [5, 1];
				[QGVAR(searchintel),_intelar] call FUNC(NetSetJIP);
				[QGVAR(intel_upd), [5, GVAR(name_pl)]] call FUNC(NetCallEventToClients);
			};
			case 6: {
				(localize "STR_DOM_MISSIONSTRING_354") call FUNC(GlobalChat);
				sleep 2;
				_intelar set [6, 1];
				[QGVAR(searchintel),_intelar] call FUNC(NetSetJIP);
				[QGVAR(intel_upd), [6, GVAR(name_pl)]] call FUNC(NetCallEventToClients);
			};
		};
	} else {
		(localize "STR_DOM_MISSIONSTRING_355") call FUNC(GlobalChat);
	};
} else {
	(localize "STR_DOM_MISSIONSTRING_356") call FUNC(GlobalChat);
};