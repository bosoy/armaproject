// Create a mission entry for the server and client RPT file, easier to debug when you know what mission created the error
diag_log text ""; 
diag_log text format["|=============================   %1   =============================|", missionName]; // stamp mission name
diag_log text "";

difficulty = 6;

if (!isNil "paramsArray") then
{
	for [{_i = 0}, {_i < count(paramsArray)}, {_i = _i + 1 }] do
	{
		switch (configName ((missionConfigFile >> "Params") select _i)) do
		{
			case "Difficulty":
			{
				difficulty = (paramsArray select _i);
			};
		};
	};
};

call compile preprocessFile "markeralpha.sqf";

blueforUnits = [];
blueforCount=0;
opforUnits = [];
opforCount=0;
indUnits = [];
civCount = 0;
civUnits = [];
indCount=0;
{
	if (side _x == WEST) then
	{
		blueforUnits set [blueforCount, _x];
		blueforCount = blueforCount + 1;
	};
	if (side _x == EAST) then
	{
		opforUnits set [opforCount, _x];
		opforCount = opforCount + 1;
	};
	if (side _x == RESISTANCE) then
	{
		indUnits set [indCount, _x];
		indCount = indCount + 1;
	};
	if (side _x == CIVILIAN) then
	{
		civUnits set [civCount, _x];
		civCount = civCount + 1;
	};
} forEach allUnits;

enemyCount = round ((difficulty/6) * (10 + (blueforCount / 28) * 120) * (0.93 + random 0.14));
briefingEnemycount = round ((difficulty/6) * (10 + (blueforCount / 28) * 120));
briefingReinfCount = 2 + floor (briefingEnemyCount/7);
if (isServer) then
{
	call compile preprocessFileLineNumbers "serverinit.sqf";
};