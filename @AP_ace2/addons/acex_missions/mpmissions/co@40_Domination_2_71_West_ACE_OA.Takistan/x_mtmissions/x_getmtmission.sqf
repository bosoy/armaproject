// by Xeno
#define THIS_FILE "x_getmtmission.sqf"
#include "x_setup.sqf"

#define __getPos \
_poss = [_target_array2 select 0, _target_array2 select 2] call FUNC(GetRanPointCircleBig);\
if (isOnRoad _poss) then {_poss = []};\
while {count _poss == 0} do {\
	_poss = [_target_array2 select 0, _target_array2 select 2] call FUNC(GetRanPointCircleBig);\
	if (isOnRoad _poss) then {_poss = []};\
	sleep 0.01;\
}

#define __specops \
__GetEGrp(_newgroup)\
_unit_array = [#specops, GVAR(enemy_side)] call FUNC(getunitliste);\
[_poss, _unit_array select 0, _newgroup,true] spawn FUNC(makemgroup);\
sleep 1.0112;\
_newgroup allowFleeing 0;\
_newgroup setVariable [QGVAR(defend), true]; \
[_newgroup, _poss] spawn FUNC(taskDefend); \
GVAR(reduce_groups) set [count GVAR(reduce_groups), _newgroup]


#define __vkilled(ktype) _vehicle addEventHandler [#killed, {_this set [count _this, #ktype]; _this call FUNC(MTSMTargetKilled)}]

private ["_man","_newgroup","_poss","_unit_array","_vehicle","_wp_array","_truck","_the_officer","_sec_kind","_fixor"];
if (!isServer) exitWith {};

_fixor = {
	private ["_unit", "_list","_curidx"];
	PARAMS_2(_unit,_curidx);
	while {true} do {
		if (!alive _unit || isNull _unit) exitWith {};
		sleep 0.01;
		_list = list GVAR(current_trigger);
		#ifndef __TT__
		if ((X_JIPH getVariable QGVAR(campscaptured)) == GVAR(sum_camps) && ("Car" countType _list <= GVAR(car_count_for_target_clear)) && ("Tank" countType _list <= GVAR(tank_count_for_target_clear)) && ("CAManBase" countType _list <= GVAR(man_count_for_target_clear))) exitWith {};
		#else
		if (((X_JIPH getVariable QGVAR(campscaptured_e)) == GVAR(sum_camps) || (X_JIPH getVariable QGVAR(campscaptured_w)) == GVAR(sum_camps)) && ("Car" countType _list <= GVAR(car_count_for_target_clear)) && ("Tank" countType _list <= GVAR(tank_count_for_target_clear)) && ("CAManBase" countType _list <= GVAR(man_count_for_target_clear))) exitWith {};
		#endif
		
		sleep 3.219;
	};
	if (alive _unit) then {
		sleep 240 + random 60;
		if (alive _unit && _curidx == __XJIPGetVar(GVAR(current_target_index))) then {
			_unit setDamage 1;
			GVAR(side_main_done) = true;
		} else {
			if (isNull _unit && !GVAR(side_main_done) && _curidx == __XJIPGetVar(GVAR(current_target_index))) then {
				GVAR(side_main_done) = true;
			};
		};
	} else {
		if (isNull _unit && !GVAR(side_main_done) && _curidx == __XJIPGetVar(GVAR(current_target_index))) then {
			GVAR(side_main_done) = true;
		};
	};
};

_wp_array = _this;

sleep 3.120;
_xx_ran = (count _wp_array) call FUNC(RandomFloor);
_poss = _wp_array select _xx_ran;

_sec_kind = (floor (random 11)) + 1;

__TargetInfo

switch (_sec_kind) do {
	case 1: {
		__GetEGrp(_newgroup)
#ifdef __CO__
		_the_officer = switch (GVAR(enemy_side)) do {
			case "EAST": {"RU_Commander"};
			case "WEST": {"USMC_Soldier_Officer"};
			case "GUER": {"GUE_Commander"};
		};
#endif
#ifdef __OA__
		_the_officer = switch (GVAR(enemy_side)) do {
			case "EAST": {"TK_Soldier_Officer_EP1"};
			case "WEST": {"US_Soldier_Officer_EP1"};
			case "GUER": {"TK_GUE_Warlord_EP1"};
		};
#endif
		_vehicle = _newgroup createUnit [_the_officer, _poss, [], 0, "FORM"];
		if (GVAR(without_nvg) == 0) then {
			if (_vehicle hasWeapon "NVGoggles") then {_vehicle removeWeapon "NVGoggles"};
		};
		_svec = sizeOf _the_officer;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setPos _poss;
		_vehicle setVariable ["BIS_noCoreConversations", true];
		_vehicle setRank "COLONEL";
		_vehicle setSkill 0.3;
		_vehicle disableAI "MOVE";
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}];
		};
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
#ifndef __TT__
		_iar = __XJIPGetVar(GVAR(searchintel));
		_sum = 0;
		{if (_x == 1) then {__INC(_sum)}} forEach _iar;
		if (_sum < count _iar) then {
			GVAR(intel_unit) = _vehicle;
			[QGVAR(searchbody), _vehicle] call FUNC(NetSetJIP);
			[QGVAR(s_b_client)] call FUNC(NetCallEventToClients);
		} else {
			if (!isNull __XJIPGetVar(GVAR(searchbody))) then {[QGVAR(searchbody), objNull] call FUNC(NetSetJIP)};
			__addDeadAI(_vehicle)
		};
		sleep 0.1;
