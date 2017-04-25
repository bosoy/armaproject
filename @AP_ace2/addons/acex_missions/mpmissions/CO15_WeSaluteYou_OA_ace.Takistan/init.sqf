
MissionTime = paramsArray select 0;
MissionMoon = paramsArray select 1;
GroupTracking = paramsArray select 2;

ace_sys_spector_ShownSides = [west, east, resistance];

switch (GroupTracking) do {case 1: {ace_sys_tracking_markers_enabled = true;}; case 2: {ace_sys_tracking_markers_enabled = false;};};

if (isServer) then {
	switch (MissionMoon) do {case 1: {_moon = [2015, 12, 1, 00, 0];};case 2: {_moon = [2015, 12, 8, 00, 0];};case 3: {_moon = [2015, 12, 12, 00, 0];};};
	setDate _moon;
	skiptime MissionTime;
	[] execVM "server\initServer.sqf";
};

sleep 2;
if (!isDedicated)then {
	[] execVM "client\initClient.sqf";
};
