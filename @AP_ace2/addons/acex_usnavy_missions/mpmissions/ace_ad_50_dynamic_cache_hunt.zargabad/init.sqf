// Create a mission entry for the server and client RPT file, easier to debug when you know what mission created the error
diag_log text ""; 
diag_log text format["|=============================   %1   =============================|", missionName]; // stamp mission name
diag_log text "";


//-----------------------------------------------------------------------------------------------------

// When porting to other islands:

// Edit setdate.sqf to appropriate time/date (matching description.ext options).
// Make sure the mission.sqm/editor are set to the earliest time/date possible.

// Make sure west and east starting areas are not off-map (or else ammo crates become unusable).
// Place the empty markers "mrkSWcorner" and "mrkNEcorner" to the corners of the area where you want the objective to be able to spawn.
// Consider that west spawns in a random direction and distance between minDist and maxDist from the objective, so adjust the zone accordingly.

// minimum and maximum starting distance for west team from the objective, adjust when porting!
minDist = 400;
maxDist = 480;

//------------------------------------------------------------------------------------------------------

// default view distance (changeable by players at flag)
setViewDistance 1400;
setTerrainGrid 50;

if (isServer) then
{
	execVM "roundserver.sqf";
	onPlayerConnected
	"
		{
			if (alive _x && !(isPlayer _x)) then
			{
				removeAllWeapons _x;
				removeBackPack _x;
			};
		} forEach allUnits;
	";
	[] spawn
	{
		while {true} do 
		{ 
			waitUntil {sideEnemy countSide allUnits > 0};
			{
				if (side _X == sideEnemy) then
				{ 
					_X addRating (-(rating _X)); 
				}; 
			} forEach allUnits; 
		}; 
	};
};

ace_sys_tracking_markers_enabled = false;

execVM "endhandler.sqf";

if (!isDedicated) then
{
	execVM "briefing.sqf";
	execVM "unitmarkers.sqf";
	
	waitUntil {!isNull player};
	sleep .1;
	
	removeAllWeapons player;
	removeBackPack player;
	
	player setVariable ["ACE_WeaponOnBack", ""];
	
	execVM "roundclient.sqf";
};

sleep 1;

if
(
	(weaponTypes>4 && caliber>4)
	||
	explosives>4
	||
	launchers==0
	||
	launchers>3
	||
	csw>1
	||
	(
		sideWeapons<2
		&&
		(
			(futureweapons>0 && caliber>4)
			||
			sfweapons>1
			||
			(nightsights>1 && nightOrDay>0)
			||
			(sideWeapons>0 && hiCapMags>1)
		)
	)
) then
{
	hint "Warning: Mission parameters selected by server admin are imbalanced!";
}
else
{
	if
	(
		launchers==2
		||
		sideWeapons<2
	) then
	{
		hint "Warning: Mission parameters selected by server admin are slightly imbalanced!";
	};
};