#else
		__addDeadAI(_vehicle)
		[_vehicle] call FUNC(TTAddKEH);
#endif
		__vkilled(gov_dead);
		if (GVAR(with_ai)) then {
			if (__RankedVer) then {_vehicle addEventHandler ["killed", {[1,_this select 1] call FUNC(AddKillsAI)}]};
		};
		sleep 1.0112;
		__specops;
	};
	case 2: {
		__getPos;
		_ctype =
#ifdef __OA__
		"Land_Fort_Watchtower_EP1";
#endif
#ifdef __CO__
		"Land_vysilac_FM2";
#endif
		_vehicle = createVehicle [_ctype, _poss, [], 0, "NONE"];
		_svec = sizeOf _ctype;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setPos _poss;
		[_vehicle] execFSM "fsms\XRemoveVehiExtra.fsm";
		__vkilled(radar_down);
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddMTObjKillPoints)}}];
		};
		sleep 1.0112;
		__specops;
#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
	case 3: {
		__getPos;
#ifdef __CO__
		_truck = switch (GVAR(enemy_side)) do {
			case "EAST": {"KamazReammo"};
			case "WEST": {"MtvrReammo"};
			case "GUER": {"V3S_Gue"};
		};
#endif
#ifdef __OA__
		_truck = switch (GVAR(enemy_side)) do {
			case "EAST": {"UralReammo_TK_EP1"};
			case "WEST": {"MtvrReammo_DES_EP1"};
			case "GUER": {"V3S_Reammo_TK_GUE_EP1"};
		};
#endif
		_vehicle = createVehicle [_truck, _poss, [], 0, "NONE"];
		_svec = sizeOf _truck;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setDir (floor random 360);
		_vehicle setPos _poss;
		_vehicle lock true;
		_vehicle addEventHandler ["killed", {
			_this set [count _this, "ammo_down"];
			_this call FUNC(MTSMTargetKilled);
			if (GVAR(domdatabase)) then {
				if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddCarKillPoints)};
			};
			_this call FUNC(handleDeadVec);
		}];
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		sleep 1.0112;
		__specops;
		#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
	case 4: {
#ifdef __CO__
		_truck = switch (GVAR(enemy_side)) do {
			case "EAST": {"GAZ_Vodnik_MedEvac"};
			case "WEST": {"HMMWV_Ambulance"};
			case "GUER": {"BMP2_Gue"};
		};
#endif
#ifdef __OA__
		_truck = switch (GVAR(enemy_side)) do {
			case "EAST": {"M113Ambul_TK_EP1"};
			case "WEST": {"HMMWV_Ambulance_DES_EP1"};
			case "GUER": {"M113Ambul_UN_EP1"};
		};
#endif
		_vehicle = createVehicle [_truck, _poss, [], 0, "NONE"];
		_svec = sizeOf _truck;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setDir (floor random 360);
		_vehicle setPos _poss;
		_vehicle lock true;
		if (__ACEVer) then {
			[_vehicle] spawn {
				private "_vehicle";
				PARAMS_1(_vehicle);
				waitUntil {sleep 0.311;!(_vehicle call ace_v_alive)};
				GVAR(side_main_done) = true;
				_s = "apc_down" call FUNC(GetSMTargetMessage);
				["sec_kind",0] call FUNC(NetSetJIP);
				GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"Dummy",["1","",_s,[]],true];
				__addDead(_vehicle)
				sleep 600;
				_vehicle setDamage 1;
			};
		} else {
			_vehicle addEventHandler ["killed", {
				_this set [count _this, "apc_down"];
				_this call FUNC(MTSMTargetKilled);
				if (GVAR(domdatabase)) then {
					if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddCarKillPoints)};
				};
				_this call FUNC(handleDeadVec);
			}];
		};
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		sleep 1.0112;
		__specops;
	};
	case 5: {
		__getPos;
		_vehicle = createVehicle [GVAR(enemy_hq), _poss, [], 0, "NONE"];
		_svec = sizeOf GVAR(enemy_hq);
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setDir (floor random 360);
		_vehicle setPos _poss;
		_vehicle lock true;
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddMTObjKillPoints)}}];
		};
		[_vehicle] execFSM "fsms\XRemoveVehiExtra.fsm";
		__vkilled(hq_down);
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		sleep 1.0112;
		__specops;
