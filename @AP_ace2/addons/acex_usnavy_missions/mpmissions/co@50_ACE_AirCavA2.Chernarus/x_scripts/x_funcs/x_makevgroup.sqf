// by Xeno
private ["_numbervehicles", "_pos", "_crewmember", "_vehiclename", "_grp", "_radius", "_direction", "_with_nv", "_with_map", "_the_vehicles", "_grpskill", "_n", "_dir", "_vec_array", "_vehicle"];

_numbervehicles = _this select 0;
_pos = _this select 1;
_crewmember = _this select 2;
_vehiclename = _this select 3;
_grp = _this select 4;
_radius = _this select 5;
_direction = _this select 6;
_with_nv = if (count _this > 7) then {_this select 7} else {true};
_with_map = if (count _this > 8) then {_this select 8} else {true};
_the_vehicles = [];

_grpskill = (d_skill_array select 0) + (random (d_skill_array select 1));

_the_vehicles resize _numbervehicles;

for "_n" from 0 to _numbervehicles - 1 do {
	sleep 0.331;
	_dir = if (_direction != -1.111) then {_direction} else {floor random 360};

	_vec_array = [_pos, _dir, _vehiclename, _grp] call X_fnc_spawnVehicle;
	_vehicle = _vec_array select 0;

	_the_vehicles set [_n,_vehicle];

	if (x_lock_spawned) then {_vehicle lock true};
	sleep 0.543;
	{
		if ((format["%1",_x getVariable "ke"]) == "<null>") then {
			allunits_add set [count allunits_add, _x];
			_x setVariable ["ke", 1];
		};
		if (!_with_nv) then {_x removeWeapon "NVGoggles"};
		if (!_with_map) then {_x removeWeapon "ItemMap"};
	} forEach (_vec_array select 1);

	if ((format["%1",_vehicle getVariable "ke"]) == "<null>") then {
		_vehicle execFSM "fsms\RemoveVehi.fsm";
		allunits_add set [count allunits_add, _vehicle];
		_vehicle setVariable ["ke", 1];
	};
};
_the_vehicles
