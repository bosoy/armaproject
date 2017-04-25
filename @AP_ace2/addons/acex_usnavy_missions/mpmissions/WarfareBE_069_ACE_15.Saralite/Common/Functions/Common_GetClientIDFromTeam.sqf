Private ['_index','_team'];

_team = _this;

if (isNil '_team') exitWith {0};
if (isNull _team) exitWith {0};

_index = (Format["WFBE_%1TEAMS",str (side _team)] Call GetNamespace) find _team;
if (_index < 0) exitWith {0};

_index+1