#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
	case 6: {
		__getPos;
#ifdef __CO__
		_fact = switch (GVAR(enemy_side)) do {
			case "EAST": {"RU_WarfareBLightFactory"};
			case "WEST": {"USMC_WarfareBLightFactory"};
			case "GUER": {"Gue_WarfareBLightFactory"};
		};
#endif
#ifdef __OA__
		_fact = switch (GVAR(enemy_side)) do {
			case "EAST": {"TK_WarfareBLightFactory_EP1"};
			case "WEST": {"US_WarfareBLightFactory_EP1"};
			case "GUER": {"TK_GUE_WarfareBLightFactory_EP1"};
		};
#endif
		_vehicle = createVehicle [_fact, _poss, [], 0, "NONE"];
		_svec = sizeOf _fact;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setDir (floor random 360);
		_vehicle setPos _poss;
		[_vehicle] execFSM "fsms\XRemoveVehiExtra.fsm";
		__vkilled(light_down);
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddMTObjKillPoints)}}];
		};
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		sleep 1.0112;
		__specops;
#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
	case 7: {
		__getPos;
#ifdef __CO__
		_fact = switch (GVAR(enemy_side)) do {
			case "EAST": {"RU_WarfareBHeavyFactory"};
			case "WEST": {"USMC_WarfareBHeavyFactory"};
			case "GUER": {"Gue_WarfareBHeavyFactory"};
		};
#endif
#ifdef __OA__
		_fact = switch (GVAR(enemy_side)) do {
			case "EAST": {"TK_WarfareBHeavyFactory_EP1"};
			case "WEST": {"US_WarfareBHeavyFactory_EP1"};
			case "GUER": {"TK_GUE_WarfareBHeavyFactory_EP1"};
		};
#endif
		_vehicle = createVehicle [_fact, _poss, [], 0, "NONE"];
		_svec = sizeOf _fact;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setDir (floor random 360);
		_vehicle setPos _poss;
		[_vehicle] execFSM "fsms\XRemoveVehiExtra.fsm";
		__vkilled(heavy_down);
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddMTObjKillPoints)}}];
		};
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		sleep 1.0112;
		__GetEGrp(_newgroup)
		__specops;
