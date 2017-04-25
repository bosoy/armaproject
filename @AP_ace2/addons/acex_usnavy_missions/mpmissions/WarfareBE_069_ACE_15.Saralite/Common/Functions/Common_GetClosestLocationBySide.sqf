Private["_enemyTowns","_object","_nearest","_side"];

_object = _this select 0;
_side = _this select 1;

_enemyTowns = towns - ((_side) Call GetSideTowns);
_nearest = objNull;

if (count _enemyTowns > 0) then {
	_nearest = ([_object,_enemyTowns] Call SortByDistance) select 0;
};

_nearest