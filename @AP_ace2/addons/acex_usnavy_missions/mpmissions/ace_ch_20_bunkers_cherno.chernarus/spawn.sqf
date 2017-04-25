if (!isDedicated && (player != player)) then
{
    waitUntil {player == player};
};

execVM "saveloadout.sqf";

while {true} do {
	waitUntil {!alive player};
	waitUntil {alive player};
	execVM "loadLoadout.sqf";
	canSave=true;
	if (!(player hasWeapon "itemGPS")) then
	{
		player addWeapon "itemGPS";
	};
};