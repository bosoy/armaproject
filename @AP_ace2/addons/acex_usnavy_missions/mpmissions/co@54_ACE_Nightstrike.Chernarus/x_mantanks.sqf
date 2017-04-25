private ["_tank_counter", "_xstate","_unit","_orderunits","_grp"];

if (!isServer) exitWith {};

sleep 5;

if (({alive _x} count d_tankunits) > 0) then {
	_grp = objNull;
	_tank_counter = 1;
	_xstate = 0;
	_tank = t90_1;
	_orderunits = [];
	{
		_unit = _x;
		if (!isNull _unit && alive _unit) then {
			if (isNull _grp) then {
				_grp = group _unit;
			};
			switch (_xstate) do {
				case 0: {
					_unit assignAsDriver _tank;
				};
				case 1: {
					_unit assignAsGunner _tank;
				};
				case 2: {
					_unit assignAsCommander _tank;
				};
			};
			_orderunits set [count _orderunits, _unit];
			_xstate = _xstate + 1;
			if (_xstate == 3) then {
				_xstate = 0;
				_tank_counter = _tank_counter + 1;
				if (_tank_counter < 5) then {
					_tank = missionNamespace getVariable format ["t90_%1", _tank_counter];
				};
			};
		};
	} forEach d_tankunits;
	if (count _orderunits > 0) then {
		_orderunits orderGetIn true;
	};
	if (!isNull _grp) then {
		_grp setCombatMode "YELLOW";
		_grp setBehaviour "COMBAT";
	};
};

if (true) exitWith {};