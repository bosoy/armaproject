// Create a mission entry for the server and client RPT file, easier to debug when you know what mission created the error
diag_log text ""; 
diag_log text format["|=============================   %1   =============================|", missionName]; // stamp mission name
diag_log text "";

setViewDistance 1000;
setTerrainGrid 50;

scoreW = 0;
scoreE = 0;
// none: 0
// West: 1
// East: -1
flags=[0, 0, 0, 0];
// peresent: 1
// not present: 0
flagsPresenceE=[0,0,0,0];
flagsPresenceW=[0,0,0,0];
westWin=false;
eastWin=false;
tie=false;
showScore=false;
msgFree=true;

ace_sys_tracking_markers_enabled = false;

if (isServer) then {
	execVM "scoreServer.sqf";
	{[_x] execVM "flagsServer.sqf";} forEach [0,1,2,3];
	publicVariable "flags";
	publicVariable "scoreW";
	publicVariable "maxScore";
	publicVariable "scoreE";
	publicVariable "westWin";
	publicVariable "eastWin";
	publicVariable "tie";
	
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

if (!isDedicated) then
{
	execVM "briefing.sqf";
	execVM "unitmarkers.sqf";
	execVM "showscore.sqf";
	
	waitUntil {!isNull player};
	sleep .1;
	
	removeAllWeapons player;
	removeBackPack player;
	
	_nightVision=1;
	if (!isNil "paramsArray") then
	{
		for [{_i = 0}, {_i < count(paramsArray)}, {_i = _i + 1 }] do
		{
			switch (configName ((missionConfigFile >> "Params") select _i)) do
			{
				case "NightVision":
				{
					_nightVision = (paramsArray select _i);
				};

			};
		};
	};
	if (_nightVision>0) then
	{
		player addWeapon "NVGoggles";
	};
	
	if (!(player hasWeapon "itemGPS")) then
	{
		player addWeapon "itemGPS";
	};
	if (!(player hasWeapon "LaserDesignator" || player hasWeapon "Binocular_Vector")) then
	{
		player addWeapon "Binocular";
	};
	player addWeapon "ACE_GlassesLHD_glasses";
	if (!(player hasWeapon "ACE_Earplugs")) then
	{
		player addWeapon "ACE_Earplugs";
	};
	
	//waitUntil {!isNil "ace_sys_ruck"};
	player setVariable ["ACE_WeaponOnBack", ""];
	
	execVM "spawn.sqf";
	
	{[_x] execVM "flagsClient.sqf";} forEach [0,1,2,3];
	
	
	"end1" addPublicVariableEventHandler
	{
		if (dialog) then
		{
			closeDialog 0;
		};
		end1go=true;
	};
	
	"end2" addPublicVariableEventHandler
	{
		if (dialog) then
		{
			closeDialog 0;
		};
		end2go=true;
	};
	
	"end3" addPublicVariableEventHandler
	{
		if (dialog) then
		{
			closeDialog 0;
		};
		end3go=true;
	};
};

{
	[_x, 10] execVM "spawnprotection.sqf";	
} forEach ["p1", "p2", "p3", "p4", "p5", "p6", "p7", "p8", "p9", "p10"];

{
	[_x, 10] execVM "spawnprotection.sqf";
} forEach ["s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10"];

sleep 1;

hint "Change and save loadout at the crate. Change view distance at the flag.";