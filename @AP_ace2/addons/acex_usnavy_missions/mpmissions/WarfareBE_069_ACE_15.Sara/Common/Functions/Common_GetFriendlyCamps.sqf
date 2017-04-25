private ["_camps","_friendlyCamps","_side","_sideID","_town"];

_town = _this Select 0;
_side = _this Select 1;

_sideID = _side Call GetSideID;
_camps = _town getVariable "camps";
_friendlyCamps = [];

{
	if ((_x getVariable "sideID") == _sideID) then {_friendlyCamps = _friendlyCamps + [_x]};	
} forEach _camps;

_friendlyCamps