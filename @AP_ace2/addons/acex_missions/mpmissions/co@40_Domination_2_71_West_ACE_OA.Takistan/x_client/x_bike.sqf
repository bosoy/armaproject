// by Xeno
#define THIS_FILE "x_bike.sqf"
#include "x_setup.sqf"
private ["_create_bike", "_disp_name", "_str", "_pos", "_vehicle", "_exitit", "_dosearch", "_index", "_parray", "_rank"];
if (!X_Client) exitWith {};

_create_bike = (_this select 3) select 0;
_b_mode = (_this select 3) select 1;

if (GVAR(with_ranked)) then {
	_exitit = false;
	_dosearch = true;
	if (_create_bike in GVAR(create_bike)) then {
		if (count GVAR(create_bike) > 1) then {
			_index = GVAR(create_bike) find _create_bike;
			if (_index != -1) then {
				_dosearch = false;
				_parray = [GVAR(points_needed) select 1, GVAR(points_needed) select 2, GVAR(points_needed) select 3, GVAR(points_needed) select 4, GVAR(points_needed) select 5];
				if (_index < count _parray) then {
					if (score player < (_parray select _index)) then {
						_rank = switch (_parray select _index) do {
							case (GVAR(points_needed) select 1): {"Sergeant"};
							case (GVAR(points_needed) select 2): {"Lieutenant"};
							case (GVAR(points_needed) select 3): {"Captain"};
							case (GVAR(points_needed) select 4): {"Major"};
							case (GVAR(points_needed) select 5): {"Colonel"};
						};
						(format [(localize "STR_DOM_MISSIONSTRING_156"),_rank,_create_bike]) call FUNC(GlobalChat);
						_exitit = true;
					};
				};
			};
		};
	};
	if (_dosearch) then {
		if (score player < (GVAR(ranked_a) select 6)) then {
			_rank = (GVAR(ranked_a) select 6) call FUNC(GetRankFromScore); 
			_exitit = true;
			(format[(localize "STR_DOM_MISSIONSTRING_157"),_create_bike,_rank]) call FUNC(GlobalChat);
		};
	};
};
if (_exitit) exitWith {};

_disp_name = [_create_bike,0] call FUNC(GetDisplayName);

if (vehicle player != player) exitWith {
	_str = format [(localize "STR_DOM_MISSIONSTRING_158"), _disp_name];
	_str call FUNC(GlobalChat);
};

if (isNil {__pGetVar(GVAR(bike_created))}) then {__pSetVar [QGVAR(bike_created), false]};
if (__pGetVar(GVAR(bike_created)) && _b_mode == 1) exitWith {(localize "STR_DOM_MISSIONSTRING_159") call FUNC(GlobalChat)};

if (diag_tickTime > GVAR(vec_end_time) && !isNull GVAR(flag_vec)) then {
	if (GVAR(flag_vec) call FUNC(GetVehicleEmpty)) then {
		deleteVehicle GVAR(flag_vec);
		GVAR(flag_vec) = objNull;
		GVAR(vec_end_time) = -1;
	};
};
if (!isNull GVAR(flag_vec) && alive GVAR(flag_vec) && _b_mode == 0) exitWith {
	(format [(localize "STR_DOM_MISSIONSTRING_160"),0 max (round((GVAR(vec_end_time) - diag_tickTime)/60))]) call FUNC(GlobalChat);
};

if (GVAR(with_ranked)) then {
	[QGVAR(pas), [player, (GVAR(ranked_a) select 5) * -1]] call FUNC(NetCallEventCTS);
};

_pos = position player;
_str = format [(localize "STR_DOM_MISSIONSTRING_161"), _disp_name];
_str call FUNC(GlobalChat);
sleep 3.123;
__pSetVar [QGVAR(bike_created), true];
_pos = position player;
_vehicle = createVehicle [_create_bike, _pos, [], 0, "NONE"];
_vehicle setDir direction player;
_vehicle setPos _pos;
player reveal _vehicle;

player moveInDriver _vehicle;

if (_vehicle isKindOf "ATV_US_EP1") then {
	_vehicle addAction [(localize "STR_DOM_MISSIONSTRING_162") call FUNC(BlueText), "x_client\x_flipatv.sqf", 0, -1, false, false, "", "!(player in _target) && ((vectorUp _target) select 2) < 0.6"];
};

if (_b_mode == 1) then {
	_vehicle spawn {
		private "_vehicle";
		_vehicle = _this;
		[QGVAR(ad), _vehicle] call FUNC(NetCallEventCTS);
		waitUntil {sleep 0.412;!alive player || !alive _vehicle};
		sleep 10.123;
		_vehicle spawn {
			private "_vehicle";
			_vehicle = _this;
			while {true} do {
				if (_vehicle call FUNC(GetVehicleEmpty)) exitWith {deleteVehicle _vehicle};
				sleep 15.123;
			};
		};
	};
} else {
	GVAR(flag_vec) = _vehicle;
	GVAR(vec_end_time) = diag_tickTime + GVAR(VecCreateWaitTime) + 60;
	[QGVAR(ad2), [GVAR(flag_vec),GVAR(vec_end_time)]] call FUNC(NetCallEventCTS);
	GVAR(flag_vec) addEventHandler ["killed", {(_this select 0) spawn {private ["_vec"];_vec = _this;sleep 10.123;while {true} do {if (isNull _vec) exitWith {};if (_vec call FUNC(GetVehicleEmpty)) exitWith {deleteVehicle _vec};sleep 15.123};GVAR(flag_vec) = objNull}}];
};
