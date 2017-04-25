if (!cancreateenemies) exitWith {
	player sideChat "Creating enemies currently not possible, clear the target first...";
};

docreateenemies = true;
publicVariable "docreateenemies";

ecreatedx = true;
publicVariable "ecreatedx";

player sideChat "New enemies get created...";