Private ['_boundariesXY'];
_boundariesXY = -1;

switch (toLower(worldName)) do {
	case 'chernarus': {_boundariesXY = 15360};
	case 'eden': {_boundariesXY = 12800};
	case 'fallujah': {_boundariesXY = 10240};
	case 'isladuala': {_boundariesXY = 10240};
	case 'panthera2': {_boundariesXY = 10240};
	case 'queshkibrul': {_boundariesXY = 5120};
	case 'sara': {_boundariesXY = 20480};
	case 'saraLite': {_boundariesXY = 10240};
	case 'takistan': {_boundariesXY = 12800};
	case 'utes': {_boundariesXY = 5120};
	case 'yapal': {_boundariesXY = 5120};
	case 'zargabad': {_boundariesXY = 8192};
};

if (paramBoundaries) then {
	if (_boundariesXY == -1) then {
	paramBoundaries = false;
	if (local player) then {
		BoundariesIsOnMap = nil;
		BoundariesHandleOnMap = nil;
	};
	diag_log Format["[WFBE (INFORMATION)][frameno:%2 | ticktime:%3] Init_Boundaries: There is no proper boundaries set for the island '%1'",worldName,diag_frameno,diag_tickTime];
	} else {
		['WFBE_BOUNDARIESXY',_boundariesXY,true] Call SetNamespace;
		diag_log Format["[WFBE (INIT)][frameno:%3 | ticktime:%4] Init_Boundaries: Boundaries found for the island '%1' %2",worldName,_boundariesXY,diag_frameno,diag_tickTime];
	};
} else {
	if (_boundariesXY == -1) then {
		diag_log Format["[WFBE (INFORMATION)][frameno:%2 | ticktime:%3] Init_Boundaries: There is no proper boundaries set for the island '%1'",worldName,diag_frameno,diag_tickTime];
	} else {
	['WFBE_BOUNDARIESXY',_boundariesXY,true] Call SetNamespace;
		diag_log Format["[WFBE (INIT)][frameno:%3 | ticktime:%4] Init_Boundaries: Boundaries found for the island '%1' %2 [Boundaries parameter is disabled]",worldName,_boundariesXY,diag_frameno,diag_tickTime];
	};
};