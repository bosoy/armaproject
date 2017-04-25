// by Xeno
private ["_pos", "_unitliste", "_grp", "_with_nv", "_with_map", "_units", "_grpskill", "_one_unit"];
_pos = _this select 0;
_unitliste = _this select 1;
_grp = _this select 2;
_with_nv = if (count _this > 3) then {_this select 3} else {true};
_with_map = if (count _this > 4) then {_this select 4} else {true};
_units = [];

_grpskill = (d_skill_array select 0) + (random (d_skill_array select 1));
{
	_one_unit = _grp createunit [_x, _pos, [], 10,"NONE"];[_one_unit] joinSilent _grp;
	if ((format["%1",_one_unit getVariable "ke"]) == "<null>") then {allunits_add set [count allunits_add, _one_unit];_one_unit setVariable ["ke", 1]};
	if (!_with_nv) then {_one_unit removeWeapon "NVGoggles"};
	if (!_with_map) then {_one_unit removeWeapon "ItemMap"};
	[_units, _one_unit] call BIS_fnc_arrayPush;sleep 0.01
} forEach _unitliste;
_units
