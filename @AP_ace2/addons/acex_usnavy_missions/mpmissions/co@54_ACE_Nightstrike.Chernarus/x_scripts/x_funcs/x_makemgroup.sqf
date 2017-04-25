// by Xeno
private ["_pos", "_unitliste", "_grp", "_with_nv", "_with_gps", "_units", "_grpskill", "_one_unit"];
_pos = _this select 0;
_unitliste = _this select 1;
_grp = _this select 2;
_with_nv = if (count _this > 3) then {_this select 3} else {true};
_with_gps = if (count _this > 4) then {_this select 4} else {true};
_units = [];

_grpskill = (d_skill_array select 0) + (random (d_skill_array select 1));
{
	_one_unit = _grp createunit [_x, _pos, [], 10,"NONE"];[_one_unit] joinSilent _grp;
	if (isNil {_one_unit getVariable "ke"}) then {allunits_add set [count allunits_add, _one_unit];_one_unit setVariable ["ke", 1]};
	if (!_with_nv) then {if (_one_unit hasWeapon "NVGoggles") then {_one_unit removeWeapon "NVGoggles"}};
	if (!_with_gps) then {if (_one_unit hasWeapon "ItemGPS") then {_one_unit removeWeapon "ItemGPS"}};
	_units set [count _units, _one_unit];sleep 0.01
} forEach _unitliste;
_units
