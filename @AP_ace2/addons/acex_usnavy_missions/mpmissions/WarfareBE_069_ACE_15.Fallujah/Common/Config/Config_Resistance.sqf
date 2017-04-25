Private ['_resType'];

_resType = ('WFBE_RESISTANCEFACTIONS' Call GetNamespace) select ('WFBE_RESISTANCEFACTION' Call GetNamespace);

[] Call Compile preprocessFile Format["Common\Config\Core_Resistance\Resistance_%1.sqf",_resType];

diag_log Format["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Resistance: Intialization (Resistance: %3) - [Done]",diag_frameno,diag_tickTime,_resType];