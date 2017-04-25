// by Xeno
private ["_weapons", "_magazines", "_p", "_hasruck", "_ruckmags", "_ruckweapons", "_backwep", "_types", "_type", "_action", "_ar", "_primw", "_muzzles", "_s", "_items"];
_weapons = [];
_magazines = [];

while {true} do {
	waitUntil {!alive player};

	_p = player;
	_ubackp = if (!isNull (unitBackpack _p)) then {typeOf (unitBackpack _p)} else {""};
	_weapons = weapons _p;
	_magazines = magazines _p;
	_items = items _p;

	waitUntil {alive player};

	_p = player;

	removeBackpack _p;
	removeAllItems _p;
	removeAllWeapons _p;
	#define __addmx _p addMagazine _x
	#define __addwx _p addWeapon _x

	{__addmx} forEach _magazines;
	{__addwx} forEach _weapons;
	{if !(_p hasWeapon _x) then {_p addWeapon _x}} forEach _items;

		_primw = primaryWeapon _p;
		if (_primw != "") then {
			_p selectWeapon _primw;
			_muzzles = getArray(configFile>>"cfgWeapons" >> _primw >> "muzzles");
			_p selectWeapon (_muzzles select 0);
		};

	if (_ubackp != "") then {_p addBackPack _ubackp;};

	if (_p hasWeapon "NVGoggles") then {if (daytime > 18.5 || daytime < 6.25) then {_p action ["NVGoggles",_p]}};
	sleep 5;
};

if (true) exitWith {};