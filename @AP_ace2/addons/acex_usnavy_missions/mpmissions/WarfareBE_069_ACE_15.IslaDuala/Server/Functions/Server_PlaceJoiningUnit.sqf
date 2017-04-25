Private ["_buildings","_hq","_placeAt","_side","_unit"];

_unit = _this select 0;
_side = _this select 1;

waitUntil {!isNil Format["%1StartingLocation",str _side]};

_buildings = (str _side) Call GetSideStructures;
_hq = (str _side) Call GetSideHQ;

_placeAt = objNull;
if (count _buildings > 0) then {
	_placeAt = ([_hq, _buildings] Call SortByDistance) select 0;
} else {
	_placeAt = _hq;
};

_unit setPos ([getPos _placeAt,20,30] Call GetRandomPosition);