Private ['_squads'];

//--- West
_squads = Call Compile PreprocessFile Format["Common\Config\Core_Squads\%1\Squad_%2.sqf",WFBE_V_West_SquadsRootVersion,WFBE_V_West_SquadsFaction];
['WFBE_WESTAITEAMTEMPLATES',_squads select 0,true] Call SetNamespace;
['WFBE_WESTAITEAMTEMPLATEREQUIRES',_squads select 1,true] Call SetNamespace;
['WFBE_WESTAITEAMTYPES',_squads select 2,true] Call SetNamespace;
['WFBE_WESTAITEAMUPGRADES',_squads select 3,true] Call SetNamespace;
['WFBE_WESTAITEAMTEMPLATEDESCRIPTIONS',_squads select 4,true] Call SetNamespace;

//--- East.
_squads = Call Compile PreprocessFile Format["Common\Config\Core_Squads\%1\Squad_%2.sqf",WFBE_V_East_SquadsRootVersion,WFBE_V_East_SquadsFaction];
['WFBE_EASTAITEAMTEMPLATES',_squads select 0,true] Call SetNamespace;
['WFBE_EASTAITEAMTEMPLATEREQUIRES',_squads select 1,true] Call SetNamespace;
['WFBE_EASTAITEAMTYPES',_squads select 2,true] Call SetNamespace;
['WFBE_EASTAITEAMUPGRADES',_squads select 3,true] Call SetNamespace;
['WFBE_EASTAITEAMTEMPLATEDESCRIPTIONS',_squads select 4,true] Call SetNamespace;

diag_log Format ["[WFBE (INIT)][frameno:%1 | ticktime:%2] Config_Squads: Initialization (West: %3 | East: %4) - [Done]",diag_frameno,diag_tickTime,WFBE_V_West_SquadsFaction,WFBE_V_East_SquadsFaction];