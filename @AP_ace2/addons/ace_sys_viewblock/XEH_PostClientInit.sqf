//#define DEBUG_MODE_FULL
#include "script_component.hpp"

ADDON = false;
LOG(MSG_INIT);

if (!isNil QGVAR(blockgrass)) then {
	FUNC(getUnitStance) = {
		private ["_unit", "_selz"];
		_unit = _this;
		if (isNull _unit) exitWith {""};
		if (vehicle _unit != _unit) exitWith {""};
		_selz = (_unit selectionPosition "neck") select 2;
		if (_selz == 0) exitWith {""};
		if (_selz > 1.4) exitWith {"stand"};
		if (_selz > 0.8) exitWith {"kneel"};
		"prone"
	};
	
	0 spawn {
		#define SurfaceTypes ["#CRGRASS1","#CRGRASS2","#CRGRASSW1","#CRGRASSW2","#UTGRASS","#TKPOLE"]
		private ["_block_ceated", "_old_pos", "_old_dir"];
		sleep (10 + random 10);
		_block_ceated = false;
		_old_pos = [0,0,0];
		_old_dir = -999;
		while {true} do {
			#ifdef DEBUG_MODE_FULL
			_stance = player call FUNC(getUnitStance);
			TRACE_1("",_stance);
			#endif
			if (!_block_ceated) then {
				if (alive player && {vehicle player == player} && {(player call FUNC(getUnitStance)) == "prone"} && {(toUpper(surfaceType (getPosASL player)) in SurfaceTypes)}) then {
					[QGVAR(createaivb), player] call ACE_fnc_clientToServerEvent;
					_block_ceated = true;
					_old_pos = position player;
					_old_dir = direction player;
					TRACE_1("",_block_ceated);
				};
			} else {
				if (!alive player || {vehicle player != player} || {(player call FUNC(getUnitStance)) != "prone"} || {!(toUpper(surfaceType (getPosASL player)) in SurfaceTypes)}) then {
					[QGVAR(delaivb), player] call ACE_fnc_clientToServerEvent;
					_block_ceated = false;
					TRACE_1("send del to server",_block_ceated);
				} else {
					_new_dir = direction player;
					_new_pos = position player;
					if (_new_dir != _old_dir || {_new_pos distance _old_pos > 0.3}) then {
						[QGVAR(moveaivb), player] call ACE_fnc_clientToServerEvent;
						_old_pos = _new_pos;
						_old_dir = _new_dir;
						TRACE_1("send move to server",_block_ceated);
					};
				};
			};
			sleep 1;
		};
	};
};

ADDON = true;