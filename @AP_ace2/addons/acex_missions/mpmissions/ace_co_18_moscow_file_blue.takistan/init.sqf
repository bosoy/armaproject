// Create a mission entry for the server and client RPT file, easier to debug when you know what mission created the error
diag_log text ""; 
diag_log text format["|=============================   %1   =============================|", missionName]; // stamp mission name
diag_log text "";

if (!isNil "param1") then
{
	setViewDistance param1;
};

execVM "briefing.sqf";
execVM "endhandler.sqf";

execVM "unitmarkers.sqf";

if (isServer) then
{
	execVM "scripts\Init_UPSMON.sqf";
};

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
	
	execVM "groupmerge.sqf";
};

waitUntil {!isNil "startPos"};
waitUntil {!isNil "startDir"};
waitUntil {!isNil "objPos"};
"mrkObj" setMarkerPos objPos;
"mrkStart" setMarkerPos startPos;
"mrkStart" setMarkerDir startDir;