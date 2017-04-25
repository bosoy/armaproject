private ["_aid","_caller","_coef","_damage","_damage_ok","_damage_val","_fuel","_fuel_ok","_fuel_val","_rep_count","_rep_array"];
_caller = _this select 1;
_aid = _this select 2;
_caller removeAction _aid;
if (!(local _caller)) exitWith {};
_rep_array = [x_repair_obj];
_rep_count = 4;

if (x_repair_obj isKindOf "Air") then {
	_rep_count = 0.1;
} else {
	if (x_repair_obj isKindOf "Tank") then {
		_rep_count = 0.2;
	} else {
		_rep_count = 0.3;
	};
};

_fuel = 1;//fuel x_repair_obj;
_damage = damage x_repair_obj;

_damage_val = (_damage / _rep_count);
_fuel_val = ((1 - _fuel) / _rep_count);
_coef = (
	if (_fuel_val == _damage_val) then {
		_damage_val
	} else {
		if (_fuel_val > _damage_val) then {
			_fuel_val
		} else {
			_damage_val
		}
	}
);
_coef = ceil _coef;

hint format ["Vehicle status:\n---------------------\nDamage: %1", _damage];
player sideChat format ["Repairing ... Stand by", typeOf (x_repair_obj)];
disableUserInput true;
_damage_ok = false;
_fuel_ok = false;
for "_wc" from 1 to _coef do {
	if (!alive player) exitWith {disableUserInput false;};
	player sideChat "Still working...";
	player playMove "AinvPknlMstpSlayWrflDnon_medic";
	sleep 3.0;
	WaitUntil {animationState player != "AinvPknlMstpSlayWrflDnon_medic"};
	if (!_fuel_ok) then {_fuel = _fuel + _rep_count;};
	if (_fuel >= 1 && !_fuel_ok) then {_fuel = 1;_fuel_ok = true;};
	if (!_damage_ok) then {_damage = _damage - _rep_count;};
	if (_damage <= 0.01 && !_damage_ok) then {_damage = 0;_damage_ok = true;};
	hint format ["Vehicle status:\n---------------------\nDamage: %1", _damage];
};
if (!alive player) exitWith {disableUserInput false;};
rep_array = _rep_array;
publicVariable "rep_array";
[_rep_array select 0] spawn XCallRep;
player sideChat format ["%1 repaired", typeOf (x_repair_obj)];
disableUserInput false;

if (true) exitWith {};