Private["_currentDammages","_damage","_damagedBy","_side","_structure","_timeAttacked"];

_structure = _this Select 0;
_damagedBy = _this Select 1;
_damage = _this Select 2;
_currentDammages = getDammage _structure;

_side = east;
if ((typeOf _structure) in ('WFBE_WESTSTRUCTURENAMES' Call GetNamespace)) then {_side = west};

_timeAttacked = Format["WFBE_%1_TimeUnderAttack",str _side] Call GetNamespace;

if (_side != Side _damagedBy) then {
	if (time - _timeAttacked > 30 && _damage > 0.05 && ((_currentDammages + _damage) < 1)) then {
		[Format["WFBE_%1_TimeUnderAttack",str _side],time,true] Call SetNamespace;
		["IsUnderAttack",TypeOf _structure ,_side] Spawn SideMessage;
	};
};