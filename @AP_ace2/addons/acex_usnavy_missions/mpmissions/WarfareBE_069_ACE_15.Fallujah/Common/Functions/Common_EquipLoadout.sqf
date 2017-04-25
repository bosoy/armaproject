Private['_ammo','_unit','_weapon','_weapons'];

_unit = _this select 0;
_weapons = _this select 1;
_ammo = _this select 2;

removeAllWeapons _unit;
removeAllItems _unit;

{_unit addMagazine _x} forEach _ammo;
{_unit addWeapon _x} forEach _weapons;

_weapon = primaryWeapon _unit;
if (_weapon != '') then {_unit selectWeapon _weapon};