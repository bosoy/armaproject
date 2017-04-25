difficulty = 1.8;

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
} forEach allUnits;

enemyCount = round ((difficulty/6) * (5 + (indCount / 15) * 47));
if (isServer) then
{
	call compile preprocessFileLineNumbers "serverinit.sqf";
};