#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
	case 8: {
		__getPos;
		_vehicle = createVehicle [GVAR(artillery_radar), _poss, [], 0, "NONE"];
		_svec = sizeOf GVAR(artillery_radar);
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setDir (floor random 360);
		_vehicle setPos _poss;
		[_vehicle] execFSM "fsms\XRemoveVehiExtra.fsm";
		__vkilled(artrad_down);
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddMTObjKillPoints)}}];
		};
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		sleep 1.0112;
		__specops;
#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
	case 9: {
		__getPos;
		_vehicle = createVehicle [GVAR(air_radar), _poss, [], 0, "NONE"];
		_svec = sizeOf GVAR(air_radar);
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setDir (floor random 360);
		_vehicle setPos _poss;
		[_vehicle] execFSM "fsms\XRemoveVehiExtra.fsm";
		__vkilled(airrad_down);
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddMTObjKillPoints)}}];
		};
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		sleep 1.0112;
		__specops;
#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
	case 10: {
		__GetEGrp(_newgroup)
		_ctype =
#ifdef __CO__
		"Ins_Lopotev";
#endif
#ifdef __OA__
		"Dr_Hladik_EP1";
#endif
		_vehicle = _newgroup createUnit [_ctype, _poss, [], 0, "FORM"];
		if (GVAR(without_nvg) == 0) then {
			if (_vehicle hasWeapon "NVGoggles") then {_vehicle removeWeapon "NVGoggles"};
		};
		_svec = sizeOf _ctype;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setPos _poss;
		_vehicle setVariable ["BIS_noCoreConversations", true];
		_vehicle setRank "COLONEL";
		_vehicle setSkill 0.3;
		_vehicle disableAI "MOVE";
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}];
		};
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		for "_i" from 1 to 4 do {_vehicle addMagazine "15Rnd_9x19_M9"};
		_vehicle addWeapon "M9";
#ifndef __TT__
		_iar = __XJIPGetVar(GVAR(searchintel));
		_sum = 0;
		{if (_x == 1) then {__INC(_sum)}} forEach _iar;
		if (_sum < count _iar) then {
			GVAR(intel_unit) = _vehicle;
			[QGVAR(searchbody), _vehicle] call FUNC(NetSetJIP);
			[QGVAR(s_b_client)] call FUNC(NetCallEventToClients);
		} else {
			if (!isNull __XJIPGetVar(GVAR(searchbody))) then {[QGVAR(searchbody), objNull] call FUNC(NetSetJIP)};
			__addDeadAI(_vehicle)
		};
		sleep 0.1;
#else
		__addDeadAI(_vehicle)
		[_vehicle] call FUNC(TTAddKEH);
