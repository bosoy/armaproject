private ["_vec","_gr"];
if (!isServer) exitWith {};

sleep 4.321;

{
	if ((side _x) in x_addkilledhandler) then {
		if (_x isKindOf "Man") then { // not needed, I guess ;)
			_gr = group _x;
			if (isNil {_gr getVariable "gr_a"}) then {
				_gr setVariable ["gr_a", 1];
				_gr setVariable ["X_CREATED", time + 120];
			};
			if (!(isPlayer _x)) then {
				if (isNil {_x getVariable "ke"}) then {
					allunits_add set [count allunits_add, _x];
					_x setVariable ["ke", 1];
				};
				if (_x hasWeapon "NVGoggles") then {_x removeWeapon "NVGoggles"};
				if (_x hasWeapon "ItemGPS") then {_x removeWeapon "ItemGPS"};
			};
			if (vehicle _x != _x) then {
				_vec = vehicle _x;
				if (isNil {_vec getVariable "ke"}) then {
					_vec setVariable ["ke", 1];
					allunits_add set [count allunits_add, _vec];
				};
			};
		};
	};
	sleep 0.423;
} forEach allUnits;

if (true) exitWith {};