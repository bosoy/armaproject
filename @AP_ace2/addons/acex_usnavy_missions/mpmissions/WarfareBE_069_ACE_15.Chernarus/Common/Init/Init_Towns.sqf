Private ["_startAt","_txt"];

waitUntil{townModeSet};
_startAt = time;
waitUntil {!isNil "totalTowns" || time - _startAt > 120};
waitUntil {(count towns == totalTowns) ||  time - _startAt > 120};
if ((count towns != totalTowns) && local player) then {
	_txt = Format["DEBUG: \n\n Something might be wrong with the town initialization process... \n\n This could be related to the towns amount set in WF_Logic or to the initialization itself, try to rejoin the game if the auto-fix doesn't work... \n\n Extra Info: \n count towns: %1 \n totalTowns: %2... \n\n The game will now attempt to fix itself...",count towns,totalTowns];
	_txt Call DebugHint;
	
	/* Attempt to fix Null over JIP */
	towns = towns - [objNull];
	if (count towns == totalTowns) then 
	{
		townInit = true;
	} 
	else 
	{
		diag_log Format["[WFBE (INIT)] Init_Towns: Fail with count towns = %1, totalTowns = %2",count towns, totalTowns];
		sleep 5; 
		failMission "END1";
	};
} else {townInit = true};

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Init_Towns: Towns initialization - [Done]",diag_frameno,diag_tickTime];