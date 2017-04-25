private ["_vec","_gr"];
if (!isServer) exitWith {};

sleep 4.321;

{
	if ((side _x) in x_addkilledhandler) then {
		if (_x isKindOf "Man") then { // not needed, I guess ;)
			_gr = group _x;
			if ((format["%1",_gr getVariable "gr_a"]) == "<null>") then {
				_gr setVariable ["gr_a", 1];
				_gr setVariable ["X_CREATED", time + 120];
			};
			if (!(isPlayer _x)) then {
				if ((format["%1",_x getVariable "ke"]) == "<null>") then {
					allunits_add set [count allunits_add, _x];
					_x setVariable ["ke", 1];
				};
			};
			if (vehicle _x != _x) then {
				_vec = vehicle _x;
				if ((format["%1",_vec getVariable "ke"]) == "<null>") then {
					_vec execFSM "fsms\RemoveVehi.fsm";
					allunits_add set [count allunits_add, _vec];
					_vec setVariable ["ke", 1];
				};
			};
		};
	};
	sleep 0.423;
} forEach allUnits;

if (true) exitWith {};