// by Xeno
#define THIS_FILE "x_checkveckillwest.sqf"
#include "x_setup.sqf"
private ["_killer", "_killed", "_strkil", "_kpar", "_sidekiller"];
_killer = _this select 1;

if (isPlayer _killer) then {
	_killed = _this select 0;
	
	_strkil = getPlayerUID _killer;
	_kpar = GV(GVAR(player_store),_strkil);
	_sidekiller = if (!isNil "_kpar") then {_kpar select 5} else {sideUnknown};

	if (_sidekiller == east) then {
		GVAR(points_east) = GVAR(points_east) + (GVAR(tt_points) select 7);
		[QGVAR(vec_killer), [_kpar select 6, "US", "EAST"]] call FUNC(NetCallEventToClients);
		
		if (GVAR(domdatabase)) then {
			switch (true) do {
				case (_killed isKindOf "Tank"): {_kpar set [23, (_kpar select 23) + 1]};
				case (_killed isKindOf "Wheeled_APC"): {_kpar set [22, (_kpar select 22) + 1]};
				case (_killed isKindOf "Car"): {_kpar set [21, (_kpar select 21) + 1]};
				case (_killed isKindOf "Car"): {_kpar set [21, (_kpar select 21) + 1]};
				case (_killed isKindOf "Plane"): {_kpar set [24, (_kpar select 24) + 1]};
				case (_killed isKindOf "Helicopter"): {_kpar set [25, (_kpar select 25) + 1]};
			};
		};
	};
};