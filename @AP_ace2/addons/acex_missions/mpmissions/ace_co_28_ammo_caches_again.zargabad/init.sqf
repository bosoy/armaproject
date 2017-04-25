if (!isNil "param1") then
{
	setViewDistance param1;
};

if (isServer) then
{
	execVM "scripts\Init_UPSMON.sqf";
	deadCivCount=0;
	{
		_x addEventHandler ["killed", "if (side (_this select 1) == WEST) then {deadCivCount=deadCivCount+1;};"];
	} forEach civUnits;
};

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

execVM "briefing.sqf";
execVM "endhandler.sqf";
execVM "unitmarkers.sqf";

if (!isDedicated) then
{
	[] spawn
	{
		waitUntil {!isNil "groupCMD"};
		groupCMD setGroupID ["CMD"];
	};
	
	[] spawn
	{
		waitUntil {!isNil "groupA"};
		groupA setGroupID ["A"];
	};
	
	[] spawn
	{
		waitUntil {!isNil "groupB"};
		groupB setGroupID ["B"];
	};
	
	[] spawn
	{
		waitUntil {!isNil "groupC"};
		groupC setGroupID ["C"];
	};
	
	[] spawn
	{
		waitUntil {!isNil "groupSn"};
		groupSn setGroupID ["Sn"];
	};
	
	execVM "groupmerge.sqf";
};

waitUntil {!isNil "objPos"};
"mrkObj" setMarkerPos objPos;