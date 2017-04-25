Private ["_location"];
_location = _this select 0;

waitUntil {commonInitComplete};

if (isNil "Airfields") then {Airfields = []};
Airfields = Airfields + [_location];

diag_log Format["[WFBE (INIT)][frameno:%4 | ticktime:%5] Init_Airfield: Airfield initialization (position: %1 - item: %2 (%3)) - [Done]",getPos _location,_location,typeOf _location,diag_frameno,diag_tickTime];