#endif
		__vkilled(lopo_dead);
		if (GVAR(with_ai)) then {
			if (__RankedVer) then {_vehicle addEventHandler ["killed", {[1,_this select 1] call FUNC(AddKillsAI)}]};
		};
		sleep 1.0112;
		__specops;
	};
	case 11: {
		__GetEGrp(_newgroup)
		_ctype =
#ifdef __CO__
		"Rocker3";
#endif
#ifdef __OA__
		"CIV_EuroMan01_EP1";
#endif
		_vehicle = _newgroup createUnit [_ctype, _poss, [], 0, "FORM"];
		if (GVAR(without_nvg) == 0) then {
			if (_vehicle hasWeapon "NVGoggles") then {_vehicle removeWeapon "NVGoggles"};
		};
		_svec = sizeOf _ctype;
		_isFlat = (position _vehicle) isFlatEmpty [_svec / 2, 150, 0.7, _svec, 0, false, _vehicle];
		if (count _isFlat > 1) then {
			_isFlat set [2,0];
			if (_poss distance _isFlat < 100) then {
				_poss = _isFlat;
			};
		};
		_vehicle setPos _poss;
		_vehicle setVariable ["BIS_noCoreConversations", true];
		_vehicle setRank "COLONEL";
		_vehicle setSkill 0.3;
		[_vehicle, __XJIPGetVar(GVAR(current_target_index))] spawn _fixor;
		_vehicle disableAI "MOVE";
		if (GVAR(domdatabase)) then {
			_vehicle addEventHandler ["killed", {if (isPlayer (_this select 1)) then {(_this select 1) call FUNC(PAddAIKillPoints)}}];
		};
		for "_i" from 1 to 4 do {_vehicle addMagazine "15Rnd_9x19_M9"};
		_vehicle addWeapon "M9";
#ifndef __TT__
		_iar = __XJIPGetVar(GVAR(searchintel));
		_sum = 0;
		{if (_x == 1) then {__INC(_sum)}} forEach _iar;
		if (_sum < count _iar) then {
			GVAR(intel_unit) = _vehicle;
			[QGVAR(searchbody), _vehicle] call FUNC(NetSetJIP);
			[QGVAR(s_b_client)] call FUNC(NetCallEventToClients);
		} else {
			if (!isNull __XJIPGetVar(GVAR(searchbody))) then {[QGVAR(searchbody), objNull] call FUNC(NetSetJIP)};
			__addDeadAI(_vehicle)
		};
		sleep 0.1;
#else
		__addDeadAI(_vehicle)
#endif
		__vkilled(dealer_dead);
		if (GVAR(with_ai)) then {
			if (__RankedVer) then {_vehicle addEventHandler ["killed", {[1,_this select 1] call FUNC(AddKillsAI)}]};
		};
		sleep 1.0112;
		__specops;
#ifdef __TT__
		[_vehicle] call FUNC(TTAddKEH);
#endif
	};
};

["sec_kind",_sec_kind] call FUNC(NetSetJIP);
_s = "";
if (__XJIPGetVar(GVAR(current_target_index)) != -1) then {
	_s = (switch (_sec_kind) do {
		case 1: {
			format [(localize "STR_DOM_MISSIONSTRING_891"), _current_target_name]
		};
		case 2: {
#ifdef __CO__
			format [(localize "STR_DOM_MISSIONSTRING_892"), _current_target_name]
#endif
#ifdef __OA__
			format [(localize "STR_DOM_MISSIONSTRING_893"), _current_target_name]
#endif
		};
		case 3: {
			#ifndef __TT__
			format [(localize "STR_DOM_MISSIONSTRING_894"), _current_target_name]
			#else
			format [(localize "STR_DOM_MISSIONSTRING_895"), _current_target_name]
			#endif
		};
		case 4: {
			#ifndef __TT__
			format [(localize "STR_DOM_MISSIONSTRING_896"), _current_target_name]
			#else
			format [(localize "STR_DOM_MISSIONSTRING_897"), _current_target_name]
			#endif
		};
		case 5: {
			format [(localize "STR_DOM_MISSIONSTRING_898"), _current_target_name]
		};
		case 6: {
			format [(localize "STR_DOM_MISSIONSTRING_899"), _current_target_name]
		};
		case 7: {
			format [(localize "STR_DOM_MISSIONSTRING_900"), _current_target_name]
		};
		case 8: {
			format [(localize "STR_DOM_MISSIONSTRING_901"), _current_target_name]
		};
		case 9: {
			format [(localize "STR_DOM_MISSIONSTRING_902"), _current_target_name]
		};
		case 10: {
			format [(localize "STR_DOM_MISSIONSTRING_903"), _current_target_name]
		};
		case 11: {
			format [(localize "STR_DOM_MISSIONSTRING_904"), _current_target_name]
		};
	});
} else {
	_s = (localize "STR_DOM_MISSIONSTRING_905");
};
#ifndef __TT__
GVAR(kb_logic1) kbTell [GVAR(kb_logic2),GVAR(kb_topic_side),"TellSecondaryMTM",["1","",_s,[]],true];
#else
GVAR(hq_logic_en1) kbTell [GVAR(hq_logic_en2),"HQ_W","TellSecondaryMTM",["1","",_s,[]],true];
GVAR(hq_logic_ru1) kbTell [GVAR(hq_logic_ru2),"HQ_E","TellSecondaryMTM",["1","",_s,[]],true];
#endif
