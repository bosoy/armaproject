// by Xeno
//#define __DEBUG__
#define THIS_FILE "x_helilift.sqf"
#include "x_setup.sqf"
private ["_vehicle", "_nearest", "_id", "_pos", "_nobjects", "_dummy", "_depl", "_nx", "_ny", "_px", "_py", "_npos", "_fuelloss"];
if (!X_Client) exitWith {};

PARAMS_1(_vehicle);

_menu_lift_shown = false;
_nearest = objNull;
_id = -1212;
_release_id = -1212;

_vehicle setVariable [QGVAR(Vehicle_Attached), false];
_vehicle setVariable [QGVAR(Vehicle_Released), false];
_vehicle setVariable [QGVAR(Attached_Vec), objNull];

sleep 10.123;

_possible_types = GV(_vehicle,GVAR(lift_types));

while {alive _vehicle && alive player && (player in _vehicle)} do {
	if ((driver _vehicle) == player) then {
		_pos = getPos _vehicle;
		
		if (!(GV(_vehicle,GVAR(Vehicle_Attached))) && {(_pos select 2 > 2.5) && (_pos select 2 < 11)}) then {
			_nearest = objNull;
			_nobjects = nearestObjects [(position _vehicle), ["LandVehicle","Air"], 40];
			if (count _nobjects > 0) then {
				_dummy = _nobjects select 0;
				if (_dummy == _vehicle) then {
					if (count _nobjects > 1) then {_nearest = _nobjects select 1};
				} else {
					_nearest = _dummy;
				};
			};
			if (!isNull _nearest) then {
				if (_nearest isKindOf "CAManBase") then {
					_nearest = objNull;
				} else {
					if ((speed _nearest > 10) || {(position _nearest select 2 > 5) || !((toUpper (typeof _nearest)) in _possible_types)}) then {_nearest = objNull};
				};
			};
			sleep 0.1;
			if (!isNull _nearest && _nearest != (GV(_vehicle,GVAR(Attached_Vec)))) then {
				_depl = GV(_nearest,GVAR(MHQ_Deployed));
				if (isNil "_depl") then {_depl = false};
				if (!_depl) then {
					_nearest_pos = getPos _nearest;
					_nx = _nearest_pos select 0;_ny = _nearest_pos select 1;_px = _pos select 0;_py = _pos select 1;
					if ((_px <= _nx + 10 && _px >= _nx - 10) && {(_py <= _ny + 10 && _py >= _ny - 10)}) then {
						if (!_menu_lift_shown) then {
							_id = _vehicle addAction [(localize "STR_DOM_MISSIONSTRING_250") call FUNC(BlueText), "x_client\x_heli_action.sqf",-1,100000];
							_menu_lift_shown = true;
						};
					} else {
						_nearest = objNull;
						if (_menu_lift_shown) then {
							_vehicle removeAction _id;
							_id = -1212;
							_menu_lift_shown = false;
						};
					};
				};
			};
		} else {
			if (_menu_lift_shown) then {
				_vehicle removeAction _id;
				_id = -1212;
				_menu_lift_shown = false;
			};
			
			sleep 0.1;
			
			if (isNull _nearest) then {
				_vehicle setVariable [QGVAR(Vehicle_Attached), false];
				_vehicle setVariable [QGVAR(Vehicle_Released), false];
			} else {
				if (GV(_vehicle,GVAR(Vehicle_Attached))) then {
					_release_id = _vehicle addAction [(localize "STR_DOM_MISSIONSTRING_251") call FUNC(RedText), "x_client\x_heli_release.sqf",-1,100000];
					[_vehicle, (localize "STR_DOM_MISSIONSTRING_252")] call FUNC(VehicleChat);
					_vehicle setVariable [QGVAR(Attached_Vec), _nearest];
					
					switch (_nearest) do {
						case MRR1: {
							["mr1_in_air",true] call FUNC(NetSetJIP);
							#ifndef __TT__
							player kbTell [GVAR(kb_logic1),GVAR(kb_topic_side),"Dmr1_in_air",true];
							#else
							player kbTell [GVAR(hq_logic_en1),"HQ_W","Dmr1_in_air",true];
							#endif
							[QGVAR(mr1_l_c), _vehicle] call FUNC(NetCallEventCTS);
						};
						case MRR2: {
							["mr2_in_air",true] call FUNC(NetSetJIP);
							#ifndef __TT__
							player kbTell [GVAR(kb_logic1),GVAR(kb_topic_side),"Dmr2_in_air",true];
							#else
							player kbTell [GVAR(hq_logic_en1),"HQ_W","Dmr2_in_air",true];
							#endif
							[QGVAR(mr2_l_c), _vehicle] call FUNC(NetCallEventCTS);
						};
#ifdef __TT__
						case MRRR1: {
							["mrr1_in_air",true] call FUNC(NetSetJIP);
							player kbTell [GVAR(hq_logic_ru1),"HQ_E","Dmr1_in_air",true];
							[QGVAR(mrr1_l_c), _vehicle] call FUNC(NetCallEventCTS);
						};
						case MRRR2: {
							["mrr2_in_air",true] call FUNC(NetSetJIP);
							player kbTell [GVAR(hq_logic_ru1),"HQ_E","Dmr2_in_air",true];
							[QGVAR(mrr2_l_c), _vehicle] call FUNC(NetCallEventCTS);
						};
#endif
					};
					
					_fuelloss = switch (true) do {
						case (_vehicle isKindOf "Wheeled_APC"): {0.0002};
						case (_vehicle isKindOf "Car"): {0.0001};
						case (_vehicle isKindOf "Air"): {0.0003};
						case (_vehicle isKindOf "TANK"): {0.0005};
						default {0.0001};
					};
					
					_nearest engineOn false;
//#ifndef __TOH__
					_nearest attachTo [_vehicle, [0,0,-15]];
//#else
//					_vehicle animate ["AddCargoHook_Cover", 0];
//					_vehicle animate ["AddCargoHook", 1];
//					private "_rope";
//					_rope = ropeCreate [_vehicle, "slingload0", _nearest,[0,0,0], 10, 25];
//					ropeSetCargoMass [_rope, _nearest, 1000];
//#endif
					while {alive _vehicle && alive _nearest && alive player && !(GV(_vehicle,GVAR(Vehicle_Released))) && (player in _vehicle)} do {
						_vehicle setFuel ((fuel _vehicle) - _fuelloss);
						sleep 0.312;
					};
//#ifndef __TOH__
					detach _nearest;
//#else
//					if (alive _vehicle) then {
//						_vehicle animate ["AddCargoHook_Cover", 1];
//						_vehicle animate ["AddCargoHook", 0];
//					};
//					ropeDestroy _rope;
//#endif
					_nearest setVelocity [0,0,0];
					_nearest engineOn false;
					if (position _nearest select 2 > 5) then {
						_nearest spawn {
							while {position _this select 2 > 5} do {
								_this setDamage ((damage _this) + 0.01);
								sleep 0.1;
								if (!alive _this) exitWith {};
							};
						};
					};
					
					_vehicle setVariable [QGVAR(Vehicle_Attached), false];
					_vehicle setVariable [QGVAR(Vehicle_Released), false];
					
					switch (_nearest) do {
						case MRR1: {
							["mr1_in_air",false] call FUNC(NetSetJIP);
							[QGVAR(mr1_l_c), objNull] call FUNC(NetCallEventCTS);
							#ifndef __TT__
							player kbTell [GVAR(kb_logic1),GVAR(kb_topic_side),"Dmr1_available",true];
							#else
							player kbTell [GVAR(hq_logic_en1),"HQ_W","Dmr1_available",true];
							#endif
						};
						case MRR2: {
							["mr2_in_air",false] call FUNC(NetSetJIP);
							[QGVAR(mr2_l_c), objNull] call FUNC(NetCallEventCTS);
							#ifndef __TT__
							player kbTell [GVAR(kb_logic1),GVAR(kb_topic_side),"Dmr2_available",true];
							#else
							player kbTell [GVAR(hq_logic_en1),"HQ_W","Dmr2_available",true];
							#endif
						};
#ifdef __TT__
						case MRRR1: {
							["mrr1_in_air",false] call FUNC(NetSetJIP);
							[QGVAR(mrr1_l_c), objNull] call FUNC(NetCallEventCTS);
							player kbTell [GVAR(hq_logic_ru1),"HQ_E","Dmr1_available",true];
						};
						case MRRR2: {
							["mrr2_in_air",false] call FUNC(NetSetJIP);
							[QGVAR(mrr2_l_c), objNull] call FUNC(NetCallEventCTS);
							player kbTell [GVAR(hq_logic_ru1),"HQ_E","Dmr2_available",true];
						};
#endif
					};
					
					_vehicle setVariable [QGVAR(Attached_Vec), objNull];
					
					if (!alive _vehicle) then {
						_vehicle removeAction _release_id;
					} else {
						if (alive _vehicle && alive player) then {[_vehicle, (localize "STR_DOM_MISSIONSTRING_253")] call FUNC(VehicleChat)};
					};
					
					if (!(_nearest isKindOf "StaticWeapon") && (position _nearest) select 2 < 200) then {
						waitUntil {sleep 0.222;(position _nearest) select 2 < 10};
					} else {
						_npos = position _nearest;
						_nearest setPos [_npos select 0, _npos select 1, 0];
					};
					_nearest setVelocity [0,0,0];
					
					sleep 1.012;
				};
			};
		};
	};
	sleep 0.51;
};

if (alive _vehicle) then {
	if (_id != -1212) then {_vehicle removeAction _id};
	if (_release_id != -1212) then {_vehicle removeAction _release_id};
};