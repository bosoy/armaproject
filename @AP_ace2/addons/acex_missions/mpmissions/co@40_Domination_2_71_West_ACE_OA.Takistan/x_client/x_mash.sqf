// by Xeno
#define THIS_FILE "x_mash.sqf"
#include "x_setup.sqf"
private ["_dir_to_set","_m_name","_marker","_d_medtent", "_exit_it"];

if (__pGetVar(GVAR(isinaction))) exitWith {
	GVAR(commandingMenuIniting) = false;
};

if (player distance GVAR(name_flag_base) < 30) exitWith {
	(localize "STR_DOM_MISSIONSTRING_283") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

if ((player call FUNC(GetHeight)) > 5) exitWith {
	(localize "STR_DOM_MISSIONSTRING_241") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_d_medtent = __pGetVar(GVAR(medtent));
if (count _d_medtent > 0) exitWith {(localize "STR_DOM_MISSIONSTRING_281") call FUNC(GlobalChat)};

_d_medtent = player modeltoworld [0,5,0];
_d_medtent set [2,0];

if (surfaceIsWater [_d_medtent select 0, _d_medtent select 1]) exitWith {
	(localize "STR_DOM_MISSIONSTRING_282") call FUNC(GlobalChat);
	GVAR(commandingMenuIniting) = false;
};

_helper1 = GVAR(HeliHEmpty) createVehicleLocal [_d_medtent select 0, (_d_medtent select 1) + 4, 0];
_helper2 = GVAR(HeliHEmpty) createVehicleLocal [_d_medtent select 0, (_d_medtent select 1) - 4, 0];
_helper3 = GVAR(HeliHEmpty) createVehicleLocal [(_d_medtent select 0) + 4, _d_medtent select 1, 0];
_helper4 = GVAR(HeliHEmpty) createVehicleLocal [(_d_medtent select 0) - 4, _d_medtent select 1, 0];

_exit_it = false;
if ((abs (((getPosASL _helper1) select 2) - ((getPosASL _helper2) select 2)) > 2) || (abs (((getPosASL _helper3) select 2) - ((getPosASL _helper4) select 2)) > 2)) then {
	(localize "STR_DOM_MISSIONSTRING_283") call FUNC(GlobalChat);
	_exit_it = true;
};

for "_mt" from 1 to 4 do {call compile format ["deleteVehicle _helper%1;", _mt]};

if (_exit_it) exitWith {
	GVAR(commandingMenuIniting) = false;
};

__pSetVar [QGVAR(isinaction), true];

player playMove "AinvPknlMstpSlayWrflDnon_medic";
sleep 3;
waitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
GVAR(commandingMenuIniting) = false;
if (!alive player) exitWith {
	(localize "STR_DOM_MISSIONSTRING_284") call FUNC(GlobalChat);
	__pSetVar [QGVAR(isinaction), false];
};

_dir_to_set = getdir player - 180;

_medic_tent = createVehicle [GVAR(mash), _d_medtent, [], 0, "NONE"];
_medic_tent setdir _dir_to_set;
_medic_tent setPos _d_medtent;
[_medic_tent, 0] call FUNC(SetHeight);

__pSetVar ["medic_tent", _medic_tent];
player reveal _medic_tent;
_d_medtent = position _medic_tent;
__pSetVar [QGVAR(medtent), _d_medtent];

(localize "STR_DOM_MISSIONSTRING_285") call FUNC(GlobalChat);
_m_name = "Mash " + GVAR(string_player);

[QGVAR(p_o_a), [GVAR(string_player), [_medic_tent,_m_name,GVAR(name_pl),GVAR(player_side)]]] call FUNC(NetCallEvent);

_medic_tent addAction [(localize "STR_DOM_MISSIONSTRING_286") call FUNC(RedText), "x_client\x_removemash.sqf"];

__pSetVar [QGVAR(isinaction), false];

if (GVAR(with_ranked)) then {
	_medic_tent spawn {
		private ["_tent", "_pos_healers", "_healerslist", "_points", "_nobs", "_i", "_h", "_healanims"];
		_tent = _this;
		_pos_healers = switch (GVAR(own_side)) do {
			case "WEST": {"SoldierWB"};
			case "EAST": {"SoldierEB"};
			case "GUER": {"SoldierGB"};
		};
		_healerslist = [];
		_healanims = ["ainvpknlmstpslaywrfldnon_healed","ainvpknlmstpslaywrfldnon_healed2","ainvpknlmstpsnonwnondnon_healed_1","ainvpknlmstpsnonwnondnon_healed_2","amovppnemstpsnonwnondnon_healed","amovppnemstpsraswpstdnon_healed","amovppnemstpsraswrfldnon_healed"];
		while {!isNull _tent && alive _tent} do {
			_points = 0;
			
			_nobs = (position _tent) nearEntities [_pos_healers, 13];
			{
				if (!(_x in _healerslist) && (_x != player)) then {
					if (animationState _x in _healanims) then {
						_points = _points + (GVAR(ranked_a) select 7);
						_healerslist set [count _healerslist, _x];
					};
				};
			} forEach _nobs;
			if (_points > 0) then {
				[QGVAR(pas), [player, _points]] call FUNC(NetCallEventCTS);
				(format [(localize "STR_DOM_MISSIONSTRING_287"), _points]) call FUNC(HQChat);
			};
			sleep 0.01;
			if (count _healerslist > 0) then {
				{
					if !(animationState _x in _healanims) then {_healerslist set [_forEachIndex, -1]};
				} forEach _healerslist;
				_healerslist = _healerslist - [-1];
			};
			sleep 0.521;
		};
	};
};