#define CAPTURE_TIMER 10
private ["_flagNumber", "_westDominationTimer", "_eastDominationTimer", "_startTime"];

// script changes the _flagNumber element of the flag array based on which side dominates it
// east dominates if the _flagNumber element of flagsPresenceE is >0 and flagPresenceW is 0
// west is the opposite

// first parameter: flag number

// function to check of east dominates and change flag
_eastDominationTimer=
{
	_startTime=time+CAPTURE_TIMER;
	waitUntil
	{
		time>_startTime
		||
		!(
			(flagsPresenceE select _flagNumber) > 0
			&&
			(flagsPresenceW select _flagNumber) == 0
		)
	};
	
	// if 10 seconds elapsed and east still dominates change flag control to east
	if (
		(flagsPresenceE select _flagNumber) > 0
		&&
		(flagsPresenceW select _flagNumber) == 0
	) then
	{
		flags set [_flagNumber, -1];
		call compile format ["objFlag%1 setFlagTexture ""\ca\data\Flag_rus_co.paa""", _flagNumber+1];
		publicVariable "flags";
	};
};

// function to check if west dominates and change flag
_westDominationTimer=
{
	_startTime=time+CAPTURE_TIMER;
	waitUntil
	{
		time>_startTime
		||
		!(
			(flagsPresenceE select _flagNumber) == 0
			&&
			(flagsPresenceW select _flagNumber) > 0
		)
	};
	
	// if 10 seconds elapsed and west still dominates change flag control to west
	if (
		(flagsPresenceE select _flagNumber) == 0
		&&
		(flagsPresenceW select _flagNumber) > 0
	) then
	{
		flags set [_flagNumber, 1];
		call compile format ["objFlag%1 setFlagTexture ""\ca\data\Flag_usa_co.paa""", _flagNumber+1];
		publicVariable "flags";
	};
};

_flagNumber = _this select 0;

while {true} do {
	
	// if owned by west
	if (0<(flags select _flagNumber)) then
	{
		// wait for east domination
		waitUntil {
			(flagsPresenceE select _flagNumber) > 0
			&&
			(flagsPresenceW select _flagNumber) == 0
		};
		call _eastDominationTimer;
	};

	// if owned by east
	if (0>(flags select _flagNumber)) then
	{
		// wait for west domination
		waitUntil {
			(flagsPresenceE select _flagNumber) == 0
			&&
			(flagsPresenceW select _flagNumber) > 0
		};	
		call _westDominationTimer;
	}
	// if neutral
	else
	{
		// wait for someone to dominate
		waitUntil {
			(
				(flagsPresenceE select _flagNumber) > 0
				&&
				(flagsPresenceW select _flagNumber) == 0
			)
			||
			(
				(flagsPresenceE select _flagNumber) == 0
				&&
				(flagsPresenceW select _flagNumber) > 0
			)
		};
		
		// if west dominates for 10 seconds change flag control to west
		if (
			(flagsPresenceE select _flagNumber) == 0
			&&
			(flagsPresenceW select _flagNumber) > 0
		) then
		{
			call _westDominationTimer;
		};
		
		// if east dominates for 10 seconds change flag control to east
		if (
			(flagsPresenceE select _flagNumber) > 0
			&&
			(flagsPresenceW select _flagNumber) == 0
		) then
		{
			call _eastDominationTimer;
		};
	};
};