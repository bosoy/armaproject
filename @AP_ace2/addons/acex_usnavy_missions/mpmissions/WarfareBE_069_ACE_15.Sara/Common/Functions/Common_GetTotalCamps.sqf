Private ['_camps'];

_camps = _this getVariable "camps";
if (isNil '_camps') exitWith {1};
if (count _camps == 0) exitWith {1};

count _camps