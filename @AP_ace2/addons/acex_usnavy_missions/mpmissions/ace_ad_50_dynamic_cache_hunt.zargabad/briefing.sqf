private ["_strSide", "_strSpectGear"];

waitUntil {!isNull player};

player createDiaryRecord ["Diary", ["Credits", "Mission by GalZohar<br/><br/>Inspired by DTAS (Dynamic Take And Secure), game mode for Infiltration, which is a realistic total conversion mod for the original Unreal Tournament (1999)."]];

_strSpectGear=".";
if (loadouts==0) then
{
	_strSpectGear = " and change your weapon loadout."
};
player createDiaryRecord ["Diary", ["Technical info", format ["Spectating is possible for all dead players and players who join while a round is in progress. You can press the X key to exit the spectator script%1 Use the action menu on the flag in order to resume spectating or change your view distance.<br/><br/>There is no reliable way to prevent you from communicating with the living while you are dead, therefore you will have to keep the realism, be fair and be mature - After you die do not communicate with your team by any means until the round ends.", _strSpectGear]]];

switch (loadouts) do
{
	case 0:
	{
		player createDiaryRecord ["Diary", ["Equipment", format ["Grab your gear from the ammo crates. You will have %1 seconds between rounds to re-pick your gear and plan your next attack. Make sure you have the means to complete your mission!", setupTime]]];
	};
	
	case 1:
	{
		_strSide = "eastern";
		if (playerSide==West) then
		{
			_strSide = "western";
		};
		player createDiaryRecord ["Diary", ["Equipment", format ["You will be equipped with standard %1 gear based on the roles you have chosen.", _strSide]]];
	};
	
	case 2:
	{
		_strSide = "eastern";
		if (playerSide==West) then
		{
			_strSide = "western";
		};
		player createDiaryRecord ["Diary", ["Equipment", format ["You will be equipped with old-fashioned %1 gear based on the roles you have chosen.", _strSide]]];
	};
};

player createDiaryRecord ["Diary", ["Last players countdown", format ["When only 1/5 of the attacking force are left alive, or when they have only 1 attacker alive, time limit will be cut down to %1 seconds. Attackers will be notified, but defenders will only find out if the time runs out and their mission is successful.", lastPlayersCountdown]]];

if (playerSide == WEST) then
{
	player createDiaryRecord ["Diary", ["Intelligence", "The caches should be within about 50 meters of the marked location and are relatively close to eachother. The enemy will be defending the caches but will not know which direction we will be coming from. The ammo caches should be easy to destroy by a direct hit of a rocket launcher, explosive charge such as a claymore mine, several magazines worth of rifle rounds or several grenade launcher rounds."]];
	player createDiaryRecord ["Diary", ["Mission", format["Estimated location of the 2 ammo caches will be marked on your map. Destroy them before time runs out (%1 minutes). Win %2 out of %3 times to win it all!", timeLimit/60, maxScore, 2*maxScore-1]]];
};

if (playerSide == EAST) then
{
	player createDiaryRecord ["Diary", ["Intelligence", "Enemies will only receive estimated location (up to about 50 meters away) of the ammo caches, but we do not know where they will be coming from. The ammo caches should be easy to destroy by a direct hit of a rocket launcher, explosive charge such as a claymore mine, several magazines or several grenade launcher rounds."]];
	player createDiaryRecord ["Diary", ["Mission", format["2 ammo caches will be marked on your map. Defend them until time runs out (%1 minutes). Win %2 out of %3 times to win it all!", timeLimit/60, maxScore, 2*maxScore-1]]];
};