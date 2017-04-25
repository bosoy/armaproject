forbiddenWeapons = [];
forbiddenMagazines = [];

{
	if (player hasWeapon _x) then
	{
		player removeWeapon _x;
	};
	if (player getVariable "ACE_WeaponOnBack" == _x) then
	{
		player setVariable ["ACE_WeaponOnBack", ""];
	};
} forEach forbiddenWeapons;

{
	if (_x in forbiddenMagazines) then
	{
		player removeMagazine "_x";
	};
} forEach magazines player;

//{
//	if (_x in forbiddenMagazines) then
//	{
//		player setVariable ["ACE_RuckMagContents", []];
//	};
//} forEach (player call ACE_fnc_RuckMagazinesList);
//
//{
//	if (_x in forbiddenMagazines) then
//	{
//		player setVariable ["ACE_RuckWepContents", []];
//	};
//} forEach (player call ACE_fnc_RuckWeaponsList);


customWeapons = weapons player;
customMagazines = magazines player;
customBack = player getVariable "ACE_WeaponOnBack";
//backpackMags = [player] call ACE_fnc_RuckMagazinesList;
//backpackWeapons = [player] call ACE_fnc_RuckWeaponsList;

//hint "Loadout saved";