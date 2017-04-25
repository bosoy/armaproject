// by Xeno
#define THIS_FILE "x_handleobservers.sqf"
#include "x_setup.sqf"
private ["_nextaritime", "_height", "_type", "_radius", "_i", "_observer", "_enemy", "_distance", "_man_type"];
if (!isServer) exitWith {};

_enemy_ari_available = true;
_nextaritime = 0;
_height = 150;
_type = "";
_radius = 30;

#ifndef __TT__
_man_type = switch (GVAR(enemy_side)) do {
	case "WEST": {"SoldierWB"};
	case "EAST": {"SoldierEB"};
	case "GUER": {"SoldierGB"};
};
#else
_man_type = ["SoldierWB","SoldierEB"];
#endif

if (isNil QUOTE(FUNC(shootari))) then {__cppfln(FUNC(shootari),x_server\x_shootari.sqf)};

sleep 10.123;
while {GVAR(nr_observers) > 0} do {
	GVAR(ai_artiller_unit_vecs) = GVAR(ai_artiller_unit_vecs) - [objNull];
	__MPCheck;
	for "_i" from 0 to 2 do {
		private "_observer";
		_observer = GVAR(obs_array) select _i;
		if (!isNull _observer && alive _observer) then {
			if (_enemy_ari_available) then {
				_enemy = _observer findNearestEnemy _observer;
				if (!isNull _enemy && (_observer knowsAbout _enemy >= 1.5) && !((vehicle _enemy) isKindOf "Air")) then {
					_distance = _observer distance _enemy;
					if (_distance < 500) then {
						_pos_nearest = [getPosASL _enemy select 0, getPosASL _enemy select 1, 0];
						_near_targets = _pos_nearest nearEntities [_man_type, 35];
						if (count _near_targets == 0) then {
							_enemy_ari_available = false;
							_nextaritime = time + GVAR(ai_arti_available_time) + (random 120);
							[_pos_nearest,floor (random 2)] spawn FUNC(shootari);
						} else {
							_enemy_ari_available = false;
							_nextaritime = time + GVAR(ai_arti_available_time) + (random 120);
							if ((random 100) < 15) then {// 1 to 6 chance for smoke
								[_pos_nearest,2] spawn FUNC(shootari);
							};
						};
					};
				};
			};
			sleep 2.321;
		};
	};
	sleep 5.123;
	if (time > _nextaritime && !_enemy_ari_available) then {_enemy_ari_available = true};
};
