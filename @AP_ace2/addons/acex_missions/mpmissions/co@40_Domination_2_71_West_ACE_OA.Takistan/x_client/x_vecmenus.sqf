#define THIS_FILE "x_vecmenus.sqf"
#include "x_setup.sqf"
while {true} do {
	_type = "";
	_vec = objNull;
	waitUntil {alive player};
	waitUntil {sleep (0.2 + random 0.3);vehicle player != player};
	_vec = vehicle player;
	_added = false;
	if (!(_vec isKindOf "ParachuteBase") && !(_vec isKindOf "BIS_Steerable_Parachute")) then {
		if (count d_action_menus_vehicle > 0) then {
			_type = typeOf _vec;
			{
				_entry = _x;
				if (count (_entry select 0) > 0) then {
					if (_type in (_entry select 0)) then {
						_action = _vec addAction [(_entry select 1) call FUNC(GreyText), _entry select 2,[],-1,false];
						_entry set [3, _action];
					};
				} else {
					_action = _vec addAction [(_entry select 1) call FUNC(GreyText), _entry select 2,[],-1,false];
					_entry set [3, _action];
				};
			} forEach d_action_menus_vehicle;
			_added = true;
		};
	};
	waitUntil {sleep (0.2 + random 0.3);vehicle player == player};
	if (_added) then {
		{
			_entry = _x;
			if (count (_entry select 0) > 0) then {
				if (_type in (_entry select 0)) then {
					_action = _entry select 3;
					_vec removeAction _action;
					_entry set [3, -1000];
				};
			} else {
				_action = _entry select 3;
				_vec removeAction _action;
				_entry set [3, -1000];
			};
		} forEach GVAR(action_menus_vehicle);
	};
};
