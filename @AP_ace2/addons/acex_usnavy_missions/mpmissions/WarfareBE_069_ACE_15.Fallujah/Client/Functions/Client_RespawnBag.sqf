private ["_add"];

if !(isNil 'respawnBag') then {
	_add = false;
	/* Player did purchase a backpack and have one by default */
	if !(isNull (unitBackPack player)) then {
		/* If the backpack type is different from the current one, then we remove it */
		if (typeOf (unitBackPack player) != respawnBag) then {
			removeBackpack player;
			_add = true;
		};
	} else {
		_add = true;
	};

	/* We give a new backpack to the player */
	if (_add) then {player addBackpack respawnBag};
	
	/* We clear the new backpack content */
	clearMagazineCargo (unitBackpack player);
	
	/* We add the player's backpack content inside the new one */
	if (count (respawnBagContent select 0) > 0) then {
		for '_u' from 0 to count(respawnBagContent select 0)-1 do {
			(unitBackpack player) addMagazineCargo [(respawnBagContent select 0) select _u, (respawnBagContent select 1) select _u];
		};
	};
} else {
	/* Player did not purchase a backpack but have one by default */
	if !(isNull (unitBackPack player)) then {
		removeBackpack player;
	};
};