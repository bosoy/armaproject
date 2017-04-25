private ["_id","_side","_amount"];

_amount = _this Select 0;
_side = _this Select 1;
_id = _this Select 2;

Call Compile Format ["%1Funds%2 = %1Funds%2 + %3; publicVariable '%1Funds%2';",str _side,_id,_amount];