// Create a mission entry for the server and client RPT file, easier to debug when you know what mission created the error
diag_log text ""; 
diag_log text format["|=============================   %1   =============================|", missionName]; // stamp mission name
diag_log text "";

if (!isNil "param1") then
{
	setViewDistance param1;
};

ace_sys_tracking_markers_enabled = false;
execVM "briefing.sqf";
execVM "endhandler.sqf";

if (isServer) then
{
	execVM "scripts\Init_UPSMON.sqf";
};

if (!isDedicated) then
{
	[] spawn
	{
		waitUntil {!isNil "groupR"};
		groupR setGroupID ["Rebels"];
	};
};

waitUntil {!isNil "startPos"};
waitUntil {!isNil "startDir"};
waitUntil {!isNil "objPos"};
"mrkObj" setMarkerPos objPos;
"mrkStart" setMarkerPos startPos;
"mrkStart" setMarkerDir startDir;